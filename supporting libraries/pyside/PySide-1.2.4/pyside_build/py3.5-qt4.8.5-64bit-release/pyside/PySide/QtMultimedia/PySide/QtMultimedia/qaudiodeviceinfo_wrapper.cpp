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
#include "pyside_qtmultimedia_python.h"

#include "qaudiodeviceinfo_wrapper.h"

// Extra includes
#include <QList>
#include <qaudiodeviceinfo.h>
#include <qaudioformat.h>
#include <qbytearray.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAudioDeviceInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAudioDeviceInfo >()))
        return -1;

    ::QAudioDeviceInfo* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAudioDeviceInfo", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAudioDeviceInfo()
    // 1: QAudioDeviceInfo(QAudioDeviceInfo)
    if (numArgs == 0) {
        overloadId = 0; // QAudioDeviceInfo()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (pyArgs[0])))) {
        overloadId = 1; // QAudioDeviceInfo(QAudioDeviceInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioDeviceInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QAudioDeviceInfo()
        {

            if (!PyErr_Occurred()) {
                // QAudioDeviceInfo()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAudioDeviceInfo();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QAudioDeviceInfo(const QAudioDeviceInfo & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAudioDeviceInfo cppArg0_local = ::QAudioDeviceInfo();
            ::QAudioDeviceInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QAudioDeviceInfo(QAudioDeviceInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAudioDeviceInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAudioDeviceInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAudioDeviceInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QAudioDeviceInfo_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtMultimedia.QAudioDeviceInfo", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAudioDeviceInfo", overloads);
        return -1;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_availableDevices(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: availableDevices(QAudio::Mode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]), (pyArg)))) {
        overloadId = 0; // availableDevices(QAudio::Mode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioDeviceInfoFunc_availableDevices_TypeError;

    // Call function/method
    {
        ::QAudio::Mode cppArg0 = ((::QAudio::Mode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // availableDevices(QAudio::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAudioDeviceInfo > cppResult = ::QAudioDeviceInfo::availableDevices(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIODEVICEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioDeviceInfoFunc_availableDevices_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudio.Mode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioDeviceInfo.availableDevices", overloads);
        return 0;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_defaultInputDevice(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultInputDevice()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioDeviceInfo cppResult = ::QAudioDeviceInfo::defaultInputDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_defaultOutputDevice(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultOutputDevice()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioDeviceInfo cppResult = ::QAudioDeviceInfo::defaultOutputDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_deviceName(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->deviceName();
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

static PyObject* Sbk_QAudioDeviceInfoFunc_isFormatSupported(PyObject* self, PyObject* pyArg)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isFormatSupported(QAudioFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // isFormatSupported(QAudioFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioDeviceInfoFunc_isFormatSupported_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAudioFormat cppArg0_local = ::QAudioFormat();
        ::QAudioFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isFormatSupported(QAudioFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->isFormatSupported(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioDeviceInfoFunc_isFormatSupported_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioDeviceInfo.isFormatSupported", overloads);
        return 0;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_isNull(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->isNull();
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

static PyObject* Sbk_QAudioDeviceInfoFunc_nearestFormat(PyObject* self, PyObject* pyArg)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: nearestFormat(QAudioFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // nearestFormat(QAudioFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioDeviceInfoFunc_nearestFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAudioFormat cppArg0_local = ::QAudioFormat();
        ::QAudioFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // nearestFormat(QAudioFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->nearestFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioDeviceInfoFunc_nearestFormat_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioDeviceInfo.nearestFormat", overloads);
        return 0;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_preferredFormat(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->preferredFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedByteOrders(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedByteOrders()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAudioFormat::Endian > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedByteOrders();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedChannelCounts(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedChannelCounts()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedChannelCounts();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedChannels(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedChannels()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedChannels();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedCodecs(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedCodecs()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedCodecs();
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

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedFrequencies(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedFrequencies()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedFrequencies();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedSampleRates(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedSampleRates()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedSampleRates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedSampleSizes(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedSampleSizes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedSampleSizes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfoFunc_supportedSampleTypes(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedSampleTypes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAudioFormat::SampleType > cppResult = const_cast<const ::QAudioDeviceInfo*>(cppSelf)->supportedSampleTypes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioDeviceInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAudioDeviceInfo& cppSelf = *(((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAudioDeviceInfo_methods[] = {
    {"availableDevices", (PyCFunction)Sbk_QAudioDeviceInfoFunc_availableDevices, METH_O|METH_STATIC},
    {"defaultInputDevice", (PyCFunction)Sbk_QAudioDeviceInfoFunc_defaultInputDevice, METH_NOARGS|METH_STATIC},
    {"defaultOutputDevice", (PyCFunction)Sbk_QAudioDeviceInfoFunc_defaultOutputDevice, METH_NOARGS|METH_STATIC},
    {"deviceName", (PyCFunction)Sbk_QAudioDeviceInfoFunc_deviceName, METH_NOARGS},
    {"isFormatSupported", (PyCFunction)Sbk_QAudioDeviceInfoFunc_isFormatSupported, METH_O},
    {"isNull", (PyCFunction)Sbk_QAudioDeviceInfoFunc_isNull, METH_NOARGS},
    {"nearestFormat", (PyCFunction)Sbk_QAudioDeviceInfoFunc_nearestFormat, METH_O},
    {"preferredFormat", (PyCFunction)Sbk_QAudioDeviceInfoFunc_preferredFormat, METH_NOARGS},
    {"supportedByteOrders", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedByteOrders, METH_NOARGS},
    {"supportedChannelCounts", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedChannelCounts, METH_NOARGS},
    {"supportedChannels", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedChannels, METH_NOARGS},
    {"supportedCodecs", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedCodecs, METH_NOARGS},
    {"supportedFrequencies", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedFrequencies, METH_NOARGS},
    {"supportedSampleRates", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedSampleRates, METH_NOARGS},
    {"supportedSampleSizes", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedSampleSizes, METH_NOARGS},
    {"supportedSampleTypes", (PyCFunction)Sbk_QAudioDeviceInfoFunc_supportedSampleTypes, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QAudioDeviceInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QAudioDeviceInfo___nb_bool(PyObject* self)
{
    ::QAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QAudioDeviceInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAudioDeviceInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QAudioDeviceInfo_TypeAsNumber;

static SbkObjectType Sbk_QAudioDeviceInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAudioDeviceInfo",
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
    /*tp_traverse*/         Sbk_QAudioDeviceInfo_traverse,
    /*tp_clear*/            Sbk_QAudioDeviceInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAudioDeviceInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAudioDeviceInfo_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAudioDeviceInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAudioDeviceInfo_Type))
        return QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAudioDeviceInfo_PTR_CppToPython_QAudioDeviceInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAudioDeviceInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAudioDeviceInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QAudioDeviceInfo_COPY_CppToPython_QAudioDeviceInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QAudioDeviceInfo_Type, new ::QAudioDeviceInfo(*((::QAudioDeviceInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QAudioDeviceInfo*)cppOut) = *((::QAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAudioDeviceInfo_Type))
        return QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_COPY;
    return 0;
}

void init_QAudioDeviceInfo(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QAudioDeviceInfo_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QAudioDeviceInfo_TypeAsNumber) = Sbk_QAudioDeviceInfo___nb_bool;
    Sbk_QAudioDeviceInfo_Type.super.ht_type.tp_as_number = &Sbk_QAudioDeviceInfo_TypeAsNumber;

    SbkPySide_QtMultimediaTypes[SBK_QAUDIODEVICEINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAudioDeviceInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAudioDeviceInfo", "QAudioDeviceInfo",
        &Sbk_QAudioDeviceInfo_Type, &Shiboken::callCppDestructor< ::QAudioDeviceInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAudioDeviceInfo_Type,
        QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_PTR,
        is_QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_PTR_Convertible,
        QAudioDeviceInfo_PTR_CppToPython_QAudioDeviceInfo,
        QAudioDeviceInfo_COPY_CppToPython_QAudioDeviceInfo);

    Shiboken::Conversions::registerConverterName(converter, "QAudioDeviceInfo");
    Shiboken::Conversions::registerConverterName(converter, "QAudioDeviceInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QAudioDeviceInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAudioDeviceInfo).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_COPY,
        is_QAudioDeviceInfo_PythonToCpp_QAudioDeviceInfo_COPY_Convertible);


    qRegisterMetaType< ::QAudioDeviceInfo >("QAudioDeviceInfo");
}
