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
#include "pyside_qtgui_python.h"

#include "qstylehintreturnmask_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleHintReturnMask_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleHintReturnMask >()))
        return -1;

    ::QStyleHintReturnMask* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QStyleHintReturnMask()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QStyleHintReturnMask();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleHintReturnMask >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_QStyleHintReturnMask_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleHintReturnMask_get_region(PyObject* self, void*)
{
    ::QStyleHintReturnMask* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturnMask*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], &(cppSelf->region), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleHintReturnMask_set_region(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleHintReturnMask* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturnMask*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'region' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'region', 'QRegion' or convertible type expected");
        return -1;
    }

    ::QRegion& cppOut_ptr = cppSelf->region;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleHintReturnMask
static PyGetSetDef Sbk_QStyleHintReturnMask_getsetlist[] = {
    {const_cast<char*>("region"), Sbk_QStyleHintReturnMask_get_region, Sbk_QStyleHintReturnMask_set_region},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleHintReturnMask_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleHintReturnMask_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleHintReturnMask_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleHintReturnMask",
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
    /*tp_traverse*/         Sbk_QStyleHintReturnMask_traverse,
    /*tp_clear*/            Sbk_QStyleHintReturnMask_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleHintReturnMask_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleHintReturnMask_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleHintReturnMask_Init,
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
static void QStyleHintReturnMask_StyleOptionType_PythonToCpp_QStyleHintReturnMask_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturnMask::StyleOptionType*)cppOut) = (::QStyleHintReturnMask::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturnMask_StyleOptionType_PythonToCpp_QStyleHintReturnMask_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX]))
        return QStyleHintReturnMask_StyleOptionType_PythonToCpp_QStyleHintReturnMask_StyleOptionType;
    return 0;
}
static PyObject* QStyleHintReturnMask_StyleOptionType_CppToPython_QStyleHintReturnMask_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturnMask::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleHintReturnMask_StyleOptionVersion_PythonToCpp_QStyleHintReturnMask_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturnMask::StyleOptionVersion*)cppOut) = (::QStyleHintReturnMask::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturnMask_StyleOptionVersion_PythonToCpp_QStyleHintReturnMask_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX]))
        return QStyleHintReturnMask_StyleOptionVersion_PythonToCpp_QStyleHintReturnMask_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleHintReturnMask_StyleOptionVersion_CppToPython_QStyleHintReturnMask_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturnMask::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleHintReturnMask_PythonToCpp_QStyleHintReturnMask_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleHintReturnMask_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleHintReturnMask_PythonToCpp_QStyleHintReturnMask_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleHintReturnMask_Type))
        return QStyleHintReturnMask_PythonToCpp_QStyleHintReturnMask_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleHintReturnMask_PTR_CppToPython_QStyleHintReturnMask(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleHintReturnMask*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleHintReturnMask_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleHintReturnMask(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleHintReturnMask_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleHintReturnMask", "QStyleHintReturnMask*",
        &Sbk_QStyleHintReturnMask_Type, &Shiboken::callCppDestructor< ::QStyleHintReturnMask >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleHintReturnMask_Type,
        QStyleHintReturnMask_PythonToCpp_QStyleHintReturnMask_PTR,
        is_QStyleHintReturnMask_PythonToCpp_QStyleHintReturnMask_PTR_Convertible,
        QStyleHintReturnMask_PTR_CppToPython_QStyleHintReturnMask);

    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnMask");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnMask*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnMask&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleHintReturnMask).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturnMask_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleHintReturnMask.StyleOptionType",
        "QStyleHintReturnMask::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleHintReturnMask_Type, "Type", (long) QStyleHintReturnMask::Type))
        return ;
    // Register converter for enum 'QStyleHintReturnMask::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX],
            QStyleHintReturnMask_StyleOptionType_CppToPython_QStyleHintReturnMask_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturnMask_StyleOptionType_PythonToCpp_QStyleHintReturnMask_StyleOptionType,
            is_QStyleHintReturnMask_StyleOptionType_PythonToCpp_QStyleHintReturnMask_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnMask::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturnMask_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleHintReturnMask.StyleOptionVersion",
        "QStyleHintReturnMask::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleHintReturnMask_Type, "Version", (long) QStyleHintReturnMask::Version))
        return ;
    // Register converter for enum 'QStyleHintReturnMask::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX],
            QStyleHintReturnMask_StyleOptionVersion_CppToPython_QStyleHintReturnMask_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturnMask_StyleOptionVersion_PythonToCpp_QStyleHintReturnMask_StyleOptionVersion,
            is_QStyleHintReturnMask_StyleOptionVersion_PythonToCpp_QStyleHintReturnMask_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNMASK_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnMask::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleHintReturnMask::StyleOptionType >("QStyleHintReturnMask::StyleOptionType");
    qRegisterMetaType< ::QStyleHintReturnMask::StyleOptionVersion >("QStyleHintReturnMask::StyleOptionVersion");
}
