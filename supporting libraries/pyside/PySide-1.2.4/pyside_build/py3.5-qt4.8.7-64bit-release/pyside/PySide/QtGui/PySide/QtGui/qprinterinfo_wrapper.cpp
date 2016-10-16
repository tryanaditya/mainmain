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

#include "qprinterinfo_wrapper.h"

// Extra includes
#include <QList>
#include <qprinter.h>
#include <qprinterinfo.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPrinterInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPrinterInfo >()))
        return -1;

    ::QPrinterInfo* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPrinterInfo", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPrinterInfo()
    // 1: QPrinterInfo(QPrinter)
    // 2: QPrinterInfo(QPrinterInfo)
    if (numArgs == 0) {
        overloadId = 0; // QPrinterInfo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPrinterInfo(QPrinter)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPrinterInfo(QPrinterInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPrinterInfo()
        {

            if (!PyErr_Occurred()) {
                // QPrinterInfo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPrinterInfo();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPrinterInfo(const QPrinter & printer)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPrinter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPrinterInfo(QPrinter)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPrinterInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPrinterInfo(const QPrinterInfo & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPrinterInfo cppArg0_local = ::QPrinterInfo();
            ::QPrinterInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPrinterInfo(QPrinterInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPrinterInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPrinterInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPrinterInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPrinterInfo_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPrinter", "PySide.QtGui.QPrinterInfo", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinterInfo", overloads);
        return -1;
}

static PyObject* Sbk_QPrinterInfoFunc_availablePrinters(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availablePrinters()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPrinterInfo > cppResult = ::QPrinterInfo::availablePrinters();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTERINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterInfoFunc_defaultPrinter(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultPrinter()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinterInfo cppResult = ::QPrinterInfo::defaultPrinter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterInfoFunc_isDefault(PyObject* self)
{
    ::QPrinterInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDefault()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinterInfo*>(cppSelf)->isDefault();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterInfoFunc_isNull(PyObject* self)
{
    ::QPrinterInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinterInfo*>(cppSelf)->isNull();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterInfoFunc_printerName(PyObject* self)
{
    ::QPrinterInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printerName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinterInfo*>(cppSelf)->printerName();
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

static PyObject* Sbk_QPrinterInfoFunc_supportedPaperSizes(PyObject* self)
{
    ::QPrinterInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedPaperSizes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPrinter::PageSize > cppResult = const_cast<const ::QPrinterInfo*>(cppSelf)->supportedPaperSizes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPRINTER_PAGESIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPrinterInfo& cppSelf = *(((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPrinterInfo_methods[] = {
    {"availablePrinters", (PyCFunction)Sbk_QPrinterInfoFunc_availablePrinters, METH_NOARGS|METH_STATIC},
    {"defaultPrinter", (PyCFunction)Sbk_QPrinterInfoFunc_defaultPrinter, METH_NOARGS|METH_STATIC},
    {"isDefault", (PyCFunction)Sbk_QPrinterInfoFunc_isDefault, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QPrinterInfoFunc_isNull, METH_NOARGS},
    {"printerName", (PyCFunction)Sbk_QPrinterInfoFunc_printerName, METH_NOARGS},
    {"supportedPaperSizes", (PyCFunction)Sbk_QPrinterInfoFunc_supportedPaperSizes, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QPrinterInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QPrinterInfo___nb_bool(PyObject* self)
{
    ::QPrinterInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QPrinterInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPrinterInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPrinterInfo_TypeAsNumber;

static SbkObjectType Sbk_QPrinterInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPrinterInfo",
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
    /*tp_traverse*/         Sbk_QPrinterInfo_traverse,
    /*tp_clear*/            Sbk_QPrinterInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPrinterInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPrinterInfo_Init,
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
static void QPrinterInfo_PythonToCpp_QPrinterInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPrinterInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPrinterInfo_PythonToCpp_QPrinterInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPrinterInfo_Type))
        return QPrinterInfo_PythonToCpp_QPrinterInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPrinterInfo_PTR_CppToPython_QPrinterInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPrinterInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPrinterInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPrinterInfo_COPY_CppToPython_QPrinterInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPrinterInfo_Type, new ::QPrinterInfo(*((::QPrinterInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPrinterInfo_PythonToCpp_QPrinterInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPrinterInfo*)cppOut) = *((::QPrinterInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPrinterInfo_PythonToCpp_QPrinterInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPrinterInfo_Type))
        return QPrinterInfo_PythonToCpp_QPrinterInfo_COPY;
    return 0;
}

// Implicit conversions.
static void constQPrinterREF_PythonToCpp_QPrinterInfo(PyObject* pyIn, void* cppOut) {
    *((::QPrinterInfo*)cppOut) = ::QPrinterInfo(*((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPrinterREF_PythonToCpp_QPrinterInfo_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], pyIn))
        return constQPrinterREF_PythonToCpp_QPrinterInfo;
    return 0;
}

void init_QPrinterInfo(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPrinterInfo_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QPrinterInfo_TypeAsNumber) = Sbk_QPrinterInfo___nb_bool;
    Sbk_QPrinterInfo_Type.super.ht_type.tp_as_number = &Sbk_QPrinterInfo_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPrinterInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPrinterInfo", "QPrinterInfo",
        &Sbk_QPrinterInfo_Type, &Shiboken::callCppDestructor< ::QPrinterInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPrinterInfo_Type,
        QPrinterInfo_PythonToCpp_QPrinterInfo_PTR,
        is_QPrinterInfo_PythonToCpp_QPrinterInfo_PTR_Convertible,
        QPrinterInfo_PTR_CppToPython_QPrinterInfo,
        QPrinterInfo_COPY_CppToPython_QPrinterInfo);

    Shiboken::Conversions::registerConverterName(converter, "QPrinterInfo");
    Shiboken::Conversions::registerConverterName(converter, "QPrinterInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QPrinterInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPrinterInfo).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPrinterInfo_PythonToCpp_QPrinterInfo_COPY,
        is_QPrinterInfo_PythonToCpp_QPrinterInfo_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPrinterREF_PythonToCpp_QPrinterInfo,
        is_constQPrinterREF_PythonToCpp_QPrinterInfo_Convertible);


    qRegisterMetaType< ::QPrinterInfo >("QPrinterInfo");
}
