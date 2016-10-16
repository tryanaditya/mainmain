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

#include "qabstracttextdocumentlayout_paintcontext_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractTextDocumentLayout_PaintContext_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractTextDocumentLayout::PaintContext >()))
        return -1;

    ::QAbstractTextDocumentLayout::PaintContext* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "PaintContext", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: PaintContext()
    // 1: PaintContext(QAbstractTextDocumentLayout::PaintContext)
    if (numArgs == 0) {
        overloadId = 0; // PaintContext()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (pyArgs[0])))) {
        overloadId = 1; // PaintContext(QAbstractTextDocumentLayout::PaintContext)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractTextDocumentLayout_PaintContext_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // PaintContext()
        {

            if (!PyErr_Occurred()) {
                // PaintContext()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAbstractTextDocumentLayout::PaintContext();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // PaintContext(const QAbstractTextDocumentLayout::PaintContext & PaintContext)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAbstractTextDocumentLayout::PaintContext cppArg0_local = ::QAbstractTextDocumentLayout::PaintContext();
            ::QAbstractTextDocumentLayout::PaintContext* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // PaintContext(QAbstractTextDocumentLayout::PaintContext)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAbstractTextDocumentLayout::PaintContext(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractTextDocumentLayout::PaintContext >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractTextDocumentLayout_PaintContext_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QAbstractTextDocumentLayout_PaintContext_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QAbstractTextDocumentLayout::PaintContext", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.PaintContext", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractTextDocumentLayout_PaintContext___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAbstractTextDocumentLayout::PaintContext& cppSelf = *(((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAbstractTextDocumentLayout_PaintContext_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QAbstractTextDocumentLayout_PaintContext___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QAbstractTextDocumentLayout_PaintContext_get_palette(PyObject* self, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &(cppSelf->palette), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QAbstractTextDocumentLayout_PaintContext_set_palette(PyObject* self, PyObject* pyIn, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'palette' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'palette', 'QPalette' or convertible type expected");
        return -1;
    }

    ::QPalette& cppOut_ptr = cppSelf->palette;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QAbstractTextDocumentLayout_PaintContext_get_cursorPosition(PyObject* self, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->cursorPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QAbstractTextDocumentLayout_PaintContext_set_cursorPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'cursorPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'cursorPosition', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->cursorPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->cursorPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QAbstractTextDocumentLayout_PaintContext_get_clip(PyObject* self, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &(cppSelf->clip), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QAbstractTextDocumentLayout_PaintContext_set_clip(PyObject* self, PyObject* pyIn, void*)
{
    ::QAbstractTextDocumentLayout::PaintContext* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'clip' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'clip', 'QRectF' or convertible type expected");
        return -1;
    }

    ::QRectF& cppOut_ptr = cppSelf->clip;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for PaintContext
static PyGetSetDef Sbk_QAbstractTextDocumentLayout_PaintContext_getsetlist[] = {
    {const_cast<char*>("palette"), Sbk_QAbstractTextDocumentLayout_PaintContext_get_palette, Sbk_QAbstractTextDocumentLayout_PaintContext_set_palette},
    {const_cast<char*>("cursorPosition"), Sbk_QAbstractTextDocumentLayout_PaintContext_get_cursorPosition, Sbk_QAbstractTextDocumentLayout_PaintContext_set_cursorPosition},
    {const_cast<char*>("clip"), Sbk_QAbstractTextDocumentLayout_PaintContext_get_clip, Sbk_QAbstractTextDocumentLayout_PaintContext_set_clip},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QAbstractTextDocumentLayout_PaintContext_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractTextDocumentLayout_PaintContext_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractTextDocumentLayout_PaintContext_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QAbstractTextDocumentLayout.PaintContext",
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
    /*tp_traverse*/         Sbk_QAbstractTextDocumentLayout_PaintContext_traverse,
    /*tp_clear*/            Sbk_QAbstractTextDocumentLayout_PaintContext_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractTextDocumentLayout_PaintContext_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QAbstractTextDocumentLayout_PaintContext_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractTextDocumentLayout_PaintContext_Init,
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
static void PaintContext_PythonToCpp_PaintContext_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractTextDocumentLayout_PaintContext_Type, pyIn, cppOut);
}
static PythonToCppFunc is_PaintContext_PythonToCpp_PaintContext_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractTextDocumentLayout_PaintContext_Type))
        return PaintContext_PythonToCpp_PaintContext_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PaintContext_PTR_CppToPython_PaintContext(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAbstractTextDocumentLayout::PaintContext*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAbstractTextDocumentLayout_PaintContext_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* PaintContext_COPY_CppToPython_PaintContext(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QAbstractTextDocumentLayout_PaintContext_Type, new ::QAbstractTextDocumentLayout::PaintContext(*((::QAbstractTextDocumentLayout::PaintContext*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void PaintContext_PythonToCpp_PaintContext_COPY(PyObject* pyIn, void* cppOut) {
    *((::QAbstractTextDocumentLayout::PaintContext*)cppOut) = *((::QAbstractTextDocumentLayout::PaintContext*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_PaintContext_PythonToCpp_PaintContext_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractTextDocumentLayout_PaintContext_Type))
        return PaintContext_PythonToCpp_PaintContext_COPY;
    return 0;
}

void init_QAbstractTextDocumentLayout_PaintContext(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractTextDocumentLayout_PaintContext_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "PaintContext", "QAbstractTextDocumentLayout::PaintContext",
        &Sbk_QAbstractTextDocumentLayout_PaintContext_Type, &Shiboken::callCppDestructor< ::QAbstractTextDocumentLayout::PaintContext >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractTextDocumentLayout_PaintContext_Type,
        PaintContext_PythonToCpp_PaintContext_PTR,
        is_PaintContext_PythonToCpp_PaintContext_PTR_Convertible,
        PaintContext_PTR_CppToPython_PaintContext,
        PaintContext_COPY_CppToPython_PaintContext);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractTextDocumentLayout::PaintContext");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractTextDocumentLayout::PaintContext*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractTextDocumentLayout::PaintContext&");
    Shiboken::Conversions::registerConverterName(converter, "PaintContext");
    Shiboken::Conversions::registerConverterName(converter, "PaintContext*");
    Shiboken::Conversions::registerConverterName(converter, "PaintContext&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractTextDocumentLayout::PaintContext).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PaintContext_PythonToCpp_PaintContext_COPY,
        is_PaintContext_PythonToCpp_PaintContext_COPY_Convertible);


    qRegisterMetaType< ::QAbstractTextDocumentLayout::PaintContext >("PaintContext");
    qRegisterMetaType< ::QAbstractTextDocumentLayout::PaintContext >("QAbstractTextDocumentLayout::PaintContext");
}
