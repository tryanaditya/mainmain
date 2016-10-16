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

#include "qwebframe_wrapper.h"

// Extra includes
#include <QList>
#include <QMultiMap>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qicon.h>
#include <qmetaobject.h>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qpoint.h>
#include <qprinter.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qthread.h>
#include <qurl.h>
#include <qwebelement.h>
#include <qwebframe.h>
#include <qwebpage.h>
#include <qwebsecurityorigin.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QWebFrameFunc_addToJavaScriptWindowObject(PyObject* self, PyObject* args)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addToJavaScriptWindowObject", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addToJavaScriptWindowObject(QString,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // addToJavaScriptWindowObject(QString,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_addToJavaScriptWindowObject_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addToJavaScriptWindowObject(QString,QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addToJavaScriptWindowObject(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_addToJavaScriptWindowObject_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.addToJavaScriptWindowObject", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_baseUrl(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // baseUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebFrame*>(cppSelf)->baseUrl();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_childFrames(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childFrames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWebFrame * > cppResult = const_cast<const ::QWebFrame*>(cppSelf)->childFrames();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBFRAMEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_contentsSize(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contentsSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QWebFrame*>(cppSelf)->contentsSize();
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

static PyObject* Sbk_QWebFrameFunc_documentElement(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebFrame*>(cppSelf)->documentElement();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_evaluateJavaScript(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: evaluateJavaScript(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // evaluateJavaScript(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_evaluateJavaScript_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // evaluateJavaScript(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = cppSelf->evaluateJavaScript(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_evaluateJavaScript_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.evaluateJavaScript", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QWebFrameFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QWebFrame::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.event", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_findAllElements(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findAllElements(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // findAllElements(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_findAllElements_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findAllElements(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElementCollection cppResult = const_cast<const ::QWebFrame*>(cppSelf)->findAllElements(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_findAllElements_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.findAllElements", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_findFirstElement(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: findFirstElement(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // findFirstElement(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_findFirstElement_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // findFirstElement(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebFrame*>(cppSelf)->findFirstElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_findFirstElement_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.findFirstElement", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_frameName(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frameName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebFrame*>(cppSelf)->frameName();
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

static PyObject* Sbk_QWebFrameFunc_geometry(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometry()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QWebFrame*>(cppSelf)->geometry();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_hasFocus(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebFrame*>(cppSelf)->hasFocus();
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

static PyObject* Sbk_QWebFrameFunc_hitTestContent(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hitTestContent(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // hitTestContent(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_hitTestContent_TypeError;

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
            // hitTestContent(QPoint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebHitTestResult cppResult = const_cast<const ::QWebFrame*>(cppSelf)->hitTestContent(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_hitTestContent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.hitTestContent", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_icon(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QWebFrame*>(cppSelf)->icon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_load(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.load(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.load(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:load", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: load(QNetworkRequest,QNetworkAccessManager::Operation,QByteArray)
    // 1: load(QUrl)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 1; // load(QUrl)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // load(QNetworkRequest,QNetworkAccessManager::Operation,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // load(QNetworkRequest,QNetworkAccessManager::Operation,QByteArray)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2])))) {
                overloadId = 0; // load(QNetworkRequest,QNetworkAccessManager::Operation,QByteArray)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_load_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // load(const QNetworkRequest & request, QNetworkAccessManager::Operation operation, const QByteArray & body)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "operation");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.load(): got multiple values for keyword argument 'operation'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), (pyArgs[1]))))
                        goto Sbk_QWebFrameFunc_load_TypeError;
                }
                value = PyDict_GetItemString(kwds, "body");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.load(): got multiple values for keyword argument 'body'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2]))))
                        goto Sbk_QWebFrameFunc_load_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QNetworkAccessManager::Operation cppArg1 = QNetworkAccessManager::GetOperation;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QByteArray cppArg2_local = QByteArray();
            ::QByteArray* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // load(QNetworkRequest,QNetworkAccessManager::Operation,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->load(*cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // load(const QUrl & url)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // load(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->load(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_load_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest, PySide.QtNetwork.QNetworkAccessManager.Operation = QNetworkAccessManager.GetOperation, PySide.QtCore.QByteArray = QByteArray()", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.load", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_metaData(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // metaData()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMultiMap<QString, QString > cppResult = const_cast<const ::QWebFrame*>(cppSelf)->metaData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Begin code injection

            // TEMPLATE - convertFromMultiMap - START
            pyResult = PyDict_New();
            foreach(QString _key, cppResult.keys()) {
            Shiboken::AutoDecRef _pyValueList(PyList_New(0));
            foreach(QString _value, cppResult.values(_key)) {
                Shiboken::AutoDecRef _pyValue(Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_value));
                PyList_Append(_pyValueList, _pyValue);
            }

            Shiboken::AutoDecRef _pyKey(Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_key));
            PyDict_SetItem(pyResult, _pyKey, _pyValueList);
            }
            // TEMPLATE - convertFromMultiMap - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_page(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // page()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebPage * cppResult = const_cast<const ::QWebFrame*>(cppSelf)->page();
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
}

static PyObject* Sbk_QWebFrameFunc_parentFrame(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebFrame*>(cppSelf)->parentFrame();
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

static PyObject* Sbk_QWebFrameFunc_pos(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QWebFrame*>(cppSelf)->pos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_print_(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: print(QPrinter*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (pyArg)))) {
        overloadId = 0; // print(QPrinter*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_print__TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPrinter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // print(QPrinter*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QWebFrame*>(cppSelf)->print(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_print__TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.print_", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_render(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.render(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.render(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:render", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: render(QPainter*)
    // 1: render(QPainter*,QWebFrame::RenderLayer,QRegion)
    // 2: render(QPainter*,QRegion)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // render(QPainter*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[1])))) {
            overloadId = 2; // render(QPainter*,QRegion)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // render(QPainter*,QWebFrame::RenderLayer,QRegion)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[2])))) {
                overloadId = 1; // render(QPainter*,QWebFrame::RenderLayer,QRegion)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_render_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // render(QPainter * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // render(QPainter*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->render(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // render(QPainter * arg__1, QWebFrame::RenderLayer layer, const QRegion & clip)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "clip");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.render(): got multiple values for keyword argument 'clip'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[2]))))
                        goto Sbk_QWebFrameFunc_render_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QWebFrame::RenderLayer cppArg1 = ((::QWebFrame::RenderLayer)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRegion cppArg2_local = QRegion();
            ::QRegion* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // render(QPainter*,QWebFrame::RenderLayer,QRegion)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->render(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // render(QPainter * arg__1, const QRegion & clip)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRegion cppArg1_local = ::QRegion();
            ::QRegion* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // render(QPainter*,QRegion)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->render(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_render_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", "PySide.QtGui.QPainter, PySide.QtWebKit.QWebFrame.RenderLayer, PySide.QtGui.QRegion = QRegion()", "PySide.QtGui.QPainter, PySide.QtGui.QRegion", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.render", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_renderTreeDump(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // renderTreeDump()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebFrame*>(cppSelf)->renderTreeDump();
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

static PyObject* Sbk_QWebFrameFunc_requestedUrl(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // requestedUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebFrame*>(cppSelf)->requestedUrl();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_scroll(PyObject* self, PyObject* args)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scroll", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scroll(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // scroll(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scroll_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scroll(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scroll(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_scroll_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.scroll", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollBarGeometry(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollBarGeometry(Qt::Orientation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // scrollBarGeometry(Qt::Orientation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollBarGeometry_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollBarGeometry(Qt::Orientation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollBarGeometry(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_scrollBarGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollBarGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollBarMaximum(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollBarMaximum(Qt::Orientation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // scrollBarMaximum(Qt::Orientation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollBarMaximum_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollBarMaximum(Qt::Orientation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollBarMaximum(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_scrollBarMaximum_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollBarMaximum", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollBarMinimum(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollBarMinimum(Qt::Orientation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // scrollBarMinimum(Qt::Orientation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollBarMinimum_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollBarMinimum(Qt::Orientation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollBarMinimum(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_scrollBarMinimum_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollBarMinimum", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollBarPolicy(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollBarPolicy(Qt::Orientation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // scrollBarPolicy(Qt::Orientation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollBarPolicy_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollBarPolicy(Qt::Orientation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ScrollBarPolicy cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollBarPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_scrollBarPolicy_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollBarPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollBarValue(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollBarValue(Qt::Orientation)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // scrollBarValue(Qt::Orientation)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollBarValue_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollBarValue(Qt::Orientation)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollBarValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebFrameFunc_scrollBarValue_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollBarValue", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_scrollPosition(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scrollPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QWebFrame*>(cppSelf)->scrollPosition();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_scrollToAnchor(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scrollToAnchor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // scrollToAnchor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_scrollToAnchor_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scrollToAnchor(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scrollToAnchor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_scrollToAnchor_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.scrollToAnchor", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_securityOrigin(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // securityOrigin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebSecurityOrigin cppResult = const_cast<const ::QWebFrame*>(cppSelf)->securityOrigin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_setContent(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setContent(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setContent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setContent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setContent(QByteArray,QString,QUrl)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setContent(QByteArray,QString,QUrl)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setContent(QByteArray,QString,QUrl)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[2])))) {
                overloadId = 0; // setContent(QByteArray,QString,QUrl)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setContent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mimeType");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setContent(): got multiple values for keyword argument 'mimeType'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QWebFrameFunc_setContent_TypeError;
            }
            value = PyDict_GetItemString(kwds, "baseUrl");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setContent(): got multiple values for keyword argument 'baseUrl'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[2]))))
                    goto Sbk_QWebFrameFunc_setContent_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QUrl cppArg2_local = QUrl();
        ::QUrl* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // setContent(QByteArray,QString,QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContent(*cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setContent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, unicode = QString(), PySide.QtCore.QUrl = QUrl()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.setContent", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setFocus(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setFocus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebFrameFunc_setHtml(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setHtml(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setHtml(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setHtml", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setHtml(QString,QUrl)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setHtml(QString,QUrl)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
            overloadId = 0; // setHtml(QString,QUrl)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setHtml_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "baseUrl");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtWebKit.QWebFrame.setHtml(): got multiple values for keyword argument 'baseUrl'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1]))))
                    goto Sbk_QWebFrameFunc_setHtml_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // setHtml(QString,QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHtml(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setHtml_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QUrl = QUrl()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.setHtml", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setScrollBarPolicy(PyObject* self, PyObject* args)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setScrollBarPolicy", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setScrollBarPolicy(Qt::Orientation,Qt::ScrollBarPolicy)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SCROLLBARPOLICY_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setScrollBarPolicy(Qt::Orientation,Qt::ScrollBarPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setScrollBarPolicy_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::ScrollBarPolicy cppArg1 = ((::Qt::ScrollBarPolicy)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setScrollBarPolicy(Qt::Orientation,Qt::ScrollBarPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScrollBarPolicy(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setScrollBarPolicy_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation, PySide.QtCore.Qt.ScrollBarPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.setScrollBarPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setScrollBarValue(PyObject* self, PyObject* args)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setScrollBarValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setScrollBarValue(Qt::Orientation,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setScrollBarValue(Qt::Orientation,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setScrollBarValue_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setScrollBarValue(Qt::Orientation,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScrollBarValue(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setScrollBarValue_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebFrame.setScrollBarValue", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setScrollPosition(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScrollPosition(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setScrollPosition(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setScrollPosition_TypeError;

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
            // setScrollPosition(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScrollPosition(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setScrollPosition_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.setScrollPosition", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setTextSizeMultiplier(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextSizeMultiplier(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTextSizeMultiplier(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setTextSizeMultiplier_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextSizeMultiplier(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextSizeMultiplier(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setTextSizeMultiplier_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.setTextSizeMultiplier", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setUrl(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setUrl_TypeError;

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
            // setUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_setZoomFactor(PyObject* self, PyObject* pyArg)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setZoomFactor(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setZoomFactor(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebFrameFunc_setZoomFactor_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setZoomFactor(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setZoomFactor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebFrameFunc_setZoomFactor_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebFrame.setZoomFactor", overloads);
        return 0;
}

static PyObject* Sbk_QWebFrameFunc_textSizeMultiplier(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textSizeMultiplier()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QWebFrame*>(cppSelf)->textSizeMultiplier();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_title(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // title()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebFrame*>(cppSelf)->title();
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

static PyObject* Sbk_QWebFrameFunc_toHtml(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toHtml()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebFrame*>(cppSelf)->toHtml();
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

static PyObject* Sbk_QWebFrameFunc_toPlainText(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPlainText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebFrame*>(cppSelf)->toPlainText();
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

static PyObject* Sbk_QWebFrameFunc_url(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebFrame*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebFrameFunc_zoomFactor(PyObject* self)
{
    ::QWebFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // zoomFactor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QWebFrame*>(cppSelf)->zoomFactor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebFrame_methods[] = {
    {"addToJavaScriptWindowObject", (PyCFunction)Sbk_QWebFrameFunc_addToJavaScriptWindowObject, METH_VARARGS},
    {"baseUrl", (PyCFunction)Sbk_QWebFrameFunc_baseUrl, METH_NOARGS},
    {"childFrames", (PyCFunction)Sbk_QWebFrameFunc_childFrames, METH_NOARGS},
    {"contentsSize", (PyCFunction)Sbk_QWebFrameFunc_contentsSize, METH_NOARGS},
    {"documentElement", (PyCFunction)Sbk_QWebFrameFunc_documentElement, METH_NOARGS},
    {"evaluateJavaScript", (PyCFunction)Sbk_QWebFrameFunc_evaluateJavaScript, METH_O},
    {"event", (PyCFunction)Sbk_QWebFrameFunc_event, METH_O},
    {"findAllElements", (PyCFunction)Sbk_QWebFrameFunc_findAllElements, METH_O},
    {"findFirstElement", (PyCFunction)Sbk_QWebFrameFunc_findFirstElement, METH_O},
    {"frameName", (PyCFunction)Sbk_QWebFrameFunc_frameName, METH_NOARGS},
    {"geometry", (PyCFunction)Sbk_QWebFrameFunc_geometry, METH_NOARGS},
    {"hasFocus", (PyCFunction)Sbk_QWebFrameFunc_hasFocus, METH_NOARGS},
    {"hitTestContent", (PyCFunction)Sbk_QWebFrameFunc_hitTestContent, METH_O},
    {"icon", (PyCFunction)Sbk_QWebFrameFunc_icon, METH_NOARGS},
    {"load", (PyCFunction)Sbk_QWebFrameFunc_load, METH_VARARGS|METH_KEYWORDS},
    {"metaData", (PyCFunction)Sbk_QWebFrameFunc_metaData, METH_NOARGS},
    {"page", (PyCFunction)Sbk_QWebFrameFunc_page, METH_NOARGS},
    {"parentFrame", (PyCFunction)Sbk_QWebFrameFunc_parentFrame, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QWebFrameFunc_pos, METH_NOARGS},
    {"print_", (PyCFunction)Sbk_QWebFrameFunc_print_, METH_O},
    {"render", (PyCFunction)Sbk_QWebFrameFunc_render, METH_VARARGS|METH_KEYWORDS},
    {"renderTreeDump", (PyCFunction)Sbk_QWebFrameFunc_renderTreeDump, METH_NOARGS},
    {"requestedUrl", (PyCFunction)Sbk_QWebFrameFunc_requestedUrl, METH_NOARGS},
    {"scroll", (PyCFunction)Sbk_QWebFrameFunc_scroll, METH_VARARGS},
    {"scrollBarGeometry", (PyCFunction)Sbk_QWebFrameFunc_scrollBarGeometry, METH_O},
    {"scrollBarMaximum", (PyCFunction)Sbk_QWebFrameFunc_scrollBarMaximum, METH_O},
    {"scrollBarMinimum", (PyCFunction)Sbk_QWebFrameFunc_scrollBarMinimum, METH_O},
    {"scrollBarPolicy", (PyCFunction)Sbk_QWebFrameFunc_scrollBarPolicy, METH_O},
    {"scrollBarValue", (PyCFunction)Sbk_QWebFrameFunc_scrollBarValue, METH_O},
    {"scrollPosition", (PyCFunction)Sbk_QWebFrameFunc_scrollPosition, METH_NOARGS},
    {"scrollToAnchor", (PyCFunction)Sbk_QWebFrameFunc_scrollToAnchor, METH_O},
    {"securityOrigin", (PyCFunction)Sbk_QWebFrameFunc_securityOrigin, METH_NOARGS},
    {"setContent", (PyCFunction)Sbk_QWebFrameFunc_setContent, METH_VARARGS|METH_KEYWORDS},
    {"setFocus", (PyCFunction)Sbk_QWebFrameFunc_setFocus, METH_NOARGS},
    {"setHtml", (PyCFunction)Sbk_QWebFrameFunc_setHtml, METH_VARARGS|METH_KEYWORDS},
    {"setScrollBarPolicy", (PyCFunction)Sbk_QWebFrameFunc_setScrollBarPolicy, METH_VARARGS},
    {"setScrollBarValue", (PyCFunction)Sbk_QWebFrameFunc_setScrollBarValue, METH_VARARGS},
    {"setScrollPosition", (PyCFunction)Sbk_QWebFrameFunc_setScrollPosition, METH_O},
    {"setTextSizeMultiplier", (PyCFunction)Sbk_QWebFrameFunc_setTextSizeMultiplier, METH_O},
    {"setUrl", (PyCFunction)Sbk_QWebFrameFunc_setUrl, METH_O},
    {"setZoomFactor", (PyCFunction)Sbk_QWebFrameFunc_setZoomFactor, METH_O},
    {"textSizeMultiplier", (PyCFunction)Sbk_QWebFrameFunc_textSizeMultiplier, METH_NOARGS},
    {"title", (PyCFunction)Sbk_QWebFrameFunc_title, METH_NOARGS},
    {"toHtml", (PyCFunction)Sbk_QWebFrameFunc_toHtml, METH_NOARGS},
    {"toPlainText", (PyCFunction)Sbk_QWebFrameFunc_toPlainText, METH_NOARGS},
    {"url", (PyCFunction)Sbk_QWebFrameFunc_url, METH_NOARGS},
    {"zoomFactor", (PyCFunction)Sbk_QWebFrameFunc_zoomFactor, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebFrame_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebFrame_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebFrame_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebFrame",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          SbkDeallocWrapperWithPrivateDtor,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QWebFrame_traverse,
    /*tp_clear*/            Sbk_QWebFrame_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebFrame_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

static void* Sbk_QWebFrame_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QWebFrame*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QWebFrame_RenderLayer_PythonToCpp_QWebFrame_RenderLayer(PyObject* pyIn, void* cppOut) {
    *((::QWebFrame::RenderLayer*)cppOut) = (::QWebFrame::RenderLayer) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QWebFrame_RenderLayer_PythonToCpp_QWebFrame_RenderLayer_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX]))
        return QWebFrame_RenderLayer_PythonToCpp_QWebFrame_RenderLayer;
    return 0;
}
static PyObject* QWebFrame_RenderLayer_CppToPython_QWebFrame_RenderLayer(const void* cppIn) {
    int castCppIn = *((::QWebFrame::RenderLayer*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWebFrame_PythonToCpp_QWebFrame_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebFrame_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebFrame_PythonToCpp_QWebFrame_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebFrame_Type))
        return QWebFrame_PythonToCpp_QWebFrame_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebFrame_PTR_CppToPython_QWebFrame(const void* cppIn) {
    return PySide::getWrapperForQObject((::QWebFrame*)cppIn, &Sbk_QWebFrame_Type);

}

void init_QWebFrame(PyObject* module)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebFrame_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebFrame", "QWebFrame*",
        &Sbk_QWebFrame_Type, 0, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebFrame_Type,
        QWebFrame_PythonToCpp_QWebFrame_PTR,
        is_QWebFrame_PythonToCpp_QWebFrame_PTR_Convertible,
        QWebFrame_PTR_CppToPython_QWebFrame);

    Shiboken::Conversions::registerConverterName(converter, "QWebFrame");
    Shiboken::Conversions::registerConverterName(converter, "QWebFrame*");
    Shiboken::Conversions::registerConverterName(converter, "QWebFrame&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebFrame).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QWebFrame_Type, &Sbk_QWebFrame_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'RenderLayer'.
    SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QWebFrame_Type,
        "RenderLayer",
        "PySide.QtWebKit.QWebFrame.RenderLayer",
        "QWebFrame::RenderLayer");
    if (!SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX],
        &Sbk_QWebFrame_Type, "ContentsLayer", (long) QWebFrame::ContentsLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX],
        &Sbk_QWebFrame_Type, "ScrollBarLayer", (long) QWebFrame::ScrollBarLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX],
        &Sbk_QWebFrame_Type, "PanIconLayer", (long) QWebFrame::PanIconLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX],
        &Sbk_QWebFrame_Type, "AllLayers", (long) QWebFrame::AllLayers))
        return ;
    // Register converter for enum 'QWebFrame::RenderLayer'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX],
            QWebFrame_RenderLayer_CppToPython_QWebFrame_RenderLayer);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QWebFrame_RenderLayer_PythonToCpp_QWebFrame_RenderLayer,
            is_QWebFrame_RenderLayer_PythonToCpp_QWebFrame_RenderLayer_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtWebKitTypes[SBK_QWEBFRAME_RENDERLAYER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QWebFrame::RenderLayer");
        Shiboken::Conversions::registerConverterName(converter, "RenderLayer");
    }
    // End of 'RenderLayer' enum.

    PySide::Signal::registerSignals(&Sbk_QWebFrame_Type, &::QWebFrame::staticMetaObject);

    qRegisterMetaType< ::QWebFrame::RenderLayer >("QWebFrame::RenderLayer");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QWebFrame_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QWebFrame_Type, &::QWebFrame::staticMetaObject, sizeof(::QWebFrame));
}
