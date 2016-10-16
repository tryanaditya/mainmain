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

#ifndef SBK_QURLINFOWRAPPER_H
#define SBK_QURLINFOWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qurlinfo.h>

class QUrlInfoWrapper : public QUrlInfo
{
public:
    QUrlInfoWrapper();
    QUrlInfoWrapper(const QString & name, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable);
    QUrlInfoWrapper(const QUrl & url, int permissions, const QString & owner, const QString & group, qint64 size, const QDateTime & lastModified, const QDateTime & lastRead, bool isDir, bool isFile, bool isSymLink, bool isWritable, bool isReadable, bool isExecutable);
    QUrlInfoWrapper(const QUrlInfo& self) : QUrlInfo(self)
    {
    }

    virtual void setDir(bool b);
    virtual void setFile(bool b);
    virtual void setGroup(const QString & s);
    virtual void setLastModified(const QDateTime & dt);
    virtual void setName(const QString & name);
    virtual void setOwner(const QString & s);
    virtual void setPermissions(int p);
    virtual void setReadable(bool b);
    virtual void setSize(qint64 size);
    virtual void setSymLink(bool b);
    virtual void setWritable(bool b);
    virtual ~QUrlInfoWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QURLINFOWRAPPER_H

