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

#ifndef SBK_QGLWIDGETWRAPPER_H
#define SBK_QGLWIDGETWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qgl.h>

namespace PySide { class DynamicQMetaObject; }

class QGLWidgetWrapper : public QGLWidget
{
public:
    QGLWidgetWrapper(QGLContext * context, QWidget * parent = 0, const QGLWidget * shareWidget = 0, QFlags<Qt::WindowType> f = 0);
    QGLWidgetWrapper(QWidget * parent = 0, const QGLWidget * shareWidget = 0, QFlags<Qt::WindowType> f = 0);
    QGLWidgetWrapper(const QGLFormat & format, QWidget * parent = 0, const QGLWidget * shareWidget = 0, QFlags<Qt::WindowType> f = 0);
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
    virtual void glDraw();
    virtual void glInit();
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual void initializeGL();
    virtual void initializeOverlayGL();
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
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void moveEvent(QMoveEvent * event);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * arg__1);
    virtual void paintGL();
    virtual void paintOverlayGL();
    virtual void resizeEvent(QResizeEvent * arg__1);
    virtual void resizeGL(int w, int h);
    virtual void resizeOverlayGL(int w, int h);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * event);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void updateGL();
    virtual void updateOverlayGL();
    virtual void wheelEvent(QWheelEvent * event);
    virtual ~QGLWidgetWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGLWIDGETWRAPPER_H

