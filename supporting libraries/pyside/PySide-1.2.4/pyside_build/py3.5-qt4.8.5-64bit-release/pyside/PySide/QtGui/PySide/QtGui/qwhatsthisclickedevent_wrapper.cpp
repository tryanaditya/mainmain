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

#include "qwhatsthisclickedevent_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QWhatsThisClickedEventWrapper::QWhatsThisClickedEventWrapper(const QString & href) : QWhatsThisClickedEvent(href) {
    // ... middle
}

QWhatsThisClickedEventWrapper::~QWhatsThisClickedEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWhatsThisClickedEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWhatsThisClickedEvent >()))
        return -1;

    ::QWhatsThisClickedEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWhatsThisClickedEvent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWhatsThisClickedEvent(QString)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // QWhatsThisClickedEvent(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWhatsThisClickedEvent_Init_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QWhatsThisClickedEvent(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QWhatsThisClickedEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWhatsThisClickedEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWhatsThisClickedEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWhatsThisClickedEvent_Init_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QWhatsThisClickedEvent", overloads);
        return -1;
}

static PyObject* Sbk_QWhatsThisClickedEventFunc_href(PyObject* self)
{
    ::QWhatsThisClickedEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWhatsThisClickedEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHATSTHISCLICKEDEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // href()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWhatsThisClickedEvent*>(cppSelf)->href();
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

static PyMethodDef Sbk_QWhatsThisClickedEvent_methods[] = {
    {"href", (PyCFunction)Sbk_QWhatsThisClickedEventFunc_href, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWhatsThisClickedEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWhatsThisClickedEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWhatsThisClickedEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QWhatsThisClickedEvent",
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
    /*tp_traverse*/         Sbk_QWhatsThisClickedEvent_traverse,
    /*tp_clear*/            Sbk_QWhatsThisClickedEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWhatsThisClickedEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWhatsThisClickedEvent_Init,
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

static void* Sbk_QWhatsThisClickedEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QWhatsThisClickedEvent*>(cptr)->type() == QEvent::WhatsThisClicked)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWhatsThisClickedEvent_PythonToCpp_QWhatsThisClickedEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWhatsThisClickedEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWhatsThisClickedEvent_PythonToCpp_QWhatsThisClickedEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWhatsThisClickedEvent_Type))
        return QWhatsThisClickedEvent_PythonToCpp_QWhatsThisClickedEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWhatsThisClickedEvent_PTR_CppToPython_QWhatsThisClickedEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWhatsThisClickedEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWhatsThisClickedEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QWhatsThisClickedEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QWHATSTHISCLICKEDEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWhatsThisClickedEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWhatsThisClickedEvent", "QWhatsThisClickedEvent*",
        &Sbk_QWhatsThisClickedEvent_Type, &Shiboken::callCppDestructor< ::QWhatsThisClickedEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWhatsThisClickedEvent_Type,
        QWhatsThisClickedEvent_PythonToCpp_QWhatsThisClickedEvent_PTR,
        is_QWhatsThisClickedEvent_PythonToCpp_QWhatsThisClickedEvent_PTR_Convertible,
        QWhatsThisClickedEvent_PTR_CppToPython_QWhatsThisClickedEvent);

    Shiboken::Conversions::registerConverterName(converter, "QWhatsThisClickedEvent");
    Shiboken::Conversions::registerConverterName(converter, "QWhatsThisClickedEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QWhatsThisClickedEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWhatsThisClickedEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWhatsThisClickedEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QWhatsThisClickedEvent_Type, &Sbk_QWhatsThisClickedEvent_typeDiscovery);


}
