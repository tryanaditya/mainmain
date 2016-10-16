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

#include "qabstractanimation_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractanimation.h>
#include <qanimationgroup.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QAbstractAnimationWrapper::QAbstractAnimationWrapper(QObject * parent) : QAbstractAnimation(parent) {
    // ... middle
}

void QAbstractAnimationWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractAnimationWrapper::connectNotify(const char * signal)
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

void QAbstractAnimationWrapper::customEvent(QEvent * arg__1)
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

void QAbstractAnimationWrapper::disconnectNotify(const char * signal)
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

int QAbstractAnimationWrapper::duration() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "duration"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAnimation.duration()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAnimation.duration", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractAnimationWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractAnimation::event(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAnimation.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractAnimationWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAnimation.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QAbstractAnimationWrapper::timerEvent(QTimerEvent * arg__1)
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

void QAbstractAnimationWrapper::updateCurrentTime(int currentTime)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateCurrentTime"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAnimation.updateCurrentTime()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        currentTime
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractAnimationWrapper::updateDirection(QAbstractAnimation::Direction direction)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateDirection"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractAnimation::updateDirection(direction);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX]), &direction)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractAnimationWrapper::updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateState"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractAnimation::updateState(newState, oldState);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]), &newState),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]), &oldState)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

const QMetaObject* QAbstractAnimationWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractAnimation::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractAnimationWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractAnimation::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractAnimationWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractAnimationWrapper* >(this));
        return QAbstractAnimation::qt_metacast(_clname);
}

QAbstractAnimationWrapper::~QAbstractAnimationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractAnimation_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractAnimation' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractAnimation >()))
        return -1;

    ::QAbstractAnimationWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QAbstractAnimation", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractAnimation(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QAbstractAnimation(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAbstractAnimation(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimation_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractAnimation(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractAnimation_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractAnimation(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractAnimationWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractAnimationWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractAnimation >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractAnimation_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QAbstractAnimation_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractAnimation", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractAnimationFunc_currentLoop(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentLoop()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->currentLoop();
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

static PyObject* Sbk_QAbstractAnimationFunc_currentLoopTime(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentLoopTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->currentLoopTime();
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

static PyObject* Sbk_QAbstractAnimationFunc_currentTime(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->currentTime();
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

static PyObject* Sbk_QAbstractAnimationFunc_direction(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // direction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractAnimation::Direction cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->direction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAnimationFunc_duration(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // duration()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAnimation.duration()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->duration();
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

static PyObject* Sbk_QAbstractAnimationFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractAnimation::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractAnimationFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.event", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_group(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // group()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAnimationGroup * cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->group();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QANIMATIONGROUP_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAnimationFunc_loopCount(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // loopCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->loopCount();
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

static PyObject* Sbk_QAbstractAnimationFunc_pause(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pause()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pause();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractAnimationFunc_resume(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resume()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resume();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractAnimationFunc_setCurrentTime(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentTime(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentTime(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_setCurrentTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentTime(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_setCurrentTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.setCurrentTime", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_setDirection(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirection(QAbstractAnimation::Direction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDirection(QAbstractAnimation::Direction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_setDirection_TypeError;

    // Call function/method
    {
        ::QAbstractAnimation::Direction cppArg0 = ((::QAbstractAnimation::Direction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDirection(QAbstractAnimation::Direction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_setDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation.Direction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.setDirection", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_setLoopCount(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLoopCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLoopCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_setLoopCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLoopCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLoopCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_setLoopCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.setLoopCount", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_setPaused(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPaused(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setPaused(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_setPaused_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPaused(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPaused(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_setPaused_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.setPaused", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_start(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractAnimation.start(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:start", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: start(QAbstractAnimation::DeletionPolicy)
    if (numArgs == 0) {
        overloadId = 0; // start(QAbstractAnimation::DeletionPolicy)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX]), (pyArgs[0])))) {
        overloadId = 0; // start(QAbstractAnimation::DeletionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_start_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "policy");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractAnimation.start(): got multiple values for keyword argument 'policy'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX]), (pyArgs[0]))))
                    goto Sbk_QAbstractAnimationFunc_start_TypeError;
            }
        }
        ::QAbstractAnimation::DeletionPolicy cppArg0 = QAbstractAnimation::KeepWhenStopped;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // start(QAbstractAnimation::DeletionPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_start_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation.DeletionPolicy = KeepWhenStopped", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractAnimation.start", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_state(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractAnimation::State cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAnimationFunc_stop(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractAnimationFunc_totalDuration(PyObject* self)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // totalDuration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractAnimation*>(cppSelf)->totalDuration();
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

static PyObject* Sbk_QAbstractAnimationFunc_updateCurrentTime(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateCurrentTime(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // updateCurrentTime(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_updateCurrentTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // updateCurrentTime(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAnimation.updateCurrentTime()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateCurrentTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_updateCurrentTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.updateCurrentTime", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_updateDirection(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateDirection(QAbstractAnimation::Direction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // updateDirection(QAbstractAnimation::Direction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_updateDirection_TypeError;

    // Call function/method
    {
        ::QAbstractAnimation::Direction cppArg0 = ((::QAbstractAnimation::Direction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // updateDirection(QAbstractAnimation::Direction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractAnimation::updateDirection(cppArg0) : cppSelf->updateDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_updateDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation.Direction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractAnimation.updateDirection", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAnimationFunc_updateState(PyObject* self, PyObject* args)
{
    ::QAbstractAnimation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAnimation*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "updateState", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: updateState(QAbstractAnimation::State,QAbstractAnimation::State)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // updateState(QAbstractAnimation::State,QAbstractAnimation::State)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAnimationFunc_updateState_TypeError;

    // Call function/method
    {
        ::QAbstractAnimation::State cppArg0 = ((::QAbstractAnimation::State)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QAbstractAnimation::State cppArg1 = ((::QAbstractAnimation::State)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // updateState(QAbstractAnimation::State,QAbstractAnimation::State)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractAnimation::updateState(cppArg0, cppArg1) : cppSelf->updateState(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractAnimationFunc_updateState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation.State, PySide.QtCore.QAbstractAnimation.State", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractAnimation.updateState", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractAnimation_methods[] = {
    {"currentLoop", (PyCFunction)Sbk_QAbstractAnimationFunc_currentLoop, METH_NOARGS},
    {"currentLoopTime", (PyCFunction)Sbk_QAbstractAnimationFunc_currentLoopTime, METH_NOARGS},
    {"currentTime", (PyCFunction)Sbk_QAbstractAnimationFunc_currentTime, METH_NOARGS},
    {"direction", (PyCFunction)Sbk_QAbstractAnimationFunc_direction, METH_NOARGS},
    {"duration", (PyCFunction)Sbk_QAbstractAnimationFunc_duration, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QAbstractAnimationFunc_event, METH_O},
    {"group", (PyCFunction)Sbk_QAbstractAnimationFunc_group, METH_NOARGS},
    {"loopCount", (PyCFunction)Sbk_QAbstractAnimationFunc_loopCount, METH_NOARGS},
    {"pause", (PyCFunction)Sbk_QAbstractAnimationFunc_pause, METH_NOARGS},
    {"resume", (PyCFunction)Sbk_QAbstractAnimationFunc_resume, METH_NOARGS},
    {"setCurrentTime", (PyCFunction)Sbk_QAbstractAnimationFunc_setCurrentTime, METH_O},
    {"setDirection", (PyCFunction)Sbk_QAbstractAnimationFunc_setDirection, METH_O},
    {"setLoopCount", (PyCFunction)Sbk_QAbstractAnimationFunc_setLoopCount, METH_O},
    {"setPaused", (PyCFunction)Sbk_QAbstractAnimationFunc_setPaused, METH_O},
    {"start", (PyCFunction)Sbk_QAbstractAnimationFunc_start, METH_VARARGS|METH_KEYWORDS},
    {"state", (PyCFunction)Sbk_QAbstractAnimationFunc_state, METH_NOARGS},
    {"stop", (PyCFunction)Sbk_QAbstractAnimationFunc_stop, METH_NOARGS},
    {"totalDuration", (PyCFunction)Sbk_QAbstractAnimationFunc_totalDuration, METH_NOARGS},
    {"updateCurrentTime", (PyCFunction)Sbk_QAbstractAnimationFunc_updateCurrentTime, METH_O},
    {"updateDirection", (PyCFunction)Sbk_QAbstractAnimationFunc_updateDirection, METH_O},
    {"updateState", (PyCFunction)Sbk_QAbstractAnimationFunc_updateState, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractAnimation_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractAnimation_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractAnimation_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QAbstractAnimation",
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
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QAbstractAnimation_traverse,
    /*tp_clear*/            Sbk_QAbstractAnimation_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractAnimation_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractAnimation_Init,
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

static void* Sbk_QAbstractAnimation_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractAnimation*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QAbstractAnimation_Direction_PythonToCpp_QAbstractAnimation_Direction(PyObject* pyIn, void* cppOut) {
    *((::QAbstractAnimation::Direction*)cppOut) = (::QAbstractAnimation::Direction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractAnimation_Direction_PythonToCpp_QAbstractAnimation_Direction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX]))
        return QAbstractAnimation_Direction_PythonToCpp_QAbstractAnimation_Direction;
    return 0;
}
static PyObject* QAbstractAnimation_Direction_CppToPython_QAbstractAnimation_Direction(const void* cppIn) {
    int castCppIn = *((::QAbstractAnimation::Direction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX], castCppIn);

}

static void QAbstractAnimation_State_PythonToCpp_QAbstractAnimation_State(PyObject* pyIn, void* cppOut) {
    *((::QAbstractAnimation::State*)cppOut) = (::QAbstractAnimation::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractAnimation_State_PythonToCpp_QAbstractAnimation_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX]))
        return QAbstractAnimation_State_PythonToCpp_QAbstractAnimation_State;
    return 0;
}
static PyObject* QAbstractAnimation_State_CppToPython_QAbstractAnimation_State(const void* cppIn) {
    int castCppIn = *((::QAbstractAnimation::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX], castCppIn);

}

static void QAbstractAnimation_DeletionPolicy_PythonToCpp_QAbstractAnimation_DeletionPolicy(PyObject* pyIn, void* cppOut) {
    *((::QAbstractAnimation::DeletionPolicy*)cppOut) = (::QAbstractAnimation::DeletionPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractAnimation_DeletionPolicy_PythonToCpp_QAbstractAnimation_DeletionPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX]))
        return QAbstractAnimation_DeletionPolicy_PythonToCpp_QAbstractAnimation_DeletionPolicy;
    return 0;
}
static PyObject* QAbstractAnimation_DeletionPolicy_CppToPython_QAbstractAnimation_DeletionPolicy(const void* cppIn) {
    int castCppIn = *((::QAbstractAnimation::DeletionPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractAnimation_PythonToCpp_QAbstractAnimation_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractAnimation_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractAnimation_PythonToCpp_QAbstractAnimation_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractAnimation_Type))
        return QAbstractAnimation_PythonToCpp_QAbstractAnimation_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractAnimation_PTR_CppToPython_QAbstractAnimation(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractAnimation*)cppIn, &Sbk_QAbstractAnimation_Type);

}

void init_QAbstractAnimation(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractAnimation_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractAnimation", "QAbstractAnimation*",
        &Sbk_QAbstractAnimation_Type, &Shiboken::callCppDestructor< ::QAbstractAnimation >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractAnimation_Type,
        QAbstractAnimation_PythonToCpp_QAbstractAnimation_PTR,
        is_QAbstractAnimation_PythonToCpp_QAbstractAnimation_PTR_Convertible,
        QAbstractAnimation_PTR_CppToPython_QAbstractAnimation);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractAnimation).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractAnimationWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractAnimation_Type, &Sbk_QAbstractAnimation_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Direction'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractAnimation_Type,
        "Direction",
        "PySide.QtCore.QAbstractAnimation.Direction",
        "QAbstractAnimation::Direction");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX],
        &Sbk_QAbstractAnimation_Type, "Forward", (long) QAbstractAnimation::Forward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX],
        &Sbk_QAbstractAnimation_Type, "Backward", (long) QAbstractAnimation::Backward))
        return ;
    // Register converter for enum 'QAbstractAnimation::Direction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX],
            QAbstractAnimation_Direction_CppToPython_QAbstractAnimation_Direction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractAnimation_Direction_PythonToCpp_QAbstractAnimation_Direction,
            is_QAbstractAnimation_Direction_PythonToCpp_QAbstractAnimation_Direction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DIRECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation::Direction");
        Shiboken::Conversions::registerConverterName(converter, "Direction");
    }
    // End of 'Direction' enum.

    // Initialization of enum 'State'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractAnimation_Type,
        "State",
        "PySide.QtCore.QAbstractAnimation.State",
        "QAbstractAnimation::State");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX],
        &Sbk_QAbstractAnimation_Type, "Stopped", (long) QAbstractAnimation::Stopped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX],
        &Sbk_QAbstractAnimation_Type, "Paused", (long) QAbstractAnimation::Paused))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX],
        &Sbk_QAbstractAnimation_Type, "Running", (long) QAbstractAnimation::Running))
        return ;
    // Register converter for enum 'QAbstractAnimation::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX],
            QAbstractAnimation_State_CppToPython_QAbstractAnimation_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractAnimation_State_PythonToCpp_QAbstractAnimation_State,
            is_QAbstractAnimation_State_PythonToCpp_QAbstractAnimation_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'DeletionPolicy'.
    SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractAnimation_Type,
        "DeletionPolicy",
        "PySide.QtCore.QAbstractAnimation.DeletionPolicy",
        "QAbstractAnimation::DeletionPolicy");
    if (!SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX],
        &Sbk_QAbstractAnimation_Type, "KeepWhenStopped", (long) QAbstractAnimation::KeepWhenStopped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX],
        &Sbk_QAbstractAnimation_Type, "DeleteWhenStopped", (long) QAbstractAnimation::DeleteWhenStopped))
        return ;
    // Register converter for enum 'QAbstractAnimation::DeletionPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX],
            QAbstractAnimation_DeletionPolicy_CppToPython_QAbstractAnimation_DeletionPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractAnimation_DeletionPolicy_PythonToCpp_QAbstractAnimation_DeletionPolicy,
            is_QAbstractAnimation_DeletionPolicy_PythonToCpp_QAbstractAnimation_DeletionPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_DELETIONPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractAnimation::DeletionPolicy");
        Shiboken::Conversions::registerConverterName(converter, "DeletionPolicy");
    }
    // End of 'DeletionPolicy' enum.

    PySide::Signal::registerSignals(&Sbk_QAbstractAnimation_Type, &::QAbstractAnimation::staticMetaObject);

    qRegisterMetaType< ::QAbstractAnimation::Direction >("QAbstractAnimation::Direction");
    qRegisterMetaType< ::QAbstractAnimation::State >("QAbstractAnimation::State");
    qRegisterMetaType< ::QAbstractAnimation::DeletionPolicy >("QAbstractAnimation::DeletionPolicy");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractAnimation_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractAnimation_Type, &::QAbstractAnimation::staticMetaObject, sizeof(::QAbstractAnimation));
}
