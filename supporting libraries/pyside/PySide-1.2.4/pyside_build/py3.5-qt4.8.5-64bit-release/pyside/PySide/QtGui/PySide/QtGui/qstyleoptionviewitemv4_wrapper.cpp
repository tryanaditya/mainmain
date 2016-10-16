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

#include "qstyleoptionviewitemv4_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionViewItemV4_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionViewItemV4 >()))
        return -1;

    ::QStyleOptionViewItemV4* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionViewItemV4", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionViewItemV4()
    // 1: QStyleOptionViewItemV4(QStyleOptionViewItem)
    // 2: QStyleOptionViewItemV4(QStyleOptionViewItemV4)
    // 3: QStyleOptionViewItemV4(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionViewItemV4()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionViewItemV4(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionViewItemV4(QStyleOptionViewItemV4)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionViewItemV4(QStyleOptionViewItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionViewItemV4_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionViewItemV4()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV4()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV4();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionViewItemV4(const QStyleOptionViewItem & other)
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
                // QStyleOptionViewItemV4(QStyleOptionViewItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV4(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionViewItemV4(const QStyleOptionViewItemV4 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionViewItemV4 cppArg0_local = ::QStyleOptionViewItemV4();
            ::QStyleOptionViewItemV4* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV4(QStyleOptionViewItemV4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV4(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionViewItemV4(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV4(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV4(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionViewItemV4 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionViewItemV4_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionViewItemV4_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionViewItem", "PySide.QtGui.QStyleOptionViewItemV4", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionViewItemV4", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionViewItemV4___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStyleOptionViewItemV4& cppSelf = *(((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStyleOptionViewItemV4_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QStyleOptionViewItemV4___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionViewItemV4_get_checkState(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    ::Qt::CheckState cppOut_local = cppSelf->checkState;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_checkState(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'checkState' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'checkState', 'CheckState' or convertible type expected");
        return -1;
    }

    ::Qt::CheckState cppOut_local = cppSelf->checkState;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->checkState = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItemV4_get_viewItemPosition(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    ::QStyleOptionViewItemV4::ViewItemPosition cppOut_local = cppSelf->viewItemPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_viewItemPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'viewItemPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'viewItemPosition', 'ViewItemPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionViewItemV4::ViewItemPosition cppOut_local = cppSelf->viewItemPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->viewItemPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItemV4_get_icon(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionViewItemV4_get_backgroundBrush(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &(cppSelf->backgroundBrush), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_backgroundBrush(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'backgroundBrush' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'backgroundBrush', 'QBrush' or convertible type expected");
        return -1;
    }

    ::QBrush& cppOut_ptr = cppSelf->backgroundBrush;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItemV4_get_index(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &(cppSelf->index), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_index(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'index' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'index', 'QModelIndex' or convertible type expected");
        return -1;
    }

    ::QModelIndex& cppOut_ptr = cppSelf->index;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionViewItemV4_get_text(PyObject* self, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV4_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)self));
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

// Getters and Setters for QStyleOptionViewItemV4
static PyGetSetDef Sbk_QStyleOptionViewItemV4_getsetlist[] = {
    {const_cast<char*>("checkState"), Sbk_QStyleOptionViewItemV4_get_checkState, Sbk_QStyleOptionViewItemV4_set_checkState},
    {const_cast<char*>("viewItemPosition"), Sbk_QStyleOptionViewItemV4_get_viewItemPosition, Sbk_QStyleOptionViewItemV4_set_viewItemPosition},
    {const_cast<char*>("icon"), Sbk_QStyleOptionViewItemV4_get_icon, Sbk_QStyleOptionViewItemV4_set_icon},
    {const_cast<char*>("backgroundBrush"), Sbk_QStyleOptionViewItemV4_get_backgroundBrush, Sbk_QStyleOptionViewItemV4_set_backgroundBrush},
    {const_cast<char*>("index"), Sbk_QStyleOptionViewItemV4_get_index, Sbk_QStyleOptionViewItemV4_set_index},
    {const_cast<char*>("text"), Sbk_QStyleOptionViewItemV4_get_text, Sbk_QStyleOptionViewItemV4_set_text},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionViewItemV4_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionViewItemV4_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionViewItemV4_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionViewItemV4",
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
    /*tp_traverse*/         Sbk_QStyleOptionViewItemV4_traverse,
    /*tp_clear*/            Sbk_QStyleOptionViewItemV4_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionViewItemV4_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionViewItemV4_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionViewItemV4_Init,
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
static void QStyleOptionViewItemV4_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV4_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV4::StyleOptionVersion*)cppOut) = (::QStyleOptionViewItemV4::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItemV4_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV4_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionViewItemV4_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV4_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionViewItemV4_StyleOptionVersion_CppToPython_QStyleOptionViewItemV4_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItemV4::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionViewItemV4_ViewItemPosition_PythonToCpp_QStyleOptionViewItemV4_ViewItemPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV4::ViewItemPosition*)cppOut) = (::QStyleOptionViewItemV4::ViewItemPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItemV4_ViewItemPosition_PythonToCpp_QStyleOptionViewItemV4_ViewItemPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX]))
        return QStyleOptionViewItemV4_ViewItemPosition_PythonToCpp_QStyleOptionViewItemV4_ViewItemPosition;
    return 0;
}
static PyObject* QStyleOptionViewItemV4_ViewItemPosition_CppToPython_QStyleOptionViewItemV4_ViewItemPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItemV4::ViewItemPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionViewItemV4_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV4_Type))
        return QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionViewItemV4_PTR_CppToPython_QStyleOptionViewItemV4(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionViewItemV4*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV4_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QStyleOptionViewItemV4_COPY_CppToPython_QStyleOptionViewItemV4(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV4_Type, new ::QStyleOptionViewItemV4(*((::QStyleOptionViewItemV4*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV4*)cppOut) = *((::QStyleOptionViewItemV4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV4_Type))
        return QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_COPY;
    return 0;
}

// Implicit conversions.
static void constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV4(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV4*)cppOut) = ::QStyleOptionViewItemV4(*((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV4_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pyIn))
        return constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV4;
    return 0;
}

void init_QStyleOptionViewItemV4(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionViewItemV4_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionViewItemV4", "QStyleOptionViewItemV4",
        &Sbk_QStyleOptionViewItemV4_Type, &Shiboken::callCppDestructor< ::QStyleOptionViewItemV4 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionViewItemV4_Type,
        QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_PTR,
        is_QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_PTR_Convertible,
        QStyleOptionViewItemV4_PTR_CppToPython_QStyleOptionViewItemV4,
        QStyleOptionViewItemV4_COPY_CppToPython_QStyleOptionViewItemV4);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV4");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV4*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV4&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionViewItemV4).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_COPY,
        is_QStyleOptionViewItemV4_PythonToCpp_QStyleOptionViewItemV4_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV4,
        is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV4_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItemV4_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionViewItemV4.StyleOptionVersion",
        "QStyleOptionViewItemV4::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "Version", (long) QStyleOptionViewItemV4::Version))
        return ;
    // Register converter for enum 'QStyleOptionViewItemV4::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX],
            QStyleOptionViewItemV4_StyleOptionVersion_CppToPython_QStyleOptionViewItemV4_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV4_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV4_StyleOptionVersion,
            is_QStyleOptionViewItemV4_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV4_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV4::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'ViewItemPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItemV4_Type,
        "ViewItemPosition",
        "PySide.QtGui.QStyleOptionViewItemV4.ViewItemPosition",
        "QStyleOptionViewItemV4::ViewItemPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "Invalid", (long) QStyleOptionViewItemV4::Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "Beginning", (long) QStyleOptionViewItemV4::Beginning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "Middle", (long) QStyleOptionViewItemV4::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "End", (long) QStyleOptionViewItemV4::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
        &Sbk_QStyleOptionViewItemV4_Type, "OnlyOne", (long) QStyleOptionViewItemV4::OnlyOne))
        return ;
    // Register converter for enum 'QStyleOptionViewItemV4::ViewItemPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX],
            QStyleOptionViewItemV4_ViewItemPosition_CppToPython_QStyleOptionViewItemV4_ViewItemPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV4_ViewItemPosition_PythonToCpp_QStyleOptionViewItemV4_ViewItemPosition,
            is_QStyleOptionViewItemV4_ViewItemPosition_PythonToCpp_QStyleOptionViewItemV4_ViewItemPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV4_VIEWITEMPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV4::ViewItemPosition");
        Shiboken::Conversions::registerConverterName(converter, "ViewItemPosition");
    }
    // End of 'ViewItemPosition' enum.


    qRegisterMetaType< ::QStyleOptionViewItemV4 >("QStyleOptionViewItemV4");
    qRegisterMetaType< ::QStyleOptionViewItemV4::StyleOptionVersion >("QStyleOptionViewItemV4::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionViewItemV4::ViewItemPosition >("QStyleOptionViewItemV4::ViewItemPosition");
}
