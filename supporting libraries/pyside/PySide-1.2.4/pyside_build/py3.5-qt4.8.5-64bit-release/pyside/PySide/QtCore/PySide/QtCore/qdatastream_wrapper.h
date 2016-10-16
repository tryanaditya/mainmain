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

#ifndef SBK_QDATASTREAMWRAPPER_H
#define SBK_QDATASTREAMWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qdatastream.h>

class QDataStreamWrapper : public QDataStream
{
public:
    QDataStreamWrapper();
    QDataStreamWrapper(QByteArray * arg__1, QFlags<QIODevice::OpenModeFlag> flags);
    QDataStreamWrapper(QIODevice * arg__1);
    QDataStreamWrapper(const QByteArray & arg__1);
    virtual ~QDataStreamWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QDATASTREAMWRAPPER_H

