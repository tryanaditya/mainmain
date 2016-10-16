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
#include "pyside_qtgui_python.h"

#include "qimagereader_wrapper.h"

// Extra includes
#include <QColor>
#include <QImage>
#include <QList>
#include <QRect>
#include <QSize>
#include <QStringList>
#include <qbytearray.h>
#include <qcolor.h>
#include <qimage.h>
#include <qimagereader.h>
#include <qiodevice.h>
#include <qrect.h>
#include <qsize.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QImageReader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QImageReader >()))
        return -1;

    ::QImageReader* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImageReader(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QImageReader", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QImageReader()
    // 1: QImageReader(QIODevice*,QByteArray)
    // 2: QImageReader(QString,QByteArray)
    if (numArgs == 0) {
        overloadId = 0; // QImageReader()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QImageReader(QIODevice*,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 1; // QImageReader(QIODevice*,QByteArray)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QImageReader(QString,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 2; // QImageReader(QString,QByteArray)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReader_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QImageReader()
        {

            if (!PyErr_Occurred()) {
                // QImageReader()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageReader();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QImageReader(QIODevice * device, const QByteArray & format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImageReader(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                        goto Sbk_QImageReader_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QByteArray cppArg1_local = QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // QImageReader(QIODevice*,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageReader(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QImageReader(const QString & fileName, const QByteArray & format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImageReader(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                        goto Sbk_QImageReader_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QByteArray cppArg1_local = QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // QImageReader(QString,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageReader(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QImageReader >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QImageReader_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QImageReader_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QIODevice, PySide.QtCore.QByteArray = QByteArray()", "unicode, PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImageReader", overloads);
        return -1;
}

static PyObject* Sbk_QImageReaderFunc_autoDetectImageFormat(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoDetectImageFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageReader*>(cppSelf)->autoDetectImageFormat();
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

static PyObject* Sbk_QImageReaderFunc_backgroundColor(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundColor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QImageReader*>(cppSelf)->backgroundColor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageReaderFunc_canRead(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canRead()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageReader*>(cppSelf)->canRead();
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

static PyObject* Sbk_QImageReaderFunc_clipRect(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QImageReader*>(cppSelf)->clipRect();
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

static PyObject* Sbk_QImageReaderFunc_currentImageNumber(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentImageNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageReader*>(cppSelf)->currentImageNumber();
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

static PyObject* Sbk_QImageReaderFunc_currentImageRect(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentImageRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QImageReader*>(cppSelf)->currentImageRect();
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

static PyObject* Sbk_QImageReaderFunc_decideFormatFromContent(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // decideFormatFromContent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageReader*>(cppSelf)->decideFormatFromContent();
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

static PyObject* Sbk_QImageReaderFunc_device(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QImageReader*>(cppSelf)->device();
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

static PyObject* Sbk_QImageReaderFunc_error(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImageReader::ImageReaderError cppResult = const_cast<const ::QImageReader*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageReaderFunc_errorString(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImageReader*>(cppSelf)->errorString();
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

static PyObject* Sbk_QImageReaderFunc_fileName(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImageReader*>(cppSelf)->fileName();
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

static PyObject* Sbk_QImageReaderFunc_format(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QImageReader*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageReaderFunc_imageCount(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // imageCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageReader*>(cppSelf)->imageCount();
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

static PyObject* Sbk_QImageReaderFunc_imageFormat(PyObject* self, PyObject* args)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "imageFormat", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: imageFormat()const
    // 1: imageFormat(QIODevice*)
    // 2: imageFormat(QString)
    if (numArgs == 0) {
        overloadId = 0; // imageFormat()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        overloadId = 1; // imageFormat(QIODevice*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 2; // imageFormat(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_imageFormat_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // imageFormat() const
        {

            if (!PyErr_Occurred()) {
                // imageFormat()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QImage::Format cppResult = const_cast<const ::QImageReader*>(cppSelf)->imageFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]), &cppResult);
            }
            break;
        }
        case 1: // imageFormat(QIODevice * device)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // imageFormat(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray cppResult = ::QImageReader::imageFormat(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 2: // imageFormat(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // imageFormat(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray cppResult = ::QImageReader::imageFormat(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageReaderFunc_imageFormat_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QIODevice", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImageReader.imageFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_jumpToImage(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: jumpToImage(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // jumpToImage(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_jumpToImage_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // jumpToImage(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->jumpToImage(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageReaderFunc_jumpToImage_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.jumpToImage", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_jumpToNextImage(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // jumpToNextImage()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->jumpToNextImage();
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

static PyObject* Sbk_QImageReaderFunc_loopCount(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // loopCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageReader*>(cppSelf)->loopCount();
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

static PyObject* Sbk_QImageReaderFunc_nextImageDelay(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextImageDelay()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageReader*>(cppSelf)->nextImageDelay();
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

static PyObject* Sbk_QImageReaderFunc_quality(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // quality()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageReader*>(cppSelf)->quality();
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

static PyObject* Sbk_QImageReaderFunc_read(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // read()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = cppSelf->read();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageReaderFunc_scaledClipRect(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scaledClipRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QImageReader*>(cppSelf)->scaledClipRect();
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

static PyObject* Sbk_QImageReaderFunc_scaledSize(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scaledSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QImageReader*>(cppSelf)->scaledSize();
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

static PyObject* Sbk_QImageReaderFunc_setAutoDetectImageFormat(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoDetectImageFormat(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoDetectImageFormat(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setAutoDetectImageFormat_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoDetectImageFormat(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoDetectImageFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setAutoDetectImageFormat_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setAutoDetectImageFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setBackgroundColor(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackgroundColor(QColor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 0; // setBackgroundColor(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setBackgroundColor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QColor cppArg0_local = ::QColor();
        ::QColor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBackgroundColor(QColor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackgroundColor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setBackgroundColor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setBackgroundColor", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setClipRect(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setClipRect(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setClipRect(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setClipRect_TypeError;

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
            // setClipRect(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setClipRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setClipRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setClipRect", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setDecideFormatFromContent(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDecideFormatFromContent(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDecideFormatFromContent(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setDecideFormatFromContent_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDecideFormatFromContent(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDecideFormatFromContent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setDecideFormatFromContent_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setDecideFormatFromContent", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setDevice_TypeError;

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

    Sbk_QImageReaderFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setFileName(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFileName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFileName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setFileName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFileName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFileName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setFileName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setFileName", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setFormat(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormat(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setFormat(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setFormat_TypeError;

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
            // setFormat(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setQuality(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQuality(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setQuality(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setQuality_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setQuality(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setQuality(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setQuality_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setQuality", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setScaledClipRect(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScaledClipRect(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setScaledClipRect(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setScaledClipRect_TypeError;

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
            // setScaledClipRect(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScaledClipRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setScaledClipRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setScaledClipRect", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_setScaledSize(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScaledSize(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setScaledSize(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_setScaledSize_TypeError;

    // Call function/method
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
            // setScaledSize(QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScaledSize(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageReaderFunc_setScaledSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.setScaledSize", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_size(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QImageReader*>(cppSelf)->size();
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

static PyObject* Sbk_QImageReaderFunc_supportedImageFormats(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedImageFormats()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = ::QImageReader::supportedImageFormats();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageReaderFunc_supportsAnimation(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsAnimation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageReader*>(cppSelf)->supportsAnimation();
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

static PyObject* Sbk_QImageReaderFunc_supportsOption(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsOption(QImageIOHandler::ImageOption)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsOption(QImageIOHandler::ImageOption)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_supportsOption_TypeError;

    // Call function/method
    {
        ::QImageIOHandler::ImageOption cppArg0 = ((::QImageIOHandler::ImageOption)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsOption(QImageIOHandler::ImageOption)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageReader*>(cppSelf)->supportsOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageReaderFunc_supportsOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageIOHandler.ImageOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.supportsOption", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_text(PyObject* self, PyObject* pyArg)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: text(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // text(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageReaderFunc_text_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // text(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImageReader*>(cppSelf)->text(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageReaderFunc_text_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageReader.text", overloads);
        return 0;
}

static PyObject* Sbk_QImageReaderFunc_textKeys(PyObject* self)
{
    ::QImageReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textKeys()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QImageReader*>(cppSelf)->textKeys();
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

static PyMethodDef Sbk_QImageReaderMethod_imageFormat = {
    "imageFormat", (PyCFunction)Sbk_QImageReaderFunc_imageFormat, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QImageReader_methods[] = {
    {"autoDetectImageFormat", (PyCFunction)Sbk_QImageReaderFunc_autoDetectImageFormat, METH_NOARGS},
    {"backgroundColor", (PyCFunction)Sbk_QImageReaderFunc_backgroundColor, METH_NOARGS},
    {"canRead", (PyCFunction)Sbk_QImageReaderFunc_canRead, METH_NOARGS},
    {"clipRect", (PyCFunction)Sbk_QImageReaderFunc_clipRect, METH_NOARGS},
    {"currentImageNumber", (PyCFunction)Sbk_QImageReaderFunc_currentImageNumber, METH_NOARGS},
    {"currentImageRect", (PyCFunction)Sbk_QImageReaderFunc_currentImageRect, METH_NOARGS},
    {"decideFormatFromContent", (PyCFunction)Sbk_QImageReaderFunc_decideFormatFromContent, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QImageReaderFunc_device, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QImageReaderFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QImageReaderFunc_errorString, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QImageReaderFunc_fileName, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QImageReaderFunc_format, METH_NOARGS},
    {"imageCount", (PyCFunction)Sbk_QImageReaderFunc_imageCount, METH_NOARGS},
    Sbk_QImageReaderMethod_imageFormat,
    {"jumpToImage", (PyCFunction)Sbk_QImageReaderFunc_jumpToImage, METH_O},
    {"jumpToNextImage", (PyCFunction)Sbk_QImageReaderFunc_jumpToNextImage, METH_NOARGS},
    {"loopCount", (PyCFunction)Sbk_QImageReaderFunc_loopCount, METH_NOARGS},
    {"nextImageDelay", (PyCFunction)Sbk_QImageReaderFunc_nextImageDelay, METH_NOARGS},
    {"quality", (PyCFunction)Sbk_QImageReaderFunc_quality, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QImageReaderFunc_read, METH_NOARGS},
    {"scaledClipRect", (PyCFunction)Sbk_QImageReaderFunc_scaledClipRect, METH_NOARGS},
    {"scaledSize", (PyCFunction)Sbk_QImageReaderFunc_scaledSize, METH_NOARGS},
    {"setAutoDetectImageFormat", (PyCFunction)Sbk_QImageReaderFunc_setAutoDetectImageFormat, METH_O},
    {"setBackgroundColor", (PyCFunction)Sbk_QImageReaderFunc_setBackgroundColor, METH_O},
    {"setClipRect", (PyCFunction)Sbk_QImageReaderFunc_setClipRect, METH_O},
    {"setDecideFormatFromContent", (PyCFunction)Sbk_QImageReaderFunc_setDecideFormatFromContent, METH_O},
    {"setDevice", (PyCFunction)Sbk_QImageReaderFunc_setDevice, METH_O},
    {"setFileName", (PyCFunction)Sbk_QImageReaderFunc_setFileName, METH_O},
    {"setFormat", (PyCFunction)Sbk_QImageReaderFunc_setFormat, METH_O},
    {"setQuality", (PyCFunction)Sbk_QImageReaderFunc_setQuality, METH_O},
    {"setScaledClipRect", (PyCFunction)Sbk_QImageReaderFunc_setScaledClipRect, METH_O},
    {"setScaledSize", (PyCFunction)Sbk_QImageReaderFunc_setScaledSize, METH_O},
    {"size", (PyCFunction)Sbk_QImageReaderFunc_size, METH_NOARGS},
    {"supportedImageFormats", (PyCFunction)Sbk_QImageReaderFunc_supportedImageFormats, METH_NOARGS|METH_STATIC},
    {"supportsAnimation", (PyCFunction)Sbk_QImageReaderFunc_supportsAnimation, METH_NOARGS},
    {"supportsOption", (PyCFunction)Sbk_QImageReaderFunc_supportsOption, METH_O},
    {"text", (PyCFunction)Sbk_QImageReaderFunc_text, METH_O},
    {"textKeys", (PyCFunction)Sbk_QImageReaderFunc_textKeys, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_QImageReader_getattro(PyObject* self, PyObject* name)
{
    if (self) {
        // Search the method in the instance dict
        if (reinterpret_cast<SbkObject*>(self)->ob_dict) {
            PyObject* meth = PyDict_GetItem(reinterpret_cast<SbkObject*>(self)->ob_dict, name);
            if (meth) {
                Py_INCREF(meth);
                return meth;
            }
        }
        // Search the method in the type dict
        if (Shiboken::Object::isUserType(self)) {
            PyObject* meth = PyDict_GetItem(self->ob_type->tp_dict, name);
            if (meth)
                return PyFunction_Check(meth) ? SBK_PyMethod_New(meth, self) : PyObject_GenericGetAttr(self, name);
        }
        static PyMethodDef non_static_Sbk_QImageReaderMethod_imageFormat = {
            Sbk_QImageReaderMethod_imageFormat.ml_name,
            Sbk_QImageReaderMethod_imageFormat.ml_meth,
            Sbk_QImageReaderMethod_imageFormat.ml_flags & (~METH_STATIC),
            Sbk_QImageReaderMethod_imageFormat.ml_doc,
        };
        if (Shiboken::String::compare(name, "imageFormat") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QImageReaderMethod_imageFormat, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

} // extern "C"

static int Sbk_QImageReader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QImageReader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QImageReader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QImageReader",
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
    /*tp_getattro*/         Sbk_QImageReader_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QImageReader_traverse,
    /*tp_clear*/            Sbk_QImageReader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QImageReader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QImageReader_Init,
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
static void QImageReader_ImageReaderError_PythonToCpp_QImageReader_ImageReaderError(PyObject* pyIn, void* cppOut) {
    *((::QImageReader::ImageReaderError*)cppOut) = (::QImageReader::ImageReaderError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QImageReader_ImageReaderError_PythonToCpp_QImageReader_ImageReaderError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX]))
        return QImageReader_ImageReaderError_PythonToCpp_QImageReader_ImageReaderError;
    return 0;
}
static PyObject* QImageReader_ImageReaderError_CppToPython_QImageReader_ImageReaderError(const void* cppIn) {
    int castCppIn = *((::QImageReader::ImageReaderError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QImageReader_PythonToCpp_QImageReader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QImageReader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QImageReader_PythonToCpp_QImageReader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QImageReader_Type))
        return QImageReader_PythonToCpp_QImageReader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QImageReader_PTR_CppToPython_QImageReader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QImageReader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QImageReader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QImageReader(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QImageReader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QImageReader", "QImageReader*",
        &Sbk_QImageReader_Type, &Shiboken::callCppDestructor< ::QImageReader >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QImageReader_Type,
        QImageReader_PythonToCpp_QImageReader_PTR,
        is_QImageReader_PythonToCpp_QImageReader_PTR_Convertible,
        QImageReader_PTR_CppToPython_QImageReader);

    Shiboken::Conversions::registerConverterName(converter, "QImageReader");
    Shiboken::Conversions::registerConverterName(converter, "QImageReader*");
    Shiboken::Conversions::registerConverterName(converter, "QImageReader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImageReader).name());


    // Initialization of enums.

    // Initialization of enum 'ImageReaderError'.
    SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QImageReader_Type,
        "ImageReaderError",
        "PySide.QtGui.QImageReader.ImageReaderError",
        "QImageReader::ImageReaderError");
    if (!SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
        &Sbk_QImageReader_Type, "UnknownError", (long) QImageReader::UnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
        &Sbk_QImageReader_Type, "FileNotFoundError", (long) QImageReader::FileNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
        &Sbk_QImageReader_Type, "DeviceError", (long) QImageReader::DeviceError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
        &Sbk_QImageReader_Type, "UnsupportedFormatError", (long) QImageReader::UnsupportedFormatError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
        &Sbk_QImageReader_Type, "InvalidDataError", (long) QImageReader::InvalidDataError))
        return ;
    // Register converter for enum 'QImageReader::ImageReaderError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX],
            QImageReader_ImageReaderError_CppToPython_QImageReader_ImageReaderError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QImageReader_ImageReaderError_PythonToCpp_QImageReader_ImageReaderError,
            is_QImageReader_ImageReaderError_PythonToCpp_QImageReader_ImageReaderError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QImageReader::ImageReaderError");
        Shiboken::Conversions::registerConverterName(converter, "ImageReaderError");
    }
    // End of 'ImageReaderError' enum.


    qRegisterMetaType< ::QImageReader::ImageReaderError >("QImageReader::ImageReaderError");
}
