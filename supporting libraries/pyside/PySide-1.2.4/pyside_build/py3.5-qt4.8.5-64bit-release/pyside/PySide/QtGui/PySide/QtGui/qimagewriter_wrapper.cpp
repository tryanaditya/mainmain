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

#include "qimagewriter_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qimage.h>
#include <qimagewriter.h>
#include <qiodevice.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QImageWriter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QImageWriter >()))
        return -1;

    ::QImageWriter* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImageWriter(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QImageWriter", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QImageWriter()
    // 1: QImageWriter(QIODevice*,QByteArray)
    // 2: QImageWriter(QString,QByteArray)
    if (numArgs == 0) {
        overloadId = 0; // QImageWriter()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 1; // QImageWriter(QIODevice*,QByteArray)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QImageWriter(QString,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 2; // QImageWriter(QString,QByteArray)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QImageWriter()
        {

            if (!PyErr_Occurred()) {
                // QImageWriter()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWriter();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QImageWriter(QIODevice * device, const QByteArray & format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QImageWriter(QIODevice*,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWriter(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QImageWriter(const QString & fileName, const QByteArray & format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QImageWriter(): got multiple values for keyword argument 'format'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                        goto Sbk_QImageWriter_Init_TypeError;
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
                // QImageWriter(QString,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QImageWriter(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QImageWriter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QImageWriter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QImageWriter_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QIODevice, PySide.QtCore.QByteArray", "unicode, PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImageWriter", overloads);
        return -1;
}

static PyObject* Sbk_QImageWriterFunc_canWrite(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canWrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageWriter*>(cppSelf)->canWrite();
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

static PyObject* Sbk_QImageWriterFunc_compression(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // compression()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageWriter*>(cppSelf)->compression();
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

static PyObject* Sbk_QImageWriterFunc_device(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QImageWriter*>(cppSelf)->device();
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

static PyObject* Sbk_QImageWriterFunc_error(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImageWriter::ImageWriterError cppResult = const_cast<const ::QImageWriter*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageWriterFunc_errorString(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImageWriter*>(cppSelf)->errorString();
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

static PyObject* Sbk_QImageWriterFunc_fileName(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QImageWriter*>(cppSelf)->fileName();
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

static PyObject* Sbk_QImageWriterFunc_format(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QImageWriter*>(cppSelf)->format();
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

static PyObject* Sbk_QImageWriterFunc_gamma(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // gamma()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            float cppResult = const_cast<const ::QImageWriter*>(cppSelf)->gamma();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageWriterFunc_quality(PyObject* self)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // quality()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QImageWriter*>(cppSelf)->quality();
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

static PyObject* Sbk_QImageWriterFunc_setCompression(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompression(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCompression(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setCompression_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompression(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompression(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageWriterFunc_setCompression_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setCompression", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setDevice_TypeError;

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

    Sbk_QImageWriterFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setFileName(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFileName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFileName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setFileName_TypeError;

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

    Sbk_QImageWriterFunc_setFileName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setFileName", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setFormat(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormat(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setFormat(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setFormat_TypeError;

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

    Sbk_QImageWriterFunc_setFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setGamma(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGamma(float)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArg)))) {
        overloadId = 0; // setGamma(float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setGamma_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGamma(float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGamma(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageWriterFunc_setGamma_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setGamma", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setQuality(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQuality(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setQuality(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setQuality_TypeError;

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

    Sbk_QImageWriterFunc_setQuality_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.setQuality", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_setText(PyObject* self, PyObject* args)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setText", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setText(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setText(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_setText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setText(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageWriterFunc_setText_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImageWriter.setText", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_supportedImageFormats(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedImageFormats()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = ::QImageWriter::supportedImageFormats();
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

static PyObject* Sbk_QImageWriterFunc_supportsOption(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QImageWriterFunc_supportsOption_TypeError;

    // Call function/method
    {
        ::QImageIOHandler::ImageOption cppArg0 = ((::QImageIOHandler::ImageOption)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsOption(QImageIOHandler::ImageOption)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageWriter*>(cppSelf)->supportsOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageWriterFunc_supportsOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageIOHandler.ImageOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.supportsOption", overloads);
        return 0;
}

static PyObject* Sbk_QImageWriterFunc_write(PyObject* self, PyObject* pyArg)
{
    ::QImageWriter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageWriter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QImage)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // write(QImage)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageWriterFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // write(QImage)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageWriterFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageWriter.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QImageWriter_methods[] = {
    {"canWrite", (PyCFunction)Sbk_QImageWriterFunc_canWrite, METH_NOARGS},
    {"compression", (PyCFunction)Sbk_QImageWriterFunc_compression, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QImageWriterFunc_device, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QImageWriterFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QImageWriterFunc_errorString, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QImageWriterFunc_fileName, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QImageWriterFunc_format, METH_NOARGS},
    {"gamma", (PyCFunction)Sbk_QImageWriterFunc_gamma, METH_NOARGS},
    {"quality", (PyCFunction)Sbk_QImageWriterFunc_quality, METH_NOARGS},
    {"setCompression", (PyCFunction)Sbk_QImageWriterFunc_setCompression, METH_O},
    {"setDevice", (PyCFunction)Sbk_QImageWriterFunc_setDevice, METH_O},
    {"setFileName", (PyCFunction)Sbk_QImageWriterFunc_setFileName, METH_O},
    {"setFormat", (PyCFunction)Sbk_QImageWriterFunc_setFormat, METH_O},
    {"setGamma", (PyCFunction)Sbk_QImageWriterFunc_setGamma, METH_O},
    {"setQuality", (PyCFunction)Sbk_QImageWriterFunc_setQuality, METH_O},
    {"setText", (PyCFunction)Sbk_QImageWriterFunc_setText, METH_VARARGS},
    {"supportedImageFormats", (PyCFunction)Sbk_QImageWriterFunc_supportedImageFormats, METH_NOARGS|METH_STATIC},
    {"supportsOption", (PyCFunction)Sbk_QImageWriterFunc_supportsOption, METH_O},
    {"write", (PyCFunction)Sbk_QImageWriterFunc_write, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QImageWriter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QImageWriter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QImageWriter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QImageWriter",
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
    /*tp_traverse*/         Sbk_QImageWriter_traverse,
    /*tp_clear*/            Sbk_QImageWriter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QImageWriter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QImageWriter_Init,
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
static void QImageWriter_ImageWriterError_PythonToCpp_QImageWriter_ImageWriterError(PyObject* pyIn, void* cppOut) {
    *((::QImageWriter::ImageWriterError*)cppOut) = (::QImageWriter::ImageWriterError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QImageWriter_ImageWriterError_PythonToCpp_QImageWriter_ImageWriterError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX]))
        return QImageWriter_ImageWriterError_PythonToCpp_QImageWriter_ImageWriterError;
    return 0;
}
static PyObject* QImageWriter_ImageWriterError_CppToPython_QImageWriter_ImageWriterError(const void* cppIn) {
    int castCppIn = *((::QImageWriter::ImageWriterError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QImageWriter_PythonToCpp_QImageWriter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QImageWriter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QImageWriter_PythonToCpp_QImageWriter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QImageWriter_Type))
        return QImageWriter_PythonToCpp_QImageWriter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QImageWriter_PTR_CppToPython_QImageWriter(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QImageWriter*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QImageWriter_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QImageWriter(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QImageWriter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QImageWriter", "QImageWriter*",
        &Sbk_QImageWriter_Type, &Shiboken::callCppDestructor< ::QImageWriter >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QImageWriter_Type,
        QImageWriter_PythonToCpp_QImageWriter_PTR,
        is_QImageWriter_PythonToCpp_QImageWriter_PTR_Convertible,
        QImageWriter_PTR_CppToPython_QImageWriter);

    Shiboken::Conversions::registerConverterName(converter, "QImageWriter");
    Shiboken::Conversions::registerConverterName(converter, "QImageWriter*");
    Shiboken::Conversions::registerConverterName(converter, "QImageWriter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImageWriter).name());


    // Initialization of enums.

    // Initialization of enum 'ImageWriterError'.
    SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QImageWriter_Type,
        "ImageWriterError",
        "PySide.QtGui.QImageWriter.ImageWriterError",
        "QImageWriter::ImageWriterError");
    if (!SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX],
        &Sbk_QImageWriter_Type, "UnknownError", (long) QImageWriter::UnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX],
        &Sbk_QImageWriter_Type, "DeviceError", (long) QImageWriter::DeviceError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX],
        &Sbk_QImageWriter_Type, "UnsupportedFormatError", (long) QImageWriter::UnsupportedFormatError))
        return ;
    // Register converter for enum 'QImageWriter::ImageWriterError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX],
            QImageWriter_ImageWriterError_CppToPython_QImageWriter_ImageWriterError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QImageWriter_ImageWriterError_PythonToCpp_QImageWriter_ImageWriterError,
            is_QImageWriter_ImageWriterError_PythonToCpp_QImageWriter_ImageWriterError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QImageWriter::ImageWriterError");
        Shiboken::Conversions::registerConverterName(converter, "ImageWriterError");
    }
    // End of 'ImageWriterError' enum.


    qRegisterMetaType< ::QImageWriter::ImageWriterError >("QImageWriter::ImageWriterError");
}
