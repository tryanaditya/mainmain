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
#include "pyside_qtmultimedia_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_QtMultimediaTypes;
// Current module's converter array.
SbkConverter** SbkPySide_QtMultimediaTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_QtMultimedia_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_QtMultimediaTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef QtMultimedia_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QAbstractVideoBuffer(PyObject* module);
void init_QVideoSurfaceFormat(PyObject* module);
void init_QVideoFrame(PyObject* module);
void init_QAudioFormat(PyObject* module);
void init_QAudioEngineFactoryInterface(PyObject* module);
void init_QAudioDeviceInfo(PyObject* module);
void init_QAbstractAudioDeviceInfo(PyObject* module);
void init_QAbstractAudioOutput(PyObject* module);
void init_QAbstractAudioInput(PyObject* module);
void init_QAudioEnginePlugin(PyObject* module);
void init_QAudioInput(PyObject* module);
void init_QAudioOutput(PyObject* module);
void init_QAbstractVideoSurface(PyObject* module);
void init_QAudio(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtGuiTypes;
SbkConverter** SbkPySide_QtGuiTypeConverters;
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QList<QAudioDeviceInfo >'.
static PyObject* _QList_QAudioDeviceInfo__CppToPython__QList_QAudioDeviceInfo_(const void* cppIn) {
    ::QList<QAudioDeviceInfo >& cppInRef = *((::QList<QAudioDeviceInfo >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAudioDeviceInfo >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAudioDeviceInfo cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QAudioDeviceInfo__PythonToCpp__QList_QAudioDeviceInfo_(PyObject* pyIn, void* cppOut) {
    ::QList<QAudioDeviceInfo >& cppOutRef = *((::QList<QAudioDeviceInfo >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAudioDeviceInfo cppItem = ::QAudioDeviceInfo();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QAudioDeviceInfo__PythonToCpp__QList_QAudioDeviceInfo__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], pyIn))
        return _QList_QAudioDeviceInfo__PythonToCpp__QList_QAudioDeviceInfo_;
    return 0;
}

// C++ to Python conversion for type 'QList<QAudioFormat::Endian >'.
static PyObject* _QList_QAudioFormat_Endian__CppToPython__QList_QAudioFormat_Endian_(const void* cppIn) {
    ::QList<QAudioFormat::Endian >& cppInRef = *((::QList<QAudioFormat::Endian >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAudioFormat::Endian >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAudioFormat::Endian cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QAudioFormat_Endian__PythonToCpp__QList_QAudioFormat_Endian_(PyObject* pyIn, void* cppOut) {
    ::QList<QAudioFormat::Endian >& cppOutRef = *((::QList<QAudioFormat::Endian >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAudioFormat::Endian cppItem = ((::QAudioFormat::Endian)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QAudioFormat_Endian__PythonToCpp__QList_QAudioFormat_Endian__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]), pyIn))
        return _QList_QAudioFormat_Endian__PythonToCpp__QList_QAudioFormat_Endian_;
    return 0;
}

// C++ to Python conversion for type 'QList<int >'.
static PyObject* _QList_int__CppToPython__QList_int_(const void* cppIn) {
    ::QList<int >& cppInRef = *((::QList<int >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<int >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            int cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_int__PythonToCpp__QList_int_(PyObject* pyIn, void* cppOut) {
    ::QList<int >& cppOutRef = *((::QList<int >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_int__PythonToCpp__QList_int__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return _QList_int__PythonToCpp__QList_int_;
    return 0;
}

// C++ to Python conversion for type 'QList<QAudioFormat::SampleType >'.
static PyObject* _QList_QAudioFormat_SampleType__CppToPython__QList_QAudioFormat_SampleType_(const void* cppIn) {
    ::QList<QAudioFormat::SampleType >& cppInRef = *((::QList<QAudioFormat::SampleType >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QAudioFormat::SampleType >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QAudioFormat::SampleType cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QAudioFormat_SampleType__PythonToCpp__QList_QAudioFormat_SampleType_(PyObject* pyIn, void* cppOut) {
    ::QList<QAudioFormat::SampleType >& cppOutRef = *((::QList<QAudioFormat::SampleType >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QAudioFormat::SampleType cppItem = ((::QAudioFormat::SampleType)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QAudioFormat_SampleType__PythonToCpp__QList_QAudioFormat_SampleType__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]), pyIn))
        return _QList_QAudioFormat_SampleType__PythonToCpp__QList_QAudioFormat_SampleType_;
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

// C++ to Python conversion for type 'QList<QVideoFrame::PixelFormat >'.
static PyObject* _QList_QVideoFrame_PixelFormat__CppToPython__QList_QVideoFrame_PixelFormat_(const void* cppIn) {
    ::QList<QVideoFrame::PixelFormat >& cppInRef = *((::QList<QVideoFrame::PixelFormat >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QVideoFrame::PixelFormat >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QVideoFrame::PixelFormat cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QVideoFrame_PixelFormat__PythonToCpp__QList_QVideoFrame_PixelFormat_(PyObject* pyIn, void* cppOut) {
    ::QList<QVideoFrame::PixelFormat >& cppOutRef = *((::QList<QVideoFrame::PixelFormat >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QVideoFrame::PixelFormat cppItem = ((::QVideoFrame::PixelFormat)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QVideoFrame_PixelFormat__PythonToCpp__QList_QVideoFrame_PixelFormat__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), pyIn))
        return _QList_QVideoFrame_PixelFormat__PythonToCpp__QList_QVideoFrame_PixelFormat_;
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
    /* m_name     */ "QtMultimedia",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ QtMultimedia_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(QtMultimedia)
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
    static PyTypeObject* cppApi[SBK_QtMultimedia_IDX_COUNT];
    SbkPySide_QtMultimediaTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_QtMultimedia_CONVERTERS_IDX_COUNT];
    SbkPySide_QtMultimediaTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("QtMultimedia", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("QtMultimedia", QtMultimedia_methods);
#endif

    // Initialize classes in the type system
    init_QAbstractVideoBuffer(module);
    init_QVideoSurfaceFormat(module);
    init_QVideoFrame(module);
    init_QAudioFormat(module);
    init_QAudioEngineFactoryInterface(module);
    init_QAudioDeviceInfo(module);
    init_QAbstractAudioDeviceInfo(module);
    init_QAbstractAudioOutput(module);
    init_QAbstractAudioInput(module);
    init_QAudioEnginePlugin(module);
    init_QAudioInput(module);
    init_QAudioOutput(module);
    init_QAbstractVideoSurface(module);
    init_QAudio(module);

    // Register converter for type 'QList<QAudioDeviceInfo>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIODEVICEINFO_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QAudioDeviceInfo__CppToPython__QList_QAudioDeviceInfo_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIODEVICEINFO_IDX], "QList<QAudioDeviceInfo>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIODEVICEINFO_IDX],
        _QList_QAudioDeviceInfo__PythonToCpp__QList_QAudioDeviceInfo_,
        is__QList_QAudioDeviceInfo__PythonToCpp__QList_QAudioDeviceInfo__Convertible);

    // Register converter for type 'QList<QAudioFormat::Endian>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QAudioFormat_Endian__CppToPython__QList_QAudioFormat_Endian_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX], "QList<QAudioFormat::Endian>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX],
        _QList_QAudioFormat_Endian__PythonToCpp__QList_QAudioFormat_Endian_,
        is__QList_QAudioFormat_Endian__PythonToCpp__QList_QAudioFormat_Endian__Convertible);

    // Register converter for type 'QList<int>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_int__CppToPython__QList_int_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], "QList<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX],
        _QList_int__PythonToCpp__QList_int_,
        is__QList_int__PythonToCpp__QList_int__Convertible);

    // Register converter for type 'QList<QAudioFormat::SampleType>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QAudioFormat_SampleType__CppToPython__QList_QAudioFormat_SampleType_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX], "QList<QAudioFormat::SampleType>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX],
        _QList_QAudioFormat_SampleType__PythonToCpp__QList_QAudioFormat_SampleType_,
        is__QList_QAudioFormat_SampleType__PythonToCpp__QList_QAudioFormat_SampleType__Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QVideoFrame::PixelFormat>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVIDEOFRAME_PIXELFORMAT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVideoFrame_PixelFormat__CppToPython__QList_QVideoFrame_PixelFormat_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVIDEOFRAME_PIXELFORMAT_IDX], "QList<QVideoFrame::PixelFormat>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVIDEOFRAME_PIXELFORMAT_IDX],
        _QList_QVideoFrame_PixelFormat__PythonToCpp__QList_QVideoFrame_PixelFormat_,
        is__QList_QVideoFrame_PixelFormat__PythonToCpp__QList_QVideoFrame_PixelFormat__Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_QtMultimediaTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_QtMultimediaTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module QtMultimedia");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
