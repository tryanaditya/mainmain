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

#include "qtextlayout_formatrange_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextLayout_FormatRange_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextLayout::FormatRange >()))
        return -1;

    ::QTextLayout::FormatRange* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "FormatRange", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: FormatRange()
    // 1: FormatRange(QTextLayout::FormatRange)
    if (numArgs == 0) {
        overloadId = 0; // FormatRange()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (pyArgs[0])))) {
        overloadId = 1; // FormatRange(QTextLayout::FormatRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLayout_FormatRange_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // FormatRange()
        {

            if (!PyErr_Occurred()) {
                // FormatRange()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLayout::FormatRange();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // FormatRange(const QTextLayout::FormatRange & FormatRange)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextLayout::FormatRange cppArg0_local = ::QTextLayout::FormatRange();
            ::QTextLayout::FormatRange* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // FormatRange(QTextLayout::FormatRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLayout::FormatRange(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextLayout::FormatRange >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextLayout_FormatRange_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextLayout_FormatRange_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextLayout::FormatRange", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.FormatRange", overloads);
        return -1;
}

static PyObject* Sbk_QTextLayout_FormatRange___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextLayout::FormatRange& cppSelf = *(((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextLayout_FormatRange_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QTextLayout_FormatRange___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTextLayout_FormatRange_get_format(PyObject* self, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &(cppSelf->format), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QTextLayout_FormatRange_set_format(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QTextLayout_FormatRange_get_length(PyObject* self, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->length;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QTextLayout_FormatRange_set_length(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'length' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'length', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->length;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->length = cppOut_local;

    return 0;
}

static PyObject* Sbk_QTextLayout_FormatRange_get_start(PyObject* self, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->start;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QTextLayout_FormatRange_set_start(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextLayout::FormatRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'start' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'start', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->start;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->start = cppOut_local;

    return 0;
}

// Getters and Setters for FormatRange
static PyGetSetDef Sbk_QTextLayout_FormatRange_getsetlist[] = {
    {const_cast<char*>("format"), Sbk_QTextLayout_FormatRange_get_format, Sbk_QTextLayout_FormatRange_set_format},
    {const_cast<char*>("length"), Sbk_QTextLayout_FormatRange_get_length, Sbk_QTextLayout_FormatRange_set_length},
    {const_cast<char*>("start"), Sbk_QTextLayout_FormatRange_get_start, Sbk_QTextLayout_FormatRange_set_start},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QTextLayout_FormatRange_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextLayout_FormatRange_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextLayout_FormatRange_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextLayout.FormatRange",
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
    /*tp_traverse*/         Sbk_QTextLayout_FormatRange_traverse,
    /*tp_clear*/            Sbk_QTextLayout_FormatRange_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextLayout_FormatRange_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QTextLayout_FormatRange_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextLayout_FormatRange_Init,
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
static void FormatRange_PythonToCpp_FormatRange_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextLayout_FormatRange_Type, pyIn, cppOut);
}
static PythonToCppFunc is_FormatRange_PythonToCpp_FormatRange_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLayout_FormatRange_Type))
        return FormatRange_PythonToCpp_FormatRange_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* FormatRange_PTR_CppToPython_FormatRange(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextLayout::FormatRange*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextLayout_FormatRange_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* FormatRange_COPY_CppToPython_FormatRange(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextLayout_FormatRange_Type, new ::QTextLayout::FormatRange(*((::QTextLayout::FormatRange*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void FormatRange_PythonToCpp_FormatRange_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextLayout::FormatRange*)cppOut) = *((::QTextLayout::FormatRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_FormatRange_PythonToCpp_FormatRange_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLayout_FormatRange_Type))
        return FormatRange_PythonToCpp_FormatRange_COPY;
    return 0;
}

void init_QTextLayout_FormatRange(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextLayout_FormatRange_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "FormatRange", "QTextLayout::FormatRange",
        &Sbk_QTextLayout_FormatRange_Type, &Shiboken::callCppDestructor< ::QTextLayout::FormatRange >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextLayout_FormatRange_Type,
        FormatRange_PythonToCpp_FormatRange_PTR,
        is_FormatRange_PythonToCpp_FormatRange_PTR_Convertible,
        FormatRange_PTR_CppToPython_FormatRange,
        FormatRange_COPY_CppToPython_FormatRange);

    Shiboken::Conversions::registerConverterName(converter, "QTextLayout::FormatRange");
    Shiboken::Conversions::registerConverterName(converter, "QTextLayout::FormatRange*");
    Shiboken::Conversions::registerConverterName(converter, "QTextLayout::FormatRange&");
    Shiboken::Conversions::registerConverterName(converter, "FormatRange");
    Shiboken::Conversions::registerConverterName(converter, "FormatRange*");
    Shiboken::Conversions::registerConverterName(converter, "FormatRange&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextLayout::FormatRange).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        FormatRange_PythonToCpp_FormatRange_COPY,
        is_FormatRange_PythonToCpp_FormatRange_COPY_Convertible);


    qRegisterMetaType< ::QTextLayout::FormatRange >("FormatRange");
    qRegisterMetaType< ::QTextLayout::FormatRange >("QTextLayout::FormatRange");
}
