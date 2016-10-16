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

#include "qsqlquery_wrapper.h"

// Extra includes
#include <QMap>
#include <QSize>
#include <QSqlError>
#include <QSqlRecord>
#include <QStringList>
#include <qsqldatabase.h>
#include <qsqldriver.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <qsqlresult.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlQuery_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlQuery >()))
        return -1;

    ::QSqlQuery* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QSqlQuery", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlQuery(QSqlDatabase)
    // 1: QSqlQuery(QSqlResult*)
    // 2: QSqlQuery(QSqlQuery)
    // 3: QSqlQuery(QString,QSqlDatabase)
    if (numArgs == 0) {
        overloadId = 3; // QSqlQuery(QString,QSqlDatabase)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSqlQuery(QSqlResult*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QSqlQuery(QString,QSqlDatabase)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[1])))) {
            overloadId = 3; // QSqlQuery(QString,QSqlDatabase)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (pyArgs[0])))) {
        overloadId = 2; // QSqlQuery(QSqlQuery)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlQuery(QSqlDatabase)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQuery_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlQuery(QSqlDatabase db)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlDatabase cppArg0 = ::QSqlDatabase();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSqlQuery(QSqlDatabase)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlQuery(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlQuery(QSqlResult * r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlResult* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSqlQuery(QSqlResult*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlQuery(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSqlQuery(const QSqlQuery & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlQuery cppArg0_local = ::QSqlQuery(((::QSqlResult*)0));
            ::QSqlQuery* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlQuery(QSqlQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlQuery(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QSqlQuery(const QString & query, QSqlDatabase db)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "query");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery(): got multiple values for keyword argument 'query'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QSqlQuery_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "db");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery(): got multiple values for keyword argument 'db'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlQuery_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QSqlDatabase cppArg1 = QSqlDatabase();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSqlQuery(QString,QSqlDatabase)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlQuery(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlQuery >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlQuery_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlQuery_Init_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDatabase", "PySide.QtSql.QSqlResult", "PySide.QtSql.QSqlQuery", "unicode = QString(), PySide.QtSql.QSqlDatabase = QSqlDatabase()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery", overloads);
        return -1;
}

static PyObject* Sbk_QSqlQueryFunc_addBindValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.addBindValue(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.addBindValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addBindValue", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_addBindValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.addBindValue(): got multiple values for keyword argument 'type'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QSqlQueryFunc_addBindValue_TypeError;
            }
        }
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QSql::ParamTypeFlag> cppArg1 = QSql::In;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addBindValue(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlQueryFunc_addBindValue_TypeError:
        const char* overloads[] = {"QVariant, PySide.QtSql.QSql.ParamType = QSql.In", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery.addBindValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_at(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // at()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->at();
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

static PyObject* Sbk_QSqlQueryFunc_bindValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.bindValue(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.bindValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:bindValue", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
    // 1: bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 1; // bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 0; // bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_bindValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindValue(const QString & placeholder, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.bindValue(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QSqlQueryFunc_bindValue_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QSql::ParamTypeFlag> cppArg2 = QSql::In;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // bindValue(int pos, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.bindValue(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QSqlQueryFunc_bindValue_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QSql::ParamTypeFlag> cppArg2 = QSql::In;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->bindValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlQueryFunc_bindValue_TypeError:
        const char* overloads[] = {"unicode, QVariant, PySide.QtSql.QSql.ParamType = QSql.In", "int, QVariant, PySide.QtSql.QSql.ParamType = QSql.In", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery.bindValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_boundValue(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boundValue(QString)const
    // 1: boundValue(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // boundValue(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // boundValue(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_boundValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // boundValue(const QString & placeholder) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // boundValue(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->boundValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
        case 1: // boundValue(int pos) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // boundValue(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->boundValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_boundValue_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.boundValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_boundValues(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundValues()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMap<QString, QVariant > cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->boundValues();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtSqlTypeConverters[SBK_QTSQL_QMAP_QSTRING_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlQueryFunc_clear(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QSqlQueryFunc_driver(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // driver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QSqlDriver * cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->driver();
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

static PyObject* Sbk_QSqlQueryFunc_execBatch(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.execBatch(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:execBatch", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: execBatch(QSqlQuery::BatchExecutionMode)
    if (numArgs == 0) {
        overloadId = 0; // execBatch(QSqlQuery::BatchExecutionMode)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // execBatch(QSqlQuery::BatchExecutionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_execBatch_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.execBatch(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QSqlQueryFunc_execBatch_TypeError;
            }
        }
        ::QSqlQuery::BatchExecutionMode cppArg0 = QSqlQuery::ValuesAsRows;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // execBatch(QSqlQuery::BatchExecutionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->execBatch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_execBatch_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlQuery.BatchExecutionMode = ValuesAsRows", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery.execBatch", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_exec_(PyObject* self, PyObject* args)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "exec_", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exec()
    // 1: exec(QString)
    if (numArgs == 0) {
        overloadId = 0; // exec()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // exec(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_exec__TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // exec()
        {

            if (!PyErr_Occurred()) {
                // exec()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->exec();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // exec(const QString & query)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // exec(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->exec(cppArg0);
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

    Sbk_QSqlQueryFunc_exec__TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery.exec_", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_executedQuery(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // executedQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->executedQuery();
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

static PyObject* Sbk_QSqlQueryFunc_finish(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // finish()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->finish();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlQueryFunc_first(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // first()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->first();
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

static PyObject* Sbk_QSqlQueryFunc_isActive(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->isActive();
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

static PyObject* Sbk_QSqlQueryFunc_isForwardOnly(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isForwardOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->isForwardOnly();
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

static PyObject* Sbk_QSqlQueryFunc_isNull(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isNull(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // isNull(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_isNull_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isNull(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->isNull(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_isNull_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.isNull", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_isSelect(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->isSelect();
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

static PyObject* Sbk_QSqlQueryFunc_isValid(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSqlQueryFunc_last(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // last()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->last();
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

static PyObject* Sbk_QSqlQueryFunc_lastError(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlError cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->lastError();
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

static PyObject* Sbk_QSqlQueryFunc_lastInsertId(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastInsertId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->lastInsertId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlQueryFunc_lastQuery(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->lastQuery();
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

static PyObject* Sbk_QSqlQueryFunc_next(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // next()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->next();
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

static PyObject* Sbk_QSqlQueryFunc_nextResult(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextResult()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->nextResult();
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

static PyObject* Sbk_QSqlQueryFunc_numRowsAffected(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numRowsAffected()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->numRowsAffected();
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

static PyObject* Sbk_QSqlQueryFunc_numericalPrecisionPolicy(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numericalPrecisionPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSql::NumericalPrecisionPolicy cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->numericalPrecisionPolicy();
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

static PyObject* Sbk_QSqlQueryFunc_prepare(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prepare(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // prepare(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_prepare_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // prepare(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->prepare(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_prepare_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.prepare", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_previous(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previous()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->previous();
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

static PyObject* Sbk_QSqlQueryFunc_record(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // record()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlRecord cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->record();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlQueryFunc_result(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // result()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QSqlResult * cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->result();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlQueryFunc_seek(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.seek(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.seek(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:seek", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: seek(int,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // seek(int,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // seek(int,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_seek_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "relative");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlQuery.seek(): got multiple values for keyword argument 'relative'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QSqlQueryFunc_seek_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // seek(int,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->seek(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_seek_TypeError:
        const char* overloads[] = {"int, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlQuery.seek", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_setForwardOnly(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForwardOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setForwardOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_setForwardOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setForwardOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForwardOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlQueryFunc_setForwardOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.setForwardOnly", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_setNumericalPrecisionPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_setNumericalPrecisionPolicy_TypeError;

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

    Sbk_QSqlQueryFunc_setNumericalPrecisionPolicy_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.NumericalPrecisionPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.setNumericalPrecisionPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQueryFunc_size(PyObject* self)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->size();
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

static PyObject* Sbk_QSqlQueryFunc_value(PyObject* self, PyObject* pyArg)
{
    ::QSqlQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: value(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // value(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlQueryFunc_value_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // value(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QSqlQuery*>(cppSelf)->value(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlQueryFunc_value_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlQuery.value", overloads);
        return 0;
}

static PyObject* Sbk_QSqlQuery___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlQuery& cppSelf = *(((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlQuery_methods[] = {
    {"addBindValue", (PyCFunction)Sbk_QSqlQueryFunc_addBindValue, METH_VARARGS|METH_KEYWORDS},
    {"at", (PyCFunction)Sbk_QSqlQueryFunc_at, METH_NOARGS},
    {"bindValue", (PyCFunction)Sbk_QSqlQueryFunc_bindValue, METH_VARARGS|METH_KEYWORDS},
    {"boundValue", (PyCFunction)Sbk_QSqlQueryFunc_boundValue, METH_O},
    {"boundValues", (PyCFunction)Sbk_QSqlQueryFunc_boundValues, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QSqlQueryFunc_clear, METH_NOARGS},
    {"driver", (PyCFunction)Sbk_QSqlQueryFunc_driver, METH_NOARGS},
    {"execBatch", (PyCFunction)Sbk_QSqlQueryFunc_execBatch, METH_VARARGS|METH_KEYWORDS},
    {"exec_", (PyCFunction)Sbk_QSqlQueryFunc_exec_, METH_VARARGS},
    {"executedQuery", (PyCFunction)Sbk_QSqlQueryFunc_executedQuery, METH_NOARGS},
    {"finish", (PyCFunction)Sbk_QSqlQueryFunc_finish, METH_NOARGS},
    {"first", (PyCFunction)Sbk_QSqlQueryFunc_first, METH_NOARGS},
    {"isActive", (PyCFunction)Sbk_QSqlQueryFunc_isActive, METH_NOARGS},
    {"isForwardOnly", (PyCFunction)Sbk_QSqlQueryFunc_isForwardOnly, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSqlQueryFunc_isNull, METH_O},
    {"isSelect", (PyCFunction)Sbk_QSqlQueryFunc_isSelect, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlQueryFunc_isValid, METH_NOARGS},
    {"last", (PyCFunction)Sbk_QSqlQueryFunc_last, METH_NOARGS},
    {"lastError", (PyCFunction)Sbk_QSqlQueryFunc_lastError, METH_NOARGS},
    {"lastInsertId", (PyCFunction)Sbk_QSqlQueryFunc_lastInsertId, METH_NOARGS},
    {"lastQuery", (PyCFunction)Sbk_QSqlQueryFunc_lastQuery, METH_NOARGS},
    {"next", (PyCFunction)Sbk_QSqlQueryFunc_next, METH_NOARGS},
    {"nextResult", (PyCFunction)Sbk_QSqlQueryFunc_nextResult, METH_NOARGS},
    {"numRowsAffected", (PyCFunction)Sbk_QSqlQueryFunc_numRowsAffected, METH_NOARGS},
    {"numericalPrecisionPolicy", (PyCFunction)Sbk_QSqlQueryFunc_numericalPrecisionPolicy, METH_NOARGS},
    {"prepare", (PyCFunction)Sbk_QSqlQueryFunc_prepare, METH_O},
    {"previous", (PyCFunction)Sbk_QSqlQueryFunc_previous, METH_NOARGS},
    {"record", (PyCFunction)Sbk_QSqlQueryFunc_record, METH_NOARGS},
    {"result", (PyCFunction)Sbk_QSqlQueryFunc_result, METH_NOARGS},
    {"seek", (PyCFunction)Sbk_QSqlQueryFunc_seek, METH_VARARGS|METH_KEYWORDS},
    {"setForwardOnly", (PyCFunction)Sbk_QSqlQueryFunc_setForwardOnly, METH_O},
    {"setNumericalPrecisionPolicy", (PyCFunction)Sbk_QSqlQueryFunc_setNumericalPrecisionPolicy, METH_O},
    {"size", (PyCFunction)Sbk_QSqlQueryFunc_size, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QSqlQueryFunc_value, METH_O},

    {"__copy__", (PyCFunction)Sbk_QSqlQuery___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlQuery_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlQuery_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlQuery_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlQuery",
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
    /*tp_traverse*/         Sbk_QSqlQuery_traverse,
    /*tp_clear*/            Sbk_QSqlQuery_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlQuery_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlQuery_Init,
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
static void QSqlQuery_BatchExecutionMode_PythonToCpp_QSqlQuery_BatchExecutionMode(PyObject* pyIn, void* cppOut) {
    *((::QSqlQuery::BatchExecutionMode*)cppOut) = (::QSqlQuery::BatchExecutionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlQuery_BatchExecutionMode_PythonToCpp_QSqlQuery_BatchExecutionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX]))
        return QSqlQuery_BatchExecutionMode_PythonToCpp_QSqlQuery_BatchExecutionMode;
    return 0;
}
static PyObject* QSqlQuery_BatchExecutionMode_CppToPython_QSqlQuery_BatchExecutionMode(const void* cppIn) {
    int castCppIn = *((::QSqlQuery::BatchExecutionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlQuery_PythonToCpp_QSqlQuery_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlQuery_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlQuery_PythonToCpp_QSqlQuery_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlQuery_Type))
        return QSqlQuery_PythonToCpp_QSqlQuery_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlQuery_PTR_CppToPython_QSqlQuery(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlQuery*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlQuery_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlQuery_COPY_CppToPython_QSqlQuery(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlQuery_Type, new ::QSqlQuery(*((::QSqlQuery*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlQuery_PythonToCpp_QSqlQuery_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlQuery*)cppOut) = *((::QSqlQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlQuery_PythonToCpp_QSqlQuery_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlQuery_Type))
        return QSqlQuery_PythonToCpp_QSqlQuery_COPY;
    return 0;
}

// Implicit conversions.
static void QSqlResultPTR_PythonToCpp_QSqlQuery(PyObject* pyIn, void* cppOut) {
    *((::QSqlQuery*)cppOut) = ::QSqlQuery(((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_QSqlResultPTR_PythonToCpp_QSqlQuery_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], pyIn))
        return QSqlResultPTR_PythonToCpp_QSqlQuery;
    return 0;
}

void init_QSqlQuery(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlQuery_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlQuery", "QSqlQuery",
        &Sbk_QSqlQuery_Type, &Shiboken::callCppDestructor< ::QSqlQuery >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlQuery_Type,
        QSqlQuery_PythonToCpp_QSqlQuery_PTR,
        is_QSqlQuery_PythonToCpp_QSqlQuery_PTR_Convertible,
        QSqlQuery_PTR_CppToPython_QSqlQuery,
        QSqlQuery_COPY_CppToPython_QSqlQuery);

    Shiboken::Conversions::registerConverterName(converter, "QSqlQuery");
    Shiboken::Conversions::registerConverterName(converter, "QSqlQuery*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlQuery&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlQuery).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlQuery_PythonToCpp_QSqlQuery_COPY,
        is_QSqlQuery_PythonToCpp_QSqlQuery_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlResultPTR_PythonToCpp_QSqlQuery,
        is_QSqlResultPTR_PythonToCpp_QSqlQuery_Convertible);

    // Initialization of enums.

    // Initialization of enum 'BatchExecutionMode'.
    SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlQuery_Type,
        "BatchExecutionMode",
        "PySide.QtSql.QSqlQuery.BatchExecutionMode",
        "QSqlQuery::BatchExecutionMode");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX],
        &Sbk_QSqlQuery_Type, "ValuesAsRows", (long) QSqlQuery::ValuesAsRows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX],
        &Sbk_QSqlQuery_Type, "ValuesAsColumns", (long) QSqlQuery::ValuesAsColumns))
        return ;
    // Register converter for enum 'QSqlQuery::BatchExecutionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX],
            QSqlQuery_BatchExecutionMode_CppToPython_QSqlQuery_BatchExecutionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlQuery_BatchExecutionMode_PythonToCpp_QSqlQuery_BatchExecutionMode,
            is_QSqlQuery_BatchExecutionMode_PythonToCpp_QSqlQuery_BatchExecutionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLQUERY_BATCHEXECUTIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlQuery::BatchExecutionMode");
        Shiboken::Conversions::registerConverterName(converter, "BatchExecutionMode");
    }
    // End of 'BatchExecutionMode' enum.


    qRegisterMetaType< ::QSqlQuery::BatchExecutionMode >("QSqlQuery::BatchExecutionMode");
}
