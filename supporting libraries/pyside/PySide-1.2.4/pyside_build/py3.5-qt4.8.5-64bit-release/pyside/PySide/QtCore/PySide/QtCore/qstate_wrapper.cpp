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

#include "qstate_wrapper.h"

// Extra includes
#include <QList>
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

QStateWrapper::QStateWrapper(QState * parent) : QState(parent) {
    // ... middle
}

QStateWrapper::QStateWrapper(QState::ChildMode childMode, QState * parent) : QState(childMode, parent) {
    // ... middle
}

void QStateWrapper::childEvent(QChildEvent * arg__1)
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

void QStateWrapper::connectNotify(const char * signal)
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

void QStateWrapper::customEvent(QEvent * arg__1)
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

void QStateWrapper::disconnectNotify(const char * signal)
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

bool QStateWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QState::event(e);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QState.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QStateWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QState.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QStateWrapper::onEntry(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onEntry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QState::onEntry(event);
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

void QStateWrapper::onExit(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onExit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QState::onExit(event);
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

void QStateWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QStateWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QState::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QStateWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QState::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QStateWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QStateWrapper* >(this));
        return QState::qt_metacast(_clname);
}

QStateWrapper::~QStateWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QState_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QState >()))
        return -1;

    ::QStateWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QState", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QState(QState*)
    // 1: QState(QState::ChildMode,QState*)
    if (numArgs == 0) {
        overloadId = 0; // QState(QState*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QState(QState::ChildMode,QState*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[1])))) {
            overloadId = 1; // QState(QState::ChildMode,QState*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[0])))) {
        overloadId = 0; // QState(QState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QState_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QState(QState * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QState(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[0]))))
                        goto Sbk_QState_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QState* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QState(QState*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QStateWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QStateWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QState(QState::ChildMode childMode, QState * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QState(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[1]))))
                        goto Sbk_QState_Init_TypeError;
                }
            }
            ::QState::ChildMode cppArg0 = ((::QState::ChildMode)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QState* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QState(QState::ChildMode,QState*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QStateWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QStateWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QState >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QState_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QState_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QState = None", "PySide.QtCore.QState.ChildMode, PySide.QtCore.QState = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QState", overloads);
        return -1;
}

static PyObject* Sbk_QStateFunc_addTransition(PyObject* self, PyObject* args)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addTransition", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addTransition(PyObject*,QAbstractState*)
    // 1: addTransition(QAbstractState*)
    // 2: addTransition(QAbstractTransition*)
    // 3: addTransition(QObject*,const char*,QAbstractState*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArgs[2])))) {
        overloadId = 3; // addTransition(QObject*,const char*,QAbstractState*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], (pyArgs[0])))) {
        overloadId = 2; // addTransition(QAbstractTransition*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArgs[0])))) {
        overloadId = 1; // addTransition(QAbstractState*)
    } else if (numArgs == 2
        && PyObject_Check(pyArgs[0])
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArgs[1])))) {
        overloadId = 0; // addTransition(PyObject*,QAbstractState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_addTransition_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addTransition(PyObject * arg__1, QAbstractState * arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QAbstractState* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // addTransition(PyObject*,QAbstractState*)
                // Begin code injection

                // Obviously the label used by the following goto is a very awkward solution,
                // since it refers to a name very tied to the generator implementation.
                // Check bug #362 for more information on this
                // http://bugs.openbossa.org/show_bug.cgi?id=362
                if (!PyObject_TypeCheck(pyArgs[0], &PySideSignalInstanceType))
                    goto Sbk_QStateFunc_addTransition_TypeError;
                PySideSignalInstance* signalInstance = reinterpret_cast<PySideSignalInstance*>(pyArgs[0]);
                ::QObject* sender = ((::QObject*)0);
                    Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], PySide::Signal::getObject(signalInstance), &(sender));
                QSignalTransition* cppResult = cppSelf->addTransition(sender, PySide::Signal::getSignature(signalInstance), cppArg1);
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], cppResult);

                // End of code injection


                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // addTransition(QAbstractState * target)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QAbstractState* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addTransition(QAbstractState*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QAbstractTransition * cppResult = cppSelf->addTransition(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], cppResult);
                Shiboken::Object::setParent(self, pyArgs[0]);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 2: // addTransition(QAbstractTransition * transition)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QAbstractTransition* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addTransition(QAbstractTransition*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addTransition(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 3: // addTransition(QObject * sender, const char * signal, QAbstractState * target)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QAbstractState* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addTransition(QObject*,const char*,QAbstractState*)
                // Begin code injection

                QString signalName(cppArg1);
                if (PySide::SignalManager::registerMetaMethod(cppArg0, signalName.mid(1).toAscii().data(), QMetaMethod::Signal)) {
                    QSignalTransition* cppResult = cppSelf->addTransition(cppArg0, cppArg1, cppArg2);
                    pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], cppResult);
                } else {
                    Py_INCREF(Py_None);
                    pyResult = Py_None;
                }

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

    Sbk_QStateFunc_addTransition_TypeError:
        const char* overloads[] = {"object, PySide.QtCore.QAbstractState", "PySide.QtCore.QAbstractState", "PySide.QtCore.QAbstractTransition", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QAbstractState", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QState.addTransition", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_assignProperty(PyObject* self, PyObject* args)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "assignProperty", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: assignProperty(QObject*,const char*,QVariant)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[2])))) {
        overloadId = 0; // assignProperty(QObject*,const char*,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_assignProperty_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QVariant cppArg2 = ::QVariant();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // assignProperty(QObject*,const char*,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->assignProperty(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_assignProperty_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, " SBK_STR_NAME ", QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QState.assignProperty", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_childMode(PyObject* self)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QState::ChildMode cppResult = const_cast<const ::QState*>(cppSelf)->childMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateFunc_errorState(PyObject* self)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractState * cppResult = const_cast<const ::QState*>(cppSelf)->errorState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QStateFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QState::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStateFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.event", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_initialState(PyObject* self)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractState * cppResult = const_cast<const ::QState*>(cppSelf)->initialState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateFunc_onEntry(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onEntry(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // onEntry(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_onEntry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onEntry(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QState::onEntry(cppArg0) : cppSelf->onEntry(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_onEntry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.onEntry", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_onExit(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onExit(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // onExit(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_onExit_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onExit(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QState::onExit(cppArg0) : cppSelf->onExit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_onExit_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.onExit", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_removeTransition(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeTransition(QAbstractTransition*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX], (pyArg)))) {
        overloadId = 0; // removeTransition(QAbstractTransition*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_removeTransition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractTransition* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeTransition(QAbstractTransition*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeTransition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_removeTransition_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractTransition", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.removeTransition", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_setChildMode(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setChildMode(QState::ChildMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setChildMode(QState::ChildMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_setChildMode_TypeError;

    // Call function/method
    {
        ::QState::ChildMode cppArg0 = ((::QState::ChildMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChildMode(QState::ChildMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setChildMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_setChildMode_TypeError:
        const char* overloads[] = {"PySide.QtCore.QState.ChildMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.setChildMode", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_setErrorState(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setErrorState(QAbstractState*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArg)))) {
        overloadId = 0; // setErrorState(QAbstractState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_setErrorState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractState* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setErrorState(QAbstractState*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setErrorState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_setErrorState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.setErrorState", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_setInitialState(PyObject* self, PyObject* pyArg)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInitialState(QAbstractState*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX], (pyArg)))) {
        overloadId = 0; // setInitialState(QAbstractState*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateFunc_setInitialState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractState* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInitialState(QAbstractState*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInitialState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStateFunc_setInitialState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QState.setInitialState", overloads);
        return 0;
}

static PyObject* Sbk_QStateFunc_transitions(PyObject* self)
{
    ::QState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transitions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAbstractTransition * > cppResult = const_cast<const ::QState*>(cppSelf)->transitions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QABSTRACTTRANSITIONPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QState_methods[] = {
    {"addTransition", (PyCFunction)Sbk_QStateFunc_addTransition, METH_VARARGS},
    {"assignProperty", (PyCFunction)Sbk_QStateFunc_assignProperty, METH_VARARGS},
    {"childMode", (PyCFunction)Sbk_QStateFunc_childMode, METH_NOARGS},
    {"errorState", (PyCFunction)Sbk_QStateFunc_errorState, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QStateFunc_event, METH_O},
    {"initialState", (PyCFunction)Sbk_QStateFunc_initialState, METH_NOARGS},
    {"onEntry", (PyCFunction)Sbk_QStateFunc_onEntry, METH_O},
    {"onExit", (PyCFunction)Sbk_QStateFunc_onExit, METH_O},
    {"removeTransition", (PyCFunction)Sbk_QStateFunc_removeTransition, METH_O},
    {"setChildMode", (PyCFunction)Sbk_QStateFunc_setChildMode, METH_O},
    {"setErrorState", (PyCFunction)Sbk_QStateFunc_setErrorState, METH_O},
    {"setInitialState", (PyCFunction)Sbk_QStateFunc_setInitialState, METH_O},
    {"transitions", (PyCFunction)Sbk_QStateFunc_transitions, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QState_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QState_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QState_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QState",
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
    /*tp_traverse*/         Sbk_QState_traverse,
    /*tp_clear*/            Sbk_QState_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QState_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QState_Init,
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

static void* Sbk_QState_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QState*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QState_ChildMode_PythonToCpp_QState_ChildMode(PyObject* pyIn, void* cppOut) {
    *((::QState::ChildMode*)cppOut) = (::QState::ChildMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QState_ChildMode_PythonToCpp_QState_ChildMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX]))
        return QState_ChildMode_PythonToCpp_QState_ChildMode;
    return 0;
}
static PyObject* QState_ChildMode_CppToPython_QState_ChildMode(const void* cppIn) {
    int castCppIn = *((::QState::ChildMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QState_PythonToCpp_QState_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QState_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QState_PythonToCpp_QState_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QState_Type))
        return QState_PythonToCpp_QState_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QState_PTR_CppToPython_QState(const void* cppIn) {
    return PySide::getWrapperForQObject((::QState*)cppIn, &Sbk_QState_Type);

}

void init_QState(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSTATE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QState_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QState", "QState*",
        &Sbk_QState_Type, &Shiboken::callCppDestructor< ::QState >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTSTATE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QState_Type,
        QState_PythonToCpp_QState_PTR,
        is_QState_PythonToCpp_QState_PTR_Convertible,
        QState_PTR_CppToPython_QState);

    Shiboken::Conversions::registerConverterName(converter, "QState");
    Shiboken::Conversions::registerConverterName(converter, "QState*");
    Shiboken::Conversions::registerConverterName(converter, "QState&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QState).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStateWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QState_Type, &Sbk_QState_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ChildMode'.
    SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QState_Type,
        "ChildMode",
        "PySide.QtCore.QState.ChildMode",
        "QState::ChildMode");
    if (!SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX],
        &Sbk_QState_Type, "ExclusiveStates", (long) QState::ExclusiveStates))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX],
        &Sbk_QState_Type, "ParallelStates", (long) QState::ParallelStates))
        return ;
    // Register converter for enum 'QState::ChildMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX],
            QState_ChildMode_CppToPython_QState_ChildMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QState_ChildMode_PythonToCpp_QState_ChildMode,
            is_QState_ChildMode_PythonToCpp_QState_ChildMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSTATE_CHILDMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QState::ChildMode");
        Shiboken::Conversions::registerConverterName(converter, "ChildMode");
    }
    // End of 'ChildMode' enum.

    PySide::Signal::registerSignals(&Sbk_QState_Type, &::QState::staticMetaObject);

    qRegisterMetaType< ::QState::ChildMode >("QState::ChildMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QState_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QState_Type, &::QState::staticMetaObject, sizeof(::QState));
}
