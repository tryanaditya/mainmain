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

#include "qhttprequestheader_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <qhttp.h>


// Native ---------------------------------------------------------

QHttpRequestHeaderWrapper::QHttpRequestHeaderWrapper() : QHttpRequestHeader() {
    // ... middle
}

QHttpRequestHeaderWrapper::QHttpRequestHeaderWrapper(const QString & method, const QString & path, int majorVer, int minorVer) : QHttpRequestHeader(method, path, majorVer, minorVer) {
    // ... middle
}

QHttpRequestHeaderWrapper::QHttpRequestHeaderWrapper(const QString & str) : QHttpRequestHeader(str) {
    // ... middle
}

int QHttpRequestHeaderWrapper::majorVersion() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "majorVersion"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QHttpRequestHeader::majorVersion();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttpRequestHeader.majorVersion", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QHttpRequestHeaderWrapper::minorVersion() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minorVersion"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QHttpRequestHeader::minorVersion();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttpRequestHeader.minorVersion", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QHttpRequestHeaderWrapper::parseLine(const QString & line, int number)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parseLine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QHttpRequestHeader::parseLine(line, number);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &line),
        number
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttpRequestHeader.parseLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QHttpRequestHeaderWrapper::toString() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "toString"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QHttpRequestHeader::toString();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttpRequestHeader.toString", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QHttpRequestHeaderWrapper::~QHttpRequestHeaderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QHttpRequestHeader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QHttpRequestHeader >()))
        return -1;

    ::QHttpRequestHeaderWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QHttpRequestHeader", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QHttpRequestHeader()
    // 1: QHttpRequestHeader(QHttpRequestHeader)
    // 2: QHttpRequestHeader(QString,QString,int,int)
    // 3: QHttpRequestHeader(QString)
    if (numArgs == 0) {
        overloadId = 0; // QHttpRequestHeader()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QHttpRequestHeader(QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QHttpRequestHeader(QString,QString,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 2; // QHttpRequestHeader(QString,QString,int,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 2; // QHttpRequestHeader(QString,QString,int,int)
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QHttpRequestHeader(QHttpRequestHeader)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpRequestHeader_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QHttpRequestHeader()
        {

            if (!PyErr_Occurred()) {
                // QHttpRequestHeader()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHttpRequestHeaderWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QHttpRequestHeader(const QHttpRequestHeader & header)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QHttpRequestHeader cppArg0_local = ::QHttpRequestHeader();
            ::QHttpRequestHeader* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QHttpRequestHeader(QHttpRequestHeader)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHttpRequestHeaderWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QHttpRequestHeader(const QString & method, const QString & path, int majorVer, int minorVer)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "majorVer");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader(): got multiple values for keyword argument 'majorVer'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QHttpRequestHeader_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "minorVer");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader(): got multiple values for keyword argument 'minorVer'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QHttpRequestHeader_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QHttpRequestHeader(QString,QString,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHttpRequestHeaderWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QHttpRequestHeader(const QString & str)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHttpRequestHeader(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHttpRequestHeaderWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QHttpRequestHeader >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QHttpRequestHeader_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QHttpRequestHeader_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QHttpRequestHeader", "unicode, unicode, int = 1, int = 1", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttpRequestHeader", overloads);
        return -1;
}

static PyObject* Sbk_QHttpRequestHeaderFunc_majorVersion(PyObject* self)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // majorVersion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QHttpRequestHeader*>(cppSelf)->::QHttpRequestHeader::majorVersion() : const_cast<const ::QHttpRequestHeader*>(cppSelf)->majorVersion();
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

static PyObject* Sbk_QHttpRequestHeaderFunc_method(PyObject* self)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // method()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHttpRequestHeader*>(cppSelf)->method();
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

static PyObject* Sbk_QHttpRequestHeaderFunc_minorVersion(PyObject* self)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minorVersion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QHttpRequestHeader*>(cppSelf)->::QHttpRequestHeader::minorVersion() : const_cast<const ::QHttpRequestHeader*>(cppSelf)->minorVersion();
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

static PyObject* Sbk_QHttpRequestHeaderFunc_parseLine(PyObject* self, PyObject* args)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "parseLine", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: parseLine(QString,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // parseLine(QString,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpRequestHeaderFunc_parseLine_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // parseLine(QString,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QHttpRequestHeader::parseLine(cppArg0, cppArg1) : cppSelf->parseLine(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpRequestHeaderFunc_parseLine_TypeError:
        const char* overloads[] = {"unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttpRequestHeader.parseLine", overloads);
        return 0;
}

static PyObject* Sbk_QHttpRequestHeaderFunc_path(PyObject* self)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // path()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHttpRequestHeader*>(cppSelf)->path();
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

static PyObject* Sbk_QHttpRequestHeaderFunc_setRequest(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader.setRequest(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader.setRequest(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setRequest", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setRequest(QString,QString,int,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setRequest(QString,QString,int,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // setRequest(QString,QString,int,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                overloadId = 0; // setRequest(QString,QString,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpRequestHeaderFunc_setRequest_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "majorVer");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader.setRequest(): got multiple values for keyword argument 'majorVer'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QHttpRequestHeaderFunc_setRequest_TypeError;
            }
            value = PyDict_GetItemString(kwds, "minorVer");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttpRequestHeader.setRequest(): got multiple values for keyword argument 'minorVer'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QHttpRequestHeaderFunc_setRequest_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 1;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setRequest(QString,QString,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRequest(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHttpRequestHeaderFunc_setRequest_TypeError:
        const char* overloads[] = {"unicode, unicode, int = 1, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttpRequestHeader.setRequest", overloads);
        return 0;
}

static PyObject* Sbk_QHttpRequestHeaderFunc_toString(PyObject* self)
{
    ::QHttpRequestHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QHttpRequestHeader*>(cppSelf)->::QHttpRequestHeader::toString() : const_cast<const ::QHttpRequestHeader*>(cppSelf)->toString();
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

static PyObject* Sbk_QHttpRequestHeader___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHttpRequestHeader& cppSelf = *(((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHttpRequestHeader_methods[] = {
    {"majorVersion", (PyCFunction)Sbk_QHttpRequestHeaderFunc_majorVersion, METH_NOARGS},
    {"method", (PyCFunction)Sbk_QHttpRequestHeaderFunc_method, METH_NOARGS},
    {"minorVersion", (PyCFunction)Sbk_QHttpRequestHeaderFunc_minorVersion, METH_NOARGS},
    {"parseLine", (PyCFunction)Sbk_QHttpRequestHeaderFunc_parseLine, METH_VARARGS},
    {"path", (PyCFunction)Sbk_QHttpRequestHeaderFunc_path, METH_NOARGS},
    {"setRequest", (PyCFunction)Sbk_QHttpRequestHeaderFunc_setRequest, METH_VARARGS|METH_KEYWORDS},
    {"toString", (PyCFunction)Sbk_QHttpRequestHeaderFunc_toString, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QHttpRequestHeader___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QHttpRequestHeader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHttpRequestHeader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHttpRequestHeader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QHttpRequestHeader",
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
    /*tp_traverse*/         Sbk_QHttpRequestHeader_traverse,
    /*tp_clear*/            Sbk_QHttpRequestHeader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHttpRequestHeader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QHttpRequestHeader_Init,
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

static void* Sbk_QHttpRequestHeader_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QHttpHeader >()))
        return dynamic_cast< ::QHttpRequestHeader*>(reinterpret_cast< ::QHttpHeader*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHttpRequestHeader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHttpRequestHeader_Type))
        return QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHttpRequestHeader_PTR_CppToPython_QHttpRequestHeader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QHttpRequestHeader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QHttpRequestHeader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QHttpRequestHeader_COPY_CppToPython_QHttpRequestHeader(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QHttpRequestHeader_Type, new ::QHttpRequestHeaderWrapper(*((::QHttpRequestHeader*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_COPY(PyObject* pyIn, void* cppOut) {
    *((::QHttpRequestHeader*)cppOut) = *((::QHttpRequestHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHttpRequestHeader_Type))
        return QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQStringREF_PythonToCpp_QHttpRequestHeader(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QHttpRequestHeader*)cppOut) = ::QHttpRequestHeader(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QHttpRequestHeader_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QHttpRequestHeader;
    return 0;
}

void init_QHttpRequestHeader(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHttpRequestHeader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHttpRequestHeader", "QHttpRequestHeader",
        &Sbk_QHttpRequestHeader_Type, &Shiboken::callCppDestructor< ::QHttpRequestHeaderWrapper >, (SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPHEADER_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHttpRequestHeader_Type,
        QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_PTR,
        is_QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_PTR_Convertible,
        QHttpRequestHeader_PTR_CppToPython_QHttpRequestHeader,
        QHttpRequestHeader_COPY_CppToPython_QHttpRequestHeader);

    Shiboken::Conversions::registerConverterName(converter, "QHttpRequestHeader");
    Shiboken::Conversions::registerConverterName(converter, "QHttpRequestHeader*");
    Shiboken::Conversions::registerConverterName(converter, "QHttpRequestHeader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHttpRequestHeader).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHttpRequestHeaderWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_COPY,
        is_QHttpRequestHeader_PythonToCpp_QHttpRequestHeader_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QHttpRequestHeader,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QHttpRequestHeader_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QHttpRequestHeader_Type, &Sbk_QHttpRequestHeader_typeDiscovery);


    qRegisterMetaType< ::QHttpRequestHeader >("QHttpRequestHeader");
}
