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
#include "pyside_qtcore_python.h"

#include "qlibraryinfo_wrapper.h"

// Extra includes
#include <qdatetime.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QLibraryInfoFunc_buildDate(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buildDate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = ::QLibraryInfo::buildDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLibraryInfoFunc_buildKey(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buildKey()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLibraryInfo::buildKey();
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

static PyObject* Sbk_QLibraryInfoFunc_licensedProducts(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // licensedProducts()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLibraryInfo::licensedProducts();
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

static PyObject* Sbk_QLibraryInfoFunc_licensee(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // licensee()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLibraryInfo::licensee();
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

static PyObject* Sbk_QLibraryInfoFunc_location(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: location(QLibraryInfo::LibraryLocation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX]), (pyArg)))) {
        overloadId = 0; // location(QLibraryInfo::LibraryLocation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLibraryInfoFunc_location_TypeError;

    // Call function/method
    {
        ::QLibraryInfo::LibraryLocation cppArg0 = ((::QLibraryInfo::LibraryLocation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // location(QLibraryInfo::LibraryLocation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLibraryInfo::location(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLibraryInfoFunc_location_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLibraryInfo.LibraryLocation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLibraryInfo.location", overloads);
        return 0;
}

static PyMethodDef Sbk_QLibraryInfo_methods[] = {
    {"buildDate", (PyCFunction)Sbk_QLibraryInfoFunc_buildDate, METH_NOARGS|METH_STATIC},
    {"buildKey", (PyCFunction)Sbk_QLibraryInfoFunc_buildKey, METH_NOARGS|METH_STATIC},
    {"licensedProducts", (PyCFunction)Sbk_QLibraryInfoFunc_licensedProducts, METH_NOARGS|METH_STATIC},
    {"licensee", (PyCFunction)Sbk_QLibraryInfoFunc_licensee, METH_NOARGS|METH_STATIC},
    {"location", (PyCFunction)Sbk_QLibraryInfoFunc_location, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QLibraryInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QLibraryInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QLibraryInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QLibraryInfo",
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
    /*tp_traverse*/         Sbk_QLibraryInfo_traverse,
    /*tp_clear*/            Sbk_QLibraryInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QLibraryInfo_methods,
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
static void QLibraryInfo_LibraryLocation_PythonToCpp_QLibraryInfo_LibraryLocation(PyObject* pyIn, void* cppOut) {
    *((::QLibraryInfo::LibraryLocation*)cppOut) = (::QLibraryInfo::LibraryLocation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLibraryInfo_LibraryLocation_PythonToCpp_QLibraryInfo_LibraryLocation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX]))
        return QLibraryInfo_LibraryLocation_PythonToCpp_QLibraryInfo_LibraryLocation;
    return 0;
}
static PyObject* QLibraryInfo_LibraryLocation_CppToPython_QLibraryInfo_LibraryLocation(const void* cppIn) {
    int castCppIn = *((::QLibraryInfo::LibraryLocation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QLibraryInfo_PythonToCpp_QLibraryInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QLibraryInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QLibraryInfo_PythonToCpp_QLibraryInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLibraryInfo_Type))
        return QLibraryInfo_PythonToCpp_QLibraryInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QLibraryInfo_PTR_CppToPython_QLibraryInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QLibraryInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QLibraryInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QLibraryInfo(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QLibraryInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QLibraryInfo", "QLibraryInfo*",
        &Sbk_QLibraryInfo_Type, &Shiboken::callCppDestructor< ::QLibraryInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QLibraryInfo_Type,
        QLibraryInfo_PythonToCpp_QLibraryInfo_PTR,
        is_QLibraryInfo_PythonToCpp_QLibraryInfo_PTR_Convertible,
        QLibraryInfo_PTR_CppToPython_QLibraryInfo);

    Shiboken::Conversions::registerConverterName(converter, "QLibraryInfo");
    Shiboken::Conversions::registerConverterName(converter, "QLibraryInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QLibraryInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLibraryInfo).name());


    // Initialization of enums.

    // Initialization of enum 'LibraryLocation'.
    SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLibraryInfo_Type,
        "LibraryLocation",
        "PySide.QtCore.QLibraryInfo.LibraryLocation",
        "QLibraryInfo::LibraryLocation");
    if (!SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "PrefixPath", (long) QLibraryInfo::PrefixPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "DocumentationPath", (long) QLibraryInfo::DocumentationPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "HeadersPath", (long) QLibraryInfo::HeadersPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "LibrariesPath", (long) QLibraryInfo::LibrariesPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "BinariesPath", (long) QLibraryInfo::BinariesPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "PluginsPath", (long) QLibraryInfo::PluginsPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "DataPath", (long) QLibraryInfo::DataPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "TranslationsPath", (long) QLibraryInfo::TranslationsPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "SettingsPath", (long) QLibraryInfo::SettingsPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "DemosPath", (long) QLibraryInfo::DemosPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "ExamplesPath", (long) QLibraryInfo::ExamplesPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
        &Sbk_QLibraryInfo_Type, "ImportsPath", (long) QLibraryInfo::ImportsPath))
        return ;
    // Register converter for enum 'QLibraryInfo::LibraryLocation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX],
            QLibraryInfo_LibraryLocation_CppToPython_QLibraryInfo_LibraryLocation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLibraryInfo_LibraryLocation_PythonToCpp_QLibraryInfo_LibraryLocation,
            is_QLibraryInfo_LibraryLocation_PythonToCpp_QLibraryInfo_LibraryLocation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLIBRARYINFO_LIBRARYLOCATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLibraryInfo::LibraryLocation");
        Shiboken::Conversions::registerConverterName(converter, "LibraryLocation");
    }
    // End of 'LibraryLocation' enum.


    qRegisterMetaType< ::QLibraryInfo::LibraryLocation >("QLibraryInfo::LibraryLocation");
}
