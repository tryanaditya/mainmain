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

#include "qinputevent_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QInputEventWrapper::QInputEventWrapper(QEvent::Type type, QFlags<Qt::KeyboardModifier> modifiers) : QInputEvent(type, modifiers) {
    // ... middle
}

QInputEventWrapper::~QInputEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QInputEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QInputEvent >()))
        return -1;

    ::QInputEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputEvent(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QInputEvent", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QInputEvent(QEvent::Type,QFlags<Qt::KeyboardModifier>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QInputEvent(QEvent::Type,QFlags<Qt::KeyboardModifier>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[1])))) {
            overloadId = 0; // QInputEvent(QEvent::Type,QFlags<Qt::KeyboardModifier>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QInputEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "modifiers");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputEvent(): got multiple values for keyword argument 'modifiers'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[1]))))
                    goto Sbk_QInputEvent_Init_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::KeyboardModifier> cppArg1 = Qt::NoModifier;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QInputEvent(QEvent::Type,QFlags<Qt::KeyboardModifier>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QInputEventWrapper(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QInputEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QInputEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QInputEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QInputEvent", overloads);
        return -1;
}

static PyObject* Sbk_QInputEventFunc_modifiers(PyObject* self)
{
    ::QInputEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QInputEvent*>(cppSelf)->modifiers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QInputEventFunc_setModifiers(PyObject* self, PyObject* pyArg)
{
    ::QInputEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModifiers(QFlags<Qt::KeyboardModifier>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArg)))) {
        overloadId = 0; // setModifiers(QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QInputEventFunc_setModifiers_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::KeyboardModifier> cppArg0 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModifiers(QFlags<Qt::KeyboardModifier>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModifiers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QInputEventFunc_setModifiers_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QInputEvent.setModifiers", overloads);
        return 0;
}

static PyMethodDef Sbk_QInputEvent_methods[] = {
    {"modifiers", (PyCFunction)Sbk_QInputEventFunc_modifiers, METH_NOARGS},
    {"setModifiers", (PyCFunction)Sbk_QInputEventFunc_setModifiers, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QInputEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QInputEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QInputEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QInputEvent",
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
    /*tp_traverse*/         Sbk_QInputEvent_traverse,
    /*tp_clear*/            Sbk_QInputEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QInputEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QInputEvent_Init,
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

static void* Sbk_QInputEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QEvent >()))
        return dynamic_cast< ::QInputEvent*>(reinterpret_cast< ::QEvent*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QInputEvent_PythonToCpp_QInputEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QInputEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QInputEvent_PythonToCpp_QInputEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QInputEvent_Type))
        return QInputEvent_PythonToCpp_QInputEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QInputEvent_PTR_CppToPython_QInputEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QInputEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QInputEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QInputEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QInputEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QInputEvent", "QInputEvent*",
        &Sbk_QInputEvent_Type, &Shiboken::callCppDestructor< ::QInputEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QInputEvent_Type,
        QInputEvent_PythonToCpp_QInputEvent_PTR,
        is_QInputEvent_PythonToCpp_QInputEvent_PTR_Convertible,
        QInputEvent_PTR_CppToPython_QInputEvent);

    Shiboken::Conversions::registerConverterName(converter, "QInputEvent");
    Shiboken::Conversions::registerConverterName(converter, "QInputEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QInputEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QInputEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QInputEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QInputEvent_Type, &Sbk_QInputEvent_typeDiscovery);


}
