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

#ifndef SBK_QABSTRACTFILEENGINEHANDLERWRAPPER_H
#define SBK_QABSTRACTFILEENGINEHANDLERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qabstractfileengine.h>

class QAbstractFileEngineHandlerWrapper : public QAbstractFileEngineHandler
{
public:
    QAbstractFileEngineHandlerWrapper();
    virtual QAbstractFileEngine * create(const QString & fileName) const;
    virtual ~QAbstractFileEngineHandlerWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QABSTRACTFILEENGINEHANDLERWRAPPER_H

