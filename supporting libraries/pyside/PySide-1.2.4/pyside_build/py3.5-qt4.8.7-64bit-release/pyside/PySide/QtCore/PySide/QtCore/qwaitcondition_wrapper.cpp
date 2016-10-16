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

#include "qwaitcondition_wrapper.h"

// Extra includes
#include <qmutex.h>
#include <qreadwritelock.h>
#include <qwaitcondition.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWaitCondition_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWaitCondition >()))
        return -1;

    ::QWaitCondition* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QWaitCondition()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QWaitCondition();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWaitCondition >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QWaitConditionFunc_wait(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWaitCondition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWaitCondition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QWAITCONDITION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QWaitCondition.wait(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QWaitCondition.wait(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:wait", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: wait(QMutex*,ulong)
    // 1: wait(QReadWriteLock*,ulong)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREADWRITELOCK_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // wait(QReadWriteLock*,ulong)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1])))) {
            overloadId = 1; // wait(QReadWriteLock*,ulong)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMUTEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // wait(QMutex*,ulong)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1])))) {
            overloadId = 0; // wait(QMutex*,ulong)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWaitConditionFunc_wait_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // wait(QMutex * mutex, unsigned long time)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "time");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QWaitCondition.wait(): got multiple values for keyword argument 'time'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1]))))
                        goto Sbk_QWaitConditionFunc_wait_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMutex* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            unsigned long cppArg1 = 4294967295UL;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // wait(QMutex*,ulong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->wait(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // wait(QReadWriteLock * readWriteLock, unsigned long time)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "time");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QWaitCondition.wait(): got multiple values for keyword argument 'time'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1]))))
                        goto Sbk_QWaitConditionFunc_wait_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QReadWriteLock* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            unsigned long cppArg1 = 4294967295UL;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // wait(QReadWriteLock*,ulong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->wait(cppArg0, cppArg1);
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

    Sbk_QWaitConditionFunc_wait_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMutex, unsigned long = 4294967295UL", "PySide.QtCore.QReadWriteLock, unsigned long = 4294967295UL", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QWaitCondition.wait", overloads);
        return 0;
}

static PyObject* Sbk_QWaitConditionFunc_wakeAll(PyObject* self)
{
    ::QWaitCondition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWaitCondition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QWAITCONDITION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wakeAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->wakeAll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWaitConditionFunc_wakeOne(PyObject* self)
{
    ::QWaitCondition* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWaitCondition*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QWAITCONDITION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wakeOne()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->wakeOne();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QWaitCondition_methods[] = {
    {"wait", (PyCFunction)Sbk_QWaitConditionFunc_wait, METH_VARARGS|METH_KEYWORDS},
    {"wakeAll", (PyCFunction)Sbk_QWaitConditionFunc_wakeAll, METH_NOARGS},
    {"wakeOne", (PyCFunction)Sbk_QWaitConditionFunc_wakeOne, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWaitCondition_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWaitCondition_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWaitCondition_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QWaitCondition",
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
    /*tp_traverse*/         Sbk_QWaitCondition_traverse,
    /*tp_clear*/            Sbk_QWaitCondition_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWaitCondition_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWaitCondition_Init,
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
static void QWaitCondition_PythonToCpp_QWaitCondition_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWaitCondition_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWaitCondition_PythonToCpp_QWaitCondition_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWaitCondition_Type))
        return QWaitCondition_PythonToCpp_QWaitCondition_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWaitCondition_PTR_CppToPython_QWaitCondition(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWaitCondition*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWaitCondition_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QWaitCondition(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QWAITCONDITION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWaitCondition_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWaitCondition", "QWaitCondition*",
        &Sbk_QWaitCondition_Type, &Shiboken::callCppDestructor< ::QWaitCondition >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWaitCondition_Type,
        QWaitCondition_PythonToCpp_QWaitCondition_PTR,
        is_QWaitCondition_PythonToCpp_QWaitCondition_PTR_Convertible,
        QWaitCondition_PTR_CppToPython_QWaitCondition);

    Shiboken::Conversions::registerConverterName(converter, "QWaitCondition");
    Shiboken::Conversions::registerConverterName(converter, "QWaitCondition*");
    Shiboken::Conversions::registerConverterName(converter, "QWaitCondition&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWaitCondition).name());



}
