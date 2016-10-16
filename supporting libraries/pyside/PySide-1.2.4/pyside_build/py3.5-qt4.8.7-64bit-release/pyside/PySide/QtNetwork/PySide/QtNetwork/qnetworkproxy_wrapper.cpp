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

#include "qnetworkproxy_wrapper.h"

// Extra includes
#include <qnetworkproxy.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkProxy_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkProxy >()))
        return -1;

    ::QNetworkProxy* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxy(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QNetworkProxy", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkProxy()
    // 1: QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
    // 2: QNetworkProxy(QNetworkProxy)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkProxy()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 1; // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 1; // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
                    }
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArgs[0])))) {
        overloadId = 2; // QNetworkProxy(QNetworkProxy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxy_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkProxy()
        {

            if (!PyErr_Occurred()) {
                // QNetworkProxy()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxy();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkProxy(QNetworkProxy::ProxyType type, const QString & hostName, quint16 port, const QString & user, const QString & password)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "hostName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxy(): got multiple values for keyword argument 'hostName'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QNetworkProxy_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "port");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxy(): got multiple values for keyword argument 'port'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2]))))
                        goto Sbk_QNetworkProxy_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "user");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxy(): got multiple values for keyword argument 'user'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QNetworkProxy_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "password");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxy(): got multiple values for keyword argument 'password'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                        goto Sbk_QNetworkProxy_Init_TypeError;
                }
            }
            ::QNetworkProxy::ProxyType cppArg0 = ((::QNetworkProxy::ProxyType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            quint16 cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QString cppArg4 = QString();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QNetworkProxy(QNetworkProxy::ProxyType,QString,quint16,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxy(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QNetworkProxy(const QNetworkProxy & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
            ::QNetworkProxy* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkProxy(QNetworkProxy)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkProxy >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkProxy_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkProxy_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkProxy.ProxyType, unicode = QString(), unsigned short = 0, unicode = QString(), unicode = QString()", "PySide.QtNetwork.QNetworkProxy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkProxy", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkProxyFunc_applicationProxy(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationProxy()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxy cppResult = ::QNetworkProxy::applicationProxy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyFunc_capabilities(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capabilities()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QNetworkProxy::Capability> cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->capabilities();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyFunc_hostName(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hostName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->hostName();
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

static PyObject* Sbk_QNetworkProxyFunc_isCachingProxy(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCachingProxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->isCachingProxy();
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

static PyObject* Sbk_QNetworkProxyFunc_isTransparentProxy(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isTransparentProxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->isTransparentProxy();
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

static PyObject* Sbk_QNetworkProxyFunc_password(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // password()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->password();
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

static PyObject* Sbk_QNetworkProxyFunc_port(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // port()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint16 cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->port();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyFunc_setApplicationProxy(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setApplicationProxy(QNetworkProxy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArg)))) {
        overloadId = 0; // setApplicationProxy(QNetworkProxy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setApplicationProxy_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
        ::QNetworkProxy* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setApplicationProxy(QNetworkProxy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QNetworkProxy::setApplicationProxy(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setApplicationProxy_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setApplicationProxy", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setCapabilities(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCapabilities(QFlags<QNetworkProxy::Capability>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), (pyArg)))) {
        overloadId = 0; // setCapabilities(QFlags<QNetworkProxy::Capability>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setCapabilities_TypeError;

    // Call function/method
    {
        ::QFlags<QNetworkProxy::Capability> cppArg0 = ((::QFlags<QNetworkProxy::Capability>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCapabilities(QFlags<QNetworkProxy::Capability>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCapabilities(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setCapabilities_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy.Capabilities", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setCapabilities", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setHostName(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHostName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHostName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setHostName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHostName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHostName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setHostName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setHostName", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setPassword(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPassword(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPassword(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setPassword_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPassword(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPassword(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setPassword_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setPassword", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setPort(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPort(quint16)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArg)))) {
        overloadId = 0; // setPort(quint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setPort_TypeError;

    // Call function/method
    {
        quint16 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPort(quint16)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setPort_TypeError:
        const char* overloads[] = {"unsigned short", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setPort", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setType(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(QNetworkProxy::ProxyType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setType(QNetworkProxy::ProxyType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setType_TypeError;

    // Call function/method
    {
        ::QNetworkProxy::ProxyType cppArg0 = ((::QNetworkProxy::ProxyType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(QNetworkProxy::ProxyType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setType_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy.ProxyType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setType", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_setUser(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUser(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setUser(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyFunc_setUser_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUser(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUser(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyFunc_setUser_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxy.setUser", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyFunc_type(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxy::ProxyType cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyFunc_user(PyObject* self)
{
    ::QNetworkProxy* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // user()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkProxy*>(cppSelf)->user();
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

static PyObject* Sbk_QNetworkProxy___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkProxy& cppSelf = *(((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkProxy_methods[] = {
    {"applicationProxy", (PyCFunction)Sbk_QNetworkProxyFunc_applicationProxy, METH_NOARGS|METH_STATIC},
    {"capabilities", (PyCFunction)Sbk_QNetworkProxyFunc_capabilities, METH_NOARGS},
    {"hostName", (PyCFunction)Sbk_QNetworkProxyFunc_hostName, METH_NOARGS},
    {"isCachingProxy", (PyCFunction)Sbk_QNetworkProxyFunc_isCachingProxy, METH_NOARGS},
    {"isTransparentProxy", (PyCFunction)Sbk_QNetworkProxyFunc_isTransparentProxy, METH_NOARGS},
    {"password", (PyCFunction)Sbk_QNetworkProxyFunc_password, METH_NOARGS},
    {"port", (PyCFunction)Sbk_QNetworkProxyFunc_port, METH_NOARGS},
    {"setApplicationProxy", (PyCFunction)Sbk_QNetworkProxyFunc_setApplicationProxy, METH_O|METH_STATIC},
    {"setCapabilities", (PyCFunction)Sbk_QNetworkProxyFunc_setCapabilities, METH_O},
    {"setHostName", (PyCFunction)Sbk_QNetworkProxyFunc_setHostName, METH_O},
    {"setPassword", (PyCFunction)Sbk_QNetworkProxyFunc_setPassword, METH_O},
    {"setPort", (PyCFunction)Sbk_QNetworkProxyFunc_setPort, METH_O},
    {"setType", (PyCFunction)Sbk_QNetworkProxyFunc_setType, METH_O},
    {"setUser", (PyCFunction)Sbk_QNetworkProxyFunc_setUser, METH_O},
    {"type", (PyCFunction)Sbk_QNetworkProxyFunc_type, METH_NOARGS},
    {"user", (PyCFunction)Sbk_QNetworkProxyFunc_user, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkProxy___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkProxy_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkProxy& cppSelf = *(((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArg)))) {
                // operator!=(const QNetworkProxy & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
                ::QNetworkProxy* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArg)))) {
                // operator==(const QNetworkProxy & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
                ::QNetworkProxy* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp))
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
            goto Sbk_QNetworkProxy_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkProxy_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkProxy_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkProxy_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkProxy_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkProxy",
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
    /*tp_traverse*/         Sbk_QNetworkProxy_traverse,
    /*tp_clear*/            Sbk_QNetworkProxy_clear,
    /*tp_richcompare*/      Sbk_QNetworkProxy_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkProxy_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkProxy_Init,
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

PyObject* SbkPySide_QtNetwork_QNetworkProxy_Capability___and__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkProxy::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkProxy::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkProxy_Capability___or__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkProxy::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkProxy::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkProxy_Capability___xor__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkProxy::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkProxy::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkProxy::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkProxy_Capability___invert__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxy::Capabilities cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), self, &cppSelf);
    ::QNetworkProxy::Capabilities cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtNetwork_QNetworkProxy_Capability_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtNetwork_QNetworkProxy_Capability__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtNetwork_QNetworkProxy_Capability_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtNetwork_QNetworkProxy_Capability__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtNetwork_QNetworkProxy_Capability___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkProxy_Capability___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkProxy_Capability___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtNetwork_QNetworkProxy_Capability___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtNetwork_QNetworkProxy_Capability_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtNetwork_QNetworkProxy_Capability_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_ProxyType(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxy::ProxyType*)cppOut) = (::QNetworkProxy::ProxyType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_ProxyType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX]))
        return QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_ProxyType;
    return 0;
}
static PyObject* QNetworkProxy_ProxyType_CppToPython_QNetworkProxy_ProxyType(const void* cppIn) {
    int castCppIn = *((::QNetworkProxy::ProxyType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX], castCppIn);

}

static void QNetworkProxy_Capability_PythonToCpp_QNetworkProxy_Capability(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxy::Capability*)cppOut) = (::QNetworkProxy::Capability) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkProxy_Capability_PythonToCpp_QNetworkProxy_Capability_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX]))
        return QNetworkProxy_Capability_PythonToCpp_QNetworkProxy_Capability;
    return 0;
}
static PyObject* QNetworkProxy_Capability_CppToPython_QNetworkProxy_Capability(const void* cppIn) {
    int castCppIn = *((::QNetworkProxy::Capability*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX], castCppIn);

}

static void QFlags_QNetworkProxy_Capability__PythonToCpp_QFlags_QNetworkProxy_Capability_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkProxy::Capability>*)cppOut) = ::QFlags<QNetworkProxy::Capability>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QNetworkProxy_Capability__PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]))
        return QFlags_QNetworkProxy_Capability__PythonToCpp_QFlags_QNetworkProxy_Capability_;
    return 0;
}
static PyObject* QFlags_QNetworkProxy_Capability__CppToPython_QFlags_QNetworkProxy_Capability_(const void* cppIn) {
    int castCppIn = *((::QFlags<QNetworkProxy::Capability>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]));

}

static void QNetworkProxy_Capability_PythonToCpp_QFlags_QNetworkProxy_Capability_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkProxy::Capability>*)cppOut) = ::QFlags<QNetworkProxy::Capability>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QNetworkProxy_Capability_PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX]))
        return QNetworkProxy_Capability_PythonToCpp_QFlags_QNetworkProxy_Capability_;
    return 0;
}
static void number_PythonToCpp_QFlags_QNetworkProxy_Capability_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QNetworkProxy::Capability>*)cppOut) = ::QFlags<QNetworkProxy::Capability>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QNetworkProxy_Capability_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkProxy_PythonToCpp_QNetworkProxy_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkProxy_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkProxy_PythonToCpp_QNetworkProxy_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkProxy_Type))
        return QNetworkProxy_PythonToCpp_QNetworkProxy_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkProxy_PTR_CppToPython_QNetworkProxy(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkProxy*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkProxy_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkProxy_COPY_CppToPython_QNetworkProxy(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkProxy_Type, new ::QNetworkProxy(*((::QNetworkProxy*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkProxy_PythonToCpp_QNetworkProxy_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxy*)cppOut) = *((::QNetworkProxy*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkProxy_PythonToCpp_QNetworkProxy_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkProxy_Type))
        return QNetworkProxy_PythonToCpp_QNetworkProxy_COPY;
    return 0;
}

// Implicit conversions.
static void QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy(PyObject* pyIn, void* cppOut) {
    ::QNetworkProxy::ProxyType cppIn = ((::QNetworkProxy::ProxyType)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX]), pyIn, &cppIn);
    *((::QNetworkProxy*)cppOut) = ::QNetworkProxy(cppIn);
}
static PythonToCppFunc is_QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX], pyIn))
        return QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy;
    return 0;
}

void init_QNetworkProxy(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkProxy_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkProxy", "QNetworkProxy",
        &Sbk_QNetworkProxy_Type, &Shiboken::callCppDestructor< ::QNetworkProxy >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkProxy_Type,
        QNetworkProxy_PythonToCpp_QNetworkProxy_PTR,
        is_QNetworkProxy_PythonToCpp_QNetworkProxy_PTR_Convertible,
        QNetworkProxy_PTR_CppToPython_QNetworkProxy,
        QNetworkProxy_COPY_CppToPython_QNetworkProxy);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxy");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxy*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxy&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkProxy).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkProxy_PythonToCpp_QNetworkProxy_COPY,
        is_QNetworkProxy_PythonToCpp_QNetworkProxy_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy,
        is_QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ProxyType'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkProxy_Type,
        "ProxyType",
        "PySide.QtNetwork.QNetworkProxy.ProxyType",
        "QNetworkProxy::ProxyType");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "DefaultProxy", (long) QNetworkProxy::DefaultProxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "Socks5Proxy", (long) QNetworkProxy::Socks5Proxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "NoProxy", (long) QNetworkProxy::NoProxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "HttpProxy", (long) QNetworkProxy::HttpProxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "HttpCachingProxy", (long) QNetworkProxy::HttpCachingProxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
        &Sbk_QNetworkProxy_Type, "FtpCachingProxy", (long) QNetworkProxy::FtpCachingProxy))
        return ;
    // Register converter for enum 'QNetworkProxy::ProxyType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX],
            QNetworkProxy_ProxyType_CppToPython_QNetworkProxy_ProxyType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_ProxyType,
            is_QNetworkProxy_ProxyType_PythonToCpp_QNetworkProxy_ProxyType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_PROXYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkProxy::ProxyType");
        Shiboken::Conversions::registerConverterName(converter, "ProxyType");
    }
    // End of 'ProxyType' enum.

    // Initialization of enum 'Capability'.
    SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX] = PySide::QFlags::create("Capabilities", &SbkPySide_QtNetwork_QNetworkProxy_Capability_as_number);
    SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkProxy_Type,
        "Capability",
        "PySide.QtNetwork.QNetworkProxy.Capability",
        "QNetworkProxy::Capability",
        SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX]);
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
        &Sbk_QNetworkProxy_Type, "TunnelingCapability", (long) QNetworkProxy::TunnelingCapability))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
        &Sbk_QNetworkProxy_Type, "ListeningCapability", (long) QNetworkProxy::ListeningCapability))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
        &Sbk_QNetworkProxy_Type, "UdpTunnelingCapability", (long) QNetworkProxy::UdpTunnelingCapability))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
        &Sbk_QNetworkProxy_Type, "CachingCapability", (long) QNetworkProxy::CachingCapability))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
        &Sbk_QNetworkProxy_Type, "HostNameLookupCapability", (long) QNetworkProxy::HostNameLookupCapability))
        return ;
    // Register converter for enum 'QNetworkProxy::Capability'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX],
            QNetworkProxy_Capability_CppToPython_QNetworkProxy_Capability);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkProxy_Capability_PythonToCpp_QNetworkProxy_Capability,
            is_QNetworkProxy_Capability_PythonToCpp_QNetworkProxy_Capability_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_CAPABILITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkProxy::Capability");
        Shiboken::Conversions::registerConverterName(converter, "Capability");
    }
    // Register converter for flag 'QFlags<QNetworkProxy::Capability>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX],
            QFlags_QNetworkProxy_Capability__CppToPython_QFlags_QNetworkProxy_Capability_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkProxy_Capability_PythonToCpp_QFlags_QNetworkProxy_Capability_,
            is_QNetworkProxy_Capability_PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QNetworkProxy_Capability__PythonToCpp_QFlags_QNetworkProxy_Capability_,
            is_QFlags_QNetworkProxy_Capability__PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QNetworkProxy_Capability_,
            is_number_PythonToCpp_QFlags_QNetworkProxy_Capability__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKPROXY_CAPABILITY__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QNetworkProxy::Capability>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Capability>");
    }
    // End of 'Capability' enum/flags.


    qRegisterMetaType< ::QNetworkProxy >("QNetworkProxy");
    qRegisterMetaType< ::QNetworkProxy::ProxyType >("QNetworkProxy::ProxyType");
    qRegisterMetaType< ::QNetworkProxy::Capability >("QNetworkProxy::Capability");
    qRegisterMetaType< ::QNetworkProxy::Capabilities >("QNetworkProxy::Capabilities");
}
