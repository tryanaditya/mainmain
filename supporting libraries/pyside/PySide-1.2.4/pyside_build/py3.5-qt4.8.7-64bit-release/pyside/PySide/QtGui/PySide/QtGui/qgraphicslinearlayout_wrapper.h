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

#ifndef SBK_QGRAPHICSLINEARLAYOUTWRAPPER_H
#define SBK_QGRAPHICSLINEARLAYOUTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qgraphicslinearlayout.h>

class QGraphicsLinearLayoutWrapper : public QGraphicsLinearLayout
{
public:
    QGraphicsLinearLayoutWrapper(QGraphicsLayoutItem * parent = 0);
    QGraphicsLinearLayoutWrapper(Qt::Orientation orientation, QGraphicsLayoutItem * parent = 0);
    virtual int count() const;
    virtual void getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const;
    virtual void invalidate();
    virtual QGraphicsLayoutItem * itemAt(int index) const;
    virtual void removeAt(int index);
    virtual void setGeometry(const QRectF & rect);
    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF & constraint = QSizeF()) const;
    virtual void updateGeometry();
    virtual void widgetEvent(QEvent * e);
    virtual ~QGraphicsLinearLayoutWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGRAPHICSLINEARLAYOUTWRAPPER_H

