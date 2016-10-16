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


#include <sbkpython.h>
#include <shiboken.h>
#include <algorithm>
#include <pyside.h>
#include "pyside_qtnetwork_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtNetworkTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtNetworkTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtNetwork_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtNetworkTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef QtNetwork_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QNetworkRequest(PyObject* module);
void init_QNetworkCookie(PyObject* module);
void init_QNetworkConfiguration(PyObject* module);
void init_QIPv6Address(PyObject* module);
void init_QHostAddress(PyObject* module);
void init_QNetworkAddressEntry(PyObject* module);
void init_QNetworkInterface(PyObject* module);
void init_QNetworkCacheMetaData(PyObject* module);
void init_QUrlInfo(PyObject* module);
void init_QHttpHeader(PyObject* module);
void init_QHttpResponseHeader(PyObject* module);
void init_QHttpRequestHeader(PyObject* module);
void init_QSslCipher(PyObject* module);
void init_QSslError(PyObject* module);
void init_QSslConfiguration(PyObject* module);
void init_QAuthenticator(PyObject* module);
void init_QHostInfo(PyObject* module);
void init_QNetworkProxyQuery(PyObject* module);
void init_QNetworkProxyFactory(PyObject* module);
void init_QNetworkProxy(PyObject* module);
void init_QLocalSocket(PyObject* module);
void init_QAbstractSocket(PyObject* module);
void init_QTcpSocket(PyObject* module);
void init_QUdpSocket(PyObject* module);
void init_QNetworkReply(PyObject* module);
void init_QHttp(PyObject* module);
void init_QNetworkAccessManager(PyObject* module);
void init_QNetworkCookieJar(PyObject* module);
void init_QNetworkSession(PyObject* module);
void init_QAbstractNetworkCache(PyObject* module);
void init_QNetworkDiskCache(PyObject* module);
void init_QFtp(PyObject* module);
void init_QLocalServer(PyObject* module);
void init_QTcpServer(PyObject* module);
void init_QNetworkConfigurationManager(PyObject* module);
void init_QSsl(PyObject* module);
void init_QSslCertificate(PyObject* module);
void init_QSslSocket(PyObject* module);
void init_QSslKey(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QList<QNetworkProxy >'.
static PyObject* _QList_QNetworkProxy__CppToPython__QList_QNetworkProxy_(const void* cppIn) {
    ::QList<QNetworkProxy >& cppInRef = *((::QList<QNetworkProxy >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QNetworkProxy >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QNetworkProxy cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QNetworkProxy__PythonToCpp__QList_QNetworkProxy_(PyObject* pyIn, void* cppOut) {
    ::QList<QNetworkProxy >& cppOutRef = *((::QList<QNetworkProxy >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QNetworkProxy cppItem = ::QNetworkProxy();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QNetworkProxy__PythonToCpp__QList_QNetworkProxy__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pyIn))
        return _QList_QNetworkProxy__PythonToCpp__QList_QNetworkProxy_;
    return 0;
}

// C++ to Python conversion for type 'QList<QHostAddress >'.
static PyObject* _QList_QHostAddress__CppToPython__QList_QHostAddress_(const void* cppIn) {
    ::QList<QHostAddress >& cppInRef = *((::QList<QHostAddress >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QHostAddress >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QHostAddress cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QHostAddress__PythonToCpp__QList_QHostAddress_(PyObject* pyIn, void* cppOut) {
    ::QList<QHostAddress >& cppOutRef = *((::QList<QHostAddress >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QHostAddress cppItem = ::QHostAddress();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QHostAddress__PythonToCpp__QList_QHostAddress__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pyIn))
        return _QList_QHostAddress__PythonToCpp__QList_QHostAddress_;
    return 0;
}

// C++ to Python conversion for type 'QHash<QString, QVariant >'.
static PyObject* _QHash_QString_QVariant__CppToPython__QHash_QString_QVariant_(const void* cppIn) {
    ::QHash<QString, QVariant >& cppInRef = *((::QHash<QString, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QHash<QString, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QString key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QHash_QString_QVariant__PythonToCpp__QHash_QString_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QHash<QString, QVariant >& cppOutRef = *((::QHash<QString, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QHash_QString_QVariant__PythonToCpp__QHash_QString_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QHash_QString_QVariant__PythonToCpp__QHash_QString_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'QList<QSslCertificate >'.
static PyObject* _QList_QSslCertificate__CppToPython__QList_QSslCertificate_(const void* cppIn) {
    ::QList<QSslCertificate >& cppInRef = *((::QList<QSslCertificate >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QSslCertificate >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QSslCertificate cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QSslCertificate__PythonToCpp__QList_QSslCertificate_(PyObject* pyIn, void* cppOut) {
    ::QList<QSslCertificate >& cppOutRef = *((::QList<QSslCertificate >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QSslCertificate cppItem = ::QSslCertificate(((::QIODevice*)0));
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QSslCertificate__PythonToCpp__QList_QSslCertificate__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pyIn))
        return _QList_QSslCertificate__PythonToCpp__QList_QSslCertificate_;
    return 0;
}

// C++ to Python conversion for type 'QList<QSslCipher >'.
static PyObject* _QList_QSslCipher__CppToPython__QList_QSslCipher_(const void* cppIn) {
    ::QList<QSslCipher >& cppInRef = *((::QList<QSslCipher >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QSslCipher >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QSslCipher cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QSslCipher__PythonToCpp__QList_QSslCipher_(PyObject* pyIn, void* cppOut) {
    ::QList<QSslCipher >& cppOutRef = *((::QList<QSslCipher >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QSslCipher cppItem = ::QSslCipher();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QSslCipher__PythonToCpp__QList_QSslCipher__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], pyIn))
        return _QList_QSslCipher__PythonToCpp__QList_QSslCipher_;
    return 0;
}

// C++ to Python conversion for type 'QPair<QString, QString >'.
static PyObject* _QPair_QString_QString__CppToPython__QPair_QString_QString_(const void* cppIn) {
    ::QPair<QString, QString >& cppInRef = *((::QPair<QString, QString >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.second));
            return pyOut;

}
static void _QPair_QString_QString__PythonToCpp__QPair_QString_QString_(PyObject* pyIn, void* cppOut) {
    ::QPair<QString, QString >& cppOutRef = *((::QPair<QString, QString >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_QString_QString__PythonToCpp__QPair_QString_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return _QPair_QString_QString__PythonToCpp__QPair_QString_QString_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QPair<QString, QString > > &'.
static PyObject* _constQList_QPair_QString_QString__REF_CppToPython__constQList_QPair_QString_QString__REF(const void* cppIn) {
    ::QList<QPair<QString, QString > >& cppInRef = *((::QList<QPair<QString, QString > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QString, QString > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QString, QString > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QPair_QString_QString__REF_PythonToCpp__constQList_QPair_QString_QString__REF(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QString, QString > >& cppOutRef = *((::QList<QPair<QString, QString > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QString, QString > cppItem = ::QPair<QString, QString >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QPair_QString_QString__REF_PythonToCpp__constQList_QPair_QString_QString__REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX], pyIn))
        return _constQList_QPair_QString_QString__REF_PythonToCpp__constQList_QPair_QString_QString__REF;
    return 0;
}

// C++ to Python conversion for type 'QHash<QNetworkRequest::Attribute, QVariant >'.
static PyObject* _QHash_QNetworkRequest_Attribute_QVariant__CppToPython__QHash_QNetworkRequest_Attribute_QVariant_(const void* cppIn) {
    ::QHash<QNetworkRequest::Attribute, QVariant >& cppInRef = *((::QHash<QNetworkRequest::Attribute, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QHash<QNetworkRequest::Attribute, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QNetworkRequest::Attribute key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QHash_QNetworkRequest_Attribute_QVariant__PythonToCpp__QHash_QNetworkRequest_Attribute_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QHash<QNetworkRequest::Attribute, QVariant >& cppOutRef = *((::QHash<QNetworkRequest::Attribute, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QNetworkRequest::Attribute cppKey = ((::QNetworkRequest::Attribute)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QHash_QNetworkRequest_Attribute_QVariant__PythonToCpp__QHash_QNetworkRequest_Attribute_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QHash_QNetworkRequest_Attribute_QVariant__PythonToCpp__QHash_QNetworkRequest_Attribute_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'QPair<QByteArray, QByteArray >'.
static PyObject* _QPair_QByteArray_QByteArray__CppToPython__QPair_QByteArray_QByteArray_(const void* cppIn) {
    ::QPair<QByteArray, QByteArray >& cppInRef = *((::QPair<QByteArray, QByteArray >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppInRef.second));
            return pyOut;

}
static void _QPair_QByteArray_QByteArray__PythonToCpp__QPair_QByteArray_QByteArray_(PyObject* pyIn, void* cppOut) {
    ::QPair<QByteArray, QByteArray >& cppOutRef = *((::QPair<QByteArray, QByteArray >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_QByteArray_QByteArray__PythonToCpp__QPair_QByteArray_QByteArray__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, pyIn))
        return _QPair_QByteArray_QByteArray__PythonToCpp__QPair_QByteArray_QByteArray_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<QByteArray, QByteArray > >'.
static PyObject* _QList_QPair_QByteArray_QByteArray___CppToPython__QList_QPair_QByteArray_QByteArray__(const void* cppIn) {
    ::QList<QPair<QByteArray, QByteArray > >& cppInRef = *((::QList<QPair<QByteArray, QByteArray > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QByteArray, QByteArray > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QByteArray, QByteArray > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPair_QByteArray_QByteArray___PythonToCpp__QList_QPair_QByteArray_QByteArray__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QByteArray, QByteArray > >& cppOutRef = *((::QList<QPair<QByteArray, QByteArray > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QByteArray, QByteArray > cppItem = ::QPair<QByteArray, QByteArray >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPair_QByteArray_QByteArray___PythonToCpp__QList_QPair_QByteArray_QByteArray___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], pyIn))
        return _QList_QPair_QByteArray_QByteArray___PythonToCpp__QList_QPair_QByteArray_QByteArray__;
    return 0;
}

// C++ to Python conversion for type 'QList<QNetworkAddressEntry >'.
static PyObject* _QList_QNetworkAddressEntry__CppToPython__QList_QNetworkAddressEntry_(const void* cppIn) {
    ::QList<QNetworkAddressEntry >& cppInRef = *((::QList<QNetworkAddressEntry >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QNetworkAddressEntry >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QNetworkAddressEntry cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QNetworkAddressEntry__PythonToCpp__QList_QNetworkAddressEntry_(PyObject* pyIn, void* cppOut) {
    ::QList<QNetworkAddressEntry >& cppOutRef = *((::QList<QNetworkAddressEntry >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QNetworkAddressEntry cppItem = ::QNetworkAddressEntry();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QNetworkAddressEntry__PythonToCpp__QList_QNetworkAddressEntry__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], pyIn))
        return _QList_QNetworkAddressEntry__PythonToCpp__QList_QNetworkAddressEntry_;
    return 0;
}

// C++ to Python conversion for type 'QList<QNetworkInterface >'.
static PyObject* _QList_QNetworkInterface__CppToPython__QList_QNetworkInterface_(const void* cppIn) {
    ::QList<QNetworkInterface >& cppInRef = *((::QList<QNetworkInterface >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QNetworkInterface >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QNetworkInterface cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QNetworkInterface__PythonToCpp__QList_QNetworkInterface_(PyObject* pyIn, void* cppOut) {
    ::QList<QNetworkInterface >& cppOutRef = *((::QList<QNetworkInterface >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QNetworkInterface cppItem = ::QNetworkInterface();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QNetworkInterface__PythonToCpp__QList_QNetworkInterface__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], pyIn))
        return _QList_QNetworkInterface__PythonToCpp__QList_QNetworkInterface_;
    return 0;
}

// C++ to Python conversion for type 'const QPair<QHostAddress, int > &'.
static PyObject* _constQPair_QHostAddress_int_REF_CppToPython__constQPair_QHostAddress_int_REF(const void* cppIn) {
    ::QPair<QHostAddress, int >& cppInRef = *((::QPair<QHostAddress, int >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppInRef.second));
            return pyOut;

}
static void _constQPair_QHostAddress_int_REF_PythonToCpp__constQPair_QHostAddress_int_REF(PyObject* pyIn, void* cppOut) {
    ::QPair<QHostAddress, int >& cppOutRef = *((::QPair<QHostAddress, int >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__constQPair_QHostAddress_int_REF_PythonToCpp__constQPair_QHostAddress_int_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX]), false, Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, pyIn))
        return _constQPair_QHostAddress_int_REF_PythonToCpp__constQPair_QHostAddress_int_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QNetworkConfiguration >'.
static PyObject* _QList_QNetworkConfiguration__CppToPython__QList_QNetworkConfiguration_(const void* cppIn) {
    ::QList<QNetworkConfiguration >& cppInRef = *((::QList<QNetworkConfiguration >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QNetworkConfiguration >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QNetworkConfiguration cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QNetworkConfiguration__PythonToCpp__QList_QNetworkConfiguration_(PyObject* pyIn, void* cppOut) {
    ::QList<QNetworkConfiguration >& cppOutRef = *((::QList<QNetworkConfiguration >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QNetworkConfiguration cppItem = ::QNetworkConfiguration();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QNetworkConfiguration__PythonToCpp__QList_QNetworkConfiguration__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pyIn))
        return _QList_QNetworkConfiguration__PythonToCpp__QList_QNetworkConfiguration_;
    return 0;
}

// C++ to Python conversion for type 'QList<QNetworkCookie >'.
static PyObject* _QList_QNetworkCookie__CppToPython__QList_QNetworkCookie_(const void* cppIn) {
    ::QList<QNetworkCookie >& cppInRef = *((::QList<QNetworkCookie >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QNetworkCookie >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QNetworkCookie cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QNetworkCookie__PythonToCpp__QList_QNetworkCookie_(PyObject* pyIn, void* cppOut) {
    ::QList<QNetworkCookie >& cppOutRef = *((::QList<QNetworkCookie >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QNetworkCookie cppItem = ::QNetworkCookie(::QByteArray(), ::QByteArray());
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QNetworkCookie__PythonToCpp__QList_QNetworkCookie__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], pyIn))
        return _QList_QNetworkCookie__PythonToCpp__QList_QNetworkCookie_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QObject * > &'.
static PyObject* _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF(const void* cppIn) {
    ::QList<QObject * >& cppInRef = *((::QList<QObject * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QObject * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QObject* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QObject * >& cppOutRef = *((::QList<QObject * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QObject* cppItem = ((::QObject*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyIn))
        return _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<QByteArray >'.
static PyObject* _QList_QByteArray__CppToPython__QList_QByteArray_(const void* cppIn) {
    ::QList<QByteArray >& cppInRef = *((::QList<QByteArray >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QByteArray >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QByteArray cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QByteArray__PythonToCpp__QList_QByteArray_(PyObject* pyIn, void* cppOut) {
    ::QList<QByteArray >& cppOutRef = *((::QList<QByteArray >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QByteArray cppItem = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyIn))
        return _QList_QByteArray__PythonToCpp__QList_QByteArray_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QSslError > &'.
static PyObject* _constQList_QSslError_REF_CppToPython__constQList_QSslError_REF(const void* cppIn) {
    ::QList<QSslError >& cppInRef = *((::QList<QSslError >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QSslError >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QSslError cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_QSslError_REF_PythonToCpp__constQList_QSslError_REF(PyObject* pyIn, void* cppOut) {
    ::QList<QSslError >& cppOutRef = *((::QList<QSslError >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QSslError cppItem = ::QSslError();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_QSslError_REF_PythonToCpp__constQList_QSslError_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLERROR_IDX], pyIn))
        return _constQList_QSslError_REF_PythonToCpp__constQList_QSslError_REF;
    return 0;
}

// C++ to Python conversion for type 'QMultiMap<QSsl::AlternateNameEntryType, QString >'.
static PyObject* _QMultiMap_QSsl_AlternateNameEntryType_QString__CppToPython__QMultiMap_QSsl_AlternateNameEntryType_QString_(const void* cppIn) {
    ::QMultiMap<QSsl::AlternateNameEntryType, QString >& cppInRef = *((::QMultiMap<QSsl::AlternateNameEntryType, QString >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMultiMap<QSsl::AlternateNameEntryType, QString >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QSsl::AlternateNameEntryType key = it.key();
            ::QString value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX]), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMultiMap_QSsl_AlternateNameEntryType_QString__PythonToCpp__QMultiMap_QSsl_AlternateNameEntryType_QString_(PyObject* pyIn, void* cppOut) {
    ::QMultiMap<QSsl::AlternateNameEntryType, QString >& cppOutRef = *((::QMultiMap<QSsl::AlternateNameEntryType, QString >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QSsl::AlternateNameEntryType cppKey = ((::QSsl::AlternateNameEntryType)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX]), key, &(cppKey));
        ::QString cppValue = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMultiMap_QSsl_AlternateNameEntryType_QString__PythonToCpp__QMultiMap_QSsl_AlternateNameEntryType_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX]), false, SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return _QMultiMap_QSsl_AlternateNameEntryType_QString__PythonToCpp__QMultiMap_QSsl_AlternateNameEntryType_QString_;
    return 0;
}

// C++ to Python conversion for type 'QList<QVariant >'.
static PyObject* _QList_QVariant__CppToPython__QList_QVariant_(const void* cppIn) {
    ::QList<QVariant >& cppInRef = *((::QList<QVariant >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QVariant >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QVariant cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QVariant__PythonToCpp__QList_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QList<QVariant >& cppOutRef = *((::QList<QVariant >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QVariant cppItem = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return _QList_QVariant__PythonToCpp__QList_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'QList<QString >'.
static PyObject* _QList_QString__CppToPython__QList_QString_(const void* cppIn) {
    ::QList<QString >& cppInRef = *((::QList<QString >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QString >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QString cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QString__PythonToCpp__QList_QString_(PyObject* pyIn, void* cppOut) {
    ::QList<QString >& cppOutRef = *((::QList<QString >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QString cppItem = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QString__PythonToCpp__QList_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return _QList_QString__PythonToCpp__QList_QString_;
    return 0;
}

// C++ to Python conversion for type 'QMap<QString, QVariant >'.
static PyObject* _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_(const void* cppIn) {
    ::QMap<QString, QVariant >& cppInRef = *((::QMap<QString, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<QString, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QString key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QMap<QString, QVariant >& cppOutRef = *((::QMap<QString, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_;
    return 0;
}


#if defined _WIN32 || defined __CYGWIN__
    #define SBK_EXPORT_MODULE __declspec(dllexport)
#elif __GNUC__ >= 4
    #define SBK_EXPORT_MODULE __attribute__ ((visibility("default")))
#else
    #define SBK_EXPORT_MODULE
#endif

#ifdef IS_PY3K
static struct PyModuleDef moduledef = {
    /* m_base     */ PyModuleDef_HEAD_INIT,
    /* m_name     */ "QtNetwork",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtNetwork_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtNetwork)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtNetwork_IDX_COUNT];
    SbkPySide_QtNetworkTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtNetwork_CONVERTERS_IDX_COUNT];
    SbkPySide_QtNetworkTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtNetwork", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtNetwork", QtNetwork_methods);
#endif

    // Initialize classes in the type system
    init_QNetworkRequest(module);
    init_QNetworkCookie(module);
    init_QNetworkConfiguration(module);
    init_QIPv6Address(module);
    init_QHostAddress(module);
    init_QNetworkAddressEntry(module);
    init_QNetworkInterface(module);
    init_QNetworkCacheMetaData(module);
    init_QUrlInfo(module);
    init_QHttpHeader(module);
    init_QHttpResponseHeader(module);
    init_QHttpRequestHeader(module);
    init_QSslCipher(module);
    init_QSslError(module);
    init_QSslConfiguration(module);
    init_QAuthenticator(module);
    init_QHostInfo(module);
    init_QNetworkProxyQuery(module);
    init_QNetworkProxyFactory(module);
    init_QNetworkProxy(module);
    init_QLocalSocket(module);
    init_QAbstractSocket(module);
    init_QTcpSocket(module);
    init_QUdpSocket(module);
    init_QNetworkReply(module);
    init_QHttp(module);
    init_QNetworkAccessManager(module);
    init_QNetworkCookieJar(module);
    init_QNetworkSession(module);
    init_QAbstractNetworkCache(module);
    init_QNetworkDiskCache(module);
    init_QFtp(module);
    init_QLocalServer(module);
    init_QTcpServer(module);
    init_QNetworkConfigurationManager(module);
    init_QSsl(module);
    init_QSslCertificate(module);
    init_QSslSocket(module);
    init_QSslKey(module);

    // Register converter for type 'QList<QNetworkProxy>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKPROXY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QNetworkProxy__CppToPython__QList_QNetworkProxy_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKPROXY_IDX], "QList<QNetworkProxy>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKPROXY_IDX],
        _QList_QNetworkProxy__PythonToCpp__QList_QNetworkProxy_,
        is__QList_QNetworkProxy__PythonToCpp__QList_QNetworkProxy__Convertible);

    // Register converter for type 'QList<QHostAddress>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QHostAddress__CppToPython__QList_QHostAddress_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX], "QList<QHostAddress>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX],
        _QList_QHostAddress__PythonToCpp__QList_QHostAddress_,
        is__QList_QHostAddress__PythonToCpp__QList_QHostAddress__Convertible);

    // Register converter for type 'QHash<QString,QVariant>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QHash_QString_QVariant__CppToPython__QHash_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QSTRING_QVARIANT_IDX], "QHash<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QSTRING_QVARIANT_IDX],
        _QHash_QString_QVariant__PythonToCpp__QHash_QString_QVariant_,
        is__QHash_QString_QVariant__PythonToCpp__QHash_QString_QVariant__Convertible);

    // Register converter for type 'QList<QSslCertificate>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QSslCertificate__CppToPython__QList_QSslCertificate_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], "QList<QSslCertificate>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX],
        _QList_QSslCertificate__PythonToCpp__QList_QSslCertificate_,
        is__QList_QSslCertificate__PythonToCpp__QList_QSslCertificate__Convertible);

    // Register converter for type 'QList<QSslCipher>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QSslCipher__CppToPython__QList_QSslCipher_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], "QList<QSslCipher>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX],
        _QList_QSslCipher__PythonToCpp__QList_QSslCipher_,
        is__QList_QSslCipher__PythonToCpp__QList_QSslCipher__Convertible);

    // Register converter for type 'QPair<QString,QString>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_QString_QString__CppToPython__QPair_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX], "QPair<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QSTRING_QSTRING_IDX],
        _QPair_QString_QString__PythonToCpp__QPair_QString_QString_,
        is__QPair_QString_QString__PythonToCpp__QPair_QString_QString__Convertible);

    // Register converter for type 'const QList<QPair<QString,QString>>&'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QPair_QString_QString__REF_CppToPython__constQList_QPair_QString_QString__REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QSTRING_QSTRING_IDX], "const QList<QPair<QString,QString>>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QSTRING_QSTRING_IDX], "QList<QPair<QString,QString>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QSTRING_QSTRING_IDX],
        _constQList_QPair_QString_QString__REF_PythonToCpp__constQList_QPair_QString_QString__REF,
        is__constQList_QPair_QString_QString__REF_PythonToCpp__constQList_QPair_QString_QString__REF_Convertible);

    // Register converter for type 'QHash<QNetworkRequest::Attribute,QVariant>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QNETWORKREQUEST_ATTRIBUTE_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QHash_QNetworkRequest_Attribute_QVariant__CppToPython__QHash_QNetworkRequest_Attribute_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QNETWORKREQUEST_ATTRIBUTE_QVARIANT_IDX], "QHash<QNetworkRequest::Attribute,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QNETWORKREQUEST_ATTRIBUTE_QVARIANT_IDX],
        _QHash_QNetworkRequest_Attribute_QVariant__PythonToCpp__QHash_QNetworkRequest_Attribute_QVariant_,
        is__QHash_QNetworkRequest_Attribute_QVariant__PythonToCpp__QHash_QNetworkRequest_Attribute_QVariant__Convertible);

    // Register converter for type 'QPair<QByteArray,QByteArray>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_QByteArray_QByteArray__CppToPython__QPair_QByteArray_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], "QPair<QByteArray,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX],
        _QPair_QByteArray_QByteArray__PythonToCpp__QPair_QByteArray_QByteArray_,
        is__QPair_QByteArray_QByteArray__PythonToCpp__QPair_QByteArray_QByteArray__Convertible);

    // Register converter for type 'QList<QPair<QByteArray,QByteArray>>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPair_QByteArray_QByteArray___CppToPython__QList_QPair_QByteArray_QByteArray__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], "QList<QPair<QByteArray,QByteArray>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX],
        _QList_QPair_QByteArray_QByteArray___PythonToCpp__QList_QPair_QByteArray_QByteArray__,
        is__QList_QPair_QByteArray_QByteArray___PythonToCpp__QList_QPair_QByteArray_QByteArray___Convertible);

    // Register converter for type 'QList<QNetworkAddressEntry>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKADDRESSENTRY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QNetworkAddressEntry__CppToPython__QList_QNetworkAddressEntry_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKADDRESSENTRY_IDX], "QList<QNetworkAddressEntry>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKADDRESSENTRY_IDX],
        _QList_QNetworkAddressEntry__PythonToCpp__QList_QNetworkAddressEntry_,
        is__QList_QNetworkAddressEntry__PythonToCpp__QList_QNetworkAddressEntry__Convertible);

    // Register converter for type 'QList<QNetworkInterface>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKINTERFACE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QNetworkInterface__CppToPython__QList_QNetworkInterface_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKINTERFACE_IDX], "QList<QNetworkInterface>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKINTERFACE_IDX],
        _QList_QNetworkInterface__PythonToCpp__QList_QNetworkInterface_,
        is__QList_QNetworkInterface__PythonToCpp__QList_QNetworkInterface__Convertible);

    // Register converter for type 'const QPair<QHostAddress,int>&'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQPair_QHostAddress_int_REF_CppToPython__constQPair_QHostAddress_int_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX], "const QPair<QHostAddress,int>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX], "QPair<QHostAddress,int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QPAIR_QHOSTADDRESS_INT_IDX],
        _constQPair_QHostAddress_int_REF_PythonToCpp__constQPair_QHostAddress_int_REF,
        is__constQPair_QHostAddress_int_REF_PythonToCpp__constQPair_QHostAddress_int_REF_Convertible);

    // Register converter for type 'QList<QNetworkConfiguration>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCONFIGURATION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QNetworkConfiguration__CppToPython__QList_QNetworkConfiguration_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCONFIGURATION_IDX], "QList<QNetworkConfiguration>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCONFIGURATION_IDX],
        _QList_QNetworkConfiguration__PythonToCpp__QList_QNetworkConfiguration_,
        is__QList_QNetworkConfiguration__PythonToCpp__QList_QNetworkConfiguration__Convertible);

    // Register converter for type 'QList<QNetworkCookie>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCOOKIE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QNetworkCookie__CppToPython__QList_QNetworkCookie_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCOOKIE_IDX], "QList<QNetworkCookie>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCOOKIE_IDX],
        _QList_QNetworkCookie__PythonToCpp__QList_QNetworkCookie_,
        is__QList_QNetworkCookie__PythonToCpp__QList_QNetworkCookie__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'const QList<QSslError>&'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QSslError_REF_CppToPython__constQList_QSslError_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX], "const QList<QSslError>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX], "QList<QSslError>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX],
        _constQList_QSslError_REF_PythonToCpp__constQList_QSslError_REF,
        is__constQList_QSslError_REF_PythonToCpp__constQList_QSslError_REF_Convertible);

    // Register converter for type 'QMultiMap<QSsl::AlternateNameEntryType,QString>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMULTIMAP_QSSL_ALTERNATENAMEENTRYTYPE_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMultiMap_QSsl_AlternateNameEntryType_QString__CppToPython__QMultiMap_QSsl_AlternateNameEntryType_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMULTIMAP_QSSL_ALTERNATENAMEENTRYTYPE_QSTRING_IDX], "QMultiMap<QSsl::AlternateNameEntryType,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMULTIMAP_QSSL_ALTERNATENAMEENTRYTYPE_QSTRING_IDX],
        _QMultiMap_QSsl_AlternateNameEntryType_QString__PythonToCpp__QMultiMap_QSsl_AlternateNameEntryType_QString_,
        is__QMultiMap_QSsl_AlternateNameEntryType_QString__PythonToCpp__QMultiMap_QSsl_AlternateNameEntryType_QString__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtNetworkTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtNetworkTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtNetwork");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
