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

#ifndef SBK_QGRAPHICSSCENEWRAPPER_H
#define SBK_QGRAPHICSSCENEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qgraphicsscene.h>

namespace PySide { class DynamicQMetaObject; }

class QGraphicsSceneWrapper : public QGraphicsScene
{
public:
    QGraphicsSceneWrapper(QObject * parent = 0);
    QGraphicsSceneWrapper(const QRectF & sceneRect, QObject * parent = 0);
    QGraphicsSceneWrapper(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
    virtual void drawBackground(QPainter * painter, const QRectF & rect);
    virtual void drawForeground(QPainter * painter, const QRectF & rect);
    virtual void dropEvent(QGraphicsSceneDragDropEvent * event);
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * watched, QEvent * event);
    virtual void focusInEvent(QFocusEvent * event);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual void helpEvent(QGraphicsSceneHelpEvent * event);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const;
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void wheelEvent(QGraphicsSceneWheelEvent * event);
    virtual ~QGraphicsSceneWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGRAPHICSSCENEWRAPPER_H

