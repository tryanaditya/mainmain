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

#ifndef SBK_BACKENDINTERFACEWRAPPER_H
#define SBK_BACKENDINTERFACEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <backendinterface.h>

class BackendInterfaceWrapper : public Phonon::BackendInterface
{
public:
    BackendInterfaceWrapper();
    virtual QStringList availableMimeTypes() const;
    virtual bool connectNodes(QObject * arg__1, QObject * arg__2);
    virtual QObject * createObject(Phonon::BackendInterface::Class c, QObject * parent, const QList<QVariant > & args = QList< QVariant >());
    virtual bool disconnectNodes(QObject * arg__1, QObject * arg__2);
    virtual bool endConnectionChange(QSet<QObject * > arg__1);
    virtual QList<int > objectDescriptionIndexes(Phonon::ObjectDescriptionType type) const;
    virtual QHash<QByteArray, QVariant > objectDescriptionProperties(Phonon::ObjectDescriptionType type, int index) const;
    virtual bool startConnectionChange(QSet<QObject * > arg__1);
    virtual ~BackendInterfaceWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_BACKENDINTERFACEWRAPPER_H

