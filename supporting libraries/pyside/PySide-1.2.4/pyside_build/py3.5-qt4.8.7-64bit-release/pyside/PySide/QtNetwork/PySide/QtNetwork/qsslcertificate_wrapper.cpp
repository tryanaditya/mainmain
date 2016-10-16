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

#include "qsslcertificate_wrapper.h"

// Extra includes
#include <QList>
#include <QMultiMap>
#include <qbytearray.h>
#include <qdatetime.h>
#include <qiodevice.h>
#include <qsslcertificate.h>
#include <qsslkey.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslCertificate_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslCertificate >()))
        return -1;

    ::QSslCertificate* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QSslCertificate", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSslCertificate(QIODevice*,QSsl::EncodingFormat)
    // 1: QSslCertificate(QByteArray,QSsl::EncodingFormat)
    // 2: QSslCertificate(QSslCertificate)
    if (numArgs == 0) {
        overloadId = 1; // QSslCertificate(QByteArray,QSsl::EncodingFormat)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSslCertificate(QByteArray,QSsl::EncodingFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 1; // QSslCertificate(QByteArray,QSsl::EncodingFormat)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QSslCertificate(QIODevice*,QSsl::EncodingFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // QSslCertificate(QIODevice*,QSsl::EncodingFormat)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QSslCertificate(QSslCertificate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificate_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSslCertificate(QIODevice * device, QSsl::EncodingFormat format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslCertificate_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSslCertificate(QIODevice*,QSsl::EncodingFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCertificate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSslCertificate(const QByteArray & encoded, QSsl::EncodingFormat format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "encoded");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate(): got multiple values for keyword argument 'encoded'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                        goto Sbk_QSslCertificate_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslCertificate_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }
            ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSslCertificate(QByteArray,QSsl::EncodingFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCertificate(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSslCertificate(const QSslCertificate & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
            ::QSslCertificate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSslCertificate(QSslCertificate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslCertificate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslCertificate >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslCertificate_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSslCertificate_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem", "PySide.QtCore.QByteArray = QByteArray(), PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem", "PySide.QtNetwork.QSslCertificate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCertificate", overloads);
        return -1;
}

static PyObject* Sbk_QSslCertificateFunc_alternateSubjectNames(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alternateSubjectNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMultiMap<QSsl::AlternateNameEntryType, QString > cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->alternateSubjectNames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMULTIMAP_QSSL_ALTERNATENAMEENTRYTYPE_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_clear(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QSslCertificateFunc_digest(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.digest(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:digest", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: digest(QCryptographicHash::Algorithm)const
    if (numArgs == 0) {
        overloadId = 0; // digest(QCryptographicHash::Algorithm)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX]), (pyArgs[0])))) {
        overloadId = 0; // digest(QCryptographicHash::Algorithm)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_digest_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "algorithm");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.digest(): got multiple values for keyword argument 'algorithm'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX]), (pyArgs[0]))))
                    goto Sbk_QSslCertificateFunc_digest_TypeError;
            }
        }
        ::QCryptographicHash::Algorithm cppArg0 = QCryptographicHash::Md5;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // digest(QCryptographicHash::Algorithm)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->digest(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_digest_TypeError:
        const char* overloads[] = {"PySide.QtCore.QCryptographicHash.Algorithm = QCryptographicHash.Md5", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCertificate.digest", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_effectiveDate(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // effectiveDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->effectiveDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_expiryDate(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expiryDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->expiryDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_fromData(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromData", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromData(QByteArray,QSsl::EncodingFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromData(QByteArray,QSsl::EncodingFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromData(QByteArray,QSsl::EncodingFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_fromData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromData(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                    goto Sbk_QSslCertificateFunc_fromData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromData(QByteArray,QSsl::EncodingFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = ::QSslCertificate::fromData(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_fromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCertificate.fromData", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_fromDevice(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromDevice(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromDevice(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromDevice", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromDevice(QIODevice*,QSsl::EncodingFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromDevice(QIODevice*,QSsl::EncodingFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromDevice(QIODevice*,QSsl::EncodingFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_fromDevice_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromDevice(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                    goto Sbk_QSslCertificateFunc_fromDevice_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QIODevice* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromDevice(QIODevice*,QSsl::EncodingFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = ::QSslCertificate::fromDevice(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_fromDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCertificate.fromDevice", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_fromPath(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromPath(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromPath(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:fromPath", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: fromPath(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromPath(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // fromPath(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2])))) {
                overloadId = 0; // fromPath(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_fromPath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromPath(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                    goto Sbk_QSslCertificateFunc_fromPath_TypeError;
            }
            value = PyDict_GetItemString(kwds, "syntax");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslCertificate.fromPath(): got multiple values for keyword argument 'syntax'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2]))))
                    goto Sbk_QSslCertificateFunc_fromPath_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QRegExp::PatternSyntax cppArg2 = QRegExp::FixedString;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // fromPath(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = ::QSslCertificate::fromPath(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_fromPath_TypeError:
        const char* overloads[] = {"unicode, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtCore.QRegExp.PatternSyntax = QRegExp.FixedString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslCertificate.fromPath", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_handle(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->handle();
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

static PyObject* Sbk_QSslCertificateFunc_isNull(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSslCertificateFunc_isValid(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSslCertificateFunc_issuerInfo(PyObject* self, PyObject* pyArg)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: issuerInfo(QSslCertificate::SubjectInfo)const
    // 1: issuerInfo(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // issuerInfo(QByteArray)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX]), (pyArg)))) {
        overloadId = 0; // issuerInfo(QSslCertificate::SubjectInfo)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_issuerInfo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // issuerInfo(QSslCertificate::SubjectInfo info) const
        {
            ::QSslCertificate::SubjectInfo cppArg0 = ((::QSslCertificate::SubjectInfo)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // issuerInfo(QSslCertificate::SubjectInfo)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->issuerInfo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // issuerInfo(const QByteArray & tag) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // issuerInfo(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->issuerInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_issuerInfo_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate.SubjectInfo", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslCertificate.issuerInfo", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_publicKey(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // publicKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslKey cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->publicKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_serialNumber(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // serialNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->serialNumber();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_subjectInfo(PyObject* self, PyObject* pyArg)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subjectInfo(QSslCertificate::SubjectInfo)const
    // 1: subjectInfo(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // subjectInfo(QByteArray)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX]), (pyArg)))) {
        overloadId = 0; // subjectInfo(QSslCertificate::SubjectInfo)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslCertificateFunc_subjectInfo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // subjectInfo(QSslCertificate::SubjectInfo info) const
        {
            ::QSslCertificate::SubjectInfo cppArg0 = ((::QSslCertificate::SubjectInfo)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // subjectInfo(QSslCertificate::SubjectInfo)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->subjectInfo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // subjectInfo(const QByteArray & tag) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // subjectInfo(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->subjectInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslCertificateFunc_subjectInfo_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate.SubjectInfo", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslCertificate.subjectInfo", overloads);
        return 0;
}

static PyObject* Sbk_QSslCertificateFunc_toDer(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toDer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->toDer();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_toPem(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->toPem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificateFunc_version(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // version()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QSslCertificate*>(cppSelf)->version();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslCertificate___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslCertificate& cppSelf = *(((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSslCertificate_methods[] = {
    {"alternateSubjectNames", (PyCFunction)Sbk_QSslCertificateFunc_alternateSubjectNames, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QSslCertificateFunc_clear, METH_NOARGS},
    {"digest", (PyCFunction)Sbk_QSslCertificateFunc_digest, METH_VARARGS|METH_KEYWORDS},
    {"effectiveDate", (PyCFunction)Sbk_QSslCertificateFunc_effectiveDate, METH_NOARGS},
    {"expiryDate", (PyCFunction)Sbk_QSslCertificateFunc_expiryDate, METH_NOARGS},
    {"fromData", (PyCFunction)Sbk_QSslCertificateFunc_fromData, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromDevice", (PyCFunction)Sbk_QSslCertificateFunc_fromDevice, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromPath", (PyCFunction)Sbk_QSslCertificateFunc_fromPath, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"handle", (PyCFunction)Sbk_QSslCertificateFunc_handle, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSslCertificateFunc_isNull, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSslCertificateFunc_isValid, METH_NOARGS},
    {"issuerInfo", (PyCFunction)Sbk_QSslCertificateFunc_issuerInfo, METH_O},
    {"publicKey", (PyCFunction)Sbk_QSslCertificateFunc_publicKey, METH_NOARGS},
    {"serialNumber", (PyCFunction)Sbk_QSslCertificateFunc_serialNumber, METH_NOARGS},
    {"subjectInfo", (PyCFunction)Sbk_QSslCertificateFunc_subjectInfo, METH_O},
    {"toDer", (PyCFunction)Sbk_QSslCertificateFunc_toDer, METH_NOARGS},
    {"toPem", (PyCFunction)Sbk_QSslCertificateFunc_toPem, METH_NOARGS},
    {"version", (PyCFunction)Sbk_QSslCertificateFunc_version, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSslCertificate___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSslCertificate___nb_bool(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSslCertificate_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslCertificate& cppSelf = *(((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArg)))) {
                // operator!=(const QSslCertificate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
                ::QSslCertificate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArg)))) {
                // operator==(const QSslCertificate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
                ::QSslCertificate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp))
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
            goto Sbk_QSslCertificate_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSslCertificate_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSslCertificate_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslCertificate_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSslCertificate__repr__(PyObject* self)
{
    ::QSslCertificate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QSslCertificate_TypeAsNumber;

static SbkObjectType Sbk_QSslCertificate_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslCertificate",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSslCertificate__repr__,
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
    /*tp_traverse*/         Sbk_QSslCertificate_traverse,
    /*tp_clear*/            Sbk_QSslCertificate_clear,
    /*tp_richcompare*/      Sbk_QSslCertificate_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslCertificate_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslCertificate_Init,
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
static void QSslCertificate_SubjectInfo_PythonToCpp_QSslCertificate_SubjectInfo(PyObject* pyIn, void* cppOut) {
    *((::QSslCertificate::SubjectInfo*)cppOut) = (::QSslCertificate::SubjectInfo) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSslCertificate_SubjectInfo_PythonToCpp_QSslCertificate_SubjectInfo_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX]))
        return QSslCertificate_SubjectInfo_PythonToCpp_QSslCertificate_SubjectInfo;
    return 0;
}
static PyObject* QSslCertificate_SubjectInfo_CppToPython_QSslCertificate_SubjectInfo(const void* cppIn) {
    int castCppIn = *((::QSslCertificate::SubjectInfo*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSslCertificate_PythonToCpp_QSslCertificate_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslCertificate_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslCertificate_PythonToCpp_QSslCertificate_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslCertificate_Type))
        return QSslCertificate_PythonToCpp_QSslCertificate_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslCertificate_PTR_CppToPython_QSslCertificate(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSslCertificate*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSslCertificate_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSslCertificate_COPY_CppToPython_QSslCertificate(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSslCertificate_Type, new ::QSslCertificate(*((::QSslCertificate*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSslCertificate_PythonToCpp_QSslCertificate_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSslCertificate*)cppOut) = *((::QSslCertificate*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSslCertificate_PythonToCpp_QSslCertificate_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslCertificate_Type))
        return QSslCertificate_PythonToCpp_QSslCertificate_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_QIODevicePTR_PythonToCpp_QSslCertificate(PyObject* pyIn, void* cppOut) {
    *((::QSslCertificate*)cppOut) = ::QSslCertificate(((::QIODevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_QIODevicePTR_PythonToCpp_QSslCertificate_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], pyIn))
        return PySide_QtCore_QIODevicePTR_PythonToCpp_QSslCertificate;
    return 0;
}

void init_QSslCertificate(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSslCertificate_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSslCertificate_TypeAsNumber) = Sbk_QSslCertificate___nb_bool;
    Sbk_QSslCertificate_Type.super.ht_type.tp_as_number = &Sbk_QSslCertificate_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslCertificate_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslCertificate", "QSslCertificate",
        &Sbk_QSslCertificate_Type, &Shiboken::callCppDestructor< ::QSslCertificate >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslCertificate_Type,
        QSslCertificate_PythonToCpp_QSslCertificate_PTR,
        is_QSslCertificate_PythonToCpp_QSslCertificate_PTR_Convertible,
        QSslCertificate_PTR_CppToPython_QSslCertificate,
        QSslCertificate_COPY_CppToPython_QSslCertificate);

    Shiboken::Conversions::registerConverterName(converter, "QSslCertificate");
    Shiboken::Conversions::registerConverterName(converter, "QSslCertificate*");
    Shiboken::Conversions::registerConverterName(converter, "QSslCertificate&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslCertificate).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslCertificate_PythonToCpp_QSslCertificate_COPY,
        is_QSslCertificate_PythonToCpp_QSslCertificate_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_QIODevicePTR_PythonToCpp_QSslCertificate,
        is_PySide_QtCore_QIODevicePTR_PythonToCpp_QSslCertificate_Convertible);

    // Initialization of enums.

    // Initialization of enum 'SubjectInfo'.
    SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSslCertificate_Type,
        "SubjectInfo",
        "PySide.QtNetwork.QSslCertificate.SubjectInfo",
        "QSslCertificate::SubjectInfo");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "Organization", (long) QSslCertificate::Organization))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "CommonName", (long) QSslCertificate::CommonName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "LocalityName", (long) QSslCertificate::LocalityName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "OrganizationalUnitName", (long) QSslCertificate::OrganizationalUnitName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "CountryName", (long) QSslCertificate::CountryName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
        &Sbk_QSslCertificate_Type, "StateOrProvinceName", (long) QSslCertificate::StateOrProvinceName))
        return ;
    // Register converter for enum 'QSslCertificate::SubjectInfo'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX],
            QSslCertificate_SubjectInfo_CppToPython_QSslCertificate_SubjectInfo);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSslCertificate_SubjectInfo_PythonToCpp_QSslCertificate_SubjectInfo,
            is_QSslCertificate_SubjectInfo_PythonToCpp_QSslCertificate_SubjectInfo_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_SUBJECTINFO_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSslCertificate::SubjectInfo");
        Shiboken::Conversions::registerConverterName(converter, "SubjectInfo");
    }
    // End of 'SubjectInfo' enum.


    qRegisterMetaType< ::QSslCertificate::SubjectInfo >("QSslCertificate::SubjectInfo");
}
