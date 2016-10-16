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

#include "qsemaphore_wrapper.h"

// Extra includes
#include <qsemaphore.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSemaphore_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSemaphore >()))
        return -1;

    ::QSemaphore* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QSemaphore", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSemaphore(int)
    if (numArgs == 0) {
        overloadId = 0; // QSemaphore(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // QSemaphore(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSemaphore_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore(): got multiple values for keyword argument 'n'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSemaphore_Init_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QSemaphore(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSemaphore(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSemaphore >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSemaphore_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSemaphore_Init_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSemaphore", overloads);
        return -1;
}

static PyObject* Sbk_QSemaphoreFunc_acquire(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSEMAPHORE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.acquire(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:acquire", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: acquire(int)
    if (numArgs == 0) {
        overloadId = 0; // acquire(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // acquire(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSemaphoreFunc_acquire_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.acquire(): got multiple values for keyword argument 'n'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSemaphoreFunc_acquire_TypeError;
            }
        }
        int cppArg0 = 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // acquire(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->acquire(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSemaphoreFunc_acquire_TypeError:
        const char* overloads[] = {"int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSemaphore.acquire", overloads);
        return 0;
}

static PyObject* Sbk_QSemaphoreFunc_available(PyObject* self)
{
    ::QSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // available()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSemaphore*>(cppSelf)->available();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSemaphoreFunc_release(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSEMAPHORE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.release(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:release", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: release(int)
    if (numArgs == 0) {
        overloadId = 0; // release(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // release(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSemaphoreFunc_release_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.release(): got multiple values for keyword argument 'n'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSemaphoreFunc_release_TypeError;
            }
        }
        int cppArg0 = 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // release(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->release(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSemaphoreFunc_release_TypeError:
        const char* overloads[] = {"int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSemaphore.release", overloads);
        return 0;
}

static PyObject* Sbk_QSemaphoreFunc_tryAcquire(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.tryAcquire(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:tryAcquire", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: tryAcquire(int)
    // 1: tryAcquire(int,int)
    if (numArgs == 0) {
        overloadId = 0; // tryAcquire(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // tryAcquire(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // tryAcquire(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSemaphoreFunc_tryAcquire_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // tryAcquire(int n)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "n");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSemaphore.tryAcquire(): got multiple values for keyword argument 'n'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QSemaphoreFunc_tryAcquire_TypeError;
                }
            }
            int cppArg0 = 1;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // tryAcquire(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->tryAcquire(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // tryAcquire(int n, int timeout)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // tryAcquire(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->tryAcquire(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSemaphoreFunc_tryAcquire_TypeError:
        const char* overloads[] = {"int = 1", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSemaphore.tryAcquire", overloads);
        return 0;
}

static PyMethodDef Sbk_QSemaphore_methods[] = {
    {"acquire", (PyCFunction)Sbk_QSemaphoreFunc_acquire, METH_VARARGS|METH_KEYWORDS},
    {"available", (PyCFunction)Sbk_QSemaphoreFunc_available, METH_NOARGS},
    {"release", (PyCFunction)Sbk_QSemaphoreFunc_release, METH_VARARGS|METH_KEYWORDS},
    {"tryAcquire", (PyCFunction)Sbk_QSemaphoreFunc_tryAcquire, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSemaphore_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSemaphore_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSemaphore_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSemaphore",
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
    /*tp_traverse*/         Sbk_QSemaphore_traverse,
    /*tp_clear*/            Sbk_QSemaphore_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSemaphore_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSemaphore_Init,
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
static void QSemaphore_PythonToCpp_QSemaphore_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSemaphore_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSemaphore_PythonToCpp_QSemaphore_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSemaphore_Type))
        return QSemaphore_PythonToCpp_QSemaphore_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSemaphore_PTR_CppToPython_QSemaphore(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSemaphore*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSemaphore_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSemaphore(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSEMAPHORE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSemaphore_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSemaphore", "QSemaphore*",
        &Sbk_QSemaphore_Type, &Shiboken::callCppDestructor< ::QSemaphore >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSemaphore_Type,
        QSemaphore_PythonToCpp_QSemaphore_PTR,
        is_QSemaphore_PythonToCpp_QSemaphore_PTR_Convertible,
        QSemaphore_PTR_CppToPython_QSemaphore);

    Shiboken::Conversions::registerConverterName(converter, "QSemaphore");
    Shiboken::Conversions::registerConverterName(converter, "QSemaphore*");
    Shiboken::Conversions::registerConverterName(converter, "QSemaphore&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSemaphore).name());



}
