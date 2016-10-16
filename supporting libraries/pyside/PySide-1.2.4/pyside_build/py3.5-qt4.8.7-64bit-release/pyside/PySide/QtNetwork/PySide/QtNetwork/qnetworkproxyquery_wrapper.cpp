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

#include "qnetworkproxyquery_wrapper.h"

// Extra includes
#include <qnetworkconfiguration.h>
#include <qnetworkproxy.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkProxyQuery_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkProxyQuery >()))
        return -1;

    ::QNetworkProxyQuery* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QNetworkProxyQuery", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkProxyQuery()
    // 1: QNetworkProxyQuery(QNetworkConfiguration,QString,int,QString,QNetworkProxyQuery::QueryType)
    // 2: QNetworkProxyQuery(QNetworkConfiguration,QUrl,QNetworkProxyQuery::QueryType)
    // 3: QNetworkProxyQuery(QNetworkConfiguration,quint16,QString,QNetworkProxyQuery::QueryType)
    // 4: QNetworkProxyQuery(QNetworkProxyQuery)
    // 5: QNetworkProxyQuery(QString,int,QString,QNetworkProxyQuery::QueryType)
    // 6: QNetworkProxyQuery(QUrl,QNetworkProxyQuery::QueryType)
    // 7: QNetworkProxyQuery(quint16,QString,QNetworkProxyQuery::QueryType)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkProxyQuery()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 7; // QNetworkProxyQuery(quint16,QString,QNetworkProxyQuery::QueryType)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 7; // QNetworkProxyQuery(quint16,QString,QNetworkProxyQuery::QueryType)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[2])))) {
                overloadId = 7; // QNetworkProxyQuery(quint16,QString,QNetworkProxyQuery::QueryType)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 5; // QNetworkProxyQuery(QString,int,QString,QNetworkProxyQuery::QueryType)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 5; // QNetworkProxyQuery(QString,int,QString,QNetworkProxyQuery::QueryType)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[3])))) {
                overloadId = 5; // QNetworkProxyQuery(QString,int,QString,QNetworkProxyQuery::QueryType)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // QNetworkProxyQuery(QUrl,QNetworkProxyQuery::QueryType)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 6; // QNetworkProxyQuery(QUrl,QNetworkProxyQuery::QueryType)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (pyArgs[0])))) {
        overloadId = 4; // QNetworkProxyQuery(QNetworkProxyQuery)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // QNetworkProxyQuery(QNetworkConfiguration,quint16,QString,QNetworkProxyQuery::QueryType)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // QNetworkProxyQuery(QNetworkConfiguration,quint16,QString,QNetworkProxyQuery::QueryType)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[3])))) {
                    overloadId = 3; // QNetworkProxyQuery(QNetworkConfiguration,quint16,QString,QNetworkProxyQuery::QueryType)
                }
            }
        } else if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // QNetworkProxyQuery(QNetworkConfiguration,QString,int,QString,QNetworkProxyQuery::QueryType)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 1; // QNetworkProxyQuery(QNetworkConfiguration,QString,int,QString,QNetworkProxyQuery::QueryType)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[4])))) {
                    overloadId = 1; // QNetworkProxyQuery(QNetworkConfiguration,QString,int,QString,QNetworkProxyQuery::QueryType)
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QNetworkProxyQuery(QNetworkConfiguration,QUrl,QNetworkProxyQuery::QueryType)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[2])))) {
                overloadId = 2; // QNetworkProxyQuery(QNetworkConfiguration,QUrl,QNetworkProxyQuery::QueryType)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQuery_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkProxyQuery()
        {

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkProxyQuery(const QNetworkConfiguration & networkConfiguration, const QString & hostname, int port, const QString & protocolTag, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "protocolTag");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'protocolTag'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[4]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
            ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QNetworkProxyQuery::QueryType cppArg4 = QNetworkProxyQuery::TcpSocket;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QNetworkConfiguration,QString,int,QString,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QNetworkProxyQuery(const QNetworkConfiguration & networkConfiguration, const QUrl & requestUrl, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
            ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QUrl cppArg1_local = ::QUrl();
            ::QUrl* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QNetworkProxyQuery::QueryType cppArg2 = QNetworkProxyQuery::UrlRequest;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QNetworkConfiguration,QUrl,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QNetworkProxyQuery(const QNetworkConfiguration & networkConfiguration, quint16 bindPort, const QString & protocolTag, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "protocolTag");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'protocolTag'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
            ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            quint16 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QNetworkProxyQuery::QueryType cppArg3 = QNetworkProxyQuery::TcpServer;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QNetworkConfiguration,quint16,QString,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QNetworkProxyQuery(const QNetworkProxyQuery & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkProxyQuery cppArg0_local = ::QNetworkProxyQuery();
            ::QNetworkProxyQuery* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QNetworkProxyQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QNetworkProxyQuery(const QString & hostname, int port, const QString & protocolTag, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "protocolTag");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'protocolTag'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[3]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QNetworkProxyQuery::QueryType cppArg3 = QNetworkProxyQuery::TcpSocket;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QString,int,QString,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QNetworkProxyQuery(const QUrl & requestUrl, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QNetworkProxyQuery::QueryType cppArg1 = QNetworkProxyQuery::UrlRequest;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(QUrl,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QNetworkProxyQuery(quint16 bindPort, const QString & protocolTag, QNetworkProxyQuery::QueryType queryType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "protocolTag");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'protocolTag'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "queryType");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkProxyQuery(): got multiple values for keyword argument 'queryType'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QNetworkProxyQuery_Init_TypeError;
                }
            }
            quint16 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QNetworkProxyQuery::QueryType cppArg2 = QNetworkProxyQuery::TcpServer;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QNetworkProxyQuery(quint16,QString,QNetworkProxyQuery::QueryType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkProxyQuery(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkProxyQuery >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkProxyQuery_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkProxyQuery_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkConfiguration, unicode, int, unicode = QString(), PySide.QtNetwork.QNetworkProxyQuery.QueryType = TcpSocket", "PySide.QtNetwork.QNetworkConfiguration, PySide.QtCore.QUrl, PySide.QtNetwork.QNetworkProxyQuery.QueryType = UrlRequest", "PySide.QtNetwork.QNetworkConfiguration, unsigned short, unicode = QString(), PySide.QtNetwork.QNetworkProxyQuery.QueryType = TcpServer", "PySide.QtNetwork.QNetworkProxyQuery", "unicode, int, unicode = QString(), PySide.QtNetwork.QNetworkProxyQuery.QueryType = TcpSocket", "PySide.QtCore.QUrl, PySide.QtNetwork.QNetworkProxyQuery.QueryType = UrlRequest", "unsigned short, unicode = QString(), PySide.QtNetwork.QNetworkProxyQuery.QueryType = TcpServer", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkProxyQuery", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_localPort(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localPort()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->localPort();
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

static PyObject* Sbk_QNetworkProxyQueryFunc_networkConfiguration(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // networkConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->networkConfiguration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_peerHostName(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerHostName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->peerHostName();
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

static PyObject* Sbk_QNetworkProxyQueryFunc_peerPort(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerPort()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->peerPort();
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

static PyObject* Sbk_QNetworkProxyQueryFunc_protocolTag(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocolTag()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->protocolTag();
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

static PyObject* Sbk_QNetworkProxyQueryFunc_queryType(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxyQuery::QueryType cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->queryType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setLocalPort(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocalPort(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLocalPort(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setLocalPort_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLocalPort(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocalPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setLocalPort_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setLocalPort", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setNetworkConfiguration(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNetworkConfiguration(QNetworkConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setNetworkConfiguration(QNetworkConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setNetworkConfiguration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
        ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setNetworkConfiguration(QNetworkConfiguration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNetworkConfiguration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setNetworkConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setNetworkConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setPeerHostName(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerHostName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPeerHostName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setPeerHostName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerHostName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerHostName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setPeerHostName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setPeerHostName", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setPeerPort(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerPort(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPeerPort(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setPeerPort_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerPort(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setPeerPort_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setPeerPort", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setProtocolTag(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProtocolTag(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setProtocolTag(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setProtocolTag_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProtocolTag(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProtocolTag(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setProtocolTag_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setProtocolTag", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setQueryType(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQueryType(QNetworkProxyQuery::QueryType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setQueryType(QNetworkProxyQuery::QueryType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setQueryType_TypeError;

    // Call function/method
    {
        ::QNetworkProxyQuery::QueryType cppArg0 = ((::QNetworkProxyQuery::QueryType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setQueryType(QNetworkProxyQuery::QueryType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setQueryType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setQueryType_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxyQuery.QueryType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setQueryType", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_setUrl(PyObject* self, PyObject* pyArg)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkProxyQueryFunc_setUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkProxyQueryFunc_setUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkProxyQuery.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkProxyQueryFunc_url(PyObject* self)
{
    ::QNetworkProxyQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QNetworkProxyQuery*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkProxyQuery___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkProxyQuery& cppSelf = *(((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkProxyQuery_methods[] = {
    {"localPort", (PyCFunction)Sbk_QNetworkProxyQueryFunc_localPort, METH_NOARGS},
    {"networkConfiguration", (PyCFunction)Sbk_QNetworkProxyQueryFunc_networkConfiguration, METH_NOARGS},
    {"peerHostName", (PyCFunction)Sbk_QNetworkProxyQueryFunc_peerHostName, METH_NOARGS},
    {"peerPort", (PyCFunction)Sbk_QNetworkProxyQueryFunc_peerPort, METH_NOARGS},
    {"protocolTag", (PyCFunction)Sbk_QNetworkProxyQueryFunc_protocolTag, METH_NOARGS},
    {"queryType", (PyCFunction)Sbk_QNetworkProxyQueryFunc_queryType, METH_NOARGS},
    {"setLocalPort", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setLocalPort, METH_O},
    {"setNetworkConfiguration", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setNetworkConfiguration, METH_O},
    {"setPeerHostName", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setPeerHostName, METH_O},
    {"setPeerPort", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setPeerPort, METH_O},
    {"setProtocolTag", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setProtocolTag, METH_O},
    {"setQueryType", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setQueryType, METH_O},
    {"setUrl", (PyCFunction)Sbk_QNetworkProxyQueryFunc_setUrl, METH_O},
    {"url", (PyCFunction)Sbk_QNetworkProxyQueryFunc_url, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkProxyQuery___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkProxyQuery_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkProxyQuery& cppSelf = *(((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (pyArg)))) {
                // operator!=(const QNetworkProxyQuery & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkProxyQuery cppArg0_local = ::QNetworkProxyQuery();
                ::QNetworkProxyQuery* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (pyArg)))) {
                // operator==(const QNetworkProxyQuery & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkProxyQuery cppArg0_local = ::QNetworkProxyQuery();
                ::QNetworkProxyQuery* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], pythonToCpp))
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
            goto Sbk_QNetworkProxyQuery_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkProxyQuery_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkProxyQuery_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkProxyQuery_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkProxyQuery_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkProxyQuery",
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
    /*tp_traverse*/         Sbk_QNetworkProxyQuery_traverse,
    /*tp_clear*/            Sbk_QNetworkProxyQuery_clear,
    /*tp_richcompare*/      Sbk_QNetworkProxyQuery_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkProxyQuery_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkProxyQuery_Init,
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
static void QNetworkProxyQuery_QueryType_PythonToCpp_QNetworkProxyQuery_QueryType(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxyQuery::QueryType*)cppOut) = (::QNetworkProxyQuery::QueryType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkProxyQuery_QueryType_PythonToCpp_QNetworkProxyQuery_QueryType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX]))
        return QNetworkProxyQuery_QueryType_PythonToCpp_QNetworkProxyQuery_QueryType;
    return 0;
}
static PyObject* QNetworkProxyQuery_QueryType_CppToPython_QNetworkProxyQuery_QueryType(const void* cppIn) {
    int castCppIn = *((::QNetworkProxyQuery::QueryType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkProxyQuery_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkProxyQuery_Type))
        return QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkProxyQuery_PTR_CppToPython_QNetworkProxyQuery(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkProxyQuery*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkProxyQuery_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkProxyQuery_COPY_CppToPython_QNetworkProxyQuery(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkProxyQuery_Type, new ::QNetworkProxyQuery(*((::QNetworkProxyQuery*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxyQuery*)cppOut) = *((::QNetworkProxyQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkProxyQuery_Type))
        return QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQUrlREF_PythonToCpp_QNetworkProxyQuery(PyObject* pyIn, void* cppOut) {
    *((::QNetworkProxyQuery*)cppOut) = ::QNetworkProxyQuery(*((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_constQUrlREF_PythonToCpp_QNetworkProxyQuery_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return PySide_QtCore_constQUrlREF_PythonToCpp_QNetworkProxyQuery;
    return 0;
}

static void PySide_QtCore_quint16_PythonToCpp_QNetworkProxyQuery(PyObject* pyIn, void* cppOut) {
    quint16 cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), pyIn, &cppIn);
    *((::QNetworkProxyQuery*)cppOut) = ::QNetworkProxyQuery(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_quint16_PythonToCpp_QNetworkProxyQuery_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_quint16_PythonToCpp_QNetworkProxyQuery;
    return 0;
}

void init_QNetworkProxyQuery(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkProxyQuery_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkProxyQuery", "QNetworkProxyQuery",
        &Sbk_QNetworkProxyQuery_Type, &Shiboken::callCppDestructor< ::QNetworkProxyQuery >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkProxyQuery_Type,
        QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_PTR,
        is_QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_PTR_Convertible,
        QNetworkProxyQuery_PTR_CppToPython_QNetworkProxyQuery,
        QNetworkProxyQuery_COPY_CppToPython_QNetworkProxyQuery);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxyQuery");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxyQuery*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkProxyQuery&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkProxyQuery).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_COPY,
        is_QNetworkProxyQuery_PythonToCpp_QNetworkProxyQuery_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQUrlREF_PythonToCpp_QNetworkProxyQuery,
        is_PySide_QtCore_constQUrlREF_PythonToCpp_QNetworkProxyQuery_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_quint16_PythonToCpp_QNetworkProxyQuery,
        is_PySide_QtCore_quint16_PythonToCpp_QNetworkProxyQuery_Convertible);

    // Initialization of enums.

    // Initialization of enum 'QueryType'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkProxyQuery_Type,
        "QueryType",
        "PySide.QtNetwork.QNetworkProxyQuery.QueryType",
        "QNetworkProxyQuery::QueryType");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX],
        &Sbk_QNetworkProxyQuery_Type, "TcpSocket", (long) QNetworkProxyQuery::TcpSocket))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX],
        &Sbk_QNetworkProxyQuery_Type, "UdpSocket", (long) QNetworkProxyQuery::UdpSocket))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX],
        &Sbk_QNetworkProxyQuery_Type, "TcpServer", (long) QNetworkProxyQuery::TcpServer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX],
        &Sbk_QNetworkProxyQuery_Type, "UrlRequest", (long) QNetworkProxyQuery::UrlRequest))
        return ;
    // Register converter for enum 'QNetworkProxyQuery::QueryType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX],
            QNetworkProxyQuery_QueryType_CppToPython_QNetworkProxyQuery_QueryType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkProxyQuery_QueryType_PythonToCpp_QNetworkProxyQuery_QueryType,
            is_QNetworkProxyQuery_QueryType_PythonToCpp_QNetworkProxyQuery_QueryType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYQUERY_QUERYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkProxyQuery::QueryType");
        Shiboken::Conversions::registerConverterName(converter, "QueryType");
    }
    // End of 'QueryType' enum.


    qRegisterMetaType< ::QNetworkProxyQuery >("QNetworkProxyQuery");
    qRegisterMetaType< ::QNetworkProxyQuery::QueryType >("QNetworkProxyQuery::QueryType");
}
