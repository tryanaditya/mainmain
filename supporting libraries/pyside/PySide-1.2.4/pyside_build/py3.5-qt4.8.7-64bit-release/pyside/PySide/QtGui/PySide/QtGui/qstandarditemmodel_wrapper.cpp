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
#include "pyside_qtgui_python.h"

#include "qstandarditemmodel_wrapper.h"

// Extra includes
#include <QList>
#include <QMap>
#include <QSize>
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
#include <qstandarditemmodel.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QStandardItemModelWrapper::QStandardItemModelWrapper(QObject * parent) : QStandardItemModel(parent) {
    // ... middle
}

QStandardItemModelWrapper::QStandardItemModelWrapper(int rows, int columns, QObject * parent) : QStandardItemModel(rows, columns, parent) {
    // ... middle
}

QModelIndex QStandardItemModelWrapper::buddy(const QModelIndex & index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.buddy", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::canFetchMore(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canFetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::canFetchMore(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.canFetchMore", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemModelWrapper::childEvent(QChildEvent * arg__1)
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

int QStandardItemModelWrapper::columnCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "columnCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::columnCount(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.columnCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemModelWrapper::connectNotify(const char * signal)
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

void QStandardItemModelWrapper::customEvent(QEvent * arg__1)
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

QVariant QStandardItemModelWrapper::data(const QModelIndex & index, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::data(index, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

void QStandardItemModelWrapper::disconnectNotify(const char * signal)
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

bool QStandardItemModelWrapper::dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropMimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::dropMimeData(data, action, row, column, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.dropMimeData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QStandardItemModelWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QStandardItemModelWrapper::fetchMore(const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::fetchMore(parent);
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

QFlags<Qt::ItemFlag> QStandardItemModelWrapper::flags(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "flags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::flags(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.flags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::hasChildren(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::hasChildren(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.hasChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QStandardItemModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "headerData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::headerData(section, orientation, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.headerData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndex QStandardItemModelWrapper::index(int row, int column, const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "index"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::index(row, column, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.index", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::insertColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::insertColumns(column, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.insertColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::insertRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::insertRows(row, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.insertRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMap<int, QVariant > QStandardItemModelWrapper::itemData(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QMap<int, QVariant >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::itemData(index);
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
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.itemData", "map", pyResult->ob_type->tp_name);
        return ::QMap<int, QVariant >();
    }
    ::QMap<int, QVariant > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndexList QStandardItemModelWrapper::match(const QModelIndex & start, int role, const QVariant & value, int hits, QFlags<Qt::MatchFlag> flags) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.match", "QModelIndexList", pyResult->ob_type->tp_name);
        return ::QModelIndexList();
    }
    ::QModelIndexList cppResult = ::QModelIndexList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMimeData * QStandardItemModelWrapper::mimeData(const QModelIndexList & indexes) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMimeData*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::mimeData(indexes);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.mimeData", Shiboken::SbkType< QMimeData >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMimeData*)0);
    }
    ::QMimeData* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

QStringList QStandardItemModelWrapper::mimeTypes() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeTypes"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::mimeTypes();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.mimeTypes", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndex QStandardItemModelWrapper::parent(const QModelIndex & child) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::parent(child);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &child)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.parent", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::removeColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::removeColumns(column, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.removeColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::removeRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::removeRows(row, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.removeRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemModelWrapper::revert()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "revert"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::revert();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QStandardItemModelWrapper::rowCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rowCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::rowCount(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.rowCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::setData(const QModelIndex & index, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::setData(index, value, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.setData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHeaderData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::setHeaderData(section, orientation, value, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.setHeaderData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::setItemData(const QModelIndex & index, const QMap<int, QVariant > & roles)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setItemData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::setItemData(index, roles);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], &roles)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.setItemData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemModelWrapper::sort(int column, Qt::SortOrder order)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sort"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::sort(column, order);
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

QSize QStandardItemModelWrapper::span(const QModelIndex & index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.span", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QStandardItemModelWrapper::submit()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "submit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::submit();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.submit", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::DropAction> QStandardItemModelWrapper::supportedDropActions() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::DropAction>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportedDropActions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItemModel::supportedDropActions();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItemModel.supportedDropActions", Shiboken::SbkType< QFlags<Qt::DropAction> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::DropAction>)0);
    }
    ::QFlags<Qt::DropAction> cppResult = ((::QFlags<Qt::DropAction>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemModelWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QStandardItemModelWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QStandardItemModel::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QStandardItemModelWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QStandardItemModel::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QStandardItemModelWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QStandardItemModelWrapper* >(this));
        return QStandardItemModel::qt_metacast(_clname);
}

QStandardItemModelWrapper::~QStandardItemModelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStandardItemModel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStandardItemModel >()))
        return -1;

    ::QStandardItemModelWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOO:QStandardItemModel", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QStandardItemModel(QObject*)
    // 1: QStandardItemModel(int,int,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QStandardItemModel(QObject*)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // QStandardItemModel(int,int,QObject*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
            overloadId = 1; // QStandardItemModel(int,int,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QStandardItemModel(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModel_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStandardItemModel(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QStandardItemModel_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStandardItemModel(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QStandardItemModelWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QStandardItemModelWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QStandardItemModel(int rows, int columns, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QStandardItemModel_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QStandardItemModel(int,int,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QStandardItemModelWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QStandardItemModelWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStandardItemModel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStandardItemModel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QStandardItemModel_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "int, int, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel", overloads);
        return -1;
}

static PyObject* Sbk_QStandardItemModelFunc_appendColumn(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendColumn(QList<QStandardItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArg)))) {
        overloadId = 0; // appendColumn(QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_appendColumn_TypeError;

    // Call function/method
    {
        ::QList<QStandardItem * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendColumn(QList<QStandardItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_appendColumn_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.appendColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_appendRow(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendRow(QStandardItem*)
    // 1: appendRow(QList<QStandardItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArg)))) {
        overloadId = 0; // appendRow(QStandardItem*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArg)))) {
        overloadId = 1; // appendRow(QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_appendRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // appendRow(QStandardItem * item)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QStandardItem* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendRow(QStandardItem*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArg);
            }
            break;
        }
        case 1: // appendRow(const QList<QStandardItem * > & items)
        {
            ::QList<QStandardItem * > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendRow(QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArg);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_appendRow_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStandardItem", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.appendRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_clear(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            // Begin code injection

            Shiboken::BindingManager& bm = Shiboken::BindingManager::instance();
            SbkObject* pyRoot = bm.retrieveWrapper(cppSelf->invisibleRootItem());
            if (pyRoot) {
              Shiboken::Object::destroy(pyRoot, cppSelf->invisibleRootItem());
            }

            for(int r=0, r_max = cppSelf->rowCount(); r < r_max; r++) {
              QList<QStandardItem *> ri = cppSelf->takeRow(0);

              PyObject *pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &ri);
              Shiboken::Object::setParent(Py_None, pyResult);
              Py_XDECREF(pyResult);
            }

            // End of code injection

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

static PyObject* Sbk_QStandardItemModelFunc_columnCount(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.columnCount(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:columnCount", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: columnCount(QModelIndex)const
    if (numArgs == 0) {
        overloadId = 0; // columnCount(QModelIndex)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // columnCount(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_columnCount_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.columnCount(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QStandardItemModelFunc_columnCount_TypeError;
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
            // columnCount(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::columnCount(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->columnCount(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_columnCount_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.columnCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_data(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.data(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.data(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_data_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.data(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemModelFunc_data_TypeError;
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
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::data(*cppArg0, cppArg1) : const_cast<const ::QStandardItemModel*>(cppSelf)->data(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_data_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.data", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_dropMimeData(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "dropMimeData", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: dropMimeData(const QMimeData*,Qt::DropAction,int,int,QModelIndex)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[4])))) {
        overloadId = 0; // dropMimeData(const QMimeData*,Qt::DropAction,int,int,QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_dropMimeData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QMimeData* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::DropAction cppArg1 = ((::Qt::DropAction)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QModelIndex cppArg4_local = ::QModelIndex();
        ::QModelIndex* cppArg4 = &cppArg4_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[4]))
            pythonToCpp[4](pyArgs[4], &cppArg4_local);
        else
            pythonToCpp[4](pyArgs[4], &cppArg4);


        if (!PyErr_Occurred()) {
            // dropMimeData(const QMimeData*,Qt::DropAction,int,int,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::dropMimeData(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4) : cppSelf->dropMimeData(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_dropMimeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMimeData, PySide.QtCore.Qt.DropAction, int, int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.dropMimeData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_findItems(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.findItems(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.findItems(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:findItems", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: findItems(QString,QFlags<Qt::MatchFlag>,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // findItems(QString,QFlags<Qt::MatchFlag>,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // findItems(QString,QFlags<Qt::MatchFlag>,int)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // findItems(QString,QFlags<Qt::MatchFlag>,int)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_findItems_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.findItems(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MATCHFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QStandardItemModelFunc_findItems_TypeError;
            }
            value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.findItems(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_findItems_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::MatchFlag> cppArg1 = Qt::MatchExactly;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // findItems(QString,QFlags<Qt::MatchFlag>,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QStandardItem * > cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->findItems(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_findItems_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.MatchFlags = Qt.MatchExactly, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.findItems", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_flags(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_flags_TypeError;

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
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::flags(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->flags(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_flags_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.flags", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_hasChildren(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.hasChildren(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:hasChildren", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: hasChildren(QModelIndex)const
    if (numArgs == 0) {
        overloadId = 0; // hasChildren(QModelIndex)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // hasChildren(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_hasChildren_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.hasChildren(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QStandardItemModelFunc_hasChildren_TypeError;
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
            // hasChildren(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::hasChildren(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->hasChildren(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_hasChildren_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.hasChildren", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_headerData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.headerData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.headerData(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_headerData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.headerData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_headerData_TypeError;
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
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::headerData(cppArg0, cppArg1, cppArg2) : const_cast<const ::QStandardItemModel*>(cppSelf)->headerData(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_headerData_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Orientation, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.headerData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_horizontalHeaderItem(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: horizontalHeaderItem(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // horizontalHeaderItem(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_horizontalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // horizontalHeaderItem(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->horizontalHeaderItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_horizontalHeaderItem_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.horizontalHeaderItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_index(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.index(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.index(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:index", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: index(int,int,QModelIndex)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // index(int,int,QModelIndex)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 0; // index(int,int,QModelIndex)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_index_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.index(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_index_TypeError;
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
            // index(int,int,QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::index(cppArg0, cppArg1, *cppArg2) : const_cast<const ::QStandardItemModel*>(cppSelf)->index(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_index_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.index", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_indexFromItem(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexFromItem(const QStandardItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArg)))) {
        overloadId = 0; // indexFromItem(const QStandardItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_indexFromItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStandardItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexFromItem(const QStandardItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->indexFromItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_indexFromItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.indexFromItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_insertColumn(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumn(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumn(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:insertColumn", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertColumn(int,QList<QStandardItem*>)
    // 1: insertColumn(int,QModelIndex)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // insertColumn(int,QModelIndex)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
            overloadId = 1; // insertColumn(int,QModelIndex)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertColumn(int,QList<QStandardItem*>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_insertColumn_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertColumn(int column, const QList<QStandardItem * > & items)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QList<QStandardItem * > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertColumn(int,QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertColumn(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // insertColumn(int column, const QModelIndex & parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumn(): got multiple values for keyword argument 'parent'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1]))))
                        goto Sbk_QStandardItemModelFunc_insertColumn_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QModelIndex cppArg1_local = QModelIndex();
            ::QModelIndex* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // insertColumn(int,QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->insertColumn(cppArg0, *cppArg1);
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

    Sbk_QStandardItemModelFunc_insertColumn_TypeError:
        const char* overloads[] = {"int, list", "int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.insertColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_insertColumns(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumns(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumns(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:insertColumns", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insertColumns(int,int,QModelIndex)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // insertColumns(int,int,QModelIndex)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 0; // insertColumns(int,int,QModelIndex)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_insertColumns_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertColumns(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_insertColumns_TypeError;
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
            // insertColumns(int,int,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::insertColumns(cppArg0, cppArg1, *cppArg2) : cppSelf->insertColumns(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_insertColumns_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.insertColumns", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_insertRow(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRow(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRow(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:insertRow", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertRow(int,QStandardItem*)
    // 1: insertRow(int,QList<QStandardItem*>)
    // 2: insertRow(int,QModelIndex)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // insertRow(int,QModelIndex)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
            overloadId = 2; // insertRow(int,QModelIndex)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertRow(int,QStandardItem*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArgs[1])))) {
            overloadId = 1; // insertRow(int,QList<QStandardItem*>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_insertRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertRow(int row, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QStandardItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QStandardItem*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // insertRow(int row, const QList<QStandardItem * > & items)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QList<QStandardItem * > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 2: // insertRow(int row, const QModelIndex & parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRow(): got multiple values for keyword argument 'parent'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1]))))
                        goto Sbk_QStandardItemModelFunc_insertRow_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QModelIndex cppArg1_local = QModelIndex();
            ::QModelIndex* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // insertRow(int,QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->insertRow(cppArg0, *cppArg1);
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

    Sbk_QStandardItemModelFunc_insertRow_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", "int, list", "int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.insertRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_insertRows(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRows(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRows(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_insertRows_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.insertRows(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_insertRows_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::insertRows(cppArg0, cppArg1, *cppArg2) : cppSelf->insertRows(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_insertRows_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.insertRows", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_invisibleRootItem(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invisibleRootItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->invisibleRootItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemModelFunc_item(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.item(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.item(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:item", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: item(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // item(int,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // item(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_item_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.item(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemModelFunc_item_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // item(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->item(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_item_TypeError:
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.item", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_itemData(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemData(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // itemData(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_itemData_TypeError;

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
            // itemData(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMap<int, QVariant > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::itemData(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->itemData(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_itemData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.itemData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_itemFromIndex(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemFromIndex(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // itemFromIndex(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_itemFromIndex_TypeError;

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
            // itemFromIndex(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->itemFromIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_itemFromIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.itemFromIndex", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_itemPrototype(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // itemPrototype()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->itemPrototype();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemModelFunc_mimeData(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mimeData(QModelIndexList)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], (pyArg)))) {
        overloadId = 0; // mimeData(QModelIndexList)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_mimeData_TypeError;

    // Call function/method
    {
        ::QModelIndexList cppArg0 = ::QModelIndexList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mimeData(QModelIndexList)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMimeData * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::mimeData(cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->mimeData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_mimeData_TypeError:
        const char* overloads[] = {"QModelIndexList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.mimeData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_mimeTypes(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mimeTypes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::mimeTypes() : const_cast<const ::QStandardItemModel*>(cppSelf)->mimeTypes();
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

static PyObject* Sbk_QStandardItemModelFunc_parent(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "parent", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: parent()const
    // 1: parent(QModelIndex)const
    if (numArgs == 0) {
        overloadId = 0; // parent()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 1; // parent(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_parent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // parent() const
        {

            if (!PyErr_Occurred()) {
                // parent()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QObject * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->parent();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);

                // Ownership transferences.
                Shiboken::Object::setParent(pyResult, self);
            }
            break;
        }
        case 1: // parent(const QModelIndex & child) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // parent(QModelIndex)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QModelIndex cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::parent(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->parent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_parent_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.parent", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_removeColumns(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeColumns(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeColumns(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_removeColumns_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeColumns(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_removeColumns_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::removeColumns(cppArg0, cppArg1, *cppArg2) : cppSelf->removeColumns(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_removeColumns_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.removeColumns", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_removeRows(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeRows(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeRows(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_removeRows_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.removeRows(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_removeRows_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::removeRows(cppArg0, cppArg1, *cppArg2) : cppSelf->removeRows(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_removeRows_TypeError:
        const char* overloads[] = {"int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.removeRows", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_rowCount(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.rowCount(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_rowCount_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.rowCount(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QStandardItemModelFunc_rowCount_TypeError;
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
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::rowCount(*cppArg0) : const_cast<const ::QStandardItemModel*>(cppSelf)->rowCount(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_rowCount_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.rowCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setColumnCount(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColumnCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setColumnCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setColumnCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColumnCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setColumnCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setColumnCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setData(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QStandardItemModelFunc_setData_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::setData(*cppArg0, cppArg1, cppArg2) : cppSelf->setData(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_setData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, QVariant, int = Qt.EditRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setHeaderData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setHeaderData(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setHeaderData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHeaderData", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHeaderData(int,Qt::Orientation,QVariant,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHeaderData(int,Qt::Orientation,QVariant,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // setHeaderData(int,Qt::Orientation,QVariant,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setHeaderData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.setHeaderData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QStandardItemModelFunc_setHeaderData_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::Orientation cppArg1 = ((::Qt::Orientation)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QVariant cppArg2 = ::QVariant();
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = Qt::EditRole;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHeaderData(int,Qt::Orientation,QVariant,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::setHeaderData(cppArg0, cppArg1, cppArg2, cppArg3) : cppSelf->setHeaderData(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_setHeaderData_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Orientation, QVariant, int = Qt.EditRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setHeaderData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setHorizontalHeaderItem(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setHorizontalHeaderItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setHorizontalHeaderItem(int,QStandardItem*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // setHorizontalHeaderItem(int,QStandardItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setHorizontalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStandardItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setHorizontalHeaderItem(int,QStandardItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalHeaderItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setHorizontalHeaderItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setHorizontalHeaderItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setHorizontalHeaderLabels(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalHeaderLabels(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setHorizontalHeaderLabels(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setHorizontalHeaderLabels_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalHeaderLabels(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalHeaderLabels(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setHorizontalHeaderLabels_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setHorizontalHeaderLabels", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setItem(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setItem", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setItem(int,QStandardItem*)
    // 1: setItem(int,int,QStandardItem*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[2])))) {
            overloadId = 1; // setItem(int,int,QStandardItem*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
            overloadId = 0; // setItem(int,QStandardItem*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setItem(int row, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QStandardItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setItem(int,QStandardItem*)
                // Begin code injection

                // Clear parent from the old child
                QStandardItem* _i = cppSelf->item(cppArg0);
                if (_i) {
                    PyObject* _pyI = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], _i);
                    Shiboken::Object::setParent(0, _pyI);
                }

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setItem(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 1: // setItem(int row, int column, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QStandardItem* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setItem(int,int,QStandardItem*)
                // Begin code injection

                // Clear parent from the old child
                QStandardItem* _i = cppSelf->item(cppArg0, cppArg1);
                if (_i) {
                    PyObject* _pyI = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], _i);
                    Shiboken::Object::setParent(0, _pyI);
                }

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setItem(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", "int, int, PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setItemData(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setItemData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setItemData(QModelIndex,QMap<int,QVariant>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setItemData(QModelIndex,QMap<int,QVariant>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setItemData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QMap<int, QVariant > cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setItemData(QModelIndex,QMap<int,QVariant>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::setItemData(*cppArg0, cppArg1) : cppSelf->setItemData(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_setItemData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, dict", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setItemData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setItemPrototype(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItemPrototype(const QStandardItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArg)))) {
        overloadId = 0; // setItemPrototype(const QStandardItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setItemPrototype_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStandardItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setItemPrototype(const QStandardItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemPrototype(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setItemPrototype_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setItemPrototype", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setRowCount(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRowCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRowCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setRowCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRowCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setRowCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setRowCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setSortRole(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSortRole(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSortRole(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setSortRole_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSortRole(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSortRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setSortRole_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setSortRole", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setVerticalHeaderItem(PyObject* self, PyObject* args)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setVerticalHeaderItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setVerticalHeaderItem(int,QStandardItem*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // setVerticalHeaderItem(int,QStandardItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setVerticalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStandardItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setVerticalHeaderItem(int,QStandardItem*)
            // Begin code injection

            // Clear parent from the old child
            QStandardItem* _i = cppSelf->verticalHeaderItem(cppArg0);
            if (_i) {
                PyObject* _pyI = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], _i);
                Shiboken::Object::setParent(0, _pyI);
            }

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalHeaderItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setVerticalHeaderItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.setVerticalHeaderItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_setVerticalHeaderLabels(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalHeaderLabels(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setVerticalHeaderLabels(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_setVerticalHeaderLabels_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalHeaderLabels(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalHeaderLabels(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_setVerticalHeaderLabels_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.setVerticalHeaderLabels", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_sort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.sort(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.sort(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:sort", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sort(int,Qt::SortOrder)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // sort(int,Qt::SortOrder)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1])))) {
            overloadId = 0; // sort(int,Qt::SortOrder)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_sort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "order");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.sort(): got multiple values for keyword argument 'order'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1]))))
                    goto Sbk_QStandardItemModelFunc_sort_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = Qt::AscendingOrder;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sort(int,Qt::SortOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItemModel::sort(cppArg0, cppArg1) : cppSelf->sort(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemModelFunc_sort_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder = Qt.AscendingOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.sort", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_sortRole(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sortRole()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->sortRole();
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

static PyObject* Sbk_QStandardItemModelFunc_supportedDropActions(PyObject* self)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedDropActions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::DropAction> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItemModel*>(cppSelf)->::QStandardItemModel::supportedDropActions() : const_cast<const ::QStandardItemModel*>(cppSelf)->supportedDropActions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemModelFunc_takeColumn(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeColumn(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeColumn(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_takeColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeColumn(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QStandardItem * > cppResult = cppSelf->takeColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_takeColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.takeColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_takeHorizontalHeaderItem(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeHorizontalHeaderItem(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeHorizontalHeaderItem(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_takeHorizontalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeHorizontalHeaderItem(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = cppSelf->takeHorizontalHeaderItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_takeHorizontalHeaderItem_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.takeHorizontalHeaderItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_takeItem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.takeItem(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.takeItem(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:takeItem", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: takeItem(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // takeItem(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // takeItem(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_takeItem_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItemModel.takeItem(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemModelFunc_takeItem_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // takeItem(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = cppSelf->takeItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_takeItem_TypeError:
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItemModel.takeItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_takeRow(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeRow(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeRow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_takeRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeRow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QStandardItem * > cppResult = cppSelf->takeRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_takeRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.takeRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_takeVerticalHeaderItem(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeVerticalHeaderItem(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeVerticalHeaderItem(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_takeVerticalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeVerticalHeaderItem(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = cppSelf->takeVerticalHeaderItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_takeVerticalHeaderItem_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.takeVerticalHeaderItem", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemModelFunc_verticalHeaderItem(PyObject* self, PyObject* pyArg)
{
    ::QStandardItemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: verticalHeaderItem(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // verticalHeaderItem(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemModelFunc_verticalHeaderItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // verticalHeaderItem(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItemModel*>(cppSelf)->verticalHeaderItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemModelFunc_verticalHeaderItem_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItemModel.verticalHeaderItem", overloads);
        return 0;
}

static PyMethodDef Sbk_QStandardItemModel_methods[] = {
    {"appendColumn", (PyCFunction)Sbk_QStandardItemModelFunc_appendColumn, METH_O},
    {"appendRow", (PyCFunction)Sbk_QStandardItemModelFunc_appendRow, METH_O},
    {"clear", (PyCFunction)Sbk_QStandardItemModelFunc_clear, METH_NOARGS},
    {"columnCount", (PyCFunction)Sbk_QStandardItemModelFunc_columnCount, METH_VARARGS|METH_KEYWORDS},
    {"data", (PyCFunction)Sbk_QStandardItemModelFunc_data, METH_VARARGS|METH_KEYWORDS},
    {"dropMimeData", (PyCFunction)Sbk_QStandardItemModelFunc_dropMimeData, METH_VARARGS},
    {"findItems", (PyCFunction)Sbk_QStandardItemModelFunc_findItems, METH_VARARGS|METH_KEYWORDS},
    {"flags", (PyCFunction)Sbk_QStandardItemModelFunc_flags, METH_O},
    {"hasChildren", (PyCFunction)Sbk_QStandardItemModelFunc_hasChildren, METH_VARARGS|METH_KEYWORDS},
    {"headerData", (PyCFunction)Sbk_QStandardItemModelFunc_headerData, METH_VARARGS|METH_KEYWORDS},
    {"horizontalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_horizontalHeaderItem, METH_O},
    {"index", (PyCFunction)Sbk_QStandardItemModelFunc_index, METH_VARARGS|METH_KEYWORDS},
    {"indexFromItem", (PyCFunction)Sbk_QStandardItemModelFunc_indexFromItem, METH_O},
    {"insertColumn", (PyCFunction)Sbk_QStandardItemModelFunc_insertColumn, METH_VARARGS|METH_KEYWORDS},
    {"insertColumns", (PyCFunction)Sbk_QStandardItemModelFunc_insertColumns, METH_VARARGS|METH_KEYWORDS},
    {"insertRow", (PyCFunction)Sbk_QStandardItemModelFunc_insertRow, METH_VARARGS|METH_KEYWORDS},
    {"insertRows", (PyCFunction)Sbk_QStandardItemModelFunc_insertRows, METH_VARARGS|METH_KEYWORDS},
    {"invisibleRootItem", (PyCFunction)Sbk_QStandardItemModelFunc_invisibleRootItem, METH_NOARGS},
    {"item", (PyCFunction)Sbk_QStandardItemModelFunc_item, METH_VARARGS|METH_KEYWORDS},
    {"itemData", (PyCFunction)Sbk_QStandardItemModelFunc_itemData, METH_O},
    {"itemFromIndex", (PyCFunction)Sbk_QStandardItemModelFunc_itemFromIndex, METH_O},
    {"itemPrototype", (PyCFunction)Sbk_QStandardItemModelFunc_itemPrototype, METH_NOARGS},
    {"mimeData", (PyCFunction)Sbk_QStandardItemModelFunc_mimeData, METH_O},
    {"mimeTypes", (PyCFunction)Sbk_QStandardItemModelFunc_mimeTypes, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QStandardItemModelFunc_parent, METH_VARARGS},
    {"removeColumns", (PyCFunction)Sbk_QStandardItemModelFunc_removeColumns, METH_VARARGS|METH_KEYWORDS},
    {"removeRows", (PyCFunction)Sbk_QStandardItemModelFunc_removeRows, METH_VARARGS|METH_KEYWORDS},
    {"rowCount", (PyCFunction)Sbk_QStandardItemModelFunc_rowCount, METH_VARARGS|METH_KEYWORDS},
    {"setColumnCount", (PyCFunction)Sbk_QStandardItemModelFunc_setColumnCount, METH_O},
    {"setData", (PyCFunction)Sbk_QStandardItemModelFunc_setData, METH_VARARGS|METH_KEYWORDS},
    {"setHeaderData", (PyCFunction)Sbk_QStandardItemModelFunc_setHeaderData, METH_VARARGS|METH_KEYWORDS},
    {"setHorizontalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_setHorizontalHeaderItem, METH_VARARGS},
    {"setHorizontalHeaderLabels", (PyCFunction)Sbk_QStandardItemModelFunc_setHorizontalHeaderLabels, METH_O},
    {"setItem", (PyCFunction)Sbk_QStandardItemModelFunc_setItem, METH_VARARGS},
    {"setItemData", (PyCFunction)Sbk_QStandardItemModelFunc_setItemData, METH_VARARGS},
    {"setItemPrototype", (PyCFunction)Sbk_QStandardItemModelFunc_setItemPrototype, METH_O},
    {"setRowCount", (PyCFunction)Sbk_QStandardItemModelFunc_setRowCount, METH_O},
    {"setSortRole", (PyCFunction)Sbk_QStandardItemModelFunc_setSortRole, METH_O},
    {"setVerticalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_setVerticalHeaderItem, METH_VARARGS},
    {"setVerticalHeaderLabels", (PyCFunction)Sbk_QStandardItemModelFunc_setVerticalHeaderLabels, METH_O},
    {"sort", (PyCFunction)Sbk_QStandardItemModelFunc_sort, METH_VARARGS|METH_KEYWORDS},
    {"sortRole", (PyCFunction)Sbk_QStandardItemModelFunc_sortRole, METH_NOARGS},
    {"supportedDropActions", (PyCFunction)Sbk_QStandardItemModelFunc_supportedDropActions, METH_NOARGS},
    {"takeColumn", (PyCFunction)Sbk_QStandardItemModelFunc_takeColumn, METH_O},
    {"takeHorizontalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_takeHorizontalHeaderItem, METH_O},
    {"takeItem", (PyCFunction)Sbk_QStandardItemModelFunc_takeItem, METH_VARARGS|METH_KEYWORDS},
    {"takeRow", (PyCFunction)Sbk_QStandardItemModelFunc_takeRow, METH_O},
    {"takeVerticalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_takeVerticalHeaderItem, METH_O},
    {"verticalHeaderItem", (PyCFunction)Sbk_QStandardItemModelFunc_verticalHeaderItem, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QStandardItemModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStandardItemModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStandardItemModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStandardItemModel",
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
    /*tp_traverse*/         Sbk_QStandardItemModel_traverse,
    /*tp_clear*/            Sbk_QStandardItemModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStandardItemModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStandardItemModel_Init,
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

static void* Sbk_QStandardItemModel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if (qobject_cast<QStandardItemModel*>( reinterpret_cast< ::QStandardItemModel*>(cptr)))
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStandardItemModel_PythonToCpp_QStandardItemModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStandardItemModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStandardItemModel_PythonToCpp_QStandardItemModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStandardItemModel_Type))
        return QStandardItemModel_PythonToCpp_QStandardItemModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStandardItemModel_PTR_CppToPython_QStandardItemModel(const void* cppIn) {
    return PySide::getWrapperForQObject((::QStandardItemModel*)cppIn, &Sbk_QStandardItemModel_Type);

}

void init_QStandardItemModel(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStandardItemModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStandardItemModel", "QStandardItemModel*",
        &Sbk_QStandardItemModel_Type, &Shiboken::callCppDestructor< ::QStandardItemModel >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStandardItemModel_Type,
        QStandardItemModel_PythonToCpp_QStandardItemModel_PTR,
        is_QStandardItemModel_PythonToCpp_QStandardItemModel_PTR_Convertible,
        QStandardItemModel_PTR_CppToPython_QStandardItemModel);

    Shiboken::Conversions::registerConverterName(converter, "QStandardItemModel");
    Shiboken::Conversions::registerConverterName(converter, "QStandardItemModel*");
    Shiboken::Conversions::registerConverterName(converter, "QStandardItemModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStandardItemModel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStandardItemModelWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QStandardItemModel_Type, &Sbk_QStandardItemModel_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QStandardItemModel_Type, &::QStandardItemModel::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QStandardItemModel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QStandardItemModel_Type, &::QStandardItemModel::staticMetaObject, sizeof(::QStandardItemModel));
}
