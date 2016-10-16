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

#include "qurl_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <QStringList>
#include <qbytearray.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QUrl_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QUrl >()))
        return -1;

    ::QUrl* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QUrl", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QUrl()
    // 1: QUrl(QString)
    // 2: QUrl(QString,QUrl::ParsingMode)
    // 3: QUrl(QUrl)
    if (numArgs == 0) {
        overloadId = 0; // QUrl()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QUrl(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX]), (pyArgs[1])))) {
            overloadId = 2; // QUrl(QString,QUrl::ParsingMode)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 3; // QUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrl_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QUrl()
        {

            if (!PyErr_Occurred()) {
                // QUrl()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrl();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QUrl(const QString & url)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QUrl(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrl(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QUrl(const QString & url, QUrl::ParsingMode mode)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QUrl::ParsingMode cppArg1 = ((::QUrl::ParsingMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QUrl(QString,QUrl::ParsingMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrl(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QUrl(const QUrl & copy)
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
                // QUrl(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUrl(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QUrl >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QUrl_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QUrl_Init_TypeError:
        const char* overloads[] = {"", "unicode", "unicode, PySide.QtCore.QUrl.ParsingMode", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl", overloads);
        return -1;
}

static PyObject* Sbk_QUrlFunc___reduce__(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(s))", PyObject_Type(self), qPrintable(cppSelf->toString()));
            // TEMPLATE - reduce_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc___repr__(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s('%s')", ((PyObject*)self)->ob_type->tp_name, qPrintable(cppSelf->toString()));
            pyResult = Shiboken::String::fromCString(qPrintable(format));
            // TEMPLATE - repr_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc_addEncodedQueryItem(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addEncodedQueryItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addEncodedQueryItem(QByteArray,QByteArray)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 0; // addEncodedQueryItem(QByteArray,QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_addEncodedQueryItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = ::QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // addEncodedQueryItem(QByteArray,QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addEncodedQueryItem(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_addEncodedQueryItem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.addEncodedQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_addQueryItem(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addQueryItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addQueryItem(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // addQueryItem(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_addQueryItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addQueryItem(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addQueryItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_addQueryItem_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.addQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_allEncodedQueryItemValues(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: allEncodedQueryItemValues(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // allEncodedQueryItemValues(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_allEncodedQueryItemValues_TypeError;

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
            // allEncodedQueryItemValues(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QUrl*>(cppSelf)->allEncodedQueryItemValues(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_allEncodedQueryItemValues_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.allEncodedQueryItemValues", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_allQueryItemValues(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: allQueryItemValues(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // allQueryItemValues(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_allQueryItemValues_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // allQueryItemValues(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QUrl*>(cppSelf)->allQueryItemValues(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_allQueryItemValues_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.allQueryItemValues", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_authority(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // authority()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->authority();
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

static PyObject* Sbk_QUrlFunc_clear(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QUrlFunc_encodedFragment(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedFragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedFragment();
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

static PyObject* Sbk_QUrlFunc_encodedHost(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedHost()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedHost();
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

static PyObject* Sbk_QUrlFunc_encodedPassword(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedPassword()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedPassword();
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

static PyObject* Sbk_QUrlFunc_encodedPath(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedPath();
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

static PyObject* Sbk_QUrlFunc_encodedQuery(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedQuery();
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

static PyObject* Sbk_QUrlFunc_encodedQueryItemValue(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: encodedQueryItemValue(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // encodedQueryItemValue(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_encodedQueryItemValue_TypeError;

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
            // encodedQueryItemValue(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedQueryItemValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_encodedQueryItemValue_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.encodedQueryItemValue", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_encodedQueryItems(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedQueryItems()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPair<QByteArray, QByteArray > > cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedQueryItems();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc_encodedUserName(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encodedUserName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->encodedUserName();
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

static PyObject* Sbk_QUrlFunc_errorString(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->errorString();
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

static PyObject* Sbk_QUrlFunc_fragment(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->fragment();
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

static PyObject* Sbk_QUrlFunc_fromAce(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromAce(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromAce(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromAce_TypeError;

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
            // fromAce(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QUrl::fromAce(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromAce_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.fromAce", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_fromEncoded(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fromEncoded", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromEncoded(QByteArray)
    // 1: fromEncoded(QByteArray,QUrl::ParsingMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromEncoded(QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // fromEncoded(QByteArray,QUrl::ParsingMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromEncoded_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromEncoded(const QByteArray & url)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // fromEncoded(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QUrl cppResult = ::QUrl::fromEncoded(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
            }
            break;
        }
        case 1: // fromEncoded(const QByteArray & url, QUrl::ParsingMode mode)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QUrl::ParsingMode cppArg1 = ((::QUrl::ParsingMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromEncoded(QByteArray,QUrl::ParsingMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QUrl cppResult = ::QUrl::fromEncoded(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromEncoded_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray, PySide.QtCore.QUrl.ParsingMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.fromEncoded", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_fromLocalFile(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromLocalFile(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromLocalFile(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromLocalFile_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromLocalFile(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = ::QUrl::fromLocalFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromLocalFile_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.fromLocalFile", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_fromPercentEncoding(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromPercentEncoding(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromPercentEncoding(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromPercentEncoding_TypeError;

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
            // fromPercentEncoding(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QUrl::fromPercentEncoding(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromPercentEncoding_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.fromPercentEncoding", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_fromPunycode(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromPunycode(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromPunycode(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromPunycode_TypeError;

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
            // fromPunycode(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QUrl::fromPunycode(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromPunycode_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.fromPunycode", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_fromUserInput(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromUserInput(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromUserInput(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_fromUserInput_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromUserInput(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = ::QUrl::fromUserInput(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_fromUserInput_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.fromUserInput", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_hasEncodedQueryItem(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasEncodedQueryItem(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // hasEncodedQueryItem(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_hasEncodedQueryItem_TypeError;

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
            // hasEncodedQueryItem(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->hasEncodedQueryItem(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_hasEncodedQueryItem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.hasEncodedQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_hasFragment(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->hasFragment();
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

static PyObject* Sbk_QUrlFunc_hasQuery(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->hasQuery();
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

static PyObject* Sbk_QUrlFunc_hasQueryItem(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasQueryItem(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasQueryItem(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_hasQueryItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasQueryItem(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->hasQueryItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_hasQueryItem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.hasQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_host(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // host()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->host();
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

static PyObject* Sbk_QUrlFunc_idnWhitelist(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // idnWhitelist()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QUrl::idnWhitelist();
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

static PyObject* Sbk_QUrlFunc_isEmpty(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QUrlFunc_isLocalFile(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLocalFile()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->isLocalFile();
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

static PyObject* Sbk_QUrlFunc_isParentOf(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isParentOf(QUrl)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // isParentOf(QUrl)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_isParentOf_TypeError;

    // Call function/method
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
            // isParentOf(QUrl)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->isParentOf(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_isParentOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.isParentOf", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_isRelative(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRelative()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->isRelative();
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

static PyObject* Sbk_QUrlFunc_isValid(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUrl*>(cppSelf)->isValid();
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

static PyObject* Sbk_QUrlFunc_password(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // password()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->password();
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

static PyObject* Sbk_QUrlFunc_path(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // path()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->path();
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

static PyObject* Sbk_QUrlFunc_port(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "port", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: port()const
    // 1: port(int)const
    if (numArgs == 0) {
        overloadId = 0; // port()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // port(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_port_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // port() const
        {

            if (!PyErr_Occurred()) {
                // port()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QUrl*>(cppSelf)->port();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // port(int defaultPort) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // port(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QUrl*>(cppSelf)->port(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_port_TypeError:
        const char* overloads[] = {"", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.port", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_queryItemValue(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: queryItemValue(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // queryItemValue(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_queryItemValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // queryItemValue(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->queryItemValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_queryItemValue_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.queryItemValue", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_queryItems(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryItems()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPair<QString, QString > > cppResult = const_cast<const ::QUrl*>(cppSelf)->queryItems();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QSTRING_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc_queryPairDelimiter(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryPairDelimiter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            char cppResult = const_cast<const ::QUrl*>(cppSelf)->queryPairDelimiter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc_queryValueDelimiter(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queryValueDelimiter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            char cppResult = const_cast<const ::QUrl*>(cppSelf)->queryValueDelimiter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUrlFunc_removeAllEncodedQueryItems(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAllEncodedQueryItems(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // removeAllEncodedQueryItems(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_removeAllEncodedQueryItems_TypeError;

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
            // removeAllEncodedQueryItems(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAllEncodedQueryItems(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_removeAllEncodedQueryItems_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.removeAllEncodedQueryItems", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_removeAllQueryItems(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAllQueryItems(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeAllQueryItems(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_removeAllQueryItems_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAllQueryItems(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAllQueryItems(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_removeAllQueryItems_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.removeAllQueryItems", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_removeEncodedQueryItem(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeEncodedQueryItem(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // removeEncodedQueryItem(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_removeEncodedQueryItem_TypeError;

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
            // removeEncodedQueryItem(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeEncodedQueryItem(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_removeEncodedQueryItem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.removeEncodedQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_removeQueryItem(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeQueryItem(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeQueryItem(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_removeQueryItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeQueryItem(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeQueryItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_removeQueryItem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.removeQueryItem", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_resolved(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resolved(QUrl)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // resolved(QUrl)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_resolved_TypeError;

    // Call function/method
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
            // resolved(QUrl)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QUrl*>(cppSelf)->resolved(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_resolved_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.resolved", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_scheme(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scheme()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->scheme();
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

static PyObject* Sbk_QUrlFunc_setAuthority(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAuthority(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setAuthority(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setAuthority_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAuthority(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAuthority(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setAuthority_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setAuthority", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedFragment(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedFragment(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedFragment(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedFragment_TypeError;

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
            // setEncodedFragment(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedFragment(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedFragment_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedFragment", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedHost(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedHost(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedHost(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedHost_TypeError;

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
            // setEncodedHost(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedHost(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedHost_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedHost", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedPassword(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedPassword(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedPassword(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedPassword_TypeError;

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
            // setEncodedPassword(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedPassword(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedPassword_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedPassword", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedPath(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedPath(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedPath(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedPath_TypeError;

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
            // setEncodedPath(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedPath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedPath_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedPath", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedQuery(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedQuery(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedQuery(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedQuery_TypeError;

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
            // setEncodedQuery(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedQuery(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedQuery", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedQueryItems(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedQueryItems(QList<QPair<QByteArray,QByteArray> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedQueryItems(QList<QPair<QByteArray,QByteArray> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedQueryItems_TypeError;

    // Call function/method
    {
        ::QList<QPair<QByteArray, QByteArray > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEncodedQueryItems(QList<QPair<QByteArray,QByteArray> >)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedQueryItems(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedQueryItems_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedQueryItems", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedUrl(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setEncodedUrl", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setEncodedUrl(QByteArray)
    // 1: setEncodedUrl(QByteArray,QUrl::ParsingMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setEncodedUrl(QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // setEncodedUrl(QByteArray,QUrl::ParsingMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedUrl_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setEncodedUrl(const QByteArray & url)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setEncodedUrl(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEncodedUrl(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setEncodedUrl(const QByteArray & url, QUrl::ParsingMode mode)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QUrl::ParsingMode cppArg1 = ((::QUrl::ParsingMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setEncodedUrl(QByteArray,QUrl::ParsingMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEncodedUrl(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray, PySide.QtCore.QUrl.ParsingMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.setEncodedUrl", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setEncodedUserName(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEncodedUserName(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setEncodedUserName(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setEncodedUserName_TypeError;

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
            // setEncodedUserName(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEncodedUserName(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setEncodedUserName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setEncodedUserName", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setFragment(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFragment(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFragment(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setFragment_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFragment(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFragment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setFragment_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setFragment", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setHost(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHost(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHost(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setHost_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHost(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHost(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setHost_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setHost", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setIdnWhitelist(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIdnWhitelist(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setIdnWhitelist(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setIdnWhitelist_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIdnWhitelist(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QUrl::setIdnWhitelist(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setIdnWhitelist_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setIdnWhitelist", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setPassword(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPassword(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPassword(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setPassword_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPassword(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPassword(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setPassword_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setPassword", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setPath(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setPath", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setPort(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPort(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPort(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setPort_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPort(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setPort_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setPort", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setQueryDelimiters(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setQueryDelimiters", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setQueryDelimiters(char,char)
    if (numArgs == 2
        && SbkChar_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[0])))
        && SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
        overloadId = 0; // setQueryDelimiters(char,char)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setQueryDelimiters_TypeError;

    // Call function/method
    {
        char cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        char cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setQueryDelimiters(char,char)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setQueryDelimiters(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setQueryDelimiters_TypeError:
        const char* overloads[] = {"char, char", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.setQueryDelimiters", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setQueryItems(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQueryItems(QList<QPair<QString,QString> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QPAIR_QSTRING_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setQueryItems(QList<QPair<QString,QString> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setQueryItems_TypeError;

    // Call function/method
    {
        ::QList<QPair<QString, QString > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setQueryItems(QList<QPair<QString,QString> >)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setQueryItems(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setQueryItems_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setQueryItems", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setScheme(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScheme(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setScheme(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setScheme_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScheme(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScheme(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setScheme_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setScheme", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setUrl(PyObject* self, PyObject* args)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUrl", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUrl(QString)
    // 1: setUrl(QString,QUrl::ParsingMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setUrl(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // setUrl(QString,QUrl::ParsingMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setUrl_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setUrl(const QString & url)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setUrl(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUrl(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setUrl(const QString & url, QUrl::ParsingMode mode)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QUrl::ParsingMode cppArg1 = ((::QUrl::ParsingMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setUrl(QString,QUrl::ParsingMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setUrl(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setUrl_TypeError:
        const char* overloads[] = {"unicode", "unicode, PySide.QtCore.QUrl.ParsingMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setUserInfo(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserInfo(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setUserInfo(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setUserInfo_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUserInfo(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUserInfo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setUserInfo_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setUserInfo", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_setUserName(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setUserName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_setUserName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUserName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUserName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_setUserName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.setUserName", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QUrl&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // swap(QUrl&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_swap_TypeError;

    // Call function/method
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
            // swap(QUrl&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QUrlFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.swap", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_toAce(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toAce(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toAce(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_toAce_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toAce(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QUrl::toAce(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_toAce_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.toAce", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_toEncoded(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toEncoded(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toEncoded", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toEncoded(QFlags<QUrl::FormattingOption>)const
    if (numArgs == 0) {
        overloadId = 0; // toEncoded(QFlags<QUrl::FormattingOption>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), (pyArgs[0])))) {
        overloadId = 0; // toEncoded(QFlags<QUrl::FormattingOption>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_toEncoded_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toEncoded(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), (pyArgs[0]))))
                    goto Sbk_QUrlFunc_toEncoded_TypeError;
            }
        }
        ::QFlags<QUrl::FormattingOption> cppArg0 = QUrl::None;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toEncoded(QFlags<QUrl::FormattingOption>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUrl*>(cppSelf)->toEncoded(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_toEncoded_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl.FormattingOptions = QUrl.None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.toEncoded", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_toLocalFile(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toLocalFile()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->toLocalFile();
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

static PyObject* Sbk_QUrlFunc_toPercentEncoding(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toPercentEncoding(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toPercentEncoding(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:toPercentEncoding", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: toPercentEncoding(QString,QByteArray,QByteArray)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toPercentEncoding(QString,QByteArray,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // toPercentEncoding(QString,QByteArray,QByteArray)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2])))) {
                overloadId = 0; // toPercentEncoding(QString,QByteArray,QByteArray)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_toPercentEncoding_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "exclude");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toPercentEncoding(): got multiple values for keyword argument 'exclude'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                    goto Sbk_QUrlFunc_toPercentEncoding_TypeError;
            }
            value = PyDict_GetItemString(kwds, "include");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toPercentEncoding(): got multiple values for keyword argument 'include'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2]))))
                    goto Sbk_QUrlFunc_toPercentEncoding_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QByteArray cppArg2_local = QByteArray();
        ::QByteArray* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // toPercentEncoding(QString,QByteArray,QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QUrl::toPercentEncoding(cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_toPercentEncoding_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QByteArray = QByteArray(), PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.toPercentEncoding", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_toPunycode(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toPunycode(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toPunycode(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_toPunycode_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toPunycode(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QUrl::toPunycode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_toPunycode_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUrl.toPunycode", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toString(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toString", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toString(QFlags<QUrl::FormattingOption>)const
    if (numArgs == 0) {
        overloadId = 0; // toString(QFlags<QUrl::FormattingOption>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), (pyArgs[0])))) {
        overloadId = 0; // toString(QFlags<QUrl::FormattingOption>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUrlFunc_toString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QUrl.toString(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), (pyArgs[0]))))
                    goto Sbk_QUrlFunc_toString_TypeError;
            }
        }
        ::QFlags<QUrl::FormattingOption> cppArg0 = QUrl::None;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toString(QFlags<QUrl::FormattingOption>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->toString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUrlFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl.FormattingOptions = QUrl.None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUrl.toString", overloads);
        return 0;
}

static PyObject* Sbk_QUrlFunc_topLevelDomain(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topLevelDomain()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->topLevelDomain();
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

static PyObject* Sbk_QUrlFunc_userInfo(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userInfo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->userInfo();
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

static PyObject* Sbk_QUrlFunc_userName(PyObject* self)
{
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUrl*>(cppSelf)->userName();
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

static PyObject* Sbk_QUrl___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUrl& cppSelf = *(((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QUrl_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QUrlFunc___reduce__, METH_NOARGS},
    {"addEncodedQueryItem", (PyCFunction)Sbk_QUrlFunc_addEncodedQueryItem, METH_VARARGS},
    {"addQueryItem", (PyCFunction)Sbk_QUrlFunc_addQueryItem, METH_VARARGS},
    {"allEncodedQueryItemValues", (PyCFunction)Sbk_QUrlFunc_allEncodedQueryItemValues, METH_O},
    {"allQueryItemValues", (PyCFunction)Sbk_QUrlFunc_allQueryItemValues, METH_O},
    {"authority", (PyCFunction)Sbk_QUrlFunc_authority, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QUrlFunc_clear, METH_NOARGS},
    {"encodedFragment", (PyCFunction)Sbk_QUrlFunc_encodedFragment, METH_NOARGS},
    {"encodedHost", (PyCFunction)Sbk_QUrlFunc_encodedHost, METH_NOARGS},
    {"encodedPassword", (PyCFunction)Sbk_QUrlFunc_encodedPassword, METH_NOARGS},
    {"encodedPath", (PyCFunction)Sbk_QUrlFunc_encodedPath, METH_NOARGS},
    {"encodedQuery", (PyCFunction)Sbk_QUrlFunc_encodedQuery, METH_NOARGS},
    {"encodedQueryItemValue", (PyCFunction)Sbk_QUrlFunc_encodedQueryItemValue, METH_O},
    {"encodedQueryItems", (PyCFunction)Sbk_QUrlFunc_encodedQueryItems, METH_NOARGS},
    {"encodedUserName", (PyCFunction)Sbk_QUrlFunc_encodedUserName, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QUrlFunc_errorString, METH_NOARGS},
    {"fragment", (PyCFunction)Sbk_QUrlFunc_fragment, METH_NOARGS},
    {"fromAce", (PyCFunction)Sbk_QUrlFunc_fromAce, METH_O|METH_STATIC},
    {"fromEncoded", (PyCFunction)Sbk_QUrlFunc_fromEncoded, METH_VARARGS|METH_STATIC},
    {"fromLocalFile", (PyCFunction)Sbk_QUrlFunc_fromLocalFile, METH_O|METH_STATIC},
    {"fromPercentEncoding", (PyCFunction)Sbk_QUrlFunc_fromPercentEncoding, METH_O|METH_STATIC},
    {"fromPunycode", (PyCFunction)Sbk_QUrlFunc_fromPunycode, METH_O|METH_STATIC},
    {"fromUserInput", (PyCFunction)Sbk_QUrlFunc_fromUserInput, METH_O|METH_STATIC},
    {"hasEncodedQueryItem", (PyCFunction)Sbk_QUrlFunc_hasEncodedQueryItem, METH_O},
    {"hasFragment", (PyCFunction)Sbk_QUrlFunc_hasFragment, METH_NOARGS},
    {"hasQuery", (PyCFunction)Sbk_QUrlFunc_hasQuery, METH_NOARGS},
    {"hasQueryItem", (PyCFunction)Sbk_QUrlFunc_hasQueryItem, METH_O},
    {"host", (PyCFunction)Sbk_QUrlFunc_host, METH_NOARGS},
    {"idnWhitelist", (PyCFunction)Sbk_QUrlFunc_idnWhitelist, METH_NOARGS|METH_STATIC},
    {"isEmpty", (PyCFunction)Sbk_QUrlFunc_isEmpty, METH_NOARGS},
    {"isLocalFile", (PyCFunction)Sbk_QUrlFunc_isLocalFile, METH_NOARGS},
    {"isParentOf", (PyCFunction)Sbk_QUrlFunc_isParentOf, METH_O},
    {"isRelative", (PyCFunction)Sbk_QUrlFunc_isRelative, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QUrlFunc_isValid, METH_NOARGS},
    {"password", (PyCFunction)Sbk_QUrlFunc_password, METH_NOARGS},
    {"path", (PyCFunction)Sbk_QUrlFunc_path, METH_NOARGS},
    {"port", (PyCFunction)Sbk_QUrlFunc_port, METH_VARARGS},
    {"queryItemValue", (PyCFunction)Sbk_QUrlFunc_queryItemValue, METH_O},
    {"queryItems", (PyCFunction)Sbk_QUrlFunc_queryItems, METH_NOARGS},
    {"queryPairDelimiter", (PyCFunction)Sbk_QUrlFunc_queryPairDelimiter, METH_NOARGS},
    {"queryValueDelimiter", (PyCFunction)Sbk_QUrlFunc_queryValueDelimiter, METH_NOARGS},
    {"removeAllEncodedQueryItems", (PyCFunction)Sbk_QUrlFunc_removeAllEncodedQueryItems, METH_O},
    {"removeAllQueryItems", (PyCFunction)Sbk_QUrlFunc_removeAllQueryItems, METH_O},
    {"removeEncodedQueryItem", (PyCFunction)Sbk_QUrlFunc_removeEncodedQueryItem, METH_O},
    {"removeQueryItem", (PyCFunction)Sbk_QUrlFunc_removeQueryItem, METH_O},
    {"resolved", (PyCFunction)Sbk_QUrlFunc_resolved, METH_O},
    {"scheme", (PyCFunction)Sbk_QUrlFunc_scheme, METH_NOARGS},
    {"setAuthority", (PyCFunction)Sbk_QUrlFunc_setAuthority, METH_O},
    {"setEncodedFragment", (PyCFunction)Sbk_QUrlFunc_setEncodedFragment, METH_O},
    {"setEncodedHost", (PyCFunction)Sbk_QUrlFunc_setEncodedHost, METH_O},
    {"setEncodedPassword", (PyCFunction)Sbk_QUrlFunc_setEncodedPassword, METH_O},
    {"setEncodedPath", (PyCFunction)Sbk_QUrlFunc_setEncodedPath, METH_O},
    {"setEncodedQuery", (PyCFunction)Sbk_QUrlFunc_setEncodedQuery, METH_O},
    {"setEncodedQueryItems", (PyCFunction)Sbk_QUrlFunc_setEncodedQueryItems, METH_O},
    {"setEncodedUrl", (PyCFunction)Sbk_QUrlFunc_setEncodedUrl, METH_VARARGS},
    {"setEncodedUserName", (PyCFunction)Sbk_QUrlFunc_setEncodedUserName, METH_O},
    {"setFragment", (PyCFunction)Sbk_QUrlFunc_setFragment, METH_O},
    {"setHost", (PyCFunction)Sbk_QUrlFunc_setHost, METH_O},
    {"setIdnWhitelist", (PyCFunction)Sbk_QUrlFunc_setIdnWhitelist, METH_O|METH_STATIC},
    {"setPassword", (PyCFunction)Sbk_QUrlFunc_setPassword, METH_O},
    {"setPath", (PyCFunction)Sbk_QUrlFunc_setPath, METH_O},
    {"setPort", (PyCFunction)Sbk_QUrlFunc_setPort, METH_O},
    {"setQueryDelimiters", (PyCFunction)Sbk_QUrlFunc_setQueryDelimiters, METH_VARARGS},
    {"setQueryItems", (PyCFunction)Sbk_QUrlFunc_setQueryItems, METH_O},
    {"setScheme", (PyCFunction)Sbk_QUrlFunc_setScheme, METH_O},
    {"setUrl", (PyCFunction)Sbk_QUrlFunc_setUrl, METH_VARARGS},
    {"setUserInfo", (PyCFunction)Sbk_QUrlFunc_setUserInfo, METH_O},
    {"setUserName", (PyCFunction)Sbk_QUrlFunc_setUserName, METH_O},
    {"swap", (PyCFunction)Sbk_QUrlFunc_swap, METH_O},
    {"toAce", (PyCFunction)Sbk_QUrlFunc_toAce, METH_O|METH_STATIC},
    {"toEncoded", (PyCFunction)Sbk_QUrlFunc_toEncoded, METH_VARARGS|METH_KEYWORDS},
    {"toLocalFile", (PyCFunction)Sbk_QUrlFunc_toLocalFile, METH_NOARGS},
    {"toPercentEncoding", (PyCFunction)Sbk_QUrlFunc_toPercentEncoding, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"toPunycode", (PyCFunction)Sbk_QUrlFunc_toPunycode, METH_O|METH_STATIC},
    {"toString", (PyCFunction)Sbk_QUrlFunc_toString, METH_VARARGS|METH_KEYWORDS},
    {"topLevelDomain", (PyCFunction)Sbk_QUrlFunc_topLevelDomain, METH_NOARGS},
    {"userInfo", (PyCFunction)Sbk_QUrlFunc_userInfo, METH_NOARGS},
    {"userName", (PyCFunction)Sbk_QUrlFunc_userName, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QUrl___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QUrl_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUrl& cppSelf = *(((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
                // operator!=(const QUrl & url) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUrl cppArg0_local = ::QUrl();
                ::QUrl* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
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
        case Py_LT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
                // operator<(const QUrl & url) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUrl cppArg0_local = ::QUrl();
                ::QUrl* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QUrl_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
                // operator==(const QUrl & url) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUrl cppArg0_local = ::QUrl();
                ::QUrl* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
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
            goto Sbk_QUrl_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QUrl_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QUrl_HashFunc(PyObject* self) {
    ::QUrl* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)self));
    return PySide::hash(*cppSelf);
}

static int Sbk_QUrl_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QUrl_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QUrl_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QUrl",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QUrlFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QUrl_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QUrl_traverse,
    /*tp_clear*/            Sbk_QUrl_clear,
    /*tp_richcompare*/      Sbk_QUrl_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QUrl_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QUrl_Init,
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

PyObject* SbkPySide_QtCore_QUrl_FormattingOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QUrl::FormattingOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QUrl::FormattingOptions)PyLong_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QUrl::FormattingOptions)PyInt_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QUrl_FormattingOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QUrl::FormattingOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QUrl::FormattingOptions)PyLong_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QUrl::FormattingOptions)PyInt_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QUrl_FormattingOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QUrl::FormattingOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QUrl::FormattingOptions)PyLong_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QUrl::FormattingOptions)PyInt_AsLong(self);
    cppArg = (QUrl::FormattingOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QUrl_FormattingOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QUrl::FormattingOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), self, &cppSelf);
    ::QUrl::FormattingOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QUrl_FormattingOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QUrl_FormattingOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QUrl_FormattingOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QUrl_FormattingOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QUrl_FormattingOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QUrl_FormattingOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QUrl_FormattingOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QUrl_FormattingOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QUrl_FormattingOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QUrl_FormattingOption_long,
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
static void QUrl_ParsingMode_PythonToCpp_QUrl_ParsingMode(PyObject* pyIn, void* cppOut) {
    *((::QUrl::ParsingMode*)cppOut) = (::QUrl::ParsingMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QUrl_ParsingMode_PythonToCpp_QUrl_ParsingMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX]))
        return QUrl_ParsingMode_PythonToCpp_QUrl_ParsingMode;
    return 0;
}
static PyObject* QUrl_ParsingMode_CppToPython_QUrl_ParsingMode(const void* cppIn) {
    int castCppIn = *((::QUrl::ParsingMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX], castCppIn);

}

static void QUrl_FormattingOption_PythonToCpp_QUrl_FormattingOption(PyObject* pyIn, void* cppOut) {
    *((::QUrl::FormattingOption*)cppOut) = (::QUrl::FormattingOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QUrl_FormattingOption_PythonToCpp_QUrl_FormattingOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX]))
        return QUrl_FormattingOption_PythonToCpp_QUrl_FormattingOption;
    return 0;
}
static PyObject* QUrl_FormattingOption_CppToPython_QUrl_FormattingOption(const void* cppIn) {
    int castCppIn = *((::QUrl::FormattingOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX], castCppIn);

}

static void QFlags_QUrl_FormattingOption__PythonToCpp_QFlags_QUrl_FormattingOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QUrl::FormattingOption>*)cppOut) = ::QFlags<QUrl::FormattingOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QUrl_FormattingOption__PythonToCpp_QFlags_QUrl_FormattingOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]))
        return QFlags_QUrl_FormattingOption__PythonToCpp_QFlags_QUrl_FormattingOption_;
    return 0;
}
static PyObject* QFlags_QUrl_FormattingOption__CppToPython_QFlags_QUrl_FormattingOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QUrl::FormattingOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]));

}

static void QUrl_FormattingOption_PythonToCpp_QFlags_QUrl_FormattingOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QUrl::FormattingOption>*)cppOut) = ::QFlags<QUrl::FormattingOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QUrl_FormattingOption_PythonToCpp_QFlags_QUrl_FormattingOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX]))
        return QUrl_FormattingOption_PythonToCpp_QFlags_QUrl_FormattingOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QUrl_FormattingOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QUrl::FormattingOption>*)cppOut) = ::QFlags<QUrl::FormattingOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QUrl_FormattingOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QUrl_FormattingOption_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QUrl_PythonToCpp_QUrl_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QUrl_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QUrl_PythonToCpp_QUrl_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUrl_Type))
        return QUrl_PythonToCpp_QUrl_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QUrl_PTR_CppToPython_QUrl(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QUrl*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QUrl_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QUrl_COPY_CppToPython_QUrl(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QUrl_Type, new ::QUrl(*((::QUrl*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QUrl_PythonToCpp_QUrl_COPY(PyObject* pyIn, void* cppOut) {
    *((::QUrl*)cppOut) = *((::QUrl*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QURL_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QUrl_PythonToCpp_QUrl_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUrl_Type))
        return QUrl_PythonToCpp_QUrl_COPY;
    return 0;
}

// Implicit conversions.
static void constQStringREF_PythonToCpp_QUrl(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QUrl*)cppOut) = ::QUrl(cppIn);
}
static PythonToCppFunc is_constQStringREF_PythonToCpp_QUrl_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return constQStringREF_PythonToCpp_QUrl;
    return 0;
}

void init_QUrl(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QURL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QUrl_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QUrl", "QUrl",
        &Sbk_QUrl_Type, &Shiboken::callCppDestructor< ::QUrl >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QUrl_Type,
        QUrl_PythonToCpp_QUrl_PTR,
        is_QUrl_PythonToCpp_QUrl_PTR_Convertible,
        QUrl_PTR_CppToPython_QUrl,
        QUrl_COPY_CppToPython_QUrl);

    Shiboken::Conversions::registerConverterName(converter, "QUrl");
    Shiboken::Conversions::registerConverterName(converter, "QUrl*");
    Shiboken::Conversions::registerConverterName(converter, "QUrl&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QUrl).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QUrl_PythonToCpp_QUrl_COPY,
        is_QUrl_PythonToCpp_QUrl_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStringREF_PythonToCpp_QUrl,
        is_constQStringREF_PythonToCpp_QUrl_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ParsingMode'.
    SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QUrl_Type,
        "ParsingMode",
        "PySide.QtCore.QUrl.ParsingMode",
        "QUrl::ParsingMode");
    if (!SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX],
        &Sbk_QUrl_Type, "TolerantMode", (long) QUrl::TolerantMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX],
        &Sbk_QUrl_Type, "StrictMode", (long) QUrl::StrictMode))
        return ;
    // Register converter for enum 'QUrl::ParsingMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX],
            QUrl_ParsingMode_CppToPython_QUrl_ParsingMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUrl_ParsingMode_PythonToCpp_QUrl_ParsingMode,
            is_QUrl_ParsingMode_PythonToCpp_QUrl_ParsingMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QURL_PARSINGMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QUrl::ParsingMode");
        Shiboken::Conversions::registerConverterName(converter, "ParsingMode");
    }
    // End of 'ParsingMode' enum.

    // Initialization of enum 'FormattingOption'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX] = PySide::QFlags::create("FormattingOptions", &SbkPySide_QtCore_QUrl_FormattingOption_as_number);
    SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QUrl_Type,
        "FormattingOption",
        "PySide.QtCore.QUrl.FormattingOption",
        "QUrl::FormattingOption",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "None", (long) QUrl::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemoveScheme", (long) QUrl::RemoveScheme))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemovePassword", (long) QUrl::RemovePassword))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemoveUserInfo", (long) QUrl::RemoveUserInfo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemovePort", (long) QUrl::RemovePort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemoveAuthority", (long) QUrl::RemoveAuthority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemovePath", (long) QUrl::RemovePath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemoveQuery", (long) QUrl::RemoveQuery))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "RemoveFragment", (long) QUrl::RemoveFragment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
        &Sbk_QUrl_Type, "StripTrailingSlash", (long) QUrl::StripTrailingSlash))
        return ;
    // Register converter for enum 'QUrl::FormattingOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX],
            QUrl_FormattingOption_CppToPython_QUrl_FormattingOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUrl_FormattingOption_PythonToCpp_QUrl_FormattingOption,
            is_QUrl_FormattingOption_PythonToCpp_QUrl_FormattingOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QURL_FORMATTINGOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QUrl::FormattingOption");
        Shiboken::Conversions::registerConverterName(converter, "FormattingOption");
    }
    // Register converter for flag 'QFlags<QUrl::FormattingOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX],
            QFlags_QUrl_FormattingOption__CppToPython_QFlags_QUrl_FormattingOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUrl_FormattingOption_PythonToCpp_QFlags_QUrl_FormattingOption_,
            is_QUrl_FormattingOption_PythonToCpp_QFlags_QUrl_FormattingOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QUrl_FormattingOption__PythonToCpp_QFlags_QUrl_FormattingOption_,
            is_QFlags_QUrl_FormattingOption__PythonToCpp_QFlags_QUrl_FormattingOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QUrl_FormattingOption_,
            is_number_PythonToCpp_QFlags_QUrl_FormattingOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QURL_FORMATTINGOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QUrl::FormattingOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FormattingOption>");
    }
    // End of 'FormattingOption' enum/flags.


    qRegisterMetaType< ::QUrl >("QUrl");
    qRegisterMetaType< ::QUrl::ParsingMode >("QUrl::ParsingMode");
    qRegisterMetaType< ::QUrl::FormattingOption >("QUrl::FormattingOption");
    qRegisterMetaType< ::QUrl::FormattingOptions >("QUrl::FormattingOptions");
}
