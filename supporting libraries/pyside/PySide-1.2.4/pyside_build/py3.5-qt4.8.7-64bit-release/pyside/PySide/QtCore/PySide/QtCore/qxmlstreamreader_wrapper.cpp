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

#include "qxmlstreamreader_wrapper.h"

// Extra includes
#include <QVector>
#include <qbytearray.h>
#include <qiodevice.h>
#include <qxmlstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlStreamReader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlStreamReader >()))
        return -1;

    ::QXmlStreamReader* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlStreamReader", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlStreamReader()
    // 1: QXmlStreamReader(QIODevice*)
    // 2: QXmlStreamReader(QByteArray)
    // 3: QXmlStreamReader(QString)
    // 4: QXmlStreamReader(const char*)
    if (numArgs == 0) {
        overloadId = 0; // QXmlStreamReader()
    } else if (numArgs == 1
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 4; // QXmlStreamReader(const char*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlStreamReader(QIODevice*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 3; // QXmlStreamReader(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 2; // QXmlStreamReader(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReader_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlStreamReader()
        {

            if (!PyErr_Occurred()) {
                // QXmlStreamReader()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamReader();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlStreamReader(QIODevice * device)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlStreamReader(QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamReader(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QXmlStreamReader(const QByteArray & data)
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
                // QXmlStreamReader(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamReader(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QXmlStreamReader(const QString & data)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlStreamReader(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamReader(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QXmlStreamReader(const char * data)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlStreamReader(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamReader(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlStreamReader >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlStreamReader_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlStreamReader_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QIODevice", "PySide.QtCore.QByteArray", "unicode", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamReader", overloads);
        return -1;
}

static PyObject* Sbk_QXmlStreamReaderFunc_addData(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addData(QByteArray)
    // 1: addData(QString)
    // 2: addData(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 2; // addData(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // addData(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // addData(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_addData_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addData(const QByteArray & data)
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
                // addData(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addData(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addData(const QString & data)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // addData(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addData(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // addData(const char * data)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // addData(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addData(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_addData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "unicode", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.addData", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclaration(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addExtraNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (pyArg)))) {
        overloadId = 0; // addExtraNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclaration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamNamespaceDeclaration cppArg0_local = ::QXmlStreamNamespaceDeclaration();
        ::QXmlStreamNamespaceDeclaration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addExtraNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addExtraNamespaceDeclaration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclaration_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamNamespaceDeclaration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.addExtraNamespaceDeclaration", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclarations(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addExtraNamespaceDeclarations(QVector<QXmlStreamNamespaceDeclaration>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX], (pyArg)))) {
        overloadId = 0; // addExtraNamespaceDeclarations(QVector<QXmlStreamNamespaceDeclaration>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclarations_TypeError;

    // Call function/method
    {
        ::QVector<QXmlStreamNamespaceDeclaration > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addExtraNamespaceDeclarations(QVector<QXmlStreamNamespaceDeclaration>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addExtraNamespaceDeclarations(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclarations_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.addExtraNamespaceDeclarations", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_atEnd(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QXmlStreamReaderFunc_attributes(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttributes cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->attributes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_characterOffset(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // characterOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->characterOffset();
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

static PyObject* Sbk_QXmlStreamReaderFunc_clear(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlStreamReaderFunc_columnNumber(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->columnNumber();
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

static PyObject* Sbk_QXmlStreamReaderFunc_device(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->device();
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

static PyObject* Sbk_QXmlStreamReaderFunc_documentEncoding(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentEncoding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->documentEncoding();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_documentVersion(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentVersion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->documentVersion();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_dtdName(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dtdName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->dtdName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_dtdPublicId(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dtdPublicId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->dtdPublicId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_dtdSystemId(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dtdSystemId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->dtdSystemId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_entityDeclarations(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // entityDeclarations()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamEntityDeclaration > cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->entityDeclarations();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMENTITYDECLARATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_entityResolver(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // entityResolver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamEntityResolver * cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->entityResolver();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYRESOLVER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_error(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamReader::Error cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_errorString(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->errorString();
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

static PyObject* Sbk_QXmlStreamReaderFunc_hasError(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->hasError();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isCDATA(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCDATA()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isCDATA();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isCharacters(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCharacters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isCharacters();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isComment(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isComment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isComment();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isDTD(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDTD()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isDTD();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isEndDocument(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEndDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isEndDocument();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isEndElement(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEndElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isEndElement();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isEntityReference(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEntityReference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isEntityReference();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isProcessingInstruction(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isProcessingInstruction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isProcessingInstruction();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isStandaloneDocument(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isStandaloneDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isStandaloneDocument();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isStartDocument(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isStartDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isStartDocument();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isStartElement(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isStartElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isStartElement();
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

static PyObject* Sbk_QXmlStreamReaderFunc_isWhitespace(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWhitespace()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->isWhitespace();
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

static PyObject* Sbk_QXmlStreamReaderFunc_lineNumber(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QXmlStreamReaderFunc_name(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_namespaceDeclarations(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceDeclarations()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamNamespaceDeclaration > cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->namespaceDeclarations();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNAMESPACEDECLARATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_namespaceProcessing(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceProcessing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->namespaceProcessing();
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

static PyObject* Sbk_QXmlStreamReaderFunc_namespaceUri(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceUri()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->namespaceUri();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_notationDeclarations(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notationDeclarations()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamNotationDeclaration > cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->notationDeclarations();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMNOTATIONDECLARATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_prefix(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->prefix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_processingInstructionData(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // processingInstructionData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->processingInstructionData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_processingInstructionTarget(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // processingInstructionTarget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->processingInstructionTarget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_qualifiedName(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // qualifiedName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->qualifiedName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_raiseError(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamReader.raiseError(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:raiseError", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: raiseError(QString)
    if (numArgs == 0) {
        overloadId = 0; // raiseError(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // raiseError(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_raiseError_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "message");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamReader.raiseError(): got multiple values for keyword argument 'message'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QXmlStreamReaderFunc_raiseError_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // raiseError(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->raiseError(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_raiseError_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamReader.raiseError", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_readElementText(PyObject* self, PyObject* args)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "readElementText", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: readElementText()
    // 1: readElementText(QXmlStreamReader::ReadElementTextBehaviour)
    if (numArgs == 0) {
        overloadId = 0; // readElementText()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX]), (pyArgs[0])))) {
        overloadId = 1; // readElementText(QXmlStreamReader::ReadElementTextBehaviour)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_readElementText_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // readElementText()
        {

            if (!PyErr_Occurred()) {
                // readElementText()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = cppSelf->readElementText();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // readElementText(QXmlStreamReader::ReadElementTextBehaviour behaviour)
        {
            ::QXmlStreamReader::ReadElementTextBehaviour cppArg0 = ((::QXmlStreamReader::ReadElementTextBehaviour)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // readElementText(QXmlStreamReader::ReadElementTextBehaviour)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = cppSelf->readElementText(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamReaderFunc_readElementText_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QXmlStreamReader.ReadElementTextBehaviour", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamReader.readElementText", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_readNext(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readNext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamReader::TokenType cppResult = cppSelf->readNext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_readNextStartElement(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readNextStartElement()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->readNextStartElement();
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

static PyObject* Sbk_QXmlStreamReaderFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_setDevice_TypeError;

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

    Sbk_QXmlStreamReaderFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_setEntityResolver(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEntityResolver(QXmlStreamEntityResolver*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYRESOLVER_IDX], (pyArg)))) {
        overloadId = 0; // setEntityResolver(QXmlStreamEntityResolver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_setEntityResolver_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamEntityResolver* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEntityResolver(QXmlStreamEntityResolver*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEntityResolver(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_setEntityResolver_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamEntityResolver", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.setEntityResolver", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_setNamespaceProcessing(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNamespaceProcessing(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setNamespaceProcessing(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamReaderFunc_setNamespaceProcessing_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNamespaceProcessing(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNamespaceProcessing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamReaderFunc_setNamespaceProcessing_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamReader.setNamespaceProcessing", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamReaderFunc_skipCurrentElement(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // skipCurrentElement()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->skipCurrentElement();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlStreamReaderFunc_text(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->text();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamReaderFunc_tokenString(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tokenString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->tokenString();
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

static PyObject* Sbk_QXmlStreamReaderFunc_tokenType(PyObject* self)
{
    ::QXmlStreamReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tokenType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamReader::TokenType cppResult = const_cast<const ::QXmlStreamReader*>(cppSelf)->tokenType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlStreamReader_methods[] = {
    {"addData", (PyCFunction)Sbk_QXmlStreamReaderFunc_addData, METH_O},
    {"addExtraNamespaceDeclaration", (PyCFunction)Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclaration, METH_O},
    {"addExtraNamespaceDeclarations", (PyCFunction)Sbk_QXmlStreamReaderFunc_addExtraNamespaceDeclarations, METH_O},
    {"atEnd", (PyCFunction)Sbk_QXmlStreamReaderFunc_atEnd, METH_NOARGS},
    {"attributes", (PyCFunction)Sbk_QXmlStreamReaderFunc_attributes, METH_NOARGS},
    {"characterOffset", (PyCFunction)Sbk_QXmlStreamReaderFunc_characterOffset, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QXmlStreamReaderFunc_clear, METH_NOARGS},
    {"columnNumber", (PyCFunction)Sbk_QXmlStreamReaderFunc_columnNumber, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QXmlStreamReaderFunc_device, METH_NOARGS},
    {"documentEncoding", (PyCFunction)Sbk_QXmlStreamReaderFunc_documentEncoding, METH_NOARGS},
    {"documentVersion", (PyCFunction)Sbk_QXmlStreamReaderFunc_documentVersion, METH_NOARGS},
    {"dtdName", (PyCFunction)Sbk_QXmlStreamReaderFunc_dtdName, METH_NOARGS},
    {"dtdPublicId", (PyCFunction)Sbk_QXmlStreamReaderFunc_dtdPublicId, METH_NOARGS},
    {"dtdSystemId", (PyCFunction)Sbk_QXmlStreamReaderFunc_dtdSystemId, METH_NOARGS},
    {"entityDeclarations", (PyCFunction)Sbk_QXmlStreamReaderFunc_entityDeclarations, METH_NOARGS},
    {"entityResolver", (PyCFunction)Sbk_QXmlStreamReaderFunc_entityResolver, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QXmlStreamReaderFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QXmlStreamReaderFunc_errorString, METH_NOARGS},
    {"hasError", (PyCFunction)Sbk_QXmlStreamReaderFunc_hasError, METH_NOARGS},
    {"isCDATA", (PyCFunction)Sbk_QXmlStreamReaderFunc_isCDATA, METH_NOARGS},
    {"isCharacters", (PyCFunction)Sbk_QXmlStreamReaderFunc_isCharacters, METH_NOARGS},
    {"isComment", (PyCFunction)Sbk_QXmlStreamReaderFunc_isComment, METH_NOARGS},
    {"isDTD", (PyCFunction)Sbk_QXmlStreamReaderFunc_isDTD, METH_NOARGS},
    {"isEndDocument", (PyCFunction)Sbk_QXmlStreamReaderFunc_isEndDocument, METH_NOARGS},
    {"isEndElement", (PyCFunction)Sbk_QXmlStreamReaderFunc_isEndElement, METH_NOARGS},
    {"isEntityReference", (PyCFunction)Sbk_QXmlStreamReaderFunc_isEntityReference, METH_NOARGS},
    {"isProcessingInstruction", (PyCFunction)Sbk_QXmlStreamReaderFunc_isProcessingInstruction, METH_NOARGS},
    {"isStandaloneDocument", (PyCFunction)Sbk_QXmlStreamReaderFunc_isStandaloneDocument, METH_NOARGS},
    {"isStartDocument", (PyCFunction)Sbk_QXmlStreamReaderFunc_isStartDocument, METH_NOARGS},
    {"isStartElement", (PyCFunction)Sbk_QXmlStreamReaderFunc_isStartElement, METH_NOARGS},
    {"isWhitespace", (PyCFunction)Sbk_QXmlStreamReaderFunc_isWhitespace, METH_NOARGS},
    {"lineNumber", (PyCFunction)Sbk_QXmlStreamReaderFunc_lineNumber, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QXmlStreamReaderFunc_name, METH_NOARGS},
    {"namespaceDeclarations", (PyCFunction)Sbk_QXmlStreamReaderFunc_namespaceDeclarations, METH_NOARGS},
    {"namespaceProcessing", (PyCFunction)Sbk_QXmlStreamReaderFunc_namespaceProcessing, METH_NOARGS},
    {"namespaceUri", (PyCFunction)Sbk_QXmlStreamReaderFunc_namespaceUri, METH_NOARGS},
    {"notationDeclarations", (PyCFunction)Sbk_QXmlStreamReaderFunc_notationDeclarations, METH_NOARGS},
    {"prefix", (PyCFunction)Sbk_QXmlStreamReaderFunc_prefix, METH_NOARGS},
    {"processingInstructionData", (PyCFunction)Sbk_QXmlStreamReaderFunc_processingInstructionData, METH_NOARGS},
    {"processingInstructionTarget", (PyCFunction)Sbk_QXmlStreamReaderFunc_processingInstructionTarget, METH_NOARGS},
    {"qualifiedName", (PyCFunction)Sbk_QXmlStreamReaderFunc_qualifiedName, METH_NOARGS},
    {"raiseError", (PyCFunction)Sbk_QXmlStreamReaderFunc_raiseError, METH_VARARGS|METH_KEYWORDS},
    {"readElementText", (PyCFunction)Sbk_QXmlStreamReaderFunc_readElementText, METH_VARARGS},
    {"readNext", (PyCFunction)Sbk_QXmlStreamReaderFunc_readNext, METH_NOARGS},
    {"readNextStartElement", (PyCFunction)Sbk_QXmlStreamReaderFunc_readNextStartElement, METH_NOARGS},
    {"setDevice", (PyCFunction)Sbk_QXmlStreamReaderFunc_setDevice, METH_O},
    {"setEntityResolver", (PyCFunction)Sbk_QXmlStreamReaderFunc_setEntityResolver, METH_O},
    {"setNamespaceProcessing", (PyCFunction)Sbk_QXmlStreamReaderFunc_setNamespaceProcessing, METH_O},
    {"skipCurrentElement", (PyCFunction)Sbk_QXmlStreamReaderFunc_skipCurrentElement, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QXmlStreamReaderFunc_text, METH_NOARGS},
    {"tokenString", (PyCFunction)Sbk_QXmlStreamReaderFunc_tokenString, METH_NOARGS},
    {"tokenType", (PyCFunction)Sbk_QXmlStreamReaderFunc_tokenType, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlStreamReader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlStreamReader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlStreamReader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QXmlStreamReader",
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
    /*tp_traverse*/         Sbk_QXmlStreamReader_traverse,
    /*tp_clear*/            Sbk_QXmlStreamReader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlStreamReader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlStreamReader_Init,
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
static void QXmlStreamReader_TokenType_PythonToCpp_QXmlStreamReader_TokenType(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamReader::TokenType*)cppOut) = (::QXmlStreamReader::TokenType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlStreamReader_TokenType_PythonToCpp_QXmlStreamReader_TokenType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX]))
        return QXmlStreamReader_TokenType_PythonToCpp_QXmlStreamReader_TokenType;
    return 0;
}
static PyObject* QXmlStreamReader_TokenType_CppToPython_QXmlStreamReader_TokenType(const void* cppIn) {
    int castCppIn = *((::QXmlStreamReader::TokenType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX], castCppIn);

}

static void QXmlStreamReader_ReadElementTextBehaviour_PythonToCpp_QXmlStreamReader_ReadElementTextBehaviour(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamReader::ReadElementTextBehaviour*)cppOut) = (::QXmlStreamReader::ReadElementTextBehaviour) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlStreamReader_ReadElementTextBehaviour_PythonToCpp_QXmlStreamReader_ReadElementTextBehaviour_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX]))
        return QXmlStreamReader_ReadElementTextBehaviour_PythonToCpp_QXmlStreamReader_ReadElementTextBehaviour;
    return 0;
}
static PyObject* QXmlStreamReader_ReadElementTextBehaviour_CppToPython_QXmlStreamReader_ReadElementTextBehaviour(const void* cppIn) {
    int castCppIn = *((::QXmlStreamReader::ReadElementTextBehaviour*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX], castCppIn);

}

static void QXmlStreamReader_Error_PythonToCpp_QXmlStreamReader_Error(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamReader::Error*)cppOut) = (::QXmlStreamReader::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlStreamReader_Error_PythonToCpp_QXmlStreamReader_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX]))
        return QXmlStreamReader_Error_PythonToCpp_QXmlStreamReader_Error;
    return 0;
}
static PyObject* QXmlStreamReader_Error_CppToPython_QXmlStreamReader_Error(const void* cppIn) {
    int castCppIn = *((::QXmlStreamReader::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlStreamReader_PythonToCpp_QXmlStreamReader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlStreamReader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlStreamReader_PythonToCpp_QXmlStreamReader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamReader_Type))
        return QXmlStreamReader_PythonToCpp_QXmlStreamReader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlStreamReader_PTR_CppToPython_QXmlStreamReader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlStreamReader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlStreamReader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlStreamReader(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlStreamReader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlStreamReader", "QXmlStreamReader*",
        &Sbk_QXmlStreamReader_Type, &Shiboken::callCppDestructor< ::QXmlStreamReader >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlStreamReader_Type,
        QXmlStreamReader_PythonToCpp_QXmlStreamReader_PTR,
        is_QXmlStreamReader_PythonToCpp_QXmlStreamReader_PTR_Convertible,
        QXmlStreamReader_PTR_CppToPython_QXmlStreamReader);

    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlStreamReader).name());


    // Initialization of enums.

    // Initialization of enum 'TokenType'.
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlStreamReader_Type,
        "TokenType",
        "PySide.QtCore.QXmlStreamReader.TokenType",
        "QXmlStreamReader::TokenType");
    if (!SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "NoToken", (long) QXmlStreamReader::NoToken))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "Invalid", (long) QXmlStreamReader::Invalid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "StartDocument", (long) QXmlStreamReader::StartDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "EndDocument", (long) QXmlStreamReader::EndDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "StartElement", (long) QXmlStreamReader::StartElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "EndElement", (long) QXmlStreamReader::EndElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "Characters", (long) QXmlStreamReader::Characters))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "Comment", (long) QXmlStreamReader::Comment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "DTD", (long) QXmlStreamReader::DTD))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "EntityReference", (long) QXmlStreamReader::EntityReference))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
        &Sbk_QXmlStreamReader_Type, "ProcessingInstruction", (long) QXmlStreamReader::ProcessingInstruction))
        return ;
    // Register converter for enum 'QXmlStreamReader::TokenType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX],
            QXmlStreamReader_TokenType_CppToPython_QXmlStreamReader_TokenType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlStreamReader_TokenType_PythonToCpp_QXmlStreamReader_TokenType,
            is_QXmlStreamReader_TokenType_PythonToCpp_QXmlStreamReader_TokenType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_TOKENTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader::TokenType");
        Shiboken::Conversions::registerConverterName(converter, "TokenType");
    }
    // End of 'TokenType' enum.

    // Initialization of enum 'ReadElementTextBehaviour'.
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlStreamReader_Type,
        "ReadElementTextBehaviour",
        "PySide.QtCore.QXmlStreamReader.ReadElementTextBehaviour",
        "QXmlStreamReader::ReadElementTextBehaviour");
    if (!SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX],
        &Sbk_QXmlStreamReader_Type, "ErrorOnUnexpectedElement", (long) QXmlStreamReader::ErrorOnUnexpectedElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX],
        &Sbk_QXmlStreamReader_Type, "IncludeChildElements", (long) QXmlStreamReader::IncludeChildElements))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX],
        &Sbk_QXmlStreamReader_Type, "SkipChildElements", (long) QXmlStreamReader::SkipChildElements))
        return ;
    // Register converter for enum 'QXmlStreamReader::ReadElementTextBehaviour'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX],
            QXmlStreamReader_ReadElementTextBehaviour_CppToPython_QXmlStreamReader_ReadElementTextBehaviour);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlStreamReader_ReadElementTextBehaviour_PythonToCpp_QXmlStreamReader_ReadElementTextBehaviour,
            is_QXmlStreamReader_ReadElementTextBehaviour_PythonToCpp_QXmlStreamReader_ReadElementTextBehaviour_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_READELEMENTTEXTBEHAVIOUR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader::ReadElementTextBehaviour");
        Shiboken::Conversions::registerConverterName(converter, "ReadElementTextBehaviour");
    }
    // End of 'ReadElementTextBehaviour' enum.

    // Initialization of enum 'Error'.
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlStreamReader_Type,
        "Error",
        "PySide.QtCore.QXmlStreamReader.Error",
        "QXmlStreamReader::Error");
    if (!SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
        &Sbk_QXmlStreamReader_Type, "NoError", (long) QXmlStreamReader::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
        &Sbk_QXmlStreamReader_Type, "UnexpectedElementError", (long) QXmlStreamReader::UnexpectedElementError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
        &Sbk_QXmlStreamReader_Type, "CustomError", (long) QXmlStreamReader::CustomError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
        &Sbk_QXmlStreamReader_Type, "NotWellFormedError", (long) QXmlStreamReader::NotWellFormedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
        &Sbk_QXmlStreamReader_Type, "PrematureEndOfDocumentError", (long) QXmlStreamReader::PrematureEndOfDocumentError))
        return ;
    // Register converter for enum 'QXmlStreamReader::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX],
            QXmlStreamReader_Error_CppToPython_QXmlStreamReader_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlStreamReader_Error_PythonToCpp_QXmlStreamReader_Error,
            is_QXmlStreamReader_Error_PythonToCpp_QXmlStreamReader_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMREADER_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlStreamReader::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.


    qRegisterMetaType< ::QXmlStreamReader::TokenType >("QXmlStreamReader::TokenType");
    qRegisterMetaType< ::QXmlStreamReader::ReadElementTextBehaviour >("QXmlStreamReader::ReadElementTextBehaviour");
    qRegisterMetaType< ::QXmlStreamReader::Error >("QXmlStreamReader::Error");
}
