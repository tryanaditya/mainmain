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

#ifndef SBK_VIDEOWIDGETINTERFACEWRAPPER_H
#define SBK_VIDEOWIDGETINTERFACEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <videowidgetinterface.h>

class VideoWidgetInterfaceWrapper : public Phonon::VideoWidgetInterface
{
public:
    VideoWidgetInterfaceWrapper();
    virtual Phonon::VideoWidget::AspectRatio aspectRatio() const;
    virtual qreal brightness() const;
    virtual qreal contrast() const;
    virtual qreal hue() const;
    virtual qreal saturation() const;
    virtual Phonon::VideoWidget::ScaleMode scaleMode() const;
    virtual void setAspectRatio(Phonon::VideoWidget::AspectRatio arg__1);
    virtual void setBrightness(qreal arg__1);
    virtual void setContrast(qreal arg__1);
    virtual void setHue(qreal arg__1);
    virtual void setSaturation(qreal arg__1);
    virtual void setScaleMode(Phonon::VideoWidget::ScaleMode arg__1);
    virtual QWidget * widget();
    virtual ~VideoWidgetInterfaceWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_VIDEOWIDGETINTERFACEWRAPPER_H

