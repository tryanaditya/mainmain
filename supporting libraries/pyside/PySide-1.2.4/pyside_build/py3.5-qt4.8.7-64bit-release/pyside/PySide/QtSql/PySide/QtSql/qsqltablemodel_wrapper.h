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

#ifndef SBK_QSQLTABLEMODELWRAPPER_H
#define SBK_QSQLTABLEMODELWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qsqltablemodel.h>

namespace PySide { class DynamicQMetaObject; }

class QSqlTableModelWrapper : public QSqlTableModel
{
public:
    QSqlTableModelWrapper(QObject * parent = 0, QSqlDatabase db = QSqlDatabase());
    virtual QModelIndex buddy(const QModelIndex & index) const;
    virtual bool canFetchMore(const QModelIndex & parent = QModelIndex()) const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void clear();
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual QVariant data(const QModelIndex & idx, int role = Qt::DisplayRole) const;
    virtual bool deleteRowFromTable(int row);
    virtual void disconnectNotify(const char * signal);
    virtual bool dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void fetchMore(const QModelIndex & parent = QModelIndex());
    virtual QFlags<Qt::ItemFlag> flags(const QModelIndex & index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
    virtual bool insertColumns(int column, int count, const QModelIndex & parent = QModelIndex());
    virtual bool insertRowIntoTable(const QSqlRecord & values);
    virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
    virtual QMap<int, QVariant > itemData(const QModelIndex & index) const;
    virtual QModelIndexList match(const QModelIndex & start, int role, const QVariant & value, int hits = 1, QFlags<Qt::MatchFlag> flags = Qt::MatchFlags(Qt::MatchStartsWith|Qt::MatchWrap)) const;
    virtual const QMetaObject * metaObject() const;
    virtual QMimeData * mimeData(const QModelIndexList & indexes) const;
    virtual QStringList mimeTypes() const;
    virtual QString orderByClause() const;
    virtual void queryChange();
    virtual bool removeColumns(int column, int count, const QModelIndex & parent = QModelIndex());
    virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
    virtual void revert();
    virtual void revertRow(int row);
    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    virtual bool select();
    virtual QString selectStatement() const;
    virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    virtual void setEditStrategy(QSqlTableModel::EditStrategy strategy);
    virtual void setFilter(const QString & filter);
    virtual bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole);
    virtual bool setItemData(const QModelIndex & index, const QMap<int, QVariant > & roles);
    virtual void setSort(int column, Qt::SortOrder order);
    virtual void setTable(const QString & tableName);
    virtual void sort(int column, Qt::SortOrder order);
    virtual QSize span(const QModelIndex & index) const;
    virtual bool submit();
    virtual QFlags<Qt::DropAction> supportedDropActions() const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual bool updateRowInTable(int row, const QSqlRecord & values);
    virtual ~QSqlTableModelWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSQLTABLEMODELWRAPPER_H

