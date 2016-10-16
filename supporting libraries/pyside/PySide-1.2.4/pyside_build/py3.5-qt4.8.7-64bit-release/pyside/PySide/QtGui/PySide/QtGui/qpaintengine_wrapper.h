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

#ifndef SBK_QPAINTENGINEWRAPPER_H
#define SBK_QPAINTENGINEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qpaintengine.h>

class QPaintEngineWrapper : public QPaintEngine
{
public:
    QPaintEngineWrapper(QFlags<QPaintEngine::PaintEngineFeature> features = 0);
    virtual bool begin(QPaintDevice * pdev);
    virtual QPoint coordinateOffset() const;
    virtual void drawEllipse(const QRect & r);
    virtual void drawEllipse(const QRectF & r);
    virtual void drawImage(const QRectF & r, const QImage & pm, const QRectF & sr, QFlags<Qt::ImageConversionFlag> flags = Qt::AutoColor);
    virtual void drawLines(const QLine * lines, int lineCount);
    virtual void drawLines(const QLineF * lines, int lineCount);
    virtual void drawPath(const QPainterPath & path);
    virtual void drawPixmap(const QRectF & r, const QPixmap & pm, const QRectF & sr);
    virtual void drawPoints(const QPoint * points, int pointCount);
    virtual void drawPoints(const QPointF * points, int pointCount);
    virtual void drawPolygon(const QPoint * points, int pointCount, QPaintEngine::PolygonDrawMode mode);
    virtual void drawPolygon(const QPointF * points, int pointCount, QPaintEngine::PolygonDrawMode mode);
    virtual void drawRects(const QRect * rects, int rectCount);
    virtual void drawRects(const QRectF * rects, int rectCount);
    virtual void drawTextItem(const QPointF & p, const QTextItem & textItem);
    virtual void drawTiledPixmap(const QRectF & r, const QPixmap & pixmap, const QPointF & s);
    virtual bool end();
    virtual QPaintEngine::Type type() const;
    virtual void updateState(const QPaintEngineState & state);
    virtual ~QPaintEngineWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QPAINTENGINEWRAPPER_H

