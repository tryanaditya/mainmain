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

#include "qfilesystemmodel_wrapper.h"

// Extra includes
#include <QList>
#include <QMap>
#include <pysideconversions.h>
#include <qabstractitemmodel.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdatastream.h>
#include <qdatetime.h>
#include <qdir.h>
#include <qfileiconprovider.h>
#include <qfileinfo.h>
#include <qfilesystemmodel.h>
#include <qicon.h>
#include <qmetaobject.h>
#include <qmimedata.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsize.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QFileSystemModelWrapper::QFileSystemModelWrapper(QObject * parent) : QFileSystemModel(parent) {
    // ... middle
}

QModelIndex QFileSystemModelWrapper::buddy(const QModelIndex & index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.buddy", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::canFetchMore(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canFetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::canFetchMore(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.canFetchMore", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileSystemModelWrapper::childEvent(QChildEvent * arg__1)
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

int QFileSystemModelWrapper::columnCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "columnCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::columnCount(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.columnCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileSystemModelWrapper::connectNotify(const char * signal)
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

void QFileSystemModelWrapper::customEvent(QEvent * arg__1)
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

QVariant QFileSystemModelWrapper::data(const QModelIndex & index, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::data(index, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

void QFileSystemModelWrapper::disconnectNotify(const char * signal)
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

bool QFileSystemModelWrapper::dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropMimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::dropMimeData(data, action, row, column, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.dropMimeData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::event(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QFileSystemModelWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QFileSystemModelWrapper::fetchMore(const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchMore"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::fetchMore(parent);
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

QFlags<Qt::ItemFlag> QFileSystemModelWrapper::flags(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::ItemFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "flags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::flags(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.flags", Shiboken::SbkType< QFlags<Qt::ItemFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::ItemFlag>)0);
    }
    ::QFlags<Qt::ItemFlag> cppResult = ((::QFlags<Qt::ItemFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::hasChildren(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasChildren"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::hasChildren(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.hasChildren", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QFileSystemModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "headerData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::headerData(section, orientation, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.headerData", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndex QFileSystemModelWrapper::index(int row, int column, const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "index"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::index(row, column, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.index", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::insertColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::insertColumns(column, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.insertColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::insertRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::insertRows(row, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.insertRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMap<int, QVariant > QFileSystemModelWrapper::itemData(const QModelIndex & index) const
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
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.itemData", "map", pyResult->ob_type->tp_name);
        return ::QMap<int, QVariant >();
    }
    ::QMap<int, QVariant > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndexList QFileSystemModelWrapper::match(const QModelIndex & start, int role, const QVariant & value, int hits, QFlags<Qt::MatchFlag> flags) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.match", "QModelIndexList", pyResult->ob_type->tp_name);
        return ::QModelIndexList();
    }
    ::QModelIndexList cppResult = ::QModelIndexList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QMimeData * QFileSystemModelWrapper::mimeData(const QModelIndexList & indexes) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMimeData*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::mimeData(indexes);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.mimeData", Shiboken::SbkType< QMimeData >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMimeData*)0);
    }
    ::QMimeData* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

QStringList QFileSystemModelWrapper::mimeTypes() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mimeTypes"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::mimeTypes();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.mimeTypes", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QModelIndex QFileSystemModelWrapper::parent(const QModelIndex & child) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::parent(child);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.parent", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::removeColumns(int column, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeColumns"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::removeColumns(column, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.removeColumns", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::removeRows(int row, int count, const QModelIndex & parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeRows"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::removeRows(row, count, parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.removeRows", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileSystemModelWrapper::revert()
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

int QFileSystemModelWrapper::rowCount(const QModelIndex & parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rowCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::rowCount(parent);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.rowCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::setData(const QModelIndex & index, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::setData(index, value, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.setData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHeaderData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemModel::setHeaderData(section, orientation, value, role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.setHeaderData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::setItemData(const QModelIndex & index, const QMap<int, QVariant > & roles)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.setItemData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileSystemModelWrapper::sort(int column, Qt::SortOrder order)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sort"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::sort(column, order);
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

QSize QFileSystemModelWrapper::span(const QModelIndex & index) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.span", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileSystemModelWrapper::submit()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.submit", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<Qt::DropAction> QFileSystemModelWrapper::supportedDropActions() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::DropAction>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportedDropActions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::supportedDropActions();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileSystemModel.supportedDropActions", Shiboken::SbkType< QFlags<Qt::DropAction> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::DropAction>)0);
    }
    ::QFlags<Qt::DropAction> cppResult = ((::QFlags<Qt::DropAction>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileSystemModelWrapper::timerEvent(QTimerEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileSystemModel::timerEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], event)
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

const QMetaObject* QFileSystemModelWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QFileSystemModel::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QFileSystemModelWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QFileSystemModel::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QFileSystemModelWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QFileSystemModelWrapper* >(this));
        return QFileSystemModel::qt_metacast(_clname);
}

QFileSystemModelWrapper::~QFileSystemModelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFileSystemModel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFileSystemModel >()))
        return -1;

    ::QFileSystemModelWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QFileSystemModel", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFileSystemModel(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QFileSystemModel(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QFileSystemModel(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModel_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QFileSystemModel_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QFileSystemModel(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QFileSystemModelWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QFileSystemModelWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFileSystemModel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFileSystemModel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QFileSystemModel_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel", overloads);
        return -1;
}

static PyObject* Sbk_QFileSystemModelFunc_canFetchMore(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: canFetchMore(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // canFetchMore(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_canFetchMore_TypeError;

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
            // canFetchMore(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::canFetchMore(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->canFetchMore(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_canFetchMore_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.canFetchMore", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_columnCount(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.columnCount(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_columnCount_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.columnCount(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QFileSystemModelFunc_columnCount_TypeError;
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
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::columnCount(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->columnCount(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_columnCount_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.columnCount", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_data(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.data(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.data(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_data_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.data(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QFileSystemModelFunc_data_TypeError;
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
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::data(*cppArg0, cppArg1) : const_cast<const ::QFileSystemModel*>(cppSelf)->data(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_data_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.data", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_dropMimeData(PyObject* self, PyObject* args)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_dropMimeData_TypeError;

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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::dropMimeData(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4) : cppSelf->dropMimeData(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_dropMimeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMimeData, PySide.QtCore.Qt.DropAction, int, int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.dropMimeData", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.event", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_fetchMore(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fetchMore(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // fetchMore(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_fetchMore_TypeError;

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
            // fetchMore(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::fetchMore(*cppArg0) : cppSelf->fetchMore(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_fetchMore_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.fetchMore", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_fileIcon(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fileIcon(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // fileIcon(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_fileIcon_TypeError;

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
            // fileIcon(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->fileIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_fileIcon_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.fileIcon", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_fileInfo(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fileInfo(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // fileInfo(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_fileInfo_TypeError;

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
            // fileInfo(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileInfo cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->fileInfo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_fileInfo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.fileInfo", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_fileName(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fileName(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // fileName(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_fileName_TypeError;

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
            // fileName(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->fileName(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_fileName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.fileName", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_filePath(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: filePath(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // filePath(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_filePath_TypeError;

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
            // filePath(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->filePath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_filePath_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.filePath", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_filter(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDir::Filter> cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->filter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileSystemModelFunc_flags(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_flags_TypeError;

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
            QFlags<Qt::ItemFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::flags(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->flags(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_flags_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.flags", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_hasChildren(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.hasChildren(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_hasChildren_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.hasChildren(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QFileSystemModelFunc_hasChildren_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::hasChildren(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->hasChildren(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_hasChildren_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.hasChildren", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_headerData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.headerData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.headerData(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_headerData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.headerData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QFileSystemModelFunc_headerData_TypeError;
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
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::headerData(cppArg0, cppArg1, cppArg2) : const_cast<const ::QFileSystemModel*>(cppSelf)->headerData(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_headerData_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Orientation, int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.headerData", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_iconProvider(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconProvider()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileIconProvider * cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->iconProvider();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileSystemModelFunc_index(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.index(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.index(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:index", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: index(QString,int)const
    // 1: index(int,int,QModelIndex)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // index(int,int,QModelIndex)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
            overloadId = 1; // index(int,int,QModelIndex)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // index(QString,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // index(QString,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_index_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // index(const QString & path, int column) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "column");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.index(): got multiple values for keyword argument 'column'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QFileSystemModelFunc_index_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // index(QString,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QModelIndex cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->index(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
            }
            break;
        }
        case 1: // index(int row, int column, const QModelIndex & parent) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.index(): got multiple values for keyword argument 'parent'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2]))))
                        goto Sbk_QFileSystemModelFunc_index_TypeError;
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
                QModelIndex cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::index(cppArg0, cppArg1, *cppArg2) : const_cast<const ::QFileSystemModel*>(cppSelf)->index(cppArg0, cppArg1, *cppArg2);
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

    Sbk_QFileSystemModelFunc_index_TypeError:
        const char* overloads[] = {"unicode, int = 0", "int, int, PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.index", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_isDir(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isDir(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // isDir(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_isDir_TypeError;

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
            // isDir(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->isDir(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_isDir_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.isDir", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_isReadOnly(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QFileSystemModelFunc_lastModified(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: lastModified(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // lastModified(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_lastModified_TypeError;

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
            // lastModified(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->lastModified(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_lastModified_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.lastModified", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_mimeData(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_mimeData_TypeError;

    // Call function/method
    {
        ::QModelIndexList cppArg0 = ::QModelIndexList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mimeData(QModelIndexList)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMimeData * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::mimeData(cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->mimeData(cppArg0);
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

    Sbk_QFileSystemModelFunc_mimeData_TypeError:
        const char* overloads[] = {"QModelIndexList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.mimeData", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_mimeTypes(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mimeTypes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::mimeTypes() : const_cast<const ::QFileSystemModel*>(cppSelf)->mimeTypes();
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

static PyObject* Sbk_QFileSystemModelFunc_mkdir(PyObject* self, PyObject* args)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mkdir", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mkdir(QModelIndex,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // mkdir(QModelIndex,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_mkdir_TypeError;

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

        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mkdir(QModelIndex,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = cppSelf->mkdir(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_mkdir_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.mkdir", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_myComputer(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.myComputer(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:myComputer", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: myComputer(int)const
    if (numArgs == 0) {
        overloadId = 0; // myComputer(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // myComputer(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_myComputer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.myComputer(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QFileSystemModelFunc_myComputer_TypeError;
            }
        }
        int cppArg0 = Qt::DisplayRole;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // myComputer(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->myComputer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_myComputer_TypeError:
        const char* overloads[] = {"int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.myComputer", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_nameFilterDisables(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nameFilterDisables()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->nameFilterDisables();
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

static PyObject* Sbk_QFileSystemModelFunc_nameFilters(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nameFilters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->nameFilters();
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

static PyObject* Sbk_QFileSystemModelFunc_parent(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: parent(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // parent(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_parent_TypeError;

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
            // parent(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::parent(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->parent(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_parent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.parent", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_permissions(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: permissions(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // permissions(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_permissions_TypeError;

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
            // permissions(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QFile::Permission> cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->permissions(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_permissions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.permissions", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // remove(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_remove_TypeError;

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
            // remove(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->remove(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_remove_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.remove", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_resolveSymlinks(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resolveSymlinks()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->resolveSymlinks();
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

static PyObject* Sbk_QFileSystemModelFunc_rmdir(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rmdir(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // rmdir(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_rmdir_TypeError;

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
            // rmdir(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->rmdir(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_rmdir_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.rmdir", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_rootDirectory(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootDirectory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->rootDirectory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileSystemModelFunc_rootPath(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->rootPath();
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

static PyObject* Sbk_QFileSystemModelFunc_rowCount(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.rowCount(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_rowCount_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.rowCount(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0]))))
                    goto Sbk_QFileSystemModelFunc_rowCount_TypeError;
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
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::rowCount(*cppArg0) : const_cast<const ::QFileSystemModel*>(cppSelf)->rowCount(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_rowCount_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex = QModelIndex()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.rowCount", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.setData(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.setData(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.setData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QFileSystemModelFunc_setData_TypeError;
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
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::setData(*cppArg0, cppArg1, cppArg2) : cppSelf->setData(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_setData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, QVariant, int = Qt.EditRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.setData", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setFilter(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFilter(QFlags<QDir::Filter>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArg)))) {
        overloadId = 0; // setFilter(QFlags<QDir::Filter>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setFilter_TypeError;

    // Call function/method
    {
        ::QFlags<QDir::Filter> cppArg0 = ((::QFlags<QDir::Filter>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFilter(QFlags<QDir::Filter>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setFilter", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setIconProvider(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconProvider(QFileIconProvider*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], (pyArg)))) {
        overloadId = 0; // setIconProvider(QFileIconProvider*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setIconProvider_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFileIconProvider* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconProvider(QFileIconProvider*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconProvider(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setIconProvider_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileIconProvider", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setIconProvider", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setNameFilterDisables(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilterDisables(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setNameFilterDisables(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setNameFilterDisables_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilterDisables(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilterDisables(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setNameFilterDisables_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setNameFilterDisables", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setNameFilters(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilters(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setNameFilters(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setNameFilters_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilters(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilters(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setNameFilters_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setNameFilters", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setReadOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReadOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setResolveSymlinks(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setResolveSymlinks(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setResolveSymlinks(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setResolveSymlinks_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setResolveSymlinks(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setResolveSymlinks(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_setResolveSymlinks_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setResolveSymlinks", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_setRootPath(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRootPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setRootPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_setRootPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRootPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = cppSelf->setRootPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_setRootPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.setRootPath", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_size(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: size(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // size(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_size_TypeError;

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
            // size(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->size(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_size_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.size", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_sort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.sort(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.sort(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_sort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "order");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileSystemModel.sort(): got multiple values for keyword argument 'order'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1]))))
                    goto Sbk_QFileSystemModelFunc_sort_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = Qt::AscendingOrder;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sort(int,Qt::SortOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::sort(cppArg0, cppArg1) : cppSelf->sort(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_sort_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder = Qt.AscendingOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileSystemModel.sort", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_supportedDropActions(PyObject* self)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedDropActions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::DropAction> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileSystemModel*>(cppSelf)->::QFileSystemModel::supportedDropActions() : const_cast<const ::QFileSystemModel*>(cppSelf)->supportedDropActions();
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

static PyObject* Sbk_QFileSystemModelFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileSystemModel::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileSystemModelFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QFileSystemModelFunc_type(PyObject* self, PyObject* pyArg)
{
    ::QFileSystemModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileSystemModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: type(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // type(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileSystemModelFunc_type_TypeError;

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
            // type(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileSystemModel*>(cppSelf)->type(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileSystemModelFunc_type_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileSystemModel.type", overloads);
        return 0;
}

static PyMethodDef Sbk_QFileSystemModel_methods[] = {
    {"canFetchMore", (PyCFunction)Sbk_QFileSystemModelFunc_canFetchMore, METH_O},
    {"columnCount", (PyCFunction)Sbk_QFileSystemModelFunc_columnCount, METH_VARARGS|METH_KEYWORDS},
    {"data", (PyCFunction)Sbk_QFileSystemModelFunc_data, METH_VARARGS|METH_KEYWORDS},
    {"dropMimeData", (PyCFunction)Sbk_QFileSystemModelFunc_dropMimeData, METH_VARARGS},
    {"event", (PyCFunction)Sbk_QFileSystemModelFunc_event, METH_O},
    {"fetchMore", (PyCFunction)Sbk_QFileSystemModelFunc_fetchMore, METH_O},
    {"fileIcon", (PyCFunction)Sbk_QFileSystemModelFunc_fileIcon, METH_O},
    {"fileInfo", (PyCFunction)Sbk_QFileSystemModelFunc_fileInfo, METH_O},
    {"fileName", (PyCFunction)Sbk_QFileSystemModelFunc_fileName, METH_O},
    {"filePath", (PyCFunction)Sbk_QFileSystemModelFunc_filePath, METH_O},
    {"filter", (PyCFunction)Sbk_QFileSystemModelFunc_filter, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QFileSystemModelFunc_flags, METH_O},
    {"hasChildren", (PyCFunction)Sbk_QFileSystemModelFunc_hasChildren, METH_VARARGS|METH_KEYWORDS},
    {"headerData", (PyCFunction)Sbk_QFileSystemModelFunc_headerData, METH_VARARGS|METH_KEYWORDS},
    {"iconProvider", (PyCFunction)Sbk_QFileSystemModelFunc_iconProvider, METH_NOARGS},
    {"index", (PyCFunction)Sbk_QFileSystemModelFunc_index, METH_VARARGS|METH_KEYWORDS},
    {"isDir", (PyCFunction)Sbk_QFileSystemModelFunc_isDir, METH_O},
    {"isReadOnly", (PyCFunction)Sbk_QFileSystemModelFunc_isReadOnly, METH_NOARGS},
    {"lastModified", (PyCFunction)Sbk_QFileSystemModelFunc_lastModified, METH_O},
    {"mimeData", (PyCFunction)Sbk_QFileSystemModelFunc_mimeData, METH_O},
    {"mimeTypes", (PyCFunction)Sbk_QFileSystemModelFunc_mimeTypes, METH_NOARGS},
    {"mkdir", (PyCFunction)Sbk_QFileSystemModelFunc_mkdir, METH_VARARGS},
    {"myComputer", (PyCFunction)Sbk_QFileSystemModelFunc_myComputer, METH_VARARGS|METH_KEYWORDS},
    {"nameFilterDisables", (PyCFunction)Sbk_QFileSystemModelFunc_nameFilterDisables, METH_NOARGS},
    {"nameFilters", (PyCFunction)Sbk_QFileSystemModelFunc_nameFilters, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QFileSystemModelFunc_parent, METH_O},
    {"permissions", (PyCFunction)Sbk_QFileSystemModelFunc_permissions, METH_O},
    {"remove", (PyCFunction)Sbk_QFileSystemModelFunc_remove, METH_O},
    {"resolveSymlinks", (PyCFunction)Sbk_QFileSystemModelFunc_resolveSymlinks, METH_NOARGS},
    {"rmdir", (PyCFunction)Sbk_QFileSystemModelFunc_rmdir, METH_O},
    {"rootDirectory", (PyCFunction)Sbk_QFileSystemModelFunc_rootDirectory, METH_NOARGS},
    {"rootPath", (PyCFunction)Sbk_QFileSystemModelFunc_rootPath, METH_NOARGS},
    {"rowCount", (PyCFunction)Sbk_QFileSystemModelFunc_rowCount, METH_VARARGS|METH_KEYWORDS},
    {"setData", (PyCFunction)Sbk_QFileSystemModelFunc_setData, METH_VARARGS|METH_KEYWORDS},
    {"setFilter", (PyCFunction)Sbk_QFileSystemModelFunc_setFilter, METH_O},
    {"setIconProvider", (PyCFunction)Sbk_QFileSystemModelFunc_setIconProvider, METH_O},
    {"setNameFilterDisables", (PyCFunction)Sbk_QFileSystemModelFunc_setNameFilterDisables, METH_O},
    {"setNameFilters", (PyCFunction)Sbk_QFileSystemModelFunc_setNameFilters, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QFileSystemModelFunc_setReadOnly, METH_O},
    {"setResolveSymlinks", (PyCFunction)Sbk_QFileSystemModelFunc_setResolveSymlinks, METH_O},
    {"setRootPath", (PyCFunction)Sbk_QFileSystemModelFunc_setRootPath, METH_O},
    {"size", (PyCFunction)Sbk_QFileSystemModelFunc_size, METH_O},
    {"sort", (PyCFunction)Sbk_QFileSystemModelFunc_sort, METH_VARARGS|METH_KEYWORDS},
    {"supportedDropActions", (PyCFunction)Sbk_QFileSystemModelFunc_supportedDropActions, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QFileSystemModelFunc_timerEvent, METH_O},
    {"type", (PyCFunction)Sbk_QFileSystemModelFunc_type, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFileSystemModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFileSystemModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFileSystemModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFileSystemModel",
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
    /*tp_traverse*/         Sbk_QFileSystemModel_traverse,
    /*tp_clear*/            Sbk_QFileSystemModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFileSystemModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFileSystemModel_Init,
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

static void* Sbk_QFileSystemModel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if (qobject_cast<QFileSystemModel*>( reinterpret_cast< ::QFileSystemModel*>(cptr)))
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QFileSystemModel_Roles_PythonToCpp_QFileSystemModel_Roles(PyObject* pyIn, void* cppOut) {
    *((::QFileSystemModel::Roles*)cppOut) = (::QFileSystemModel::Roles) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileSystemModel_Roles_PythonToCpp_QFileSystemModel_Roles_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX]))
        return QFileSystemModel_Roles_PythonToCpp_QFileSystemModel_Roles;
    return 0;
}
static PyObject* QFileSystemModel_Roles_CppToPython_QFileSystemModel_Roles(const void* cppIn) {
    int castCppIn = *((::QFileSystemModel::Roles*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFileSystemModel_PythonToCpp_QFileSystemModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFileSystemModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFileSystemModel_PythonToCpp_QFileSystemModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFileSystemModel_Type))
        return QFileSystemModel_PythonToCpp_QFileSystemModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFileSystemModel_PTR_CppToPython_QFileSystemModel(const void* cppIn) {
    return PySide::getWrapperForQObject((::QFileSystemModel*)cppIn, &Sbk_QFileSystemModel_Type);

}

void init_QFileSystemModel(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFileSystemModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFileSystemModel", "QFileSystemModel*",
        &Sbk_QFileSystemModel_Type, &Shiboken::callCppDestructor< ::QFileSystemModel >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFileSystemModel_Type,
        QFileSystemModel_PythonToCpp_QFileSystemModel_PTR,
        is_QFileSystemModel_PythonToCpp_QFileSystemModel_PTR_Convertible,
        QFileSystemModel_PTR_CppToPython_QFileSystemModel);

    Shiboken::Conversions::registerConverterName(converter, "QFileSystemModel");
    Shiboken::Conversions::registerConverterName(converter, "QFileSystemModel*");
    Shiboken::Conversions::registerConverterName(converter, "QFileSystemModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileSystemModel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileSystemModelWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFileSystemModel_Type, &Sbk_QFileSystemModel_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Roles'.
    SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileSystemModel_Type,
        "Roles",
        "PySide.QtGui.QFileSystemModel.Roles",
        "QFileSystemModel::Roles");
    if (!SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX],
        &Sbk_QFileSystemModel_Type, "FileIconRole", (long) QFileSystemModel::FileIconRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX],
        &Sbk_QFileSystemModel_Type, "FilePathRole", (long) QFileSystemModel::FilePathRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX],
        &Sbk_QFileSystemModel_Type, "FileNameRole", (long) QFileSystemModel::FileNameRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX],
        &Sbk_QFileSystemModel_Type, "FilePermissions", (long) QFileSystemModel::FilePermissions))
        return ;
    // Register converter for enum 'QFileSystemModel::Roles'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX],
            QFileSystemModel_Roles_CppToPython_QFileSystemModel_Roles);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileSystemModel_Roles_PythonToCpp_QFileSystemModel_Roles,
            is_QFileSystemModel_Roles_PythonToCpp_QFileSystemModel_Roles_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILESYSTEMMODEL_ROLES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileSystemModel::Roles");
        Shiboken::Conversions::registerConverterName(converter, "Roles");
    }
    // End of 'Roles' enum.

    PySide::Signal::registerSignals(&Sbk_QFileSystemModel_Type, &::QFileSystemModel::staticMetaObject);

    qRegisterMetaType< ::QFileSystemModel::Roles >("QFileSystemModel::Roles");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QFileSystemModel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QFileSystemModel_Type, &::QFileSystemModel::staticMetaObject, sizeof(::QFileSystemModel));
}
