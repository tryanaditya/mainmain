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

#ifndef SBK_QWEBPAGEWRAPPER_H
#define SBK_QWEBPAGEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <qwebpage.h>

namespace PySide { class DynamicQMetaObject; }

class QWebPageWrapper : public QWebPage
{
public:
    QWebPageWrapper(QObject * parent = 0);
    virtual bool acceptNavigationRequest(QWebFrame * frame, const QNetworkRequest & request, QWebPage::NavigationType type);
    virtual void childEvent(QChildEvent * arg__1);
    virtual QString chooseFile(QWebFrame * originatingFrame, const QString & oldFile);
    virtual void connectNotify(const char * signal);
    virtual QObject * createPlugin(const QString & classid, const QUrl & url, const QStringList & paramNames, const QStringList & paramValues);
    virtual QWebPage * createWindow(QWebPage::WebWindowType type);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual bool extension(QWebPage::Extension extension, const QWebPage::ExtensionOption * option = 0, QWebPage::ExtensionReturn * output = 0);
    virtual void javaScriptAlert(QWebFrame * originatingFrame, const QString & msg);
    virtual bool javaScriptConfirm(QWebFrame * originatingFrame, const QString & msg);
    virtual void javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID);
    virtual bool javaScriptPrompt(QWebFrame * originatingFrame, const QString & msg, const QString & defaultValue, QString * result);
    virtual const QMetaObject * metaObject() const;
    virtual bool supportsExtension(QWebPage::Extension extension) const;
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void triggerAction(QWebPage::WebAction action, bool checked = false);
    virtual QString userAgentForUrl(const QUrl & url) const;
    virtual ~QWebPageWrapper();
public:
    virtual int qt_metacall(QMetaObject::Call call, int id, void** args);
    virtual void* qt_metacast(const char* _clname);
    static void pysideInitQtMetaTypes();
};

#endif // SBK_QWEBPAGEWRAPPER_H

