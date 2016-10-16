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

#include "qhostinfo_wrapper.h"

// Extra includes
#include <QList>
#include <qhostaddress.h>
#include <qhostinfo.h>
#include <qobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QHostInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QHostInfo >()))
        return -1;

    ::QHostInfo* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHostInfo(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QHostInfo", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QHostInfo(QHostInfo)
    // 1: QHostInfo(int)
    if (numArgs == 0) {
        overloadId = 1; // QHostInfo(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // QHostInfo(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (pyArgs[0])))) {
        overloadId = 0; // QHostInfo(QHostInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QHostInfo(const QHostInfo & d)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QHostInfo cppArg0_local = ::QHostInfo(((int)0));
            ::QHostInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QHostInfo(QHostInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QHostInfo(int lookupId)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "lookupId");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHostInfo(): got multiple values for keyword argument 'lookupId'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QHostInfo_Init_TypeError;
                }
            }
            int cppArg0 = -1;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHostInfo(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHostInfo(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QHostInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QHostInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QHostInfo_Init_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostInfo", "int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHostInfo", overloads);
        return -1;
}

static PyObject* Sbk_QHostInfoFunc_abortHostLookup(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: abortHostLookup(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // abortHostLookup(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_abortHostLookup_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // abortHostLookup(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QHostInfo::abortHostLookup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_abortHostLookup_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.abortHostLookup", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_addresses(PyObject* self)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // addresses()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QHostAddress > cppResult = const_cast<const ::QHostInfo*>(cppSelf)->addresses();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHostInfoFunc_error(PyObject* self)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostInfo::HostInfoError cppResult = const_cast<const ::QHostInfo*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHostInfoFunc_errorString(PyObject* self)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHostInfo*>(cppSelf)->errorString();
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

static PyObject* Sbk_QHostInfoFunc_fromName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_fromName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostInfo cppResult = ::QHostInfo::fromName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHostInfoFunc_fromName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.fromName", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_hostName(PyObject* self)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hostName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHostInfo*>(cppSelf)->hostName();
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

static PyObject* Sbk_QHostInfoFunc_localDomainName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localDomainName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QHostInfo::localDomainName();
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

static PyObject* Sbk_QHostInfoFunc_localHostName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localHostName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QHostInfo::localHostName();
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

static PyObject* Sbk_QHostInfoFunc_lookupId(PyObject* self)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lookupId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QHostInfo*>(cppSelf)->lookupId();
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

static PyObject* Sbk_QHostInfoFunc_setAddresses(PyObject* self, PyObject* pyArg)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAddresses(QList<QHostAddress>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setAddresses(QList<QHostAddress>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_setAddresses_TypeError;

    // Call function/method
    {
        ::QList<QHostAddress > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAddresses(QList<QHostAddress>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAddresses(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_setAddresses_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.setAddresses", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_setError(PyObject* self, PyObject* pyArg)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setError(QHostInfo::HostInfoError)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX]), (pyArg)))) {
        overloadId = 0; // setError(QHostInfo::HostInfoError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_setError_TypeError;

    // Call function/method
    {
        ::QHostInfo::HostInfoError cppArg0 = ((::QHostInfo::HostInfoError)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setError(QHostInfo::HostInfoError)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setError(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_setError_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostInfo.HostInfoError", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.setError", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_setErrorString(PyObject* self, PyObject* pyArg)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setErrorString(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setErrorString(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_setErrorString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setErrorString(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setErrorString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_setErrorString_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.setErrorString", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_setHostName(PyObject* self, PyObject* pyArg)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHostName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHostName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_setHostName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHostName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHostName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_setHostName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.setHostName", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfoFunc_setLookupId(PyObject* self, PyObject* pyArg)
{
    ::QHostInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLookupId(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLookupId(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHostInfoFunc_setLookupId_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLookupId(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLookupId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHostInfoFunc_setLookupId_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHostInfo.setLookupId", overloads);
        return 0;
}

static PyObject* Sbk_QHostInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHostInfo& cppSelf = *(((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHostInfo_methods[] = {
    {"abortHostLookup", (PyCFunction)Sbk_QHostInfoFunc_abortHostLookup, METH_O|METH_STATIC},
    {"addresses", (PyCFunction)Sbk_QHostInfoFunc_addresses, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QHostInfoFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QHostInfoFunc_errorString, METH_NOARGS},
    {"fromName", (PyCFunction)Sbk_QHostInfoFunc_fromName, METH_O|METH_STATIC},
    {"hostName", (PyCFunction)Sbk_QHostInfoFunc_hostName, METH_NOARGS},
    {"localDomainName", (PyCFunction)Sbk_QHostInfoFunc_localDomainName, METH_NOARGS|METH_STATIC},
    {"localHostName", (PyCFunction)Sbk_QHostInfoFunc_localHostName, METH_NOARGS|METH_STATIC},
    {"lookupId", (PyCFunction)Sbk_QHostInfoFunc_lookupId, METH_NOARGS},
    {"setAddresses", (PyCFunction)Sbk_QHostInfoFunc_setAddresses, METH_O},
    {"setError", (PyCFunction)Sbk_QHostInfoFunc_setError, METH_O},
    {"setErrorString", (PyCFunction)Sbk_QHostInfoFunc_setErrorString, METH_O},
    {"setHostName", (PyCFunction)Sbk_QHostInfoFunc_setHostName, METH_O},
    {"setLookupId", (PyCFunction)Sbk_QHostInfoFunc_setLookupId, METH_O},

    {"__copy__", (PyCFunction)Sbk_QHostInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QHostInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHostInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHostInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QHostInfo",
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
    /*tp_traverse*/         Sbk_QHostInfo_traverse,
    /*tp_clear*/            Sbk_QHostInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHostInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QHostInfo_Init,
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
static void QHostInfo_HostInfoError_PythonToCpp_QHostInfo_HostInfoError(PyObject* pyIn, void* cppOut) {
    *((::QHostInfo::HostInfoError*)cppOut) = (::QHostInfo::HostInfoError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHostInfo_HostInfoError_PythonToCpp_QHostInfo_HostInfoError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX]))
        return QHostInfo_HostInfoError_PythonToCpp_QHostInfo_HostInfoError;
    return 0;
}
static PyObject* QHostInfo_HostInfoError_CppToPython_QHostInfo_HostInfoError(const void* cppIn) {
    int castCppIn = *((::QHostInfo::HostInfoError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHostInfo_PythonToCpp_QHostInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHostInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHostInfo_PythonToCpp_QHostInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHostInfo_Type))
        return QHostInfo_PythonToCpp_QHostInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHostInfo_PTR_CppToPython_QHostInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QHostInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QHostInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QHostInfo_COPY_CppToPython_QHostInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QHostInfo_Type, new ::QHostInfo(*((::QHostInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QHostInfo_PythonToCpp_QHostInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QHostInfo*)cppOut) = *((::QHostInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QHostInfo_PythonToCpp_QHostInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHostInfo_Type))
        return QHostInfo_PythonToCpp_QHostInfo_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_int_PythonToCpp_QHostInfo(PyObject* pyIn, void* cppOut) {
    int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &cppIn);
    *((::QHostInfo*)cppOut) = ::QHostInfo(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_int_PythonToCpp_QHostInfo_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_int_PythonToCpp_QHostInfo;
    return 0;
}

void init_QHostInfo(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHostInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHostInfo", "QHostInfo",
        &Sbk_QHostInfo_Type, &Shiboken::callCppDestructor< ::QHostInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHostInfo_Type,
        QHostInfo_PythonToCpp_QHostInfo_PTR,
        is_QHostInfo_PythonToCpp_QHostInfo_PTR_Convertible,
        QHostInfo_PTR_CppToPython_QHostInfo,
        QHostInfo_COPY_CppToPython_QHostInfo);

    Shiboken::Conversions::registerConverterName(converter, "QHostInfo");
    Shiboken::Conversions::registerConverterName(converter, "QHostInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QHostInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHostInfo).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHostInfo_PythonToCpp_QHostInfo_COPY,
        is_QHostInfo_PythonToCpp_QHostInfo_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_int_PythonToCpp_QHostInfo,
        is_PySide_QtCore_int_PythonToCpp_QHostInfo_Convertible);

    // Initialization of enums.

    // Initialization of enum 'HostInfoError'.
    SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHostInfo_Type,
        "HostInfoError",
        "PySide.QtNetwork.QHostInfo.HostInfoError",
        "QHostInfo::HostInfoError");
    if (!SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX],
        &Sbk_QHostInfo_Type, "NoError", (long) QHostInfo::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX],
        &Sbk_QHostInfo_Type, "HostNotFound", (long) QHostInfo::HostNotFound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX],
        &Sbk_QHostInfo_Type, "UnknownError", (long) QHostInfo::UnknownError))
        return ;
    // Register converter for enum 'QHostInfo::HostInfoError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX],
            QHostInfo_HostInfoError_CppToPython_QHostInfo_HostInfoError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHostInfo_HostInfoError_PythonToCpp_QHostInfo_HostInfoError,
            is_QHostInfo_HostInfoError_PythonToCpp_QHostInfo_HostInfoError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHOSTINFO_HOSTINFOERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHostInfo::HostInfoError");
        Shiboken::Conversions::registerConverterName(converter, "HostInfoError");
    }
    // End of 'HostInfoError' enum.


    qRegisterMetaType< ::QHostInfo::HostInfoError >("QHostInfo::HostInfoError");
}
