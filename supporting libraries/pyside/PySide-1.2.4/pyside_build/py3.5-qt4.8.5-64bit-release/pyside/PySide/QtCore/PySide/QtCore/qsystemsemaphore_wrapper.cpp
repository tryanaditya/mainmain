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

#include "qsystemsemaphore_wrapper.h"

// Extra includes
#include <qsystemsemaphore.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSystemSemaphore_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSystemSemaphore >()))
        return -1;

    ::QSystemSemaphore* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QSystemSemaphore", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QSystemSemaphore(QString,int,QSystemSemaphore::AccessMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QSystemSemaphore(QString,int,QSystemSemaphore::AccessMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // QSystemSemaphore(QString,int,QSystemSemaphore::AccessMode)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // QSystemSemaphore(QString,int,QSystemSemaphore::AccessMode)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemSemaphore_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "initialValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore(): got multiple values for keyword argument 'initialValue'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QSystemSemaphore_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore(): got multiple values for keyword argument 'mode'.");
                return -1;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QSystemSemaphore_Init_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QSystemSemaphore::AccessMode cppArg2 = QSystemSemaphore::Open;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // QSystemSemaphore(QString,int,QSystemSemaphore::AccessMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSystemSemaphore(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSystemSemaphore >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSystemSemaphore_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSystemSemaphore_Init_TypeError:
        const char* overloads[] = {"unicode, int = 0, PySide.QtCore.QSystemSemaphore.AccessMode = Open", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSystemSemaphore", overloads);
        return -1;
}

static PyObject* Sbk_QSystemSemaphoreFunc_acquire(PyObject* self)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acquire()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->acquire();
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

static PyObject* Sbk_QSystemSemaphoreFunc_error(PyObject* self)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSystemSemaphore::SystemSemaphoreError cppResult = const_cast<const ::QSystemSemaphore*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSystemSemaphoreFunc_errorString(PyObject* self)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSystemSemaphore*>(cppSelf)->errorString();
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

static PyObject* Sbk_QSystemSemaphoreFunc_key(PyObject* self)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // key()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSystemSemaphore*>(cppSelf)->key();
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

static PyObject* Sbk_QSystemSemaphoreFunc_release(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.release(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QSystemSemaphoreFunc_release_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.release(): got multiple values for keyword argument 'n'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSystemSemaphoreFunc_release_TypeError;
            }
        }
        int cppArg0 = 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // release(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->release(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSystemSemaphoreFunc_release_TypeError:
        const char* overloads[] = {"int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSystemSemaphore.release", overloads);
        return 0;
}

static PyObject* Sbk_QSystemSemaphoreFunc_setKey(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSystemSemaphore* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemSemaphore*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.setKey(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.setKey(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setKey", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setKey(QString,int,QSystemSemaphore::AccessMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setKey(QString,int,QSystemSemaphore::AccessMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setKey(QString,int,QSystemSemaphore::AccessMode)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // setKey(QString,int,QSystemSemaphore::AccessMode)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemSemaphoreFunc_setKey_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "initialValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.setKey(): got multiple values for keyword argument 'initialValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QSystemSemaphoreFunc_setKey_TypeError;
            }
            value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSystemSemaphore.setKey(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QSystemSemaphoreFunc_setKey_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QSystemSemaphore::AccessMode cppArg2 = QSystemSemaphore::Open;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setKey(QString,int,QSystemSemaphore::AccessMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setKey(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSystemSemaphoreFunc_setKey_TypeError:
        const char* overloads[] = {"unicode, int = 0, PySide.QtCore.QSystemSemaphore.AccessMode = Open", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSystemSemaphore.setKey", overloads);
        return 0;
}

static PyMethodDef Sbk_QSystemSemaphore_methods[] = {
    {"acquire", (PyCFunction)Sbk_QSystemSemaphoreFunc_acquire, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QSystemSemaphoreFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QSystemSemaphoreFunc_errorString, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QSystemSemaphoreFunc_key, METH_NOARGS},
    {"release", (PyCFunction)Sbk_QSystemSemaphoreFunc_release, METH_VARARGS|METH_KEYWORDS},
    {"setKey", (PyCFunction)Sbk_QSystemSemaphoreFunc_setKey, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSystemSemaphore_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSystemSemaphore_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSystemSemaphore_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSystemSemaphore",
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
    /*tp_traverse*/         Sbk_QSystemSemaphore_traverse,
    /*tp_clear*/            Sbk_QSystemSemaphore_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSystemSemaphore_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSystemSemaphore_Init,
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
static void QSystemSemaphore_AccessMode_PythonToCpp_QSystemSemaphore_AccessMode(PyObject* pyIn, void* cppOut) {
    *((::QSystemSemaphore::AccessMode*)cppOut) = (::QSystemSemaphore::AccessMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSystemSemaphore_AccessMode_PythonToCpp_QSystemSemaphore_AccessMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX]))
        return QSystemSemaphore_AccessMode_PythonToCpp_QSystemSemaphore_AccessMode;
    return 0;
}
static PyObject* QSystemSemaphore_AccessMode_CppToPython_QSystemSemaphore_AccessMode(const void* cppIn) {
    int castCppIn = *((::QSystemSemaphore::AccessMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX], castCppIn);

}

static void QSystemSemaphore_SystemSemaphoreError_PythonToCpp_QSystemSemaphore_SystemSemaphoreError(PyObject* pyIn, void* cppOut) {
    *((::QSystemSemaphore::SystemSemaphoreError*)cppOut) = (::QSystemSemaphore::SystemSemaphoreError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSystemSemaphore_SystemSemaphoreError_PythonToCpp_QSystemSemaphore_SystemSemaphoreError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX]))
        return QSystemSemaphore_SystemSemaphoreError_PythonToCpp_QSystemSemaphore_SystemSemaphoreError;
    return 0;
}
static PyObject* QSystemSemaphore_SystemSemaphoreError_CppToPython_QSystemSemaphore_SystemSemaphoreError(const void* cppIn) {
    int castCppIn = *((::QSystemSemaphore::SystemSemaphoreError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSystemSemaphore_PythonToCpp_QSystemSemaphore_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSystemSemaphore_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSystemSemaphore_PythonToCpp_QSystemSemaphore_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSystemSemaphore_Type))
        return QSystemSemaphore_PythonToCpp_QSystemSemaphore_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSystemSemaphore_PTR_CppToPython_QSystemSemaphore(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSystemSemaphore*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSystemSemaphore_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSystemSemaphore(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSystemSemaphore_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSystemSemaphore", "QSystemSemaphore*",
        &Sbk_QSystemSemaphore_Type, &Shiboken::callCppDestructor< ::QSystemSemaphore >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSystemSemaphore_Type,
        QSystemSemaphore_PythonToCpp_QSystemSemaphore_PTR,
        is_QSystemSemaphore_PythonToCpp_QSystemSemaphore_PTR_Convertible,
        QSystemSemaphore_PTR_CppToPython_QSystemSemaphore);

    Shiboken::Conversions::registerConverterName(converter, "QSystemSemaphore");
    Shiboken::Conversions::registerConverterName(converter, "QSystemSemaphore*");
    Shiboken::Conversions::registerConverterName(converter, "QSystemSemaphore&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSystemSemaphore).name());


    // Initialization of enums.

    // Initialization of enum 'AccessMode'.
    SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSystemSemaphore_Type,
        "AccessMode",
        "PySide.QtCore.QSystemSemaphore.AccessMode",
        "QSystemSemaphore::AccessMode");
    if (!SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX],
        &Sbk_QSystemSemaphore_Type, "Open", (long) QSystemSemaphore::Open))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX],
        &Sbk_QSystemSemaphore_Type, "Create", (long) QSystemSemaphore::Create))
        return ;
    // Register converter for enum 'QSystemSemaphore::AccessMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX],
            QSystemSemaphore_AccessMode_CppToPython_QSystemSemaphore_AccessMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSystemSemaphore_AccessMode_PythonToCpp_QSystemSemaphore_AccessMode,
            is_QSystemSemaphore_AccessMode_PythonToCpp_QSystemSemaphore_AccessMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_ACCESSMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSystemSemaphore::AccessMode");
        Shiboken::Conversions::registerConverterName(converter, "AccessMode");
    }
    // End of 'AccessMode' enum.

    // Initialization of enum 'SystemSemaphoreError'.
    SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSystemSemaphore_Type,
        "SystemSemaphoreError",
        "PySide.QtCore.QSystemSemaphore.SystemSemaphoreError",
        "QSystemSemaphore::SystemSemaphoreError");
    if (!SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "NoError", (long) QSystemSemaphore::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "PermissionDenied", (long) QSystemSemaphore::PermissionDenied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "KeyError", (long) QSystemSemaphore::KeyError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "AlreadyExists", (long) QSystemSemaphore::AlreadyExists))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "NotFound", (long) QSystemSemaphore::NotFound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "OutOfResources", (long) QSystemSemaphore::OutOfResources))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
        &Sbk_QSystemSemaphore_Type, "UnknownError", (long) QSystemSemaphore::UnknownError))
        return ;
    // Register converter for enum 'QSystemSemaphore::SystemSemaphoreError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX],
            QSystemSemaphore_SystemSemaphoreError_CppToPython_QSystemSemaphore_SystemSemaphoreError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSystemSemaphore_SystemSemaphoreError_PythonToCpp_QSystemSemaphore_SystemSemaphoreError,
            is_QSystemSemaphore_SystemSemaphoreError_PythonToCpp_QSystemSemaphore_SystemSemaphoreError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMSEMAPHORE_SYSTEMSEMAPHOREERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSystemSemaphore::SystemSemaphoreError");
        Shiboken::Conversions::registerConverterName(converter, "SystemSemaphoreError");
    }
    // End of 'SystemSemaphoreError' enum.


    qRegisterMetaType< ::QSystemSemaphore::AccessMode >("QSystemSemaphore::AccessMode");
    qRegisterMetaType< ::QSystemSemaphore::SystemSemaphoreError >("QSystemSemaphore::SystemSemaphoreError");
}
