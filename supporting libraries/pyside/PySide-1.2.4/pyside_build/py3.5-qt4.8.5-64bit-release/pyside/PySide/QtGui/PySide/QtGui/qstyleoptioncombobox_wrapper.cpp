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

#include "qstyleoptioncombobox_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionComboBox_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionComboBox >()))
        return -1;

    ::QStyleOptionComboBox* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionComboBox", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionComboBox()
    // 1: QStyleOptionComboBox(QStyleOptionComboBox)
    // 2: QStyleOptionComboBox(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionComboBox()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionComboBox(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionComboBox(QStyleOptionComboBox)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionComboBox_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionComboBox()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionComboBox()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionComboBox();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionComboBox(const QStyleOptionComboBox & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionComboBox* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionComboBox(QStyleOptionComboBox)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionComboBox(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionComboBox(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionComboBox(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionComboBox(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionComboBox >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionComboBox_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionComboBox_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionComboBox", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionComboBox", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionComboBox_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionComboBox_get_currentText(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->currentText);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_currentText(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'currentText' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'currentText', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->currentText;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionComboBox_get_iconSize(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->iconSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_iconSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'iconSize' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'iconSize', 'QSize' or convertible type expected");
        return -1;
    }

    ::QSize& cppOut_ptr = cppSelf->iconSize;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionComboBox_get_editable(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->editable;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_editable(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'editable' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'editable', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->editable;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->editable = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionComboBox_get_frame(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->frame;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_frame(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'frame' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'frame', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->frame;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->frame = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionComboBox_get_popupRect(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &(cppSelf->popupRect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_popupRect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'popupRect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'popupRect', 'QRect' or convertible type expected");
        return -1;
    }

    ::QRect& cppOut_ptr = cppSelf->popupRect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionComboBox_get_currentIcon(PyObject* self, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->currentIcon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionComboBox_set_currentIcon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComboBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComboBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'currentIcon' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'currentIcon', 'QIcon' or convertible type expected");
        return -1;
    }

    ::QIcon& cppOut_ptr = cppSelf->currentIcon;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionComboBox
static PyGetSetDef Sbk_QStyleOptionComboBox_getsetlist[] = {
    {const_cast<char*>("currentText"), Sbk_QStyleOptionComboBox_get_currentText, Sbk_QStyleOptionComboBox_set_currentText},
    {const_cast<char*>("iconSize"), Sbk_QStyleOptionComboBox_get_iconSize, Sbk_QStyleOptionComboBox_set_iconSize},
    {const_cast<char*>("editable"), Sbk_QStyleOptionComboBox_get_editable, Sbk_QStyleOptionComboBox_set_editable},
    {const_cast<char*>("frame"), Sbk_QStyleOptionComboBox_get_frame, Sbk_QStyleOptionComboBox_set_frame},
    {const_cast<char*>("popupRect"), Sbk_QStyleOptionComboBox_get_popupRect, Sbk_QStyleOptionComboBox_set_popupRect},
    {const_cast<char*>("currentIcon"), Sbk_QStyleOptionComboBox_get_currentIcon, Sbk_QStyleOptionComboBox_set_currentIcon},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionComboBox_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionComboBox_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionComboBox_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionComboBox",
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
    /*tp_traverse*/         Sbk_QStyleOptionComboBox_traverse,
    /*tp_clear*/            Sbk_QStyleOptionComboBox_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionComboBox_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionComboBox_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionComboBox_Init,
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
static void QStyleOptionComboBox_StyleOptionType_PythonToCpp_QStyleOptionComboBox_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionComboBox::StyleOptionType*)cppOut) = (::QStyleOptionComboBox::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionComboBox_StyleOptionType_PythonToCpp_QStyleOptionComboBox_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionComboBox_StyleOptionType_PythonToCpp_QStyleOptionComboBox_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionComboBox_StyleOptionType_CppToPython_QStyleOptionComboBox_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionComboBox::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionComboBox_StyleOptionVersion_PythonToCpp_QStyleOptionComboBox_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionComboBox::StyleOptionVersion*)cppOut) = (::QStyleOptionComboBox::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionComboBox_StyleOptionVersion_PythonToCpp_QStyleOptionComboBox_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionComboBox_StyleOptionVersion_PythonToCpp_QStyleOptionComboBox_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionComboBox_StyleOptionVersion_CppToPython_QStyleOptionComboBox_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionComboBox::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionComboBox_PythonToCpp_QStyleOptionComboBox_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionComboBox_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionComboBox_PythonToCpp_QStyleOptionComboBox_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionComboBox_Type))
        return QStyleOptionComboBox_PythonToCpp_QStyleOptionComboBox_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionComboBox_PTR_CppToPython_QStyleOptionComboBox(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionComboBox*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionComboBox_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionComboBox(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionComboBox_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionComboBox", "QStyleOptionComboBox*",
        &Sbk_QStyleOptionComboBox_Type, &Shiboken::callCppDestructor< ::QStyleOptionComboBox >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionComboBox_Type,
        QStyleOptionComboBox_PythonToCpp_QStyleOptionComboBox_PTR,
        is_QStyleOptionComboBox_PythonToCpp_QStyleOptionComboBox_PTR_Convertible,
        QStyleOptionComboBox_PTR_CppToPython_QStyleOptionComboBox);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComboBox");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComboBox*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComboBox&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionComboBox).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionComboBox_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionComboBox.StyleOptionType",
        "QStyleOptionComboBox::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionComboBox_Type, "Type", (long) QStyleOptionComboBox::Type))
        return ;
    // Register converter for enum 'QStyleOptionComboBox::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX],
            QStyleOptionComboBox_StyleOptionType_CppToPython_QStyleOptionComboBox_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionComboBox_StyleOptionType_PythonToCpp_QStyleOptionComboBox_StyleOptionType,
            is_QStyleOptionComboBox_StyleOptionType_PythonToCpp_QStyleOptionComboBox_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComboBox::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionComboBox_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionComboBox.StyleOptionVersion",
        "QStyleOptionComboBox::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionComboBox_Type, "Version", (long) QStyleOptionComboBox::Version))
        return ;
    // Register converter for enum 'QStyleOptionComboBox::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX],
            QStyleOptionComboBox_StyleOptionVersion_CppToPython_QStyleOptionComboBox_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionComboBox_StyleOptionVersion_PythonToCpp_QStyleOptionComboBox_StyleOptionVersion,
            is_QStyleOptionComboBox_StyleOptionVersion_PythonToCpp_QStyleOptionComboBox_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMBOBOX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComboBox::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionComboBox::StyleOptionType >("QStyleOptionComboBox::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionComboBox::StyleOptionVersion >("QStyleOptionComboBox::StyleOptionVersion");
}
