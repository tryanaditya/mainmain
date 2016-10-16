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

#include "qstyleoptiontab_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionTab_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionTab >()))
        return -1;

    ::QStyleOptionTab* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionTab", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionTab()
    // 1: QStyleOptionTab(QStyleOptionTab)
    // 2: QStyleOptionTab(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionTab()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionTab(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionTab(QStyleOptionTab)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionTab_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionTab()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionTab()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTab();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionTab(const QStyleOptionTab & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionTab* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTab(QStyleOptionTab)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTab(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionTab(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTab(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTab(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionTab >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionTab_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionTab_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionTab", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionTab", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionTab_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionTab_get_row(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->row;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_row(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'row' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'row', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->row;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->row = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTab_get_cornerWidgets(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), &cppSelf->cornerWidgets);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_cornerWidgets(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'cornerWidgets' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'cornerWidgets', 'CornerWidgets' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionTab::CornerWidget> cppOut_local = cppSelf->cornerWidgets;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->cornerWidgets = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTab_get_position(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    ::QStyleOptionTab::TabPosition cppOut_local = cppSelf->position;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_position(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'position' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'position', 'TabPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionTab::TabPosition cppOut_local = cppSelf->position;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->position = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTab_get_icon(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionTab_get_shape(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    ::QTabBar::Shape cppOut_local = cppSelf->shape;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABBAR_SHAPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_shape(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'shape' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABBAR_SHAPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'shape', 'Shape' or convertible type expected");
        return -1;
    }

    ::QTabBar::Shape cppOut_local = cppSelf->shape;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->shape = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionTab_get_text(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionTab_get_selectedPosition(PyObject* self, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    ::QStyleOptionTab::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTab_set_selectedPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'selectedPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'selectedPosition', 'SelectedPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionTab::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->selectedPosition = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionTab
static PyGetSetDef Sbk_QStyleOptionTab_getsetlist[] = {
    {const_cast<char*>("row"), Sbk_QStyleOptionTab_get_row, Sbk_QStyleOptionTab_set_row},
    {const_cast<char*>("cornerWidgets"), Sbk_QStyleOptionTab_get_cornerWidgets, Sbk_QStyleOptionTab_set_cornerWidgets},
    {const_cast<char*>("position"), Sbk_QStyleOptionTab_get_position, Sbk_QStyleOptionTab_set_position},
    {const_cast<char*>("icon"), Sbk_QStyleOptionTab_get_icon, Sbk_QStyleOptionTab_set_icon},
    {const_cast<char*>("shape"), Sbk_QStyleOptionTab_get_shape, Sbk_QStyleOptionTab_set_shape},
    {const_cast<char*>("text"), Sbk_QStyleOptionTab_get_text, Sbk_QStyleOptionTab_set_text},
    {const_cast<char*>("selectedPosition"), Sbk_QStyleOptionTab_get_selectedPosition, Sbk_QStyleOptionTab_set_selectedPosition},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionTab_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionTab_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionTab_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionTab",
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
    /*tp_traverse*/         Sbk_QStyleOptionTab_traverse,
    /*tp_clear*/            Sbk_QStyleOptionTab_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionTab_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionTab_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionTab_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionTab_CornerWidget___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionTab::CornerWidgets cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyLong_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyInt_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionTab_CornerWidget___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionTab::CornerWidgets cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyLong_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyInt_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionTab_CornerWidget___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionTab::CornerWidgets cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyLong_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionTab::CornerWidgets)PyInt_AsLong(self);
    cppArg = (QStyleOptionTab::CornerWidgets)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionTab_CornerWidget___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionTab::CornerWidgets cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), self, &cppSelf);
    ::QStyleOptionTab::CornerWidgets cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionTab_CornerWidget_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionTab_CornerWidget__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionTab_CornerWidget_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionTab_CornerWidget__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionTab_CornerWidget___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionTab_CornerWidget___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionTab_CornerWidget___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionTab_CornerWidget___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionTab_CornerWidget_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionTab_CornerWidget_long,
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
static void QStyleOptionTab_StyleOptionType_PythonToCpp_QStyleOptionTab_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTab::StyleOptionType*)cppOut) = (::QStyleOptionTab::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTab_StyleOptionType_PythonToCpp_QStyleOptionTab_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionTab_StyleOptionType_PythonToCpp_QStyleOptionTab_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionTab_StyleOptionType_CppToPython_QStyleOptionTab_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTab::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionTab_StyleOptionVersion_PythonToCpp_QStyleOptionTab_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTab::StyleOptionVersion*)cppOut) = (::QStyleOptionTab::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTab_StyleOptionVersion_PythonToCpp_QStyleOptionTab_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionTab_StyleOptionVersion_PythonToCpp_QStyleOptionTab_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionTab_StyleOptionVersion_CppToPython_QStyleOptionTab_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTab::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionTab_TabPosition_PythonToCpp_QStyleOptionTab_TabPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTab::TabPosition*)cppOut) = (::QStyleOptionTab::TabPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTab_TabPosition_PythonToCpp_QStyleOptionTab_TabPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX]))
        return QStyleOptionTab_TabPosition_PythonToCpp_QStyleOptionTab_TabPosition;
    return 0;
}
static PyObject* QStyleOptionTab_TabPosition_CppToPython_QStyleOptionTab_TabPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTab::TabPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX], castCppIn);

}

static void QStyleOptionTab_SelectedPosition_PythonToCpp_QStyleOptionTab_SelectedPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTab::SelectedPosition*)cppOut) = (::QStyleOptionTab::SelectedPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTab_SelectedPosition_PythonToCpp_QStyleOptionTab_SelectedPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX]))
        return QStyleOptionTab_SelectedPosition_PythonToCpp_QStyleOptionTab_SelectedPosition;
    return 0;
}
static PyObject* QStyleOptionTab_SelectedPosition_CppToPython_QStyleOptionTab_SelectedPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTab::SelectedPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX], castCppIn);

}

static void QStyleOptionTab_CornerWidget_PythonToCpp_QStyleOptionTab_CornerWidget(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTab::CornerWidget*)cppOut) = (::QStyleOptionTab::CornerWidget) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTab_CornerWidget_PythonToCpp_QStyleOptionTab_CornerWidget_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX]))
        return QStyleOptionTab_CornerWidget_PythonToCpp_QStyleOptionTab_CornerWidget;
    return 0;
}
static PyObject* QStyleOptionTab_CornerWidget_CppToPython_QStyleOptionTab_CornerWidget(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTab::CornerWidget*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX], castCppIn);

}

static void QFlags_QStyleOptionTab_CornerWidget__PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionTab::CornerWidget>*)cppOut) = ::QFlags<QStyleOptionTab::CornerWidget>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionTab_CornerWidget__PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]))
        return QFlags_QStyleOptionTab_CornerWidget__PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_;
    return 0;
}
static PyObject* QFlags_QStyleOptionTab_CornerWidget__CppToPython_QFlags_QStyleOptionTab_CornerWidget_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionTab::CornerWidget>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]));

}

static void QStyleOptionTab_CornerWidget_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionTab::CornerWidget>*)cppOut) = ::QFlags<QStyleOptionTab::CornerWidget>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionTab_CornerWidget_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX]))
        return QStyleOptionTab_CornerWidget_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionTab::CornerWidget>*)cppOut) = ::QFlags<QStyleOptionTab::CornerWidget>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionTab_PythonToCpp_QStyleOptionTab_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionTab_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionTab_PythonToCpp_QStyleOptionTab_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionTab_Type))
        return QStyleOptionTab_PythonToCpp_QStyleOptionTab_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionTab_PTR_CppToPython_QStyleOptionTab(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionTab*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionTab_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionTab(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionTab_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionTab", "QStyleOptionTab*",
        &Sbk_QStyleOptionTab_Type, &Shiboken::callCppDestructor< ::QStyleOptionTab >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionTab_Type,
        QStyleOptionTab_PythonToCpp_QStyleOptionTab_PTR,
        is_QStyleOptionTab_PythonToCpp_QStyleOptionTab_PTR_Convertible,
        QStyleOptionTab_PTR_CppToPython_QStyleOptionTab);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionTab).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTab_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionTab.StyleOptionType",
        "QStyleOptionTab::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionTab_Type, "Type", (long) QStyleOptionTab::Type))
        return ;
    // Register converter for enum 'QStyleOptionTab::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX],
            QStyleOptionTab_StyleOptionType_CppToPython_QStyleOptionTab_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_StyleOptionType_PythonToCpp_QStyleOptionTab_StyleOptionType,
            is_QStyleOptionTab_StyleOptionType_PythonToCpp_QStyleOptionTab_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTab_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionTab.StyleOptionVersion",
        "QStyleOptionTab::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionTab_Type, "Version", (long) QStyleOptionTab::Version))
        return ;
    // Register converter for enum 'QStyleOptionTab::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX],
            QStyleOptionTab_StyleOptionVersion_CppToPython_QStyleOptionTab_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_StyleOptionVersion_PythonToCpp_QStyleOptionTab_StyleOptionVersion,
            is_QStyleOptionTab_StyleOptionVersion_PythonToCpp_QStyleOptionTab_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'TabPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTab_Type,
        "TabPosition",
        "PySide.QtGui.QStyleOptionTab.TabPosition",
        "QStyleOptionTab::TabPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "Beginning", (long) QStyleOptionTab::Beginning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "Middle", (long) QStyleOptionTab::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "End", (long) QStyleOptionTab::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "OnlyOneTab", (long) QStyleOptionTab::OnlyOneTab))
        return ;
    // Register converter for enum 'QStyleOptionTab::TabPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX],
            QStyleOptionTab_TabPosition_CppToPython_QStyleOptionTab_TabPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_TabPosition_PythonToCpp_QStyleOptionTab_TabPosition,
            is_QStyleOptionTab_TabPosition_PythonToCpp_QStyleOptionTab_TabPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_TABPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab::TabPosition");
        Shiboken::Conversions::registerConverterName(converter, "TabPosition");
    }
    // End of 'TabPosition' enum.

    // Initialization of enum 'SelectedPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTab_Type,
        "SelectedPosition",
        "PySide.QtGui.QStyleOptionTab.SelectedPosition",
        "QStyleOptionTab::SelectedPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "NotAdjacent", (long) QStyleOptionTab::NotAdjacent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "NextIsSelected", (long) QStyleOptionTab::NextIsSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionTab_Type, "PreviousIsSelected", (long) QStyleOptionTab::PreviousIsSelected))
        return ;
    // Register converter for enum 'QStyleOptionTab::SelectedPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX],
            QStyleOptionTab_SelectedPosition_CppToPython_QStyleOptionTab_SelectedPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_SelectedPosition_PythonToCpp_QStyleOptionTab_SelectedPosition,
            is_QStyleOptionTab_SelectedPosition_PythonToCpp_QStyleOptionTab_SelectedPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_SELECTEDPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab::SelectedPosition");
        Shiboken::Conversions::registerConverterName(converter, "SelectedPosition");
    }
    // End of 'SelectedPosition' enum.

    // Initialization of enum 'CornerWidget'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX] = PySide::QFlags::create("CornerWidgets", &SbkPySide_QtGui_QStyleOptionTab_CornerWidget_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTab_Type,
        "CornerWidget",
        "PySide.QtGui.QStyleOptionTab.CornerWidget",
        "QStyleOptionTab::CornerWidget",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX],
        &Sbk_QStyleOptionTab_Type, "NoCornerWidgets", (long) QStyleOptionTab::NoCornerWidgets))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX],
        &Sbk_QStyleOptionTab_Type, "LeftCornerWidget", (long) QStyleOptionTab::LeftCornerWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX],
        &Sbk_QStyleOptionTab_Type, "RightCornerWidget", (long) QStyleOptionTab::RightCornerWidget))
        return ;
    // Register converter for enum 'QStyleOptionTab::CornerWidget'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX],
            QStyleOptionTab_CornerWidget_CppToPython_QStyleOptionTab_CornerWidget);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_CornerWidget_PythonToCpp_QStyleOptionTab_CornerWidget,
            is_QStyleOptionTab_CornerWidget_PythonToCpp_QStyleOptionTab_CornerWidget_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTAB_CORNERWIDGET_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTab::CornerWidget");
        Shiboken::Conversions::registerConverterName(converter, "CornerWidget");
    }
    // Register converter for flag 'QFlags<QStyleOptionTab::CornerWidget>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX],
            QFlags_QStyleOptionTab_CornerWidget__CppToPython_QFlags_QStyleOptionTab_CornerWidget_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTab_CornerWidget_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_,
            is_QStyleOptionTab_CornerWidget_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionTab_CornerWidget__PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_,
            is_QFlags_QStyleOptionTab_CornerWidget__PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget_,
            is_number_PythonToCpp_QFlags_QStyleOptionTab_CornerWidget__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTAB_CORNERWIDGET__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionTab::CornerWidget>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<CornerWidget>");
    }
    // End of 'CornerWidget' enum/flags.


    qRegisterMetaType< ::QStyleOptionTab::StyleOptionType >("QStyleOptionTab::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionTab::StyleOptionVersion >("QStyleOptionTab::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionTab::TabPosition >("QStyleOptionTab::TabPosition");
    qRegisterMetaType< ::QStyleOptionTab::SelectedPosition >("QStyleOptionTab::SelectedPosition");
    qRegisterMetaType< ::QStyleOptionTab::CornerWidget >("QStyleOptionTab::CornerWidget");
    qRegisterMetaType< ::QStyleOptionTab::CornerWidgets >("QStyleOptionTab::CornerWidgets");
}
