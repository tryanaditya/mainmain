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

#ifndef SBK_QTEXTBROWSERWRAPPER_H
#define SBK_QTEXTBROWSERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qtextbrowser.h>

namespace PySide { class DynamicQMetaObject; }

class QTextBrowserWrapper : public QTextBrowser
{
public:
    QTextBrowserWrapper(QWidget * parent = 0);
    virtual void actionEvent(QActionEvent * event);
    virtual void backward();
    virtual bool canInsertFromMimeData(const QMimeData * source) const;
    virtual void changeEvent(QEvent * e);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEvent(QCloseEvent * event);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * e);
    virtual QMimeData * createMimeDataFromSelection() const;
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * e);
    virtual void dragLeaveEvent(QDragLeaveEvent * e);
    virtual void dragMoveEvent(QDragMoveEvent * e);
    virtual void dropEvent(QDropEvent * e);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * e);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void focusInEvent(QFocusEvent * e);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * ev);
    virtual void forward();
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual void home();
    virtual void inputMethodEvent(QInputMethodEvent * arg__1);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery property) const;
    virtual void insertFromMimeData(const QMimeData * source);
    virtual void keyPressEvent(QKeyEvent * ev);
    virtual void keyReleaseEvent(QKeyEvent * e);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual QVariant loadResource(int type, const QUrl & name);
    virtual const QMetaObject * metaObject() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * e);
    virtual void mouseMoveEvent(QMouseEvent * ev);
    virtual void mousePressEvent(QMouseEvent * ev);
    virtual void mouseReleaseEvent(QMouseEvent * ev);
    virtual void moveEvent(QMoveEvent * event);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * e);
    virtual void reload();
    virtual void resizeEvent(QResizeEvent * e);
    virtual void scrollContentsBy(int dx, int dy);
    virtual void setSource(const QUrl & name);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * arg__1);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * e);
    virtual bool viewportEvent(QEvent * arg__1);
    virtual void wheelEvent(QWheelEvent * e);
    virtual ~QTextBrowserWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QTEXTBROWSERWRAPPER_H

