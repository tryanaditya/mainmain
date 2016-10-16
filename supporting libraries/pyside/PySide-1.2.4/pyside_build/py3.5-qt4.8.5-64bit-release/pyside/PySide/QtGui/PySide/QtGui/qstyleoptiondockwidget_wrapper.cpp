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

#include "qstyleoptiondockwidget_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionDockWidget_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionDockWidget >()))
        return -1;

    ::QStyleOptionDockWidget* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionDockWidget", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionDockWidget()
    // 1: QStyleOptionDockWidget(QStyleOptionDockWidget)
    // 2: QStyleOptionDockWidget(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionDockWidget()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionDockWidget(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionDockWidget(QStyleOptionDockWidget)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionDockWidget_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionDockWidget()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionDockWidget()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionDockWidget();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionDockWidget(const QStyleOptionDockWidget & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionDockWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionDockWidget(QStyleOptionDockWidget)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionDockWidget(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionDockWidget(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionDockWidget(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionDockWidget(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionDockWidget >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionDockWidget_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionDockWidget_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionDockWidget", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionDockWidget", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionDockWidget_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionDockWidget_get_title(PyObject* self, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->title);
    return pyOut;
}
static int Sbk_QStyleOptionDockWidget_set_title(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'title' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'title', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->title;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionDockWidget_get_floatable(PyObject* self, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->floatable;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionDockWidget_set_floatable(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'floatable' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'floatable', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->floatable;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->floatable = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionDockWidget_get_closable(PyObject* self, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->closable;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionDockWidget_set_closable(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'closable' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'closable', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->closable;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->closable = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionDockWidget_get_movable(PyObject* self, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->movable;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionDockWidget_set_movable(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionDockWidget* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionDockWidget*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'movable' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'movable', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->movable;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->movable = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionDockWidget
static PyGetSetDef Sbk_QStyleOptionDockWidget_getsetlist[] = {
    {const_cast<char*>("title"), Sbk_QStyleOptionDockWidget_get_title, Sbk_QStyleOptionDockWidget_set_title},
    {const_cast<char*>("floatable"), Sbk_QStyleOptionDockWidget_get_floatable, Sbk_QStyleOptionDockWidget_set_floatable},
    {const_cast<char*>("closable"), Sbk_QStyleOptionDockWidget_get_closable, Sbk_QStyleOptionDockWidget_set_closable},
    {const_cast<char*>("movable"), Sbk_QStyleOptionDockWidget_get_movable, Sbk_QStyleOptionDockWidget_set_movable},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionDockWidget_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionDockWidget_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionDockWidget_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionDockWidget",
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
    /*tp_traverse*/         Sbk_QStyleOptionDockWidget_traverse,
    /*tp_clear*/            Sbk_QStyleOptionDockWidget_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionDockWidget_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionDockWidget_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionDockWidget_Init,
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
static void QStyleOptionDockWidget_StyleOptionType_PythonToCpp_QStyleOptionDockWidget_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionDockWidget::StyleOptionType*)cppOut) = (::QStyleOptionDockWidget::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionDockWidget_StyleOptionType_PythonToCpp_QStyleOptionDockWidget_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionDockWidget_StyleOptionType_PythonToCpp_QStyleOptionDockWidget_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionDockWidget_StyleOptionType_CppToPython_QStyleOptionDockWidget_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionDockWidget::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionDockWidget_StyleOptionVersion_PythonToCpp_QStyleOptionDockWidget_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionDockWidget::StyleOptionVersion*)cppOut) = (::QStyleOptionDockWidget::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionDockWidget_StyleOptionVersion_PythonToCpp_QStyleOptionDockWidget_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionDockWidget_StyleOptionVersion_PythonToCpp_QStyleOptionDockWidget_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionDockWidget_StyleOptionVersion_CppToPython_QStyleOptionDockWidget_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionDockWidget::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionDockWidget_PythonToCpp_QStyleOptionDockWidget_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionDockWidget_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionDockWidget_PythonToCpp_QStyleOptionDockWidget_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionDockWidget_Type))
        return QStyleOptionDockWidget_PythonToCpp_QStyleOptionDockWidget_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionDockWidget_PTR_CppToPython_QStyleOptionDockWidget(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionDockWidget*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionDockWidget_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionDockWidget(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionDockWidget_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionDockWidget", "QStyleOptionDockWidget*",
        &Sbk_QStyleOptionDockWidget_Type, &Shiboken::callCppDestructor< ::QStyleOptionDockWidget >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionDockWidget_Type,
        QStyleOptionDockWidget_PythonToCpp_QStyleOptionDockWidget_PTR,
        is_QStyleOptionDockWidget_PythonToCpp_QStyleOptionDockWidget_PTR_Convertible,
        QStyleOptionDockWidget_PTR_CppToPython_QStyleOptionDockWidget);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionDockWidget");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionDockWidget*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionDockWidget&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionDockWidget).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionDockWidget_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionDockWidget.StyleOptionType",
        "QStyleOptionDockWidget::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionDockWidget_Type, "Type", (long) QStyleOptionDockWidget::Type))
        return ;
    // Register converter for enum 'QStyleOptionDockWidget::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX],
            QStyleOptionDockWidget_StyleOptionType_CppToPython_QStyleOptionDockWidget_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionDockWidget_StyleOptionType_PythonToCpp_QStyleOptionDockWidget_StyleOptionType,
            is_QStyleOptionDockWidget_StyleOptionType_PythonToCpp_QStyleOptionDockWidget_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionDockWidget::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionDockWidget_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionDockWidget.StyleOptionVersion",
        "QStyleOptionDockWidget::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionDockWidget_Type, "Version", (long) QStyleOptionDockWidget::Version))
        return ;
    // Register converter for enum 'QStyleOptionDockWidget::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX],
            QStyleOptionDockWidget_StyleOptionVersion_CppToPython_QStyleOptionDockWidget_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionDockWidget_StyleOptionVersion_PythonToCpp_QStyleOptionDockWidget_StyleOptionVersion,
            is_QStyleOptionDockWidget_StyleOptionVersion_PythonToCpp_QStyleOptionDockWidget_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONDOCKWIDGET_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionDockWidget::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionDockWidget::StyleOptionType >("QStyleOptionDockWidget::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionDockWidget::StyleOptionVersion >("QStyleOptionDockWidget::StyleOptionVersion");
}
