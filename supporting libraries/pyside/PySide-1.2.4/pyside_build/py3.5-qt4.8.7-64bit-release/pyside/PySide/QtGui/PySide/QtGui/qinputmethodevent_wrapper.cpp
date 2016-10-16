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

#include "qinputmethodevent_wrapper.h"
#include "qinputmethodevent_attribute_wrapper.h"

// Extra includes
#include <QInputMethodEvent>
#include <QList>
#include <qevent.h>


// Native ---------------------------------------------------------

QInputMethodEventWrapper::QInputMethodEventWrapper() : QInputMethodEvent() {
    // ... middle
}

QInputMethodEventWrapper::QInputMethodEventWrapper(const QString & preeditText, const QList<QInputMethodEvent::Attribute > & attributes) : QInputMethodEvent(preeditText, attributes) {
    // ... middle
}

QInputMethodEventWrapper::~QInputMethodEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QInputMethodEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QInputMethodEvent >()))
        return -1;

    ::QInputMethodEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QInputMethodEvent", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QInputMethodEvent()
    // 1: QInputMethodEvent(QInputMethodEvent)
    // 2: QInputMethodEvent(QString,QList<QInputMethodEvent::Attribute>)
    if (numArgs == 0) {
        overloadId = 0; // QInputMethodEvent()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (pyArgs[1])))) {
        overloadId = 2; // QInputMethodEvent(QString,QList<QInputMethodEvent::Attribute>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QInputMethodEvent(QInputMethodEvent)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QInputMethodEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QInputMethodEvent()
        {

            if (!PyErr_Occurred()) {
                // QInputMethodEvent()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QInputMethodEventWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QInputMethodEvent(const QInputMethodEvent & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QInputMethodEvent* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QInputMethodEvent(QInputMethodEvent)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QInputMethodEventWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QInputMethodEvent(const QString & preeditText, const QList<QInputMethodEvent::Attribute > & attributes)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QList<QInputMethodEvent::Attribute > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QInputMethodEvent(QString,QList<QInputMethodEvent::Attribute>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QInputMethodEventWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QInputMethodEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QInputMethodEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QInputMethodEvent_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QInputMethodEvent", "unicode, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QInputMethodEvent", overloads);
        return -1;
}

static PyObject* Sbk_QInputMethodEventFunc_attributes(PyObject* self)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QInputMethodEvent::Attribute > & cppResult = const_cast<const ::QInputMethodEvent*>(cppSelf)->attributes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QInputMethodEventFunc_commitString(PyObject* self)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // commitString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QString & cppResult = const_cast<const ::QInputMethodEvent*>(cppSelf)->commitString();
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

static PyObject* Sbk_QInputMethodEventFunc_preeditString(PyObject* self)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preeditString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QString & cppResult = const_cast<const ::QInputMethodEvent*>(cppSelf)->preeditString();
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

static PyObject* Sbk_QInputMethodEventFunc_replacementLength(PyObject* self)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // replacementLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QInputMethodEvent*>(cppSelf)->replacementLength();
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

static PyObject* Sbk_QInputMethodEventFunc_replacementStart(PyObject* self)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // replacementStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QInputMethodEvent*>(cppSelf)->replacementStart();
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

static PyObject* Sbk_QInputMethodEventFunc_setCommitString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QInputMethodEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputMethodEvent.setCommitString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputMethodEvent.setCommitString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setCommitString", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setCommitString(QString,int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setCommitString(QString,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setCommitString(QString,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // setCommitString(QString,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QInputMethodEventFunc_setCommitString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "replaceFrom");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputMethodEvent.setCommitString(): got multiple values for keyword argument 'replaceFrom'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QInputMethodEventFunc_setCommitString_TypeError;
            }
            value = PyDict_GetItemString(kwds, "replaceLength");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QInputMethodEvent.setCommitString(): got multiple values for keyword argument 'replaceLength'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QInputMethodEventFunc_setCommitString_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setCommitString(QString,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCommitString(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QInputMethodEventFunc_setCommitString_TypeError:
        const char* overloads[] = {"unicode, int = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QInputMethodEvent.setCommitString", overloads);
        return 0;
}

static PyMethodDef Sbk_QInputMethodEvent_methods[] = {
    {"attributes", (PyCFunction)Sbk_QInputMethodEventFunc_attributes, METH_NOARGS},
    {"commitString", (PyCFunction)Sbk_QInputMethodEventFunc_commitString, METH_NOARGS},
    {"preeditString", (PyCFunction)Sbk_QInputMethodEventFunc_preeditString, METH_NOARGS},
    {"replacementLength", (PyCFunction)Sbk_QInputMethodEventFunc_replacementLength, METH_NOARGS},
    {"replacementStart", (PyCFunction)Sbk_QInputMethodEventFunc_replacementStart, METH_NOARGS},
    {"setCommitString", (PyCFunction)Sbk_QInputMethodEventFunc_setCommitString, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QInputMethodEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QInputMethodEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QInputMethodEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QInputMethodEvent",
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
    /*tp_traverse*/         Sbk_QInputMethodEvent_traverse,
    /*tp_clear*/            Sbk_QInputMethodEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QInputMethodEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QInputMethodEvent_Init,
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

static void* Sbk_QInputMethodEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QInputMethodEvent*>(cptr)->type() == QEvent::InputMethod)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QInputMethodEvent_AttributeType_PythonToCpp_QInputMethodEvent_AttributeType(PyObject* pyIn, void* cppOut) {
    *((::QInputMethodEvent::AttributeType*)cppOut) = (::QInputMethodEvent::AttributeType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QInputMethodEvent_AttributeType_PythonToCpp_QInputMethodEvent_AttributeType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX]))
        return QInputMethodEvent_AttributeType_PythonToCpp_QInputMethodEvent_AttributeType;
    return 0;
}
static PyObject* QInputMethodEvent_AttributeType_CppToPython_QInputMethodEvent_AttributeType(const void* cppIn) {
    int castCppIn = *((::QInputMethodEvent::AttributeType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QInputMethodEvent_PythonToCpp_QInputMethodEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QInputMethodEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QInputMethodEvent_PythonToCpp_QInputMethodEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QInputMethodEvent_Type))
        return QInputMethodEvent_PythonToCpp_QInputMethodEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QInputMethodEvent_PTR_CppToPython_QInputMethodEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QInputMethodEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QInputMethodEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QInputMethodEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QInputMethodEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QInputMethodEvent", "QInputMethodEvent*",
        &Sbk_QInputMethodEvent_Type, &Shiboken::callCppDestructor< ::QInputMethodEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QInputMethodEvent_Type,
        QInputMethodEvent_PythonToCpp_QInputMethodEvent_PTR,
        is_QInputMethodEvent_PythonToCpp_QInputMethodEvent_PTR_Convertible,
        QInputMethodEvent_PTR_CppToPython_QInputMethodEvent);

    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent");
    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QInputMethodEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QInputMethodEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QInputMethodEvent_Type, &Sbk_QInputMethodEvent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'AttributeType'.
    SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QInputMethodEvent_Type,
        "AttributeType",
        "PySide.QtGui.QInputMethodEvent.AttributeType",
        "QInputMethodEvent::AttributeType");
    if (!SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
        &Sbk_QInputMethodEvent_Type, "TextFormat", (long) QInputMethodEvent::TextFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
        &Sbk_QInputMethodEvent_Type, "Cursor", (long) QInputMethodEvent::Cursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
        &Sbk_QInputMethodEvent_Type, "Language", (long) QInputMethodEvent::Language))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
        &Sbk_QInputMethodEvent_Type, "Ruby", (long) QInputMethodEvent::Ruby))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
        &Sbk_QInputMethodEvent_Type, "Selection", (long) QInputMethodEvent::Selection))
        return ;
    // Register converter for enum 'QInputMethodEvent::AttributeType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX],
            QInputMethodEvent_AttributeType_CppToPython_QInputMethodEvent_AttributeType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QInputMethodEvent_AttributeType_PythonToCpp_QInputMethodEvent_AttributeType,
            is_QInputMethodEvent_AttributeType_PythonToCpp_QInputMethodEvent_AttributeType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent::AttributeType");
        Shiboken::Conversions::registerConverterName(converter, "AttributeType");
    }
    // End of 'AttributeType' enum.


    qRegisterMetaType< ::QInputMethodEvent::AttributeType >("QInputMethodEvent::AttributeType");
}
