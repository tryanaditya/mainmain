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

#include "qsignaltransition_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractanimation.h>
#include <qabstractstate.h>
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

QSignalTransitionWrapper::QSignalTransitionWrapper(QObject * sender, const char * signal, QState * sourceState) : QSignalTransition(sender, signal, sourceState) {
    // ... middle
}

QSignalTransitionWrapper::QSignalTransitionWrapper(QState * sourceState) : QSignalTransition(sourceState) {
    // ... middle
}

void QSignalTransitionWrapper::childEvent(QChildEvent * arg__1)
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

void QSignalTransitionWrapper::connectNotify(const char * signal)
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

void QSignalTransitionWrapper::customEvent(QEvent * arg__1)
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

void QSignalTransitionWrapper::disconnectNotify(const char * signal)
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

bool QSignalTransitionWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSignalTransition::event(e);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSignalTransition.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSignalTransitionWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSignalTransition.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QSignalTransitionWrapper::eventTest(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventTest"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSignalTransition::eventTest(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSignalTransition.eventTest", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSignalTransitionWrapper::onTransition(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "onTransition"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSignalTransition::onTransition(event);
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

void QSignalTransitionWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QSignalTransitionWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSignalTransition::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSignalTransitionWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSignalTransition::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSignalTransitionWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSignalTransitionWrapper* >(this));
        return QSignalTransition::qt_metacast(_clname);
}

QSignalTransitionWrapper::~QSignalTransitionWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSignalTransition_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"arg__2", "sourceState"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSignalTransition >()))
        return -1;

    ::QSignalTransitionWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOO:QSignalTransition", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QSignalTransition(PyObject*,QState*)
    // 1: QSignalTransition(QObject*,const char*,QState*)
    // 2: QSignalTransition(QState*)
    if (numArgs == 0) {
        overloadId = 2; // QSignalTransition(QState*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QSignalTransition(QState*)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QSignalTransition(QObject*,const char*,QState*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[2])))) {
            overloadId = 1; // QSignalTransition(QObject*,const char*,QState*)
        }
    } else if (PyObject_Check(pyArgs[0])) {
        if (numArgs == 1) {
            overloadId = 0; // QSignalTransition(PyObject*,QState*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[1])))) {
            overloadId = 0; // QSignalTransition(PyObject*,QState*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSignalTransition_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSignalTransition(PyObject * arg__1, QState * arg__2)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__2");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSignalTransition(): got multiple values for keyword argument 'arg__2'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[1]))))
                        goto Sbk_QSignalTransition_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QState* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // QSignalTransition(PyObject*,QState*)
                // Begin code injection

                if (PyObject_TypeCheck(pyArgs[0], &PySideSignalInstanceType)) {
                    PyObject* dataSource = PySide::Signal::getObject((PySideSignalInstance*) pyArgs[1-1]);
                    Shiboken::AutoDecRef obType(PyObject_Type(dataSource));
                    ::QObject* sender = ((::QObject*)0);
                    Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], dataSource, &(sender));
                    if (sender) {
                        const char* dataSignature = PySide::Signal::getSignature((PySideSignalInstance*) pyArgs[1-1]);
                        QByteArray signature(dataSignature); // Append SIGNAL flag (2)
                        cptr = new QSignalTransitionWrapper(sender, "2" + signature, cppArg1);
                    }
                }

                // End of code injection

            }
            break;
        }
        case 1: // QSignalTransition(QObject * sender, const char * signal, QState * sourceState)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "sourceState");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSignalTransition(): got multiple values for keyword argument 'sourceState'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[2]))))
                        goto Sbk_QSignalTransition_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QState* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSignalTransition(QObject*,const char*,QState*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSignalTransitionWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSignalTransitionWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSignalTransition(QState * sourceState)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "sourceState");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSignalTransition(): got multiple values for keyword argument 'sourceState'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATE_IDX], (pyArgs[0]))))
                        goto Sbk_QSignalTransition_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QState* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSignalTransition(QState*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSignalTransitionWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSignalTransitionWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSignalTransition >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSignalTransition_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QSignalTransition_Init_TypeError:
        const char* overloads[] = {"object, PySide.QtCore.QState = None", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QState = None", "PySide.QtCore.QState = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSignalTransition", overloads);
        return -1;
}

static PyObject* Sbk_QSignalTransitionFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSignalTransitionFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSignalTransition::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSignalTransitionFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSignalTransition.event", overloads);
        return 0;
}

static PyObject* Sbk_QSignalTransitionFunc_eventTest(PyObject* self, PyObject* pyArg)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: eventTest(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // eventTest(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSignalTransitionFunc_eventTest_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // eventTest(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSignalTransition::eventTest(cppArg0) : cppSelf->eventTest(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSignalTransitionFunc_eventTest_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSignalTransition.eventTest", overloads);
        return 0;
}

static PyObject* Sbk_QSignalTransitionFunc_onTransition(PyObject* self, PyObject* pyArg)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: onTransition(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // onTransition(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSignalTransitionFunc_onTransition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // onTransition(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSignalTransition::onTransition(cppArg0) : cppSelf->onTransition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSignalTransitionFunc_onTransition_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSignalTransition.onTransition", overloads);
        return 0;
}

static PyObject* Sbk_QSignalTransitionFunc_senderObject(PyObject* self)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // senderObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QSignalTransition*>(cppSelf)->senderObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSignalTransitionFunc_setSenderObject(PyObject* self, PyObject* pyArg)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSenderObject(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // setSenderObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSignalTransitionFunc_setSenderObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSenderObject(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSenderObject(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSignalTransitionFunc_setSenderObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSignalTransition.setSenderObject", overloads);
        return 0;
}

static PyObject* Sbk_QSignalTransitionFunc_setSignal(PyObject* self, PyObject* pyArg)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSignal(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setSignal(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSignalTransitionFunc_setSignal_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSignal(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSignal(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSignalTransitionFunc_setSignal_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSignalTransition.setSignal", overloads);
        return 0;
}

static PyObject* Sbk_QSignalTransitionFunc_signal(PyObject* self)
{
    ::QSignalTransition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSignalTransition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // signal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSignalTransition*>(cppSelf)->signal();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSignalTransition_methods[] = {
    {"event", (PyCFunction)Sbk_QSignalTransitionFunc_event, METH_O},
    {"eventTest", (PyCFunction)Sbk_QSignalTransitionFunc_eventTest, METH_O},
    {"onTransition", (PyCFunction)Sbk_QSignalTransitionFunc_onTransition, METH_O},
    {"senderObject", (PyCFunction)Sbk_QSignalTransitionFunc_senderObject, METH_NOARGS},
    {"setSenderObject", (PyCFunction)Sbk_QSignalTransitionFunc_setSenderObject, METH_O},
    {"setSignal", (PyCFunction)Sbk_QSignalTransitionFunc_setSignal, METH_O},
    {"signal", (PyCFunction)Sbk_QSignalTransitionFunc_signal, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSignalTransition_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSignalTransition_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSignalTransition_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSignalTransition",
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
    /*tp_traverse*/         Sbk_QSignalTransition_traverse,
    /*tp_clear*/            Sbk_QSignalTransition_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSignalTransition_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSignalTransition_Init,
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

static void* Sbk_QSignalTransition_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSignalTransition*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSignalTransition_PythonToCpp_QSignalTransition_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSignalTransition_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSignalTransition_PythonToCpp_QSignalTransition_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSignalTransition_Type))
        return QSignalTransition_PythonToCpp_QSignalTransition_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSignalTransition_PTR_CppToPython_QSignalTransition(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSignalTransition*)cppIn, &Sbk_QSignalTransition_Type);

}

void init_QSignalTransition(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSIGNALTRANSITION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSignalTransition_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSignalTransition", "QSignalTransition*",
        &Sbk_QSignalTransition_Type, &Shiboken::callCppDestructor< ::QSignalTransition >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTTRANSITION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSignalTransition_Type,
        QSignalTransition_PythonToCpp_QSignalTransition_PTR,
        is_QSignalTransition_PythonToCpp_QSignalTransition_PTR_Convertible,
        QSignalTransition_PTR_CppToPython_QSignalTransition);

    Shiboken::Conversions::registerConverterName(converter, "QSignalTransition");
    Shiboken::Conversions::registerConverterName(converter, "QSignalTransition*");
    Shiboken::Conversions::registerConverterName(converter, "QSignalTransition&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSignalTransition).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSignalTransitionWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSignalTransition_Type, &Sbk_QSignalTransition_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QSignalTransition_Type, &::QSignalTransition::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSignalTransition_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSignalTransition_Type, &::QSignalTransition::staticMetaObject, sizeof(::QSignalTransition));
}
