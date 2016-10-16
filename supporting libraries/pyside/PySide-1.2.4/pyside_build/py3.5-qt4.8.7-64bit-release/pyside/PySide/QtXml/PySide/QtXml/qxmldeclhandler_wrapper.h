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

#ifndef SBK_QXMLDECLHANDLERWRAPPER_H
#define SBK_QXMLDECLHANDLERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qxml.h>

class QXmlDeclHandlerWrapper : public QXmlDeclHandler
{
public:
    QXmlDeclHandlerWrapper();
    virtual bool attributeDecl(const QString & eName, const QString & aName, const QString & type, const QString & valueDefault, const QString & value);
    virtual QString errorString() const;
    virtual bool externalEntityDecl(const QString & name, const QString & publicId, const QString & systemId);
    virtual bool internalEntityDecl(const QString & name, const QString & value);
    virtual ~QXmlDeclHandlerWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QXMLDECLHANDLERWRAPPER_H

