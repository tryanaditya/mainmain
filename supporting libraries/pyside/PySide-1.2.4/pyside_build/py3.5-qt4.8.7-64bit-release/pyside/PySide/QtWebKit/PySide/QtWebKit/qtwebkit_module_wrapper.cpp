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
#include "pyside_qtwebkit_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtWebKitTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtWebKitTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtWebKit_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtWebKitTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef QtWebKit_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QWebSettings(PyObject* module);
void init_QWebDatabase(PyObject* module);
void init_QWebElement(PyObject* module);
void init_QWebElementCollection(PyObject* module);
void init_QWebHitTestResult(PyObject* module);
void init_QWebHistoryItem(PyObject* module);
void init_QWebHistory(PyObject* module);
void init_QWebSecurityOrigin(PyObject* module);
void init_QWebPage(PyObject* module);
void init_QWebPage_ExtensionOption(PyObject* module);
void init_QWebPage_ErrorPageExtensionOption(PyObject* module);
void init_QWebPage_ChooseMultipleFilesExtensionOption(PyObject* module);
void init_QWebPage_ExtensionReturn(PyObject* module);
void init_QWebPage_ErrorPageExtensionReturn(PyObject* module);
void init_QWebPage_ChooseMultipleFilesExtensionReturn(PyObject* module);
void init_QWebHistoryInterface(PyObject* module);
void init_QWebPluginFactory(PyObject* module);
void init_QWebPluginFactory_Plugin(PyObject* module);
void init_QWebPluginFactory_MimeType(PyObject* module);
void init_QWebInspector(PyObject* module);
void init_QWebView(PyObject* module);
void init_QWebFrame(PyObject* module);
void init_QGraphicsWebView(PyObject* module);
void init_WebCore(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;
PyTypeObject** SbkPySide_QtGuiTypes;
SbkConverter** SbkPySide_QtGuiTypeConverters;
PyTypeObject** SbkPySide_QtNetworkTypes;
SbkConverter** SbkPySide_QtNetworkTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QList<QWebSecurityOrigin >'.
static PyObject* _QList_QWebSecurityOrigin__CppToPython__QList_QWebSecurityOrigin_(const void* cppIn) {
    ::QList<QWebSecurityOrigin >& cppInRef = *((::QList<QWebSecurityOrigin >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebSecurityOrigin >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebSecurityOrigin cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebSecurityOrigin__PythonToCpp__QList_QWebSecurityOrigin_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebSecurityOrigin >& cppOutRef = *((::QList<QWebSecurityOrigin >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebSecurityOrigin* cppItem = ((::QWebSecurityOrigin*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], pyItem, &(cppItem));
        cppOutRef << *cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebSecurityOrigin__PythonToCpp__QList_QWebSecurityOrigin__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], pyIn))
        return _QList_QWebSecurityOrigin__PythonToCpp__QList_QWebSecurityOrigin_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWebDatabase >'.
static PyObject* _QList_QWebDatabase__CppToPython__QList_QWebDatabase_(const void* cppIn) {
    ::QList<QWebDatabase >& cppInRef = *((::QList<QWebDatabase >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebDatabase >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebDatabase cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebDatabase__PythonToCpp__QList_QWebDatabase_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebDatabase >& cppOutRef = *((::QList<QWebDatabase >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebDatabase* cppItem = ((::QWebDatabase*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], pyItem, &(cppItem));
        cppOutRef << *cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebDatabase__PythonToCpp__QList_QWebDatabase__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], pyIn))
        return _QList_QWebDatabase__PythonToCpp__QList_QWebDatabase_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWebHistoryItem >'.
static PyObject* _QList_QWebHistoryItem__CppToPython__QList_QWebHistoryItem_(const void* cppIn) {
    ::QList<QWebHistoryItem >& cppInRef = *((::QList<QWebHistoryItem >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebHistoryItem >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebHistoryItem cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHISTORYITEM_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebHistoryItem__PythonToCpp__QList_QWebHistoryItem_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebHistoryItem >& cppOutRef = *((::QList<QWebHistoryItem >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebHistoryItem* cppItem = ((::QWebHistoryItem*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHISTORYITEM_IDX], pyItem, &(cppItem));
        cppOutRef << *cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebHistoryItem__PythonToCpp__QList_QWebHistoryItem__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHISTORYITEM_IDX], pyIn))
        return _QList_QWebHistoryItem__PythonToCpp__QList_QWebHistoryItem_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWebElement >'.
static PyObject* _QList_QWebElement__CppToPython__QList_QWebElement_(const void* cppIn) {
    ::QList<QWebElement >& cppInRef = *((::QList<QWebElement >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebElement >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebElement cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebElement__PythonToCpp__QList_QWebElement_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebElement >& cppOutRef = *((::QList<QWebElement >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebElement cppItem = ::QWebElement();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebElement__PythonToCpp__QList_QWebElement__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pyIn))
        return _QList_QWebElement__PythonToCpp__QList_QWebElement_;
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

// C++ to Python conversion for type 'QList<QWebPluginFactory::Plugin >'.
static PyObject* _QList_QWebPluginFactory_Plugin__CppToPython__QList_QWebPluginFactory_Plugin_(const void* cppIn) {
    ::QList<QWebPluginFactory::Plugin >& cppInRef = *((::QList<QWebPluginFactory::Plugin >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebPluginFactory::Plugin >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebPluginFactory::Plugin cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebPluginFactory_Plugin__PythonToCpp__QList_QWebPluginFactory_Plugin_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebPluginFactory::Plugin >& cppOutRef = *((::QList<QWebPluginFactory::Plugin >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebPluginFactory::Plugin cppItem = ::QWebPluginFactory::Plugin();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebPluginFactory_Plugin__PythonToCpp__QList_QWebPluginFactory_Plugin__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], pyIn))
        return _QList_QWebPluginFactory_Plugin__PythonToCpp__QList_QWebPluginFactory_Plugin_;
    return 0;
}

// C++ to Python conversion for type 'QList<QWebPluginFactory::MimeType >'.
static PyObject* _QList_QWebPluginFactory_MimeType__CppToPython__QList_QWebPluginFactory_MimeType_(const void* cppIn) {
    ::QList<QWebPluginFactory::MimeType >& cppInRef = *((::QList<QWebPluginFactory::MimeType >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebPluginFactory::MimeType >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebPluginFactory::MimeType cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebPluginFactory_MimeType__PythonToCpp__QList_QWebPluginFactory_MimeType_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebPluginFactory::MimeType >& cppOutRef = *((::QList<QWebPluginFactory::MimeType >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebPluginFactory::MimeType cppItem = ::QWebPluginFactory::MimeType();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebPluginFactory_MimeType__PythonToCpp__QList_QWebPluginFactory_MimeType__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], pyIn))
        return _QList_QWebPluginFactory_MimeType__PythonToCpp__QList_QWebPluginFactory_MimeType_;
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

// C++ to Python conversion for type 'QList<QWebFrame * >'.
static PyObject* _QList_QWebFramePTR__CppToPython__QList_QWebFramePTR_(const void* cppIn) {
    ::QList<QWebFrame * >& cppInRef = *((::QList<QWebFrame * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QWebFrame * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QWebFrame* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QWebFramePTR__PythonToCpp__QList_QWebFramePTR_(PyObject* pyIn, void* cppOut) {
    ::QList<QWebFrame * >& cppOutRef = *((::QList<QWebFrame * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QWebFrame* cppItem = ((::QWebFrame*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QWebFramePTR__PythonToCpp__QList_QWebFramePTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], pyIn))
        return _QList_QWebFramePTR__PythonToCpp__QList_QWebFramePTR_;
    return 0;
}

// C++ to Python conversion for type 'QMultiMap<QString, QString >'.
static PyObject* _QMultiMap_QString_QString__CppToPython__QMultiMap_QString_QString_(const void* cppIn) {
    ::QMultiMap<QString, QString >& cppInRef = *((::QMultiMap<QString, QString >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QMultiMap<QString, QString >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QString key = it.key();
            ::QString value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString_(PyObject* pyIn, void* cppOut) {
    ::QMultiMap<QString, QString >& cppOutRef = *((::QMultiMap<QString, QString >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QString cppValue = ::QString();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return _QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString_;
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
    /* m_name     */ "QtWebKit",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtWebKit_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtWebKit)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtGui"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtGuiTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtGuiTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide.QtNetwork"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide_QtNetworkTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide_QtNetworkTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_QtWebKit_IDX_COUNT];
    SbkPySide_QtWebKitTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtWebKit_CONVERTERS_IDX_COUNT];
    SbkPySide_QtWebKitTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtWebKit", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtWebKit", QtWebKit_methods);
#endif

    // Initialize classes in the type system
    init_QWebSettings(module);
    init_QWebDatabase(module);
    init_QWebElement(module);
    init_QWebElementCollection(module);
    init_QWebHitTestResult(module);
    init_QWebHistoryItem(module);
    init_QWebHistory(module);
    init_QWebSecurityOrigin(module);
    init_QWebPage(module);
    init_QWebPage_ExtensionOption(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebPage_ErrorPageExtensionOption(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebPage_ChooseMultipleFilesExtensionOption(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebPage_ExtensionReturn(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebPage_ErrorPageExtensionReturn(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebPage_ChooseMultipleFilesExtensionReturn(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX]->tp_dict);
    init_QWebHistoryInterface(module);
    init_QWebPluginFactory(module);
    init_QWebPluginFactory_Plugin(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_IDX]->tp_dict);
    init_QWebPluginFactory_MimeType(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_IDX]->tp_dict);
    init_QWebInspector(module);
    init_QWebView(module);
    init_QWebFrame(module);
    init_QGraphicsWebView(module);
    init_WebCore(module);

    // Register converter for type 'QList<QWebSecurityOrigin>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBSECURITYORIGIN_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebSecurityOrigin__CppToPython__QList_QWebSecurityOrigin_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBSECURITYORIGIN_IDX], "QList<QWebSecurityOrigin>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBSECURITYORIGIN_IDX],
        _QList_QWebSecurityOrigin__PythonToCpp__QList_QWebSecurityOrigin_,
        is__QList_QWebSecurityOrigin__PythonToCpp__QList_QWebSecurityOrigin__Convertible);

    // Register converter for type 'QList<QWebDatabase>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBDATABASE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebDatabase__CppToPython__QList_QWebDatabase_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBDATABASE_IDX], "QList<QWebDatabase>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBDATABASE_IDX],
        _QList_QWebDatabase__PythonToCpp__QList_QWebDatabase_,
        is__QList_QWebDatabase__PythonToCpp__QList_QWebDatabase__Convertible);

    // Register converter for type 'QList<QWebHistoryItem>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBHISTORYITEM_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebHistoryItem__CppToPython__QList_QWebHistoryItem_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBHISTORYITEM_IDX], "QList<QWebHistoryItem>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBHISTORYITEM_IDX],
        _QList_QWebHistoryItem__PythonToCpp__QList_QWebHistoryItem_,
        is__QList_QWebHistoryItem__PythonToCpp__QList_QWebHistoryItem__Convertible);

    // Register converter for type 'QList<QWebElement>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBELEMENT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebElement__CppToPython__QList_QWebElement_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBELEMENT_IDX], "QList<QWebElement>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBELEMENT_IDX],
        _QList_QWebElement__PythonToCpp__QList_QWebElement_,
        is__QList_QWebElement__PythonToCpp__QList_QWebElement__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'QList<QWebPluginFactory::Plugin>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_PLUGIN_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebPluginFactory_Plugin__CppToPython__QList_QWebPluginFactory_Plugin_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_PLUGIN_IDX], "QList<QWebPluginFactory::Plugin>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_PLUGIN_IDX],
        _QList_QWebPluginFactory_Plugin__PythonToCpp__QList_QWebPluginFactory_Plugin_,
        is__QList_QWebPluginFactory_Plugin__PythonToCpp__QList_QWebPluginFactory_Plugin__Convertible);

    // Register converter for type 'QList<QWebPluginFactory::MimeType>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_MIMETYPE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebPluginFactory_MimeType__CppToPython__QList_QWebPluginFactory_MimeType_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_MIMETYPE_IDX], "QList<QWebPluginFactory::MimeType>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_MIMETYPE_IDX],
        _QList_QWebPluginFactory_MimeType__PythonToCpp__QList_QWebPluginFactory_MimeType_,
        is__QList_QWebPluginFactory_MimeType__PythonToCpp__QList_QWebPluginFactory_MimeType__Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'QList<QWebFrame*>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBFRAMEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QWebFramePTR__CppToPython__QList_QWebFramePTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBFRAMEPTR_IDX], "QList<QWebFrame*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBFRAMEPTR_IDX],
        _QList_QWebFramePTR__PythonToCpp__QList_QWebFramePTR_,
        is__QList_QWebFramePTR__PythonToCpp__QList_QWebFramePTR__Convertible);

    // Register converter for type 'QMultiMap<QString,QString>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMULTIMAP_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMultiMap_QString_QString__CppToPython__QMultiMap_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMULTIMAP_QSTRING_QSTRING_IDX], "QMultiMap<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMULTIMAP_QSTRING_QSTRING_IDX],
        _QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString_,
        is__QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtWebKitTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtWebKitTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtWebKit");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
