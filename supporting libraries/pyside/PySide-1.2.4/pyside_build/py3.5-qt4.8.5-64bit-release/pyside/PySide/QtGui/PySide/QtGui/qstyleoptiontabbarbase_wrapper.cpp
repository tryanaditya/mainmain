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

#include "qstyleoptiontabbarbase_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionTabBarBase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionTabBarBase >()))
        return -1;

    ::QStyleOptionTabBarBase* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionTabBarBase", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionTabBarBase()
    // 1: QStyleOptionTabBarBase(QStyleOptionTabBarBase)
    // 2: QStyleOptionTabBarBase(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionTabBarBase()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionTabBarBase(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionTabBarBase(QStyleOptionTabBarBase)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionTabBarBase_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionTabBarBase()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionTabBarBase()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabBarBase();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionTabBarBase(const QStyleOptionTabBarBase & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionTabBarBase* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTabBarBase(QStyleOptionTabBarBase)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabBarBase(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionTabBarBase(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTabBarBase(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabBarBase(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionTabBarBase >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionTabBarBase_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionTabBarBase_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionTabBarBase", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionTabBarBase", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionTabBarBase_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionTabBarBase_get_selectedTabRect(PyObject* self, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &(cppSelf->selectedTabRect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTabBarBase_set_selectedTabRect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'selectedTabRect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'selectedTabRect', 'QRect' or convertible type expected");
        return -1;
    }

    ::QRect& cppOut_ptr = cppSelf->selectedTabRect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionTabBarBase_get_shape(PyObject* self, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    ::QTabBar::Shape cppOut_local = cppSelf->shape;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABBAR_SHAPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTabBarBase_set_shape(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'shape' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABBAR_SHAPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'shape', 'Shape' or convertible type expected");
        return -1;
    }

    ::QTabBar::Shape cppOut_local = cppSelf->shape;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->shape = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTabBarBase_get_tabBarRect(PyObject* self, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &(cppSelf->tabBarRect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTabBarBase_set_tabBarRect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabBarBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabBarBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tabBarRect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tabBarRect', 'QRect' or convertible type expected");
        return -1;
    }

    ::QRect& cppOut_ptr = cppSelf->tabBarRect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionTabBarBase
static PyGetSetDef Sbk_QStyleOptionTabBarBase_getsetlist[] = {
    {const_cast<char*>("selectedTabRect"), Sbk_QStyleOptionTabBarBase_get_selectedTabRect, Sbk_QStyleOptionTabBarBase_set_selectedTabRect},
    {const_cast<char*>("shape"), Sbk_QStyleOptionTabBarBase_get_shape, Sbk_QStyleOptionTabBarBase_set_shape},
    {const_cast<char*>("tabBarRect"), Sbk_QStyleOptionTabBarBase_get_tabBarRect, Sbk_QStyleOptionTabBarBase_set_tabBarRect},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionTabBarBase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionTabBarBase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionTabBarBase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionTabBarBase",
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
    /*tp_traverse*/         Sbk_QStyleOptionTabBarBase_traverse,
    /*tp_clear*/            Sbk_QStyleOptionTabBarBase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionTabBarBase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionTabBarBase_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionTabBarBase_Init,
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
static void QStyleOptionTabBarBase_StyleOptionType_PythonToCpp_QStyleOptionTabBarBase_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTabBarBase::StyleOptionType*)cppOut) = (::QStyleOptionTabBarBase::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTabBarBase_StyleOptionType_PythonToCpp_QStyleOptionTabBarBase_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionTabBarBase_StyleOptionType_PythonToCpp_QStyleOptionTabBarBase_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionTabBarBase_StyleOptionType_CppToPython_QStyleOptionTabBarBase_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTabBarBase::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionTabBarBase_StyleOptionVersion_PythonToCpp_QStyleOptionTabBarBase_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTabBarBase::StyleOptionVersion*)cppOut) = (::QStyleOptionTabBarBase::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTabBarBase_StyleOptionVersion_PythonToCpp_QStyleOptionTabBarBase_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionTabBarBase_StyleOptionVersion_PythonToCpp_QStyleOptionTabBarBase_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionTabBarBase_StyleOptionVersion_CppToPython_QStyleOptionTabBarBase_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTabBarBase::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionTabBarBase_PythonToCpp_QStyleOptionTabBarBase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionTabBarBase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionTabBarBase_PythonToCpp_QStyleOptionTabBarBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionTabBarBase_Type))
        return QStyleOptionTabBarBase_PythonToCpp_QStyleOptionTabBarBase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionTabBarBase_PTR_CppToPython_QStyleOptionTabBarBase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionTabBarBase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionTabBarBase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionTabBarBase(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionTabBarBase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionTabBarBase", "QStyleOptionTabBarBase*",
        &Sbk_QStyleOptionTabBarBase_Type, &Shiboken::callCppDestructor< ::QStyleOptionTabBarBase >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionTabBarBase_Type,
        QStyleOptionTabBarBase_PythonToCpp_QStyleOptionTabBarBase_PTR,
        is_QStyleOptionTabBarBase_PythonToCpp_QStyleOptionTabBarBase_PTR_Convertible,
        QStyleOptionTabBarBase_PTR_CppToPython_QStyleOptionTabBarBase);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabBarBase");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabBarBase*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabBarBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionTabBarBase).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTabBarBase_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionTabBarBase.StyleOptionType",
        "QStyleOptionTabBarBase::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionTabBarBase_Type, "Type", (long) QStyleOptionTabBarBase::Type))
        return ;
    // Register converter for enum 'QStyleOptionTabBarBase::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX],
            QStyleOptionTabBarBase_StyleOptionType_CppToPython_QStyleOptionTabBarBase_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTabBarBase_StyleOptionType_PythonToCpp_QStyleOptionTabBarBase_StyleOptionType,
            is_QStyleOptionTabBarBase_StyleOptionType_PythonToCpp_QStyleOptionTabBarBase_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabBarBase::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTabBarBase_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionTabBarBase.StyleOptionVersion",
        "QStyleOptionTabBarBase::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionTabBarBase_Type, "Version", (long) QStyleOptionTabBarBase::Version))
        return ;
    // Register converter for enum 'QStyleOptionTabBarBase::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX],
            QStyleOptionTabBarBase_StyleOptionVersion_CppToPython_QStyleOptionTabBarBase_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTabBarBase_StyleOptionVersion_PythonToCpp_QStyleOptionTabBarBase_StyleOptionVersion,
            is_QStyleOptionTabBarBase_StyleOptionVersion_PythonToCpp_QStyleOptionTabBarBase_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABBARBASE_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabBarBase::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionTabBarBase::StyleOptionType >("QStyleOptionTabBarBase::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionTabBarBase::StyleOptionVersion >("QStyleOptionTabBarBase::StyleOptionVersion");
}
