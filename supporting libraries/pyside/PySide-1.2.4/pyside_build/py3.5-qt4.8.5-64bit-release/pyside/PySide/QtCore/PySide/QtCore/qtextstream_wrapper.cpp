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
#include "pyside_qtcore_python.h"

#include "qtextstream_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qiodevice.h>
#include <qlocale.h>
#include <qtextcodec.h>
#include <qtextstream.h>


// Native ---------------------------------------------------------

QTextStreamWrapper::QTextStreamWrapper() : QTextStream() {
    // ... middle
}

QTextStreamWrapper::QTextStreamWrapper(QByteArray * array, QFlags<QIODevice::OpenModeFlag> openMode) : QTextStream(array, openMode) {
    // ... middle
}

QTextStreamWrapper::QTextStreamWrapper(QIODevice * device) : QTextStream(device) {
    // ... middle
}

QTextStreamWrapper::~QTextStreamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextStream_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextStream >()))
        return -1;

    ::QTextStreamWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextStream(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QTextStream", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTextStream()
    // 1: QTextStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
    // 2: QTextStream(QIODevice*)
    if (numArgs == 0) {
        overloadId = 0; // QTextStream()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextStream(QIODevice*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QTextStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // QTextStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStream_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextStream()
        {

            if (!PyErr_Occurred()) {
                // QTextStream()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextStreamWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextStream(QByteArray * array, QFlags<QIODevice::OpenModeFlag> openMode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "openMode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextStream(): got multiple values for keyword argument 'openMode'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QTextStream_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QIODevice::OpenModeFlag> cppArg1 = QIODevice::ReadWrite;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTextStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextStreamWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextStream(QIODevice * device)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextStream(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextStreamWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextStream >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextStream_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextStream_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", "PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextStream", overloads);
        return -1;
}

static PyObject* Sbk_QTextStreamFunc_atEnd(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextStream*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QTextStreamFunc_autoDetectUnicode(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoDetectUnicode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextStream*>(cppSelf)->autoDetectUnicode();
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

static PyObject* Sbk_QTextStreamFunc_codec(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = const_cast<const ::QTextStream*>(cppSelf)->codec();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_device(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QTextStream*>(cppSelf)->device();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_fieldAlignment(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fieldAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextStream::FieldAlignment cppResult = const_cast<const ::QTextStream*>(cppSelf)->fieldAlignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_fieldWidth(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fieldWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextStream*>(cppSelf)->fieldWidth();
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

static PyObject* Sbk_QTextStreamFunc_flush(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flush()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->flush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextStreamFunc_generateByteOrderMark(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // generateByteOrderMark()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextStream*>(cppSelf)->generateByteOrderMark();
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

static PyObject* Sbk_QTextStreamFunc_integerBase(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // integerBase()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextStream*>(cppSelf)->integerBase();
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

static PyObject* Sbk_QTextStreamFunc_locale(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // locale()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale cppResult = const_cast<const ::QTextStream*>(cppSelf)->locale();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_numberFlags(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numberFlags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextStream::NumberFlag> cppResult = const_cast<const ::QTextStream*>(cppSelf)->numberFlags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_padChar(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // padChar()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QTextStream*>(cppSelf)->padChar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_pos(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QTextStream*>(cppSelf)->pos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // read(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_read_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->read(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextStreamFunc_read_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.read", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_readAll(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->readAll();
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

static PyObject* Sbk_QTextStreamFunc_readLine(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextStream.readLine(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:readLine", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: readLine(qint64)
    if (numArgs == 0) {
        overloadId = 0; // readLine(qint64)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))) {
        overloadId = 0; // readLine(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_readLine_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "maxlen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTextStream.readLine(): got multiple values for keyword argument 'maxlen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0]))))
                    goto Sbk_QTextStreamFunc_readLine_TypeError;
            }
        }
        qint64 cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // readLine(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->readLine(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextStreamFunc_readLine_TypeError:
        const char* overloads[] = {"long long = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextStream.readLine", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_realNumberNotation(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // realNumberNotation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextStream::RealNumberNotation cppResult = const_cast<const ::QTextStream*>(cppSelf)->realNumberNotation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_realNumberPrecision(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // realNumberPrecision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextStream*>(cppSelf)->realNumberPrecision();
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

static PyObject* Sbk_QTextStreamFunc_reset(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextStreamFunc_resetStatus(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetStatus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetStatus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextStreamFunc_seek(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seek(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seek(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_seek_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->seek(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextStreamFunc_seek_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.seek", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setAutoDetectUnicode(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoDetectUnicode(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoDetectUnicode(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setAutoDetectUnicode_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoDetectUnicode(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoDetectUnicode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setAutoDetectUnicode_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setAutoDetectUnicode", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setCodec(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCodec(QTextCodec*)
    // 1: setCodec(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 1; // setCodec(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArg)))) {
        overloadId = 0; // setCodec(QTextCodec*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setCodec_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setCodec(QTextCodec * codec)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextCodec* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setCodec(QTextCodec*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCodec(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setCodec(const char * codecName)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setCodec(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCodec(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setCodec_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setCodec", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setDevice_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIODevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDevice(QIODevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDevice(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setFieldAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFieldAlignment(QTextStream::FieldAlignment)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX]), (pyArg)))) {
        overloadId = 0; // setFieldAlignment(QTextStream::FieldAlignment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setFieldAlignment_TypeError;

    // Call function/method
    {
        ::QTextStream::FieldAlignment cppArg0 = ((::QTextStream::FieldAlignment)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFieldAlignment(QTextStream::FieldAlignment)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFieldAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setFieldAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream.FieldAlignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setFieldAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setFieldWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFieldWidth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setFieldWidth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setFieldWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFieldWidth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFieldWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setFieldWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setFieldWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setGenerateByteOrderMark(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGenerateByteOrderMark(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setGenerateByteOrderMark(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setGenerateByteOrderMark_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGenerateByteOrderMark(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGenerateByteOrderMark(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setGenerateByteOrderMark_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setGenerateByteOrderMark", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setIntegerBase(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIntegerBase(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setIntegerBase(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setIntegerBase_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIntegerBase(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIntegerBase(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setIntegerBase_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setIntegerBase", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setLocale(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocale(QLocale)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
        overloadId = 0; // setLocale(QLocale)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setLocale_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLocale cppArg0_local = ::QLocale();
        ::QLocale* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setLocale(QLocale)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocale(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setLocale_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setLocale", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setNumberFlags(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumberFlags(QFlags<QTextStream::NumberFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setNumberFlags(QFlags<QTextStream::NumberFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setNumberFlags_TypeError;

    // Call function/method
    {
        ::QFlags<QTextStream::NumberFlag> cppArg0 = ((::QFlags<QTextStream::NumberFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumberFlags(QFlags<QTextStream::NumberFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumberFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setNumberFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream.NumberFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setNumberFlags", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setPadChar(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPadChar(QChar)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // setPadChar(QChar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setPadChar_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPadChar(QChar)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPadChar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setPadChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setPadChar", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setRealNumberNotation(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRealNumberNotation(QTextStream::RealNumberNotation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX]), (pyArg)))) {
        overloadId = 0; // setRealNumberNotation(QTextStream::RealNumberNotation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setRealNumberNotation_TypeError;

    // Call function/method
    {
        ::QTextStream::RealNumberNotation cppArg0 = ((::QTextStream::RealNumberNotation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRealNumberNotation(QTextStream::RealNumberNotation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRealNumberNotation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setRealNumberNotation_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream.RealNumberNotation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setRealNumberNotation", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setRealNumberPrecision(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRealNumberPrecision(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRealNumberPrecision(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setRealNumberPrecision_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRealNumberPrecision(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRealNumberPrecision(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setRealNumberPrecision_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setRealNumberPrecision", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QTextStream::Status)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX]), (pyArg)))) {
        overloadId = 0; // setStatus(QTextStream::Status)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc_setStatus_TypeError;

    // Call function/method
    {
        ::QTextStream::Status cppArg0 = ((::QTextStream::Status)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatus(QTextStream::Status)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextStreamFunc_setStatus_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream.Status", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc_skipWhiteSpace(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // skipWhiteSpace()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->skipWhiteSpace();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextStreamFunc_status(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // status()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextStream::Status cppResult = const_cast<const ::QTextStream*>(cppSelf)->status();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextStreamFunc_string(PyObject* self)
{
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // string()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString * cppResult = const_cast<const ::QTextStream*>(cppSelf)->string();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // Begin code injection

            QString& res = *cppResult;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &res);

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextStream_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QTextStreamFunc_atEnd, METH_NOARGS},
    {"autoDetectUnicode", (PyCFunction)Sbk_QTextStreamFunc_autoDetectUnicode, METH_NOARGS},
    {"codec", (PyCFunction)Sbk_QTextStreamFunc_codec, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QTextStreamFunc_device, METH_NOARGS},
    {"fieldAlignment", (PyCFunction)Sbk_QTextStreamFunc_fieldAlignment, METH_NOARGS},
    {"fieldWidth", (PyCFunction)Sbk_QTextStreamFunc_fieldWidth, METH_NOARGS},
    {"flush", (PyCFunction)Sbk_QTextStreamFunc_flush, METH_NOARGS},
    {"generateByteOrderMark", (PyCFunction)Sbk_QTextStreamFunc_generateByteOrderMark, METH_NOARGS},
    {"integerBase", (PyCFunction)Sbk_QTextStreamFunc_integerBase, METH_NOARGS},
    {"locale", (PyCFunction)Sbk_QTextStreamFunc_locale, METH_NOARGS},
    {"numberFlags", (PyCFunction)Sbk_QTextStreamFunc_numberFlags, METH_NOARGS},
    {"padChar", (PyCFunction)Sbk_QTextStreamFunc_padChar, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QTextStreamFunc_pos, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QTextStreamFunc_read, METH_O},
    {"readAll", (PyCFunction)Sbk_QTextStreamFunc_readAll, METH_NOARGS},
    {"readLine", (PyCFunction)Sbk_QTextStreamFunc_readLine, METH_VARARGS|METH_KEYWORDS},
    {"realNumberNotation", (PyCFunction)Sbk_QTextStreamFunc_realNumberNotation, METH_NOARGS},
    {"realNumberPrecision", (PyCFunction)Sbk_QTextStreamFunc_realNumberPrecision, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_QTextStreamFunc_reset, METH_NOARGS},
    {"resetStatus", (PyCFunction)Sbk_QTextStreamFunc_resetStatus, METH_NOARGS},
    {"seek", (PyCFunction)Sbk_QTextStreamFunc_seek, METH_O},
    {"setAutoDetectUnicode", (PyCFunction)Sbk_QTextStreamFunc_setAutoDetectUnicode, METH_O},
    {"setCodec", (PyCFunction)Sbk_QTextStreamFunc_setCodec, METH_O},
    {"setDevice", (PyCFunction)Sbk_QTextStreamFunc_setDevice, METH_O},
    {"setFieldAlignment", (PyCFunction)Sbk_QTextStreamFunc_setFieldAlignment, METH_O},
    {"setFieldWidth", (PyCFunction)Sbk_QTextStreamFunc_setFieldWidth, METH_O},
    {"setGenerateByteOrderMark", (PyCFunction)Sbk_QTextStreamFunc_setGenerateByteOrderMark, METH_O},
    {"setIntegerBase", (PyCFunction)Sbk_QTextStreamFunc_setIntegerBase, METH_O},
    {"setLocale", (PyCFunction)Sbk_QTextStreamFunc_setLocale, METH_O},
    {"setNumberFlags", (PyCFunction)Sbk_QTextStreamFunc_setNumberFlags, METH_O},
    {"setPadChar", (PyCFunction)Sbk_QTextStreamFunc_setPadChar, METH_O},
    {"setRealNumberNotation", (PyCFunction)Sbk_QTextStreamFunc_setRealNumberNotation, METH_O},
    {"setRealNumberPrecision", (PyCFunction)Sbk_QTextStreamFunc_setRealNumberPrecision, METH_O},
    {"setStatus", (PyCFunction)Sbk_QTextStreamFunc_setStatus, METH_O},
    {"skipWhiteSpace", (PyCFunction)Sbk_QTextStreamFunc_skipWhiteSpace, METH_NOARGS},
    {"status", (PyCFunction)Sbk_QTextStreamFunc_status, METH_NOARGS},
    {"string", (PyCFunction)Sbk_QTextStreamFunc_string, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_QTextStreamFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QChar)
    // 1: operator<<(QTextStream&,QTextStreamManipulator)
    // 2: operator<<(char)
    // 3: operator<<(QByteArray)
    // 4: operator<<(QString)
    // 5: operator<<(double)
    // 6: operator<<(signed long)
    // 7: operator<<(ulong)
    if (!isReverse
        && PyLong_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArg)))) {
        overloadId = 7; // operator<<(ulong)
    } else if (!isReverse
        && PyLong_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<signed long>(), (pyArg)))) {
        overloadId = 6; // operator<<(signed long)
    } else if (!isReverse
        && PyFloat_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 5; // operator<<(double)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 4; // operator<<(QString)
    } else if (!isReverse
        && SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 2; // operator<<(char)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 3; // operator<<(QByteArray)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAMMANIPULATOR_IDX], (pyArg)))) {
        overloadId = 1; // operator<<(QTextStream&,QTextStreamManipulator)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QChar)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc___lshift___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator<<(QChar ch)
        {
            ::QChar cppArg0 = ::QChar();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(QChar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator<<(QTextStreamManipulator m)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextStreamManipulator cppArg0 = QTextStreamManipulator(0, 0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(QTextStream&,QTextStreamManipulator)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator<<(char ch)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator<<(const QByteArray & array)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator<<(const QString & s)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 5: // operator<<(double f)
        {
            double cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 6: // operator<<(signed long i)
        {
            signed long cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(signed long)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
        case 7: // operator<<(unsigned long i)
        {
            unsigned long cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(ulong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextStream & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
            }
            break;
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextStreamFunc___lshift___TypeError:
        const char* overloads[] = {"1-unicode", "PySide.QtCore.QTextStreamManipulator", "char", "PySide.QtCore.QByteArray", "unicode", "float", "long", "unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QTextStreamFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QByteArray&)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QByteArray&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextStreamFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator>>(QByteArray&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextStream & cppResult = (*cppSelf) >> (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextStreamFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextStream.__rshift__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QTextStream_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextStream_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTextStream_TypeAsNumber;

static SbkObjectType Sbk_QTextStream_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextStream",
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
    /*tp_traverse*/         Sbk_QTextStream_traverse,
    /*tp_clear*/            Sbk_QTextStream_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextStream_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextStream_Init,
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

PyObject* SbkPySide_QtCore_QTextStream_NumberFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextStream::NumberFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextStream::NumberFlags)PyLong_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextStream::NumberFlags)PyInt_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextStream_NumberFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextStream::NumberFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextStream::NumberFlags)PyLong_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextStream::NumberFlags)PyInt_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextStream_NumberFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextStream::NumberFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextStream::NumberFlags)PyLong_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextStream::NumberFlags)PyInt_AsLong(self);
    cppArg = (QTextStream::NumberFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextStream_NumberFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextStream::NumberFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), self, &cppSelf);
    ::QTextStream::NumberFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QTextStream_NumberFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QTextStream_NumberFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QTextStream_NumberFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QTextStream_NumberFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QTextStream_NumberFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QTextStream_NumberFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QTextStream_NumberFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QTextStream_NumberFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QTextStream_NumberFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QTextStream_NumberFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QTextStream_RealNumberNotation_PythonToCpp_QTextStream_RealNumberNotation(PyObject* pyIn, void* cppOut) {
    *((::QTextStream::RealNumberNotation*)cppOut) = (::QTextStream::RealNumberNotation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextStream_RealNumberNotation_PythonToCpp_QTextStream_RealNumberNotation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX]))
        return QTextStream_RealNumberNotation_PythonToCpp_QTextStream_RealNumberNotation;
    return 0;
}
static PyObject* QTextStream_RealNumberNotation_CppToPython_QTextStream_RealNumberNotation(const void* cppIn) {
    int castCppIn = *((::QTextStream::RealNumberNotation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX], castCppIn);

}

static void QTextStream_FieldAlignment_PythonToCpp_QTextStream_FieldAlignment(PyObject* pyIn, void* cppOut) {
    *((::QTextStream::FieldAlignment*)cppOut) = (::QTextStream::FieldAlignment) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextStream_FieldAlignment_PythonToCpp_QTextStream_FieldAlignment_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX]))
        return QTextStream_FieldAlignment_PythonToCpp_QTextStream_FieldAlignment;
    return 0;
}
static PyObject* QTextStream_FieldAlignment_CppToPython_QTextStream_FieldAlignment(const void* cppIn) {
    int castCppIn = *((::QTextStream::FieldAlignment*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX], castCppIn);

}

static void QTextStream_Status_PythonToCpp_QTextStream_Status(PyObject* pyIn, void* cppOut) {
    *((::QTextStream::Status*)cppOut) = (::QTextStream::Status) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextStream_Status_PythonToCpp_QTextStream_Status_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX]))
        return QTextStream_Status_PythonToCpp_QTextStream_Status;
    return 0;
}
static PyObject* QTextStream_Status_CppToPython_QTextStream_Status(const void* cppIn) {
    int castCppIn = *((::QTextStream::Status*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX], castCppIn);

}

static void QTextStream_NumberFlag_PythonToCpp_QTextStream_NumberFlag(PyObject* pyIn, void* cppOut) {
    *((::QTextStream::NumberFlag*)cppOut) = (::QTextStream::NumberFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextStream_NumberFlag_PythonToCpp_QTextStream_NumberFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX]))
        return QTextStream_NumberFlag_PythonToCpp_QTextStream_NumberFlag;
    return 0;
}
static PyObject* QTextStream_NumberFlag_CppToPython_QTextStream_NumberFlag(const void* cppIn) {
    int castCppIn = *((::QTextStream::NumberFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX], castCppIn);

}

static void QFlags_QTextStream_NumberFlag__PythonToCpp_QFlags_QTextStream_NumberFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextStream::NumberFlag>*)cppOut) = ::QFlags<QTextStream::NumberFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextStream_NumberFlag__PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]))
        return QFlags_QTextStream_NumberFlag__PythonToCpp_QFlags_QTextStream_NumberFlag_;
    return 0;
}
static PyObject* QFlags_QTextStream_NumberFlag__CppToPython_QFlags_QTextStream_NumberFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextStream::NumberFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]));

}

static void QTextStream_NumberFlag_PythonToCpp_QFlags_QTextStream_NumberFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextStream::NumberFlag>*)cppOut) = ::QFlags<QTextStream::NumberFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextStream_NumberFlag_PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX]))
        return QTextStream_NumberFlag_PythonToCpp_QFlags_QTextStream_NumberFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextStream_NumberFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextStream::NumberFlag>*)cppOut) = ::QFlags<QTextStream::NumberFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextStream_NumberFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextStream_PythonToCpp_QTextStream_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextStream_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextStream_PythonToCpp_QTextStream_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextStream_Type))
        return QTextStream_PythonToCpp_QTextStream_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextStream_PTR_CppToPython_QTextStream(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextStream*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextStream_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextStream(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTextStream_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTextStream_TypeAsNumber.nb_rshift = Sbk_QTextStreamFunc___rshift__;
    Sbk_QTextStream_TypeAsNumber.nb_lshift = Sbk_QTextStreamFunc___lshift__;
    Sbk_QTextStream_Type.super.ht_type.tp_as_number = &Sbk_QTextStream_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextStream_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextStream", "QTextStream*",
        &Sbk_QTextStream_Type, &Shiboken::callCppDestructor< ::QTextStream >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextStream_Type,
        QTextStream_PythonToCpp_QTextStream_PTR,
        is_QTextStream_PythonToCpp_QTextStream_PTR_Convertible,
        QTextStream_PTR_CppToPython_QTextStream);

    Shiboken::Conversions::registerConverterName(converter, "QTextStream");
    Shiboken::Conversions::registerConverterName(converter, "QTextStream*");
    Shiboken::Conversions::registerConverterName(converter, "QTextStream&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextStream).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextStreamWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'RealNumberNotation'.
    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextStream_Type,
        "RealNumberNotation",
        "PySide.QtCore.QTextStream.RealNumberNotation",
        "QTextStream::RealNumberNotation");
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX],
        &Sbk_QTextStream_Type, "SmartNotation", (long) QTextStream::SmartNotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX],
        &Sbk_QTextStream_Type, "FixedNotation", (long) QTextStream::FixedNotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX],
        &Sbk_QTextStream_Type, "ScientificNotation", (long) QTextStream::ScientificNotation))
        return ;
    // Register converter for enum 'QTextStream::RealNumberNotation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX],
            QTextStream_RealNumberNotation_CppToPython_QTextStream_RealNumberNotation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextStream_RealNumberNotation_PythonToCpp_QTextStream_RealNumberNotation,
            is_QTextStream_RealNumberNotation_PythonToCpp_QTextStream_RealNumberNotation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_REALNUMBERNOTATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextStream::RealNumberNotation");
        Shiboken::Conversions::registerConverterName(converter, "RealNumberNotation");
    }
    // End of 'RealNumberNotation' enum.

    // Initialization of enum 'FieldAlignment'.
    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextStream_Type,
        "FieldAlignment",
        "PySide.QtCore.QTextStream.FieldAlignment",
        "QTextStream::FieldAlignment");
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX],
        &Sbk_QTextStream_Type, "AlignLeft", (long) QTextStream::AlignLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX],
        &Sbk_QTextStream_Type, "AlignRight", (long) QTextStream::AlignRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX],
        &Sbk_QTextStream_Type, "AlignCenter", (long) QTextStream::AlignCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX],
        &Sbk_QTextStream_Type, "AlignAccountingStyle", (long) QTextStream::AlignAccountingStyle))
        return ;
    // Register converter for enum 'QTextStream::FieldAlignment'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX],
            QTextStream_FieldAlignment_CppToPython_QTextStream_FieldAlignment);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextStream_FieldAlignment_PythonToCpp_QTextStream_FieldAlignment,
            is_QTextStream_FieldAlignment_PythonToCpp_QTextStream_FieldAlignment_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_FIELDALIGNMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextStream::FieldAlignment");
        Shiboken::Conversions::registerConverterName(converter, "FieldAlignment");
    }
    // End of 'FieldAlignment' enum.

    // Initialization of enum 'Status'.
    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextStream_Type,
        "Status",
        "PySide.QtCore.QTextStream.Status",
        "QTextStream::Status");
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX],
        &Sbk_QTextStream_Type, "Ok", (long) QTextStream::Ok))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX],
        &Sbk_QTextStream_Type, "ReadPastEnd", (long) QTextStream::ReadPastEnd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX],
        &Sbk_QTextStream_Type, "ReadCorruptData", (long) QTextStream::ReadCorruptData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX],
        &Sbk_QTextStream_Type, "WriteFailed", (long) QTextStream::WriteFailed))
        return ;
    // Register converter for enum 'QTextStream::Status'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX],
            QTextStream_Status_CppToPython_QTextStream_Status);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextStream_Status_PythonToCpp_QTextStream_Status,
            is_QTextStream_Status_PythonToCpp_QTextStream_Status_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_STATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextStream::Status");
        Shiboken::Conversions::registerConverterName(converter, "Status");
    }
    // End of 'Status' enum.

    // Initialization of enum 'NumberFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX] = PySide::QFlags::create("NumberFlags", &SbkPySide_QtCore_QTextStream_NumberFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextStream_Type,
        "NumberFlag",
        "PySide.QtCore.QTextStream.NumberFlag",
        "QTextStream::NumberFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
        &Sbk_QTextStream_Type, "ShowBase", (long) QTextStream::ShowBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
        &Sbk_QTextStream_Type, "ForcePoint", (long) QTextStream::ForcePoint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
        &Sbk_QTextStream_Type, "ForceSign", (long) QTextStream::ForceSign))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
        &Sbk_QTextStream_Type, "UppercaseBase", (long) QTextStream::UppercaseBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
        &Sbk_QTextStream_Type, "UppercaseDigits", (long) QTextStream::UppercaseDigits))
        return ;
    // Register converter for enum 'QTextStream::NumberFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX],
            QTextStream_NumberFlag_CppToPython_QTextStream_NumberFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextStream_NumberFlag_PythonToCpp_QTextStream_NumberFlag,
            is_QTextStream_NumberFlag_PythonToCpp_QTextStream_NumberFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_NUMBERFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextStream::NumberFlag");
        Shiboken::Conversions::registerConverterName(converter, "NumberFlag");
    }
    // Register converter for flag 'QFlags<QTextStream::NumberFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX],
            QFlags_QTextStream_NumberFlag__CppToPython_QFlags_QTextStream_NumberFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextStream_NumberFlag_PythonToCpp_QFlags_QTextStream_NumberFlag_,
            is_QTextStream_NumberFlag_PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextStream_NumberFlag__PythonToCpp_QFlags_QTextStream_NumberFlag_,
            is_QFlags_QTextStream_NumberFlag__PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextStream_NumberFlag_,
            is_number_PythonToCpp_QFlags_QTextStream_NumberFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTSTREAM_NUMBERFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextStream::NumberFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<NumberFlag>");
    }
    // End of 'NumberFlag' enum/flags.


    qRegisterMetaType< ::QTextStream::RealNumberNotation >("QTextStream::RealNumberNotation");
    qRegisterMetaType< ::QTextStream::FieldAlignment >("QTextStream::FieldAlignment");
    qRegisterMetaType< ::QTextStream::Status >("QTextStream::Status");
    qRegisterMetaType< ::QTextStream::NumberFlag >("QTextStream::NumberFlag");
    qRegisterMetaType< ::QTextStream::NumberFlags >("QTextStream::NumberFlags");
}
