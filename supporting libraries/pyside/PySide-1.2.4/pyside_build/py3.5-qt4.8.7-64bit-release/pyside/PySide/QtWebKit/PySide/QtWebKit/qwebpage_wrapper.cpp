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


//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtwebkit_python.h"

#include "qwebpage_wrapper.h"
#include "qwebpage_extensionreturn_wrapper.h"
#include "qwebpage_choosemultiplefilesextensionreturn_wrapper.h"
#include "qwebpage_extensionoption_wrapper.h"
#include "qwebpage_choosemultiplefilesextensionoption_wrapper.h"
#include "qwebpage_errorpageextensionreturn_wrapper.h"
#include "qwebpage_errorpageextensionoption_wrapper.h"

// Extra includes
#include <QList>
#include <qaction.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qevent.h>
#include <qmenu.h>
#include <qmetaobject.h>
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>
#include <qthread.h>
#include <qundostack.h>
#include <qurl.h>
#include <qwebframe.h>
#include <qwebhistory.h>
#include <qwebpage.h>
#include <qwebpluginfactory.h>
#include <qwebsecurityorigin.h>
#include <qwebsettings.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QWebPageWrapper::QWebPageWrapper(QObject * parent) : QWebPage(parent) {
    // ... middle
}

bool QWebPageWrapper::acceptNavigationRequest(QWebFrame * frame, const QNetworkRequest & request, QWebPage::NavigationType type)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "acceptNavigationRequest"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::acceptNavigationRequest(frame, request, type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], frame),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], &request),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.acceptNavigationRequest", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QWebPageWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QString QWebPageWrapper::chooseFile(QWebFrame * originatingFrame, const QString & oldFile)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "chooseFile"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::chooseFile(originatingFrame, oldFile);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], originatingFrame),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &oldFile)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.chooseFile", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QWebPageWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QObject * QWebPageWrapper::createPlugin(const QString & classid, const QUrl & url, const QStringList & paramNames, const QStringList & paramValues)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createPlugin"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::createPlugin(classid, url, paramNames, paramValues);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &classid),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &url),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &paramNames),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &paramValues)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.createPlugin", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QWebPage * QWebPageWrapper::createWindow(QWebPage::WebWindowType type)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWebPage*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createWindow"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::createWindow(type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWebPage*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.createWindow", Shiboken::SbkType< QWebPage >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWebPage*)0);
    }
    ::QWebPage* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QWebPageWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QWebPageWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QWebPageWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QWebPageWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QWebPageWrapper::extension(QWebPage::Extension extension, const QWebPage::ExtensionOption * option, QWebPage::ExtensionReturn * output)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "extension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::extension(extension, option, output);
    }

    // Begin code injection

    // TEMPLATE - qwebpage_extension_argument_conversion - START
    PyObject* option_out = 0;
    // Cast the parameters according to the extension type
    if (extension == QWebPage::ChooseMultipleFilesExtension) {
    const ChooseMultipleFilesExtensionOption* _in = reinterpret_cast<const ChooseMultipleFilesExtensionOption*>(option);
    option_out = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONOPTION_IDX], _in);
    #if QT_VERSION >= 0x040600
    } else if (extension == QWebPage::ErrorPageExtension) {
    const ErrorPageExtensionOption* _in = reinterpret_cast<const ErrorPageExtensionOption*>(option);
    option_out = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONOPTION_IDX], _in);
    #endif
    }
    // TEMPLATE - qwebpage_extension_argument_conversion - END


    // TEMPLATE - qwebpage_extension_argument_conversion - START
    PyObject* output_out = 0;
    // Cast the parameters according to the extension type
    if (extension == QWebPage::ChooseMultipleFilesExtension) {
    const ChooseMultipleFilesExtensionReturn* _in = reinterpret_cast<const ChooseMultipleFilesExtensionReturn*>(output);
    output_out = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_CHOOSEMULTIPLEFILESEXTENSIONRETURN_IDX], _in);
    #if QT_VERSION >= 0x040600
    } else if (extension == QWebPage::ErrorPageExtension) {
    const ErrorPageExtensionReturn* _in = reinterpret_cast<const ErrorPageExtensionReturn*>(output);
    output_out = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORPAGEEXTENSIONRETURN_IDX], _in);
    #endif
    }
    // TEMPLATE - qwebpage_extension_argument_conversion - END

    // End of code injection
    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX]), &extension),
        option_out,
        output_out
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.extension", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
    return cppResult;
}

void QWebPageWrapper::javaScriptAlert(QWebFrame * originatingFrame, const QString & msg)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "javaScriptAlert"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::javaScriptAlert(originatingFrame, msg);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], originatingFrame),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &msg)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QWebPageWrapper::javaScriptConfirm(QWebFrame * originatingFrame, const QString & msg)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "javaScriptConfirm"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::javaScriptConfirm(originatingFrame, msg);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], originatingFrame),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &msg)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.javaScriptConfirm", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QWebPageWrapper::javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "javaScriptConsoleMessage"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::javaScriptConsoleMessage(message, lineNumber, sourceID);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &message),
        lineNumber,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &sourceID)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QWebPageWrapper::javaScriptPrompt(QWebFrame * originatingFrame, const QString & msg, const QString & defaultValue, QString * result)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "javaScriptPrompt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::javaScriptPrompt(originatingFrame, msg, defaultValue, result);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], originatingFrame),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &msg),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &defaultValue)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
        // Check return type
    bool typeIsValid = PySequence_Check(pyResult);
    if (!typeIsValid) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.javaScriptPrompt", "PySequence", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    // Begin code injection

    Shiboken::AutoDecRef pyRes(PySequence_GetItem(pyResult, 0));
    Shiboken::AutoDecRef pyStr(PySequence_GetItem(pyResult, 1));
    bool cppResult;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyRes, &(cppResult));
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyStr, (result));

    // End of code injection
    return cppResult;
}

bool QWebPageWrapper::supportsExtension(QWebPage::Extension extension) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportsExtension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::supportsExtension(extension);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX]), &extension)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.supportsExtension", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QWebPageWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QWebPageWrapper::triggerAction(QWebPage::WebAction action, bool checked)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "triggerAction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::triggerAction(action, checked);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX]), &action),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &checked)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QString QWebPageWrapper::userAgentForUrl(const QUrl & url) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "userAgentForUrl"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWebPage::userAgentForUrl(url);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &url)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QWebPage.userAgentForUrl", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QWebPageWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QWebPage::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QWebPageWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    // Begin code injection

    static int _signalIndex = -1;
    static QMetaMethod _m;

    if (_signalIndex == -1) {
        _signalIndex = QWebPage::staticMetaObject.indexOfSlot("shouldInterruptJavaScript()");
        _m = QWebPage::staticMetaObject.method(_signalIndex);
    }

    if (_signalIndex == id) {
        Shiboken::GilState gil;
        PyObject* self = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (self) {
            Shiboken::AutoDecRef _pyMethod(PyObject_GetAttrString(self, "shouldInterruptJavaScript"));
            return PySide::SignalManager::callPythonMetaMethod(_m, args, _pyMethod, false);
        }
    }

    // End of code injection
    int result = QWebPage::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QWebPageWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QWebPageWrapper* >(this));
        return QWebPage::qt_metacast(_clname);
}

QWebPageWrapper::~QWebPageWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPage_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPage >()))
        return -1;

    ::QWebPageWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QWebPage", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWebPage(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QWebPage(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QWebPage(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPage_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QWebPage_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QWebPage(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QWebPageWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QWebPageWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPage >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPage_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QWebPage_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage", overloads);
        return -1;
}

static PyObject* Sbk_QWebPageFunc_acceptNavigationRequest(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "acceptNavigationRequest", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: acceptNavigationRequest(QWebFrame*,QNetworkRequest,QWebPage::NavigationType)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX]), (pyArgs[2])))) {
        overloadId = 0; // acceptNavigationRequest(QWebFrame*,QNetworkRequest,QWebPage::NavigationType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_acceptNavigationRequest_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QNetworkRequest cppArg1_local = ::QNetworkRequest(::QUrl());
        ::QNetworkRequest* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        ::QWebPage::NavigationType cppArg2 = ((::QWebPage::NavigationType)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // acceptNavigationRequest(QWebFrame*,QNetworkRequest,QWebPage::NavigationType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::acceptNavigationRequest(cppArg0, *cppArg1, cppArg2) : cppSelf->acceptNavigationRequest(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_acceptNavigationRequest_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, PySide.QtNetwork.QNetworkRequest, PySide.QtWebKit.QWebPage.NavigationType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.acceptNavigationRequest", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_action(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: action(QWebPage::WebAction)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX]), (pyArg)))) {
        overloadId = 0; // action(QWebPage::WebAction)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_action_TypeError;

    // Call function/method
    {
        ::QWebPage::WebAction cppArg0 = ((::QWebPage::WebAction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // action(QWebPage::WebAction)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction * cppResult = const_cast<const ::QWebPage*>(cppSelf)->action(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_action_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.WebAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.action", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_bytesReceived(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesReceived()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint64 cppResult = const_cast<const ::QWebPage*>(cppSelf)->bytesReceived();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_chooseFile(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "chooseFile", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: chooseFile(QWebFrame*,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // chooseFile(QWebFrame*,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_chooseFile_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // chooseFile(QWebFrame*,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::chooseFile(cppArg0, cppArg1) : cppSelf->chooseFile(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_chooseFile_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.chooseFile", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_createPlugin(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPlugin", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: createPlugin(QString,QUrl,QStringList,QStringList)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[3])))) {
        overloadId = 0; // createPlugin(QString,QUrl,QStringList,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_createPlugin_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        ::QStringList cppArg2 = ::QStringList();
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QStringList cppArg3 = ::QStringList();
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // createPlugin(QString,QUrl,QStringList,QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::createPlugin(cppArg0, *cppArg1, cppArg2, cppArg3) : cppSelf->createPlugin(cppArg0, *cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_createPlugin_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QUrl, QStringList, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.createPlugin", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_createStandardContextMenu(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createStandardContextMenu()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = cppSelf->createStandardContextMenu();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_createWindow(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createWindow(QWebPage::WebWindowType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // createWindow(QWebPage::WebWindowType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_createWindow_TypeError;

    // Call function/method
    {
        ::QWebPage::WebWindowType cppArg0 = ((::QWebPage::WebWindowType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createWindow(QWebPage::WebWindowType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebPage * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::createWindow(cppArg0) : cppSelf->createWindow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_createWindow_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.WebWindowType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.createWindow", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_currentFrame(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebPage*>(cppSelf)->currentFrame();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.event", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_extension(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.extension(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.extension(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:extension", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: extension(QWebPage::Extension,const QWebPage::ExtensionOption*,QWebPage::ExtensionReturn*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // extension(QWebPage::Extension,const QWebPage::ExtensionOption*,QWebPage::ExtensionReturn*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // extension(QWebPage::Extension,const QWebPage::ExtensionOption*,QWebPage::ExtensionReturn*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONRETURN_IDX], (pyArgs[2])))) {
                overloadId = 0; // extension(QWebPage::Extension,const QWebPage::ExtensionOption*,QWebPage::ExtensionReturn*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_extension_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.extension(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QWebPageFunc_extension_TypeError;
            }
            value = PyDict_GetItemString(kwds, "output");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.extension(): got multiple values for keyword argument 'output'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSIONRETURN_IDX], (pyArgs[2]))))
                    goto Sbk_QWebPageFunc_extension_TypeError;
            }
        }
        ::QWebPage::Extension cppArg0 = ((::QWebPage::Extension)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWebPage::ExtensionOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWebPage::ExtensionReturn* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // extension(QWebPage::Extension,const QWebPage::ExtensionOption*,QWebPage::ExtensionReturn*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::extension(cppArg0, cppArg1, cppArg2) : cppSelf->extension(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_extension_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.Extension, PySide.QtWebKit.QWebPage::ExtensionOption = None, PySide.QtWebKit.QWebPage::ExtensionReturn = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.extension", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_findText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.findText(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.findText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:findText", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: findText(QString,QFlags<QWebPage::FindFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // findText(QString,QFlags<QWebPage::FindFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // findText(QString,QFlags<QWebPage::FindFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_findText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.findText(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QWebPageFunc_findText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QWebPage::FindFlag> cppArg1 = QFlags<QWebPage::FindFlag>(0);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // findText(QString,QFlags<QWebPage::FindFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->findText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_findText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtWebKit.QWebPage.FindFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.findText", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusNextPrevChild(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // focusNextPrevChild(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_forwardUnsupportedContent(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // forwardUnsupportedContent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebPage*>(cppSelf)->forwardUnsupportedContent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_frameAt(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: frameAt(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // frameAt(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_frameAt_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // frameAt(QPoint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebPage*>(cppSelf)->frameAt(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_frameAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.frameAt", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_hasSelection(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebPage*>(cppSelf)->hasSelection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_history(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // history()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebHistory * cppResult = const_cast<const ::QWebPage*>(cppSelf)->history();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHISTORY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodQuery(Qt::InputMethodQuery)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), (pyArg)))) {
        overloadId = 0; // inputMethodQuery(Qt::InputMethodQuery)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QWebPage*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_isContentEditable(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isContentEditable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebPage*>(cppSelf)->isContentEditable();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_isModified(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isModified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebPage*>(cppSelf)->isModified();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_javaScriptAlert(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "javaScriptAlert", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: javaScriptAlert(QWebFrame*,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // javaScriptAlert(QWebFrame*,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_javaScriptAlert_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // javaScriptAlert(QWebFrame*,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::javaScriptAlert(cppArg0, cppArg1) : cppSelf->javaScriptAlert(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_javaScriptAlert_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.javaScriptAlert", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_javaScriptConfirm(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "javaScriptConfirm", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: javaScriptConfirm(QWebFrame*,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // javaScriptConfirm(QWebFrame*,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_javaScriptConfirm_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // javaScriptConfirm(QWebFrame*,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::javaScriptConfirm(cppArg0, cppArg1) : cppSelf->javaScriptConfirm(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_javaScriptConfirm_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.javaScriptConfirm", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_javaScriptConsoleMessage(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "javaScriptConsoleMessage", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: javaScriptConsoleMessage(QString,int,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // javaScriptConsoleMessage(QString,int,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_javaScriptConsoleMessage_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // javaScriptConsoleMessage(QString,int,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::javaScriptConsoleMessage(cppArg0, cppArg1, cppArg2) : cppSelf->javaScriptConsoleMessage(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_javaScriptConsoleMessage_TypeError:
        const char* overloads[] = {"unicode, int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.javaScriptConsoleMessage", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_javaScriptPrompt(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "javaScriptPrompt", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: javaScriptPrompt(QWebFrame*,QString,QString,QString*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // javaScriptPrompt(QWebFrame*,QString,QString,QString*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_javaScriptPrompt_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // javaScriptPrompt(QWebFrame*,QString,QString,QString*)
            // Begin code injection

            QString _local;
            QString* result_out = &_local;

            // End of code injection
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::javaScriptPrompt(cppArg0, cppArg1, cppArg2, result_out) : cppSelf->javaScriptPrompt(cppArg0, cppArg1, cppArg2, result_out);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // Begin code injection

            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &*result_out));

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_javaScriptPrompt_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, unicode, unicode, PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.javaScriptPrompt", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_linkDelegationPolicy(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkDelegationPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebPage::LinkDelegationPolicy cppResult = const_cast<const ::QWebPage*>(cppSelf)->linkDelegationPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_mainFrame(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mainFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebPage*>(cppSelf)->mainFrame();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_networkAccessManager(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // networkAccessManager()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkAccessManager * cppResult = const_cast<const ::QWebPage*>(cppSelf)->networkAccessManager();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], cppResult);
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setNetworkAccessManager(QNetworkAccessManager*)1", pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_palette(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // palette()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPalette cppResult = const_cast<const ::QWebPage*>(cppSelf)->palette();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_pluginFactory(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pluginFactory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebPluginFactory * cppResult = const_cast<const ::QWebPage*>(cppSelf)->pluginFactory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_preferredContentsSize(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredContentsSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QWebPage*>(cppSelf)->preferredContentsSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_selectedHtml(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedHtml()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebPage*>(cppSelf)->selectedHtml();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_selectedText(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebPage*>(cppSelf)->selectedText();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_setActualVisibleContentRect(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActualVisibleContentRect(QRect)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setActualVisibleContentRect(QRect)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setActualVisibleContentRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRect cppArg0_local = ::QRect();
        ::QRect* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setActualVisibleContentRect(QRect)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QWebPage*>(cppSelf)->setActualVisibleContentRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setActualVisibleContentRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setActualVisibleContentRect", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setContentEditable(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContentEditable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setContentEditable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setContentEditable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContentEditable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContentEditable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setContentEditable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setContentEditable", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setFeaturePermission(PyObject* self, PyObject* args)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFeaturePermission", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setFeaturePermission(QWebFrame*,QWebPage::Feature,QWebPage::PermissionPolicy)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX]), (pyArgs[2])))) {
        overloadId = 0; // setFeaturePermission(QWebFrame*,QWebPage::Feature,QWebPage::PermissionPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setFeaturePermission_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWebFrame* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QWebPage::Feature cppArg1 = ((::QWebPage::Feature)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QWebPage::PermissionPolicy cppArg2 = ((::QWebPage::PermissionPolicy)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setFeaturePermission(QWebFrame*,QWebPage::Feature,QWebPage::PermissionPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFeaturePermission(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setFeaturePermission_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebFrame, PySide.QtWebKit.QWebPage.Feature, PySide.QtWebKit.QWebPage.PermissionPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.setFeaturePermission", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setForwardUnsupportedContent(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForwardUnsupportedContent(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setForwardUnsupportedContent(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setForwardUnsupportedContent_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setForwardUnsupportedContent(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForwardUnsupportedContent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setForwardUnsupportedContent_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setForwardUnsupportedContent", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setLinkDelegationPolicy(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLinkDelegationPolicy(QWebPage::LinkDelegationPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setLinkDelegationPolicy(QWebPage::LinkDelegationPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setLinkDelegationPolicy_TypeError;

    // Call function/method
    {
        ::QWebPage::LinkDelegationPolicy cppArg0 = ((::QWebPage::LinkDelegationPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLinkDelegationPolicy(QWebPage::LinkDelegationPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLinkDelegationPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setLinkDelegationPolicy_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.LinkDelegationPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setLinkDelegationPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setNetworkAccessManager(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNetworkAccessManager(QNetworkAccessManager*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (pyArg)))) {
        overloadId = 0; // setNetworkAccessManager(QNetworkAccessManager*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setNetworkAccessManager_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkAccessManager* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNetworkAccessManager(QNetworkAccessManager*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNetworkAccessManager(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setNetworkAccessManager(QNetworkAccessManager*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setNetworkAccessManager_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkAccessManager", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setNetworkAccessManager", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setPalette(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPalette(QPalette)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
        overloadId = 0; // setPalette(QPalette)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setPalette_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPalette cppArg0_local = ::QPalette();
        ::QPalette* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPalette(QPalette)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPalette(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setPalette_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setPalette", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setPluginFactory(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPluginFactory(QWebPluginFactory*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_IDX], (pyArg)))) {
        overloadId = 0; // setPluginFactory(QWebPluginFactory*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setPluginFactory_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWebPluginFactory* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPluginFactory(QWebPluginFactory*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPluginFactory(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setPluginFactory_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPluginFactory", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setPluginFactory", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setPreferredContentsSize(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPreferredContentsSize(QSize)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setPreferredContentsSize(QSize)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setPreferredContentsSize_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPreferredContentsSize(QSize)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QWebPage*>(cppSelf)->setPreferredContentsSize(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setPreferredContentsSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setPreferredContentsSize", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setView(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setView(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setView(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setView_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setView(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setView(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setView_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setView", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_setViewportSize(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setViewportSize(QSize)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setViewportSize(QSize)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_setViewportSize_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setViewportSize(QSize)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QWebPage*>(cppSelf)->setViewportSize(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_setViewportSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.setViewportSize", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_settings(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // settings()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebSettings * cppResult = const_cast<const ::QWebPage*>(cppSelf)->settings();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSETTINGS_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_shouldInterruptJavaScript(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shouldInterruptJavaScript()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->shouldInterruptJavaScript();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_supportedContentTypes(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedContentTypes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QWebPage*>(cppSelf)->supportedContentTypes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_supportsContentType(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsContentType(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // supportsContentType(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_supportsContentType_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsContentType(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebPage*>(cppSelf)->supportsContentType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_supportsContentType_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.supportsContentType", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_supportsExtension(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsExtension(QWebPage::Extension)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsExtension(QWebPage::Extension)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_supportsExtension_TypeError;

    // Call function/method
    {
        ::QWebPage::Extension cppArg0 = ((::QWebPage::Extension)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsExtension(QWebPage::Extension)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QWebPage*>(cppSelf)->::QWebPage::supportsExtension(cppArg0) : const_cast<const ::QWebPage*>(cppSelf)->supportsExtension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_supportsExtension_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.Extension", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.supportsExtension", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_swallowContextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swallowContextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // swallowContextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_swallowContextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // swallowContextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->swallowContextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_swallowContextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.swallowContextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_totalBytes(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // totalBytes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint64 cppResult = const_cast<const ::QWebPage*>(cppSelf)->totalBytes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_triggerAction(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.triggerAction(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.triggerAction(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:triggerAction", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: triggerAction(QWebPage::WebAction,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // triggerAction(QWebPage::WebAction,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // triggerAction(QWebPage::WebAction,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_triggerAction_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "checked");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebPage.triggerAction(): got multiple values for keyword argument 'checked'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QWebPageFunc_triggerAction_TypeError;
            }
        }
        ::QWebPage::WebAction cppArg0 = ((::QWebPage::WebAction)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // triggerAction(QWebPage::WebAction,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebPage::triggerAction(cppArg0, cppArg1) : cppSelf->triggerAction(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_triggerAction_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebPage.WebAction, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebPage.triggerAction", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_undoStack(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // undoStack()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUndoStack * cppResult = const_cast<const ::QWebPage*>(cppSelf)->undoStack();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QUNDOSTACK_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_updatePositionDependentActions(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updatePositionDependentActions(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // updatePositionDependentActions(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_updatePositionDependentActions_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // updatePositionDependentActions(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updatePositionDependentActions(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebPageFunc_updatePositionDependentActions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.updatePositionDependentActions", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_userAgentForUrl(PyObject* self, PyObject* pyArg)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: userAgentForUrl(QUrl)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // userAgentForUrl(QUrl)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPageFunc_userAgentForUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // userAgentForUrl(QUrl)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QWebPage*>(cppSelf)->::QWebPage::userAgentForUrl(*cppArg0) : const_cast<const ::QWebPage*>(cppSelf)->userAgentForUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebPageFunc_userAgentForUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebPage.userAgentForUrl", overloads);
        return 0;
}

static PyObject* Sbk_QWebPageFunc_view(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // view()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QWebPage*>(cppSelf)->view();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebPageFunc_viewportSize(PyObject* self)
{
    ::QWebPage* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPage*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewportSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QWebPage*>(cppSelf)->viewportSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPage_methods[] = {
    {"acceptNavigationRequest", (PyCFunction)Sbk_QWebPageFunc_acceptNavigationRequest, METH_VARARGS},
    {"action", (PyCFunction)Sbk_QWebPageFunc_action, METH_O},
    {"bytesReceived", (PyCFunction)Sbk_QWebPageFunc_bytesReceived, METH_NOARGS},
    {"chooseFile", (PyCFunction)Sbk_QWebPageFunc_chooseFile, METH_VARARGS},
    {"createPlugin", (PyCFunction)Sbk_QWebPageFunc_createPlugin, METH_VARARGS},
    {"createStandardContextMenu", (PyCFunction)Sbk_QWebPageFunc_createStandardContextMenu, METH_NOARGS},
    {"createWindow", (PyCFunction)Sbk_QWebPageFunc_createWindow, METH_O},
    {"currentFrame", (PyCFunction)Sbk_QWebPageFunc_currentFrame, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QWebPageFunc_event, METH_O},
    {"extension", (PyCFunction)Sbk_QWebPageFunc_extension, METH_VARARGS|METH_KEYWORDS},
    {"findText", (PyCFunction)Sbk_QWebPageFunc_findText, METH_VARARGS|METH_KEYWORDS},
    {"focusNextPrevChild", (PyCFunction)Sbk_QWebPageFunc_focusNextPrevChild, METH_O},
    {"forwardUnsupportedContent", (PyCFunction)Sbk_QWebPageFunc_forwardUnsupportedContent, METH_NOARGS},
    {"frameAt", (PyCFunction)Sbk_QWebPageFunc_frameAt, METH_O},
    {"hasSelection", (PyCFunction)Sbk_QWebPageFunc_hasSelection, METH_NOARGS},
    {"history", (PyCFunction)Sbk_QWebPageFunc_history, METH_NOARGS},
    {"inputMethodQuery", (PyCFunction)Sbk_QWebPageFunc_inputMethodQuery, METH_O},
    {"isContentEditable", (PyCFunction)Sbk_QWebPageFunc_isContentEditable, METH_NOARGS},
    {"isModified", (PyCFunction)Sbk_QWebPageFunc_isModified, METH_NOARGS},
    {"javaScriptAlert", (PyCFunction)Sbk_QWebPageFunc_javaScriptAlert, METH_VARARGS},
    {"javaScriptConfirm", (PyCFunction)Sbk_QWebPageFunc_javaScriptConfirm, METH_VARARGS},
    {"javaScriptConsoleMessage", (PyCFunction)Sbk_QWebPageFunc_javaScriptConsoleMessage, METH_VARARGS},
    {"javaScriptPrompt", (PyCFunction)Sbk_QWebPageFunc_javaScriptPrompt, METH_VARARGS},
    {"linkDelegationPolicy", (PyCFunction)Sbk_QWebPageFunc_linkDelegationPolicy, METH_NOARGS},
    {"mainFrame", (PyCFunction)Sbk_QWebPageFunc_mainFrame, METH_NOARGS},
    {"networkAccessManager", (PyCFunction)Sbk_QWebPageFunc_networkAccessManager, METH_NOARGS},
    {"palette", (PyCFunction)Sbk_QWebPageFunc_palette, METH_NOARGS},
    {"pluginFactory", (PyCFunction)Sbk_QWebPageFunc_pluginFactory, METH_NOARGS},
    {"preferredContentsSize", (PyCFunction)Sbk_QWebPageFunc_preferredContentsSize, METH_NOARGS},
    {"selectedHtml", (PyCFunction)Sbk_QWebPageFunc_selectedHtml, METH_NOARGS},
    {"selectedText", (PyCFunction)Sbk_QWebPageFunc_selectedText, METH_NOARGS},
    {"setActualVisibleContentRect", (PyCFunction)Sbk_QWebPageFunc_setActualVisibleContentRect, METH_O},
    {"setContentEditable", (PyCFunction)Sbk_QWebPageFunc_setContentEditable, METH_O},
    {"setFeaturePermission", (PyCFunction)Sbk_QWebPageFunc_setFeaturePermission, METH_VARARGS},
    {"setForwardUnsupportedContent", (PyCFunction)Sbk_QWebPageFunc_setForwardUnsupportedContent, METH_O},
    {"setLinkDelegationPolicy", (PyCFunction)Sbk_QWebPageFunc_setLinkDelegationPolicy, METH_O},
    {"setNetworkAccessManager", (PyCFunction)Sbk_QWebPageFunc_setNetworkAccessManager, METH_O},
    {"setPalette", (PyCFunction)Sbk_QWebPageFunc_setPalette, METH_O},
    {"setPluginFactory", (PyCFunction)Sbk_QWebPageFunc_setPluginFactory, METH_O},
    {"setPreferredContentsSize", (PyCFunction)Sbk_QWebPageFunc_setPreferredContentsSize, METH_O},
    {"setView", (PyCFunction)Sbk_QWebPageFunc_setView, METH_O},
    {"setViewportSize", (PyCFunction)Sbk_QWebPageFunc_setViewportSize, METH_O},
    {"settings", (PyCFunction)Sbk_QWebPageFunc_settings, METH_NOARGS},
    {"shouldInterruptJavaScript", (PyCFunction)Sbk_QWebPageFunc_shouldInterruptJavaScript, METH_NOARGS},
    {"supportedContentTypes", (PyCFunction)Sbk_QWebPageFunc_supportedContentTypes, METH_NOARGS},
    {"supportsContentType", (PyCFunction)Sbk_QWebPageFunc_supportsContentType, METH_O},
    {"supportsExtension", (PyCFunction)Sbk_QWebPageFunc_supportsExtension, METH_O},
    {"swallowContextMenuEvent", (PyCFunction)Sbk_QWebPageFunc_swallowContextMenuEvent, METH_O},
    {"totalBytes", (PyCFunction)Sbk_QWebPageFunc_totalBytes, METH_NOARGS},
    {"triggerAction", (PyCFunction)Sbk_QWebPageFunc_triggerAction, METH_VARARGS|METH_KEYWORDS},
    {"undoStack", (PyCFunction)Sbk_QWebPageFunc_undoStack, METH_NOARGS},
    {"updatePositionDependentActions", (PyCFunction)Sbk_QWebPageFunc_updatePositionDependentActions, METH_O},
    {"userAgentForUrl", (PyCFunction)Sbk_QWebPageFunc_userAgentForUrl, METH_O},
    {"view", (PyCFunction)Sbk_QWebPageFunc_view, METH_NOARGS},
    {"viewportSize", (PyCFunction)Sbk_QWebPageFunc_viewportSize, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebPage_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPage_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPage_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPage",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QWebPage_traverse,
    /*tp_clear*/            Sbk_QWebPage_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPage_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPage_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern

static void* Sbk_QWebPage_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QWebPage*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtWebKit_QWebPage_FindFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QWebPage::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QWebPage::FindFlags)PyLong_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QWebPage::FindFlags)PyInt_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtWebKit_QWebPage_FindFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QWebPage::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QWebPage::FindFlags)PyLong_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QWebPage::FindFlags)PyInt_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtWebKit_QWebPage_FindFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QWebPage::FindFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QWebPage::FindFlags)PyLong_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QWebPage::FindFlags)PyInt_AsLong(self);
    cppArg = (QWebPage::FindFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtWebKit_QWebPage_FindFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QWebPage::FindFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), self, &cppSelf);
    ::QWebPage::FindFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtWebKit_QWebPage_FindFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtWebKit_QWebPage_FindFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtWebKit_QWebPage_FindFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtWebKit_QWebPage_FindFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtWebKit_QWebPage_FindFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtWebKit_QWebPage_FindFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtWebKit_QWebPage_FindFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtWebKit_QWebPage_FindFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtWebKit_QWebPage_FindFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtWebKit_QWebPage_FindFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QWebPage_NavigationType_PythonToCpp_QWebPage_NavigationType(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::NavigationType*)cppOut) = (::QWebPage::NavigationType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_NavigationType_PythonToCpp_QWebPage_NavigationType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX]))
        return QWebPage_NavigationType_PythonToCpp_QWebPage_NavigationType;
    return 0;
}
static PyObject* QWebPage_NavigationType_CppToPython_QWebPage_NavigationType(const void* cppIn) {
    int castCppIn = *((::QWebPage::NavigationType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX], castCppIn);

}

static void QWebPage_WebAction_PythonToCpp_QWebPage_WebAction(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::WebAction*)cppOut) = (::QWebPage::WebAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_WebAction_PythonToCpp_QWebPage_WebAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX]))
        return QWebPage_WebAction_PythonToCpp_QWebPage_WebAction;
    return 0;
}
static PyObject* QWebPage_WebAction_CppToPython_QWebPage_WebAction(const void* cppIn) {
    int castCppIn = *((::QWebPage::WebAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX], castCppIn);

}

static void QWebPage_FindFlag_PythonToCpp_QWebPage_FindFlag(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::FindFlag*)cppOut) = (::QWebPage::FindFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_FindFlag_PythonToCpp_QWebPage_FindFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX]))
        return QWebPage_FindFlag_PythonToCpp_QWebPage_FindFlag;
    return 0;
}
static PyObject* QWebPage_FindFlag_CppToPython_QWebPage_FindFlag(const void* cppIn) {
    int castCppIn = *((::QWebPage::FindFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX], castCppIn);

}

static void QFlags_QWebPage_FindFlag__PythonToCpp_QFlags_QWebPage_FindFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QWebPage::FindFlag>*)cppOut) = ::QFlags<QWebPage::FindFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QWebPage_FindFlag__PythonToCpp_QFlags_QWebPage_FindFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]))
        return QFlags_QWebPage_FindFlag__PythonToCpp_QFlags_QWebPage_FindFlag_;
    return 0;
}
static PyObject* QFlags_QWebPage_FindFlag__CppToPython_QFlags_QWebPage_FindFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QWebPage::FindFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]));

}

static void QWebPage_FindFlag_PythonToCpp_QFlags_QWebPage_FindFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QWebPage::FindFlag>*)cppOut) = ::QFlags<QWebPage::FindFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QWebPage_FindFlag_PythonToCpp_QFlags_QWebPage_FindFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX]))
        return QWebPage_FindFlag_PythonToCpp_QFlags_QWebPage_FindFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QWebPage_FindFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QWebPage::FindFlag>*)cppOut) = ::QFlags<QWebPage::FindFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QWebPage_FindFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QWebPage_FindFlag_;
    return 0;
}
static void QWebPage_LinkDelegationPolicy_PythonToCpp_QWebPage_LinkDelegationPolicy(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::LinkDelegationPolicy*)cppOut) = (::QWebPage::LinkDelegationPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_LinkDelegationPolicy_PythonToCpp_QWebPage_LinkDelegationPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX]))
        return QWebPage_LinkDelegationPolicy_PythonToCpp_QWebPage_LinkDelegationPolicy;
    return 0;
}
static PyObject* QWebPage_LinkDelegationPolicy_CppToPython_QWebPage_LinkDelegationPolicy(const void* cppIn) {
    int castCppIn = *((::QWebPage::LinkDelegationPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX], castCppIn);

}

static void QWebPage_WebWindowType_PythonToCpp_QWebPage_WebWindowType(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::WebWindowType*)cppOut) = (::QWebPage::WebWindowType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_WebWindowType_PythonToCpp_QWebPage_WebWindowType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX]))
        return QWebPage_WebWindowType_PythonToCpp_QWebPage_WebWindowType;
    return 0;
}
static PyObject* QWebPage_WebWindowType_CppToPython_QWebPage_WebWindowType(const void* cppIn) {
    int castCppIn = *((::QWebPage::WebWindowType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX], castCppIn);

}

static void QWebPage_PermissionPolicy_PythonToCpp_QWebPage_PermissionPolicy(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::PermissionPolicy*)cppOut) = (::QWebPage::PermissionPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_PermissionPolicy_PythonToCpp_QWebPage_PermissionPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX]))
        return QWebPage_PermissionPolicy_PythonToCpp_QWebPage_PermissionPolicy;
    return 0;
}
static PyObject* QWebPage_PermissionPolicy_CppToPython_QWebPage_PermissionPolicy(const void* cppIn) {
    int castCppIn = *((::QWebPage::PermissionPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX], castCppIn);

}

static void QWebPage_Feature_PythonToCpp_QWebPage_Feature(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::Feature*)cppOut) = (::QWebPage::Feature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_Feature_PythonToCpp_QWebPage_Feature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX]))
        return QWebPage_Feature_PythonToCpp_QWebPage_Feature;
    return 0;
}
static PyObject* QWebPage_Feature_CppToPython_QWebPage_Feature(const void* cppIn) {
    int castCppIn = *((::QWebPage::Feature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX], castCppIn);

}

static void QWebPage_Extension_PythonToCpp_QWebPage_Extension(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::Extension*)cppOut) = (::QWebPage::Extension) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_Extension_PythonToCpp_QWebPage_Extension_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX]))
        return QWebPage_Extension_PythonToCpp_QWebPage_Extension;
    return 0;
}
static PyObject* QWebPage_Extension_CppToPython_QWebPage_Extension(const void* cppIn) {
    int castCppIn = *((::QWebPage::Extension*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX], castCppIn);

}

static void QWebPage_ErrorDomain_PythonToCpp_QWebPage_ErrorDomain(PyObject* pyIn, void* cppOut) {
    *((::QWebPage::ErrorDomain*)cppOut) = (::QWebPage::ErrorDomain) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebPage_ErrorDomain_PythonToCpp_QWebPage_ErrorDomain_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX]))
        return QWebPage_ErrorDomain_PythonToCpp_QWebPage_ErrorDomain;
    return 0;
}
static PyObject* QWebPage_ErrorDomain_CppToPython_QWebPage_ErrorDomain(const void* cppIn) {
    int castCppIn = *((::QWebPage::ErrorDomain*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWebPage_PythonToCpp_QWebPage_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPage_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebPage_PythonToCpp_QWebPage_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPage_Type))
        return QWebPage_PythonToCpp_QWebPage_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebPage_PTR_CppToPython_QWebPage(const void* cppIn) {
    return PySide::getWrapperForQObject((::QWebPage*)cppIn, &Sbk_QWebPage_Type);

}

void init_QWebPage(PyObject* module)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPage_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebPage", "QWebPage*",
        &Sbk_QWebPage_Type, &Shiboken::callCppDestructor< ::QWebPage >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPage_Type,
        QWebPage_PythonToCpp_QWebPage_PTR,
        is_QWebPage_PythonToCpp_QWebPage_PTR_Convertible,
        QWebPage_PTR_CppToPython_QWebPage);

    Shiboken::Conversions::registerConverterName(converter, "QWebPage");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPage&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPage).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPageWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QWebPage_Type, &Sbk_QWebPage_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'NavigationType'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "NavigationType",
        "PySide.QtWebKit.QWebPage.NavigationType",
        "QWebPage::NavigationType");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeLinkClicked", (long) QWebPage::NavigationTypeLinkClicked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeFormSubmitted", (long) QWebPage::NavigationTypeFormSubmitted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeBackOrForward", (long) QWebPage::NavigationTypeBackOrForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeReload", (long) QWebPage::NavigationTypeReload))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeFormResubmitted", (long) QWebPage::NavigationTypeFormResubmitted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
        &Sbk_QWebPage_Type, "NavigationTypeOther", (long) QWebPage::NavigationTypeOther))
        return ;
    // Register converter for enum 'QWebPage::NavigationType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX],
            QWebPage_NavigationType_CppToPython_QWebPage_NavigationType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_NavigationType_PythonToCpp_QWebPage_NavigationType,
            is_QWebPage_NavigationType_PythonToCpp_QWebPage_NavigationType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_NAVIGATIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::NavigationType");
        Shiboken::Conversions::registerConverterName(converter, "NavigationType");
    }
    // End of 'NavigationType' enum.

    // Initialization of enum 'WebAction'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "WebAction",
        "PySide.QtWebKit.QWebPage.WebAction",
        "QWebPage::WebAction");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "NoWebAction", (long) QWebPage::NoWebAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "OpenLink", (long) QWebPage::OpenLink))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "OpenLinkInNewWindow", (long) QWebPage::OpenLinkInNewWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "OpenFrameInNewWindow", (long) QWebPage::OpenFrameInNewWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "DownloadLinkToDisk", (long) QWebPage::DownloadLinkToDisk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "CopyLinkToClipboard", (long) QWebPage::CopyLinkToClipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "OpenImageInNewWindow", (long) QWebPage::OpenImageInNewWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "DownloadImageToDisk", (long) QWebPage::DownloadImageToDisk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "CopyImageToClipboard", (long) QWebPage::CopyImageToClipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Back", (long) QWebPage::Back))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Forward", (long) QWebPage::Forward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Stop", (long) QWebPage::Stop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Reload", (long) QWebPage::Reload))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Cut", (long) QWebPage::Cut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Copy", (long) QWebPage::Copy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Paste", (long) QWebPage::Paste))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Undo", (long) QWebPage::Undo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Redo", (long) QWebPage::Redo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToNextChar", (long) QWebPage::MoveToNextChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToPreviousChar", (long) QWebPage::MoveToPreviousChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToNextWord", (long) QWebPage::MoveToNextWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToPreviousWord", (long) QWebPage::MoveToPreviousWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToNextLine", (long) QWebPage::MoveToNextLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToPreviousLine", (long) QWebPage::MoveToPreviousLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToStartOfLine", (long) QWebPage::MoveToStartOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToEndOfLine", (long) QWebPage::MoveToEndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToStartOfBlock", (long) QWebPage::MoveToStartOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToEndOfBlock", (long) QWebPage::MoveToEndOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToStartOfDocument", (long) QWebPage::MoveToStartOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "MoveToEndOfDocument", (long) QWebPage::MoveToEndOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectNextChar", (long) QWebPage::SelectNextChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectPreviousChar", (long) QWebPage::SelectPreviousChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectNextWord", (long) QWebPage::SelectNextWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectPreviousWord", (long) QWebPage::SelectPreviousWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectNextLine", (long) QWebPage::SelectNextLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectPreviousLine", (long) QWebPage::SelectPreviousLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectStartOfLine", (long) QWebPage::SelectStartOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectEndOfLine", (long) QWebPage::SelectEndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectStartOfBlock", (long) QWebPage::SelectStartOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectEndOfBlock", (long) QWebPage::SelectEndOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectStartOfDocument", (long) QWebPage::SelectStartOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectEndOfDocument", (long) QWebPage::SelectEndOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "DeleteStartOfWord", (long) QWebPage::DeleteStartOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "DeleteEndOfWord", (long) QWebPage::DeleteEndOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SetTextDirectionDefault", (long) QWebPage::SetTextDirectionDefault))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SetTextDirectionLeftToRight", (long) QWebPage::SetTextDirectionLeftToRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SetTextDirectionRightToLeft", (long) QWebPage::SetTextDirectionRightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleBold", (long) QWebPage::ToggleBold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleItalic", (long) QWebPage::ToggleItalic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleUnderline", (long) QWebPage::ToggleUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "InspectElement", (long) QWebPage::InspectElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "InsertParagraphSeparator", (long) QWebPage::InsertParagraphSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "InsertLineSeparator", (long) QWebPage::InsertLineSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "SelectAll", (long) QWebPage::SelectAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ReloadAndBypassCache", (long) QWebPage::ReloadAndBypassCache))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "PasteAndMatchStyle", (long) QWebPage::PasteAndMatchStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "RemoveFormat", (long) QWebPage::RemoveFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleStrikethrough", (long) QWebPage::ToggleStrikethrough))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleSubscript", (long) QWebPage::ToggleSubscript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "ToggleSuperscript", (long) QWebPage::ToggleSuperscript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "InsertUnorderedList", (long) QWebPage::InsertUnorderedList))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "InsertOrderedList", (long) QWebPage::InsertOrderedList))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Indent", (long) QWebPage::Indent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "Outdent", (long) QWebPage::Outdent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "AlignCenter", (long) QWebPage::AlignCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "AlignJustified", (long) QWebPage::AlignJustified))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "AlignLeft", (long) QWebPage::AlignLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "AlignRight", (long) QWebPage::AlignRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "StopScheduledPageRefresh", (long) QWebPage::StopScheduledPageRefresh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "CopyImageUrlToClipboard", (long) QWebPage::CopyImageUrlToClipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "OpenLinkInThisWindow", (long) QWebPage::OpenLinkInThisWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
        &Sbk_QWebPage_Type, "WebActionCount", (long) QWebPage::WebActionCount))
        return ;
    // Register converter for enum 'QWebPage::WebAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX],
            QWebPage_WebAction_CppToPython_QWebPage_WebAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_WebAction_PythonToCpp_QWebPage_WebAction,
            is_QWebPage_WebAction_PythonToCpp_QWebPage_WebAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::WebAction");
        Shiboken::Conversions::registerConverterName(converter, "WebAction");
    }
    // End of 'WebAction' enum.

    // Initialization of enum 'FindFlag'.
    SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX] = PySide::QFlags::create("FindFlags", &SbkPySide_QtWebKit_QWebPage_FindFlag_as_number);
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "FindFlag",
        "PySide.QtWebKit.QWebPage.FindFlag",
        "QWebPage::FindFlag",
        SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX]);
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX],
        &Sbk_QWebPage_Type, "FindBackward", (long) QWebPage::FindBackward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX],
        &Sbk_QWebPage_Type, "FindCaseSensitively", (long) QWebPage::FindCaseSensitively))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX],
        &Sbk_QWebPage_Type, "FindWrapsAroundDocument", (long) QWebPage::FindWrapsAroundDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX],
        &Sbk_QWebPage_Type, "HighlightAllOccurrences", (long) QWebPage::HighlightAllOccurrences))
        return ;
    // Register converter for enum 'QWebPage::FindFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX],
            QWebPage_FindFlag_CppToPython_QWebPage_FindFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_FindFlag_PythonToCpp_QWebPage_FindFlag,
            is_QWebPage_FindFlag_PythonToCpp_QWebPage_FindFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FINDFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::FindFlag");
        Shiboken::Conversions::registerConverterName(converter, "FindFlag");
    }
    // Register converter for flag 'QFlags<QWebPage::FindFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX],
            QFlags_QWebPage_FindFlag__CppToPython_QFlags_QWebPage_FindFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_FindFlag_PythonToCpp_QFlags_QWebPage_FindFlag_,
            is_QWebPage_FindFlag_PythonToCpp_QFlags_QWebPage_FindFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QWebPage_FindFlag__PythonToCpp_QFlags_QWebPage_FindFlag_,
            is_QFlags_QWebPage_FindFlag__PythonToCpp_QFlags_QWebPage_FindFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QWebPage_FindFlag_,
            is_number_PythonToCpp_QFlags_QWebPage_FindFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QFLAGS_QWEBPAGE_FINDFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QWebPage::FindFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FindFlag>");
    }
    // End of 'FindFlag' enum/flags.

    // Initialization of enum 'LinkDelegationPolicy'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "LinkDelegationPolicy",
        "PySide.QtWebKit.QWebPage.LinkDelegationPolicy",
        "QWebPage::LinkDelegationPolicy");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "DontDelegateLinks", (long) QWebPage::DontDelegateLinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "DelegateExternalLinks", (long) QWebPage::DelegateExternalLinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "DelegateAllLinks", (long) QWebPage::DelegateAllLinks))
        return ;
    // Register converter for enum 'QWebPage::LinkDelegationPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX],
            QWebPage_LinkDelegationPolicy_CppToPython_QWebPage_LinkDelegationPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_LinkDelegationPolicy_PythonToCpp_QWebPage_LinkDelegationPolicy,
            is_QWebPage_LinkDelegationPolicy_PythonToCpp_QWebPage_LinkDelegationPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_LINKDELEGATIONPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::LinkDelegationPolicy");
        Shiboken::Conversions::registerConverterName(converter, "LinkDelegationPolicy");
    }
    // End of 'LinkDelegationPolicy' enum.

    // Initialization of enum 'WebWindowType'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "WebWindowType",
        "PySide.QtWebKit.QWebPage.WebWindowType",
        "QWebPage::WebWindowType");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX],
        &Sbk_QWebPage_Type, "WebBrowserWindow", (long) QWebPage::WebBrowserWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX],
        &Sbk_QWebPage_Type, "WebModalDialog", (long) QWebPage::WebModalDialog))
        return ;
    // Register converter for enum 'QWebPage::WebWindowType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX],
            QWebPage_WebWindowType_CppToPython_QWebPage_WebWindowType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_WebWindowType_PythonToCpp_QWebPage_WebWindowType,
            is_QWebPage_WebWindowType_PythonToCpp_QWebPage_WebWindowType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_WEBWINDOWTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::WebWindowType");
        Shiboken::Conversions::registerConverterName(converter, "WebWindowType");
    }
    // End of 'WebWindowType' enum.

    // Initialization of enum 'PermissionPolicy'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "PermissionPolicy",
        "PySide.QtWebKit.QWebPage.PermissionPolicy",
        "QWebPage::PermissionPolicy");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "PermissionUnknown", (long) QWebPage::PermissionUnknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "PermissionGrantedByUser", (long) QWebPage::PermissionGrantedByUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX],
        &Sbk_QWebPage_Type, "PermissionDeniedByUser", (long) QWebPage::PermissionDeniedByUser))
        return ;
    // Register converter for enum 'QWebPage::PermissionPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX],
            QWebPage_PermissionPolicy_CppToPython_QWebPage_PermissionPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_PermissionPolicy_PythonToCpp_QWebPage_PermissionPolicy,
            is_QWebPage_PermissionPolicy_PythonToCpp_QWebPage_PermissionPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_PERMISSIONPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::PermissionPolicy");
        Shiboken::Conversions::registerConverterName(converter, "PermissionPolicy");
    }
    // End of 'PermissionPolicy' enum.

    // Initialization of enum 'Feature'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "Feature",
        "PySide.QtWebKit.QWebPage.Feature",
        "QWebPage::Feature");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX],
        &Sbk_QWebPage_Type, "Notifications", (long) QWebPage::Notifications))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX],
        &Sbk_QWebPage_Type, "Geolocation", (long) QWebPage::Geolocation))
        return ;
    // Register converter for enum 'QWebPage::Feature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX],
            QWebPage_Feature_CppToPython_QWebPage_Feature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_Feature_PythonToCpp_QWebPage_Feature,
            is_QWebPage_Feature_PythonToCpp_QWebPage_Feature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_FEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::Feature");
        Shiboken::Conversions::registerConverterName(converter, "Feature");
    }
    // End of 'Feature' enum.

    // Initialization of enum 'Extension'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "Extension",
        "PySide.QtWebKit.QWebPage.Extension",
        "QWebPage::Extension");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX],
        &Sbk_QWebPage_Type, "ChooseMultipleFilesExtension", (long) QWebPage::ChooseMultipleFilesExtension))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX],
        &Sbk_QWebPage_Type, "ErrorPageExtension", (long) QWebPage::ErrorPageExtension))
        return ;
    // Register converter for enum 'QWebPage::Extension'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX],
            QWebPage_Extension_CppToPython_QWebPage_Extension);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_Extension_PythonToCpp_QWebPage_Extension,
            is_QWebPage_Extension_PythonToCpp_QWebPage_Extension_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_EXTENSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::Extension");
        Shiboken::Conversions::registerConverterName(converter, "Extension");
    }
    // End of 'Extension' enum.

    // Initialization of enum 'ErrorDomain'.
    SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebPage_Type,
        "ErrorDomain",
        "PySide.QtWebKit.QWebPage.ErrorDomain",
        "QWebPage::ErrorDomain");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX],
        &Sbk_QWebPage_Type, "QtNetwork", (long) QWebPage::QtNetwork))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX],
        &Sbk_QWebPage_Type, "Http", (long) QWebPage::Http))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX],
        &Sbk_QWebPage_Type, "WebKit", (long) QWebPage::WebKit))
        return ;
    // Register converter for enum 'QWebPage::ErrorDomain'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX],
            QWebPage_ErrorDomain_CppToPython_QWebPage_ErrorDomain);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebPage_ErrorDomain_PythonToCpp_QWebPage_ErrorDomain,
            is_QWebPage_ErrorDomain_PythonToCpp_QWebPage_ErrorDomain_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBPAGE_ERRORDOMAIN_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebPage::ErrorDomain");
        Shiboken::Conversions::registerConverterName(converter, "ErrorDomain");
    }
    // End of 'ErrorDomain' enum.

    PySide::Signal::registerSignals(&Sbk_QWebPage_Type, &::QWebPage::staticMetaObject);

    qRegisterMetaType< ::QWebPage::NavigationType >("QWebPage::NavigationType");
    qRegisterMetaType< ::QWebPage::WebAction >("QWebPage::WebAction");
    qRegisterMetaType< ::QWebPage::FindFlag >("QWebPage::FindFlag");
    qRegisterMetaType< ::QWebPage::FindFlags >("QWebPage::FindFlags");
    qRegisterMetaType< ::QWebPage::LinkDelegationPolicy >("QWebPage::LinkDelegationPolicy");
    qRegisterMetaType< ::QWebPage::WebWindowType >("QWebPage::WebWindowType");
    qRegisterMetaType< ::QWebPage::PermissionPolicy >("QWebPage::PermissionPolicy");
    qRegisterMetaType< ::QWebPage::Feature >("QWebPage::Feature");
    qRegisterMetaType< ::QWebPage::Extension >("QWebPage::Extension");
    qRegisterMetaType< ::QWebPage::ErrorDomain >("QWebPage::ErrorDomain");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QWebPage_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QWebPage_Type, &::QWebPage::staticMetaObject, sizeof(::QWebPage));
}
