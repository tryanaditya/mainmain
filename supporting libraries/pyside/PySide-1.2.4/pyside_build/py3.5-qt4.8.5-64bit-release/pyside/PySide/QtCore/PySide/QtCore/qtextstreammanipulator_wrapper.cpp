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
#include "pyside_qtcore_python.h"

#include "qtextstreammanipulator_wrapper.h"

// Extra includes
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QTextStreamManipulatorFunc_exec_(PyObject* self, PyObject* pyArg)
{
    ::QTextStreamManipulator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStreamManipulator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: exec(QTextStream&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (pyArg)))) {
        overloadId = 0; // exec(QTextStream&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamManipulatorFunc_exec__TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // exec(QTextStream&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->exec(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamManipulatorFunc_exec__TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStreamManipulator.exec_", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamManipulator___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextStreamManipulator& cppSelf = *(((::QTextStreamManipulator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextStreamManipulator_methods[] = {
    {"exec_", (PyCFunction)Sbk_QTextStreamManipulatorFunc_exec_, METH_O},

    {"__copy__", (PyCFunction)Sbk_QTextStreamManipulator___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextStreamManipulator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextStreamManipulator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextStreamManipulator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextStreamManipulator",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QTextStreamManipulator_traverse,
    /*tp_clear*/            Sbk_QTextStreamManipulator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextStreamManipulator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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
static void QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextStreamManipulator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextStreamManipulator_Type))
        return QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextStreamManipulator_PTR_CppToPython_QTextStreamManipulator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextStreamManipulator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextStreamManipulator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextStreamManipulator_COPY_CppToPython_QTextStreamManipulator(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextStreamManipulator_Type, new ::QTextStreamManipulator(*((::QTextStreamManipulator*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextStreamManipulator*)cppOut) = *((::QTextStreamManipulator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextStreamManipulator_Type))
        return QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_COPY;
    return 0;
}

void init_QTextStreamManipulator(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextStreamManipulator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextStreamManipulator", "QTextStreamManipulator",
        &Sbk_QTextStreamManipulator_Type, &Shiboken::callCppDestructor< ::QTextStreamManipulator >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextStreamManipulator_Type,
        QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_PTR,
        is_QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_PTR_Convertible,
        QTextStreamManipulator_PTR_CppToPython_QTextStreamManipulator,
        QTextStreamManipulator_COPY_CppToPython_QTextStreamManipulator);

    Shiboken::Conversions::registerConverterName(converter, "QTextStreamManipulator");
    Shiboken::Conversions::registerConverterName(converter, "QTextStreamManipulator*");
    Shiboken::Conversions::registerConverterName(converter, "QTextStreamManipulator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextStreamManipulator).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_COPY,
        is_QTextStreamManipulator_PythonToCpp_QTextStreamManipulator_COPY_Convertible);


}
