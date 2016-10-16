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
#include "pyside_qtsql_python.h"

#include "qsqlerror_wrapper.h"

// Extra includes
#include <qsqlerror.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlError_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlError >()))
        return -1;

    ::QSqlError* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlError(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QSqlError", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlError(QSqlError)
    // 1: QSqlError(QString,QString,QSqlError::ErrorType,int)
    if (numArgs == 0) {
        overloadId = 1; // QSqlError(QString,QString,QSqlError::ErrorType,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSqlError(QString,QString,QSqlError::ErrorType,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QSqlError(QString,QString,QSqlError::ErrorType,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // QSqlError(QString,QString,QSqlError::ErrorType,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 1; // QSqlError(QString,QString,QSqlError::ErrorType,int)
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlError(QSqlError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlError_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlError(const QSqlError & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlError cppArg0_local = ::QSqlError(::QString(), ::QString(), ((::QSqlError::ErrorType)0), ((int)0));
            ::QSqlError* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlError(QSqlError)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlError(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlError(const QString & driverText, const QString & databaseText, QSqlError::ErrorType type, int number)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "driverText");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlError(): got multiple values for keyword argument 'driverText'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QSqlError_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "databaseText");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlError(): got multiple values for keyword argument 'databaseText'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlError_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlError(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QSqlError_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "number");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlError(): got multiple values for keyword argument 'number'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QSqlError_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSqlError::ErrorType cppArg2 = QSqlError::NoError;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QSqlError(QString,QString,QSqlError::ErrorType,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlError(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlError >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlError_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlError_Init_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlError", "unicode = QString(), unicode = QString(), PySide.QtSql.QSqlError.ErrorType = NoError, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlError", overloads);
        return -1;
}

static PyObject* Sbk_QSqlErrorFunc_databaseText(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // databaseText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlError*>(cppSelf)->databaseText();
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

static PyObject* Sbk_QSqlErrorFunc_driverText(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // driverText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlError*>(cppSelf)->driverText();
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

static PyObject* Sbk_QSqlErrorFunc_isValid(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlError*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSqlErrorFunc_number(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // number()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlError*>(cppSelf)->number();
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

static PyObject* Sbk_QSqlErrorFunc_setDatabaseText(PyObject* self, PyObject* pyArg)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDatabaseText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDatabaseText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlErrorFunc_setDatabaseText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDatabaseText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDatabaseText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlErrorFunc_setDatabaseText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlError.setDatabaseText", overloads);
        return 0;
}

static PyObject* Sbk_QSqlErrorFunc_setDriverText(PyObject* self, PyObject* pyArg)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDriverText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDriverText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlErrorFunc_setDriverText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDriverText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDriverText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlErrorFunc_setDriverText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlError.setDriverText", overloads);
        return 0;
}

static PyObject* Sbk_QSqlErrorFunc_setNumber(PyObject* self, PyObject* pyArg)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumber(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setNumber(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlErrorFunc_setNumber_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumber(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumber(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlErrorFunc_setNumber_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlError.setNumber", overloads);
        return 0;
}

static PyObject* Sbk_QSqlErrorFunc_setType(PyObject* self, PyObject* pyArg)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(QSqlError::ErrorType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setType(QSqlError::ErrorType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlErrorFunc_setType_TypeError;

    // Call function/method
    {
        ::QSqlError::ErrorType cppArg0 = ((::QSqlError::ErrorType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(QSqlError::ErrorType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlErrorFunc_setType_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlError.ErrorType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlError.setType", overloads);
        return 0;
}

static PyObject* Sbk_QSqlErrorFunc_text(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlError*>(cppSelf)->text();
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

static PyObject* Sbk_QSqlErrorFunc_type(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlError::ErrorType cppResult = const_cast<const ::QSqlError*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlError___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlError& cppSelf = *(((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlError_methods[] = {
    {"databaseText", (PyCFunction)Sbk_QSqlErrorFunc_databaseText, METH_NOARGS},
    {"driverText", (PyCFunction)Sbk_QSqlErrorFunc_driverText, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlErrorFunc_isValid, METH_NOARGS},
    {"number", (PyCFunction)Sbk_QSqlErrorFunc_number, METH_NOARGS},
    {"setDatabaseText", (PyCFunction)Sbk_QSqlErrorFunc_setDatabaseText, METH_O},
    {"setDriverText", (PyCFunction)Sbk_QSqlErrorFunc_setDriverText, METH_O},
    {"setNumber", (PyCFunction)Sbk_QSqlErrorFunc_setNumber, METH_O},
    {"setType", (PyCFunction)Sbk_QSqlErrorFunc_setType, METH_O},
    {"text", (PyCFunction)Sbk_QSqlErrorFunc_text, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QSqlErrorFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSqlError___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlError_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlError_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSqlError__repr__(PyObject* self)
{
    ::QSqlError* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QSqlError_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlError",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSqlError__repr__,
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
    /*tp_traverse*/         Sbk_QSqlError_traverse,
    /*tp_clear*/            Sbk_QSqlError_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlError_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlError_Init,
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
static void QSqlError_ErrorType_PythonToCpp_QSqlError_ErrorType(PyObject* pyIn, void* cppOut) {
    *((::QSqlError::ErrorType*)cppOut) = (::QSqlError::ErrorType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlError_ErrorType_PythonToCpp_QSqlError_ErrorType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX]))
        return QSqlError_ErrorType_PythonToCpp_QSqlError_ErrorType;
    return 0;
}
static PyObject* QSqlError_ErrorType_CppToPython_QSqlError_ErrorType(const void* cppIn) {
    int castCppIn = *((::QSqlError::ErrorType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlError_PythonToCpp_QSqlError_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlError_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlError_PythonToCpp_QSqlError_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlError_Type))
        return QSqlError_PythonToCpp_QSqlError_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlError_PTR_CppToPython_QSqlError(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlError*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlError_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlError_COPY_CppToPython_QSqlError(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlError_Type, new ::QSqlError(*((::QSqlError*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlError_PythonToCpp_QSqlError_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlError*)cppOut) = *((::QSqlError*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlError_PythonToCpp_QSqlError_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlError_Type))
        return QSqlError_PythonToCpp_QSqlError_COPY;
    return 0;
}

void init_QSqlError(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlError_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlError", "QSqlError",
        &Sbk_QSqlError_Type, &Shiboken::callCppDestructor< ::QSqlError >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlError_Type,
        QSqlError_PythonToCpp_QSqlError_PTR,
        is_QSqlError_PythonToCpp_QSqlError_PTR_Convertible,
        QSqlError_PTR_CppToPython_QSqlError,
        QSqlError_COPY_CppToPython_QSqlError);

    Shiboken::Conversions::registerConverterName(converter, "QSqlError");
    Shiboken::Conversions::registerConverterName(converter, "QSqlError*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlError&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlError).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlError_PythonToCpp_QSqlError_COPY,
        is_QSqlError_PythonToCpp_QSqlError_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ErrorType'.
    SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlError_Type,
        "ErrorType",
        "PySide.QtSql.QSqlError.ErrorType",
        "QSqlError::ErrorType");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
        &Sbk_QSqlError_Type, "NoError", (long) QSqlError::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
        &Sbk_QSqlError_Type, "ConnectionError", (long) QSqlError::ConnectionError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
        &Sbk_QSqlError_Type, "StatementError", (long) QSqlError::StatementError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
        &Sbk_QSqlError_Type, "TransactionError", (long) QSqlError::TransactionError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
        &Sbk_QSqlError_Type, "UnknownError", (long) QSqlError::UnknownError))
        return ;
    // Register converter for enum 'QSqlError::ErrorType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX],
            QSqlError_ErrorType_CppToPython_QSqlError_ErrorType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlError_ErrorType_PythonToCpp_QSqlError_ErrorType,
            is_QSqlError_ErrorType_PythonToCpp_QSqlError_ErrorType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLERROR_ERRORTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlError::ErrorType");
        Shiboken::Conversions::registerConverterName(converter, "ErrorType");
    }
    // End of 'ErrorType' enum.


    qRegisterMetaType< ::QSqlError::ErrorType >("QSqlError::ErrorType");
}
