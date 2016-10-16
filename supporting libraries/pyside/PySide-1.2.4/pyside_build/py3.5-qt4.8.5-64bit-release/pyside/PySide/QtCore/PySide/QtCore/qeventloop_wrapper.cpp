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

#include "qeventloop_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QEventLoopWrapper::QEventLoopWrapper(QObject * parent) : QEventLoop(parent) {
    // ... middle
}

void QEventLoopWrapper::childEvent(QChildEvent * arg__1)
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

void QEventLoopWrapper::connectNotify(const char * signal)
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

void QEventLoopWrapper::customEvent(QEvent * arg__1)
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

void QEventLoopWrapper::disconnectNotify(const char * signal)
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

bool QEventLoopWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QEventLoop.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QEventLoopWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QEventLoop.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QEventLoopWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QEventLoopWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QEventLoop::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QEventLoopWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QEventLoop::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QEventLoopWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QEventLoopWrapper* >(this));
        return QEventLoop::qt_metacast(_clname);
}

QEventLoopWrapper::~QEventLoopWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QEventLoop_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QEventLoop >()))
        return -1;

    ::QEventLoopWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QEventLoop", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QEventLoop(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QEventLoop(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QEventLoop(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventLoop_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QEventLoop_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QEventLoop(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QEventLoopWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QEventLoopWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QEventLoop >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QEventLoop_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QEventLoop_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEventLoop", overloads);
        return -1;
}

static PyObject* Sbk_QEventLoopFunc_exec_(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.exec_(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:exec_", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exec(QFlags<QEventLoop::ProcessEventsFlag>)
    if (numArgs == 0) {
        overloadId = 0; // exec(QFlags<QEventLoop::ProcessEventsFlag>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // exec(QFlags<QEventLoop::ProcessEventsFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventLoopFunc_exec__TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.exec_(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0]))))
                    goto Sbk_QEventLoopFunc_exec__TypeError;
            }
        }
        ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = QEventLoop::AllEvents;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // exec(QFlags<QEventLoop::ProcessEventsFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->exec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QEventLoopFunc_exec__TypeError:
        const char* overloads[] = {"PySide.QtCore.QEventLoop.ProcessEventsFlags = QEventLoop.AllEvents", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEventLoop.exec_", overloads);
        return 0;
}

static PyObject* Sbk_QEventLoopFunc_exit(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.exit(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:exit", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exit(int)
    if (numArgs == 0) {
        overloadId = 0; // exit(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // exit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventLoopFunc_exit_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "returnCode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.exit(): got multiple values for keyword argument 'returnCode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QEventLoopFunc_exit_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // exit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->exit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEventLoopFunc_exit_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEventLoop.exit", overloads);
        return 0;
}

static PyObject* Sbk_QEventLoopFunc_isRunning(PyObject* self)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRunning()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QEventLoop*>(cppSelf)->isRunning();
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

static PyObject* Sbk_QEventLoopFunc_processEvents(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.processEvents(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:processEvents", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    // 1: processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
    if (numArgs == 0) {
        overloadId = 0; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventLoopFunc_processEvents_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEventLoop.processEvents(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0]))))
                        goto Sbk_QEventLoopFunc_processEvents_TypeError;
                }
            }
            ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = QEventLoop::AllEvents;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->processEvents(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags, int maximumTime)
        {
            ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = ((::QFlags<QEventLoop::ProcessEventsFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->processEvents(cppArg0, cppArg1);
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

    Sbk_QEventLoopFunc_processEvents_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEventLoop.ProcessEventsFlags = QEventLoop.AllEvents", "PySide.QtCore.QEventLoop.ProcessEventsFlags, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEventLoop.processEvents", overloads);
        return 0;
}

static PyObject* Sbk_QEventLoopFunc_quit(PyObject* self)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // quit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->quit();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QEventLoopFunc_wakeUp(PyObject* self)
{
    ::QEventLoop* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEventLoop*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wakeUp()
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

static PyMethodDef Sbk_QEventLoop_methods[] = {
    {"exec_", (PyCFunction)Sbk_QEventLoopFunc_exec_, METH_VARARGS|METH_KEYWORDS},
    {"exit", (PyCFunction)Sbk_QEventLoopFunc_exit, METH_VARARGS|METH_KEYWORDS},
    {"isRunning", (PyCFunction)Sbk_QEventLoopFunc_isRunning, METH_NOARGS},
    {"processEvents", (PyCFunction)Sbk_QEventLoopFunc_processEvents, METH_VARARGS|METH_KEYWORDS},
    {"quit", (PyCFunction)Sbk_QEventLoopFunc_quit, METH_NOARGS},
    {"wakeUp", (PyCFunction)Sbk_QEventLoopFunc_wakeUp, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QEventLoop_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QEventLoop_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QEventLoop_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QEventLoop",
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
    /*tp_traverse*/         Sbk_QEventLoop_traverse,
    /*tp_clear*/            Sbk_QEventLoop_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QEventLoop_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QEventLoop_Init,
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

static void* Sbk_QEventLoop_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QEventLoop*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QEventLoop::ProcessEventsFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyLong_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyInt_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QEventLoop::ProcessEventsFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyLong_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyInt_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QEventLoop::ProcessEventsFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyLong_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QEventLoop::ProcessEventsFlags)PyInt_AsLong(self);
    cppArg = (QEventLoop::ProcessEventsFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QEventLoop::ProcessEventsFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), self, &cppSelf);
    ::QEventLoop::ProcessEventsFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QEventLoop_ProcessEventsFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QEventLoop_ProcessEventsFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QEventLoop_ProcessEventsFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QEventLoop_ProcessEventsFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QEventLoop_ProcessEventsFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QEventLoop_ProcessEventsFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QEventLoop_ProcessEventsFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QEventLoop_ProcessEventsFlag_PythonToCpp_QEventLoop_ProcessEventsFlag(PyObject* pyIn, void* cppOut) {
    *((::QEventLoop::ProcessEventsFlag*)cppOut) = (::QEventLoop::ProcessEventsFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QEventLoop_ProcessEventsFlag_PythonToCpp_QEventLoop_ProcessEventsFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX]))
        return QEventLoop_ProcessEventsFlag_PythonToCpp_QEventLoop_ProcessEventsFlag;
    return 0;
}
static PyObject* QEventLoop_ProcessEventsFlag_CppToPython_QEventLoop_ProcessEventsFlag(const void* cppIn) {
    int castCppIn = *((::QEventLoop::ProcessEventsFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX], castCppIn);

}

static void QFlags_QEventLoop_ProcessEventsFlag__PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QEventLoop::ProcessEventsFlag>*)cppOut) = ::QFlags<QEventLoop::ProcessEventsFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QEventLoop_ProcessEventsFlag__PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]))
        return QFlags_QEventLoop_ProcessEventsFlag__PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_;
    return 0;
}
static PyObject* QFlags_QEventLoop_ProcessEventsFlag__CppToPython_QFlags_QEventLoop_ProcessEventsFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QEventLoop::ProcessEventsFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]));

}

static void QEventLoop_ProcessEventsFlag_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QEventLoop::ProcessEventsFlag>*)cppOut) = ::QFlags<QEventLoop::ProcessEventsFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QEventLoop_ProcessEventsFlag_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX]))
        return QEventLoop_ProcessEventsFlag_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QEventLoop::ProcessEventsFlag>*)cppOut) = ::QFlags<QEventLoop::ProcessEventsFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QEventLoop_PythonToCpp_QEventLoop_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QEventLoop_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QEventLoop_PythonToCpp_QEventLoop_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QEventLoop_Type))
        return QEventLoop_PythonToCpp_QEventLoop_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QEventLoop_PTR_CppToPython_QEventLoop(const void* cppIn) {
    return PySide::getWrapperForQObject((::QEventLoop*)cppIn, &Sbk_QEventLoop_Type);

}

void init_QEventLoop(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QEventLoop_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QEventLoop", "QEventLoop*",
        &Sbk_QEventLoop_Type, &Shiboken::callCppDestructor< ::QEventLoop >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QEventLoop_Type,
        QEventLoop_PythonToCpp_QEventLoop_PTR,
        is_QEventLoop_PythonToCpp_QEventLoop_PTR_Convertible,
        QEventLoop_PTR_CppToPython_QEventLoop);

    Shiboken::Conversions::registerConverterName(converter, "QEventLoop");
    Shiboken::Conversions::registerConverterName(converter, "QEventLoop*");
    Shiboken::Conversions::registerConverterName(converter, "QEventLoop&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QEventLoop).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QEventLoopWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QEventLoop_Type, &Sbk_QEventLoop_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ProcessEventsFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX] = PySide::QFlags::create("ProcessEventsFlags", &SbkPySide_QtCore_QEventLoop_ProcessEventsFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QEventLoop_Type,
        "ProcessEventsFlag",
        "PySide.QtCore.QEventLoop.ProcessEventsFlag",
        "QEventLoop::ProcessEventsFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "AllEvents", (long) QEventLoop::AllEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "ExcludeUserInputEvents", (long) QEventLoop::ExcludeUserInputEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "ExcludeSocketNotifiers", (long) QEventLoop::ExcludeSocketNotifiers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "WaitForMoreEvents", (long) QEventLoop::WaitForMoreEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "X11ExcludeTimers", (long) QEventLoop::X11ExcludeTimers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "DeferredDeletion", (long) QEventLoop::DeferredDeletion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "EventLoopExec", (long) QEventLoop::EventLoopExec))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
        &Sbk_QEventLoop_Type, "DialogExec", (long) QEventLoop::DialogExec))
        return ;
    // Register converter for enum 'QEventLoop::ProcessEventsFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX],
            QEventLoop_ProcessEventsFlag_CppToPython_QEventLoop_ProcessEventsFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QEventLoop_ProcessEventsFlag_PythonToCpp_QEventLoop_ProcessEventsFlag,
            is_QEventLoop_ProcessEventsFlag_PythonToCpp_QEventLoop_ProcessEventsFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEVENTLOOP_PROCESSEVENTSFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QEventLoop::ProcessEventsFlag");
        Shiboken::Conversions::registerConverterName(converter, "ProcessEventsFlag");
    }
    // Register converter for flag 'QFlags<QEventLoop::ProcessEventsFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX],
            QFlags_QEventLoop_ProcessEventsFlag__CppToPython_QFlags_QEventLoop_ProcessEventsFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QEventLoop_ProcessEventsFlag_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_,
            is_QEventLoop_ProcessEventsFlag_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QEventLoop_ProcessEventsFlag__PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_,
            is_QFlags_QEventLoop_ProcessEventsFlag__PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag_,
            is_number_PythonToCpp_QFlags_QEventLoop_ProcessEventsFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QEventLoop::ProcessEventsFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ProcessEventsFlag>");
    }
    // End of 'ProcessEventsFlag' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QEventLoop_Type, &::QEventLoop::staticMetaObject);

    qRegisterMetaType< ::QEventLoop::ProcessEventsFlag >("QEventLoop::ProcessEventsFlag");
    qRegisterMetaType< ::QEventLoop::ProcessEventsFlags >("QEventLoop::ProcessEventsFlags");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QEventLoop_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QEventLoop_Type, &::QEventLoop::staticMetaObject, sizeof(::QEventLoop));
}
