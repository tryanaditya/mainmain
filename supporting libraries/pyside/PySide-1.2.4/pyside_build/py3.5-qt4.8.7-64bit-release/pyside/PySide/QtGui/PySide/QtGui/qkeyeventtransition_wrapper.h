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

#ifndef SBK_QKEYEVENTTRANSITIONWRAPPER_H
#define SBK_QKEYEVENTTRANSITIONWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qkeyeventtransition.h>

namespace PySide { class DynamicQMetaObject; }

class QKeyEventTransitionWrapper : public QKeyEventTransition
{
public:
    QKeyEventTransitionWrapper(QObject * object, QEvent::Type type, int key, QState * sourceState = 0);
    QKeyEventTransitionWrapper(QState * sourceState = 0);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * e);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual bool eventTest(QEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual void onTransition(QEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~QKeyEventTransitionWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QKEYEVENTTRANSITIONWRAPPER_H

