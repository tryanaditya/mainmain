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

#include "qnetworkcookie_wrapper.h"

// Extra includes
#include <QDateTime>
#include <QList>
#include <qbytearray.h>
#include <qdatetime.h>
#include <qnetworkcookie.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkCookie_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkCookie >()))
        return -1;

    ::QNetworkCookie* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkCookie(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QNetworkCookie", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkCookie(QByteArray,QByteArray)
    // 1: QNetworkCookie(QNetworkCookie)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkCookie(QByteArray,QByteArray)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkCookie(QNetworkCookie)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QNetworkCookie(QByteArray,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 0; // QNetworkCookie(QByteArray,QByteArray)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookie_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkCookie(const QByteArray & name, const QByteArray & value)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "name");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkCookie(): got multiple values for keyword argument 'name'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                        goto Sbk_QNetworkCookie_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "value");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkCookie(): got multiple values for keyword argument 'value'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                        goto Sbk_QNetworkCookie_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }
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
                // QNetworkCookie(QByteArray,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkCookie(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkCookie(const QNetworkCookie & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkCookie cppArg0_local = ::QNetworkCookie(::QByteArray(), ::QByteArray());
            ::QNetworkCookie* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkCookie(QNetworkCookie)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkCookie(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkCookie >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkCookie_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkCookie_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray = QByteArray(), PySide.QtCore.QByteArray = QByteArray()", "PySide.QtNetwork.QNetworkCookie", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkCookie", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkCookieFunc_domain(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // domain()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->domain();
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

static PyObject* Sbk_QNetworkCookieFunc_expirationDate(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expirationDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->expirationDate();
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

static PyObject* Sbk_QNetworkCookieFunc_isHttpOnly(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isHttpOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->isHttpOnly();
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

static PyObject* Sbk_QNetworkCookieFunc_isSecure(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSecure()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->isSecure();
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

static PyObject* Sbk_QNetworkCookieFunc_isSessionCookie(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSessionCookie()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->isSessionCookie();
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

static PyObject* Sbk_QNetworkCookieFunc_name(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->name();
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

static PyObject* Sbk_QNetworkCookieFunc_parseCookies(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: parseCookies(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // parseCookies(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_parseCookies_TypeError;

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
            // parseCookies(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QNetworkCookie > cppResult = ::QNetworkCookie::parseCookies(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCOOKIE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkCookieFunc_parseCookies_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.parseCookies", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_path(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // path()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->path();
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

static PyObject* Sbk_QNetworkCookieFunc_setDomain(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDomain(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDomain(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setDomain_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDomain(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDomain(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCookieFunc_setDomain_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setDomain", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setExpirationDate(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setExpirationDate(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setExpirationDate(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setExpirationDate_TypeError;

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

    Sbk_QNetworkCookieFunc_setExpirationDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setExpirationDate", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setHttpOnly(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHttpOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHttpOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setHttpOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHttpOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHttpOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCookieFunc_setHttpOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setHttpOnly", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setName(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setName_TypeError;

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
            // setName(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setName(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCookieFunc_setName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setName", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setPath(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setPath_TypeError;

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

    Sbk_QNetworkCookieFunc_setPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setPath", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setSecure(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSecure(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSecure(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setSecure_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSecure(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSecure(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCookieFunc_setSecure_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setSecure", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_setValue_TypeError;

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
            // setValue(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkCookieFunc_setValue_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkCookie.setValue", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_toRawForm(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkCookie.toRawForm(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toRawForm", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toRawForm(QNetworkCookie::RawForm)const
    if (numArgs == 0) {
        overloadId = 0; // toRawForm(QNetworkCookie::RawForm)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX]), (pyArgs[0])))) {
        overloadId = 0; // toRawForm(QNetworkCookie::RawForm)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkCookieFunc_toRawForm_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "form");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkCookie.toRawForm(): got multiple values for keyword argument 'form'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX]), (pyArgs[0]))))
                    goto Sbk_QNetworkCookieFunc_toRawForm_TypeError;
            }
        }
        ::QNetworkCookie::RawForm cppArg0 = QNetworkCookie::Full;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toRawForm(QNetworkCookie::RawForm)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->toRawForm(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkCookieFunc_toRawForm_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkCookie.RawForm = Full", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkCookie.toRawForm", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkCookieFunc_value(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QNetworkCookie*>(cppSelf)->value();
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

static PyObject* Sbk_QNetworkCookie___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkCookie& cppSelf = *(((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkCookie_methods[] = {
    {"domain", (PyCFunction)Sbk_QNetworkCookieFunc_domain, METH_NOARGS},
    {"expirationDate", (PyCFunction)Sbk_QNetworkCookieFunc_expirationDate, METH_NOARGS},
    {"isHttpOnly", (PyCFunction)Sbk_QNetworkCookieFunc_isHttpOnly, METH_NOARGS},
    {"isSecure", (PyCFunction)Sbk_QNetworkCookieFunc_isSecure, METH_NOARGS},
    {"isSessionCookie", (PyCFunction)Sbk_QNetworkCookieFunc_isSessionCookie, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QNetworkCookieFunc_name, METH_NOARGS},
    {"parseCookies", (PyCFunction)Sbk_QNetworkCookieFunc_parseCookies, METH_O|METH_STATIC},
    {"path", (PyCFunction)Sbk_QNetworkCookieFunc_path, METH_NOARGS},
    {"setDomain", (PyCFunction)Sbk_QNetworkCookieFunc_setDomain, METH_O},
    {"setExpirationDate", (PyCFunction)Sbk_QNetworkCookieFunc_setExpirationDate, METH_O},
    {"setHttpOnly", (PyCFunction)Sbk_QNetworkCookieFunc_setHttpOnly, METH_O},
    {"setName", (PyCFunction)Sbk_QNetworkCookieFunc_setName, METH_O},
    {"setPath", (PyCFunction)Sbk_QNetworkCookieFunc_setPath, METH_O},
    {"setSecure", (PyCFunction)Sbk_QNetworkCookieFunc_setSecure, METH_O},
    {"setValue", (PyCFunction)Sbk_QNetworkCookieFunc_setValue, METH_O},
    {"toRawForm", (PyCFunction)Sbk_QNetworkCookieFunc_toRawForm, METH_VARARGS|METH_KEYWORDS},
    {"value", (PyCFunction)Sbk_QNetworkCookieFunc_value, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkCookie___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkCookie_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkCookie& cppSelf = *(((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (pyArg)))) {
                // operator!=(const QNetworkCookie & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkCookie cppArg0_local = ::QNetworkCookie(::QByteArray(), ::QByteArray());
                ::QNetworkCookie* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (pyArg)))) {
                // operator==(const QNetworkCookie & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkCookie cppArg0_local = ::QNetworkCookie(::QByteArray(), ::QByteArray());
                ::QNetworkCookie* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], pythonToCpp))
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
            goto Sbk_QNetworkCookie_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkCookie_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkCookie_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkCookie_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QNetworkCookie__repr__(PyObject* self)
{
    ::QNetworkCookie* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QNetworkCookie_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkCookie",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QNetworkCookie__repr__,
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
    /*tp_traverse*/         Sbk_QNetworkCookie_traverse,
    /*tp_clear*/            Sbk_QNetworkCookie_clear,
    /*tp_richcompare*/      Sbk_QNetworkCookie_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkCookie_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkCookie_Init,
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
static void QNetworkCookie_RawForm_PythonToCpp_QNetworkCookie_RawForm(PyObject* pyIn, void* cppOut) {
    *((::QNetworkCookie::RawForm*)cppOut) = (::QNetworkCookie::RawForm) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkCookie_RawForm_PythonToCpp_QNetworkCookie_RawForm_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX]))
        return QNetworkCookie_RawForm_PythonToCpp_QNetworkCookie_RawForm;
    return 0;
}
static PyObject* QNetworkCookie_RawForm_CppToPython_QNetworkCookie_RawForm(const void* cppIn) {
    int castCppIn = *((::QNetworkCookie::RawForm*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkCookie_PythonToCpp_QNetworkCookie_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkCookie_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkCookie_PythonToCpp_QNetworkCookie_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkCookie_Type))
        return QNetworkCookie_PythonToCpp_QNetworkCookie_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkCookie_PTR_CppToPython_QNetworkCookie(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkCookie*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkCookie_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkCookie_COPY_CppToPython_QNetworkCookie(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkCookie_Type, new ::QNetworkCookie(*((::QNetworkCookie*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkCookie_PythonToCpp_QNetworkCookie_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkCookie*)cppOut) = *((::QNetworkCookie*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkCookie_PythonToCpp_QNetworkCookie_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkCookie_Type))
        return QNetworkCookie_PythonToCpp_QNetworkCookie_COPY;
    return 0;
}

void init_QNetworkCookie(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkCookie_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkCookie", "QNetworkCookie",
        &Sbk_QNetworkCookie_Type, &Shiboken::callCppDestructor< ::QNetworkCookie >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkCookie_Type,
        QNetworkCookie_PythonToCpp_QNetworkCookie_PTR,
        is_QNetworkCookie_PythonToCpp_QNetworkCookie_PTR_Convertible,
        QNetworkCookie_PTR_CppToPython_QNetworkCookie,
        QNetworkCookie_COPY_CppToPython_QNetworkCookie);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkCookie");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkCookie*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkCookie&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkCookie).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkCookie_PythonToCpp_QNetworkCookie_COPY,
        is_QNetworkCookie_PythonToCpp_QNetworkCookie_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'RawForm'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkCookie_Type,
        "RawForm",
        "PySide.QtNetwork.QNetworkCookie.RawForm",
        "QNetworkCookie::RawForm");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX],
        &Sbk_QNetworkCookie_Type, "NameAndValueOnly", (long) QNetworkCookie::NameAndValueOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX],
        &Sbk_QNetworkCookie_Type, "Full", (long) QNetworkCookie::Full))
        return ;
    // Register converter for enum 'QNetworkCookie::RawForm'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX],
            QNetworkCookie_RawForm_CppToPython_QNetworkCookie_RawForm);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkCookie_RawForm_PythonToCpp_QNetworkCookie_RawForm,
            is_QNetworkCookie_RawForm_PythonToCpp_QNetworkCookie_RawForm_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIE_RAWFORM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkCookie::RawForm");
        Shiboken::Conversions::registerConverterName(converter, "RawForm");
    }
    // End of 'RawForm' enum.


    qRegisterMetaType< ::QNetworkCookie::RawForm >("QNetworkCookie::RawForm");
}
