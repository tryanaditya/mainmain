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

#ifndef SBK_PLATFORMPLUGINWRAPPER_H
#define SBK_PLATFORMPLUGINWRAPPER_H

#define protected public

#include <shiboken.h>

#include <platformplugin.h>

class PlatformPluginWrapper : public Phonon::PlatformPlugin
{
public:
    PlatformPluginWrapper();
    virtual QString applicationName() const;
    virtual QObject * createBackend();
    virtual QObject * createBackend(const QString & library, const QString & version);
    virtual Phonon::AbstractMediaStream * createMediaStream(const QUrl & url, QObject * parent);
    virtual QList<QPair<QByteArray, QString > > deviceAccessListFor(const Phonon::AudioCaptureDevice & arg__1) const;
    virtual QList<QPair<QByteArray, QString > > deviceAccessListFor(const Phonon::AudioOutputDevice & arg__1) const;
    virtual QList<QPair<QByteArray, QString > > deviceAccessListFor(const Phonon::VideoCaptureDevice & arg__1) const;
    virtual QIcon icon(const QString & name) const;
    virtual bool isMimeTypeAvailable(const QString & mimeType) const;
    virtual qreal loadVolume(const QString & outputName) const;
    virtual void notification(const char * notificationName, const QString & text, const QStringList & actions = QStringList(), QObject * receiver = 0, const char * actionSlot = 0) const;
    virtual QList<int > objectDescriptionIndexes(Phonon::ObjectDescriptionType type) const;
    virtual QHash<QByteArray, QVariant > objectDescriptionProperties(Phonon::ObjectDescriptionType type, int index) const;
    virtual void saveVolume(const QString & outputName, qreal volume);
    virtual ~PlatformPluginWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_PLATFORMPLUGINWRAPPER_H

