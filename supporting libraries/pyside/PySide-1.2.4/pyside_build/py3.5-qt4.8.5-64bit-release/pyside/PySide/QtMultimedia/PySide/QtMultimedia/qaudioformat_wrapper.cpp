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

#include "qaudioformat_wrapper.h"

// Extra includes
#include <qaudioformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAudioFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAudioFormat >()))
        return -1;

    ::QAudioFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAudioFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAudioFormat()
    // 1: QAudioFormat(QAudioFormat)
    if (numArgs == 0) {
        overloadId = 0; // QAudioFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QAudioFormat(QAudioFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QAudioFormat()
        {

            if (!PyErr_Occurred()) {
                // QAudioFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAudioFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QAudioFormat(const QAudioFormat & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAudioFormat cppArg0_local = ::QAudioFormat();
            ::QAudioFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QAudioFormat(QAudioFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAudioFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAudioFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAudioFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QAudioFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtMultimedia.QAudioFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAudioFormat", overloads);
        return -1;
}

static PyObject* Sbk_QAudioFormatFunc_byteOrder(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // byteOrder()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat::Endian cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->byteOrder();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_channelCount(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // channelCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->channelCount();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_channels(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // channels()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->channels();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_codec(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->codec();
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

static PyObject* Sbk_QAudioFormatFunc_frequency(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frequency()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->frequency();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_isValid(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QAudioFormatFunc_sampleRate(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleRate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->sampleRate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_sampleSize(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->sampleSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_sampleType(PyObject* self)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat::SampleType cppResult = const_cast<const ::QAudioFormat*>(cppSelf)->sampleType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAudioFormatFunc_setByteOrder(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setByteOrder(QAudioFormat::Endian)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]), (pyArg)))) {
        overloadId = 0; // setByteOrder(QAudioFormat::Endian)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setByteOrder_TypeError;

    // Call function/method
    {
        ::QAudioFormat::Endian cppArg0 = ((::QAudioFormat::Endian)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setByteOrder(QAudioFormat::Endian)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setByteOrder(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setByteOrder_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat.Endian", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setByteOrder", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setChannelCount(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setChannelCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setChannelCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setChannelCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChannelCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setChannelCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setChannelCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setChannelCount", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setChannels(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setChannels(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setChannels(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setChannels_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChannels(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setChannels(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setChannels_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setChannels", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setCodec(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCodec(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setCodec(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setCodec_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCodec(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCodec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setCodec_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setCodec", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setFrequency(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFrequency(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setFrequency(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setFrequency_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFrequency(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFrequency(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setFrequency_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setFrequency", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setSampleRate(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSampleRate(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSampleRate(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setSampleRate_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSampleRate(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSampleRate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setSampleRate_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setSampleRate", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setSampleSize(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSampleSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSampleSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setSampleSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSampleSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSampleSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setSampleSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setSampleSize", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormatFunc_setSampleType(PyObject* self, PyObject* pyArg)
{
    ::QAudioFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSampleType(QAudioFormat::SampleType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setSampleType(QAudioFormat::SampleType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioFormatFunc_setSampleType_TypeError;

    // Call function/method
    {
        ::QAudioFormat::SampleType cppArg0 = ((::QAudioFormat::SampleType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSampleType(QAudioFormat::SampleType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSampleType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAudioFormatFunc_setSampleType_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat.SampleType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioFormat.setSampleType", overloads);
        return 0;
}

static PyObject* Sbk_QAudioFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAudioFormat& cppSelf = *(((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAudioFormat_methods[] = {
    {"byteOrder", (PyCFunction)Sbk_QAudioFormatFunc_byteOrder, METH_NOARGS},
    {"channelCount", (PyCFunction)Sbk_QAudioFormatFunc_channelCount, METH_NOARGS},
    {"channels", (PyCFunction)Sbk_QAudioFormatFunc_channels, METH_NOARGS},
    {"codec", (PyCFunction)Sbk_QAudioFormatFunc_codec, METH_NOARGS},
    {"frequency", (PyCFunction)Sbk_QAudioFormatFunc_frequency, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QAudioFormatFunc_isValid, METH_NOARGS},
    {"sampleRate", (PyCFunction)Sbk_QAudioFormatFunc_sampleRate, METH_NOARGS},
    {"sampleSize", (PyCFunction)Sbk_QAudioFormatFunc_sampleSize, METH_NOARGS},
    {"sampleType", (PyCFunction)Sbk_QAudioFormatFunc_sampleType, METH_NOARGS},
    {"setByteOrder", (PyCFunction)Sbk_QAudioFormatFunc_setByteOrder, METH_O},
    {"setChannelCount", (PyCFunction)Sbk_QAudioFormatFunc_setChannelCount, METH_O},
    {"setChannels", (PyCFunction)Sbk_QAudioFormatFunc_setChannels, METH_O},
    {"setCodec", (PyCFunction)Sbk_QAudioFormatFunc_setCodec, METH_O},
    {"setFrequency", (PyCFunction)Sbk_QAudioFormatFunc_setFrequency, METH_O},
    {"setSampleRate", (PyCFunction)Sbk_QAudioFormatFunc_setSampleRate, METH_O},
    {"setSampleSize", (PyCFunction)Sbk_QAudioFormatFunc_setSampleSize, METH_O},
    {"setSampleType", (PyCFunction)Sbk_QAudioFormatFunc_setSampleType, METH_O},

    {"__copy__", (PyCFunction)Sbk_QAudioFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QAudioFormat_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAudioFormat& cppSelf = *(((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
                // operator!=(const QAudioFormat & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QAudioFormat cppArg0_local = ::QAudioFormat();
                ::QAudioFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
                // operator==(const QAudioFormat & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QAudioFormat cppArg0_local = ::QAudioFormat();
                ::QAudioFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
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
            goto Sbk_QAudioFormat_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QAudioFormat_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QAudioFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAudioFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAudioFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAudioFormat",
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
    /*tp_traverse*/         Sbk_QAudioFormat_traverse,
    /*tp_clear*/            Sbk_QAudioFormat_clear,
    /*tp_richcompare*/      Sbk_QAudioFormat_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAudioFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAudioFormat_Init,
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
static void QAudioFormat_SampleType_PythonToCpp_QAudioFormat_SampleType(PyObject* pyIn, void* cppOut) {
    *((::QAudioFormat::SampleType*)cppOut) = (::QAudioFormat::SampleType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAudioFormat_SampleType_PythonToCpp_QAudioFormat_SampleType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX]))
        return QAudioFormat_SampleType_PythonToCpp_QAudioFormat_SampleType;
    return 0;
}
static PyObject* QAudioFormat_SampleType_CppToPython_QAudioFormat_SampleType(const void* cppIn) {
    int castCppIn = *((::QAudioFormat::SampleType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX], castCppIn);

}

static void QAudioFormat_Endian_PythonToCpp_QAudioFormat_Endian(PyObject* pyIn, void* cppOut) {
    *((::QAudioFormat::Endian*)cppOut) = (::QAudioFormat::Endian) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAudioFormat_Endian_PythonToCpp_QAudioFormat_Endian_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX]))
        return QAudioFormat_Endian_PythonToCpp_QAudioFormat_Endian;
    return 0;
}
static PyObject* QAudioFormat_Endian_CppToPython_QAudioFormat_Endian(const void* cppIn) {
    int castCppIn = *((::QAudioFormat::Endian*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAudioFormat_PythonToCpp_QAudioFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAudioFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAudioFormat_PythonToCpp_QAudioFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAudioFormat_Type))
        return QAudioFormat_PythonToCpp_QAudioFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAudioFormat_PTR_CppToPython_QAudioFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAudioFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAudioFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QAudioFormat_COPY_CppToPython_QAudioFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QAudioFormat_Type, new ::QAudioFormat(*((::QAudioFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QAudioFormat_PythonToCpp_QAudioFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QAudioFormat*)cppOut) = *((::QAudioFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QAudioFormat_PythonToCpp_QAudioFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAudioFormat_Type))
        return QAudioFormat_PythonToCpp_QAudioFormat_COPY;
    return 0;
}

void init_QAudioFormat(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAudioFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAudioFormat", "QAudioFormat",
        &Sbk_QAudioFormat_Type, &Shiboken::callCppDestructor< ::QAudioFormat >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAudioFormat_Type,
        QAudioFormat_PythonToCpp_QAudioFormat_PTR,
        is_QAudioFormat_PythonToCpp_QAudioFormat_PTR_Convertible,
        QAudioFormat_PTR_CppToPython_QAudioFormat,
        QAudioFormat_COPY_CppToPython_QAudioFormat);

    Shiboken::Conversions::registerConverterName(converter, "QAudioFormat");
    Shiboken::Conversions::registerConverterName(converter, "QAudioFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QAudioFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAudioFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QAudioFormat_PythonToCpp_QAudioFormat_COPY,
        is_QAudioFormat_PythonToCpp_QAudioFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'SampleType'.
    SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAudioFormat_Type,
        "SampleType",
        "PySide.QtMultimedia.QAudioFormat.SampleType",
        "QAudioFormat::SampleType");
    if (!SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX],
        &Sbk_QAudioFormat_Type, "Unknown", (long) QAudioFormat::Unknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX],
        &Sbk_QAudioFormat_Type, "SignedInt", (long) QAudioFormat::SignedInt))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX],
        &Sbk_QAudioFormat_Type, "UnSignedInt", (long) QAudioFormat::UnSignedInt))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX],
        &Sbk_QAudioFormat_Type, "Float", (long) QAudioFormat::Float))
        return ;
    // Register converter for enum 'QAudioFormat::SampleType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX],
            QAudioFormat_SampleType_CppToPython_QAudioFormat_SampleType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAudioFormat_SampleType_PythonToCpp_QAudioFormat_SampleType,
            is_QAudioFormat_SampleType_PythonToCpp_QAudioFormat_SampleType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_SAMPLETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAudioFormat::SampleType");
        Shiboken::Conversions::registerConverterName(converter, "SampleType");
    }
    // End of 'SampleType' enum.

    // Initialization of enum 'Endian'.
    SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAudioFormat_Type,
        "Endian",
        "PySide.QtMultimedia.QAudioFormat.Endian",
        "QAudioFormat::Endian");
    if (!SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX],
        &Sbk_QAudioFormat_Type, "BigEndian", (long) QAudioFormat::BigEndian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX],
        &Sbk_QAudioFormat_Type, "LittleEndian", (long) QAudioFormat::LittleEndian))
        return ;
    // Register converter for enum 'QAudioFormat::Endian'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX],
            QAudioFormat_Endian_CppToPython_QAudioFormat_Endian);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAudioFormat_Endian_PythonToCpp_QAudioFormat_Endian,
            is_QAudioFormat_Endian_PythonToCpp_QAudioFormat_Endian_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_ENDIAN_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAudioFormat::Endian");
        Shiboken::Conversions::registerConverterName(converter, "Endian");
    }
    // End of 'Endian' enum.


    qRegisterMetaType< ::QAudioFormat >("QAudioFormat");
    qRegisterMetaType< ::QAudioFormat::SampleType >("QAudioFormat::SampleType");
    qRegisterMetaType< ::QAudioFormat::Endian >("QAudioFormat::Endian");
}
