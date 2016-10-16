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

#include "qwebpage_choosemultiplefilesextensionreturn_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPage::ChooseMultipleFilesExtensionReturn >()))
        return -1;

    ::QWebPage::ChooseMultipleFilesExtensionReturn* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ChooseMultipleFilesExtensionReturn", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ChooseMultipleFilesExtensionReturn()
    // 1: ChooseMultipleFilesExtensionReturn(QWebPage::ChooseMultipleFilesExtensionReturn)
    if (numArgs == 0) {
        overloadId = 0; // ChooseMultipleFilesExtensionReturn()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], (pyArgs[0])))) {
        overloadId = 1; // ChooseMultipleFilesExtensionReturn(QWebPage::ChooseMultipleFilesExtensionReturn)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ChooseMultipleFilesExtensionReturn()
        {

            if (!PyErr_Occurred()) {
                // ChooseMultipleFilesExtensionReturn()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ChooseMultipleFilesExtensionReturn();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ChooseMultipleFilesExtensionReturn(const QWebPage::ChooseMultipleFilesExtensionReturn & ChooseMultipleFilesExtensionReturn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPage::ChooseMultipleFilesExtensionReturn cppArg0_local = ::QWebPage::ChooseMultipleFilesExtensionReturn();
            ::QWebPage::ChooseMultipleFilesExtensionReturn* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ChooseMultipleFilesExtensionReturn(QWebPage::ChooseMultipleFilesExtensionReturn)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPage::ChooseMultipleFilesExtensionReturn(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPage::ChooseMultipleFilesExtensionReturn >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPage::ChooseMultipleFilesExtensionReturn", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.ChooseMultipleFilesExtensionReturn", overloads);
        return -1;
}

static PyObject* Sbk_QWebPage_ChooseMultipleFilesExtensionReturn___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPage::ChooseMultipleFilesExtensionReturn& cppSelf = *(((::QWebPage::ChooseMultipleFilesExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPage_ChooseMultipleFilesExtensionReturn___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_get_fileNames(PyObject* self, void*)
{
    ::QWebPage::ChooseMultipleFilesExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ChooseMultipleFilesExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppSelf->fileNames);
    return pyOut;
}
static int Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_set_fileNames(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPage::ChooseMultipleFilesExtensionReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage::ChooseMultipleFilesExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fileNames' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fileNames', 'QStringList' or convertible type expected");
        return -1;
    }

    ::QStringList& cppOut_ptr = cppSelf->fileNames;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for ChooseMultipleFilesExtensionReturn
static PyGetSetDef Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_getsetlist[] = {
    {const_cast<char*>("fileNames"), Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_get_fileNames, Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_set_fileNames},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPage.ChooseMultipleFilesExtensionReturn",
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
    /*tp_traverse*/         Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_traverse,
    /*tp_clear*/            Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Init,
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
static void ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type))
        return ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ChooseMultipleFilesExtensionReturn_PTR_CppToPython_ChooseMultipleFilesExtensionReturn(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPage::ChooseMultipleFilesExtensionReturn*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* ChooseMultipleFilesExtensionReturn_COPY_CppToPython_ChooseMultipleFilesExtensionReturn(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type, new ::QWebPage::ChooseMultipleFilesExtensionReturn(*((::QWebPage::ChooseMultipleFilesExtensionReturn*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::ChooseMultipleFilesExtensionReturn*)cppOut) = *((::QWebPage::ChooseMultipleFilesExtensionReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type))
        return ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_COPY;
    return 0;
}

void init_QWebPage_ChooseMultipleFilesExtensionReturn(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ChooseMultipleFilesExtensionReturn", "QWebPage::ChooseMultipleFilesExtensionReturn",
        &Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type, &Shiboken::callCppDestructor< ::QWebPage::ChooseMultipleFilesExtensionReturn >, (SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONRETURN_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPage_ChooseMultipleFilesExtensionReturn_Type,
        ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_PTR,
        is_ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_PTR_Convertible,
        ChooseMultipleFilesExtensionReturn_PTR_CppToPython_ChooseMultipleFilesExtensionReturn,
        ChooseMultipleFilesExtensionReturn_COPY_CppToPython_ChooseMultipleFilesExtensionReturn);

    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ChooseMultipleFilesExtensionReturn");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ChooseMultipleFilesExtensionReturn*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage::ChooseMultipleFilesExtensionReturn&");
    Shiboken::Conversions::registerConverterName(converter, "ChooseMultipleFilesExtensionReturn");
    Shiboken::Conversions::registerConverterName(converter, "ChooseMultipleFilesExtensionReturn*");
    Shiboken::Conversions::registerConverterName(converter, "ChooseMultipleFilesExtensionReturn&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPage::ChooseMultipleFilesExtensionReturn).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_COPY,
        is_ChooseMultipleFilesExtensionReturn_PythonToCpp_ChooseMultipleFilesExtensionReturn_COPY_Convertible);


    qRegisterMetaType< ::QWebPage::ChooseMultipleFilesExtensionReturn >("ChooseMultipleFilesExtensionReturn");
    qRegisterMetaType< ::QWebPage::ChooseMultipleFilesExtensionReturn >("QWebPage::ChooseMultipleFilesExtensionReturn");
}
