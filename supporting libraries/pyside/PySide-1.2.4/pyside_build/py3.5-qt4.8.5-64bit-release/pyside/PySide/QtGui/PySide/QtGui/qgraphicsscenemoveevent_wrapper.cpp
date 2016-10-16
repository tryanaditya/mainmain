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

#include "qgraphicsscenemoveevent_wrapper.h"

// Extra includes
#include <qgraphicssceneevent.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGraphicsSceneMoveEventWrapper::QGraphicsSceneMoveEventWrapper() : QGraphicsSceneMoveEvent() {
    // ... middle
}

QGraphicsSceneMoveEventWrapper::~QGraphicsSceneMoveEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsSceneMoveEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsSceneMoveEvent >()))
        return -1;

    ::QGraphicsSceneMoveEventWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QGraphicsSceneMoveEvent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsSceneMoveEventWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsSceneMoveEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QGraphicsSceneMoveEventFunc_newPos(PyObject* self)
{
    ::QGraphicsSceneMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOVEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMoveEvent*>(cppSelf)->newPos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneMoveEventFunc_oldPos(PyObject* self)
{
    ::QGraphicsSceneMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOVEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // oldPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMoveEvent*>(cppSelf)->oldPos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneMoveEventFunc_setNewPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOVEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNewPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setNewPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMoveEventFunc_setNewPos_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setNewPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNewPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMoveEventFunc_setNewPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMoveEvent.setNewPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMoveEventFunc_setOldPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOVEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOldPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setOldPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMoveEventFunc_setOldPos_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setOldPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOldPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMoveEventFunc_setOldPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMoveEvent.setOldPos", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsSceneMoveEvent_methods[] = {
    {"newPos", (PyCFunction)Sbk_QGraphicsSceneMoveEventFunc_newPos, METH_NOARGS},
    {"oldPos", (PyCFunction)Sbk_QGraphicsSceneMoveEventFunc_oldPos, METH_NOARGS},
    {"setNewPos", (PyCFunction)Sbk_QGraphicsSceneMoveEventFunc_setNewPos, METH_O},
    {"setOldPos", (PyCFunction)Sbk_QGraphicsSceneMoveEventFunc_setOldPos, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsSceneMoveEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsSceneMoveEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsSceneMoveEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsSceneMoveEvent",
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
    /*tp_traverse*/         Sbk_QGraphicsSceneMoveEvent_traverse,
    /*tp_clear*/            Sbk_QGraphicsSceneMoveEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsSceneMoveEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsSceneMoveEvent_Init,
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

static void* Sbk_QGraphicsSceneMoveEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QGraphicsSceneMoveEvent*>(cptr)->type() == QEvent::GraphicsSceneMove)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsSceneMoveEvent_PythonToCpp_QGraphicsSceneMoveEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsSceneMoveEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsSceneMoveEvent_PythonToCpp_QGraphicsSceneMoveEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsSceneMoveEvent_Type))
        return QGraphicsSceneMoveEvent_PythonToCpp_QGraphicsSceneMoveEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsSceneMoveEvent_PTR_CppToPython_QGraphicsSceneMoveEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsSceneMoveEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsSceneMoveEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsSceneMoveEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOVEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsSceneMoveEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsSceneMoveEvent", "QGraphicsSceneMoveEvent*",
        &Sbk_QGraphicsSceneMoveEvent_Type, &Shiboken::callCppDestructor< ::QGraphicsSceneMoveEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsSceneMoveEvent_Type,
        QGraphicsSceneMoveEvent_PythonToCpp_QGraphicsSceneMoveEvent_PTR,
        is_QGraphicsSceneMoveEvent_PythonToCpp_QGraphicsSceneMoveEvent_PTR_Convertible,
        QGraphicsSceneMoveEvent_PTR_CppToPython_QGraphicsSceneMoveEvent);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMoveEvent");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMoveEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMoveEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneMoveEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneMoveEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsSceneMoveEvent_Type, &Sbk_QGraphicsSceneMoveEvent_typeDiscovery);


}
