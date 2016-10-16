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

#include "qstyleoptionframev2_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionFrameV2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionFrameV2 >()))
        return -1;

    ::QStyleOptionFrameV2* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionFrameV2", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionFrameV2()
    // 1: QStyleOptionFrameV2(QStyleOptionFrame)
    // 2: QStyleOptionFrameV2(QStyleOptionFrameV2)
    // 3: QStyleOptionFrameV2(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionFrameV2()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionFrameV2(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionFrameV2(QStyleOptionFrameV2)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionFrameV2(QStyleOptionFrame)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionFrameV2_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionFrameV2()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV2()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV2();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionFrameV2(const QStyleOptionFrame & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV2(QStyleOptionFrame)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionFrameV2(const QStyleOptionFrameV2 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionFrameV2* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV2(QStyleOptionFrameV2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionFrameV2(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV2(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV2(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionFrameV2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionFrameV2_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionFrameV2_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionFrame", "PySide.QtGui.QStyleOptionFrameV2", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionFrameV2", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionFrameV2_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionFrameV2_get_features(PyObject* self, void*)
{
    ::QStyleOptionFrameV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionFrameV2_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionFrameV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_IDX], (SbkObject*)self));
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

// Getters and Setters for QStyleOptionFrameV2
static PyGetSetDef Sbk_QStyleOptionFrameV2_getsetlist[] = {
    {const_cast<char*>("features"), Sbk_QStyleOptionFrameV2_get_features, Sbk_QStyleOptionFrameV2_set_features},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionFrameV2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionFrameV2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionFrameV2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionFrameV2",
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
    /*tp_traverse*/         Sbk_QStyleOptionFrameV2_traverse,
    /*tp_clear*/            Sbk_QStyleOptionFrameV2_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionFrameV2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionFrameV2_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionFrameV2_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionFrameV2::FrameFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionFrameV2::FrameFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionFrameV2::FrameFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionFrameV2::FrameFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionFrameV2::FrameFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), self, &cppSelf);
    ::QStyleOptionFrameV2::FrameFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature_long,
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
static void QStyleOptionFrameV2_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV2_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionFrameV2::StyleOptionVersion*)cppOut) = (::QStyleOptionFrameV2::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionFrameV2_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV2_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionFrameV2_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV2_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionFrameV2_StyleOptionVersion_CppToPython_QStyleOptionFrameV2_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionFrameV2::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionFrameV2_FrameFeature_PythonToCpp_QStyleOptionFrameV2_FrameFeature(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionFrameV2::FrameFeature*)cppOut) = (::QStyleOptionFrameV2::FrameFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionFrameV2_FrameFeature_PythonToCpp_QStyleOptionFrameV2_FrameFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX]))
        return QStyleOptionFrameV2_FrameFeature_PythonToCpp_QStyleOptionFrameV2_FrameFeature;
    return 0;
}
static PyObject* QStyleOptionFrameV2_FrameFeature_CppToPython_QStyleOptionFrameV2_FrameFeature(const void* cppIn) {
    int castCppIn = *((::QStyleOptionFrameV2::FrameFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX], castCppIn);

}

static void QFlags_QStyleOptionFrameV2_FrameFeature__PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionFrameV2::FrameFeature>*)cppOut) = ::QFlags<QStyleOptionFrameV2::FrameFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionFrameV2_FrameFeature__PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]))
        return QFlags_QStyleOptionFrameV2_FrameFeature__PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_;
    return 0;
}
static PyObject* QFlags_QStyleOptionFrameV2_FrameFeature__CppToPython_QFlags_QStyleOptionFrameV2_FrameFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionFrameV2::FrameFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]));

}

static void QStyleOptionFrameV2_FrameFeature_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionFrameV2::FrameFeature>*)cppOut) = ::QFlags<QStyleOptionFrameV2::FrameFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionFrameV2_FrameFeature_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX]))
        return QStyleOptionFrameV2_FrameFeature_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionFrameV2::FrameFeature>*)cppOut) = ::QFlags<QStyleOptionFrameV2::FrameFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionFrameV2_PythonToCpp_QStyleOptionFrameV2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionFrameV2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionFrameV2_PythonToCpp_QStyleOptionFrameV2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionFrameV2_Type))
        return QStyleOptionFrameV2_PythonToCpp_QStyleOptionFrameV2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionFrameV2_PTR_CppToPython_QStyleOptionFrameV2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionFrameV2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionFrameV2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionFrameV2(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionFrameV2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionFrameV2", "QStyleOptionFrameV2*",
        &Sbk_QStyleOptionFrameV2_Type, &Shiboken::callCppDestructor< ::QStyleOptionFrameV2 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionFrameV2_Type,
        QStyleOptionFrameV2_PythonToCpp_QStyleOptionFrameV2_PTR,
        is_QStyleOptionFrameV2_PythonToCpp_QStyleOptionFrameV2_PTR_Convertible,
        QStyleOptionFrameV2_PTR_CppToPython_QStyleOptionFrameV2);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV2");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV2*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionFrameV2).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionFrameV2_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionFrameV2.StyleOptionVersion",
        "QStyleOptionFrameV2::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionFrameV2_Type, "Version", (long) QStyleOptionFrameV2::Version))
        return ;
    // Register converter for enum 'QStyleOptionFrameV2::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX],
            QStyleOptionFrameV2_StyleOptionVersion_CppToPython_QStyleOptionFrameV2_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrameV2_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV2_StyleOptionVersion,
            is_QStyleOptionFrameV2_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV2_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV2::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'FrameFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX] = PySide::QFlags::create("FrameFeatures", &SbkPySide_QtGui_QStyleOptionFrameV2_FrameFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionFrameV2_Type,
        "FrameFeature",
        "PySide.QtGui.QStyleOptionFrameV2.FrameFeature",
        "QStyleOptionFrameV2::FrameFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX],
        &Sbk_QStyleOptionFrameV2_Type, "None", (long) QStyleOptionFrameV2::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX],
        &Sbk_QStyleOptionFrameV2_Type, "Flat", (long) QStyleOptionFrameV2::Flat))
        return ;
    // Register converter for enum 'QStyleOptionFrameV2::FrameFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX],
            QStyleOptionFrameV2_FrameFeature_CppToPython_QStyleOptionFrameV2_FrameFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrameV2_FrameFeature_PythonToCpp_QStyleOptionFrameV2_FrameFeature,
            is_QStyleOptionFrameV2_FrameFeature_PythonToCpp_QStyleOptionFrameV2_FrameFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV2::FrameFeature");
        Shiboken::Conversions::registerConverterName(converter, "FrameFeature");
    }
    // Register converter for flag 'QFlags<QStyleOptionFrameV2::FrameFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX],
            QFlags_QStyleOptionFrameV2_FrameFeature__CppToPython_QFlags_QStyleOptionFrameV2_FrameFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrameV2_FrameFeature_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_,
            is_QStyleOptionFrameV2_FrameFeature_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionFrameV2_FrameFeature__PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_,
            is_QFlags_QStyleOptionFrameV2_FrameFeature__PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature_,
            is_number_PythonToCpp_QFlags_QStyleOptionFrameV2_FrameFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONFRAMEV2_FRAMEFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionFrameV2::FrameFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FrameFeature>");
    }
    // End of 'FrameFeature' enum/flags.


    qRegisterMetaType< ::QStyleOptionFrameV2::StyleOptionVersion >("QStyleOptionFrameV2::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionFrameV2::FrameFeature >("QStyleOptionFrameV2::FrameFeature");
    qRegisterMetaType< ::QStyleOptionFrameV2::FrameFeatures >("QStyleOptionFrameV2::FrameFeatures");
}
