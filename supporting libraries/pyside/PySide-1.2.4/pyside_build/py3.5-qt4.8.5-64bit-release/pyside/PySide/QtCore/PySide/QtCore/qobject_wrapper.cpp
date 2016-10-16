/*
 * This file is part of PySide: Python for Qt
 *
 * Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */


//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtcore_python.h"

#include "qobject_wrapper.h"

// Extra includes
#include <QCoreApplication>
#include <QList>
#include <QThread>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qregexp.h>
#include <qthread.h>
#include "signalmanager.h"


// Begin code injection
// ========================================================================
// START of custom code block [file: glue/qobject_connect.cpp]
static bool isDecorator(PyObject* method, PyObject* self)
{
    Shiboken::AutoDecRef methodName(PyObject_GetAttrString(method, "__name__"));
    if (!PyObject_HasAttr(self, methodName))
        return true;
    Shiboken::AutoDecRef otherMethod(PyObject_GetAttr(self, methodName));
    return reinterpret_cast<PyMethodObject*>(otherMethod.object())->im_func != \
           reinterpret_cast<PyMethodObject*>(method)->im_func;
}

static bool getReceiver(QObject *source, const char* signal, PyObject* callback, QObject** receiver, PyObject** self, QByteArray* callbackSig)
{
    bool forceGlobalReceiver = false;
    if (PyMethod_Check(callback)) {
        *self = PyMethod_GET_SELF(callback);
        if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], *self))
            Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], *self, (receiver));
        forceGlobalReceiver = isDecorator(callback, *self);
    } else if (PyCFunction_Check(callback)) {
        *self = PyCFunction_GET_SELF(callback);
        if (*self && SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], *self))
            Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], *self, (receiver));
    } else if (PyCallable_Check(callback)) {
        // Ok, just a callable object
        *receiver = 0;
        *self = 0;
    }

    bool usingGlobalReceiver = !*receiver || forceGlobalReceiver;

    // Check if this callback is a overwrite of a non-virtual Qt slot.
    if (!usingGlobalReceiver && receiver && self) {
        *callbackSig = PySide::Signal::getCallbackSignature(signal, *receiver, callback, usingGlobalReceiver).toAscii();
        const QMetaObject* metaObject = (*receiver)->metaObject();
        int slotIndex = metaObject->indexOfSlot(callbackSig->constData());
        if (slotIndex != -1 && slotIndex < metaObject->methodOffset() && PyMethod_Check(callback))
            usingGlobalReceiver = true;
    }

    if (usingGlobalReceiver) {
        PySide::SignalManager& signalManager = PySide::SignalManager::instance();
        *receiver = signalManager.globalReceiver(source, callback);
        *callbackSig = PySide::Signal::getCallbackSignature(signal, *receiver, callback, usingGlobalReceiver).toAscii();
    }

    return usingGlobalReceiver;
}

static bool qobjectConnect(QObject* source, const char* signal, QObject* receiver, const char* slot, Qt::ConnectionType type)
{
    if (!signal || !slot)
        return false;

    if (!PySide::Signal::checkQtSignal(signal))
        return false;
    signal++;

    if (!PySide::SignalManager::registerMetaMethod(source, signal, QMetaMethod::Signal))
        return false;

    bool isSignal = PySide::Signal::isQtSignal(slot);
    slot++;
    PySide::SignalManager::registerMetaMethod(receiver, slot, isSignal ? QMetaMethod::Signal : QMetaMethod::Slot);
    bool connected;
    Py_BEGIN_ALLOW_THREADS
    connected = QObject::connect(source, signal - 1, receiver, slot - 1, type);
    Py_END_ALLOW_THREADS
    return connected;
}

static bool qobjectConnectCallback(QObject* source, const char* signal, PyObject* callback, Qt::ConnectionType type)
{
    if (!signal || !PySide::Signal::checkQtSignal(signal))
        return false;
    signal++;

    int signalIndex = PySide::SignalManager::registerMetaMethodGetIndex(source, signal, QMetaMethod::Signal);
    if (signalIndex == -1)
        return false;

    PySide::SignalManager& signalManager = PySide::SignalManager::instance();

    // Extract receiver from callback
    QObject* receiver = 0;
    PyObject* self = 0;
    QByteArray callbackSig;
    bool usingGlobalReceiver = getReceiver(source, signal, callback, &receiver, &self, &callbackSig);
    if (receiver == 0 && self == 0)
        return false;

    const QMetaObject* metaObject = receiver->metaObject();
    const char* slot = callbackSig.constData();
    int slotIndex = metaObject->indexOfSlot(slot);

    if (slotIndex == -1) {
        if (!usingGlobalReceiver && self && !Shiboken::Object::hasCppWrapper((SbkObject*)self)) {
            qWarning() << "You can't add dynamic slots on an object originated from C++.";
            if (usingGlobalReceiver)
                signalManager.releaseGlobalReceiver(source, receiver);

            return false;
        }

        if (usingGlobalReceiver)
            slotIndex = signalManager.globalReceiverSlotIndex(receiver, slot);
        else
            slotIndex = PySide::SignalManager::registerMetaMethodGetIndex(receiver, slot, QMetaMethod::Slot);

        if (slotIndex == -1) {
            if (usingGlobalReceiver)
                signalManager.releaseGlobalReceiver(source, receiver);

            return false;
        }
    }
    bool connected;
    Py_BEGIN_ALLOW_THREADS
    connected = QMetaObject::connect(source, signalIndex, receiver, slotIndex, type);
    Py_END_ALLOW_THREADS
    if (connected) {
        if (usingGlobalReceiver)
            signalManager.notifyGlobalReceiver(receiver);
        #ifndef AVOID_PROTECTED_HACK
            source->connectNotify(signal - 1);
        #else
            // Need to cast to QObjectWrapper* and call the public version of
            // connectNotify when avoiding the protected hack.
            reinterpret_cast<QObjectWrapper*>(source)->connectNotify(signal - 1);
        #endif

        return true;
    }

    if (usingGlobalReceiver)
        signalManager.releaseGlobalReceiver(source, receiver);

    return false;
}


static bool qobjectDisconnectCallback(QObject* source, const char* signal, PyObject* callback)
{
    if (!PySide::Signal::checkQtSignal(signal))
        return false;

    PySide::SignalManager& signalManager = PySide::SignalManager::instance();

    // Extract receiver from callback
    QObject* receiver = 0;
    PyObject* self = 0;
    QByteArray callbackSig;
    bool usingGlobalReceiver = getReceiver(NULL, signal, callback, &receiver, &self, &callbackSig);
    if (receiver == 0 && self == 0)
        return false;

    const QMetaObject* metaObject = receiver->metaObject();
    int signalIndex = source->metaObject()->indexOfSignal(++signal);
    int slotIndex = -1;

    slotIndex = metaObject->indexOfSlot(callbackSig);

    bool disconnected;
    Py_BEGIN_ALLOW_THREADS
    disconnected = QMetaObject::disconnectOne(source, signalIndex, receiver, slotIndex);
    Py_END_ALLOW_THREADS

    if (disconnected) {
        if (usingGlobalReceiver)
            signalManager.releaseGlobalReceiver(source, receiver);

        #ifndef AVOID_PROTECTED_HACK
            source->disconnectNotify(callbackSig);
        #else
            // Need to cast to QObjectWrapper* and call the public version of
            // connectNotify when avoiding the protected hack.
            reinterpret_cast<QObjectWrapper*>(source)->disconnectNotify(callbackSig);
        #endif
        return true;
    }
    return false;
}

// END of custom code block [file: glue/qobject_connect.cpp]
// ========================================================================

// ========================================================================
// START of custom code block [file: glue/qobject_findchild.cpp]
static QObject* _findChildHelper(const QObject* parent, const QString& name, PyTypeObject* desiredType)
{
    foreach(QObject* child, parent->children()) {
        Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], child));
        if (PyType_IsSubtype(pyChild->ob_type, desiredType)
            && (name.isNull() || name == child->objectName())) {
            return child;
        }
    }

    QObject* obj;
    foreach(QObject* child, parent->children()) {
        obj = _findChildHelper(child, name, desiredType);
        if (obj)
            return obj;
    }
    return 0;
}

static inline bool _findChildrenComparator(const QObject*& child, const QRegExp& name)
{
    return name.indexIn(child->objectName()) != -1;
}

static inline bool _findChildrenComparator(const QObject*& child, const QString& name)
{
    return name.isNull() || name == child->objectName();
}

template<typename T>
static void _findChildrenHelper(const QObject* parent, const T& name, PyTypeObject* desiredType, PyObject* result)
{
    foreach(const QObject* child, parent->children()) {
        Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], child));
        if (PyType_IsSubtype(pyChild->ob_type, desiredType) && _findChildrenComparator(child, name))
            PyList_Append(result, pyChild);
        _findChildrenHelper(child, name, desiredType, result);
    }
}

// END of custom code block [file: glue/qobject_findchild.cpp]
// ========================================================================

// End of code injection

// Native ---------------------------------------------------------

QObjectWrapper::QObjectWrapper(QObject * parent) : QObject(parent) {
    // ... middle
}

void QObjectWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QObjectWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QObjectWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QObjectWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QObjectWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QObject.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QObjectWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QObject.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QObjectWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject* QObjectWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QObject::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QObjectWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QObject::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QObjectWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QObjectWrapper* >(this));
        return QObject::qt_metacast(_clname);
}

QObjectWrapper::~QObjectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QObject_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QObject >()))
        return -1;

    ::QObjectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QObject", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QObject(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QObject(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObject_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QObject_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QObject(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QObjectWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QObjectWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QObject >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QObject_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QObject_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject", overloads);
        return -1;
}

static PyObject* Sbk_QObjectFunc_blockSignals(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: blockSignals(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // blockSignals(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_blockSignals_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // blockSignals(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->blockSignals(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_blockSignals_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.blockSignals", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_childEvent(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: childEvent(QChildEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], (pyArg)))) {
        overloadId = 0; // childEvent(QChildEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_childEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QChildEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // childEvent(QChildEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::childEvent(cppArg0) : cppSelf->childEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_childEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QChildEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.childEvent", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_children(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // children()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QObject * > & cppResult = const_cast<const ::QObject*>(cppSelf)->children();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QOBJECTPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_connect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:connect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: connect(const QObject*,const char*,PyCallable*,Qt::ConnectionType)
    // 1: connect(const QObject*,QMetaMethod,const QObject*,QMetaMethod,Qt::ConnectionType)
    // 2: connect(const QObject*,const char*,const QObject*,const char*,Qt::ConnectionType)
    // 3: connect(const QObject*,const char*,const char*,Qt::ConnectionType)const
    // 4: connect(const char*,PyCallable*,Qt::ConnectionType)
    // 5: connect(const char*,const QObject*,const char*,Qt::ConnectionType)
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))
            && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 5; // connect(const char*,const QObject*,const char*,Qt::ConnectionType)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3])))) {
                overloadId = 5; // connect(const char*,const QObject*,const char*,Qt::ConnectionType)
            }
        } else if (PyCallable_Check(pyArgs[1])) {
            if (numArgs == 2) {
                overloadId = 4; // connect(const char*,PyCallable*,Qt::ConnectionType)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[2])))) {
                overloadId = 4; // connect(const char*,PyCallable*,Qt::ConnectionType)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs >= 4
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 1; // connect(const QObject*,QMetaMethod,const QObject*,QMetaMethod,Qt::ConnectionType)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[4])))) {
                overloadId = 1; // connect(const QObject*,QMetaMethod,const QObject*,QMetaMethod,Qt::ConnectionType)
            }
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // connect(const QObject*,const char*,const char*,Qt::ConnectionType)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3])))) {
                    overloadId = 3; // connect(const QObject*,const char*,const char*,Qt::ConnectionType)const
                }
            } else if (numArgs >= 4
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))
                && Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 2; // connect(const QObject*,const char*,const QObject*,const char*,Qt::ConnectionType)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[4])))) {
                    overloadId = 2; // connect(const QObject*,const char*,const QObject*,const char*,Qt::ConnectionType)
                }
            } else if (PyCallable_Check(pyArgs[2])) {
                if (numArgs == 3) {
                    overloadId = 0; // connect(const QObject*,const char*,PyCallable*,Qt::ConnectionType)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3])))) {
                    overloadId = 0; // connect(const QObject*,const char*,PyCallable*,Qt::ConnectionType)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_connect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // connect(const QObject * arg__1, const char * arg__2, PyCallable * arg__3, Qt::ConnectionType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            ::Qt::ConnectionType cppArg3 = Qt::AutoConnection;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)

            if (!PyErr_Occurred()) {
                // connect(const QObject*,const char*,PyCallable*,Qt::ConnectionType)
                // Begin code injection

                // connect() - disable generation of function call.
                bool cppResult = qobjectConnectCallback(cppArg0, cppArg1, pyArgs[3-1], cppArg3);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 1: // connect(const QObject * sender, const QMetaMethod & signal, const QObject * receiver, const QMetaMethod & method, Qt::ConnectionType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[4]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMetaMethod cppArg1_local = ::QMetaMethod();
            ::QMetaMethod* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QMetaMethod cppArg3_local = ::QMetaMethod();
            ::QMetaMethod* cppArg3 = &cppArg3_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);

            ::Qt::ConnectionType cppArg4 = Qt::AutoConnection;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // connect(const QObject*,QMetaMethod,const QObject*,QMetaMethod,Qt::ConnectionType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QObject::connect(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // connect(const QObject * sender, const char * signal, const QObject * receiver, const char * member, Qt::ConnectionType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[4]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            const char* cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::ConnectionType cppArg4 = Qt::AutoConnection;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // connect(const QObject*,const char*,const QObject*,const char*,Qt::ConnectionType)
                // Begin code injection

                // connect() - disable generation of function call.
                bool cppResult = qobjectConnect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 3: // connect(const QObject * sender, const char * signal, const char * member, Qt::ConnectionType type) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            const char* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::ConnectionType cppArg3 = Qt::AutoConnection;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // connect(const QObject*,const char*,const char*,Qt::ConnectionType)const
                // Begin code injection

                // connect() - disable generation of function call.
                bool cppResult = qobjectConnect(cppArg0, cppArg1, cppSelf, cppArg2, cppArg3);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 4: // connect(const char * arg__1, PyCallable * arg__2, Qt::ConnectionType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            ::Qt::ConnectionType cppArg2 = Qt::AutoConnection;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)

            if (!PyErr_Occurred()) {
                // connect(const char*,PyCallable*,Qt::ConnectionType)
                // Begin code injection

                // connect() - disable generation of function call.
                bool cppResult = qobjectConnectCallback(cppSelf, cppArg0, pyArgs[2-1], cppArg2);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 5: // connect(const char * arg__1, const QObject * arg__2, const char * arg__3, Qt::ConnectionType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.connect(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QObjectFunc_connect_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            const char* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)
            ::Qt::ConnectionType cppArg3 = Qt::AutoConnection;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)

            if (!PyErr_Occurred()) {
                // connect(const char*,const QObject*,const char*,Qt::ConnectionType)
                // Begin code injection

                // connect() - disable generation of function call.
                bool cppResult = qobjectConnect(cppSelf, cppArg0, cppArg1, cppArg2, cppArg3);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_connect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, " SBK_STR_NAME ", callable, PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", "PySide.QtCore.QObject, PySide.QtCore.QMetaMethod, PySide.QtCore.QObject, PySide.QtCore.QMetaMethod, PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", "PySide.QtCore.QObject, " SBK_STR_NAME ", " SBK_STR_NAME ", PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", "" SBK_STR_NAME ", callable, PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", "" SBK_STR_NAME ", PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.Qt.ConnectionType = Qt.AutoConnection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.connect", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_connectNotify(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: connectNotify(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // connectNotify(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_connectNotify_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // connectNotify(const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::connectNotify(cppArg0) : cppSelf->connectNotify(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_connectNotify_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.connectNotify", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_customEvent(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: customEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // customEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_customEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // customEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::customEvent(cppArg0) : cppSelf->customEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_customEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.customEvent", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_deleteLater(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deleteLater()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deleteLater();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Ownership transferences.
            Shiboken::Object::releaseOwnership(self);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QObjectFunc_disconnect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.disconnect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.disconnect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:disconnect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: disconnect(const QObject*,const char*,PyCallable*)
    // 1: disconnect(const QObject*,const char*)
    // 2: disconnect(const QObject*,QMetaMethod,const QObject*,QMetaMethod)
    // 3: disconnect(const QObject*,const char*,const QObject*,const char*)
    // 4: disconnect(const char*,PyCallable*)
    // 5: disconnect(const char*,const QObject*,const char*)
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))
            && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
            overloadId = 5; // disconnect(const char*,const QObject*,const char*)
        } else if (numArgs == 2
            && PyCallable_Check(pyArgs[1])) {
            overloadId = 4; // disconnect(const char*,PyCallable*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // disconnect(const QObject*,const char*)
        } else if (numArgs == 4
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], (pyArgs[3])))) {
            overloadId = 2; // disconnect(const QObject*,QMetaMethod,const QObject*,QMetaMethod)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // disconnect(const QObject*,const char*)
            } else if (numArgs == 4
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))
                && Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))) {
                overloadId = 3; // disconnect(const QObject*,const char*,const QObject*,const char*)
            } else if (numArgs == 3
                && PyCallable_Check(pyArgs[2])) {
                overloadId = 0; // disconnect(const QObject*,const char*,PyCallable*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_disconnect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // disconnect(const QObject * arg__1, const char * arg__2, PyCallable * arg__3)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // disconnect(const QObject*,const char*,PyCallable*)
                // Begin code injection

                // disconnect() - disable generation of function call.
                bool cppResult = qobjectDisconnectCallback(cppArg0, cppArg1, pyArgs[2]);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 1: // disconnect(const QObject * receiver, const char * member)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "member");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.disconnect(): got multiple values for keyword argument 'member'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QObjectFunc_disconnect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // disconnect(const QObject*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->disconnect(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // disconnect(const QObject * sender, const QMetaMethod & signal, const QObject * receiver, const QMetaMethod & member)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QMetaMethod cppArg1_local = ::QMetaMethod();
            ::QMetaMethod* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QMetaMethod cppArg3_local = ::QMetaMethod();
            ::QMetaMethod* cppArg3 = &cppArg3_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);


            if (!PyErr_Occurred()) {
                // disconnect(const QObject*,QMetaMethod,const QObject*,QMetaMethod)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QObject::disconnect(cppArg0, *cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 3: // disconnect(const QObject * sender, const char * signal, const QObject * receiver, const char * member)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            const char* cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // disconnect(const QObject*,const char*,const QObject*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QObject::disconnect(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 4: // disconnect(const char * arg__1, PyCallable * arg__2)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // disconnect(const char*,PyCallable*)
                // Begin code injection

                // disconnect() - disable generation of function call.
                bool cppResult = qobjectDisconnectCallback(cppSelf, cppArg0, pyArgs[1]);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

                // End of code injection


            }
            break;
        }
        case 5: // disconnect(const char * signal, const QObject * receiver, const char * member)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            const char* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // disconnect(const char*,const QObject*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->disconnect(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_disconnect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, " SBK_STR_NAME ", callable", "PySide.QtCore.QObject, " SBK_STR_NAME " = None", "PySide.QtCore.QObject, PySide.QtCore.QMetaMethod, PySide.QtCore.QObject, PySide.QtCore.QMetaMethod", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QObject, " SBK_STR_NAME "", "" SBK_STR_NAME ", callable", "" SBK_STR_NAME ", PySide.QtCore.QObject, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.disconnect", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_disconnectNotify(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: disconnectNotify(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // disconnectNotify(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_disconnectNotify_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // disconnectNotify(const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::disconnectNotify(cppArg0) : cppSelf->disconnectNotify(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_disconnectNotify_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.disconnectNotify", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_dumpObjectInfo(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dumpObjectInfo()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->dumpObjectInfo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QObjectFunc_dumpObjectTree(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dumpObjectTree()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->dumpObjectTree();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QObjectFunc_dynamicPropertyNames(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dynamicPropertyNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QObject*>(cppSelf)->dynamicPropertyNames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_emit(PyObject* self, PyObject* args)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    PyObject* nonvarargs = PyTuple_GetSlice(args, 0, 1);
    Shiboken::AutoDecRef auto_nonvarargs(nonvarargs);
    pyArgs[1] = PyTuple_GetSlice(args, 1, numArgs);
    Shiboken::AutoDecRef auto_varargs(pyArgs[1]);

    // invalid argument lengths


    if (!PyArg_UnpackTuple(nonvarargs, "emit", 1, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: emit(const char*,...)
    if (numArgs >= 1
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 0; // emit(const char*,...)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_emit_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // emit(const char*,...)
            // Begin code injection

            bool cppResult = PySide::SignalManager::instance().emitSignal(cppSelf, cppArg0, pyArgs[2-1]);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_emit_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", ...", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.emit", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.event", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_eventFilter(PyObject* self, PyObject* args)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "eventFilter", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: eventFilter(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // eventFilter(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_eventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // eventFilter(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::eventFilter(cppArg0, cppArg1) : cppSelf->eventFilter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_eventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.eventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_findChild(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChild(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChild(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:findChild", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: findChild(PyTypeObject*,QString)
    if (PyType_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 0; // findChild(PyTypeObject*,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // findChild(PyTypeObject*,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_findChild_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__2");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChild(): got multiple values for keyword argument 'arg__2'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QObjectFunc_findChild_TypeError;
            }
        }
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        SBK_UNUSED(cppArg1)

        if (!PyErr_Occurred()) {
            // findChild(PyTypeObject*,QString)
            // Begin code injection

            QObject* child = _findChildHelper(cppSelf, cppArg1, (PyTypeObject*)pyArgs[1-1]);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], child);

            // End of code injection


            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_findChild_TypeError:
        const char* overloads[] = {"PyTypeObject, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.findChild", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_findChildren(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChildren(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChildren(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:findChildren", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: findChildren(PyTypeObject*,QRegExp)
    // 1: findChildren(PyTypeObject*,QString)
    if (PyType_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 1; // findChildren(PyTypeObject*,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // findChildren(PyTypeObject*,QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArgs[1])))) {
            overloadId = 0; // findChildren(PyTypeObject*,QRegExp)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_findChildren_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // findChildren(PyTypeObject * arg__1, QRegExp arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRegExp cppArg1 = ::QRegExp();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // findChildren(PyTypeObject*,QRegExp)
                // Begin code injection

                pyResult = PyList_New(0);
                _findChildrenHelper(cppSelf, cppArg1, (PyTypeObject*)pyArgs[1-1], pyResult);

                // End of code injection


                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // findChildren(PyTypeObject * arg__1, QString arg__2)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__2");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.findChildren(): got multiple values for keyword argument 'arg__2'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QObjectFunc_findChildren_TypeError;
                }
            }
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // findChildren(PyTypeObject*,QString)
                // Begin code injection

                pyResult = PyList_New(0);
                _findChildrenHelper(cppSelf, cppArg1, (PyTypeObject*)pyArgs[1-1], pyResult);

                // End of code injection


                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_findChildren_TypeError:
        const char* overloads[] = {"PyTypeObject, PySide.QtCore.QRegExp", "PyTypeObject, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.findChildren", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_inherits(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inherits(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // inherits(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_inherits_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inherits(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QObject*>(cppSelf)->inherits(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_inherits_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.inherits", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_installEventFilter(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: installEventFilter(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // installEventFilter(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_installEventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // installEventFilter(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->installEventFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_installEventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.installEventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_isWidgetType(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWidgetType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QObject*>(cppSelf)->isWidgetType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_killTimer(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: killTimer(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // killTimer(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_killTimer_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // killTimer(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->killTimer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_killTimer_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.killTimer", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_metaObject(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // metaObject()const
            // Begin code injection

            const QMetaObject * cppResult = (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? reinterpret_cast<QObjectWrapper*>(cppSelf)->::QObjectWrapper::metaObject() : cppSelf->metaObject());
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], cppResult);

            // End of code injection


            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "metaObject()const0", pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_moveToThread(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: moveToThread(QThread*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTHREAD_IDX], (pyArg)))) {
        overloadId = 0; // moveToThread(QThread*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_moveToThread_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QThread* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // moveToThread(QThread*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->moveToThread(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_moveToThread_TypeError:
        const char* overloads[] = {"PySide.QtCore.QThread", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.moveToThread", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_objectName(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // objectName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QObject*>(cppSelf)->objectName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_parent(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QObject*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::setParent(pyResult, self);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // property(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_property_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QObject*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_property_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.property", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_receivers(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: receivers(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // receivers(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_receivers_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // receivers(const char*)const
            // Begin code injection

            // Avoid return +1 because SignalManager connect to "destroyed()" signal to control object timelife
            int ret = cppSelf->receivers(cppArg0);
            if (ret > 0 && ((strcmp(cppArg0, SIGNAL(destroyed())) == 0) || (strcmp(cppArg0, SIGNAL(destroyed(QObject*))) == 0)))
            ret -= PySide::SignalManager::instance().countConnectionsWith(cppSelf);

            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &ret);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_receivers_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.receivers", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_registerUserData(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // registerUserData()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = ::QObject::registerUserData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_removeEventFilter(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeEventFilter(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // removeEventFilter(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_removeEventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeEventFilter(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeEventFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_removeEventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.removeEventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_sender(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sender()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QObject*>(cppSelf)->sender();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_senderSignalIndex(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // senderSignalIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QObject*>(cppSelf)->senderSignalIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_setObjectName(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setObjectName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setObjectName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_setObjectName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setObjectName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setObjectName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_setObjectName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.setObjectName", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_setParent(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setParent(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // setParent(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_setParent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParent(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setParent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArg, self);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_setParent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.setParent", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(const char*,QVariant)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setProperty(const char*,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_setProperty_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProperty(const char*,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_setProperty_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.setProperty", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_signalsBlocked(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // signalsBlocked()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QObject*>(cppSelf)->signalsBlocked();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_startTimer(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startTimer(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // startTimer(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_startTimer_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // startTimer(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->startTimer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_startTimer_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.startTimer", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_thread(PyObject* self)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // thread()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QThread * cppResult = const_cast<const ::QObject*>(cppSelf)->thread();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTHREAD_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QObjectFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QObject::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QObjectFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QObject.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_tr(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.tr(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.tr(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:tr", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: tr(const char*,const char*,int)
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // tr(const char*,const char*,int)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // tr(const char*,const char*,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // tr(const char*,const char*,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_tr_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__2");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.tr(): got multiple values for keyword argument 'arg__2'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                    goto Sbk_QObjectFunc_tr_TypeError;
            }
            value = PyDict_GetItemString(kwds, "arg__3");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.tr(): got multiple values for keyword argument 'arg__3'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QObjectFunc_tr_TypeError;
            }
        }
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)
        const char* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        SBK_UNUSED(cppArg1)
        int cppArg2 = -1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        SBK_UNUSED(cppArg2)

        if (!PyErr_Occurred()) {
            // tr(const char*,const char*,int)
            // Begin code injection

            QString result;
            if (QCoreApplication::instance()) {
                PyObject *klass = PyObject_GetAttrString(self, "__class__");
                PyObject *cname = PyObject_GetAttrString(klass, "__name__");
                result = QString(QCoreApplication::instance()->translate(Shiboken::String::toCString(cname), cppArg0, cppArg1, QCoreApplication::CodecForTr, cppArg2));

                Py_DECREF(klass);
                Py_DECREF(cname);
            } else {
                result = QString(QString::fromLatin1(cppArg0));
            }
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &result);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_tr_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", " SBK_STR_NAME " = None, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.tr", overloads);
        return 0;
}

static PyObject* Sbk_QObjectFunc_trUtf8(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:trUtf8", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: trUtf8(PyUnicode,const char*,int)
    // 1: trUtf8(const char*,const char*,int)
    if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // trUtf8(const char*,const char*,int)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // trUtf8(const char*,const char*,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // trUtf8(const char*,const char*,int)
            }
        }
    } else if (PyUnicode_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 0; // trUtf8(PyUnicode,const char*,int)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // trUtf8(PyUnicode,const char*,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // trUtf8(PyUnicode,const char*,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QObjectFunc_trUtf8_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // trUtf8(PyUnicode arg__1, const char * arg__2, int arg__3)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__2");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): got multiple values for keyword argument 'arg__2'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QObjectFunc_trUtf8_TypeError;
                }
                value = PyDict_GetItemString(kwds, "arg__3");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): got multiple values for keyword argument 'arg__3'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QObjectFunc_trUtf8_TypeError;
                }
            }
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)

            if (!PyErr_Occurred()) {
                // trUtf8(PyUnicode,const char*,int)
                // Begin code injection

                // TEMPLATE - translate_utf8 - START
                if (QCoreApplication::instance()) {
                Shiboken::AutoDecRef klass(PyObject_GetAttrString(self, "__class__"));
                Shiboken::AutoDecRef cname(PyObject_GetAttrString(klass, "__name__"));
                Shiboken::AutoDecRef str(PyUnicode_AsUTF8String(pyArgs[0]));
                QString result = QCoreApplication::instance()->translate(Shiboken::String::toCString(cname.object()), Shiboken::String::toCString(str.object()), cppArg1, QCoreApplication::UnicodeUTF8, cppArg2);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &result);
                } else {
                Py_INCREF(pyArgs[1-1]);
                pyResult = pyArgs[1-1];
                }
                // TEMPLATE - translate_utf8 - END

                // End of code injection


            }
            break;
        }
        case 1: // trUtf8(const char * arg__1, const char * arg__2, int arg__3)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__2");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): got multiple values for keyword argument 'arg__2'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QObjectFunc_trUtf8_TypeError;
                }
                value = PyDict_GetItemString(kwds, "arg__3");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QObject.trUtf8(): got multiple values for keyword argument 'arg__3'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QObjectFunc_trUtf8_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)

            if (!PyErr_Occurred()) {
                // trUtf8(const char*,const char*,int)
                // Begin code injection

                // TEMPLATE - translate_utf8 - START
                if (QCoreApplication::instance()) {
                Shiboken::AutoDecRef klass(PyObject_GetAttrString(self, "__class__"));
                Shiboken::AutoDecRef cname(PyObject_GetAttrString(klass, "__name__"));

                QString result = QCoreApplication::instance()->translate(Shiboken::String::toCString(cname.object()), cppArg0, cppArg1, QCoreApplication::UnicodeUTF8, cppArg2);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &result);
                } else {
                Py_INCREF(pyArgs[1-1]);
                pyResult = pyArgs[1-1];
                }
                // TEMPLATE - translate_utf8 - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QObjectFunc_trUtf8_TypeError:
        const char* overloads[] = {"unicode, " SBK_STR_NAME " = None, int = -1", "" SBK_STR_NAME ", " SBK_STR_NAME " = None, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QObject.trUtf8", overloads);
        return 0;
}

static PyMethodDef Sbk_QObjectMethod_connect = {
    "connect", (PyCFunction)Sbk_QObjectFunc_connect, METH_VARARGS|METH_KEYWORDS|METH_STATIC
};

static PyMethodDef Sbk_QObjectMethod_disconnect = {
    "disconnect", (PyCFunction)Sbk_QObjectFunc_disconnect, METH_VARARGS|METH_KEYWORDS|METH_STATIC
};

static PyMethodDef Sbk_QObject_methods[] = {
    {"blockSignals", (PyCFunction)Sbk_QObjectFunc_blockSignals, METH_O},
    {"childEvent", (PyCFunction)Sbk_QObjectFunc_childEvent, METH_O},
    {"children", (PyCFunction)Sbk_QObjectFunc_children, METH_NOARGS},
    Sbk_QObjectMethod_connect,
    {"connectNotify", (PyCFunction)Sbk_QObjectFunc_connectNotify, METH_O},
    {"customEvent", (PyCFunction)Sbk_QObjectFunc_customEvent, METH_O},
    {"deleteLater", (PyCFunction)Sbk_QObjectFunc_deleteLater, METH_NOARGS},
    Sbk_QObjectMethod_disconnect,
    {"disconnectNotify", (PyCFunction)Sbk_QObjectFunc_disconnectNotify, METH_O},
    {"dumpObjectInfo", (PyCFunction)Sbk_QObjectFunc_dumpObjectInfo, METH_NOARGS},
    {"dumpObjectTree", (PyCFunction)Sbk_QObjectFunc_dumpObjectTree, METH_NOARGS},
    {"dynamicPropertyNames", (PyCFunction)Sbk_QObjectFunc_dynamicPropertyNames, METH_NOARGS},
    {"emit", (PyCFunction)Sbk_QObjectFunc_emit, METH_VARARGS},
    {"event", (PyCFunction)Sbk_QObjectFunc_event, METH_O},
    {"eventFilter", (PyCFunction)Sbk_QObjectFunc_eventFilter, METH_VARARGS},
    {"findChild", (PyCFunction)Sbk_QObjectFunc_findChild, METH_VARARGS|METH_KEYWORDS},
    {"findChildren", (PyCFunction)Sbk_QObjectFunc_findChildren, METH_VARARGS|METH_KEYWORDS},
    {"inherits", (PyCFunction)Sbk_QObjectFunc_inherits, METH_O},
    {"installEventFilter", (PyCFunction)Sbk_QObjectFunc_installEventFilter, METH_O},
    {"isWidgetType", (PyCFunction)Sbk_QObjectFunc_isWidgetType, METH_NOARGS},
    {"killTimer", (PyCFunction)Sbk_QObjectFunc_killTimer, METH_O},
    {"metaObject", (PyCFunction)Sbk_QObjectFunc_metaObject, METH_NOARGS},
    {"moveToThread", (PyCFunction)Sbk_QObjectFunc_moveToThread, METH_O},
    {"objectName", (PyCFunction)Sbk_QObjectFunc_objectName, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QObjectFunc_parent, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QObjectFunc_property, METH_O},
    {"receivers", (PyCFunction)Sbk_QObjectFunc_receivers, METH_O},
    {"registerUserData", (PyCFunction)Sbk_QObjectFunc_registerUserData, METH_NOARGS|METH_STATIC},
    {"removeEventFilter", (PyCFunction)Sbk_QObjectFunc_removeEventFilter, METH_O},
    {"sender", (PyCFunction)Sbk_QObjectFunc_sender, METH_NOARGS},
    {"senderSignalIndex", (PyCFunction)Sbk_QObjectFunc_senderSignalIndex, METH_NOARGS},
    {"setObjectName", (PyCFunction)Sbk_QObjectFunc_setObjectName, METH_O},
    {"setParent", (PyCFunction)Sbk_QObjectFunc_setParent, METH_O},
    {"setProperty", (PyCFunction)Sbk_QObjectFunc_setProperty, METH_VARARGS},
    {"signalsBlocked", (PyCFunction)Sbk_QObjectFunc_signalsBlocked, METH_NOARGS},
    {"startTimer", (PyCFunction)Sbk_QObjectFunc_startTimer, METH_O},
    {"thread", (PyCFunction)Sbk_QObjectFunc_thread, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QObjectFunc_timerEvent, METH_O},
    {"tr", (PyCFunction)Sbk_QObjectFunc_tr, METH_VARARGS|METH_KEYWORDS},
    {"trUtf8", (PyCFunction)Sbk_QObjectFunc_trUtf8, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

static PyObject* Sbk_QObject_getattro(PyObject* self, PyObject* name)
{
    if (self) {
        // Search the method in the instance dict
        if (reinterpret_cast<SbkObject*>(self)->ob_dict) {
            PyObject* meth = PyDict_GetItem(reinterpret_cast<SbkObject*>(self)->ob_dict, name);
            if (meth) {
                Py_INCREF(meth);
                return meth;
            }
        }
        // Search the method in the type dict
        if (Shiboken::Object::isUserType(self)) {
            PyObject* meth = PyDict_GetItem(self->ob_type->tp_dict, name);
            if (meth)
                return PyFunction_Check(meth) ? SBK_PyMethod_New(meth, self) : PySide::getMetaDataFromQObject(((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self)), self, name);
        }
        static PyMethodDef non_static_Sbk_QObjectMethod_connect = {
            Sbk_QObjectMethod_connect.ml_name,
            Sbk_QObjectMethod_connect.ml_meth,
            Sbk_QObjectMethod_connect.ml_flags & (~METH_STATIC),
            Sbk_QObjectMethod_connect.ml_doc,
        };
        if (Shiboken::String::compare(name, "connect") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QObjectMethod_connect, self, 0);
        static PyMethodDef non_static_Sbk_QObjectMethod_disconnect = {
            Sbk_QObjectMethod_disconnect.ml_name,
            Sbk_QObjectMethod_disconnect.ml_meth,
            Sbk_QObjectMethod_disconnect.ml_flags & (~METH_STATIC),
            Sbk_QObjectMethod_disconnect.ml_doc,
        };
        if (Shiboken::String::compare(name, "disconnect") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QObjectMethod_disconnect, self, 0);
    }
    return PySide::getMetaDataFromQObject(((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self)), self, name);
}

static int Sbk_QObject_setattro(PyObject* self, PyObject* name, PyObject* value)
{
    Shiboken::AutoDecRef pp(reinterpret_cast<PyObject*>(PySide::Property::getObject(self, name)));
    if (!pp.isNull())
        return PySide::Property::setValue(reinterpret_cast<PySideProperty*>(pp.object()), self, value);
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_QObject_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QObject_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QObject_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QObject",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         Sbk_QObject_getattro,
    /*tp_setattro*/         Sbk_QObject_setattro,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QObject_traverse,
    /*tp_clear*/            Sbk_QObject_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QObject_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QObject_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QObject_PythonToCpp_QObject_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QObject_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QObject_PythonToCpp_QObject_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QObject_Type))
        return QObject_PythonToCpp_QObject_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QObject_PTR_CppToPython_QObject(const void* cppIn) {
    return PySide::getWrapperForQObject((::QObject*)cppIn, &Sbk_QObject_Type);

}

void init_QObject(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QObject_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QObject", "QObject*",
        &Sbk_QObject_Type, &Shiboken::callCppDestructor< ::QObject >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QObject_Type,
        QObject_PythonToCpp_QObject_PTR,
        is_QObject_PythonToCpp_QObject_PTR_Convertible,
        QObject_PTR_CppToPython_QObject);

    Shiboken::Conversions::registerConverterName(converter, "QObject");
    Shiboken::Conversions::registerConverterName(converter, "QObject*");
    Shiboken::Conversions::registerConverterName(converter, "QObject&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QObject).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QObjectWrapper).name());



    PySide::Signal::registerSignals(&Sbk_QObject_Type, &::QObject::staticMetaObject);


    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QObject_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QObject_Type, &::QObject::staticMetaObject, sizeof(::QObject));
}

