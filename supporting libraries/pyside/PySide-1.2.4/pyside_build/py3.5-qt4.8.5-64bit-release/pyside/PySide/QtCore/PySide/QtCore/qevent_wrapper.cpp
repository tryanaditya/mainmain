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

#include "qevent_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QEventWrapper::QEventWrapper(QEvent::Type type) : QEvent(type) {
    // ... middle
}

QEventWrapper::~QEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QEvent >()))
        return -1;

    ::QEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QEvent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QEvent(QEvent::Type)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QEvent(QEvent::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEvent_Init_TypeError;

    // Call function/method
    {
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QEvent(QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEvent", overloads);
        return -1;
}

static PyObject* Sbk_QEventFunc_accept(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accept()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->accept();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QEventFunc_ignore(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ignore()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->ignore();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QEventFunc_isAccepted(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAccepted()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QEvent*>(cppSelf)->isAccepted();
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

static PyObject* Sbk_QEventFunc_registerEventType(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEvent.registerEventType(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:registerEventType", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: registerEventType(int)
    if (numArgs == 0) {
        overloadId = 0; // registerEventType(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // registerEventType(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventFunc_registerEventType_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "hint");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEvent.registerEventType(): got multiple values for keyword argument 'hint'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QEventFunc_registerEventType_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // registerEventType(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QEvent::registerEventType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QEventFunc_registerEventType_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEvent.registerEventType", overloads);
        return 0;
}

static PyObject* Sbk_QEventFunc_setAccepted(PyObject* self, PyObject* pyArg)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccepted(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAccepted(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEventFunc_setAccepted_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccepted(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccepted(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEventFunc_setAccepted_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEvent.setAccepted", overloads);
        return 0;
}

static PyObject* Sbk_QEventFunc_spontaneous(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spontaneous()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QEvent*>(cppSelf)->spontaneous();
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

static PyObject* Sbk_QEventFunc_type(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QEvent::Type cppResult = const_cast<const ::QEvent*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QEvent_methods[] = {
    {"accept", (PyCFunction)Sbk_QEventFunc_accept, METH_NOARGS},
    {"ignore", (PyCFunction)Sbk_QEventFunc_ignore, METH_NOARGS},
    {"isAccepted", (PyCFunction)Sbk_QEventFunc_isAccepted, METH_NOARGS},
    {"registerEventType", (PyCFunction)Sbk_QEventFunc_registerEventType, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setAccepted", (PyCFunction)Sbk_QEventFunc_setAccepted, METH_O},
    {"spontaneous", (PyCFunction)Sbk_QEventFunc_spontaneous, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QEventFunc_type, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QEvent__repr__(PyObject* self)
{
    ::QEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QEvent",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QEvent__repr__,
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
    /*tp_traverse*/         Sbk_QEvent_traverse,
    /*tp_clear*/            Sbk_QEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QEvent_Init,
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

// Python to C++ enum conversion.
static void QEvent_Type_PythonToCpp_QEvent_Type(PyObject* pyIn, void* cppOut) {
    *((::QEvent::Type*)cppOut) = (::QEvent::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QEvent_Type_PythonToCpp_QEvent_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]))
        return QEvent_Type_PythonToCpp_QEvent_Type;
    return 0;
}
static PyObject* QEvent_Type_CppToPython_QEvent_Type(const void* cppIn) {
    int castCppIn = *((::QEvent::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QEvent_PythonToCpp_QEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QEvent_PythonToCpp_QEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QEvent_Type))
        return QEvent_PythonToCpp_QEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QEvent_PTR_CppToPython_QEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QEvent(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QEvent", "QEvent*",
        &Sbk_QEvent_Type, &Shiboken::callCppDestructor< ::QEvent >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QEvent_Type,
        QEvent_PythonToCpp_QEvent_PTR,
        is_QEvent_PythonToCpp_QEvent_PTR_Convertible,
        QEvent_PTR_CppToPython_QEvent);

    Shiboken::Conversions::registerConverterName(converter, "QEvent");
    Shiboken::Conversions::registerConverterName(converter, "QEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QEventWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QEvent_Type,
        "Type",
        "PySide.QtCore.QEvent.Type",
        "QEvent::Type");
    if (!SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "None", (long) QEvent::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Timer", (long) QEvent::Timer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MouseButtonPress", (long) QEvent::MouseButtonPress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MouseButtonRelease", (long) QEvent::MouseButtonRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MouseButtonDblClick", (long) QEvent::MouseButtonDblClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MouseMove", (long) QEvent::MouseMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "KeyPress", (long) QEvent::KeyPress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "KeyRelease", (long) QEvent::KeyRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "FocusIn", (long) QEvent::FocusIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "FocusOut", (long) QEvent::FocusOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Enter", (long) QEvent::Enter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Leave", (long) QEvent::Leave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Paint", (long) QEvent::Paint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Move", (long) QEvent::Move))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Resize", (long) QEvent::Resize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Create", (long) QEvent::Create))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Destroy", (long) QEvent::Destroy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Show", (long) QEvent::Show))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Hide", (long) QEvent::Hide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Close", (long) QEvent::Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Quit", (long) QEvent::Quit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ParentChange", (long) QEvent::ParentChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ParentAboutToChange", (long) QEvent::ParentAboutToChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ThreadChange", (long) QEvent::ThreadChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowActivate", (long) QEvent::WindowActivate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowDeactivate", (long) QEvent::WindowDeactivate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ShowToParent", (long) QEvent::ShowToParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "HideToParent", (long) QEvent::HideToParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Wheel", (long) QEvent::Wheel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowTitleChange", (long) QEvent::WindowTitleChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowIconChange", (long) QEvent::WindowIconChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationWindowIconChange", (long) QEvent::ApplicationWindowIconChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationFontChange", (long) QEvent::ApplicationFontChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationLayoutDirectionChange", (long) QEvent::ApplicationLayoutDirectionChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationPaletteChange", (long) QEvent::ApplicationPaletteChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "PaletteChange", (long) QEvent::PaletteChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Clipboard", (long) QEvent::Clipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Speech", (long) QEvent::Speech))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MetaCall", (long) QEvent::MetaCall))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "SockAct", (long) QEvent::SockAct))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WinEventAct", (long) QEvent::WinEventAct))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DeferredDelete", (long) QEvent::DeferredDelete))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DragEnter", (long) QEvent::DragEnter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DragMove", (long) QEvent::DragMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DragLeave", (long) QEvent::DragLeave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Drop", (long) QEvent::Drop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DragResponse", (long) QEvent::DragResponse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ChildAdded", (long) QEvent::ChildAdded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ChildPolished", (long) QEvent::ChildPolished))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ChildRemoved", (long) QEvent::ChildRemoved))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ShowWindowRequest", (long) QEvent::ShowWindowRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "PolishRequest", (long) QEvent::PolishRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Polish", (long) QEvent::Polish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "LayoutRequest", (long) QEvent::LayoutRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "UpdateRequest", (long) QEvent::UpdateRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "UpdateLater", (long) QEvent::UpdateLater))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "EmbeddingControl", (long) QEvent::EmbeddingControl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ActivateControl", (long) QEvent::ActivateControl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DeactivateControl", (long) QEvent::DeactivateControl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ContextMenu", (long) QEvent::ContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "InputMethod", (long) QEvent::InputMethod))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "AccessibilityPrepare", (long) QEvent::AccessibilityPrepare))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TabletMove", (long) QEvent::TabletMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "LocaleChange", (long) QEvent::LocaleChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "LanguageChange", (long) QEvent::LanguageChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "LayoutDirectionChange", (long) QEvent::LayoutDirectionChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Style", (long) QEvent::Style))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TabletPress", (long) QEvent::TabletPress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TabletRelease", (long) QEvent::TabletRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "OkRequest", (long) QEvent::OkRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "HelpRequest", (long) QEvent::HelpRequest))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "IconDrag", (long) QEvent::IconDrag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "FontChange", (long) QEvent::FontChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "EnabledChange", (long) QEvent::EnabledChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ActivationChange", (long) QEvent::ActivationChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "StyleChange", (long) QEvent::StyleChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "IconTextChange", (long) QEvent::IconTextChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ModifiedChange", (long) QEvent::ModifiedChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MouseTrackingChange", (long) QEvent::MouseTrackingChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowBlocked", (long) QEvent::WindowBlocked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowUnblocked", (long) QEvent::WindowUnblocked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WindowStateChange", (long) QEvent::WindowStateChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ToolTip", (long) QEvent::ToolTip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WhatsThis", (long) QEvent::WhatsThis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "StatusTip", (long) QEvent::StatusTip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ActionChanged", (long) QEvent::ActionChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ActionAdded", (long) QEvent::ActionAdded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ActionRemoved", (long) QEvent::ActionRemoved))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "FileOpen", (long) QEvent::FileOpen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Shortcut", (long) QEvent::Shortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ShortcutOverride", (long) QEvent::ShortcutOverride))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WhatsThisClicked", (long) QEvent::WhatsThisClicked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ToolBarChange", (long) QEvent::ToolBarChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationActivate", (long) QEvent::ApplicationActivate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationActivated", (long) QEvent::ApplicationActivated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationDeactivate", (long) QEvent::ApplicationDeactivate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ApplicationDeactivated", (long) QEvent::ApplicationDeactivated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "QueryWhatsThis", (long) QEvent::QueryWhatsThis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "EnterWhatsThisMode", (long) QEvent::EnterWhatsThisMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "LeaveWhatsThisMode", (long) QEvent::LeaveWhatsThisMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ZOrderChange", (long) QEvent::ZOrderChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "HoverEnter", (long) QEvent::HoverEnter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "HoverLeave", (long) QEvent::HoverLeave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "HoverMove", (long) QEvent::HoverMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "AccessibilityHelp", (long) QEvent::AccessibilityHelp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "AccessibilityDescription", (long) QEvent::AccessibilityDescription))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "AcceptDropsChange", (long) QEvent::AcceptDropsChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MenubarUpdated", (long) QEvent::MenubarUpdated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ZeroTimerEvent", (long) QEvent::ZeroTimerEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneMouseMove", (long) QEvent::GraphicsSceneMouseMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneMousePress", (long) QEvent::GraphicsSceneMousePress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneMouseRelease", (long) QEvent::GraphicsSceneMouseRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneMouseDoubleClick", (long) QEvent::GraphicsSceneMouseDoubleClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneContextMenu", (long) QEvent::GraphicsSceneContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneHoverEnter", (long) QEvent::GraphicsSceneHoverEnter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneHoverMove", (long) QEvent::GraphicsSceneHoverMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneHoverLeave", (long) QEvent::GraphicsSceneHoverLeave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneHelp", (long) QEvent::GraphicsSceneHelp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneDragEnter", (long) QEvent::GraphicsSceneDragEnter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneDragMove", (long) QEvent::GraphicsSceneDragMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneDragLeave", (long) QEvent::GraphicsSceneDragLeave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneDrop", (long) QEvent::GraphicsSceneDrop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneWheel", (long) QEvent::GraphicsSceneWheel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "KeyboardLayoutChange", (long) QEvent::KeyboardLayoutChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "DynamicPropertyChange", (long) QEvent::DynamicPropertyChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TabletEnterProximity", (long) QEvent::TabletEnterProximity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TabletLeaveProximity", (long) QEvent::TabletLeaveProximity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NonClientAreaMouseMove", (long) QEvent::NonClientAreaMouseMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NonClientAreaMouseButtonPress", (long) QEvent::NonClientAreaMouseButtonPress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NonClientAreaMouseButtonRelease", (long) QEvent::NonClientAreaMouseButtonRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NonClientAreaMouseButtonDblClick", (long) QEvent::NonClientAreaMouseButtonDblClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MacSizeChange", (long) QEvent::MacSizeChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ContentsRectChange", (long) QEvent::ContentsRectChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MacGLWindowChange", (long) QEvent::MacGLWindowChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "FutureCallOut", (long) QEvent::FutureCallOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneResize", (long) QEvent::GraphicsSceneResize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GraphicsSceneMove", (long) QEvent::GraphicsSceneMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "CursorChange", (long) QEvent::CursorChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "ToolTipChange", (long) QEvent::ToolTipChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NetworkReplyUpdated", (long) QEvent::NetworkReplyUpdated))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GrabMouse", (long) QEvent::GrabMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "UngrabMouse", (long) QEvent::UngrabMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GrabKeyboard", (long) QEvent::GrabKeyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "UngrabKeyboard", (long) QEvent::UngrabKeyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MacGLClearDrawable", (long) QEvent::MacGLClearDrawable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "StateMachineSignal", (long) QEvent::StateMachineSignal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "StateMachineWrapped", (long) QEvent::StateMachineWrapped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TouchBegin", (long) QEvent::TouchBegin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TouchUpdate", (long) QEvent::TouchUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "TouchEnd", (long) QEvent::TouchEnd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "NativeGesture", (long) QEvent::NativeGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "RequestSoftwareInputPanel", (long) QEvent::RequestSoftwareInputPanel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "CloseSoftwareInputPanel", (long) QEvent::CloseSoftwareInputPanel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "UpdateSoftKeys", (long) QEvent::UpdateSoftKeys))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "WinIdChange", (long) QEvent::WinIdChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "Gesture", (long) QEvent::Gesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "GestureOverride", (long) QEvent::GestureOverride))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "PlatformPanel", (long) QEvent::PlatformPanel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "User", (long) QEvent::User))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
        &Sbk_QEvent_Type, "MaxUser", (long) QEvent::MaxUser))
        return ;
    // Register converter for enum 'QEvent::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX],
            QEvent_Type_CppToPython_QEvent_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QEvent_Type_PythonToCpp_QEvent_Type,
            is_QEvent_Type_PythonToCpp_QEvent_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QEvent::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


    qRegisterMetaType< ::QEvent::Type >("QEvent::Type");
}
