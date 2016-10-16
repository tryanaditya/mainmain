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
#include "pyside_qtwebkit_python.h"

#include "qwebpage_errorpageextensionreturn_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPage_ErrorPageExtensionReturn_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPage::ErrorPageExtensionReturn >()))
        return -1;

    ::QWebPage::ErrorPageExtensionReturn* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ErrorPageExtensionReturn", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ErrorPageExtensionReturn()
    // 1: ErrorPageExtensionReturn(QWebPage::ErrorPageExtensionReturn)
    if (numArgs == 0) {
        overloadId = 0; // ErrorPageExtensionReturn()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (pyArgs[0])))) {
        overloadId = 1; // ErrorPageExtensionReturn(QWebPage::ErrorPageExtensionReturn)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPage_ErrorPageExtensionReturn_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ErrorPageExtensionReturn()
        {

            if (!PyErr_Occurred()) {
                // ErrorPageExtensionReturn()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ErrorPageExtensionReturn();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ErrorPageExtensionReturn(const QWebPage::ErrorPageExtensionReturn & ErrorPageExtensionReturn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPage::ErrorPageExtensionReturn cppArg0_local = ::QWebPage::ErrorPageExtensionReturn();
            ::QWebPage::ErrorPageExtensionReturn* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ErrorPageExtensionReturn(QWebPage::ErrorPageExtensionReturn)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ErrorPageExtensionReturn(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPage::ErrorPageExtensionReturn >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPage_ErrorPageExtensionReturn_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPage_ErrorPageExtensionReturn_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPage::ErrorPageExtensionReturn", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.ErrorPageExtensionReturn", overloads);
        return -1;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionReturn___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPage::ErrorPageExtensionReturn& cppSelf = *(((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPage_ErrorPageExtensionReturn_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPage_ErrorPageExtensionReturn___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QWebPage_ErrorPageExtensionReturn_get_baseUrl(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &(cppSelf->baseUrl), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionReturn_set_baseUrl(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'baseUrl' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'baseUrl', 'QUrl' or convertible type expected");
        return -1;
    }

    ::QUrl& cppOut_ptr = cppSelf->baseUrl;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionReturn_get_contentType(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->contentType);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionReturn_set_contentType(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'contentType' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'contentType', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->contentType;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionReturn_get_encoding(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->encoding);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionReturn_set_encoding(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'encoding' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'encoding', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->encoding;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionReturn_get_content(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &(cppSelf->content), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionReturn_set_content(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'content' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'content', 'QByteArray' or convertible type expected");
        return -1;
    }

    ::QByteArray& cppOut_ptr = cppSelf->content;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for ErrorPageExtensionReturn
static PyGetSetDef Sbk_QWebPage_ErrorPageExtensionReturn_getsetlist[] = {
    {const_cast<char*>("baseUrl"), Sbk_QWebPage_ErrorPageExtensionReturn_get_baseUrl, Sbk_QWebPage_ErrorPageExtensionReturn_set_baseUrl},
    {const_cast<char*>("contentType"), Sbk_QWebPage_ErrorPageExtensionReturn_get_contentType, Sbk_QWebPage_ErrorPageExtensionReturn_set_contentType},
    {const_cast<char*>("encoding"), Sbk_QWebPage_ErrorPageExtensionReturn_get_encoding, Sbk_QWebPage_ErrorPageExtensionReturn_set_encoding},
    {const_cast<char*>("content"), Sbk_QWebPage_ErrorPageExtensionReturn_get_content, Sbk_QWebPage_ErrorPageExtensionReturn_set_content},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QWebPage_ErrorPageExtensionReturn_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPage_ErrorPageExtensionReturn_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPage_ErrorPageExtensionReturn_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPage.ErrorPageExtensionReturn",
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
    /*tp_traverse*/         Sbk_QWebPage_ErrorPageExtensionReturn_traverse,
    /*tp_clear*/            Sbk_QWebPage_ErrorPageExtensionReturn_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPage_ErrorPageExtensionReturn_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QWebPage_ErrorPageExtensionReturn_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPage_ErrorPageExtensionReturn_Init,
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
static void ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPage_ErrorPageExtensionReturn_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ErrorPageExtensionReturn_Type))
        return ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ErrorPageExtensionReturn_PTR_CppToPython_ErrorPageExtensionReturn(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPage::ErrorPageExtensionReturn*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPage_ErrorPageExtensionReturn_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* ErrorPageExtensionReturn_COPY_CppToPython_ErrorPageExtensionReturn(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPage_ErrorPageExtensionReturn_Type, new ::QWebPage::ErrorPageExtensionReturn(*((::QWebPage::ErrorPageExtensionReturn*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::ErrorPageExtensionReturn*)cppOut) = *((::QWebPage::ErrorPageExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ErrorPageExtensionReturn_Type))
        return ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_COPY;
    return 0;
}

void init_QWebPage_ErrorPageExtensionReturn(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPage_ErrorPageExtensionReturn_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ErrorPageExtensionReturn", "QWebPage::ErrorPageExtensionReturn",
        &Sbk_QWebPage_ErrorPageExtensionReturn_Type, &Shiboken::callCppDestructor< ::QWebPage::ErrorPageExtensionReturn >, (SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONRETURN_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPage_ErrorPageExtensionReturn_Type,
        ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_PTR,
        is_ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_PTR_Convertible,
        ErrorPageExtensionReturn_PTR_CppToPython_ErrorPageExtensionReturn,
        ErrorPageExtensionReturn_COPY_CppToPython_ErrorPageExtensionReturn);

    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionReturn");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionReturn*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionReturn&");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionReturn");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionReturn*");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionReturn&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPage::ErrorPageExtensionReturn).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_COPY,
        is_ErrorPageExtensionReturn_PythonToCpp_ErrorPageExtensionReturn_COPY_Convertible);


    qRegisterMetaType< ::QWebPage::ErrorPageExtensionReturn >("ErrorPageExtensionReturn");
    qRegisterMetaType< ::QWebPage::ErrorPageExtensionReturn >("QWebPage::ErrorPageExtensionReturn");
}
