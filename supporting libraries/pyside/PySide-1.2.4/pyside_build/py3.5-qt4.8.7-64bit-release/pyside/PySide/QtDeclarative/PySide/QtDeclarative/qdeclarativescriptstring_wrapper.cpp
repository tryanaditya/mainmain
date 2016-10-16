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
#include "pyside_qtdeclarative_python.h"

#include "qdeclarativescriptstring_wrapper.h"

// Extra includes
#include <qdeclarativecontext.h>
#include <qdeclarativescriptstring.h>
#include <qobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeScriptString_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeScriptString >()))
        return -1;

    ::QDeclarativeScriptString* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDeclarativeScriptString", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeScriptString()
    // 1: QDeclarativeScriptString(QDeclarativeScriptString)
    if (numArgs == 0) {
        overloadId = 0; // QDeclarativeScriptString()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDeclarativeScriptString(QDeclarativeScriptString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeScriptString_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDeclarativeScriptString()
        {

            if (!PyErr_Occurred()) {
                // QDeclarativeScriptString()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeScriptString();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDeclarativeScriptString(const QDeclarativeScriptString & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDeclarativeScriptString cppArg0_local = ::QDeclarativeScriptString();
            ::QDeclarativeScriptString* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDeclarativeScriptString(QDeclarativeScriptString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDeclarativeScriptString(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeScriptString >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeScriptString_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDeclarativeScriptString_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtDeclarative.QDeclarativeScriptString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeScriptString", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativeScriptStringFunc_context(PyObject* self)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // context()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeContext * cppResult = const_cast<const ::QDeclarativeScriptString*>(cppSelf)->context();
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

static PyObject* Sbk_QDeclarativeScriptStringFunc_scopeObject(PyObject* self)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scopeObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QDeclarativeScriptString*>(cppSelf)->scopeObject();
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

static PyObject* Sbk_QDeclarativeScriptStringFunc_script(PyObject* self)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // script()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDeclarativeScriptString*>(cppSelf)->script();
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

static PyObject* Sbk_QDeclarativeScriptStringFunc_setContext(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContext(QDeclarativeContext*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVECONTEXT_IDX], (pyArg)))) {
        overloadId = 0; // setContext(QDeclarativeContext*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeScriptStringFunc_setContext_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDeclarativeContext* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContext(QDeclarativeContext*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContext(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeScriptStringFunc_setContext_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeContext", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeScriptString.setContext", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeScriptStringFunc_setScopeObject(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScopeObject(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // setScopeObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeScriptStringFunc_setScopeObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScopeObject(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScopeObject(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeScriptStringFunc_setScopeObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeScriptString.setScopeObject", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeScriptStringFunc_setScript(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeScriptString* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScript(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setScript(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeScriptStringFunc_setScript_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScript(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScript(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDeclarativeScriptStringFunc_setScript_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeScriptString.setScript", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeScriptString___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDeclarativeScriptString& cppSelf = *(((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDeclarativeScriptString_methods[] = {
    {"context", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_context, METH_NOARGS},
    {"scopeObject", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_scopeObject, METH_NOARGS},
    {"script", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_script, METH_NOARGS},
    {"setContext", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_setContext, METH_O},
    {"setScopeObject", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_setScopeObject, METH_O},
    {"setScript", (PyCFunction)Sbk_QDeclarativeScriptStringFunc_setScript, METH_O},

    {"__copy__", (PyCFunction)Sbk_QDeclarativeScriptString___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDeclarativeScriptString_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeScriptString_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeScriptString_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeScriptString",
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
    /*tp_traverse*/         Sbk_QDeclarativeScriptString_traverse,
    /*tp_clear*/            Sbk_QDeclarativeScriptString_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeScriptString_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeScriptString_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeScriptString_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeScriptString_Type))
        return QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeScriptString_PTR_CppToPython_QDeclarativeScriptString(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDeclarativeScriptString*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDeclarativeScriptString_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDeclarativeScriptString_COPY_CppToPython_QDeclarativeScriptString(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDeclarativeScriptString_Type, new ::QDeclarativeScriptString(*((::QDeclarativeScriptString*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeScriptString*)cppOut) = *((::QDeclarativeScriptString*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeScriptString_Type))
        return QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_COPY;
    return 0;
}

void init_QDeclarativeScriptString(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVESCRIPTSTRING_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeScriptString_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeScriptString", "QDeclarativeScriptString",
        &Sbk_QDeclarativeScriptString_Type, &Shiboken::callCppDestructor< ::QDeclarativeScriptString >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeScriptString_Type,
        QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_PTR,
        is_QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_PTR_Convertible,
        QDeclarativeScriptString_PTR_CppToPython_QDeclarativeScriptString,
        QDeclarativeScriptString_COPY_CppToPython_QDeclarativeScriptString);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeScriptString");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeScriptString*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeScriptString&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeScriptString).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_COPY,
        is_QDeclarativeScriptString_PythonToCpp_QDeclarativeScriptString_COPY_Convertible);


    qRegisterMetaType< ::QDeclarativeScriptString >("QDeclarativeScriptString");
}
