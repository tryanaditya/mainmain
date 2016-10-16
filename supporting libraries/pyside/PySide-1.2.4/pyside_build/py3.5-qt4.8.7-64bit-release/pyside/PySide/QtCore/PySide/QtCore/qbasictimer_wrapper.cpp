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

#include "qbasictimer_wrapper.h"

// Extra includes
#include <qobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QBasicTimer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QBasicTimer >()))
        return -1;

    ::QBasicTimer* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QBasicTimer", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QBasicTimer()
    // 1: QBasicTimer(QBasicTimer)
    if (numArgs == 0) {
        overloadId = 0; // QBasicTimer()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QBasicTimer(QBasicTimer)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBasicTimer_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QBasicTimer()
        {

            if (!PyErr_Occurred()) {
                // QBasicTimer()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBasicTimer();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QBasicTimer(const QBasicTimer & QBasicTimer)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QBasicTimer cppArg0_local = ::QBasicTimer();
            ::QBasicTimer* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBasicTimer(QBasicTimer)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBasicTimer(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QBasicTimer >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QBasicTimer_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QBasicTimer_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QBasicTimer", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBasicTimer", overloads);
        return -1;
}

static PyObject* Sbk_QBasicTimerFunc_isActive(PyObject* self)
{
    ::QBasicTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBasicTimer*>(cppSelf)->isActive();
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

static PyObject* Sbk_QBasicTimerFunc_start(PyObject* self, PyObject* args)
{
    ::QBasicTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "start", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: start(int,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // start(int,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBasicTimerFunc_start_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // start(int,QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBasicTimerFunc_start_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBasicTimer.start", overloads);
        return 0;
}

static PyObject* Sbk_QBasicTimerFunc_stop(PyObject* self)
{
    ::QBasicTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QBasicTimerFunc_timerId(PyObject* self)
{
    ::QBasicTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timerId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QBasicTimer*>(cppSelf)->timerId();
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

static PyObject* Sbk_QBasicTimer___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBasicTimer& cppSelf = *(((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QBasicTimer_methods[] = {
    {"isActive", (PyCFunction)Sbk_QBasicTimerFunc_isActive, METH_NOARGS},
    {"start", (PyCFunction)Sbk_QBasicTimerFunc_start, METH_VARARGS},
    {"stop", (PyCFunction)Sbk_QBasicTimerFunc_stop, METH_NOARGS},
    {"timerId", (PyCFunction)Sbk_QBasicTimerFunc_timerId, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QBasicTimer___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QBasicTimer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QBasicTimer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QBasicTimer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QBasicTimer",
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
    /*tp_traverse*/         Sbk_QBasicTimer_traverse,
    /*tp_clear*/            Sbk_QBasicTimer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QBasicTimer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QBasicTimer_Init,
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
static void QBasicTimer_PythonToCpp_QBasicTimer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QBasicTimer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QBasicTimer_PythonToCpp_QBasicTimer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBasicTimer_Type))
        return QBasicTimer_PythonToCpp_QBasicTimer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QBasicTimer_PTR_CppToPython_QBasicTimer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QBasicTimer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QBasicTimer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QBasicTimer_COPY_CppToPython_QBasicTimer(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QBasicTimer_Type, new ::QBasicTimer(*((::QBasicTimer*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QBasicTimer_PythonToCpp_QBasicTimer_COPY(PyObject* pyIn, void* cppOut) {
    *((::QBasicTimer*)cppOut) = *((::QBasicTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QBasicTimer_PythonToCpp_QBasicTimer_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBasicTimer_Type))
        return QBasicTimer_PythonToCpp_QBasicTimer_COPY;
    return 0;
}

void init_QBasicTimer(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QBASICTIMER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QBasicTimer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QBasicTimer", "QBasicTimer",
        &Sbk_QBasicTimer_Type, &Shiboken::callCppDestructor< ::QBasicTimer >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QBasicTimer_Type,
        QBasicTimer_PythonToCpp_QBasicTimer_PTR,
        is_QBasicTimer_PythonToCpp_QBasicTimer_PTR_Convertible,
        QBasicTimer_PTR_CppToPython_QBasicTimer,
        QBasicTimer_COPY_CppToPython_QBasicTimer);

    Shiboken::Conversions::registerConverterName(converter, "QBasicTimer");
    Shiboken::Conversions::registerConverterName(converter, "QBasicTimer*");
    Shiboken::Conversions::registerConverterName(converter, "QBasicTimer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBasicTimer).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QBasicTimer_PythonToCpp_QBasicTimer_COPY,
        is_QBasicTimer_PythonToCpp_QBasicTimer_COPY_Convertible);


    qRegisterMetaType< ::QBasicTimer >("QBasicTimer");
}
