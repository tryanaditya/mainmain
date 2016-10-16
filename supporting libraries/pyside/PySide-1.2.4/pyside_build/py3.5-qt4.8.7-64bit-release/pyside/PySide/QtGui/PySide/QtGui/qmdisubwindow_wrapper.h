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

#ifndef SBK_QMDISUBWINDOWWRAPPER_H
#define SBK_QMDISUBWINDOWWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qmdisubwindow.h>

namespace PySide { class DynamicQMetaObject; }

class QMdiSubWindowWrapper : public QMdiSubWindow
{
public:
    QMdiSubWindowWrapper(QWidget * parent = 0, QFlags<Qt::WindowType> flags = 0);
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * changeEvent);
    virtual void childEvent(QChildEvent * childEvent);
    virtual void closeEvent(QCloseEvent * closeEvent);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * contextMenuEvent);
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * event);
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * event);
    virtual void dropEvent(QDropEvent * event);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * object, QEvent * event);
    virtual void focusInEvent(QFocusEvent * focusInEvent);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * focusOutEvent);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * hideEvent);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const;
    virtual void keyPressEvent(QKeyEvent * keyEvent);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * leaveEvent);
    virtual const QMetaObject * metaObject() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * mouseEvent);
    virtual void mouseMoveEvent(QMouseEvent * mouseEvent);
    virtual void mousePressEvent(QMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QMouseEvent * mouseEvent);
    virtual void moveEvent(QMoveEvent * moveEvent);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * paintEvent);
    virtual void resizeEvent(QResizeEvent * resizeEvent);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * showEvent);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * timerEvent);
    virtual void wheelEvent(QWheelEvent * event);
    virtual ~QMdiSubWindowWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QMDISUBWINDOWWRAPPER_H

