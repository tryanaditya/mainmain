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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include "pyside_qtopengl_python.h"

#include "qgl_wrapper.h"

// Extra includes
#include <qgl.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QGLFunc_setPreferredPaintEngine(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPreferredPaintEngine(QPaintEngine::Type)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setPreferredPaintEngine(QPaintEngine::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGLFunc_setPreferredPaintEngine_TypeError;

    // Call function/method
    {
        ::QPaintEngine::Type cppArg0 = ((::QPaintEngine::Type)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPreferredPaintEngine(QPaintEngine::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGL::setPreferredPaintEngine(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGLFunc_setPreferredPaintEngine_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.Type", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtOpenGL.QGL.setPreferredPaintEngine", overloads);
        return 0;
}

static PyMethodDef Sbk_QGL_methods[] = {
    {"setPreferredPaintEngine", (PyCFunction)Sbk_QGLFunc_setPreferredPaintEngine, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGL_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGL_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGL_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtOpenGL.QGL",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QGL_traverse,
    /*tp_clear*/            Sbk_QGL_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGL_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

PyObject* SbkPySide_QtOpenGL_QGL_FormatOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QGL::FormatOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGL::FormatOptions)PyLong_AsLong(self);
    cppArg = (QGL::FormatOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGL::FormatOptions)PyInt_AsLong(self);
    cppArg = (QGL::FormatOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGL_FormatOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QGL::FormatOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGL::FormatOptions)PyLong_AsLong(self);
    cppArg = (QGL::FormatOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGL::FormatOptions)PyInt_AsLong(self);
    cppArg = (QGL::FormatOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGL_FormatOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGL::FormatOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGL::FormatOptions)PyLong_AsLong(self);
    cppArg = (QGL::FormatOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGL::FormatOptions)PyInt_AsLong(self);
    cppArg = (QGL::FormatOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtOpenGL_QGL_FormatOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGL::FormatOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), self, &cppSelf);
    ::QGL::FormatOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtOpenGL_QGL_FormatOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtOpenGL_QGL_FormatOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtOpenGL_QGL_FormatOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtOpenGL_QGL_FormatOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtOpenGL_QGL_FormatOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtOpenGL_QGL_FormatOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtOpenGL_QGL_FormatOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtOpenGL_QGL_FormatOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtOpenGL_QGL_FormatOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtOpenGL_QGL_FormatOption_long,
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
static void QGL_FormatOption_PythonToCpp_QGL_FormatOption(PyObject* pyIn, void* cppOut) {
    *((::QGL::FormatOption*)cppOut) = (::QGL::FormatOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGL_FormatOption_PythonToCpp_QGL_FormatOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX]))
        return QGL_FormatOption_PythonToCpp_QGL_FormatOption;
    return 0;
}
static PyObject* QGL_FormatOption_CppToPython_QGL_FormatOption(const void* cppIn) {
    int castCppIn = *((::QGL::FormatOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX], castCppIn);

}

static void QFlags_QGL_FormatOption__PythonToCpp_QFlags_QGL_FormatOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGL::FormatOption>*)cppOut) = ::QFlags<QGL::FormatOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGL_FormatOption__PythonToCpp_QFlags_QGL_FormatOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]))
        return QFlags_QGL_FormatOption__PythonToCpp_QFlags_QGL_FormatOption_;
    return 0;
}
static PyObject* QFlags_QGL_FormatOption__CppToPython_QFlags_QGL_FormatOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGL::FormatOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]));

}

static void QGL_FormatOption_PythonToCpp_QFlags_QGL_FormatOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGL::FormatOption>*)cppOut) = ::QFlags<QGL::FormatOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGL_FormatOption_PythonToCpp_QFlags_QGL_FormatOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX]))
        return QGL_FormatOption_PythonToCpp_QFlags_QGL_FormatOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGL_FormatOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGL::FormatOption>*)cppOut) = ::QFlags<QGL::FormatOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGL_FormatOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGL_FormatOption_;
    return 0;
}
void init_QGL(PyObject* module)
{
    SbkPySide_QtOpenGLTypes[SBK_QGL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGL_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGL", "QGL",
        &Sbk_QGL_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'FormatOption'.
    SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX] = PySide::QFlags::create("FormatOptions", &SbkPySide_QtOpenGL_QGL_FormatOption_as_number);
    SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGL_Type,
        "FormatOption",
        "PySide.QtOpenGL.QGL.FormatOption",
        "QGL::FormatOption",
        SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX]);
    if (!SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "DoubleBuffer", (long) QGL::DoubleBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "DepthBuffer", (long) QGL::DepthBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "Rgba", (long) QGL::Rgba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "AlphaChannel", (long) QGL::AlphaChannel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "AccumBuffer", (long) QGL::AccumBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "StencilBuffer", (long) QGL::StencilBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "StereoBuffers", (long) QGL::StereoBuffers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "DirectRendering", (long) QGL::DirectRendering))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "HasOverlay", (long) QGL::HasOverlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "SampleBuffers", (long) QGL::SampleBuffers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "DeprecatedFunctions", (long) QGL::DeprecatedFunctions))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "SingleBuffer", (long) QGL::SingleBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoDepthBuffer", (long) QGL::NoDepthBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "ColorIndex", (long) QGL::ColorIndex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoAlphaChannel", (long) QGL::NoAlphaChannel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoAccumBuffer", (long) QGL::NoAccumBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoStencilBuffer", (long) QGL::NoStencilBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoStereoBuffers", (long) QGL::NoStereoBuffers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "IndirectRendering", (long) QGL::IndirectRendering))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoOverlay", (long) QGL::NoOverlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoSampleBuffers", (long) QGL::NoSampleBuffers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
        &Sbk_QGL_Type, "NoDeprecatedFunctions", (long) QGL::NoDeprecatedFunctions))
        return ;
    // Register converter for enum 'QGL::FormatOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX],
            QGL_FormatOption_CppToPython_QGL_FormatOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGL_FormatOption_PythonToCpp_QGL_FormatOption,
            is_QGL_FormatOption_PythonToCpp_QGL_FormatOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QGL_FORMATOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGL::FormatOption");
        Shiboken::Conversions::registerConverterName(converter, "FormatOption");
    }
    // Register converter for flag 'QFlags<QGL::FormatOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX],
            QFlags_QGL_FormatOption__CppToPython_QFlags_QGL_FormatOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGL_FormatOption_PythonToCpp_QFlags_QGL_FormatOption_,
            is_QGL_FormatOption_PythonToCpp_QFlags_QGL_FormatOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGL_FormatOption__PythonToCpp_QFlags_QGL_FormatOption_,
            is_QFlags_QGL_FormatOption__PythonToCpp_QFlags_QGL_FormatOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGL_FormatOption_,
            is_number_PythonToCpp_QFlags_QGL_FormatOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtOpenGLTypes[SBK_QFLAGS_QGL_FORMATOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGL::FormatOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FormatOption>");
    }
    // End of 'FormatOption' enum/flags.


    qRegisterMetaType< ::QGL::FormatOption >("QGL::FormatOption");
    qRegisterMetaType< ::QGL::FormatOptions >("QGL::FormatOptions");
}
