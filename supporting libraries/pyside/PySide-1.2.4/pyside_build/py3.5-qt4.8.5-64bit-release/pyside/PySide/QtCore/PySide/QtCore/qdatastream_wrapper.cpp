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

#include "qdatastream_wrapper.h"

// Extra includes
#include <QtCore/QtCore>
#include <qbitarray.h>
#include <qbytearray.h>
#include <qdatastream.h>
#include <qdatetime.h>
#include <qeasingcurve.h>
#include <qiodevice.h>
#include <qline.h>
#include <qlocale.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregexp.h>
#include <qsize.h>
#include <qurl.h>
#include <quuid.h>


// Native ---------------------------------------------------------

QDataStreamWrapper::QDataStreamWrapper() : QDataStream() {
    // ... middle
}

QDataStreamWrapper::QDataStreamWrapper(QByteArray * arg__1, QFlags<QIODevice::OpenModeFlag> flags) : QDataStream(arg__1, flags) {
    // ... middle
}

QDataStreamWrapper::QDataStreamWrapper(QIODevice * arg__1) : QDataStream(arg__1) {
    // ... middle
}

QDataStreamWrapper::QDataStreamWrapper(const QByteArray & arg__1) : QDataStream(arg__1) {
    // ... middle
}

QDataStreamWrapper::~QDataStreamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDataStream_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDataStream >()))
        return -1;

    ::QDataStreamWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDataStream", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QDataStream()
    // 1: QDataStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
    // 2: QDataStream(QIODevice*)
    // 3: QDataStream(QByteArray)
    if (numArgs == 0) {
        overloadId = 0; // QDataStream()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QDataStream(QIODevice*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QDataStream(QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // QDataStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStream_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDataStream()
        {

            if (!PyErr_Occurred()) {
                // QDataStream()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDataStreamWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDataStream(QByteArray * arg__1, QFlags<QIODevice::OpenModeFlag> flags)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QIODevice::OpenModeFlag> cppArg1 = ((::QFlags<QIODevice::OpenModeFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDataStream(QByteArray*,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDataStreamWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDataStream(QIODevice * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDataStream(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDataStreamWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QDataStream(const QByteArray & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDataStream(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDataStreamWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDataStream >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDataStream_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDataStream_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray, PySide.QtCore.QIODevice.OpenMode", "PySide.QtCore.QIODevice", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDataStream", overloads);
        return -1;
}

static PyObject* Sbk_QDataStreamFunc_atEnd(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDataStream*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QDataStreamFunc_byteOrder(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // byteOrder()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream::ByteOrder cppResult = const_cast<const ::QDataStream*>(cppSelf)->byteOrder();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_device(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QDataStream*>(cppSelf)->device();
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

static PyObject* Sbk_QDataStreamFunc_floatingPointPrecision(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // floatingPointPrecision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream::FloatingPointPrecision cppResult = const_cast<const ::QDataStream*>(cppSelf)->floatingPointPrecision();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readBool(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readBool()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            bool _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readDouble(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readDouble()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            qreal _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readFloat(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readFloat()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            float _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readInt16(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readInt16()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            qint16 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint16>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readInt32(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readInt32()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            qint32 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readInt64(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readInt64()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            qint64 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readInt8(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readInt8()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            qint8 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint8>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readQChar(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readQChar()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            QChar _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readQString(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readQString()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            QString _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readQStringList(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readQStringList()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            QStringList _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readQVariant(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readQVariant()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            QVariant _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readRawData(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: readRawData(char*,int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // readRawData(char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_readRawData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readRawData(char*,int)
            // Begin code injection

            QByteArray data;
            data.resize(cppArg0);
            int result = cppSelf->readRawData(data.data(), data.size());
            if (result == -1) {
                Py_INCREF(Py_None);
                pyResult = Py_None;
            } else {
                pyResult = PyBytes_FromStringAndSize(data.data(), result);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataStreamFunc_readRawData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.readRawData", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_readString(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readString()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            QString _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readUInt16(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readUInt16()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            quint16 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readUInt32(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readUInt32()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            quint32 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readUInt64(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readUInt64()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            quint64 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint64>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_readUInt8(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readUInt8()


            // Begin code injection

            // TEMPLATE - stream_read_method - START
            quint8 _cpp_result;
            (*cppSelf) >> _cpp_result;
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint8>(), &_cpp_result);
            // TEMPLATE - stream_read_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_resetStatus(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QDataStreamFunc_setByteOrder(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setByteOrder(QDataStream::ByteOrder)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX]), (pyArg)))) {
        overloadId = 0; // setByteOrder(QDataStream::ByteOrder)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_setByteOrder_TypeError;

    // Call function/method
    {
        ::QDataStream::ByteOrder cppArg0 = ((::QDataStream::ByteOrder)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setByteOrder(QDataStream::ByteOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setByteOrder(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_setByteOrder_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream.ByteOrder", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.setByteOrder", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_setDevice_TypeError;

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
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_setFloatingPointPrecision(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFloatingPointPrecision(QDataStream::FloatingPointPrecision)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX]), (pyArg)))) {
        overloadId = 0; // setFloatingPointPrecision(QDataStream::FloatingPointPrecision)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_setFloatingPointPrecision_TypeError;

    // Call function/method
    {
        ::QDataStream::FloatingPointPrecision cppArg0 = ((::QDataStream::FloatingPointPrecision)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFloatingPointPrecision(QDataStream::FloatingPointPrecision)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFloatingPointPrecision(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_setFloatingPointPrecision_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream.FloatingPointPrecision", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.setFloatingPointPrecision", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_setStatus(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatus(QDataStream::Status)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX]), (pyArg)))) {
        overloadId = 0; // setStatus(QDataStream::Status)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_setStatus_TypeError;

    // Call function/method
    {
        ::QDataStream::Status cppArg0 = ((::QDataStream::Status)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatus(QDataStream::Status)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_setStatus_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream.Status", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.setStatus", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_setVersion(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVersion(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setVersion(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_setVersion_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVersion(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVersion(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_setVersion_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.setVersion", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_skipRawData(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: skipRawData(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // skipRawData(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_skipRawData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // skipRawData(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->skipRawData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataStreamFunc_skipRawData_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.skipRawData", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_status(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // status()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream::Status cppResult = const_cast<const ::QDataStream*>(cppSelf)->status();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDataStreamFunc_unsetDevice(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unsetDevice()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unsetDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDataStreamFunc_version(PyObject* self)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // version()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDataStream*>(cppSelf)->version();
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

static PyObject* Sbk_QDataStreamFunc_writeBool(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeBool(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // writeBool(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeBool_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeBool(bool)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeBool_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeBool", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeDouble(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeDouble(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // writeDouble(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeDouble_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeDouble(qreal)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeDouble_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeDouble", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeFloat(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeFloat(float)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArg)))) {
        overloadId = 0; // writeFloat(float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeFloat_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeFloat(float)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeFloat_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeFloat", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeInt16(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeInt16(qint16)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint16>(), (pyArg)))) {
        overloadId = 0; // writeInt16(qint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeInt16_TypeError;

    // Call function/method
    {
        qint16 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeInt16(qint16)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeInt16_TypeError:
        const char* overloads[] = {"short", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeInt16", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeInt32(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeInt32(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // writeInt32(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeInt32_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeInt32(qint32)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeInt32_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeInt32", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeInt64(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeInt64(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // writeInt64(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeInt64_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeInt64(qint64)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeInt64_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeInt64", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeInt8(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeInt8(qint8)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint8>(), (pyArg)))) {
        overloadId = 0; // writeInt8(qint8)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeInt8_TypeError;

    // Call function/method
    {
        qint8 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeInt8(qint8)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeInt8_TypeError:
        const char* overloads[] = {"char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeInt8", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeQChar(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeQChar(QChar)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // writeQChar(QChar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeQChar_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeQChar(QChar)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeQChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeQChar", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeQString(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeQString(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // writeQString(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeQString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeQString(QString)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeQString_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeQString", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeQStringList(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeQStringList(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // writeQStringList(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeQStringList_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeQStringList(QStringList)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeQStringList_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeQStringList", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeQVariant(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeQVariant(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // writeQVariant(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeQVariant_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeQVariant(QVariant)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeQVariant_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeQVariant", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeRawData(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeRawData(const char*,int)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // writeRawData(const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeRawData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // writeRawData(const char*,int)
            // Begin code injection

            int r = cppSelf->writeRawData(cppArg0, Shiboken::String::len(pyArg));
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &r);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDataStreamFunc_writeRawData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeRawData", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeString(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeString(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // writeString(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeString(QString)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeString_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeString", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeUInt16(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeUInt16(quint16)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArg)))) {
        overloadId = 0; // writeUInt16(quint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeUInt16_TypeError;

    // Call function/method
    {
        quint16 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeUInt16(quint16)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeUInt16_TypeError:
        const char* overloads[] = {"unsigned short", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeUInt16", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeUInt32(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeUInt32(quint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArg)))) {
        overloadId = 0; // writeUInt32(quint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeUInt32_TypeError;

    // Call function/method
    {
        quint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeUInt32(quint32)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeUInt32_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeUInt32", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeUInt64(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeUInt64(quint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint64>(), (pyArg)))) {
        overloadId = 0; // writeUInt64(quint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeUInt64_TypeError;

    // Call function/method
    {
        quint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeUInt64(quint64)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeUInt64_TypeError:
        const char* overloads[] = {"unsigned long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeUInt64", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc_writeUInt8(PyObject* self, PyObject* pyArg)
{
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeUInt8(quint8)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint8>(), (pyArg)))) {
        overloadId = 0; // writeUInt8(quint8)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc_writeUInt8_TypeError;

    // Call function/method
    {
        quint8 cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // writeUInt8(quint8)


            // Begin code injection

            // TEMPLATE - stream_write_method - START
            (*cppSelf) << cppArg0;
            // TEMPLATE - stream_write_method - END

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDataStreamFunc_writeUInt8_TypeError:
        const char* overloads[] = {"unsigned char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.writeUInt8", overloads);
        return 0;
}

static PyMethodDef Sbk_QDataStream_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QDataStreamFunc_atEnd, METH_NOARGS},
    {"byteOrder", (PyCFunction)Sbk_QDataStreamFunc_byteOrder, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QDataStreamFunc_device, METH_NOARGS},
    {"floatingPointPrecision", (PyCFunction)Sbk_QDataStreamFunc_floatingPointPrecision, METH_NOARGS},
    {"readBool", (PyCFunction)Sbk_QDataStreamFunc_readBool, METH_NOARGS},
    {"readDouble", (PyCFunction)Sbk_QDataStreamFunc_readDouble, METH_NOARGS},
    {"readFloat", (PyCFunction)Sbk_QDataStreamFunc_readFloat, METH_NOARGS},
    {"readInt16", (PyCFunction)Sbk_QDataStreamFunc_readInt16, METH_NOARGS},
    {"readInt32", (PyCFunction)Sbk_QDataStreamFunc_readInt32, METH_NOARGS},
    {"readInt64", (PyCFunction)Sbk_QDataStreamFunc_readInt64, METH_NOARGS},
    {"readInt8", (PyCFunction)Sbk_QDataStreamFunc_readInt8, METH_NOARGS},
    {"readQChar", (PyCFunction)Sbk_QDataStreamFunc_readQChar, METH_NOARGS},
    {"readQString", (PyCFunction)Sbk_QDataStreamFunc_readQString, METH_NOARGS},
    {"readQStringList", (PyCFunction)Sbk_QDataStreamFunc_readQStringList, METH_NOARGS},
    {"readQVariant", (PyCFunction)Sbk_QDataStreamFunc_readQVariant, METH_NOARGS},
    {"readRawData", (PyCFunction)Sbk_QDataStreamFunc_readRawData, METH_O},
    {"readString", (PyCFunction)Sbk_QDataStreamFunc_readString, METH_NOARGS},
    {"readUInt16", (PyCFunction)Sbk_QDataStreamFunc_readUInt16, METH_NOARGS},
    {"readUInt32", (PyCFunction)Sbk_QDataStreamFunc_readUInt32, METH_NOARGS},
    {"readUInt64", (PyCFunction)Sbk_QDataStreamFunc_readUInt64, METH_NOARGS},
    {"readUInt8", (PyCFunction)Sbk_QDataStreamFunc_readUInt8, METH_NOARGS},
    {"resetStatus", (PyCFunction)Sbk_QDataStreamFunc_resetStatus, METH_NOARGS},
    {"setByteOrder", (PyCFunction)Sbk_QDataStreamFunc_setByteOrder, METH_O},
    {"setDevice", (PyCFunction)Sbk_QDataStreamFunc_setDevice, METH_O},
    {"setFloatingPointPrecision", (PyCFunction)Sbk_QDataStreamFunc_setFloatingPointPrecision, METH_O},
    {"setStatus", (PyCFunction)Sbk_QDataStreamFunc_setStatus, METH_O},
    {"setVersion", (PyCFunction)Sbk_QDataStreamFunc_setVersion, METH_O},
    {"skipRawData", (PyCFunction)Sbk_QDataStreamFunc_skipRawData, METH_O},
    {"status", (PyCFunction)Sbk_QDataStreamFunc_status, METH_NOARGS},
    {"unsetDevice", (PyCFunction)Sbk_QDataStreamFunc_unsetDevice, METH_NOARGS},
    {"version", (PyCFunction)Sbk_QDataStreamFunc_version, METH_NOARGS},
    {"writeBool", (PyCFunction)Sbk_QDataStreamFunc_writeBool, METH_O},
    {"writeDouble", (PyCFunction)Sbk_QDataStreamFunc_writeDouble, METH_O},
    {"writeFloat", (PyCFunction)Sbk_QDataStreamFunc_writeFloat, METH_O},
    {"writeInt16", (PyCFunction)Sbk_QDataStreamFunc_writeInt16, METH_O},
    {"writeInt32", (PyCFunction)Sbk_QDataStreamFunc_writeInt32, METH_O},
    {"writeInt64", (PyCFunction)Sbk_QDataStreamFunc_writeInt64, METH_O},
    {"writeInt8", (PyCFunction)Sbk_QDataStreamFunc_writeInt8, METH_O},
    {"writeQChar", (PyCFunction)Sbk_QDataStreamFunc_writeQChar, METH_O},
    {"writeQString", (PyCFunction)Sbk_QDataStreamFunc_writeQString, METH_O},
    {"writeQStringList", (PyCFunction)Sbk_QDataStreamFunc_writeQStringList, METH_O},
    {"writeQVariant", (PyCFunction)Sbk_QDataStreamFunc_writeQVariant, METH_O},
    {"writeRawData", (PyCFunction)Sbk_QDataStreamFunc_writeRawData, METH_O},
    {"writeString", (PyCFunction)Sbk_QDataStreamFunc_writeString, METH_O},
    {"writeUInt16", (PyCFunction)Sbk_QDataStreamFunc_writeUInt16, METH_O},
    {"writeUInt32", (PyCFunction)Sbk_QDataStreamFunc_writeUInt32, METH_O},
    {"writeUInt64", (PyCFunction)Sbk_QDataStreamFunc_writeUInt64, METH_O},
    {"writeUInt8", (PyCFunction)Sbk_QDataStreamFunc_writeUInt8, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QDataStreamFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
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
    // 0: operator<<(QString)
    // 1: operator<<(QDataStream&,QBitArray)
    // 2: operator<<(QDataStream&,QByteArray)
    // 3: operator<<(QDataStream&,QDate)
    // 4: operator<<(QDataStream&,QDateTime)
    // 5: operator<<(QDataStream&,QEasingCurve)
    // 6: operator<<(QDataStream&,QLine)
    // 7: operator<<(QDataStream&,QLineF)
    // 8: operator<<(QDataStream&,QLocale)
    // 9: operator<<(QDataStream&,QPoint)
    // 10: operator<<(QDataStream&,QPointF)
    // 11: operator<<(QDataStream&,QRect)
    // 12: operator<<(QDataStream&,QRectF)
    // 13: operator<<(QDataStream&,QRegExp)
    // 14: operator<<(QDataStream&,QSize)
    // 15: operator<<(QDataStream&,QSizeF)
    // 16: operator<<(QDataStream&,QTime)
    // 17: operator<<(QDataStream&,QUrl)
    // 18: operator<<(QDataStream&,QUuid)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 16; // operator<<(QDataStream&,QTime)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 14; // operator<<(QDataStream&,QSize)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArg)))) {
        overloadId = 15; // operator<<(QDataStream&,QSizeF)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArg)))) {
        overloadId = 13; // operator<<(QDataStream&,QRegExp)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 11; // operator<<(QDataStream&,QRect)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 12; // operator<<(QDataStream&,QRectF)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 9; // operator<<(QDataStream&,QPoint)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 10; // operator<<(QDataStream&,QPointF)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (pyArg)))) {
        overloadId = 6; // operator<<(QDataStream&,QLine)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
        overloadId = 7; // operator<<(QDataStream&,QLineF)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArg)))) {
        overloadId = 5; // operator<<(QDataStream&,QEasingCurve)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 4; // operator<<(QDataStream&,QDateTime)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 3; // operator<<(QDataStream&,QDate)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 1; // operator<<(QDataStream&,QBitArray)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QString)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
        overloadId = 8; // operator<<(QDataStream&,QLocale)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 2; // operator<<(QDataStream&,QByteArray)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
        overloadId = 18; // operator<<(QDataStream&,QUuid)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 17; // operator<<(QDataStream&,QUrl)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc___lshift___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator<<(QString arg__1)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // operator<<(QString)


                // Begin code injection

                // TEMPLATE - stream_write_method - START
                (*cppSelf) << cppArg0;
                // TEMPLATE - stream_write_method - END

                // End of code injection
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // operator<<(const QBitArray & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QBitArray cppArg0_local = ::QBitArray();
            ::QBitArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QBitArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator<<(const QByteArray & arg__2)
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
                // operator<<(QDataStream&,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator<<(const QDate & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QDate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator<<(const QDateTime & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QDateTime)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 5: // operator<<(const QEasingCurve & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
            ::QEasingCurve* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QEasingCurve)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 6: // operator<<(const QLine & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QLine cppArg0_local = ::QLine();
            ::QLine* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QLine)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 7: // operator<<(const QLineF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QLineF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 8: // operator<<(const QLocale & arg__2)
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
                // operator<<(QDataStream&,QLocale)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 9: // operator<<(const QPoint & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 10: // operator<<(const QPointF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 11: // operator<<(const QRect & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 12: // operator<<(const QRectF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 13: // operator<<(const QRegExp & regExp)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QRegExp)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 14: // operator<<(const QSize & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 15: // operator<<(const QSizeF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 16: // operator<<(const QTime & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QTime)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 17: // operator<<(const QUrl & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 18: // operator<<(const QUuid & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUuid cppArg0_local = ::QUuid();
            ::QUuid* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QDataStream&,QUuid)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
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

    Sbk_QDataStreamFunc___lshift___TypeError:
        const char* overloads[] = {"unicode", "PySide.QtCore.QBitArray", "PySide.QtCore.QByteArray", "PySide.QtCore.QDate", "PySide.QtCore.QDateTime", "PySide.QtCore.QEasingCurve", "PySide.QtCore.QLine", "PySide.QtCore.QLineF", "PySide.QtCore.QLocale", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "PySide.QtCore.QRect", "PySide.QtCore.QRectF", "PySide.QtCore.QRegExp", "PySide.QtCore.QSize", "PySide.QtCore.QSizeF", "PySide.QtCore.QTime", "PySide.QtCore.QUrl", "PySide.QtCore.QUuid", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QDataStreamFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QDataStream* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDataStream*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QBitArray&)
    // 1: operator>>(QDataStream&,QByteArray&)
    // 2: operator>>(QDataStream&,QDate&)
    // 3: operator>>(QDataStream&,QDateTime&)
    // 4: operator>>(QDataStream&,QEasingCurve&)
    // 5: operator>>(QDataStream&,QLine&)
    // 6: operator>>(QDataStream&,QLineF&)
    // 7: operator>>(QDataStream&,QLocale&)
    // 8: operator>>(QDataStream&,QPoint&)
    // 9: operator>>(QDataStream&,QPointF&)
    // 10: operator>>(QDataStream&,QRect&)
    // 11: operator>>(QDataStream&,QRectF&)
    // 12: operator>>(QDataStream&,QRegExp&)
    // 13: operator>>(QDataStream&,QSize&)
    // 14: operator>>(QDataStream&,QSizeF&)
    // 15: operator>>(QDataStream&,QTime&)
    // 16: operator>>(QDataStream&,QUrl&)
    // 17: operator>>(QDataStream&,QUuid&)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 16; // operator>>(QDataStream&,QUrl&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 15; // operator>>(QDataStream&,QTime&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 13; // operator>>(QDataStream&,QSize&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArg)))) {
        overloadId = 14; // operator>>(QDataStream&,QSizeF&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArg)))) {
        overloadId = 12; // operator>>(QDataStream&,QRegExp&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 10; // operator>>(QDataStream&,QRect&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 11; // operator>>(QDataStream&,QRectF&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 8; // operator>>(QDataStream&,QPoint&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 9; // operator>>(QDataStream&,QPointF&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
        overloadId = 7; // operator>>(QDataStream&,QLocale&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (pyArg)))) {
        overloadId = 5; // operator>>(QDataStream&,QLine&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
        overloadId = 6; // operator>>(QDataStream&,QLineF&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArg)))) {
        overloadId = 4; // operator>>(QDataStream&,QEasingCurve&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 3; // operator>>(QDataStream&,QDateTime&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 2; // operator>>(QDataStream&,QDate&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // operator>>(QDataStream&,QByteArray&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
        overloadId = 17; // operator>>(QDataStream&,QUuid&)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QBitArray&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDataStreamFunc___rshift___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator>>(QBitArray & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QBitArray cppArg0_local = ::QBitArray();
            ::QBitArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QBitArray&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator>>(QByteArray & arg__2)
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
                // operator>>(QDataStream&,QByteArray&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator>>(QDate & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QDate&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator>>(QDateTime & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QDateTime&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator>>(QEasingCurve & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
            ::QEasingCurve* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QEasingCurve&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 5: // operator>>(QLine & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QLine cppArg0_local = ::QLine();
            ::QLine* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QLine&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 6: // operator>>(QLineF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QLineF&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 7: // operator>>(QLocale & arg__2)
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
                // operator>>(QDataStream&,QLocale&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 8: // operator>>(QPoint & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QPoint&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 9: // operator>>(QPointF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QPointF&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 10: // operator>>(QRect & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QRect&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 11: // operator>>(QRectF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QRectF&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 12: // operator>>(QRegExp & regExp)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QRegExp&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 13: // operator>>(QSize & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QSize&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 14: // operator>>(QSizeF & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QSizeF&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 15: // operator>>(QTime & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QTime&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 16: // operator>>(QUrl & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QUrl&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
            }
            break;
        }
        case 17: // operator>>(QUuid & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUuid cppArg0_local = ::QUuid();
            ::QUuid* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator>>(QDataStream&,QUuid&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDataStream & cppResult = (*cppSelf) >> (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
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

    Sbk_QDataStreamFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", "PySide.QtCore.QByteArray", "PySide.QtCore.QDate", "PySide.QtCore.QDateTime", "PySide.QtCore.QEasingCurve", "PySide.QtCore.QLine", "PySide.QtCore.QLineF", "PySide.QtCore.QLocale", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "PySide.QtCore.QRect", "PySide.QtCore.QRectF", "PySide.QtCore.QRegExp", "PySide.QtCore.QSize", "PySide.QtCore.QSizeF", "PySide.QtCore.QTime", "PySide.QtCore.QUrl", "PySide.QtCore.QUuid", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDataStream.__rshift__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QDataStream_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDataStream_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDataStream_TypeAsNumber;

static SbkObjectType Sbk_QDataStream_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QDataStream",
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
    /*tp_traverse*/         Sbk_QDataStream_traverse,
    /*tp_clear*/            Sbk_QDataStream_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDataStream_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDataStream_Init,
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
static void QDataStream_Version_PythonToCpp_QDataStream_Version(PyObject* pyIn, void* cppOut) {
    *((::QDataStream::Version*)cppOut) = (::QDataStream::Version) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDataStream_Version_PythonToCpp_QDataStream_Version_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX]))
        return QDataStream_Version_PythonToCpp_QDataStream_Version;
    return 0;
}
static PyObject* QDataStream_Version_CppToPython_QDataStream_Version(const void* cppIn) {
    int castCppIn = *((::QDataStream::Version*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX], castCppIn);

}

static void QDataStream_ByteOrder_PythonToCpp_QDataStream_ByteOrder(PyObject* pyIn, void* cppOut) {
    *((::QDataStream::ByteOrder*)cppOut) = (::QDataStream::ByteOrder) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDataStream_ByteOrder_PythonToCpp_QDataStream_ByteOrder_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX]))
        return QDataStream_ByteOrder_PythonToCpp_QDataStream_ByteOrder;
    return 0;
}
static PyObject* QDataStream_ByteOrder_CppToPython_QDataStream_ByteOrder(const void* cppIn) {
    int castCppIn = *((::QDataStream::ByteOrder*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX], castCppIn);

}

static void QDataStream_Status_PythonToCpp_QDataStream_Status(PyObject* pyIn, void* cppOut) {
    *((::QDataStream::Status*)cppOut) = (::QDataStream::Status) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDataStream_Status_PythonToCpp_QDataStream_Status_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX]))
        return QDataStream_Status_PythonToCpp_QDataStream_Status;
    return 0;
}
static PyObject* QDataStream_Status_CppToPython_QDataStream_Status(const void* cppIn) {
    int castCppIn = *((::QDataStream::Status*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX], castCppIn);

}

static void QDataStream_FloatingPointPrecision_PythonToCpp_QDataStream_FloatingPointPrecision(PyObject* pyIn, void* cppOut) {
    *((::QDataStream::FloatingPointPrecision*)cppOut) = (::QDataStream::FloatingPointPrecision) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDataStream_FloatingPointPrecision_PythonToCpp_QDataStream_FloatingPointPrecision_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX]))
        return QDataStream_FloatingPointPrecision_PythonToCpp_QDataStream_FloatingPointPrecision;
    return 0;
}
static PyObject* QDataStream_FloatingPointPrecision_CppToPython_QDataStream_FloatingPointPrecision(const void* cppIn) {
    int castCppIn = *((::QDataStream::FloatingPointPrecision*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDataStream_PythonToCpp_QDataStream_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDataStream_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDataStream_PythonToCpp_QDataStream_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDataStream_Type))
        return QDataStream_PythonToCpp_QDataStream_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDataStream_PTR_CppToPython_QDataStream(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDataStream*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDataStream_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDataStream(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDataStream_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QDataStream_TypeAsNumber.nb_rshift = Sbk_QDataStreamFunc___rshift__;
    Sbk_QDataStream_TypeAsNumber.nb_lshift = Sbk_QDataStreamFunc___lshift__;
    Sbk_QDataStream_Type.super.ht_type.tp_as_number = &Sbk_QDataStream_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDataStream_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDataStream", "QDataStream*",
        &Sbk_QDataStream_Type, &Shiboken::callCppDestructor< ::QDataStream >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDataStream_Type,
        QDataStream_PythonToCpp_QDataStream_PTR,
        is_QDataStream_PythonToCpp_QDataStream_PTR_Convertible,
        QDataStream_PTR_CppToPython_QDataStream);

    Shiboken::Conversions::registerConverterName(converter, "QDataStream");
    Shiboken::Conversions::registerConverterName(converter, "QDataStream*");
    Shiboken::Conversions::registerConverterName(converter, "QDataStream&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDataStream).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDataStreamWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'Version'.
    SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDataStream_Type,
        "Version",
        "PySide.QtCore.QDataStream.Version",
        "QDataStream::Version");
    if (!SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_1_0", (long) QDataStream::Qt_1_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_2_0", (long) QDataStream::Qt_2_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_2_1", (long) QDataStream::Qt_2_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_3_0", (long) QDataStream::Qt_3_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_3_1", (long) QDataStream::Qt_3_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_3_3", (long) QDataStream::Qt_3_3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_0", (long) QDataStream::Qt_4_0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_1", (long) QDataStream::Qt_4_1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_2", (long) QDataStream::Qt_4_2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_3", (long) QDataStream::Qt_4_3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_4", (long) QDataStream::Qt_4_4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_5", (long) QDataStream::Qt_4_5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_6", (long) QDataStream::Qt_4_6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_7", (long) QDataStream::Qt_4_7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
        &Sbk_QDataStream_Type, "Qt_4_8", (long) QDataStream::Qt_4_8))
        return ;
    // Register converter for enum 'QDataStream::Version'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX],
            QDataStream_Version_CppToPython_QDataStream_Version);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDataStream_Version_PythonToCpp_QDataStream_Version,
            is_QDataStream_Version_PythonToCpp_QDataStream_Version_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_VERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDataStream::Version");
        Shiboken::Conversions::registerConverterName(converter, "Version");
    }
    // End of 'Version' enum.

    // Initialization of enum 'ByteOrder'.
    SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDataStream_Type,
        "ByteOrder",
        "PySide.QtCore.QDataStream.ByteOrder",
        "QDataStream::ByteOrder");
    if (!SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX],
        &Sbk_QDataStream_Type, "BigEndian", (long) QDataStream::BigEndian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX],
        &Sbk_QDataStream_Type, "LittleEndian", (long) QDataStream::LittleEndian))
        return ;
    // Register converter for enum 'QDataStream::ByteOrder'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX],
            QDataStream_ByteOrder_CppToPython_QDataStream_ByteOrder);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDataStream_ByteOrder_PythonToCpp_QDataStream_ByteOrder,
            is_QDataStream_ByteOrder_PythonToCpp_QDataStream_ByteOrder_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_BYTEORDER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDataStream::ByteOrder");
        Shiboken::Conversions::registerConverterName(converter, "ByteOrder");
    }
    // End of 'ByteOrder' enum.

    // Initialization of enum 'Status'.
    SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDataStream_Type,
        "Status",
        "PySide.QtCore.QDataStream.Status",
        "QDataStream::Status");
    if (!SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX],
        &Sbk_QDataStream_Type, "Ok", (long) QDataStream::Ok))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX],
        &Sbk_QDataStream_Type, "ReadPastEnd", (long) QDataStream::ReadPastEnd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX],
        &Sbk_QDataStream_Type, "ReadCorruptData", (long) QDataStream::ReadCorruptData))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX],
        &Sbk_QDataStream_Type, "WriteFailed", (long) QDataStream::WriteFailed))
        return ;
    // Register converter for enum 'QDataStream::Status'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX],
            QDataStream_Status_CppToPython_QDataStream_Status);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDataStream_Status_PythonToCpp_QDataStream_Status,
            is_QDataStream_Status_PythonToCpp_QDataStream_Status_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_STATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDataStream::Status");
        Shiboken::Conversions::registerConverterName(converter, "Status");
    }
    // End of 'Status' enum.

    // Initialization of enum 'FloatingPointPrecision'.
    SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDataStream_Type,
        "FloatingPointPrecision",
        "PySide.QtCore.QDataStream.FloatingPointPrecision",
        "QDataStream::FloatingPointPrecision");
    if (!SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX],
        &Sbk_QDataStream_Type, "SinglePrecision", (long) QDataStream::SinglePrecision))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX],
        &Sbk_QDataStream_Type, "DoublePrecision", (long) QDataStream::DoublePrecision))
        return ;
    // Register converter for enum 'QDataStream::FloatingPointPrecision'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX],
            QDataStream_FloatingPointPrecision_CppToPython_QDataStream_FloatingPointPrecision);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDataStream_FloatingPointPrecision_PythonToCpp_QDataStream_FloatingPointPrecision,
            is_QDataStream_FloatingPointPrecision_PythonToCpp_QDataStream_FloatingPointPrecision_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATASTREAM_FLOATINGPOINTPRECISION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDataStream::FloatingPointPrecision");
        Shiboken::Conversions::registerConverterName(converter, "FloatingPointPrecision");
    }
    // End of 'FloatingPointPrecision' enum.


    qRegisterMetaType< ::QDataStream::Version >("QDataStream::Version");
    qRegisterMetaType< ::QDataStream::ByteOrder >("QDataStream::ByteOrder");
    qRegisterMetaType< ::QDataStream::Status >("QDataStream::Status");
    qRegisterMetaType< ::QDataStream::FloatingPointPrecision >("QDataStream::FloatingPointPrecision");
}
