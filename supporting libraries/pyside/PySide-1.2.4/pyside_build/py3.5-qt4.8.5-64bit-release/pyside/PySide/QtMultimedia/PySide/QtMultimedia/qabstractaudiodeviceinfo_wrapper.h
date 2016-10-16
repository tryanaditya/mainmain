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

#ifndef SBK_QABSTRACTAUDIODEVICEINFOWRAPPER_H
#define SBK_QABSTRACTAUDIODEVICEINFOWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qaudioengine.h>

namespace PySide { class DynamicQMetaObject; }

class QAbstractAudioDeviceInfoWrapper : public QAbstractAudioDeviceInfo
{
public:
    QAbstractAudioDeviceInfoWrapper();
    virtual QList<QAudioFormat::Endian > byteOrderList();
    virtual QList<int > channelsList();
    virtual void childEvent(QChildEvent * arg__1);
    virtual QStringList codecList();
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual QString deviceName() const;
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QList<int > frequencyList();
    virtual bool isFormatSupported(const QAudioFormat & format) const;
    virtual const QMetaObject * metaObject() const;
    virtual QAudioFormat nearestFormat(const QAudioFormat & format) const;
    virtual QAudioFormat preferredFormat() const;
    virtual QList<int > sampleSizeList();
    virtual QList<QAudioFormat::SampleType > sampleTypeList();
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QAbstractAudioDeviceInfoWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTAUDIODEVICEINFOWRAPPER_H

