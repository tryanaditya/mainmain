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

#include "qstyleoptiontitlebar_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionTitleBar_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionTitleBar >()))
        return -1;

    ::QStyleOptionTitleBar* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionTitleBar", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionTitleBar()
    // 1: QStyleOptionTitleBar(QStyleOptionTitleBar)
    // 2: QStyleOptionTitleBar(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionTitleBar()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionTitleBar(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionTitleBar(QStyleOptionTitleBar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionTitleBar_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionTitleBar()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionTitleBar()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTitleBar();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionTitleBar(const QStyleOptionTitleBar & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionTitleBar* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTitleBar(QStyleOptionTitleBar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTitleBar(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionTitleBar(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTitleBar(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTitleBar(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionTitleBar >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionTitleBar_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionTitleBar_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionTitleBar", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionTitleBar", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionTitleBar_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionTitleBar_get_titleBarFlags(PyObject* self, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), &cppSelf->titleBarFlags);
    return pyOut;
}
static int Sbk_QStyleOptionTitleBar_set_titleBarFlags(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'titleBarFlags' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'titleBarFlags', 'WindowFlags' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::WindowType> cppOut_local = cppSelf->titleBarFlags;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->titleBarFlags = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTitleBar_get_icon(PyObject* self, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTitleBar_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'icon' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'icon', 'QIcon' or convertible type expected");
        return -1;
    }

    ::QIcon& cppOut_ptr = cppSelf->icon;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionTitleBar_get_text(PyObject* self, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionTitleBar_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'text' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'text', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->text;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionTitleBar_get_titleBarState(PyObject* self, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->titleBarState;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTitleBar_set_titleBarState(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTitleBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTitleBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'titleBarState' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'titleBarState', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->titleBarState;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->titleBarState = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionTitleBar
static PyGetSetDef Sbk_QStyleOptionTitleBar_getsetlist[] = {
    {const_cast<char*>("titleBarFlags"), Sbk_QStyleOptionTitleBar_get_titleBarFlags, Sbk_QStyleOptionTitleBar_set_titleBarFlags},
    {const_cast<char*>("icon"), Sbk_QStyleOptionTitleBar_get_icon, Sbk_QStyleOptionTitleBar_set_icon},
    {const_cast<char*>("text"), Sbk_QStyleOptionTitleBar_get_text, Sbk_QStyleOptionTitleBar_set_text},
    {const_cast<char*>("titleBarState"), Sbk_QStyleOptionTitleBar_get_titleBarState, Sbk_QStyleOptionTitleBar_set_titleBarState},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionTitleBar_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionTitleBar_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionTitleBar_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionTitleBar",
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
    /*tp_traverse*/         Sbk_QStyleOptionTitleBar_traverse,
    /*tp_clear*/            Sbk_QStyleOptionTitleBar_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionTitleBar_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionTitleBar_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionTitleBar_Init,
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
static void QStyleOptionTitleBar_StyleOptionType_PythonToCpp_QStyleOptionTitleBar_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTitleBar::StyleOptionType*)cppOut) = (::QStyleOptionTitleBar::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTitleBar_StyleOptionType_PythonToCpp_QStyleOptionTitleBar_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionTitleBar_StyleOptionType_PythonToCpp_QStyleOptionTitleBar_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionTitleBar_StyleOptionType_CppToPython_QStyleOptionTitleBar_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTitleBar::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionTitleBar_StyleOptionVersion_PythonToCpp_QStyleOptionTitleBar_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTitleBar::StyleOptionVersion*)cppOut) = (::QStyleOptionTitleBar::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTitleBar_StyleOptionVersion_PythonToCpp_QStyleOptionTitleBar_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionTitleBar_StyleOptionVersion_PythonToCpp_QStyleOptionTitleBar_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionTitleBar_StyleOptionVersion_CppToPython_QStyleOptionTitleBar_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTitleBar::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionTitleBar_PythonToCpp_QStyleOptionTitleBar_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionTitleBar_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionTitleBar_PythonToCpp_QStyleOptionTitleBar_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionTitleBar_Type))
        return QStyleOptionTitleBar_PythonToCpp_QStyleOptionTitleBar_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionTitleBar_PTR_CppToPython_QStyleOptionTitleBar(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionTitleBar*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionTitleBar_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionTitleBar(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionTitleBar_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionTitleBar", "QStyleOptionTitleBar*",
        &Sbk_QStyleOptionTitleBar_Type, &Shiboken::callCppDestructor< ::QStyleOptionTitleBar >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionTitleBar_Type,
        QStyleOptionTitleBar_PythonToCpp_QStyleOptionTitleBar_PTR,
        is_QStyleOptionTitleBar_PythonToCpp_QStyleOptionTitleBar_PTR_Convertible,
        QStyleOptionTitleBar_PTR_CppToPython_QStyleOptionTitleBar);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTitleBar");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTitleBar*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTitleBar&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionTitleBar).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTitleBar_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionTitleBar.StyleOptionType",
        "QStyleOptionTitleBar::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionTitleBar_Type, "Type", (long) QStyleOptionTitleBar::Type))
        return ;
    // Register converter for enum 'QStyleOptionTitleBar::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX],
            QStyleOptionTitleBar_StyleOptionType_CppToPython_QStyleOptionTitleBar_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTitleBar_StyleOptionType_PythonToCpp_QStyleOptionTitleBar_StyleOptionType,
            is_QStyleOptionTitleBar_StyleOptionType_PythonToCpp_QStyleOptionTitleBar_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTitleBar::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTitleBar_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionTitleBar.StyleOptionVersion",
        "QStyleOptionTitleBar::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionTitleBar_Type, "Version", (long) QStyleOptionTitleBar::Version))
        return ;
    // Register converter for enum 'QStyleOptionTitleBar::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX],
            QStyleOptionTitleBar_StyleOptionVersion_CppToPython_QStyleOptionTitleBar_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTitleBar_StyleOptionVersion_PythonToCpp_QStyleOptionTitleBar_StyleOptionVersion,
            is_QStyleOptionTitleBar_StyleOptionVersion_PythonToCpp_QStyleOptionTitleBar_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTITLEBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTitleBar::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionTitleBar::StyleOptionType >("QStyleOptionTitleBar::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionTitleBar::StyleOptionVersion >("QStyleOptionTitleBar::StyleOptionVersion");
}
