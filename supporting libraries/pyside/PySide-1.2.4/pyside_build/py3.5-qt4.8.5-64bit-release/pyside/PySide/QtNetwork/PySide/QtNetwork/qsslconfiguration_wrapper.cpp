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

#include "qsslconfiguration_wrapper.h"

// Extra includes
#include <QList>
#include <qsslcertificate.h>
#include <qsslcipher.h>
#include <qsslconfiguration.h>
#include <qsslkey.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslConfiguration_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslConfiguration >()))
        return -1;

    ::QSslConfiguration* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSslConfiguration", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSslConfiguration()
    // 1: QSslConfiguration(QSslConfiguration)
    if (numArgs == 0) {
        overloadId = 0; // QSslConfiguration()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSslConfiguration(QSslConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfiguration_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSslConfiguration()
        {

            if (!PyErr_Occurred()) {
                // QSslConfiguration()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslConfiguration();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSslConfiguration(const QSslConfiguration & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
            ::QSslConfiguration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSslConfiguration(QSslConfiguration)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSslConfiguration(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslConfiguration >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslConfiguration_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSslConfiguration_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QSslConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslConfiguration", overloads);
        return -1;
}

static PyObject* Sbk_QSslConfigurationFunc_caCertificates(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // caCertificates()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->caCertificates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_ciphers(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ciphers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCipher > cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->ciphers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_defaultConfiguration(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultConfiguration()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslConfiguration cppResult = ::QSslConfiguration::defaultConfiguration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_isNull(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSslConfigurationFunc_localCertificate(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localCertificate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCertificate cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->localCertificate();
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

static PyObject* Sbk_QSslConfigurationFunc_peerCertificate(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerCertificate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCertificate cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->peerCertificate();
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

static PyObject* Sbk_QSslConfigurationFunc_peerCertificateChain(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerCertificateChain()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->peerCertificateChain();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_peerVerifyDepth(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerVerifyDepth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->peerVerifyDepth();
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

static PyObject* Sbk_QSslConfigurationFunc_peerVerifyMode(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerVerifyMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslSocket::PeerVerifyMode cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->peerVerifyMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_privateKey(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // privateKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslKey cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->privateKey();
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

static PyObject* Sbk_QSslConfigurationFunc_protocol(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocol()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSsl::SslProtocol cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->protocol();
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

static PyObject* Sbk_QSslConfigurationFunc_sessionCipher(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionCipher()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCipher cppResult = const_cast<const ::QSslConfiguration*>(cppSelf)->sessionCipher();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslConfigurationFunc_setCaCertificates(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCaCertificates(QList<QSslCertificate>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // setCaCertificates(QList<QSslCertificate>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setCaCertificates_TypeError;

    // Call function/method
    {
        ::QList<QSslCertificate > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCaCertificates(QList<QSslCertificate>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCaCertificates(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setCaCertificates_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setCaCertificates", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setCiphers(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCiphers(QList<QSslCipher>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], (pyArg)))) {
        overloadId = 0; // setCiphers(QList<QSslCipher>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setCiphers_TypeError;

    // Call function/method
    {
        ::QList<QSslCipher > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCiphers(QList<QSslCipher>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCiphers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setCiphers_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setCiphers", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setDefaultConfiguration(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultConfiguration(QSslConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultConfiguration(QSslConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setDefaultConfiguration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
        ::QSslConfiguration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDefaultConfiguration(QSslConfiguration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSslConfiguration::setDefaultConfiguration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setDefaultConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setDefaultConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setLocalCertificate(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocalCertificate(QSslCertificate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // setLocalCertificate(QSslCertificate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setLocalCertificate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
        ::QSslCertificate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setLocalCertificate(QSslCertificate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocalCertificate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setLocalCertificate_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setLocalCertificate", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setPeerVerifyDepth(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerVerifyDepth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPeerVerifyDepth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setPeerVerifyDepth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerVerifyDepth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerVerifyDepth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setPeerVerifyDepth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setPeerVerifyDepth", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setPeerVerifyMode(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerVerifyMode(QSslSocket::PeerVerifyMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setPeerVerifyMode(QSslSocket::PeerVerifyMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setPeerVerifyMode_TypeError;

    // Call function/method
    {
        ::QSslSocket::PeerVerifyMode cppArg0 = ((::QSslSocket::PeerVerifyMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerVerifyMode(QSslSocket::PeerVerifyMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerVerifyMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setPeerVerifyMode_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslSocket.PeerVerifyMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setPeerVerifyMode", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setPrivateKey(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrivateKey(QSslKey)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (pyArg)))) {
        overloadId = 0; // setPrivateKey(QSslKey)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setPrivateKey_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslKey cppArg0_local = ::QSslKey();
        ::QSslKey* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPrivateKey(QSslKey)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrivateKey(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setPrivateKey_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslKey", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setPrivateKey", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfigurationFunc_setProtocol(PyObject* self, PyObject* pyArg)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProtocol(QSsl::SslProtocol)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]), (pyArg)))) {
        overloadId = 0; // setProtocol(QSsl::SslProtocol)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslConfigurationFunc_setProtocol_TypeError;

    // Call function/method
    {
        ::QSsl::SslProtocol cppArg0 = ((::QSsl::SslProtocol)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProtocol(QSsl::SslProtocol)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProtocol(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslConfigurationFunc_setProtocol_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSsl.SslProtocol", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslConfiguration.setProtocol", overloads);
        return 0;
}

static PyObject* Sbk_QSslConfiguration___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslConfiguration& cppSelf = *(((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSslConfiguration_methods[] = {
    {"caCertificates", (PyCFunction)Sbk_QSslConfigurationFunc_caCertificates, METH_NOARGS},
    {"ciphers", (PyCFunction)Sbk_QSslConfigurationFunc_ciphers, METH_NOARGS},
    {"defaultConfiguration", (PyCFunction)Sbk_QSslConfigurationFunc_defaultConfiguration, METH_NOARGS|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QSslConfigurationFunc_isNull, METH_NOARGS},
    {"localCertificate", (PyCFunction)Sbk_QSslConfigurationFunc_localCertificate, METH_NOARGS},
    {"peerCertificate", (PyCFunction)Sbk_QSslConfigurationFunc_peerCertificate, METH_NOARGS},
    {"peerCertificateChain", (PyCFunction)Sbk_QSslConfigurationFunc_peerCertificateChain, METH_NOARGS},
    {"peerVerifyDepth", (PyCFunction)Sbk_QSslConfigurationFunc_peerVerifyDepth, METH_NOARGS},
    {"peerVerifyMode", (PyCFunction)Sbk_QSslConfigurationFunc_peerVerifyMode, METH_NOARGS},
    {"privateKey", (PyCFunction)Sbk_QSslConfigurationFunc_privateKey, METH_NOARGS},
    {"protocol", (PyCFunction)Sbk_QSslConfigurationFunc_protocol, METH_NOARGS},
    {"sessionCipher", (PyCFunction)Sbk_QSslConfigurationFunc_sessionCipher, METH_NOARGS},
    {"setCaCertificates", (PyCFunction)Sbk_QSslConfigurationFunc_setCaCertificates, METH_O},
    {"setCiphers", (PyCFunction)Sbk_QSslConfigurationFunc_setCiphers, METH_O},
    {"setDefaultConfiguration", (PyCFunction)Sbk_QSslConfigurationFunc_setDefaultConfiguration, METH_O|METH_STATIC},
    {"setLocalCertificate", (PyCFunction)Sbk_QSslConfigurationFunc_setLocalCertificate, METH_O},
    {"setPeerVerifyDepth", (PyCFunction)Sbk_QSslConfigurationFunc_setPeerVerifyDepth, METH_O},
    {"setPeerVerifyMode", (PyCFunction)Sbk_QSslConfigurationFunc_setPeerVerifyMode, METH_O},
    {"setPrivateKey", (PyCFunction)Sbk_QSslConfigurationFunc_setPrivateKey, METH_O},
    {"setProtocol", (PyCFunction)Sbk_QSslConfigurationFunc_setProtocol, METH_O},

    {"__copy__", (PyCFunction)Sbk_QSslConfiguration___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSslConfiguration___nb_bool(PyObject* self)
{
    ::QSslConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSslConfiguration_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSslConfiguration& cppSelf = *(((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
                // operator!=(const QSslConfiguration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
                ::QSslConfiguration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
                // operator==(const QSslConfiguration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
                ::QSslConfiguration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp))
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
            goto Sbk_QSslConfiguration_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSslConfiguration_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSslConfiguration_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslConfiguration_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QSslConfiguration_TypeAsNumber;

static SbkObjectType Sbk_QSslConfiguration_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslConfiguration",
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
    /*tp_traverse*/         Sbk_QSslConfiguration_traverse,
    /*tp_clear*/            Sbk_QSslConfiguration_clear,
    /*tp_richcompare*/      Sbk_QSslConfiguration_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslConfiguration_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslConfiguration_Init,
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
static void QSslConfiguration_PythonToCpp_QSslConfiguration_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslConfiguration_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslConfiguration_PythonToCpp_QSslConfiguration_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslConfiguration_Type))
        return QSslConfiguration_PythonToCpp_QSslConfiguration_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslConfiguration_PTR_CppToPython_QSslConfiguration(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSslConfiguration*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSslConfiguration_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSslConfiguration_COPY_CppToPython_QSslConfiguration(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSslConfiguration_Type, new ::QSslConfiguration(*((::QSslConfiguration*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSslConfiguration_PythonToCpp_QSslConfiguration_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSslConfiguration*)cppOut) = *((::QSslConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSslConfiguration_PythonToCpp_QSslConfiguration_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslConfiguration_Type))
        return QSslConfiguration_PythonToCpp_QSslConfiguration_COPY;
    return 0;
}

void init_QSslConfiguration(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSslConfiguration_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSslConfiguration_TypeAsNumber) = Sbk_QSslConfiguration___nb_bool;
    Sbk_QSslConfiguration_Type.super.ht_type.tp_as_number = &Sbk_QSslConfiguration_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslConfiguration_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslConfiguration", "QSslConfiguration",
        &Sbk_QSslConfiguration_Type, &Shiboken::callCppDestructor< ::QSslConfiguration >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslConfiguration_Type,
        QSslConfiguration_PythonToCpp_QSslConfiguration_PTR,
        is_QSslConfiguration_PythonToCpp_QSslConfiguration_PTR_Convertible,
        QSslConfiguration_PTR_CppToPython_QSslConfiguration,
        QSslConfiguration_COPY_CppToPython_QSslConfiguration);

    Shiboken::Conversions::registerConverterName(converter, "QSslConfiguration");
    Shiboken::Conversions::registerConverterName(converter, "QSslConfiguration*");
    Shiboken::Conversions::registerConverterName(converter, "QSslConfiguration&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslConfiguration).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSslConfiguration_PythonToCpp_QSslConfiguration_COPY,
        is_QSslConfiguration_PythonToCpp_QSslConfiguration_COPY_Convertible);


    qRegisterMetaType< ::QSslConfiguration >("QSslConfiguration");
}
