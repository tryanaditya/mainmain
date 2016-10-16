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

#include "qmutex_wrapper.h"

// Extra includes
#include <qmutex.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMutex_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMutex >()))
        return -1;

    ::QMutex* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMutex(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QMutex", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMutex(QMutex::RecursionMode)
    if (numArgs == 0) {
        overloadId = 0; // QMutex(QMutex::RecursionMode)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QMutex(QMutex::RecursionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMutex_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMutex(): got multiple values for keyword argument 'mode'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QMutex_Init_TypeError;
            }
        }
        ::QMutex::RecursionMode cppArg0 = QMutex::NonRecursive;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QMutex(QMutex::RecursionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QMutex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMutex >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMutex_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMutex_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMutex.RecursionMode = NonRecursive", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMutex", overloads);
        return -1;
}

static PyObject* Sbk_QMutexFunc_lock(PyObject* self)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->lock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMutexFunc_lockInline(PyObject* self)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lockInline()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->lockInline();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMutexFunc_tryLock(PyObject* self, PyObject* args)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "tryLock", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: tryLock()
    // 1: tryLock(int)
    if (numArgs == 0) {
        overloadId = 0; // tryLock()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // tryLock(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMutexFunc_tryLock_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // tryLock()
        {

            if (!PyErr_Occurred()) {
                // tryLock()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->tryLock();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // tryLock(int timeout)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // tryLock(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->tryLock(cppArg0);
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

    Sbk_QMutexFunc_tryLock_TypeError:
        const char* overloads[] = {"", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMutex.tryLock", overloads);
        return 0;
}

static PyObject* Sbk_QMutexFunc_tryLockInline(PyObject* self)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tryLockInline()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->tryLockInline();
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

static PyObject* Sbk_QMutexFunc_unlock(PyObject* self)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unlock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMutexFunc_unlockInline(PyObject* self)
{
    ::QMutex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unlockInline()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unlockInline();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QMutex_methods[] = {
    {"lock", (PyCFunction)Sbk_QMutexFunc_lock, METH_NOARGS},
    {"lockInline", (PyCFunction)Sbk_QMutexFunc_lockInline, METH_NOARGS},
    {"tryLock", (PyCFunction)Sbk_QMutexFunc_tryLock, METH_VARARGS},
    {"tryLockInline", (PyCFunction)Sbk_QMutexFunc_tryLockInline, METH_NOARGS},
    {"unlock", (PyCFunction)Sbk_QMutexFunc_unlock, METH_NOARGS},
    {"unlockInline", (PyCFunction)Sbk_QMutexFunc_unlockInline, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMutex_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMutex_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMutex_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMutex",
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
    /*tp_traverse*/         Sbk_QMutex_traverse,
    /*tp_clear*/            Sbk_QMutex_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMutex_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMutex_Init,
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
static void QMutex_RecursionMode_PythonToCpp_QMutex_RecursionMode(PyObject* pyIn, void* cppOut) {
    *((::QMutex::RecursionMode*)cppOut) = (::QMutex::RecursionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMutex_RecursionMode_PythonToCpp_QMutex_RecursionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX]))
        return QMutex_RecursionMode_PythonToCpp_QMutex_RecursionMode;
    return 0;
}
static PyObject* QMutex_RecursionMode_CppToPython_QMutex_RecursionMode(const void* cppIn) {
    int castCppIn = *((::QMutex::RecursionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMutex_PythonToCpp_QMutex_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMutex_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMutex_PythonToCpp_QMutex_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMutex_Type))
        return QMutex_PythonToCpp_QMutex_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMutex_PTR_CppToPython_QMutex(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMutex*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMutex_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QMutex(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMutex_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMutex", "QMutex*",
        &Sbk_QMutex_Type, &Shiboken::callCppDestructor< ::QMutex >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMutex_Type,
        QMutex_PythonToCpp_QMutex_PTR,
        is_QMutex_PythonToCpp_QMutex_PTR_Convertible,
        QMutex_PTR_CppToPython_QMutex);

    Shiboken::Conversions::registerConverterName(converter, "QMutex");
    Shiboken::Conversions::registerConverterName(converter, "QMutex*");
    Shiboken::Conversions::registerConverterName(converter, "QMutex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMutex).name());


    // Initialization of enums.

    // Initialization of enum 'RecursionMode'.
    SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMutex_Type,
        "RecursionMode",
        "PySide.QtCore.QMutex.RecursionMode",
        "QMutex::RecursionMode");
    if (!SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX],
        &Sbk_QMutex_Type, "NonRecursive", (long) QMutex::NonRecursive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX],
        &Sbk_QMutex_Type, "Recursive", (long) QMutex::Recursive))
        return ;
    // Register converter for enum 'QMutex::RecursionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX],
            QMutex_RecursionMode_CppToPython_QMutex_RecursionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMutex_RecursionMode_PythonToCpp_QMutex_RecursionMode,
            is_QMutex_RecursionMode_PythonToCpp_QMutex_RecursionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMUTEX_RECURSIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMutex::RecursionMode");
        Shiboken::Conversions::registerConverterName(converter, "RecursionMode");
    }
    // End of 'RecursionMode' enum.


    qRegisterMetaType< ::QMutex::RecursionMode >("QMutex::RecursionMode");
}
