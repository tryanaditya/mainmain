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

#ifndef SBK_QGLFRAMEBUFFEROBJECTWRAPPER_H
#define SBK_QGLFRAMEBUFFEROBJECTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qglframebufferobject.h>

class QGLFramebufferObjectWrapper : public QGLFramebufferObject
{
public:
    QGLFramebufferObjectWrapper(const QSize & size, GLenum target = 0x0DE1);
    QGLFramebufferObjectWrapper(const QSize & size, QGLFramebufferObject::Attachment attachment, GLenum target = 0x0DE1, GLenum internal_format = 0x8058);
    QGLFramebufferObjectWrapper(const QSize & size, const QGLFramebufferObjectFormat & format);
    QGLFramebufferObjectWrapper(int width, int height, GLenum target = 0x0DE1);
    QGLFramebufferObjectWrapper(int width, int height, QGLFramebufferObject::Attachment attachment, GLenum target = 0x0DE1, GLenum internal_format = 0x8058);
    QGLFramebufferObjectWrapper(int width, int height, const QGLFramebufferObjectFormat & format);
    virtual int devType() const;
    virtual int metric(QPaintDevice::PaintDeviceMetric metric) const;
    virtual QPaintEngine * paintEngine() const;
    virtual ~QGLFramebufferObjectWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QGLFRAMEBUFFEROBJECTWRAPPER_H

