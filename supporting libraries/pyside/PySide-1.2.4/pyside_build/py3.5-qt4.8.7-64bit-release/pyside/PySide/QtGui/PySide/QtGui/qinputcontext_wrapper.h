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

#ifndef SBK_QINPUTCONTEXTWRAPPER_H
#define SBK_QINPUTCONTEXTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qinputcontext.h>

namespace PySide { class DynamicQMetaObject; }

class QInputContextWrapper : public QInputContext
{
public:
    QInputContextWrapper(QObject * parent = 0);
    virtual QList<QAction * > actions();
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual bool filterEvent(const QEvent * event);
    virtual QFont font() const;
    virtual QString identifierName();
    virtual bool isComposing() const;
    virtual QString language();
    virtual const QMetaObject * metaObject() const;
    virtual void mouseHandler(int x, QMouseEvent * event);
    virtual void reset();
    virtual void setFocusWidget(QWidget * w);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void update();
    virtual void widgetDestroyed(QWidget * w);
    virtual ~QInputContextWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QINPUTCONTEXTWRAPPER_H

