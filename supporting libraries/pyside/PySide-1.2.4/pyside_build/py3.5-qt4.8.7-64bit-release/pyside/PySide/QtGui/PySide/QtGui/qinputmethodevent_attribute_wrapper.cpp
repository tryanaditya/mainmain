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

#include "qinputmethodevent_attribute_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QInputMethodEvent_Attribute_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QInputMethodEvent::Attribute >()))
        return -1;

    ::QInputMethodEvent::Attribute* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QInputMethodEvent_Attribute_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "Attribute", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: Attribute(QInputMethodEvent::AttributeType,int,int,QVariant)
    // 1: Attribute(QInputMethodEvent::Attribute)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (pyArgs[0])))) {
        overloadId = 1; // Attribute(QInputMethodEvent::Attribute)
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[3])))) {
        overloadId = 0; // Attribute(QInputMethodEvent::AttributeType,int,int,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QInputMethodEvent_Attribute_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Attribute(QInputMethodEvent::AttributeType t, int s, int l, QVariant val)
        {
            ::QInputMethodEvent::AttributeType cppArg0 = ((::QInputMethodEvent::AttributeType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QVariant cppArg3 = ::QVariant();
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // Attribute(QInputMethodEvent::AttributeType,int,int,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QInputMethodEvent::Attribute(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Attribute(const QInputMethodEvent::Attribute & Attribute)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QInputMethodEvent::Attribute cppArg0_local = ::QInputMethodEvent::Attribute(((::QInputMethodEvent::AttributeType)0), ((int)0), ((int)0), ::QVariant());
            ::QInputMethodEvent::Attribute* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // Attribute(QInputMethodEvent::Attribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QInputMethodEvent::Attribute(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QInputMethodEvent::Attribute >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QInputMethodEvent_Attribute_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QInputMethodEvent_Attribute_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent.AttributeType, int, int, QVariant", "PySide.QtGui.QInputMethodEvent::Attribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.Attribute", overloads);
        return -1;
}

static PyObject* Sbk_QInputMethodEvent_Attribute___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QInputMethodEvent::Attribute& cppSelf = *(((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QInputMethodEvent_Attribute_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QInputMethodEvent_Attribute___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QInputMethodEvent_Attribute_get_length(PyObject* self, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->length;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QInputMethodEvent_Attribute_set_length(PyObject* self, PyObject* pyIn, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'length' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'length', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->length;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->length = cppOut_local;

    return 0;
}

static PyObject* Sbk_QInputMethodEvent_Attribute_get_type(PyObject* self, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    ::QInputMethodEvent::AttributeType cppOut_local = cppSelf->type;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QInputMethodEvent_Attribute_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'AttributeType' or convertible type expected");
        return -1;
    }

    ::QInputMethodEvent::AttributeType cppOut_local = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->type = cppOut_local;

    return 0;
}

static PyObject* Sbk_QInputMethodEvent_Attribute_get_value(PyObject* self, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppSelf->value);
    return pyOut;
}
static int Sbk_QInputMethodEvent_Attribute_set_value(PyObject* self, PyObject* pyIn, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'value' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'value', 'QVariant' or convertible type expected");
        return -1;
    }

    ::QVariant& cppOut_ptr = cppSelf->value;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QInputMethodEvent_Attribute_get_start(PyObject* self, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->start;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QInputMethodEvent_Attribute_set_start(PyObject* self, PyObject* pyIn, void*)
{
    ::QInputMethodEvent::Attribute* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'start' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'start', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->start;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->start = cppOut_local;

    return 0;
}

// Getters and Setters for Attribute
static PyGetSetDef Sbk_QInputMethodEvent_Attribute_getsetlist[] = {
    {const_cast<char*>("length"), Sbk_QInputMethodEvent_Attribute_get_length, Sbk_QInputMethodEvent_Attribute_set_length},
    {const_cast<char*>("type"), Sbk_QInputMethodEvent_Attribute_get_type, Sbk_QInputMethodEvent_Attribute_set_type},
    {const_cast<char*>("value"), Sbk_QInputMethodEvent_Attribute_get_value, Sbk_QInputMethodEvent_Attribute_set_value},
    {const_cast<char*>("start"), Sbk_QInputMethodEvent_Attribute_get_start, Sbk_QInputMethodEvent_Attribute_set_start},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QInputMethodEvent_Attribute_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QInputMethodEvent_Attribute_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QInputMethodEvent_Attribute_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QInputMethodEvent.Attribute",
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
    /*tp_traverse*/         Sbk_QInputMethodEvent_Attribute_traverse,
    /*tp_clear*/            Sbk_QInputMethodEvent_Attribute_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QInputMethodEvent_Attribute_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QInputMethodEvent_Attribute_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QInputMethodEvent_Attribute_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Attribute_PythonToCpp_Attribute_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QInputMethodEvent_Attribute_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Attribute_PythonToCpp_Attribute_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QInputMethodEvent_Attribute_Type))
        return Attribute_PythonToCpp_Attribute_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Attribute_PTR_CppToPython_Attribute(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QInputMethodEvent::Attribute*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QInputMethodEvent_Attribute_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* Attribute_COPY_CppToPython_Attribute(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QInputMethodEvent_Attribute_Type, new ::QInputMethodEvent::Attribute(*((::QInputMethodEvent::Attribute*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void Attribute_PythonToCpp_Attribute_COPY(PyObject* pyIn, void* cppOut) {
    *((::QInputMethodEvent::Attribute*)cppOut) = *((::QInputMethodEvent::Attribute*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_Attribute_PythonToCpp_Attribute_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QInputMethodEvent_Attribute_Type))
        return Attribute_PythonToCpp_Attribute_COPY;
    return 0;
}

void init_QInputMethodEvent_Attribute(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QInputMethodEvent_Attribute_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Attribute", "QInputMethodEvent::Attribute",
        &Sbk_QInputMethodEvent_Attribute_Type, &Shiboken::callCppDestructor< ::QInputMethodEvent::Attribute >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QInputMethodEvent_Attribute_Type,
        Attribute_PythonToCpp_Attribute_PTR,
        is_Attribute_PythonToCpp_Attribute_PTR_Convertible,
        Attribute_PTR_CppToPython_Attribute,
        Attribute_COPY_CppToPython_Attribute);

    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent::Attribute");
    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent::Attribute*");
    Shiboken::Conversions::registerConverterName(converter, "QInputMethodEvent::Attribute&");
    Shiboken::Conversions::registerConverterName(converter, "Attribute");
    Shiboken::Conversions::registerConverterName(converter, "Attribute*");
    Shiboken::Conversions::registerConverterName(converter, "Attribute&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QInputMethodEvent::Attribute).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Attribute_PythonToCpp_Attribute_COPY,
        is_Attribute_PythonToCpp_Attribute_COPY_Convertible);


}
