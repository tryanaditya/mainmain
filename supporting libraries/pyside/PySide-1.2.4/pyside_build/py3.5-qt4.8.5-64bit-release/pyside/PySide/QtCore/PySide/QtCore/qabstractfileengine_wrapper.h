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

#ifndef SBK_QABSTRACTFILEENGINEWRAPPER_H
#define SBK_QABSTRACTFILEENGINEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qabstractfileengine.h>

class QAbstractFileEngineWrapper : public QAbstractFileEngine
{
public:
    QAbstractFileEngineWrapper();
    virtual QAbstractFileEngineIterator * beginEntryList(QFlags<QDir::Filter> filters, const QStringList & filterNames);
    virtual bool caseSensitive() const;
    virtual bool close();
    virtual bool copy(const QString & newName);
    virtual QStringList entryList(QFlags<QDir::Filter> filters, const QStringList & filterNames) const;
    virtual QFlags<QAbstractFileEngine::FileFlag> fileFlags(QFlags<QAbstractFileEngine::FileFlag> type = QAbstractFileEngine::FileInfoAll) const;
    virtual QString fileName(QAbstractFileEngine::FileName file = DefaultName) const;
    virtual QDateTime fileTime(QAbstractFileEngine::FileTime time) const;
    virtual bool flush();
    virtual int handle() const;
    virtual bool isRelativePath() const;
    virtual bool isSequential() const;
    virtual bool link(const QString & newName);
    virtual bool mkdir(const QString & dirName, bool createParentDirectories) const;
    virtual bool open(QFlags<QIODevice::OpenModeFlag> openMode);
    virtual QString owner(QAbstractFileEngine::FileOwner arg__1) const;
    virtual uint ownerId(QAbstractFileEngine::FileOwner arg__1) const;
    virtual qint64 pos() const;
    virtual qint64 read(char * data, qint64 maxlen);
    virtual qint64 readLine(char * data, qint64 maxlen);
    virtual bool remove();
    virtual bool rename(const QString & newName);
    virtual bool rmdir(const QString & dirName, bool recurseParentDirectories) const;
    virtual bool seek(qint64 pos);
    virtual void setFileName(const QString & file);
    virtual bool setPermissions(uint perms);
    virtual bool setSize(qint64 size);
    virtual qint64 size() const;
    virtual bool supportsExtension(QAbstractFileEngine::Extension extension) const;
    virtual qint64 write(const char * data, qint64 len);
    virtual ~QAbstractFileEngineWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTFILEENGINEWRAPPER_H

