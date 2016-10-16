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

#include "qstyleoptiongroupbox_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionGroupBox_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionGroupBox >()))
        return -1;

    ::QStyleOptionGroupBox* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionGroupBox", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionGroupBox()
    // 1: QStyleOptionGroupBox(QStyleOptionGroupBox)
    // 2: QStyleOptionGroupBox(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionGroupBox()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionGroupBox(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionGroupBox(QStyleOptionGroupBox)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionGroupBox_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionGroupBox()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionGroupBox()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGroupBox();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionGroupBox(const QStyleOptionGroupBox & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionGroupBox* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionGroupBox(QStyleOptionGroupBox)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGroupBox(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionGroupBox(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionGroupBox(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGroupBox(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionGroupBox >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionGroupBox_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionGroupBox_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionGroupBox", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionGroupBox", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionGroupBox_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionGroupBox_get_lineWidth(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->lineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_lineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'lineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'lineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->lineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->lineWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionGroupBox_get_features(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'features' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'features', 'FrameFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionFrameV2::FrameFeature> cppOut_local = cppSelf->features;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->features = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionGroupBox_get_textAlignment(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->textAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_textAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionGroupBox_get_midLineWidth(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->midLineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_midLineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'midLineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'midLineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->midLineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->midLineWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionGroupBox_get_text(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionGroupBox_get_textColor(PyObject* self, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &(cppSelf->textColor), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionGroupBox_set_textColor(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGroupBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGroupBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'textColor' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'textColor', 'QColor' or convertible type expected");
        return -1;
    }

    ::QColor& cppOut_ptr = cppSelf->textColor;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionGroupBox
static PyGetSetDef Sbk_QStyleOptionGroupBox_getsetlist[] = {
    {const_cast<char*>("lineWidth"), Sbk_QStyleOptionGroupBox_get_lineWidth, Sbk_QStyleOptionGroupBox_set_lineWidth},
    {const_cast<char*>("features"), Sbk_QStyleOptionGroupBox_get_features, Sbk_QStyleOptionGroupBox_set_features},
    {const_cast<char*>("textAlignment"), Sbk_QStyleOptionGroupBox_get_textAlignment, Sbk_QStyleOptionGroupBox_set_textAlignment},
    {const_cast<char*>("midLineWidth"), Sbk_QStyleOptionGroupBox_get_midLineWidth, Sbk_QStyleOptionGroupBox_set_midLineWidth},
    {const_cast<char*>("text"), Sbk_QStyleOptionGroupBox_get_text, Sbk_QStyleOptionGroupBox_set_text},
    {const_cast<char*>("textColor"), Sbk_QStyleOptionGroupBox_get_textColor, Sbk_QStyleOptionGroupBox_set_textColor},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionGroupBox_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionGroupBox_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionGroupBox_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionGroupBox",
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
    /*tp_traverse*/         Sbk_QStyleOptionGroupBox_traverse,
    /*tp_clear*/            Sbk_QStyleOptionGroupBox_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionGroupBox_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionGroupBox_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionGroupBox_Init,
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
static void QStyleOptionGroupBox_StyleOptionType_PythonToCpp_QStyleOptionGroupBox_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionGroupBox::StyleOptionType*)cppOut) = (::QStyleOptionGroupBox::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionGroupBox_StyleOptionType_PythonToCpp_QStyleOptionGroupBox_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionGroupBox_StyleOptionType_PythonToCpp_QStyleOptionGroupBox_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionGroupBox_StyleOptionType_CppToPython_QStyleOptionGroupBox_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionGroupBox::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionGroupBox_StyleOptionVersion_PythonToCpp_QStyleOptionGroupBox_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionGroupBox::StyleOptionVersion*)cppOut) = (::QStyleOptionGroupBox::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionGroupBox_StyleOptionVersion_PythonToCpp_QStyleOptionGroupBox_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionGroupBox_StyleOptionVersion_PythonToCpp_QStyleOptionGroupBox_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionGroupBox_StyleOptionVersion_CppToPython_QStyleOptionGroupBox_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionGroupBox::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionGroupBox_PythonToCpp_QStyleOptionGroupBox_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionGroupBox_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionGroupBox_PythonToCpp_QStyleOptionGroupBox_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionGroupBox_Type))
        return QStyleOptionGroupBox_PythonToCpp_QStyleOptionGroupBox_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionGroupBox_PTR_CppToPython_QStyleOptionGroupBox(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionGroupBox*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionGroupBox_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionGroupBox(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionGroupBox_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionGroupBox", "QStyleOptionGroupBox*",
        &Sbk_QStyleOptionGroupBox_Type, &Shiboken::callCppDestructor< ::QStyleOptionGroupBox >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionGroupBox_Type,
        QStyleOptionGroupBox_PythonToCpp_QStyleOptionGroupBox_PTR,
        is_QStyleOptionGroupBox_PythonToCpp_QStyleOptionGroupBox_PTR_Convertible,
        QStyleOptionGroupBox_PTR_CppToPython_QStyleOptionGroupBox);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGroupBox");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGroupBox*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGroupBox&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionGroupBox).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionGroupBox_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionGroupBox.StyleOptionType",
        "QStyleOptionGroupBox::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionGroupBox_Type, "Type", (long) QStyleOptionGroupBox::Type))
        return ;
    // Register converter for enum 'QStyleOptionGroupBox::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX],
            QStyleOptionGroupBox_StyleOptionType_CppToPython_QStyleOptionGroupBox_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionGroupBox_StyleOptionType_PythonToCpp_QStyleOptionGroupBox_StyleOptionType,
            is_QStyleOptionGroupBox_StyleOptionType_PythonToCpp_QStyleOptionGroupBox_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGroupBox::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionGroupBox_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionGroupBox.StyleOptionVersion",
        "QStyleOptionGroupBox::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionGroupBox_Type, "Version", (long) QStyleOptionGroupBox::Version))
        return ;
    // Register converter for enum 'QStyleOptionGroupBox::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX],
            QStyleOptionGroupBox_StyleOptionVersion_CppToPython_QStyleOptionGroupBox_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionGroupBox_StyleOptionVersion_PythonToCpp_QStyleOptionGroupBox_StyleOptionVersion,
            is_QStyleOptionGroupBox_StyleOptionVersion_PythonToCpp_QStyleOptionGroupBox_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGROUPBOX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGroupBox::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionGroupBox::StyleOptionType >("QStyleOptionGroupBox::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionGroupBox::StyleOptionVersion >("QStyleOptionGroupBox::StyleOptionVersion");
}
