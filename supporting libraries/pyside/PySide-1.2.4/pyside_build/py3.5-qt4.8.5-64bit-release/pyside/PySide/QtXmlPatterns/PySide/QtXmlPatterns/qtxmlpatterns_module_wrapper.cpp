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
#include "pyside_qtxmlpatterns_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtXmlPatternsTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtXmlPatternsTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtXmlPatterns_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtXmlPatternsTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef QtXmlPatterns_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QXmlSchema(PyObject* module);
void init_QXmlSchemaValidator(PyObject* module);
void init_QSourceLocation(PyObject* module);
void init_QXmlName(PyObject* module);
void init_QXmlNodeModelIndex(PyObject* module);
void init_QAbstractXmlNodeModel(PyObject* module);
void init_QXmlItem(PyObject* module);
void init_QAbstractXmlReceiver(PyObject* module);
void init_QXmlSerializer(PyObject* module);
void init_QXmlFormatter(PyObject* module);
void init_QXmlNamePool(PyObject* module);
void init_QXmlQuery(PyObject* module);
void init_QXmlResultItems(PyObject* module);
void init_QAbstractMessageHandler(PyObject* module);
void init_QAbstractUriResolver(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QVector<QXmlNodeModelIndex >'.
static PyObject* _QVector_QXmlNodeModelIndex__CppToPython__QVector_QXmlNodeModelIndex_(const void* cppIn) {
    ::QVector<QXmlNodeModelIndex >& cppInRef = *((::QVector<QXmlNodeModelIndex >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlNodeModelIndex >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlNodeModelIndex >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlNodeModelIndex cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_QXmlNodeModelIndex__PythonToCpp__QVector_QXmlNodeModelIndex_(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlNodeModelIndex >& cppOutRef = *((::QVector<QXmlNodeModelIndex >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlNodeModelIndex cppItem = ::QXmlNodeModelIndex();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_QXmlNodeModelIndex__PythonToCpp__QVector_QXmlNodeModelIndex__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyIn))
        return _QVector_QXmlNodeModelIndex__PythonToCpp__QVector_QXmlNodeModelIndex_;
    return 0;
}

// C++ to Python conversion for type 'QVector<QXmlName >'.
static PyObject* _QVector_QXmlName__CppToPython__QVector_QXmlName_(const void* cppIn) {
    ::QVector<QXmlName >& cppInRef = *((::QVector<QXmlName >*)cppIn);

                // TEMPLATE - cppvector_to_pylist_conversion - START
        ::QVector<QXmlName >::size_type vectorSize = cppInRef.size();
        PyObject* pyOut = PyList_New((int) vectorSize);
        for (::QVector<QXmlName >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::QXmlName cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cppvector_to_pylist_conversion - END

}
static void _QVector_QXmlName__PythonToCpp__QVector_QXmlName_(PyObject* pyIn, void* cppOut) {
    ::QVector<QXmlName >& cppOutRef = *((::QVector<QXmlName >*)cppOut);

                // TEMPLATE - pyseq_to_cppvector_conversion - START
    int vectorSize = PySequence_Size(pyIn);
    cppOutRef.reserve(vectorSize);
    for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::QXmlName cppItem = ::QXmlName();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cppvector_conversion - END

}
static PythonToCppFunc is__QVector_QXmlName__PythonToCpp__QVector_QXmlName__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pyIn))
        return _QVector_QXmlName__PythonToCpp__QVector_QXmlName_;
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
    /* m_name     */ "QtXmlPatterns",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtXmlPatterns_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtXmlPatterns)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtXmlPatterns_IDX_COUNT];
    SbkPySide_QtXmlPatternsTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtXmlPatterns_CONVERTERS_IDX_COUNT];
    SbkPySide_QtXmlPatternsTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtXmlPatterns", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtXmlPatterns", QtXmlPatterns_methods);
#endif

    // Initialize classes in the type system
    init_QXmlSchema(module);
    init_QXmlSchemaValidator(module);
    init_QSourceLocation(module);
    init_QXmlName(module);
    init_QXmlNodeModelIndex(module);
    init_QAbstractXmlNodeModel(module);
    init_QXmlItem(module);
    init_QAbstractXmlReceiver(module);
    init_QXmlSerializer(module);
    init_QXmlFormatter(module);
    init_QXmlNamePool(module);
    init_QXmlQuery(module);
    init_QXmlResultItems(module);
    init_QAbstractMessageHandler(module);
    init_QAbstractUriResolver(module);

    // Register converter for type 'QVector<QXmlNodeModelIndex>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_QXmlNodeModelIndex__CppToPython__QVector_QXmlNodeModelIndex_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX], "QVector<QXmlNodeModelIndex>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX],
        _QVector_QXmlNodeModelIndex__PythonToCpp__QVector_QXmlNodeModelIndex_,
        is__QVector_QXmlNodeModelIndex__PythonToCpp__QVector_QXmlNodeModelIndex__Convertible);

    // Register converter for type 'QVector<QXmlName>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNAME_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QVector_QXmlName__CppToPython__QVector_QXmlName_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNAME_IDX], "QVector<QXmlName>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNAME_IDX],
        _QVector_QXmlName__PythonToCpp__QVector_QXmlName_,
        is__QVector_QXmlName__PythonToCpp__QVector_QXmlName__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtXmlPatternsTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtXmlPatternsTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtXmlPatterns");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
