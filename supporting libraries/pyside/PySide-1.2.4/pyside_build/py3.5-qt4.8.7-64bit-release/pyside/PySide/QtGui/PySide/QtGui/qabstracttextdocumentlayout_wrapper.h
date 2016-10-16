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

#ifndef SBK_QABSTRACTTEXTDOCUMENTLAYOUTWRAPPER_H
#define SBK_QABSTRACTTEXTDOCUMENTLAYOUTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qabstracttextdocumentlayout.h>

namespace PySide { class DynamicQMetaObject; }

class QAbstractTextDocumentLayoutWrapper : public QAbstractTextDocumentLayout
{
public:
    QAbstractTextDocumentLayoutWrapper(QTextDocument * doc);
    virtual QRectF blockBoundingRect(const QTextBlock & block) const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual void documentChanged(int from, int charsRemoved, int charsAdded);
    virtual QSizeF documentSize() const;
    virtual void draw(QPainter * painter, const QAbstractTextDocumentLayout::PaintContext & context);
    virtual void drawInlineObject(QPainter * painter, const QRectF & rect, QTextInlineObject object, int posInDocument, const QTextFormat & format);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QRectF frameBoundingRect(QTextFrame * frame) const;
    virtual int hitTest(const QPointF & point, Qt::HitTestAccuracy accuracy) const;
    virtual const QMetaObject * metaObject() const;
    virtual int pageCount() const;
    virtual void positionInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat & format);
    virtual void resizeInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat & format);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QAbstractTextDocumentLayoutWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTTEXTDOCUMENTLAYOUTWRAPPER_H

