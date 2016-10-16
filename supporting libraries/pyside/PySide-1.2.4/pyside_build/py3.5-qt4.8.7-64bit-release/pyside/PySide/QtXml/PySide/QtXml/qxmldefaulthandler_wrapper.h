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

#ifndef SBK_QXMLDEFAULTHANDLERWRAPPER_H
#define SBK_QXMLDEFAULTHANDLERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qxml.h>

class QXmlDefaultHandlerWrapper : public QXmlDefaultHandler
{
public:
    QXmlDefaultHandlerWrapper();
    virtual bool attributeDecl(const QString & eName, const QString & aName, const QString & type, const QString & valueDefault, const QString & value);
    virtual bool characters(const QString & ch);
    virtual bool comment(const QString & ch);
    virtual bool endCDATA();
    virtual bool endDTD();
    virtual bool endDocument();
    virtual bool endElement(const QString & namespaceURI, const QString & localName, const QString & qName);
    virtual bool endEntity(const QString & name);
    virtual bool endPrefixMapping(const QString & prefix);
    virtual bool error(const QXmlParseException & exception);
    virtual QString errorString() const;
    virtual bool externalEntityDecl(const QString & name, const QString & publicId, const QString & systemId);
    virtual bool fatalError(const QXmlParseException & exception);
    virtual bool ignorableWhitespace(const QString & ch);
    virtual bool internalEntityDecl(const QString & name, const QString & value);
    virtual bool notationDecl(const QString & name, const QString & publicId, const QString & systemId);
    virtual bool processingInstruction(const QString & target, const QString & data);
    virtual bool resolveEntity(const QString & publicId, const QString & systemId, QXmlInputSource *& ret);
    virtual void setDocumentLocator(QXmlLocator * locator);
    virtual bool skippedEntity(const QString & name);
    virtual bool startCDATA();
    virtual bool startDTD(const QString & name, const QString & publicId, const QString & systemId);
    virtual bool startDocument();
    virtual bool startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts);
    virtual bool startEntity(const QString & name);
    virtual bool startPrefixMapping(const QString & prefix, const QString & uri);
    virtual bool unparsedEntityDecl(const QString & name, const QString & publicId, const QString & systemId, const QString & notationName);
    virtual bool warning(const QXmlParseException & exception);
    virtual ~QXmlDefaultHandlerWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QXMLDEFAULTHANDLERWRAPPER_H

