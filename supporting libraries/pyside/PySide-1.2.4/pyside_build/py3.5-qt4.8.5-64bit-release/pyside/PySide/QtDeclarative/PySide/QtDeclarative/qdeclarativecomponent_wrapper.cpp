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
#include "pyside_qtdeclarative_python.h"

#include "qdeclarativecomponent_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdeclarativecomponent.h>
#include <qdeclarativecontext.h>
#include <qdeclarativeengine.h>
#include <qdeclarativeerror.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qurl.h>


// Native ---------------------------------------------------------

QDeclarativeComponentWrapper::QDeclarativeComponentWrapper(QDeclarativeEngine * arg__1, QObject * parent) : QDeclarativeComponent(arg__1, parent) {
    // ... middle
}

QDeclarativeComponentWrapper::QDeclarativeComponentWrapper(QDeclarativeEngine * arg__1, const QString & fileName, QObject * parent) : QDeclarativeComponent(arg__1, fileName, parent) {
    // ... middle
}

QDeclarativeComponentWrapper::QDeclarativeComponentWrapper(QDeclarativeEngine * arg__1, const QUrl & url, QObject * parent) : QDeclarativeComponent(arg__1, url, parent) {
    // ... middle
}

QObject * QDeclarativeComponentWrapper::beginCreate(QDeclarativeContext * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "beginCreate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDeclarativeComponent::beginCreate(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeComponent.beginCreate", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDeclarativeComponentWrapper::childEvent(QChildEvent * arg__1)
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

void QDeclarativeComponentWrapper::completeCreate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "completeCreate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDeclarativeComponent::completeCreate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QDeclarativeComponentWrapper::connectNotify(const char * signal)
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

QObject * QDeclarativeComponentWrapper::create(QDeclarativeContext * context)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "create"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDeclarativeComponent::create(context);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], context)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeComponent.create", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDeclarativeComponentWrapper::customEvent(QEvent * arg__1)
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

void QDeclarativeComponentWrapper::disconnectNotify(const char * signal)
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

bool QDeclarativeComponentWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeComponent.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDeclarativeComponentWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeComponent.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDeclarativeComponentWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QDeclarativeComponentWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDeclarativeComponent::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDeclarativeComponentWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDeclarativeComponent::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDeclarativeComponentWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDeclarativeComponentWrapper* >(this));
        return QDeclarativeComponent::qt_metacast(_clname);
}

QDeclarativeComponentWrapper::~QDeclarativeComponentWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeComponent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeComponent >()))
        return -1;

    ::QDeclarativeComponentWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QDeclarativeComponent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeComponent(QDeclarativeEngine*,QObject*)
    // 1: QDeclarativeComponent(QDeclarativeEngine*,QString,QObject*)
    // 2: QDeclarativeComponent(QDeclarativeEngine*,QUrl,QObject*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QDeclarativeComponent(QDeclarativeEngine*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // QDeclarativeComponent(QDeclarativeEngine*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QDeclarativeComponent(QDeclarativeEngine*,QString,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 1; // QDeclarativeComponent(QDeclarativeEngine*,QString,QObject*)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QDeclarativeComponent(QDeclarativeEngine*,QUrl,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 2; // QDeclarativeComponent(QDeclarativeEngine*,QUrl,QObject*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeComponent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDeclarativeComponent(QDeclarativeEngine * arg__1, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QDeclarativeComponent_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDeclarativeComponent(QDeclarativeEngine*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeComponentWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeComponentWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 1: // QDeclarativeComponent(QDeclarativeEngine * arg__1, const QString & fileName, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QDeclarativeComponent_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDeclarativeComponent(QDeclarativeEngine*,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeComponentWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeComponentWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
        case 2: // QDeclarativeComponent(QDeclarativeEngine * arg__1, const QUrl & url, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QDeclarativeComponent_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QUrl cppArg1_local = ::QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDeclarativeComponent(QDeclarativeEngine*,QUrl,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeComponentWrapper(cppArg0, *cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeComponentWrapper(cppArg0, *cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeComponent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeComponent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDeclarativeComponent_Init_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeEngine, PySide.QtCore.QObject = None", "PySide.QtDeclarative.QDeclarativeEngine, unicode, PySide.QtCore.QObject = None", "PySide.QtDeclarative.QDeclarativeEngine, PySide.QtCore.QUrl, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeComponent", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativeComponentFunc_beginCreate(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: beginCreate(QDeclarativeContext*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArg)))) {
        overloadId = 0; // beginCreate(QDeclarativeContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeComponentFunc_beginCreate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDeclarativeContext* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginCreate(QDeclarativeContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDeclarativeComponent::beginCreate(cppArg0) : cppSelf->beginCreate(cppArg0);
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

    Sbk_QDeclarativeComponentFunc_beginCreate_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeContext", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeComponent.beginCreate", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeComponentFunc_completeCreate(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completeCreate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDeclarativeComponent::completeCreate() : cppSelf->completeCreate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDeclarativeComponentFunc_create(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent.create(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:create", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: create(QDeclarativeContext*)
    if (numArgs == 0) {
        overloadId = 0; // create(QDeclarativeContext*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 0; // create(QDeclarativeContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeComponentFunc_create_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "context");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeComponent.create(): got multiple values for keyword argument 'context'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[0]))))
                    goto Sbk_QDeclarativeComponentFunc_create_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDeclarativeContext* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // create(QDeclarativeContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDeclarativeComponent::create(cppArg0) : cppSelf->create(cppArg0);
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

    Sbk_QDeclarativeComponentFunc_create_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeContext = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeComponent.create", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeComponentFunc_creationContext(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // creationContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeContext * cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->creationContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeComponentFunc_errorString(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->errorString();
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

static PyObject* Sbk_QDeclarativeComponentFunc_errors(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errors()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QDeclarativeError > cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->errors();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtDeclarativeTypeConverters[SBK_QTDECLARATIVE_QLIST_QDECLARATIVEERROR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeComponentFunc_isError(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->isError();
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

static PyObject* Sbk_QDeclarativeComponentFunc_isLoading(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLoading()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->isLoading();
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

static PyObject* Sbk_QDeclarativeComponentFunc_isNull(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->isNull();
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

static PyObject* Sbk_QDeclarativeComponentFunc_isReady(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReady()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->isReady();
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

static PyObject* Sbk_QDeclarativeComponentFunc_loadUrl(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // loadUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeComponentFunc_loadUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // loadUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->loadUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeComponentFunc_loadUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeComponent.loadUrl", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeComponentFunc_progress(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // progress()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->progress();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeComponentFunc_setData(PyObject* self, PyObject* args)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setData(QByteArray,QUrl)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
        overloadId = 0; // setData(QByteArray,QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeComponentFunc_setData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setData(QByteArray,QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setData(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeComponentFunc_setData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeComponent.setData", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeComponentFunc_status(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // status()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeComponent::Status cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->status();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeComponentFunc_url(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QDeclarativeComponent*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDeclarativeComponent_methods[] = {
    {"beginCreate", (PyCFunction)Sbk_QDeclarativeComponentFunc_beginCreate, METH_O},
    {"completeCreate", (PyCFunction)Sbk_QDeclarativeComponentFunc_completeCreate, METH_NOARGS},
    {"create", (PyCFunction)Sbk_QDeclarativeComponentFunc_create, METH_VARARGS|METH_KEYWORDS},
    {"creationContext", (PyCFunction)Sbk_QDeclarativeComponentFunc_creationContext, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QDeclarativeComponentFunc_errorString, METH_NOARGS},
    {"errors", (PyCFunction)Sbk_QDeclarativeComponentFunc_errors, METH_NOARGS},
    {"isError", (PyCFunction)Sbk_QDeclarativeComponentFunc_isError, METH_NOARGS},
    {"isLoading", (PyCFunction)Sbk_QDeclarativeComponentFunc_isLoading, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QDeclarativeComponentFunc_isNull, METH_NOARGS},
    {"isReady", (PyCFunction)Sbk_QDeclarativeComponentFunc_isReady, METH_NOARGS},
    {"loadUrl", (PyCFunction)Sbk_QDeclarativeComponentFunc_loadUrl, METH_O},
    {"progress", (PyCFunction)Sbk_QDeclarativeComponentFunc_progress, METH_NOARGS},
    {"setData", (PyCFunction)Sbk_QDeclarativeComponentFunc_setData, METH_VARARGS},
    {"status", (PyCFunction)Sbk_QDeclarativeComponentFunc_status, METH_NOARGS},
    {"url", (PyCFunction)Sbk_QDeclarativeComponentFunc_url, METH_NOARGS},

    {0} // Sentinel
};

static int Sbk_QDeclarativeComponent___nb_bool(PyObject* self)
{
    ::QDeclarativeComponent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDeclarativeComponent*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDeclarativeComponent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeComponent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDeclarativeComponent_TypeAsNumber;

static SbkObjectType Sbk_QDeclarativeComponent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeComponent",
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
    /*tp_traverse*/         Sbk_QDeclarativeComponent_traverse,
    /*tp_clear*/            Sbk_QDeclarativeComponent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeComponent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeComponent_Init,
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

static void* Sbk_QDeclarativeComponent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDeclarativeComponent*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QDeclarativeComponent_Status_PythonToCpp_QDeclarativeComponent_Status(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeComponent::Status*)cppOut) = (::QDeclarativeComponent::Status) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDeclarativeComponent_Status_PythonToCpp_QDeclarativeComponent_Status_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX]))
        return QDeclarativeComponent_Status_PythonToCpp_QDeclarativeComponent_Status;
    return 0;
}
static PyObject* QDeclarativeComponent_Status_CppToPython_QDeclarativeComponent_Status(const void* cppIn) {
    int castCppIn = *((::QDeclarativeComponent::Status*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeComponent_PythonToCpp_QDeclarativeComponent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeComponent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeComponent_PythonToCpp_QDeclarativeComponent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeComponent_Type))
        return QDeclarativeComponent_PythonToCpp_QDeclarativeComponent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeComponent_PTR_CppToPython_QDeclarativeComponent(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDeclarativeComponent*)cppIn, &Sbk_QDeclarativeComponent_Type);

}

void init_QDeclarativeComponent(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDeclarativeComponent_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDeclarativeComponent_TypeAsNumber) = Sbk_QDeclarativeComponent___nb_bool;
    Sbk_QDeclarativeComponent_Type.super.ht_type.tp_as_number = &Sbk_QDeclarativeComponent_TypeAsNumber;

    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeComponent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeComponent", "QDeclarativeComponent*",
        &Sbk_QDeclarativeComponent_Type, &Shiboken::callCppDestructor< ::QDeclarativeComponent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeComponent_Type,
        QDeclarativeComponent_PythonToCpp_QDeclarativeComponent_PTR,
        is_QDeclarativeComponent_PythonToCpp_QDeclarativeComponent_PTR_Convertible,
        QDeclarativeComponent_PTR_CppToPython_QDeclarativeComponent);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeComponent");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeComponent*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeComponent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeComponent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeComponentWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDeclarativeComponent_Type, &Sbk_QDeclarativeComponent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Status'.
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDeclarativeComponent_Type,
        "Status",
        "PySide.QtDeclarative.QDeclarativeComponent.Status",
        "QDeclarativeComponent::Status");
    if (!SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX],
        &Sbk_QDeclarativeComponent_Type, "Null", (long) QDeclarativeComponent::Null))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX],
        &Sbk_QDeclarativeComponent_Type, "Ready", (long) QDeclarativeComponent::Ready))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX],
        &Sbk_QDeclarativeComponent_Type, "Loading", (long) QDeclarativeComponent::Loading))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX],
        &Sbk_QDeclarativeComponent_Type, "Error", (long) QDeclarativeComponent::Error))
        return ;
    // Register converter for enum 'QDeclarativeComponent::Status'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX],
            QDeclarativeComponent_Status_CppToPython_QDeclarativeComponent_Status);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDeclarativeComponent_Status_PythonToCpp_QDeclarativeComponent_Status,
            is_QDeclarativeComponent_Status_PythonToCpp_QDeclarativeComponent_Status_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECOMPONENT_STATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDeclarativeComponent::Status");
        Shiboken::Conversions::registerConverterName(converter, "Status");
    }
    // End of 'Status' enum.

    PySide::Signal::registerSignals(&Sbk_QDeclarativeComponent_Type, &::QDeclarativeComponent::staticMetaObject);

    qRegisterMetaType< ::QDeclarativeComponent::Status >("QDeclarativeComponent::Status");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDeclarativeComponent_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDeclarativeComponent_Type, &::QDeclarativeComponent::staticMetaObject, sizeof(::QDeclarativeComponent));
}
