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

#include "qstyleoptiontoolbutton_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionToolButton_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionToolButton >()))
        return -1;

    ::QStyleOptionToolButton* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionToolButton", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionToolButton()
    // 1: QStyleOptionToolButton(QStyleOptionToolButton)
    // 2: QStyleOptionToolButton(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionToolButton()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionToolButton(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionToolButton(QStyleOptionToolButton)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionToolButton_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionToolButton()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionToolButton()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolButton();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionToolButton(const QStyleOptionToolButton & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionToolButton* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolButton(QStyleOptionToolButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolButton(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionToolButton(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolButton(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionToolButton >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionToolButton_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionToolButton_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionToolButton", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionToolButton", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionToolButton_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionToolButton_get_iconSize(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->iconSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_iconSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionToolButton_get_toolButtonStyle(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    ::Qt::ToolButtonStyle cppOut_local = cppSelf->toolButtonStyle;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_toolButtonStyle(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'toolButtonStyle' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'toolButtonStyle', 'ToolButtonStyle' or convertible type expected");
        return -1;
    }

    ::Qt::ToolButtonStyle cppOut_local = cppSelf->toolButtonStyle;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->toolButtonStyle = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolButton_get_features(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'features' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'features', 'ToolButtonFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionToolButton::ToolButtonFeature> cppOut_local = cppSelf->features;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->features = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolButton_get_arrowType(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    ::Qt::ArrowType cppOut_local = cppSelf->arrowType;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_arrowType(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'arrowType' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ARROWTYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'arrowType', 'ArrowType' or convertible type expected");
        return -1;
    }

    ::Qt::ArrowType cppOut_local = cppSelf->arrowType;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->arrowType = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolButton_get_icon(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionToolButton_get_pos(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &(cppSelf->pos), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_pos(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'pos' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'pos', 'QPoint' or convertible type expected");
        return -1;
    }

    ::QPoint& cppOut_ptr = cppSelf->pos;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionToolButton_get_text(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionToolButton_get_font(PyObject* self, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &(cppSelf->font), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionToolButton_set_font(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolButton* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolButton*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX], (SbkObject*)self));
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

// Getters and Setters for QStyleOptionToolButton
static PyGetSetDef Sbk_QStyleOptionToolButton_getsetlist[] = {
    {const_cast<char*>("iconSize"), Sbk_QStyleOptionToolButton_get_iconSize, Sbk_QStyleOptionToolButton_set_iconSize},
    {const_cast<char*>("toolButtonStyle"), Sbk_QStyleOptionToolButton_get_toolButtonStyle, Sbk_QStyleOptionToolButton_set_toolButtonStyle},
    {const_cast<char*>("features"), Sbk_QStyleOptionToolButton_get_features, Sbk_QStyleOptionToolButton_set_features},
    {const_cast<char*>("arrowType"), Sbk_QStyleOptionToolButton_get_arrowType, Sbk_QStyleOptionToolButton_set_arrowType},
    {const_cast<char*>("icon"), Sbk_QStyleOptionToolButton_get_icon, Sbk_QStyleOptionToolButton_set_icon},
    {const_cast<char*>("pos"), Sbk_QStyleOptionToolButton_get_pos, Sbk_QStyleOptionToolButton_set_pos},
    {const_cast<char*>("text"), Sbk_QStyleOptionToolButton_get_text, Sbk_QStyleOptionToolButton_set_text},
    {const_cast<char*>("font"), Sbk_QStyleOptionToolButton_get_font, Sbk_QStyleOptionToolButton_set_font},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionToolButton_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionToolButton_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionToolButton_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionToolButton",
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
    /*tp_traverse*/         Sbk_QStyleOptionToolButton_traverse,
    /*tp_clear*/            Sbk_QStyleOptionToolButton_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionToolButton_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionToolButton_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionToolButton_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolButton::ToolButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolButton::ToolButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolButton::ToolButtonFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolButton::ToolButtonFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolButton::ToolButtonFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), self, &cppSelf);
    ::QStyleOptionToolButton::ToolButtonFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature_long,
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
static void QStyleOptionToolButton_StyleOptionType_PythonToCpp_QStyleOptionToolButton_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolButton::StyleOptionType*)cppOut) = (::QStyleOptionToolButton::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolButton_StyleOptionType_PythonToCpp_QStyleOptionToolButton_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionToolButton_StyleOptionType_PythonToCpp_QStyleOptionToolButton_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionToolButton_StyleOptionType_CppToPython_QStyleOptionToolButton_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolButton::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionToolButton_StyleOptionVersion_PythonToCpp_QStyleOptionToolButton_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolButton::StyleOptionVersion*)cppOut) = (::QStyleOptionToolButton::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolButton_StyleOptionVersion_PythonToCpp_QStyleOptionToolButton_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionToolButton_StyleOptionVersion_PythonToCpp_QStyleOptionToolButton_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionToolButton_StyleOptionVersion_CppToPython_QStyleOptionToolButton_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolButton::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QStyleOptionToolButton_ToolButtonFeature(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolButton::ToolButtonFeature*)cppOut) = (::QStyleOptionToolButton::ToolButtonFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QStyleOptionToolButton_ToolButtonFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX]))
        return QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QStyleOptionToolButton_ToolButtonFeature;
    return 0;
}
static PyObject* QStyleOptionToolButton_ToolButtonFeature_CppToPython_QStyleOptionToolButton_ToolButtonFeature(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolButton::ToolButtonFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX], castCppIn);

}

static void QFlags_QStyleOptionToolButton_ToolButtonFeature__PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionToolButton::ToolButtonFeature>*)cppOut) = ::QFlags<QStyleOptionToolButton::ToolButtonFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionToolButton_ToolButtonFeature__PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]))
        return QFlags_QStyleOptionToolButton_ToolButtonFeature__PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_;
    return 0;
}
static PyObject* QFlags_QStyleOptionToolButton_ToolButtonFeature__CppToPython_QFlags_QStyleOptionToolButton_ToolButtonFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionToolButton::ToolButtonFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]));

}

static void QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionToolButton::ToolButtonFeature>*)cppOut) = ::QFlags<QStyleOptionToolButton::ToolButtonFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX]))
        return QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionToolButton::ToolButtonFeature>*)cppOut) = ::QFlags<QStyleOptionToolButton::ToolButtonFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionToolButton_PythonToCpp_QStyleOptionToolButton_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionToolButton_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionToolButton_PythonToCpp_QStyleOptionToolButton_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionToolButton_Type))
        return QStyleOptionToolButton_PythonToCpp_QStyleOptionToolButton_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionToolButton_PTR_CppToPython_QStyleOptionToolButton(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionToolButton*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionToolButton_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionToolButton(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionToolButton_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionToolButton", "QStyleOptionToolButton*",
        &Sbk_QStyleOptionToolButton_Type, &Shiboken::callCppDestructor< ::QStyleOptionToolButton >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionToolButton_Type,
        QStyleOptionToolButton_PythonToCpp_QStyleOptionToolButton_PTR,
        is_QStyleOptionToolButton_PythonToCpp_QStyleOptionToolButton_PTR_Convertible,
        QStyleOptionToolButton_PTR_CppToPython_QStyleOptionToolButton);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionToolButton).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolButton_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionToolButton.StyleOptionType",
        "QStyleOptionToolButton::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "Type", (long) QStyleOptionToolButton::Type))
        return ;
    // Register converter for enum 'QStyleOptionToolButton::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX],
            QStyleOptionToolButton_StyleOptionType_CppToPython_QStyleOptionToolButton_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolButton_StyleOptionType_PythonToCpp_QStyleOptionToolButton_StyleOptionType,
            is_QStyleOptionToolButton_StyleOptionType_PythonToCpp_QStyleOptionToolButton_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolButton_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionToolButton.StyleOptionVersion",
        "QStyleOptionToolButton::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionToolButton_Type, "Version", (long) QStyleOptionToolButton::Version))
        return ;
    // Register converter for enum 'QStyleOptionToolButton::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX],
            QStyleOptionToolButton_StyleOptionVersion_CppToPython_QStyleOptionToolButton_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolButton_StyleOptionVersion_PythonToCpp_QStyleOptionToolButton_StyleOptionVersion,
            is_QStyleOptionToolButton_StyleOptionVersion_PythonToCpp_QStyleOptionToolButton_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'ToolButtonFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX] = PySide::QFlags::create("ToolButtonFeatures", &SbkPySide_QtGui_QStyleOptionToolButton_ToolButtonFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolButton_Type,
        "ToolButtonFeature",
        "PySide.QtGui.QStyleOptionToolButton.ToolButtonFeature",
        "QStyleOptionToolButton::ToolButtonFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "None", (long) QStyleOptionToolButton::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "Arrow", (long) QStyleOptionToolButton::Arrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "Menu", (long) QStyleOptionToolButton::Menu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "MenuButtonPopup", (long) QStyleOptionToolButton::MenuButtonPopup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "PopupDelay", (long) QStyleOptionToolButton::PopupDelay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
        &Sbk_QStyleOptionToolButton_Type, "HasMenu", (long) QStyleOptionToolButton::HasMenu))
        return ;
    // Register converter for enum 'QStyleOptionToolButton::ToolButtonFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX],
            QStyleOptionToolButton_ToolButtonFeature_CppToPython_QStyleOptionToolButton_ToolButtonFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QStyleOptionToolButton_ToolButtonFeature,
            is_QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QStyleOptionToolButton_ToolButtonFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolButton::ToolButtonFeature");
        Shiboken::Conversions::registerConverterName(converter, "ToolButtonFeature");
    }
    // Register converter for flag 'QFlags<QStyleOptionToolButton::ToolButtonFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX],
            QFlags_QStyleOptionToolButton_ToolButtonFeature__CppToPython_QFlags_QStyleOptionToolButton_ToolButtonFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_,
            is_QStyleOptionToolButton_ToolButtonFeature_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionToolButton_ToolButtonFeature__PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_,
            is_QFlags_QStyleOptionToolButton_ToolButtonFeature__PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature_,
            is_number_PythonToCpp_QFlags_QStyleOptionToolButton_ToolButtonFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBUTTON_TOOLBUTTONFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionToolButton::ToolButtonFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ToolButtonFeature>");
    }
    // End of 'ToolButtonFeature' enum/flags.


    qRegisterMetaType< ::QStyleOptionToolButton::StyleOptionType >("QStyleOptionToolButton::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionToolButton::StyleOptionVersion >("QStyleOptionToolButton::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionToolButton::ToolButtonFeature >("QStyleOptionToolButton::ToolButtonFeature");
    qRegisterMetaType< ::QStyleOptionToolButton::ToolButtonFeatures >("QStyleOptionToolButton::ToolButtonFeatures");
}
