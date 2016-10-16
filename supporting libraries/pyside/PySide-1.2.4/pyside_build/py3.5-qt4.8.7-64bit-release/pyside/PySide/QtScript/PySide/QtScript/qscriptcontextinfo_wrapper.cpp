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

#include "qscriptcontextinfo_wrapper.h"

// Extra includes
#include <qdatastream.h>
#include <qscriptcontext.h>
#include <qscriptcontextinfo.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptContextInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptContextInfo >()))
        return -1;

    ::QScriptContextInfo* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QScriptContextInfo", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptContextInfo()
    // 1: QScriptContextInfo(const QScriptContext*)
    // 2: QScriptContextInfo(QScriptContextInfo)
    if (numArgs == 0) {
        overloadId = 0; // QScriptContextInfo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QScriptContextInfo(const QScriptContext*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (pyArgs[0])))) {
        overloadId = 2; // QScriptContextInfo(QScriptContextInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QScriptContextInfo()
        {

            if (!PyErr_Occurred()) {
                // QScriptContextInfo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptContextInfo();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QScriptContextInfo(const QScriptContext * context)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptContext* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptContextInfo(const QScriptContext*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptContextInfo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QScriptContextInfo(const QScriptContextInfo & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptContextInfo cppArg0_local = ::QScriptContextInfo();
            ::QScriptContextInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QScriptContextInfo(QScriptContextInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptContextInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptContextInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptContextInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QScriptContextInfo_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtScript.QScriptContext", "PySide.QtScript.QScriptContextInfo", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptContextInfo", overloads);
        return -1;
}

static PyObject* Sbk_QScriptContextInfoFunc_columnNumber(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->columnNumber();
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

static PyObject* Sbk_QScriptContextInfoFunc_fileName(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->fileName();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionEndLineNumber(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionEndLineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionEndLineNumber();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionMetaIndex(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionMetaIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionMetaIndex();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionName(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionName();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionParameterNames(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionParameterNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionParameterNames();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionStartLineNumber(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionStartLineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionStartLineNumber();
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

static PyObject* Sbk_QScriptContextInfoFunc_functionType(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // functionType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptContextInfo::FunctionType cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->functionType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextInfoFunc_isNull(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->isNull();
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

static PyObject* Sbk_QScriptContextInfoFunc_lineNumber(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QScriptContextInfoFunc_scriptId(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scriptId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QScriptContextInfo*>(cppSelf)->scriptId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptContextInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptContextInfo& cppSelf = *(((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QScriptContextInfo_methods[] = {
    {"columnNumber", (PyCFunction)Sbk_QScriptContextInfoFunc_columnNumber, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QScriptContextInfoFunc_fileName, METH_NOARGS},
    {"functionEndLineNumber", (PyCFunction)Sbk_QScriptContextInfoFunc_functionEndLineNumber, METH_NOARGS},
    {"functionMetaIndex", (PyCFunction)Sbk_QScriptContextInfoFunc_functionMetaIndex, METH_NOARGS},
    {"functionName", (PyCFunction)Sbk_QScriptContextInfoFunc_functionName, METH_NOARGS},
    {"functionParameterNames", (PyCFunction)Sbk_QScriptContextInfoFunc_functionParameterNames, METH_NOARGS},
    {"functionStartLineNumber", (PyCFunction)Sbk_QScriptContextInfoFunc_functionStartLineNumber, METH_NOARGS},
    {"functionType", (PyCFunction)Sbk_QScriptContextInfoFunc_functionType, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QScriptContextInfoFunc_isNull, METH_NOARGS},
    {"lineNumber", (PyCFunction)Sbk_QScriptContextInfoFunc_lineNumber, METH_NOARGS},
    {"scriptId", (PyCFunction)Sbk_QScriptContextInfoFunc_scriptId, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QScriptContextInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QScriptContextInfo___nb_bool(PyObject* self)
{
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QScriptContextInfoFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QScriptContextInfo)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QScriptContextInfo)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextInfoFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QScriptContextInfo) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptContextInfoFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContextInfo.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QScriptContextInfoFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QScriptContextInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QScriptContextInfo&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QScriptContextInfo&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptContextInfoFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QScriptContextInfo&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptContextInfoFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptContextInfo.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QScriptContextInfo_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptContextInfo& cppSelf = *(((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (pyArg)))) {
                // operator!=(const QScriptContextInfo & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QScriptContextInfo cppArg0_local = ::QScriptContextInfo();
                ::QScriptContextInfo* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (pyArg)))) {
                // operator==(const QScriptContextInfo & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QScriptContextInfo cppArg0_local = ::QScriptContextInfo();
                ::QScriptContextInfo* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QScriptContextInfo_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QScriptContextInfo_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QScriptContextInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptContextInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QScriptContextInfo_TypeAsNumber;

static SbkObjectType Sbk_QScriptContextInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptContextInfo",
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
    /*tp_traverse*/         Sbk_QScriptContextInfo_traverse,
    /*tp_clear*/            Sbk_QScriptContextInfo_clear,
    /*tp_richcompare*/      Sbk_QScriptContextInfo_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptContextInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptContextInfo_Init,
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


// Type conversion functions.

// Python to C++ enum conversion.
static void QScriptContextInfo_FunctionType_PythonToCpp_QScriptContextInfo_FunctionType(PyObject* pyIn, void* cppOut) {
    *((::QScriptContextInfo::FunctionType*)cppOut) = (::QScriptContextInfo::FunctionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptContextInfo_FunctionType_PythonToCpp_QScriptContextInfo_FunctionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX]))
        return QScriptContextInfo_FunctionType_PythonToCpp_QScriptContextInfo_FunctionType;
    return 0;
}
static PyObject* QScriptContextInfo_FunctionType_CppToPython_QScriptContextInfo_FunctionType(const void* cppIn) {
    int castCppIn = *((::QScriptContextInfo::FunctionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptContextInfo_PythonToCpp_QScriptContextInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptContextInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptContextInfo_PythonToCpp_QScriptContextInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptContextInfo_Type))
        return QScriptContextInfo_PythonToCpp_QScriptContextInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptContextInfo_PTR_CppToPython_QScriptContextInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptContextInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptContextInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QScriptContextInfo_COPY_CppToPython_QScriptContextInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QScriptContextInfo_Type, new ::QScriptContextInfo(*((::QScriptContextInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QScriptContextInfo_PythonToCpp_QScriptContextInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QScriptContextInfo*)cppOut) = *((::QScriptContextInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QScriptContextInfo_PythonToCpp_QScriptContextInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptContextInfo_Type))
        return QScriptContextInfo_PythonToCpp_QScriptContextInfo_COPY;
    return 0;
}

// Implicit conversions.
static void constQScriptContextPTR_PythonToCpp_QScriptContextInfo(PyObject* pyIn, void* cppOut) {
    *((::QScriptContextInfo*)cppOut) = ::QScriptContextInfo(((::QScriptContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQScriptContextPTR_PythonToCpp_QScriptContextInfo_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], pyIn))
        return constQScriptContextPTR_PythonToCpp_QScriptContextInfo;
    return 0;
}

void init_QScriptContextInfo(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QScriptContextInfo_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QScriptContextInfo_TypeAsNumber.nb_rshift = Sbk_QScriptContextInfoFunc___rshift__;
    Sbk_QScriptContextInfo_TypeAsNumber.nb_lshift = Sbk_QScriptContextInfoFunc___lshift__;
    SBK_NB_BOOL(Sbk_QScriptContextInfo_TypeAsNumber) = Sbk_QScriptContextInfo___nb_bool;
    Sbk_QScriptContextInfo_Type.super.ht_type.tp_as_number = &Sbk_QScriptContextInfo_TypeAsNumber;

    SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptContextInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptContextInfo", "QScriptContextInfo",
        &Sbk_QScriptContextInfo_Type, &Shiboken::callCppDestructor< ::QScriptContextInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptContextInfo_Type,
        QScriptContextInfo_PythonToCpp_QScriptContextInfo_PTR,
        is_QScriptContextInfo_PythonToCpp_QScriptContextInfo_PTR_Convertible,
        QScriptContextInfo_PTR_CppToPython_QScriptContextInfo,
        QScriptContextInfo_COPY_CppToPython_QScriptContextInfo);

    Shiboken::Conversions::registerConverterName(converter, "QScriptContextInfo");
    Shiboken::Conversions::registerConverterName(converter, "QScriptContextInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptContextInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptContextInfo).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QScriptContextInfo_PythonToCpp_QScriptContextInfo_COPY,
        is_QScriptContextInfo_PythonToCpp_QScriptContextInfo_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQScriptContextPTR_PythonToCpp_QScriptContextInfo,
        is_constQScriptContextPTR_PythonToCpp_QScriptContextInfo_Convertible);

    // Initialization of enums.

    // Initialization of enum 'FunctionType'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptContextInfo_Type,
        "FunctionType",
        "PySide.QtScript.QScriptContextInfo.FunctionType",
        "QScriptContextInfo::FunctionType");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX],
        &Sbk_QScriptContextInfo_Type, "ScriptFunction", (long) QScriptContextInfo::ScriptFunction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX],
        &Sbk_QScriptContextInfo_Type, "QtFunction", (long) QScriptContextInfo::QtFunction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX],
        &Sbk_QScriptContextInfo_Type, "QtPropertyFunction", (long) QScriptContextInfo::QtPropertyFunction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX],
        &Sbk_QScriptContextInfo_Type, "NativeFunction", (long) QScriptContextInfo::NativeFunction))
        return ;
    // Register converter for enum 'QScriptContextInfo::FunctionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX],
            QScriptContextInfo_FunctionType_CppToPython_QScriptContextInfo_FunctionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptContextInfo_FunctionType_PythonToCpp_QScriptContextInfo_FunctionType,
            is_QScriptContextInfo_FunctionType_PythonToCpp_QScriptContextInfo_FunctionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXTINFO_FUNCTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptContextInfo::FunctionType");
        Shiboken::Conversions::registerConverterName(converter, "FunctionType");
    }
    // End of 'FunctionType' enum.


    qRegisterMetaType< ::QScriptContextInfo >("QScriptContextInfo");
    qRegisterMetaType< ::QScriptContextInfo::FunctionType >("QScriptContextInfo::FunctionType");
}
