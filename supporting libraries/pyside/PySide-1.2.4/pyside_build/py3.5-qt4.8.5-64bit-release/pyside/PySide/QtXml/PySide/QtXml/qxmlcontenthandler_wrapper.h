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

#ifndef SBK_QXMLCONTENTHANDLERWRAPPER_H
#define SBK_QXMLCONTENTHANDLERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qxml.h>

class QXmlContentHandlerWrapper : public QXmlContentHandler
{
public:
    QXmlContentHandlerWrapper();
    virtual bool characters(const QString & ch);
    virtual bool endDocument();
    virtual bool endElement(const QString & namespaceURI, const QString & localName, const QString & qName);
    virtual bool endPrefixMapping(const QString & prefix);
    virtual QString errorString() const;
    virtual bool ignorableWhitespace(const QString & ch);
    virtual bool processingInstruction(const QString & target, const QString & data);
    virtual void setDocumentLocator(QXmlLocator * locator);
    virtual bool skippedEntity(const QString & name);
    virtual bool startDocument();
    virtual bool startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts);
    virtual bool startPrefixMapping(const QString & prefix, const QString & uri);
    virtual ~QXmlContentHandlerWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QXMLCONTENTHANDLERWRAPPER_H

