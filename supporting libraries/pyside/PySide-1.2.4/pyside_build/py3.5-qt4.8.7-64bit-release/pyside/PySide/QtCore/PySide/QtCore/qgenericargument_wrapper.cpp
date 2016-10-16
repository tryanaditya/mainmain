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

#include "qgenericargument_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGenericArgument_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGenericArgument >()))
        return -1;

    ::QGenericArgument* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericArgument(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QGenericArgument", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGenericArgument(QGenericArgument)
    // 1: QGenericArgument(const char*,const void*)
    if (numArgs == 0) {
        overloadId = 1; // QGenericArgument(const char*,const void*)
    } else if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QGenericArgument(const char*,const void*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1])))) {
            overloadId = 1; // QGenericArgument(const char*,const void*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGenericArgument(QGenericArgument)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGenericArgument_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGenericArgument(const QGenericArgument & QGenericArgument)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGenericArgument cppArg0_local = ::QGenericArgument(((char*)0), ((void*)0));
            ::QGenericArgument* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QGenericArgument(QGenericArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGenericArgument(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGenericArgument(const char * aName, const void * aData)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aName");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericArgument(): got multiple values for keyword argument 'aName'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0]))))
                        goto Sbk_QGenericArgument_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "aData");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericArgument(): got multiple values for keyword argument 'aData'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1]))))
                        goto Sbk_QGenericArgument_Init_TypeError;
                }
            }
            const char* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            void* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGenericArgument(const char*,const void*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGenericArgument(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGenericArgument >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGenericArgument_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGenericArgument_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QGenericArgument", "" SBK_STR_NAME " = None, void = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QGenericArgument", overloads);
        return -1;
}

static PyObject* Sbk_QGenericArgumentFunc_data(PyObject* self)
{
    ::QGenericArgument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGenericArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = const_cast<const ::QGenericArgument*>(cppSelf)->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGenericArgumentFunc_name(PyObject* self)
{
    ::QGenericArgument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGenericArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QGenericArgument*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGenericArgument___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGenericArgument& cppSelf = *(((::QGenericArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGenericArgument_methods[] = {
    {"data", (PyCFunction)Sbk_QGenericArgumentFunc_data, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QGenericArgumentFunc_name, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QGenericArgument___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGenericArgument_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGenericArgument_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGenericArgument_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QGenericArgument",
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
    /*tp_traverse*/         Sbk_QGenericArgument_traverse,
    /*tp_clear*/            Sbk_QGenericArgument_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGenericArgument_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGenericArgument_Init,
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
static void QGenericArgument_PythonToCpp_QGenericArgument_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGenericArgument_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGenericArgument_PythonToCpp_QGenericArgument_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGenericArgument_Type))
        return QGenericArgument_PythonToCpp_QGenericArgument_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGenericArgument_PTR_CppToPython_QGenericArgument(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGenericArgument*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGenericArgument_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGenericArgument_COPY_CppToPython_QGenericArgument(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGenericArgument_Type, new ::QGenericArgument(*((::QGenericArgument*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGenericArgument_PythonToCpp_QGenericArgument_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGenericArgument*)cppOut) = *((::QGenericArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGenericArgument_PythonToCpp_QGenericArgument_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGenericArgument_Type))
        return QGenericArgument_PythonToCpp_QGenericArgument_COPY;
    return 0;
}

void init_QGenericArgument(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGenericArgument_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGenericArgument", "QGenericArgument",
        &Sbk_QGenericArgument_Type, &Shiboken::callCppDestructor< ::QGenericArgument >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGenericArgument_Type,
        QGenericArgument_PythonToCpp_QGenericArgument_PTR,
        is_QGenericArgument_PythonToCpp_QGenericArgument_PTR_Convertible,
        QGenericArgument_PTR_CppToPython_QGenericArgument,
        QGenericArgument_COPY_CppToPython_QGenericArgument);

    Shiboken::Conversions::registerConverterName(converter, "QGenericArgument");
    Shiboken::Conversions::registerConverterName(converter, "QGenericArgument*");
    Shiboken::Conversions::registerConverterName(converter, "QGenericArgument&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGenericArgument).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGenericArgument_PythonToCpp_QGenericArgument_COPY,
        is_QGenericArgument_PythonToCpp_QGenericArgument_COPY_Convertible);


}
