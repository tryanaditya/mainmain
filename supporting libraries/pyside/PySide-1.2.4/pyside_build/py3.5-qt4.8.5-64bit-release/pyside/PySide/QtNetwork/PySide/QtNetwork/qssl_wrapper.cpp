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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include "pyside_qtnetwork_python.h"

#include "qssl_wrapper.h"

// Extra includes
#include <qssl.h>



// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_QSsl_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSsl_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSsl_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSsl_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSsl",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QSsl_traverse,
    /*tp_clear*/            Sbk_QSsl_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSsl_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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
static void QSsl_KeyType_PythonToCpp_QSsl_KeyType(PyObject* pyIn, void* cppOut) {
    *((::QSsl::KeyType*)cppOut) = (::QSsl::KeyType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSsl_KeyType_PythonToCpp_QSsl_KeyType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX]))
        return QSsl_KeyType_PythonToCpp_QSsl_KeyType;
    return 0;
}
static PyObject* QSsl_KeyType_CppToPython_QSsl_KeyType(const void* cppIn) {
    int castCppIn = *((::QSsl::KeyType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX], castCppIn);

}

static void QSsl_EncodingFormat_PythonToCpp_QSsl_EncodingFormat(PyObject* pyIn, void* cppOut) {
    *((::QSsl::EncodingFormat*)cppOut) = (::QSsl::EncodingFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSsl_EncodingFormat_PythonToCpp_QSsl_EncodingFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]))
        return QSsl_EncodingFormat_PythonToCpp_QSsl_EncodingFormat;
    return 0;
}
static PyObject* QSsl_EncodingFormat_CppToPython_QSsl_EncodingFormat(const void* cppIn) {
    int castCppIn = *((::QSsl::EncodingFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX], castCppIn);

}

static void QSsl_KeyAlgorithm_PythonToCpp_QSsl_KeyAlgorithm(PyObject* pyIn, void* cppOut) {
    *((::QSsl::KeyAlgorithm*)cppOut) = (::QSsl::KeyAlgorithm) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSsl_KeyAlgorithm_PythonToCpp_QSsl_KeyAlgorithm_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]))
        return QSsl_KeyAlgorithm_PythonToCpp_QSsl_KeyAlgorithm;
    return 0;
}
static PyObject* QSsl_KeyAlgorithm_CppToPython_QSsl_KeyAlgorithm(const void* cppIn) {
    int castCppIn = *((::QSsl::KeyAlgorithm*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX], castCppIn);

}

static void QSsl_AlternateNameEntryType_PythonToCpp_QSsl_AlternateNameEntryType(PyObject* pyIn, void* cppOut) {
    *((::QSsl::AlternateNameEntryType*)cppOut) = (::QSsl::AlternateNameEntryType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSsl_AlternateNameEntryType_PythonToCpp_QSsl_AlternateNameEntryType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX]))
        return QSsl_AlternateNameEntryType_PythonToCpp_QSsl_AlternateNameEntryType;
    return 0;
}
static PyObject* QSsl_AlternateNameEntryType_CppToPython_QSsl_AlternateNameEntryType(const void* cppIn) {
    int castCppIn = *((::QSsl::AlternateNameEntryType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX], castCppIn);

}

static void QSsl_SslProtocol_PythonToCpp_QSsl_SslProtocol(PyObject* pyIn, void* cppOut) {
    *((::QSsl::SslProtocol*)cppOut) = (::QSsl::SslProtocol) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSsl_SslProtocol_PythonToCpp_QSsl_SslProtocol_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]))
        return QSsl_SslProtocol_PythonToCpp_QSsl_SslProtocol;
    return 0;
}
static PyObject* QSsl_SslProtocol_CppToPython_QSsl_SslProtocol(const void* cppIn) {
    int castCppIn = *((::QSsl::SslProtocol*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX], castCppIn);

}

void init_QSsl(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QSSL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSsl_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSsl", "QSsl",
        &Sbk_QSsl_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'KeyType'.
    SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSsl_Type,
        "KeyType",
        "PySide.QtNetwork.QSsl.KeyType",
        "QSsl::KeyType");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX],
        &Sbk_QSsl_Type, "PrivateKey", (long) QSsl::PrivateKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX],
        &Sbk_QSsl_Type, "PublicKey", (long) QSsl::PublicKey))
        return ;
    // Register converter for enum 'QSsl::KeyType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX],
            QSsl_KeyType_CppToPython_QSsl_KeyType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSsl_KeyType_PythonToCpp_QSsl_KeyType,
            is_QSsl_KeyType_PythonToCpp_QSsl_KeyType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSsl::KeyType");
        Shiboken::Conversions::registerConverterName(converter, "KeyType");
    }
    // End of 'KeyType' enum.

    // Initialization of enum 'EncodingFormat'.
    SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSsl_Type,
        "EncodingFormat",
        "PySide.QtNetwork.QSsl.EncodingFormat",
        "QSsl::EncodingFormat");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX],
        &Sbk_QSsl_Type, "Pem", (long) QSsl::Pem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX],
        &Sbk_QSsl_Type, "Der", (long) QSsl::Der))
        return ;
    // Register converter for enum 'QSsl::EncodingFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX],
            QSsl_EncodingFormat_CppToPython_QSsl_EncodingFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSsl_EncodingFormat_PythonToCpp_QSsl_EncodingFormat,
            is_QSsl_EncodingFormat_PythonToCpp_QSsl_EncodingFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSsl::EncodingFormat");
        Shiboken::Conversions::registerConverterName(converter, "EncodingFormat");
    }
    // End of 'EncodingFormat' enum.

    // Initialization of enum 'KeyAlgorithm'.
    SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSsl_Type,
        "KeyAlgorithm",
        "PySide.QtNetwork.QSsl.KeyAlgorithm",
        "QSsl::KeyAlgorithm");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX],
        &Sbk_QSsl_Type, "Rsa", (long) QSsl::Rsa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX],
        &Sbk_QSsl_Type, "Dsa", (long) QSsl::Dsa))
        return ;
    // Register converter for enum 'QSsl::KeyAlgorithm'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX],
            QSsl_KeyAlgorithm_CppToPython_QSsl_KeyAlgorithm);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSsl_KeyAlgorithm_PythonToCpp_QSsl_KeyAlgorithm,
            is_QSsl_KeyAlgorithm_PythonToCpp_QSsl_KeyAlgorithm_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSsl::KeyAlgorithm");
        Shiboken::Conversions::registerConverterName(converter, "KeyAlgorithm");
    }
    // End of 'KeyAlgorithm' enum.

    // Initialization of enum 'AlternateNameEntryType'.
    SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSsl_Type,
        "AlternateNameEntryType",
        "PySide.QtNetwork.QSsl.AlternateNameEntryType",
        "QSsl::AlternateNameEntryType");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX],
        &Sbk_QSsl_Type, "EmailEntry", (long) QSsl::EmailEntry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX],
        &Sbk_QSsl_Type, "DnsEntry", (long) QSsl::DnsEntry))
        return ;
    // Register converter for enum 'QSsl::AlternateNameEntryType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX],
            QSsl_AlternateNameEntryType_CppToPython_QSsl_AlternateNameEntryType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSsl_AlternateNameEntryType_PythonToCpp_QSsl_AlternateNameEntryType,
            is_QSsl_AlternateNameEntryType_PythonToCpp_QSsl_AlternateNameEntryType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_ALTERNATENAMEENTRYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSsl::AlternateNameEntryType");
        Shiboken::Conversions::registerConverterName(converter, "AlternateNameEntryType");
    }
    // End of 'AlternateNameEntryType' enum.

    // Initialization of enum 'SslProtocol'.
    SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSsl_Type,
        "SslProtocol",
        "PySide.QtNetwork.QSsl.SslProtocol",
        "QSsl::SslProtocol");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "SslV3", (long) QSsl::SslV3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "SslV2", (long) QSsl::SslV2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "TlsV1", (long) QSsl::TlsV1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "AnyProtocol", (long) QSsl::AnyProtocol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "TlsV1SslV3", (long) QSsl::TlsV1SslV3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "SecureProtocols", (long) QSsl::SecureProtocols))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
        &Sbk_QSsl_Type, "UnknownProtocol", (long) QSsl::UnknownProtocol))
        return ;
    // Register converter for enum 'QSsl::SslProtocol'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX],
            QSsl_SslProtocol_CppToPython_QSsl_SslProtocol);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSsl_SslProtocol_PythonToCpp_QSsl_SslProtocol,
            is_QSsl_SslProtocol_PythonToCpp_QSsl_SslProtocol_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSsl::SslProtocol");
        Shiboken::Conversions::registerConverterName(converter, "SslProtocol");
    }
    // End of 'SslProtocol' enum.


    qRegisterMetaType< ::QSsl::KeyType >("QSsl::KeyType");
    qRegisterMetaType< ::QSsl::EncodingFormat >("QSsl::EncodingFormat");
    qRegisterMetaType< ::QSsl::KeyAlgorithm >("QSsl::KeyAlgorithm");
    qRegisterMetaType< ::QSsl::AlternateNameEntryType >("QSsl::AlternateNameEntryType");
    qRegisterMetaType< ::QSsl::SslProtocol >("QSsl::SslProtocol");
}
