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

#include "qstyleoptionbutton_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionButton_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionButton >()))
        return -1;

    ::QStyleOptionButton* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionButton", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionButton()
    // 1: QStyleOptionButton(QStyleOptionButton)
    // 2: QStyleOptionButton(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionButton()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionButton(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionButton(QStyleOptionButton)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionButton_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionButton()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionButton()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionButton();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionButton(const QStyleOptionButton & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionButton* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionButton(QStyleOptionButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionButton(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionButton(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionButton(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionButton >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionButton_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionButton_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionButton", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionButton", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionButton_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionButton_get_iconSize(PyObject* self, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->iconSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionButton_set_iconSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionButton_get_features(PyObject* self, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionButton_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'features' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'features', 'ButtonFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionButton::ButtonFeature> cppOut_local = cppSelf->features;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->features = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionButton_get_icon(PyObject* self, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionButton_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionButton_get_text(PyObject* self, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionButton_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX], (SbkObject*)self));
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

// Getters and Setters for QStyleOptionButton
static PyGetSetDef Sbk_QStyleOptionButton_getsetlist[] = {
    {const_cast<char*>("iconSize"), Sbk_QStyleOptionButton_get_iconSize, Sbk_QStyleOptionButton_set_iconSize},
    {const_cast<char*>("features"), Sbk_QStyleOptionButton_get_features, Sbk_QStyleOptionButton_set_features},
    {const_cast<char*>("icon"), Sbk_QStyleOptionButton_get_icon, Sbk_QStyleOptionButton_set_icon},
    {const_cast<char*>("text"), Sbk_QStyleOptionButton_get_text, Sbk_QStyleOptionButton_set_text},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionButton_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionButton_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionButton_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionButton",
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
    /*tp_traverse*/         Sbk_QStyleOptionButton_traverse,
    /*tp_clear*/            Sbk_QStyleOptionButton_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionButton_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionButton_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionButton_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionButton::ButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionButton::ButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionButton::ButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionButton::ButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionButton::ButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionButton::ButtonFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), self, &cppSelf);
    ::QStyleOptionButton::ButtonFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionButton_ButtonFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionButton_ButtonFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionButton_ButtonFeature_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionButton_ButtonFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionButton_ButtonFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionButton_ButtonFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionButton_ButtonFeature_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QStyleOptionButton_StyleOptionType_PythonToCpp_QStyleOptionButton_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionButton::StyleOptionType*)cppOut) = (::QStyleOptionButton::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionButton_StyleOptionType_PythonToCpp_QStyleOptionButton_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionButton_StyleOptionType_PythonToCpp_QStyleOptionButton_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionButton_StyleOptionType_CppToPython_QStyleOptionButton_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionButton::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionButton_StyleOptionVersion_PythonToCpp_QStyleOptionButton_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionButton::StyleOptionVersion*)cppOut) = (::QStyleOptionButton::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionButton_StyleOptionVersion_PythonToCpp_QStyleOptionButton_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionButton_StyleOptionVersion_PythonToCpp_QStyleOptionButton_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionButton_StyleOptionVersion_CppToPython_QStyleOptionButton_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionButton::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionButton_ButtonFeature_PythonToCpp_QStyleOptionButton_ButtonFeature(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionButton::ButtonFeature*)cppOut) = (::QStyleOptionButton::ButtonFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionButton_ButtonFeature_PythonToCpp_QStyleOptionButton_ButtonFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX]))
        return QStyleOptionButton_ButtonFeature_PythonToCpp_QStyleOptionButton_ButtonFeature;
    return 0;
}
static PyObject* QStyleOptionButton_ButtonFeature_CppToPython_QStyleOptionButton_ButtonFeature(const void* cppIn) {
    int castCppIn = *((::QStyleOptionButton::ButtonFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX], castCppIn);

}

static void QFlags_QStyleOptionButton_ButtonFeature__PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionButton::ButtonFeature>*)cppOut) = ::QFlags<QStyleOptionButton::ButtonFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionButton_ButtonFeature__PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]))
        return QFlags_QStyleOptionButton_ButtonFeature__PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_;
    return 0;
}
static PyObject* QFlags_QStyleOptionButton_ButtonFeature__CppToPython_QFlags_QStyleOptionButton_ButtonFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionButton::ButtonFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]));

}

static void QStyleOptionButton_ButtonFeature_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionButton::ButtonFeature>*)cppOut) = ::QFlags<QStyleOptionButton::ButtonFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionButton_ButtonFeature_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX]))
        return QStyleOptionButton_ButtonFeature_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionButton::ButtonFeature>*)cppOut) = ::QFlags<QStyleOptionButton::ButtonFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionButton_PythonToCpp_QStyleOptionButton_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionButton_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionButton_PythonToCpp_QStyleOptionButton_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionButton_Type))
        return QStyleOptionButton_PythonToCpp_QStyleOptionButton_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionButton_PTR_CppToPython_QStyleOptionButton(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionButton*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionButton_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionButton(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionButton_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionButton", "QStyleOptionButton*",
        &Sbk_QStyleOptionButton_Type, &Shiboken::callCppDestructor< ::QStyleOptionButton >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionButton_Type,
        QStyleOptionButton_PythonToCpp_QStyleOptionButton_PTR,
        is_QStyleOptionButton_PythonToCpp_QStyleOptionButton_PTR_Convertible,
        QStyleOptionButton_PTR_CppToPython_QStyleOptionButton);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionButton).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionButton_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionButton.StyleOptionType",
        "QStyleOptionButton::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionButton_Type, "Type", (long) QStyleOptionButton::Type))
        return ;
    // Register converter for enum 'QStyleOptionButton::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX],
            QStyleOptionButton_StyleOptionType_CppToPython_QStyleOptionButton_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionButton_StyleOptionType_PythonToCpp_QStyleOptionButton_StyleOptionType,
            is_QStyleOptionButton_StyleOptionType_PythonToCpp_QStyleOptionButton_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionButton_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionButton.StyleOptionVersion",
        "QStyleOptionButton::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionButton_Type, "Version", (long) QStyleOptionButton::Version))
        return ;
    // Register converter for enum 'QStyleOptionButton::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX],
            QStyleOptionButton_StyleOptionVersion_CppToPython_QStyleOptionButton_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionButton_StyleOptionVersion_PythonToCpp_QStyleOptionButton_StyleOptionVersion,
            is_QStyleOptionButton_StyleOptionVersion_PythonToCpp_QStyleOptionButton_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'ButtonFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX] = PySide::QFlags::create("ButtonFeatures", &SbkPySide_QtGui_QStyleOptionButton_ButtonFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionButton_Type,
        "ButtonFeature",
        "PySide.QtGui.QStyleOptionButton.ButtonFeature",
        "QStyleOptionButton::ButtonFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "None", (long) QStyleOptionButton::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "Flat", (long) QStyleOptionButton::Flat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "HasMenu", (long) QStyleOptionButton::HasMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "DefaultButton", (long) QStyleOptionButton::DefaultButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "AutoDefaultButton", (long) QStyleOptionButton::AutoDefaultButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
        &Sbk_QStyleOptionButton_Type, "CommandLinkButton", (long) QStyleOptionButton::CommandLinkButton))
        return ;
    // Register converter for enum 'QStyleOptionButton::ButtonFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX],
            QStyleOptionButton_ButtonFeature_CppToPython_QStyleOptionButton_ButtonFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionButton_ButtonFeature_PythonToCpp_QStyleOptionButton_ButtonFeature,
            is_QStyleOptionButton_ButtonFeature_PythonToCpp_QStyleOptionButton_ButtonFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONBUTTON_BUTTONFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionButton::ButtonFeature");
        Shiboken::Conversions::registerConverterName(converter, "ButtonFeature");
    }
    // Register converter for flag 'QFlags<QStyleOptionButton::ButtonFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX],
            QFlags_QStyleOptionButton_ButtonFeature__CppToPython_QFlags_QStyleOptionButton_ButtonFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionButton_ButtonFeature_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_,
            is_QStyleOptionButton_ButtonFeature_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionButton_ButtonFeature__PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_,
            is_QFlags_QStyleOptionButton_ButtonFeature__PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature_,
            is_number_PythonToCpp_QFlags_QStyleOptionButton_ButtonFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONBUTTON_BUTTONFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionButton::ButtonFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ButtonFeature>");
    }
    // End of 'ButtonFeature' enum/flags.


    qRegisterMetaType< ::QStyleOptionButton::StyleOptionType >("QStyleOptionButton::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionButton::StyleOptionVersion >("QStyleOptionButton::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionButton::ButtonFeature >("QStyleOptionButton::ButtonFeature");
    qRegisterMetaType< ::QStyleOptionButton::ButtonFeatures >("QStyleOptionButton::ButtonFeatures");
}
