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
#include "pyside_phonon_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkPySide_phononTypes;
// Current module's converter array.
SbkConverter** SbkPySide_phononTypeConverters;
void cleanTypesAttributes(void) {
    for (int i = 0, imax = SBK_phonon_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkPySide_phononTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef phonon_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_Phonon(PyObject* module);
void init_Phonon_EffectWidget(PyObject* module);
void init_Phonon_SeekSlider(PyObject* module);
void init_Phonon_VideoPlayer(PyObject* module);
void init_Phonon_AudioOutputDeviceModel(PyObject* module);
void init_Phonon_EffectDescriptionModel(PyObject* module);
void init_Phonon_VolumeSlider(PyObject* module);
void init_Phonon_EffectDescription(PyObject* module);
void init_Phonon_VideoCaptureDevice(PyObject* module);
void init_Phonon_SubtitleDescription(PyObject* module);
void init_Phonon_AudioCaptureDevice(PyObject* module);
void init_Phonon_AudioOutputDevice(PyObject* module);
void init_Phonon_AudioChannelDescription(PyObject* module);
void init_Phonon_MediaController(PyObject* module);
void init_Phonon_Path(PyObject* module);
void init_Phonon_MediaNode(PyObject* module);
void init_Phonon_AbstractVideoOutput(PyObject* module);
void init_Phonon_VideoWidget(PyObject* module);
void init_Phonon_MediaObject(PyObject* module);
void init_Phonon_AddonInterface(PyObject* module);
void init_Phonon_BackendInterface(PyObject* module);
void init_Phonon_EffectInterface(PyObject* module);
void init_Phonon_EffectParameter(PyObject* module);
void init_Phonon_MediaSource(PyObject* module);
void init_Phonon_MediaObjectInterface(PyObject* module);
void init_Phonon_PlatformPlugin(PyObject* module);
void init_Phonon_StreamInterface(PyObject* module);
void init_Phonon_VideoWidgetInterface(PyObject* module);
void init_Phonon_VolumeFaderInterface(PyObject* module);
void init_Phonon_BackendCapabilities(PyObject* module);
void init_Phonon_BackendCapabilities_NotifierWrapper(PyObject* module);
void init_Phonon_AbstractAudioOutput(PyObject* module);
void init_Phonon_AudioOutput(PyObject* module);
void init_Phonon_AbstractMediaStream(PyObject* module);
void init_Phonon_Effect(PyObject* module);
void init_Phonon_VolumeFaderEffect(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide_QtGuiTypes;
SbkConverter** SbkPySide_QtGuiTypeConverters;
PyTypeObject** SbkPySide_QtCoreTypes;
SbkConverter** SbkPySide_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------
// Container Type converters.

// C++ to Python conversion for type 'QList<Phonon::VideoCaptureDevice >'.
static PyObject* _QList_Phonon_VideoCaptureDevice__CppToPython__QList_Phonon_VideoCaptureDevice_(const void* cppIn) {
    ::QList<Phonon::VideoCaptureDevice >& cppInRef = *((::QList<Phonon::VideoCaptureDevice >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::VideoCaptureDevice >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::VideoCaptureDevice cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_VideoCaptureDevice__PythonToCpp__QList_Phonon_VideoCaptureDevice_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::VideoCaptureDevice >& cppOutRef = *((::QList<Phonon::VideoCaptureDevice >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::VideoCaptureDevice cppItem = ::Phonon::VideoCaptureDevice();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_VideoCaptureDevice__PythonToCpp__QList_Phonon_VideoCaptureDevice__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], pyIn))
        return _QList_Phonon_VideoCaptureDevice__PythonToCpp__QList_Phonon_VideoCaptureDevice_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::AudioCaptureDevice >'.
static PyObject* _QList_Phonon_AudioCaptureDevice__CppToPython__QList_Phonon_AudioCaptureDevice_(const void* cppIn) {
    ::QList<Phonon::AudioCaptureDevice >& cppInRef = *((::QList<Phonon::AudioCaptureDevice >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::AudioCaptureDevice >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::AudioCaptureDevice cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_AudioCaptureDevice__PythonToCpp__QList_Phonon_AudioCaptureDevice_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::AudioCaptureDevice >& cppOutRef = *((::QList<Phonon::AudioCaptureDevice >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::AudioCaptureDevice cppItem = ::Phonon::AudioCaptureDevice();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_AudioCaptureDevice__PythonToCpp__QList_Phonon_AudioCaptureDevice__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], pyIn))
        return _QList_Phonon_AudioCaptureDevice__PythonToCpp__QList_Phonon_AudioCaptureDevice_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::EffectDescription >'.
static PyObject* _QList_Phonon_EffectDescription__CppToPython__QList_Phonon_EffectDescription_(const void* cppIn) {
    ::QList<Phonon::EffectDescription >& cppInRef = *((::QList<Phonon::EffectDescription >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::EffectDescription >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::EffectDescription cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTDESCRIPTION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_EffectDescription__PythonToCpp__QList_Phonon_EffectDescription_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::EffectDescription >& cppOutRef = *((::QList<Phonon::EffectDescription >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::EffectDescription cppItem = ::Phonon::EffectDescription();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTDESCRIPTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_EffectDescription__PythonToCpp__QList_Phonon_EffectDescription__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTDESCRIPTION_IDX], pyIn))
        return _QList_Phonon_EffectDescription__PythonToCpp__QList_Phonon_EffectDescription_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::AudioOutputDevice >'.
static PyObject* _QList_Phonon_AudioOutputDevice__CppToPython__QList_Phonon_AudioOutputDevice_(const void* cppIn) {
    ::QList<Phonon::AudioOutputDevice >& cppInRef = *((::QList<Phonon::AudioOutputDevice >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::AudioOutputDevice >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::AudioOutputDevice cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_AudioOutputDevice__PythonToCpp__QList_Phonon_AudioOutputDevice_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::AudioOutputDevice >& cppOutRef = *((::QList<Phonon::AudioOutputDevice >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::AudioOutputDevice cppItem = ::Phonon::AudioOutputDevice();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_AudioOutputDevice__PythonToCpp__QList_Phonon_AudioOutputDevice__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], pyIn))
        return _QList_Phonon_AudioOutputDevice__PythonToCpp__QList_Phonon_AudioOutputDevice_;
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

// C++ to Python conversion for type 'QPair<QByteArray, QString >'.
static PyObject* _QPair_QByteArray_QString__CppToPython__QPair_QByteArray_QString_(const void* cppIn) {
    ::QPair<QByteArray, QString >& cppInRef = *((::QPair<QByteArray, QString >*)cppIn);

            PyObject* pyOut = PyTuple_New(2);
            PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppInRef.first));
            PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.second));
            return pyOut;

}
static void _QPair_QByteArray_QString__PythonToCpp__QPair_QByteArray_QString_(PyObject* pyIn, void* cppOut) {
    ::QPair<QByteArray, QString >& cppOutRef = *((::QPair<QByteArray, QString >*)cppOut);

            Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is__QPair_QByteArray_QString__PythonToCpp__QPair_QByteArray_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return _QPair_QByteArray_QString__PythonToCpp__QPair_QByteArray_QString_;
    return 0;
}

// C++ to Python conversion for type 'QList<QPair<QByteArray, QString > >'.
static PyObject* _QList_QPair_QByteArray_QString___CppToPython__QList_QPair_QByteArray_QString__(const void* cppIn) {
    ::QList<QPair<QByteArray, QString > >& cppInRef = *((::QList<QPair<QByteArray, QString > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QPair<QByteArray, QString > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QPair<QByteArray, QString > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QPair_QByteArray_QString___PythonToCpp__QList_QPair_QByteArray_QString__(PyObject* pyIn, void* cppOut) {
    ::QList<QPair<QByteArray, QString > >& cppOutRef = *((::QList<QPair<QByteArray, QString > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QPair<QByteArray, QString > cppItem = ::QPair<QByteArray, QString >();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QPair_QByteArray_QString___PythonToCpp__QList_QPair_QByteArray_QString___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX], pyIn))
        return _QList_QPair_QByteArray_QString___PythonToCpp__QList_QPair_QByteArray_QString__;
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

// C++ to Python conversion for type 'QHash<QByteArray, QVariant >'.
static PyObject* _QHash_QByteArray_QVariant__CppToPython__QHash_QByteArray_QVariant_(const void* cppIn) {
    ::QHash<QByteArray, QVariant >& cppInRef = *((::QHash<QByteArray, QVariant >*)cppIn);

                // TEMPLATE - cppmap_to_pymap_conversion - START
        PyObject* pyOut = PyDict_New();
        ::QHash<QByteArray, QVariant >::const_iterator it = cppInRef.begin();
        for (; it != cppInRef.end(); ++it) {
            ::QByteArray key = it.key();
            ::QVariant value = it.value();
            PyObject* pyKey = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
        }
        return pyOut;
      // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QHash_QByteArray_QVariant__PythonToCpp__QHash_QByteArray_QVariant_(PyObject* pyIn, void* cppOut) {
    ::QHash<QByteArray, QVariant >& cppOutRef = *((::QHash<QByteArray, QVariant >*)cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QByteArray cppKey = ::QByteArray();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], key, &(cppKey));
        ::QVariant cppValue = ::QVariant();
        Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
        cppOutRef.insert(cppKey, cppValue);
    }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QHash_QByteArray_QVariant__PythonToCpp__QHash_QByteArray_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX]), false, SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QHash_QByteArray_QVariant__PythonToCpp__QHash_QByteArray_QVariant_;
    return 0;
}

// C++ to Python conversion for type 'const QList<Phonon::ObjectDescription<Phonon::EffectType > > &'.
static PyObject* _constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_CppToPython__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF(const void* cppIn) {
    ::QList<Phonon::ObjectDescription<Phonon::EffectType > >& cppInRef = *((::QList<Phonon::ObjectDescription<Phonon::EffectType > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::ObjectDescription<Phonon::EffectType > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::ObjectDescription<Phonon::EffectType > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::ObjectDescription<Phonon::EffectType > >& cppOutRef = *((::QList<Phonon::ObjectDescription<Phonon::EffectType > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::ObjectDescription<Phonon::EffectType > cppItem = ::Phonon::ObjectDescription<Phonon::EffectType >();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE_IDX], pyIn))
        return _constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF;
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

// C++ to Python conversion for type 'const QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > > &'.
static PyObject* _constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_CppToPython__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF(const void* cppIn) {
    ::QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > >& cppInRef = *((::QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > >& cppOutRef = *((::QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::ObjectDescription<Phonon::AudioOutputDeviceType > cppItem = ::Phonon::ObjectDescription<Phonon::AudioOutputDeviceType >();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE_IDX], pyIn))
        return _constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::AudioChannelDescription >'.
static PyObject* _QList_Phonon_AudioChannelDescription__CppToPython__QList_Phonon_AudioChannelDescription_(const void* cppIn) {
    ::QList<Phonon::AudioChannelDescription >& cppInRef = *((::QList<Phonon::AudioChannelDescription >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::AudioChannelDescription >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::AudioChannelDescription cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_AudioChannelDescription__PythonToCpp__QList_Phonon_AudioChannelDescription_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::AudioChannelDescription >& cppOutRef = *((::QList<Phonon::AudioChannelDescription >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::AudioChannelDescription cppItem = ::Phonon::AudioChannelDescription();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_AudioChannelDescription__PythonToCpp__QList_Phonon_AudioChannelDescription__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], pyIn))
        return _QList_Phonon_AudioChannelDescription__PythonToCpp__QList_Phonon_AudioChannelDescription_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::MediaController::NavigationMenu >'.
static PyObject* _QList_Phonon_MediaController_NavigationMenu__CppToPython__QList_Phonon_MediaController_NavigationMenu_(const void* cppIn) {
    ::QList<Phonon::MediaController::NavigationMenu >& cppInRef = *((::QList<Phonon::MediaController::NavigationMenu >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::MediaController::NavigationMenu >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::MediaController::NavigationMenu cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]), &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_MediaController_NavigationMenu__PythonToCpp__QList_Phonon_MediaController_NavigationMenu_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::MediaController::NavigationMenu >& cppOutRef = *((::QList<Phonon::MediaController::NavigationMenu >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::MediaController::NavigationMenu cppItem = ((::Phonon::MediaController::NavigationMenu)0);
        Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]), pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_MediaController_NavigationMenu__PythonToCpp__QList_Phonon_MediaController_NavigationMenu__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]), pyIn))
        return _QList_Phonon_MediaController_NavigationMenu__PythonToCpp__QList_Phonon_MediaController_NavigationMenu_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::SubtitleDescription >'.
static PyObject* _QList_Phonon_SubtitleDescription__CppToPython__QList_Phonon_SubtitleDescription_(const void* cppIn) {
    ::QList<Phonon::SubtitleDescription >& cppInRef = *((::QList<Phonon::SubtitleDescription >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::SubtitleDescription >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::SubtitleDescription cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_SubtitleDescription__PythonToCpp__QList_Phonon_SubtitleDescription_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::SubtitleDescription >& cppOutRef = *((::QList<Phonon::SubtitleDescription >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::SubtitleDescription cppItem = ::Phonon::SubtitleDescription();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_SubtitleDescription__PythonToCpp__QList_Phonon_SubtitleDescription__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], pyIn))
        return _QList_Phonon_SubtitleDescription__PythonToCpp__QList_Phonon_SubtitleDescription_;
    return 0;
}

// C++ to Python conversion for type 'const QList<QVariant > &'.
static PyObject* _constQList_QVariant_REF_CppToPython__constQList_QVariant_REF(const void* cppIn) {
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
static void _constQList_QVariant_REF_PythonToCpp__constQList_QVariant_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQList_QVariant_REF_PythonToCpp__constQList_QVariant_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return _constQList_QVariant_REF_PythonToCpp__constQList_QVariant_REF;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::EffectParameter >'.
static PyObject* _QList_Phonon_EffectParameter__CppToPython__QList_Phonon_EffectParameter_(const void* cppIn) {
    ::QList<Phonon::EffectParameter >& cppInRef = *((::QList<Phonon::EffectParameter >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::EffectParameter >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::EffectParameter cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_EffectParameter__PythonToCpp__QList_Phonon_EffectParameter_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::EffectParameter >& cppOutRef = *((::QList<Phonon::EffectParameter >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::EffectParameter cppItem = ::Phonon::EffectParameter();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_EffectParameter__PythonToCpp__QList_Phonon_EffectParameter__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pyIn))
        return _QList_Phonon_EffectParameter__PythonToCpp__QList_Phonon_EffectParameter_;
    return 0;
}

// C++ to Python conversion for type 'QSet<QObject * >'.
static PyObject* _QSet_QObjectPTR__CppToPython__QSet_QObjectPTR_(const void* cppIn) {
    ::QSet<QObject * >& cppInRef = *((::QSet<QObject * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QSet<QObject * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QObject* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QSet_QObjectPTR__PythonToCpp__QSet_QObjectPTR_(PyObject* pyIn, void* cppOut) {
    ::QSet<QObject * >& cppOutRef = *((::QSet<QObject * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QObject* cppItem = ((::QObject*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QSet_QObjectPTR__PythonToCpp__QSet_QObjectPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyIn))
        return _QSet_QObjectPTR__PythonToCpp__QSet_QObjectPTR_;
    return 0;
}

// C++ to Python conversion for type 'QList<Phonon::Path >'.
static PyObject* _QList_Phonon_Path__CppToPython__QList_Phonon_Path_(const void* cppIn) {
    ::QList<Phonon::Path >& cppInRef = *((::QList<Phonon::Path >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::Path >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::Path cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_Path__PythonToCpp__QList_Phonon_Path_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::Path >& cppOutRef = *((::QList<Phonon::Path >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::Path cppItem = ::Phonon::Path();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_Path__PythonToCpp__QList_Phonon_Path__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_PATH_IDX], pyIn))
        return _QList_Phonon_Path__PythonToCpp__QList_Phonon_Path_;
    return 0;
}

// C++ to Python conversion for type 'const QList<Phonon::MediaSource > &'.
static PyObject* _constQList_Phonon_MediaSource_REF_CppToPython__constQList_Phonon_MediaSource_REF(const void* cppIn) {
    ::QList<Phonon::MediaSource >& cppInRef = *((::QList<Phonon::MediaSource >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::MediaSource >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::MediaSource cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _constQList_Phonon_MediaSource_REF_PythonToCpp__constQList_Phonon_MediaSource_REF(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::MediaSource >& cppOutRef = *((::QList<Phonon::MediaSource >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::MediaSource cppItem = ::Phonon::MediaSource();
        Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__constQList_Phonon_MediaSource_REF_PythonToCpp__constQList_Phonon_MediaSource_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pyIn))
        return _constQList_Phonon_MediaSource_REF_PythonToCpp__constQList_Phonon_MediaSource_REF;
    return 0;
}

// C++ to Python conversion for type 'const QList<QUrl > &'.
static PyObject* _constQList_QUrl_REF_CppToPython__constQList_QUrl_REF(const void* cppIn) {
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
static void _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF(PyObject* pyIn, void* cppOut) {
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
static PythonToCppFunc is__constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF;
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

// C++ to Python conversion for type 'QList<Phonon::Effect * >'.
static PyObject* _QList_Phonon_EffectPTR__CppToPython__QList_Phonon_EffectPTR_(const void* cppIn) {
    ::QList<Phonon::Effect * >& cppInRef = *((::QList<Phonon::Effect * >*)cppIn);

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<Phonon::Effect * >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Phonon::Effect* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], cppItem));
        }
        return pyOut;
        // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_Phonon_EffectPTR__PythonToCpp__QList_Phonon_EffectPTR_(PyObject* pyIn, void* cppOut) {
    ::QList<Phonon::Effect * >& cppOutRef = *((::QList<Phonon::Effect * >*)cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Phonon::Effect* cppItem = ((::Phonon::Effect*)0);
        Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_Phonon_EffectPTR__PythonToCpp__QList_Phonon_EffectPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], pyIn))
        return _QList_Phonon_EffectPTR__PythonToCpp__QList_Phonon_EffectPTR_;
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
    /* m_name     */ "phonon",
    /* m_doc      */ 0,
    /* m_size     */ -1,
    /* m_methods  */ phonon_methods,
    /* m_reload   */ 0,
    /* m_traverse */ 0,
    /* m_clear    */ 0,
    /* m_free     */ 0
};

#endif
SBK_MODULE_INIT_FUNCTION_BEGIN(phonon)
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
    static PyTypeObject* cppApi[SBK_phonon_IDX_COUNT];
    SbkPySide_phononTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_phonon_CONVERTERS_IDX_COUNT];
    SbkPySide_phononTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("phonon", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("phonon", phonon_methods);
#endif

    // Initialize classes in the type system
    init_Phonon(module);
    init_Phonon_EffectWidget(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_SeekSlider(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VideoPlayer(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AudioOutputDeviceModel(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_EffectDescriptionModel(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VolumeSlider(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_EffectDescription(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VideoCaptureDevice(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_SubtitleDescription(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AudioCaptureDevice(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AudioOutputDevice(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AudioChannelDescription(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_MediaController(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_Path(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_MediaNode(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AbstractVideoOutput(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VideoWidget(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_MediaObject(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AddonInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_BackendInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_EffectInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_EffectParameter(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_MediaSource(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_MediaObjectInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_PlatformPlugin(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_StreamInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VideoWidgetInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VolumeFaderInterface(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_BackendCapabilities(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_BackendCapabilities_NotifierWrapper(SbkPySide_phononTypes[SBK_PHONON_BACKENDCAPABILITIES_IDX]->tp_dict);
    init_Phonon_AbstractAudioOutput(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AudioOutput(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_AbstractMediaStream(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_Effect(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);
    init_Phonon_VolumeFaderEffect(SbkPySide_phononTypes[SBK_PHONON_IDX]->tp_dict);

    // Register converter for type 'QList<Phonon::VideoCaptureDevice>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_VIDEOCAPTUREDEVICE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_VideoCaptureDevice__CppToPython__QList_Phonon_VideoCaptureDevice_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_VIDEOCAPTUREDEVICE_IDX], "QList<Phonon::VideoCaptureDevice>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_VIDEOCAPTUREDEVICE_IDX],
        _QList_Phonon_VideoCaptureDevice__PythonToCpp__QList_Phonon_VideoCaptureDevice_,
        is__QList_Phonon_VideoCaptureDevice__PythonToCpp__QList_Phonon_VideoCaptureDevice__Convertible);

    // Register converter for type 'QList<Phonon::AudioCaptureDevice>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCAPTUREDEVICE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_AudioCaptureDevice__CppToPython__QList_Phonon_AudioCaptureDevice_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCAPTUREDEVICE_IDX], "QList<Phonon::AudioCaptureDevice>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCAPTUREDEVICE_IDX],
        _QList_Phonon_AudioCaptureDevice__PythonToCpp__QList_Phonon_AudioCaptureDevice_,
        is__QList_Phonon_AudioCaptureDevice__PythonToCpp__QList_Phonon_AudioCaptureDevice__Convertible);

    // Register converter for type 'QList<Phonon::EffectDescription>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTDESCRIPTION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_EffectDescription__CppToPython__QList_Phonon_EffectDescription_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTDESCRIPTION_IDX], "QList<Phonon::EffectDescription>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTDESCRIPTION_IDX],
        _QList_Phonon_EffectDescription__PythonToCpp__QList_Phonon_EffectDescription_,
        is__QList_Phonon_EffectDescription__PythonToCpp__QList_Phonon_EffectDescription__Convertible);

    // Register converter for type 'QList<Phonon::AudioOutputDevice>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOOUTPUTDEVICE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_AudioOutputDevice__CppToPython__QList_Phonon_AudioOutputDevice_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOOUTPUTDEVICE_IDX], "QList<Phonon::AudioOutputDevice>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOOUTPUTDEVICE_IDX],
        _QList_Phonon_AudioOutputDevice__PythonToCpp__QList_Phonon_AudioOutputDevice_,
        is__QList_Phonon_AudioOutputDevice__PythonToCpp__QList_Phonon_AudioOutputDevice__Convertible);

    // Register converter for type 'const QList<QObject*>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QObjectPTR_REF_CppToPython__constQList_QObjectPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QOBJECTPTR_IDX], "const QList<QObject*>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QOBJECTPTR_IDX], "QList<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QOBJECTPTR_IDX],
        _constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF,
        is__constQList_QObjectPTR_REF_PythonToCpp__constQList_QObjectPTR_REF_Convertible);

    // Register converter for type 'QList<QByteArray>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QByteArray__CppToPython__QList_QByteArray_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QBYTEARRAY_IDX], "QList<QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QBYTEARRAY_IDX],
        _QList_QByteArray__PythonToCpp__QList_QByteArray_,
        is__QList_QByteArray__PythonToCpp__QList_QByteArray__Convertible);

    // Register converter for type 'QList<QAction*>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QACTIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QActionPTR__CppToPython__QList_QActionPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QACTIONPTR_IDX], "QList<QAction*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QACTIONPTR_IDX],
        _QList_QActionPTR__PythonToCpp__QList_QActionPTR_,
        is__QList_QActionPTR__PythonToCpp__QList_QActionPTR__Convertible);

    // Register converter for type 'QPair<QByteArray,QString>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QPair_QByteArray_QString__CppToPython__QPair_QByteArray_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX], "QPair<QByteArray,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX],
        _QPair_QByteArray_QString__PythonToCpp__QPair_QByteArray_QString_,
        is__QPair_QByteArray_QString__PythonToCpp__QPair_QByteArray_QString__Convertible);

    // Register converter for type 'QList<QPair<QByteArray,QString>>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QPair_QByteArray_QString___CppToPython__QList_QPair_QByteArray_QString__);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], "QList<QPair<QByteArray,QString>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX],
        _QList_QPair_QByteArray_QString___PythonToCpp__QList_QPair_QByteArray_QString__,
        is__QList_QPair_QByteArray_QString___PythonToCpp__QList_QPair_QByteArray_QString___Convertible);

    // Register converter for type 'QList<int>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_int__CppToPython__QList_int_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX], "QList<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX],
        _QList_int__PythonToCpp__QList_int_,
        is__QList_int__PythonToCpp__QList_int__Convertible);

    // Register converter for type 'QHash<QByteArray,QVariant>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QHash_QByteArray_QVariant__CppToPython__QHash_QByteArray_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX], "QHash<QByteArray,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX],
        _QHash_QByteArray_QVariant__PythonToCpp__QHash_QByteArray_QVariant_,
        is__QHash_QByteArray_QVariant__PythonToCpp__QHash_QByteArray_QVariant__Convertible);

    // Register converter for type 'const QList<Phonon::ObjectDescription<Phonon::EffectType>>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE__IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_CppToPython__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE__IDX], "const QList<Phonon::ObjectDescription<Phonon::EffectType>>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE__IDX], "QList<Phonon::ObjectDescription<Phonon::EffectType>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_EFFECTTYPE__IDX],
        _constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF,
        is__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_EffectType__REF_Convertible);

    // Register converter for type 'QMap<int,QVariant>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_INT_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_int_QVariant__CppToPython__QMap_int_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_INT_QVARIANT_IDX], "QMap<int,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_INT_QVARIANT_IDX],
        _QMap_int_QVariant__PythonToCpp__QMap_int_QVariant_,
        is__QMap_int_QVariant__PythonToCpp__QMap_int_QVariant__Convertible);

    // Register converter for type 'const QHash<int,QByteArray>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_INT_QBYTEARRAY_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _constQHash_int_QByteArray_REF_CppToPython__constQHash_int_QByteArray_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_INT_QBYTEARRAY_IDX], "const QHash<int,QByteArray>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_INT_QBYTEARRAY_IDX], "QHash<int,QByteArray>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_INT_QBYTEARRAY_IDX],
        _constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF,
        is__constQHash_int_QByteArray_REF_PythonToCpp__constQHash_int_QByteArray_REF_Convertible);

    // Register converter for type 'const QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType>>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE__IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_CppToPython__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE__IDX], "const QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType>>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE__IDX], "QList<Phonon::ObjectDescription<Phonon::AudioOutputDeviceType>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_OBJECTDESCRIPTION_PHONON_AUDIOOUTPUTDEVICETYPE__IDX],
        _constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF,
        is__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_PythonToCpp__constQList_Phonon_ObjectDescription_Phonon_AudioOutputDeviceType__REF_Convertible);

    // Register converter for type 'QList<Phonon::AudioChannelDescription>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCHANNELDESCRIPTION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_AudioChannelDescription__CppToPython__QList_Phonon_AudioChannelDescription_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCHANNELDESCRIPTION_IDX], "QList<Phonon::AudioChannelDescription>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCHANNELDESCRIPTION_IDX],
        _QList_Phonon_AudioChannelDescription__PythonToCpp__QList_Phonon_AudioChannelDescription_,
        is__QList_Phonon_AudioChannelDescription__PythonToCpp__QList_Phonon_AudioChannelDescription__Convertible);

    // Register converter for type 'QList<Phonon::MediaController::NavigationMenu>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_MediaController_NavigationMenu__CppToPython__QList_Phonon_MediaController_NavigationMenu_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX], "QList<Phonon::MediaController::NavigationMenu>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        _QList_Phonon_MediaController_NavigationMenu__PythonToCpp__QList_Phonon_MediaController_NavigationMenu_,
        is__QList_Phonon_MediaController_NavigationMenu__PythonToCpp__QList_Phonon_MediaController_NavigationMenu__Convertible);

    // Register converter for type 'QList<Phonon::SubtitleDescription>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_SUBTITLEDESCRIPTION_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_SubtitleDescription__CppToPython__QList_Phonon_SubtitleDescription_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_SUBTITLEDESCRIPTION_IDX], "QList<Phonon::SubtitleDescription>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_SUBTITLEDESCRIPTION_IDX],
        _QList_Phonon_SubtitleDescription__PythonToCpp__QList_Phonon_SubtitleDescription_,
        is__QList_Phonon_SubtitleDescription__PythonToCpp__QList_Phonon_SubtitleDescription__Convertible);

    // Register converter for type 'const QList<QVariant>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QVariant_REF_CppToPython__constQList_QVariant_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], "const QList<QVariant>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX],
        _constQList_QVariant_REF_PythonToCpp__constQList_QVariant_REF,
        is__constQList_QVariant_REF_PythonToCpp__constQList_QVariant_REF_Convertible);

    // Register converter for type 'QList<Phonon::EffectParameter>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPARAMETER_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_EffectParameter__CppToPython__QList_Phonon_EffectParameter_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPARAMETER_IDX], "QList<Phonon::EffectParameter>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPARAMETER_IDX],
        _QList_Phonon_EffectParameter__PythonToCpp__QList_Phonon_EffectParameter_,
        is__QList_Phonon_EffectParameter__PythonToCpp__QList_Phonon_EffectParameter__Convertible);

    // Register converter for type 'QSet<QObject*>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX] = Shiboken::Conversions::createConverter(&PySet_Type, _QSet_QObjectPTR__CppToPython__QSet_QObjectPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX], "QSet<QObject*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX],
        _QSet_QObjectPTR__PythonToCpp__QSet_QObjectPTR_,
        is__QSet_QObjectPTR__PythonToCpp__QSet_QObjectPTR__Convertible);

    // Register converter for type 'QList<Phonon::Path>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_PATH_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_Path__CppToPython__QList_Phonon_Path_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_PATH_IDX], "QList<Phonon::Path>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_PATH_IDX],
        _QList_Phonon_Path__PythonToCpp__QList_Phonon_Path_,
        is__QList_Phonon_Path__PythonToCpp__QList_Phonon_Path__Convertible);

    // Register converter for type 'const QList<Phonon::MediaSource>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_Phonon_MediaSource_REF_CppToPython__constQList_Phonon_MediaSource_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX], "const QList<Phonon::MediaSource>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX], "QList<Phonon::MediaSource>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX],
        _constQList_Phonon_MediaSource_REF_PythonToCpp__constQList_Phonon_MediaSource_REF,
        is__constQList_Phonon_MediaSource_REF_PythonToCpp__constQList_Phonon_MediaSource_REF_Convertible);

    // Register converter for type 'const QList<QUrl>&'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _constQList_QUrl_REF_CppToPython__constQList_QUrl_REF);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX], "const QList<QUrl>&");
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX], "QList<QUrl>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX],
        _constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF,
        is__constQList_QUrl_REF_PythonToCpp__constQList_QUrl_REF_Convertible);

    // Register converter for type 'QMultiMap<QString,QString>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QMULTIMAP_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMultiMap_QString_QString__CppToPython__QMultiMap_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QMULTIMAP_QSTRING_QSTRING_IDX], "QMultiMap<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QMULTIMAP_QSTRING_QSTRING_IDX],
        _QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString_,
        is__QMultiMap_QString_QString__PythonToCpp__QMultiMap_QString_QString__Convertible);

    // Register converter for type 'QList<Phonon::Effect*>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_Phonon_EffectPTR__CppToPython__QList_Phonon_EffectPTR_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPTR_IDX], "QList<Phonon::Effect*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPTR_IDX],
        _QList_Phonon_EffectPTR__PythonToCpp__QList_Phonon_EffectPTR_,
        is__QList_Phonon_EffectPTR__PythonToCpp__QList_Phonon_EffectPTR__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkPySide_phononTypeConverters[SBK_PHONON_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbkPySide_phononTypes);
    Shiboken::Module::registerTypeConverters(module, SbkPySide_phononTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module phonon");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);
SBK_MODULE_INIT_FUNCTION_END
