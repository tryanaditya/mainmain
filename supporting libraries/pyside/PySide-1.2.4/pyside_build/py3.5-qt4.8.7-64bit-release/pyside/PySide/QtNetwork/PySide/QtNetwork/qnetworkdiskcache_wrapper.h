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

#ifndef SBK_QNETWORKDISKCACHEWRAPPER_H
#define SBK_QNETWORKDISKCACHEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qnetworkdiskcache.h>

namespace PySide { class DynamicQMetaObject; }

class QNetworkDiskCacheWrapper : public QNetworkDiskCache
{
public:
    QNetworkDiskCacheWrapper(QObject * parent = 0);
    virtual qint64 cacheSize() const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void clear();
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual QIODevice * data(const QUrl & url);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual qint64 expire();
    virtual void insert(QIODevice * device);
    virtual QNetworkCacheMetaData metaData(const QUrl & url);
    virtual const QMetaObject * metaObject() const;
    virtual QIODevice * prepare(const QNetworkCacheMetaData & metaData);
    virtual bool remove(const QUrl & url);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void updateMetaData(const QNetworkCacheMetaData & metaData);
    virtual ~QNetworkDiskCacheWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QNETWORKDISKCACHEWRAPPER_H

