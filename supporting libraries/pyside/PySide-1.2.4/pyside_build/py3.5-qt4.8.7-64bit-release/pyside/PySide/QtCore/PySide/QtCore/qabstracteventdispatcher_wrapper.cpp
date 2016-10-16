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

#include "qabstracteventdispatcher_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <qabstracteventdispatcher.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsocketnotifier.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QAbstractEventDispatcherWrapper::QAbstractEventDispatcherWrapper(QObject * parent) : QAbstractEventDispatcher(parent) {
    // ... middle
}

void QAbstractEventDispatcherWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractEventDispatcherWrapper::closingDown()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closingDown"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractEventDispatcher::closingDown();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractEventDispatcherWrapper::connectNotify(const char * signal)
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

void QAbstractEventDispatcherWrapper::customEvent(QEvent * arg__1)
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

void QAbstractEventDispatcherWrapper::disconnectNotify(const char * signal)
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

bool QAbstractEventDispatcherWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractEventDispatcherWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QAbstractEventDispatcherWrapper::flush()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "flush"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.flush()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QAbstractEventDispatcherWrapper::hasPendingEvents()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasPendingEvents"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.hasPendingEvents()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.hasPendingEvents", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractEventDispatcherWrapper::interrupt()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "interrupt"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.interrupt()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QAbstractEventDispatcherWrapper::processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "processEvents"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.processEvents()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), &flags)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.processEvents", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractEventDispatcherWrapper::registerSocketNotifier(QSocketNotifier * notifier)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "registerSocketNotifier"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registerSocketNotifier()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSOCKETNOTIFIER_IDX], notifier)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractEventDispatcherWrapper::registerTimer(int timerId, int interval, QObject * object)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "registerTimer"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registerTimer()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        timerId,
        interval,
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], object)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QList<QPair<int, int > > QAbstractEventDispatcherWrapper::registeredTimers(QObject * object) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QPair<int, int > >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "registeredTimers"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registeredTimers()' not implemented.");
        return ::QList<QPair<int, int > >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], object)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QPair<int, int > >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_INT_INT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.registeredTimers", "list", pyResult->ob_type->tp_name);
        return ::QList<QPair<int, int > >();
    }
    ::QList<QPair<int, int > > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractEventDispatcherWrapper::startingUp()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startingUp"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractEventDispatcher::startingUp();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractEventDispatcherWrapper::timerEvent(QTimerEvent * arg__1)
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

void QAbstractEventDispatcherWrapper::unregisterSocketNotifier(QSocketNotifier * notifier)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unregisterSocketNotifier"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterSocketNotifier()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSOCKETNOTIFIER_IDX], notifier)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QAbstractEventDispatcherWrapper::unregisterTimer(int timerId)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unregisterTimer"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterTimer()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        timerId
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.unregisterTimer", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractEventDispatcherWrapper::unregisterTimers(QObject * object)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unregisterTimers"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterTimers()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], object)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractEventDispatcher.unregisterTimers", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractEventDispatcherWrapper::wakeUp()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wakeUp"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.wakeUp()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

const QMetaObject* QAbstractEventDispatcherWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractEventDispatcher::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractEventDispatcherWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractEventDispatcher::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractEventDispatcherWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractEventDispatcherWrapper* >(this));
        return QAbstractEventDispatcher::qt_metacast(_clname);
}

QAbstractEventDispatcherWrapper::~QAbstractEventDispatcherWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractEventDispatcher_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractEventDispatcher' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractEventDispatcher >()))
        return -1;

    ::QAbstractEventDispatcherWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QAbstractEventDispatcher", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractEventDispatcher(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QAbstractEventDispatcher(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAbstractEventDispatcher(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcher_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractEventDispatcher(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractEventDispatcher_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractEventDispatcher(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractEventDispatcherWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractEventDispatcherWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractEventDispatcher >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractEventDispatcher_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QAbstractEventDispatcher_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractEventDispatcher", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_closingDown(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closingDown()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractEventDispatcher::closingDown() : cppSelf->closingDown();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_flush(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flush()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.flush()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->flush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_hasPendingEvents(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasPendingEvents()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.hasPendingEvents()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->hasPendingEvents();
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

static PyObject* Sbk_QAbstractEventDispatcherFunc_instance(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractEventDispatcher.instance(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:instance", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: instance(QThread*)
    if (numArgs == 0) {
        overloadId = 0; // instance(QThread*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTHREAD_IDX], (pyArgs[0])))) {
        overloadId = 0; // instance(QThread*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_instance_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "thread");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QAbstractEventDispatcher.instance(): got multiple values for keyword argument 'thread'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTHREAD_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractEventDispatcherFunc_instance_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QThread* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // instance(QThread*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractEventDispatcher * cppResult = ::QAbstractEventDispatcher::instance(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_instance_TypeError:
        const char* overloads[] = {"PySide.QtCore.QThread = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractEventDispatcher.instance", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_interrupt(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // interrupt()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.interrupt()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->interrupt();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_processEvents(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_processEvents_TypeError;

    // Call function/method
    {
        ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = ((::QFlags<QEventLoop::ProcessEventsFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.processEvents()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->processEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_processEvents_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEventLoop.ProcessEventsFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.processEvents", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_registerSocketNotifier(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: registerSocketNotifier(QSocketNotifier*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSOCKETNOTIFIER_IDX], (pyArg)))) {
        overloadId = 0; // registerSocketNotifier(QSocketNotifier*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_registerSocketNotifier_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSocketNotifier* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // registerSocketNotifier(QSocketNotifier*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registerSocketNotifier()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->registerSocketNotifier(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractEventDispatcherFunc_registerSocketNotifier_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSocketNotifier", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.registerSocketNotifier", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_registerTimer(PyObject* self, PyObject* args)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerTimer", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: registerTimer(int,QObject*)
    // 1: registerTimer(int,int,QObject*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
            overloadId = 1; // registerTimer(int,int,QObject*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // registerTimer(int,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_registerTimer_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // registerTimer(int interval, QObject * object)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // registerTimer(int,QObject*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->registerTimer(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // registerTimer(int timerId, int interval, QObject * object)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // registerTimer(int,int,QObject*)
                if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                    PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registerTimer()' not implemented.");
                    return 0;
                }
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->registerTimer(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_registerTimer_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QObject", "int, int, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QAbstractEventDispatcher.registerTimer", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_registeredTimers(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: registeredTimers(QObject*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // registeredTimers(QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_registeredTimers_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // registeredTimers(QObject*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.registeredTimers()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPair<int, int > > cppResult = const_cast<const ::QAbstractEventDispatcher*>(cppSelf)->registeredTimers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_INT_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_registeredTimers_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.registeredTimers", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_startingUp(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startingUp()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractEventDispatcher::startingUp() : cppSelf->startingUp();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_unregisterSocketNotifier(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unregisterSocketNotifier(QSocketNotifier*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSOCKETNOTIFIER_IDX], (pyArg)))) {
        overloadId = 0; // unregisterSocketNotifier(QSocketNotifier*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_unregisterSocketNotifier_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSocketNotifier* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterSocketNotifier(QSocketNotifier*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterSocketNotifier()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unregisterSocketNotifier(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractEventDispatcherFunc_unregisterSocketNotifier_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSocketNotifier", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.unregisterSocketNotifier", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_unregisterTimer(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unregisterTimer(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // unregisterTimer(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_unregisterTimer_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterTimer(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterTimer()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->unregisterTimer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_unregisterTimer_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.unregisterTimer", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_unregisterTimers(PyObject* self, PyObject* pyArg)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unregisterTimers(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // unregisterTimers(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractEventDispatcherFunc_unregisterTimers_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterTimers(QObject*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.unregisterTimers()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->unregisterTimers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractEventDispatcherFunc_unregisterTimers_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QAbstractEventDispatcher.unregisterTimers", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractEventDispatcherFunc_wakeUp(PyObject* self)
{
    ::QAbstractEventDispatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractEventDispatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wakeUp()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractEventDispatcher.wakeUp()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->wakeUp();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QAbstractEventDispatcher_methods[] = {
    {"closingDown", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_closingDown, METH_NOARGS},
    {"flush", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_flush, METH_NOARGS},
    {"hasPendingEvents", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_hasPendingEvents, METH_NOARGS},
    {"instance", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_instance, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"interrupt", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_interrupt, METH_NOARGS},
    {"processEvents", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_processEvents, METH_O},
    {"registerSocketNotifier", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_registerSocketNotifier, METH_O},
    {"registerTimer", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_registerTimer, METH_VARARGS},
    {"registeredTimers", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_registeredTimers, METH_O},
    {"startingUp", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_startingUp, METH_NOARGS},
    {"unregisterSocketNotifier", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_unregisterSocketNotifier, METH_O},
    {"unregisterTimer", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_unregisterTimer, METH_O},
    {"unregisterTimers", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_unregisterTimers, METH_O},
    {"wakeUp", (PyCFunction)Sbk_QAbstractEventDispatcherFunc_wakeUp, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractEventDispatcher_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractEventDispatcher_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractEventDispatcher_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QAbstractEventDispatcher",
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
    /*tp_traverse*/         Sbk_QAbstractEventDispatcher_traverse,
    /*tp_clear*/            Sbk_QAbstractEventDispatcher_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractEventDispatcher_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractEventDispatcher_Init,
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

static void* Sbk_QAbstractEventDispatcher_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractEventDispatcher*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractEventDispatcher_PythonToCpp_QAbstractEventDispatcher_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractEventDispatcher_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractEventDispatcher_PythonToCpp_QAbstractEventDispatcher_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractEventDispatcher_Type))
        return QAbstractEventDispatcher_PythonToCpp_QAbstractEventDispatcher_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractEventDispatcher_PTR_CppToPython_QAbstractEventDispatcher(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractEventDispatcher*)cppIn, &Sbk_QAbstractEventDispatcher_Type);

}

void init_QAbstractEventDispatcher(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QABSTRACTEVENTDISPATCHER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractEventDispatcher_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractEventDispatcher", "QAbstractEventDispatcher*",
        &Sbk_QAbstractEventDispatcher_Type, &Shiboken::callCppDestructor< ::QAbstractEventDispatcher >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractEventDispatcher_Type,
        QAbstractEventDispatcher_PythonToCpp_QAbstractEventDispatcher_PTR,
        is_QAbstractEventDispatcher_PythonToCpp_QAbstractEventDispatcher_PTR_Convertible,
        QAbstractEventDispatcher_PTR_CppToPython_QAbstractEventDispatcher);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractEventDispatcher");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractEventDispatcher*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractEventDispatcher&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractEventDispatcher).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractEventDispatcherWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractEventDispatcher_Type, &Sbk_QAbstractEventDispatcher_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QAbstractEventDispatcher_Type, &::QAbstractEventDispatcher::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractEventDispatcher_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractEventDispatcher_Type, &::QAbstractEventDispatcher::staticMetaObject, sizeof(::QAbstractEventDispatcher));
}
