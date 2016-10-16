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

#include "qsysinfo_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSysInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSysInfo >()))
        return -1;

    ::QSysInfo* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QSysInfo()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSysInfo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSysInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_QSysInfo_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSysInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSysInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSysInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSysInfo",
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
    /*tp_traverse*/         Sbk_QSysInfo_traverse,
    /*tp_clear*/            Sbk_QSysInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSysInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSysInfo_Init,
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
static void QSysInfo_Sizes_PythonToCpp_QSysInfo_Sizes(PyObject* pyIn, void* cppOut) {
    *((::QSysInfo::Sizes*)cppOut) = (::QSysInfo::Sizes) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSysInfo_Sizes_PythonToCpp_QSysInfo_Sizes_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX]))
        return QSysInfo_Sizes_PythonToCpp_QSysInfo_Sizes;
    return 0;
}
static PyObject* QSysInfo_Sizes_CppToPython_QSysInfo_Sizes(const void* cppIn) {
    int castCppIn = *((::QSysInfo::Sizes*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX], castCppIn);

}

static void QSysInfo_Endian_PythonToCpp_QSysInfo_Endian(PyObject* pyIn, void* cppOut) {
    *((::QSysInfo::Endian*)cppOut) = (::QSysInfo::Endian) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSysInfo_Endian_PythonToCpp_QSysInfo_Endian_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX]))
        return QSysInfo_Endian_PythonToCpp_QSysInfo_Endian;
    return 0;
}
static PyObject* QSysInfo_Endian_CppToPython_QSysInfo_Endian(const void* cppIn) {
    int castCppIn = *((::QSysInfo::Endian*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSysInfo_PythonToCpp_QSysInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSysInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSysInfo_PythonToCpp_QSysInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSysInfo_Type))
        return QSysInfo_PythonToCpp_QSysInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSysInfo_PTR_CppToPython_QSysInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSysInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSysInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSysInfo(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSYSINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSysInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSysInfo", "QSysInfo*",
        &Sbk_QSysInfo_Type, &Shiboken::callCppDestructor< ::QSysInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSysInfo_Type,
        QSysInfo_PythonToCpp_QSysInfo_PTR,
        is_QSysInfo_PythonToCpp_QSysInfo_PTR_Convertible,
        QSysInfo_PTR_CppToPython_QSysInfo);

    Shiboken::Conversions::registerConverterName(converter, "QSysInfo");
    Shiboken::Conversions::registerConverterName(converter, "QSysInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QSysInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSysInfo).name());


    // Initialization of enums.

    // Initialization of enum 'Sizes'.
    SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSysInfo_Type,
        "Sizes",
        "PySide.QtCore.QSysInfo.Sizes",
        "QSysInfo::Sizes");
    if (!SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX],
        &Sbk_QSysInfo_Type, "WordSize", (long) QSysInfo::WordSize))
        return ;
    // Register converter for enum 'QSysInfo::Sizes'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX],
            QSysInfo_Sizes_CppToPython_QSysInfo_Sizes);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSysInfo_Sizes_PythonToCpp_QSysInfo_Sizes,
            is_QSysInfo_Sizes_PythonToCpp_QSysInfo_Sizes_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_SIZES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSysInfo::Sizes");
        Shiboken::Conversions::registerConverterName(converter, "Sizes");
    }
    // End of 'Sizes' enum.

    // Initialization of enum 'Endian'.
    SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSysInfo_Type,
        "Endian",
        "PySide.QtCore.QSysInfo.Endian",
        "QSysInfo::Endian");
    if (!SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX],
        &Sbk_QSysInfo_Type, "BigEndian", (long) QSysInfo::BigEndian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX],
        &Sbk_QSysInfo_Type, "LittleEndian", (long) QSysInfo::LittleEndian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX],
        &Sbk_QSysInfo_Type, "ByteOrder", (long) QSysInfo::ByteOrder))
        return ;
    // Register converter for enum 'QSysInfo::Endian'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX],
            QSysInfo_Endian_CppToPython_QSysInfo_Endian);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSysInfo_Endian_PythonToCpp_QSysInfo_Endian,
            is_QSysInfo_Endian_PythonToCpp_QSysInfo_Endian_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSINFO_ENDIAN_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSysInfo::Endian");
        Shiboken::Conversions::registerConverterName(converter, "Endian");
    }
    // End of 'Endian' enum.


    qRegisterMetaType< ::QSysInfo::Sizes >("QSysInfo::Sizes");
    qRegisterMetaType< ::QSysInfo::Endian >("QSysInfo::Endian");
}
