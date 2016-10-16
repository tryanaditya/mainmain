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

#ifndef SBK_QAUDIOENGINEPLUGINWRAPPER_H
#define SBK_QAUDIOENGINEPLUGINWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qaudioengineplugin.h>

namespace PySide { class DynamicQMetaObject; }

class QAudioEnginePluginWrapper : public QAudioEnginePlugin
{
public:
    QAudioEnginePluginWrapper(QObject * parent = 0);
    virtual QList<QByteArray > availableDevices(QAudio::Mode arg__1) const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual QAbstractAudioDeviceInfo * createDeviceInfo(const QByteArray & device, QAudio::Mode mode);
    virtual QAbstractAudioInput * createInput(const QByteArray & device, const QAudioFormat & format = QAudioFormat());
    virtual QAbstractAudioOutput * createOutput(const QByteArray & device, const QAudioFormat & format = QAudioFormat());
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QStringList keys() const;
    virtual const QMetaObject * metaObject() const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QAudioEnginePluginWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QAUDIOENGINEPLUGINWRAPPER_H

