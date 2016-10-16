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

#include "qstylehintreturn_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleHintReturn_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleHintReturn >()))
        return -1;

    ::QStyleHintReturn* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleHintReturn(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QStyleHintReturn", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleHintReturn(int,int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleHintReturn(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QStyleHintReturn(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // QStyleHintReturn(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleHintReturn_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "version");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleHintReturn(): got multiple values for keyword argument 'version'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QStyleHintReturn_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleHintReturn(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStyleHintReturn_Init_TypeError;
            }
        }
        int cppArg0 = QStyleOption::Version;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = QStyleHintReturn::SH_Default;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QStyleHintReturn(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QStyleHintReturn(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleHintReturn >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleHintReturn_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleHintReturn_Init_TypeError:
        const char* overloads[] = {"int = QStyleOption.Version, int = SH_Default", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleHintReturn", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleHintReturn_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleHintReturn_get_version(PyObject* self, void*)
{
    ::QStyleHintReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->version;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleHintReturn_set_version(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleHintReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'version' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'version', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->version;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->version = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleHintReturn_get_type(PyObject* self, void*)
{
    ::QStyleHintReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->type;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleHintReturn_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleHintReturn* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleHintReturn*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->type = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleHintReturn
static PyGetSetDef Sbk_QStyleHintReturn_getsetlist[] = {
    {const_cast<char*>("version"), Sbk_QStyleHintReturn_get_version, Sbk_QStyleHintReturn_set_version},
    {const_cast<char*>("type"), Sbk_QStyleHintReturn_get_type, Sbk_QStyleHintReturn_set_type},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleHintReturn_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleHintReturn_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleHintReturn_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleHintReturn",
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
    /*tp_traverse*/         Sbk_QStyleHintReturn_traverse,
    /*tp_clear*/            Sbk_QStyleHintReturn_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleHintReturn_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleHintReturn_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleHintReturn_Init,
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
static void QStyleHintReturn_HintReturnType_PythonToCpp_QStyleHintReturn_HintReturnType(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturn::HintReturnType*)cppOut) = (::QStyleHintReturn::HintReturnType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturn_HintReturnType_PythonToCpp_QStyleHintReturn_HintReturnType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX]))
        return QStyleHintReturn_HintReturnType_PythonToCpp_QStyleHintReturn_HintReturnType;
    return 0;
}
static PyObject* QStyleHintReturn_HintReturnType_CppToPython_QStyleHintReturn_HintReturnType(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturn::HintReturnType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX], castCppIn);

}

static void QStyleHintReturn_StyleOptionType_PythonToCpp_QStyleHintReturn_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturn::StyleOptionType*)cppOut) = (::QStyleHintReturn::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturn_StyleOptionType_PythonToCpp_QStyleHintReturn_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX]))
        return QStyleHintReturn_StyleOptionType_PythonToCpp_QStyleHintReturn_StyleOptionType;
    return 0;
}
static PyObject* QStyleHintReturn_StyleOptionType_CppToPython_QStyleHintReturn_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturn::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleHintReturn_StyleOptionVersion_PythonToCpp_QStyleHintReturn_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleHintReturn::StyleOptionVersion*)cppOut) = (::QStyleHintReturn::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleHintReturn_StyleOptionVersion_PythonToCpp_QStyleHintReturn_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX]))
        return QStyleHintReturn_StyleOptionVersion_PythonToCpp_QStyleHintReturn_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleHintReturn_StyleOptionVersion_CppToPython_QStyleHintReturn_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleHintReturn::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleHintReturn_PythonToCpp_QStyleHintReturn_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleHintReturn_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleHintReturn_PythonToCpp_QStyleHintReturn_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleHintReturn_Type))
        return QStyleHintReturn_PythonToCpp_QStyleHintReturn_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleHintReturn_PTR_CppToPython_QStyleHintReturn(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleHintReturn*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleHintReturn_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleHintReturn(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleHintReturn_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleHintReturn", "QStyleHintReturn*",
        &Sbk_QStyleHintReturn_Type, &Shiboken::callCppDestructor< ::QStyleHintReturn >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleHintReturn_Type,
        QStyleHintReturn_PythonToCpp_QStyleHintReturn_PTR,
        is_QStyleHintReturn_PythonToCpp_QStyleHintReturn_PTR_Convertible,
        QStyleHintReturn_PTR_CppToPython_QStyleHintReturn);

    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleHintReturn).name());


    // Initialization of enums.

    // Initialization of enum 'HintReturnType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturn_Type,
        "HintReturnType",
        "PySide.QtGui.QStyleHintReturn.HintReturnType",
        "QStyleHintReturn::HintReturnType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX],
        &Sbk_QStyleHintReturn_Type, "SH_Default", (long) QStyleHintReturn::SH_Default))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX],
        &Sbk_QStyleHintReturn_Type, "SH_Mask", (long) QStyleHintReturn::SH_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX],
        &Sbk_QStyleHintReturn_Type, "SH_Variant", (long) QStyleHintReturn::SH_Variant))
        return ;
    // Register converter for enum 'QStyleHintReturn::HintReturnType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX],
            QStyleHintReturn_HintReturnType_CppToPython_QStyleHintReturn_HintReturnType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturn_HintReturnType_PythonToCpp_QStyleHintReturn_HintReturnType,
            is_QStyleHintReturn_HintReturnType_PythonToCpp_QStyleHintReturn_HintReturnType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_HINTRETURNTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn::HintReturnType");
        Shiboken::Conversions::registerConverterName(converter, "HintReturnType");
    }
    // End of 'HintReturnType' enum.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturn_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleHintReturn.StyleOptionType",
        "QStyleHintReturn::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleHintReturn_Type, "Type", (long) QStyleHintReturn::Type))
        return ;
    // Register converter for enum 'QStyleHintReturn::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX],
            QStyleHintReturn_StyleOptionType_CppToPython_QStyleHintReturn_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturn_StyleOptionType_PythonToCpp_QStyleHintReturn_StyleOptionType,
            is_QStyleHintReturn_StyleOptionType_PythonToCpp_QStyleHintReturn_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleHintReturn_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleHintReturn.StyleOptionVersion",
        "QStyleHintReturn::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleHintReturn_Type, "Version", (long) QStyleHintReturn::Version))
        return ;
    // Register converter for enum 'QStyleHintReturn::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX],
            QStyleHintReturn_StyleOptionVersion_CppToPython_QStyleHintReturn_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleHintReturn_StyleOptionVersion_PythonToCpp_QStyleHintReturn_StyleOptionVersion,
            is_QStyleHintReturn_StyleOptionVersion_PythonToCpp_QStyleHintReturn_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleHintReturn::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleHintReturn::HintReturnType >("QStyleHintReturn::HintReturnType");
    qRegisterMetaType< ::QStyleHintReturn::StyleOptionType >("QStyleHintReturn::StyleOptionType");
    qRegisterMetaType< ::QStyleHintReturn::StyleOptionVersion >("QStyleHintReturn::StyleOptionVersion");
}
