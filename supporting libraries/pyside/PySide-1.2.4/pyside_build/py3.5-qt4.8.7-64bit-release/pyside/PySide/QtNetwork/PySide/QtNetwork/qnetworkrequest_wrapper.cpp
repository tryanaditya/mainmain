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

#include "qnetworkrequest_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qsslconfiguration.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkRequest_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkRequest >()))
        return -1;

    ::QNetworkRequest* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkRequest(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QNetworkRequest", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkRequest(QNetworkRequest)
    // 1: QNetworkRequest(QUrl)
    if (numArgs == 0) {
        overloadId = 1; // QNetworkRequest(QUrl)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkRequest(QUrl)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[0])))) {
        overloadId = 0; // QNetworkRequest(QNetworkRequest)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequest_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkRequest(const QNetworkRequest & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkRequest(QNetworkRequest)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkRequest(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkRequest(const QUrl & url)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "url");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkRequest(): got multiple values for keyword argument 'url'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0]))))
                        goto Sbk_QNetworkRequest_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // QNetworkRequest(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkRequest(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkRequest >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkRequest_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkRequest_Init_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest", "PySide.QtCore.QUrl = QUrl()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkRequest", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkRequestFunc_attribute(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkRequest.attribute(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkRequest.attribute(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:attribute", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: attribute(QNetworkRequest::Attribute,QVariant)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // attribute(QNetworkRequest::Attribute,QVariant)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 0; // attribute(QNetworkRequest::Attribute,QVariant)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_attribute_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defaultValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkRequest.attribute(): got multiple values for keyword argument 'defaultValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1]))))
                    goto Sbk_QNetworkRequestFunc_attribute_TypeError;
            }
        }
        ::QNetworkRequest::Attribute cppArg0 = ((::QNetworkRequest::Attribute)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = QVariant();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // attribute(QNetworkRequest::Attribute,QVariant)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->attribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkRequestFunc_attribute_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.Attribute, QVariant = QVariant()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkRequest.attribute", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_hasRawHeader(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasRawHeader(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // hasRawHeader(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_hasRawHeader_TypeError;

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
            // hasRawHeader(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->hasRawHeader(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkRequestFunc_hasRawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.hasRawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_header(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: header(QNetworkRequest::KnownHeaders)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX]), (pyArg)))) {
        overloadId = 0; // header(QNetworkRequest::KnownHeaders)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_header_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::KnownHeaders cppArg0 = ((::QNetworkRequest::KnownHeaders)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // header(QNetworkRequest::KnownHeaders)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->header(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkRequestFunc_header_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.KnownHeaders", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.header", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_originatingObject(PyObject* self)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // originatingObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->originatingObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkRequestFunc_priority(PyObject* self)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // priority()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkRequest::Priority cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->priority();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkRequestFunc_rawHeader(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rawHeader(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // rawHeader(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_rawHeader_TypeError;

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
            // rawHeader(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->rawHeader(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkRequestFunc_rawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.rawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_rawHeaderList(PyObject* self)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawHeaderList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->rawHeaderList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkRequestFunc_setAttribute(PyObject* self, PyObject* args)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(QNetworkRequest::Attribute,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setAttribute(QNetworkRequest::Attribute,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setAttribute_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::Attribute cppArg0 = ((::QNetworkRequest::Attribute)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAttribute(QNetworkRequest::Attribute,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setAttribute_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.Attribute, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkRequest.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setHeader(PyObject* self, PyObject* args)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setHeader", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setHeader(QNetworkRequest::KnownHeaders,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setHeader(QNetworkRequest::KnownHeaders,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setHeader_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::KnownHeaders cppArg0 = ((::QNetworkRequest::KnownHeaders)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setHeader(QNetworkRequest::KnownHeaders,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHeader(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setHeader_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.KnownHeaders, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkRequest.setHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setOriginatingObject(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOriginatingObject(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // setOriginatingObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setOriginatingObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOriginatingObject(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOriginatingObject(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setOriginatingObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.setOriginatingObject", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setPriority(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPriority(QNetworkRequest::Priority)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX]), (pyArg)))) {
        overloadId = 0; // setPriority(QNetworkRequest::Priority)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setPriority_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::Priority cppArg0 = ((::QNetworkRequest::Priority)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPriority(QNetworkRequest::Priority)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPriority(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setPriority_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.Priority", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.setPriority", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setRawHeader(PyObject* self, PyObject* args)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRawHeader", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRawHeader(QByteArray,QByteArray)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 0; // setRawHeader(QByteArray,QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setRawHeader_TypeError;

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
            // setRawHeader(QByteArray,QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRawHeader(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setRawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkRequest.setRawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setSslConfiguration(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSslConfiguration(QSslConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setSslConfiguration(QSslConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setSslConfiguration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
        ::QSslConfiguration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSslConfiguration(QSslConfiguration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSslConfiguration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkRequestFunc_setSslConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.setSslConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_setUrl(PyObject* self, PyObject* pyArg)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkRequestFunc_setUrl_TypeError;

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

    Sbk_QNetworkRequestFunc_setUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkRequest.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkRequestFunc_sslConfiguration(PyObject* self)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sslConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslConfiguration cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->sslConfiguration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkRequestFunc_url(PyObject* self)
{
    ::QNetworkRequest* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QNetworkRequest*>(cppSelf)->url();
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

static PyObject* Sbk_QNetworkRequest___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkRequest& cppSelf = *(((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkRequest_methods[] = {
    {"attribute", (PyCFunction)Sbk_QNetworkRequestFunc_attribute, METH_VARARGS|METH_KEYWORDS},
    {"hasRawHeader", (PyCFunction)Sbk_QNetworkRequestFunc_hasRawHeader, METH_O},
    {"header", (PyCFunction)Sbk_QNetworkRequestFunc_header, METH_O},
    {"originatingObject", (PyCFunction)Sbk_QNetworkRequestFunc_originatingObject, METH_NOARGS},
    {"priority", (PyCFunction)Sbk_QNetworkRequestFunc_priority, METH_NOARGS},
    {"rawHeader", (PyCFunction)Sbk_QNetworkRequestFunc_rawHeader, METH_O},
    {"rawHeaderList", (PyCFunction)Sbk_QNetworkRequestFunc_rawHeaderList, METH_NOARGS},
    {"setAttribute", (PyCFunction)Sbk_QNetworkRequestFunc_setAttribute, METH_VARARGS},
    {"setHeader", (PyCFunction)Sbk_QNetworkRequestFunc_setHeader, METH_VARARGS},
    {"setOriginatingObject", (PyCFunction)Sbk_QNetworkRequestFunc_setOriginatingObject, METH_O},
    {"setPriority", (PyCFunction)Sbk_QNetworkRequestFunc_setPriority, METH_O},
    {"setRawHeader", (PyCFunction)Sbk_QNetworkRequestFunc_setRawHeader, METH_VARARGS},
    {"setSslConfiguration", (PyCFunction)Sbk_QNetworkRequestFunc_setSslConfiguration, METH_O},
    {"setUrl", (PyCFunction)Sbk_QNetworkRequestFunc_setUrl, METH_O},
    {"sslConfiguration", (PyCFunction)Sbk_QNetworkRequestFunc_sslConfiguration, METH_NOARGS},
    {"url", (PyCFunction)Sbk_QNetworkRequestFunc_url, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkRequest___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkRequest_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkRequest& cppSelf = *(((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
                // operator!=(const QNetworkRequest & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
                ::QNetworkRequest* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
                // operator==(const QNetworkRequest & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
                ::QNetworkRequest* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp))
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
            goto Sbk_QNetworkRequest_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkRequest_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkRequest_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkRequest_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkRequest_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkRequest",
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
    /*tp_traverse*/         Sbk_QNetworkRequest_traverse,
    /*tp_clear*/            Sbk_QNetworkRequest_clear,
    /*tp_richcompare*/      Sbk_QNetworkRequest_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkRequest_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkRequest_Init,
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
static void QNetworkRequest_KnownHeaders_PythonToCpp_QNetworkRequest_KnownHeaders(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest::KnownHeaders*)cppOut) = (::QNetworkRequest::KnownHeaders) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkRequest_KnownHeaders_PythonToCpp_QNetworkRequest_KnownHeaders_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX]))
        return QNetworkRequest_KnownHeaders_PythonToCpp_QNetworkRequest_KnownHeaders;
    return 0;
}
static PyObject* QNetworkRequest_KnownHeaders_CppToPython_QNetworkRequest_KnownHeaders(const void* cppIn) {
    int castCppIn = *((::QNetworkRequest::KnownHeaders*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX], castCppIn);

}

static void QNetworkRequest_Attribute_PythonToCpp_QNetworkRequest_Attribute(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest::Attribute*)cppOut) = (::QNetworkRequest::Attribute) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkRequest_Attribute_PythonToCpp_QNetworkRequest_Attribute_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]))
        return QNetworkRequest_Attribute_PythonToCpp_QNetworkRequest_Attribute;
    return 0;
}
static PyObject* QNetworkRequest_Attribute_CppToPython_QNetworkRequest_Attribute(const void* cppIn) {
    int castCppIn = *((::QNetworkRequest::Attribute*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX], castCppIn);

}

static void QNetworkRequest_CacheLoadControl_PythonToCpp_QNetworkRequest_CacheLoadControl(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest::CacheLoadControl*)cppOut) = (::QNetworkRequest::CacheLoadControl) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkRequest_CacheLoadControl_PythonToCpp_QNetworkRequest_CacheLoadControl_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX]))
        return QNetworkRequest_CacheLoadControl_PythonToCpp_QNetworkRequest_CacheLoadControl;
    return 0;
}
static PyObject* QNetworkRequest_CacheLoadControl_CppToPython_QNetworkRequest_CacheLoadControl(const void* cppIn) {
    int castCppIn = *((::QNetworkRequest::CacheLoadControl*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX], castCppIn);

}

static void QNetworkRequest_LoadControl_PythonToCpp_QNetworkRequest_LoadControl(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest::LoadControl*)cppOut) = (::QNetworkRequest::LoadControl) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkRequest_LoadControl_PythonToCpp_QNetworkRequest_LoadControl_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX]))
        return QNetworkRequest_LoadControl_PythonToCpp_QNetworkRequest_LoadControl;
    return 0;
}
static PyObject* QNetworkRequest_LoadControl_CppToPython_QNetworkRequest_LoadControl(const void* cppIn) {
    int castCppIn = *((::QNetworkRequest::LoadControl*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX], castCppIn);

}

static void QNetworkRequest_Priority_PythonToCpp_QNetworkRequest_Priority(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest::Priority*)cppOut) = (::QNetworkRequest::Priority) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkRequest_Priority_PythonToCpp_QNetworkRequest_Priority_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX]))
        return QNetworkRequest_Priority_PythonToCpp_QNetworkRequest_Priority;
    return 0;
}
static PyObject* QNetworkRequest_Priority_CppToPython_QNetworkRequest_Priority(const void* cppIn) {
    int castCppIn = *((::QNetworkRequest::Priority*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkRequest_PythonToCpp_QNetworkRequest_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkRequest_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkRequest_PythonToCpp_QNetworkRequest_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkRequest_Type))
        return QNetworkRequest_PythonToCpp_QNetworkRequest_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkRequest_PTR_CppToPython_QNetworkRequest(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkRequest*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkRequest_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkRequest_COPY_CppToPython_QNetworkRequest(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkRequest_Type, new ::QNetworkRequest(*((::QNetworkRequest*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkRequest_PythonToCpp_QNetworkRequest_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkRequest*)cppOut) = *((::QNetworkRequest*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkRequest_PythonToCpp_QNetworkRequest_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkRequest_Type))
        return QNetworkRequest_PythonToCpp_QNetworkRequest_COPY;
    return 0;
}

void init_QNetworkRequest(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkRequest_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkRequest", "QNetworkRequest",
        &Sbk_QNetworkRequest_Type, &Shiboken::callCppDestructor< ::QNetworkRequest >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkRequest_Type,
        QNetworkRequest_PythonToCpp_QNetworkRequest_PTR,
        is_QNetworkRequest_PythonToCpp_QNetworkRequest_PTR_Convertible,
        QNetworkRequest_PTR_CppToPython_QNetworkRequest,
        QNetworkRequest_COPY_CppToPython_QNetworkRequest);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkRequest).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkRequest_PythonToCpp_QNetworkRequest_COPY,
        is_QNetworkRequest_PythonToCpp_QNetworkRequest_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'KnownHeaders'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkRequest_Type,
        "KnownHeaders",
        "PySide.QtNetwork.QNetworkRequest.KnownHeaders",
        "QNetworkRequest::KnownHeaders");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "ContentTypeHeader", (long) QNetworkRequest::ContentTypeHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "ContentLengthHeader", (long) QNetworkRequest::ContentLengthHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "LocationHeader", (long) QNetworkRequest::LocationHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "LastModifiedHeader", (long) QNetworkRequest::LastModifiedHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "CookieHeader", (long) QNetworkRequest::CookieHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "SetCookieHeader", (long) QNetworkRequest::SetCookieHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
        &Sbk_QNetworkRequest_Type, "ContentDispositionHeader", (long) QNetworkRequest::ContentDispositionHeader))
        return ;
    // Register converter for enum 'QNetworkRequest::KnownHeaders'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX],
            QNetworkRequest_KnownHeaders_CppToPython_QNetworkRequest_KnownHeaders);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkRequest_KnownHeaders_PythonToCpp_QNetworkRequest_KnownHeaders,
            is_QNetworkRequest_KnownHeaders_PythonToCpp_QNetworkRequest_KnownHeaders_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest::KnownHeaders");
        Shiboken::Conversions::registerConverterName(converter, "KnownHeaders");
    }
    // End of 'KnownHeaders' enum.

    // Initialization of enum 'Attribute'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkRequest_Type,
        "Attribute",
        "PySide.QtNetwork.QNetworkRequest.Attribute",
        "QNetworkRequest::Attribute");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "HttpStatusCodeAttribute", (long) QNetworkRequest::HttpStatusCodeAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "HttpReasonPhraseAttribute", (long) QNetworkRequest::HttpReasonPhraseAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "RedirectionTargetAttribute", (long) QNetworkRequest::RedirectionTargetAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "ConnectionEncryptedAttribute", (long) QNetworkRequest::ConnectionEncryptedAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "CacheLoadControlAttribute", (long) QNetworkRequest::CacheLoadControlAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "CacheSaveControlAttribute", (long) QNetworkRequest::CacheSaveControlAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "SourceIsFromCacheAttribute", (long) QNetworkRequest::SourceIsFromCacheAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "DoNotBufferUploadDataAttribute", (long) QNetworkRequest::DoNotBufferUploadDataAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "HttpPipeliningAllowedAttribute", (long) QNetworkRequest::HttpPipeliningAllowedAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "HttpPipeliningWasUsedAttribute", (long) QNetworkRequest::HttpPipeliningWasUsedAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "CustomVerbAttribute", (long) QNetworkRequest::CustomVerbAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "CookieLoadControlAttribute", (long) QNetworkRequest::CookieLoadControlAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "AuthenticationReuseAttribute", (long) QNetworkRequest::AuthenticationReuseAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "CookieSaveControlAttribute", (long) QNetworkRequest::CookieSaveControlAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "MaximumDownloadBufferSizeAttribute", (long) QNetworkRequest::MaximumDownloadBufferSizeAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "DownloadBufferAttribute", (long) QNetworkRequest::DownloadBufferAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "SynchronousRequestAttribute", (long) QNetworkRequest::SynchronousRequestAttribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "User", (long) QNetworkRequest::User))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
        &Sbk_QNetworkRequest_Type, "UserMax", (long) QNetworkRequest::UserMax))
        return ;
    // Register converter for enum 'QNetworkRequest::Attribute'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX],
            QNetworkRequest_Attribute_CppToPython_QNetworkRequest_Attribute);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkRequest_Attribute_PythonToCpp_QNetworkRequest_Attribute,
            is_QNetworkRequest_Attribute_PythonToCpp_QNetworkRequest_Attribute_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest::Attribute");
        Shiboken::Conversions::registerConverterName(converter, "Attribute");
    }
    // End of 'Attribute' enum.

    // Initialization of enum 'CacheLoadControl'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkRequest_Type,
        "CacheLoadControl",
        "PySide.QtNetwork.QNetworkRequest.CacheLoadControl",
        "QNetworkRequest::CacheLoadControl");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "AlwaysNetwork", (long) QNetworkRequest::AlwaysNetwork))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "PreferNetwork", (long) QNetworkRequest::PreferNetwork))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "PreferCache", (long) QNetworkRequest::PreferCache))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "AlwaysCache", (long) QNetworkRequest::AlwaysCache))
        return ;
    // Register converter for enum 'QNetworkRequest::CacheLoadControl'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX],
            QNetworkRequest_CacheLoadControl_CppToPython_QNetworkRequest_CacheLoadControl);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkRequest_CacheLoadControl_PythonToCpp_QNetworkRequest_CacheLoadControl,
            is_QNetworkRequest_CacheLoadControl_PythonToCpp_QNetworkRequest_CacheLoadControl_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_CACHELOADCONTROL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest::CacheLoadControl");
        Shiboken::Conversions::registerConverterName(converter, "CacheLoadControl");
    }
    // End of 'CacheLoadControl' enum.

    // Initialization of enum 'LoadControl'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkRequest_Type,
        "LoadControl",
        "PySide.QtNetwork.QNetworkRequest.LoadControl",
        "QNetworkRequest::LoadControl");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "Automatic", (long) QNetworkRequest::Automatic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX],
        &Sbk_QNetworkRequest_Type, "Manual", (long) QNetworkRequest::Manual))
        return ;
    // Register converter for enum 'QNetworkRequest::LoadControl'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX],
            QNetworkRequest_LoadControl_CppToPython_QNetworkRequest_LoadControl);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkRequest_LoadControl_PythonToCpp_QNetworkRequest_LoadControl,
            is_QNetworkRequest_LoadControl_PythonToCpp_QNetworkRequest_LoadControl_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_LOADCONTROL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest::LoadControl");
        Shiboken::Conversions::registerConverterName(converter, "LoadControl");
    }
    // End of 'LoadControl' enum.

    // Initialization of enum 'Priority'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkRequest_Type,
        "Priority",
        "PySide.QtNetwork.QNetworkRequest.Priority",
        "QNetworkRequest::Priority");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX],
        &Sbk_QNetworkRequest_Type, "HighPriority", (long) QNetworkRequest::HighPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX],
        &Sbk_QNetworkRequest_Type, "NormalPriority", (long) QNetworkRequest::NormalPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX],
        &Sbk_QNetworkRequest_Type, "LowPriority", (long) QNetworkRequest::LowPriority))
        return ;
    // Register converter for enum 'QNetworkRequest::Priority'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX],
            QNetworkRequest_Priority_CppToPython_QNetworkRequest_Priority);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkRequest_Priority_PythonToCpp_QNetworkRequest_Priority,
            is_QNetworkRequest_Priority_PythonToCpp_QNetworkRequest_Priority_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_PRIORITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkRequest::Priority");
        Shiboken::Conversions::registerConverterName(converter, "Priority");
    }
    // End of 'Priority' enum.


    qRegisterMetaType< ::QNetworkRequest::KnownHeaders >("QNetworkRequest::KnownHeaders");
    qRegisterMetaType< ::QNetworkRequest::Attribute >("QNetworkRequest::Attribute");
    qRegisterMetaType< ::QNetworkRequest::CacheLoadControl >("QNetworkRequest::CacheLoadControl");
    qRegisterMetaType< ::QNetworkRequest::LoadControl >("QNetworkRequest::LoadControl");
    qRegisterMetaType< ::QNetworkRequest::Priority >("QNetworkRequest::Priority");
}
