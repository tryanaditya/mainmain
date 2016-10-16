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

#ifndef SBK_QSQLRESULTWRAPPER_H
#define SBK_QSQLRESULTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qsqlresult.h>

class QSqlResultWrapper : public QSqlResult
{
public:
    QSqlResultWrapper(const QSqlDriver * db);
    virtual void bindValue(const QString & placeholder, const QVariant & val, QFlags<QSql::ParamTypeFlag> type);
    virtual void bindValue(int pos, const QVariant & val, QFlags<QSql::ParamTypeFlag> type);
    virtual QVariant data(int i);
    virtual bool exec();
    virtual bool fetch(int i);
    virtual bool fetchFirst();
    virtual bool fetchLast();
    virtual bool fetchNext();
    virtual bool fetchPrevious();
    virtual QVariant handle() const;
    virtual bool isNull(int i);
    virtual QVariant lastInsertId() const;
    virtual int numRowsAffected();
    virtual bool prepare(const QString & query);
    virtual QSqlRecord record() const;
    virtual bool reset(const QString & sqlquery);
    virtual bool savePrepare(const QString & sqlquery);
    virtual void setActive(bool a);
    virtual void setAt(int at);
    virtual void setForwardOnly(bool forward);
    virtual void setLastError(const QSqlError & e);
    virtual void setQuery(const QString & query);
    virtual void setSelect(bool s);
    virtual int size();
    virtual ~QSqlResultWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSQLRESULTWRAPPER_H

