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

#include "qstyleoptionviewitem_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionViewItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionViewItem >()))
        return -1;

    ::QStyleOptionViewItem* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionViewItem", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionViewItem()
    // 1: QStyleOptionViewItem(QStyleOptionViewItem)
    // 2: QStyleOptionViewItem(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionViewItem()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionViewItem(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionViewItem(QStyleOptionViewItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionViewItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionViewItem()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItem()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItem();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionViewItem(const QStyleOptionViewItem & other)
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
                // QStyleOptionViewItem(QStyleOptionViewItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItem(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionViewItem(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItem(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItem(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionViewItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionViewItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionViewItem_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionViewItem", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionViewItem", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionViewItem___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStyleOptionViewItem& cppSelf = *(((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStyleOptionViewItem_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QStyleOptionViewItem___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionViewItem_get_showDecorationSelected(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->showDecorationSelected;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_showDecorationSelected(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'showDecorationSelected' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'showDecorationSelected', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->showDecorationSelected;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->showDecorationSelected = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_decorationPosition(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    ::QStyleOptionViewItem::Position cppOut_local = cppSelf->decorationPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_decorationPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'decorationPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'decorationPosition', 'Position' or convertible type expected");
        return -1;
    }

    ::QStyleOptionViewItem::Position cppOut_local = cppSelf->decorationPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->decorationPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_decorationAlignment(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->decorationAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_decorationAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'decorationAlignment' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'decorationAlignment', 'Alignment' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::AlignmentFlag> cppOut_local = cppSelf->decorationAlignment;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->decorationAlignment = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_displayAlignment(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->displayAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_displayAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'displayAlignment' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'displayAlignment', 'Alignment' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::AlignmentFlag> cppOut_local = cppSelf->displayAlignment;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->displayAlignment = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_textElideMode(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    ::Qt::TextElideMode cppOut_local = cppSelf->textElideMode;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_textElideMode(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'textElideMode' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'textElideMode', 'TextElideMode' or convertible type expected");
        return -1;
    }

    ::Qt::TextElideMode cppOut_local = cppSelf->textElideMode;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->textElideMode = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_decorationSize(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->decorationSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_decorationSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'decorationSize' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'decorationSize', 'QSize' or convertible type expected");
        return -1;
    }

    ::QSize& cppOut_ptr = cppSelf->decorationSize;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItem_get_font(PyObject* self, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &(cppSelf->font), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItem_set_font(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'font' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'font', 'QFont' or convertible type expected");
        return -1;
    }

    ::QFont& cppOut_ptr = cppSelf->font;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionViewItem
static PyGetSetDef Sbk_QStyleOptionViewItem_getsetlist[] = {
    {const_cast<char*>("showDecorationSelected"), Sbk_QStyleOptionViewItem_get_showDecorationSelected, Sbk_QStyleOptionViewItem_set_showDecorationSelected},
    {const_cast<char*>("decorationPosition"), Sbk_QStyleOptionViewItem_get_decorationPosition, Sbk_QStyleOptionViewItem_set_decorationPosition},
    {const_cast<char*>("decorationAlignment"), Sbk_QStyleOptionViewItem_get_decorationAlignment, Sbk_QStyleOptionViewItem_set_decorationAlignment},
    {const_cast<char*>("displayAlignment"), Sbk_QStyleOptionViewItem_get_displayAlignment, Sbk_QStyleOptionViewItem_set_displayAlignment},
    {const_cast<char*>("textElideMode"), Sbk_QStyleOptionViewItem_get_textElideMode, Sbk_QStyleOptionViewItem_set_textElideMode},
    {const_cast<char*>("decorationSize"), Sbk_QStyleOptionViewItem_get_decorationSize, Sbk_QStyleOptionViewItem_set_decorationSize},
    {const_cast<char*>("font"), Sbk_QStyleOptionViewItem_get_font, Sbk_QStyleOptionViewItem_set_font},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionViewItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionViewItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionViewItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionViewItem",
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
    /*tp_traverse*/         Sbk_QStyleOptionViewItem_traverse,
    /*tp_clear*/            Sbk_QStyleOptionViewItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionViewItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionViewItem_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionViewItem_Init,
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
static void QStyleOptionViewItem_StyleOptionType_PythonToCpp_QStyleOptionViewItem_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItem::StyleOptionType*)cppOut) = (::QStyleOptionViewItem::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItem_StyleOptionType_PythonToCpp_QStyleOptionViewItem_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionViewItem_StyleOptionType_PythonToCpp_QStyleOptionViewItem_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionViewItem_StyleOptionType_CppToPython_QStyleOptionViewItem_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItem::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionViewItem_StyleOptionVersion_PythonToCpp_QStyleOptionViewItem_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItem::StyleOptionVersion*)cppOut) = (::QStyleOptionViewItem::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItem_StyleOptionVersion_PythonToCpp_QStyleOptionViewItem_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionViewItem_StyleOptionVersion_PythonToCpp_QStyleOptionViewItem_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionViewItem_StyleOptionVersion_CppToPython_QStyleOptionViewItem_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItem::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionViewItem_Position_PythonToCpp_QStyleOptionViewItem_Position(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItem::Position*)cppOut) = (::QStyleOptionViewItem::Position) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItem_Position_PythonToCpp_QStyleOptionViewItem_Position_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX]))
        return QStyleOptionViewItem_Position_PythonToCpp_QStyleOptionViewItem_Position;
    return 0;
}
static PyObject* QStyleOptionViewItem_Position_CppToPython_QStyleOptionViewItem_Position(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItem::Position*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionViewItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItem_Type))
        return QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionViewItem_PTR_CppToPython_QStyleOptionViewItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionViewItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QStyleOptionViewItem_COPY_CppToPython_QStyleOptionViewItem(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItem_Type, new ::QStyleOptionViewItem(*((::QStyleOptionViewItem*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItem*)cppOut) = *((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItem_Type))
        return QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_COPY;
    return 0;
}

void init_QStyleOptionViewItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionViewItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionViewItem", "QStyleOptionViewItem",
        &Sbk_QStyleOptionViewItem_Type, &Shiboken::callCppDestructor< ::QStyleOptionViewItem >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionViewItem_Type,
        QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_PTR,
        is_QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_PTR_Convertible,
        QStyleOptionViewItem_PTR_CppToPython_QStyleOptionViewItem,
        QStyleOptionViewItem_COPY_CppToPython_QStyleOptionViewItem);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionViewItem).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_COPY,
        is_QStyleOptionViewItem_PythonToCpp_QStyleOptionViewItem_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItem_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionViewItem.StyleOptionType",
        "QStyleOptionViewItem::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Type", (long) QStyleOptionViewItem::Type))
        return ;
    // Register converter for enum 'QStyleOptionViewItem::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX],
            QStyleOptionViewItem_StyleOptionType_CppToPython_QStyleOptionViewItem_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItem_StyleOptionType_PythonToCpp_QStyleOptionViewItem_StyleOptionType,
            is_QStyleOptionViewItem_StyleOptionType_PythonToCpp_QStyleOptionViewItem_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItem_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionViewItem.StyleOptionVersion",
        "QStyleOptionViewItem::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Version", (long) QStyleOptionViewItem::Version))
        return ;
    // Register converter for enum 'QStyleOptionViewItem::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX],
            QStyleOptionViewItem_StyleOptionVersion_CppToPython_QStyleOptionViewItem_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItem_StyleOptionVersion_PythonToCpp_QStyleOptionViewItem_StyleOptionVersion,
            is_QStyleOptionViewItem_StyleOptionVersion_PythonToCpp_QStyleOptionViewItem_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'Position'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItem_Type,
        "Position",
        "PySide.QtGui.QStyleOptionViewItem.Position",
        "QStyleOptionViewItem::Position");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Left", (long) QStyleOptionViewItem::Left))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Right", (long) QStyleOptionViewItem::Right))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Top", (long) QStyleOptionViewItem::Top))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX],
        &Sbk_QStyleOptionViewItem_Type, "Bottom", (long) QStyleOptionViewItem::Bottom))
        return ;
    // Register converter for enum 'QStyleOptionViewItem::Position'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX],
            QStyleOptionViewItem_Position_CppToPython_QStyleOptionViewItem_Position);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItem_Position_PythonToCpp_QStyleOptionViewItem_Position,
            is_QStyleOptionViewItem_Position_PythonToCpp_QStyleOptionViewItem_Position_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_POSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItem::Position");
        Shiboken::Conversions::registerConverterName(converter, "Position");
    }
    // End of 'Position' enum.


    qRegisterMetaType< ::QStyleOptionViewItem >("QStyleOptionViewItem");
    qRegisterMetaType< ::QStyleOptionViewItem::StyleOptionType >("QStyleOptionViewItem::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionViewItem::StyleOptionVersion >("QStyleOptionViewItem::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionViewItem::Position >("QStyleOptionViewItem::Position");
}
