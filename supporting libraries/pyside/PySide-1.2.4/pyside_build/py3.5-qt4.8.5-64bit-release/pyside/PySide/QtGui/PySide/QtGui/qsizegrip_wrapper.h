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

#ifndef SBK_QSIZEGRIPWRAPPER_H
#define SBK_QSIZEGRIPWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qsizegrip.h>

namespace PySide { class DynamicQMetaObject; }

class QSizeGripWrapper : public QSizeGrip
{
public:
    QSizeGripWrapper(QWidget * parent);
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * event);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEvent(QCloseEvent * event);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * event);
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * event);
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * event);
    virtual void dropEvent(QDropEvent * event);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * hideEvent);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const;
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * arg__1);
    virtual void mousePressEvent(QMouseEvent * arg__1);
    virtual void mouseReleaseEvent(QMouseEvent * mouseEvent);
    virtual void moveEvent(QMoveEvent * moveEvent);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * arg__1);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void setVisible(bool arg__1);
    virtual void showEvent(QShowEvent * showEvent);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void wheelEvent(QWheelEvent * event);
    virtual ~QSizeGripWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSIZEGRIPWRAPPER_H

