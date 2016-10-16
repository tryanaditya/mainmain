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
#include "pyside_qtgui_python.h"

#include "qdatawidgetmapper_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractitemdelegate.h>
#include <qabstractitemmodel.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdatawidgetmapper.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QDataWidgetMapperWrapper::QDataWidgetMapperWrapper(QObject * parent) : QDataWidgetMapper(parent) {
    // ... middle
}

void QDataWidgetMapperWrapper::childEvent(QChildEvent * arg__1)
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

void QDataWidgetMapperWrapper::connectNotify(const char * signal)
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

void QDataWidgetMapperWrapper::customEvent(QEvent * arg__1)
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

void QDataWidgetMapperWrapper::disconnectNotify(const char * signal)
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

bool QDataWidgetMapperWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDataWidgetMapper.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDataWidgetMapperWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDataWidgetMapper.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDataWidgetMapperWrapper::setCurrentIndex(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setCurrentIndex"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDataWidgetMapper::setCurrentIndex(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QDataWidgetMapperWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QDataWidgetMapperWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDataWidgetMapper::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDataWidgetMapperWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDataWidgetMapper::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDataWidgetMapperWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDataWidgetMapperWrapper* >(this));
        return QDataWidgetMapper::qt_metacast(_clname);
}

QDataWidgetMapperWrapper::~QDataWidgetMapperWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDataWidgetMapper_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDataWidgetMapper >()))
        return -1;

    ::QDataWidgetMapperWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QDataWidgetMapper", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDataWidgetMapper(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QDataWidgetMapper(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QDataWidgetMapper(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapper_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDataWidgetMapper(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QDataWidgetMapper_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QDataWidgetMapper(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QDataWidgetMapperWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QDataWidgetMapperWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDataWidgetMapper >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDataWidgetMapper_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDataWidgetMapper_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDataWidgetMapper", overloads);
        return -1;
}

static PyObject* Sbk_QDataWidgetMapperFunc_addMapping(PyObject* self, PyObject* args)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addMapping", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addMapping(QWidget*,int)
    // 1: addMapping(QWidget*,int,QByteArray)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addMapping(QWidget*,int)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2])))) {
            overloadId = 1; // addMapping(QWidget*,int,QByteArray)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_addMapping_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addMapping(QWidget * widget, int section)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addMapping(QWidget*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addMapping(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 1: // addMapping(QWidget * widget, int section, const QByteArray & propertyName)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QByteArray cppArg2_local = ::QByteArray();
            ::QByteArray* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // addMapping(QWidget*,int,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addMapping(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_addMapping_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, int", "PySide.QtGui.QWidget, int, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDataWidgetMapper.addMapping", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_clearMapping(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMapping()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMapping();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataWidgetMapperFunc_currentIndex(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->currentIndex();
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

static PyObject* Sbk_QDataWidgetMapperFunc_itemDelegate(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // itemDelegate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemDelegate * cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->itemDelegate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataWidgetMapperFunc_mappedPropertyName(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mappedPropertyName(QWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // mappedPropertyName(QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_mappedPropertyName_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mappedPropertyName(QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->mappedPropertyName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataWidgetMapperFunc_mappedPropertyName_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.mappedPropertyName", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_mappedSection(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mappedSection(QWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // mappedSection(QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_mappedSection_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mappedSection(QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->mappedSection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataWidgetMapperFunc_mappedSection_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.mappedSection", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_mappedWidgetAt(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mappedWidgetAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // mappedWidgetAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_mappedWidgetAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mappedWidgetAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->mappedWidgetAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataWidgetMapperFunc_mappedWidgetAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.mappedWidgetAt", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_model(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemModel * cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataWidgetMapperFunc_orientation(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // orientation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::Orientation cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->orientation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataWidgetMapperFunc_removeMapping(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeMapping(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // removeMapping(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_removeMapping_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeMapping(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeMapping(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_removeMapping_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.removeMapping", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_revert(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revert()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->revert();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataWidgetMapperFunc_rootIndex(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->rootIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setCurrentIndex(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setCurrentIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDataWidgetMapper::setCurrentIndex(cppArg0) : cppSelf->setCurrentIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setCurrentIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setCurrentIndex", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setCurrentModelIndex(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentModelIndex(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentModelIndex(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setCurrentModelIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCurrentModelIndex(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentModelIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setCurrentModelIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setCurrentModelIndex", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setItemDelegate(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItemDelegate(QAbstractItemDelegate*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], (pyArg)))) {
        overloadId = 0; // setItemDelegate(QAbstractItemDelegate*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setItemDelegate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemDelegate* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setItemDelegate(QAbstractItemDelegate*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemDelegate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setItemDelegate(QAbstractItemDelegate*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setItemDelegate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemDelegate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setItemDelegate", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setModel(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModel(QAbstractItemModel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], (pyArg)))) {
        overloadId = 0; // setModel(QAbstractItemModel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemModel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModel(QAbstractItemModel*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setModel(QAbstractItemModel*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setModel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractItemModel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setModel", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setOrientation(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOrientation(Qt::Orientation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // setOrientation(Qt::Orientation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setOrientation_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOrientation(Qt::Orientation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOrientation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setOrientation_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setOrientation", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setRootIndex(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRootIndex(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // setRootIndex(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setRootIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setRootIndex(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRootIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setRootIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setRootIndex", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_setSubmitPolicy(PyObject* self, PyObject* pyArg)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSubmitPolicy(QDataWidgetMapper::SubmitPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setSubmitPolicy(QDataWidgetMapper::SubmitPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataWidgetMapperFunc_setSubmitPolicy_TypeError;

    // Call function/method
    {
        ::QDataWidgetMapper::SubmitPolicy cppArg0 = ((::QDataWidgetMapper::SubmitPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSubmitPolicy(QDataWidgetMapper::SubmitPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSubmitPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataWidgetMapperFunc_setSubmitPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDataWidgetMapper.SubmitPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDataWidgetMapper.setSubmitPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QDataWidgetMapperFunc_submit(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // submit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->submit();
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

static PyObject* Sbk_QDataWidgetMapperFunc_submitPolicy(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // submitPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataWidgetMapper::SubmitPolicy cppResult = const_cast<const ::QDataWidgetMapper*>(cppSelf)->submitPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataWidgetMapperFunc_toFirst(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toFirst()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toFirst();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataWidgetMapperFunc_toLast(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toLast()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toLast();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataWidgetMapperFunc_toNext(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toNext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toNext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataWidgetMapperFunc_toPrevious(PyObject* self)
{
    ::QDataWidgetMapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataWidgetMapper*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPrevious()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toPrevious();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QDataWidgetMapper_methods[] = {
    {"addMapping", (PyCFunction)Sbk_QDataWidgetMapperFunc_addMapping, METH_VARARGS},
    {"clearMapping", (PyCFunction)Sbk_QDataWidgetMapperFunc_clearMapping, METH_NOARGS},
    {"currentIndex", (PyCFunction)Sbk_QDataWidgetMapperFunc_currentIndex, METH_NOARGS},
    {"itemDelegate", (PyCFunction)Sbk_QDataWidgetMapperFunc_itemDelegate, METH_NOARGS},
    {"mappedPropertyName", (PyCFunction)Sbk_QDataWidgetMapperFunc_mappedPropertyName, METH_O},
    {"mappedSection", (PyCFunction)Sbk_QDataWidgetMapperFunc_mappedSection, METH_O},
    {"mappedWidgetAt", (PyCFunction)Sbk_QDataWidgetMapperFunc_mappedWidgetAt, METH_O},
    {"model", (PyCFunction)Sbk_QDataWidgetMapperFunc_model, METH_NOARGS},
    {"orientation", (PyCFunction)Sbk_QDataWidgetMapperFunc_orientation, METH_NOARGS},
    {"removeMapping", (PyCFunction)Sbk_QDataWidgetMapperFunc_removeMapping, METH_O},
    {"revert", (PyCFunction)Sbk_QDataWidgetMapperFunc_revert, METH_NOARGS},
    {"rootIndex", (PyCFunction)Sbk_QDataWidgetMapperFunc_rootIndex, METH_NOARGS},
    {"setCurrentIndex", (PyCFunction)Sbk_QDataWidgetMapperFunc_setCurrentIndex, METH_O},
    {"setCurrentModelIndex", (PyCFunction)Sbk_QDataWidgetMapperFunc_setCurrentModelIndex, METH_O},
    {"setItemDelegate", (PyCFunction)Sbk_QDataWidgetMapperFunc_setItemDelegate, METH_O},
    {"setModel", (PyCFunction)Sbk_QDataWidgetMapperFunc_setModel, METH_O},
    {"setOrientation", (PyCFunction)Sbk_QDataWidgetMapperFunc_setOrientation, METH_O},
    {"setRootIndex", (PyCFunction)Sbk_QDataWidgetMapperFunc_setRootIndex, METH_O},
    {"setSubmitPolicy", (PyCFunction)Sbk_QDataWidgetMapperFunc_setSubmitPolicy, METH_O},
    {"submit", (PyCFunction)Sbk_QDataWidgetMapperFunc_submit, METH_NOARGS},
    {"submitPolicy", (PyCFunction)Sbk_QDataWidgetMapperFunc_submitPolicy, METH_NOARGS},
    {"toFirst", (PyCFunction)Sbk_QDataWidgetMapperFunc_toFirst, METH_NOARGS},
    {"toLast", (PyCFunction)Sbk_QDataWidgetMapperFunc_toLast, METH_NOARGS},
    {"toNext", (PyCFunction)Sbk_QDataWidgetMapperFunc_toNext, METH_NOARGS},
    {"toPrevious", (PyCFunction)Sbk_QDataWidgetMapperFunc_toPrevious, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDataWidgetMapper_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDataWidgetMapper_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDataWidgetMapper_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDataWidgetMapper",
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
    /*tp_traverse*/         Sbk_QDataWidgetMapper_traverse,
    /*tp_clear*/            Sbk_QDataWidgetMapper_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDataWidgetMapper_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDataWidgetMapper_Init,
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

static void* Sbk_QDataWidgetMapper_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDataWidgetMapper*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QDataWidgetMapper_SubmitPolicy_PythonToCpp_QDataWidgetMapper_SubmitPolicy(PyObject* pyIn, void* cppOut) {
    *((::QDataWidgetMapper::SubmitPolicy*)cppOut) = (::QDataWidgetMapper::SubmitPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDataWidgetMapper_SubmitPolicy_PythonToCpp_QDataWidgetMapper_SubmitPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX]))
        return QDataWidgetMapper_SubmitPolicy_PythonToCpp_QDataWidgetMapper_SubmitPolicy;
    return 0;
}
static PyObject* QDataWidgetMapper_SubmitPolicy_CppToPython_QDataWidgetMapper_SubmitPolicy(const void* cppIn) {
    int castCppIn = *((::QDataWidgetMapper::SubmitPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDataWidgetMapper_PythonToCpp_QDataWidgetMapper_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDataWidgetMapper_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDataWidgetMapper_PythonToCpp_QDataWidgetMapper_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDataWidgetMapper_Type))
        return QDataWidgetMapper_PythonToCpp_QDataWidgetMapper_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDataWidgetMapper_PTR_CppToPython_QDataWidgetMapper(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDataWidgetMapper*)cppIn, &Sbk_QDataWidgetMapper_Type);

}

void init_QDataWidgetMapper(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDataWidgetMapper_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDataWidgetMapper", "QDataWidgetMapper*",
        &Sbk_QDataWidgetMapper_Type, &Shiboken::callCppDestructor< ::QDataWidgetMapper >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDataWidgetMapper_Type,
        QDataWidgetMapper_PythonToCpp_QDataWidgetMapper_PTR,
        is_QDataWidgetMapper_PythonToCpp_QDataWidgetMapper_PTR_Convertible,
        QDataWidgetMapper_PTR_CppToPython_QDataWidgetMapper);

    Shiboken::Conversions::registerConverterName(converter, "QDataWidgetMapper");
    Shiboken::Conversions::registerConverterName(converter, "QDataWidgetMapper*");
    Shiboken::Conversions::registerConverterName(converter, "QDataWidgetMapper&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDataWidgetMapper).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDataWidgetMapperWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDataWidgetMapper_Type, &Sbk_QDataWidgetMapper_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'SubmitPolicy'.
    SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDataWidgetMapper_Type,
        "SubmitPolicy",
        "PySide.QtGui.QDataWidgetMapper.SubmitPolicy",
        "QDataWidgetMapper::SubmitPolicy");
    if (!SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX],
        &Sbk_QDataWidgetMapper_Type, "AutoSubmit", (long) QDataWidgetMapper::AutoSubmit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX],
        &Sbk_QDataWidgetMapper_Type, "ManualSubmit", (long) QDataWidgetMapper::ManualSubmit))
        return ;
    // Register converter for enum 'QDataWidgetMapper::SubmitPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX],
            QDataWidgetMapper_SubmitPolicy_CppToPython_QDataWidgetMapper_SubmitPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDataWidgetMapper_SubmitPolicy_PythonToCpp_QDataWidgetMapper_SubmitPolicy,
            is_QDataWidgetMapper_SubmitPolicy_PythonToCpp_QDataWidgetMapper_SubmitPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDATAWIDGETMAPPER_SUBMITPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDataWidgetMapper::SubmitPolicy");
        Shiboken::Conversions::registerConverterName(converter, "SubmitPolicy");
    }
    // End of 'SubmitPolicy' enum.

    PySide::Signal::registerSignals(&Sbk_QDataWidgetMapper_Type, &::QDataWidgetMapper::staticMetaObject);

    qRegisterMetaType< ::QDataWidgetMapper::SubmitPolicy >("QDataWidgetMapper::SubmitPolicy");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDataWidgetMapper_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDataWidgetMapper_Type, &::QDataWidgetMapper::staticMetaObject, sizeof(::QDataWidgetMapper));
}
