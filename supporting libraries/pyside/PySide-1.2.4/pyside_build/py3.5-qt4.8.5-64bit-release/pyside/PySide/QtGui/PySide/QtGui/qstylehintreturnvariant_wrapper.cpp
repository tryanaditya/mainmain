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

#include "qstylehintreturnvariant_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleHintReturnVariant_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleHintReturnVariant >()))
        return -1;

    ::QStyleHintReturnVariant* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QStyleHintReturnVariant()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QStyleHintReturnVariant();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleHintReturnVariant >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_QStyleHintReturnVariant_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleHintReturnVariant_get_variant(PyObject* self, void*)
{
    ::QStyleHintReturnVariant* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturnVariant*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppSelf->variant);
    return pyOut;
}
static int Sbk_QStyleHintReturnVariant_set_variant(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleHintReturnVariant* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturnVariant*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'variant' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'variant', 'QVariant' or convertible type expected");
        return -1;
    }

    ::QVariant& cppOut_ptr = cppSelf->variant;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleHintReturnVariant
static PyGetSetDef Sbk_QStyleHintReturnVariant_getsetlist[] = {
    {const_cast<char*>("variant"), Sbk_QStyleHintReturnVariant_get_variant, Sbk_QStyleHintReturnVariant_set_variant},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleHintReturnVariant_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleHintReturnVariant_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleHintReturnVariant_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleHintReturnVariant",
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
    /*tp_traverse*/         Sbk_QStyleHintReturnVariant_traverse,
    /*tp_clear*/            Sbk_QStyleHintReturnVariant_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleHintReturnVariant_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleHintReturnVariant_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleHintReturnVariant_Init,
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
static void QStyleHintReturnVariant_StyleOptionType_PythonToCpp_QStyleHintReturnVariant_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturnVariant::StyleOptionType*)cppOut) = (::QStyleHintReturnVariant::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturnVariant_StyleOptionType_PythonToCpp_QStyleHintReturnVariant_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX]))
        return QStyleHintReturnVariant_StyleOptionType_PythonToCpp_QStyleHintReturnVariant_StyleOptionType;
    return 0;
}
static PyObject* QStyleHintReturnVariant_StyleOptionType_CppToPython_QStyleHintReturnVariant_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturnVariant::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleHintReturnVariant_StyleOptionVersion_PythonToCpp_QStyleHintReturnVariant_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturnVariant::StyleOptionVersion*)cppOut) = (::QStyleHintReturnVariant::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturnVariant_StyleOptionVersion_PythonToCpp_QStyleHintReturnVariant_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX]))
        return QStyleHintReturnVariant_StyleOptionVersion_PythonToCpp_QStyleHintReturnVariant_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleHintReturnVariant_StyleOptionVersion_CppToPython_QStyleHintReturnVariant_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturnVariant::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleHintReturnVariant_PythonToCpp_QStyleHintReturnVariant_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleHintReturnVariant_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleHintReturnVariant_PythonToCpp_QStyleHintReturnVariant_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleHintReturnVariant_Type))
        return QStyleHintReturnVariant_PythonToCpp_QStyleHintReturnVariant_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleHintReturnVariant_PTR_CppToPython_QStyleHintReturnVariant(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleHintReturnVariant*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleHintReturnVariant_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleHintReturnVariant(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleHintReturnVariant_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleHintReturnVariant", "QStyleHintReturnVariant*",
        &Sbk_QStyleHintReturnVariant_Type, &Shiboken::callCppDestructor< ::QStyleHintReturnVariant >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleHintReturnVariant_Type,
        QStyleHintReturnVariant_PythonToCpp_QStyleHintReturnVariant_PTR,
        is_QStyleHintReturnVariant_PythonToCpp_QStyleHintReturnVariant_PTR_Convertible,
        QStyleHintReturnVariant_PTR_CppToPython_QStyleHintReturnVariant);

    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnVariant");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnVariant*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnVariant&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleHintReturnVariant).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturnVariant_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleHintReturnVariant.StyleOptionType",
        "QStyleHintReturnVariant::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleHintReturnVariant_Type, "Type", (long) QStyleHintReturnVariant::Type))
        return ;
    // Register converter for enum 'QStyleHintReturnVariant::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX],
            QStyleHintReturnVariant_StyleOptionType_CppToPython_QStyleHintReturnVariant_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturnVariant_StyleOptionType_PythonToCpp_QStyleHintReturnVariant_StyleOptionType,
            is_QStyleHintReturnVariant_StyleOptionType_PythonToCpp_QStyleHintReturnVariant_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnVariant::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturnVariant_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleHintReturnVariant.StyleOptionVersion",
        "QStyleHintReturnVariant::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleHintReturnVariant_Type, "Version", (long) QStyleHintReturnVariant::Version))
        return ;
    // Register converter for enum 'QStyleHintReturnVariant::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX],
            QStyleHintReturnVariant_StyleOptionVersion_CppToPython_QStyleHintReturnVariant_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturnVariant_StyleOptionVersion_PythonToCpp_QStyleHintReturnVariant_StyleOptionVersion,
            is_QStyleHintReturnVariant_StyleOptionVersion_PythonToCpp_QStyleHintReturnVariant_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURNVARIANT_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturnVariant::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleHintReturnVariant::StyleOptionType >("QStyleHintReturnVariant::StyleOptionType");
    qRegisterMetaType< ::QStyleHintReturnVariant::StyleOptionVersion >("QStyleHintReturnVariant::StyleOptionVersion");
}
