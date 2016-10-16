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
#include "pyside_qtmultimedia_python.h"

#include "qaudio_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_QAudio_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAudio_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAudio_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAudio_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAudio",
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
    /*tp_traverse*/         Sbk_QAudio_traverse,
    /*tp_clear*/            Sbk_QAudio_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAudio_methods,
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
static void QAudio_Error_PythonToCpp_QAudio_Error(PyObject* pyIn, void* cppOut) {
    *((::QAudio::Error*)cppOut) = (::QAudio::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAudio_Error_PythonToCpp_QAudio_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX]))
        return QAudio_Error_PythonToCpp_QAudio_Error;
    return 0;
}
static PyObject* QAudio_Error_CppToPython_QAudio_Error(const void* cppIn) {
    int castCppIn = *((::QAudio::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX], castCppIn);

}

static void QAudio_State_PythonToCpp_QAudio_State(PyObject* pyIn, void* cppOut) {
    *((::QAudio::State*)cppOut) = (::QAudio::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAudio_State_PythonToCpp_QAudio_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX]))
        return QAudio_State_PythonToCpp_QAudio_State;
    return 0;
}
static PyObject* QAudio_State_CppToPython_QAudio_State(const void* cppIn) {
    int castCppIn = *((::QAudio::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX], castCppIn);

}

static void QAudio_Mode_PythonToCpp_QAudio_Mode(PyObject* pyIn, void* cppOut) {
    *((::QAudio::Mode*)cppOut) = (::QAudio::Mode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAudio_Mode_PythonToCpp_QAudio_Mode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]))
        return QAudio_Mode_PythonToCpp_QAudio_Mode;
    return 0;
}
static PyObject* QAudio_Mode_CppToPython_QAudio_Mode(const void* cppIn) {
    int castCppIn = *((::QAudio::Mode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX], castCppIn);

}

void init_QAudio(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QAUDIO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAudio_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAudio", "QAudio",
        &Sbk_QAudio_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'Error'.
    SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAudio_Type,
        "Error",
        "PySide.QtMultimedia.QAudio.Error",
        "QAudio::Error");
    if (!SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
        &Sbk_QAudio_Type, "NoError", (long) QAudio::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
        &Sbk_QAudio_Type, "OpenError", (long) QAudio::OpenError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
        &Sbk_QAudio_Type, "IOError", (long) QAudio::IOError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
        &Sbk_QAudio_Type, "UnderrunError", (long) QAudio::UnderrunError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
        &Sbk_QAudio_Type, "FatalError", (long) QAudio::FatalError))
        return ;
    // Register converter for enum 'QAudio::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX],
            QAudio_Error_CppToPython_QAudio_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAudio_Error_PythonToCpp_QAudio_Error,
            is_QAudio_Error_PythonToCpp_QAudio_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAudio::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.

    // Initialization of enum 'State'.
    SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAudio_Type,
        "State",
        "PySide.QtMultimedia.QAudio.State",
        "QAudio::State");
    if (!SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX],
        &Sbk_QAudio_Type, "ActiveState", (long) QAudio::ActiveState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX],
        &Sbk_QAudio_Type, "SuspendedState", (long) QAudio::SuspendedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX],
        &Sbk_QAudio_Type, "StoppedState", (long) QAudio::StoppedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX],
        &Sbk_QAudio_Type, "IdleState", (long) QAudio::IdleState))
        return ;
    // Register converter for enum 'QAudio::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX],
            QAudio_State_CppToPython_QAudio_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAudio_State_PythonToCpp_QAudio_State,
            is_QAudio_State_PythonToCpp_QAudio_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAudio::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'Mode'.
    SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAudio_Type,
        "Mode",
        "PySide.QtMultimedia.QAudio.Mode",
        "QAudio::Mode");
    if (!SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX],
        &Sbk_QAudio_Type, "AudioInput", (long) QAudio::AudioInput))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX],
        &Sbk_QAudio_Type, "AudioOutput", (long) QAudio::AudioOutput))
        return ;
    // Register converter for enum 'QAudio::Mode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX],
            QAudio_Mode_CppToPython_QAudio_Mode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAudio_Mode_PythonToCpp_QAudio_Mode,
            is_QAudio_Mode_PythonToCpp_QAudio_Mode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAudio::Mode");
        Shiboken::Conversions::registerConverterName(converter, "Mode");
    }
    // End of 'Mode' enum.


    qRegisterMetaType< ::QAudio::Error >("QAudio::Error");
    qRegisterMetaType< ::QAudio::State >("QAudio::State");
    qRegisterMetaType< ::QAudio::Mode >("QAudio::Mode");
}
