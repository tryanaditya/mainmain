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
#include "pyside_qtxml_python.h"

#include "qxmlerrorhandler_wrapper.h"

// Extra includes
#include <qxml.h>


// Native ---------------------------------------------------------

QXmlErrorHandlerWrapper::QXmlErrorHandlerWrapper() : QXmlErrorHandler() {
    // ... middle
}

bool QXmlErrorHandlerWrapper::error(const QXmlParseException & exception)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "error"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.error()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], &exception)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlErrorHandler.error", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QXmlErrorHandlerWrapper::errorString() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "errorString"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.errorString()' not implemented.");
        return ::QString();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlErrorHandler.errorString", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlErrorHandlerWrapper::fatalError(const QXmlParseException & exception)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fatalError"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.fatalError()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], &exception)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlErrorHandler.fatalError", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlErrorHandlerWrapper::warning(const QXmlParseException & exception)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "warning"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.warning()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], &exception)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlErrorHandler.warning", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlErrorHandlerWrapper::~QXmlErrorHandlerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlErrorHandler_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QXmlErrorHandler' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlErrorHandler >()))
        return -1;

    ::QXmlErrorHandlerWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QXmlErrorHandler()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QXmlErrorHandlerWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlErrorHandler >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QXmlErrorHandlerFunc_error(PyObject* self, PyObject* pyArg)
{
    ::QXmlErrorHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlErrorHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: error(QXmlParseException)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (pyArg)))) {
        overloadId = 0; // error(QXmlParseException)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlErrorHandlerFunc_error_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlParseException* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // error(QXmlParseException)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.error()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->error(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlErrorHandlerFunc_error_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlParseException", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlErrorHandler.error", overloads);
        return 0;
}

static PyObject* Sbk_QXmlErrorHandlerFunc_errorString(PyObject* self)
{
    ::QXmlErrorHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlErrorHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.errorString()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlErrorHandler*>(cppSelf)->errorString();
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

static PyObject* Sbk_QXmlErrorHandlerFunc_fatalError(PyObject* self, PyObject* pyArg)
{
    ::QXmlErrorHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlErrorHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fatalError(QXmlParseException)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (pyArg)))) {
        overloadId = 0; // fatalError(QXmlParseException)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlErrorHandlerFunc_fatalError_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlParseException* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fatalError(QXmlParseException)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.fatalError()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->fatalError(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlErrorHandlerFunc_fatalError_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlParseException", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlErrorHandler.fatalError", overloads);
        return 0;
}

static PyObject* Sbk_QXmlErrorHandlerFunc_warning(PyObject* self, PyObject* pyArg)
{
    ::QXmlErrorHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlErrorHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: warning(QXmlParseException)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (pyArg)))) {
        overloadId = 0; // warning(QXmlParseException)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlErrorHandlerFunc_warning_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlParseException* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // warning(QXmlParseException)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlErrorHandler.warning()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->warning(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlErrorHandlerFunc_warning_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlParseException", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlErrorHandler.warning", overloads);
        return 0;
}

static PyMethodDef Sbk_QXmlErrorHandler_methods[] = {
    {"error", (PyCFunction)Sbk_QXmlErrorHandlerFunc_error, METH_O},
    {"errorString", (PyCFunction)Sbk_QXmlErrorHandlerFunc_errorString, METH_NOARGS},
    {"fatalError", (PyCFunction)Sbk_QXmlErrorHandlerFunc_fatalError, METH_O},
    {"warning", (PyCFunction)Sbk_QXmlErrorHandlerFunc_warning, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlErrorHandler_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlErrorHandler_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlErrorHandler_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlErrorHandler",
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
    /*tp_traverse*/         Sbk_QXmlErrorHandler_traverse,
    /*tp_clear*/            Sbk_QXmlErrorHandler_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlErrorHandler_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlErrorHandler_Init,
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
static void QXmlErrorHandler_PythonToCpp_QXmlErrorHandler_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlErrorHandler_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlErrorHandler_PythonToCpp_QXmlErrorHandler_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlErrorHandler_Type))
        return QXmlErrorHandler_PythonToCpp_QXmlErrorHandler_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlErrorHandler_PTR_CppToPython_QXmlErrorHandler(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlErrorHandler*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlErrorHandler_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlErrorHandler(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlErrorHandler_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlErrorHandler", "QXmlErrorHandler*",
        &Sbk_QXmlErrorHandler_Type, &Shiboken::callCppDestructor< ::QXmlErrorHandler >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlErrorHandler_Type,
        QXmlErrorHandler_PythonToCpp_QXmlErrorHandler_PTR,
        is_QXmlErrorHandler_PythonToCpp_QXmlErrorHandler_PTR_Convertible,
        QXmlErrorHandler_PTR_CppToPython_QXmlErrorHandler);

    Shiboken::Conversions::registerConverterName(converter, "QXmlErrorHandler");
    Shiboken::Conversions::registerConverterName(converter, "QXmlErrorHandler*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlErrorHandler&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlErrorHandler).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlErrorHandlerWrapper).name());



}
