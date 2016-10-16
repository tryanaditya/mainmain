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
#include "pyside_qtscript_python.h"

#include "qscriptcontext_wrapper.h"

// Extra includes
#include <QList>
#include <qscriptcontext.h>
#include <qscriptengine.h>
#include <qscriptvalue.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QScriptContextFunc_activationObject(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activationObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->activationObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_argument(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: argument(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // argument(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_argument_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // argument(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->argument(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptContextFunc_argument_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.argument", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_argumentCount(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // argumentCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContext*>(cppSelf)->argumentCount();
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

static PyObject* Sbk_QScriptContextFunc_argumentsObject(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // argumentsObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->argumentsObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_backtrace(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backtrace()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QScriptContext*>(cppSelf)->backtrace();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_callee(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // callee()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->callee();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_engine(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngine * cppResult = const_cast<const ::QScriptContext*>(cppSelf)->engine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_isCalledAsConstructor(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCalledAsConstructor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptContext*>(cppSelf)->isCalledAsConstructor();
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

static PyObject* Sbk_QScriptContextFunc_parentContext(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptContext * cppResult = const_cast<const ::QScriptContext*>(cppSelf)->parentContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_popScope(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // popScope()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->popScope();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_pushScope(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: pushScope(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // pushScope(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_pushScope_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // pushScope(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pushScope(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptContextFunc_pushScope_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.pushScope", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_returnValue(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // returnValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->returnValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_scopeChain(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scopeChain()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QScriptValue > cppResult = const_cast<const ::QScriptContext*>(cppSelf)->scopeChain();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtScriptTypeConverters[SBK_QTSCRIPT_QLIST_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_setActivationObject(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActivationObject(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setActivationObject(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_setActivationObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setActivationObject(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActivationObject(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptContextFunc_setActivationObject_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.setActivationObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_setReturnValue(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReturnValue(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setReturnValue(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_setReturnValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setReturnValue(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReturnValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptContextFunc_setReturnValue_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.setReturnValue", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_setThisObject(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setThisObject(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setThisObject(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_setThisObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setThisObject(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setThisObject(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptContextFunc_setThisObject_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.setThisObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_state(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptContext::ExecutionState cppResult = const_cast<const ::QScriptContext*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_thisObject(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // thisObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptContext*>(cppSelf)->thisObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextFunc_throwError(PyObject* self, PyObject* args)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "throwError", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: throwError(QScriptContext::Error,QString)
    // 1: throwError(QString)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // throwError(QString)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // throwError(QScriptContext::Error,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_throwError_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // throwError(QScriptContext::Error error, const QString & text)
        {
            ::QScriptContext::Error cppArg0 = ((::QScriptContext::Error)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // throwError(QScriptContext::Error,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->throwError(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // throwError(const QString & text)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // throwError(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->throwError(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptContextFunc_throwError_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptContext.Error, unicode", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptContext.throwError", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_throwValue(PyObject* self, PyObject* pyArg)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: throwValue(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // throwValue(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextFunc_throwValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // throwValue(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->throwValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptContextFunc_throwValue_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContext.throwValue", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextFunc_toString(PyObject* self)
{
    ::QScriptContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptContext*>(cppSelf)->toString();
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

static PyMethodDef Sbk_QScriptContext_methods[] = {
    {"activationObject", (PyCFunction)Sbk_QScriptContextFunc_activationObject, METH_NOARGS},
    {"argument", (PyCFunction)Sbk_QScriptContextFunc_argument, METH_O},
    {"argumentCount", (PyCFunction)Sbk_QScriptContextFunc_argumentCount, METH_NOARGS},
    {"argumentsObject", (PyCFunction)Sbk_QScriptContextFunc_argumentsObject, METH_NOARGS},
    {"backtrace", (PyCFunction)Sbk_QScriptContextFunc_backtrace, METH_NOARGS},
    {"callee", (PyCFunction)Sbk_QScriptContextFunc_callee, METH_NOARGS},
    {"engine", (PyCFunction)Sbk_QScriptContextFunc_engine, METH_NOARGS},
    {"isCalledAsConstructor", (PyCFunction)Sbk_QScriptContextFunc_isCalledAsConstructor, METH_NOARGS},
    {"parentContext", (PyCFunction)Sbk_QScriptContextFunc_parentContext, METH_NOARGS},
    {"popScope", (PyCFunction)Sbk_QScriptContextFunc_popScope, METH_NOARGS},
    {"pushScope", (PyCFunction)Sbk_QScriptContextFunc_pushScope, METH_O},
    {"returnValue", (PyCFunction)Sbk_QScriptContextFunc_returnValue, METH_NOARGS},
    {"scopeChain", (PyCFunction)Sbk_QScriptContextFunc_scopeChain, METH_NOARGS},
    {"setActivationObject", (PyCFunction)Sbk_QScriptContextFunc_setActivationObject, METH_O},
    {"setReturnValue", (PyCFunction)Sbk_QScriptContextFunc_setReturnValue, METH_O},
    {"setThisObject", (PyCFunction)Sbk_QScriptContextFunc_setThisObject, METH_O},
    {"state", (PyCFunction)Sbk_QScriptContextFunc_state, METH_NOARGS},
    {"thisObject", (PyCFunction)Sbk_QScriptContextFunc_thisObject, METH_NOARGS},
    {"throwError", (PyCFunction)Sbk_QScriptContextFunc_throwError, METH_VARARGS},
    {"throwValue", (PyCFunction)Sbk_QScriptContextFunc_throwValue, METH_O},
    {"toString", (PyCFunction)Sbk_QScriptContextFunc_toString, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QScriptContext_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptContext_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QScriptContext_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptContext",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QScriptContext_traverse,
    /*tp_clear*/            Sbk_QScriptContext_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptContext_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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


// Type conversion functions.

// Python to C++ enum conversion.
static void QScriptContext_ExecutionState_PythonToCpp_QScriptContext_ExecutionState(PyObject* pyIn, void* cppOut) {
    *((::QScriptContext::ExecutionState*)cppOut) = (::QScriptContext::ExecutionState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptContext_ExecutionState_PythonToCpp_QScriptContext_ExecutionState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX]))
        return QScriptContext_ExecutionState_PythonToCpp_QScriptContext_ExecutionState;
    return 0;
}
static PyObject* QScriptContext_ExecutionState_CppToPython_QScriptContext_ExecutionState(const void* cppIn) {
    int castCppIn = *((::QScriptContext::ExecutionState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX], castCppIn);

}

static void QScriptContext_Error_PythonToCpp_QScriptContext_Error(PyObject* pyIn, void* cppOut) {
    *((::QScriptContext::Error*)cppOut) = (::QScriptContext::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptContext_Error_PythonToCpp_QScriptContext_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX]))
        return QScriptContext_Error_PythonToCpp_QScriptContext_Error;
    return 0;
}
static PyObject* QScriptContext_Error_CppToPython_QScriptContext_Error(const void* cppIn) {
    int castCppIn = *((::QScriptContext::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptContext_PythonToCpp_QScriptContext_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptContext_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptContext_PythonToCpp_QScriptContext_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptContext_Type))
        return QScriptContext_PythonToCpp_QScriptContext_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptContext_PTR_CppToPython_QScriptContext(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptContext*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptContext_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QScriptContext(PyObject* module)
{
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptContext_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptContext", "QScriptContext*",
        &Sbk_QScriptContext_Type, &Shiboken::callCppDestructor< ::QScriptContext >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptContext_Type,
        QScriptContext_PythonToCpp_QScriptContext_PTR,
        is_QScriptContext_PythonToCpp_QScriptContext_PTR_Convertible,
        QScriptContext_PTR_CppToPython_QScriptContext);

    Shiboken::Conversions::registerConverterName(converter, "QScriptContext");
    Shiboken::Conversions::registerConverterName(converter, "QScriptContext*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptContext&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptContext).name());


    // Initialization of enums.

    // Initialization of enum 'ExecutionState'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptContext_Type,
        "ExecutionState",
        "PySide.QtScript.QScriptContext.ExecutionState",
        "QScriptContext::ExecutionState");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX],
        &Sbk_QScriptContext_Type, "NormalState", (long) QScriptContext::NormalState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX],
        &Sbk_QScriptContext_Type, "ExceptionState", (long) QScriptContext::ExceptionState))
        return ;
    // Register converter for enum 'QScriptContext::ExecutionState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX],
            QScriptContext_ExecutionState_CppToPython_QScriptContext_ExecutionState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptContext_ExecutionState_PythonToCpp_QScriptContext_ExecutionState,
            is_QScriptContext_ExecutionState_PythonToCpp_QScriptContext_ExecutionState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_EXECUTIONSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptContext::ExecutionState");
        Shiboken::Conversions::registerConverterName(converter, "ExecutionState");
    }
    // End of 'ExecutionState' enum.

    // Initialization of enum 'Error'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptContext_Type,
        "Error",
        "PySide.QtScript.QScriptContext.Error",
        "QScriptContext::Error");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "UnknownError", (long) QScriptContext::UnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "ReferenceError", (long) QScriptContext::ReferenceError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "SyntaxError", (long) QScriptContext::SyntaxError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "TypeError", (long) QScriptContext::TypeError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "RangeError", (long) QScriptContext::RangeError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
        &Sbk_QScriptContext_Type, "URIError", (long) QScriptContext::URIError))
        return ;
    // Register converter for enum 'QScriptContext::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX],
            QScriptContext_Error_CppToPython_QScriptContext_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptContext_Error_PythonToCpp_QScriptContext_Error,
            is_QScriptContext_Error_PythonToCpp_QScriptContext_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptContext::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.


    qRegisterMetaType< ::QScriptContext::ExecutionState >("QScriptContext::ExecutionState");
    qRegisterMetaType< ::QScriptContext::Error >("QScriptContext::Error");
}
