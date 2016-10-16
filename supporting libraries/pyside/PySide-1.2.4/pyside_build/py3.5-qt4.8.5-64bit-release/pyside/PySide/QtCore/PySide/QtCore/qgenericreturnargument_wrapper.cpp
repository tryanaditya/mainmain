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

#include "qgenericreturnargument_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGenericReturnArgument_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGenericReturnArgument >()))
        return -1;

    ::QGenericReturnArgument* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericReturnArgument(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QGenericReturnArgument", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGenericReturnArgument(QGenericReturnArgument)
    // 1: QGenericReturnArgument(const char*,void*)
    if (numArgs == 0) {
        overloadId = 1; // QGenericReturnArgument(const char*,void*)
    } else if (Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QGenericReturnArgument(const char*,void*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1])))) {
            overloadId = 1; // QGenericReturnArgument(const char*,void*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGenericReturnArgument(QGenericReturnArgument)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGenericReturnArgument_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGenericReturnArgument(const QGenericReturnArgument & QGenericReturnArgument)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGenericReturnArgument cppArg0_local = ::QGenericReturnArgument(((char*)0), ((void*)0));
            ::QGenericReturnArgument* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QGenericReturnArgument(QGenericReturnArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGenericReturnArgument(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGenericReturnArgument(const char * aName, void * aData)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aName");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericReturnArgument(): got multiple values for keyword argument 'aName'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0]))))
                        goto Sbk_QGenericReturnArgument_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "aData");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QGenericReturnArgument(): got multiple values for keyword argument 'aData'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1]))))
                        goto Sbk_QGenericReturnArgument_Init_TypeError;
                }
            }
            const char* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            void* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGenericReturnArgument(const char*,void*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGenericReturnArgument(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGenericReturnArgument >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGenericReturnArgument_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGenericReturnArgument_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QGenericReturnArgument", "" SBK_STR_NAME " = None, void = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QGenericReturnArgument", overloads);
        return -1;
}

static PyObject* Sbk_QGenericReturnArgument___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGenericReturnArgument& cppSelf = *(((::QGenericReturnArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGenericReturnArgument_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QGenericReturnArgument___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGenericReturnArgument_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGenericReturnArgument_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGenericReturnArgument_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QGenericReturnArgument",
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
    /*tp_traverse*/         Sbk_QGenericReturnArgument_traverse,
    /*tp_clear*/            Sbk_QGenericReturnArgument_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGenericReturnArgument_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGenericReturnArgument_Init,
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
static void QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGenericReturnArgument_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGenericReturnArgument_Type))
        return QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGenericReturnArgument_PTR_CppToPython_QGenericReturnArgument(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGenericReturnArgument*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGenericReturnArgument_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGenericReturnArgument_COPY_CppToPython_QGenericReturnArgument(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGenericReturnArgument_Type, new ::QGenericReturnArgument(*((::QGenericReturnArgument*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGenericReturnArgument*)cppOut) = *((::QGenericReturnArgument*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGenericReturnArgument_Type))
        return QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_COPY;
    return 0;
}

void init_QGenericReturnArgument(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGenericReturnArgument_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGenericReturnArgument", "QGenericReturnArgument",
        &Sbk_QGenericReturnArgument_Type, &Shiboken::callCppDestructor< ::QGenericReturnArgument >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGenericReturnArgument_Type,
        QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_PTR,
        is_QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_PTR_Convertible,
        QGenericReturnArgument_PTR_CppToPython_QGenericReturnArgument,
        QGenericReturnArgument_COPY_CppToPython_QGenericReturnArgument);

    Shiboken::Conversions::registerConverterName(converter, "QGenericReturnArgument");
    Shiboken::Conversions::registerConverterName(converter, "QGenericReturnArgument*");
    Shiboken::Conversions::registerConverterName(converter, "QGenericReturnArgument&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGenericReturnArgument).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_COPY,
        is_QGenericReturnArgument_PythonToCpp_QGenericReturnArgument_COPY_Convertible);


}
