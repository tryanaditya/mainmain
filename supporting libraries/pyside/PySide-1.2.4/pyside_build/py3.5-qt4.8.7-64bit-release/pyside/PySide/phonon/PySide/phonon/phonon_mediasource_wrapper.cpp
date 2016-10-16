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
#include "pyside_phonon_python.h"

#include "phonon_mediasource_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <abstractmediastream.h>
#include <mediasource.h>
#include <objectdescription.h>
#include <qbytearray.h>
#include <qiodevice.h>
#include <qurl.h>

using namespace Phonon;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_MediaSource_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::MediaSource >()))
        return -1;

    ::Phonon::MediaSource* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.MediaSource(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:MediaSource", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: MediaSource()
    // 1: MediaSource(Phonon::AbstractMediaStream*)
    // 2: MediaSource(Phonon::CaptureCategory)
    // 3: MediaSource(Phonon::DiscType,QString)
    // 4: MediaSource(QIODevice*)
    // 5: MediaSource(Phonon::AudioCaptureDevice)
    // 6: MediaSource(Phonon::MediaSource)
    // 7: MediaSource(Phonon::VideoCaptureDevice)
    // 8: MediaSource(QPair<QByteArray,QString>)
    // 9: MediaSource(QString)
    // 10: MediaSource(QUrl)
    if (numArgs == 0) {
        overloadId = 0; // MediaSource()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], (pyArgs[0])))) {
        overloadId = 7; // MediaSource(Phonon::VideoCaptureDevice)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], (pyArgs[0])))) {
        overloadId = 5; // MediaSource(Phonon::AudioCaptureDevice)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        overloadId = 4; // MediaSource(QIODevice*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // MediaSource(Phonon::DiscType,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 3; // MediaSource(Phonon::DiscType,QString)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX]), (pyArgs[0])))) {
        overloadId = 2; // MediaSource(Phonon::CaptureCategory)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], (pyArgs[0])))) {
        overloadId = 1; // MediaSource(Phonon::AbstractMediaStream*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 9; // MediaSource(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 10; // MediaSource(QUrl)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QPAIR_QBYTEARRAY_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 8; // MediaSource(QPair<QByteArray,QString>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArgs[0])))) {
        overloadId = 6; // MediaSource(Phonon::MediaSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaSource_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // MediaSource()
        {

            if (!PyErr_Occurred()) {
                // MediaSource()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // MediaSource(Phonon::AbstractMediaStream * stream)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::AbstractMediaStream* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::AbstractMediaStream*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // MediaSource(Phonon::CaptureCategory category)
        {
            ::Phonon::CaptureCategory cppArg0 = ((::Phonon::CaptureCategory)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::CaptureCategory)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // MediaSource(Phonon::DiscType discType, const QString & deviceName)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.MediaSource(): got multiple values for keyword argument 'deviceName'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Phonon_MediaSource_Init_TypeError;
                }
            }
            ::Phonon::DiscType cppArg0 = ((::Phonon::DiscType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::DiscType,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // MediaSource(QIODevice * ioDevice)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // MediaSource(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // MediaSource(const Phonon::AudioCaptureDevice & device)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::AudioCaptureDevice cppArg0_local = ::Phonon::AudioCaptureDevice();
            ::Phonon::AudioCaptureDevice* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::AudioCaptureDevice)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // MediaSource(const Phonon::MediaSource & rhs)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::MediaSource cppArg0_local = ::Phonon::MediaSource();
            ::Phonon::MediaSource* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::MediaSource)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // MediaSource(const Phonon::VideoCaptureDevice & device)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::VideoCaptureDevice cppArg0_local = ::Phonon::VideoCaptureDevice();
            ::Phonon::VideoCaptureDevice* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // MediaSource(Phonon::VideoCaptureDevice)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // MediaSource(const QPair<QByteArray, QString > & access)
        {
            ::QPair<QByteArray, QString > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // MediaSource(QPair<QByteArray,QString>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // MediaSource(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // MediaSource(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // MediaSource(const QUrl & url)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // MediaSource(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::MediaSource(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::MediaSource >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_MediaSource_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Phonon_MediaSource_Init_TypeError:
        const char* overloads[] = {"", "PySide.phonon.Phonon::AbstractMediaStream", "PySide.phonon.Phonon.CaptureCategory", "PySide.phonon.Phonon.DiscType, unicode = QString()", "PySide.QtCore.QIODevice", "PySide.phonon.Phonon::AudioCaptureDevice", "PySide.phonon.Phonon::MediaSource", "PySide.phonon.Phonon::VideoCaptureDevice", "QPair", "unicode", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.MediaSource", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_audioCaptureDevice(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // audioCaptureDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::AudioCaptureDevice cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->audioCaptureDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_audioDeviceAccessList(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // audioDeviceAccessList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QPair<QByteArray, QString > > & cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->audioDeviceAccessList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_autoDelete(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoDelete()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->autoDelete();
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

static PyObject* Sbk_Phonon_MediaSourceFunc_deviceAccessList(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceAccessList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QPair<QByteArray, QString > > & cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->deviceAccessList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_deviceName(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->deviceName();
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

static PyObject* Sbk_Phonon_MediaSourceFunc_discType(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // discType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::DiscType cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->discType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_fileName(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->fileName();
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

static PyObject* Sbk_Phonon_MediaSourceFunc_setAutoDelete(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoDelete(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoDelete(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaSourceFunc_setAutoDelete_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoDelete(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoDelete(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaSourceFunc_setAutoDelete_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaSource.setAutoDelete", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_stream(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stream()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::AbstractMediaStream * cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->stream();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_type(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaSource::Type cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_url(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->url();
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

static PyObject* Sbk_Phonon_MediaSourceFunc_videoCaptureDevice(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // videoCaptureDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::VideoCaptureDevice cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->videoCaptureDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSourceFunc_videoDeviceAccessList(PyObject* self)
{
    ::Phonon::MediaSource* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // videoDeviceAccessList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QPair<QByteArray, QString > > & cppResult = const_cast<const ::Phonon::MediaSource*>(cppSelf)->videoDeviceAccessList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaSource___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::MediaSource& cppSelf = *(((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_MediaSource_methods[] = {
    {"audioCaptureDevice", (PyCFunction)Sbk_Phonon_MediaSourceFunc_audioCaptureDevice, METH_NOARGS},
    {"audioDeviceAccessList", (PyCFunction)Sbk_Phonon_MediaSourceFunc_audioDeviceAccessList, METH_NOARGS},
    {"autoDelete", (PyCFunction)Sbk_Phonon_MediaSourceFunc_autoDelete, METH_NOARGS},
    {"deviceAccessList", (PyCFunction)Sbk_Phonon_MediaSourceFunc_deviceAccessList, METH_NOARGS},
    {"deviceName", (PyCFunction)Sbk_Phonon_MediaSourceFunc_deviceName, METH_NOARGS},
    {"discType", (PyCFunction)Sbk_Phonon_MediaSourceFunc_discType, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_Phonon_MediaSourceFunc_fileName, METH_NOARGS},
    {"setAutoDelete", (PyCFunction)Sbk_Phonon_MediaSourceFunc_setAutoDelete, METH_O},
    {"stream", (PyCFunction)Sbk_Phonon_MediaSourceFunc_stream, METH_NOARGS},
    {"type", (PyCFunction)Sbk_Phonon_MediaSourceFunc_type, METH_NOARGS},
    {"url", (PyCFunction)Sbk_Phonon_MediaSourceFunc_url, METH_NOARGS},
    {"videoCaptureDevice", (PyCFunction)Sbk_Phonon_MediaSourceFunc_videoCaptureDevice, METH_NOARGS},
    {"videoDeviceAccessList", (PyCFunction)Sbk_Phonon_MediaSourceFunc_videoDeviceAccessList, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_Phonon_MediaSource___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_Phonon_MediaSource_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::MediaSource& cppSelf = *(((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
                // operator==(const Phonon::MediaSource & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::Phonon::MediaSource cppArg0_local = ::Phonon::MediaSource();
                ::Phonon::MediaSource* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp))
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
            goto Sbk_Phonon_MediaSource_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_Phonon_MediaSource_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_Phonon_MediaSource_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_MediaSource_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_MediaSource_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.MediaSource",
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
    /*tp_traverse*/         Sbk_Phonon_MediaSource_traverse,
    /*tp_clear*/            Sbk_Phonon_MediaSource_clear,
    /*tp_richcompare*/      Sbk_Phonon_MediaSource_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_MediaSource_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_MediaSource_Init,
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
static void Phonon_MediaSource_Type_PythonToCpp_Phonon_MediaSource_Type(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource::Type*)cppOut) = (::Phonon::MediaSource::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_MediaSource_Type_PythonToCpp_Phonon_MediaSource_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX]))
        return Phonon_MediaSource_Type_PythonToCpp_Phonon_MediaSource_Type;
    return 0;
}
static PyObject* Phonon_MediaSource_Type_CppToPython_Phonon_MediaSource_Type(const void* cppIn) {
    int castCppIn = *((::Phonon::MediaSource::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void MediaSource_PythonToCpp_MediaSource_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_MediaSource_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MediaSource_PythonToCpp_MediaSource_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaSource_Type))
        return MediaSource_PythonToCpp_MediaSource_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MediaSource_PTR_CppToPython_MediaSource(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::MediaSource*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_MediaSource_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* MediaSource_COPY_CppToPython_MediaSource(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_Phonon_MediaSource_Type, new ::Phonon::MediaSource(*((::Phonon::MediaSource*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void MediaSource_PythonToCpp_MediaSource_COPY(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = *((::Phonon::MediaSource*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_MediaSource_PythonToCpp_MediaSource_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaSource_Type))
        return MediaSource_PythonToCpp_MediaSource_COPY;
    return 0;
}

// Implicit conversions.
static void Phonon_AbstractMediaStreamPTR_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(((::Phonon::AbstractMediaStream*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_Phonon_AbstractMediaStreamPTR_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], pyIn))
        return Phonon_AbstractMediaStreamPTR_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void Phonon_CaptureCategory_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    ::Phonon::CaptureCategory cppIn = ((::Phonon::CaptureCategory)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX]), pyIn, &cppIn);
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(cppIn);
}
static PythonToCppFunc is_Phonon_CaptureCategory_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_phononTypes[SBK_PHONON_CAPTURECATEGORY_IDX], pyIn))
        return Phonon_CaptureCategory_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void Phonon_DiscType_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    ::Phonon::DiscType cppIn = ((::Phonon::DiscType)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX]), pyIn, &cppIn);
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(cppIn);
}
static PythonToCppFunc is_Phonon_DiscType_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_phononTypes[SBK_PHONON_DISCTYPE_IDX], pyIn))
        return Phonon_DiscType_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void PySide_QtCore_QIODevicePTR_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(((::QIODevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_QIODevicePTR_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], pyIn))
        return PySide_QtCore_QIODevicePTR_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void constPhonon_AudioCaptureDeviceREF_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(*((::Phonon::AudioCaptureDevice*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constPhonon_AudioCaptureDeviceREF_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], pyIn))
        return constPhonon_AudioCaptureDeviceREF_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void constPhonon_VideoCaptureDeviceREF_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(*((::Phonon::VideoCaptureDevice*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constPhonon_VideoCaptureDeviceREF_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], pyIn))
        return constPhonon_VideoCaptureDeviceREF_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void PySide_QtCore_constQStringREF_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_Phonon_MediaSource;
    return 0;
}

static void PySide_QtCore_constQUrlREF_PythonToCpp_Phonon_MediaSource(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaSource*)cppOut) = ::Phonon::MediaSource(*((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_constQUrlREF_PythonToCpp_Phonon_MediaSource_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyIn))
        return PySide_QtCore_constQUrlREF_PythonToCpp_Phonon_MediaSource;
    return 0;
}

void init_Phonon_MediaSource(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_MediaSource_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MediaSource", "Phonon::MediaSource",
        &Sbk_Phonon_MediaSource_Type, &Shiboken::callCppDestructor< ::Phonon::MediaSource >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_MediaSource_Type,
        MediaSource_PythonToCpp_MediaSource_PTR,
        is_MediaSource_PythonToCpp_MediaSource_PTR_Convertible,
        MediaSource_PTR_CppToPython_MediaSource,
        MediaSource_COPY_CppToPython_MediaSource);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaSource");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaSource*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaSource&");
    Shiboken::Conversions::registerConverterName(converter, "MediaSource");
    Shiboken::Conversions::registerConverterName(converter, "MediaSource*");
    Shiboken::Conversions::registerConverterName(converter, "MediaSource&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::MediaSource).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        MediaSource_PythonToCpp_MediaSource_COPY,
        is_MediaSource_PythonToCpp_MediaSource_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Phonon_AbstractMediaStreamPTR_PythonToCpp_Phonon_MediaSource,
        is_Phonon_AbstractMediaStreamPTR_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Phonon_CaptureCategory_PythonToCpp_Phonon_MediaSource,
        is_Phonon_CaptureCategory_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Phonon_DiscType_PythonToCpp_Phonon_MediaSource,
        is_Phonon_DiscType_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_QIODevicePTR_PythonToCpp_Phonon_MediaSource,
        is_PySide_QtCore_QIODevicePTR_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constPhonon_AudioCaptureDeviceREF_PythonToCpp_Phonon_MediaSource,
        is_constPhonon_AudioCaptureDeviceREF_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constPhonon_VideoCaptureDeviceREF_PythonToCpp_Phonon_MediaSource,
        is_constPhonon_VideoCaptureDeviceREF_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_Phonon_MediaSource,
        is_PySide_QtCore_constQStringREF_PythonToCpp_Phonon_MediaSource_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQUrlREF_PythonToCpp_Phonon_MediaSource,
        is_PySide_QtCore_constQUrlREF_PythonToCpp_Phonon_MediaSource_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_MediaSource_Type,
        "Type",
        "PySide.phonon.Phonon.MediaSource.Type",
        "Phonon::MediaSource::Type");
    if (!SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "Invalid", (long) Phonon::MediaSource::Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "LocalFile", (long) Phonon::MediaSource::LocalFile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "Url", (long) Phonon::MediaSource::Url))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "Disc", (long) Phonon::MediaSource::Disc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "Stream", (long) Phonon::MediaSource::Stream))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "CaptureDevice", (long) Phonon::MediaSource::CaptureDevice))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "Empty", (long) Phonon::MediaSource::Empty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
        &Sbk_Phonon_MediaSource_Type, "AudioVideoCapture", (long) Phonon::MediaSource::AudioVideoCapture))
        return ;
    // Register converter for enum 'Phonon::MediaSource::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX],
            Phonon_MediaSource_Type_CppToPython_Phonon_MediaSource_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_MediaSource_Type_PythonToCpp_Phonon_MediaSource_Type,
            is_Phonon_MediaSource_Type_PythonToCpp_Phonon_MediaSource_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaSource::Type");
        Shiboken::Conversions::registerConverterName(converter, "MediaSource::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


    qRegisterMetaType< ::Phonon::MediaSource >("MediaSource");
    qRegisterMetaType< ::Phonon::MediaSource >("Phonon::MediaSource");
    qRegisterMetaType< ::Phonon::MediaSource::Type >("MediaSource::Type");
    qRegisterMetaType< ::Phonon::MediaSource::Type >("Phonon::MediaSource::Type");
}
