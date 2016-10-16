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
#include "pyside_qtgui_python.h"

#include "qmoveevent_wrapper.h"

// Extra includes
#include <qpoint.h>


// Native ---------------------------------------------------------

QMoveEventWrapper::QMoveEventWrapper(const QPoint & pos, const QPoint & oldPos) : QMoveEvent(pos, oldPos) {
    // ... middle
}

QMoveEventWrapper::~QMoveEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMoveEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMoveEvent >()))
        return -1;

    ::QMoveEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMoveEvent", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QMoveEvent(QPoint,QPoint)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
        overloadId = 0; // QMoveEvent(QPoint,QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMoveEvent_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QPoint cppArg1_local = ::QPoint();
        ::QPoint* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // QMoveEvent(QPoint,QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QMoveEventWrapper(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMoveEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMoveEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMoveEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMoveEvent", overloads);
        return -1;
}

static PyObject* Sbk_QMoveEventFunc_oldPos(PyObject* self)
{
    ::QMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // oldPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QMoveEvent*>(cppSelf)->oldPos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMoveEventFunc_pos(PyObject* self)
{
    ::QMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QMoveEvent*>(cppSelf)->pos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMoveEvent_methods[] = {
    {"oldPos", (PyCFunction)Sbk_QMoveEventFunc_oldPos, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QMoveEventFunc_pos, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMoveEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMoveEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMoveEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMoveEvent",
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
    /*tp_traverse*/         Sbk_QMoveEvent_traverse,
    /*tp_clear*/            Sbk_QMoveEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMoveEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMoveEvent_Init,
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

static void* Sbk_QMoveEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QMoveEvent*>(cptr)->type() == QEvent::Move)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMoveEvent_PythonToCpp_QMoveEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMoveEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMoveEvent_PythonToCpp_QMoveEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMoveEvent_Type))
        return QMoveEvent_PythonToCpp_QMoveEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMoveEvent_PTR_CppToPython_QMoveEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMoveEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMoveEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QMoveEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMoveEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMoveEvent", "QMoveEvent*",
        &Sbk_QMoveEvent_Type, &Shiboken::callCppDestructor< ::QMoveEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMoveEvent_Type,
        QMoveEvent_PythonToCpp_QMoveEvent_PTR,
        is_QMoveEvent_PythonToCpp_QMoveEvent_PTR_Convertible,
        QMoveEvent_PTR_CppToPython_QMoveEvent);

    Shiboken::Conversions::registerConverterName(converter, "QMoveEvent");
    Shiboken::Conversions::registerConverterName(converter, "QMoveEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QMoveEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMoveEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMoveEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QMoveEvent_Type, &Sbk_QMoveEvent_typeDiscovery);


}
