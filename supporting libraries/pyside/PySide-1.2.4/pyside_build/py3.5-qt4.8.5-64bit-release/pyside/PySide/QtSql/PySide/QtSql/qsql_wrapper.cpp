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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include "pyside_qtsql_python.h"

#include "qsql_wrapper.h"

// Extra includes
#include <QtSql/qsql.h>



// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_QSql_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSql_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSql_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSql_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSql",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_traverse*/         Sbk_QSql_traverse,
    /*tp_clear*/            Sbk_QSql_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSql_methods,
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

PyObject* SbkPySide_QtSql_QSql_ParamTypeFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QSql::ParamType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSql::ParamType)PyLong_AsLong(self);
    cppArg = (QSql::ParamType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSql::ParamType)PyInt_AsLong(self);
    cppArg = (QSql::ParamType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtSql_QSql_ParamTypeFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QSql::ParamType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSql::ParamType)PyLong_AsLong(self);
    cppArg = (QSql::ParamType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSql::ParamType)PyInt_AsLong(self);
    cppArg = (QSql::ParamType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtSql_QSql_ParamTypeFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QSql::ParamType cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QSql::ParamType)PyLong_AsLong(self);
    cppArg = (QSql::ParamType)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QSql::ParamType)PyInt_AsLong(self);
    cppArg = (QSql::ParamType)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtSql_QSql_ParamTypeFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QSql::ParamType cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), self, &cppSelf);
    ::QSql::ParamType cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtSql_QSql_ParamTypeFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtSql_QSql_ParamTypeFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtSql_QSql_ParamTypeFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtSql_QSql_ParamTypeFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtSql_QSql_ParamTypeFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtSql_QSql_ParamTypeFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtSql_QSql_ParamTypeFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtSql_QSql_ParamTypeFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtSql_QSql_ParamTypeFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtSql_QSql_ParamTypeFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QSql_Location_PythonToCpp_QSql_Location(PyObject* pyIn, void* cppOut) {
    *((::QSql::Location*)cppOut) = (::QSql::Location) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSql_Location_PythonToCpp_QSql_Location_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX]))
        return QSql_Location_PythonToCpp_QSql_Location;
    return 0;
}
static PyObject* QSql_Location_CppToPython_QSql_Location(const void* cppIn) {
    int castCppIn = *((::QSql::Location*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX], castCppIn);

}

static void QSql_ParamTypeFlag_PythonToCpp_QSql_ParamTypeFlag(PyObject* pyIn, void* cppOut) {
    *((::QSql::ParamTypeFlag*)cppOut) = (::QSql::ParamTypeFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSql_ParamTypeFlag_PythonToCpp_QSql_ParamTypeFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX]))
        return QSql_ParamTypeFlag_PythonToCpp_QSql_ParamTypeFlag;
    return 0;
}
static PyObject* QSql_ParamTypeFlag_CppToPython_QSql_ParamTypeFlag(const void* cppIn) {
    int castCppIn = *((::QSql::ParamTypeFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX], castCppIn);

}

static void QFlags_QSql_ParamTypeFlag__PythonToCpp_QFlags_QSql_ParamTypeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QSql::ParamTypeFlag>*)cppOut) = ::QFlags<QSql::ParamTypeFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QSql_ParamTypeFlag__PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]))
        return QFlags_QSql_ParamTypeFlag__PythonToCpp_QFlags_QSql_ParamTypeFlag_;
    return 0;
}
static PyObject* QFlags_QSql_ParamTypeFlag__CppToPython_QFlags_QSql_ParamTypeFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QSql::ParamTypeFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]));

}

static void QSql_ParamTypeFlag_PythonToCpp_QFlags_QSql_ParamTypeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QSql::ParamTypeFlag>*)cppOut) = ::QFlags<QSql::ParamTypeFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QSql_ParamTypeFlag_PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX]))
        return QSql_ParamTypeFlag_PythonToCpp_QFlags_QSql_ParamTypeFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QSql_ParamTypeFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QSql::ParamTypeFlag>*)cppOut) = ::QFlags<QSql::ParamTypeFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QSql_ParamTypeFlag_;
    return 0;
}
static void QSql_TableType_PythonToCpp_QSql_TableType(PyObject* pyIn, void* cppOut) {
    *((::QSql::TableType*)cppOut) = (::QSql::TableType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSql_TableType_PythonToCpp_QSql_TableType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX]))
        return QSql_TableType_PythonToCpp_QSql_TableType;
    return 0;
}
static PyObject* QSql_TableType_CppToPython_QSql_TableType(const void* cppIn) {
    int castCppIn = *((::QSql::TableType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX], castCppIn);

}

static void QSql_NumericalPrecisionPolicy_PythonToCpp_QSql_NumericalPrecisionPolicy(PyObject* pyIn, void* cppOut) {
    *((::QSql::NumericalPrecisionPolicy*)cppOut) = (::QSql::NumericalPrecisionPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSql_NumericalPrecisionPolicy_PythonToCpp_QSql_NumericalPrecisionPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]))
        return QSql_NumericalPrecisionPolicy_PythonToCpp_QSql_NumericalPrecisionPolicy;
    return 0;
}
static PyObject* QSql_NumericalPrecisionPolicy_CppToPython_QSql_NumericalPrecisionPolicy(const void* cppIn) {
    int castCppIn = *((::QSql::NumericalPrecisionPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX], castCppIn);

}

void init_QSql(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSql_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSql", "QSql",
        &Sbk_QSql_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'Location'.
    SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSql_Type,
        "Location",
        "PySide.QtSql.QSql.Location",
        "QSql::Location");
    if (!SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX],
        &Sbk_QSql_Type, "BeforeFirstRow", (long) QSql::BeforeFirstRow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX],
        &Sbk_QSql_Type, "AfterLastRow", (long) QSql::AfterLastRow))
        return ;
    // Register converter for enum 'QSql::Location'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX],
            QSql_Location_CppToPython_QSql_Location);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSql_Location_PythonToCpp_QSql_Location,
            is_QSql_Location_PythonToCpp_QSql_Location_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_LOCATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSql::Location");
        Shiboken::Conversions::registerConverterName(converter, "Location");
    }
    // End of 'Location' enum.

    // Initialization of enum 'ParamTypeFlag'.
    SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX] = PySide::QFlags::create("ParamType", &SbkPySide_QtSql_QSql_ParamTypeFlag_as_number);
    SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSql_Type,
        "ParamTypeFlag",
        "PySide.QtSql.QSql.ParamTypeFlag",
        "QSql::ParamTypeFlag",
        SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]);
    if (!SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX],
        &Sbk_QSql_Type, "In", (long) QSql::In))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX],
        &Sbk_QSql_Type, "Out", (long) QSql::Out))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX],
        &Sbk_QSql_Type, "InOut", (long) QSql::InOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX],
        &Sbk_QSql_Type, "Binary", (long) QSql::Binary))
        return ;
    // Register converter for enum 'QSql::ParamTypeFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX],
            QSql_ParamTypeFlag_CppToPython_QSql_ParamTypeFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSql_ParamTypeFlag_PythonToCpp_QSql_ParamTypeFlag,
            is_QSql_ParamTypeFlag_PythonToCpp_QSql_ParamTypeFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_PARAMTYPEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSql::ParamTypeFlag");
        Shiboken::Conversions::registerConverterName(converter, "ParamTypeFlag");
    }
    // Register converter for flag 'QFlags<QSql::ParamTypeFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX],
            QFlags_QSql_ParamTypeFlag__CppToPython_QFlags_QSql_ParamTypeFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSql_ParamTypeFlag_PythonToCpp_QFlags_QSql_ParamTypeFlag_,
            is_QSql_ParamTypeFlag_PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QSql_ParamTypeFlag__PythonToCpp_QFlags_QSql_ParamTypeFlag_,
            is_QFlags_QSql_ParamTypeFlag__PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QSql_ParamTypeFlag_,
            is_number_PythonToCpp_QFlags_QSql_ParamTypeFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QSql::ParamTypeFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ParamTypeFlag>");
    }
    // End of 'ParamTypeFlag' enum/flags.

    // Initialization of enum 'TableType'.
    SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSql_Type,
        "TableType",
        "PySide.QtSql.QSql.TableType",
        "QSql::TableType");
    if (!SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX],
        &Sbk_QSql_Type, "Tables", (long) QSql::Tables))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX],
        &Sbk_QSql_Type, "SystemTables", (long) QSql::SystemTables))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX],
        &Sbk_QSql_Type, "Views", (long) QSql::Views))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX],
        &Sbk_QSql_Type, "AllTables", (long) QSql::AllTables))
        return ;
    // Register converter for enum 'QSql::TableType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX],
            QSql_TableType_CppToPython_QSql_TableType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSql_TableType_PythonToCpp_QSql_TableType,
            is_QSql_TableType_PythonToCpp_QSql_TableType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSql::TableType");
        Shiboken::Conversions::registerConverterName(converter, "TableType");
    }
    // End of 'TableType' enum.

    // Initialization of enum 'NumericalPrecisionPolicy'.
    SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSql_Type,
        "NumericalPrecisionPolicy",
        "PySide.QtSql.QSql.NumericalPrecisionPolicy",
        "QSql::NumericalPrecisionPolicy");
    if (!SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX],
        &Sbk_QSql_Type, "LowPrecisionInt32", (long) QSql::LowPrecisionInt32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX],
        &Sbk_QSql_Type, "LowPrecisionInt64", (long) QSql::LowPrecisionInt64))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX],
        &Sbk_QSql_Type, "LowPrecisionDouble", (long) QSql::LowPrecisionDouble))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX],
        &Sbk_QSql_Type, "HighPrecision", (long) QSql::HighPrecision))
        return ;
    // Register converter for enum 'QSql::NumericalPrecisionPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX],
            QSql_NumericalPrecisionPolicy_CppToPython_QSql_NumericalPrecisionPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSql_NumericalPrecisionPolicy_PythonToCpp_QSql_NumericalPrecisionPolicy,
            is_QSql_NumericalPrecisionPolicy_PythonToCpp_QSql_NumericalPrecisionPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSql::NumericalPrecisionPolicy");
        Shiboken::Conversions::registerConverterName(converter, "NumericalPrecisionPolicy");
    }
    // End of 'NumericalPrecisionPolicy' enum.


    qRegisterMetaType< ::QSql::Location >("QSql::Location");
    qRegisterMetaType< ::QSql::ParamTypeFlag >("QSql::ParamTypeFlag");
    qRegisterMetaType< ::QSql::ParamType >("QSql::ParamType");
    qRegisterMetaType< ::QSql::TableType >("QSql::TableType");
    qRegisterMetaType< ::QSql::NumericalPrecisionPolicy >("QSql::NumericalPrecisionPolicy");
}
