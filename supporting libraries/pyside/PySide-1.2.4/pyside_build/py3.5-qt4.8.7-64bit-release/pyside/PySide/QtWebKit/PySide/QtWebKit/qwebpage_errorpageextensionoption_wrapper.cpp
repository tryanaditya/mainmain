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

#include "qwebpage_errorpageextensionoption_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPage_ErrorPageExtensionOption_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPage::ErrorPageExtensionOption >()))
        return -1;

    ::QWebPage::ErrorPageExtensionOption* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ErrorPageExtensionOption", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ErrorPageExtensionOption()
    // 1: ErrorPageExtensionOption(QWebPage::ErrorPageExtensionOption)
    if (numArgs == 0) {
        overloadId = 0; // ErrorPageExtensionOption()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // ErrorPageExtensionOption(QWebPage::ErrorPageExtensionOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPage_ErrorPageExtensionOption_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ErrorPageExtensionOption()
        {

            if (!PyErr_Occurred()) {
                // ErrorPageExtensionOption()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ErrorPageExtensionOption();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ErrorPageExtensionOption(const QWebPage::ErrorPageExtensionOption & ErrorPageExtensionOption)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPage::ErrorPageExtensionOption cppArg0_local = ::QWebPage::ErrorPageExtensionOption();
            ::QWebPage::ErrorPageExtensionOption* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ErrorPageExtensionOption(QWebPage::ErrorPageExtensionOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ErrorPageExtensionOption(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPage::ErrorPageExtensionOption >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPage_ErrorPageExtensionOption_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPage_ErrorPageExtensionOption_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPage::ErrorPageExtensionOption", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.ErrorPageExtensionOption", overloads);
        return -1;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPage::ErrorPageExtensionOption& cppSelf = *(((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPage_ErrorPageExtensionOption_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPage_ErrorPageExtensionOption___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption_get_error(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->error;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionOption_set_error(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'error' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'error', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->error;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->error = cppOut_local;

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption_get_domain(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    ::QWebPage::ErrorDomain cppOut_local = cppSelf->domain;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionOption_set_domain(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'domain' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'domain', 'ErrorDomain' or convertible type expected");
        return -1;
    }

    ::QWebPage::ErrorDomain cppOut_local = cppSelf->domain;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->domain = cppOut_local;

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption_get_errorString(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->errorString);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionOption_set_errorString(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'errorString' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'errorString', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->errorString;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption_get_url(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &(cppSelf->url), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionOption_set_url(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'url' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'url', 'QUrl' or convertible type expected");
        return -1;
    }

    ::QUrl& cppOut_ptr = cppSelf->url;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPage_ErrorPageExtensionOption_get_frame(PyObject* self, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppSelf->frame);
    return pyOut;
}
static int Sbk_QWebPage_ErrorPageExtensionOption_set_frame(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ErrorPageExtensionOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'frame' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'frame', 'QWebFrame' or convertible type expected");
        return -1;
    }

    ::QWebFrame*& cppOut_ptr = cppSelf->frame;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "frame", pyIn);
    return 0;
}

// Getters and Setters for ErrorPageExtensionOption
static PyGetSetDef Sbk_QWebPage_ErrorPageExtensionOption_getsetlist[] = {
    {const_cast<char*>("error"), Sbk_QWebPage_ErrorPageExtensionOption_get_error, Sbk_QWebPage_ErrorPageExtensionOption_set_error},
    {const_cast<char*>("domain"), Sbk_QWebPage_ErrorPageExtensionOption_get_domain, Sbk_QWebPage_ErrorPageExtensionOption_set_domain},
    {const_cast<char*>("errorString"), Sbk_QWebPage_ErrorPageExtensionOption_get_errorString, Sbk_QWebPage_ErrorPageExtensionOption_set_errorString},
    {const_cast<char*>("url"), Sbk_QWebPage_ErrorPageExtensionOption_get_url, Sbk_QWebPage_ErrorPageExtensionOption_set_url},
    {const_cast<char*>("frame"), Sbk_QWebPage_ErrorPageExtensionOption_get_frame, Sbk_QWebPage_ErrorPageExtensionOption_set_frame},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QWebPage_ErrorPageExtensionOption_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPage_ErrorPageExtensionOption_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPage_ErrorPageExtensionOption_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPage.ErrorPageExtensionOption",
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
    /*tp_traverse*/         Sbk_QWebPage_ErrorPageExtensionOption_traverse,
    /*tp_clear*/            Sbk_QWebPage_ErrorPageExtensionOption_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPage_ErrorPageExtensionOption_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QWebPage_ErrorPageExtensionOption_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPage_ErrorPageExtensionOption_Init,
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
static void ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPage_ErrorPageExtensionOption_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ErrorPageExtensionOption_Type))
        return ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ErrorPageExtensionOption_PTR_CppToPython_ErrorPageExtensionOption(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPage::ErrorPageExtensionOption*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPage_ErrorPageExtensionOption_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* ErrorPageExtensionOption_COPY_CppToPython_ErrorPageExtensionOption(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPage_ErrorPageExtensionOption_Type, new ::QWebPage::ErrorPageExtensionOption(*((::QWebPage::ErrorPageExtensionOption*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::ErrorPageExtensionOption*)cppOut) = *((::QWebPage::ErrorPageExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ErrorPageExtensionOption_Type))
        return ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_COPY;
    return 0;
}

void init_QWebPage_ErrorPageExtensionOption(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPage_ErrorPageExtensionOption_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ErrorPageExtensionOption", "QWebPage::ErrorPageExtensionOption",
        &Sbk_QWebPage_ErrorPageExtensionOption_Type, &Shiboken::callCppDestructor< ::QWebPage::ErrorPageExtensionOption >, (SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPage_ErrorPageExtensionOption_Type,
        ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_PTR,
        is_ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_PTR_Convertible,
        ErrorPageExtensionOption_PTR_CppToPython_ErrorPageExtensionOption,
        ErrorPageExtensionOption_COPY_CppToPython_ErrorPageExtensionOption);

    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionOption");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionOption*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorPageExtensionOption&");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionOption");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionOption*");
    Shiboken::Conversions::registerConverterName(converter, "ErrorPageExtensionOption&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPage::ErrorPageExtensionOption).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_COPY,
        is_ErrorPageExtensionOption_PythonToCpp_ErrorPageExtensionOption_COPY_Convertible);


    qRegisterMetaType< ::QWebPage::ErrorPageExtensionOption >("ErrorPageExtensionOption");
    qRegisterMetaType< ::QWebPage::ErrorPageExtensionOption >("QWebPage::ErrorPageExtensionOption");
}
