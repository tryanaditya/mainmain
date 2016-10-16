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

#ifndef SBK_QSPACERITEMWRAPPER_H
#define SBK_QSPACERITEMWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qlayoutitem.h>

class QSpacerItemWrapper : public QSpacerItem
{
public:
    QSpacerItemWrapper(int w, int h, QSizePolicy::Policy hData = QSizePolicy::Minimum, QSizePolicy::Policy vData = QSizePolicy::Minimum);
    virtual QFlags<Qt::Orientation> expandingDirections() const;
    virtual QRect geometry() const;
    virtual bool hasHeightForWidth() const;
    virtual int heightForWidth(int arg__1) const;
    virtual void invalidate();
    virtual bool isEmpty() const;
    virtual QLayout * layout();
    virtual QSize maximumSize() const;
    virtual int minimumHeightForWidth(int arg__1) const;
    virtual QSize minimumSize() const;
    virtual void setGeometry(const QRect & arg__1);
    virtual QSize sizeHint() const;
    virtual QSpacerItem * spacerItem();
    virtual QWidget * widget();
    virtual ~QSpacerItemWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSPACERITEMWRAPPER_H

