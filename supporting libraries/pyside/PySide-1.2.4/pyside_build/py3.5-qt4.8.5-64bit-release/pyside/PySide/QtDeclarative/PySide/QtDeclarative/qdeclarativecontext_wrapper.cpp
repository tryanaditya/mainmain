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

#include "qdeclarativecontext_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdeclarativecontext.h>
#include <qdeclarativeengine.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qurl.h>


// Native ---------------------------------------------------------

QDeclarativeContextWrapper::QDeclarativeContextWrapper(QDeclarativeContext * parent, QObject * objParent) : QDeclarativeContext(parent, objParent) {
    // ... middle
}

QDeclarativeContextWrapper::QDeclarativeContextWrapper(QDeclarativeEngine * parent, QObject * objParent) : QDeclarativeContext(parent, objParent) {
    // ... middle
}

void QDeclarativeContextWrapper::childEvent(QChildEvent * arg__1)
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

void QDeclarativeContextWrapper::connectNotify(const char * signal)
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

void QDeclarativeContextWrapper::customEvent(QEvent * arg__1)
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

void QDeclarativeContextWrapper::disconnectNotify(const char * signal)
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

bool QDeclarativeContextWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeContext.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDeclarativeContextWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeContext.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDeclarativeContextWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QDeclarativeContextWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDeclarativeContext::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDeclarativeContextWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDeclarativeContext::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDeclarativeContextWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDeclarativeContextWrapper* >(this));
        return QDeclarativeContext::qt_metacast(_clname);
}

QDeclarativeContextWrapper::~QDeclarativeContextWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeContext_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"objParent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeContext >()))
        return -1;

    ::QDeclarativeContextWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeContext(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QDeclarativeContext", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeContext(QDeclarativeContext*,QObject*)
    // 1: QDeclarativeContext(QDeclarativeEngine*,QObject*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QDeclarativeContext(QDeclarativeEngine*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QDeclarativeContext(QDeclarativeEngine*,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QDeclarativeContext(QDeclarativeContext*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // QDeclarativeContext(QDeclarativeContext*,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContext_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDeclarativeContext(QDeclarativeContext * parent, QObject * objParent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "objParent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeContext(): got multiple values for keyword argument 'objParent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QDeclarativeContext_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeContext* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDeclarativeContext(QDeclarativeContext*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeContextWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeContextWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QDeclarativeContext(QDeclarativeEngine * parent, QObject * objParent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "objParent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeContext(): got multiple values for keyword argument 'objParent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QDeclarativeContext_Init_TypeError;
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
                // QDeclarativeContext(QDeclarativeEngine*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeContextWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeContextWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeContext >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeContext_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDeclarativeContext_Init_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeContext, PySide.QtCore.QObject = None", "PySide.QtDeclarative.QDeclarativeEngine, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeContext", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativeContextFunc_baseUrl(PyObject* self)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // baseUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->baseUrl();
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

static PyObject* Sbk_QDeclarativeContextFunc_contextObject(PyObject* self)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contextObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->contextObject();
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

static PyObject* Sbk_QDeclarativeContextFunc_contextProperty(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextProperty(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // contextProperty(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContextFunc_contextProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextProperty(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->contextProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativeContextFunc_contextProperty_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeContext.contextProperty", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeContextFunc_engine(PyObject* self)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeEngine * cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->engine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeContextFunc_isValid(PyObject* self)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->isValid();
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

static PyObject* Sbk_QDeclarativeContextFunc_parentContext(PyObject* self)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeContext * cppResult = const_cast<const ::QDeclarativeContext*>(cppSelf)->parentContext();
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

static PyObject* Sbk_QDeclarativeContextFunc_resolvedUrl(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resolvedUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // resolvedUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContextFunc_resolvedUrl_TypeError;

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
            // resolvedUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = cppSelf->resolvedUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativeContextFunc_resolvedUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeContext.resolvedUrl", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeContextFunc_setBaseUrl(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBaseUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setBaseUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContextFunc_setBaseUrl_TypeError;

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
            // setBaseUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBaseUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeContextFunc_setBaseUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeContext.setBaseUrl", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeContextFunc_setContextObject(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContextObject(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // setContextObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContextFunc_setContextObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContextObject(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContextObject(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeContextFunc_setContextObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeContext.setContextObject", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeContextFunc_setContextProperty(PyObject* self, PyObject* args)
{
    ::QDeclarativeContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setContextProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setContextProperty(QString,QObject*)
    // 1: setContextProperty(QString,QVariant)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // setContextProperty(QString,QObject*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 1; // setContextProperty(QString,QVariant)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeContextFunc_setContextProperty_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setContextProperty(const QString & arg__1, QObject * arg__2)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContextProperty(QString,QObject*)

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setContextProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // Begin code injection

                QByteArray key("setContextProperty_");
                key.append(cppArg0.toLocal8Bit());
                Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), key.constData(),  pyArgs[2-1]);

                // End of code injection
            }
            break;
        }
        case 1: // setContextProperty(const QString & arg__1, const QVariant & arg__2)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContextProperty(QString,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setContextProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeContextFunc_setContextProperty_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QObject", "unicode, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeContext.setContextProperty", overloads);
        return 0;
}

static PyMethodDef Sbk_QDeclarativeContext_methods[] = {
    {"baseUrl", (PyCFunction)Sbk_QDeclarativeContextFunc_baseUrl, METH_NOARGS},
    {"contextObject", (PyCFunction)Sbk_QDeclarativeContextFunc_contextObject, METH_NOARGS},
    {"contextProperty", (PyCFunction)Sbk_QDeclarativeContextFunc_contextProperty, METH_O},
    {"engine", (PyCFunction)Sbk_QDeclarativeContextFunc_engine, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QDeclarativeContextFunc_isValid, METH_NOARGS},
    {"parentContext", (PyCFunction)Sbk_QDeclarativeContextFunc_parentContext, METH_NOARGS},
    {"resolvedUrl", (PyCFunction)Sbk_QDeclarativeContextFunc_resolvedUrl, METH_O},
    {"setBaseUrl", (PyCFunction)Sbk_QDeclarativeContextFunc_setBaseUrl, METH_O},
    {"setContextObject", (PyCFunction)Sbk_QDeclarativeContextFunc_setContextObject, METH_O},
    {"setContextProperty", (PyCFunction)Sbk_QDeclarativeContextFunc_setContextProperty, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDeclarativeContext_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeContext_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeContext_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeContext",
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
    /*tp_traverse*/         Sbk_QDeclarativeContext_traverse,
    /*tp_clear*/            Sbk_QDeclarativeContext_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeContext_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeContext_Init,
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

static void* Sbk_QDeclarativeContext_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDeclarativeContext*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeContext_PythonToCpp_QDeclarativeContext_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeContext_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeContext_PythonToCpp_QDeclarativeContext_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeContext_Type))
        return QDeclarativeContext_PythonToCpp_QDeclarativeContext_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeContext_PTR_CppToPython_QDeclarativeContext(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDeclarativeContext*)cppIn, &Sbk_QDeclarativeContext_Type);

}

void init_QDeclarativeContext(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeContext_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeContext", "QDeclarativeContext*",
        &Sbk_QDeclarativeContext_Type, &Shiboken::callCppDestructor< ::QDeclarativeContext >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeContext_Type,
        QDeclarativeContext_PythonToCpp_QDeclarativeContext_PTR,
        is_QDeclarativeContext_PythonToCpp_QDeclarativeContext_PTR_Convertible,
        QDeclarativeContext_PTR_CppToPython_QDeclarativeContext);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeContext");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeContext*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeContext&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeContext).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeContextWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDeclarativeContext_Type, &Sbk_QDeclarativeContext_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QDeclarativeContext_Type, &::QDeclarativeContext::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDeclarativeContext_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDeclarativeContext_Type, &::QDeclarativeContext::staticMetaObject, sizeof(::QDeclarativeContext));
}
