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

#include "qstyleoptionprogressbar_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionProgressBar_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionProgressBar >()))
        return -1;

    ::QStyleOptionProgressBar* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionProgressBar", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionProgressBar()
    // 1: QStyleOptionProgressBar(QStyleOptionProgressBar)
    // 2: QStyleOptionProgressBar(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionProgressBar()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionProgressBar(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionProgressBar(QStyleOptionProgressBar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionProgressBar_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionProgressBar()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBar()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBar();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionProgressBar(const QStyleOptionProgressBar & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionProgressBar* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBar(QStyleOptionProgressBar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBar(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionProgressBar(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBar(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBar(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionProgressBar >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionProgressBar_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionProgressBar_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionProgressBar", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionProgressBar", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionProgressBar_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionProgressBar_get_minimum(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->minimum;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_minimum(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'minimum' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'minimum', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->minimum;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->minimum = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBar_get_maximum(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->maximum;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_maximum(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'maximum' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'maximum', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->maximum;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->maximum = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBar_get_progress(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->progress;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_progress(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'progress' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'progress', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->progress;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->progress = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBar_get_textAlignment(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->textAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_textAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'textAlignment' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'textAlignment', 'Alignment' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::AlignmentFlag> cppOut_local = cppSelf->textAlignment;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->textAlignment = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBar_get_text(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionProgressBar_get_textVisible(PyObject* self, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->textVisible;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBar_set_textVisible(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'textVisible' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'textVisible', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->textVisible;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->textVisible = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionProgressBar
static PyGetSetDef Sbk_QStyleOptionProgressBar_getsetlist[] = {
    {const_cast<char*>("minimum"), Sbk_QStyleOptionProgressBar_get_minimum, Sbk_QStyleOptionProgressBar_set_minimum},
    {const_cast<char*>("maximum"), Sbk_QStyleOptionProgressBar_get_maximum, Sbk_QStyleOptionProgressBar_set_maximum},
    {const_cast<char*>("progress"), Sbk_QStyleOptionProgressBar_get_progress, Sbk_QStyleOptionProgressBar_set_progress},
    {const_cast<char*>("textAlignment"), Sbk_QStyleOptionProgressBar_get_textAlignment, Sbk_QStyleOptionProgressBar_set_textAlignment},
    {const_cast<char*>("text"), Sbk_QStyleOptionProgressBar_get_text, Sbk_QStyleOptionProgressBar_set_text},
    {const_cast<char*>("textVisible"), Sbk_QStyleOptionProgressBar_get_textVisible, Sbk_QStyleOptionProgressBar_set_textVisible},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionProgressBar_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionProgressBar_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionProgressBar_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionProgressBar",
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
    /*tp_traverse*/         Sbk_QStyleOptionProgressBar_traverse,
    /*tp_clear*/            Sbk_QStyleOptionProgressBar_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionProgressBar_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionProgressBar_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionProgressBar_Init,
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
static void QStyleOptionProgressBar_StyleOptionType_PythonToCpp_QStyleOptionProgressBar_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionProgressBar::StyleOptionType*)cppOut) = (::QStyleOptionProgressBar::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionProgressBar_StyleOptionType_PythonToCpp_QStyleOptionProgressBar_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionProgressBar_StyleOptionType_PythonToCpp_QStyleOptionProgressBar_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionProgressBar_StyleOptionType_CppToPython_QStyleOptionProgressBar_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionProgressBar::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionProgressBar_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBar_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionProgressBar::StyleOptionVersion*)cppOut) = (::QStyleOptionProgressBar::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionProgressBar_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBar_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionProgressBar_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBar_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionProgressBar_StyleOptionVersion_CppToPython_QStyleOptionProgressBar_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionProgressBar::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionProgressBar_PythonToCpp_QStyleOptionProgressBar_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionProgressBar_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionProgressBar_PythonToCpp_QStyleOptionProgressBar_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionProgressBar_Type))
        return QStyleOptionProgressBar_PythonToCpp_QStyleOptionProgressBar_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionProgressBar_PTR_CppToPython_QStyleOptionProgressBar(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionProgressBar*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionProgressBar_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionProgressBar(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionProgressBar_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionProgressBar", "QStyleOptionProgressBar*",
        &Sbk_QStyleOptionProgressBar_Type, &Shiboken::callCppDestructor< ::QStyleOptionProgressBar >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionProgressBar_Type,
        QStyleOptionProgressBar_PythonToCpp_QStyleOptionProgressBar_PTR,
        is_QStyleOptionProgressBar_PythonToCpp_QStyleOptionProgressBar_PTR_Convertible,
        QStyleOptionProgressBar_PTR_CppToPython_QStyleOptionProgressBar);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBar");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBar*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBar&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionProgressBar).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionProgressBar_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionProgressBar.StyleOptionType",
        "QStyleOptionProgressBar::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionProgressBar_Type, "Type", (long) QStyleOptionProgressBar::Type))
        return ;
    // Register converter for enum 'QStyleOptionProgressBar::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX],
            QStyleOptionProgressBar_StyleOptionType_CppToPython_QStyleOptionProgressBar_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionProgressBar_StyleOptionType_PythonToCpp_QStyleOptionProgressBar_StyleOptionType,
            is_QStyleOptionProgressBar_StyleOptionType_PythonToCpp_QStyleOptionProgressBar_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBar::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionProgressBar_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionProgressBar.StyleOptionVersion",
        "QStyleOptionProgressBar::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionProgressBar_Type, "Version", (long) QStyleOptionProgressBar::Version))
        return ;
    // Register converter for enum 'QStyleOptionProgressBar::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX],
            QStyleOptionProgressBar_StyleOptionVersion_CppToPython_QStyleOptionProgressBar_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionProgressBar_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBar_StyleOptionVersion,
            is_QStyleOptionProgressBar_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBar_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBar::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionProgressBar::StyleOptionType >("QStyleOptionProgressBar::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionProgressBar::StyleOptionVersion >("QStyleOptionProgressBar::StyleOptionVersion");
}
