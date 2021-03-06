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

#ifndef SBK_QSTACKEDLAYOUTWRAPPER_H
#define SBK_QSTACKEDLAYOUTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qstackedlayout.h>

namespace PySide { class DynamicQMetaObject; }

class QStackedLayoutWrapper : public QStackedLayout
{
public:
    QStackedLayoutWrapper();
    QStackedLayoutWrapper(QLayout * parentLayout);
    QStackedLayoutWrapper(QWidget * parent);
    virtual void addItem(QLayoutItem * item);
    virtual void childEvent(QChildEvent * e);
    virtual void connectNotify(const char * signal);
    virtual int count() const;
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QFlags<Qt::Orientation> expandingDirections() const;
    virtual QRect geometry() const;
    virtual bool hasHeightForWidth() const;
    virtual int heightForWidth(int arg__1) const;
    virtual int indexOf(QWidget * arg__1) const;
    virtual void invalidate();
    virtual bool isEmpty() const;
    virtual QLayoutItem * itemAt(int arg__1) const;
    virtual QLayout * layout();
    virtual QSize maximumSize() const;
    virtual const QMetaObject * metaObject() const;
    virtual int minimumHeightForWidth(int arg__1) const;
    virtual QSize minimumSize() const;
    virtual void setGeometry(const QRect & rect);
    virtual QSize sizeHint() const;
    virtual QSpacerItem * spacerItem();
    virtual QLayoutItem * takeAt(int arg__1);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual QWidget * widget();
    virtual ~QStackedLayoutWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    // Inherited overloads, because the using keyword sux
    inline QWidget * widget(int arg__1) const { return QStackedLayout::widget(arg__1); }
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSTACKEDLAYOUTWRAPPER_H

