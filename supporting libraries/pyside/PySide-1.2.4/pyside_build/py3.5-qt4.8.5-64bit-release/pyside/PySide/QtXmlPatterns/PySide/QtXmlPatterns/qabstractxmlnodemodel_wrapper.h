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

#ifndef SBK_QABSTRACTXMLNODEMODELWRAPPER_H
#define SBK_QABSTRACTXMLNODEMODELWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qabstractxmlnodemodel.h>

class QAbstractXmlNodeModelWrapper : public QAbstractXmlNodeModel
{
public:
    QAbstractXmlNodeModelWrapper();
    virtual QVector<QXmlNodeModelIndex > attributes(const QXmlNodeModelIndex & element) const;
    virtual QUrl baseUri(const QXmlNodeModelIndex & ni) const;
    virtual QXmlNodeModelIndex::DocumentOrder compareOrder(const QXmlNodeModelIndex & ni1, const QXmlNodeModelIndex & ni2) const;
    virtual QUrl documentUri(const QXmlNodeModelIndex & ni) const;
    virtual QXmlNodeModelIndex elementById(const QXmlName & NCName) const;
    virtual bool isDeepEqual(const QXmlNodeModelIndex & ni1, const QXmlNodeModelIndex & ni2) const;
    virtual QXmlNodeModelIndex::NodeKind kind(const QXmlNodeModelIndex & ni) const;
    virtual QXmlName name(const QXmlNodeModelIndex & ni) const;
    virtual QVector<QXmlName > namespaceBindings(const QXmlNodeModelIndex & n) const;
    virtual short namespaceForPrefix(const QXmlNodeModelIndex & ni, const short prefix) const;
    virtual QXmlNodeModelIndex nextFromSimpleAxis(QAbstractXmlNodeModel::SimpleAxis axis, const QXmlNodeModelIndex & origin) const;
    virtual QVector<QXmlNodeModelIndex > nodesByIdref(const QXmlName & NCName) const;
    virtual QXmlNodeModelIndex root(const QXmlNodeModelIndex & n) const;
    virtual void sendNamespaces(const QXmlNodeModelIndex & n, QAbstractXmlReceiver * receiver) const;
    virtual QString stringValue(const QXmlNodeModelIndex & n) const;
    virtual QVariant typedValue(const QXmlNodeModelIndex & n) const;
    virtual ~QAbstractXmlNodeModelWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTXMLNODEMODELWRAPPER_H

