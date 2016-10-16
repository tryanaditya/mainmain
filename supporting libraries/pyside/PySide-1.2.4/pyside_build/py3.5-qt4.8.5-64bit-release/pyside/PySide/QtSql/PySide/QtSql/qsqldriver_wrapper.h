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

#ifndef SBK_QSQLDRIVERWRAPPER_H
#define SBK_QSQLDRIVERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qsqldriver.h>

namespace PySide { class DynamicQMetaObject; }

class QSqlDriverWrapper : public QSqlDriver
{
public:
    QSqlDriverWrapper(QObject * parent = 0);
    virtual bool beginTransaction();
    virtual void childEvent(QChildEvent * arg__1);
    virtual void close();
    virtual bool commitTransaction();
    virtual void connectNotify(const char * signal);
    virtual QSqlResult * createResult() const;
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual QString escapeIdentifier(const QString & identifier, QSqlDriver::IdentifierType type) const;
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QString formatValue(const QSqlField & field, bool trimStrings = false) const;
    virtual bool hasFeature(QSqlDriver::DriverFeature f) const;
    virtual bool isOpen() const;
    virtual const QMetaObject * metaObject() const;
    virtual bool open(const QString & db, const QString & user = QString(), const QString & password = QString(), const QString & host = QString(), int port = -1, const QString & connOpts = QString());
    virtual QSqlIndex primaryIndex(const QString & tableName) const;
    virtual QSqlRecord record(const QString & tableName) const;
    virtual bool rollbackTransaction();
    virtual void setLastError(const QSqlError & e);
    virtual void setOpen(bool o);
    virtual void setOpenError(bool e);
    virtual QString sqlStatement(QSqlDriver::StatementType type, const QString & tableName, const QSqlRecord & rec, bool preparedStatement) const;
    virtual QStringList tables(QSql::TableType tableType) const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QSqlDriverWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSQLDRIVERWRAPPER_H

