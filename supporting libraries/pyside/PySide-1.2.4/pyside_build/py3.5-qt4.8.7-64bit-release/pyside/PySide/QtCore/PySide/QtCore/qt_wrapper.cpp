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
#include "pyside_qtcore_python.h"

#include "qt_wrapper.h"

// Extra includes
#include <QTextDocument>



// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_Qt_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Qt_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Qt_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Qt_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.Qt",
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
    /*tp_traverse*/         Sbk_Qt_traverse,
    /*tp_clear*/            Sbk_Qt_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Qt_methods,
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

PyObject* SbkPySide_QtCore_Qt_KeyboardModifier___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::KeyboardModifiers)PyLong_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::KeyboardModifiers)PyInt_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_KeyboardModifier___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::KeyboardModifiers)PyLong_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::KeyboardModifiers)PyInt_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_KeyboardModifier___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::KeyboardModifiers)PyLong_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::KeyboardModifiers)PyInt_AsLong(self);
    cppArg = (Qt::KeyboardModifiers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_KeyboardModifier___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::KeyboardModifiers cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), self, &cppSelf);
    ::Qt::KeyboardModifiers cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_KeyboardModifier_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_KeyboardModifier__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_KeyboardModifier_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_KeyboardModifier__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_KeyboardModifier___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_KeyboardModifier___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_KeyboardModifier___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_KeyboardModifier___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_KeyboardModifier_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_KeyboardModifier_long,
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


PyObject* SbkPySide_QtCore_Qt_MouseButton___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MouseButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MouseButtons)PyLong_AsLong(self);
    cppArg = (Qt::MouseButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MouseButtons)PyInt_AsLong(self);
    cppArg = (Qt::MouseButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MouseButton___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MouseButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MouseButtons)PyLong_AsLong(self);
    cppArg = (Qt::MouseButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MouseButtons)PyInt_AsLong(self);
    cppArg = (Qt::MouseButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MouseButton___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MouseButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MouseButtons)PyLong_AsLong(self);
    cppArg = (Qt::MouseButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MouseButtons)PyInt_AsLong(self);
    cppArg = (Qt::MouseButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MouseButton___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MouseButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), self, &cppSelf);
    ::Qt::MouseButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_MouseButton_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_MouseButton__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_MouseButton_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_MouseButton__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_MouseButton___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_MouseButton___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_MouseButton___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_MouseButton___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_MouseButton_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_MouseButton_long,
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


PyObject* SbkPySide_QtCore_Qt_Orientation___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Orientations cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Orientations)PyLong_AsLong(self);
    cppArg = (Qt::Orientations)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Orientations)PyInt_AsLong(self);
    cppArg = (Qt::Orientations)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_Orientation___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Orientations cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Orientations)PyLong_AsLong(self);
    cppArg = (Qt::Orientations)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Orientations)PyInt_AsLong(self);
    cppArg = (Qt::Orientations)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_Orientation___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Orientations cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Orientations)PyLong_AsLong(self);
    cppArg = (Qt::Orientations)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Orientations)PyInt_AsLong(self);
    cppArg = (Qt::Orientations)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_Orientation___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Orientations cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), self, &cppSelf);
    ::Qt::Orientations cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_Orientation_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_Orientation__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_Orientation_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_Orientation__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_Orientation___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_Orientation___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_Orientation___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_Orientation___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_Orientation_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_Orientation_long,
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


PyObject* SbkPySide_QtCore_Qt_AlignmentFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Alignment cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Alignment)PyLong_AsLong(self);
    cppArg = (Qt::Alignment)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Alignment)PyInt_AsLong(self);
    cppArg = (Qt::Alignment)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_AlignmentFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Alignment cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Alignment)PyLong_AsLong(self);
    cppArg = (Qt::Alignment)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Alignment)PyInt_AsLong(self);
    cppArg = (Qt::Alignment)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_AlignmentFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Alignment cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::Alignment)PyLong_AsLong(self);
    cppArg = (Qt::Alignment)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::Alignment)PyInt_AsLong(self);
    cppArg = (Qt::Alignment)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_AlignmentFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::Alignment cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), self, &cppSelf);
    ::Qt::Alignment cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_AlignmentFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_AlignmentFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_AlignmentFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_AlignmentFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_AlignmentFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_AlignmentFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_AlignmentFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_AlignmentFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_AlignmentFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_AlignmentFlag_long,
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


PyObject* SbkPySide_QtCore_Qt_WindowType___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowFlags)PyLong_AsLong(self);
    cppArg = (Qt::WindowFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowFlags)PyInt_AsLong(self);
    cppArg = (Qt::WindowFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowType___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowFlags)PyLong_AsLong(self);
    cppArg = (Qt::WindowFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowFlags)PyInt_AsLong(self);
    cppArg = (Qt::WindowFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowType___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowFlags)PyLong_AsLong(self);
    cppArg = (Qt::WindowFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowFlags)PyInt_AsLong(self);
    cppArg = (Qt::WindowFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowType___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), self, &cppSelf);
    ::Qt::WindowFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_WindowType_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_WindowType__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_WindowType_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_WindowType__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_WindowType___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_WindowType___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_WindowType___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_WindowType___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_WindowType_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_WindowType_long,
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


PyObject* SbkPySide_QtCore_Qt_WindowState___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowStates cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowStates)PyLong_AsLong(self);
    cppArg = (Qt::WindowStates)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowStates)PyInt_AsLong(self);
    cppArg = (Qt::WindowStates)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowState___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowStates cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowStates)PyLong_AsLong(self);
    cppArg = (Qt::WindowStates)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowStates)PyInt_AsLong(self);
    cppArg = (Qt::WindowStates)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowState___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowStates cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::WindowStates)PyLong_AsLong(self);
    cppArg = (Qt::WindowStates)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::WindowStates)PyInt_AsLong(self);
    cppArg = (Qt::WindowStates)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_WindowState___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::WindowStates cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), self, &cppSelf);
    ::Qt::WindowStates cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_WindowState_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_WindowState__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_WindowState_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_WindowState__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_WindowState___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_WindowState___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_WindowState___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_WindowState___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_WindowState_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_WindowState_long,
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


PyObject* SbkPySide_QtCore_Qt_ImageConversionFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ImageConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ImageConversionFlags)PyLong_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ImageConversionFlags)PyInt_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ImageConversionFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ImageConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ImageConversionFlags)PyLong_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ImageConversionFlags)PyInt_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ImageConversionFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ImageConversionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ImageConversionFlags)PyLong_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ImageConversionFlags)PyInt_AsLong(self);
    cppArg = (Qt::ImageConversionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ImageConversionFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ImageConversionFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), self, &cppSelf);
    ::Qt::ImageConversionFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_ImageConversionFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_ImageConversionFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_ImageConversionFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_ImageConversionFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_ImageConversionFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_ImageConversionFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_ImageConversionFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_ImageConversionFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_ImageConversionFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_ImageConversionFlag_long,
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


PyObject* SbkPySide_QtCore_Qt_DockWidgetArea___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DockWidgetAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DockWidgetAreas)PyLong_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DockWidgetAreas)PyInt_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DockWidgetArea___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DockWidgetAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DockWidgetAreas)PyLong_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DockWidgetAreas)PyInt_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DockWidgetArea___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DockWidgetAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DockWidgetAreas)PyLong_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DockWidgetAreas)PyInt_AsLong(self);
    cppArg = (Qt::DockWidgetAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DockWidgetArea___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DockWidgetAreas cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), self, &cppSelf);
    ::Qt::DockWidgetAreas cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_DockWidgetArea_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_DockWidgetArea__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_DockWidgetArea_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_DockWidgetArea__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_DockWidgetArea___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_DockWidgetArea___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_DockWidgetArea___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_DockWidgetArea___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_DockWidgetArea_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_DockWidgetArea_long,
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


PyObject* SbkPySide_QtCore_Qt_ToolBarArea___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ToolBarAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ToolBarAreas)PyLong_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ToolBarAreas)PyInt_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ToolBarArea___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ToolBarAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ToolBarAreas)PyLong_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ToolBarAreas)PyInt_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ToolBarArea___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ToolBarAreas cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ToolBarAreas)PyLong_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ToolBarAreas)PyInt_AsLong(self);
    cppArg = (Qt::ToolBarAreas)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ToolBarArea___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ToolBarAreas cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), self, &cppSelf);
    ::Qt::ToolBarAreas cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_ToolBarArea_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_ToolBarArea__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_ToolBarArea_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_ToolBarArea__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_ToolBarArea___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_ToolBarArea___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_ToolBarArea___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_ToolBarArea___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_ToolBarArea_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_ToolBarArea_long,
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


PyObject* SbkPySide_QtCore_Qt_InputMethodHint___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::InputMethodHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::InputMethodHints)PyLong_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::InputMethodHints)PyInt_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_InputMethodHint___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::InputMethodHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::InputMethodHints)PyLong_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::InputMethodHints)PyInt_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_InputMethodHint___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::InputMethodHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::InputMethodHints)PyLong_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::InputMethodHints)PyInt_AsLong(self);
    cppArg = (Qt::InputMethodHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_InputMethodHint___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::InputMethodHints cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), self, &cppSelf);
    ::Qt::InputMethodHints cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_InputMethodHint_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_InputMethodHint__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_InputMethodHint_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_InputMethodHint__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_InputMethodHint___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_InputMethodHint___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_InputMethodHint___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_InputMethodHint___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_InputMethodHint_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_InputMethodHint_long,
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


PyObject* SbkPySide_QtCore_Qt_DropAction___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DropActions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DropActions)PyLong_AsLong(self);
    cppArg = (Qt::DropActions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DropActions)PyInt_AsLong(self);
    cppArg = (Qt::DropActions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DropAction___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DropActions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DropActions)PyLong_AsLong(self);
    cppArg = (Qt::DropActions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DropActions)PyInt_AsLong(self);
    cppArg = (Qt::DropActions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DropAction___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DropActions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::DropActions)PyLong_AsLong(self);
    cppArg = (Qt::DropActions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::DropActions)PyInt_AsLong(self);
    cppArg = (Qt::DropActions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_DropAction___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::DropActions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), self, &cppSelf);
    ::Qt::DropActions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_DropAction_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_DropAction__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_DropAction_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_DropAction__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_DropAction___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_DropAction___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_DropAction___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_DropAction___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_DropAction_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_DropAction_long,
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


PyObject* SbkPySide_QtCore_Qt_ItemFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ItemFlags)PyLong_AsLong(self);
    cppArg = (Qt::ItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ItemFlags)PyInt_AsLong(self);
    cppArg = (Qt::ItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ItemFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ItemFlags)PyLong_AsLong(self);
    cppArg = (Qt::ItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ItemFlags)PyInt_AsLong(self);
    cppArg = (Qt::ItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ItemFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::ItemFlags)PyLong_AsLong(self);
    cppArg = (Qt::ItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::ItemFlags)PyInt_AsLong(self);
    cppArg = (Qt::ItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_ItemFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::ItemFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), self, &cppSelf);
    ::Qt::ItemFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_ItemFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_ItemFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_ItemFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_ItemFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_ItemFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_ItemFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_ItemFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_ItemFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_ItemFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_ItemFlag_long,
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


PyObject* SbkPySide_QtCore_Qt_MatchFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MatchFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MatchFlags)PyLong_AsLong(self);
    cppArg = (Qt::MatchFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MatchFlags)PyInt_AsLong(self);
    cppArg = (Qt::MatchFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MatchFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MatchFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MatchFlags)PyLong_AsLong(self);
    cppArg = (Qt::MatchFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MatchFlags)PyInt_AsLong(self);
    cppArg = (Qt::MatchFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MatchFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MatchFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::MatchFlags)PyLong_AsLong(self);
    cppArg = (Qt::MatchFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::MatchFlags)PyInt_AsLong(self);
    cppArg = (Qt::MatchFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_MatchFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::MatchFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), self, &cppSelf);
    ::Qt::MatchFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_MatchFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_MatchFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_MatchFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_MatchFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_MatchFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_MatchFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_MatchFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_MatchFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_MatchFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_MatchFlag_long,
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


PyObject* SbkPySide_QtCore_Qt_TextInteractionFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::TextInteractionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::TextInteractionFlags)PyLong_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::TextInteractionFlags)PyInt_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_TextInteractionFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::TextInteractionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::TextInteractionFlags)PyLong_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::TextInteractionFlags)PyInt_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_TextInteractionFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::TextInteractionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::TextInteractionFlags)PyLong_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::TextInteractionFlags)PyInt_AsLong(self);
    cppArg = (Qt::TextInteractionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_TextInteractionFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::TextInteractionFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), self, &cppSelf);
    ::Qt::TextInteractionFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_TextInteractionFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_TextInteractionFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_TextInteractionFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_TextInteractionFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_TextInteractionFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_TextInteractionFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_TextInteractionFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_TextInteractionFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_TextInteractionFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_TextInteractionFlag_long,
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


PyObject* SbkPySide_QtCore_Qt_GestureFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::Qt::GestureFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::GestureFlags)PyLong_AsLong(self);
    cppArg = (Qt::GestureFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::GestureFlags)PyInt_AsLong(self);
    cppArg = (Qt::GestureFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_GestureFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::Qt::GestureFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::GestureFlags)PyLong_AsLong(self);
    cppArg = (Qt::GestureFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::GestureFlags)PyInt_AsLong(self);
    cppArg = (Qt::GestureFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_GestureFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::Qt::GestureFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Qt::GestureFlags)PyLong_AsLong(self);
    cppArg = (Qt::GestureFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Qt::GestureFlags)PyInt_AsLong(self);
    cppArg = (Qt::GestureFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_Qt_GestureFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::Qt::GestureFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), self, &cppSelf);
    ::Qt::GestureFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_Qt_GestureFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_Qt_GestureFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_Qt_GestureFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_Qt_GestureFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_Qt_GestureFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_Qt_GestureFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_Qt_GestureFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_Qt_GestureFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_Qt_GestureFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_Qt_GestureFlag_long,
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
static void Qt_GlobalColor_PythonToCpp_Qt_GlobalColor(PyObject* pyIn, void* cppOut) {
    *((::Qt::GlobalColor*)cppOut) = (::Qt::GlobalColor) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_GlobalColor_PythonToCpp_Qt_GlobalColor_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]))
        return Qt_GlobalColor_PythonToCpp_Qt_GlobalColor;
    return 0;
}
static PyObject* Qt_GlobalColor_CppToPython_Qt_GlobalColor(const void* cppIn) {
    int castCppIn = *((::Qt::GlobalColor*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], castCppIn);

}

static void Qt_KeyboardModifier_PythonToCpp_Qt_KeyboardModifier(PyObject* pyIn, void* cppOut) {
    *((::Qt::KeyboardModifier*)cppOut) = (::Qt::KeyboardModifier) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_KeyboardModifier_PythonToCpp_Qt_KeyboardModifier_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX]))
        return Qt_KeyboardModifier_PythonToCpp_Qt_KeyboardModifier;
    return 0;
}
static PyObject* Qt_KeyboardModifier_CppToPython_Qt_KeyboardModifier(const void* cppIn) {
    int castCppIn = *((::Qt::KeyboardModifier*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX], castCppIn);

}

static void QFlags_Qt_KeyboardModifier__PythonToCpp_QFlags_Qt_KeyboardModifier_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::KeyboardModifier>*)cppOut) = ::QFlags<Qt::KeyboardModifier>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_KeyboardModifier__PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]))
        return QFlags_Qt_KeyboardModifier__PythonToCpp_QFlags_Qt_KeyboardModifier_;
    return 0;
}
static PyObject* QFlags_Qt_KeyboardModifier__CppToPython_QFlags_Qt_KeyboardModifier_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::KeyboardModifier>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]));

}

static void Qt_KeyboardModifier_PythonToCpp_QFlags_Qt_KeyboardModifier_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::KeyboardModifier>*)cppOut) = ::QFlags<Qt::KeyboardModifier>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_KeyboardModifier_PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX]))
        return Qt_KeyboardModifier_PythonToCpp_QFlags_Qt_KeyboardModifier_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_KeyboardModifier_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::KeyboardModifier>*)cppOut) = ::QFlags<Qt::KeyboardModifier>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_KeyboardModifier_;
    return 0;
}
static void Qt_Modifier_PythonToCpp_Qt_Modifier(PyObject* pyIn, void* cppOut) {
    *((::Qt::Modifier*)cppOut) = (::Qt::Modifier) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_Modifier_PythonToCpp_Qt_Modifier_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX]))
        return Qt_Modifier_PythonToCpp_Qt_Modifier;
    return 0;
}
static PyObject* Qt_Modifier_CppToPython_Qt_Modifier(const void* cppIn) {
    int castCppIn = *((::Qt::Modifier*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX], castCppIn);

}

static void Qt_MouseButton_PythonToCpp_Qt_MouseButton(PyObject* pyIn, void* cppOut) {
    *((::Qt::MouseButton*)cppOut) = (::Qt::MouseButton) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_MouseButton_PythonToCpp_Qt_MouseButton_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]))
        return Qt_MouseButton_PythonToCpp_Qt_MouseButton;
    return 0;
}
static PyObject* Qt_MouseButton_CppToPython_Qt_MouseButton(const void* cppIn) {
    int castCppIn = *((::Qt::MouseButton*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX], castCppIn);

}

static void QFlags_Qt_MouseButton__PythonToCpp_QFlags_Qt_MouseButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::MouseButton>*)cppOut) = ::QFlags<Qt::MouseButton>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_MouseButton__PythonToCpp_QFlags_Qt_MouseButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]))
        return QFlags_Qt_MouseButton__PythonToCpp_QFlags_Qt_MouseButton_;
    return 0;
}
static PyObject* QFlags_Qt_MouseButton__CppToPython_QFlags_Qt_MouseButton_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::MouseButton>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]));

}

static void Qt_MouseButton_PythonToCpp_QFlags_Qt_MouseButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::MouseButton>*)cppOut) = ::QFlags<Qt::MouseButton>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_MouseButton_PythonToCpp_QFlags_Qt_MouseButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]))
        return Qt_MouseButton_PythonToCpp_QFlags_Qt_MouseButton_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_MouseButton_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::MouseButton>*)cppOut) = ::QFlags<Qt::MouseButton>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_MouseButton__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_MouseButton_;
    return 0;
}
static void Qt_Orientation_PythonToCpp_Qt_Orientation(PyObject* pyIn, void* cppOut) {
    *((::Qt::Orientation*)cppOut) = (::Qt::Orientation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_Orientation_PythonToCpp_Qt_Orientation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]))
        return Qt_Orientation_PythonToCpp_Qt_Orientation;
    return 0;
}
static PyObject* Qt_Orientation_CppToPython_Qt_Orientation(const void* cppIn) {
    int castCppIn = *((::Qt::Orientation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX], castCppIn);

}

static void QFlags_Qt_Orientation__PythonToCpp_QFlags_Qt_Orientation_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::Orientation>*)cppOut) = ::QFlags<Qt::Orientation>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_Orientation__PythonToCpp_QFlags_Qt_Orientation__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]))
        return QFlags_Qt_Orientation__PythonToCpp_QFlags_Qt_Orientation_;
    return 0;
}
static PyObject* QFlags_Qt_Orientation__CppToPython_QFlags_Qt_Orientation_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::Orientation>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]));

}

static void Qt_Orientation_PythonToCpp_QFlags_Qt_Orientation_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::Orientation>*)cppOut) = ::QFlags<Qt::Orientation>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_Orientation_PythonToCpp_QFlags_Qt_Orientation__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]))
        return Qt_Orientation_PythonToCpp_QFlags_Qt_Orientation_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_Orientation_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::Orientation>*)cppOut) = ::QFlags<Qt::Orientation>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_Orientation__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_Orientation_;
    return 0;
}
static void Qt_FocusPolicy_PythonToCpp_Qt_FocusPolicy(PyObject* pyIn, void* cppOut) {
    *((::Qt::FocusPolicy*)cppOut) = (::Qt::FocusPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_FocusPolicy_PythonToCpp_Qt_FocusPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX]))
        return Qt_FocusPolicy_PythonToCpp_Qt_FocusPolicy;
    return 0;
}
static PyObject* Qt_FocusPolicy_CppToPython_Qt_FocusPolicy(const void* cppIn) {
    int castCppIn = *((::Qt::FocusPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX], castCppIn);

}

static void Qt_SortOrder_PythonToCpp_Qt_SortOrder(PyObject* pyIn, void* cppOut) {
    *((::Qt::SortOrder*)cppOut) = (::Qt::SortOrder) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_SortOrder_PythonToCpp_Qt_SortOrder_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]))
        return Qt_SortOrder_PythonToCpp_Qt_SortOrder;
    return 0;
}
static PyObject* Qt_SortOrder_CppToPython_Qt_SortOrder(const void* cppIn) {
    int castCppIn = *((::Qt::SortOrder*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX], castCppIn);

}

static void Qt_TileRule_PythonToCpp_Qt_TileRule(PyObject* pyIn, void* cppOut) {
    *((::Qt::TileRule*)cppOut) = (::Qt::TileRule) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TileRule_PythonToCpp_Qt_TileRule_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]))
        return Qt_TileRule_PythonToCpp_Qt_TileRule;
    return 0;
}
static PyObject* Qt_TileRule_CppToPython_Qt_TileRule(const void* cppIn) {
    int castCppIn = *((::Qt::TileRule*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX], castCppIn);

}

static void Qt_AlignmentFlag_PythonToCpp_Qt_AlignmentFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::AlignmentFlag*)cppOut) = (::Qt::AlignmentFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_AlignmentFlag_PythonToCpp_Qt_AlignmentFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX]))
        return Qt_AlignmentFlag_PythonToCpp_Qt_AlignmentFlag;
    return 0;
}
static PyObject* Qt_AlignmentFlag_CppToPython_Qt_AlignmentFlag(const void* cppIn) {
    int castCppIn = *((::Qt::AlignmentFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX], castCppIn);

}

static void QFlags_Qt_AlignmentFlag__PythonToCpp_QFlags_Qt_AlignmentFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::AlignmentFlag>*)cppOut) = ::QFlags<Qt::AlignmentFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_AlignmentFlag__PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]))
        return QFlags_Qt_AlignmentFlag__PythonToCpp_QFlags_Qt_AlignmentFlag_;
    return 0;
}
static PyObject* QFlags_Qt_AlignmentFlag__CppToPython_QFlags_Qt_AlignmentFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::AlignmentFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]));

}

static void Qt_AlignmentFlag_PythonToCpp_QFlags_Qt_AlignmentFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::AlignmentFlag>*)cppOut) = ::QFlags<Qt::AlignmentFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_AlignmentFlag_PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX]))
        return Qt_AlignmentFlag_PythonToCpp_QFlags_Qt_AlignmentFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_AlignmentFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::AlignmentFlag>*)cppOut) = ::QFlags<Qt::AlignmentFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_AlignmentFlag_;
    return 0;
}
static void Qt_TextFlag_PythonToCpp_Qt_TextFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::TextFlag*)cppOut) = (::Qt::TextFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TextFlag_PythonToCpp_Qt_TextFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX]))
        return Qt_TextFlag_PythonToCpp_Qt_TextFlag;
    return 0;
}
static PyObject* Qt_TextFlag_CppToPython_Qt_TextFlag(const void* cppIn) {
    int castCppIn = *((::Qt::TextFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX], castCppIn);

}

static void Qt_TextElideMode_PythonToCpp_Qt_TextElideMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::TextElideMode*)cppOut) = (::Qt::TextElideMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TextElideMode_PythonToCpp_Qt_TextElideMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]))
        return Qt_TextElideMode_PythonToCpp_Qt_TextElideMode;
    return 0;
}
static PyObject* Qt_TextElideMode_CppToPython_Qt_TextElideMode(const void* cppIn) {
    int castCppIn = *((::Qt::TextElideMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX], castCppIn);

}

static void Qt_WindowType_PythonToCpp_Qt_WindowType(PyObject* pyIn, void* cppOut) {
    *((::Qt::WindowType*)cppOut) = (::Qt::WindowType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WindowType_PythonToCpp_Qt_WindowType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX]))
        return Qt_WindowType_PythonToCpp_Qt_WindowType;
    return 0;
}
static PyObject* Qt_WindowType_CppToPython_Qt_WindowType(const void* cppIn) {
    int castCppIn = *((::Qt::WindowType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX], castCppIn);

}

static void QFlags_Qt_WindowType__PythonToCpp_QFlags_Qt_WindowType_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::WindowType>*)cppOut) = ::QFlags<Qt::WindowType>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_WindowType__PythonToCpp_QFlags_Qt_WindowType__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]))
        return QFlags_Qt_WindowType__PythonToCpp_QFlags_Qt_WindowType_;
    return 0;
}
static PyObject* QFlags_Qt_WindowType__CppToPython_QFlags_Qt_WindowType_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::WindowType>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]));

}

static void Qt_WindowType_PythonToCpp_QFlags_Qt_WindowType_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::WindowType>*)cppOut) = ::QFlags<Qt::WindowType>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_WindowType_PythonToCpp_QFlags_Qt_WindowType__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX]))
        return Qt_WindowType_PythonToCpp_QFlags_Qt_WindowType_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_WindowType_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::WindowType>*)cppOut) = ::QFlags<Qt::WindowType>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_WindowType__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_WindowType_;
    return 0;
}
static void Qt_WindowState_PythonToCpp_Qt_WindowState(PyObject* pyIn, void* cppOut) {
    *((::Qt::WindowState*)cppOut) = (::Qt::WindowState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WindowState_PythonToCpp_Qt_WindowState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX]))
        return Qt_WindowState_PythonToCpp_Qt_WindowState;
    return 0;
}
static PyObject* Qt_WindowState_CppToPython_Qt_WindowState(const void* cppIn) {
    int castCppIn = *((::Qt::WindowState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX], castCppIn);

}

static void QFlags_Qt_WindowState__PythonToCpp_QFlags_Qt_WindowState_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::WindowState>*)cppOut) = ::QFlags<Qt::WindowState>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_WindowState__PythonToCpp_QFlags_Qt_WindowState__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]))
        return QFlags_Qt_WindowState__PythonToCpp_QFlags_Qt_WindowState_;
    return 0;
}
static PyObject* QFlags_Qt_WindowState__CppToPython_QFlags_Qt_WindowState_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::WindowState>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]));

}

static void Qt_WindowState_PythonToCpp_QFlags_Qt_WindowState_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::WindowState>*)cppOut) = ::QFlags<Qt::WindowState>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_WindowState_PythonToCpp_QFlags_Qt_WindowState__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX]))
        return Qt_WindowState_PythonToCpp_QFlags_Qt_WindowState_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_WindowState_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::WindowState>*)cppOut) = ::QFlags<Qt::WindowState>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_WindowState__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_WindowState_;
    return 0;
}
static void Qt_WidgetAttribute_PythonToCpp_Qt_WidgetAttribute(PyObject* pyIn, void* cppOut) {
    *((::Qt::WidgetAttribute*)cppOut) = (::Qt::WidgetAttribute) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WidgetAttribute_PythonToCpp_Qt_WidgetAttribute_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX]))
        return Qt_WidgetAttribute_PythonToCpp_Qt_WidgetAttribute;
    return 0;
}
static PyObject* Qt_WidgetAttribute_CppToPython_Qt_WidgetAttribute(const void* cppIn) {
    int castCppIn = *((::Qt::WidgetAttribute*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX], castCppIn);

}

static void Qt_ApplicationAttribute_PythonToCpp_Qt_ApplicationAttribute(PyObject* pyIn, void* cppOut) {
    *((::Qt::ApplicationAttribute*)cppOut) = (::Qt::ApplicationAttribute) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ApplicationAttribute_PythonToCpp_Qt_ApplicationAttribute_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX]))
        return Qt_ApplicationAttribute_PythonToCpp_Qt_ApplicationAttribute;
    return 0;
}
static PyObject* Qt_ApplicationAttribute_CppToPython_Qt_ApplicationAttribute(const void* cppIn) {
    int castCppIn = *((::Qt::ApplicationAttribute*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX], castCppIn);

}

static void Qt_ImageConversionFlag_PythonToCpp_Qt_ImageConversionFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::ImageConversionFlag*)cppOut) = (::Qt::ImageConversionFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ImageConversionFlag_PythonToCpp_Qt_ImageConversionFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX]))
        return Qt_ImageConversionFlag_PythonToCpp_Qt_ImageConversionFlag;
    return 0;
}
static PyObject* Qt_ImageConversionFlag_CppToPython_Qt_ImageConversionFlag(const void* cppIn) {
    int castCppIn = *((::Qt::ImageConversionFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX], castCppIn);

}

static void QFlags_Qt_ImageConversionFlag__PythonToCpp_QFlags_Qt_ImageConversionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ImageConversionFlag>*)cppOut) = ::QFlags<Qt::ImageConversionFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_ImageConversionFlag__PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]))
        return QFlags_Qt_ImageConversionFlag__PythonToCpp_QFlags_Qt_ImageConversionFlag_;
    return 0;
}
static PyObject* QFlags_Qt_ImageConversionFlag__CppToPython_QFlags_Qt_ImageConversionFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::ImageConversionFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]));

}

static void Qt_ImageConversionFlag_PythonToCpp_QFlags_Qt_ImageConversionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ImageConversionFlag>*)cppOut) = ::QFlags<Qt::ImageConversionFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_ImageConversionFlag_PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX]))
        return Qt_ImageConversionFlag_PythonToCpp_QFlags_Qt_ImageConversionFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_ImageConversionFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::ImageConversionFlag>*)cppOut) = ::QFlags<Qt::ImageConversionFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_ImageConversionFlag_;
    return 0;
}
static void Qt_BGMode_PythonToCpp_Qt_BGMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::BGMode*)cppOut) = (::Qt::BGMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_BGMode_PythonToCpp_Qt_BGMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX]))
        return Qt_BGMode_PythonToCpp_Qt_BGMode;
    return 0;
}
static PyObject* Qt_BGMode_CppToPython_Qt_BGMode(const void* cppIn) {
    int castCppIn = *((::Qt::BGMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX], castCppIn);

}

static void Qt_Key_PythonToCpp_Qt_Key(PyObject* pyIn, void* cppOut) {
    *((::Qt::Key*)cppOut) = (::Qt::Key) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_Key_PythonToCpp_Qt_Key_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]))
        return Qt_Key_PythonToCpp_Qt_Key;
    return 0;
}
static PyObject* Qt_Key_CppToPython_Qt_Key(const void* cppIn) {
    int castCppIn = *((::Qt::Key*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX], castCppIn);

}

static void Qt_ArrowType_PythonToCpp_Qt_ArrowType(PyObject* pyIn, void* cppOut) {
    *((::Qt::ArrowType*)cppOut) = (::Qt::ArrowType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ArrowType_PythonToCpp_Qt_ArrowType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX]))
        return Qt_ArrowType_PythonToCpp_Qt_ArrowType;
    return 0;
}
static PyObject* Qt_ArrowType_CppToPython_Qt_ArrowType(const void* cppIn) {
    int castCppIn = *((::Qt::ArrowType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX], castCppIn);

}

static void Qt_PenStyle_PythonToCpp_Qt_PenStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::PenStyle*)cppOut) = (::Qt::PenStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_PenStyle_PythonToCpp_Qt_PenStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]))
        return Qt_PenStyle_PythonToCpp_Qt_PenStyle;
    return 0;
}
static PyObject* Qt_PenStyle_CppToPython_Qt_PenStyle(const void* cppIn) {
    int castCppIn = *((::Qt::PenStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX], castCppIn);

}

static void Qt_PenCapStyle_PythonToCpp_Qt_PenCapStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::PenCapStyle*)cppOut) = (::Qt::PenCapStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_PenCapStyle_PythonToCpp_Qt_PenCapStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]))
        return Qt_PenCapStyle_PythonToCpp_Qt_PenCapStyle;
    return 0;
}
static PyObject* Qt_PenCapStyle_CppToPython_Qt_PenCapStyle(const void* cppIn) {
    int castCppIn = *((::Qt::PenCapStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX], castCppIn);

}

static void Qt_PenJoinStyle_PythonToCpp_Qt_PenJoinStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::PenJoinStyle*)cppOut) = (::Qt::PenJoinStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_PenJoinStyle_PythonToCpp_Qt_PenJoinStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]))
        return Qt_PenJoinStyle_PythonToCpp_Qt_PenJoinStyle;
    return 0;
}
static PyObject* Qt_PenJoinStyle_CppToPython_Qt_PenJoinStyle(const void* cppIn) {
    int castCppIn = *((::Qt::PenJoinStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX], castCppIn);

}

static void Qt_BrushStyle_PythonToCpp_Qt_BrushStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::BrushStyle*)cppOut) = (::Qt::BrushStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_BrushStyle_PythonToCpp_Qt_BrushStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]))
        return Qt_BrushStyle_PythonToCpp_Qt_BrushStyle;
    return 0;
}
static PyObject* Qt_BrushStyle_CppToPython_Qt_BrushStyle(const void* cppIn) {
    int castCppIn = *((::Qt::BrushStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX], castCppIn);

}

static void Qt_SizeMode_PythonToCpp_Qt_SizeMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::SizeMode*)cppOut) = (::Qt::SizeMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_SizeMode_PythonToCpp_Qt_SizeMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]))
        return Qt_SizeMode_PythonToCpp_Qt_SizeMode;
    return 0;
}
static PyObject* Qt_SizeMode_CppToPython_Qt_SizeMode(const void* cppIn) {
    int castCppIn = *((::Qt::SizeMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX], castCppIn);

}

static void Qt_UIEffect_PythonToCpp_Qt_UIEffect(PyObject* pyIn, void* cppOut) {
    *((::Qt::UIEffect*)cppOut) = (::Qt::UIEffect) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_UIEffect_PythonToCpp_Qt_UIEffect_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX]))
        return Qt_UIEffect_PythonToCpp_Qt_UIEffect;
    return 0;
}
static PyObject* Qt_UIEffect_CppToPython_Qt_UIEffect(const void* cppIn) {
    int castCppIn = *((::Qt::UIEffect*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX], castCppIn);

}

static void Qt_CursorShape_PythonToCpp_Qt_CursorShape(PyObject* pyIn, void* cppOut) {
    *((::Qt::CursorShape*)cppOut) = (::Qt::CursorShape) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_CursorShape_PythonToCpp_Qt_CursorShape_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX]))
        return Qt_CursorShape_PythonToCpp_Qt_CursorShape;
    return 0;
}
static PyObject* Qt_CursorShape_CppToPython_Qt_CursorShape(const void* cppIn) {
    int castCppIn = *((::Qt::CursorShape*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX], castCppIn);

}

static void Qt_TextFormat_PythonToCpp_Qt_TextFormat(PyObject* pyIn, void* cppOut) {
    *((::Qt::TextFormat*)cppOut) = (::Qt::TextFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TextFormat_PythonToCpp_Qt_TextFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX]))
        return Qt_TextFormat_PythonToCpp_Qt_TextFormat;
    return 0;
}
static PyObject* Qt_TextFormat_CppToPython_Qt_TextFormat(const void* cppIn) {
    int castCppIn = *((::Qt::TextFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX], castCppIn);

}

static void Qt_AspectRatioMode_PythonToCpp_Qt_AspectRatioMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::AspectRatioMode*)cppOut) = (::Qt::AspectRatioMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_AspectRatioMode_PythonToCpp_Qt_AspectRatioMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]))
        return Qt_AspectRatioMode_PythonToCpp_Qt_AspectRatioMode;
    return 0;
}
static PyObject* Qt_AspectRatioMode_CppToPython_Qt_AspectRatioMode(const void* cppIn) {
    int castCppIn = *((::Qt::AspectRatioMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX], castCppIn);

}

static void Qt_AnchorAttribute_PythonToCpp_Qt_AnchorAttribute(PyObject* pyIn, void* cppOut) {
    *((::Qt::AnchorAttribute*)cppOut) = (::Qt::AnchorAttribute) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_AnchorAttribute_PythonToCpp_Qt_AnchorAttribute_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX]))
        return Qt_AnchorAttribute_PythonToCpp_Qt_AnchorAttribute;
    return 0;
}
static PyObject* Qt_AnchorAttribute_CppToPython_Qt_AnchorAttribute(const void* cppIn) {
    int castCppIn = *((::Qt::AnchorAttribute*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX], castCppIn);

}

static void Qt_DockWidgetArea_PythonToCpp_Qt_DockWidgetArea(PyObject* pyIn, void* cppOut) {
    *((::Qt::DockWidgetArea*)cppOut) = (::Qt::DockWidgetArea) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_DockWidgetArea_PythonToCpp_Qt_DockWidgetArea_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]))
        return Qt_DockWidgetArea_PythonToCpp_Qt_DockWidgetArea;
    return 0;
}
static PyObject* Qt_DockWidgetArea_CppToPython_Qt_DockWidgetArea(const void* cppIn) {
    int castCppIn = *((::Qt::DockWidgetArea*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX], castCppIn);

}

static void QFlags_Qt_DockWidgetArea__PythonToCpp_QFlags_Qt_DockWidgetArea_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::DockWidgetArea>*)cppOut) = ::QFlags<Qt::DockWidgetArea>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_DockWidgetArea__PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]))
        return QFlags_Qt_DockWidgetArea__PythonToCpp_QFlags_Qt_DockWidgetArea_;
    return 0;
}
static PyObject* QFlags_Qt_DockWidgetArea__CppToPython_QFlags_Qt_DockWidgetArea_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::DockWidgetArea>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]));

}

static void Qt_DockWidgetArea_PythonToCpp_QFlags_Qt_DockWidgetArea_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::DockWidgetArea>*)cppOut) = ::QFlags<Qt::DockWidgetArea>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_DockWidgetArea_PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]))
        return Qt_DockWidgetArea_PythonToCpp_QFlags_Qt_DockWidgetArea_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_DockWidgetArea_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::DockWidgetArea>*)cppOut) = ::QFlags<Qt::DockWidgetArea>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_DockWidgetArea_;
    return 0;
}
static void Qt_DockWidgetAreaSizes_PythonToCpp_Qt_DockWidgetAreaSizes(PyObject* pyIn, void* cppOut) {
    *((::Qt::DockWidgetAreaSizes*)cppOut) = (::Qt::DockWidgetAreaSizes) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_DockWidgetAreaSizes_PythonToCpp_Qt_DockWidgetAreaSizes_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX]))
        return Qt_DockWidgetAreaSizes_PythonToCpp_Qt_DockWidgetAreaSizes;
    return 0;
}
static PyObject* Qt_DockWidgetAreaSizes_CppToPython_Qt_DockWidgetAreaSizes(const void* cppIn) {
    int castCppIn = *((::Qt::DockWidgetAreaSizes*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX], castCppIn);

}

static void Qt_ToolBarArea_PythonToCpp_Qt_ToolBarArea(PyObject* pyIn, void* cppOut) {
    *((::Qt::ToolBarArea*)cppOut) = (::Qt::ToolBarArea) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ToolBarArea_PythonToCpp_Qt_ToolBarArea_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]))
        return Qt_ToolBarArea_PythonToCpp_Qt_ToolBarArea;
    return 0;
}
static PyObject* Qt_ToolBarArea_CppToPython_Qt_ToolBarArea(const void* cppIn) {
    int castCppIn = *((::Qt::ToolBarArea*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX], castCppIn);

}

static void QFlags_Qt_ToolBarArea__PythonToCpp_QFlags_Qt_ToolBarArea_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ToolBarArea>*)cppOut) = ::QFlags<Qt::ToolBarArea>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_ToolBarArea__PythonToCpp_QFlags_Qt_ToolBarArea__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]))
        return QFlags_Qt_ToolBarArea__PythonToCpp_QFlags_Qt_ToolBarArea_;
    return 0;
}
static PyObject* QFlags_Qt_ToolBarArea__CppToPython_QFlags_Qt_ToolBarArea_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::ToolBarArea>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]));

}

static void Qt_ToolBarArea_PythonToCpp_QFlags_Qt_ToolBarArea_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ToolBarArea>*)cppOut) = ::QFlags<Qt::ToolBarArea>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_ToolBarArea_PythonToCpp_QFlags_Qt_ToolBarArea__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]))
        return Qt_ToolBarArea_PythonToCpp_QFlags_Qt_ToolBarArea_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_ToolBarArea_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::ToolBarArea>*)cppOut) = ::QFlags<Qt::ToolBarArea>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_ToolBarArea__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_ToolBarArea_;
    return 0;
}
static void Qt_ToolBarAreaSizes_PythonToCpp_Qt_ToolBarAreaSizes(PyObject* pyIn, void* cppOut) {
    *((::Qt::ToolBarAreaSizes*)cppOut) = (::Qt::ToolBarAreaSizes) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ToolBarAreaSizes_PythonToCpp_Qt_ToolBarAreaSizes_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX]))
        return Qt_ToolBarAreaSizes_PythonToCpp_Qt_ToolBarAreaSizes;
    return 0;
}
static PyObject* Qt_ToolBarAreaSizes_CppToPython_Qt_ToolBarAreaSizes(const void* cppIn) {
    int castCppIn = *((::Qt::ToolBarAreaSizes*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX], castCppIn);

}

static void Qt_DateFormat_PythonToCpp_Qt_DateFormat(PyObject* pyIn, void* cppOut) {
    *((::Qt::DateFormat*)cppOut) = (::Qt::DateFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_DateFormat_PythonToCpp_Qt_DateFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]))
        return Qt_DateFormat_PythonToCpp_Qt_DateFormat;
    return 0;
}
static PyObject* Qt_DateFormat_CppToPython_Qt_DateFormat(const void* cppIn) {
    int castCppIn = *((::Qt::DateFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX], castCppIn);

}

static void Qt_TimeSpec_PythonToCpp_Qt_TimeSpec(PyObject* pyIn, void* cppOut) {
    *((::Qt::TimeSpec*)cppOut) = (::Qt::TimeSpec) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TimeSpec_PythonToCpp_Qt_TimeSpec_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]))
        return Qt_TimeSpec_PythonToCpp_Qt_TimeSpec;
    return 0;
}
static PyObject* Qt_TimeSpec_CppToPython_Qt_TimeSpec(const void* cppIn) {
    int castCppIn = *((::Qt::TimeSpec*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX], castCppIn);

}

static void Qt_DayOfWeek_PythonToCpp_Qt_DayOfWeek(PyObject* pyIn, void* cppOut) {
    *((::Qt::DayOfWeek*)cppOut) = (::Qt::DayOfWeek) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_DayOfWeek_PythonToCpp_Qt_DayOfWeek_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX]))
        return Qt_DayOfWeek_PythonToCpp_Qt_DayOfWeek;
    return 0;
}
static PyObject* Qt_DayOfWeek_CppToPython_Qt_DayOfWeek(const void* cppIn) {
    int castCppIn = *((::Qt::DayOfWeek*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX], castCppIn);

}

static void Qt_ScrollBarPolicy_PythonToCpp_Qt_ScrollBarPolicy(PyObject* pyIn, void* cppOut) {
    *((::Qt::ScrollBarPolicy*)cppOut) = (::Qt::ScrollBarPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ScrollBarPolicy_PythonToCpp_Qt_ScrollBarPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX]))
        return Qt_ScrollBarPolicy_PythonToCpp_Qt_ScrollBarPolicy;
    return 0;
}
static PyObject* Qt_ScrollBarPolicy_CppToPython_Qt_ScrollBarPolicy(const void* cppIn) {
    int castCppIn = *((::Qt::ScrollBarPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX], castCppIn);

}

static void Qt_CaseSensitivity_PythonToCpp_Qt_CaseSensitivity(PyObject* pyIn, void* cppOut) {
    *((::Qt::CaseSensitivity*)cppOut) = (::Qt::CaseSensitivity) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_CaseSensitivity_PythonToCpp_Qt_CaseSensitivity_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]))
        return Qt_CaseSensitivity_PythonToCpp_Qt_CaseSensitivity;
    return 0;
}
static PyObject* Qt_CaseSensitivity_CppToPython_Qt_CaseSensitivity(const void* cppIn) {
    int castCppIn = *((::Qt::CaseSensitivity*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX], castCppIn);

}

static void Qt_Corner_PythonToCpp_Qt_Corner(PyObject* pyIn, void* cppOut) {
    *((::Qt::Corner*)cppOut) = (::Qt::Corner) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_Corner_PythonToCpp_Qt_Corner_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]))
        return Qt_Corner_PythonToCpp_Qt_Corner;
    return 0;
}
static PyObject* Qt_Corner_CppToPython_Qt_Corner(const void* cppIn) {
    int castCppIn = *((::Qt::Corner*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX], castCppIn);

}

static void Qt_ConnectionType_PythonToCpp_Qt_ConnectionType(PyObject* pyIn, void* cppOut) {
    *((::Qt::ConnectionType*)cppOut) = (::Qt::ConnectionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ConnectionType_PythonToCpp_Qt_ConnectionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]))
        return Qt_ConnectionType_PythonToCpp_Qt_ConnectionType;
    return 0;
}
static PyObject* Qt_ConnectionType_CppToPython_Qt_ConnectionType(const void* cppIn) {
    int castCppIn = *((::Qt::ConnectionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX], castCppIn);

}

static void Qt_ShortcutContext_PythonToCpp_Qt_ShortcutContext(PyObject* pyIn, void* cppOut) {
    *((::Qt::ShortcutContext*)cppOut) = (::Qt::ShortcutContext) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ShortcutContext_PythonToCpp_Qt_ShortcutContext_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]))
        return Qt_ShortcutContext_PythonToCpp_Qt_ShortcutContext;
    return 0;
}
static PyObject* Qt_ShortcutContext_CppToPython_Qt_ShortcutContext(const void* cppIn) {
    int castCppIn = *((::Qt::ShortcutContext*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX], castCppIn);

}

static void Qt_FillRule_PythonToCpp_Qt_FillRule(PyObject* pyIn, void* cppOut) {
    *((::Qt::FillRule*)cppOut) = (::Qt::FillRule) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_FillRule_PythonToCpp_Qt_FillRule_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]))
        return Qt_FillRule_PythonToCpp_Qt_FillRule;
    return 0;
}
static PyObject* Qt_FillRule_CppToPython_Qt_FillRule(const void* cppIn) {
    int castCppIn = *((::Qt::FillRule*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX], castCppIn);

}

static void Qt_MaskMode_PythonToCpp_Qt_MaskMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::MaskMode*)cppOut) = (::Qt::MaskMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_MaskMode_PythonToCpp_Qt_MaskMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX]))
        return Qt_MaskMode_PythonToCpp_Qt_MaskMode;
    return 0;
}
static PyObject* Qt_MaskMode_CppToPython_Qt_MaskMode(const void* cppIn) {
    int castCppIn = *((::Qt::MaskMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX], castCppIn);

}

static void Qt_ClipOperation_PythonToCpp_Qt_ClipOperation(PyObject* pyIn, void* cppOut) {
    *((::Qt::ClipOperation*)cppOut) = (::Qt::ClipOperation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ClipOperation_PythonToCpp_Qt_ClipOperation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]))
        return Qt_ClipOperation_PythonToCpp_Qt_ClipOperation;
    return 0;
}
static PyObject* Qt_ClipOperation_CppToPython_Qt_ClipOperation(const void* cppIn) {
    int castCppIn = *((::Qt::ClipOperation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX], castCppIn);

}

static void Qt_ItemSelectionMode_PythonToCpp_Qt_ItemSelectionMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::ItemSelectionMode*)cppOut) = (::Qt::ItemSelectionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ItemSelectionMode_PythonToCpp_Qt_ItemSelectionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]))
        return Qt_ItemSelectionMode_PythonToCpp_Qt_ItemSelectionMode;
    return 0;
}
static PyObject* Qt_ItemSelectionMode_CppToPython_Qt_ItemSelectionMode(const void* cppIn) {
    int castCppIn = *((::Qt::ItemSelectionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX], castCppIn);

}

static void Qt_TransformationMode_PythonToCpp_Qt_TransformationMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::TransformationMode*)cppOut) = (::Qt::TransformationMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TransformationMode_PythonToCpp_Qt_TransformationMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX]))
        return Qt_TransformationMode_PythonToCpp_Qt_TransformationMode;
    return 0;
}
static PyObject* Qt_TransformationMode_CppToPython_Qt_TransformationMode(const void* cppIn) {
    int castCppIn = *((::Qt::TransformationMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX], castCppIn);

}

static void Qt_Axis_PythonToCpp_Qt_Axis(PyObject* pyIn, void* cppOut) {
    *((::Qt::Axis*)cppOut) = (::Qt::Axis) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_Axis_PythonToCpp_Qt_Axis_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX]))
        return Qt_Axis_PythonToCpp_Qt_Axis;
    return 0;
}
static PyObject* Qt_Axis_CppToPython_Qt_Axis(const void* cppIn) {
    int castCppIn = *((::Qt::Axis*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX], castCppIn);

}

static void Qt_FocusReason_PythonToCpp_Qt_FocusReason(PyObject* pyIn, void* cppOut) {
    *((::Qt::FocusReason*)cppOut) = (::Qt::FocusReason) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_FocusReason_PythonToCpp_Qt_FocusReason_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]))
        return Qt_FocusReason_PythonToCpp_Qt_FocusReason;
    return 0;
}
static PyObject* Qt_FocusReason_CppToPython_Qt_FocusReason(const void* cppIn) {
    int castCppIn = *((::Qt::FocusReason*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX], castCppIn);

}

static void Qt_ContextMenuPolicy_PythonToCpp_Qt_ContextMenuPolicy(PyObject* pyIn, void* cppOut) {
    *((::Qt::ContextMenuPolicy*)cppOut) = (::Qt::ContextMenuPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ContextMenuPolicy_PythonToCpp_Qt_ContextMenuPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX]))
        return Qt_ContextMenuPolicy_PythonToCpp_Qt_ContextMenuPolicy;
    return 0;
}
static PyObject* Qt_ContextMenuPolicy_CppToPython_Qt_ContextMenuPolicy(const void* cppIn) {
    int castCppIn = *((::Qt::ContextMenuPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX], castCppIn);

}

static void Qt_InputMethodQuery_PythonToCpp_Qt_InputMethodQuery(PyObject* pyIn, void* cppOut) {
    *((::Qt::InputMethodQuery*)cppOut) = (::Qt::InputMethodQuery) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_InputMethodQuery_PythonToCpp_Qt_InputMethodQuery_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]))
        return Qt_InputMethodQuery_PythonToCpp_Qt_InputMethodQuery;
    return 0;
}
static PyObject* Qt_InputMethodQuery_CppToPython_Qt_InputMethodQuery(const void* cppIn) {
    int castCppIn = *((::Qt::InputMethodQuery*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX], castCppIn);

}

static void Qt_InputMethodHint_PythonToCpp_Qt_InputMethodHint(PyObject* pyIn, void* cppOut) {
    *((::Qt::InputMethodHint*)cppOut) = (::Qt::InputMethodHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_InputMethodHint_PythonToCpp_Qt_InputMethodHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX]))
        return Qt_InputMethodHint_PythonToCpp_Qt_InputMethodHint;
    return 0;
}
static PyObject* Qt_InputMethodHint_CppToPython_Qt_InputMethodHint(const void* cppIn) {
    int castCppIn = *((::Qt::InputMethodHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX], castCppIn);

}

static void QFlags_Qt_InputMethodHint__PythonToCpp_QFlags_Qt_InputMethodHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::InputMethodHint>*)cppOut) = ::QFlags<Qt::InputMethodHint>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_InputMethodHint__PythonToCpp_QFlags_Qt_InputMethodHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]))
        return QFlags_Qt_InputMethodHint__PythonToCpp_QFlags_Qt_InputMethodHint_;
    return 0;
}
static PyObject* QFlags_Qt_InputMethodHint__CppToPython_QFlags_Qt_InputMethodHint_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::InputMethodHint>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]));

}

static void Qt_InputMethodHint_PythonToCpp_QFlags_Qt_InputMethodHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::InputMethodHint>*)cppOut) = ::QFlags<Qt::InputMethodHint>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_InputMethodHint_PythonToCpp_QFlags_Qt_InputMethodHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX]))
        return Qt_InputMethodHint_PythonToCpp_QFlags_Qt_InputMethodHint_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_InputMethodHint_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::InputMethodHint>*)cppOut) = ::QFlags<Qt::InputMethodHint>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_InputMethodHint__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_InputMethodHint_;
    return 0;
}
static void Qt_ToolButtonStyle_PythonToCpp_Qt_ToolButtonStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::ToolButtonStyle*)cppOut) = (::Qt::ToolButtonStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ToolButtonStyle_PythonToCpp_Qt_ToolButtonStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX]))
        return Qt_ToolButtonStyle_PythonToCpp_Qt_ToolButtonStyle;
    return 0;
}
static PyObject* Qt_ToolButtonStyle_CppToPython_Qt_ToolButtonStyle(const void* cppIn) {
    int castCppIn = *((::Qt::ToolButtonStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX], castCppIn);

}

static void Qt_LayoutDirection_PythonToCpp_Qt_LayoutDirection(PyObject* pyIn, void* cppOut) {
    *((::Qt::LayoutDirection*)cppOut) = (::Qt::LayoutDirection) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_LayoutDirection_PythonToCpp_Qt_LayoutDirection_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]))
        return Qt_LayoutDirection_PythonToCpp_Qt_LayoutDirection;
    return 0;
}
static PyObject* Qt_LayoutDirection_CppToPython_Qt_LayoutDirection(const void* cppIn) {
    int castCppIn = *((::Qt::LayoutDirection*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX], castCppIn);

}

static void Qt_AnchorPoint_PythonToCpp_Qt_AnchorPoint(PyObject* pyIn, void* cppOut) {
    *((::Qt::AnchorPoint*)cppOut) = (::Qt::AnchorPoint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_AnchorPoint_PythonToCpp_Qt_AnchorPoint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX]))
        return Qt_AnchorPoint_PythonToCpp_Qt_AnchorPoint;
    return 0;
}
static PyObject* Qt_AnchorPoint_CppToPython_Qt_AnchorPoint(const void* cppIn) {
    int castCppIn = *((::Qt::AnchorPoint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX], castCppIn);

}

static void Qt_DropAction_PythonToCpp_Qt_DropAction(PyObject* pyIn, void* cppOut) {
    *((::Qt::DropAction*)cppOut) = (::Qt::DropAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_DropAction_PythonToCpp_Qt_DropAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]))
        return Qt_DropAction_PythonToCpp_Qt_DropAction;
    return 0;
}
static PyObject* Qt_DropAction_CppToPython_Qt_DropAction(const void* cppIn) {
    int castCppIn = *((::Qt::DropAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX], castCppIn);

}

static void QFlags_Qt_DropAction__PythonToCpp_QFlags_Qt_DropAction_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::DropAction>*)cppOut) = ::QFlags<Qt::DropAction>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_DropAction__PythonToCpp_QFlags_Qt_DropAction__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]))
        return QFlags_Qt_DropAction__PythonToCpp_QFlags_Qt_DropAction_;
    return 0;
}
static PyObject* QFlags_Qt_DropAction__CppToPython_QFlags_Qt_DropAction_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::DropAction>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]));

}

static void Qt_DropAction_PythonToCpp_QFlags_Qt_DropAction_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::DropAction>*)cppOut) = ::QFlags<Qt::DropAction>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_DropAction_PythonToCpp_QFlags_Qt_DropAction__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]))
        return Qt_DropAction_PythonToCpp_QFlags_Qt_DropAction_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_DropAction_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::DropAction>*)cppOut) = ::QFlags<Qt::DropAction>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_DropAction__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_DropAction_;
    return 0;
}
static void Qt_CheckState_PythonToCpp_Qt_CheckState(PyObject* pyIn, void* cppOut) {
    *((::Qt::CheckState*)cppOut) = (::Qt::CheckState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_CheckState_PythonToCpp_Qt_CheckState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]))
        return Qt_CheckState_PythonToCpp_Qt_CheckState;
    return 0;
}
static PyObject* Qt_CheckState_CppToPython_Qt_CheckState(const void* cppIn) {
    int castCppIn = *((::Qt::CheckState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX], castCppIn);

}

static void Qt_ItemDataRole_PythonToCpp_Qt_ItemDataRole(PyObject* pyIn, void* cppOut) {
    *((::Qt::ItemDataRole*)cppOut) = (::Qt::ItemDataRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ItemDataRole_PythonToCpp_Qt_ItemDataRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX]))
        return Qt_ItemDataRole_PythonToCpp_Qt_ItemDataRole;
    return 0;
}
static PyObject* Qt_ItemDataRole_CppToPython_Qt_ItemDataRole(const void* cppIn) {
    int castCppIn = *((::Qt::ItemDataRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX], castCppIn);

}

static void Qt_ItemFlag_PythonToCpp_Qt_ItemFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::ItemFlag*)cppOut) = (::Qt::ItemFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_ItemFlag_PythonToCpp_Qt_ItemFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX]))
        return Qt_ItemFlag_PythonToCpp_Qt_ItemFlag;
    return 0;
}
static PyObject* Qt_ItemFlag_CppToPython_Qt_ItemFlag(const void* cppIn) {
    int castCppIn = *((::Qt::ItemFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX], castCppIn);

}

static void QFlags_Qt_ItemFlag__PythonToCpp_QFlags_Qt_ItemFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ItemFlag>*)cppOut) = ::QFlags<Qt::ItemFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_ItemFlag__PythonToCpp_QFlags_Qt_ItemFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]))
        return QFlags_Qt_ItemFlag__PythonToCpp_QFlags_Qt_ItemFlag_;
    return 0;
}
static PyObject* QFlags_Qt_ItemFlag__CppToPython_QFlags_Qt_ItemFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::ItemFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]));

}

static void Qt_ItemFlag_PythonToCpp_QFlags_Qt_ItemFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::ItemFlag>*)cppOut) = ::QFlags<Qt::ItemFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_ItemFlag_PythonToCpp_QFlags_Qt_ItemFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX]))
        return Qt_ItemFlag_PythonToCpp_QFlags_Qt_ItemFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_ItemFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::ItemFlag>*)cppOut) = ::QFlags<Qt::ItemFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_ItemFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_ItemFlag_;
    return 0;
}
static void Qt_MatchFlag_PythonToCpp_Qt_MatchFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::MatchFlag*)cppOut) = (::Qt::MatchFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_MatchFlag_PythonToCpp_Qt_MatchFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX]))
        return Qt_MatchFlag_PythonToCpp_Qt_MatchFlag;
    return 0;
}
static PyObject* Qt_MatchFlag_CppToPython_Qt_MatchFlag(const void* cppIn) {
    int castCppIn = *((::Qt::MatchFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX], castCppIn);

}

static void QFlags_Qt_MatchFlag__PythonToCpp_QFlags_Qt_MatchFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::MatchFlag>*)cppOut) = ::QFlags<Qt::MatchFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_MatchFlag__PythonToCpp_QFlags_Qt_MatchFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]))
        return QFlags_Qt_MatchFlag__PythonToCpp_QFlags_Qt_MatchFlag_;
    return 0;
}
static PyObject* QFlags_Qt_MatchFlag__CppToPython_QFlags_Qt_MatchFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::MatchFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]));

}

static void Qt_MatchFlag_PythonToCpp_QFlags_Qt_MatchFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::MatchFlag>*)cppOut) = ::QFlags<Qt::MatchFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_MatchFlag_PythonToCpp_QFlags_Qt_MatchFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX]))
        return Qt_MatchFlag_PythonToCpp_QFlags_Qt_MatchFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_MatchFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::MatchFlag>*)cppOut) = ::QFlags<Qt::MatchFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_MatchFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_MatchFlag_;
    return 0;
}
static void Qt_WindowModality_PythonToCpp_Qt_WindowModality(PyObject* pyIn, void* cppOut) {
    *((::Qt::WindowModality*)cppOut) = (::Qt::WindowModality) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WindowModality_PythonToCpp_Qt_WindowModality_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX]))
        return Qt_WindowModality_PythonToCpp_Qt_WindowModality;
    return 0;
}
static PyObject* Qt_WindowModality_CppToPython_Qt_WindowModality(const void* cppIn) {
    int castCppIn = *((::Qt::WindowModality*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX], castCppIn);

}

static void Qt_TextInteractionFlag_PythonToCpp_Qt_TextInteractionFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::TextInteractionFlag*)cppOut) = (::Qt::TextInteractionFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TextInteractionFlag_PythonToCpp_Qt_TextInteractionFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX]))
        return Qt_TextInteractionFlag_PythonToCpp_Qt_TextInteractionFlag;
    return 0;
}
static PyObject* Qt_TextInteractionFlag_CppToPython_Qt_TextInteractionFlag(const void* cppIn) {
    int castCppIn = *((::Qt::TextInteractionFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX], castCppIn);

}

static void QFlags_Qt_TextInteractionFlag__PythonToCpp_QFlags_Qt_TextInteractionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::TextInteractionFlag>*)cppOut) = ::QFlags<Qt::TextInteractionFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_TextInteractionFlag__PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]))
        return QFlags_Qt_TextInteractionFlag__PythonToCpp_QFlags_Qt_TextInteractionFlag_;
    return 0;
}
static PyObject* QFlags_Qt_TextInteractionFlag__CppToPython_QFlags_Qt_TextInteractionFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::TextInteractionFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]));

}

static void Qt_TextInteractionFlag_PythonToCpp_QFlags_Qt_TextInteractionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::TextInteractionFlag>*)cppOut) = ::QFlags<Qt::TextInteractionFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_TextInteractionFlag_PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX]))
        return Qt_TextInteractionFlag_PythonToCpp_QFlags_Qt_TextInteractionFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_TextInteractionFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::TextInteractionFlag>*)cppOut) = ::QFlags<Qt::TextInteractionFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_TextInteractionFlag_;
    return 0;
}
static void Qt_EventPriority_PythonToCpp_Qt_EventPriority(PyObject* pyIn, void* cppOut) {
    *((::Qt::EventPriority*)cppOut) = (::Qt::EventPriority) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_EventPriority_PythonToCpp_Qt_EventPriority_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX]))
        return Qt_EventPriority_PythonToCpp_Qt_EventPriority;
    return 0;
}
static PyObject* Qt_EventPriority_CppToPython_Qt_EventPriority(const void* cppIn) {
    int castCppIn = *((::Qt::EventPriority*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX], castCppIn);

}

static void Qt_SizeHint_PythonToCpp_Qt_SizeHint(PyObject* pyIn, void* cppOut) {
    *((::Qt::SizeHint*)cppOut) = (::Qt::SizeHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_SizeHint_PythonToCpp_Qt_SizeHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX]))
        return Qt_SizeHint_PythonToCpp_Qt_SizeHint;
    return 0;
}
static PyObject* Qt_SizeHint_CppToPython_Qt_SizeHint(const void* cppIn) {
    int castCppIn = *((::Qt::SizeHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX], castCppIn);

}

static void Qt_WindowFrameSection_PythonToCpp_Qt_WindowFrameSection(PyObject* pyIn, void* cppOut) {
    *((::Qt::WindowFrameSection*)cppOut) = (::Qt::WindowFrameSection) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WindowFrameSection_PythonToCpp_Qt_WindowFrameSection_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX]))
        return Qt_WindowFrameSection_PythonToCpp_Qt_WindowFrameSection;
    return 0;
}
static PyObject* Qt_WindowFrameSection_CppToPython_Qt_WindowFrameSection(const void* cppIn) {
    int castCppIn = *((::Qt::WindowFrameSection*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX], castCppIn);

}

static void Qt_CoordinateSystem_PythonToCpp_Qt_CoordinateSystem(PyObject* pyIn, void* cppOut) {
    *((::Qt::CoordinateSystem*)cppOut) = (::Qt::CoordinateSystem) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_CoordinateSystem_PythonToCpp_Qt_CoordinateSystem_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX]))
        return Qt_CoordinateSystem_PythonToCpp_Qt_CoordinateSystem;
    return 0;
}
static PyObject* Qt_CoordinateSystem_CppToPython_Qt_CoordinateSystem(const void* cppIn) {
    int castCppIn = *((::Qt::CoordinateSystem*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX], castCppIn);

}

static void Qt_TouchPointState_PythonToCpp_Qt_TouchPointState(PyObject* pyIn, void* cppOut) {
    *((::Qt::TouchPointState*)cppOut) = (::Qt::TouchPointState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_TouchPointState_PythonToCpp_Qt_TouchPointState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX]))
        return Qt_TouchPointState_PythonToCpp_Qt_TouchPointState;
    return 0;
}
static PyObject* Qt_TouchPointState_CppToPython_Qt_TouchPointState(const void* cppIn) {
    int castCppIn = *((::Qt::TouchPointState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX], castCppIn);

}

static void Qt_GestureState_PythonToCpp_Qt_GestureState(PyObject* pyIn, void* cppOut) {
    *((::Qt::GestureState*)cppOut) = (::Qt::GestureState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_GestureState_PythonToCpp_Qt_GestureState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX]))
        return Qt_GestureState_PythonToCpp_Qt_GestureState;
    return 0;
}
static PyObject* Qt_GestureState_CppToPython_Qt_GestureState(const void* cppIn) {
    int castCppIn = *((::Qt::GestureState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX], castCppIn);

}

static void Qt_GestureType_PythonToCpp_Qt_GestureType(PyObject* pyIn, void* cppOut) {
    *((::Qt::GestureType*)cppOut) = (::Qt::GestureType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_GestureType_PythonToCpp_Qt_GestureType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]))
        return Qt_GestureType_PythonToCpp_Qt_GestureType;
    return 0;
}
static PyObject* Qt_GestureType_CppToPython_Qt_GestureType(const void* cppIn) {
    int castCppIn = *((::Qt::GestureType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX], castCppIn);

}

static void Qt_GestureFlag_PythonToCpp_Qt_GestureFlag(PyObject* pyIn, void* cppOut) {
    *((::Qt::GestureFlag*)cppOut) = (::Qt::GestureFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_GestureFlag_PythonToCpp_Qt_GestureFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX]))
        return Qt_GestureFlag_PythonToCpp_Qt_GestureFlag;
    return 0;
}
static PyObject* Qt_GestureFlag_CppToPython_Qt_GestureFlag(const void* cppIn) {
    int castCppIn = *((::Qt::GestureFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX], castCppIn);

}

static void QFlags_Qt_GestureFlag__PythonToCpp_QFlags_Qt_GestureFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::GestureFlag>*)cppOut) = ::QFlags<Qt::GestureFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Qt_GestureFlag__PythonToCpp_QFlags_Qt_GestureFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]))
        return QFlags_Qt_GestureFlag__PythonToCpp_QFlags_Qt_GestureFlag_;
    return 0;
}
static PyObject* QFlags_Qt_GestureFlag__CppToPython_QFlags_Qt_GestureFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<Qt::GestureFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]));

}

static void Qt_GestureFlag_PythonToCpp_QFlags_Qt_GestureFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Qt::GestureFlag>*)cppOut) = ::QFlags<Qt::GestureFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Qt_GestureFlag_PythonToCpp_QFlags_Qt_GestureFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX]))
        return Qt_GestureFlag_PythonToCpp_QFlags_Qt_GestureFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_Qt_GestureFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Qt::GestureFlag>*)cppOut) = ::QFlags<Qt::GestureFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Qt_GestureFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Qt_GestureFlag_;
    return 0;
}
static void Qt_NavigationMode_PythonToCpp_Qt_NavigationMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::NavigationMode*)cppOut) = (::Qt::NavigationMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_NavigationMode_PythonToCpp_Qt_NavigationMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX]))
        return Qt_NavigationMode_PythonToCpp_Qt_NavigationMode;
    return 0;
}
static PyObject* Qt_NavigationMode_CppToPython_Qt_NavigationMode(const void* cppIn) {
    int castCppIn = *((::Qt::NavigationMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX], castCppIn);

}

static void Qt_CursorMoveStyle_PythonToCpp_Qt_CursorMoveStyle(PyObject* pyIn, void* cppOut) {
    *((::Qt::CursorMoveStyle*)cppOut) = (::Qt::CursorMoveStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_CursorMoveStyle_PythonToCpp_Qt_CursorMoveStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX]))
        return Qt_CursorMoveStyle_PythonToCpp_Qt_CursorMoveStyle;
    return 0;
}
static PyObject* Qt_CursorMoveStyle_CppToPython_Qt_CursorMoveStyle(const void* cppIn) {
    int castCppIn = *((::Qt::CursorMoveStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX], castCppIn);

}

static void Qt_HitTestAccuracy_PythonToCpp_Qt_HitTestAccuracy(PyObject* pyIn, void* cppOut) {
    *((::Qt::HitTestAccuracy*)cppOut) = (::Qt::HitTestAccuracy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_HitTestAccuracy_PythonToCpp_Qt_HitTestAccuracy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX]))
        return Qt_HitTestAccuracy_PythonToCpp_Qt_HitTestAccuracy;
    return 0;
}
static PyObject* Qt_HitTestAccuracy_CppToPython_Qt_HitTestAccuracy(const void* cppIn) {
    int castCppIn = *((::Qt::HitTestAccuracy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX], castCppIn);

}

static void Qt_WhiteSpaceMode_PythonToCpp_Qt_WhiteSpaceMode(PyObject* pyIn, void* cppOut) {
    *((::Qt::WhiteSpaceMode*)cppOut) = (::Qt::WhiteSpaceMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Qt_WhiteSpaceMode_PythonToCpp_Qt_WhiteSpaceMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX]))
        return Qt_WhiteSpaceMode_PythonToCpp_Qt_WhiteSpaceMode;
    return 0;
}
static PyObject* Qt_WhiteSpaceMode_CppToPython_Qt_WhiteSpaceMode(const void* cppIn) {
    int castCppIn = *((::Qt::WhiteSpaceMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX], castCppIn);

}

void init_Qt(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Qt_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Qt", "Qt",
        &Sbk_Qt_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'GlobalColor'.
    SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "GlobalColor",
        "PySide.QtCore.Qt.GlobalColor",
        "Qt::GlobalColor");
    if (!SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "color0", (long) Qt::color0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "color1", (long) Qt::color1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "black", (long) Qt::black))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "white", (long) Qt::white))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkGray", (long) Qt::darkGray))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "gray", (long) Qt::gray))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "lightGray", (long) Qt::lightGray))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "red", (long) Qt::red))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "green", (long) Qt::green))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "blue", (long) Qt::blue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "cyan", (long) Qt::cyan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "magenta", (long) Qt::magenta))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "yellow", (long) Qt::yellow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkRed", (long) Qt::darkRed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkGreen", (long) Qt::darkGreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkBlue", (long) Qt::darkBlue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkCyan", (long) Qt::darkCyan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkMagenta", (long) Qt::darkMagenta))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "darkYellow", (long) Qt::darkYellow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
        &Sbk_Qt_Type, "transparent", (long) Qt::transparent))
        return ;
    // Register converter for enum 'Qt::GlobalColor'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX],
            Qt_GlobalColor_CppToPython_Qt_GlobalColor);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_GlobalColor_PythonToCpp_Qt_GlobalColor,
            is_Qt_GlobalColor_PythonToCpp_Qt_GlobalColor_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::GlobalColor");
        Shiboken::Conversions::registerConverterName(converter, "GlobalColor");
    }
    // End of 'GlobalColor' enum.

    // Initialization of enum 'KeyboardModifier'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX] = PySide::QFlags::create("KeyboardModifiers", &SbkPySide_QtCore_Qt_KeyboardModifier_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "KeyboardModifier",
        "PySide.QtCore.Qt.KeyboardModifier",
        "Qt::KeyboardModifier",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "NoModifier", (long) Qt::NoModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "ShiftModifier", (long) Qt::ShiftModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "ControlModifier", (long) Qt::ControlModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "AltModifier", (long) Qt::AltModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "MetaModifier", (long) Qt::MetaModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "KeypadModifier", (long) Qt::KeypadModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "GroupSwitchModifier", (long) Qt::GroupSwitchModifier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
        &Sbk_Qt_Type, "KeyboardModifierMask", (long) Qt::KeyboardModifierMask))
        return ;
    // Register converter for enum 'Qt::KeyboardModifier'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX],
            Qt_KeyboardModifier_CppToPython_Qt_KeyboardModifier);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_KeyboardModifier_PythonToCpp_Qt_KeyboardModifier,
            is_Qt_KeyboardModifier_PythonToCpp_Qt_KeyboardModifier_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_KEYBOARDMODIFIER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::KeyboardModifier");
        Shiboken::Conversions::registerConverterName(converter, "KeyboardModifier");
    }
    // Register converter for flag 'QFlags<Qt::KeyboardModifier>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX],
            QFlags_Qt_KeyboardModifier__CppToPython_QFlags_Qt_KeyboardModifier_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_KeyboardModifier_PythonToCpp_QFlags_Qt_KeyboardModifier_,
            is_Qt_KeyboardModifier_PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_KeyboardModifier__PythonToCpp_QFlags_Qt_KeyboardModifier_,
            is_QFlags_Qt_KeyboardModifier__PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_KeyboardModifier_,
            is_number_PythonToCpp_QFlags_Qt_KeyboardModifier__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::KeyboardModifier>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<KeyboardModifier>");
    }
    // End of 'KeyboardModifier' enum/flags.

    // Initialization of enum 'Modifier'.
    SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "Modifier",
        "PySide.QtCore.Qt.Modifier",
        "Qt::Modifier");
    if (!SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "META", (long) Qt::META))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "SHIFT", (long) Qt::SHIFT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "CTRL", (long) Qt::CTRL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "ALT", (long) Qt::ALT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "MODIFIER_MASK", (long) Qt::MODIFIER_MASK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
        &Sbk_Qt_Type, "UNICODE_ACCEL", (long) Qt::UNICODE_ACCEL))
        return ;
    // Register converter for enum 'Qt::Modifier'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX],
            Qt_Modifier_CppToPython_Qt_Modifier);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Modifier_PythonToCpp_Qt_Modifier,
            is_Qt_Modifier_PythonToCpp_Qt_Modifier_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MODIFIER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::Modifier");
        Shiboken::Conversions::registerConverterName(converter, "Modifier");
    }
    // End of 'Modifier' enum.

    // Initialization of enum 'MouseButton'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX] = PySide::QFlags::create("MouseButtons", &SbkPySide_QtCore_Qt_MouseButton_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "MouseButton",
        "PySide.QtCore.Qt.MouseButton",
        "Qt::MouseButton",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "NoButton", (long) Qt::NoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "LeftButton", (long) Qt::LeftButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "RightButton", (long) Qt::RightButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "MidButton", (long) Qt::MidButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "MiddleButton", (long) Qt::MiddleButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "XButton1", (long) Qt::XButton1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "XButton2", (long) Qt::XButton2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
        &Sbk_Qt_Type, "MouseButtonMask", (long) Qt::MouseButtonMask))
        return ;
    // Register converter for enum 'Qt::MouseButton'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX],
            Qt_MouseButton_CppToPython_Qt_MouseButton);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_MouseButton_PythonToCpp_Qt_MouseButton,
            is_Qt_MouseButton_PythonToCpp_Qt_MouseButton_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::MouseButton");
        Shiboken::Conversions::registerConverterName(converter, "MouseButton");
    }
    // Register converter for flag 'QFlags<Qt::MouseButton>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX],
            QFlags_Qt_MouseButton__CppToPython_QFlags_Qt_MouseButton_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_MouseButton_PythonToCpp_QFlags_Qt_MouseButton_,
            is_Qt_MouseButton_PythonToCpp_QFlags_Qt_MouseButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_MouseButton__PythonToCpp_QFlags_Qt_MouseButton_,
            is_QFlags_Qt_MouseButton__PythonToCpp_QFlags_Qt_MouseButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_MouseButton_,
            is_number_PythonToCpp_QFlags_Qt_MouseButton__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::MouseButton>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<MouseButton>");
    }
    // End of 'MouseButton' enum/flags.

    // Initialization of enum 'Orientation'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX] = PySide::QFlags::create("Orientations", &SbkPySide_QtCore_Qt_Orientation_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "Orientation",
        "PySide.QtCore.Qt.Orientation",
        "Qt::Orientation",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX],
        &Sbk_Qt_Type, "Horizontal", (long) Qt::Horizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX],
        &Sbk_Qt_Type, "Vertical", (long) Qt::Vertical))
        return ;
    // Register converter for enum 'Qt::Orientation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX],
            Qt_Orientation_CppToPython_Qt_Orientation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Orientation_PythonToCpp_Qt_Orientation,
            is_Qt_Orientation_PythonToCpp_Qt_Orientation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::Orientation");
        Shiboken::Conversions::registerConverterName(converter, "Orientation");
    }
    // Register converter for flag 'QFlags<Qt::Orientation>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX],
            QFlags_Qt_Orientation__CppToPython_QFlags_Qt_Orientation_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Orientation_PythonToCpp_QFlags_Qt_Orientation_,
            is_Qt_Orientation_PythonToCpp_QFlags_Qt_Orientation__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_Orientation__PythonToCpp_QFlags_Qt_Orientation_,
            is_QFlags_Qt_Orientation__PythonToCpp_QFlags_Qt_Orientation__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_Orientation_,
            is_number_PythonToCpp_QFlags_Qt_Orientation__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::Orientation>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Orientation>");
    }
    // End of 'Orientation' enum/flags.

    // Initialization of enum 'FocusPolicy'.
    SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "FocusPolicy",
        "PySide.QtCore.Qt.FocusPolicy",
        "Qt::FocusPolicy");
    if (!SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
        &Sbk_Qt_Type, "NoFocus", (long) Qt::NoFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
        &Sbk_Qt_Type, "TabFocus", (long) Qt::TabFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
        &Sbk_Qt_Type, "ClickFocus", (long) Qt::ClickFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
        &Sbk_Qt_Type, "StrongFocus", (long) Qt::StrongFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
        &Sbk_Qt_Type, "WheelFocus", (long) Qt::WheelFocus))
        return ;
    // Register converter for enum 'Qt::FocusPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX],
            Qt_FocusPolicy_CppToPython_Qt_FocusPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_FocusPolicy_PythonToCpp_Qt_FocusPolicy,
            is_Qt_FocusPolicy_PythonToCpp_Qt_FocusPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::FocusPolicy");
        Shiboken::Conversions::registerConverterName(converter, "FocusPolicy");
    }
    // End of 'FocusPolicy' enum.

    // Initialization of enum 'SortOrder'.
    SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "SortOrder",
        "PySide.QtCore.Qt.SortOrder",
        "Qt::SortOrder");
    if (!SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX],
        &Sbk_Qt_Type, "AscendingOrder", (long) Qt::AscendingOrder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX],
        &Sbk_Qt_Type, "DescendingOrder", (long) Qt::DescendingOrder))
        return ;
    // Register converter for enum 'Qt::SortOrder'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX],
            Qt_SortOrder_CppToPython_Qt_SortOrder);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_SortOrder_PythonToCpp_Qt_SortOrder,
            is_Qt_SortOrder_PythonToCpp_Qt_SortOrder_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::SortOrder");
        Shiboken::Conversions::registerConverterName(converter, "SortOrder");
    }
    // End of 'SortOrder' enum.

    // Initialization of enum 'TileRule'.
    SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TileRule",
        "PySide.QtCore.Qt.TileRule",
        "Qt::TileRule");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX],
        &Sbk_Qt_Type, "StretchTile", (long) Qt::StretchTile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX],
        &Sbk_Qt_Type, "RepeatTile", (long) Qt::RepeatTile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX],
        &Sbk_Qt_Type, "RoundTile", (long) Qt::RoundTile))
        return ;
    // Register converter for enum 'Qt::TileRule'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX],
            Qt_TileRule_CppToPython_Qt_TileRule);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TileRule_PythonToCpp_Qt_TileRule,
            is_Qt_TileRule_PythonToCpp_Qt_TileRule_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TileRule");
        Shiboken::Conversions::registerConverterName(converter, "TileRule");
    }
    // End of 'TileRule' enum.

    // Initialization of enum 'AlignmentFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX] = PySide::QFlags::create("Alignment", &SbkPySide_QtCore_Qt_AlignmentFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "AlignmentFlag",
        "PySide.QtCore.Qt.AlignmentFlag",
        "Qt::AlignmentFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignLeft", (long) Qt::AlignLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignLeading", (long) Qt::AlignLeading))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignRight", (long) Qt::AlignRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignTrailing", (long) Qt::AlignTrailing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignHCenter", (long) Qt::AlignHCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignJustify", (long) Qt::AlignJustify))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignAbsolute", (long) Qt::AlignAbsolute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignHorizontal_Mask", (long) Qt::AlignHorizontal_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignTop", (long) Qt::AlignTop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignBottom", (long) Qt::AlignBottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignVCenter", (long) Qt::AlignVCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignVertical_Mask", (long) Qt::AlignVertical_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
        &Sbk_Qt_Type, "AlignCenter", (long) Qt::AlignCenter))
        return ;
    // Register converter for enum 'Qt::AlignmentFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX],
            Qt_AlignmentFlag_CppToPython_Qt_AlignmentFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_AlignmentFlag_PythonToCpp_Qt_AlignmentFlag,
            is_Qt_AlignmentFlag_PythonToCpp_Qt_AlignmentFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ALIGNMENTFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::AlignmentFlag");
        Shiboken::Conversions::registerConverterName(converter, "AlignmentFlag");
    }
    // Register converter for flag 'QFlags<Qt::AlignmentFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX],
            QFlags_Qt_AlignmentFlag__CppToPython_QFlags_Qt_AlignmentFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_AlignmentFlag_PythonToCpp_QFlags_Qt_AlignmentFlag_,
            is_Qt_AlignmentFlag_PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_AlignmentFlag__PythonToCpp_QFlags_Qt_AlignmentFlag_,
            is_QFlags_Qt_AlignmentFlag__PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_AlignmentFlag_,
            is_number_PythonToCpp_QFlags_Qt_AlignmentFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::AlignmentFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<AlignmentFlag>");
    }
    // End of 'AlignmentFlag' enum/flags.

    // Initialization of enum 'TextFlag'.
    SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TextFlag",
        "PySide.QtCore.Qt.TextFlag",
        "Qt::TextFlag");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextSingleLine", (long) Qt::TextSingleLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextDontClip", (long) Qt::TextDontClip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextExpandTabs", (long) Qt::TextExpandTabs))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextShowMnemonic", (long) Qt::TextShowMnemonic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextWordWrap", (long) Qt::TextWordWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextWrapAnywhere", (long) Qt::TextWrapAnywhere))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextDontPrint", (long) Qt::TextDontPrint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextIncludeTrailingSpaces", (long) Qt::TextIncludeTrailingSpaces))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextHideMnemonic", (long) Qt::TextHideMnemonic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextJustificationForced", (long) Qt::TextJustificationForced))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextForceLeftToRight", (long) Qt::TextForceLeftToRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextForceRightToLeft", (long) Qt::TextForceRightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextLongestVariant", (long) Qt::TextLongestVariant))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
        &Sbk_Qt_Type, "TextBypassShaping", (long) Qt::TextBypassShaping))
        return ;
    // Register converter for enum 'Qt::TextFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX],
            Qt_TextFlag_CppToPython_Qt_TextFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TextFlag_PythonToCpp_Qt_TextFlag,
            is_Qt_TextFlag_PythonToCpp_Qt_TextFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TextFlag");
        Shiboken::Conversions::registerConverterName(converter, "TextFlag");
    }
    // End of 'TextFlag' enum.

    // Initialization of enum 'TextElideMode'.
    SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TextElideMode",
        "PySide.QtCore.Qt.TextElideMode",
        "Qt::TextElideMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX],
        &Sbk_Qt_Type, "ElideLeft", (long) Qt::ElideLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX],
        &Sbk_Qt_Type, "ElideRight", (long) Qt::ElideRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX],
        &Sbk_Qt_Type, "ElideMiddle", (long) Qt::ElideMiddle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX],
        &Sbk_Qt_Type, "ElideNone", (long) Qt::ElideNone))
        return ;
    // Register converter for enum 'Qt::TextElideMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX],
            Qt_TextElideMode_CppToPython_Qt_TextElideMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TextElideMode_PythonToCpp_Qt_TextElideMode,
            is_Qt_TextElideMode_PythonToCpp_Qt_TextElideMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TextElideMode");
        Shiboken::Conversions::registerConverterName(converter, "TextElideMode");
    }
    // End of 'TextElideMode' enum.

    // Initialization of enum 'WindowType'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX] = PySide::QFlags::create("WindowFlags", &SbkPySide_QtCore_Qt_WindowType_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WindowType",
        "PySide.QtCore.Qt.WindowType",
        "Qt::WindowType",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Widget", (long) Qt::Widget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Window", (long) Qt::Window))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Dialog", (long) Qt::Dialog))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Sheet", (long) Qt::Sheet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Drawer", (long) Qt::Drawer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Popup", (long) Qt::Popup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Tool", (long) Qt::Tool))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "ToolTip", (long) Qt::ToolTip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "SplashScreen", (long) Qt::SplashScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "Desktop", (long) Qt::Desktop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "SubWindow", (long) Qt::SubWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowType_Mask", (long) Qt::WindowType_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "MSWindowsFixedSizeDialogHint", (long) Qt::MSWindowsFixedSizeDialogHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "MSWindowsOwnDC", (long) Qt::MSWindowsOwnDC))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "X11BypassWindowManagerHint", (long) Qt::X11BypassWindowManagerHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "FramelessWindowHint", (long) Qt::FramelessWindowHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowTitleHint", (long) Qt::WindowTitleHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowSystemMenuHint", (long) Qt::WindowSystemMenuHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowMinimizeButtonHint", (long) Qt::WindowMinimizeButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowMaximizeButtonHint", (long) Qt::WindowMaximizeButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowMinMaxButtonsHint", (long) Qt::WindowMinMaxButtonsHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowContextHelpButtonHint", (long) Qt::WindowContextHelpButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowShadeButtonHint", (long) Qt::WindowShadeButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowStaysOnTopHint", (long) Qt::WindowStaysOnTopHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "CustomizeWindowHint", (long) Qt::CustomizeWindowHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowStaysOnBottomHint", (long) Qt::WindowStaysOnBottomHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowCloseButtonHint", (long) Qt::WindowCloseButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "MacWindowToolBarButtonHint", (long) Qt::MacWindowToolBarButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "BypassGraphicsProxyWidget", (long) Qt::BypassGraphicsProxyWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowOkButtonHint", (long) Qt::WindowOkButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowCancelButtonHint", (long) Qt::WindowCancelButtonHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowSoftkeysVisibleHint", (long) Qt::WindowSoftkeysVisibleHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
        &Sbk_Qt_Type, "WindowSoftkeysRespondHint", (long) Qt::WindowSoftkeysRespondHint))
        return ;
    // Register converter for enum 'Qt::WindowType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX],
            Qt_WindowType_CppToPython_Qt_WindowType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowType_PythonToCpp_Qt_WindowType,
            is_Qt_WindowType_PythonToCpp_Qt_WindowType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WindowType");
        Shiboken::Conversions::registerConverterName(converter, "WindowType");
    }
    // Register converter for flag 'QFlags<Qt::WindowType>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX],
            QFlags_Qt_WindowType__CppToPython_QFlags_Qt_WindowType_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowType_PythonToCpp_QFlags_Qt_WindowType_,
            is_Qt_WindowType_PythonToCpp_QFlags_Qt_WindowType__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_WindowType__PythonToCpp_QFlags_Qt_WindowType_,
            is_QFlags_Qt_WindowType__PythonToCpp_QFlags_Qt_WindowType__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_WindowType_,
            is_number_PythonToCpp_QFlags_Qt_WindowType__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::WindowType>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<WindowType>");
    }
    // End of 'WindowType' enum/flags.

    // Initialization of enum 'WindowState'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX] = PySide::QFlags::create("WindowStates", &SbkPySide_QtCore_Qt_WindowState_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WindowState",
        "PySide.QtCore.Qt.WindowState",
        "Qt::WindowState",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
        &Sbk_Qt_Type, "WindowNoState", (long) Qt::WindowNoState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
        &Sbk_Qt_Type, "WindowMinimized", (long) Qt::WindowMinimized))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
        &Sbk_Qt_Type, "WindowMaximized", (long) Qt::WindowMaximized))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
        &Sbk_Qt_Type, "WindowFullScreen", (long) Qt::WindowFullScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
        &Sbk_Qt_Type, "WindowActive", (long) Qt::WindowActive))
        return ;
    // Register converter for enum 'Qt::WindowState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX],
            Qt_WindowState_CppToPython_Qt_WindowState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowState_PythonToCpp_Qt_WindowState,
            is_Qt_WindowState_PythonToCpp_Qt_WindowState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WindowState");
        Shiboken::Conversions::registerConverterName(converter, "WindowState");
    }
    // Register converter for flag 'QFlags<Qt::WindowState>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX],
            QFlags_Qt_WindowState__CppToPython_QFlags_Qt_WindowState_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowState_PythonToCpp_QFlags_Qt_WindowState_,
            is_Qt_WindowState_PythonToCpp_QFlags_Qt_WindowState__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_WindowState__PythonToCpp_QFlags_Qt_WindowState_,
            is_QFlags_Qt_WindowState__PythonToCpp_QFlags_Qt_WindowState__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_WindowState_,
            is_number_PythonToCpp_QFlags_Qt_WindowState__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWSTATE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::WindowState>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<WindowState>");
    }
    // End of 'WindowState' enum/flags.

    // Initialization of enum 'WidgetAttribute'.
    SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WidgetAttribute",
        "PySide.QtCore.Qt.WidgetAttribute",
        "Qt::WidgetAttribute");
    if (!SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_Disabled", (long) Qt::WA_Disabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_UnderMouse", (long) Qt::WA_UnderMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MouseTracking", (long) Qt::WA_MouseTracking))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ContentsPropagated", (long) Qt::WA_ContentsPropagated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_OpaquePaintEvent", (long) Qt::WA_OpaquePaintEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoBackground", (long) Qt::WA_NoBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_StaticContents", (long) Qt::WA_StaticContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_LaidOut", (long) Qt::WA_LaidOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PaintOnScreen", (long) Qt::WA_PaintOnScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoSystemBackground", (long) Qt::WA_NoSystemBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_UpdatesDisabled", (long) Qt::WA_UpdatesDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_Mapped", (long) Qt::WA_Mapped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacNoClickThrough", (long) Qt::WA_MacNoClickThrough))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PaintOutsidePaintEvent", (long) Qt::WA_PaintOutsidePaintEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_InputMethodEnabled", (long) Qt::WA_InputMethodEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_Visible", (long) Qt::WA_WState_Visible))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_Hidden", (long) Qt::WA_WState_Hidden))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ForceDisabled", (long) Qt::WA_ForceDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_KeyCompression", (long) Qt::WA_KeyCompression))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PendingMoveEvent", (long) Qt::WA_PendingMoveEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PendingResizeEvent", (long) Qt::WA_PendingResizeEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetPalette", (long) Qt::WA_SetPalette))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetFont", (long) Qt::WA_SetFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetCursor", (long) Qt::WA_SetCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoChildEventsFromChildren", (long) Qt::WA_NoChildEventsFromChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WindowModified", (long) Qt::WA_WindowModified))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_Resized", (long) Qt::WA_Resized))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_Moved", (long) Qt::WA_Moved))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PendingUpdate", (long) Qt::WA_PendingUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_InvalidSize", (long) Qt::WA_InvalidSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacBrushedMetal", (long) Qt::WA_MacBrushedMetal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacMetalStyle", (long) Qt::WA_MacMetalStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_CustomWhatsThis", (long) Qt::WA_CustomWhatsThis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_LayoutOnEntireRect", (long) Qt::WA_LayoutOnEntireRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_OutsideWSRange", (long) Qt::WA_OutsideWSRange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_GrabbedShortcut", (long) Qt::WA_GrabbedShortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_TransparentForMouseEvents", (long) Qt::WA_TransparentForMouseEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_PaintUnclipped", (long) Qt::WA_PaintUnclipped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetWindowIcon", (long) Qt::WA_SetWindowIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoMouseReplay", (long) Qt::WA_NoMouseReplay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_DeleteOnClose", (long) Qt::WA_DeleteOnClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_RightToLeft", (long) Qt::WA_RightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetLayoutDirection", (long) Qt::WA_SetLayoutDirection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoChildEventsForParent", (long) Qt::WA_NoChildEventsForParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ForceUpdatesDisabled", (long) Qt::WA_ForceUpdatesDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_Created", (long) Qt::WA_WState_Created))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_CompressKeys", (long) Qt::WA_WState_CompressKeys))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_InPaintEvent", (long) Qt::WA_WState_InPaintEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_Reparented", (long) Qt::WA_WState_Reparented))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_ConfigPending", (long) Qt::WA_WState_ConfigPending))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_Polished", (long) Qt::WA_WState_Polished))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_DND", (long) Qt::WA_WState_DND))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_OwnSizePolicy", (long) Qt::WA_WState_OwnSizePolicy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_ExplicitShowHide", (long) Qt::WA_WState_ExplicitShowHide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ShowModal", (long) Qt::WA_ShowModal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MouseNoMask", (long) Qt::WA_MouseNoMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_GroupLeader", (long) Qt::WA_GroupLeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoMousePropagation", (long) Qt::WA_NoMousePropagation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_Hover", (long) Qt::WA_Hover))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_InputMethodTransparent", (long) Qt::WA_InputMethodTransparent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_QuitOnClose", (long) Qt::WA_QuitOnClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_KeyboardFocusChange", (long) Qt::WA_KeyboardFocusChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_AcceptDrops", (long) Qt::WA_AcceptDrops))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_DropSiteRegistered", (long) Qt::WA_DropSiteRegistered))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ForceAcceptDrops", (long) Qt::WA_ForceAcceptDrops))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WindowPropagation", (long) Qt::WA_WindowPropagation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NoX11EventCompression", (long) Qt::WA_NoX11EventCompression))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_TintedBackground", (long) Qt::WA_TintedBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11OpenGLOverlay", (long) Qt::WA_X11OpenGLOverlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_AlwaysShowToolTips", (long) Qt::WA_AlwaysShowToolTips))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacOpaqueSizeGrip", (long) Qt::WA_MacOpaqueSizeGrip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetStyle", (long) Qt::WA_SetStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetLocale", (long) Qt::WA_SetLocale))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacShowFocusRect", (long) Qt::WA_MacShowFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacNormalSize", (long) Qt::WA_MacNormalSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacSmallSize", (long) Qt::WA_MacSmallSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacMiniSize", (long) Qt::WA_MacMiniSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_LayoutUsesWidgetRect", (long) Qt::WA_LayoutUsesWidgetRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_StyledBackground", (long) Qt::WA_StyledBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MSWindowsUseDirect3D", (long) Qt::WA_MSWindowsUseDirect3D))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_CanHostQMdiSubWindowTitleBar", (long) Qt::WA_CanHostQMdiSubWindowTitleBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacAlwaysShowToolWindow", (long) Qt::WA_MacAlwaysShowToolWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_StyleSheet", (long) Qt::WA_StyleSheet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_ShowWithoutActivating", (long) Qt::WA_ShowWithoutActivating))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11BypassTransientForHint", (long) Qt::WA_X11BypassTransientForHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_NativeWindow", (long) Qt::WA_NativeWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_DontCreateNativeAncestors", (long) Qt::WA_DontCreateNativeAncestors))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacVariableSize", (long) Qt::WA_MacVariableSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_DontShowOnScreen", (long) Qt::WA_DontShowOnScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeDesktop", (long) Qt::WA_X11NetWmWindowTypeDesktop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeDock", (long) Qt::WA_X11NetWmWindowTypeDock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeToolBar", (long) Qt::WA_X11NetWmWindowTypeToolBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeMenu", (long) Qt::WA_X11NetWmWindowTypeMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeUtility", (long) Qt::WA_X11NetWmWindowTypeUtility))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeSplash", (long) Qt::WA_X11NetWmWindowTypeSplash))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeDialog", (long) Qt::WA_X11NetWmWindowTypeDialog))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeDropDownMenu", (long) Qt::WA_X11NetWmWindowTypeDropDownMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypePopupMenu", (long) Qt::WA_X11NetWmWindowTypePopupMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeToolTip", (long) Qt::WA_X11NetWmWindowTypeToolTip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeNotification", (long) Qt::WA_X11NetWmWindowTypeNotification))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeCombo", (long) Qt::WA_X11NetWmWindowTypeCombo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11NetWmWindowTypeDND", (long) Qt::WA_X11NetWmWindowTypeDND))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacFrameworkScaled", (long) Qt::WA_MacFrameworkScaled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SetWindowModality", (long) Qt::WA_SetWindowModality))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_WindowOpacitySet", (long) Qt::WA_WState_WindowOpacitySet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_TranslucentBackground", (long) Qt::WA_TranslucentBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_AcceptTouchEvents", (long) Qt::WA_AcceptTouchEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_WState_AcceptedTouchBeginEvent", (long) Qt::WA_WState_AcceptedTouchBeginEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_TouchPadAcceptSingleTouchEvents", (long) Qt::WA_TouchPadAcceptSingleTouchEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MergeSoftkeys", (long) Qt::WA_MergeSoftkeys))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MergeSoftkeysRecursively", (long) Qt::WA_MergeSoftkeysRecursively))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_LockPortraitOrientation", (long) Qt::WA_LockPortraitOrientation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_LockLandscapeOrientation", (long) Qt::WA_LockLandscapeOrientation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_AutoOrientation", (long) Qt::WA_AutoOrientation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_X11DoNotAcceptFocus", (long) Qt::WA_X11DoNotAcceptFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_SymbianNoSystemRotation", (long) Qt::WA_SymbianNoSystemRotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_MacNoShadow", (long) Qt::WA_MacNoShadow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
        &Sbk_Qt_Type, "WA_AttributeCount", (long) Qt::WA_AttributeCount))
        return ;
    // Register converter for enum 'Qt::WidgetAttribute'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX],
            Qt_WidgetAttribute_CppToPython_Qt_WidgetAttribute);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WidgetAttribute_PythonToCpp_Qt_WidgetAttribute,
            is_Qt_WidgetAttribute_PythonToCpp_Qt_WidgetAttribute_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WIDGETATTRIBUTE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WidgetAttribute");
        Shiboken::Conversions::registerConverterName(converter, "WidgetAttribute");
    }
    // End of 'WidgetAttribute' enum.

    // Initialization of enum 'ApplicationAttribute'.
    SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ApplicationAttribute",
        "PySide.QtCore.Qt.ApplicationAttribute",
        "Qt::ApplicationAttribute");
    if (!SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_ImmediateWidgetCreation", (long) Qt::AA_ImmediateWidgetCreation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_MSWindowsUseDirect3DByDefault", (long) Qt::AA_MSWindowsUseDirect3DByDefault))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_DontShowIconsInMenus", (long) Qt::AA_DontShowIconsInMenus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_NativeWindows", (long) Qt::AA_NativeWindows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_DontCreateNativeWidgetSiblings", (long) Qt::AA_DontCreateNativeWidgetSiblings))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_MacPluginApplication", (long) Qt::AA_MacPluginApplication))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_DontUseNativeMenuBar", (long) Qt::AA_DontUseNativeMenuBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_MacDontSwapCtrlAndMeta", (long) Qt::AA_MacDontSwapCtrlAndMeta))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_S60DontConstructApplicationPanes", (long) Qt::AA_S60DontConstructApplicationPanes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_S60DisablePartialScreenInputMode", (long) Qt::AA_S60DisablePartialScreenInputMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_X11InitThreads", (long) Qt::AA_X11InitThreads))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_CaptureMultimediaKeys", (long) Qt::AA_CaptureMultimediaKeys))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AA_AttributeCount", (long) Qt::AA_AttributeCount))
        return ;
    // Register converter for enum 'Qt::ApplicationAttribute'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX],
            Qt_ApplicationAttribute_CppToPython_Qt_ApplicationAttribute);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ApplicationAttribute_PythonToCpp_Qt_ApplicationAttribute,
            is_Qt_ApplicationAttribute_PythonToCpp_Qt_ApplicationAttribute_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ApplicationAttribute");
        Shiboken::Conversions::registerConverterName(converter, "ApplicationAttribute");
    }
    // End of 'ApplicationAttribute' enum.

    // Initialization of enum 'ImageConversionFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX] = PySide::QFlags::create("ImageConversionFlags", &SbkPySide_QtCore_Qt_ImageConversionFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ImageConversionFlag",
        "PySide.QtCore.Qt.ImageConversionFlag",
        "Qt::ImageConversionFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "ColorMode_Mask", (long) Qt::ColorMode_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "AutoColor", (long) Qt::AutoColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "ColorOnly", (long) Qt::ColorOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "MonoOnly", (long) Qt::MonoOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "AlphaDither_Mask", (long) Qt::AlphaDither_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "ThresholdAlphaDither", (long) Qt::ThresholdAlphaDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "OrderedAlphaDither", (long) Qt::OrderedAlphaDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "DiffuseAlphaDither", (long) Qt::DiffuseAlphaDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "NoAlpha", (long) Qt::NoAlpha))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "Dither_Mask", (long) Qt::Dither_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "DiffuseDither", (long) Qt::DiffuseDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "OrderedDither", (long) Qt::OrderedDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "ThresholdDither", (long) Qt::ThresholdDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "DitherMode_Mask", (long) Qt::DitherMode_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "AutoDither", (long) Qt::AutoDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "PreferDither", (long) Qt::PreferDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "AvoidDither", (long) Qt::AvoidDither))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "NoOpaqueDetection", (long) Qt::NoOpaqueDetection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
        &Sbk_Qt_Type, "NoFormatConversion", (long) Qt::NoFormatConversion))
        return ;
    // Register converter for enum 'Qt::ImageConversionFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX],
            Qt_ImageConversionFlag_CppToPython_Qt_ImageConversionFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ImageConversionFlag_PythonToCpp_Qt_ImageConversionFlag,
            is_Qt_ImageConversionFlag_PythonToCpp_Qt_ImageConversionFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_IMAGECONVERSIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ImageConversionFlag");
        Shiboken::Conversions::registerConverterName(converter, "ImageConversionFlag");
    }
    // Register converter for flag 'QFlags<Qt::ImageConversionFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX],
            QFlags_Qt_ImageConversionFlag__CppToPython_QFlags_Qt_ImageConversionFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ImageConversionFlag_PythonToCpp_QFlags_Qt_ImageConversionFlag_,
            is_Qt_ImageConversionFlag_PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_ImageConversionFlag__PythonToCpp_QFlags_Qt_ImageConversionFlag_,
            is_QFlags_Qt_ImageConversionFlag__PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_ImageConversionFlag_,
            is_number_PythonToCpp_QFlags_Qt_ImageConversionFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::ImageConversionFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ImageConversionFlag>");
    }
    // End of 'ImageConversionFlag' enum/flags.

    // Initialization of enum 'BGMode'.
    SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "BGMode",
        "PySide.QtCore.Qt.BGMode",
        "Qt::BGMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX],
        &Sbk_Qt_Type, "TransparentMode", (long) Qt::TransparentMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX],
        &Sbk_Qt_Type, "OpaqueMode", (long) Qt::OpaqueMode))
        return ;
    // Register converter for enum 'Qt::BGMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX],
            Qt_BGMode_CppToPython_Qt_BGMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_BGMode_PythonToCpp_Qt_BGMode,
            is_Qt_BGMode_PythonToCpp_Qt_BGMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::BGMode");
        Shiboken::Conversions::registerConverterName(converter, "BGMode");
    }
    // End of 'BGMode' enum.

    // Initialization of enum 'Key'.
    SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "Key",
        "PySide.QtCore.Qt.Key",
        "Qt::Key");
    if (!SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Escape", (long) Qt::Key_Escape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Tab", (long) Qt::Key_Tab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Backtab", (long) Qt::Key_Backtab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Backspace", (long) Qt::Key_Backspace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Return", (long) Qt::Key_Return))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Enter", (long) Qt::Key_Enter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Insert", (long) Qt::Key_Insert))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Delete", (long) Qt::Key_Delete))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Pause", (long) Qt::Key_Pause))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Print", (long) Qt::Key_Print))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_SysReq", (long) Qt::Key_SysReq))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Clear", (long) Qt::Key_Clear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Home", (long) Qt::Key_Home))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_End", (long) Qt::Key_End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Left", (long) Qt::Key_Left))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Up", (long) Qt::Key_Up))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Right", (long) Qt::Key_Right))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Down", (long) Qt::Key_Down))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_PageUp", (long) Qt::Key_PageUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_PageDown", (long) Qt::Key_PageDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Shift", (long) Qt::Key_Shift))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Control", (long) Qt::Key_Control))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Meta", (long) Qt::Key_Meta))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Alt", (long) Qt::Key_Alt))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_CapsLock", (long) Qt::Key_CapsLock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_NumLock", (long) Qt::Key_NumLock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ScrollLock", (long) Qt::Key_ScrollLock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F1", (long) Qt::Key_F1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F2", (long) Qt::Key_F2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F3", (long) Qt::Key_F3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F4", (long) Qt::Key_F4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F5", (long) Qt::Key_F5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F6", (long) Qt::Key_F6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F7", (long) Qt::Key_F7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F8", (long) Qt::Key_F8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F9", (long) Qt::Key_F9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F10", (long) Qt::Key_F10))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F11", (long) Qt::Key_F11))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F12", (long) Qt::Key_F12))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F13", (long) Qt::Key_F13))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F14", (long) Qt::Key_F14))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F15", (long) Qt::Key_F15))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F16", (long) Qt::Key_F16))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F17", (long) Qt::Key_F17))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F18", (long) Qt::Key_F18))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F19", (long) Qt::Key_F19))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F20", (long) Qt::Key_F20))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F21", (long) Qt::Key_F21))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F22", (long) Qt::Key_F22))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F23", (long) Qt::Key_F23))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F24", (long) Qt::Key_F24))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F25", (long) Qt::Key_F25))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F26", (long) Qt::Key_F26))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F27", (long) Qt::Key_F27))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F28", (long) Qt::Key_F28))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F29", (long) Qt::Key_F29))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F30", (long) Qt::Key_F30))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F31", (long) Qt::Key_F31))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F32", (long) Qt::Key_F32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F33", (long) Qt::Key_F33))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F34", (long) Qt::Key_F34))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F35", (long) Qt::Key_F35))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Super_L", (long) Qt::Key_Super_L))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Super_R", (long) Qt::Key_Super_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Menu", (long) Qt::Key_Menu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hyper_L", (long) Qt::Key_Hyper_L))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hyper_R", (long) Qt::Key_Hyper_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Help", (long) Qt::Key_Help))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Direction_L", (long) Qt::Key_Direction_L))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Direction_R", (long) Qt::Key_Direction_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Space", (long) Qt::Key_Space))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Any", (long) Qt::Key_Any))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Exclam", (long) Qt::Key_Exclam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_QuoteDbl", (long) Qt::Key_QuoteDbl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_NumberSign", (long) Qt::Key_NumberSign))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dollar", (long) Qt::Key_Dollar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Percent", (long) Qt::Key_Percent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ampersand", (long) Qt::Key_Ampersand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Apostrophe", (long) Qt::Key_Apostrophe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ParenLeft", (long) Qt::Key_ParenLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ParenRight", (long) Qt::Key_ParenRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Asterisk", (long) Qt::Key_Asterisk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Plus", (long) Qt::Key_Plus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Comma", (long) Qt::Key_Comma))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Minus", (long) Qt::Key_Minus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Period", (long) Qt::Key_Period))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Slash", (long) Qt::Key_Slash))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_0", (long) Qt::Key_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_1", (long) Qt::Key_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_2", (long) Qt::Key_2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_3", (long) Qt::Key_3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_4", (long) Qt::Key_4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_5", (long) Qt::Key_5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_6", (long) Qt::Key_6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_7", (long) Qt::Key_7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_8", (long) Qt::Key_8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_9", (long) Qt::Key_9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Colon", (long) Qt::Key_Colon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Semicolon", (long) Qt::Key_Semicolon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Less", (long) Qt::Key_Less))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Equal", (long) Qt::Key_Equal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Greater", (long) Qt::Key_Greater))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Question", (long) Qt::Key_Question))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_At", (long) Qt::Key_At))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_A", (long) Qt::Key_A))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_B", (long) Qt::Key_B))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_C", (long) Qt::Key_C))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_D", (long) Qt::Key_D))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_E", (long) Qt::Key_E))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_F", (long) Qt::Key_F))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_G", (long) Qt::Key_G))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_H", (long) Qt::Key_H))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_I", (long) Qt::Key_I))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_J", (long) Qt::Key_J))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_K", (long) Qt::Key_K))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_L", (long) Qt::Key_L))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_M", (long) Qt::Key_M))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_N", (long) Qt::Key_N))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_O", (long) Qt::Key_O))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_P", (long) Qt::Key_P))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Q", (long) Qt::Key_Q))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_R", (long) Qt::Key_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_S", (long) Qt::Key_S))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_T", (long) Qt::Key_T))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_U", (long) Qt::Key_U))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_V", (long) Qt::Key_V))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_W", (long) Qt::Key_W))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_X", (long) Qt::Key_X))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Y", (long) Qt::Key_Y))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Z", (long) Qt::Key_Z))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BracketLeft", (long) Qt::Key_BracketLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Backslash", (long) Qt::Key_Backslash))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BracketRight", (long) Qt::Key_BracketRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AsciiCircum", (long) Qt::Key_AsciiCircum))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Underscore", (long) Qt::Key_Underscore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_QuoteLeft", (long) Qt::Key_QuoteLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BraceLeft", (long) Qt::Key_BraceLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Bar", (long) Qt::Key_Bar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BraceRight", (long) Qt::Key_BraceRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AsciiTilde", (long) Qt::Key_AsciiTilde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_nobreakspace", (long) Qt::Key_nobreakspace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_exclamdown", (long) Qt::Key_exclamdown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_cent", (long) Qt::Key_cent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_sterling", (long) Qt::Key_sterling))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_currency", (long) Qt::Key_currency))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_yen", (long) Qt::Key_yen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_brokenbar", (long) Qt::Key_brokenbar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_section", (long) Qt::Key_section))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_diaeresis", (long) Qt::Key_diaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_copyright", (long) Qt::Key_copyright))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ordfeminine", (long) Qt::Key_ordfeminine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_guillemotleft", (long) Qt::Key_guillemotleft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_notsign", (long) Qt::Key_notsign))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_hyphen", (long) Qt::Key_hyphen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_registered", (long) Qt::Key_registered))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_macron", (long) Qt::Key_macron))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_degree", (long) Qt::Key_degree))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_plusminus", (long) Qt::Key_plusminus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_twosuperior", (long) Qt::Key_twosuperior))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_threesuperior", (long) Qt::Key_threesuperior))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_acute", (long) Qt::Key_acute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_mu", (long) Qt::Key_mu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_paragraph", (long) Qt::Key_paragraph))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_periodcentered", (long) Qt::Key_periodcentered))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_cedilla", (long) Qt::Key_cedilla))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_onesuperior", (long) Qt::Key_onesuperior))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_masculine", (long) Qt::Key_masculine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_guillemotright", (long) Qt::Key_guillemotright))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_onequarter", (long) Qt::Key_onequarter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_onehalf", (long) Qt::Key_onehalf))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_threequarters", (long) Qt::Key_threequarters))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_questiondown", (long) Qt::Key_questiondown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Agrave", (long) Qt::Key_Agrave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Aacute", (long) Qt::Key_Aacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Acircumflex", (long) Qt::Key_Acircumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Atilde", (long) Qt::Key_Atilde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Adiaeresis", (long) Qt::Key_Adiaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Aring", (long) Qt::Key_Aring))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AE", (long) Qt::Key_AE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ccedilla", (long) Qt::Key_Ccedilla))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Egrave", (long) Qt::Key_Egrave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Eacute", (long) Qt::Key_Eacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ecircumflex", (long) Qt::Key_Ecircumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ediaeresis", (long) Qt::Key_Ediaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Igrave", (long) Qt::Key_Igrave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Iacute", (long) Qt::Key_Iacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Icircumflex", (long) Qt::Key_Icircumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Idiaeresis", (long) Qt::Key_Idiaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ETH", (long) Qt::Key_ETH))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ntilde", (long) Qt::Key_Ntilde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ograve", (long) Qt::Key_Ograve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Oacute", (long) Qt::Key_Oacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ocircumflex", (long) Qt::Key_Ocircumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Otilde", (long) Qt::Key_Otilde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Odiaeresis", (long) Qt::Key_Odiaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_multiply", (long) Qt::Key_multiply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ooblique", (long) Qt::Key_Ooblique))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ugrave", (long) Qt::Key_Ugrave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Uacute", (long) Qt::Key_Uacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Ucircumflex", (long) Qt::Key_Ucircumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Udiaeresis", (long) Qt::Key_Udiaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Yacute", (long) Qt::Key_Yacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_THORN", (long) Qt::Key_THORN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ssharp", (long) Qt::Key_ssharp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_division", (long) Qt::Key_division))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ydiaeresis", (long) Qt::Key_ydiaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AltGr", (long) Qt::Key_AltGr))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Multi_key", (long) Qt::Key_Multi_key))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Codeinput", (long) Qt::Key_Codeinput))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_SingleCandidate", (long) Qt::Key_SingleCandidate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MultipleCandidate", (long) Qt::Key_MultipleCandidate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_PreviousCandidate", (long) Qt::Key_PreviousCandidate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Mode_switch", (long) Qt::Key_Mode_switch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Kanji", (long) Qt::Key_Kanji))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Muhenkan", (long) Qt::Key_Muhenkan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Henkan", (long) Qt::Key_Henkan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Romaji", (long) Qt::Key_Romaji))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hiragana", (long) Qt::Key_Hiragana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Katakana", (long) Qt::Key_Katakana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hiragana_Katakana", (long) Qt::Key_Hiragana_Katakana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Zenkaku", (long) Qt::Key_Zenkaku))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hankaku", (long) Qt::Key_Hankaku))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Zenkaku_Hankaku", (long) Qt::Key_Zenkaku_Hankaku))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Touroku", (long) Qt::Key_Touroku))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Massyo", (long) Qt::Key_Massyo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Kana_Lock", (long) Qt::Key_Kana_Lock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Kana_Shift", (long) Qt::Key_Kana_Shift))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Eisu_Shift", (long) Qt::Key_Eisu_Shift))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Eisu_toggle", (long) Qt::Key_Eisu_toggle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul", (long) Qt::Key_Hangul))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Start", (long) Qt::Key_Hangul_Start))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_End", (long) Qt::Key_Hangul_End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Hanja", (long) Qt::Key_Hangul_Hanja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Jamo", (long) Qt::Key_Hangul_Jamo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Romaja", (long) Qt::Key_Hangul_Romaja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Jeonja", (long) Qt::Key_Hangul_Jeonja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Banja", (long) Qt::Key_Hangul_Banja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_PreHanja", (long) Qt::Key_Hangul_PreHanja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_PostHanja", (long) Qt::Key_Hangul_PostHanja))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangul_Special", (long) Qt::Key_Hangul_Special))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Grave", (long) Qt::Key_Dead_Grave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Acute", (long) Qt::Key_Dead_Acute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Circumflex", (long) Qt::Key_Dead_Circumflex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Tilde", (long) Qt::Key_Dead_Tilde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Macron", (long) Qt::Key_Dead_Macron))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Breve", (long) Qt::Key_Dead_Breve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Abovedot", (long) Qt::Key_Dead_Abovedot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Diaeresis", (long) Qt::Key_Dead_Diaeresis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Abovering", (long) Qt::Key_Dead_Abovering))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Doubleacute", (long) Qt::Key_Dead_Doubleacute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Caron", (long) Qt::Key_Dead_Caron))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Cedilla", (long) Qt::Key_Dead_Cedilla))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Ogonek", (long) Qt::Key_Dead_Ogonek))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Iota", (long) Qt::Key_Dead_Iota))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Voiced_Sound", (long) Qt::Key_Dead_Voiced_Sound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Semivoiced_Sound", (long) Qt::Key_Dead_Semivoiced_Sound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Belowdot", (long) Qt::Key_Dead_Belowdot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Hook", (long) Qt::Key_Dead_Hook))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Dead_Horn", (long) Qt::Key_Dead_Horn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Back", (long) Qt::Key_Back))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Forward", (long) Qt::Key_Forward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Stop", (long) Qt::Key_Stop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Refresh", (long) Qt::Key_Refresh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_VolumeDown", (long) Qt::Key_VolumeDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_VolumeMute", (long) Qt::Key_VolumeMute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_VolumeUp", (long) Qt::Key_VolumeUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BassBoost", (long) Qt::Key_BassBoost))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BassUp", (long) Qt::Key_BassUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BassDown", (long) Qt::Key_BassDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_TrebleUp", (long) Qt::Key_TrebleUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_TrebleDown", (long) Qt::Key_TrebleDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaPlay", (long) Qt::Key_MediaPlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaStop", (long) Qt::Key_MediaStop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaPrevious", (long) Qt::Key_MediaPrevious))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaNext", (long) Qt::Key_MediaNext))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaRecord", (long) Qt::Key_MediaRecord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaPause", (long) Qt::Key_MediaPause))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaTogglePlayPause", (long) Qt::Key_MediaTogglePlayPause))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_HomePage", (long) Qt::Key_HomePage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Favorites", (long) Qt::Key_Favorites))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Search", (long) Qt::Key_Search))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Standby", (long) Qt::Key_Standby))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_OpenUrl", (long) Qt::Key_OpenUrl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchMail", (long) Qt::Key_LaunchMail))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchMedia", (long) Qt::Key_LaunchMedia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch0", (long) Qt::Key_Launch0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch1", (long) Qt::Key_Launch1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch2", (long) Qt::Key_Launch2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch3", (long) Qt::Key_Launch3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch4", (long) Qt::Key_Launch4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch5", (long) Qt::Key_Launch5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch6", (long) Qt::Key_Launch6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch7", (long) Qt::Key_Launch7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch8", (long) Qt::Key_Launch8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Launch9", (long) Qt::Key_Launch9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchA", (long) Qt::Key_LaunchA))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchB", (long) Qt::Key_LaunchB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchC", (long) Qt::Key_LaunchC))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchD", (long) Qt::Key_LaunchD))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchE", (long) Qt::Key_LaunchE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchF", (long) Qt::Key_LaunchF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MonBrightnessUp", (long) Qt::Key_MonBrightnessUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MonBrightnessDown", (long) Qt::Key_MonBrightnessDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_KeyboardLightOnOff", (long) Qt::Key_KeyboardLightOnOff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_KeyboardBrightnessUp", (long) Qt::Key_KeyboardBrightnessUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_KeyboardBrightnessDown", (long) Qt::Key_KeyboardBrightnessDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_PowerOff", (long) Qt::Key_PowerOff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_WakeUp", (long) Qt::Key_WakeUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Eject", (long) Qt::Key_Eject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ScreenSaver", (long) Qt::Key_ScreenSaver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_WWW", (long) Qt::Key_WWW))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Memo", (long) Qt::Key_Memo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LightBulb", (long) Qt::Key_LightBulb))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Shop", (long) Qt::Key_Shop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_History", (long) Qt::Key_History))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AddFavorite", (long) Qt::Key_AddFavorite))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_HotLinks", (long) Qt::Key_HotLinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BrightnessAdjust", (long) Qt::Key_BrightnessAdjust))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Finance", (long) Qt::Key_Finance))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Community", (long) Qt::Key_Community))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AudioRewind", (long) Qt::Key_AudioRewind))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_BackForward", (long) Qt::Key_BackForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ApplicationLeft", (long) Qt::Key_ApplicationLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ApplicationRight", (long) Qt::Key_ApplicationRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Book", (long) Qt::Key_Book))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_CD", (long) Qt::Key_CD))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Calculator", (long) Qt::Key_Calculator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ToDoList", (long) Qt::Key_ToDoList))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ClearGrab", (long) Qt::Key_ClearGrab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Close", (long) Qt::Key_Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Copy", (long) Qt::Key_Copy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Cut", (long) Qt::Key_Cut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Display", (long) Qt::Key_Display))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_DOS", (long) Qt::Key_DOS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Documents", (long) Qt::Key_Documents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Excel", (long) Qt::Key_Excel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Explorer", (long) Qt::Key_Explorer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Game", (long) Qt::Key_Game))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Go", (long) Qt::Key_Go))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_iTouch", (long) Qt::Key_iTouch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LogOff", (long) Qt::Key_LogOff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Market", (long) Qt::Key_Market))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Meeting", (long) Qt::Key_Meeting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MenuKB", (long) Qt::Key_MenuKB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MenuPB", (long) Qt::Key_MenuPB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MySites", (long) Qt::Key_MySites))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_News", (long) Qt::Key_News))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_OfficeHome", (long) Qt::Key_OfficeHome))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Option", (long) Qt::Key_Option))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Paste", (long) Qt::Key_Paste))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Phone", (long) Qt::Key_Phone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Calendar", (long) Qt::Key_Calendar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Reply", (long) Qt::Key_Reply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Reload", (long) Qt::Key_Reload))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_RotateWindows", (long) Qt::Key_RotateWindows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_RotationPB", (long) Qt::Key_RotationPB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_RotationKB", (long) Qt::Key_RotationKB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Save", (long) Qt::Key_Save))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Send", (long) Qt::Key_Send))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Spell", (long) Qt::Key_Spell))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_SplitScreen", (long) Qt::Key_SplitScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Support", (long) Qt::Key_Support))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_TaskPane", (long) Qt::Key_TaskPane))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Terminal", (long) Qt::Key_Terminal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Tools", (long) Qt::Key_Tools))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Travel", (long) Qt::Key_Travel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Video", (long) Qt::Key_Video))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Word", (long) Qt::Key_Word))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Xfer", (long) Qt::Key_Xfer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ZoomIn", (long) Qt::Key_ZoomIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ZoomOut", (long) Qt::Key_ZoomOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Away", (long) Qt::Key_Away))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Messenger", (long) Qt::Key_Messenger))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_WebCam", (long) Qt::Key_WebCam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MailForward", (long) Qt::Key_MailForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Pictures", (long) Qt::Key_Pictures))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Music", (long) Qt::Key_Music))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Battery", (long) Qt::Key_Battery))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Bluetooth", (long) Qt::Key_Bluetooth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_WLAN", (long) Qt::Key_WLAN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_UWB", (long) Qt::Key_UWB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AudioForward", (long) Qt::Key_AudioForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AudioRepeat", (long) Qt::Key_AudioRepeat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AudioRandomPlay", (long) Qt::Key_AudioRandomPlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Subtitle", (long) Qt::Key_Subtitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_AudioCycleTrack", (long) Qt::Key_AudioCycleTrack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Time", (long) Qt::Key_Time))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hibernate", (long) Qt::Key_Hibernate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_View", (long) Qt::Key_View))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_TopMenu", (long) Qt::Key_TopMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_PowerDown", (long) Qt::Key_PowerDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Suspend", (long) Qt::Key_Suspend))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ContrastAdjust", (long) Qt::Key_ContrastAdjust))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchG", (long) Qt::Key_LaunchG))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LaunchH", (long) Qt::Key_LaunchH))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_MediaLast", (long) Qt::Key_MediaLast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Select", (long) Qt::Key_Select))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Yes", (long) Qt::Key_Yes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_No", (long) Qt::Key_No))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Cancel", (long) Qt::Key_Cancel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Printer", (long) Qt::Key_Printer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Execute", (long) Qt::Key_Execute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Sleep", (long) Qt::Key_Sleep))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Play", (long) Qt::Key_Play))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Zoom", (long) Qt::Key_Zoom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Context1", (long) Qt::Key_Context1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Context2", (long) Qt::Key_Context2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Context3", (long) Qt::Key_Context3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Context4", (long) Qt::Key_Context4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Call", (long) Qt::Key_Call))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Hangup", (long) Qt::Key_Hangup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Flip", (long) Qt::Key_Flip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_ToggleCallHangup", (long) Qt::Key_ToggleCallHangup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_VoiceDial", (long) Qt::Key_VoiceDial))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_LastNumberRedial", (long) Qt::Key_LastNumberRedial))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_Camera", (long) Qt::Key_Camera))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_CameraFocus", (long) Qt::Key_CameraFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
        &Sbk_Qt_Type, "Key_unknown", (long) Qt::Key_unknown))
        return ;
    // Register converter for enum 'Qt::Key'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX],
            Qt_Key_CppToPython_Qt_Key);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Key_PythonToCpp_Qt_Key,
            is_Qt_Key_PythonToCpp_Qt_Key_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::Key");
        Shiboken::Conversions::registerConverterName(converter, "Key");
    }
    // End of 'Key' enum.

    // Initialization of enum 'ArrowType'.
    SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ArrowType",
        "PySide.QtCore.Qt.ArrowType",
        "Qt::ArrowType");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
        &Sbk_Qt_Type, "NoArrow", (long) Qt::NoArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
        &Sbk_Qt_Type, "UpArrow", (long) Qt::UpArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
        &Sbk_Qt_Type, "DownArrow", (long) Qt::DownArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
        &Sbk_Qt_Type, "LeftArrow", (long) Qt::LeftArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
        &Sbk_Qt_Type, "RightArrow", (long) Qt::RightArrow))
        return ;
    // Register converter for enum 'Qt::ArrowType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX],
            Qt_ArrowType_CppToPython_Qt_ArrowType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ArrowType_PythonToCpp_Qt_ArrowType,
            is_Qt_ArrowType_PythonToCpp_Qt_ArrowType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ArrowType");
        Shiboken::Conversions::registerConverterName(converter, "ArrowType");
    }
    // End of 'ArrowType' enum.

    // Initialization of enum 'PenStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "PenStyle",
        "PySide.QtCore.Qt.PenStyle",
        "Qt::PenStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "NoPen", (long) Qt::NoPen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "SolidLine", (long) Qt::SolidLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "DashLine", (long) Qt::DashLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "DotLine", (long) Qt::DotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "DashDotLine", (long) Qt::DashDotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "DashDotDotLine", (long) Qt::DashDotDotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "CustomDashLine", (long) Qt::CustomDashLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
        &Sbk_Qt_Type, "MPenStyle", (long) Qt::MPenStyle))
        return ;
    // Register converter for enum 'Qt::PenStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX],
            Qt_PenStyle_CppToPython_Qt_PenStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_PenStyle_PythonToCpp_Qt_PenStyle,
            is_Qt_PenStyle_PythonToCpp_Qt_PenStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::PenStyle");
        Shiboken::Conversions::registerConverterName(converter, "PenStyle");
    }
    // End of 'PenStyle' enum.

    // Initialization of enum 'PenCapStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "PenCapStyle",
        "PySide.QtCore.Qt.PenCapStyle",
        "Qt::PenCapStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX],
        &Sbk_Qt_Type, "FlatCap", (long) Qt::FlatCap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX],
        &Sbk_Qt_Type, "SquareCap", (long) Qt::SquareCap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX],
        &Sbk_Qt_Type, "RoundCap", (long) Qt::RoundCap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX],
        &Sbk_Qt_Type, "MPenCapStyle", (long) Qt::MPenCapStyle))
        return ;
    // Register converter for enum 'Qt::PenCapStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX],
            Qt_PenCapStyle_CppToPython_Qt_PenCapStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_PenCapStyle_PythonToCpp_Qt_PenCapStyle,
            is_Qt_PenCapStyle_PythonToCpp_Qt_PenCapStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::PenCapStyle");
        Shiboken::Conversions::registerConverterName(converter, "PenCapStyle");
    }
    // End of 'PenCapStyle' enum.

    // Initialization of enum 'PenJoinStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "PenJoinStyle",
        "PySide.QtCore.Qt.PenJoinStyle",
        "Qt::PenJoinStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
        &Sbk_Qt_Type, "MiterJoin", (long) Qt::MiterJoin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
        &Sbk_Qt_Type, "BevelJoin", (long) Qt::BevelJoin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
        &Sbk_Qt_Type, "RoundJoin", (long) Qt::RoundJoin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
        &Sbk_Qt_Type, "SvgMiterJoin", (long) Qt::SvgMiterJoin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
        &Sbk_Qt_Type, "MPenJoinStyle", (long) Qt::MPenJoinStyle))
        return ;
    // Register converter for enum 'Qt::PenJoinStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX],
            Qt_PenJoinStyle_CppToPython_Qt_PenJoinStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_PenJoinStyle_PythonToCpp_Qt_PenJoinStyle,
            is_Qt_PenJoinStyle_PythonToCpp_Qt_PenJoinStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::PenJoinStyle");
        Shiboken::Conversions::registerConverterName(converter, "PenJoinStyle");
    }
    // End of 'PenJoinStyle' enum.

    // Initialization of enum 'BrushStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "BrushStyle",
        "PySide.QtCore.Qt.BrushStyle",
        "Qt::BrushStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "NoBrush", (long) Qt::NoBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "SolidPattern", (long) Qt::SolidPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense1Pattern", (long) Qt::Dense1Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense2Pattern", (long) Qt::Dense2Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense3Pattern", (long) Qt::Dense3Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense4Pattern", (long) Qt::Dense4Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense5Pattern", (long) Qt::Dense5Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense6Pattern", (long) Qt::Dense6Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "Dense7Pattern", (long) Qt::Dense7Pattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "HorPattern", (long) Qt::HorPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "VerPattern", (long) Qt::VerPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "CrossPattern", (long) Qt::CrossPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "BDiagPattern", (long) Qt::BDiagPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "FDiagPattern", (long) Qt::FDiagPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "DiagCrossPattern", (long) Qt::DiagCrossPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "LinearGradientPattern", (long) Qt::LinearGradientPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "RadialGradientPattern", (long) Qt::RadialGradientPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "ConicalGradientPattern", (long) Qt::ConicalGradientPattern))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
        &Sbk_Qt_Type, "TexturePattern", (long) Qt::TexturePattern))
        return ;
    // Register converter for enum 'Qt::BrushStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX],
            Qt_BrushStyle_CppToPython_Qt_BrushStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_BrushStyle_PythonToCpp_Qt_BrushStyle,
            is_Qt_BrushStyle_PythonToCpp_Qt_BrushStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::BrushStyle");
        Shiboken::Conversions::registerConverterName(converter, "BrushStyle");
    }
    // End of 'BrushStyle' enum.

    // Initialization of enum 'SizeMode'.
    SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "SizeMode",
        "PySide.QtCore.Qt.SizeMode",
        "Qt::SizeMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX],
        &Sbk_Qt_Type, "AbsoluteSize", (long) Qt::AbsoluteSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX],
        &Sbk_Qt_Type, "RelativeSize", (long) Qt::RelativeSize))
        return ;
    // Register converter for enum 'Qt::SizeMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX],
            Qt_SizeMode_CppToPython_Qt_SizeMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_SizeMode_PythonToCpp_Qt_SizeMode,
            is_Qt_SizeMode_PythonToCpp_Qt_SizeMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::SizeMode");
        Shiboken::Conversions::registerConverterName(converter, "SizeMode");
    }
    // End of 'SizeMode' enum.

    // Initialization of enum 'UIEffect'.
    SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "UIEffect",
        "PySide.QtCore.Qt.UIEffect",
        "Qt::UIEffect");
    if (!SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_General", (long) Qt::UI_General))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_AnimateMenu", (long) Qt::UI_AnimateMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_FadeMenu", (long) Qt::UI_FadeMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_AnimateCombo", (long) Qt::UI_AnimateCombo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_AnimateTooltip", (long) Qt::UI_AnimateTooltip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_FadeTooltip", (long) Qt::UI_FadeTooltip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
        &Sbk_Qt_Type, "UI_AnimateToolBox", (long) Qt::UI_AnimateToolBox))
        return ;
    // Register converter for enum 'Qt::UIEffect'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX],
            Qt_UIEffect_CppToPython_Qt_UIEffect);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_UIEffect_PythonToCpp_Qt_UIEffect,
            is_Qt_UIEffect_PythonToCpp_Qt_UIEffect_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_UIEFFECT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::UIEffect");
        Shiboken::Conversions::registerConverterName(converter, "UIEffect");
    }
    // End of 'UIEffect' enum.

    // Initialization of enum 'CursorShape'.
    SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "CursorShape",
        "PySide.QtCore.Qt.CursorShape",
        "Qt::CursorShape");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "ArrowCursor", (long) Qt::ArrowCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "UpArrowCursor", (long) Qt::UpArrowCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "CrossCursor", (long) Qt::CrossCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "WaitCursor", (long) Qt::WaitCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "IBeamCursor", (long) Qt::IBeamCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SizeVerCursor", (long) Qt::SizeVerCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SizeHorCursor", (long) Qt::SizeHorCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SizeBDiagCursor", (long) Qt::SizeBDiagCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SizeFDiagCursor", (long) Qt::SizeFDiagCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SizeAllCursor", (long) Qt::SizeAllCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "BlankCursor", (long) Qt::BlankCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SplitVCursor", (long) Qt::SplitVCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "SplitHCursor", (long) Qt::SplitHCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "PointingHandCursor", (long) Qt::PointingHandCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "ForbiddenCursor", (long) Qt::ForbiddenCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "WhatsThisCursor", (long) Qt::WhatsThisCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "BusyCursor", (long) Qt::BusyCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "OpenHandCursor", (long) Qt::OpenHandCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "ClosedHandCursor", (long) Qt::ClosedHandCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "DragCopyCursor", (long) Qt::DragCopyCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "DragMoveCursor", (long) Qt::DragMoveCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "DragLinkCursor", (long) Qt::DragLinkCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "LastCursor", (long) Qt::LastCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "BitmapCursor", (long) Qt::BitmapCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
        &Sbk_Qt_Type, "CustomCursor", (long) Qt::CustomCursor))
        return ;
    // Register converter for enum 'Qt::CursorShape'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX],
            Qt_CursorShape_CppToPython_Qt_CursorShape);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_CursorShape_PythonToCpp_Qt_CursorShape,
            is_Qt_CursorShape_PythonToCpp_Qt_CursorShape_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORSHAPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::CursorShape");
        Shiboken::Conversions::registerConverterName(converter, "CursorShape");
    }
    // End of 'CursorShape' enum.

    // Initialization of enum 'TextFormat'.
    SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TextFormat",
        "PySide.QtCore.Qt.TextFormat",
        "Qt::TextFormat");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX],
        &Sbk_Qt_Type, "PlainText", (long) Qt::PlainText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX],
        &Sbk_Qt_Type, "RichText", (long) Qt::RichText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX],
        &Sbk_Qt_Type, "AutoText", (long) Qt::AutoText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX],
        &Sbk_Qt_Type, "LogText", (long) Qt::LogText))
        return ;
    // Register converter for enum 'Qt::TextFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX],
            Qt_TextFormat_CppToPython_Qt_TextFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TextFormat_PythonToCpp_Qt_TextFormat,
            is_Qt_TextFormat_PythonToCpp_Qt_TextFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TextFormat");
        Shiboken::Conversions::registerConverterName(converter, "TextFormat");
    }
    // End of 'TextFormat' enum.

    // Initialization of enum 'AspectRatioMode'.
    SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "AspectRatioMode",
        "PySide.QtCore.Qt.AspectRatioMode",
        "Qt::AspectRatioMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX],
        &Sbk_Qt_Type, "IgnoreAspectRatio", (long) Qt::IgnoreAspectRatio))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX],
        &Sbk_Qt_Type, "KeepAspectRatio", (long) Qt::KeepAspectRatio))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX],
        &Sbk_Qt_Type, "KeepAspectRatioByExpanding", (long) Qt::KeepAspectRatioByExpanding))
        return ;
    // Register converter for enum 'Qt::AspectRatioMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX],
            Qt_AspectRatioMode_CppToPython_Qt_AspectRatioMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_AspectRatioMode_PythonToCpp_Qt_AspectRatioMode,
            is_Qt_AspectRatioMode_PythonToCpp_Qt_AspectRatioMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::AspectRatioMode");
        Shiboken::Conversions::registerConverterName(converter, "AspectRatioMode");
    }
    // End of 'AspectRatioMode' enum.

    // Initialization of enum 'AnchorAttribute'.
    SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "AnchorAttribute",
        "PySide.QtCore.Qt.AnchorAttribute",
        "Qt::AnchorAttribute");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AnchorName", (long) Qt::AnchorName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX],
        &Sbk_Qt_Type, "AnchorHref", (long) Qt::AnchorHref))
        return ;
    // Register converter for enum 'Qt::AnchorAttribute'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX],
            Qt_AnchorAttribute_CppToPython_Qt_AnchorAttribute);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_AnchorAttribute_PythonToCpp_Qt_AnchorAttribute,
            is_Qt_AnchorAttribute_PythonToCpp_Qt_AnchorAttribute_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORATTRIBUTE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::AnchorAttribute");
        Shiboken::Conversions::registerConverterName(converter, "AnchorAttribute");
    }
    // End of 'AnchorAttribute' enum.

    // Initialization of enum 'DockWidgetArea'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX] = PySide::QFlags::create("DockWidgetAreas", &SbkPySide_QtCore_Qt_DockWidgetArea_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "DockWidgetArea",
        "PySide.QtCore.Qt.DockWidgetArea",
        "Qt::DockWidgetArea",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "LeftDockWidgetArea", (long) Qt::LeftDockWidgetArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "RightDockWidgetArea", (long) Qt::RightDockWidgetArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "TopDockWidgetArea", (long) Qt::TopDockWidgetArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "BottomDockWidgetArea", (long) Qt::BottomDockWidgetArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "DockWidgetArea_Mask", (long) Qt::DockWidgetArea_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "AllDockWidgetAreas", (long) Qt::AllDockWidgetAreas))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
        &Sbk_Qt_Type, "NoDockWidgetArea", (long) Qt::NoDockWidgetArea))
        return ;
    // Register converter for enum 'Qt::DockWidgetArea'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX],
            Qt_DockWidgetArea_CppToPython_Qt_DockWidgetArea);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DockWidgetArea_PythonToCpp_Qt_DockWidgetArea,
            is_Qt_DockWidgetArea_PythonToCpp_Qt_DockWidgetArea_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::DockWidgetArea");
        Shiboken::Conversions::registerConverterName(converter, "DockWidgetArea");
    }
    // Register converter for flag 'QFlags<Qt::DockWidgetArea>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX],
            QFlags_Qt_DockWidgetArea__CppToPython_QFlags_Qt_DockWidgetArea_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DockWidgetArea_PythonToCpp_QFlags_Qt_DockWidgetArea_,
            is_Qt_DockWidgetArea_PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_DockWidgetArea__PythonToCpp_QFlags_Qt_DockWidgetArea_,
            is_QFlags_Qt_DockWidgetArea__PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_DockWidgetArea_,
            is_number_PythonToCpp_QFlags_Qt_DockWidgetArea__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::DockWidgetArea>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<DockWidgetArea>");
    }
    // End of 'DockWidgetArea' enum/flags.

    // Initialization of enum 'DockWidgetAreaSizes'.
    SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "DockWidgetAreaSizes",
        "PySide.QtCore.Qt.DockWidgetAreaSizes",
        "Qt::DockWidgetAreaSizes");
    if (!SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX],
        &Sbk_Qt_Type, "NDockWidgetAreas", (long) Qt::NDockWidgetAreas))
        return ;
    // Register converter for enum 'Qt::DockWidgetAreaSizes'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX],
            Qt_DockWidgetAreaSizes_CppToPython_Qt_DockWidgetAreaSizes);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DockWidgetAreaSizes_PythonToCpp_Qt_DockWidgetAreaSizes,
            is_Qt_DockWidgetAreaSizes_PythonToCpp_Qt_DockWidgetAreaSizes_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREASIZES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::DockWidgetAreaSizes");
        Shiboken::Conversions::registerConverterName(converter, "DockWidgetAreaSizes");
    }
    // End of 'DockWidgetAreaSizes' enum.

    // Initialization of enum 'ToolBarArea'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX] = PySide::QFlags::create("ToolBarAreas", &SbkPySide_QtCore_Qt_ToolBarArea_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ToolBarArea",
        "PySide.QtCore.Qt.ToolBarArea",
        "Qt::ToolBarArea",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "LeftToolBarArea", (long) Qt::LeftToolBarArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "RightToolBarArea", (long) Qt::RightToolBarArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "TopToolBarArea", (long) Qt::TopToolBarArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "BottomToolBarArea", (long) Qt::BottomToolBarArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "ToolBarArea_Mask", (long) Qt::ToolBarArea_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "AllToolBarAreas", (long) Qt::AllToolBarAreas))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
        &Sbk_Qt_Type, "NoToolBarArea", (long) Qt::NoToolBarArea))
        return ;
    // Register converter for enum 'Qt::ToolBarArea'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX],
            Qt_ToolBarArea_CppToPython_Qt_ToolBarArea);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ToolBarArea_PythonToCpp_Qt_ToolBarArea,
            is_Qt_ToolBarArea_PythonToCpp_Qt_ToolBarArea_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ToolBarArea");
        Shiboken::Conversions::registerConverterName(converter, "ToolBarArea");
    }
    // Register converter for flag 'QFlags<Qt::ToolBarArea>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX],
            QFlags_Qt_ToolBarArea__CppToPython_QFlags_Qt_ToolBarArea_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ToolBarArea_PythonToCpp_QFlags_Qt_ToolBarArea_,
            is_Qt_ToolBarArea_PythonToCpp_QFlags_Qt_ToolBarArea__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_ToolBarArea__PythonToCpp_QFlags_Qt_ToolBarArea_,
            is_QFlags_Qt_ToolBarArea__PythonToCpp_QFlags_Qt_ToolBarArea__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_ToolBarArea_,
            is_number_PythonToCpp_QFlags_Qt_ToolBarArea__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TOOLBARAREA__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::ToolBarArea>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ToolBarArea>");
    }
    // End of 'ToolBarArea' enum/flags.

    // Initialization of enum 'ToolBarAreaSizes'.
    SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ToolBarAreaSizes",
        "PySide.QtCore.Qt.ToolBarAreaSizes",
        "Qt::ToolBarAreaSizes");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX],
        &Sbk_Qt_Type, "NToolBarAreas", (long) Qt::NToolBarAreas))
        return ;
    // Register converter for enum 'Qt::ToolBarAreaSizes'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX],
            Qt_ToolBarAreaSizes_CppToPython_Qt_ToolBarAreaSizes);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ToolBarAreaSizes_PythonToCpp_Qt_ToolBarAreaSizes,
            is_Qt_ToolBarAreaSizes_PythonToCpp_Qt_ToolBarAreaSizes_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREASIZES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ToolBarAreaSizes");
        Shiboken::Conversions::registerConverterName(converter, "ToolBarAreaSizes");
    }
    // End of 'ToolBarAreaSizes' enum.

    // Initialization of enum 'DateFormat'.
    SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "DateFormat",
        "PySide.QtCore.Qt.DateFormat",
        "Qt::DateFormat");
    if (!SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "TextDate", (long) Qt::TextDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "ISODate", (long) Qt::ISODate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "SystemLocaleDate", (long) Qt::SystemLocaleDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "LocalDate", (long) Qt::LocalDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "LocaleDate", (long) Qt::LocaleDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "SystemLocaleShortDate", (long) Qt::SystemLocaleShortDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "SystemLocaleLongDate", (long) Qt::SystemLocaleLongDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "DefaultLocaleShortDate", (long) Qt::DefaultLocaleShortDate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
        &Sbk_Qt_Type, "DefaultLocaleLongDate", (long) Qt::DefaultLocaleLongDate))
        return ;
    // Register converter for enum 'Qt::DateFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX],
            Qt_DateFormat_CppToPython_Qt_DateFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DateFormat_PythonToCpp_Qt_DateFormat,
            is_Qt_DateFormat_PythonToCpp_Qt_DateFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::DateFormat");
        Shiboken::Conversions::registerConverterName(converter, "DateFormat");
    }
    // End of 'DateFormat' enum.

    // Initialization of enum 'TimeSpec'.
    SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TimeSpec",
        "PySide.QtCore.Qt.TimeSpec",
        "Qt::TimeSpec");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX],
        &Sbk_Qt_Type, "LocalTime", (long) Qt::LocalTime))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX],
        &Sbk_Qt_Type, "UTC", (long) Qt::UTC))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX],
        &Sbk_Qt_Type, "OffsetFromUTC", (long) Qt::OffsetFromUTC))
        return ;
    // Register converter for enum 'Qt::TimeSpec'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX],
            Qt_TimeSpec_CppToPython_Qt_TimeSpec);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TimeSpec_PythonToCpp_Qt_TimeSpec,
            is_Qt_TimeSpec_PythonToCpp_Qt_TimeSpec_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TimeSpec");
        Shiboken::Conversions::registerConverterName(converter, "TimeSpec");
    }
    // End of 'TimeSpec' enum.

    // Initialization of enum 'DayOfWeek'.
    SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "DayOfWeek",
        "PySide.QtCore.Qt.DayOfWeek",
        "Qt::DayOfWeek");
    if (!SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Monday", (long) Qt::Monday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Tuesday", (long) Qt::Tuesday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Wednesday", (long) Qt::Wednesday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Thursday", (long) Qt::Thursday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Friday", (long) Qt::Friday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Saturday", (long) Qt::Saturday))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
        &Sbk_Qt_Type, "Sunday", (long) Qt::Sunday))
        return ;
    // Register converter for enum 'Qt::DayOfWeek'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX],
            Qt_DayOfWeek_CppToPython_Qt_DayOfWeek);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DayOfWeek_PythonToCpp_Qt_DayOfWeek,
            is_Qt_DayOfWeek_PythonToCpp_Qt_DayOfWeek_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::DayOfWeek");
        Shiboken::Conversions::registerConverterName(converter, "DayOfWeek");
    }
    // End of 'DayOfWeek' enum.

    // Initialization of enum 'ScrollBarPolicy'.
    SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ScrollBarPolicy",
        "PySide.QtCore.Qt.ScrollBarPolicy",
        "Qt::ScrollBarPolicy");
    if (!SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX],
        &Sbk_Qt_Type, "ScrollBarAsNeeded", (long) Qt::ScrollBarAsNeeded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX],
        &Sbk_Qt_Type, "ScrollBarAlwaysOff", (long) Qt::ScrollBarAlwaysOff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX],
        &Sbk_Qt_Type, "ScrollBarAlwaysOn", (long) Qt::ScrollBarAlwaysOn))
        return ;
    // Register converter for enum 'Qt::ScrollBarPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX],
            Qt_ScrollBarPolicy_CppToPython_Qt_ScrollBarPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ScrollBarPolicy_PythonToCpp_Qt_ScrollBarPolicy,
            is_Qt_ScrollBarPolicy_PythonToCpp_Qt_ScrollBarPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ScrollBarPolicy");
        Shiboken::Conversions::registerConverterName(converter, "ScrollBarPolicy");
    }
    // End of 'ScrollBarPolicy' enum.

    // Initialization of enum 'CaseSensitivity'.
    SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "CaseSensitivity",
        "PySide.QtCore.Qt.CaseSensitivity",
        "Qt::CaseSensitivity");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX],
        &Sbk_Qt_Type, "CaseInsensitive", (long) Qt::CaseInsensitive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX],
        &Sbk_Qt_Type, "CaseSensitive", (long) Qt::CaseSensitive))
        return ;
    // Register converter for enum 'Qt::CaseSensitivity'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX],
            Qt_CaseSensitivity_CppToPython_Qt_CaseSensitivity);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_CaseSensitivity_PythonToCpp_Qt_CaseSensitivity,
            is_Qt_CaseSensitivity_PythonToCpp_Qt_CaseSensitivity_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::CaseSensitivity");
        Shiboken::Conversions::registerConverterName(converter, "CaseSensitivity");
    }
    // End of 'CaseSensitivity' enum.

    // Initialization of enum 'Corner'.
    SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "Corner",
        "PySide.QtCore.Qt.Corner",
        "Qt::Corner");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX],
        &Sbk_Qt_Type, "TopLeftCorner", (long) Qt::TopLeftCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX],
        &Sbk_Qt_Type, "TopRightCorner", (long) Qt::TopRightCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX],
        &Sbk_Qt_Type, "BottomLeftCorner", (long) Qt::BottomLeftCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX],
        &Sbk_Qt_Type, "BottomRightCorner", (long) Qt::BottomRightCorner))
        return ;
    // Register converter for enum 'Qt::Corner'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX],
            Qt_Corner_CppToPython_Qt_Corner);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Corner_PythonToCpp_Qt_Corner,
            is_Qt_Corner_PythonToCpp_Qt_Corner_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::Corner");
        Shiboken::Conversions::registerConverterName(converter, "Corner");
    }
    // End of 'Corner' enum.

    // Initialization of enum 'ConnectionType'.
    SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ConnectionType",
        "PySide.QtCore.Qt.ConnectionType",
        "Qt::ConnectionType");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "AutoConnection", (long) Qt::AutoConnection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "DirectConnection", (long) Qt::DirectConnection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "QueuedConnection", (long) Qt::QueuedConnection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "AutoCompatConnection", (long) Qt::AutoCompatConnection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "BlockingQueuedConnection", (long) Qt::BlockingQueuedConnection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
        &Sbk_Qt_Type, "UniqueConnection", (long) Qt::UniqueConnection))
        return ;
    // Register converter for enum 'Qt::ConnectionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX],
            Qt_ConnectionType_CppToPython_Qt_ConnectionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ConnectionType_PythonToCpp_Qt_ConnectionType,
            is_Qt_ConnectionType_PythonToCpp_Qt_ConnectionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ConnectionType");
        Shiboken::Conversions::registerConverterName(converter, "ConnectionType");
    }
    // End of 'ConnectionType' enum.

    // Initialization of enum 'ShortcutContext'.
    SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ShortcutContext",
        "PySide.QtCore.Qt.ShortcutContext",
        "Qt::ShortcutContext");
    if (!SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX],
        &Sbk_Qt_Type, "WidgetShortcut", (long) Qt::WidgetShortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX],
        &Sbk_Qt_Type, "WindowShortcut", (long) Qt::WindowShortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX],
        &Sbk_Qt_Type, "ApplicationShortcut", (long) Qt::ApplicationShortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX],
        &Sbk_Qt_Type, "WidgetWithChildrenShortcut", (long) Qt::WidgetWithChildrenShortcut))
        return ;
    // Register converter for enum 'Qt::ShortcutContext'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX],
            Qt_ShortcutContext_CppToPython_Qt_ShortcutContext);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ShortcutContext_PythonToCpp_Qt_ShortcutContext,
            is_Qt_ShortcutContext_PythonToCpp_Qt_ShortcutContext_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ShortcutContext");
        Shiboken::Conversions::registerConverterName(converter, "ShortcutContext");
    }
    // End of 'ShortcutContext' enum.

    // Initialization of enum 'FillRule'.
    SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "FillRule",
        "PySide.QtCore.Qt.FillRule",
        "Qt::FillRule");
    if (!SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX],
        &Sbk_Qt_Type, "OddEvenFill", (long) Qt::OddEvenFill))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX],
        &Sbk_Qt_Type, "WindingFill", (long) Qt::WindingFill))
        return ;
    // Register converter for enum 'Qt::FillRule'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX],
            Qt_FillRule_CppToPython_Qt_FillRule);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_FillRule_PythonToCpp_Qt_FillRule,
            is_Qt_FillRule_PythonToCpp_Qt_FillRule_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::FillRule");
        Shiboken::Conversions::registerConverterName(converter, "FillRule");
    }
    // End of 'FillRule' enum.

    // Initialization of enum 'MaskMode'.
    SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "MaskMode",
        "PySide.QtCore.Qt.MaskMode",
        "Qt::MaskMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX],
        &Sbk_Qt_Type, "MaskInColor", (long) Qt::MaskInColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX],
        &Sbk_Qt_Type, "MaskOutColor", (long) Qt::MaskOutColor))
        return ;
    // Register converter for enum 'Qt::MaskMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX],
            Qt_MaskMode_CppToPython_Qt_MaskMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_MaskMode_PythonToCpp_Qt_MaskMode,
            is_Qt_MaskMode_PythonToCpp_Qt_MaskMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MASKMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::MaskMode");
        Shiboken::Conversions::registerConverterName(converter, "MaskMode");
    }
    // End of 'MaskMode' enum.

    // Initialization of enum 'ClipOperation'.
    SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ClipOperation",
        "PySide.QtCore.Qt.ClipOperation",
        "Qt::ClipOperation");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX],
        &Sbk_Qt_Type, "NoClip", (long) Qt::NoClip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX],
        &Sbk_Qt_Type, "ReplaceClip", (long) Qt::ReplaceClip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX],
        &Sbk_Qt_Type, "IntersectClip", (long) Qt::IntersectClip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX],
        &Sbk_Qt_Type, "UniteClip", (long) Qt::UniteClip))
        return ;
    // Register converter for enum 'Qt::ClipOperation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX],
            Qt_ClipOperation_CppToPython_Qt_ClipOperation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ClipOperation_PythonToCpp_Qt_ClipOperation,
            is_Qt_ClipOperation_PythonToCpp_Qt_ClipOperation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ClipOperation");
        Shiboken::Conversions::registerConverterName(converter, "ClipOperation");
    }
    // End of 'ClipOperation' enum.

    // Initialization of enum 'ItemSelectionMode'.
    SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ItemSelectionMode",
        "PySide.QtCore.Qt.ItemSelectionMode",
        "Qt::ItemSelectionMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX],
        &Sbk_Qt_Type, "ContainsItemShape", (long) Qt::ContainsItemShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX],
        &Sbk_Qt_Type, "IntersectsItemShape", (long) Qt::IntersectsItemShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX],
        &Sbk_Qt_Type, "ContainsItemBoundingRect", (long) Qt::ContainsItemBoundingRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX],
        &Sbk_Qt_Type, "IntersectsItemBoundingRect", (long) Qt::IntersectsItemBoundingRect))
        return ;
    // Register converter for enum 'Qt::ItemSelectionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX],
            Qt_ItemSelectionMode_CppToPython_Qt_ItemSelectionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ItemSelectionMode_PythonToCpp_Qt_ItemSelectionMode,
            is_Qt_ItemSelectionMode_PythonToCpp_Qt_ItemSelectionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ItemSelectionMode");
        Shiboken::Conversions::registerConverterName(converter, "ItemSelectionMode");
    }
    // End of 'ItemSelectionMode' enum.

    // Initialization of enum 'TransformationMode'.
    SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TransformationMode",
        "PySide.QtCore.Qt.TransformationMode",
        "Qt::TransformationMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX],
        &Sbk_Qt_Type, "FastTransformation", (long) Qt::FastTransformation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX],
        &Sbk_Qt_Type, "SmoothTransformation", (long) Qt::SmoothTransformation))
        return ;
    // Register converter for enum 'Qt::TransformationMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX],
            Qt_TransformationMode_CppToPython_Qt_TransformationMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TransformationMode_PythonToCpp_Qt_TransformationMode,
            is_Qt_TransformationMode_PythonToCpp_Qt_TransformationMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TRANSFORMATIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TransformationMode");
        Shiboken::Conversions::registerConverterName(converter, "TransformationMode");
    }
    // End of 'TransformationMode' enum.

    // Initialization of enum 'Axis'.
    SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "Axis",
        "PySide.QtCore.Qt.Axis",
        "Qt::Axis");
    if (!SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX],
        &Sbk_Qt_Type, "XAxis", (long) Qt::XAxis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX],
        &Sbk_Qt_Type, "YAxis", (long) Qt::YAxis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX],
        &Sbk_Qt_Type, "ZAxis", (long) Qt::ZAxis))
        return ;
    // Register converter for enum 'Qt::Axis'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX],
            Qt_Axis_CppToPython_Qt_Axis);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_Axis_PythonToCpp_Qt_Axis,
            is_Qt_Axis_PythonToCpp_Qt_Axis_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_AXIS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::Axis");
        Shiboken::Conversions::registerConverterName(converter, "Axis");
    }
    // End of 'Axis' enum.

    // Initialization of enum 'FocusReason'.
    SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "FocusReason",
        "PySide.QtCore.Qt.FocusReason",
        "Qt::FocusReason");
    if (!SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "MouseFocusReason", (long) Qt::MouseFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "TabFocusReason", (long) Qt::TabFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "BacktabFocusReason", (long) Qt::BacktabFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "ActiveWindowFocusReason", (long) Qt::ActiveWindowFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "PopupFocusReason", (long) Qt::PopupFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "ShortcutFocusReason", (long) Qt::ShortcutFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "MenuBarFocusReason", (long) Qt::MenuBarFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "OtherFocusReason", (long) Qt::OtherFocusReason))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
        &Sbk_Qt_Type, "NoFocusReason", (long) Qt::NoFocusReason))
        return ;
    // Register converter for enum 'Qt::FocusReason'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX],
            Qt_FocusReason_CppToPython_Qt_FocusReason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_FocusReason_PythonToCpp_Qt_FocusReason,
            is_Qt_FocusReason_PythonToCpp_Qt_FocusReason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::FocusReason");
        Shiboken::Conversions::registerConverterName(converter, "FocusReason");
    }
    // End of 'FocusReason' enum.

    // Initialization of enum 'ContextMenuPolicy'.
    SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ContextMenuPolicy",
        "PySide.QtCore.Qt.ContextMenuPolicy",
        "Qt::ContextMenuPolicy");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
        &Sbk_Qt_Type, "NoContextMenu", (long) Qt::NoContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
        &Sbk_Qt_Type, "DefaultContextMenu", (long) Qt::DefaultContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
        &Sbk_Qt_Type, "ActionsContextMenu", (long) Qt::ActionsContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
        &Sbk_Qt_Type, "CustomContextMenu", (long) Qt::CustomContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
        &Sbk_Qt_Type, "PreventContextMenu", (long) Qt::PreventContextMenu))
        return ;
    // Register converter for enum 'Qt::ContextMenuPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX],
            Qt_ContextMenuPolicy_CppToPython_Qt_ContextMenuPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ContextMenuPolicy_PythonToCpp_Qt_ContextMenuPolicy,
            is_Qt_ContextMenuPolicy_PythonToCpp_Qt_ContextMenuPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CONTEXTMENUPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ContextMenuPolicy");
        Shiboken::Conversions::registerConverterName(converter, "ContextMenuPolicy");
    }
    // End of 'ContextMenuPolicy' enum.

    // Initialization of enum 'InputMethodQuery'.
    SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "InputMethodQuery",
        "PySide.QtCore.Qt.InputMethodQuery",
        "Qt::InputMethodQuery");
    if (!SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImMicroFocus", (long) Qt::ImMicroFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImFont", (long) Qt::ImFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImCursorPosition", (long) Qt::ImCursorPosition))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImSurroundingText", (long) Qt::ImSurroundingText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImCurrentSelection", (long) Qt::ImCurrentSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImMaximumTextLength", (long) Qt::ImMaximumTextLength))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
        &Sbk_Qt_Type, "ImAnchorPosition", (long) Qt::ImAnchorPosition))
        return ;
    // Register converter for enum 'Qt::InputMethodQuery'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX],
            Qt_InputMethodQuery_CppToPython_Qt_InputMethodQuery);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_InputMethodQuery_PythonToCpp_Qt_InputMethodQuery,
            is_Qt_InputMethodQuery_PythonToCpp_Qt_InputMethodQuery_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::InputMethodQuery");
        Shiboken::Conversions::registerConverterName(converter, "InputMethodQuery");
    }
    // End of 'InputMethodQuery' enum.

    // Initialization of enum 'InputMethodHint'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX] = PySide::QFlags::create("InputMethodHints", &SbkPySide_QtCore_Qt_InputMethodHint_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "InputMethodHint",
        "PySide.QtCore.Qt.InputMethodHint",
        "Qt::InputMethodHint",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhNone", (long) Qt::ImhNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhHiddenText", (long) Qt::ImhHiddenText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhNoAutoUppercase", (long) Qt::ImhNoAutoUppercase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhPreferNumbers", (long) Qt::ImhPreferNumbers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhPreferUppercase", (long) Qt::ImhPreferUppercase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhPreferLowercase", (long) Qt::ImhPreferLowercase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhNoPredictiveText", (long) Qt::ImhNoPredictiveText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhDigitsOnly", (long) Qt::ImhDigitsOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhFormattedNumbersOnly", (long) Qt::ImhFormattedNumbersOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhUppercaseOnly", (long) Qt::ImhUppercaseOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhLowercaseOnly", (long) Qt::ImhLowercaseOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhDialableCharactersOnly", (long) Qt::ImhDialableCharactersOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhEmailCharactersOnly", (long) Qt::ImhEmailCharactersOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhUrlCharactersOnly", (long) Qt::ImhUrlCharactersOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
        &Sbk_Qt_Type, "ImhExclusiveInputMask", (long) Qt::ImhExclusiveInputMask))
        return ;
    // Register converter for enum 'Qt::InputMethodHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX],
            Qt_InputMethodHint_CppToPython_Qt_InputMethodHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_InputMethodHint_PythonToCpp_Qt_InputMethodHint,
            is_Qt_InputMethodHint_PythonToCpp_Qt_InputMethodHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::InputMethodHint");
        Shiboken::Conversions::registerConverterName(converter, "InputMethodHint");
    }
    // Register converter for flag 'QFlags<Qt::InputMethodHint>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX],
            QFlags_Qt_InputMethodHint__CppToPython_QFlags_Qt_InputMethodHint_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_InputMethodHint_PythonToCpp_QFlags_Qt_InputMethodHint_,
            is_Qt_InputMethodHint_PythonToCpp_QFlags_Qt_InputMethodHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_InputMethodHint__PythonToCpp_QFlags_Qt_InputMethodHint_,
            is_QFlags_Qt_InputMethodHint__PythonToCpp_QFlags_Qt_InputMethodHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_InputMethodHint_,
            is_number_PythonToCpp_QFlags_Qt_InputMethodHint__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::InputMethodHint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<InputMethodHint>");
    }
    // End of 'InputMethodHint' enum/flags.

    // Initialization of enum 'ToolButtonStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ToolButtonStyle",
        "PySide.QtCore.Qt.ToolButtonStyle",
        "Qt::ToolButtonStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
        &Sbk_Qt_Type, "ToolButtonIconOnly", (long) Qt::ToolButtonIconOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
        &Sbk_Qt_Type, "ToolButtonTextOnly", (long) Qt::ToolButtonTextOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
        &Sbk_Qt_Type, "ToolButtonTextBesideIcon", (long) Qt::ToolButtonTextBesideIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
        &Sbk_Qt_Type, "ToolButtonTextUnderIcon", (long) Qt::ToolButtonTextUnderIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
        &Sbk_Qt_Type, "ToolButtonFollowStyle", (long) Qt::ToolButtonFollowStyle))
        return ;
    // Register converter for enum 'Qt::ToolButtonStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX],
            Qt_ToolButtonStyle_CppToPython_Qt_ToolButtonStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ToolButtonStyle_PythonToCpp_Qt_ToolButtonStyle,
            is_Qt_ToolButtonStyle_PythonToCpp_Qt_ToolButtonStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ToolButtonStyle");
        Shiboken::Conversions::registerConverterName(converter, "ToolButtonStyle");
    }
    // End of 'ToolButtonStyle' enum.

    // Initialization of enum 'LayoutDirection'.
    SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "LayoutDirection",
        "PySide.QtCore.Qt.LayoutDirection",
        "Qt::LayoutDirection");
    if (!SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX],
        &Sbk_Qt_Type, "LeftToRight", (long) Qt::LeftToRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX],
        &Sbk_Qt_Type, "RightToLeft", (long) Qt::RightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX],
        &Sbk_Qt_Type, "LayoutDirectionAuto", (long) Qt::LayoutDirectionAuto))
        return ;
    // Register converter for enum 'Qt::LayoutDirection'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX],
            Qt_LayoutDirection_CppToPython_Qt_LayoutDirection);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_LayoutDirection_PythonToCpp_Qt_LayoutDirection,
            is_Qt_LayoutDirection_PythonToCpp_Qt_LayoutDirection_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::LayoutDirection");
        Shiboken::Conversions::registerConverterName(converter, "LayoutDirection");
    }
    // End of 'LayoutDirection' enum.

    // Initialization of enum 'AnchorPoint'.
    SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "AnchorPoint",
        "PySide.QtCore.Qt.AnchorPoint",
        "Qt::AnchorPoint");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorLeft", (long) Qt::AnchorLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorHorizontalCenter", (long) Qt::AnchorHorizontalCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorRight", (long) Qt::AnchorRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorTop", (long) Qt::AnchorTop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorVerticalCenter", (long) Qt::AnchorVerticalCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
        &Sbk_Qt_Type, "AnchorBottom", (long) Qt::AnchorBottom))
        return ;
    // Register converter for enum 'Qt::AnchorPoint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX],
            Qt_AnchorPoint_CppToPython_Qt_AnchorPoint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_AnchorPoint_PythonToCpp_Qt_AnchorPoint,
            is_Qt_AnchorPoint_PythonToCpp_Qt_AnchorPoint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::AnchorPoint");
        Shiboken::Conversions::registerConverterName(converter, "AnchorPoint");
    }
    // End of 'AnchorPoint' enum.

    // Initialization of enum 'DropAction'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX] = PySide::QFlags::create("DropActions", &SbkPySide_QtCore_Qt_DropAction_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "DropAction",
        "PySide.QtCore.Qt.DropAction",
        "Qt::DropAction",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "CopyAction", (long) Qt::CopyAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "MoveAction", (long) Qt::MoveAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "LinkAction", (long) Qt::LinkAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "ActionMask", (long) Qt::ActionMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "TargetMoveAction", (long) Qt::TargetMoveAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
        &Sbk_Qt_Type, "IgnoreAction", (long) Qt::IgnoreAction))
        return ;
    // Register converter for enum 'Qt::DropAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX],
            Qt_DropAction_CppToPython_Qt_DropAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DropAction_PythonToCpp_Qt_DropAction,
            is_Qt_DropAction_PythonToCpp_Qt_DropAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::DropAction");
        Shiboken::Conversions::registerConverterName(converter, "DropAction");
    }
    // Register converter for flag 'QFlags<Qt::DropAction>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX],
            QFlags_Qt_DropAction__CppToPython_QFlags_Qt_DropAction_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_DropAction_PythonToCpp_QFlags_Qt_DropAction_,
            is_Qt_DropAction_PythonToCpp_QFlags_Qt_DropAction__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_DropAction__PythonToCpp_QFlags_Qt_DropAction_,
            is_QFlags_Qt_DropAction__PythonToCpp_QFlags_Qt_DropAction__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_DropAction_,
            is_number_PythonToCpp_QFlags_Qt_DropAction__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::DropAction>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<DropAction>");
    }
    // End of 'DropAction' enum/flags.

    // Initialization of enum 'CheckState'.
    SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "CheckState",
        "PySide.QtCore.Qt.CheckState",
        "Qt::CheckState");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX],
        &Sbk_Qt_Type, "Unchecked", (long) Qt::Unchecked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX],
        &Sbk_Qt_Type, "PartiallyChecked", (long) Qt::PartiallyChecked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX],
        &Sbk_Qt_Type, "Checked", (long) Qt::Checked))
        return ;
    // Register converter for enum 'Qt::CheckState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX],
            Qt_CheckState_CppToPython_Qt_CheckState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_CheckState_PythonToCpp_Qt_CheckState,
            is_Qt_CheckState_PythonToCpp_Qt_CheckState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::CheckState");
        Shiboken::Conversions::registerConverterName(converter, "CheckState");
    }
    // End of 'CheckState' enum.

    // Initialization of enum 'ItemDataRole'.
    SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ItemDataRole",
        "PySide.QtCore.Qt.ItemDataRole",
        "Qt::ItemDataRole");
    if (!SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "DisplayRole", (long) Qt::DisplayRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "DecorationRole", (long) Qt::DecorationRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "EditRole", (long) Qt::EditRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "ToolTipRole", (long) Qt::ToolTipRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "StatusTipRole", (long) Qt::StatusTipRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "WhatsThisRole", (long) Qt::WhatsThisRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "FontRole", (long) Qt::FontRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "TextAlignmentRole", (long) Qt::TextAlignmentRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "BackgroundColorRole", (long) Qt::BackgroundColorRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "BackgroundRole", (long) Qt::BackgroundRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "TextColorRole", (long) Qt::TextColorRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "ForegroundRole", (long) Qt::ForegroundRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "CheckStateRole", (long) Qt::CheckStateRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "AccessibleTextRole", (long) Qt::AccessibleTextRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "AccessibleDescriptionRole", (long) Qt::AccessibleDescriptionRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "SizeHintRole", (long) Qt::SizeHintRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "InitialSortOrderRole", (long) Qt::InitialSortOrderRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "DisplayPropertyRole", (long) Qt::DisplayPropertyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "DecorationPropertyRole", (long) Qt::DecorationPropertyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "ToolTipPropertyRole", (long) Qt::ToolTipPropertyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "StatusTipPropertyRole", (long) Qt::StatusTipPropertyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "WhatsThisPropertyRole", (long) Qt::WhatsThisPropertyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
        &Sbk_Qt_Type, "UserRole", (long) Qt::UserRole))
        return ;
    // Register converter for enum 'Qt::ItemDataRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX],
            Qt_ItemDataRole_CppToPython_Qt_ItemDataRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ItemDataRole_PythonToCpp_Qt_ItemDataRole,
            is_Qt_ItemDataRole_PythonToCpp_Qt_ItemDataRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMDATAROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ItemDataRole");
        Shiboken::Conversions::registerConverterName(converter, "ItemDataRole");
    }
    // End of 'ItemDataRole' enum.

    // Initialization of enum 'ItemFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX] = PySide::QFlags::create("ItemFlags", &SbkPySide_QtCore_Qt_ItemFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "ItemFlag",
        "PySide.QtCore.Qt.ItemFlag",
        "Qt::ItemFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "NoItemFlags", (long) Qt::NoItemFlags))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsSelectable", (long) Qt::ItemIsSelectable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsEditable", (long) Qt::ItemIsEditable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsDragEnabled", (long) Qt::ItemIsDragEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsDropEnabled", (long) Qt::ItemIsDropEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsUserCheckable", (long) Qt::ItemIsUserCheckable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsEnabled", (long) Qt::ItemIsEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
        &Sbk_Qt_Type, "ItemIsTristate", (long) Qt::ItemIsTristate))
        return ;
    // Register converter for enum 'Qt::ItemFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX],
            Qt_ItemFlag_CppToPython_Qt_ItemFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ItemFlag_PythonToCpp_Qt_ItemFlag,
            is_Qt_ItemFlag_PythonToCpp_Qt_ItemFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_ITEMFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::ItemFlag");
        Shiboken::Conversions::registerConverterName(converter, "ItemFlag");
    }
    // Register converter for flag 'QFlags<Qt::ItemFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX],
            QFlags_Qt_ItemFlag__CppToPython_QFlags_Qt_ItemFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_ItemFlag_PythonToCpp_QFlags_Qt_ItemFlag_,
            is_Qt_ItemFlag_PythonToCpp_QFlags_Qt_ItemFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_ItemFlag__PythonToCpp_QFlags_Qt_ItemFlag_,
            is_QFlags_Qt_ItemFlag__PythonToCpp_QFlags_Qt_ItemFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_ItemFlag_,
            is_number_PythonToCpp_QFlags_Qt_ItemFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::ItemFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ItemFlag>");
    }
    // End of 'ItemFlag' enum/flags.

    // Initialization of enum 'MatchFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX] = PySide::QFlags::create("MatchFlags", &SbkPySide_QtCore_Qt_MatchFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "MatchFlag",
        "PySide.QtCore.Qt.MatchFlag",
        "Qt::MatchFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchExactly", (long) Qt::MatchExactly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchContains", (long) Qt::MatchContains))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchStartsWith", (long) Qt::MatchStartsWith))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchEndsWith", (long) Qt::MatchEndsWith))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchRegExp", (long) Qt::MatchRegExp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchWildcard", (long) Qt::MatchWildcard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchFixedString", (long) Qt::MatchFixedString))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchCaseSensitive", (long) Qt::MatchCaseSensitive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchWrap", (long) Qt::MatchWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
        &Sbk_Qt_Type, "MatchRecursive", (long) Qt::MatchRecursive))
        return ;
    // Register converter for enum 'Qt::MatchFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX],
            Qt_MatchFlag_CppToPython_Qt_MatchFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_MatchFlag_PythonToCpp_Qt_MatchFlag,
            is_Qt_MatchFlag_PythonToCpp_Qt_MatchFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_MATCHFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::MatchFlag");
        Shiboken::Conversions::registerConverterName(converter, "MatchFlag");
    }
    // Register converter for flag 'QFlags<Qt::MatchFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX],
            QFlags_Qt_MatchFlag__CppToPython_QFlags_Qt_MatchFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_MatchFlag_PythonToCpp_QFlags_Qt_MatchFlag_,
            is_Qt_MatchFlag_PythonToCpp_QFlags_Qt_MatchFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_MatchFlag__PythonToCpp_QFlags_Qt_MatchFlag_,
            is_QFlags_Qt_MatchFlag__PythonToCpp_QFlags_Qt_MatchFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_MatchFlag_,
            is_number_PythonToCpp_QFlags_Qt_MatchFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::MatchFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<MatchFlag>");
    }
    // End of 'MatchFlag' enum/flags.

    // Initialization of enum 'WindowModality'.
    SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WindowModality",
        "PySide.QtCore.Qt.WindowModality",
        "Qt::WindowModality");
    if (!SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX],
        &Sbk_Qt_Type, "NonModal", (long) Qt::NonModal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX],
        &Sbk_Qt_Type, "WindowModal", (long) Qt::WindowModal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX],
        &Sbk_Qt_Type, "ApplicationModal", (long) Qt::ApplicationModal))
        return ;
    // Register converter for enum 'Qt::WindowModality'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX],
            Qt_WindowModality_CppToPython_Qt_WindowModality);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowModality_PythonToCpp_Qt_WindowModality,
            is_Qt_WindowModality_PythonToCpp_Qt_WindowModality_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WindowModality");
        Shiboken::Conversions::registerConverterName(converter, "WindowModality");
    }
    // End of 'WindowModality' enum.

    // Initialization of enum 'TextInteractionFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX] = PySide::QFlags::create("TextInteractionFlags", &SbkPySide_QtCore_Qt_TextInteractionFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TextInteractionFlag",
        "PySide.QtCore.Qt.TextInteractionFlag",
        "Qt::TextInteractionFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "NoTextInteraction", (long) Qt::NoTextInteraction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "TextSelectableByMouse", (long) Qt::TextSelectableByMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "TextSelectableByKeyboard", (long) Qt::TextSelectableByKeyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "LinksAccessibleByMouse", (long) Qt::LinksAccessibleByMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "LinksAccessibleByKeyboard", (long) Qt::LinksAccessibleByKeyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "TextEditable", (long) Qt::TextEditable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "TextEditorInteraction", (long) Qt::TextEditorInteraction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
        &Sbk_Qt_Type, "TextBrowserInteraction", (long) Qt::TextBrowserInteraction))
        return ;
    // Register converter for enum 'Qt::TextInteractionFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX],
            Qt_TextInteractionFlag_CppToPython_Qt_TextInteractionFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TextInteractionFlag_PythonToCpp_Qt_TextInteractionFlag,
            is_Qt_TextInteractionFlag_PythonToCpp_Qt_TextInteractionFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TEXTINTERACTIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TextInteractionFlag");
        Shiboken::Conversions::registerConverterName(converter, "TextInteractionFlag");
    }
    // Register converter for flag 'QFlags<Qt::TextInteractionFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX],
            QFlags_Qt_TextInteractionFlag__CppToPython_QFlags_Qt_TextInteractionFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TextInteractionFlag_PythonToCpp_QFlags_Qt_TextInteractionFlag_,
            is_Qt_TextInteractionFlag_PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_TextInteractionFlag__PythonToCpp_QFlags_Qt_TextInteractionFlag_,
            is_QFlags_Qt_TextInteractionFlag__PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_TextInteractionFlag_,
            is_number_PythonToCpp_QFlags_Qt_TextInteractionFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::TextInteractionFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<TextInteractionFlag>");
    }
    // End of 'TextInteractionFlag' enum/flags.

    // Initialization of enum 'EventPriority'.
    SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "EventPriority",
        "PySide.QtCore.Qt.EventPriority",
        "Qt::EventPriority");
    if (!SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX],
        &Sbk_Qt_Type, "HighEventPriority", (long) Qt::HighEventPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX],
        &Sbk_Qt_Type, "NormalEventPriority", (long) Qt::NormalEventPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX],
        &Sbk_Qt_Type, "LowEventPriority", (long) Qt::LowEventPriority))
        return ;
    // Register converter for enum 'Qt::EventPriority'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX],
            Qt_EventPriority_CppToPython_Qt_EventPriority);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_EventPriority_PythonToCpp_Qt_EventPriority,
            is_Qt_EventPriority_PythonToCpp_Qt_EventPriority_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_EVENTPRIORITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::EventPriority");
        Shiboken::Conversions::registerConverterName(converter, "EventPriority");
    }
    // End of 'EventPriority' enum.

    // Initialization of enum 'SizeHint'.
    SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "SizeHint",
        "PySide.QtCore.Qt.SizeHint",
        "Qt::SizeHint");
    if (!SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
        &Sbk_Qt_Type, "MinimumSize", (long) Qt::MinimumSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
        &Sbk_Qt_Type, "PreferredSize", (long) Qt::PreferredSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
        &Sbk_Qt_Type, "MaximumSize", (long) Qt::MaximumSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
        &Sbk_Qt_Type, "MinimumDescent", (long) Qt::MinimumDescent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
        &Sbk_Qt_Type, "NSizeHints", (long) Qt::NSizeHints))
        return ;
    // Register converter for enum 'Qt::SizeHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX],
            Qt_SizeHint_CppToPython_Qt_SizeHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_SizeHint_PythonToCpp_Qt_SizeHint,
            is_Qt_SizeHint_PythonToCpp_Qt_SizeHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::SizeHint");
        Shiboken::Conversions::registerConverterName(converter, "SizeHint");
    }
    // End of 'SizeHint' enum.

    // Initialization of enum 'WindowFrameSection'.
    SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WindowFrameSection",
        "PySide.QtCore.Qt.WindowFrameSection",
        "Qt::WindowFrameSection");
    if (!SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "NoSection", (long) Qt::NoSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "LeftSection", (long) Qt::LeftSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "TopLeftSection", (long) Qt::TopLeftSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "TopSection", (long) Qt::TopSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "TopRightSection", (long) Qt::TopRightSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "RightSection", (long) Qt::RightSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "BottomRightSection", (long) Qt::BottomRightSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "BottomSection", (long) Qt::BottomSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "BottomLeftSection", (long) Qt::BottomLeftSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
        &Sbk_Qt_Type, "TitleBarArea", (long) Qt::TitleBarArea))
        return ;
    // Register converter for enum 'Qt::WindowFrameSection'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX],
            Qt_WindowFrameSection_CppToPython_Qt_WindowFrameSection);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WindowFrameSection_PythonToCpp_Qt_WindowFrameSection,
            is_Qt_WindowFrameSection_PythonToCpp_Qt_WindowFrameSection_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WINDOWFRAMESECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WindowFrameSection");
        Shiboken::Conversions::registerConverterName(converter, "WindowFrameSection");
    }
    // End of 'WindowFrameSection' enum.

    // Initialization of enum 'CoordinateSystem'.
    SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "CoordinateSystem",
        "PySide.QtCore.Qt.CoordinateSystem",
        "Qt::CoordinateSystem");
    if (!SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX],
        &Sbk_Qt_Type, "DeviceCoordinates", (long) Qt::DeviceCoordinates))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX],
        &Sbk_Qt_Type, "LogicalCoordinates", (long) Qt::LogicalCoordinates))
        return ;
    // Register converter for enum 'Qt::CoordinateSystem'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX],
            Qt_CoordinateSystem_CppToPython_Qt_CoordinateSystem);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_CoordinateSystem_PythonToCpp_Qt_CoordinateSystem,
            is_Qt_CoordinateSystem_PythonToCpp_Qt_CoordinateSystem_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_COORDINATESYSTEM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::CoordinateSystem");
        Shiboken::Conversions::registerConverterName(converter, "CoordinateSystem");
    }
    // End of 'CoordinateSystem' enum.

    // Initialization of enum 'TouchPointState'.
    SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "TouchPointState",
        "PySide.QtCore.Qt.TouchPointState",
        "Qt::TouchPointState");
    if (!SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointPressed", (long) Qt::TouchPointPressed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointMoved", (long) Qt::TouchPointMoved))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointStationary", (long) Qt::TouchPointStationary))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointReleased", (long) Qt::TouchPointReleased))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointStateMask", (long) Qt::TouchPointStateMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
        &Sbk_Qt_Type, "TouchPointPrimary", (long) Qt::TouchPointPrimary))
        return ;
    // Register converter for enum 'Qt::TouchPointState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX],
            Qt_TouchPointState_CppToPython_Qt_TouchPointState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_TouchPointState_PythonToCpp_Qt_TouchPointState,
            is_Qt_TouchPointState_PythonToCpp_Qt_TouchPointState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::TouchPointState");
        Shiboken::Conversions::registerConverterName(converter, "TouchPointState");
    }
    // End of 'TouchPointState' enum.

    // Initialization of enum 'GestureState'.
    SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "GestureState",
        "PySide.QtCore.Qt.GestureState",
        "Qt::GestureState");
    if (!SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
        &Sbk_Qt_Type, "NoGesture", (long) Qt::NoGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
        &Sbk_Qt_Type, "GestureStarted", (long) Qt::GestureStarted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
        &Sbk_Qt_Type, "GestureUpdated", (long) Qt::GestureUpdated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
        &Sbk_Qt_Type, "GestureFinished", (long) Qt::GestureFinished))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
        &Sbk_Qt_Type, "GestureCanceled", (long) Qt::GestureCanceled))
        return ;
    // Register converter for enum 'Qt::GestureState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX],
            Qt_GestureState_CppToPython_Qt_GestureState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_GestureState_PythonToCpp_Qt_GestureState,
            is_Qt_GestureState_PythonToCpp_Qt_GestureState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURESTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::GestureState");
        Shiboken::Conversions::registerConverterName(converter, "GestureState");
    }
    // End of 'GestureState' enum.

    // Initialization of enum 'GestureType'.
    SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "GestureType",
        "PySide.QtCore.Qt.GestureType",
        "Qt::GestureType");
    if (!SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "TapGesture", (long) Qt::TapGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "TapAndHoldGesture", (long) Qt::TapAndHoldGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "PanGesture", (long) Qt::PanGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "PinchGesture", (long) Qt::PinchGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "SwipeGesture", (long) Qt::SwipeGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "CustomGesture", (long) Qt::CustomGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
        &Sbk_Qt_Type, "LastGestureType", (long) Qt::LastGestureType))
        return ;
    // Register converter for enum 'Qt::GestureType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX],
            Qt_GestureType_CppToPython_Qt_GestureType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_GestureType_PythonToCpp_Qt_GestureType,
            is_Qt_GestureType_PythonToCpp_Qt_GestureType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::GestureType");
        Shiboken::Conversions::registerConverterName(converter, "GestureType");
    }
    // End of 'GestureType' enum.

    // Initialization of enum 'GestureFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX] = PySide::QFlags::create("GestureFlags", &SbkPySide_QtCore_Qt_GestureFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "GestureFlag",
        "PySide.QtCore.Qt.GestureFlag",
        "Qt::GestureFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX],
        &Sbk_Qt_Type, "DontStartGestureOnChildren", (long) Qt::DontStartGestureOnChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX],
        &Sbk_Qt_Type, "ReceivePartialGestures", (long) Qt::ReceivePartialGestures))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX],
        &Sbk_Qt_Type, "IgnoredGesturesPropagateToParent", (long) Qt::IgnoredGesturesPropagateToParent))
        return ;
    // Register converter for enum 'Qt::GestureFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX],
            Qt_GestureFlag_CppToPython_Qt_GestureFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_GestureFlag_PythonToCpp_Qt_GestureFlag,
            is_Qt_GestureFlag_PythonToCpp_Qt_GestureFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_GESTUREFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::GestureFlag");
        Shiboken::Conversions::registerConverterName(converter, "GestureFlag");
    }
    // Register converter for flag 'QFlags<Qt::GestureFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX],
            QFlags_Qt_GestureFlag__CppToPython_QFlags_Qt_GestureFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_GestureFlag_PythonToCpp_QFlags_Qt_GestureFlag_,
            is_Qt_GestureFlag_PythonToCpp_QFlags_Qt_GestureFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Qt_GestureFlag__PythonToCpp_QFlags_Qt_GestureFlag_,
            is_QFlags_Qt_GestureFlag__PythonToCpp_QFlags_Qt_GestureFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Qt_GestureFlag_,
            is_number_PythonToCpp_QFlags_Qt_GestureFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_GESTUREFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Qt::GestureFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<GestureFlag>");
    }
    // End of 'GestureFlag' enum/flags.

    // Initialization of enum 'NavigationMode'.
    SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "NavigationMode",
        "PySide.QtCore.Qt.NavigationMode",
        "Qt::NavigationMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
        &Sbk_Qt_Type, "NavigationModeNone", (long) Qt::NavigationModeNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
        &Sbk_Qt_Type, "NavigationModeKeypadTabOrder", (long) Qt::NavigationModeKeypadTabOrder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
        &Sbk_Qt_Type, "NavigationModeKeypadDirectional", (long) Qt::NavigationModeKeypadDirectional))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
        &Sbk_Qt_Type, "NavigationModeCursorAuto", (long) Qt::NavigationModeCursorAuto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
        &Sbk_Qt_Type, "NavigationModeCursorForceVisible", (long) Qt::NavigationModeCursorForceVisible))
        return ;
    // Register converter for enum 'Qt::NavigationMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX],
            Qt_NavigationMode_CppToPython_Qt_NavigationMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_NavigationMode_PythonToCpp_Qt_NavigationMode,
            is_Qt_NavigationMode_PythonToCpp_Qt_NavigationMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_NAVIGATIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::NavigationMode");
        Shiboken::Conversions::registerConverterName(converter, "NavigationMode");
    }
    // End of 'NavigationMode' enum.

    // Initialization of enum 'CursorMoveStyle'.
    SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "CursorMoveStyle",
        "PySide.QtCore.Qt.CursorMoveStyle",
        "Qt::CursorMoveStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX],
        &Sbk_Qt_Type, "LogicalMoveStyle", (long) Qt::LogicalMoveStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX],
        &Sbk_Qt_Type, "VisualMoveStyle", (long) Qt::VisualMoveStyle))
        return ;
    // Register converter for enum 'Qt::CursorMoveStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX],
            Qt_CursorMoveStyle_CppToPython_Qt_CursorMoveStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_CursorMoveStyle_PythonToCpp_Qt_CursorMoveStyle,
            is_Qt_CursorMoveStyle_PythonToCpp_Qt_CursorMoveStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::CursorMoveStyle");
        Shiboken::Conversions::registerConverterName(converter, "CursorMoveStyle");
    }
    // End of 'CursorMoveStyle' enum.

    // Initialization of enum 'HitTestAccuracy'.
    SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "HitTestAccuracy",
        "PySide.QtCore.Qt.HitTestAccuracy",
        "Qt::HitTestAccuracy");
    if (!SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX],
        &Sbk_Qt_Type, "ExactHit", (long) Qt::ExactHit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX],
        &Sbk_Qt_Type, "FuzzyHit", (long) Qt::FuzzyHit))
        return ;
    // Register converter for enum 'Qt::HitTestAccuracy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX],
            Qt_HitTestAccuracy_CppToPython_Qt_HitTestAccuracy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_HitTestAccuracy_PythonToCpp_Qt_HitTestAccuracy,
            is_Qt_HitTestAccuracy_PythonToCpp_Qt_HitTestAccuracy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_HITTESTACCURACY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::HitTestAccuracy");
        Shiboken::Conversions::registerConverterName(converter, "HitTestAccuracy");
    }
    // End of 'HitTestAccuracy' enum.

    // Initialization of enum 'WhiteSpaceMode'.
    SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Qt_Type,
        "WhiteSpaceMode",
        "PySide.QtCore.Qt.WhiteSpaceMode",
        "Qt::WhiteSpaceMode");
    if (!SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX],
        &Sbk_Qt_Type, "WhiteSpaceNormal", (long) Qt::WhiteSpaceNormal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX],
        &Sbk_Qt_Type, "WhiteSpacePre", (long) Qt::WhiteSpacePre))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX],
        &Sbk_Qt_Type, "WhiteSpaceNoWrap", (long) Qt::WhiteSpaceNoWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX],
        &Sbk_Qt_Type, "WhiteSpaceModeUndefined", (long) Qt::WhiteSpaceModeUndefined))
        return ;
    // Register converter for enum 'Qt::WhiteSpaceMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX],
            Qt_WhiteSpaceMode_CppToPython_Qt_WhiteSpaceMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Qt_WhiteSpaceMode_PythonToCpp_Qt_WhiteSpaceMode,
            is_Qt_WhiteSpaceMode_PythonToCpp_Qt_WhiteSpaceMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QT_WHITESPACEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Qt::WhiteSpaceMode");
        Shiboken::Conversions::registerConverterName(converter, "WhiteSpaceMode");
    }
    // End of 'WhiteSpaceMode' enum.


    qRegisterMetaType< ::Qt::GlobalColor >("Qt::GlobalColor");
    qRegisterMetaType< ::Qt::KeyboardModifier >("Qt::KeyboardModifier");
    qRegisterMetaType< ::Qt::KeyboardModifiers >("Qt::KeyboardModifiers");
    qRegisterMetaType< ::Qt::Modifier >("Qt::Modifier");
    qRegisterMetaType< ::Qt::MouseButton >("Qt::MouseButton");
    qRegisterMetaType< ::Qt::MouseButtons >("Qt::MouseButtons");
    qRegisterMetaType< ::Qt::Orientation >("Qt::Orientation");
    qRegisterMetaType< ::Qt::Orientations >("Qt::Orientations");
    qRegisterMetaType< ::Qt::FocusPolicy >("Qt::FocusPolicy");
    qRegisterMetaType< ::Qt::SortOrder >("Qt::SortOrder");
    qRegisterMetaType< ::Qt::TileRule >("Qt::TileRule");
    qRegisterMetaType< ::Qt::AlignmentFlag >("Qt::AlignmentFlag");
    qRegisterMetaType< ::Qt::Alignment >("Qt::Alignment");
    qRegisterMetaType< ::Qt::TextFlag >("Qt::TextFlag");
    qRegisterMetaType< ::Qt::TextElideMode >("Qt::TextElideMode");
    qRegisterMetaType< ::Qt::WindowType >("Qt::WindowType");
    qRegisterMetaType< ::Qt::WindowFlags >("Qt::WindowFlags");
    qRegisterMetaType< ::Qt::WindowState >("Qt::WindowState");
    qRegisterMetaType< ::Qt::WindowStates >("Qt::WindowStates");
    qRegisterMetaType< ::Qt::WidgetAttribute >("Qt::WidgetAttribute");
    qRegisterMetaType< ::Qt::ApplicationAttribute >("Qt::ApplicationAttribute");
    qRegisterMetaType< ::Qt::ImageConversionFlag >("Qt::ImageConversionFlag");
    qRegisterMetaType< ::Qt::ImageConversionFlags >("Qt::ImageConversionFlags");
    qRegisterMetaType< ::Qt::BGMode >("Qt::BGMode");
    qRegisterMetaType< ::Qt::Key >("Qt::Key");
    qRegisterMetaType< ::Qt::ArrowType >("Qt::ArrowType");
    qRegisterMetaType< ::Qt::PenStyle >("Qt::PenStyle");
    qRegisterMetaType< ::Qt::PenCapStyle >("Qt::PenCapStyle");
    qRegisterMetaType< ::Qt::PenJoinStyle >("Qt::PenJoinStyle");
    qRegisterMetaType< ::Qt::BrushStyle >("Qt::BrushStyle");
    qRegisterMetaType< ::Qt::SizeMode >("Qt::SizeMode");
    qRegisterMetaType< ::Qt::UIEffect >("Qt::UIEffect");
    qRegisterMetaType< ::Qt::CursorShape >("Qt::CursorShape");
    qRegisterMetaType< ::Qt::TextFormat >("Qt::TextFormat");
    qRegisterMetaType< ::Qt::AspectRatioMode >("Qt::AspectRatioMode");
    qRegisterMetaType< ::Qt::AnchorAttribute >("Qt::AnchorAttribute");
    qRegisterMetaType< ::Qt::DockWidgetArea >("Qt::DockWidgetArea");
    qRegisterMetaType< ::Qt::DockWidgetAreas >("Qt::DockWidgetAreas");
    qRegisterMetaType< ::Qt::DockWidgetAreaSizes >("Qt::DockWidgetAreaSizes");
    qRegisterMetaType< ::Qt::ToolBarArea >("Qt::ToolBarArea");
    qRegisterMetaType< ::Qt::ToolBarAreas >("Qt::ToolBarAreas");
    qRegisterMetaType< ::Qt::ToolBarAreaSizes >("Qt::ToolBarAreaSizes");
    qRegisterMetaType< ::Qt::DateFormat >("Qt::DateFormat");
    qRegisterMetaType< ::Qt::TimeSpec >("Qt::TimeSpec");
    qRegisterMetaType< ::Qt::DayOfWeek >("Qt::DayOfWeek");
    qRegisterMetaType< ::Qt::ScrollBarPolicy >("Qt::ScrollBarPolicy");
    qRegisterMetaType< ::Qt::CaseSensitivity >("Qt::CaseSensitivity");
    qRegisterMetaType< ::Qt::Corner >("Qt::Corner");
    qRegisterMetaType< ::Qt::ConnectionType >("Qt::ConnectionType");
    qRegisterMetaType< ::Qt::ShortcutContext >("Qt::ShortcutContext");
    qRegisterMetaType< ::Qt::FillRule >("Qt::FillRule");
    qRegisterMetaType< ::Qt::MaskMode >("Qt::MaskMode");
    qRegisterMetaType< ::Qt::ClipOperation >("Qt::ClipOperation");
    qRegisterMetaType< ::Qt::ItemSelectionMode >("Qt::ItemSelectionMode");
    qRegisterMetaType< ::Qt::TransformationMode >("Qt::TransformationMode");
    qRegisterMetaType< ::Qt::Axis >("Qt::Axis");
    qRegisterMetaType< ::Qt::FocusReason >("Qt::FocusReason");
    qRegisterMetaType< ::Qt::ContextMenuPolicy >("Qt::ContextMenuPolicy");
    qRegisterMetaType< ::Qt::InputMethodQuery >("Qt::InputMethodQuery");
    qRegisterMetaType< ::Qt::InputMethodHint >("Qt::InputMethodHint");
    qRegisterMetaType< ::Qt::InputMethodHints >("Qt::InputMethodHints");
    qRegisterMetaType< ::Qt::ToolButtonStyle >("Qt::ToolButtonStyle");
    qRegisterMetaType< ::Qt::LayoutDirection >("Qt::LayoutDirection");
    qRegisterMetaType< ::Qt::AnchorPoint >("Qt::AnchorPoint");
    qRegisterMetaType< ::Qt::DropAction >("Qt::DropAction");
    qRegisterMetaType< ::Qt::DropActions >("Qt::DropActions");
    qRegisterMetaType< ::Qt::CheckState >("Qt::CheckState");
    qRegisterMetaType< ::Qt::ItemDataRole >("Qt::ItemDataRole");
    qRegisterMetaType< ::Qt::ItemFlag >("Qt::ItemFlag");
    qRegisterMetaType< ::Qt::ItemFlags >("Qt::ItemFlags");
    qRegisterMetaType< ::Qt::MatchFlag >("Qt::MatchFlag");
    qRegisterMetaType< ::Qt::MatchFlags >("Qt::MatchFlags");
    qRegisterMetaType< ::Qt::WindowModality >("Qt::WindowModality");
    qRegisterMetaType< ::Qt::TextInteractionFlag >("Qt::TextInteractionFlag");
    qRegisterMetaType< ::Qt::TextInteractionFlags >("Qt::TextInteractionFlags");
    qRegisterMetaType< ::Qt::EventPriority >("Qt::EventPriority");
    qRegisterMetaType< ::Qt::SizeHint >("Qt::SizeHint");
    qRegisterMetaType< ::Qt::WindowFrameSection >("Qt::WindowFrameSection");
    qRegisterMetaType< ::Qt::CoordinateSystem >("Qt::CoordinateSystem");
    qRegisterMetaType< ::Qt::TouchPointState >("Qt::TouchPointState");
    qRegisterMetaType< ::Qt::GestureState >("Qt::GestureState");
    qRegisterMetaType< ::Qt::GestureType >("Qt::GestureType");
    qRegisterMetaType< ::Qt::GestureFlag >("Qt::GestureFlag");
    qRegisterMetaType< ::Qt::GestureFlags >("Qt::GestureFlags");
    qRegisterMetaType< ::Qt::NavigationMode >("Qt::NavigationMode");
    qRegisterMetaType< ::Qt::CursorMoveStyle >("Qt::CursorMoveStyle");
    qRegisterMetaType< ::Qt::HitTestAccuracy >("Qt::HitTestAccuracy");
    qRegisterMetaType< ::Qt::WhiteSpaceMode >("Qt::WhiteSpaceMode");
}
