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

#ifndef SBK_QGRAPHICSTEXTITEMWRAPPER_H
#define SBK_QGRAPHICSTEXTITEMWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qgraphicsitem.h>

namespace PySide { class DynamicQMetaObject; }

class QGraphicsTextItemWrapper : public QGraphicsTextItem
{
public:
    QGraphicsTextItemWrapper(QGraphicsItem * parent = 0, QGraphicsScene * scene = 0);
    QGraphicsTextItemWrapper(const QString & text, QGraphicsItem * parent = 0, QGraphicsScene * scene = 0);
    virtual void advance(int phase);
    virtual QRectF boundingRect() const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual bool collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    virtual bool collidesWithPath(const QPainterPath & path, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    virtual void connectNotify(const char * signal);
    virtual bool contains(const QPointF & point) const;
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
    virtual void dropEvent(QGraphicsSceneDragDropEvent * event);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QVariant extension(const QVariant & variant) const;
    virtual void focusInEvent(QFocusEvent * event);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const;
    virtual bool isObscuredBy(const QGraphicsItem * item) const;
    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value);
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    virtual QPainterPath opaqueArea() const;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    virtual bool sceneEvent(QEvent * event);
    virtual bool sceneEventFilter(QGraphicsItem * watched, QEvent * event);
    virtual QPainterPath shape() const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual int type() const;
    virtual void wheelEvent(QGraphicsSceneWheelEvent * event);
    virtual ~QGraphicsTextItemWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGRAPHICSTEXTITEMWRAPPER_H

