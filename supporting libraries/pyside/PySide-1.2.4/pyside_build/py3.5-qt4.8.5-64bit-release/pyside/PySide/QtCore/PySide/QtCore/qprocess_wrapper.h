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

#ifndef SBK_QPROCESSWRAPPER_H
#define SBK_QPROCESSWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qprocess.h>

namespace PySide { class DynamicQMetaObject; }

class QProcessWrapper : public QProcess
{
public:
    QProcessWrapper(QObject * parent = 0);
    virtual bool atEnd() const;
    virtual qint64 bytesAvailable() const;
    virtual qint64 bytesToWrite() const;
    virtual bool canReadLine() const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void close();
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual bool isSequential() const;
    virtual const QMetaObject * metaObject() const;
    virtual bool open(QFlags<QIODevice::OpenModeFlag> mode);
    virtual qint64 pos() const;
    virtual qint64 readData(char * data, qint64 maxlen);
    virtual qint64 readLineData(char * data, qint64 maxlen);
    virtual bool reset();
    virtual bool seek(qint64 pos);
    virtual void setupChildProcess();
    virtual qint64 size() const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual bool waitForBytesWritten(int msecs = 30000);
    virtual bool waitForReadyRead(int msecs = 30000);
    virtual qint64 writeData(const char * data, qint64 len);
    virtual ~QProcessWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QPROCESSWRAPPER_H

