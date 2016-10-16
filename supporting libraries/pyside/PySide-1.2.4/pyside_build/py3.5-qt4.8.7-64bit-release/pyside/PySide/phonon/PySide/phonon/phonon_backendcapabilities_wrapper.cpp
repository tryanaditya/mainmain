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
#include "pyside_phonon_python.h"

#include "phonon_backendcapabilities_wrapper.h"
#include "phonon_backendcapabilities_notifierwrapper_wrapper.h"

// Extra includes
#include <QList>
#include <objectdescription.h>
#include "pyside_phonon.h"

using namespace Phonon;

// Begin code injection

Phonon::BackendCapabilities::NotifierWrapper* Phonon::BackendCapabilities::NotifierWrapper::m_instance = 0;
Phonon::BackendCapabilities::Notifier* Phonon::BackendCapabilities::NotifierWrapper::m_notifier = 0;

// End of code injection


// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableAVCaptureDevices(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAVCaptureDevices()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::VideoCaptureDevice > cppResult = ::Phonon::BackendCapabilities::availableAVCaptureDevices();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_VIDEOCAPTUREDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableAudioCaptureDevices(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAudioCaptureDevices()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::AudioCaptureDevice > cppResult = ::Phonon::BackendCapabilities::availableAudioCaptureDevices();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCAPTUREDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableAudioEffects(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAudioEffects()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::EffectDescription > cppResult = ::Phonon::BackendCapabilities::availableAudioEffects();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTDESCRIPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableAudioOutputDevices(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAudioOutputDevices()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::AudioOutputDevice > cppResult = ::Phonon::BackendCapabilities::availableAudioOutputDevices();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOOUTPUTDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableMimeTypes(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableMimeTypes()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::Phonon::BackendCapabilities::availableMimeTypes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_availableVideoCaptureDevices(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableVideoCaptureDevices()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::VideoCaptureDevice > cppResult = ::Phonon::BackendCapabilities::availableVideoCaptureDevices();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_VIDEOCAPTUREDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_isMimeTypeAvailable(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isMimeTypeAvailable(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isMimeTypeAvailable(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendCapabilitiesFunc_isMimeTypeAvailable_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isMimeTypeAvailable(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::Phonon::BackendCapabilities::isMimeTypeAvailable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendCapabilitiesFunc_isMimeTypeAvailable_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.BackendCapabilities.isMimeTypeAvailable", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendCapabilitiesFunc_notifier(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notifier()
            // Begin code injection

            Phonon::BackendCapabilities::NotifierWrapper *_notifierWrapper =  Phonon::BackendCapabilities::NotifierWrapper::notifier();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_BACKENDCAPABILITIES_NOTIFIERWRAPPER_IDX], _notifierWrapper);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_BackendCapabilities_methods[] = {
    {"availableAVCaptureDevices", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableAVCaptureDevices, METH_NOARGS|METH_STATIC},
    {"availableAudioCaptureDevices", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableAudioCaptureDevices, METH_NOARGS|METH_STATIC},
    {"availableAudioEffects", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableAudioEffects, METH_NOARGS|METH_STATIC},
    {"availableAudioOutputDevices", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableAudioOutputDevices, METH_NOARGS|METH_STATIC},
    {"availableMimeTypes", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableMimeTypes, METH_NOARGS|METH_STATIC},
    {"availableVideoCaptureDevices", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_availableVideoCaptureDevices, METH_NOARGS|METH_STATIC},
    {"isMimeTypeAvailable", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_isMimeTypeAvailable, METH_O|METH_STATIC},
    {"notifier", (PyCFunction)Sbk_Phonon_BackendCapabilitiesFunc_notifier, METH_NOARGS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_BackendCapabilities_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_BackendCapabilities_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_BackendCapabilities_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.BackendCapabilities",
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
    /*tp_traverse*/         Sbk_Phonon_BackendCapabilities_traverse,
    /*tp_clear*/            Sbk_Phonon_BackendCapabilities_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_BackendCapabilities_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
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

void init_Phonon_BackendCapabilities(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_BACKENDCAPABILITIES_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_BackendCapabilities_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "BackendCapabilities", "Phonon::BackendCapabilities",
        &Sbk_Phonon_BackendCapabilities_Type, 0, 0, 0, true)) {
        return;
    }





}

