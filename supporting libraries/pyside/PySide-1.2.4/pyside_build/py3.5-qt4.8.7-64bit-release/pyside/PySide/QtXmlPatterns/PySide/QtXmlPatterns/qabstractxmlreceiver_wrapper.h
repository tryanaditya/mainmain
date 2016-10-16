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

#ifndef SBK_QABSTRACTXMLRECEIVERWRAPPER_H
#define SBK_QABSTRACTXMLRECEIVERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qabstractxmlreceiver.h>

class QAbstractXmlReceiverWrapper : public QAbstractXmlReceiver
{
public:
    QAbstractXmlReceiverWrapper();
    virtual void atomicValue(const QVariant & value);
    virtual void attribute(const QXmlName & name, const QStringRef & value);
    virtual void characters(const QStringRef & value);
    virtual void comment(const QString & value);
    virtual void endDocument();
    virtual void endElement();
    virtual void endOfSequence();
    virtual void namespaceBinding(const QXmlName & name);
    virtual void processingInstruction(const QXmlName & target, const QString & value);
    virtual void startDocument();
    virtual void startElement(const QXmlName & name);
    virtual void startOfSequence();
    virtual void whitespaceOnly(const QStringRef & value);
    virtual ~QAbstractXmlReceiverWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTXMLRECEIVERWRAPPER_H

