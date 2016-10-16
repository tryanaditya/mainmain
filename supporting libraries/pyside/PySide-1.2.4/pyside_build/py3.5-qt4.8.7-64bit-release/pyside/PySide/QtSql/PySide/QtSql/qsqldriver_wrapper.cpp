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
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtsql_python.h"

#include "qsqldriver_wrapper.h"

// Extra includes
#include <QList>
#include <QSize>
#include <QSqlError>
#include <QSqlIndex>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsqldriver.h>
#include <qsqlerror.h>
#include <qsqlfield.h>
#include <qsqlindex.h>
#include <qsqlrecord.h>
#include <qsqlresult.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSqlDriverWrapper::QSqlDriverWrapper(QObject * parent) : QSqlDriver(parent) {
    // ... middle
}

bool QSqlDriverWrapper::beginTransaction()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "beginTransaction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::beginTransaction();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.beginTransaction", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlDriverWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QSqlDriverWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.close()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QSqlDriverWrapper::commitTransaction()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "commitTransaction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::commitTransaction();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.commitTransaction", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlDriverWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSqlResult * QSqlDriverWrapper::createResult() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QSqlResult*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createResult"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.createResult()' not implemented.");
        return ((::QSqlResult*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QSqlResult*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRESULT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.createResult", Shiboken::SbkType< QSqlResult >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QSqlResult*)0);
    }
    ::QSqlResult* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlDriverWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QSqlDriverWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QString QSqlDriverWrapper::escapeIdentifier(const QString & identifier, QSqlDriver::IdentifierType type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "escapeIdentifier"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::escapeIdentifier(identifier, type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &identifier),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.escapeIdentifier", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlDriverWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSqlDriverWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QString QSqlDriverWrapper::formatValue(const QSqlField & field, bool trimStrings) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "formatValue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::formatValue(field, trimStrings);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], &field),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &trimStrings)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.formatValue", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlDriverWrapper::hasFeature(QSqlDriver::DriverFeature f) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasFeature"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.hasFeature()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX]), &f)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.hasFeature", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlDriverWrapper::isOpen() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isOpen"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::isOpen();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.isOpen", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlDriverWrapper::open(const QString & db, const QString & user, const QString & password, const QString & host, int port, const QString & connOpts)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "open"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.open()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNNiN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &db),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &user),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &password),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &host),
        port,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &connOpts)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSqlIndex QSqlDriverWrapper::primaryIndex(const QString & tableName) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSqlIndex(::QString(), ::QString());
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "primaryIndex"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::primaryIndex(tableName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &tableName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSqlIndex(::QString(), ::QString());
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.primaryIndex", Shiboken::SbkType< QSqlIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSqlIndex(::QString(), ::QString());
    }
    ::QSqlIndex cppResult = ::QSqlIndex(::QString(), ::QString());
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSqlRecord QSqlDriverWrapper::record(const QString & tableName) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSqlRecord();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "record"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::record(tableName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &tableName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSqlRecord();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.record", Shiboken::SbkType< QSqlRecord >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSqlRecord();
    }
    ::QSqlRecord cppResult = ::QSqlRecord();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlDriverWrapper::rollbackTransaction()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rollbackTransaction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::rollbackTransaction();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.rollbackTransaction", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlDriverWrapper::setLastError(const QSqlError & e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setLastError"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::setLastError(e);
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

void QSqlDriverWrapper::setOpen(bool o)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setOpen"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::setOpen(o);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &o)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlDriverWrapper::setOpenError(bool e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setOpenError"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::setOpenError(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &e)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QString QSqlDriverWrapper::sqlStatement(QSqlDriver::StatementType type, const QString & tableName, const QSqlRecord & rec, bool preparedStatement) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sqlStatement"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::sqlStatement(type, tableName, rec, preparedStatement);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX]), &type),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &tableName),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &rec),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &preparedStatement)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.sqlStatement", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStringList QSqlDriverWrapper::tables(QSql::TableType tableType) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tables"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlDriver::tables(tableType);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX]), &tableType)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QStringList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriver.tables", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlDriverWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject* QSqlDriverWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSqlDriver::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSqlDriverWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSqlDriver::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSqlDriverWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSqlDriverWrapper* >(this));
        return QSqlDriver::qt_metacast(_clname);
}

QSqlDriverWrapper::~QSqlDriverWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlDriver_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QSqlDriver' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlDriver >()))
        return -1;

    ::QSqlDriverWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QSqlDriver", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlDriver(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QSqlDriver(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlDriver(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriver_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlDriver_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QSqlDriver(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QSqlDriverWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QSqlDriverWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlDriver >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlDriver_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QSqlDriver_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver", overloads);
        return -1;
}

static PyObject* Sbk_QSqlDriverFunc_beginTransaction(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beginTransaction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::beginTransaction() : cppSelf->beginTransaction();
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

static PyObject* Sbk_QSqlDriverFunc_close(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.close()' not implemented.");
                return 0;
            }
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

static PyObject* Sbk_QSqlDriverFunc_commitTransaction(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // commitTransaction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::commitTransaction() : cppSelf->commitTransaction();
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

static PyObject* Sbk_QSqlDriverFunc_createResult(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createResult()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.createResult()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlResult * cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->createResult();
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

static PyObject* Sbk_QSqlDriverFunc_escapeIdentifier(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "escapeIdentifier", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: escapeIdentifier(QString,QSqlDriver::IdentifierType)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // escapeIdentifier(QString,QSqlDriver::IdentifierType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_escapeIdentifier_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSqlDriver::IdentifierType cppArg1 = ((::QSqlDriver::IdentifierType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // escapeIdentifier(QString,QSqlDriver::IdentifierType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::escapeIdentifier(cppArg0, cppArg1) : const_cast<const ::QSqlDriver*>(cppSelf)->escapeIdentifier(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_escapeIdentifier_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriver.IdentifierType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.escapeIdentifier", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_formatValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.formatValue(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.formatValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:formatValue", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: formatValue(QSqlField,bool)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // formatValue(QSqlField,bool)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // formatValue(QSqlField,bool)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_formatValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "trimStrings");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.formatValue(): got multiple values for keyword argument 'trimStrings'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QSqlDriverFunc_formatValue_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
        ::QSqlField* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // formatValue(QSqlField,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::formatValue(*cppArg0, cppArg1) : const_cast<const ::QSqlDriver*>(cppSelf)->formatValue(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_formatValue_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlField, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.formatValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_hasFeature(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasFeature(QSqlDriver::DriverFeature)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX]), (pyArg)))) {
        overloadId = 0; // hasFeature(QSqlDriver::DriverFeature)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_hasFeature_TypeError;

    // Call function/method
    {
        ::QSqlDriver::DriverFeature cppArg0 = ((::QSqlDriver::DriverFeature)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasFeature(QSqlDriver::DriverFeature)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.hasFeature()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->hasFeature(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_hasFeature_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDriver.DriverFeature", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.hasFeature", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_isIdentifierEscaped(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isIdentifierEscaped", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isIdentifierEscaped(QString,QSqlDriver::IdentifierType)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // isIdentifierEscaped(QString,QSqlDriver::IdentifierType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_isIdentifierEscaped_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSqlDriver::IdentifierType cppArg1 = ((::QSqlDriver::IdentifierType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isIdentifierEscaped(QString,QSqlDriver::IdentifierType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->isIdentifierEscaped(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_isIdentifierEscaped_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriver.IdentifierType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.isIdentifierEscaped", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_isIdentifierEscapedImplementation(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isIdentifierEscapedImplementation", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isIdentifierEscapedImplementation(QString,QSqlDriver::IdentifierType)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // isIdentifierEscapedImplementation(QString,QSqlDriver::IdentifierType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_isIdentifierEscapedImplementation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSqlDriver::IdentifierType cppArg1 = ((::QSqlDriver::IdentifierType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isIdentifierEscapedImplementation(QString,QSqlDriver::IdentifierType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->isIdentifierEscapedImplementation(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_isIdentifierEscapedImplementation_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriver.IdentifierType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.isIdentifierEscapedImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_isOpen(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOpen()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::isOpen() : const_cast<const ::QSqlDriver*>(cppSelf)->isOpen();
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

static PyObject* Sbk_QSqlDriverFunc_isOpenError(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOpenError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->isOpenError();
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

static PyObject* Sbk_QSqlDriverFunc_lastError(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlError cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->lastError();
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

static PyObject* Sbk_QSqlDriverFunc_numericalPrecisionPolicy(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numericalPrecisionPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSql::NumericalPrecisionPolicy cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->numericalPrecisionPolicy();
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

static PyObject* Sbk_QSqlDriverFunc_open(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:open", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: open(QString,QString,QString,QString,int,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // open(QString,QString,QString,QString,int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // open(QString,QString,QString,QString,int,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // open(QString,QString,QString,QString,int,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // open(QString,QString,QString,QString,int,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // open(QString,QString,QString,QString,int,QString)
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
                            overloadId = 0; // open(QString,QString,QString,QString,int,QString)
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_open_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "user");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): got multiple values for keyword argument 'user'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QSqlDriverFunc_open_TypeError;
            }
            value = PyDict_GetItemString(kwds, "password");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): got multiple values for keyword argument 'password'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QSqlDriverFunc_open_TypeError;
            }
            value = PyDict_GetItemString(kwds, "host");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): got multiple values for keyword argument 'host'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_QSqlDriverFunc_open_TypeError;
            }
            value = PyDict_GetItemString(kwds, "port");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): got multiple values for keyword argument 'port'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QSqlDriverFunc_open_TypeError;
            }
            value = PyDict_GetItemString(kwds, "connOpts");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlDriver.open(): got multiple values for keyword argument 'connOpts'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5]))))
                    goto Sbk_QSqlDriverFunc_open_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QString();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QString cppArg5 = QString();
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // open(QString,QString,QString,QString,int,QString)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriver.open()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->open(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_open_TypeError:
        const char* overloads[] = {"unicode, unicode = QString(), unicode = QString(), unicode = QString(), int = -1, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.open", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_primaryIndex(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_primaryIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // primaryIndex(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlIndex cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::primaryIndex(cppArg0) : const_cast<const ::QSqlDriver*>(cppSelf)->primaryIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_primaryIndex_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.primaryIndex", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_record(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_record_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // record(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlRecord cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::record(cppArg0) : const_cast<const ::QSqlDriver*>(cppSelf)->record(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_record_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.record", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_rollbackTransaction(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rollbackTransaction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::rollbackTransaction() : cppSelf->rollbackTransaction();
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

static PyObject* Sbk_QSqlDriverFunc_setLastError(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastError(QSqlError)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLERROR_IDX], (pyArg)))) {
        overloadId = 0; // setLastError(QSqlError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_setLastError_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::setLastError(*cppArg0) : cppSelf->setLastError(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDriverFunc_setLastError_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlError", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.setLastError", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_setNumericalPrecisionPolicy(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_NUMERICALPRECISIONPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_setNumericalPrecisionPolicy_TypeError;

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

    Sbk_QSqlDriverFunc_setNumericalPrecisionPolicy_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.NumericalPrecisionPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.setNumericalPrecisionPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_setOpen(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOpen(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOpen(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_setOpen_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOpen(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::setOpen(cppArg0) : cppSelf->setOpen(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDriverFunc_setOpen_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.setOpen", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_setOpenError(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOpenError(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOpenError(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_setOpenError_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOpenError(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlDriver::setOpenError(cppArg0) : cppSelf->setOpenError(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlDriverFunc_setOpenError_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.setOpenError", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_sqlStatement(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sqlStatement", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: sqlStatement(QSqlDriver::StatementType,QString,QSqlRecord,bool)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))) {
        overloadId = 0; // sqlStatement(QSqlDriver::StatementType,QString,QSqlRecord,bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_sqlStatement_TypeError;

    // Call function/method
    {
        ::QSqlDriver::StatementType cppArg0 = ((::QSqlDriver::StatementType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QSqlRecord cppArg2_local = ::QSqlRecord();
        ::QSqlRecord* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        bool cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // sqlStatement(QSqlDriver::StatementType,QString,QSqlRecord,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::sqlStatement(cppArg0, cppArg1, *cppArg2, cppArg3) : const_cast<const ::QSqlDriver*>(cppSelf)->sqlStatement(cppArg0, cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_sqlStatement_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlDriver.StatementType, unicode, PySide.QtSql.QSqlRecord, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.sqlStatement", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_stripDelimiters(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "stripDelimiters", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: stripDelimiters(QString,QSqlDriver::IdentifierType)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // stripDelimiters(QString,QSqlDriver::IdentifierType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_stripDelimiters_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSqlDriver::IdentifierType cppArg1 = ((::QSqlDriver::IdentifierType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // stripDelimiters(QString,QSqlDriver::IdentifierType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->stripDelimiters(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_stripDelimiters_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriver.IdentifierType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.stripDelimiters", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_stripDelimitersImplementation(PyObject* self, PyObject* args)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "stripDelimitersImplementation", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: stripDelimitersImplementation(QString,QSqlDriver::IdentifierType)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // stripDelimitersImplementation(QString,QSqlDriver::IdentifierType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_stripDelimitersImplementation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSqlDriver::IdentifierType cppArg1 = ((::QSqlDriver::IdentifierType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // stripDelimitersImplementation(QString,QSqlDriver::IdentifierType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->stripDelimitersImplementation(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_stripDelimitersImplementation_TypeError:
        const char* overloads[] = {"unicode, PySide.QtSql.QSqlDriver.IdentifierType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlDriver.stripDelimitersImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_subscribeToNotification(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subscribeToNotification(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // subscribeToNotification(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_subscribeToNotification_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // subscribeToNotification(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->subscribeToNotification(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_subscribeToNotification_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.subscribeToNotification", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_subscribeToNotificationImplementation(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subscribeToNotificationImplementation(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // subscribeToNotificationImplementation(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_subscribeToNotificationImplementation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // subscribeToNotificationImplementation(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->subscribeToNotificationImplementation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_subscribeToNotificationImplementation_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.subscribeToNotificationImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_subscribedToNotifications(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // subscribedToNotifications()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->subscribedToNotifications();
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

static PyObject* Sbk_QSqlDriverFunc_subscribedToNotificationsImplementation(PyObject* self)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // subscribedToNotificationsImplementation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSqlDriver*>(cppSelf)->subscribedToNotificationsImplementation();
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

static PyObject* Sbk_QSqlDriverFunc_tables(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: tables(QSql::TableType)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQL_TABLETYPE_IDX]), (pyArg)))) {
        overloadId = 0; // tables(QSql::TableType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_tables_TypeError;

    // Call function/method
    {
        ::QSql::TableType cppArg0 = ((::QSql::TableType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // tables(QSql::TableType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlDriver*>(cppSelf)->::QSqlDriver::tables(cppArg0) : const_cast<const ::QSqlDriver*>(cppSelf)->tables(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_tables_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSql.TableType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.tables", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_unsubscribeFromNotification(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unsubscribeFromNotification(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // unsubscribeFromNotification(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_unsubscribeFromNotification_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unsubscribeFromNotification(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->unsubscribeFromNotification(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_unsubscribeFromNotification_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.unsubscribeFromNotification", overloads);
        return 0;
}

static PyObject* Sbk_QSqlDriverFunc_unsubscribeFromNotificationImplementation(PyObject* self, PyObject* pyArg)
{
    ::QSqlDriver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriver*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unsubscribeFromNotificationImplementation(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // unsubscribeFromNotificationImplementation(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlDriverFunc_unsubscribeFromNotificationImplementation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unsubscribeFromNotificationImplementation(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->unsubscribeFromNotificationImplementation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlDriverFunc_unsubscribeFromNotificationImplementation_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlDriver.unsubscribeFromNotificationImplementation", overloads);
        return 0;
}

static PyMethodDef Sbk_QSqlDriver_methods[] = {
    {"beginTransaction", (PyCFunction)Sbk_QSqlDriverFunc_beginTransaction, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QSqlDriverFunc_close, METH_NOARGS},
    {"commitTransaction", (PyCFunction)Sbk_QSqlDriverFunc_commitTransaction, METH_NOARGS},
    {"createResult", (PyCFunction)Sbk_QSqlDriverFunc_createResult, METH_NOARGS},
    {"escapeIdentifier", (PyCFunction)Sbk_QSqlDriverFunc_escapeIdentifier, METH_VARARGS},
    {"formatValue", (PyCFunction)Sbk_QSqlDriverFunc_formatValue, METH_VARARGS|METH_KEYWORDS},
    {"hasFeature", (PyCFunction)Sbk_QSqlDriverFunc_hasFeature, METH_O},
    {"isIdentifierEscaped", (PyCFunction)Sbk_QSqlDriverFunc_isIdentifierEscaped, METH_VARARGS},
    {"isIdentifierEscapedImplementation", (PyCFunction)Sbk_QSqlDriverFunc_isIdentifierEscapedImplementation, METH_VARARGS},
    {"isOpen", (PyCFunction)Sbk_QSqlDriverFunc_isOpen, METH_NOARGS},
    {"isOpenError", (PyCFunction)Sbk_QSqlDriverFunc_isOpenError, METH_NOARGS},
    {"lastError", (PyCFunction)Sbk_QSqlDriverFunc_lastError, METH_NOARGS},
    {"numericalPrecisionPolicy", (PyCFunction)Sbk_QSqlDriverFunc_numericalPrecisionPolicy, METH_NOARGS},
    {"open", (PyCFunction)Sbk_QSqlDriverFunc_open, METH_VARARGS|METH_KEYWORDS},
    {"primaryIndex", (PyCFunction)Sbk_QSqlDriverFunc_primaryIndex, METH_O},
    {"record", (PyCFunction)Sbk_QSqlDriverFunc_record, METH_O},
    {"rollbackTransaction", (PyCFunction)Sbk_QSqlDriverFunc_rollbackTransaction, METH_NOARGS},
    {"setLastError", (PyCFunction)Sbk_QSqlDriverFunc_setLastError, METH_O},
    {"setNumericalPrecisionPolicy", (PyCFunction)Sbk_QSqlDriverFunc_setNumericalPrecisionPolicy, METH_O},
    {"setOpen", (PyCFunction)Sbk_QSqlDriverFunc_setOpen, METH_O},
    {"setOpenError", (PyCFunction)Sbk_QSqlDriverFunc_setOpenError, METH_O},
    {"sqlStatement", (PyCFunction)Sbk_QSqlDriverFunc_sqlStatement, METH_VARARGS},
    {"stripDelimiters", (PyCFunction)Sbk_QSqlDriverFunc_stripDelimiters, METH_VARARGS},
    {"stripDelimitersImplementation", (PyCFunction)Sbk_QSqlDriverFunc_stripDelimitersImplementation, METH_VARARGS},
    {"subscribeToNotification", (PyCFunction)Sbk_QSqlDriverFunc_subscribeToNotification, METH_O},
    {"subscribeToNotificationImplementation", (PyCFunction)Sbk_QSqlDriverFunc_subscribeToNotificationImplementation, METH_O},
    {"subscribedToNotifications", (PyCFunction)Sbk_QSqlDriverFunc_subscribedToNotifications, METH_NOARGS},
    {"subscribedToNotificationsImplementation", (PyCFunction)Sbk_QSqlDriverFunc_subscribedToNotificationsImplementation, METH_NOARGS},
    {"tables", (PyCFunction)Sbk_QSqlDriverFunc_tables, METH_O},
    {"unsubscribeFromNotification", (PyCFunction)Sbk_QSqlDriverFunc_unsubscribeFromNotification, METH_O},
    {"unsubscribeFromNotificationImplementation", (PyCFunction)Sbk_QSqlDriverFunc_unsubscribeFromNotificationImplementation, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlDriver_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlDriver_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlDriver_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlDriver",
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
    /*tp_traverse*/         Sbk_QSqlDriver_traverse,
    /*tp_clear*/            Sbk_QSqlDriver_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlDriver_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlDriver_Init,
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

static void* Sbk_QSqlDriver_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSqlDriver*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSqlDriver_DriverFeature_PythonToCpp_QSqlDriver_DriverFeature(PyObject* pyIn, void* cppOut) {
    *((::QSqlDriver::DriverFeature*)cppOut) = (::QSqlDriver::DriverFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlDriver_DriverFeature_PythonToCpp_QSqlDriver_DriverFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX]))
        return QSqlDriver_DriverFeature_PythonToCpp_QSqlDriver_DriverFeature;
    return 0;
}
static PyObject* QSqlDriver_DriverFeature_CppToPython_QSqlDriver_DriverFeature(const void* cppIn) {
    int castCppIn = *((::QSqlDriver::DriverFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX], castCppIn);

}

static void QSqlDriver_StatementType_PythonToCpp_QSqlDriver_StatementType(PyObject* pyIn, void* cppOut) {
    *((::QSqlDriver::StatementType*)cppOut) = (::QSqlDriver::StatementType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlDriver_StatementType_PythonToCpp_QSqlDriver_StatementType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX]))
        return QSqlDriver_StatementType_PythonToCpp_QSqlDriver_StatementType;
    return 0;
}
static PyObject* QSqlDriver_StatementType_CppToPython_QSqlDriver_StatementType(const void* cppIn) {
    int castCppIn = *((::QSqlDriver::StatementType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX], castCppIn);

}

static void QSqlDriver_IdentifierType_PythonToCpp_QSqlDriver_IdentifierType(PyObject* pyIn, void* cppOut) {
    *((::QSqlDriver::IdentifierType*)cppOut) = (::QSqlDriver::IdentifierType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlDriver_IdentifierType_PythonToCpp_QSqlDriver_IdentifierType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX]))
        return QSqlDriver_IdentifierType_PythonToCpp_QSqlDriver_IdentifierType;
    return 0;
}
static PyObject* QSqlDriver_IdentifierType_CppToPython_QSqlDriver_IdentifierType(const void* cppIn) {
    int castCppIn = *((::QSqlDriver::IdentifierType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlDriver_PythonToCpp_QSqlDriver_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlDriver_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlDriver_PythonToCpp_QSqlDriver_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlDriver_Type))
        return QSqlDriver_PythonToCpp_QSqlDriver_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlDriver_PTR_CppToPython_QSqlDriver(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSqlDriver*)cppIn, &Sbk_QSqlDriver_Type);

}

void init_QSqlDriver(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlDriver_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlDriver", "QSqlDriver*",
        &Sbk_QSqlDriver_Type, &Shiboken::callCppDestructor< ::QSqlDriver >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlDriver_Type,
        QSqlDriver_PythonToCpp_QSqlDriver_PTR,
        is_QSqlDriver_PythonToCpp_QSqlDriver_PTR_Convertible,
        QSqlDriver_PTR_CppToPython_QSqlDriver);

    Shiboken::Conversions::registerConverterName(converter, "QSqlDriver");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDriver*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDriver&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlDriver).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlDriverWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSqlDriver_Type, &Sbk_QSqlDriver_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'DriverFeature'.
    SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlDriver_Type,
        "DriverFeature",
        "PySide.QtSql.QSqlDriver.DriverFeature",
        "QSqlDriver::DriverFeature");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "Transactions", (long) QSqlDriver::Transactions))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "QuerySize", (long) QSqlDriver::QuerySize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "BLOB", (long) QSqlDriver::BLOB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "Unicode", (long) QSqlDriver::Unicode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "PreparedQueries", (long) QSqlDriver::PreparedQueries))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "NamedPlaceholders", (long) QSqlDriver::NamedPlaceholders))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "PositionalPlaceholders", (long) QSqlDriver::PositionalPlaceholders))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "LastInsertId", (long) QSqlDriver::LastInsertId))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "BatchOperations", (long) QSqlDriver::BatchOperations))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "SimpleLocking", (long) QSqlDriver::SimpleLocking))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "LowPrecisionNumbers", (long) QSqlDriver::LowPrecisionNumbers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "EventNotifications", (long) QSqlDriver::EventNotifications))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "FinishQuery", (long) QSqlDriver::FinishQuery))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
        &Sbk_QSqlDriver_Type, "MultipleResultSets", (long) QSqlDriver::MultipleResultSets))
        return ;
    // Register converter for enum 'QSqlDriver::DriverFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX],
            QSqlDriver_DriverFeature_CppToPython_QSqlDriver_DriverFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlDriver_DriverFeature_PythonToCpp_QSqlDriver_DriverFeature,
            is_QSqlDriver_DriverFeature_PythonToCpp_QSqlDriver_DriverFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_DRIVERFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlDriver::DriverFeature");
        Shiboken::Conversions::registerConverterName(converter, "DriverFeature");
    }
    // End of 'DriverFeature' enum.

    // Initialization of enum 'StatementType'.
    SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlDriver_Type,
        "StatementType",
        "PySide.QtSql.QSqlDriver.StatementType",
        "QSqlDriver::StatementType");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
        &Sbk_QSqlDriver_Type, "WhereStatement", (long) QSqlDriver::WhereStatement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
        &Sbk_QSqlDriver_Type, "SelectStatement", (long) QSqlDriver::SelectStatement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
        &Sbk_QSqlDriver_Type, "UpdateStatement", (long) QSqlDriver::UpdateStatement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
        &Sbk_QSqlDriver_Type, "InsertStatement", (long) QSqlDriver::InsertStatement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
        &Sbk_QSqlDriver_Type, "DeleteStatement", (long) QSqlDriver::DeleteStatement))
        return ;
    // Register converter for enum 'QSqlDriver::StatementType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX],
            QSqlDriver_StatementType_CppToPython_QSqlDriver_StatementType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlDriver_StatementType_PythonToCpp_QSqlDriver_StatementType,
            is_QSqlDriver_StatementType_PythonToCpp_QSqlDriver_StatementType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_STATEMENTTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlDriver::StatementType");
        Shiboken::Conversions::registerConverterName(converter, "StatementType");
    }
    // End of 'StatementType' enum.

    // Initialization of enum 'IdentifierType'.
    SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlDriver_Type,
        "IdentifierType",
        "PySide.QtSql.QSqlDriver.IdentifierType",
        "QSqlDriver::IdentifierType");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX],
        &Sbk_QSqlDriver_Type, "FieldName", (long) QSqlDriver::FieldName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX],
        &Sbk_QSqlDriver_Type, "TableName", (long) QSqlDriver::TableName))
        return ;
    // Register converter for enum 'QSqlDriver::IdentifierType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX],
            QSqlDriver_IdentifierType_CppToPython_QSqlDriver_IdentifierType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlDriver_IdentifierType_PythonToCpp_QSqlDriver_IdentifierType,
            is_QSqlDriver_IdentifierType_PythonToCpp_QSqlDriver_IdentifierType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDENTIFIERTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlDriver::IdentifierType");
        Shiboken::Conversions::registerConverterName(converter, "IdentifierType");
    }
    // End of 'IdentifierType' enum.

    PySide::Signal::registerSignals(&Sbk_QSqlDriver_Type, &::QSqlDriver::staticMetaObject);

    qRegisterMetaType< ::QSqlDriver::DriverFeature >("QSqlDriver::DriverFeature");
    qRegisterMetaType< ::QSqlDriver::StatementType >("QSqlDriver::StatementType");
    qRegisterMetaType< ::QSqlDriver::IdentifierType >("QSqlDriver::IdentifierType");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSqlDriver_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSqlDriver_Type, &::QSqlDriver::staticMetaObject, sizeof(::QSqlDriver));
}
