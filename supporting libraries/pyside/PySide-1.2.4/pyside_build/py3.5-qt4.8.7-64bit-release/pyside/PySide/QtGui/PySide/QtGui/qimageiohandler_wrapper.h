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

#ifndef SBK_QIMAGEIOHANDLERWRAPPER_H
#define SBK_QIMAGEIOHANDLERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qimageiohandler.h>

class QImageIOHandlerWrapper : public QImageIOHandler
{
public:
    QImageIOHandlerWrapper();
    virtual bool canRead() const;
    virtual int currentImageNumber() const;
    virtual QRect currentImageRect() const;
    virtual int imageCount() const;
    virtual bool jumpToImage(int imageNumber);
    virtual bool jumpToNextImage();
    virtual int loopCount() const;
    virtual int nextImageDelay() const;
    virtual QVariant option(QImageIOHandler::ImageOption option) const;
    virtual bool read(QImage * image);
    virtual void setOption(QImageIOHandler::ImageOption option, const QVariant & value);
    virtual bool supportsOption(QImageIOHandler::ImageOption option) const;
    virtual bool write(const QImage & image);
    virtual ~QImageIOHandlerWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QIMAGEIOHANDLERWRAPPER_H

