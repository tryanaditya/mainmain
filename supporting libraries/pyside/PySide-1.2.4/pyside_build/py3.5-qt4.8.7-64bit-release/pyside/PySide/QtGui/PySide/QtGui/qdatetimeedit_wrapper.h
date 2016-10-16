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

#ifndef SBK_QDATETIMEEDITWRAPPER_H
#define SBK_QDATETIMEEDITWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qdatetimeedit.h>

namespace PySide { class DynamicQMetaObject; }

class QDateTimeEditWrapper : public QDateTimeEdit
{
public:
    QDateTimeEditWrapper(QWidget * parent = 0);
    QDateTimeEditWrapper(const QDate & d, QWidget * parent = 0);
    QDateTimeEditWrapper(const QDateTime & dt, QWidget * parent = 0);
    QDateTimeEditWrapper(const QTime & t, QWidget * parent = 0);
    QDateTimeEditWrapper(const QVariant & val, QVariant::Type parserType, QWidget * parent = 0);
    virtual void actionEvent(QActionEvent * event);
    virtual void changeEvent(QEvent * event);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void clear();
    virtual void closeEvent(QCloseEvent * event);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * event);
    virtual void customEvent(QEvent * arg__1);
    virtual QDateTime dateTimeFromText(const QString & text) const;
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * event);
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * event);
    virtual void dropEvent(QDropEvent * event);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void fixup(QString & input) const;
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
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
    virtual void paintEvent(QPaintEvent * event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * event);
    virtual QSize sizeHint() const;
    virtual void stepBy(int steps);
    virtual QFlags<QAbstractSpinBox::StepEnabledFlag> stepEnabled() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual QString textFromDateTime(const QDateTime & dt) const;
    virtual void timerEvent(QTimerEvent * event);
    virtual QValidator::State validate(QString & input, int & pos) const;
    virtual void wheelEvent(QWheelEvent * event);
    virtual ~QDateTimeEditWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QDATETIMEEDITWRAPPER_H

