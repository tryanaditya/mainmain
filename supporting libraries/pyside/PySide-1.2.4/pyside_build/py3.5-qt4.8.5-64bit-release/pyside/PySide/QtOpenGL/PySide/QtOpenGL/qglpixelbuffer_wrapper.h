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

#ifndef SBK_QGLPIXELBUFFERWRAPPER_H
#define SBK_QGLPIXELBUFFERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qglpixelbuffer.h>

class QGLPixelBufferWrapper : public QGLPixelBuffer
{
public:
    QGLPixelBufferWrapper(const QSize & size, const QGLFormat & format = QGLFormat::defaultFormat(), QGLWidget * shareWidget = 0);
    QGLPixelBufferWrapper(int width, int height, const QGLFormat & format = QGLFormat::defaultFormat(), QGLWidget * shareWidget = 0);
    virtual int devType() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric metric) const;
    virtual QPaintEngine * paintEngine() const;
    virtual ~QGLPixelBufferWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGLPIXELBUFFERWRAPPER_H

