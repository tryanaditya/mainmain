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

#ifndef SBK_QXMLREADERWRAPPER_H
#define SBK_QXMLREADERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qxml.h>

class QXmlReaderWrapper : public QXmlReader
{
public:
    virtual QXmlDTDHandler * DTDHandler() const;
    QXmlReaderWrapper();
    virtual QXmlContentHandler * contentHandler() const;
    virtual QXmlDeclHandler * declHandler() const;
    virtual QXmlEntityResolver * entityResolver() const;
    virtual QXmlErrorHandler * errorHandler() const;
    virtual bool feature(const QString & name, bool * ok = 0) const;
    virtual bool hasFeature(const QString & name) const;
    virtual bool hasProperty(const QString & name) const;
    virtual QXmlLexicalHandler * lexicalHandler() const;
    virtual bool parse(const QXmlInputSource & input);
    virtual bool parse(const QXmlInputSource * input);
    virtual void * property(const QString & name, bool * ok = 0) const;
    virtual void setContentHandler(QXmlContentHandler * handler);
    virtual void setDTDHandler(QXmlDTDHandler * handler);
    virtual void setDeclHandler(QXmlDeclHandler * handler);
    virtual void setEntityResolver(QXmlEntityResolver * handler);
    virtual void setErrorHandler(QXmlErrorHandler * handler);
    virtual void setFeature(const QString & name, bool value);
    virtual void setLexicalHandler(QXmlLexicalHandler * handler);
    virtual void setProperty(const QString & name, void * value);
    virtual ~QXmlReaderWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QXMLREADERWRAPPER_H

