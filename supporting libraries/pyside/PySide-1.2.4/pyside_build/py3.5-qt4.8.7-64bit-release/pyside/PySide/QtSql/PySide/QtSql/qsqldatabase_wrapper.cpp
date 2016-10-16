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

#include "qsqldatabase_wrapper.h"

// Extra includes
#include <QSize>
#include <QSqlError>
#include <QSqlIndex>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <qsqldatabase.h>
#include <qsqldriver.h>
#include <qsqlerror.h>
#include <qsqlindex.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlDatabase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlDatabase >()))
        return -1;

    ::QSqlDatabase* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSqlDatabase", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlDatabase()
    // 1: QSqlDatabase(QSqlDriver*)
    // 2: QSqlDatabase(QSqlDatabase)
    // 3: QSqlDatabase(QString)
    if (numArgs == 0) {
        overloadId = 0; // QSqlDatabase()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QSqlDatabase(QSqlDatabase)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSqlDatabase(QSqlDriver*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 3; // QSqlDatabase(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabase_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlDatabase()
        {

            if (!PyErr_Occurred()) {
                // QSqlDatabase()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlDatabase();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlDatabase(QSqlDriver * driver)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlDriver* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSqlDatabase(QSqlDriver*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlDatabase(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSqlDatabase(const QSqlDatabase & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlDatabase cppArg0_local = ::QSqlDatabase();
            ::QSqlDatabase* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlDatabase(QSqlDatabase)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlDatabase(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QSqlDatabase(const QString & type)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSqlDatabase(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlDatabase(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlDatabase >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlDatabase_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlDatabase_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtSql.QSqlDriver", "PySide.QtSql.QSqlDatabase", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase", overloads);
        return -1;
}

static PyObject* Sbk_QSqlDatabaseFunc_addDatabase(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.addDatabase(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.addDatabase(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addDatabase", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addDatabase(QSqlDriver*,QString)
    // 1: addDatabase(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addDatabase(QSqlDriver*,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // addDatabase(QSqlDriver*,QString)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // addDatabase(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // addDatabase(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_addDatabase_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addDatabase(QSqlDriver * driver, const QString & connectionName)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "connectionName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.addDatabase(): got multiple values for keyword argument 'connectionName'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlDatabaseFunc_addDatabase_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSqlDriver* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(QSqlDatabase::defaultConnection);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addDatabase(QSqlDriver*,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QSqlDatabase cppResult = ::QSqlDatabase::addDatabase(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppResult);
            }
            break;
        }
        case 1: // addDatabase(const QString & type, const QString & connectionName)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "connectionName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.addDatabase(): got multiple values for keyword argument 'connectionName'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlDatabaseFunc_addDatabase_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(QSqlDatabase::defaultConnection);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addDatabase(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QSqlDatabase cppResult = ::QSqlDatabase::addDatabase(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_addDatabase_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDriver, unicode = QLatin1String(defaultConnection)", "unicode, unicode = QLatin1String(defaultConnection)", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.addDatabase", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_cloneDatabase(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "cloneDatabase", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: cloneDatabase(QSqlDatabase,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // cloneDatabase(QSqlDatabase,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_cloneDatabase_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QSqlDatabase cppArg0_local = ::QSqlDatabase();
        ::QSqlDatabase* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // cloneDatabase(QSqlDatabase,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlDatabase cppResult = ::QSqlDatabase::cloneDatabase(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_cloneDatabase_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDatabase, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.cloneDatabase", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_close(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlDatabaseFunc_commit(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // commit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->commit();
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

static PyObject* Sbk_QSqlDatabaseFunc_connectOptions(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // connectOptions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->connectOptions();
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

static PyObject* Sbk_QSqlDatabaseFunc_connectionName(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // connectionName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->connectionName();
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

static PyObject* Sbk_QSqlDatabaseFunc_connectionNames(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // connectionNames()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QSqlDatabase::connectionNames();
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

static PyObject* Sbk_QSqlDatabaseFunc_contains(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.contains(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:contains", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: contains(QString)
    if (numArgs == 0) {
        overloadId = 0; // contains(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // contains(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_contains_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "connectionName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.contains(): got multiple values for keyword argument 'connectionName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlDatabaseFunc_contains_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(QSqlDatabase::defaultConnection);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QSqlDatabase::contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_contains_TypeError:
        const char* overloads[] = {"unicode = QLatin1String(defaultConnection)", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.contains", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_database(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.database(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:database", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: database(QString,bool)
    if (numArgs == 0) {
        overloadId = 0; // database(QString,bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // database(QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // database(QString,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_database_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "connectionName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.database(): got multiple values for keyword argument 'connectionName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlDatabaseFunc_database_TypeError;
            }
            value = PyDict_GetItemString(kwds, "open");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.database(): got multiple values for keyword argument 'open'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QSqlDatabaseFunc_database_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(QSqlDatabase::defaultConnection);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // database(QString,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlDatabase cppResult = ::QSqlDatabase::database(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_database_TypeError:
        const char* overloads[] = {"unicode = QLatin1String(defaultConnection), bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.database", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_databaseName(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // databaseName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->databaseName();
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

static PyObject* Sbk_QSqlDatabaseFunc_driver(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // driver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlDriver * cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->driver();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlDatabaseFunc_driverName(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // driverName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->driverName();
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

static PyObject* Sbk_QSqlDatabaseFunc_drivers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // drivers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QSqlDatabase::drivers();
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

static PyObject* Sbk_QSqlDatabaseFunc_exec_(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.exec_(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:exec_", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exec(QString)const
    if (numArgs == 0) {
        overloadId = 0; // exec(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // exec(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_exec__TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "query");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.exec_(): got multiple values for keyword argument 'query'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlDatabaseFunc_exec__TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // exec(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlQuery cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->exec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_exec__TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.exec_", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_hostName(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hostName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->hostName();
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

static PyObject* Sbk_QSqlDatabaseFunc_isDriverAvailable(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isDriverAvailable(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isDriverAvailable(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_isDriverAvailable_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isDriverAvailable(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QSqlDatabase::isDriverAvailable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_isDriverAvailable_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.isDriverAvailable", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_isOpen(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOpen()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->isOpen();
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

static PyObject* Sbk_QSqlDatabaseFunc_isOpenError(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOpenError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->isOpenError();
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

static PyObject* Sbk_QSqlDatabaseFunc_isValid(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSqlDatabaseFunc_lastError(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlError cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->lastError();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlDatabaseFunc_numericalPrecisionPolicy(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numericalPrecisionPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSql::NumericalPrecisionPolicy cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->numericalPrecisionPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlDatabaseFunc_open(PyObject* self, PyObject* args)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QSqlDatabaseFunc_open_TypeError;

    if (!PyArg_UnpackTuple(args, "open", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: open()
    // 1: open(QString,QString)
    if (numArgs == 0) {
        overloadId = 0; // open()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // open(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_open_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // open()
        {

            if (!PyErr_Occurred()) {
                // open()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->open();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // open(const QString & user, const QString & password)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // open(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->open(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_open_TypeError:
        const char* overloads[] = {"", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.open", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_password(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // password()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->password();
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

static PyObject* Sbk_QSqlDatabaseFunc_port(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // port()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->port();
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

static PyObject* Sbk_QSqlDatabaseFunc_primaryIndex(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: primaryIndex(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // primaryIndex(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_primaryIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // primaryIndex(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlIndex cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->primaryIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_primaryIndex_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.primaryIndex", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_record(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: record(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // record(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_record_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // record(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlRecord cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->record(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_record_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.record", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_registerSqlDriver(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerSqlDriver", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: registerSqlDriver(QString,QSqlDriverCreatorBase*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVERCREATORBASE_IDX], (pyArgs[1])))) {
        overloadId = 0; // registerSqlDriver(QString,QSqlDriverCreatorBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_registerSqlDriver_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlDriverCreatorBase* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // registerSqlDriver(QString,QSqlDriverCreatorBase*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSqlDatabase::registerSqlDriver(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Ownership transferences.
            Shiboken::Object::releaseOwnership(pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDatabaseFunc_registerSqlDriver_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriverCreatorBase", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.registerSqlDriver", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_removeDatabase(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeDatabase(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeDatabase(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_removeDatabase_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeDatabase(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSqlDatabase::removeDatabase(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDatabaseFunc_removeDatabase_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.removeDatabase", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_rollback(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rollback()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->rollback();
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

static PyObject* Sbk_QSqlDatabaseFunc_setConnectOptions(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.setConnectOptions(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:setConnectOptions", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: setConnectOptions(QString)
    if (numArgs == 0) {
        overloadId = 0; // setConnectOptions(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // setConnectOptions(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setConnectOptions_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.setConnectOptions(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlDatabaseFunc_setConnectOptions_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // setConnectOptions(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setConnectOptions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDatabaseFunc_setConnectOptions_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.setConnectOptions", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setDatabaseName(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDatabaseName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDatabaseName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setDatabaseName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDatabaseName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDatabaseName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDatabaseFunc_setDatabaseName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setDatabaseName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setHostName(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHostName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHostName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setHostName_TypeError;

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

    Sbk_QSqlDatabaseFunc_setHostName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setHostName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setNumericalPrecisionPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setNumericalPrecisionPolicy_TypeError;

    // Call function/method
    {
        ::QSql::NumericalPrecisionPolicy cppArg0 = ((::QSql::NumericalPrecisionPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumericalPrecisionPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDatabaseFunc_setNumericalPrecisionPolicy_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.NumericalPrecisionPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setNumericalPrecisionPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setPassword(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPassword(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPassword(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setPassword_TypeError;

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

    Sbk_QSqlDatabaseFunc_setPassword_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setPassword", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setPort(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPort(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPort(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setPort_TypeError;

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

    Sbk_QSqlDatabaseFunc_setPort_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setPort", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_setUserName(PyObject* self, PyObject* pyArg)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setUserName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_setUserName_TypeError;

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

    Sbk_QSqlDatabaseFunc_setUserName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDatabase.setUserName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_tables(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.tables(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:tables", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: tables(QSql::TableType)const
    if (numArgs == 0) {
        overloadId = 0; // tables(QSql::TableType)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // tables(QSql::TableType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDatabaseFunc_tables_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDatabase.tables(): got multiple values for keyword argument 'type'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QSqlDatabaseFunc_tables_TypeError;
            }
        }
        ::QSql::TableType cppArg0 = QSql::Tables;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // tables(QSql::TableType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->tables(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDatabaseFunc_tables_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.TableType = QSql.Tables", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDatabase.tables", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDatabaseFunc_transaction(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transaction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->transaction();
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

static PyObject* Sbk_QSqlDatabaseFunc_userName(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDatabase*>(cppSelf)->userName();
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

static PyObject* Sbk_QSqlDatabase___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlDatabase& cppSelf = *(((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlDatabase_methods[] = {
    {"addDatabase", (PyCFunction)Sbk_QSqlDatabaseFunc_addDatabase, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"cloneDatabase", (PyCFunction)Sbk_QSqlDatabaseFunc_cloneDatabase, METH_VARARGS|METH_STATIC},
    {"close", (PyCFunction)Sbk_QSqlDatabaseFunc_close, METH_NOARGS},
    {"commit", (PyCFunction)Sbk_QSqlDatabaseFunc_commit, METH_NOARGS},
    {"connectOptions", (PyCFunction)Sbk_QSqlDatabaseFunc_connectOptions, METH_NOARGS},
    {"connectionName", (PyCFunction)Sbk_QSqlDatabaseFunc_connectionName, METH_NOARGS},
    {"connectionNames", (PyCFunction)Sbk_QSqlDatabaseFunc_connectionNames, METH_NOARGS|METH_STATIC},
    {"contains", (PyCFunction)Sbk_QSqlDatabaseFunc_contains, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"database", (PyCFunction)Sbk_QSqlDatabaseFunc_database, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"databaseName", (PyCFunction)Sbk_QSqlDatabaseFunc_databaseName, METH_NOARGS},
    {"driver", (PyCFunction)Sbk_QSqlDatabaseFunc_driver, METH_NOARGS},
    {"driverName", (PyCFunction)Sbk_QSqlDatabaseFunc_driverName, METH_NOARGS},
    {"drivers", (PyCFunction)Sbk_QSqlDatabaseFunc_drivers, METH_NOARGS|METH_STATIC},
    {"exec_", (PyCFunction)Sbk_QSqlDatabaseFunc_exec_, METH_VARARGS|METH_KEYWORDS},
    {"hostName", (PyCFunction)Sbk_QSqlDatabaseFunc_hostName, METH_NOARGS},
    {"isDriverAvailable", (PyCFunction)Sbk_QSqlDatabaseFunc_isDriverAvailable, METH_O|METH_STATIC},
    {"isOpen", (PyCFunction)Sbk_QSqlDatabaseFunc_isOpen, METH_NOARGS},
    {"isOpenError", (PyCFunction)Sbk_QSqlDatabaseFunc_isOpenError, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlDatabaseFunc_isValid, METH_NOARGS},
    {"lastError", (PyCFunction)Sbk_QSqlDatabaseFunc_lastError, METH_NOARGS},
    {"numericalPrecisionPolicy", (PyCFunction)Sbk_QSqlDatabaseFunc_numericalPrecisionPolicy, METH_NOARGS},
    {"open", (PyCFunction)Sbk_QSqlDatabaseFunc_open, METH_VARARGS},
    {"password", (PyCFunction)Sbk_QSqlDatabaseFunc_password, METH_NOARGS},
    {"port", (PyCFunction)Sbk_QSqlDatabaseFunc_port, METH_NOARGS},
    {"primaryIndex", (PyCFunction)Sbk_QSqlDatabaseFunc_primaryIndex, METH_O},
    {"record", (PyCFunction)Sbk_QSqlDatabaseFunc_record, METH_O},
    {"registerSqlDriver", (PyCFunction)Sbk_QSqlDatabaseFunc_registerSqlDriver, METH_VARARGS|METH_STATIC},
    {"removeDatabase", (PyCFunction)Sbk_QSqlDatabaseFunc_removeDatabase, METH_O|METH_STATIC},
    {"rollback", (PyCFunction)Sbk_QSqlDatabaseFunc_rollback, METH_NOARGS},
    {"setConnectOptions", (PyCFunction)Sbk_QSqlDatabaseFunc_setConnectOptions, METH_VARARGS|METH_KEYWORDS},
    {"setDatabaseName", (PyCFunction)Sbk_QSqlDatabaseFunc_setDatabaseName, METH_O},
    {"setHostName", (PyCFunction)Sbk_QSqlDatabaseFunc_setHostName, METH_O},
    {"setNumericalPrecisionPolicy", (PyCFunction)Sbk_QSqlDatabaseFunc_setNumericalPrecisionPolicy, METH_O},
    {"setPassword", (PyCFunction)Sbk_QSqlDatabaseFunc_setPassword, METH_O},
    {"setPort", (PyCFunction)Sbk_QSqlDatabaseFunc_setPort, METH_O},
    {"setUserName", (PyCFunction)Sbk_QSqlDatabaseFunc_setUserName, METH_O},
    {"tables", (PyCFunction)Sbk_QSqlDatabaseFunc_tables, METH_VARARGS|METH_KEYWORDS},
    {"transaction", (PyCFunction)Sbk_QSqlDatabaseFunc_transaction, METH_NOARGS},
    {"userName", (PyCFunction)Sbk_QSqlDatabaseFunc_userName, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSqlDatabase___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlDatabase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlDatabase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSqlDatabase__repr__(PyObject* self)
{
    ::QSqlDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QSqlDatabase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlDatabase",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSqlDatabase__repr__,
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
    /*tp_traverse*/         Sbk_QSqlDatabase_traverse,
    /*tp_clear*/            Sbk_QSqlDatabase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlDatabase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlDatabase_Init,
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
static void QSqlDatabase_PythonToCpp_QSqlDatabase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlDatabase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlDatabase_PythonToCpp_QSqlDatabase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlDatabase_Type))
        return QSqlDatabase_PythonToCpp_QSqlDatabase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlDatabase_PTR_CppToPython_QSqlDatabase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlDatabase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlDatabase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlDatabase_COPY_CppToPython_QSqlDatabase(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlDatabase_Type, new ::QSqlDatabase(*((::QSqlDatabase*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlDatabase_PythonToCpp_QSqlDatabase_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlDatabase*)cppOut) = *((::QSqlDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlDatabase_PythonToCpp_QSqlDatabase_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlDatabase_Type))
        return QSqlDatabase_PythonToCpp_QSqlDatabase_COPY;
    return 0;
}

void init_QSqlDatabase(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlDatabase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlDatabase", "QSqlDatabase",
        &Sbk_QSqlDatabase_Type, &Shiboken::callCppDestructor< ::QSqlDatabase >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlDatabase_Type,
        QSqlDatabase_PythonToCpp_QSqlDatabase_PTR,
        is_QSqlDatabase_PythonToCpp_QSqlDatabase_PTR_Convertible,
        QSqlDatabase_PTR_CppToPython_QSqlDatabase,
        QSqlDatabase_COPY_CppToPython_QSqlDatabase);

    Shiboken::Conversions::registerConverterName(converter, "QSqlDatabase");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDatabase*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDatabase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlDatabase).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlDatabase_PythonToCpp_QSqlDatabase_COPY,
        is_QSqlDatabase_PythonToCpp_QSqlDatabase_COPY_Convertible);

    PyDict_SetItemString(Sbk_QSqlDatabase_Type.super.ht_type.tp_dict, "defaultConnection", Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), QSqlDatabase::defaultConnection));

    qRegisterMetaType< ::QSqlDatabase >("QSqlDatabase");
}
