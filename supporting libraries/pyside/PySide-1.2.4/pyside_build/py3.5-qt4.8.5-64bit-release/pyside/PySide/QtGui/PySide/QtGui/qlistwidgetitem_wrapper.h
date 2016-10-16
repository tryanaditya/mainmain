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

#ifndef SBK_QLISTWIDGETITEMWRAPPER_H
#define SBK_QLISTWIDGETITEMWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qlistwidget.h>

class QListWidgetItemWrapper : public QListWidgetItem
{
public:
    QListWidgetItemWrapper(QListWidget * view = 0, int type = Type);
    QListWidgetItemWrapper(const QIcon & icon, const QString & text, QListWidget * view = 0, int type = Type);
    QListWidgetItemWrapper(const QListWidgetItem& self) : QListWidgetItem(self)
    {
    }

    QListWidgetItemWrapper(const QString & text, QListWidget * view = 0, int type = Type);
    virtual QListWidgetItem * clone() const;
    virtual QVariant data(int role) const;
    virtual bool operator<(const QListWidgetItem & other) const;
    virtual void read(QDataStream & in);
    virtual void setData(int role, const QVariant & value);
    virtual void write(QDataStream & out) const;
    virtual ~QListWidgetItemWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QLISTWIDGETITEMWRAPPER_H

