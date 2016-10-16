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

#include "qhostaddress_wrapper.h"

// Extra includes
#include <QPair>
#include <qdatastream.h>
#include <qhostaddress.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QHostAddress_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QHostAddress >()))
        return -1;

    ::QHostAddress* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QHostAddress", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QHostAddress()
    // 1: QHostAddress(QHostAddress::SpecialAddress)
    // 2: QHostAddress(QHostAddress)
    // 3: QHostAddress(QIPv6Address)
    // 4: QHostAddress(QString)
    // 5: QHostAddress(quint32)
    if (numArgs == 0) {
        overloadId = 0; // QHostAddress()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 4; // QHostAddress(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (pyArgs[0])))) {
        overloadId = 3; // QHostAddress(QIPv6Address)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QHostAddress(QHostAddress::SpecialAddress)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[0])))) {
        overloadId = 5; // QHostAddress(quint32)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArgs[0])))) {
        overloadId = 2; // QHostAddress(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddress_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QHostAddress()
        {

            if (!PyErr_Occurred()) {
                // QHostAddress()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QHostAddress(QHostAddress::SpecialAddress address)
        {
            ::QHostAddress::SpecialAddress cppArg0 = ((::QHostAddress::SpecialAddress)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHostAddress(QHostAddress::SpecialAddress)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QHostAddress(const QHostAddress & copy)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QHostAddress cppArg0_local = ::QHostAddress();
            ::QHostAddress* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QHostAddress(QHostAddress)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QHostAddress(const QIPv6Address & ip6Addr)
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
                // QHostAddress(QIPv6Address)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QHostAddress(const QString & address)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHostAddress(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QHostAddress(quint32 ip4Addr)
        {
            quint32 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHostAddress(quint32)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostAddress(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QHostAddress >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QHostAddress_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QHostAddress_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QHostAddress.SpecialAddress", "PySide.QtNetwork.QHostAddress", "PySide.QtNetwork.QIPv6Address", "unicode", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHostAddress", overloads);
        return -1;
}

static PyObject* Sbk_QHostAddressFunc_clear(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QHostAddressFunc_isInSubnet(PyObject* self, PyObject* args)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isInSubnet", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isInSubnet(QHostAddress,int)const
    // 1: isInSubnet(QPair<QHostAddress,int>)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // isInSubnet(QHostAddress,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX], (pyArgs[0])))) {
        overloadId = 1; // isInSubnet(QPair<QHostAddress,int>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc_isInSubnet_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isInSubnet(const QHostAddress & subnet, int netmask) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QHostAddress cppArg0_local = ::QHostAddress();
            ::QHostAddress* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // isInSubnet(QHostAddress,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QHostAddress*>(cppSelf)->isInSubnet(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isInSubnet(const QPair<QHostAddress, int > & subnet) const
        {
            ::QPair<QHostAddress, int > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // isInSubnet(QPair<QHostAddress,int>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QHostAddress*>(cppSelf)->isInSubnet(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostAddressFunc_isInSubnet_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress, int", "QPair", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHostAddress.isInSubnet", overloads);
        return 0;
}

static PyObject* Sbk_QHostAddressFunc_isNull(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QHostAddress*>(cppSelf)->isNull();
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

static PyObject* Sbk_QHostAddressFunc_parseSubnet(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: parseSubnet(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // parseSubnet(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc_parseSubnet_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // parseSubnet(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPair<QHostAddress, int > cppResult = ::QHostAddress::parseSubnet(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostAddressFunc_parseSubnet_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostAddress.parseSubnet", overloads);
        return 0;
}

static PyObject* Sbk_QHostAddressFunc_protocol(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocol()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSocket::NetworkLayerProtocol cppResult = const_cast<const ::QHostAddress*>(cppSelf)->protocol();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHostAddressFunc_scopeId(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scopeId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHostAddress*>(cppSelf)->scopeId();
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

static PyObject* Sbk_QHostAddressFunc_setAddress(PyObject* self, PyObject* pyArg)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAddress(QIPv6Address)
    // 1: setAddress(QString)
    // 2: setAddress(quint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArg)))) {
        overloadId = 2; // setAddress(quint32)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setAddress(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setAddress(QIPv6Address)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc_setAddress_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAddress(const QIPv6Address & ip6Addr)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QIPv6Address cppArg0_local = ::QIPv6Address();
            ::QIPv6Address* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setAddress(QIPv6Address)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAddress(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // setAddress(const QString & address)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setAddress(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setAddress(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // setAddress(quint32 ip4Addr)
        {
            quint32 cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setAddress(quint32)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAddress(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostAddressFunc_setAddress_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QIPv6Address", "unicode", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostAddress.setAddress", overloads);
        return 0;
}

static PyObject* Sbk_QHostAddressFunc_setScopeId(PyObject* self, PyObject* pyArg)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScopeId(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setScopeId(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc_setScopeId_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScopeId(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScopeId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostAddressFunc_setScopeId_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostAddress.setScopeId", overloads);
        return 0;
}

static PyObject* Sbk_QHostAddressFunc_toIPv4Address(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toIPv4Address()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint32 cppResult = const_cast<const ::QHostAddress*>(cppSelf)->toIPv4Address();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHostAddressFunc_toIPv6Address(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toIPv6Address()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIPv6Address cppResult = const_cast<const ::QHostAddress*>(cppSelf)->toIPv6Address();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QIPV6ADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHostAddressFunc_toString(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHostAddress*>(cppSelf)->toString();
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

static PyObject* Sbk_QHostAddress___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHostAddress& cppSelf = *(((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHostAddress_methods[] = {
    {"clear", (PyCFunction)Sbk_QHostAddressFunc_clear, METH_NOARGS},
    {"isInSubnet", (PyCFunction)Sbk_QHostAddressFunc_isInSubnet, METH_VARARGS},
    {"isNull", (PyCFunction)Sbk_QHostAddressFunc_isNull, METH_NOARGS},
    {"parseSubnet", (PyCFunction)Sbk_QHostAddressFunc_parseSubnet, METH_O|METH_STATIC},
    {"protocol", (PyCFunction)Sbk_QHostAddressFunc_protocol, METH_NOARGS},
    {"scopeId", (PyCFunction)Sbk_QHostAddressFunc_scopeId, METH_NOARGS},
    {"setAddress", (PyCFunction)Sbk_QHostAddressFunc_setAddress, METH_O},
    {"setScopeId", (PyCFunction)Sbk_QHostAddressFunc_setScopeId, METH_O},
    {"toIPv4Address", (PyCFunction)Sbk_QHostAddressFunc_toIPv4Address, METH_NOARGS},
    {"toIPv6Address", (PyCFunction)Sbk_QHostAddressFunc_toIPv6Address, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QHostAddressFunc_toString, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QHostAddress___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QHostAddress___nb_bool(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QHostAddressFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QHostAddress)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QHostAddress)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QHostAddress) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostAddressFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostAddress.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QHostAddressFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QHostAddress&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QHostAddress&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostAddressFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QHostAddress&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostAddressFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostAddress.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QHostAddress_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHostAddress& cppSelf = *(((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]), (pyArg)))) {
                // operator!=(QHostAddress::SpecialAddress address) const
                ::QHostAddress::SpecialAddress cppArg0 = ((::QHostAddress::SpecialAddress)0);
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf != (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
                // operator!=(const QHostAddress & address) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QHostAddress cppArg0_local = ::QHostAddress();
                ::QHostAddress* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]), (pyArg)))) {
                // operator==(QHostAddress::SpecialAddress address1)
                ::QHostAddress::SpecialAddress cppArg0 = ((::QHostAddress::SpecialAddress)0);
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
                // operator==(const QHostAddress & address) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QHostAddress cppArg0_local = ::QHostAddress();
                ::QHostAddress* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]), (pyArg)))) {
                // operator==(QHostAddress::SpecialAddress address) const
                ::QHostAddress::SpecialAddress cppArg0 = ((::QHostAddress::SpecialAddress)0);
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QHostAddress_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QHostAddress_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QHostAddress_HashFunc(PyObject* self) {
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
    return qHash(*cppSelf);
}

static int Sbk_QHostAddress_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHostAddress_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QHostAddress__repr__(PyObject* self)
{
    ::QHostAddress* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QHostAddress_TypeAsNumber;

static SbkObjectType Sbk_QHostAddress_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QHostAddress",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QHostAddress__repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QHostAddress_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QHostAddress_traverse,
    /*tp_clear*/            Sbk_QHostAddress_clear,
    /*tp_richcompare*/      Sbk_QHostAddress_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHostAddress_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QHostAddress_Init,
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
static void QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_SpecialAddress(PyObject* pyIn, void* cppOut) {
    *((::QHostAddress::SpecialAddress*)cppOut) = (::QHostAddress::SpecialAddress) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_SpecialAddress_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]))
        return QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_SpecialAddress;
    return 0;
}
static PyObject* QHostAddress_SpecialAddress_CppToPython_QHostAddress_SpecialAddress(const void* cppIn) {
    int castCppIn = *((::QHostAddress::SpecialAddress*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHostAddress_PythonToCpp_QHostAddress_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHostAddress_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHostAddress_PythonToCpp_QHostAddress_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHostAddress_Type))
        return QHostAddress_PythonToCpp_QHostAddress_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHostAddress_PTR_CppToPython_QHostAddress(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QHostAddress*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QHostAddress_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QHostAddress_COPY_CppToPython_QHostAddress(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QHostAddress_Type, new ::QHostAddress(*((::QHostAddress*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QHostAddress_PythonToCpp_QHostAddress_COPY(PyObject* pyIn, void* cppOut) {
    *((::QHostAddress*)cppOut) = *((::QHostAddress*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QHostAddress_PythonToCpp_QHostAddress_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHostAddress_Type))
        return QHostAddress_PythonToCpp_QHostAddress_COPY;
    return 0;
}

// Implicit conversions.
static void QHostAddress_SpecialAddress_PythonToCpp_QHostAddress(PyObject* pyIn, void* cppOut) {
    ::QHostAddress::SpecialAddress cppIn = ((::QHostAddress::SpecialAddress)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX]), pyIn, &cppIn);
    *((::QHostAddress*)cppOut) = ::QHostAddress(cppIn);
}
static PythonToCppFunc is_QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX], pyIn))
        return QHostAddress_SpecialAddress_PythonToCpp_QHostAddress;
    return 0;
}

void init_QHostAddress(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QHostAddress_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QHostAddress_TypeAsNumber.nb_rshift = Sbk_QHostAddressFunc___rshift__;
    Sbk_QHostAddress_TypeAsNumber.nb_lshift = Sbk_QHostAddressFunc___lshift__;
    SBK_NB_BOOL(Sbk_QHostAddress_TypeAsNumber) = Sbk_QHostAddress___nb_bool;
    Sbk_QHostAddress_Type.super.ht_type.tp_as_number = &Sbk_QHostAddress_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHostAddress_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHostAddress", "QHostAddress",
        &Sbk_QHostAddress_Type, &Shiboken::callCppDestructor< ::QHostAddress >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHostAddress_Type,
        QHostAddress_PythonToCpp_QHostAddress_PTR,
        is_QHostAddress_PythonToCpp_QHostAddress_PTR_Convertible,
        QHostAddress_PTR_CppToPython_QHostAddress,
        QHostAddress_COPY_CppToPython_QHostAddress);

    Shiboken::Conversions::registerConverterName(converter, "QHostAddress");
    Shiboken::Conversions::registerConverterName(converter, "QHostAddress*");
    Shiboken::Conversions::registerConverterName(converter, "QHostAddress&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHostAddress).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHostAddress_PythonToCpp_QHostAddress_COPY,
        is_QHostAddress_PythonToCpp_QHostAddress_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHostAddress_SpecialAddress_PythonToCpp_QHostAddress,
        is_QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_Convertible);

    // Initialization of enums.

    // Initialization of enum 'SpecialAddress'.
    SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHostAddress_Type,
        "SpecialAddress",
        "PySide.QtNetwork.QHostAddress.SpecialAddress",
        "QHostAddress::SpecialAddress");
    if (!SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "Null", (long) QHostAddress::Null))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "Broadcast", (long) QHostAddress::Broadcast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "LocalHost", (long) QHostAddress::LocalHost))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "LocalHostIPv6", (long) QHostAddress::LocalHostIPv6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "Any", (long) QHostAddress::Any))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
        &Sbk_QHostAddress_Type, "AnyIPv6", (long) QHostAddress::AnyIPv6))
        return ;
    // Register converter for enum 'QHostAddress::SpecialAddress'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX],
            QHostAddress_SpecialAddress_CppToPython_QHostAddress_SpecialAddress);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_SpecialAddress,
            is_QHostAddress_SpecialAddress_PythonToCpp_QHostAddress_SpecialAddress_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_SPECIALADDRESS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHostAddress::SpecialAddress");
        Shiboken::Conversions::registerConverterName(converter, "SpecialAddress");
    }
    // End of 'SpecialAddress' enum.


    qRegisterMetaType< ::QHostAddress >("QHostAddress");
    qRegisterMetaType< ::QHostAddress::SpecialAddress >("QHostAddress::SpecialAddress");
}
