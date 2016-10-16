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

#include "qvideoframe_wrapper.h"

// Extra includes
#include <qabstractvideobuffer.h>
#include <qimage.h>
#include <qsize.h>
#include <qvideoframe.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QVideoFrame_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QVideoFrame >()))
        return -1;

    ::QVideoFrame* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QVideoFrame_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QVideoFrame", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QVideoFrame()
    // 1: QVideoFrame(QAbstractVideoBuffer*,QSize,QVideoFrame::PixelFormat)
    // 2: QVideoFrame(QImage)
    // 3: QVideoFrame(QVideoFrame)
    // 4: QVideoFrame(int,QSize,int,QVideoFrame::PixelFormat)
    if (numArgs == 0) {
        overloadId = 0; // QVideoFrame()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), (pyArgs[3])))) {
        overloadId = 4; // QVideoFrame(int,QSize,int,QVideoFrame::PixelFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (pyArgs[0])))) {
        overloadId = 3; // QVideoFrame(QVideoFrame)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QVideoFrame(QImage)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), (pyArgs[2])))) {
        overloadId = 1; // QVideoFrame(QAbstractVideoBuffer*,QSize,QVideoFrame::PixelFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrame_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QVideoFrame()
        {

            if (!PyErr_Occurred()) {
                // QVideoFrame()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoFrame();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QVideoFrame(QAbstractVideoBuffer * buffer, const QSize & size, QVideoFrame::PixelFormat format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAbstractVideoBuffer* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QSize cppArg1_local = ::QSize();
            ::QSize* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QVideoFrame::PixelFormat cppArg2 = ((::QVideoFrame::PixelFormat)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QVideoFrame(QAbstractVideoBuffer*,QSize,QVideoFrame::PixelFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoFrame(cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QVideoFrame(const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QVideoFrame(QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoFrame(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QVideoFrame(const QVideoFrame & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVideoFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QVideoFrame(QVideoFrame)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoFrame(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QVideoFrame(int bytes, const QSize & size, int bytesPerLine, QVideoFrame::PixelFormat format)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QSize cppArg1_local = ::QSize();
            ::QSize* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QVideoFrame::PixelFormat cppArg3 = ((::QVideoFrame::PixelFormat)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QVideoFrame(int,QSize,int,QVideoFrame::PixelFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVideoFrame(cppArg0, *cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QVideoFrame >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QVideoFrame_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QVideoFrame_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtMultimedia.QAbstractVideoBuffer, PySide.QtCore.QSize, PySide.QtMultimedia.QVideoFrame.PixelFormat", "PySide.QtGui.QImage", "PySide.QtMultimedia.QVideoFrame", "int, PySide.QtCore.QSize, int, PySide.QtMultimedia.QVideoFrame.PixelFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QVideoFrame", overloads);
        return -1;
}

static PyObject* Sbk_QVideoFrameFunc_bits(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bits()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uchar * cppResult = cppSelf->bits();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoFrameFunc_bytesPerLine(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesPerLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->bytesPerLine();
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

static PyObject* Sbk_QVideoFrameFunc_endTime(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->endTime();
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

static PyObject* Sbk_QVideoFrameFunc_fieldType(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fieldType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoFrame::FieldType cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->fieldType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoFrameFunc_handle(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoFrameFunc_handleType(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handleType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoBuffer::HandleType cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->handleType();
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

static PyObject* Sbk_QVideoFrameFunc_height(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->height();
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

static PyObject* Sbk_QVideoFrameFunc_imageFormatFromPixelFormat(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: imageFormatFromPixelFormat(QVideoFrame::PixelFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), (pyArg)))) {
        overloadId = 0; // imageFormatFromPixelFormat(QVideoFrame::PixelFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_imageFormatFromPixelFormat_TypeError;

    // Call function/method
    {
        ::QVideoFrame::PixelFormat cppArg0 = ((::QVideoFrame::PixelFormat)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // imageFormatFromPixelFormat(QVideoFrame::PixelFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage::Format cppResult = ::QVideoFrame::imageFormatFromPixelFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVideoFrameFunc_imageFormatFromPixelFormat_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoFrame.PixelFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.imageFormatFromPixelFormat", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_isMapped(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMapped()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->isMapped();
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

static PyObject* Sbk_QVideoFrameFunc_isReadable(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->isReadable();
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

static PyObject* Sbk_QVideoFrameFunc_isValid(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->isValid();
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

static PyObject* Sbk_QVideoFrameFunc_isWritable(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWritable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->isWritable();
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

static PyObject* Sbk_QVideoFrameFunc_map(PyObject* self, PyObject* pyArg)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: map(QAbstractVideoBuffer::MapMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX]), (pyArg)))) {
        overloadId = 0; // map(QAbstractVideoBuffer::MapMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_map_TypeError;

    // Call function/method
    {
        ::QAbstractVideoBuffer::MapMode cppArg0 = ((::QAbstractVideoBuffer::MapMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // map(QAbstractVideoBuffer::MapMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->map(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVideoFrameFunc_map_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAbstractVideoBuffer.MapMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.map", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_mapMode(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mapMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoBuffer::MapMode cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->mapMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVideoFrameFunc_mappedBytes(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mappedBytes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->mappedBytes();
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

static PyObject* Sbk_QVideoFrameFunc_pixelFormat(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixelFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoFrame::PixelFormat cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->pixelFormat();
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

static PyObject* Sbk_QVideoFrameFunc_pixelFormatFromImageFormat(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: pixelFormatFromImageFormat(QImage::Format)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), (pyArg)))) {
        overloadId = 0; // pixelFormatFromImageFormat(QImage::Format)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_pixelFormatFromImageFormat_TypeError;

    // Call function/method
    {
        ::QImage::Format cppArg0 = ((::QImage::Format)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // pixelFormatFromImageFormat(QImage::Format)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVideoFrame::PixelFormat cppResult = ::QVideoFrame::pixelFormatFromImageFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVideoFrameFunc_pixelFormatFromImageFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage.Format", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.pixelFormatFromImageFormat", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_setEndTime(PyObject* self, PyObject* pyArg)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEndTime(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setEndTime(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_setEndTime_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEndTime(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEndTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoFrameFunc_setEndTime_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.setEndTime", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_setFieldType(PyObject* self, PyObject* pyArg)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFieldType(QVideoFrame::FieldType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setFieldType(QVideoFrame::FieldType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_setFieldType_TypeError;

    // Call function/method
    {
        ::QVideoFrame::FieldType cppArg0 = ((::QVideoFrame::FieldType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFieldType(QVideoFrame::FieldType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFieldType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoFrameFunc_setFieldType_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QVideoFrame.FieldType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.setFieldType", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_setStartTime(PyObject* self, PyObject* pyArg)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartTime(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setStartTime(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVideoFrameFunc_setStartTime_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStartTime(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVideoFrameFunc_setStartTime_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QVideoFrame.setStartTime", overloads);
        return 0;
}

static PyObject* Sbk_QVideoFrameFunc_size(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->size();
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

static PyObject* Sbk_QVideoFrameFunc_startTime(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->startTime();
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

static PyObject* Sbk_QVideoFrameFunc_unmap(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unmap()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unmap();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QVideoFrameFunc_width(PyObject* self)
{
    ::QVideoFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVideoFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QVideoFrame*>(cppSelf)->width();
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

static PyMethodDef Sbk_QVideoFrame_methods[] = {
    {"bits", (PyCFunction)Sbk_QVideoFrameFunc_bits, METH_NOARGS},
    {"bytesPerLine", (PyCFunction)Sbk_QVideoFrameFunc_bytesPerLine, METH_NOARGS},
    {"endTime", (PyCFunction)Sbk_QVideoFrameFunc_endTime, METH_NOARGS},
    {"fieldType", (PyCFunction)Sbk_QVideoFrameFunc_fieldType, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QVideoFrameFunc_handle, METH_NOARGS},
    {"handleType", (PyCFunction)Sbk_QVideoFrameFunc_handleType, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QVideoFrameFunc_height, METH_NOARGS},
    {"imageFormatFromPixelFormat", (PyCFunction)Sbk_QVideoFrameFunc_imageFormatFromPixelFormat, METH_O|METH_STATIC},
    {"isMapped", (PyCFunction)Sbk_QVideoFrameFunc_isMapped, METH_NOARGS},
    {"isReadable", (PyCFunction)Sbk_QVideoFrameFunc_isReadable, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QVideoFrameFunc_isValid, METH_NOARGS},
    {"isWritable", (PyCFunction)Sbk_QVideoFrameFunc_isWritable, METH_NOARGS},
    {"map", (PyCFunction)Sbk_QVideoFrameFunc_map, METH_O},
    {"mapMode", (PyCFunction)Sbk_QVideoFrameFunc_mapMode, METH_NOARGS},
    {"mappedBytes", (PyCFunction)Sbk_QVideoFrameFunc_mappedBytes, METH_NOARGS},
    {"pixelFormat", (PyCFunction)Sbk_QVideoFrameFunc_pixelFormat, METH_NOARGS},
    {"pixelFormatFromImageFormat", (PyCFunction)Sbk_QVideoFrameFunc_pixelFormatFromImageFormat, METH_O|METH_STATIC},
    {"setEndTime", (PyCFunction)Sbk_QVideoFrameFunc_setEndTime, METH_O},
    {"setFieldType", (PyCFunction)Sbk_QVideoFrameFunc_setFieldType, METH_O},
    {"setStartTime", (PyCFunction)Sbk_QVideoFrameFunc_setStartTime, METH_O},
    {"size", (PyCFunction)Sbk_QVideoFrameFunc_size, METH_NOARGS},
    {"startTime", (PyCFunction)Sbk_QVideoFrameFunc_startTime, METH_NOARGS},
    {"unmap", (PyCFunction)Sbk_QVideoFrameFunc_unmap, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QVideoFrameFunc_width, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QVideoFrame_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QVideoFrame_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QVideoFrame_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QVideoFrame",
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
    /*tp_traverse*/         Sbk_QVideoFrame_traverse,
    /*tp_clear*/            Sbk_QVideoFrame_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QVideoFrame_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QVideoFrame_Init,
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
static void QVideoFrame_FieldType_PythonToCpp_QVideoFrame_FieldType(PyObject* pyIn, void* cppOut) {
    *((::QVideoFrame::FieldType*)cppOut) = (::QVideoFrame::FieldType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QVideoFrame_FieldType_PythonToCpp_QVideoFrame_FieldType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX]))
        return QVideoFrame_FieldType_PythonToCpp_QVideoFrame_FieldType;
    return 0;
}
static PyObject* QVideoFrame_FieldType_CppToPython_QVideoFrame_FieldType(const void* cppIn) {
    int castCppIn = *((::QVideoFrame::FieldType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX], castCppIn);

}

static void QVideoFrame_PixelFormat_PythonToCpp_QVideoFrame_PixelFormat(PyObject* pyIn, void* cppOut) {
    *((::QVideoFrame::PixelFormat*)cppOut) = (::QVideoFrame::PixelFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QVideoFrame_PixelFormat_PythonToCpp_QVideoFrame_PixelFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX]))
        return QVideoFrame_PixelFormat_PythonToCpp_QVideoFrame_PixelFormat;
    return 0;
}
static PyObject* QVideoFrame_PixelFormat_CppToPython_QVideoFrame_PixelFormat(const void* cppIn) {
    int castCppIn = *((::QVideoFrame::PixelFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QVideoFrame_PythonToCpp_QVideoFrame_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QVideoFrame_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QVideoFrame_PythonToCpp_QVideoFrame_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVideoFrame_Type))
        return QVideoFrame_PythonToCpp_QVideoFrame_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QVideoFrame_PTR_CppToPython_QVideoFrame(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QVideoFrame*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QVideoFrame_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QVideoFrame(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QVideoFrame_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QVideoFrame", "QVideoFrame*",
        &Sbk_QVideoFrame_Type, &Shiboken::callCppDestructor< ::QVideoFrame >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QVideoFrame_Type,
        QVideoFrame_PythonToCpp_QVideoFrame_PTR,
        is_QVideoFrame_PythonToCpp_QVideoFrame_PTR_Convertible,
        QVideoFrame_PTR_CppToPython_QVideoFrame);

    Shiboken::Conversions::registerConverterName(converter, "QVideoFrame");
    Shiboken::Conversions::registerConverterName(converter, "QVideoFrame*");
    Shiboken::Conversions::registerConverterName(converter, "QVideoFrame&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QVideoFrame).name());


    // Initialization of enums.

    // Initialization of enum 'FieldType'.
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QVideoFrame_Type,
        "FieldType",
        "PySide.QtMultimedia.QVideoFrame.FieldType",
        "QVideoFrame::FieldType");
    if (!SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX],
        &Sbk_QVideoFrame_Type, "ProgressiveFrame", (long) QVideoFrame::ProgressiveFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX],
        &Sbk_QVideoFrame_Type, "TopField", (long) QVideoFrame::TopField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX],
        &Sbk_QVideoFrame_Type, "BottomField", (long) QVideoFrame::BottomField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX],
        &Sbk_QVideoFrame_Type, "InterlacedFrame", (long) QVideoFrame::InterlacedFrame))
        return ;
    // Register converter for enum 'QVideoFrame::FieldType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX],
            QVideoFrame_FieldType_CppToPython_QVideoFrame_FieldType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QVideoFrame_FieldType_PythonToCpp_QVideoFrame_FieldType,
            is_QVideoFrame_FieldType_PythonToCpp_QVideoFrame_FieldType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_FIELDTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QVideoFrame::FieldType");
        Shiboken::Conversions::registerConverterName(converter, "FieldType");
    }
    // End of 'FieldType' enum.

    // Initialization of enum 'PixelFormat'.
    SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QVideoFrame_Type,
        "PixelFormat",
        "PySide.QtMultimedia.QVideoFrame.PixelFormat",
        "QVideoFrame::PixelFormat");
    if (!SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_Invalid", (long) QVideoFrame::Format_Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_ARGB32", (long) QVideoFrame::Format_ARGB32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_ARGB32_Premultiplied", (long) QVideoFrame::Format_ARGB32_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_RGB32", (long) QVideoFrame::Format_RGB32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_RGB24", (long) QVideoFrame::Format_RGB24))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_RGB565", (long) QVideoFrame::Format_RGB565))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_RGB555", (long) QVideoFrame::Format_RGB555))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_ARGB8565_Premultiplied", (long) QVideoFrame::Format_ARGB8565_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGRA32", (long) QVideoFrame::Format_BGRA32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGRA32_Premultiplied", (long) QVideoFrame::Format_BGRA32_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGR32", (long) QVideoFrame::Format_BGR32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGR24", (long) QVideoFrame::Format_BGR24))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGR565", (long) QVideoFrame::Format_BGR565))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGR555", (long) QVideoFrame::Format_BGR555))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_BGRA5658_Premultiplied", (long) QVideoFrame::Format_BGRA5658_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_AYUV444", (long) QVideoFrame::Format_AYUV444))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_AYUV444_Premultiplied", (long) QVideoFrame::Format_AYUV444_Premultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_YUV444", (long) QVideoFrame::Format_YUV444))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_YUV420P", (long) QVideoFrame::Format_YUV420P))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_YV12", (long) QVideoFrame::Format_YV12))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_UYVY", (long) QVideoFrame::Format_UYVY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_YUYV", (long) QVideoFrame::Format_YUYV))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_NV12", (long) QVideoFrame::Format_NV12))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_NV21", (long) QVideoFrame::Format_NV21))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_IMC1", (long) QVideoFrame::Format_IMC1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_IMC2", (long) QVideoFrame::Format_IMC2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_IMC3", (long) QVideoFrame::Format_IMC3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_IMC4", (long) QVideoFrame::Format_IMC4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_Y8", (long) QVideoFrame::Format_Y8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_Y16", (long) QVideoFrame::Format_Y16))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
        &Sbk_QVideoFrame_Type, "Format_User", (long) QVideoFrame::Format_User))
        return ;
    // Register converter for enum 'QVideoFrame::PixelFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX],
            QVideoFrame_PixelFormat_CppToPython_QVideoFrame_PixelFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QVideoFrame_PixelFormat_PythonToCpp_QVideoFrame_PixelFormat,
            is_QVideoFrame_PixelFormat_PythonToCpp_QVideoFrame_PixelFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QVIDEOFRAME_PIXELFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QVideoFrame::PixelFormat");
        Shiboken::Conversions::registerConverterName(converter, "PixelFormat");
    }
    // End of 'PixelFormat' enum.


    qRegisterMetaType< ::QVideoFrame::FieldType >("QVideoFrame::FieldType");
    qRegisterMetaType< ::QVideoFrame::PixelFormat >("QVideoFrame::PixelFormat");
}
