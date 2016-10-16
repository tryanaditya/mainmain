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

#include "qsqlresult_wrapper.h"

// Extra includes
#include <QSize>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <QVector>
#include <qsqldriver.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>
#include <qsqlresult.h>


// Native ---------------------------------------------------------

QSqlResultWrapper::QSqlResultWrapper(const QSqlDriver * db) : QSqlResult(db) {
    // ... middle
}

void QSqlResultWrapper::bindValue(const QString & placeholder, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bindValue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::bindValue(placeholder, val, type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &placeholder),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &val),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::bindValue(int pos, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bindValue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::bindValue(pos, val, type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iNN)",
        pos,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &val),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QVariant QSqlResultWrapper::data(int i)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.data()' not implemented.");
        return ::QVariant();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        i
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::exec()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "exec_"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::exec();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.exec_", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::fetch(int i)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetch"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetch()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        i
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.fetch", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::fetchFirst()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchFirst"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetchFirst()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.fetchFirst", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::fetchLast()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchLast"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetchLast()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.fetchLast", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::fetchNext()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchNext"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::fetchNext();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.fetchNext", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::fetchPrevious()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchPrevious"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::fetchPrevious();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.fetchPrevious", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QSqlResultWrapper::handle() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "handle"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::handle();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.handle", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::isNull(int i)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isNull"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.isNull()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        i
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.isNull", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QSqlResultWrapper::lastInsertId() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "lastInsertId"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::lastInsertId();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.lastInsertId", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QSqlResultWrapper::numRowsAffected()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "numRowsAffected"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.numRowsAffected()' not implemented.");
        return ((int)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.numRowsAffected", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::prepare(const QString & query)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "prepare"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::prepare(query);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &query)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.prepare", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSqlRecord QSqlResultWrapper::record() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSqlRecord();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "record"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::record();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSqlRecord();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.record", Shiboken::SbkType< QSqlRecord >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSqlRecord();
    }
    ::QSqlRecord cppResult = ::QSqlRecord();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::reset(const QString & sqlquery)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.reset()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &sqlquery)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlResultWrapper::savePrepare(const QString & sqlquery)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "savePrepare"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::savePrepare(sqlquery);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &sqlquery)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.savePrepare", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlResultWrapper::setActive(bool a)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setActive"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setActive(a);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &a)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::setAt(int at)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setAt(at);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        at
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::setForwardOnly(bool forward)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setForwardOnly"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setForwardOnly(forward);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &forward)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::setLastError(const QSqlError & e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setLastError"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setLastError(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], &e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::setQuery(const QString & query)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setQuery(query);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &query)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlResultWrapper::setSelect(bool s)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSelect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlResult::setSelect(s);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &s)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QSqlResultWrapper::size()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "size"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.size()' not implemented.");
        return ((int)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlResult.size", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSqlResultWrapper::~QSqlResultWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlResult_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QSqlResult' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlResult >()))
        return -1;

    ::QSqlResultWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSqlResult", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlResult(const QSqlDriver*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlResult(const QSqlDriver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResult_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QSqlDriver* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QSqlResult(const QSqlDriver*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSqlResultWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlResult >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlResult_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlResult_Init_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDriver", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlResult", overloads);
        return -1;
}

static PyObject* Sbk_QSqlResultFunc_addBindValue(PyObject* self, PyObject* args)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addBindValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // addBindValue(QVariant,QFlags<QSql::ParamTypeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_addBindValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QSql::ParamTypeFlag> cppArg1 = ((::QFlags<QSql::ParamTypeFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

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

    Sbk_QSqlResultFunc_addBindValue_TypeError:
        const char* overloads[] = {"QVariant, PySide.QtSql.QSql.ParamType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlResult.addBindValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_at(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // at()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlResult*>(cppSelf)->at();
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

static PyObject* Sbk_QSqlResultFunc_bindValue(PyObject* self, PyObject* args)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "bindValue", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
    // 1: bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2])))) {
        overloadId = 1; // bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), (pyArgs[2])))) {
        overloadId = 0; // bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_bindValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindValue(const QString & placeholder, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QSql::ParamTypeFlag> cppArg2 = ((::QFlags<QSql::ParamTypeFlag>)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindValue(QString,QVariant,QFlags<QSql::ParamTypeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::bindValue(cppArg0, cppArg1, cppArg2) : cppSelf->bindValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // bindValue(int pos, const QVariant & val, QFlags<QSql::ParamTypeFlag> type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QSql::ParamTypeFlag> cppArg2 = ((::QFlags<QSql::ParamTypeFlag>)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // bindValue(int,QVariant,QFlags<QSql::ParamTypeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::bindValue(cppArg0, cppArg1, cppArg2) : cppSelf->bindValue(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_bindValue_TypeError:
        const char* overloads[] = {"unicode, QVariant, PySide.QtSql.QSql.ParamType", "int, QVariant, PySide.QtSql.QSql.ParamType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlResult.bindValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_bindValueType(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: bindValueType(QString)const
    // 1: bindValueType(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // bindValueType(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // bindValueType(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_bindValueType_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // bindValueType(const QString & placeholder) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // bindValueType(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QSql::ParamTypeFlag> cppResult = const_cast<const ::QSqlResult*>(cppSelf)->bindValueType(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
            }
            break;
        }
        case 1: // bindValueType(int pos) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // bindValueType(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QSql::ParamTypeFlag> cppResult = const_cast<const ::QSqlResult*>(cppSelf)->bindValueType(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QFLAGS_QSQL_PARAMTYPEFLAG__IDX]), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_bindValueType_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.bindValueType", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_bindingSyntax(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bindingSyntax()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlResult::BindingSyntax cppResult = const_cast<const ::QSqlResult*>(cppSelf)->bindingSyntax();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlResultFunc_boundValue(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSqlResultFunc_boundValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // boundValue(const QString & placeholder) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // boundValue(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QSqlResult*>(cppSelf)->boundValue(cppArg0);
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
                QVariant cppResult = const_cast<const ::QSqlResult*>(cppSelf)->boundValue(cppArg0);
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

    Sbk_QSqlResultFunc_boundValue_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.boundValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_boundValueCount(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundValueCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlResult*>(cppSelf)->boundValueCount();
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

static PyObject* Sbk_QSqlResultFunc_boundValueName(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boundValueName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // boundValueName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_boundValueName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // boundValueName(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlResult*>(cppSelf)->boundValueName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_boundValueName_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.boundValueName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_boundValues(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundValues()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QVariant > & cppResult = const_cast<const ::QSqlResult*>(cppSelf)->boundValues();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtSqlTypeConverters[SBK_QTSQL_QVECTOR_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlResultFunc_clear(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QSqlResultFunc_data(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: data(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // data(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_data_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // data(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.data()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = cppSelf->data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_data_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.data", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_detachFromResultSet(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // detachFromResultSet()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->detachFromResultSet();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlResultFunc_driver(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // driver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QSqlDriver * cppResult = const_cast<const ::QSqlResult*>(cppSelf)->driver();
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

static PyObject* Sbk_QSqlResultFunc_execBatch(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlResult.execBatch(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:execBatch", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: execBatch(bool)
    if (numArgs == 0) {
        overloadId = 0; // execBatch(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // execBatch(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_execBatch_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arrayBind");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlResult.execBatch(): got multiple values for keyword argument 'arrayBind'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QSqlResultFunc_execBatch_TypeError;
            }
        }
        bool cppArg0 = false;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // execBatch(bool)
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

    Sbk_QSqlResultFunc_execBatch_TypeError:
        const char* overloads[] = {"bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlResult.execBatch", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_exec_(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::exec() : cppSelf->exec();
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

static PyObject* Sbk_QSqlResultFunc_executedQuery(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // executedQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlResult*>(cppSelf)->executedQuery();
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

static PyObject* Sbk_QSqlResultFunc_fetch(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fetch(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fetch(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_fetch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fetch(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetch()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->fetch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_fetch_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.fetch", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_fetchFirst(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fetchFirst()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetchFirst()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->fetchFirst();
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

static PyObject* Sbk_QSqlResultFunc_fetchLast(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fetchLast()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.fetchLast()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->fetchLast();
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

static PyObject* Sbk_QSqlResultFunc_fetchNext(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fetchNext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::fetchNext() : cppSelf->fetchNext();
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

static PyObject* Sbk_QSqlResultFunc_fetchPrevious(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fetchPrevious()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::fetchPrevious() : cppSelf->fetchPrevious();
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

static PyObject* Sbk_QSqlResultFunc_handle(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlResult*>(cppSelf)->::QSqlResult::handle() : const_cast<const ::QSqlResult*>(cppSelf)->handle();
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

static PyObject* Sbk_QSqlResultFunc_hasOutValues(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasOutValues()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlResult*>(cppSelf)->hasOutValues();
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

static PyObject* Sbk_QSqlResultFunc_isActive(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlResult*>(cppSelf)->isActive();
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

static PyObject* Sbk_QSqlResultFunc_isForwardOnly(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isForwardOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlResult*>(cppSelf)->isForwardOnly();
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

static PyObject* Sbk_QSqlResultFunc_isNull(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isNull(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // isNull(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_isNull_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isNull(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.isNull()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->isNull(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_isNull_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.isNull", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_isSelect(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlResult*>(cppSelf)->isSelect();
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

static PyObject* Sbk_QSqlResultFunc_isValid(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlResult*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSqlResultFunc_lastError(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlError cppResult = const_cast<const ::QSqlResult*>(cppSelf)->lastError();
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

static PyObject* Sbk_QSqlResultFunc_lastInsertId(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastInsertId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlResult*>(cppSelf)->::QSqlResult::lastInsertId() : const_cast<const ::QSqlResult*>(cppSelf)->lastInsertId();
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

static PyObject* Sbk_QSqlResultFunc_lastQuery(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastQuery()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlResult*>(cppSelf)->lastQuery();
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

static PyObject* Sbk_QSqlResultFunc_nextResult(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QSqlResultFunc_numRowsAffected(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numRowsAffected()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.numRowsAffected()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->numRowsAffected();
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

static PyObject* Sbk_QSqlResultFunc_numericalPrecisionPolicy(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numericalPrecisionPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSql::NumericalPrecisionPolicy cppResult = const_cast<const ::QSqlResult*>(cppSelf)->numericalPrecisionPolicy();
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

static PyObject* Sbk_QSqlResultFunc_prepare(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSqlResultFunc_prepare_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // prepare(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::prepare(cppArg0) : cppSelf->prepare(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_prepare_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.prepare", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_record(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // record()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlRecord cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlResult*>(cppSelf)->::QSqlResult::record() : const_cast<const ::QSqlResult*>(cppSelf)->record();
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

static PyObject* Sbk_QSqlResultFunc_reset(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reset(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // reset(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_reset_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reset(QString)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.reset()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->reset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_reset_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.reset", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_savePrepare(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: savePrepare(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // savePrepare(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_savePrepare_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // savePrepare(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::savePrepare(cppArg0) : cppSelf->savePrepare(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlResultFunc_savePrepare_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.savePrepare", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setActive(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActive(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setActive(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setActive_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActive(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setActive(cppArg0) : cppSelf->setActive(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setActive_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setActive", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setAt(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setAt(cppArg0) : cppSelf->setAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setAt", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setForwardOnly(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForwardOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setForwardOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setForwardOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setForwardOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setForwardOnly(cppArg0) : cppSelf->setForwardOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setForwardOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setForwardOnly", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setLastError(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastError(QSqlError)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (pyArg)))) {
        overloadId = 0; // setLastError(QSqlError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setLastError_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSqlError cppArg0_local = ::QSqlError(::QString(), ::QString(), ((::QSqlError::ErrorType)0), ((int)0));
        ::QSqlError* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setLastError(QSqlError)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setLastError(*cppArg0) : cppSelf->setLastError(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setLastError_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlError", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setLastError", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setNumericalPrecisionPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setNumericalPrecisionPolicy_TypeError;

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

    Sbk_QSqlResultFunc_setNumericalPrecisionPolicy_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.NumericalPrecisionPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setNumericalPrecisionPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setQuery(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQuery(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setQuery(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setQuery_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setQuery(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setQuery(cppArg0) : cppSelf->setQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setQuery_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setQuery", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_setSelect(PyObject* self, PyObject* pyArg)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelect(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSelect(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlResultFunc_setSelect_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelect(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlResult::setSelect(cppArg0) : cppSelf->setSelect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlResultFunc_setSelect_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlResult.setSelect", overloads);
        return 0;
}

static PyObject* Sbk_QSqlResultFunc_size(PyObject* self)
{
    ::QSqlResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlResult.size()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->size();
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

static PyMethodDef Sbk_QSqlResult_methods[] = {
    {"addBindValue", (PyCFunction)Sbk_QSqlResultFunc_addBindValue, METH_VARARGS},
    {"at", (PyCFunction)Sbk_QSqlResultFunc_at, METH_NOARGS},
    {"bindValue", (PyCFunction)Sbk_QSqlResultFunc_bindValue, METH_VARARGS},
    {"bindValueType", (PyCFunction)Sbk_QSqlResultFunc_bindValueType, METH_O},
    {"bindingSyntax", (PyCFunction)Sbk_QSqlResultFunc_bindingSyntax, METH_NOARGS},
    {"boundValue", (PyCFunction)Sbk_QSqlResultFunc_boundValue, METH_O},
    {"boundValueCount", (PyCFunction)Sbk_QSqlResultFunc_boundValueCount, METH_NOARGS},
    {"boundValueName", (PyCFunction)Sbk_QSqlResultFunc_boundValueName, METH_O},
    {"boundValues", (PyCFunction)Sbk_QSqlResultFunc_boundValues, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QSqlResultFunc_clear, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QSqlResultFunc_data, METH_O},
    {"detachFromResultSet", (PyCFunction)Sbk_QSqlResultFunc_detachFromResultSet, METH_NOARGS},
    {"driver", (PyCFunction)Sbk_QSqlResultFunc_driver, METH_NOARGS},
    {"execBatch", (PyCFunction)Sbk_QSqlResultFunc_execBatch, METH_VARARGS|METH_KEYWORDS},
    {"exec_", (PyCFunction)Sbk_QSqlResultFunc_exec_, METH_NOARGS},
    {"executedQuery", (PyCFunction)Sbk_QSqlResultFunc_executedQuery, METH_NOARGS},
    {"fetch", (PyCFunction)Sbk_QSqlResultFunc_fetch, METH_O},
    {"fetchFirst", (PyCFunction)Sbk_QSqlResultFunc_fetchFirst, METH_NOARGS},
    {"fetchLast", (PyCFunction)Sbk_QSqlResultFunc_fetchLast, METH_NOARGS},
    {"fetchNext", (PyCFunction)Sbk_QSqlResultFunc_fetchNext, METH_NOARGS},
    {"fetchPrevious", (PyCFunction)Sbk_QSqlResultFunc_fetchPrevious, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QSqlResultFunc_handle, METH_NOARGS},
    {"hasOutValues", (PyCFunction)Sbk_QSqlResultFunc_hasOutValues, METH_NOARGS},
    {"isActive", (PyCFunction)Sbk_QSqlResultFunc_isActive, METH_NOARGS},
    {"isForwardOnly", (PyCFunction)Sbk_QSqlResultFunc_isForwardOnly, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSqlResultFunc_isNull, METH_O},
    {"isSelect", (PyCFunction)Sbk_QSqlResultFunc_isSelect, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlResultFunc_isValid, METH_NOARGS},
    {"lastError", (PyCFunction)Sbk_QSqlResultFunc_lastError, METH_NOARGS},
    {"lastInsertId", (PyCFunction)Sbk_QSqlResultFunc_lastInsertId, METH_NOARGS},
    {"lastQuery", (PyCFunction)Sbk_QSqlResultFunc_lastQuery, METH_NOARGS},
    {"nextResult", (PyCFunction)Sbk_QSqlResultFunc_nextResult, METH_NOARGS},
    {"numRowsAffected", (PyCFunction)Sbk_QSqlResultFunc_numRowsAffected, METH_NOARGS},
    {"numericalPrecisionPolicy", (PyCFunction)Sbk_QSqlResultFunc_numericalPrecisionPolicy, METH_NOARGS},
    {"prepare", (PyCFunction)Sbk_QSqlResultFunc_prepare, METH_O},
    {"record", (PyCFunction)Sbk_QSqlResultFunc_record, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_QSqlResultFunc_reset, METH_O},
    {"savePrepare", (PyCFunction)Sbk_QSqlResultFunc_savePrepare, METH_O},
    {"setActive", (PyCFunction)Sbk_QSqlResultFunc_setActive, METH_O},
    {"setAt", (PyCFunction)Sbk_QSqlResultFunc_setAt, METH_O},
    {"setForwardOnly", (PyCFunction)Sbk_QSqlResultFunc_setForwardOnly, METH_O},
    {"setLastError", (PyCFunction)Sbk_QSqlResultFunc_setLastError, METH_O},
    {"setNumericalPrecisionPolicy", (PyCFunction)Sbk_QSqlResultFunc_setNumericalPrecisionPolicy, METH_O},
    {"setQuery", (PyCFunction)Sbk_QSqlResultFunc_setQuery, METH_O},
    {"setSelect", (PyCFunction)Sbk_QSqlResultFunc_setSelect, METH_O},
    {"size", (PyCFunction)Sbk_QSqlResultFunc_size, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlResult_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlResult_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlResult_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlResult",
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
    /*tp_traverse*/         Sbk_QSqlResult_traverse,
    /*tp_clear*/            Sbk_QSqlResult_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlResult_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlResult_Init,
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
static void QSqlResult_BindingSyntax_PythonToCpp_QSqlResult_BindingSyntax(PyObject* pyIn, void* cppOut) {
    *((::QSqlResult::BindingSyntax*)cppOut) = (::QSqlResult::BindingSyntax) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlResult_BindingSyntax_PythonToCpp_QSqlResult_BindingSyntax_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX]))
        return QSqlResult_BindingSyntax_PythonToCpp_QSqlResult_BindingSyntax;
    return 0;
}
static PyObject* QSqlResult_BindingSyntax_CppToPython_QSqlResult_BindingSyntax(const void* cppIn) {
    int castCppIn = *((::QSqlResult::BindingSyntax*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX], castCppIn);

}

static void QSqlResult_VirtualHookOperation_PythonToCpp_QSqlResult_VirtualHookOperation(PyObject* pyIn, void* cppOut) {
    *((::QSqlResult::VirtualHookOperation*)cppOut) = (::QSqlResult::VirtualHookOperation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlResult_VirtualHookOperation_PythonToCpp_QSqlResult_VirtualHookOperation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX]))
        return QSqlResult_VirtualHookOperation_PythonToCpp_QSqlResult_VirtualHookOperation;
    return 0;
}
static PyObject* QSqlResult_VirtualHookOperation_CppToPython_QSqlResult_VirtualHookOperation(const void* cppIn) {
    int castCppIn = *((::QSqlResult::VirtualHookOperation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlResult_PythonToCpp_QSqlResult_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlResult_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlResult_PythonToCpp_QSqlResult_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlResult_Type))
        return QSqlResult_PythonToCpp_QSqlResult_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlResult_PTR_CppToPython_QSqlResult(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlResult*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlResult_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSqlResult(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlResult_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlResult", "QSqlResult*",
        &Sbk_QSqlResult_Type, &Shiboken::callCppDestructor< ::QSqlResult >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlResult_Type,
        QSqlResult_PythonToCpp_QSqlResult_PTR,
        is_QSqlResult_PythonToCpp_QSqlResult_PTR_Convertible,
        QSqlResult_PTR_CppToPython_QSqlResult);

    Shiboken::Conversions::registerConverterName(converter, "QSqlResult");
    Shiboken::Conversions::registerConverterName(converter, "QSqlResult*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlResult&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlResult).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlResultWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'BindingSyntax'.
    SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlResult_Type,
        "BindingSyntax",
        "PySide.QtSql.QSqlResult.BindingSyntax",
        "QSqlResult::BindingSyntax");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX],
        &Sbk_QSqlResult_Type, "PositionalBinding", (long) QSqlResult::PositionalBinding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX],
        &Sbk_QSqlResult_Type, "NamedBinding", (long) QSqlResult::NamedBinding))
        return ;
    // Register converter for enum 'QSqlResult::BindingSyntax'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX],
            QSqlResult_BindingSyntax_CppToPython_QSqlResult_BindingSyntax);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlResult_BindingSyntax_PythonToCpp_QSqlResult_BindingSyntax,
            is_QSqlResult_BindingSyntax_PythonToCpp_QSqlResult_BindingSyntax_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_BINDINGSYNTAX_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlResult::BindingSyntax");
        Shiboken::Conversions::registerConverterName(converter, "BindingSyntax");
    }
    // End of 'BindingSyntax' enum.

    // Initialization of enum 'VirtualHookOperation'.
    SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlResult_Type,
        "VirtualHookOperation",
        "PySide.QtSql.QSqlResult.VirtualHookOperation",
        "QSqlResult::VirtualHookOperation");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX],
        &Sbk_QSqlResult_Type, "BatchOperation", (long) QSqlResult::BatchOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX],
        &Sbk_QSqlResult_Type, "DetachFromResultSet", (long) QSqlResult::DetachFromResultSet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX],
        &Sbk_QSqlResult_Type, "SetNumericalPrecision", (long) QSqlResult::SetNumericalPrecision))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX],
        &Sbk_QSqlResult_Type, "NextResult", (long) QSqlResult::NextResult))
        return ;
    // Register converter for enum 'QSqlResult::VirtualHookOperation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX],
            QSqlResult_VirtualHookOperation_CppToPython_QSqlResult_VirtualHookOperation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlResult_VirtualHookOperation_PythonToCpp_QSqlResult_VirtualHookOperation,
            is_QSqlResult_VirtualHookOperation_PythonToCpp_QSqlResult_VirtualHookOperation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLRESULT_VIRTUALHOOKOPERATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlResult::VirtualHookOperation");
        Shiboken::Conversions::registerConverterName(converter, "VirtualHookOperation");
    }
    // End of 'VirtualHookOperation' enum.


    qRegisterMetaType< ::QSqlResult::BindingSyntax >("QSqlResult::BindingSyntax");
    qRegisterMetaType< ::QSqlResult::VirtualHookOperation >("QSqlResult::VirtualHookOperation");
}
