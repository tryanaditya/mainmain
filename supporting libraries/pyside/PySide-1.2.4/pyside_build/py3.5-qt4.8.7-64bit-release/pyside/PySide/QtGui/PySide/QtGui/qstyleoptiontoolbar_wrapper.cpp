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

#include "qstyleoptiontoolbar_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionToolBar_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionToolBar >()))
        return -1;

    ::QStyleOptionToolBar* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionToolBar", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionToolBar()
    // 1: QStyleOptionToolBar(QStyleOptionToolBar)
    // 2: QStyleOptionToolBar(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionToolBar()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionToolBar(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionToolBar(QStyleOptionToolBar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionToolBar_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionToolBar()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBar()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBar();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionToolBar(const QStyleOptionToolBar & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionToolBar* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBar(QStyleOptionToolBar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBar(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionToolBar(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionToolBar(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionToolBar(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionToolBar >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionToolBar_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionToolBar_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionToolBar", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionToolBar", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionToolBar_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionToolBar_get_lineWidth(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->lineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_lineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'lineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'lineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->lineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->lineWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBar_get_positionWithinLine(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    ::QStyleOptionToolBar::ToolBarPosition cppOut_local = cppSelf->positionWithinLine;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_positionWithinLine(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'positionWithinLine' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'positionWithinLine', 'ToolBarPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionToolBar::ToolBarPosition cppOut_local = cppSelf->positionWithinLine;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->positionWithinLine = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBar_get_positionOfLine(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    ::QStyleOptionToolBar::ToolBarPosition cppOut_local = cppSelf->positionOfLine;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_positionOfLine(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'positionOfLine' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'positionOfLine', 'ToolBarPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionToolBar::ToolBarPosition cppOut_local = cppSelf->positionOfLine;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->positionOfLine = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBar_get_features(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), &cppSelf->features);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_features(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'features' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'features', 'ToolBarFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyleOptionToolBar::ToolBarFeature> cppOut_local = cppSelf->features;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->features = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBar_get_toolBarArea(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    ::Qt::ToolBarArea cppOut_local = cppSelf->toolBarArea;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_toolBarArea(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'toolBarArea' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'toolBarArea', 'ToolBarArea' or convertible type expected");
        return -1;
    }

    ::Qt::ToolBarArea cppOut_local = cppSelf->toolBarArea;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->toolBarArea = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionToolBar_get_midLineWidth(PyObject* self, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->midLineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionToolBar_set_midLineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionToolBar* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionToolBar*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'midLineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'midLineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->midLineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->midLineWidth = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionToolBar
static PyGetSetDef Sbk_QStyleOptionToolBar_getsetlist[] = {
    {const_cast<char*>("lineWidth"), Sbk_QStyleOptionToolBar_get_lineWidth, Sbk_QStyleOptionToolBar_set_lineWidth},
    {const_cast<char*>("positionWithinLine"), Sbk_QStyleOptionToolBar_get_positionWithinLine, Sbk_QStyleOptionToolBar_set_positionWithinLine},
    {const_cast<char*>("positionOfLine"), Sbk_QStyleOptionToolBar_get_positionOfLine, Sbk_QStyleOptionToolBar_set_positionOfLine},
    {const_cast<char*>("features"), Sbk_QStyleOptionToolBar_get_features, Sbk_QStyleOptionToolBar_set_features},
    {const_cast<char*>("toolBarArea"), Sbk_QStyleOptionToolBar_get_toolBarArea, Sbk_QStyleOptionToolBar_set_toolBarArea},
    {const_cast<char*>("midLineWidth"), Sbk_QStyleOptionToolBar_get_midLineWidth, Sbk_QStyleOptionToolBar_set_midLineWidth},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionToolBar_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionToolBar_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionToolBar_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionToolBar",
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
    /*tp_traverse*/         Sbk_QStyleOptionToolBar_traverse,
    /*tp_clear*/            Sbk_QStyleOptionToolBar_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionToolBar_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionToolBar_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionToolBar_Init,
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

PyObject* SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolBar::ToolBarFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolBar::ToolBarFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolBar::ToolBarFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(self);
    cppArg = (QStyleOptionToolBar::ToolBarFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyleOptionToolBar::ToolBarFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), self, &cppSelf);
    ::QStyleOptionToolBar::ToolBarFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature_long,
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
static void QStyleOptionToolBar_StyleOptionType_PythonToCpp_QStyleOptionToolBar_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBar::StyleOptionType*)cppOut) = (::QStyleOptionToolBar::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBar_StyleOptionType_PythonToCpp_QStyleOptionToolBar_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionToolBar_StyleOptionType_PythonToCpp_QStyleOptionToolBar_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionToolBar_StyleOptionType_CppToPython_QStyleOptionToolBar_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBar::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionToolBar_StyleOptionVersion_PythonToCpp_QStyleOptionToolBar_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBar::StyleOptionVersion*)cppOut) = (::QStyleOptionToolBar::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBar_StyleOptionVersion_PythonToCpp_QStyleOptionToolBar_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionToolBar_StyleOptionVersion_PythonToCpp_QStyleOptionToolBar_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionToolBar_StyleOptionVersion_CppToPython_QStyleOptionToolBar_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBar::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionToolBar_ToolBarPosition_PythonToCpp_QStyleOptionToolBar_ToolBarPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBar::ToolBarPosition*)cppOut) = (::QStyleOptionToolBar::ToolBarPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBar_ToolBarPosition_PythonToCpp_QStyleOptionToolBar_ToolBarPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX]))
        return QStyleOptionToolBar_ToolBarPosition_PythonToCpp_QStyleOptionToolBar_ToolBarPosition;
    return 0;
}
static PyObject* QStyleOptionToolBar_ToolBarPosition_CppToPython_QStyleOptionToolBar_ToolBarPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBar::ToolBarPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX], castCppIn);

}

static void QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QStyleOptionToolBar_ToolBarFeature(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionToolBar::ToolBarFeature*)cppOut) = (::QStyleOptionToolBar::ToolBarFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QStyleOptionToolBar_ToolBarFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX]))
        return QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QStyleOptionToolBar_ToolBarFeature;
    return 0;
}
static PyObject* QStyleOptionToolBar_ToolBarFeature_CppToPython_QStyleOptionToolBar_ToolBarFeature(const void* cppIn) {
    int castCppIn = *((::QStyleOptionToolBar::ToolBarFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX], castCppIn);

}

static void QFlags_QStyleOptionToolBar_ToolBarFeature__PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionToolBar::ToolBarFeature>*)cppOut) = ::QFlags<QStyleOptionToolBar::ToolBarFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyleOptionToolBar_ToolBarFeature__PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]))
        return QFlags_QStyleOptionToolBar_ToolBarFeature__PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_;
    return 0;
}
static PyObject* QFlags_QStyleOptionToolBar_ToolBarFeature__CppToPython_QFlags_QStyleOptionToolBar_ToolBarFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyleOptionToolBar::ToolBarFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]));

}

static void QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyleOptionToolBar::ToolBarFeature>*)cppOut) = ::QFlags<QStyleOptionToolBar::ToolBarFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX]))
        return QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyleOptionToolBar::ToolBarFeature>*)cppOut) = ::QFlags<QStyleOptionToolBar::ToolBarFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionToolBar_PythonToCpp_QStyleOptionToolBar_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionToolBar_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionToolBar_PythonToCpp_QStyleOptionToolBar_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionToolBar_Type))
        return QStyleOptionToolBar_PythonToCpp_QStyleOptionToolBar_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionToolBar_PTR_CppToPython_QStyleOptionToolBar(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionToolBar*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionToolBar_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionToolBar(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionToolBar_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionToolBar", "QStyleOptionToolBar*",
        &Sbk_QStyleOptionToolBar_Type, &Shiboken::callCppDestructor< ::QStyleOptionToolBar >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionToolBar_Type,
        QStyleOptionToolBar_PythonToCpp_QStyleOptionToolBar_PTR,
        is_QStyleOptionToolBar_PythonToCpp_QStyleOptionToolBar_PTR_Convertible,
        QStyleOptionToolBar_PTR_CppToPython_QStyleOptionToolBar);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionToolBar).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBar_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionToolBar.StyleOptionType",
        "QStyleOptionToolBar::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionToolBar_Type, "Type", (long) QStyleOptionToolBar::Type))
        return ;
    // Register converter for enum 'QStyleOptionToolBar::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX],
            QStyleOptionToolBar_StyleOptionType_CppToPython_QStyleOptionToolBar_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBar_StyleOptionType_PythonToCpp_QStyleOptionToolBar_StyleOptionType,
            is_QStyleOptionToolBar_StyleOptionType_PythonToCpp_QStyleOptionToolBar_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBar_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionToolBar.StyleOptionVersion",
        "QStyleOptionToolBar::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionToolBar_Type, "Version", (long) QStyleOptionToolBar::Version))
        return ;
    // Register converter for enum 'QStyleOptionToolBar::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX],
            QStyleOptionToolBar_StyleOptionVersion_CppToPython_QStyleOptionToolBar_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBar_StyleOptionVersion_PythonToCpp_QStyleOptionToolBar_StyleOptionVersion,
            is_QStyleOptionToolBar_StyleOptionVersion_PythonToCpp_QStyleOptionToolBar_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'ToolBarPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBar_Type,
        "ToolBarPosition",
        "PySide.QtGui.QStyleOptionToolBar.ToolBarPosition",
        "QStyleOptionToolBar::ToolBarPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX],
        &Sbk_QStyleOptionToolBar_Type, "Beginning", (long) QStyleOptionToolBar::Beginning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX],
        &Sbk_QStyleOptionToolBar_Type, "Middle", (long) QStyleOptionToolBar::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX],
        &Sbk_QStyleOptionToolBar_Type, "End", (long) QStyleOptionToolBar::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX],
        &Sbk_QStyleOptionToolBar_Type, "OnlyOne", (long) QStyleOptionToolBar::OnlyOne))
        return ;
    // Register converter for enum 'QStyleOptionToolBar::ToolBarPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX],
            QStyleOptionToolBar_ToolBarPosition_CppToPython_QStyleOptionToolBar_ToolBarPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBar_ToolBarPosition_PythonToCpp_QStyleOptionToolBar_ToolBarPosition,
            is_QStyleOptionToolBar_ToolBarPosition_PythonToCpp_QStyleOptionToolBar_ToolBarPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar::ToolBarPosition");
        Shiboken::Conversions::registerConverterName(converter, "ToolBarPosition");
    }
    // End of 'ToolBarPosition' enum.

    // Initialization of enum 'ToolBarFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX] = PySide::QFlags::create("ToolBarFeatures", &SbkPySide_QtGui_QStyleOptionToolBar_ToolBarFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionToolBar_Type,
        "ToolBarFeature",
        "PySide.QtGui.QStyleOptionToolBar.ToolBarFeature",
        "QStyleOptionToolBar::ToolBarFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX],
        &Sbk_QStyleOptionToolBar_Type, "None", (long) QStyleOptionToolBar::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX],
        &Sbk_QStyleOptionToolBar_Type, "Movable", (long) QStyleOptionToolBar::Movable))
        return ;
    // Register converter for enum 'QStyleOptionToolBar::ToolBarFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX],
            QStyleOptionToolBar_ToolBarFeature_CppToPython_QStyleOptionToolBar_ToolBarFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QStyleOptionToolBar_ToolBarFeature,
            is_QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QStyleOptionToolBar_ToolBarFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionToolBar::ToolBarFeature");
        Shiboken::Conversions::registerConverterName(converter, "ToolBarFeature");
    }
    // Register converter for flag 'QFlags<QStyleOptionToolBar::ToolBarFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX],
            QFlags_QStyleOptionToolBar_ToolBarFeature__CppToPython_QFlags_QStyleOptionToolBar_ToolBarFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_,
            is_QStyleOptionToolBar_ToolBarFeature_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyleOptionToolBar_ToolBarFeature__PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_,
            is_QFlags_QStyleOptionToolBar_ToolBarFeature__PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature_,
            is_number_PythonToCpp_QFlags_QStyleOptionToolBar_ToolBarFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLEOPTIONTOOLBAR_TOOLBARFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyleOptionToolBar::ToolBarFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ToolBarFeature>");
    }
    // End of 'ToolBarFeature' enum/flags.


    qRegisterMetaType< ::QStyleOptionToolBar::StyleOptionType >("QStyleOptionToolBar::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionToolBar::StyleOptionVersion >("QStyleOptionToolBar::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionToolBar::ToolBarPosition >("QStyleOptionToolBar::ToolBarPosition");
    qRegisterMetaType< ::QStyleOptionToolBar::ToolBarFeature >("QStyleOptionToolBar::ToolBarFeature");
    qRegisterMetaType< ::QStyleOptionToolBar::ToolBarFeatures >("QStyleOptionToolBar::ToolBarFeatures");
}
