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

#include "qvideosurfaceformat_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qrect.h>
#include <qsize.h>
#include <qvideosurfaceformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QVideoSurfaceFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QVideoSurfaceFormat >()))
        return -1;

    ::QVideoSurfaceFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QVideoSurfaceFormat(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QVideoSurfaceFormat", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QVideoSurfaceFormat()
    // 1: QVideoSurfaceFormat(QSize,QVideoFrame::PixelFormat,QAbstractVideoBuffer::HandleType)
    // 2: QVideoSurfaceFormat(QVideoSurfaceFormat)
    if (numArgs == 0) {
        overloadId = 0; // QVideoSurfaceFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QVideoSurfaceFormat(QVideoSurfaceFormat)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QVideoSurfaceFormat(QSize,QVideoFrame::PixelFormat,QAbstractVideoBuffer::HandleType)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), (pyArgs[2])))) {
            overloadId = 1; // QVideoSurfaceFormat(QSize,QVideoFrame::PixelFormat,QAbstractVideoBuffer::HandleType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QVideoSurfaceFormat()
        {

            if (!PyErr_Occurred()) {
                // QVideoSurfaceFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoSurfaceFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QVideoSurfaceFormat(const QSize & size, QVideoFrame::PixelFormat pixelFormat, QAbstractVideoBuffer::HandleType handleType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "handleType");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QVideoSurfaceFormat(): got multiple values for keyword argument 'handleType'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QVideoSurfaceFormat_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QVideoFrame::PixelFormat cppArg1 = ((::QVideoFrame::PixelFormat)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QAbstractVideoBuffer::HandleType cppArg2 = QAbstractVideoBuffer::NoHandle;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QVideoSurfaceFormat(QSize,QVideoFrame::PixelFormat,QAbstractVideoBuffer::HandleType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoSurfaceFormat(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QVideoSurfaceFormat(const QVideoSurfaceFormat & format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
            ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QVideoSurfaceFormat(QVideoSurfaceFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoSurfaceFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QVideoSurfaceFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QVideoSurfaceFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QVideoSurfaceFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QSize, PySide.QtMultimedia.QVideoFrame.PixelFormat, PySide.QtMultimedia.QAbstractVideoBuffer.HandleType = QAbstractVideoBuffer.NoHandle", "PySide.QtMultimedia.QVideoSurfaceFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QVideoSurfaceFormat", overloads);
        return -1;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_frameHeight(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frameHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->frameHeight();
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

static PyObject* Sbk_QVideoSurfaceFormatFunc_frameRate(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frameRate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->frameRate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_frameSize(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frameSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->frameSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_frameWidth(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frameWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->frameWidth();
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

static PyObject* Sbk_QVideoSurfaceFormatFunc_handleType(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handleType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoBuffer::HandleType cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->handleType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_isValid(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QVideoSurfaceFormatFunc_pixelAspectRatio(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixelAspectRatio()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->pixelAspectRatio();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_pixelFormat(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixelFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoFrame::PixelFormat cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->pixelFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // property(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_property_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVideoSurfaceFormatFunc_property_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoSurfaceFormat.property", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_propertyNames(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->propertyNames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_scanLineDirection(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scanLineDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoSurfaceFormat::Direction cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->scanLineDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setFrameRate(PyObject* self, PyObject* pyArg)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFrameRate(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setFrameRate(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setFrameRate_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFrameRate(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFrameRate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setFrameRate_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoSurfaceFormat.setFrameRate", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setFrameSize(PyObject* self, PyObject* args)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFrameSize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFrameSize(QSize)
    // 1: setFrameSize(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // setFrameSize(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        overloadId = 0; // setFrameSize(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setFrameSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setFrameSize(const QSize & size)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setFrameSize(QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFrameSize(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setFrameSize(int width, int height)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setFrameSize(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFrameSize(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setFrameSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QVideoSurfaceFormat.setFrameSize", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setPixelAspectRatio(PyObject* self, PyObject* args)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPixelAspectRatio", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPixelAspectRatio(QSize)
    // 1: setPixelAspectRatio(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // setPixelAspectRatio(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        overloadId = 0; // setPixelAspectRatio(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setPixelAspectRatio_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPixelAspectRatio(const QSize & ratio)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setPixelAspectRatio(QSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPixelAspectRatio(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPixelAspectRatio(int width, int height)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPixelAspectRatio(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPixelAspectRatio(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setPixelAspectRatio_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QVideoSurfaceFormat.setPixelAspectRatio", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(const char*,QVariant)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setProperty(const char*,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setProperty_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProperty(const char*,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setProperty_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QVideoSurfaceFormat.setProperty", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setScanLineDirection(PyObject* self, PyObject* pyArg)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScanLineDirection(QVideoSurfaceFormat::Direction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setScanLineDirection(QVideoSurfaceFormat::Direction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setScanLineDirection_TypeError;

    // Call function/method
    {
        ::QVideoSurfaceFormat::Direction cppArg0 = ((::QVideoSurfaceFormat::Direction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScanLineDirection(QVideoSurfaceFormat::Direction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScanLineDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setScanLineDirection_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoSurfaceFormat.Direction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoSurfaceFormat.setScanLineDirection", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setViewport(PyObject* self, PyObject* pyArg)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setViewport(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setViewport(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setViewport_TypeError;

    // Call function/method
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
            // setViewport(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setViewport(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setViewport_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoSurfaceFormat.setViewport", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_setYCbCrColorSpace(PyObject* self, PyObject* pyArg)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setYCbCrColorSpace(QVideoSurfaceFormat::YCbCrColorSpace)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX]), (pyArg)))) {
        overloadId = 0; // setYCbCrColorSpace(QVideoSurfaceFormat::YCbCrColorSpace)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoSurfaceFormatFunc_setYCbCrColorSpace_TypeError;

    // Call function/method
    {
        ::QVideoSurfaceFormat::YCbCrColorSpace cppArg0 = ((::QVideoSurfaceFormat::YCbCrColorSpace)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setYCbCrColorSpace(QVideoSurfaceFormat::YCbCrColorSpace)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setYCbCrColorSpace(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoSurfaceFormatFunc_setYCbCrColorSpace_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoSurfaceFormat.YCbCrColorSpace", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoSurfaceFormat.setYCbCrColorSpace", overloads);
        return 0;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_sizeHint(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->sizeHint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_viewport(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewport()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->viewport();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormatFunc_yCbCrColorSpace(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // yCbCrColorSpace()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoSurfaceFormat::YCbCrColorSpace cppResult = const_cast<const ::QVideoSurfaceFormat*>(cppSelf)->yCbCrColorSpace();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoSurfaceFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVideoSurfaceFormat& cppSelf = *(((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QVideoSurfaceFormat_methods[] = {
    {"frameHeight", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_frameHeight, METH_NOARGS},
    {"frameRate", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_frameRate, METH_NOARGS},
    {"frameSize", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_frameSize, METH_NOARGS},
    {"frameWidth", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_frameWidth, METH_NOARGS},
    {"handleType", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_handleType, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_isValid, METH_NOARGS},
    {"pixelAspectRatio", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_pixelAspectRatio, METH_NOARGS},
    {"pixelFormat", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_pixelFormat, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_property, METH_O},
    {"propertyNames", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_propertyNames, METH_NOARGS},
    {"scanLineDirection", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_scanLineDirection, METH_NOARGS},
    {"setFrameRate", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setFrameRate, METH_O},
    {"setFrameSize", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setFrameSize, METH_VARARGS},
    {"setPixelAspectRatio", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setPixelAspectRatio, METH_VARARGS},
    {"setProperty", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setProperty, METH_VARARGS},
    {"setScanLineDirection", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setScanLineDirection, METH_O},
    {"setViewport", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setViewport, METH_O},
    {"setYCbCrColorSpace", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_setYCbCrColorSpace, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_sizeHint, METH_NOARGS},
    {"viewport", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_viewport, METH_NOARGS},
    {"yCbCrColorSpace", (PyCFunction)Sbk_QVideoSurfaceFormatFunc_yCbCrColorSpace, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QVideoSurfaceFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QVideoSurfaceFormat_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVideoSurfaceFormat& cppSelf = *(((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArg)))) {
                // operator!=(const QVideoSurfaceFormat & format) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
                ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (pyArg)))) {
                // operator==(const QVideoSurfaceFormat & format) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVideoSurfaceFormat cppArg0_local = ::QVideoSurfaceFormat();
                ::QVideoSurfaceFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], pythonToCpp))
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
            goto Sbk_QVideoSurfaceFormat_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QVideoSurfaceFormat_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QVideoSurfaceFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QVideoSurfaceFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QVideoSurfaceFormat__repr__(PyObject* self)
{
    ::QVideoSurfaceFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QVideoSurfaceFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QVideoSurfaceFormat",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QVideoSurfaceFormat__repr__,
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
    /*tp_traverse*/         Sbk_QVideoSurfaceFormat_traverse,
    /*tp_clear*/            Sbk_QVideoSurfaceFormat_clear,
    /*tp_richcompare*/      Sbk_QVideoSurfaceFormat_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QVideoSurfaceFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QVideoSurfaceFormat_Init,
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
static void QVideoSurfaceFormat_Direction_PythonToCpp_QVideoSurfaceFormat_Direction(PyObject* pyIn, void* cppOut) {
    *((::QVideoSurfaceFormat::Direction*)cppOut) = (::QVideoSurfaceFormat::Direction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QVideoSurfaceFormat_Direction_PythonToCpp_QVideoSurfaceFormat_Direction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX]))
        return QVideoSurfaceFormat_Direction_PythonToCpp_QVideoSurfaceFormat_Direction;
    return 0;
}
static PyObject* QVideoSurfaceFormat_Direction_CppToPython_QVideoSurfaceFormat_Direction(const void* cppIn) {
    int castCppIn = *((::QVideoSurfaceFormat::Direction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX], castCppIn);

}

static void QVideoSurfaceFormat_YCbCrColorSpace_PythonToCpp_QVideoSurfaceFormat_YCbCrColorSpace(PyObject* pyIn, void* cppOut) {
    *((::QVideoSurfaceFormat::YCbCrColorSpace*)cppOut) = (::QVideoSurfaceFormat::YCbCrColorSpace) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QVideoSurfaceFormat_YCbCrColorSpace_PythonToCpp_QVideoSurfaceFormat_YCbCrColorSpace_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX]))
        return QVideoSurfaceFormat_YCbCrColorSpace_PythonToCpp_QVideoSurfaceFormat_YCbCrColorSpace;
    return 0;
}
static PyObject* QVideoSurfaceFormat_YCbCrColorSpace_CppToPython_QVideoSurfaceFormat_YCbCrColorSpace(const void* cppIn) {
    int castCppIn = *((::QVideoSurfaceFormat::YCbCrColorSpace*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QVideoSurfaceFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVideoSurfaceFormat_Type))
        return QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QVideoSurfaceFormat_PTR_CppToPython_QVideoSurfaceFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QVideoSurfaceFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QVideoSurfaceFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QVideoSurfaceFormat_COPY_CppToPython_QVideoSurfaceFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QVideoSurfaceFormat_Type, new ::QVideoSurfaceFormat(*((::QVideoSurfaceFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QVideoSurfaceFormat*)cppOut) = *((::QVideoSurfaceFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVideoSurfaceFormat_Type))
        return QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_COPY;
    return 0;
}

void init_QVideoSurfaceFormat(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QVideoSurfaceFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QVideoSurfaceFormat", "QVideoSurfaceFormat",
        &Sbk_QVideoSurfaceFormat_Type, &Shiboken::callCppDestructor< ::QVideoSurfaceFormat >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QVideoSurfaceFormat_Type,
        QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_PTR,
        is_QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_PTR_Convertible,
        QVideoSurfaceFormat_PTR_CppToPython_QVideoSurfaceFormat,
        QVideoSurfaceFormat_COPY_CppToPython_QVideoSurfaceFormat);

    Shiboken::Conversions::registerConverterName(converter, "QVideoSurfaceFormat");
    Shiboken::Conversions::registerConverterName(converter, "QVideoSurfaceFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QVideoSurfaceFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QVideoSurfaceFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_COPY,
        is_QVideoSurfaceFormat_PythonToCpp_QVideoSurfaceFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Direction'.
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QVideoSurfaceFormat_Type,
        "Direction",
        "PySide.QtMultimedia.QVideoSurfaceFormat.Direction",
        "QVideoSurfaceFormat::Direction");
    if (!SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "TopToBottom", (long) QVideoSurfaceFormat::TopToBottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "BottomToTop", (long) QVideoSurfaceFormat::BottomToTop))
        return ;
    // Register converter for enum 'QVideoSurfaceFormat::Direction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX],
            QVideoSurfaceFormat_Direction_CppToPython_QVideoSurfaceFormat_Direction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QVideoSurfaceFormat_Direction_PythonToCpp_QVideoSurfaceFormat_Direction,
            is_QVideoSurfaceFormat_Direction_PythonToCpp_QVideoSurfaceFormat_Direction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_DIRECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QVideoSurfaceFormat::Direction");
        Shiboken::Conversions::registerConverterName(converter, "Direction");
    }
    // End of 'Direction' enum.

    // Initialization of enum 'YCbCrColorSpace'.
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QVideoSurfaceFormat_Type,
        "YCbCrColorSpace",
        "PySide.QtMultimedia.QVideoSurfaceFormat.YCbCrColorSpace",
        "QVideoSurfaceFormat::YCbCrColorSpace");
    if (!SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_Undefined", (long) QVideoSurfaceFormat::YCbCr_Undefined))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_BT601", (long) QVideoSurfaceFormat::YCbCr_BT601))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_BT709", (long) QVideoSurfaceFormat::YCbCr_BT709))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_xvYCC601", (long) QVideoSurfaceFormat::YCbCr_xvYCC601))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_xvYCC709", (long) QVideoSurfaceFormat::YCbCr_xvYCC709))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
        &Sbk_QVideoSurfaceFormat_Type, "YCbCr_JPEG", (long) QVideoSurfaceFormat::YCbCr_JPEG))
        return ;
    // Register converter for enum 'QVideoSurfaceFormat::YCbCrColorSpace'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX],
            QVideoSurfaceFormat_YCbCrColorSpace_CppToPython_QVideoSurfaceFormat_YCbCrColorSpace);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QVideoSurfaceFormat_YCbCrColorSpace_PythonToCpp_QVideoSurfaceFormat_YCbCrColorSpace,
            is_QVideoSurfaceFormat_YCbCrColorSpace_PythonToCpp_QVideoSurfaceFormat_YCbCrColorSpace_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOSURFACEFORMAT_YCBCRCOLORSPACE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QVideoSurfaceFormat::YCbCrColorSpace");
        Shiboken::Conversions::registerConverterName(converter, "YCbCrColorSpace");
    }
    // End of 'YCbCrColorSpace' enum.


    qRegisterMetaType< ::QVideoSurfaceFormat >("QVideoSurfaceFormat");
    qRegisterMetaType< ::QVideoSurfaceFormat::Direction >("QVideoSurfaceFormat::Direction");
    qRegisterMetaType< ::QVideoSurfaceFormat::YCbCrColorSpace >("QVideoSurfaceFormat::YCbCrColorSpace");
}
