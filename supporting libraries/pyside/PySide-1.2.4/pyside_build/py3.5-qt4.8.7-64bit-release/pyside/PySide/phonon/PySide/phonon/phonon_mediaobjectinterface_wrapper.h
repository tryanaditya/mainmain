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

#ifndef SBK_MEDIAOBJECTINTERFACEWRAPPER_H
#define SBK_MEDIAOBJECTINTERFACEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <mediaobjectinterface.h>

class MediaObjectInterfaceWrapper : public Phonon::MediaObjectInterface
{
public:
    MediaObjectInterfaceWrapper();
    virtual qint64 currentTime() const;
    virtual QString errorString() const;
    virtual Phonon::ErrorType errorType() const;
    virtual bool hasVideo() const;
    virtual bool isSeekable() const;
    virtual void pause();
    virtual void play();
    virtual qint32 prefinishMark() const;
    virtual qint64 remainingTime() const;
    virtual void seek(qint64 milliseconds);
    virtual void setNextSource(const Phonon::MediaSource & source);
    virtual void setPrefinishMark(qint32 arg__1);
    virtual void setSource(const Phonon::MediaSource & arg__1);
    virtual void setTickInterval(qint32 interval);
    virtual void setTransitionTime(qint32 arg__1);
    virtual Phonon::MediaSource source() const;
    virtual Phonon::State state() const;
    virtual void stop();
    virtual qint32 tickInterval() const;
    virtual qint64 totalTime() const;
    virtual qint32 transitionTime() const;
    virtual ~MediaObjectInterfaceWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_MEDIAOBJECTINTERFACEWRAPPER_H

