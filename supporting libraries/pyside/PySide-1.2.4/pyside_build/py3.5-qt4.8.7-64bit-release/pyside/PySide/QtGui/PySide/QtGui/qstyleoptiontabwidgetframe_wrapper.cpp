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

#include "qstyleoptiontabwidgetframe_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionTabWidgetFrame_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionTabWidgetFrame >()))
        return -1;

    ::QStyleOptionTabWidgetFrame* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionTabWidgetFrame", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionTabWidgetFrame()
    // 1: QStyleOptionTabWidgetFrame(QStyleOptionTabWidgetFrame)
    // 2: QStyleOptionTabWidgetFrame(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionTabWidgetFrame()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionTabWidgetFrame(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionTabWidgetFrame(QStyleOptionTabWidgetFrame)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionTabWidgetFrame_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionTabWidgetFrame()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionTabWidgetFrame()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabWidgetFrame();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionTabWidgetFrame(const QStyleOptionTabWidgetFrame & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionTabWidgetFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTabWidgetFrame(QStyleOptionTabWidgetFrame)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabWidgetFrame(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionTabWidgetFrame(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionTabWidgetFrame(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionTabWidgetFrame(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionTabWidgetFrame >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionTabWidgetFrame_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionTabWidgetFrame_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionTabWidgetFrame", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionTabWidgetFrame", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionTabWidgetFrame_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_lineWidth(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->lineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_lineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_rightCornerWidgetSize(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->rightCornerWidgetSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_rightCornerWidgetSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'rightCornerWidgetSize' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'rightCornerWidgetSize', 'QSize' or convertible type expected");
        return -1;
    }

    ::QSize& cppOut_ptr = cppSelf->rightCornerWidgetSize;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_tabBarSize(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->tabBarSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_tabBarSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tabBarSize' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tabBarSize', 'QSize' or convertible type expected");
        return -1;
    }

    ::QSize& cppOut_ptr = cppSelf->tabBarSize;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_shape(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    ::QTabBar::Shape cppOut_local = cppSelf->shape;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABBAR_SHAPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_shape(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_midLineWidth(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->midLineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_midLineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionTabWidgetFrame_get_leftCornerWidgetSize(PyObject* self, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &(cppSelf->leftCornerWidgetSize), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionTabWidgetFrame_set_leftCornerWidgetSize(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionTabWidgetFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionTabWidgetFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'leftCornerWidgetSize' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'leftCornerWidgetSize', 'QSize' or convertible type expected");
        return -1;
    }

    ::QSize& cppOut_ptr = cppSelf->leftCornerWidgetSize;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionTabWidgetFrame
static PyGetSetDef Sbk_QStyleOptionTabWidgetFrame_getsetlist[] = {
    {const_cast<char*>("lineWidth"), Sbk_QStyleOptionTabWidgetFrame_get_lineWidth, Sbk_QStyleOptionTabWidgetFrame_set_lineWidth},
    {const_cast<char*>("rightCornerWidgetSize"), Sbk_QStyleOptionTabWidgetFrame_get_rightCornerWidgetSize, Sbk_QStyleOptionTabWidgetFrame_set_rightCornerWidgetSize},
    {const_cast<char*>("tabBarSize"), Sbk_QStyleOptionTabWidgetFrame_get_tabBarSize, Sbk_QStyleOptionTabWidgetFrame_set_tabBarSize},
    {const_cast<char*>("shape"), Sbk_QStyleOptionTabWidgetFrame_get_shape, Sbk_QStyleOptionTabWidgetFrame_set_shape},
    {const_cast<char*>("midLineWidth"), Sbk_QStyleOptionTabWidgetFrame_get_midLineWidth, Sbk_QStyleOptionTabWidgetFrame_set_midLineWidth},
    {const_cast<char*>("leftCornerWidgetSize"), Sbk_QStyleOptionTabWidgetFrame_get_leftCornerWidgetSize, Sbk_QStyleOptionTabWidgetFrame_set_leftCornerWidgetSize},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionTabWidgetFrame_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionTabWidgetFrame_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionTabWidgetFrame_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionTabWidgetFrame",
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
    /*tp_traverse*/         Sbk_QStyleOptionTabWidgetFrame_traverse,
    /*tp_clear*/            Sbk_QStyleOptionTabWidgetFrame_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionTabWidgetFrame_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionTabWidgetFrame_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionTabWidgetFrame_Init,
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
static void QStyleOptionTabWidgetFrame_StyleOptionType_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTabWidgetFrame::StyleOptionType*)cppOut) = (::QStyleOptionTabWidgetFrame::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTabWidgetFrame_StyleOptionType_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionTabWidgetFrame_StyleOptionType_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionTabWidgetFrame_StyleOptionType_CppToPython_QStyleOptionTabWidgetFrame_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTabWidgetFrame::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionTabWidgetFrame_StyleOptionVersion_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionTabWidgetFrame::StyleOptionVersion*)cppOut) = (::QStyleOptionTabWidgetFrame::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionTabWidgetFrame_StyleOptionVersion_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionTabWidgetFrame_StyleOptionVersion_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionTabWidgetFrame_StyleOptionVersion_CppToPython_QStyleOptionTabWidgetFrame_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionTabWidgetFrame::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionTabWidgetFrame_PythonToCpp_QStyleOptionTabWidgetFrame_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionTabWidgetFrame_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionTabWidgetFrame_PythonToCpp_QStyleOptionTabWidgetFrame_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionTabWidgetFrame_Type))
        return QStyleOptionTabWidgetFrame_PythonToCpp_QStyleOptionTabWidgetFrame_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionTabWidgetFrame_PTR_CppToPython_QStyleOptionTabWidgetFrame(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionTabWidgetFrame*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionTabWidgetFrame_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionTabWidgetFrame(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionTabWidgetFrame_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionTabWidgetFrame", "QStyleOptionTabWidgetFrame*",
        &Sbk_QStyleOptionTabWidgetFrame_Type, &Shiboken::callCppDestructor< ::QStyleOptionTabWidgetFrame >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionTabWidgetFrame_Type,
        QStyleOptionTabWidgetFrame_PythonToCpp_QStyleOptionTabWidgetFrame_PTR,
        is_QStyleOptionTabWidgetFrame_PythonToCpp_QStyleOptionTabWidgetFrame_PTR_Convertible,
        QStyleOptionTabWidgetFrame_PTR_CppToPython_QStyleOptionTabWidgetFrame);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabWidgetFrame");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabWidgetFrame*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabWidgetFrame&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionTabWidgetFrame).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTabWidgetFrame_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionTabWidgetFrame.StyleOptionType",
        "QStyleOptionTabWidgetFrame::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionTabWidgetFrame_Type, "Type", (long) QStyleOptionTabWidgetFrame::Type))
        return ;
    // Register converter for enum 'QStyleOptionTabWidgetFrame::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX],
            QStyleOptionTabWidgetFrame_StyleOptionType_CppToPython_QStyleOptionTabWidgetFrame_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTabWidgetFrame_StyleOptionType_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionType,
            is_QStyleOptionTabWidgetFrame_StyleOptionType_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabWidgetFrame::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionTabWidgetFrame_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionTabWidgetFrame.StyleOptionVersion",
        "QStyleOptionTabWidgetFrame::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionTabWidgetFrame_Type, "Version", (long) QStyleOptionTabWidgetFrame::Version))
        return ;
    // Register converter for enum 'QStyleOptionTabWidgetFrame::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX],
            QStyleOptionTabWidgetFrame_StyleOptionVersion_CppToPython_QStyleOptionTabWidgetFrame_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionTabWidgetFrame_StyleOptionVersion_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionVersion,
            is_QStyleOptionTabWidgetFrame_StyleOptionVersion_PythonToCpp_QStyleOptionTabWidgetFrame_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONTABWIDGETFRAME_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionTabWidgetFrame::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionTabWidgetFrame::StyleOptionType >("QStyleOptionTabWidgetFrame::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionTabWidgetFrame::StyleOptionVersion >("QStyleOptionTabWidgetFrame::StyleOptionVersion");
}
