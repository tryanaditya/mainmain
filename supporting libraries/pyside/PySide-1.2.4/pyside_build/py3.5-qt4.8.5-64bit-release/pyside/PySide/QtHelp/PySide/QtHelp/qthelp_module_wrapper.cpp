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
#include "pyside_qthelp_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtHelpTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtHelpTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtHelp_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtHelpTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef QtHelp_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QHelpContentItem(PyObject* module);
void init_QHelpSearchQuery(PyObject* module);
void init_QHelpEngineCore(PyObject* module);
void init_QHelpEngine(PyObject* module);
void init_QHelpSearchEngine(PyObject* module);
void init_QHelpSearchQueryWidget(PyObject* module);
void init_QHelpSearchResultWidget(PyObject* module);
void init_QHelpIndexWidget(PyObject* module);
void init_QHelpContentWidget(PyObject* module);
void init_QHelpIndexModel(PyObject* module);
void init_QHelpContentModel(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtGuiTypes;
SbkConverter** SbkPySide_QtGuiTypeConverters;
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

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

// C++ to Python conversion for type 'QMap<int, QVariant >'.
static PyObject* _QMap_int_QVariant__CppToPython__QMap_int_QVariant_(const void* cppIn) {
    ::QMap<int, QVariant >& cppInRef = *((::QMap<int, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<int, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            int key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QMap<int, QVariant >& cppOutRef = *((::QMap<int, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        int cppKey;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_int_QVariant__PythonToCpp__QMap_int_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'const QHash<int, QByteArray > &'.
static PyObject* _constQHash_int_QByteArray_REF_CppToPython__constQHash_int_QByteArray_REF(const void* cppIn) {
    ::QHash<int, QByteArray >& cppInRef = *((::QHash<int, QByteArray >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QHash<int, QByteArray >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            int key = it.key();
            ::QByteArray value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF(PyObject* pyIn, void* cppOut) {
    ::QHash<int, QByteArray >& cppOutRef = *((::QHash<int, QByteArray >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        int cppKey;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), key, &(cppKey));
        ::QByteArray cppValue = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, pyIn))
        return _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF;
    return 0;
}

// C++ to Python conversion for type 'QMap<QString, QUrl >'.
static PyObject* _QMap_QString_QUrl__CppToPython__QMap_QString_QUrl_(const void* cppIn) {
    ::QMap<QString, QUrl >& cppInRef = *((::QMap<QString, QUrl >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMap<QString, QUrl >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QString key = it.key();
            ::QUrl value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_QString_QUrl__PythonToCpp__QMap_QString_QUrl_(PyObject* pyIn, void* cppOut) {
    ::QMap<QString, QUrl >& cppOutRef = *((::QMap<QString, QUrl >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QUrl cppValue = ::QUrl();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_QString_QUrl__PythonToCpp__QMap_QString_QUrl__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QURL_IDX]), false, pyIn))
        return _QMap_QString_QUrl__PythonToCpp__QMap_QString_QUrl_;
    return 0;
}

// C++ to Python conversion for type 'QList<QAction * >'.
static PyObject* _QList_QActionPTR__CppToPython__QList_QActionPTR_(const void* cppIn) {
    ::QList<QAction * >& cppInRef = *((::QList<QAction * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAction * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAction* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QActionPTR__PythonToCpp__QList_QActionPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QAction * >& cppOutRef = *((::QList<QAction * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAction* cppItem = ((::QAction*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], pyIn))
        return _QList_QActionPTR__PythonToCpp__QList_QActionPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<QHelpSearchQuery >'.
static PyObject* _QList_QHelpSearchQuery__CppToPython__QList_QHelpSearchQuery_(const void* cppIn) {
    ::QList<QHelpSearchQuery >& cppInRef = *((::QList<QHelpSearchQuery >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QHelpSearchQuery >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QHelpSearchQuery cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QHelpSearchQuery__PythonToCpp__QList_QHelpSearchQuery_(PyObject* pyIn, void* cppOut) {
    ::QList<QHelpSearchQuery >& cppOutRef = *((::QList<QHelpSearchQuery >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QHelpSearchQuery cppItem = ::QHelpSearchQuery();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QHelpSearchQuery__PythonToCpp__QList_QHelpSearchQuery__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], pyIn))
        return _QList_QHelpSearchQuery__PythonToCpp__QList_QHelpSearchQuery_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWidget * >'.
static PyObject* _QList_QWidgetPTR__CppToPython__QList_QWidgetPTR_(const void* cppIn) {
    ::QList<QWidget * >& cppInRef = *((::QList<QWidget * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWidget * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWidget* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QWidget * >& cppOutRef = *((::QList<QWidget * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWidget* cppItem = ((::QWidget*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyIn))
        return _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_;
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

// C++ to Python conversion for type 'QList<QPair<QString, QString > >'.
static PyObject* _QList_QPair_QString_QString___CppToPython__QList_QPair_QString_QString__(const void* cppIn) {
    ::QList<QPair<QString, QString > >& cppInRef = *((::QList<QPair<QString, QString > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QString, QString > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QString, QString > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPair_QString_QString___PythonToCpp__QList_QPair_QString_QString__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QString, QString > >& cppOutRef = *((::QList<QPair<QString, QString > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QString, QString > cppItem = ::QPair<QString, QString >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPair_QString_QString___PythonToCpp__QList_QPair_QString_QString___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX], pyIn))
        return _QList_QPair_QString_QString___PythonToCpp__QList_QPair_QString_QString__;
    return 0;
}

// C++ to Python conversion for type 'QList<QUrl >'.
static PyObject* _QList_QUrl__CppToPython__QList_QUrl_(const void* cppIn) {
    ::QList<QUrl >& cppInRef = *((::QList<QUrl >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QUrl >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QUrl cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QUrl__PythonToCpp__QList_QUrl_(PyObject* pyIn, void* cppOut) {
    ::QList<QUrl >& cppOutRef = *((::QList<QUrl >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QUrl cppItem = ::QUrl();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QUrl__PythonToCpp__QList_QUrl__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return _QList_QUrl__PythonToCpp__QList_QUrl_;
    return 0;
}

// C++ to Python conversion for type 'QList<QStringList >'.
static PyObject* _QList_QStringList__CppToPython__QList_QStringList_(const void* cppIn) {
    ::QList<QStringList >& cppInRef = *((::QList<QStringList >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QStringList >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QStringList cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QStringList__PythonToCpp__QList_QStringList_(PyObject* pyIn, void* cppOut) {
    ::QList<QStringList >& cppOutRef = *((::QList<QStringList >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QStringList cppItem = ::QStringList();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QStringList__PythonToCpp__QList_QStringList__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyIn))
        return _QList_QStringList__PythonToCpp__QList_QStringList_;
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
    /* m_name     */ "QtHelp",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtHelp_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtHelp)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtGui"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtGuiTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtGuiTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtHelp_IDX_COUNT];
    SbkPySide_QtHelpTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtHelp_CONVERTERS_IDX_COUNT];
    SbkPySide_QtHelpTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtHelp", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtHelp", QtHelp_methods);
#endif

    // Initialize classes in the type system
    init_QHelpContentItem(module);
    init_QHelpSearchQuery(module);
    init_QHelpEngineCore(module);
    init_QHelpEngine(module);
    init_QHelpSearchEngine(module);
    init_QHelpSearchQueryWidget(module);
    init_QHelpSearchResultWidget(module);
    init_QHelpIndexWidget(module);
    init_QHelpContentWidget(module);
    init_QHelpIndexModel(module);
    init_QHelpContentModel(module);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'QMap<int,QVariant>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_INT_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_int_QVariant__CppToPython__QMap_int_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_INT_QVARIANT_IDX], "QMap<int,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_INT_QVARIANT_IDX],
        _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_,
        is__QMap_int_QVariant__PythonToCpp__QMap_int_QVariant__Convertible);

    // Register converter for type 'const QHash<int,QByteArray>&'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QHASH_INT_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _constQHash_int_QByteArray_REF_CppToPython__constQHash_int_QByteArray_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QHASH_INT_QBYTEARRAY_IDX], "const QHash<int,QByteArray>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QHASH_INT_QBYTEARRAY_IDX], "QHash<int,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QHASH_INT_QBYTEARRAY_IDX],
        _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF,
        is__constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF_Convertible);

    // Register converter for type 'QMap<QString,QUrl>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QURL_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QUrl__CppToPython__QMap_QString_QUrl_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QURL_IDX], "QMap<QString,QUrl>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QURL_IDX],
        _QMap_QString_QUrl__PythonToCpp__QMap_QString_QUrl_,
        is__QMap_QString_QUrl__PythonToCpp__QMap_QString_QUrl__Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'QList<QHelpSearchQuery>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QHELPSEARCHQUERY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QHelpSearchQuery__CppToPython__QList_QHelpSearchQuery_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QHELPSEARCHQUERY_IDX], "QList<QHelpSearchQuery>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QHELPSEARCHQUERY_IDX],
        _QList_QHelpSearchQuery__PythonToCpp__QList_QHelpSearchQuery_,
        is__QList_QHelpSearchQuery__PythonToCpp__QList_QHelpSearchQuery__Convertible);

    // Register converter for type 'QList<QWidget*>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QWIDGETPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWidgetPTR__CppToPython__QList_QWidgetPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QWIDGETPTR_IDX], "QList<QWidget*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QWIDGETPTR_IDX],
        _QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR_,
        is__QList_QWidgetPTR__PythonToCpp__QList_QWidgetPTR__Convertible);

    // Register converter for type 'QPair<QString,QString>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_QString_QString__CppToPython__QPair_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX], "QPair<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QPAIR_QSTRING_QSTRING_IDX],
        _QPair_QString_QString__PythonToCpp__QPair_QString_QString_,
        is__QPair_QString_QString__PythonToCpp__QPair_QString_QString__Convertible);

    // Register converter for type 'QList<QPair<QString,QString>>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QPAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPair_QString_QString___CppToPython__QList_QPair_QString_QString__);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QPAIR_QSTRING_QSTRING_IDX], "QList<QPair<QString,QString>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QPAIR_QSTRING_QSTRING_IDX],
        _QList_QPair_QString_QString___PythonToCpp__QList_QPair_QString_QString__,
        is__QList_QPair_QString_QString___PythonToCpp__QList_QPair_QString_QString___Convertible);

    // Register converter for type 'QList<QUrl>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QURL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QUrl__CppToPython__QList_QUrl_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QURL_IDX], "QList<QUrl>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QURL_IDX],
        _QList_QUrl__PythonToCpp__QList_QUrl_,
        is__QList_QUrl__PythonToCpp__QList_QUrl__Convertible);

    // Register converter for type 'QList<QStringList>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRINGLIST_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QStringList__CppToPython__QList_QStringList_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRINGLIST_IDX], "QList<QStringList>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRINGLIST_IDX],
        _QList_QStringList__PythonToCpp__QList_QStringList_,
        is__QList_QStringList__PythonToCpp__QList_QStringList__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtHelpTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtHelpTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtHelp");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
