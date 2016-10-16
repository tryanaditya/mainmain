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

#include "qsqltablemodel_wrapper.h"

// Extra includes
#include <QList>
#include <QMap>
#include <QSize>
#include <QSqlIndex>
#include <QStringList>
#include <pysideconversions.h>
#include <qabstractitemmodel.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdatastream.h>
#include <qmetaobject.h>
#include <qmimedata.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsize.h>
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlindex.h>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSqlTableModelWrapper::QSqlTableModelWrapper(QObject * parent, QSqlDatabase db) : QSqlTableModel(parent, db) {
    // ... middle
}

QModelIndex QSqlTableModelWrapper::buddy(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "buddy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::buddy(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.buddy", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::canFetchMore(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canFetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::canFetchMore(parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.canFetchMore", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::childEvent(QChildEvent * arg__1)
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

void QSqlTableModelWrapper::clear()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clear"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::clear();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QSqlTableModelWrapper::columnCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "columnCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::columnCount(parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.columnCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::connectNotify(const char * signal)
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

void QSqlTableModelWrapper::customEvent(QEvent * arg__1)
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

QVariant QSqlTableModelWrapper::data(const QModelIndex & idx, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::data(idx, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &idx),
        role
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

bool QSqlTableModelWrapper::deleteRowFromTable(int row)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deleteRowFromTable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::deleteRowFromTable(row);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        row
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.deleteRowFromTable", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::disconnectNotify(const char * signal)
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

bool QSqlTableModelWrapper::dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropMimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractTableModel::dropMimeData(data, action, row, column, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNiiN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], data),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), &action),
        row,
        column,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.dropMimeData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSqlTableModelWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QSqlTableModelWrapper::fetchMore(const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::fetchMore(parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QFlags<Qt::ItemFlag> QSqlTableModelWrapper::flags(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "flags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::flags(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.flags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QSqlTableModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "headerData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::headerData(section, orientation, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iNi)",
        section,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &orientation),
        role
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.headerData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndex QSqlTableModelWrapper::index(int row, int column, const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "index"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractTableModel::index(row, column, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        row,
        column,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.index", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::insertColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::insertColumns(column, count, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        column,
        count,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.insertColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::insertRowIntoTable(const QSqlRecord & values)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertRowIntoTable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::insertRowIntoTable(values);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &values)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.insertRowIntoTable", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::insertRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::insertRows(row, count, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        row,
        count,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.insertRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMap<int, QVariant > QSqlTableModelWrapper::itemData(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QMap<int, QVariant >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::itemData(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QMap<int, QVariant >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtSqlTypeConverters[SBK_QTSQL_QMAP_INT_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.itemData", "map", pyResult->ob_type->tp_name);
        return ::QMap<int, QVariant >();
    }
    ::QMap<int, QVariant > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndexList QSqlTableModelWrapper::match(const QModelIndex & start, int role, const QVariant & value, int hits, QFlags<Qt::MatchFlag> flags) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndexList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "match"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::match(start, role, value, hits, flags);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiNiN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &start),
        role,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value),
        hits,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), &flags)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndexList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.match", "QModelIndexList", pyResult->ob_type->tp_name);
        return ::QModelIndexList();
    }
    ::QModelIndexList cppResult = ::QModelIndexList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMimeData * QSqlTableModelWrapper::mimeData(const QModelIndexList & indexes) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMimeData*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::mimeData(indexes);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &indexes)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QMimeData*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.mimeData", Shiboken::SbkType< QMimeData >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMimeData*)0);
    }
    ::QMimeData* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

QStringList QSqlTableModelWrapper::mimeTypes() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeTypes"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::mimeTypes();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QStringList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.mimeTypes", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QSqlTableModelWrapper::orderByClause() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "orderByClause"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::orderByClause();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.orderByClause", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::queryChange()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "queryChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::queryChange();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QSqlTableModelWrapper::removeColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::removeColumns(column, count, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        column,
        count,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.removeColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::removeRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::removeRows(row, count, parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        row,
        count,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.removeRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::revert()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "revert"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::revert();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlTableModelWrapper::revertRow(int row)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "revertRow"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::revertRow(row);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        row
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QSqlTableModelWrapper::rowCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rowCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::rowCount(parent);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.rowCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::select()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "select"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::select();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.select", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QSqlTableModelWrapper::selectStatement() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "selectStatement"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::selectStatement();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.selectStatement", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::setData(const QModelIndex & index, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::setData(index, value, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNi)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value),
        role
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.setData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::setEditStrategy(QSqlTableModel::EditStrategy strategy)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setEditStrategy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::setEditStrategy(strategy);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX]), &strategy)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlTableModelWrapper::setFilter(const QString & filter)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::setFilter(filter);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &filter)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QSqlTableModelWrapper::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHeaderData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlQueryModel::setHeaderData(section, orientation, value, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iNNi)",
        section,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &orientation),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value),
        role
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.setHeaderData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::setItemData(const QModelIndex & index, const QMap<int, QVariant > & roles)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setItemData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::setItemData(index, roles);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SbkPySide_QtSqlTypeConverters[SBK_QTSQL_QMAP_INT_QVARIANT_IDX], &roles)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.setItemData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::setSort(int column, Qt::SortOrder order)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSort"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::setSort(column, order);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        column,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), &order)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlTableModelWrapper::setTable(const QString & tableName)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setTable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::setTable(tableName);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &tableName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSqlTableModelWrapper::sort(int column, Qt::SortOrder order)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sort"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::sort(column, order);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        column,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), &order)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSize QSqlTableModelWrapper::span(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "span"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::span(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.span", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSqlTableModelWrapper::submit()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "submit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::submit();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.submit", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::DropAction> QSqlTableModelWrapper::supportedDropActions() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::DropAction>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportedDropActions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::supportedDropActions();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<Qt::DropAction>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.supportedDropActions", Shiboken::SbkType< QFlags<Qt::DropAction> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::DropAction>)0);
    }
    ::QFlags<Qt::DropAction> cppResult = ((::QFlags<Qt::DropAction>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSqlTableModelWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QSqlTableModelWrapper::updateRowInTable(int row, const QSqlRecord & values)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateRowInTable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSqlTableModel::updateRowInTable(row, values);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        row,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &values)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlTableModel.updateRowInTable", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QSqlTableModelWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSqlTableModel::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSqlTableModelWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSqlTableModel::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSqlTableModelWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSqlTableModelWrapper* >(this));
        return QSqlTableModel::qt_metacast(_clname);
}

QSqlTableModelWrapper::~QSqlTableModelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlTableModel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"db", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlTableModel >()))
        return -1;

    ::QSqlTableModelWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QSqlTableModel", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlTableModel(QObject*,QSqlDatabase)
    if (numArgs == 0) {
        overloadId = 0; // QSqlTableModel(QObject*,QSqlDatabase)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QSqlTableModel(QObject*,QSqlDatabase)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[1])))) {
            overloadId = 0; // QSqlTableModel(QObject*,QSqlDatabase)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModel_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlTableModel_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "db");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel(): got multiple values for keyword argument 'db'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], (pyArgs[1]))))
                    goto Sbk_QSqlTableModel_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QSqlDatabase cppArg1 = QSqlDatabase();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QSqlTableModel(QObject*,QSqlDatabase)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QSqlTableModelWrapper(cppArg0, cppArg1);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QSqlTableModelWrapper(cppArg0, cppArg1);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlTableModel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlTableModel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QSqlTableModel_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None, PySide.QtSql.QSqlDatabase = QSqlDatabase()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel", overloads);
        return -1;
}

static PyObject* Sbk_QSqlTableModelFunc_clear(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::clear() : cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlTableModelFunc_data(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.data(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.data(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:data", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: data(QModelIndex,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // data(QModelIndex,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // data(QModelIndex,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_data_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.data(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QSqlTableModelFunc_data_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = Qt::DisplayRole;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // data(QModelIndex,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::data(*cppArg0, cppArg1) : const_cast<const ::QSqlTableModel*>(cppSelf)->data(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_data_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.data", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_database(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // database()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlDatabase cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->database();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDATABASE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlTableModelFunc_deleteRowFromTable(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteRowFromTable(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // deleteRowFromTable(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_deleteRowFromTable_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // deleteRowFromTable(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::deleteRowFromTable(cppArg0) : cppSelf->deleteRowFromTable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_deleteRowFromTable_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.deleteRowFromTable", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_editStrategy(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // editStrategy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlTableModel::EditStrategy cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->editStrategy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlTableModelFunc_fieldIndex(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fieldIndex(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fieldIndex(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_fieldIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fieldIndex(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->fieldIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_fieldIndex_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.fieldIndex", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_filter(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->filter();
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

static PyObject* Sbk_QSqlTableModelFunc_flags(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: flags(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // flags(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_flags_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // flags(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::flags(*cppArg0) : const_cast<const ::QSqlTableModel*>(cppSelf)->flags(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_flags_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.flags", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_headerData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.headerData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.headerData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:headerData", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: headerData(int,Qt::Orientation,int)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // headerData(int,Qt::Orientation,int)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // headerData(int,Qt::Orientation,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_headerData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.headerData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QSqlTableModelFunc_headerData_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::Orientation cppArg1 = ((::Qt::Orientation)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = Qt::DisplayRole;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // headerData(int,Qt::Orientation,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::headerData(cppArg0, cppArg1, cppArg2) : const_cast<const ::QSqlTableModel*>(cppSelf)->headerData(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_headerData_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Orientation, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.headerData", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_indexInQuery(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexInQuery(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // indexInQuery(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_indexInQuery_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // indexInQuery(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->indexInQuery(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_indexInQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.indexInQuery", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_insertRecord(PyObject* self, PyObject* args)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertRecord", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertRecord(int,QSqlRecord)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertRecord(int,QSqlRecord)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_insertRecord_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlRecord cppArg1_local = ::QSqlRecord();
        ::QSqlRecord* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insertRecord(int,QSqlRecord)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->insertRecord(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_insertRecord_TypeError:
        const char* overloads[] = {"int, PySide.QtSql.QSqlRecord", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.insertRecord", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_insertRowIntoTable(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertRowIntoTable(QSqlRecord)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArg)))) {
        overloadId = 0; // insertRowIntoTable(QSqlRecord)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_insertRowIntoTable_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSqlRecord cppArg0_local = ::QSqlRecord();
        ::QSqlRecord* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // insertRowIntoTable(QSqlRecord)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::insertRowIntoTable(*cppArg0) : cppSelf->insertRowIntoTable(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_insertRowIntoTable_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlRecord", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.insertRowIntoTable", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_insertRows(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.insertRows(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.insertRows(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:insertRows", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insertRows(int,int,QModelIndex)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // insertRows(int,int,QModelIndex)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 0; // insertRows(int,int,QModelIndex)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_insertRows_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.insertRows(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QSqlTableModelFunc_insertRows_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QModelIndex cppArg2_local = QModelIndex();
        ::QModelIndex* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // insertRows(int,int,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::insertRows(cppArg0, cppArg1, *cppArg2) : cppSelf->insertRows(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_insertRows_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.insertRows", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_isDirty(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isDirty(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // isDirty(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_isDirty_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isDirty(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->isDirty(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_isDirty_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.isDirty", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_orderByClause(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // orderByClause()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::orderByClause() : const_cast<const ::QSqlTableModel*>(cppSelf)->orderByClause();
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

static PyObject* Sbk_QSqlTableModelFunc_primaryKey(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // primaryKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlIndex cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->primaryKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlTableModelFunc_removeColumns(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeColumns(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeColumns(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:removeColumns", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: removeColumns(int,int,QModelIndex)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // removeColumns(int,int,QModelIndex)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 0; // removeColumns(int,int,QModelIndex)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_removeColumns_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeColumns(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QSqlTableModelFunc_removeColumns_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QModelIndex cppArg2_local = QModelIndex();
        ::QModelIndex* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // removeColumns(int,int,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::removeColumns(cppArg0, cppArg1, *cppArg2) : cppSelf->removeColumns(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_removeColumns_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.removeColumns", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_removeRows(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeRows(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeRows(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:removeRows", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: removeRows(int,int,QModelIndex)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // removeRows(int,int,QModelIndex)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 0; // removeRows(int,int,QModelIndex)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_removeRows_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.removeRows(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QSqlTableModelFunc_removeRows_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QModelIndex cppArg2_local = QModelIndex();
        ::QModelIndex* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // removeRows(int,int,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::removeRows(cppArg0, cppArg1, *cppArg2) : cppSelf->removeRows(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_removeRows_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.removeRows", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_revert(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revert()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::revert() : cppSelf->revert();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlTableModelFunc_revertAll(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revertAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->revertAll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlTableModelFunc_revertRow(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: revertRow(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // revertRow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_revertRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // revertRow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::revertRow(cppArg0) : cppSelf->revertRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_revertRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.revertRow", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_rowCount(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.rowCount(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:rowCount", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: rowCount(QModelIndex)const
    if (numArgs == 0) {
        overloadId = 0; // rowCount(QModelIndex)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // rowCount(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_rowCount_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.rowCount(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QSqlTableModelFunc_rowCount_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // rowCount(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::rowCount(*cppArg0) : const_cast<const ::QSqlTableModel*>(cppSelf)->rowCount(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_rowCount_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.rowCount", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_select(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // select()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::select() : cppSelf->select();
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

static PyObject* Sbk_QSqlTableModelFunc_selectStatement(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectStatement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSqlTableModel*>(cppSelf)->::QSqlTableModel::selectStatement() : const_cast<const ::QSqlTableModel*>(cppSelf)->selectStatement();
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

static PyObject* Sbk_QSqlTableModelFunc_setData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.setData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.setData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setData", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setData(QModelIndex,QVariant,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setData(QModelIndex,QVariant,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setData(QModelIndex,QVariant,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlTableModel.setData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QSqlTableModelFunc_setData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = Qt::EditRole;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setData(QModelIndex,QVariant,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::setData(*cppArg0, cppArg1, cppArg2) : cppSelf->setData(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_setData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, QVariant, int = Qt.EditRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.setData", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setEditStrategy(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEditStrategy(QSqlTableModel::EditStrategy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX]), (pyArg)))) {
        overloadId = 0; // setEditStrategy(QSqlTableModel::EditStrategy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setEditStrategy_TypeError;

    // Call function/method
    {
        ::QSqlTableModel::EditStrategy cppArg0 = ((::QSqlTableModel::EditStrategy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEditStrategy(QSqlTableModel::EditStrategy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::setEditStrategy(cppArg0) : cppSelf->setEditStrategy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setEditStrategy_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlTableModel.EditStrategy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.setEditStrategy", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setFilter(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFilter(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFilter(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setFilter_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFilter(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::setFilter(cppArg0) : cppSelf->setFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setFilter_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.setFilter", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setPrimaryKey(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrimaryKey(QSqlIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (pyArg)))) {
        overloadId = 0; // setPrimaryKey(QSqlIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setPrimaryKey_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSqlIndex cppArg0_local = ::QSqlIndex(::QString(), ::QString());
        ::QSqlIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPrimaryKey(QSqlIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrimaryKey(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setPrimaryKey_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.setPrimaryKey", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setQuery(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQuery(QSqlQuery)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], (pyArg)))) {
        overloadId = 0; // setQuery(QSqlQuery)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setQuery_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSqlQuery cppArg0_local = ::QSqlQuery(((::QSqlResult*)0));
        ::QSqlQuery* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setQuery(QSqlQuery)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setQuery(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setQuery_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.setQuery", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setRecord(PyObject* self, PyObject* args)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRecord", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRecord(int,QSqlRecord)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArgs[1])))) {
        overloadId = 0; // setRecord(int,QSqlRecord)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setRecord_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlRecord cppArg1_local = ::QSqlRecord();
        ::QSqlRecord* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setRecord(int,QSqlRecord)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setRecord(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_setRecord_TypeError:
        const char* overloads[] = {"int, PySide.QtSql.QSqlRecord", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.setRecord", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setSort(PyObject* self, PyObject* args)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSort", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSort(int,Qt::SortOrder)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setSort(int,Qt::SortOrder)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setSort_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = ((::Qt::SortOrder)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSort(int,Qt::SortOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::setSort(cppArg0, cppArg1) : cppSelf->setSort(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setSort_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.setSort", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_setTable(PyObject* self, PyObject* pyArg)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTable(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setTable(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_setTable_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTable(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::setTable(cppArg0) : cppSelf->setTable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_setTable_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlTableModel.setTable", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_sort(PyObject* self, PyObject* args)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sort", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sort(int,Qt::SortOrder)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1])))) {
        overloadId = 0; // sort(int,Qt::SortOrder)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_sort_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = ((::Qt::SortOrder)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sort(int,Qt::SortOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::sort(cppArg0, cppArg1) : cppSelf->sort(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlTableModelFunc_sort_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.sort", overloads);
        return 0;
}

static PyObject* Sbk_QSqlTableModelFunc_submit(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // submit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::submit() : cppSelf->submit();
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

static PyObject* Sbk_QSqlTableModelFunc_submitAll(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // submitAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->submitAll();
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

static PyObject* Sbk_QSqlTableModelFunc_tableName(PyObject* self)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlTableModel*>(cppSelf)->tableName();
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

static PyObject* Sbk_QSqlTableModelFunc_updateRowInTable(PyObject* self, PyObject* args)
{
    ::QSqlTableModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlTableModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "updateRowInTable", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: updateRowInTable(int,QSqlRecord)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArgs[1])))) {
        overloadId = 0; // updateRowInTable(int,QSqlRecord)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlTableModelFunc_updateRowInTable_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlRecord cppArg1_local = ::QSqlRecord();
        ::QSqlRecord* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // updateRowInTable(int,QSqlRecord)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSqlTableModel::updateRowInTable(cppArg0, *cppArg1) : cppSelf->updateRowInTable(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlTableModelFunc_updateRowInTable_TypeError:
        const char* overloads[] = {"int, PySide.QtSql.QSqlRecord", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlTableModel.updateRowInTable", overloads);
        return 0;
}

static PyMethodDef Sbk_QSqlTableModel_methods[] = {
    {"clear", (PyCFunction)Sbk_QSqlTableModelFunc_clear, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QSqlTableModelFunc_data, METH_VARARGS|METH_KEYWORDS},
    {"database", (PyCFunction)Sbk_QSqlTableModelFunc_database, METH_NOARGS},
    {"deleteRowFromTable", (PyCFunction)Sbk_QSqlTableModelFunc_deleteRowFromTable, METH_O},
    {"editStrategy", (PyCFunction)Sbk_QSqlTableModelFunc_editStrategy, METH_NOARGS},
    {"fieldIndex", (PyCFunction)Sbk_QSqlTableModelFunc_fieldIndex, METH_O},
    {"filter", (PyCFunction)Sbk_QSqlTableModelFunc_filter, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QSqlTableModelFunc_flags, METH_O},
    {"headerData", (PyCFunction)Sbk_QSqlTableModelFunc_headerData, METH_VARARGS|METH_KEYWORDS},
    {"indexInQuery", (PyCFunction)Sbk_QSqlTableModelFunc_indexInQuery, METH_O},
    {"insertRecord", (PyCFunction)Sbk_QSqlTableModelFunc_insertRecord, METH_VARARGS},
    {"insertRowIntoTable", (PyCFunction)Sbk_QSqlTableModelFunc_insertRowIntoTable, METH_O},
    {"insertRows", (PyCFunction)Sbk_QSqlTableModelFunc_insertRows, METH_VARARGS|METH_KEYWORDS},
    {"isDirty", (PyCFunction)Sbk_QSqlTableModelFunc_isDirty, METH_O},
    {"orderByClause", (PyCFunction)Sbk_QSqlTableModelFunc_orderByClause, METH_NOARGS},
    {"primaryKey", (PyCFunction)Sbk_QSqlTableModelFunc_primaryKey, METH_NOARGS},
    {"removeColumns", (PyCFunction)Sbk_QSqlTableModelFunc_removeColumns, METH_VARARGS|METH_KEYWORDS},
    {"removeRows", (PyCFunction)Sbk_QSqlTableModelFunc_removeRows, METH_VARARGS|METH_KEYWORDS},
    {"revert", (PyCFunction)Sbk_QSqlTableModelFunc_revert, METH_NOARGS},
    {"revertAll", (PyCFunction)Sbk_QSqlTableModelFunc_revertAll, METH_NOARGS},
    {"revertRow", (PyCFunction)Sbk_QSqlTableModelFunc_revertRow, METH_O},
    {"rowCount", (PyCFunction)Sbk_QSqlTableModelFunc_rowCount, METH_VARARGS|METH_KEYWORDS},
    {"select", (PyCFunction)Sbk_QSqlTableModelFunc_select, METH_NOARGS},
    {"selectStatement", (PyCFunction)Sbk_QSqlTableModelFunc_selectStatement, METH_NOARGS},
    {"setData", (PyCFunction)Sbk_QSqlTableModelFunc_setData, METH_VARARGS|METH_KEYWORDS},
    {"setEditStrategy", (PyCFunction)Sbk_QSqlTableModelFunc_setEditStrategy, METH_O},
    {"setFilter", (PyCFunction)Sbk_QSqlTableModelFunc_setFilter, METH_O},
    {"setPrimaryKey", (PyCFunction)Sbk_QSqlTableModelFunc_setPrimaryKey, METH_O},
    {"setQuery", (PyCFunction)Sbk_QSqlTableModelFunc_setQuery, METH_O},
    {"setRecord", (PyCFunction)Sbk_QSqlTableModelFunc_setRecord, METH_VARARGS},
    {"setSort", (PyCFunction)Sbk_QSqlTableModelFunc_setSort, METH_VARARGS},
    {"setTable", (PyCFunction)Sbk_QSqlTableModelFunc_setTable, METH_O},
    {"sort", (PyCFunction)Sbk_QSqlTableModelFunc_sort, METH_VARARGS},
    {"submit", (PyCFunction)Sbk_QSqlTableModelFunc_submit, METH_NOARGS},
    {"submitAll", (PyCFunction)Sbk_QSqlTableModelFunc_submitAll, METH_NOARGS},
    {"tableName", (PyCFunction)Sbk_QSqlTableModelFunc_tableName, METH_NOARGS},
    {"updateRowInTable", (PyCFunction)Sbk_QSqlTableModelFunc_updateRowInTable, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlTableModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlTableModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlTableModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlTableModel",
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
    /*tp_traverse*/         Sbk_QSqlTableModel_traverse,
    /*tp_clear*/            Sbk_QSqlTableModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlTableModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlTableModel_Init,
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

static void* Sbk_QSqlTableModel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSqlTableModel*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSqlTableModel_EditStrategy_PythonToCpp_QSqlTableModel_EditStrategy(PyObject* pyIn, void* cppOut) {
    *((::QSqlTableModel::EditStrategy*)cppOut) = (::QSqlTableModel::EditStrategy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlTableModel_EditStrategy_PythonToCpp_QSqlTableModel_EditStrategy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX]))
        return QSqlTableModel_EditStrategy_PythonToCpp_QSqlTableModel_EditStrategy;
    return 0;
}
static PyObject* QSqlTableModel_EditStrategy_CppToPython_QSqlTableModel_EditStrategy(const void* cppIn) {
    int castCppIn = *((::QSqlTableModel::EditStrategy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlTableModel_PythonToCpp_QSqlTableModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlTableModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlTableModel_PythonToCpp_QSqlTableModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlTableModel_Type))
        return QSqlTableModel_PythonToCpp_QSqlTableModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlTableModel_PTR_CppToPython_QSqlTableModel(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSqlTableModel*)cppIn, &Sbk_QSqlTableModel_Type);

}

void init_QSqlTableModel(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlTableModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlTableModel", "QSqlTableModel*",
        &Sbk_QSqlTableModel_Type, &Shiboken::callCppDestructor< ::QSqlTableModel >, (SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLQUERYMODEL_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlTableModel_Type,
        QSqlTableModel_PythonToCpp_QSqlTableModel_PTR,
        is_QSqlTableModel_PythonToCpp_QSqlTableModel_PTR_Convertible,
        QSqlTableModel_PTR_CppToPython_QSqlTableModel);

    Shiboken::Conversions::registerConverterName(converter, "QSqlTableModel");
    Shiboken::Conversions::registerConverterName(converter, "QSqlTableModel*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlTableModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlTableModel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlTableModelWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSqlTableModel_Type, &Sbk_QSqlTableModel_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'EditStrategy'.
    SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlTableModel_Type,
        "EditStrategy",
        "PySide.QtSql.QSqlTableModel.EditStrategy",
        "QSqlTableModel::EditStrategy");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX],
        &Sbk_QSqlTableModel_Type, "OnFieldChange", (long) QSqlTableModel::OnFieldChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX],
        &Sbk_QSqlTableModel_Type, "OnRowChange", (long) QSqlTableModel::OnRowChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX],
        &Sbk_QSqlTableModel_Type, "OnManualSubmit", (long) QSqlTableModel::OnManualSubmit))
        return ;
    // Register converter for enum 'QSqlTableModel::EditStrategy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX],
            QSqlTableModel_EditStrategy_CppToPython_QSqlTableModel_EditStrategy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlTableModel_EditStrategy_PythonToCpp_QSqlTableModel_EditStrategy,
            is_QSqlTableModel_EditStrategy_PythonToCpp_QSqlTableModel_EditStrategy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLTABLEMODEL_EDITSTRATEGY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlTableModel::EditStrategy");
        Shiboken::Conversions::registerConverterName(converter, "EditStrategy");
    }
    // End of 'EditStrategy' enum.

    PySide::Signal::registerSignals(&Sbk_QSqlTableModel_Type, &::QSqlTableModel::staticMetaObject);

    qRegisterMetaType< ::QSqlTableModel::EditStrategy >("QSqlTableModel::EditStrategy");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSqlTableModel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSqlTableModel_Type, &::QSqlTableModel::staticMetaObject, sizeof(::QSqlTableModel));
}
