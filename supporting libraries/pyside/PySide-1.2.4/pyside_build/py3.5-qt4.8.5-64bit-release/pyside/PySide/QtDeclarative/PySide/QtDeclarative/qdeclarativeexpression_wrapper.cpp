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

#include "qdeclarativeexpression_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdeclarativecontext.h>
#include <qdeclarativeengine.h>
#include <qdeclarativeerror.h>
#include <qdeclarativeexpression.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QDeclarativeExpressionWrapper::QDeclarativeExpressionWrapper() : QDeclarativeExpression() {
    // ... middle
}

QDeclarativeExpressionWrapper::QDeclarativeExpressionWrapper(QDeclarativeContext * arg__1, QObject * arg__2, const QString & arg__3, QObject * arg__4) : QDeclarativeExpression(arg__1, arg__2, arg__3, arg__4) {
    // ... middle
}

void QDeclarativeExpressionWrapper::childEvent(QChildEvent * arg__1)
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

void QDeclarativeExpressionWrapper::connectNotify(const char * signal)
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

void QDeclarativeExpressionWrapper::customEvent(QEvent * arg__1)
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

void QDeclarativeExpressionWrapper::disconnectNotify(const char * signal)
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

bool QDeclarativeExpressionWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeExpression.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDeclarativeExpressionWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeExpression.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDeclarativeExpressionWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QDeclarativeExpressionWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDeclarativeExpression::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDeclarativeExpressionWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDeclarativeExpression::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDeclarativeExpressionWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDeclarativeExpressionWrapper* >(this));
        return QDeclarativeExpression::qt_metacast(_clname);
}

QDeclarativeExpressionWrapper::~QDeclarativeExpressionWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeExpression_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"arg__4"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeExpression >()))
        return -1;

    ::QDeclarativeExpressionWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 1 || numArgs == 2)
        goto Sbk_QDeclarativeExpression_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:QDeclarativeExpression", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeExpression()
    // 1: QDeclarativeExpression(QDeclarativeContext*,QObject*,QString,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QDeclarativeExpression()
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 1; // QDeclarativeExpression(QDeclarativeContext*,QObject*,QString,QObject*)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3])))) {
            overloadId = 1; // QDeclarativeExpression(QDeclarativeContext*,QObject*,QString,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeExpression_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDeclarativeExpression()
        {

            if (!PyErr_Occurred()) {
                // QDeclarativeExpression()
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeExpressionWrapper();
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeExpressionWrapper();
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDeclarativeExpression(QDeclarativeContext * arg__1, QObject * arg__2, const QString & arg__3, QObject * arg__4)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__4");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtDeclarative.QDeclarativeExpression(): got multiple values for keyword argument 'arg__4'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3]))))
                        goto Sbk_QDeclarativeExpression_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeContext* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QObject* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QDeclarativeExpression(QDeclarativeContext*,QObject*,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDeclarativeExpressionWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDeclarativeExpressionWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeExpression >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeExpression_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDeclarativeExpression_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtDeclarative.QDeclarativeContext, PySide.QtCore.QObject, unicode, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeExpression", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_clearError(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QDeclarativeExpressionFunc_context(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // context()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeContext * cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->context();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_engine(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeEngine * cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->engine();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_error(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeError cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEERROR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_evaluate(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // evaluate(bool*)
            // Begin code injection

            // TEMPLATE - fix_bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant retval_ = cppSelf->evaluate(&ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_expression(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expression()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->expression();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_hasError(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->hasError();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_lineNumber(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_notifyOnValueChanged(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notifyOnValueChanged()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->notifyOnValueChanged();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_scopeObject(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scopeObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->scopeObject();
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

static PyObject* Sbk_QDeclarativeExpressionFunc_setExpression(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setExpression(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setExpression(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeExpressionFunc_setExpression_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setExpression(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setExpression(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeExpressionFunc_setExpression_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeExpression.setExpression", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_setNotifyOnValueChanged(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNotifyOnValueChanged(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setNotifyOnValueChanged(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeExpressionFunc_setNotifyOnValueChanged_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNotifyOnValueChanged(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNotifyOnValueChanged(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeExpressionFunc_setNotifyOnValueChanged_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeExpression.setNotifyOnValueChanged", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_setSourceLocation(PyObject* self, PyObject* args)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSourceLocation", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSourceLocation(QString,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setSourceLocation(QString,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeExpressionFunc_setSourceLocation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSourceLocation(QString,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSourceLocation(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeExpressionFunc_setSourceLocation_TypeError:
        const char* overloads[] = {"unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeExpression.setSourceLocation", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeExpressionFunc_sourceFile(PyObject* self)
{
    ::QDeclarativeExpression* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeExpression*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sourceFile()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDeclarativeExpression*>(cppSelf)->sourceFile();
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

static PyMethodDef Sbk_QDeclarativeExpression_methods[] = {
    {"clearError", (PyCFunction)Sbk_QDeclarativeExpressionFunc_clearError, METH_NOARGS},
    {"context", (PyCFunction)Sbk_QDeclarativeExpressionFunc_context, METH_NOARGS},
    {"engine", (PyCFunction)Sbk_QDeclarativeExpressionFunc_engine, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QDeclarativeExpressionFunc_error, METH_NOARGS},
    {"evaluate", (PyCFunction)Sbk_QDeclarativeExpressionFunc_evaluate, METH_NOARGS},
    {"expression", (PyCFunction)Sbk_QDeclarativeExpressionFunc_expression, METH_NOARGS},
    {"hasError", (PyCFunction)Sbk_QDeclarativeExpressionFunc_hasError, METH_NOARGS},
    {"lineNumber", (PyCFunction)Sbk_QDeclarativeExpressionFunc_lineNumber, METH_NOARGS},
    {"notifyOnValueChanged", (PyCFunction)Sbk_QDeclarativeExpressionFunc_notifyOnValueChanged, METH_NOARGS},
    {"scopeObject", (PyCFunction)Sbk_QDeclarativeExpressionFunc_scopeObject, METH_NOARGS},
    {"setExpression", (PyCFunction)Sbk_QDeclarativeExpressionFunc_setExpression, METH_O},
    {"setNotifyOnValueChanged", (PyCFunction)Sbk_QDeclarativeExpressionFunc_setNotifyOnValueChanged, METH_O},
    {"setSourceLocation", (PyCFunction)Sbk_QDeclarativeExpressionFunc_setSourceLocation, METH_VARARGS},
    {"sourceFile", (PyCFunction)Sbk_QDeclarativeExpressionFunc_sourceFile, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDeclarativeExpression_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeExpression_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeExpression_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeExpression",
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
    /*tp_traverse*/         Sbk_QDeclarativeExpression_traverse,
    /*tp_clear*/            Sbk_QDeclarativeExpression_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeExpression_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeExpression_Init,
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

static void* Sbk_QDeclarativeExpression_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDeclarativeExpression*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeExpression_PythonToCpp_QDeclarativeExpression_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeExpression_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeExpression_PythonToCpp_QDeclarativeExpression_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeExpression_Type))
        return QDeclarativeExpression_PythonToCpp_QDeclarativeExpression_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeExpression_PTR_CppToPython_QDeclarativeExpression(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDeclarativeExpression*)cppIn, &Sbk_QDeclarativeExpression_Type);

}

void init_QDeclarativeExpression(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEEXPRESSION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeExpression_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeExpression", "QDeclarativeExpression*",
        &Sbk_QDeclarativeExpression_Type, &Shiboken::callCppDestructor< ::QDeclarativeExpression >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeExpression_Type,
        QDeclarativeExpression_PythonToCpp_QDeclarativeExpression_PTR,
        is_QDeclarativeExpression_PythonToCpp_QDeclarativeExpression_PTR_Convertible,
        QDeclarativeExpression_PTR_CppToPython_QDeclarativeExpression);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeExpression");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeExpression*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeExpression&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeExpression).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeExpressionWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDeclarativeExpression_Type, &Sbk_QDeclarativeExpression_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QDeclarativeExpression_Type, &::QDeclarativeExpression::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDeclarativeExpression_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDeclarativeExpression_Type, &::QDeclarativeExpression::staticMetaObject, sizeof(::QDeclarativeExpression));
}
