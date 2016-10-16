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

#include "qactionevent_wrapper.h"

// Extra includes
#include <qaction.h>


// Native ---------------------------------------------------------

QActionEventWrapper::QActionEventWrapper(int type, QAction * action, QAction * before) : QActionEvent(type, action, before) {
    // ... middle
}

QActionEventWrapper::~QActionEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QActionEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QActionEvent >()))
        return -1;

    ::QActionEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QActionEvent(): too many arguments");
        return -1;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QActionEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QActionEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QActionEvent(int,QAction*,QAction*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // QActionEvent(int,QAction*,QAction*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyArgs[2])))) {
            overloadId = 0; // QActionEvent(int,QAction*,QAction*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "before");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QActionEvent(): got multiple values for keyword argument 'before'.");
                return -1;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (pyArgs[2]))))
                    goto Sbk_QActionEvent_Init_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QAction* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return -1;
        ::QAction* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // QActionEvent(int,QAction*,QAction*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QActionEventWrapper(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QActionEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QActionEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QActionEvent_Init_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QAction, PySide.QtGui.QAction = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QActionEvent", overloads);
        return -1;
}

static PyObject* Sbk_QActionEventFunc_action(PyObject* self)
{
    ::QActionEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QActionEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // action()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction * cppResult = const_cast<const ::QActionEvent*>(cppSelf)->action();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionEventFunc_before(PyObject* self)
{
    ::QActionEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QActionEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // before()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction * cppResult = const_cast<const ::QActionEvent*>(cppSelf)->before();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QActionEvent_methods[] = {
    {"action", (PyCFunction)Sbk_QActionEventFunc_action, METH_NOARGS},
    {"before", (PyCFunction)Sbk_QActionEventFunc_before, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QActionEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QActionEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QActionEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QActionEvent",
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
    /*tp_traverse*/         Sbk_QActionEvent_traverse,
    /*tp_clear*/            Sbk_QActionEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QActionEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QActionEvent_Init,
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

static void* Sbk_QActionEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QActionEvent*>(cptr)->type() == QEvent::ActionAdded ||  reinterpret_cast< ::QActionEvent*>(cptr)->type() == QEvent::ActionRemoved ||  reinterpret_cast< ::QActionEvent*>(cptr)->type() == QEvent::ActionChanged)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QActionEvent_PythonToCpp_QActionEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QActionEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QActionEvent_PythonToCpp_QActionEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QActionEvent_Type))
        return QActionEvent_PythonToCpp_QActionEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QActionEvent_PTR_CppToPython_QActionEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QActionEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QActionEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QActionEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QActionEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QActionEvent", "QActionEvent*",
        &Sbk_QActionEvent_Type, &Shiboken::callCppDestructor< ::QActionEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QActionEvent_Type,
        QActionEvent_PythonToCpp_QActionEvent_PTR,
        is_QActionEvent_PythonToCpp_QActionEvent_PTR_Convertible,
        QActionEvent_PTR_CppToPython_QActionEvent);

    Shiboken::Conversions::registerConverterName(converter, "QActionEvent");
    Shiboken::Conversions::registerConverterName(converter, "QActionEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QActionEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QActionEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QActionEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QActionEvent_Type, &Sbk_QActionEvent_typeDiscovery);


}
