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

#include "qstatemachine_signalevent_wrapper.h"

// Extra includes
#include <QList>
#include <qobject.h>


// Native ---------------------------------------------------------

SignalEventWrapper::SignalEventWrapper(QObject * sender, int signalIndex, const QList<QVariant > & arguments) : QStateMachine::SignalEvent(sender, signalIndex, arguments) {
    // ... middle
}

SignalEventWrapper::~SignalEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStateMachine_SignalEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStateMachine::SignalEvent >()))
        return -1;

    ::SignalEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QStateMachine_SignalEvent_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "SignalEvent", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: SignalEvent(QObject*,int,QList<QVariant>)
    // 1: SignalEvent(QStateMachine::SignalEvent)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // SignalEvent(QStateMachine::SignalEvent)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], (pyArgs[2])))) {
        overloadId = 0; // SignalEvent(QObject*,int,QList<QVariant>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStateMachine_SignalEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // SignalEvent(QObject * sender, int signalIndex, const QList<QVariant > & arguments)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QList<QVariant > cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // SignalEvent(QObject*,int,QList<QVariant>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::SignalEventWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // SignalEvent(const QStateMachine::SignalEvent & SignalEvent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStateMachine::SignalEvent cppArg0_local = ::QStateMachine::SignalEvent(((::QObject*)0), ((int)0), ::QList<QVariant >());
            ::QStateMachine::SignalEvent* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // SignalEvent(QStateMachine::SignalEvent)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::SignalEventWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStateMachine::SignalEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStateMachine_SignalEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStateMachine_SignalEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, int, list", "PySide.QtCore.QStateMachine::SignalEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.SignalEvent", overloads);
        return -1;
}

static PyObject* Sbk_QStateMachine_SignalEventFunc_arguments(PyObject* self)
{
    ::QStateMachine::SignalEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine::SignalEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // arguments()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QVariant > cppResult = const_cast<const ::QStateMachine::SignalEvent*>(cppSelf)->arguments();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStateMachine_SignalEventFunc_sender(PyObject* self)
{
    ::QStateMachine::SignalEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine::SignalEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sender()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QStateMachine::SignalEvent*>(cppSelf)->sender();
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

static PyObject* Sbk_QStateMachine_SignalEventFunc_signalIndex(PyObject* self)
{
    ::QStateMachine::SignalEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStateMachine::SignalEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // signalIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStateMachine::SignalEvent*>(cppSelf)->signalIndex();
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

static PyObject* Sbk_QStateMachine_SignalEvent___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStateMachine::SignalEvent& cppSelf = *(((::QStateMachine::SignalEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStateMachine_SignalEvent_methods[] = {
    {"arguments", (PyCFunction)Sbk_QStateMachine_SignalEventFunc_arguments, METH_NOARGS},
    {"sender", (PyCFunction)Sbk_QStateMachine_SignalEventFunc_sender, METH_NOARGS},
    {"signalIndex", (PyCFunction)Sbk_QStateMachine_SignalEventFunc_signalIndex, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QStateMachine_SignalEvent___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QStateMachine_SignalEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStateMachine_SignalEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStateMachine_SignalEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QStateMachine.SignalEvent",
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
    /*tp_traverse*/         Sbk_QStateMachine_SignalEvent_traverse,
    /*tp_clear*/            Sbk_QStateMachine_SignalEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStateMachine_SignalEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStateMachine_SignalEvent_Init,
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

static void* Sbk_QStateMachine_SignalEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QEvent >()))
        return dynamic_cast< ::QStateMachine::SignalEvent*>(reinterpret_cast< ::QEvent*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SignalEvent_PythonToCpp_SignalEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStateMachine_SignalEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_SignalEvent_PythonToCpp_SignalEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStateMachine_SignalEvent_Type))
        return SignalEvent_PythonToCpp_SignalEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* SignalEvent_PTR_CppToPython_SignalEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStateMachine::SignalEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStateMachine_SignalEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* SignalEvent_COPY_CppToPython_SignalEvent(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStateMachine_SignalEvent_Type, new ::SignalEventWrapper(*((::QStateMachine::SignalEvent*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void SignalEvent_PythonToCpp_SignalEvent_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStateMachine::SignalEvent*)cppOut) = *((::QStateMachine::SignalEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_SignalEvent_PythonToCpp_SignalEvent_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStateMachine_SignalEvent_Type))
        return SignalEvent_PythonToCpp_SignalEvent_COPY;
    return 0;
}

void init_QStateMachine_SignalEvent(PyObject* enclosingClass)
{
    SbkPySide_QtCoreTypes[SBK_QSTATEMACHINE_SIGNALEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStateMachine_SignalEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "SignalEvent", "QStateMachine::SignalEvent",
        &Sbk_QStateMachine_SignalEvent_Type, &Shiboken::callCppDestructor< ::SignalEventWrapper >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStateMachine_SignalEvent_Type,
        SignalEvent_PythonToCpp_SignalEvent_PTR,
        is_SignalEvent_PythonToCpp_SignalEvent_PTR_Convertible,
        SignalEvent_PTR_CppToPython_SignalEvent,
        SignalEvent_COPY_CppToPython_SignalEvent);

    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::SignalEvent");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::SignalEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QStateMachine::SignalEvent&");
    Shiboken::Conversions::registerConverterName(converter, "SignalEvent");
    Shiboken::Conversions::registerConverterName(converter, "SignalEvent*");
    Shiboken::Conversions::registerConverterName(converter, "SignalEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStateMachine::SignalEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SignalEventWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        SignalEvent_PythonToCpp_SignalEvent_COPY,
        is_SignalEvent_PythonToCpp_SignalEvent_COPY_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QStateMachine_SignalEvent_Type, &Sbk_QStateMachine_SignalEvent_typeDiscovery);


}
