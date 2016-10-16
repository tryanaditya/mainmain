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

#ifndef SBK_QITEMSELECTIONMODELWRAPPER_H
#define SBK_QITEMSELECTIONMODELWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qitemselectionmodel.h>

namespace PySide { class DynamicQMetaObject; }

class QItemSelectionModelWrapper : public QItemSelectionModel
{
public:
    QItemSelectionModelWrapper(QAbstractItemModel * model);
    QItemSelectionModelWrapper(QAbstractItemModel * model, QObject * parent);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void clear();
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual const QMetaObject * metaObject() const;
    virtual void reset();
    virtual void select(const QItemSelection & selection, QFlags<QItemSelectionModel::SelectionFlag> command);
    virtual void select(const QModelIndex & index, QFlags<QItemSelectionModel::SelectionFlag> command);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QItemSelectionModelWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QITEMSELECTIONMODELWRAPPER_H
