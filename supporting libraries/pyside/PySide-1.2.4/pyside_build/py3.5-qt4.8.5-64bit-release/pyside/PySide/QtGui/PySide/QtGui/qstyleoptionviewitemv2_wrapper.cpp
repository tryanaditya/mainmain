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

#include "qstyleoptionviewitemv2_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionViewItemV2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionViewItemV2 >()))
        return -1;

    ::QStyleOptionViewItemV2* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionViewItemV2", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionViewItemV2()
    // 1: QStyleOptionViewItemV2(QStyleOptionViewItem)
    // 2: QStyleOptionViewItemV2(QStyleOptionViewItemV2)
    // 3: QStyleOptionViewItemV2(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionViewItemV2()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionViewItemV2(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionViewItemV2(QStyleOptionViewItemV2)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionViewItemV2(QStyleOptionViewItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionViewItemV2_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionViewItemV2()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV2()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV2();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionViewItemV2(const QStyleOptionViewItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionViewItem cppArg0_local = ::QStyleOptionViewItem();
            ::QStyleOptionViewItem* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV2(QStyleOptionViewItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionViewItemV2(const QStyleOptionViewItemV2 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionViewItemV2 cppArg0_local = ::QStyleOptionViewItemV2();
            ::QStyleOptionViewItemV2* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV2(QStyleOptionViewItemV2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionViewItemV2(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV2(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV2(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionViewItemV2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionViewItemV2_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionViewItemV2_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionViewItem", "PySide.QtGui.QStyleOptionViewItemV2", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionViewItemV2", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionViewItemV2___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStyleOptionViewItemV2& cppSelf = *(((::QStyleOptionViewItemV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStyleOptionViewItemV2_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QStyleOptionViewItemV2___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionViewItemV2_get_features(PyObject* self, void*)
{
    ::QStyleOptionViewItemV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV2_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'features' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'features', 'ViewItemFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionViewItemV2::ViewItemFeature> cppOut_local = cppSelf->features;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->features = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionViewItemV2
static PyGetSetDef Sbk_QStyleOptionViewItemV2_getsetlist[] = {
    {const_cast<char*>("features"), Sbk_QStyleOptionViewItemV2_get_features, Sbk_QStyleOptionViewItemV2_set_features},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionViewItemV2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionViewItemV2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionViewItemV2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionViewItemV2",
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
    /*tp_traverse*/         Sbk_QStyleOptionViewItemV2_traverse,
    /*tp_clear*/            Sbk_QStyleOptionViewItemV2_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionViewItemV2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionViewItemV2_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionViewItemV2_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionViewItemV2::ViewItemFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionViewItemV2::ViewItemFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionViewItemV2::ViewItemFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionViewItemV2::ViewItemFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionViewItemV2::ViewItemFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), self, &cppSelf);
    ::QStyleOptionViewItemV2::ViewItemFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature_long,
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
static void QStyleOptionViewItemV2_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV2_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV2::StyleOptionVersion*)cppOut) = (::QStyleOptionViewItemV2::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItemV2_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV2_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionViewItemV2_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV2_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionViewItemV2_StyleOptionVersion_CppToPython_QStyleOptionViewItemV2_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItemV2::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QStyleOptionViewItemV2_ViewItemFeature(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV2::ViewItemFeature*)cppOut) = (::QStyleOptionViewItemV2::ViewItemFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QStyleOptionViewItemV2_ViewItemFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX]))
        return QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QStyleOptionViewItemV2_ViewItemFeature;
    return 0;
}
static PyObject* QStyleOptionViewItemV2_ViewItemFeature_CppToPython_QStyleOptionViewItemV2_ViewItemFeature(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItemV2::ViewItemFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX], castCppIn);

}

static void QFlags_QStyleOptionViewItemV2_ViewItemFeature__PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionViewItemV2::ViewItemFeature>*)cppOut) = ::QFlags<QStyleOptionViewItemV2::ViewItemFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionViewItemV2_ViewItemFeature__PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]))
        return QFlags_QStyleOptionViewItemV2_ViewItemFeature__PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_;
    return 0;
}
static PyObject* QFlags_QStyleOptionViewItemV2_ViewItemFeature__CppToPython_QFlags_QStyleOptionViewItemV2_ViewItemFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionViewItemV2::ViewItemFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]));

}

static void QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionViewItemV2::ViewItemFeature>*)cppOut) = ::QFlags<QStyleOptionViewItemV2::ViewItemFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX]))
        return QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionViewItemV2::ViewItemFeature>*)cppOut) = ::QFlags<QStyleOptionViewItemV2::ViewItemFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionViewItemV2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV2_Type))
        return QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionViewItemV2_PTR_CppToPython_QStyleOptionViewItemV2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionViewItemV2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QStyleOptionViewItemV2_COPY_CppToPython_QStyleOptionViewItemV2(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV2_Type, new ::QStyleOptionViewItemV2(*((::QStyleOptionViewItemV2*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV2*)cppOut) = *((::QStyleOptionViewItemV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV2_Type))
        return QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_COPY;
    return 0;
}

// Implicit conversions.
static void constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV2(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV2*)cppOut) = ::QStyleOptionViewItemV2(*((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV2_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pyIn))
        return constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV2;
    return 0;
}

void init_QStyleOptionViewItemV2(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionViewItemV2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionViewItemV2", "QStyleOptionViewItemV2",
        &Sbk_QStyleOptionViewItemV2_Type, &Shiboken::callCppDestructor< ::QStyleOptionViewItemV2 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionViewItemV2_Type,
        QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_PTR,
        is_QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_PTR_Convertible,
        QStyleOptionViewItemV2_PTR_CppToPython_QStyleOptionViewItemV2,
        QStyleOptionViewItemV2_COPY_CppToPython_QStyleOptionViewItemV2);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV2");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV2*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionViewItemV2).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_COPY,
        is_QStyleOptionViewItemV2_PythonToCpp_QStyleOptionViewItemV2_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV2,
        is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV2_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItemV2_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionViewItemV2.StyleOptionVersion",
        "QStyleOptionViewItemV2::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "Version", (long) QStyleOptionViewItemV2::Version))
        return ;
    // Register converter for enum 'QStyleOptionViewItemV2::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX],
            QStyleOptionViewItemV2_StyleOptionVersion_CppToPython_QStyleOptionViewItemV2_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV2_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV2_StyleOptionVersion,
            is_QStyleOptionViewItemV2_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV2_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV2::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'ViewItemFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX] = PySide::QFlags::create("ViewItemFeatures", &SbkPySide_QtGui_QStyleOptionViewItemV2_ViewItemFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItemV2_Type,
        "ViewItemFeature",
        "PySide.QtGui.QStyleOptionViewItemV2.ViewItemFeature",
        "QStyleOptionViewItemV2::ViewItemFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "None", (long) QStyleOptionViewItemV2::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "WrapText", (long) QStyleOptionViewItemV2::WrapText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "Alternate", (long) QStyleOptionViewItemV2::Alternate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "HasCheckIndicator", (long) QStyleOptionViewItemV2::HasCheckIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "HasDisplay", (long) QStyleOptionViewItemV2::HasDisplay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
        &Sbk_QStyleOptionViewItemV2_Type, "HasDecoration", (long) QStyleOptionViewItemV2::HasDecoration))
        return ;
    // Register converter for enum 'QStyleOptionViewItemV2::ViewItemFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX],
            QStyleOptionViewItemV2_ViewItemFeature_CppToPython_QStyleOptionViewItemV2_ViewItemFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QStyleOptionViewItemV2_ViewItemFeature,
            is_QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QStyleOptionViewItemV2_ViewItemFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV2::ViewItemFeature");
        Shiboken::Conversions::registerConverterName(converter, "ViewItemFeature");
    }
    // Register converter for flag 'QFlags<QStyleOptionViewItemV2::ViewItemFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX],
            QFlags_QStyleOptionViewItemV2_ViewItemFeature__CppToPython_QFlags_QStyleOptionViewItemV2_ViewItemFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_,
            is_QStyleOptionViewItemV2_ViewItemFeature_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionViewItemV2_ViewItemFeature__PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_,
            is_QFlags_QStyleOptionViewItemV2_ViewItemFeature__PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature_,
            is_number_PythonToCpp_QFlags_QStyleOptionViewItemV2_ViewItemFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONVIEWITEMV2_VIEWITEMFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionViewItemV2::ViewItemFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ViewItemFeature>");
    }
    // End of 'ViewItemFeature' enum/flags.


    qRegisterMetaType< ::QStyleOptionViewItemV2 >("QStyleOptionViewItemV2");
    qRegisterMetaType< ::QStyleOptionViewItemV2::StyleOptionVersion >("QStyleOptionViewItemV2::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionViewItemV2::ViewItemFeature >("QStyleOptionViewItemV2::ViewItemFeature");
    qRegisterMetaType< ::QStyleOptionViewItemV2::ViewItemFeatures >("QStyleOptionViewItemV2::ViewItemFeatures");
}
