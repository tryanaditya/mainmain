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

#include "qstatemachine_wrappedevent_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qobject.h>


// Native ---------------------------------------------------------

WrappedEventWrapper::WrappedEventWrapper(QObject * object, QEvent * event) : QStateMachine::WrappedEvent(object, event) {
    // ... middle
}

WrappedEventWrapper::~WrappedEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStateMachine_WrappedEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStateMachine::WrappedEvent >()))
        return -1;

    ::WrappedEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "WrappedEvent", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: WrappedEvent(QObject*,QEvent*)
    // 1: WrappedEvent(QStateMachine::WrappedEvent)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // WrappedEvent(QStateMachine::WrappedEvent)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // WrappedEvent(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachine_WrappedEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // WrappedEvent(QObject * object, QEvent * event)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QEvent* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // WrappedEvent(QObject*,QEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::WrappedEventWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // WrappedEvent(const QStateMachine::WrappedEvent & WrappedEvent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStateMachine::WrappedEvent cppArg0_local = ::QStateMachine::WrappedEvent(((::QObject*)0), ((::QEvent*)0));
            ::QStateMachine::WrappedEvent* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // WrappedEvent(QStateMachine::WrappedEvent)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::WrappedEventWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStateMachine::WrappedEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStateMachine_WrappedEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStateMachine_WrappedEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", "PySide.QtCore.QStateMachine::WrappedEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.WrappedEvent", overloads);
        return -1;
}

static PyObject* Sbk_QStateMachine_WrappedEventFunc_event(PyObject* self)
{
    ::QStateMachine::WrappedEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine::WrappedEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // event()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QEvent * cppResult = const_cast<const ::QStateMachine::WrappedEvent*>(cppSelf)->event();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachine_WrappedEventFunc_object(PyObject* self)
{
    ::QStateMachine::WrappedEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine::WrappedEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // object()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QStateMachine::WrappedEvent*>(cppSelf)->object();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachine_WrappedEvent___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStateMachine::WrappedEvent& cppSelf = *(((::QStateMachine::WrappedEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStateMachine_WrappedEvent_methods[] = {
    {"event", (PyCFunction)Sbk_QStateMachine_WrappedEventFunc_event, METH_NOARGS},
    {"object", (PyCFunction)Sbk_QStateMachine_WrappedEventFunc_object, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QStateMachine_WrappedEvent___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QStateMachine_WrappedEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStateMachine_WrappedEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStateMachine_WrappedEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QStateMachine.WrappedEvent",
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
    /*tp_traverse*/         Sbk_QStateMachine_WrappedEvent_traverse,
    /*tp_clear*/            Sbk_QStateMachine_WrappedEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStateMachine_WrappedEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStateMachine_WrappedEvent_Init,
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

static void* Sbk_QStateMachine_WrappedEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QEvent >()))
        return dynamic_cast< ::QStateMachine::WrappedEvent*>(reinterpret_cast< ::QEvent*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void WrappedEvent_PythonToCpp_WrappedEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStateMachine_WrappedEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_WrappedEvent_PythonToCpp_WrappedEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStateMachine_WrappedEvent_Type))
        return WrappedEvent_PythonToCpp_WrappedEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* WrappedEvent_PTR_CppToPython_WrappedEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStateMachine::WrappedEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStateMachine_WrappedEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* WrappedEvent_COPY_CppToPython_WrappedEvent(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStateMachine_WrappedEvent_Type, new ::WrappedEventWrapper(*((::QStateMachine::WrappedEvent*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void WrappedEvent_PythonToCpp_WrappedEvent_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStateMachine::WrappedEvent*)cppOut) = *((::QStateMachine::WrappedEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_WrappedEvent_PythonToCpp_WrappedEvent_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStateMachine_WrappedEvent_Type))
        return WrappedEvent_PythonToCpp_WrappedEvent_COPY;
    return 0;
}

void init_QStateMachine_WrappedEvent(PyObject* enclosingClass)
{
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_WRAPPEDEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStateMachine_WrappedEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "WrappedEvent", "QStateMachine::WrappedEvent",
        &Sbk_QStateMachine_WrappedEvent_Type, &Shiboken::callCppDestructor< ::WrappedEventWrapper >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStateMachine_WrappedEvent_Type,
        WrappedEvent_PythonToCpp_WrappedEvent_PTR,
        is_WrappedEvent_PythonToCpp_WrappedEvent_PTR_Convertible,
        WrappedEvent_PTR_CppToPython_WrappedEvent,
        WrappedEvent_COPY_CppToPython_WrappedEvent);

    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::WrappedEvent");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::WrappedEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::WrappedEvent&");
    Shiboken::Conversions::registerConverterName(converter, "WrappedEvent");
    Shiboken::Conversions::registerConverterName(converter, "WrappedEvent*");
    Shiboken::Conversions::registerConverterName(converter, "WrappedEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStateMachine::WrappedEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::WrappedEventWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        WrappedEvent_PythonToCpp_WrappedEvent_COPY,
        is_WrappedEvent_PythonToCpp_WrappedEvent_COPY_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QStateMachine_WrappedEvent_Type, &Sbk_QStateMachine_WrappedEvent_typeDiscovery);


}
