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

#include "qmutexlocker_wrapper.h"

// Extra includes
#include <qmutex.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMutexLocker_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMutexLocker >()))
        return -1;

    ::QMutexLocker* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMutexLocker", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMutexLocker(QMutex*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // QMutexLocker(QMutex*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMutexLocker_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QMutex* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QMutexLocker(QMutex*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QMutexLocker(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "mutex()const0", pyArgs[0]);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMutexLocker >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMutexLocker_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMutexLocker_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMutex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMutexLocker", overloads);
        return -1;
}

static PyObject* Sbk_QMutexLockerFunc___enter__(PyObject* self)
{
    ::QMutexLocker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutexLocker*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __enter__()
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMutexLockerFunc___exit__(PyObject* self, PyObject* args)
{
    ::QMutexLocker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutexLocker*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "__exit__", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: __exit__(PyObject*,PyObject*,PyObject*)
    if (numArgs == 3
        && PyObject_Check(pyArgs[0])
        && PyObject_Check(pyArgs[1])
        && PyObject_Check(pyArgs[2])) {
        overloadId = 0; // __exit__(PyObject*,PyObject*,PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMutexLockerFunc___exit___TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __exit__(PyObject*,PyObject*,PyObject*)
            // Begin code injection

            cppSelf->unlock();

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMutexLockerFunc___exit___TypeError:
        const char* overloads[] = {"object, object, object", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMutexLocker.__exit__", overloads);
        return 0;
}

static PyObject* Sbk_QMutexLockerFunc_mutex(PyObject* self)
{
    ::QMutexLocker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutexLocker*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mutex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMutex * cppResult = const_cast<const ::QMutexLocker*>(cppSelf)->mutex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], cppResult);
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "mutex()const0", pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMutexLockerFunc_relock(PyObject* self)
{
    ::QMutexLocker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutexLocker*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // relock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->relock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMutexLockerFunc_unlock(PyObject* self)
{
    ::QMutexLocker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMutexLocker*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX], (SbkObject*)self));

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

static PyMethodDef Sbk_QMutexLocker_methods[] = {
    {"__enter__", (PyCFunction)Sbk_QMutexLockerFunc___enter__, METH_NOARGS},
    {"__exit__", (PyCFunction)Sbk_QMutexLockerFunc___exit__, METH_VARARGS},
    {"mutex", (PyCFunction)Sbk_QMutexLockerFunc_mutex, METH_NOARGS},
    {"relock", (PyCFunction)Sbk_QMutexLockerFunc_relock, METH_NOARGS},
    {"unlock", (PyCFunction)Sbk_QMutexLockerFunc_unlock, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMutexLocker_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMutexLocker_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMutexLocker_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMutexLocker",
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
    /*tp_traverse*/         Sbk_QMutexLocker_traverse,
    /*tp_clear*/            Sbk_QMutexLocker_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMutexLocker_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMutexLocker_Init,
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
static void QMutexLocker_PythonToCpp_QMutexLocker_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMutexLocker_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMutexLocker_PythonToCpp_QMutexLocker_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMutexLocker_Type))
        return QMutexLocker_PythonToCpp_QMutexLocker_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMutexLocker_PTR_CppToPython_QMutexLocker(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMutexLocker*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMutexLocker_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QMutexLocker(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMUTEXLOCKER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMutexLocker_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMutexLocker", "QMutexLocker*",
        &Sbk_QMutexLocker_Type, &Shiboken::callCppDestructor< ::QMutexLocker >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMutexLocker_Type,
        QMutexLocker_PythonToCpp_QMutexLocker_PTR,
        is_QMutexLocker_PythonToCpp_QMutexLocker_PTR_Convertible,
        QMutexLocker_PTR_CppToPython_QMutexLocker);

    Shiboken::Conversions::registerConverterName(converter, "QMutexLocker");
    Shiboken::Conversions::registerConverterName(converter, "QMutexLocker*");
    Shiboken::Conversions::registerConverterName(converter, "QMutexLocker&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMutexLocker).name());



}
