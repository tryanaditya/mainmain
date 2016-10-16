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

#ifndef SBK_QSCRIPTENGINEAGENTWRAPPER_H
#define SBK_QSCRIPTENGINEAGENTWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qscriptengineagent.h>

class QScriptEngineAgentWrapper : public QScriptEngineAgent
{
public:
    QScriptEngineAgentWrapper(QScriptEngine * engine);
    virtual void contextPop();
    virtual void contextPush();
    virtual void exceptionCatch(qint64 scriptId, const QScriptValue & exception);
    virtual void exceptionThrow(qint64 scriptId, const QScriptValue & exception, bool hasHandler);
    virtual QVariant extension(QScriptEngineAgent::Extension extension, const QVariant & argument = QVariant());
    virtual void functionEntry(qint64 scriptId);
    virtual void functionExit(qint64 scriptId, const QScriptValue & returnValue);
    virtual void positionChange(qint64 scriptId, int lineNumber, int columnNumber);
    virtual void scriptLoad(qint64 id, const QString & program, const QString & fileName, int baseLineNumber);
    virtual void scriptUnload(qint64 id);
    virtual bool supportsExtension(QScriptEngineAgent::Extension extension) const;
    virtual ~QScriptEngineAgentWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QSCRIPTENGINEAGENTWRAPPER_H

