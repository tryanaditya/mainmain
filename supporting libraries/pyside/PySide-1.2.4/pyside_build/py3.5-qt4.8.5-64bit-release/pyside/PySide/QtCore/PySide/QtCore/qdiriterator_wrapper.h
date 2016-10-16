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

#ifndef SBK_QDIRITERATORWRAPPER_H
#define SBK_QDIRITERATORWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qdiriterator.h>

class QDirIteratorWrapper : public QDirIterator
{
public:
    QDirIteratorWrapper(const QDir & dir, QFlags<QDirIterator::IteratorFlag> flags = QDirIterator::NoIteratorFlags);
    QDirIteratorWrapper(const QString & path, QFlags<QDir::Filter> filter, QFlags<QDirIterator::IteratorFlag> flags = QDirIterator::NoIteratorFlags);
    QDirIteratorWrapper(const QString & path, QFlags<QDirIterator::IteratorFlag> flags = QDirIterator::NoIteratorFlags);
    QDirIteratorWrapper(const QString & path, const QStringList & nameFilters, QFlags<QDir::Filter> filters = QDir::NoFilter, QFlags<QDirIterator::IteratorFlag> flags = QDirIterator::NoIteratorFlags);
    virtual ~QDirIteratorWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QDIRITERATORWRAPPER_H

