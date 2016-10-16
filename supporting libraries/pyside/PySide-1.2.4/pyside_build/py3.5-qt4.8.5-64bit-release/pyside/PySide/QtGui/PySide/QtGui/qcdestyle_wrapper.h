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

#ifndef SBK_QCDESTYLEWRAPPER_H
#define SBK_QCDESTYLEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qcdestyle.h>

namespace PySide { class DynamicQMetaObject; }

class QCDEStyleWrapper : public QCDEStyle
{
public:
    QCDEStyleWrapper(bool useHighlightCols = false);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual void drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, QPainter * p, const QWidget * w = 0) const;
    virtual void drawControl(QStyle::ControlElement element, const QStyleOption * opt, QPainter * p, const QWidget * w = 0) const;
    virtual void drawItemPixmap(QPainter * painter, const QRect & rect, int alignment, const QPixmap & pixmap) const;
    virtual void drawItemText(QPainter * painter, const QRect & rect, int flags, const QPalette & pal, bool enabled, const QString & text, QPalette::ColorRole textRole = QPalette::NoRole) const;
    virtual void drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption * opt, QPainter * p, const QWidget * w = 0) const;
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * o, QEvent * e);
    virtual QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap & pixmap, const QStyleOption * opt) const;
    virtual QStyle::SubControl hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, const QPoint & pt, const QWidget * w = 0) const;
    virtual QRect itemPixmapRect(const QRect & r, int flags, const QPixmap & pixmap) const;
    virtual QRect itemTextRect(const QFontMetrics & fm, const QRect & r, int flags, bool enabled, const QString & text) const;
    virtual const QMetaObject * metaObject() const;
    virtual int pixelMetric(QStyle::PixelMetric metric, const QStyleOption * option = 0, const QWidget * widget = 0) const;
    virtual void polish(QApplication * arg__1);
    virtual void polish(QPalette & arg__1);
    virtual void polish(QWidget * arg__1);
    virtual QSize sizeFromContents(QStyle::ContentsType ct, const QStyleOption * opt, const QSize & contentsSize, const QWidget * widget = 0) const;
    virtual QPalette standardPalette() const;
    virtual QPixmap standardPixmap(QStyle::StandardPixmap standardPixmap, const QStyleOption * opt = 0, const QWidget * widget = 0) const;
    virtual int styleHint(QStyle::StyleHint hint, const QStyleOption * opt = 0, const QWidget * widget = 0, QStyleHintReturn * returnData = 0) const;
    virtual QRect subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, QStyle::SubControl sc, const QWidget * widget = 0) const;
    virtual QRect subElementRect(QStyle::SubElement r, const QStyleOption * opt, const QWidget * widget = 0) const;
    virtual void timerEvent(QTimerEvent * event);
    virtual void unpolish(QApplication * arg__1);
    virtual void unpolish(QWidget * arg__1);
    virtual ~QCDEStyleWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QCDESTYLEWRAPPER_H

