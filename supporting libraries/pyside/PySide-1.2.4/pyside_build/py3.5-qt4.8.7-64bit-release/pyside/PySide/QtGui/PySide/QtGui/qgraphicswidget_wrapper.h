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

#ifndef SBK_QGRAPHICSWIDGETWRAPPER_H
#define SBK_QGRAPHICSWIDGETWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qgraphicswidget.h>

namespace PySide { class DynamicQMetaObject; }

class QGraphicsWidgetWrapper : public QGraphicsWidget
{
public:
    QGraphicsWidgetWrapper(QGraphicsItem * parent = 0, QFlags<Qt::WindowType> wFlags = 0);
    virtual void advance(int phase);
    virtual QRectF boundingRect() const;
    virtual void changeEvent(QEvent * event);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEvent(QCloseEvent * event);
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
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QVariant extension(const QVariant & variant) const;
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual void getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const;
    virtual void grabKeyboardEvent(QEvent * event);
    virtual void grabMouseEvent(QEvent * event);
    virtual void hideEvent(QHideEvent * event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
    virtual void initStyleOption(QStyleOption * option) const;
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
    virtual void moveEvent(QGraphicsSceneMoveEvent * event);
    virtual QPainterPath opaqueArea() const;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    virtual void paintWindowFrame(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    virtual void polishEvent();
    virtual QVariant propertyChange(const QString & propertyName, const QVariant & value);
    virtual void resizeEvent(QGraphicsSceneResizeEvent * event);
    virtual bool sceneEvent(QEvent * event);
    virtual bool sceneEventFilter(QGraphicsItem * watched, QEvent * event);
    virtual void setGeometry(const QRectF & rect);
    virtual QPainterPath shape() const;
    virtual void showEvent(QShowEvent * event);
    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF & constraint = QSizeF()) const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual int type() const;
    virtual void ungrabKeyboardEvent(QEvent * event);
    virtual void ungrabMouseEvent(QEvent * event);
    virtual void updateGeometry();
    virtual void wheelEvent(QGraphicsSceneWheelEvent * event);
    virtual bool windowFrameEvent(QEvent * e);
    virtual Qt::WindowFrameSection windowFrameSectionAt(const QPointF & pos) const;
    virtual ~QGraphicsWidgetWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    // Inherited overloads, because the using keyword sux
    inline void setGeometry(qreal x, qreal y, qreal w, qreal h) { QGraphicsWidget::setGeometry(x, y, w, h); }
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGRAPHICSWIDGETWRAPPER_H

