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

#include "qscriptengineagent_wrapper.h"

// Extra includes
#include <qscriptengine.h>
#include <qscriptengineagent.h>
#include <qscriptvalue.h>


// Native ---------------------------------------------------------

QScriptEngineAgentWrapper::QScriptEngineAgentWrapper(QScriptEngine * engine) : QScriptEngineAgent(engine) {
    // ... middle
}

void QScriptEngineAgentWrapper::contextPop()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextPop"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::contextPop();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::contextPush()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextPush"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::contextPush();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::exceptionCatch(qint64 scriptId, const QScriptValue & exception)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "exceptionCatch"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::exceptionCatch(scriptId, exception);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(LN)",
        scriptId,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &exception)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::exceptionThrow(qint64 scriptId, const QScriptValue & exception, bool hasHandler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "exceptionThrow"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::exceptionThrow(scriptId, exception, hasHandler);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(LNN)",
        scriptId,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &exception),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &hasHandler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QVariant QScriptEngineAgentWrapper::extension(QScriptEngineAgent::Extension extension, const QVariant & argument)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "extension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::extension(extension, argument);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX]), &extension),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &argument)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngineAgent.extension", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QScriptEngineAgentWrapper::functionEntry(qint64 scriptId)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "functionEntry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::functionEntry(scriptId);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        scriptId
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::functionExit(qint64 scriptId, const QScriptValue & returnValue)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "functionExit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::functionExit(scriptId, returnValue);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(LN)",
        scriptId,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &returnValue)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::positionChange(qint64 scriptId, int lineNumber, int columnNumber)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "positionChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::positionChange(scriptId, lineNumber, columnNumber);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Lii)",
        scriptId,
        lineNumber,
        columnNumber
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::scriptLoad(qint64 id, const QString & program, const QString & fileName, int baseLineNumber)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scriptLoad"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::scriptLoad(id, program, fileName, baseLineNumber);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(LNNi)",
        id,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &program),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &fileName),
        baseLineNumber
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QScriptEngineAgentWrapper::scriptUnload(qint64 id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scriptUnload"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::scriptUnload(id);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        id
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QScriptEngineAgentWrapper::supportsExtension(QScriptEngineAgent::Extension extension) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportsExtension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptEngineAgent::supportsExtension(extension);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX]), &extension)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngineAgent.supportsExtension", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QScriptEngineAgentWrapper::~QScriptEngineAgentWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptEngineAgent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptEngineAgent >()))
        return -1;

    ::QScriptEngineAgentWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QScriptEngineAgent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptEngineAgent(QScriptEngine*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (pyArgs[0])))) {
        overloadId = 0; // QScriptEngineAgent(QScriptEngine*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgent_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QScriptEngine* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QScriptEngineAgent(QScriptEngine*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QScriptEngineAgentWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptEngineAgent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptEngineAgent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QScriptEngineAgent_Init_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngine", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent", overloads);
        return -1;
}

static PyObject* Sbk_QScriptEngineAgentFunc_contextPop(PyObject* self)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contextPop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::contextPop() : cppSelf->contextPop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QScriptEngineAgentFunc_contextPush(PyObject* self)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contextPush()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::contextPush() : cppSelf->contextPush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QScriptEngineAgentFunc_engine(PyObject* self)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngine * cppResult = const_cast<const ::QScriptEngineAgent*>(cppSelf)->engine();
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

static PyObject* Sbk_QScriptEngineAgentFunc_exceptionCatch(PyObject* self, PyObject* args)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "exceptionCatch", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: exceptionCatch(qint64,QScriptValue)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        overloadId = 0; // exceptionCatch(qint64,QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_exceptionCatch_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QScriptValue cppArg1_local = ::QScriptValue();
        ::QScriptValue* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // exceptionCatch(qint64,QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::exceptionCatch(cppArg0, *cppArg1) : cppSelf->exceptionCatch(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_exceptionCatch_TypeError:
        const char* overloads[] = {"long long, PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.exceptionCatch", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_exceptionThrow(PyObject* self, PyObject* args)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "exceptionThrow", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: exceptionThrow(qint64,QScriptValue,bool)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // exceptionThrow(qint64,QScriptValue,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_exceptionThrow_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QScriptValue cppArg1_local = ::QScriptValue();
        ::QScriptValue* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // exceptionThrow(qint64,QScriptValue,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::exceptionThrow(cppArg0, *cppArg1, cppArg2) : cppSelf->exceptionThrow(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_exceptionThrow_TypeError:
        const char* overloads[] = {"long long, PySide.QtScript.QScriptValue, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.exceptionThrow", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_extension(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngineAgent.extension(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngineAgent.extension(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:extension", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: extension(QScriptEngineAgent::Extension,QVariant)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // extension(QScriptEngineAgent::Extension,QVariant)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 0; // extension(QScriptEngineAgent::Extension,QVariant)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_extension_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "argument");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngineAgent.extension(): got multiple values for keyword argument 'argument'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1]))))
                    goto Sbk_QScriptEngineAgentFunc_extension_TypeError;
            }
        }
        ::QScriptEngineAgent::Extension cppArg0 = ((::QScriptEngineAgent::Extension)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = QVariant();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // extension(QScriptEngineAgent::Extension,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::extension(cppArg0, cppArg1) : cppSelf->extension(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineAgentFunc_extension_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngineAgent.Extension, QVariant = QVariant()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.extension", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_functionEntry(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: functionEntry(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // functionEntry(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_functionEntry_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // functionEntry(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::functionEntry(cppArg0) : cppSelf->functionEntry(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_functionEntry_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngineAgent.functionEntry", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_functionExit(PyObject* self, PyObject* args)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "functionExit", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: functionExit(qint64,QScriptValue)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        overloadId = 0; // functionExit(qint64,QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_functionExit_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QScriptValue cppArg1_local = ::QScriptValue();
        ::QScriptValue* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // functionExit(qint64,QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::functionExit(cppArg0, *cppArg1) : cppSelf->functionExit(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_functionExit_TypeError:
        const char* overloads[] = {"long long, PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.functionExit", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_positionChange(PyObject* self, PyObject* args)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "positionChange", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: positionChange(qint64,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // positionChange(qint64,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_positionChange_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // positionChange(qint64,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::positionChange(cppArg0, cppArg1, cppArg2) : cppSelf->positionChange(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_positionChange_TypeError:
        const char* overloads[] = {"long long, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.positionChange", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_scriptLoad(PyObject* self, PyObject* args)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scriptLoad", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: scriptLoad(qint64,QString,QString,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 0; // scriptLoad(qint64,QString,QString,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_scriptLoad_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // scriptLoad(qint64,QString,QString,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::scriptLoad(cppArg0, cppArg1, cppArg2, cppArg3) : cppSelf->scriptLoad(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_scriptLoad_TypeError:
        const char* overloads[] = {"long long, unicode, unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngineAgent.scriptLoad", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_scriptUnload(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scriptUnload(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // scriptUnload(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_scriptUnload_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scriptUnload(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptEngineAgent::scriptUnload(cppArg0) : cppSelf->scriptUnload(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineAgentFunc_scriptUnload_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngineAgent.scriptUnload", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineAgentFunc_supportsExtension(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineAgent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineAgent*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsExtension(QScriptEngineAgent::Extension)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsExtension(QScriptEngineAgent::Extension)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineAgentFunc_supportsExtension_TypeError;

    // Call function/method
    {
        ::QScriptEngineAgent::Extension cppArg0 = ((::QScriptEngineAgent::Extension)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsExtension(QScriptEngineAgent::Extension)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QScriptEngineAgent*>(cppSelf)->::QScriptEngineAgent::supportsExtension(cppArg0) : const_cast<const ::QScriptEngineAgent*>(cppSelf)->supportsExtension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineAgentFunc_supportsExtension_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngineAgent.Extension", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngineAgent.supportsExtension", overloads);
        return 0;
}

static PyMethodDef Sbk_QScriptEngineAgent_methods[] = {
    {"contextPop", (PyCFunction)Sbk_QScriptEngineAgentFunc_contextPop, METH_NOARGS},
    {"contextPush", (PyCFunction)Sbk_QScriptEngineAgentFunc_contextPush, METH_NOARGS},
    {"engine", (PyCFunction)Sbk_QScriptEngineAgentFunc_engine, METH_NOARGS},
    {"exceptionCatch", (PyCFunction)Sbk_QScriptEngineAgentFunc_exceptionCatch, METH_VARARGS},
    {"exceptionThrow", (PyCFunction)Sbk_QScriptEngineAgentFunc_exceptionThrow, METH_VARARGS},
    {"extension", (PyCFunction)Sbk_QScriptEngineAgentFunc_extension, METH_VARARGS|METH_KEYWORDS},
    {"functionEntry", (PyCFunction)Sbk_QScriptEngineAgentFunc_functionEntry, METH_O},
    {"functionExit", (PyCFunction)Sbk_QScriptEngineAgentFunc_functionExit, METH_VARARGS},
    {"positionChange", (PyCFunction)Sbk_QScriptEngineAgentFunc_positionChange, METH_VARARGS},
    {"scriptLoad", (PyCFunction)Sbk_QScriptEngineAgentFunc_scriptLoad, METH_VARARGS},
    {"scriptUnload", (PyCFunction)Sbk_QScriptEngineAgentFunc_scriptUnload, METH_O},
    {"supportsExtension", (PyCFunction)Sbk_QScriptEngineAgentFunc_supportsExtension, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QScriptEngineAgent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptEngineAgent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QScriptEngineAgent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptEngineAgent",
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
    /*tp_traverse*/         Sbk_QScriptEngineAgent_traverse,
    /*tp_clear*/            Sbk_QScriptEngineAgent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptEngineAgent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptEngineAgent_Init,
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
static void QScriptEngineAgent_Extension_PythonToCpp_QScriptEngineAgent_Extension(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngineAgent::Extension*)cppOut) = (::QScriptEngineAgent::Extension) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngineAgent_Extension_PythonToCpp_QScriptEngineAgent_Extension_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX]))
        return QScriptEngineAgent_Extension_PythonToCpp_QScriptEngineAgent_Extension;
    return 0;
}
static PyObject* QScriptEngineAgent_Extension_CppToPython_QScriptEngineAgent_Extension(const void* cppIn) {
    int castCppIn = *((::QScriptEngineAgent::Extension*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptEngineAgent_PythonToCpp_QScriptEngineAgent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptEngineAgent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptEngineAgent_PythonToCpp_QScriptEngineAgent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptEngineAgent_Type))
        return QScriptEngineAgent_PythonToCpp_QScriptEngineAgent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptEngineAgent_PTR_CppToPython_QScriptEngineAgent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptEngineAgent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptEngineAgent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QScriptEngineAgent(PyObject* module)
{
    SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptEngineAgent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptEngineAgent", "QScriptEngineAgent*",
        &Sbk_QScriptEngineAgent_Type, &Shiboken::callCppDestructor< ::QScriptEngineAgent >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptEngineAgent_Type,
        QScriptEngineAgent_PythonToCpp_QScriptEngineAgent_PTR,
        is_QScriptEngineAgent_PythonToCpp_QScriptEngineAgent_PTR_Convertible,
        QScriptEngineAgent_PTR_CppToPython_QScriptEngineAgent);

    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineAgent");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineAgent*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineAgent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngineAgent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngineAgentWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'Extension'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngineAgent_Type,
        "Extension",
        "PySide.QtScript.QScriptEngineAgent.Extension",
        "QScriptEngineAgent::Extension");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX],
        &Sbk_QScriptEngineAgent_Type, "DebuggerInvocationRequest", (long) QScriptEngineAgent::DebuggerInvocationRequest))
        return ;
    // Register converter for enum 'QScriptEngineAgent::Extension'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX],
            QScriptEngineAgent_Extension_CppToPython_QScriptEngineAgent_Extension);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngineAgent_Extension_PythonToCpp_QScriptEngineAgent_Extension,
            is_QScriptEngineAgent_Extension_PythonToCpp_QScriptEngineAgent_Extension_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_EXTENSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngineAgent::Extension");
        Shiboken::Conversions::registerConverterName(converter, "Extension");
    }
    // End of 'Extension' enum.


    qRegisterMetaType< ::QScriptEngineAgent::Extension >("QScriptEngineAgent::Extension");
}
