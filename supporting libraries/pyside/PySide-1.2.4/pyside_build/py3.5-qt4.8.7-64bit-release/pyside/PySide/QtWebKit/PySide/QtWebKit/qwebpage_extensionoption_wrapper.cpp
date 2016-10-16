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

#include "qwebpage_extensionoption_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPage_ExtensionOption_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPage::ExtensionOption >()))
        return -1;

    ::QWebPage::ExtensionOption* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ExtensionOption", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ExtensionOption()
    // 1: ExtensionOption(QWebPage::ExtensionOption)
    if (numArgs == 0) {
        overloadId = 0; // ExtensionOption()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // ExtensionOption(QWebPage::ExtensionOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPage_ExtensionOption_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ExtensionOption()
        {

            if (!PyErr_Occurred()) {
                // ExtensionOption()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ExtensionOption();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ExtensionOption(const QWebPage::ExtensionOption & ExtensionOption)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPage::ExtensionOption cppArg0_local = ::QWebPage::ExtensionOption();
            ::QWebPage::ExtensionOption* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ExtensionOption(QWebPage::ExtensionOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ExtensionOption(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPage::ExtensionOption >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPage_ExtensionOption_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPage_ExtensionOption_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPage::ExtensionOption", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.ExtensionOption", overloads);
        return -1;
}

static PyObject* Sbk_QWebPage_ExtensionOption___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPage::ExtensionOption& cppSelf = *(((::QWebPage::ExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPage_ExtensionOption_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPage_ExtensionOption___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebPage_ExtensionOption_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPage_ExtensionOption_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPage_ExtensionOption_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPage.ExtensionOption",
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
    /*tp_traverse*/         Sbk_QWebPage_ExtensionOption_traverse,
    /*tp_clear*/            Sbk_QWebPage_ExtensionOption_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPage_ExtensionOption_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPage_ExtensionOption_Init,
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
static void ExtensionOption_PythonToCpp_ExtensionOption_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPage_ExtensionOption_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ExtensionOption_PythonToCpp_ExtensionOption_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ExtensionOption_Type))
        return ExtensionOption_PythonToCpp_ExtensionOption_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ExtensionOption_PTR_CppToPython_ExtensionOption(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPage::ExtensionOption*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPage_ExtensionOption_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* ExtensionOption_COPY_CppToPython_ExtensionOption(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPage_ExtensionOption_Type, new ::QWebPage::ExtensionOption(*((::QWebPage::ExtensionOption*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void ExtensionOption_PythonToCpp_ExtensionOption_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::ExtensionOption*)cppOut) = *((::QWebPage::ExtensionOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_ExtensionOption_PythonToCpp_ExtensionOption_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ExtensionOption_Type))
        return ExtensionOption_PythonToCpp_ExtensionOption_COPY;
    return 0;
}

void init_QWebPage_ExtensionOption(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPage_ExtensionOption_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ExtensionOption", "QWebPage::ExtensionOption",
        &Sbk_QWebPage_ExtensionOption_Type, &Shiboken::callCppDestructor< ::QWebPage::ExtensionOption >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPage_ExtensionOption_Type,
        ExtensionOption_PythonToCpp_ExtensionOption_PTR,
        is_ExtensionOption_PythonToCpp_ExtensionOption_PTR_Convertible,
        ExtensionOption_PTR_CppToPython_ExtensionOption,
        ExtensionOption_COPY_CppToPython_ExtensionOption);

    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ExtensionOption");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ExtensionOption*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ExtensionOption&");
    Shiboken::Conversions::registerConverterName(converter, "ExtensionOption");
    Shiboken::Conversions::registerConverterName(converter, "ExtensionOption*");
    Shiboken::Conversions::registerConverterName(converter, "ExtensionOption&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPage::ExtensionOption).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        ExtensionOption_PythonToCpp_ExtensionOption_COPY,
        is_ExtensionOption_PythonToCpp_ExtensionOption_COPY_Convertible);


    qRegisterMetaType< ::QWebPage::ExtensionOption >("ExtensionOption");
    qRegisterMetaType< ::QWebPage::ExtensionOption >("QWebPage::ExtensionOption");
}