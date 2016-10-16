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

#include "qsslerror_wrapper.h"

// Extra includes
#include <qsslcertificate.h>
#include <qsslerror.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslError_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslError >()))
        return -1;

    ::QSslError* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSslError", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSslError()
    // 1: QSslError(QSslError::SslError)
    // 2: QSslError(QSslError::SslError,QSslCertificate)
    // 3: QSslError(QSslError)
    if (numArgs == 0) {
        overloadId = 0; // QSslError()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSslError(QSslError::SslError)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArgs[1])))) {
            overloadId = 2; // QSslError(QSslError::SslError,QSslCertificate)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (pyArgs[0])))) {
        overloadId = 3; // QSslError(QSslError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslError_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSslError()
        {

            if (!PyErr_Occurred()) {
                // QSslError()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslError();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSslError(QSslError::SslError error)
        {
            ::QSslError::SslError cppArg0 = ((::QSslError::SslError)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSslError(QSslError::SslError)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslError(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSslError(QSslError::SslError error, const QSslCertificate & certificate)
        {
            ::QSslError::SslError cppArg0 = ((::QSslError::SslError)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QSslCertificate cppArg1_local = ::QSslCertificate(((::QIODevice*)0));
            ::QSslCertificate* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QSslError(QSslError::SslError,QSslCertificate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslError(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QSslError(const QSslError & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSslError cppArg0_local = ::QSslError();
            ::QSslError* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSslError(QSslError)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslError(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslError >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslError_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSslError_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QSslError.SslError", "PySide.QtNetwork.QSslError.SslError, PySide.QtNetwork.QSslCertificate", "PySide.QtNetwork.QSslError", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslError", overloads);
        return -1;
}

static PyObject* Sbk_QSslErrorFunc_certificate(PyObject* self)
{
    ::QSslError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // certificate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCertificate cppResult = const_cast<const ::QSslError*>(cppSelf)->certificate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslErrorFunc_error(PyObject* self)
{
    ::QSslError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslError::SslError cppResult = const_cast<const ::QSslError*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslErrorFunc_errorString(PyObject* self)
{
    ::QSslError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslError*>(cppSelf)->errorString();
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

static PyObject* Sbk_QSslError___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslError& cppSelf = *(((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSslError_methods[] = {
    {"certificate", (PyCFunction)Sbk_QSslErrorFunc_certificate, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QSslErrorFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QSslErrorFunc_errorString, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSslError___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QSslError_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslError& cppSelf = *(((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (pyArg)))) {
                // operator!=(const QSslError & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslError cppArg0_local = ::QSslError();
                ::QSslError* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (pyArg)))) {
                // operator==(const QSslError & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslError cppArg0_local = ::QSslError();
                ::QSslError* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QSslError_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSslError_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSslError_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslError_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSslError__repr__(PyObject* self)
{
    ::QSslError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
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
static SbkObjectType Sbk_QSslError_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslError",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSslError__repr__,
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
    /*tp_traverse*/         Sbk_QSslError_traverse,
    /*tp_clear*/            Sbk_QSslError_clear,
    /*tp_richcompare*/      Sbk_QSslError_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslError_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslError_Init,
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
static void QSslError_SslError_PythonToCpp_QSslError_SslError(PyObject* pyIn, void* cppOut) {
    *((::QSslError::SslError*)cppOut) = (::QSslError::SslError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSslError_SslError_PythonToCpp_QSslError_SslError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX]))
        return QSslError_SslError_PythonToCpp_QSslError_SslError;
    return 0;
}
static PyObject* QSslError_SslError_CppToPython_QSslError_SslError(const void* cppIn) {
    int castCppIn = *((::QSslError::SslError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSslError_PythonToCpp_QSslError_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslError_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslError_PythonToCpp_QSslError_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslError_Type))
        return QSslError_PythonToCpp_QSslError_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslError_PTR_CppToPython_QSslError(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSslError*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSslError_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSslError_COPY_CppToPython_QSslError(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSslError_Type, new ::QSslError(*((::QSslError*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSslError_PythonToCpp_QSslError_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSslError*)cppOut) = *((::QSslError*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSslError_PythonToCpp_QSslError_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslError_Type))
        return QSslError_PythonToCpp_QSslError_COPY;
    return 0;
}

// Implicit conversions.
static void QSslError_SslError_PythonToCpp_QSslError(PyObject* pyIn, void* cppOut) {
    ::QSslError::SslError cppIn = ((::QSslError::SslError)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX]), pyIn, &cppIn);
    *((::QSslError*)cppOut) = ::QSslError(cppIn);
}
static PythonToCppFunc is_QSslError_SslError_PythonToCpp_QSslError_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX], pyIn))
        return QSslError_SslError_PythonToCpp_QSslError;
    return 0;
}

void init_QSslError(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslError_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslError", "QSslError",
        &Sbk_QSslError_Type, &Shiboken::callCppDestructor< ::QSslError >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslError_Type,
        QSslError_PythonToCpp_QSslError_PTR,
        is_QSslError_PythonToCpp_QSslError_PTR_Convertible,
        QSslError_PTR_CppToPython_QSslError,
        QSslError_COPY_CppToPython_QSslError);

    Shiboken::Conversions::registerConverterName(converter, "QSslError");
    Shiboken::Conversions::registerConverterName(converter, "QSslError*");
    Shiboken::Conversions::registerConverterName(converter, "QSslError&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslError).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslError_PythonToCpp_QSslError_COPY,
        is_QSslError_PythonToCpp_QSslError_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslError_SslError_PythonToCpp_QSslError,
        is_QSslError_SslError_PythonToCpp_QSslError_Convertible);

    // Initialization of enums.

    // Initialization of enum 'SslError'.
    SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSslError_Type,
        "SslError",
        "PySide.QtNetwork.QSslError.SslError",
        "QSslError::SslError");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "NoError", (long) QSslError::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnableToGetIssuerCertificate", (long) QSslError::UnableToGetIssuerCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnableToDecryptCertificateSignature", (long) QSslError::UnableToDecryptCertificateSignature))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnableToDecodeIssuerPublicKey", (long) QSslError::UnableToDecodeIssuerPublicKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateSignatureFailed", (long) QSslError::CertificateSignatureFailed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateNotYetValid", (long) QSslError::CertificateNotYetValid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateExpired", (long) QSslError::CertificateExpired))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "InvalidNotBeforeField", (long) QSslError::InvalidNotBeforeField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "InvalidNotAfterField", (long) QSslError::InvalidNotAfterField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "SelfSignedCertificate", (long) QSslError::SelfSignedCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "SelfSignedCertificateInChain", (long) QSslError::SelfSignedCertificateInChain))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnableToGetLocalIssuerCertificate", (long) QSslError::UnableToGetLocalIssuerCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnableToVerifyFirstCertificate", (long) QSslError::UnableToVerifyFirstCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateRevoked", (long) QSslError::CertificateRevoked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "InvalidCaCertificate", (long) QSslError::InvalidCaCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "PathLengthExceeded", (long) QSslError::PathLengthExceeded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "InvalidPurpose", (long) QSslError::InvalidPurpose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateUntrusted", (long) QSslError::CertificateUntrusted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateRejected", (long) QSslError::CertificateRejected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "SubjectIssuerMismatch", (long) QSslError::SubjectIssuerMismatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "AuthorityIssuerSerialNumberMismatch", (long) QSslError::AuthorityIssuerSerialNumberMismatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "NoPeerCertificate", (long) QSslError::NoPeerCertificate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "HostNameMismatch", (long) QSslError::HostNameMismatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "NoSslSupport", (long) QSslError::NoSslSupport))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "CertificateBlacklisted", (long) QSslError::CertificateBlacklisted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
        &Sbk_QSslError_Type, "UnspecifiedError", (long) QSslError::UnspecifiedError))
        return ;
    // Register converter for enum 'QSslError::SslError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX],
            QSslError_SslError_CppToPython_QSslError_SslError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSslError_SslError_PythonToCpp_QSslError_SslError,
            is_QSslError_SslError_PythonToCpp_QSslError_SslError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLERROR_SSLERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSslError::SslError");
        Shiboken::Conversions::registerConverterName(converter, "SslError");
    }
    // End of 'SslError' enum.


    qRegisterMetaType< ::QSslError >("QSslError");
    qRegisterMetaType< ::QSslError::SslError >("QSslError::SslError");
}
