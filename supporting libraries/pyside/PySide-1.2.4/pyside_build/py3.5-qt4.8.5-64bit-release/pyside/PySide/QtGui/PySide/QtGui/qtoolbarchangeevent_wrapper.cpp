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

#include "qtoolbarchangeevent_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QToolBarChangeEventWrapper::QToolBarChangeEventWrapper(bool t) : QToolBarChangeEvent(t) {
    // ... middle
}

QToolBarChangeEventWrapper::~QToolBarChangeEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QToolBarChangeEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QToolBarChangeEvent >()))
        return -1;

    ::QToolBarChangeEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QToolBarChangeEvent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QToolBarChangeEvent(bool)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // QToolBarChangeEvent(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QToolBarChangeEvent_Init_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QToolBarChangeEvent(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QToolBarChangeEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QToolBarChangeEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QToolBarChangeEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QToolBarChangeEvent_Init_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QToolBarChangeEvent", overloads);
        return -1;
}

static PyObject* Sbk_QToolBarChangeEventFunc_toggle(PyObject* self)
{
    ::QToolBarChangeEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QToolBarChangeEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOOLBARCHANGEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toggle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QToolBarChangeEvent*>(cppSelf)->toggle();
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

static PyMethodDef Sbk_QToolBarChangeEvent_methods[] = {
    {"toggle", (PyCFunction)Sbk_QToolBarChangeEventFunc_toggle, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QToolBarChangeEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QToolBarChangeEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QToolBarChangeEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QToolBarChangeEvent",
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
    /*tp_traverse*/         Sbk_QToolBarChangeEvent_traverse,
    /*tp_clear*/            Sbk_QToolBarChangeEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QToolBarChangeEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QToolBarChangeEvent_Init,
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

static void* Sbk_QToolBarChangeEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QToolBarChangeEvent*>(cptr)->type() == QEvent::ToolBarChange)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QToolBarChangeEvent_PythonToCpp_QToolBarChangeEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QToolBarChangeEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QToolBarChangeEvent_PythonToCpp_QToolBarChangeEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QToolBarChangeEvent_Type))
        return QToolBarChangeEvent_PythonToCpp_QToolBarChangeEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QToolBarChangeEvent_PTR_CppToPython_QToolBarChangeEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QToolBarChangeEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QToolBarChangeEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QToolBarChangeEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTOOLBARCHANGEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QToolBarChangeEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QToolBarChangeEvent", "QToolBarChangeEvent*",
        &Sbk_QToolBarChangeEvent_Type, &Shiboken::callCppDestructor< ::QToolBarChangeEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QToolBarChangeEvent_Type,
        QToolBarChangeEvent_PythonToCpp_QToolBarChangeEvent_PTR,
        is_QToolBarChangeEvent_PythonToCpp_QToolBarChangeEvent_PTR_Convertible,
        QToolBarChangeEvent_PTR_CppToPython_QToolBarChangeEvent);

    Shiboken::Conversions::registerConverterName(converter, "QToolBarChangeEvent");
    Shiboken::Conversions::registerConverterName(converter, "QToolBarChangeEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QToolBarChangeEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QToolBarChangeEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QToolBarChangeEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QToolBarChangeEvent_Type, &Sbk_QToolBarChangeEvent_typeDiscovery);


}
