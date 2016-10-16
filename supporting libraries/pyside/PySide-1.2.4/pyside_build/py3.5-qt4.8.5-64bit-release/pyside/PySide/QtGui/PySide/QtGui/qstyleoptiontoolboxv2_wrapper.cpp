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

#include "qstyleoptiontoolboxv2_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionToolBoxV2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionToolBoxV2 >()))
        return -1;

    ::QStyleOptionToolBoxV2* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionToolBoxV2", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionToolBoxV2()
    // 1: QStyleOptionToolBoxV2(QStyleOptionToolBox)
    // 2: QStyleOptionToolBoxV2(QStyleOptionToolBoxV2)
    // 3: QStyleOptionToolBoxV2(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionToolBoxV2()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionToolBoxV2(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionToolBoxV2(QStyleOptionToolBoxV2)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionToolBoxV2(QStyleOptionToolBox)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionToolBoxV2_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionToolBoxV2()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBoxV2()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBoxV2();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionToolBoxV2(const QStyleOptionToolBox & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionToolBox* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBoxV2(QStyleOptionToolBox)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBoxV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionToolBoxV2(const QStyleOptionToolBoxV2 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionToolBoxV2* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBoxV2(QStyleOptionToolBoxV2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBoxV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionToolBoxV2(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBoxV2(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBoxV2(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionToolBoxV2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionToolBoxV2_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionToolBoxV2_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionToolBox", "PySide.QtGui.QStyleOptionToolBoxV2", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionToolBoxV2", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionToolBoxV2_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionToolBoxV2_get_position(PyObject* self, void*)
{
    ::QStyleOptionToolBoxV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBoxV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX], (SbkObject*)self));
    ::QStyleOptionToolBoxV2::TabPosition cppOut_local = cppSelf->position;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBoxV2_set_position(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBoxV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBoxV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'position' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'position', 'TabPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionToolBoxV2::TabPosition cppOut_local = cppSelf->position;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->position = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBoxV2_get_selectedPosition(PyObject* self, void*)
{
    ::QStyleOptionToolBoxV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBoxV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX], (SbkObject*)self));
    ::QStyleOptionToolBoxV2::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBoxV2_set_selectedPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBoxV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBoxV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'selectedPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'selectedPosition', 'SelectedPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionToolBoxV2::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->selectedPosition = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionToolBoxV2
static PyGetSetDef Sbk_QStyleOptionToolBoxV2_getsetlist[] = {
    {const_cast<char*>("position"), Sbk_QStyleOptionToolBoxV2_get_position, Sbk_QStyleOptionToolBoxV2_set_position},
    {const_cast<char*>("selectedPosition"), Sbk_QStyleOptionToolBoxV2_get_selectedPosition, Sbk_QStyleOptionToolBoxV2_set_selectedPosition},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionToolBoxV2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionToolBoxV2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionToolBoxV2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionToolBoxV2",
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
    /*tp_traverse*/         Sbk_QStyleOptionToolBoxV2_traverse,
    /*tp_clear*/            Sbk_QStyleOptionToolBoxV2_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionToolBoxV2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionToolBoxV2_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionToolBoxV2_Init,
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
static void QStyleOptionToolBoxV2_StyleOptionVersion_PythonToCpp_QStyleOptionToolBoxV2_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBoxV2::StyleOptionVersion*)cppOut) = (::QStyleOptionToolBoxV2::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBoxV2_StyleOptionVersion_PythonToCpp_QStyleOptionToolBoxV2_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionToolBoxV2_StyleOptionVersion_PythonToCpp_QStyleOptionToolBoxV2_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionToolBoxV2_StyleOptionVersion_CppToPython_QStyleOptionToolBoxV2_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBoxV2::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionToolBoxV2_TabPosition_PythonToCpp_QStyleOptionToolBoxV2_TabPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBoxV2::TabPosition*)cppOut) = (::QStyleOptionToolBoxV2::TabPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBoxV2_TabPosition_PythonToCpp_QStyleOptionToolBoxV2_TabPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX]))
        return QStyleOptionToolBoxV2_TabPosition_PythonToCpp_QStyleOptionToolBoxV2_TabPosition;
    return 0;
}
static PyObject* QStyleOptionToolBoxV2_TabPosition_CppToPython_QStyleOptionToolBoxV2_TabPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBoxV2::TabPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX], castCppIn);

}

static void QStyleOptionToolBoxV2_SelectedPosition_PythonToCpp_QStyleOptionToolBoxV2_SelectedPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBoxV2::SelectedPosition*)cppOut) = (::QStyleOptionToolBoxV2::SelectedPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBoxV2_SelectedPosition_PythonToCpp_QStyleOptionToolBoxV2_SelectedPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX]))
        return QStyleOptionToolBoxV2_SelectedPosition_PythonToCpp_QStyleOptionToolBoxV2_SelectedPosition;
    return 0;
}
static PyObject* QStyleOptionToolBoxV2_SelectedPosition_CppToPython_QStyleOptionToolBoxV2_SelectedPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBoxV2::SelectedPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionToolBoxV2_PythonToCpp_QStyleOptionToolBoxV2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionToolBoxV2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionToolBoxV2_PythonToCpp_QStyleOptionToolBoxV2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionToolBoxV2_Type))
        return QStyleOptionToolBoxV2_PythonToCpp_QStyleOptionToolBoxV2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionToolBoxV2_PTR_CppToPython_QStyleOptionToolBoxV2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionToolBoxV2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionToolBoxV2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionToolBoxV2(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionToolBoxV2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionToolBoxV2", "QStyleOptionToolBoxV2*",
        &Sbk_QStyleOptionToolBoxV2_Type, &Shiboken::callCppDestructor< ::QStyleOptionToolBoxV2 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionToolBoxV2_Type,
        QStyleOptionToolBoxV2_PythonToCpp_QStyleOptionToolBoxV2_PTR,
        is_QStyleOptionToolBoxV2_PythonToCpp_QStyleOptionToolBoxV2_PTR_Convertible,
        QStyleOptionToolBoxV2_PTR_CppToPython_QStyleOptionToolBoxV2);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionToolBoxV2).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBoxV2_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionToolBoxV2.StyleOptionVersion",
        "QStyleOptionToolBoxV2::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "Version", (long) QStyleOptionToolBoxV2::Version))
        return ;
    // Register converter for enum 'QStyleOptionToolBoxV2::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX],
            QStyleOptionToolBoxV2_StyleOptionVersion_CppToPython_QStyleOptionToolBoxV2_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBoxV2_StyleOptionVersion_PythonToCpp_QStyleOptionToolBoxV2_StyleOptionVersion,
            is_QStyleOptionToolBoxV2_StyleOptionVersion_PythonToCpp_QStyleOptionToolBoxV2_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'TabPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBoxV2_Type,
        "TabPosition",
        "PySide.QtGui.QStyleOptionToolBoxV2.TabPosition",
        "QStyleOptionToolBoxV2::TabPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "Beginning", (long) QStyleOptionToolBoxV2::Beginning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "Middle", (long) QStyleOptionToolBoxV2::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "End", (long) QStyleOptionToolBoxV2::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "OnlyOneTab", (long) QStyleOptionToolBoxV2::OnlyOneTab))
        return ;
    // Register converter for enum 'QStyleOptionToolBoxV2::TabPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX],
            QStyleOptionToolBoxV2_TabPosition_CppToPython_QStyleOptionToolBoxV2_TabPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBoxV2_TabPosition_PythonToCpp_QStyleOptionToolBoxV2_TabPosition,
            is_QStyleOptionToolBoxV2_TabPosition_PythonToCpp_QStyleOptionToolBoxV2_TabPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_TABPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2::TabPosition");
        Shiboken::Conversions::registerConverterName(converter, "TabPosition");
    }
    // End of 'TabPosition' enum.

    // Initialization of enum 'SelectedPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBoxV2_Type,
        "SelectedPosition",
        "PySide.QtGui.QStyleOptionToolBoxV2.SelectedPosition",
        "QStyleOptionToolBoxV2::SelectedPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "NotAdjacent", (long) QStyleOptionToolBoxV2::NotAdjacent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "NextIsSelected", (long) QStyleOptionToolBoxV2::NextIsSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionToolBoxV2_Type, "PreviousIsSelected", (long) QStyleOptionToolBoxV2::PreviousIsSelected))
        return ;
    // Register converter for enum 'QStyleOptionToolBoxV2::SelectedPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX],
            QStyleOptionToolBoxV2_SelectedPosition_CppToPython_QStyleOptionToolBoxV2_SelectedPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBoxV2_SelectedPosition_PythonToCpp_QStyleOptionToolBoxV2_SelectedPosition,
            is_QStyleOptionToolBoxV2_SelectedPosition_PythonToCpp_QStyleOptionToolBoxV2_SelectedPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBOXV2_SELECTEDPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBoxV2::SelectedPosition");
        Shiboken::Conversions::registerConverterName(converter, "SelectedPosition");
    }
    // End of 'SelectedPosition' enum.


    qRegisterMetaType< ::QStyleOptionToolBoxV2::StyleOptionVersion >("QStyleOptionToolBoxV2::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionToolBoxV2::TabPosition >("QStyleOptionToolBoxV2::TabPosition");
    qRegisterMetaType< ::QStyleOptionToolBoxV2::SelectedPosition >("QStyleOptionToolBoxV2::SelectedPosition");
}
