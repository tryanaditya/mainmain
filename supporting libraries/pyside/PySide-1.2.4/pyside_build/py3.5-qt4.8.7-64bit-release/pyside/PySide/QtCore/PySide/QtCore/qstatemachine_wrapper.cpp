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

#include "qstatemachine_wrapper.h"
#include "qstatemachine_wrappedevent_wrapper.h"
#include "qstatemachine_signalevent_wrapper.h"

// Extra includes
#include <QList>
#include <QSet>
#include <qabstractanimation.h>
#include <qabstractstate.h>
#include <qabstracttransition.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsignaltransition.h>
#include <qstate.h>
#include <qstatemachine.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QStateMachineWrapper::QStateMachineWrapper(QObject * parent) : QStateMachine(parent) {
    // ... middle
}

void QStateMachineWrapper::beginMicrostep(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "beginMicrostep"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::beginMicrostep(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStateMachineWrapper::beginSelectTransitions(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "beginSelectTransitions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::beginSelectTransitions(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStateMachineWrapper::childEvent(QChildEvent * arg__1)
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

void QStateMachineWrapper::connectNotify(const char * signal)
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

void QStateMachineWrapper::customEvent(QEvent * arg__1)
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

void QStateMachineWrapper::disconnectNotify(const char * signal)
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

void QStateMachineWrapper::endMicrostep(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endMicrostep"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::endMicrostep(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStateMachineWrapper::endSelectTransitions(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endSelectTransitions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::endSelectTransitions(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QStateMachineWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::event(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStateMachine.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QStateMachineWrapper::eventFilter(QObject * watched, QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::eventFilter(watched, event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], watched),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStateMachine.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QStateMachineWrapper::onEntry(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onEntry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::onEntry(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStateMachineWrapper::onExit(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onExit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStateMachine::onExit(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStateMachineWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QStateMachineWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QStateMachine::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QStateMachineWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QStateMachine::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QStateMachineWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QStateMachineWrapper* >(this));
        return QStateMachine::qt_metacast(_clname);
}

QStateMachineWrapper::~QStateMachineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStateMachine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStateMachine >()))
        return -1;

    ::QStateMachineWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QStateMachine", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStateMachine(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QStateMachine(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QStateMachine(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachine_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QStateMachine(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QStateMachine_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QStateMachine(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QStateMachineWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QStateMachineWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStateMachine >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStateMachine_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QStateMachine_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QStateMachine", overloads);
        return -1;
}

static PyObject* Sbk_QStateMachineFunc_addDefaultAnimation(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addDefaultAnimation(QAbstractAnimation*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (pyArg)))) {
        overloadId = 0; // addDefaultAnimation(QAbstractAnimation*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_addDefaultAnimation_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractAnimation* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addDefaultAnimation(QAbstractAnimation*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addDefaultAnimation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_addDefaultAnimation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.addDefaultAnimation", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_addState(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addState(QAbstractState*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArg)))) {
        overloadId = 0; // addState(QAbstractState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_addState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractState* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addState(QAbstractState*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_addState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.addState", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_beginMicrostep(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: beginMicrostep(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // beginMicrostep(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_beginMicrostep_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginMicrostep(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::beginMicrostep(cppArg0) : cppSelf->beginMicrostep(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_beginMicrostep_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.beginMicrostep", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_beginSelectTransitions(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: beginSelectTransitions(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // beginSelectTransitions(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_beginSelectTransitions_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginSelectTransitions(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::beginSelectTransitions(cppArg0) : cppSelf->beginSelectTransitions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_beginSelectTransitions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.beginSelectTransitions", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_cancelDelayedEvent(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cancelDelayedEvent(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // cancelDelayedEvent(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_cancelDelayedEvent_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cancelDelayedEvent(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->cancelDelayedEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStateMachineFunc_cancelDelayedEvent_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.cancelDelayedEvent", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_clearError(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearError()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearError();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QStateMachineFunc_configuration(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // configuration()
            // Begin code injection

            pyResult = PySet_New(0);
            foreach(QAbstractState* abs_state, cppSelf->configuration()) {
                    Shiboken::AutoDecRef obj(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], abs_state));
                    Shiboken::Object::setParent(self, obj);
                    PySet_Add(pyResult, obj);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachineFunc_defaultAnimations(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultAnimations()
            // Begin code injection

            pyResult = PyList_New(0);
            foreach(QAbstractAnimation* abs_anim, cppSelf->defaultAnimations()) {
                    Shiboken::AutoDecRef obj(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], abs_anim));
                    Shiboken::Object::setParent(self, obj);
                    PyList_Append(pyResult, obj);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachineFunc_endMicrostep(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endMicrostep(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // endMicrostep(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_endMicrostep_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // endMicrostep(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::endMicrostep(cppArg0) : cppSelf->endMicrostep(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_endMicrostep_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.endMicrostep", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_endSelectTransitions(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endSelectTransitions(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // endSelectTransitions(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_endSelectTransitions_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // endSelectTransitions(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::endSelectTransitions(cppArg0) : cppSelf->endSelectTransitions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_endSelectTransitions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.endSelectTransitions", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_error(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStateMachine::Error cppResult = const_cast<const ::QStateMachine*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachineFunc_errorString(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStateMachine*>(cppSelf)->errorString();
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

static PyObject* Sbk_QStateMachineFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QStateMachineFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStateMachineFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.event", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_eventFilter(PyObject* self, PyObject* args)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QStateMachineFunc_eventFilter_TypeError;

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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::eventFilter(cppArg0, cppArg1) : cppSelf->eventFilter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStateMachineFunc_eventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QStateMachine.eventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_globalRestorePolicy(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalRestorePolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStateMachine::RestorePolicy cppResult = const_cast<const ::QStateMachine*>(cppSelf)->globalRestorePolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachineFunc_isAnimated(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAnimated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStateMachine*>(cppSelf)->isAnimated();
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

static PyObject* Sbk_QStateMachineFunc_isRunning(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRunning()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStateMachine*>(cppSelf)->isRunning();
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

static PyObject* Sbk_QStateMachineFunc_onEntry(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onEntry(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // onEntry(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_onEntry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onEntry(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::onEntry(cppArg0) : cppSelf->onEntry(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_onEntry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.onEntry", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_onExit(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onExit(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // onExit(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_onExit_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onExit(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStateMachine::onExit(cppArg0) : cppSelf->onExit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_onExit_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.onExit", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_postDelayedEvent(PyObject* self, PyObject* args)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "postDelayedEvent", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: postDelayedEvent(QEvent*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // postDelayedEvent(QEvent*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_postDelayedEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // postDelayedEvent(QEvent*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->postDelayedEvent(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStateMachineFunc_postDelayedEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QStateMachine.postDelayedEvent", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_postEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QStateMachine.postEvent(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QStateMachine.postEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:postEvent", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: postEvent(QEvent*,QStateMachine::EventPriority)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // postEvent(QEvent*,QStateMachine::EventPriority)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX]), (pyArgs[1])))) {
            overloadId = 0; // postEvent(QEvent*,QStateMachine::EventPriority)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_postEvent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "priority");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QStateMachine.postEvent(): got multiple values for keyword argument 'priority'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX]), (pyArgs[1]))))
                    goto Sbk_QStateMachineFunc_postEvent_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStateMachine::EventPriority cppArg1 = QStateMachine::NormalPriority;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // postEvent(QEvent*,QStateMachine::EventPriority)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->postEvent(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_postEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent, PySide.QtCore.QStateMachine.EventPriority = NormalPriority", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QStateMachine.postEvent", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_removeDefaultAnimation(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeDefaultAnimation(QAbstractAnimation*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTANIMATION_IDX], (pyArg)))) {
        overloadId = 0; // removeDefaultAnimation(QAbstractAnimation*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_removeDefaultAnimation_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractAnimation* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeDefaultAnimation(QAbstractAnimation*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeDefaultAnimation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_removeDefaultAnimation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractAnimation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.removeDefaultAnimation", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_removeState(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeState(QAbstractState*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArg)))) {
        overloadId = 0; // removeState(QAbstractState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_removeState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractState* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeState(QAbstractState*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_removeState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.removeState", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_setAnimated(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnimated(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAnimated(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_setAnimated_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnimated(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAnimated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_setAnimated_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.setAnimated", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_setGlobalRestorePolicy(PyObject* self, PyObject* pyArg)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGlobalRestorePolicy(QStateMachine::RestorePolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setGlobalRestorePolicy(QStateMachine::RestorePolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachineFunc_setGlobalRestorePolicy_TypeError;

    // Call function/method
    {
        ::QStateMachine::RestorePolicy cppArg0 = ((::QStateMachine::RestorePolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGlobalRestorePolicy(QStateMachine::RestorePolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGlobalRestorePolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateMachineFunc_setGlobalRestorePolicy_TypeError:
        const char* overloads[] = {"PySide.QtCore.QStateMachine.RestorePolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QStateMachine.setGlobalRestorePolicy", overloads);
        return 0;
}

static PyObject* Sbk_QStateMachineFunc_start(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // start()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QStateMachineFunc_stop(PyObject* self)
{
    ::QStateMachine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX], (SbkObject*)self));

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

static PyMethodDef Sbk_QStateMachine_methods[] = {
    {"addDefaultAnimation", (PyCFunction)Sbk_QStateMachineFunc_addDefaultAnimation, METH_O},
    {"addState", (PyCFunction)Sbk_QStateMachineFunc_addState, METH_O},
    {"beginMicrostep", (PyCFunction)Sbk_QStateMachineFunc_beginMicrostep, METH_O},
    {"beginSelectTransitions", (PyCFunction)Sbk_QStateMachineFunc_beginSelectTransitions, METH_O},
    {"cancelDelayedEvent", (PyCFunction)Sbk_QStateMachineFunc_cancelDelayedEvent, METH_O},
    {"clearError", (PyCFunction)Sbk_QStateMachineFunc_clearError, METH_NOARGS},
    {"configuration", (PyCFunction)Sbk_QStateMachineFunc_configuration, METH_NOARGS},
    {"defaultAnimations", (PyCFunction)Sbk_QStateMachineFunc_defaultAnimations, METH_NOARGS},
    {"endMicrostep", (PyCFunction)Sbk_QStateMachineFunc_endMicrostep, METH_O},
    {"endSelectTransitions", (PyCFunction)Sbk_QStateMachineFunc_endSelectTransitions, METH_O},
    {"error", (PyCFunction)Sbk_QStateMachineFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QStateMachineFunc_errorString, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QStateMachineFunc_event, METH_O},
    {"eventFilter", (PyCFunction)Sbk_QStateMachineFunc_eventFilter, METH_VARARGS},
    {"globalRestorePolicy", (PyCFunction)Sbk_QStateMachineFunc_globalRestorePolicy, METH_NOARGS},
    {"isAnimated", (PyCFunction)Sbk_QStateMachineFunc_isAnimated, METH_NOARGS},
    {"isRunning", (PyCFunction)Sbk_QStateMachineFunc_isRunning, METH_NOARGS},
    {"onEntry", (PyCFunction)Sbk_QStateMachineFunc_onEntry, METH_O},
    {"onExit", (PyCFunction)Sbk_QStateMachineFunc_onExit, METH_O},
    {"postDelayedEvent", (PyCFunction)Sbk_QStateMachineFunc_postDelayedEvent, METH_VARARGS},
    {"postEvent", (PyCFunction)Sbk_QStateMachineFunc_postEvent, METH_VARARGS|METH_KEYWORDS},
    {"removeDefaultAnimation", (PyCFunction)Sbk_QStateMachineFunc_removeDefaultAnimation, METH_O},
    {"removeState", (PyCFunction)Sbk_QStateMachineFunc_removeState, METH_O},
    {"setAnimated", (PyCFunction)Sbk_QStateMachineFunc_setAnimated, METH_O},
    {"setGlobalRestorePolicy", (PyCFunction)Sbk_QStateMachineFunc_setGlobalRestorePolicy, METH_O},
    {"start", (PyCFunction)Sbk_QStateMachineFunc_start, METH_NOARGS},
    {"stop", (PyCFunction)Sbk_QStateMachineFunc_stop, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QStateMachine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStateMachine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStateMachine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QStateMachine",
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
    /*tp_traverse*/         Sbk_QStateMachine_traverse,
    /*tp_clear*/            Sbk_QStateMachine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStateMachine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStateMachine_Init,
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

static void* Sbk_QStateMachine_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QStateMachine*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QStateMachine_EventPriority_PythonToCpp_QStateMachine_EventPriority(PyObject* pyIn, void* cppOut) {
    *((::QStateMachine::EventPriority*)cppOut) = (::QStateMachine::EventPriority) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStateMachine_EventPriority_PythonToCpp_QStateMachine_EventPriority_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX]))
        return QStateMachine_EventPriority_PythonToCpp_QStateMachine_EventPriority;
    return 0;
}
static PyObject* QStateMachine_EventPriority_CppToPython_QStateMachine_EventPriority(const void* cppIn) {
    int castCppIn = *((::QStateMachine::EventPriority*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX], castCppIn);

}

static void QStateMachine_RestorePolicy_PythonToCpp_QStateMachine_RestorePolicy(PyObject* pyIn, void* cppOut) {
    *((::QStateMachine::RestorePolicy*)cppOut) = (::QStateMachine::RestorePolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStateMachine_RestorePolicy_PythonToCpp_QStateMachine_RestorePolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX]))
        return QStateMachine_RestorePolicy_PythonToCpp_QStateMachine_RestorePolicy;
    return 0;
}
static PyObject* QStateMachine_RestorePolicy_CppToPython_QStateMachine_RestorePolicy(const void* cppIn) {
    int castCppIn = *((::QStateMachine::RestorePolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX], castCppIn);

}

static void QStateMachine_Error_PythonToCpp_QStateMachine_Error(PyObject* pyIn, void* cppOut) {
    *((::QStateMachine::Error*)cppOut) = (::QStateMachine::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStateMachine_Error_PythonToCpp_QStateMachine_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX]))
        return QStateMachine_Error_PythonToCpp_QStateMachine_Error;
    return 0;
}
static PyObject* QStateMachine_Error_CppToPython_QStateMachine_Error(const void* cppIn) {
    int castCppIn = *((::QStateMachine::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStateMachine_PythonToCpp_QStateMachine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStateMachine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStateMachine_PythonToCpp_QStateMachine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStateMachine_Type))
        return QStateMachine_PythonToCpp_QStateMachine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStateMachine_PTR_CppToPython_QStateMachine(const void* cppIn) {
    return PySide::getWrapperForQObject((::QStateMachine*)cppIn, &Sbk_QStateMachine_Type);

}

void init_QStateMachine(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStateMachine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStateMachine", "QStateMachine*",
        &Sbk_QStateMachine_Type, &Shiboken::callCppDestructor< ::QStateMachine >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStateMachine_Type,
        QStateMachine_PythonToCpp_QStateMachine_PTR,
        is_QStateMachine_PythonToCpp_QStateMachine_PTR_Convertible,
        QStateMachine_PTR_CppToPython_QStateMachine);

    Shiboken::Conversions::registerConverterName(converter, "QStateMachine");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine*");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStateMachine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStateMachineWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QStateMachine_Type, &Sbk_QStateMachine_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'EventPriority'.
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStateMachine_Type,
        "EventPriority",
        "PySide.QtCore.QStateMachine.EventPriority",
        "QStateMachine::EventPriority");
    if (!SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX],
        &Sbk_QStateMachine_Type, "NormalPriority", (long) QStateMachine::NormalPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX],
        &Sbk_QStateMachine_Type, "HighPriority", (long) QStateMachine::HighPriority))
        return ;
    // Register converter for enum 'QStateMachine::EventPriority'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX],
            QStateMachine_EventPriority_CppToPython_QStateMachine_EventPriority);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStateMachine_EventPriority_PythonToCpp_QStateMachine_EventPriority,
            is_QStateMachine_EventPriority_PythonToCpp_QStateMachine_EventPriority_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_EVENTPRIORITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStateMachine::EventPriority");
        Shiboken::Conversions::registerConverterName(converter, "EventPriority");
    }
    // End of 'EventPriority' enum.

    // Initialization of enum 'RestorePolicy'.
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStateMachine_Type,
        "RestorePolicy",
        "PySide.QtCore.QStateMachine.RestorePolicy",
        "QStateMachine::RestorePolicy");
    if (!SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX],
        &Sbk_QStateMachine_Type, "DontRestoreProperties", (long) QStateMachine::DontRestoreProperties))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX],
        &Sbk_QStateMachine_Type, "RestoreProperties", (long) QStateMachine::RestoreProperties))
        return ;
    // Register converter for enum 'QStateMachine::RestorePolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX],
            QStateMachine_RestorePolicy_CppToPython_QStateMachine_RestorePolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStateMachine_RestorePolicy_PythonToCpp_QStateMachine_RestorePolicy,
            is_QStateMachine_RestorePolicy_PythonToCpp_QStateMachine_RestorePolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_RESTOREPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStateMachine::RestorePolicy");
        Shiboken::Conversions::registerConverterName(converter, "RestorePolicy");
    }
    // End of 'RestorePolicy' enum.

    // Initialization of enum 'Error'.
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStateMachine_Type,
        "Error",
        "PySide.QtCore.QStateMachine.Error",
        "QStateMachine::Error");
    if (!SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX],
        &Sbk_QStateMachine_Type, "NoError", (long) QStateMachine::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX],
        &Sbk_QStateMachine_Type, "NoInitialStateError", (long) QStateMachine::NoInitialStateError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX],
        &Sbk_QStateMachine_Type, "NoDefaultStateInHistoryStateError", (long) QStateMachine::NoDefaultStateInHistoryStateError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX],
        &Sbk_QStateMachine_Type, "NoCommonAncestorForTransitionError", (long) QStateMachine::NoCommonAncestorForTransitionError))
        return ;
    // Register converter for enum 'QStateMachine::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX],
            QStateMachine_Error_CppToPython_QStateMachine_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStateMachine_Error_PythonToCpp_QStateMachine_Error,
            is_QStateMachine_Error_PythonToCpp_QStateMachine_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStateMachine::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.

    PySide::Signal::registerSignals(&Sbk_QStateMachine_Type, &::QStateMachine::staticMetaObject);

    qRegisterMetaType< ::QStateMachine::EventPriority >("QStateMachine::EventPriority");
    qRegisterMetaType< ::QStateMachine::RestorePolicy >("QStateMachine::RestorePolicy");
    qRegisterMetaType< ::QStateMachine::Error >("QStateMachine::Error");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QStateMachine_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QStateMachine_Type, &::QStateMachine::staticMetaObject, sizeof(::QStateMachine));
}
