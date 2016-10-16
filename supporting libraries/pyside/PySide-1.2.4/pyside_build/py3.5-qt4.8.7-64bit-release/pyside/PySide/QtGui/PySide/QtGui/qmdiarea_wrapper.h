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

#ifndef SBK_QMDIAREAWRAPPER_H
#define SBK_QMDIAREAWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qmdiarea.h>

namespace PySide { class DynamicQMetaObject; }

class QMdiAreaWrapper : public QMdiArea
{
public:
    QMdiAreaWrapper(QWidget * parent = 0);
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * arg__1);
    virtual void childEvent(QChildEvent * childEvent);
    virtual void closeEvent(QCloseEvent * event);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * arg__1);
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * arg__1);
    virtual void dragLeaveEvent(QDragLeaveEvent * arg__1);
    virtual void dragMoveEvent(QDragMoveEvent * arg__1);
    virtual void dropEvent(QDropEvent * arg__1);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * object, QEvent * event);
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const;
    virtual void keyPressEvent(QKeyEvent * arg__1);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual const QMetaObject * metaObject() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * arg__1);
    virtual void mouseMoveEvent(QMouseEvent * arg__1);
    virtual void mousePressEvent(QMouseEvent * arg__1);
    virtual void mouseReleaseEvent(QMouseEvent * arg__1);
    virtual void moveEvent(QMoveEvent * event);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * paintEvent);
    virtual void resizeEvent(QResizeEvent * resizeEvent);
    virtual void scrollContentsBy(int dx, int dy);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * showEvent);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * timerEvent);
    virtual bool viewportEvent(QEvent * event);
    virtual void wheelEvent(QWheelEvent * arg__1);
    virtual ~QMdiAreaWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QMDIAREAWRAPPER_H

