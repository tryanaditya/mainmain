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

#include "qsslcipher_wrapper.h"

// Extra includes
#include <qsslcipher.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslCipher_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslCipher >()))
        return -1;

    ::QSslCipher* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSslCipher", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSslCipher()
    // 1: QSslCipher(QSslCipher)
    // 2: QSslCipher(QString,QSsl::SslProtocol)
    if (numArgs == 0) {
        overloadId = 0; // QSslCipher()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]), (pyArgs[1])))) {
        overloadId = 2; // QSslCipher(QString,QSsl::SslProtocol)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSslCipher(QSslCipher)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCipher_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSslCipher()
        {

            if (!PyErr_Occurred()) {
                // QSslCipher()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCipher();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSslCipher(const QSslCipher & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSslCipher cppArg0_local = ::QSslCipher();
            ::QSslCipher* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSslCipher(QSslCipher)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCipher(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSslCipher(const QString & name, QSsl::SslProtocol protocol)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::SslProtocol cppArg1 = ((::QSsl::SslProtocol)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSslCipher(QString,QSsl::SslProtocol)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCipher(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslCipher >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslCipher_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSslCipher_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QSslCipher", "unicode, PySide.QtNetwork.QSsl.SslProtocol", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCipher", overloads);
        return -1;
}

static PyObject* Sbk_QSslCipherFunc_authenticationMethod(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // authenticationMethod()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslCipher*>(cppSelf)->authenticationMethod();
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

static PyObject* Sbk_QSslCipherFunc_encryptionMethod(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encryptionMethod()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslCipher*>(cppSelf)->encryptionMethod();
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

static PyObject* Sbk_QSslCipherFunc_isNull(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslCipher*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSslCipherFunc_keyExchangeMethod(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyExchangeMethod()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslCipher*>(cppSelf)->keyExchangeMethod();
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

static PyObject* Sbk_QSslCipherFunc_name(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslCipher*>(cppSelf)->name();
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

static PyObject* Sbk_QSslCipherFunc_protocol(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocol()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSsl::SslProtocol cppResult = const_cast<const ::QSslCipher*>(cppSelf)->protocol();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCipherFunc_protocolString(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocolString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslCipher*>(cppSelf)->protocolString();
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

static PyObject* Sbk_QSslCipherFunc_supportedBits(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedBits()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSslCipher*>(cppSelf)->supportedBits();
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

static PyObject* Sbk_QSslCipherFunc_usedBits(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // usedBits()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSslCipher*>(cppSelf)->usedBits();
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

static PyObject* Sbk_QSslCipher___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslCipher& cppSelf = *(((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSslCipher_methods[] = {
    {"authenticationMethod", (PyCFunction)Sbk_QSslCipherFunc_authenticationMethod, METH_NOARGS},
    {"encryptionMethod", (PyCFunction)Sbk_QSslCipherFunc_encryptionMethod, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSslCipherFunc_isNull, METH_NOARGS},
    {"keyExchangeMethod", (PyCFunction)Sbk_QSslCipherFunc_keyExchangeMethod, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QSslCipherFunc_name, METH_NOARGS},
    {"protocol", (PyCFunction)Sbk_QSslCipherFunc_protocol, METH_NOARGS},
    {"protocolString", (PyCFunction)Sbk_QSslCipherFunc_protocolString, METH_NOARGS},
    {"supportedBits", (PyCFunction)Sbk_QSslCipherFunc_supportedBits, METH_NOARGS},
    {"usedBits", (PyCFunction)Sbk_QSslCipherFunc_usedBits, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSslCipher___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSslCipher___nb_bool(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSslCipher_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslCipher& cppSelf = *(((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (pyArg)))) {
                // operator!=(const QSslCipher & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslCipher cppArg0_local = ::QSslCipher();
                ::QSslCipher* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (pyArg)))) {
                // operator==(const QSslCipher & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslCipher cppArg0_local = ::QSslCipher();
                ::QSslCipher* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], pythonToCpp))
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
            goto Sbk_QSslCipher_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSslCipher_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSslCipher_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslCipher_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSslCipher__repr__(PyObject* self)
{
    ::QSslCipher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QSslCipher_TypeAsNumber;

static SbkObjectType Sbk_QSslCipher_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslCipher",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSslCipher__repr__,
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
    /*tp_traverse*/         Sbk_QSslCipher_traverse,
    /*tp_clear*/            Sbk_QSslCipher_clear,
    /*tp_richcompare*/      Sbk_QSslCipher_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslCipher_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslCipher_Init,
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
static void QSslCipher_PythonToCpp_QSslCipher_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslCipher_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslCipher_PythonToCpp_QSslCipher_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslCipher_Type))
        return QSslCipher_PythonToCpp_QSslCipher_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslCipher_PTR_CppToPython_QSslCipher(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSslCipher*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSslCipher_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSslCipher_COPY_CppToPython_QSslCipher(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSslCipher_Type, new ::QSslCipher(*((::QSslCipher*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSslCipher_PythonToCpp_QSslCipher_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSslCipher*)cppOut) = *((::QSslCipher*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSslCipher_PythonToCpp_QSslCipher_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslCipher_Type))
        return QSslCipher_PythonToCpp_QSslCipher_COPY;
    return 0;
}

void init_QSslCipher(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSslCipher_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSslCipher_TypeAsNumber) = Sbk_QSslCipher___nb_bool;
    Sbk_QSslCipher_Type.super.ht_type.tp_as_number = &Sbk_QSslCipher_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslCipher_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslCipher", "QSslCipher",
        &Sbk_QSslCipher_Type, &Shiboken::callCppDestructor< ::QSslCipher >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslCipher_Type,
        QSslCipher_PythonToCpp_QSslCipher_PTR,
        is_QSslCipher_PythonToCpp_QSslCipher_PTR_Convertible,
        QSslCipher_PTR_CppToPython_QSslCipher,
        QSslCipher_COPY_CppToPython_QSslCipher);

    Shiboken::Conversions::registerConverterName(converter, "QSslCipher");
    Shiboken::Conversions::registerConverterName(converter, "QSslCipher*");
    Shiboken::Conversions::registerConverterName(converter, "QSslCipher&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslCipher).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslCipher_PythonToCpp_QSslCipher_COPY,
        is_QSslCipher_PythonToCpp_QSslCipher_COPY_Convertible);


    qRegisterMetaType< ::QSslCipher >("QSslCipher");
}
