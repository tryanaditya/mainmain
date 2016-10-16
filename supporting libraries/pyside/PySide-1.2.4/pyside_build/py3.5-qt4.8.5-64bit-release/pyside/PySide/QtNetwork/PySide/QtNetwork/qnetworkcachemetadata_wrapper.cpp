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
#include "pyside_qtnetwork_python.h"

#include "qnetworkcachemetadata_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <pysideconversions.h>
#include <qabstractnetworkcache.h>
#include <qbytearray.h>
#include <qdatastream.h>
#include <qdatetime.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkCacheMetaData_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkCacheMetaData >()))
        return -1;

    ::QNetworkCacheMetaData* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QNetworkCacheMetaData", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkCacheMetaData()
    // 1: QNetworkCacheMetaData(QNetworkCacheMetaData)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkCacheMetaData()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkCacheMetaData(QNetworkCacheMetaData)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaData_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkCacheMetaData()
        {

            if (!PyErr_Occurred()) {
                // QNetworkCacheMetaData()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkCacheMetaData();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkCacheMetaData(const QNetworkCacheMetaData & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkCacheMetaData cppArg0_local = ::QNetworkCacheMetaData();
            ::QNetworkCacheMetaData* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkCacheMetaData(QNetworkCacheMetaData)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkCacheMetaData(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkCacheMetaData >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkCacheMetaData_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkCacheMetaData_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkCacheMetaData", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkCacheMetaData", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_attributes(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHash<QNetworkRequest::Attribute, QVariant > cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->attributes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QNETWORKREQUEST_ATTRIBUTE_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_expirationDate(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expirationDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->expirationDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_isValid(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->isValid();
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

static PyObject* Sbk_QNetworkCacheMetaDataFunc_lastModified(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastModified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->lastModified();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_rawHeaders(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawHeaders()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPair<QByteArray, QByteArray > > cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->rawHeaders();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_saveToDisk(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // saveToDisk()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->saveToDisk();
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

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setAttributes(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAttributes(QHash<QNetworkRequest::Attribute,QVariant>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QNETWORKREQUEST_ATTRIBUTE_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setAttributes(QHash<QNetworkRequest::Attribute,QVariant>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setAttributes_TypeError;

    // Call function/method
    {
        ::QHash<QNetworkRequest::Attribute, QVariant > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAttributes(QHash<QNetworkRequest::Attribute,QVariant>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttributes(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setAttributes_TypeError:
        const char* overloads[] = {"dict", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setAttributes", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setExpirationDate(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setExpirationDate(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setExpirationDate(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setExpirationDate_TypeError;

    // Call function/method
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
            // setExpirationDate(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setExpirationDate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setExpirationDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setExpirationDate", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setLastModified(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastModified(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setLastModified(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setLastModified_TypeError;

    // Call function/method
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
            // setLastModified(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastModified(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setLastModified_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setLastModified", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setRawHeaders(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRawHeaders(QList<QPair<QByteArray,QByteArray> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setRawHeaders(QList<QPair<QByteArray,QByteArray> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setRawHeaders_TypeError;

    // Call function/method
    {
        ::QList<QPair<QByteArray, QByteArray > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRawHeaders(QList<QPair<QByteArray,QByteArray> >)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRawHeaders(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setRawHeaders_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setRawHeaders", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setSaveToDisk(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSaveToDisk(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSaveToDisk(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setSaveToDisk_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSaveToDisk(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSaveToDisk(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setSaveToDisk_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setSaveToDisk", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_setUrl(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc_setUrl_TypeError;

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
            // setUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCacheMetaDataFunc_setUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc_url(PyObject* self)
{
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QNetworkCacheMetaData*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkCacheMetaData___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkCacheMetaData& cppSelf = *(((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkCacheMetaData_methods[] = {
    {"attributes", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_attributes, METH_NOARGS},
    {"expirationDate", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_expirationDate, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_isValid, METH_NOARGS},
    {"lastModified", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_lastModified, METH_NOARGS},
    {"rawHeaders", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_rawHeaders, METH_NOARGS},
    {"saveToDisk", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_saveToDisk, METH_NOARGS},
    {"setAttributes", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setAttributes, METH_O},
    {"setExpirationDate", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setExpirationDate, METH_O},
    {"setLastModified", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setLastModified, METH_O},
    {"setRawHeaders", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setRawHeaders, METH_O},
    {"setSaveToDisk", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setSaveToDisk, METH_O},
    {"setUrl", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_setUrl, METH_O},
    {"url", (PyCFunction)Sbk_QNetworkCacheMetaDataFunc_url, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkCacheMetaData___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QNetworkCacheMetaDataFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QNetworkCacheMetaData)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QNetworkCacheMetaData)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QNetworkCacheMetaData) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkCacheMetaDataFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCacheMetaDataFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QNetworkCacheMetaData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QNetworkCacheMetaData&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QNetworkCacheMetaData&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCacheMetaDataFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QNetworkCacheMetaData&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkCacheMetaDataFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCacheMetaData.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QNetworkCacheMetaData_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkCacheMetaData& cppSelf = *(((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (pyArg)))) {
                // operator!=(const QNetworkCacheMetaData & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkCacheMetaData cppArg0_local = ::QNetworkCacheMetaData();
                ::QNetworkCacheMetaData* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (pyArg)))) {
                // operator==(const QNetworkCacheMetaData & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkCacheMetaData cppArg0_local = ::QNetworkCacheMetaData();
                ::QNetworkCacheMetaData* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], pythonToCpp))
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
            goto Sbk_QNetworkCacheMetaData_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkCacheMetaData_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkCacheMetaData_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkCacheMetaData_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QNetworkCacheMetaData_TypeAsNumber;

static SbkObjectType Sbk_QNetworkCacheMetaData_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkCacheMetaData",
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
    /*tp_traverse*/         Sbk_QNetworkCacheMetaData_traverse,
    /*tp_clear*/            Sbk_QNetworkCacheMetaData_clear,
    /*tp_richcompare*/      Sbk_QNetworkCacheMetaData_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkCacheMetaData_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkCacheMetaData_Init,
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
static void QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkCacheMetaData_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkCacheMetaData_Type))
        return QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkCacheMetaData_PTR_CppToPython_QNetworkCacheMetaData(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkCacheMetaData*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkCacheMetaData_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkCacheMetaData_COPY_CppToPython_QNetworkCacheMetaData(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkCacheMetaData_Type, new ::QNetworkCacheMetaData(*((::QNetworkCacheMetaData*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkCacheMetaData*)cppOut) = *((::QNetworkCacheMetaData*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkCacheMetaData_Type))
        return QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_COPY;
    return 0;
}

void init_QNetworkCacheMetaData(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QNetworkCacheMetaData_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QNetworkCacheMetaData_TypeAsNumber.nb_rshift = Sbk_QNetworkCacheMetaDataFunc___rshift__;
    Sbk_QNetworkCacheMetaData_TypeAsNumber.nb_lshift = Sbk_QNetworkCacheMetaDataFunc___lshift__;
    Sbk_QNetworkCacheMetaData_Type.super.ht_type.tp_as_number = &Sbk_QNetworkCacheMetaData_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QNETWORKCACHEMETADATA_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkCacheMetaData_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkCacheMetaData", "QNetworkCacheMetaData",
        &Sbk_QNetworkCacheMetaData_Type, &Shiboken::callCppDestructor< ::QNetworkCacheMetaData >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkCacheMetaData_Type,
        QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_PTR,
        is_QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_PTR_Convertible,
        QNetworkCacheMetaData_PTR_CppToPython_QNetworkCacheMetaData,
        QNetworkCacheMetaData_COPY_CppToPython_QNetworkCacheMetaData);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkCacheMetaData");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkCacheMetaData*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkCacheMetaData&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkCacheMetaData).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_COPY,
        is_QNetworkCacheMetaData_PythonToCpp_QNetworkCacheMetaData_COPY_Convertible);


    qRegisterMetaType< ::QNetworkCacheMetaData >("QNetworkCacheMetaData");
}
