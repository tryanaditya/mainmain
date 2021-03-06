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
#include "pyside_qtnetwork_python.h"

#include "qipv6address_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QIPv6Address_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QIPv6Address >()))
        return -1;

    ::QIPv6Address* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QIPv6Address", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QIPv6Address()
    // 1: QIPv6Address(QIPv6Address)
    if (numArgs == 0) {
        overloadId = 0; // QIPv6Address()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (pyArgs[0])))) {
        overloadId = 1; // QIPv6Address(QIPv6Address)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIPv6Address_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QIPv6Address()
        {

            if (!PyErr_Occurred()) {
                // QIPv6Address()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIPv6Address();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QIPv6Address(const QIPv6Address & QIPv6Address)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIPv6Address cppArg0_local = ::QIPv6Address();
            ::QIPv6Address* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QIPv6Address(QIPv6Address)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIPv6Address(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QIPv6Address >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QIPv6Address_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QIPv6Address_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QIPv6Address", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QIPv6Address", overloads);
        return -1;
}

static PyObject* Sbk_QIPv6Address___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QIPv6Address& cppSelf = *(((::QIPv6Address*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QIPv6Address_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QIPv6Address___copy__, METH_NOARGS},
    {0} // Sentinel
};

Py_ssize_t Sbk_QIPv6AddressFunc___len__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QIPv6Address* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIPv6Address*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (SbkObject*)self));
    // Begin code injection

    return 16;


    return 16;

    // End of code injection
}

PyObject* Sbk_QIPv6AddressFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QIPv6Address* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIPv6Address*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i >= 16) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    if (_i < 0)
        _i = 16 - qAbs(_i);

    uint item = cppSelf->c[_i];
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &item);

    // End of code injection
}

int Sbk_QIPv6AddressFunc___setitem__(PyObject* self, Py_ssize_t _i, PyObject* _value)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QIPv6Address* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIPv6Address*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i >= 16) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return -1;
    }
    if (_i < 0)
        _i = 16 - qAbs(_i);
    quint8 item;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<quint8>(), _value, &(item));
    cppSelf->c[_i] = item;
    return 0;

    // End of code injection
}

} // extern "C"

static int Sbk_QIPv6Address_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QIPv6Address_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PySequenceMethods Sbk_QIPv6Address_TypeAsSequence;

static SbkObjectType Sbk_QIPv6Address_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QIPv6Address",
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
    /*tp_traverse*/         Sbk_QIPv6Address_traverse,
    /*tp_clear*/            Sbk_QIPv6Address_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QIPv6Address_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QIPv6Address_Init,
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
static void QIPv6Address_PythonToCpp_QIPv6Address_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QIPv6Address_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QIPv6Address_PythonToCpp_QIPv6Address_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QIPv6Address_Type))
        return QIPv6Address_PythonToCpp_QIPv6Address_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QIPv6Address_PTR_CppToPython_QIPv6Address(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QIPv6Address*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QIPv6Address_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QIPv6Address_COPY_CppToPython_QIPv6Address(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QIPv6Address_Type, new ::QIPv6Address(*((::QIPv6Address*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QIPv6Address_PythonToCpp_QIPv6Address_COPY(PyObject* pyIn, void* cppOut) {
    *((::QIPv6Address*)cppOut) = *((::QIPv6Address*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QIPv6Address_PythonToCpp_QIPv6Address_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QIPv6Address_Type))
        return QIPv6Address_PythonToCpp_QIPv6Address_COPY;
    return 0;
}

void init_QIPv6Address(PyObject* module)
{
    // type supports sequence protocol
    memset(&Sbk_QIPv6Address_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QIPv6Address_TypeAsSequence.sq_length = &Sbk_QIPv6AddressFunc___len__;
    Sbk_QIPv6Address_TypeAsSequence.sq_item = &Sbk_QIPv6AddressFunc___getitem__;
    Sbk_QIPv6Address_TypeAsSequence.sq_ass_item = &Sbk_QIPv6AddressFunc___setitem__;
    Sbk_QIPv6Address_Type.super.ht_type.tp_as_sequence = &Sbk_QIPv6Address_TypeAsSequence;

    SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QIPv6Address_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QIPv6Address", "QIPv6Address",
        &Sbk_QIPv6Address_Type, &Shiboken::callCppDestructor< ::QIPv6Address >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QIPv6Address_Type,
        QIPv6Address_PythonToCpp_QIPv6Address_PTR,
        is_QIPv6Address_PythonToCpp_QIPv6Address_PTR_Convertible,
        QIPv6Address_PTR_CppToPython_QIPv6Address,
        QIPv6Address_COPY_CppToPython_QIPv6Address);

    Shiboken::Conversions::registerConverterName(converter, "QIPv6Address");
    Shiboken::Conversions::registerConverterName(converter, "QIPv6Address*");
    Shiboken::Conversions::registerConverterName(converter, "QIPv6Address&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QIPv6Address).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QIPv6Address_PythonToCpp_QIPv6Address_COPY,
        is_QIPv6Address_PythonToCpp_QIPv6Address_COPY_Convertible);


    qRegisterMetaType< ::QIPv6Address >("QIPv6Address");
}
