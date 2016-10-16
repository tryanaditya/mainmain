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

#include "qsslkey_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qiodevice.h>
#include <qsslkey.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslKey_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslKey >()))
        return -1;

    ::QSslKey* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QSslKey", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QSslKey()
    // 1: QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
    // 2: QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
    // 3: QSslKey(QSslKey)
    if (numArgs == 0) {
        overloadId = 0; // QSslKey()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (pyArgs[0])))) {
        overloadId = 3; // QSslKey(QSslKey)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 2; // QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[4])))) {
                    overloadId = 2; // QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                }
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 1; // QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[4])))) {
                    overloadId = 1; // QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslKey_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSslKey()
        {

            if (!PyErr_Occurred()) {
                // QSslKey()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslKey();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSslKey(QIODevice * device, QSsl::KeyAlgorithm algorithm, QSsl::EncodingFormat format, QSsl::KeyType type, const QByteArray & passPhrase)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "passPhrase");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'passPhrase'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[4]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::KeyAlgorithm cppArg1 = ((::QSsl::KeyAlgorithm)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSsl::EncodingFormat cppArg2 = QSsl::Pem;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QSsl::KeyType cppArg3 = QSsl::PrivateKey;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QByteArray cppArg4_local = QByteArray();
            ::QByteArray* cppArg4 = &cppArg4_local;
            if (pythonToCpp[4]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);
            }

            if (!PyErr_Occurred()) {
                // QSslKey(QIODevice*,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslKey(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSslKey(const QByteArray & encoded, QSsl::KeyAlgorithm algorithm, QSsl::EncodingFormat format, QSsl::KeyType type, const QByteArray & passPhrase)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "passPhrase");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey(): got multiple values for keyword argument 'passPhrase'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[4]))))
                        goto Sbk_QSslKey_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QSsl::KeyAlgorithm cppArg1 = ((::QSsl::KeyAlgorithm)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSsl::EncodingFormat cppArg2 = QSsl::Pem;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QSsl::KeyType cppArg3 = QSsl::PrivateKey;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QByteArray cppArg4_local = QByteArray();
            ::QByteArray* cppArg4 = &cppArg4_local;
            if (pythonToCpp[4]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);
            }

            if (!PyErr_Occurred()) {
                // QSslKey(QByteArray,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QSsl::KeyType,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslKey(*cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QSslKey(const QSslKey & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSslKey cppArg0_local = ::QSslKey();
            ::QSslKey* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSslKey(QSslKey)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslKey(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslKey >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslKey_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSslKey_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QIODevice, PySide.QtNetwork.QSsl.KeyAlgorithm, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtNetwork.QSsl.KeyType = QSsl.PrivateKey, PySide.QtCore.QByteArray = QByteArray()", "PySide.QtCore.QByteArray, PySide.QtNetwork.QSsl.KeyAlgorithm, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtNetwork.QSsl.KeyType = QSsl.PrivateKey, PySide.QtCore.QByteArray = QByteArray()", "PySide.QtNetwork.QSslKey", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslKey", overloads);
        return -1;
}

static PyObject* Sbk_QSslKeyFunc_algorithm(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // algorithm()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSsl::KeyAlgorithm cppResult = const_cast<const ::QSslKey*>(cppSelf)->algorithm();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslKeyFunc_clear(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSslKeyFunc_handle(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QSslKey*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslKeyFunc_isNull(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslKey*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSslKeyFunc_length(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSslKey*>(cppSelf)->length();
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

static PyObject* Sbk_QSslKeyFunc_toDer(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey.toDer(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toDer", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toDer(QByteArray)const
    if (numArgs == 0) {
        overloadId = 0; // toDer(QByteArray)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 0; // toDer(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslKeyFunc_toDer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "passPhrase");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey.toDer(): got multiple values for keyword argument 'passPhrase'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                    goto Sbk_QSslKeyFunc_toDer_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // toDer(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslKey*>(cppSelf)->toDer(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslKeyFunc_toDer_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslKey.toDer", overloads);
        return 0;
}

static PyObject* Sbk_QSslKeyFunc_toPem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey.toPem(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toPem", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toPem(QByteArray)const
    if (numArgs == 0) {
        overloadId = 0; // toPem(QByteArray)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 0; // toPem(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslKeyFunc_toPem_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "passPhrase");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslKey.toPem(): got multiple values for keyword argument 'passPhrase'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                    goto Sbk_QSslKeyFunc_toPem_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // toPem(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslKey*>(cppSelf)->toPem(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslKeyFunc_toPem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslKey.toPem", overloads);
        return 0;
}

static PyObject* Sbk_QSslKeyFunc_type(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSsl::KeyType cppResult = const_cast<const ::QSslKey*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslKey___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslKey& cppSelf = *(((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSslKey_methods[] = {
    {"algorithm", (PyCFunction)Sbk_QSslKeyFunc_algorithm, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QSslKeyFunc_clear, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QSslKeyFunc_handle, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSslKeyFunc_isNull, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QSslKeyFunc_length, METH_NOARGS},
    {"toDer", (PyCFunction)Sbk_QSslKeyFunc_toDer, METH_VARARGS|METH_KEYWORDS},
    {"toPem", (PyCFunction)Sbk_QSslKeyFunc_toPem, METH_VARARGS|METH_KEYWORDS},
    {"type", (PyCFunction)Sbk_QSslKeyFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSslKey___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSslKey___nb_bool(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSslKey_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslKey& cppSelf = *(((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (pyArg)))) {
                // operator!=(const QSslKey & key) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslKey cppArg0_local = ::QSslKey();
                ::QSslKey* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (pyArg)))) {
                // operator==(const QSslKey & key) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslKey cppArg0_local = ::QSslKey();
                ::QSslKey* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], pythonToCpp))
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
            goto Sbk_QSslKey_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSslKey_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSslKey_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslKey_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSslKey__repr__(PyObject* self)
{
    ::QSslKey* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QSslKey_TypeAsNumber;

static SbkObjectType Sbk_QSslKey_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslKey",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSslKey__repr__,
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
    /*tp_traverse*/         Sbk_QSslKey_traverse,
    /*tp_clear*/            Sbk_QSslKey_clear,
    /*tp_richcompare*/      Sbk_QSslKey_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslKey_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslKey_Init,
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
static void QSslKey_PythonToCpp_QSslKey_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslKey_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslKey_PythonToCpp_QSslKey_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslKey_Type))
        return QSslKey_PythonToCpp_QSslKey_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslKey_PTR_CppToPython_QSslKey(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSslKey*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSslKey_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSslKey_COPY_CppToPython_QSslKey(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSslKey_Type, new ::QSslKey(*((::QSslKey*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSslKey_PythonToCpp_QSslKey_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSslKey*)cppOut) = *((::QSslKey*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSslKey_PythonToCpp_QSslKey_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslKey_Type))
        return QSslKey_PythonToCpp_QSslKey_COPY;
    return 0;
}

void init_QSslKey(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSslKey_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSslKey_TypeAsNumber) = Sbk_QSslKey___nb_bool;
    Sbk_QSslKey_Type.super.ht_type.tp_as_number = &Sbk_QSslKey_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslKey_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslKey", "QSslKey",
        &Sbk_QSslKey_Type, &Shiboken::callCppDestructor< ::QSslKey >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslKey_Type,
        QSslKey_PythonToCpp_QSslKey_PTR,
        is_QSslKey_PythonToCpp_QSslKey_PTR_Convertible,
        QSslKey_PTR_CppToPython_QSslKey,
        QSslKey_COPY_CppToPython_QSslKey);

    Shiboken::Conversions::registerConverterName(converter, "QSslKey");
    Shiboken::Conversions::registerConverterName(converter, "QSslKey*");
    Shiboken::Conversions::registerConverterName(converter, "QSslKey&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslKey).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslKey_PythonToCpp_QSslKey_COPY,
        is_QSslKey_PythonToCpp_QSslKey_COPY_Convertible);


    qRegisterMetaType< ::QSslKey >("QSslKey");
}
