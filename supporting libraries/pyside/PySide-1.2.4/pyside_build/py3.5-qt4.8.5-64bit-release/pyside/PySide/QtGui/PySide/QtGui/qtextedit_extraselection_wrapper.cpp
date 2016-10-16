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

#include "qtextedit_extraselection_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextEdit_ExtraSelection_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextEdit::ExtraSelection >()))
        return -1;

    ::QTextEdit::ExtraSelection* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ExtraSelection", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ExtraSelection()
    // 1: ExtraSelection(QTextEdit::ExtraSelection)
    if (numArgs == 0) {
        overloadId = 0; // ExtraSelection()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // ExtraSelection(QTextEdit::ExtraSelection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextEdit_ExtraSelection_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ExtraSelection()
        {

            if (!PyErr_Occurred()) {
                // ExtraSelection()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextEdit::ExtraSelection();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ExtraSelection(const QTextEdit::ExtraSelection & ExtraSelection)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextEdit::ExtraSelection cppArg0_local = ::QTextEdit::ExtraSelection();
            ::QTextEdit::ExtraSelection* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ExtraSelection(QTextEdit::ExtraSelection)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextEdit::ExtraSelection(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextEdit::ExtraSelection >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextEdit_ExtraSelection_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextEdit_ExtraSelection_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextEdit::ExtraSelection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.ExtraSelection", overloads);
        return -1;
}

static PyObject* Sbk_QTextEdit_ExtraSelection___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextEdit::ExtraSelection& cppSelf = *(((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextEdit_ExtraSelection_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QTextEdit_ExtraSelection___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTextEdit_ExtraSelection_get_cursor(PyObject* self, void*)
{
    ::QTextEdit::ExtraSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &(cppSelf->cursor), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QTextEdit_ExtraSelection_set_cursor(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextEdit::ExtraSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'cursor' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'cursor', 'QTextCursor' or convertible type expected");
        return -1;
    }

    ::QTextCursor& cppOut_ptr = cppSelf->cursor;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QTextEdit_ExtraSelection_get_format(PyObject* self, void*)
{
    ::QTextEdit::ExtraSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &(cppSelf->format), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QTextEdit_ExtraSelection_set_format(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextEdit::ExtraSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'format' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'format', 'QTextCharFormat' or convertible type expected");
        return -1;
    }

    ::QTextCharFormat& cppOut_ptr = cppSelf->format;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for ExtraSelection
static PyGetSetDef Sbk_QTextEdit_ExtraSelection_getsetlist[] = {
    {const_cast<char*>("cursor"), Sbk_QTextEdit_ExtraSelection_get_cursor, Sbk_QTextEdit_ExtraSelection_set_cursor},
    {const_cast<char*>("format"), Sbk_QTextEdit_ExtraSelection_get_format, Sbk_QTextEdit_ExtraSelection_set_format},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QTextEdit_ExtraSelection_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextEdit_ExtraSelection_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextEdit_ExtraSelection_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextEdit.ExtraSelection",
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
    /*tp_traverse*/         Sbk_QTextEdit_ExtraSelection_traverse,
    /*tp_clear*/            Sbk_QTextEdit_ExtraSelection_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextEdit_ExtraSelection_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QTextEdit_ExtraSelection_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextEdit_ExtraSelection_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ExtraSelection_PythonToCpp_ExtraSelection_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextEdit_ExtraSelection_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ExtraSelection_PythonToCpp_ExtraSelection_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextEdit_ExtraSelection_Type))
        return ExtraSelection_PythonToCpp_ExtraSelection_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ExtraSelection_PTR_CppToPython_ExtraSelection(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextEdit::ExtraSelection*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextEdit_ExtraSelection_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* ExtraSelection_COPY_CppToPython_ExtraSelection(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextEdit_ExtraSelection_Type, new ::QTextEdit::ExtraSelection(*((::QTextEdit::ExtraSelection*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void ExtraSelection_PythonToCpp_ExtraSelection_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextEdit::ExtraSelection*)cppOut) = *((::QTextEdit::ExtraSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_ExtraSelection_PythonToCpp_ExtraSelection_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextEdit_ExtraSelection_Type))
        return ExtraSelection_PythonToCpp_ExtraSelection_COPY;
    return 0;
}

void init_QTextEdit_ExtraSelection(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTEDIT_EXTRASELECTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextEdit_ExtraSelection_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ExtraSelection", "QTextEdit::ExtraSelection",
        &Sbk_QTextEdit_ExtraSelection_Type, &Shiboken::callCppDestructor< ::QTextEdit::ExtraSelection >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextEdit_ExtraSelection_Type,
        ExtraSelection_PythonToCpp_ExtraSelection_PTR,
        is_ExtraSelection_PythonToCpp_ExtraSelection_PTR_Convertible,
        ExtraSelection_PTR_CppToPython_ExtraSelection,
        ExtraSelection_COPY_CppToPython_ExtraSelection);

    Shiboken::Conversions::registerConverterName(converter, "QTextEdit::ExtraSelection");
    Shiboken::Conversions::registerConverterName(converter, "QTextEdit::ExtraSelection*");
    Shiboken::Conversions::registerConverterName(converter, "QTextEdit::ExtraSelection&");
    Shiboken::Conversions::registerConverterName(converter, "ExtraSelection");
    Shiboken::Conversions::registerConverterName(converter, "ExtraSelection*");
    Shiboken::Conversions::registerConverterName(converter, "ExtraSelection&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextEdit::ExtraSelection).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        ExtraSelection_PythonToCpp_ExtraSelection_COPY,
        is_ExtraSelection_PythonToCpp_ExtraSelection_COPY_Convertible);


    qRegisterMetaType< ::QTextEdit::ExtraSelection >("ExtraSelection");
    qRegisterMetaType< ::QTextEdit::ExtraSelection >("QTextEdit::ExtraSelection");
}
