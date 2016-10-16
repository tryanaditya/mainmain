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
#include "pyside_qtcore_python.h"

#include "qtconcurrent_wrapper.h"

// Extra includes
#include <qtconcurrentreducekernel.h>
#include <qtconcurrentthreadengine.h>



// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_QtConcurrent_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QtConcurrent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QtConcurrent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QtConcurrent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QtConcurrent",
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
    /*tp_traverse*/         Sbk_QtConcurrent_traverse,
    /*tp_clear*/            Sbk_QtConcurrent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QtConcurrent_methods,
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

PyObject* SbkPySide_QtCore_QtConcurrent_ReduceOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QtConcurrent::ReduceOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QtConcurrent::ReduceOptions)PyLong_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QtConcurrent::ReduceOptions)PyInt_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QtConcurrent_ReduceOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QtConcurrent::ReduceOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QtConcurrent::ReduceOptions)PyLong_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QtConcurrent::ReduceOptions)PyInt_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QtConcurrent_ReduceOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QtConcurrent::ReduceOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QtConcurrent::ReduceOptions)PyLong_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QtConcurrent::ReduceOptions)PyInt_AsLong(self);
    cppArg = (QtConcurrent::ReduceOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QtConcurrent_ReduceOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QtConcurrent::ReduceOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), self, &cppSelf);
    ::QtConcurrent::ReduceOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QtConcurrent_ReduceOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QtConcurrent_ReduceOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QtConcurrent_ReduceOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QtConcurrent_ReduceOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QtConcurrent_ReduceOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QtConcurrent_ReduceOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QtConcurrent_ReduceOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QtConcurrent_ReduceOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QtConcurrent_ReduceOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QtConcurrent_ReduceOption_long,
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
static void QtConcurrent_ReduceOption_PythonToCpp_QtConcurrent_ReduceOption(PyObject* pyIn, void* cppOut) {
    *((::QtConcurrent::ReduceOption*)cppOut) = (::QtConcurrent::ReduceOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QtConcurrent_ReduceOption_PythonToCpp_QtConcurrent_ReduceOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX]))
        return QtConcurrent_ReduceOption_PythonToCpp_QtConcurrent_ReduceOption;
    return 0;
}
static PyObject* QtConcurrent_ReduceOption_CppToPython_QtConcurrent_ReduceOption(const void* cppIn) {
    int castCppIn = *((::QtConcurrent::ReduceOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX], castCppIn);

}

static void QFlags_QtConcurrent_ReduceOption__PythonToCpp_QFlags_QtConcurrent_ReduceOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QtConcurrent::ReduceOption>*)cppOut) = ::QFlags<QtConcurrent::ReduceOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QtConcurrent_ReduceOption__PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]))
        return QFlags_QtConcurrent_ReduceOption__PythonToCpp_QFlags_QtConcurrent_ReduceOption_;
    return 0;
}
static PyObject* QFlags_QtConcurrent_ReduceOption__CppToPython_QFlags_QtConcurrent_ReduceOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QtConcurrent::ReduceOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]));

}

static void QtConcurrent_ReduceOption_PythonToCpp_QFlags_QtConcurrent_ReduceOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QtConcurrent::ReduceOption>*)cppOut) = ::QFlags<QtConcurrent::ReduceOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QtConcurrent_ReduceOption_PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX]))
        return QtConcurrent_ReduceOption_PythonToCpp_QFlags_QtConcurrent_ReduceOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QtConcurrent_ReduceOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QtConcurrent::ReduceOption>*)cppOut) = ::QFlags<QtConcurrent::ReduceOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QtConcurrent_ReduceOption_;
    return 0;
}
void init_QtConcurrent(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QtConcurrent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QtConcurrent", "QtConcurrent",
        &Sbk_QtConcurrent_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'ReduceOption'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX] = PySide::QFlags::create("ReduceOptions", &SbkPySide_QtCore_QtConcurrent_ReduceOption_as_number);
    SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QtConcurrent_Type,
        "ReduceOption",
        "PySide.QtCore.QtConcurrent.ReduceOption",
        "QtConcurrent::ReduceOption",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX],
        &Sbk_QtConcurrent_Type, "UnorderedReduce", (long) QtConcurrent::UnorderedReduce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX],
        &Sbk_QtConcurrent_Type, "OrderedReduce", (long) QtConcurrent::OrderedReduce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX],
        &Sbk_QtConcurrent_Type, "SequentialReduce", (long) QtConcurrent::SequentialReduce))
        return ;
    // Register converter for enum 'QtConcurrent::ReduceOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX],
            QtConcurrent_ReduceOption_CppToPython_QtConcurrent_ReduceOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QtConcurrent_ReduceOption_PythonToCpp_QtConcurrent_ReduceOption,
            is_QtConcurrent_ReduceOption_PythonToCpp_QtConcurrent_ReduceOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTCONCURRENT_REDUCEOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QtConcurrent::ReduceOption");
        Shiboken::Conversions::registerConverterName(converter, "ReduceOption");
    }
    // Register converter for flag 'QFlags<QtConcurrent::ReduceOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX],
            QFlags_QtConcurrent_ReduceOption__CppToPython_QFlags_QtConcurrent_ReduceOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QtConcurrent_ReduceOption_PythonToCpp_QFlags_QtConcurrent_ReduceOption_,
            is_QtConcurrent_ReduceOption_PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QtConcurrent_ReduceOption__PythonToCpp_QFlags_QtConcurrent_ReduceOption_,
            is_QFlags_QtConcurrent_ReduceOption__PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QtConcurrent_ReduceOption_,
            is_number_PythonToCpp_QFlags_QtConcurrent_ReduceOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTCONCURRENT_REDUCEOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QtConcurrent::ReduceOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ReduceOption>");
    }
    // End of 'ReduceOption' enum/flags.


    qRegisterMetaType< ::QtConcurrent::ReduceOption >("QtConcurrent::ReduceOption");
    qRegisterMetaType< ::QtConcurrent::ReduceOptions >("QtConcurrent::ReduceOptions");
}
