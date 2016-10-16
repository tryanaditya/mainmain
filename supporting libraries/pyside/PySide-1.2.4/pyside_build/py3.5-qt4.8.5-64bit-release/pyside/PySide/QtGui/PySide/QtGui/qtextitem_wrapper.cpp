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

#include "qtextitem_wrapper.h"

// Extra includes
#include <qfont.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextItem >()))
        return -1;

    ::QTextItem* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QTextItem()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QTextItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QTextItemFunc_ascent(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ascent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextItem*>(cppSelf)->ascent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextItemFunc_descent(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // descent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextItem*>(cppSelf)->descent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextItemFunc_font(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QTextItem*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextItemFunc_renderFlags(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // renderFlags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextItem::RenderFlag> cppResult = const_cast<const ::QTextItem*>(cppSelf)->renderFlags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextItemFunc_text(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextItem*>(cppSelf)->text();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextItemFunc_width(PyObject* self)
{
    ::QTextItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextItem*>(cppSelf)->width();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextItem_methods[] = {
    {"ascent", (PyCFunction)Sbk_QTextItemFunc_ascent, METH_NOARGS},
    {"descent", (PyCFunction)Sbk_QTextItemFunc_descent, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QTextItemFunc_font, METH_NOARGS},
    {"renderFlags", (PyCFunction)Sbk_QTextItemFunc_renderFlags, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QTextItemFunc_text, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QTextItemFunc_width, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextItem",
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
    /*tp_traverse*/         Sbk_QTextItem_traverse,
    /*tp_clear*/            Sbk_QTextItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextItem_Init,
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

PyObject* SbkPySide_QtGui_QTextItem_RenderFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextItem::RenderFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextItem::RenderFlags)PyLong_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextItem::RenderFlags)PyInt_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextItem_RenderFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextItem::RenderFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextItem::RenderFlags)PyLong_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextItem::RenderFlags)PyInt_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextItem_RenderFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextItem::RenderFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextItem::RenderFlags)PyLong_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextItem::RenderFlags)PyInt_AsLong(self);
    cppArg = (QTextItem::RenderFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextItem_RenderFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextItem::RenderFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), self, &cppSelf);
    ::QTextItem::RenderFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QTextItem_RenderFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QTextItem_RenderFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QTextItem_RenderFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QTextItem_RenderFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QTextItem_RenderFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QTextItem_RenderFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QTextItem_RenderFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QTextItem_RenderFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QTextItem_RenderFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QTextItem_RenderFlag_long,
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
static void QTextItem_RenderFlag_PythonToCpp_QTextItem_RenderFlag(PyObject* pyIn, void* cppOut) {
    *((::QTextItem::RenderFlag*)cppOut) = (::QTextItem::RenderFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextItem_RenderFlag_PythonToCpp_QTextItem_RenderFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX]))
        return QTextItem_RenderFlag_PythonToCpp_QTextItem_RenderFlag;
    return 0;
}
static PyObject* QTextItem_RenderFlag_CppToPython_QTextItem_RenderFlag(const void* cppIn) {
    int castCppIn = *((::QTextItem::RenderFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX], castCppIn);

}

static void QFlags_QTextItem_RenderFlag__PythonToCpp_QFlags_QTextItem_RenderFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextItem::RenderFlag>*)cppOut) = ::QFlags<QTextItem::RenderFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextItem_RenderFlag__PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]))
        return QFlags_QTextItem_RenderFlag__PythonToCpp_QFlags_QTextItem_RenderFlag_;
    return 0;
}
static PyObject* QFlags_QTextItem_RenderFlag__CppToPython_QFlags_QTextItem_RenderFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextItem::RenderFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]));

}

static void QTextItem_RenderFlag_PythonToCpp_QFlags_QTextItem_RenderFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextItem::RenderFlag>*)cppOut) = ::QFlags<QTextItem::RenderFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextItem_RenderFlag_PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX]))
        return QTextItem_RenderFlag_PythonToCpp_QFlags_QTextItem_RenderFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextItem_RenderFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextItem::RenderFlag>*)cppOut) = ::QFlags<QTextItem::RenderFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextItem_RenderFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextItem_PythonToCpp_QTextItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextItem_PythonToCpp_QTextItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextItem_Type))
        return QTextItem_PythonToCpp_QTextItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextItem_PTR_CppToPython_QTextItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextItem", "QTextItem*",
        &Sbk_QTextItem_Type, &Shiboken::callCppDestructor< ::QTextItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextItem_Type,
        QTextItem_PythonToCpp_QTextItem_PTR,
        is_QTextItem_PythonToCpp_QTextItem_PTR_Convertible,
        QTextItem_PTR_CppToPython_QTextItem);

    Shiboken::Conversions::registerConverterName(converter, "QTextItem");
    Shiboken::Conversions::registerConverterName(converter, "QTextItem*");
    Shiboken::Conversions::registerConverterName(converter, "QTextItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextItem).name());


    // Initialization of enums.

    // Initialization of enum 'RenderFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX] = PySide::QFlags::create("RenderFlags", &SbkPySide_QtGui_QTextItem_RenderFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextItem_Type,
        "RenderFlag",
        "PySide.QtGui.QTextItem.RenderFlag",
        "QTextItem::RenderFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
        &Sbk_QTextItem_Type, "RightToLeft", (long) QTextItem::RightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
        &Sbk_QTextItem_Type, "Overline", (long) QTextItem::Overline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
        &Sbk_QTextItem_Type, "Underline", (long) QTextItem::Underline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
        &Sbk_QTextItem_Type, "StrikeOut", (long) QTextItem::StrikeOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
        &Sbk_QTextItem_Type, "Dummy", (long) QTextItem::Dummy))
        return ;
    // Register converter for enum 'QTextItem::RenderFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX],
            QTextItem_RenderFlag_CppToPython_QTextItem_RenderFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextItem_RenderFlag_PythonToCpp_QTextItem_RenderFlag,
            is_QTextItem_RenderFlag_PythonToCpp_QTextItem_RenderFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextItem::RenderFlag");
        Shiboken::Conversions::registerConverterName(converter, "RenderFlag");
    }
    // Register converter for flag 'QFlags<QTextItem::RenderFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX],
            QFlags_QTextItem_RenderFlag__CppToPython_QFlags_QTextItem_RenderFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextItem_RenderFlag_PythonToCpp_QFlags_QTextItem_RenderFlag_,
            is_QTextItem_RenderFlag_PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextItem_RenderFlag__PythonToCpp_QFlags_QTextItem_RenderFlag_,
            is_QFlags_QTextItem_RenderFlag__PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextItem_RenderFlag_,
            is_number_PythonToCpp_QFlags_QTextItem_RenderFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextItem::RenderFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<RenderFlag>");
    }
    // End of 'RenderFlag' enum/flags.


    qRegisterMetaType< ::QTextItem::RenderFlag >("QTextItem::RenderFlag");
    qRegisterMetaType< ::QTextItem::RenderFlags >("QTextItem::RenderFlags");
}
