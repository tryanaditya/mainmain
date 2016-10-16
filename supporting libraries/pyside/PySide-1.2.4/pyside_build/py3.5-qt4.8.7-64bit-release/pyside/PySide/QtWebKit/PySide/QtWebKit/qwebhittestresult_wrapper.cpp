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
#include "pyside_qtwebkit_python.h"

#include "qwebhittestresult_wrapper.h"

// Extra includes
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qurl.h>
#include <qwebelement.h>
#include <qwebframe.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebHitTestResult_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebHitTestResult >()))
        return -1;

    ::QWebHitTestResult* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWebHitTestResult", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWebHitTestResult()
    // 1: QWebHitTestResult(QWebHitTestResult)
    if (numArgs == 0) {
        overloadId = 0; // QWebHitTestResult()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QWebHitTestResult(QWebHitTestResult)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebHitTestResult_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QWebHitTestResult()
        {

            if (!PyErr_Occurred()) {
                // QWebHitTestResult()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebHitTestResult();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QWebHitTestResult(const QWebHitTestResult & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebHitTestResult cppArg0_local = ::QWebHitTestResult();
            ::QWebHitTestResult* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QWebHitTestResult(QWebHitTestResult)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebHitTestResult(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebHitTestResult >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebHitTestResult_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebHitTestResult_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebHitTestResult", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebHitTestResult", overloads);
        return -1;
}

static PyObject* Sbk_QWebHitTestResultFunc_alternateText(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alternateText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->alternateText();
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

static PyObject* Sbk_QWebHitTestResultFunc_boundingRect(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->boundingRect();
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

static PyObject* Sbk_QWebHitTestResultFunc_element(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // element()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->element();
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

static PyObject* Sbk_QWebHitTestResultFunc_enclosingBlockElement(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enclosingBlockElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->enclosingBlockElement();
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

static PyObject* Sbk_QWebHitTestResultFunc_frame(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->frame();
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

static PyObject* Sbk_QWebHitTestResultFunc_imageUrl(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // imageUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->imageUrl();
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

static PyObject* Sbk_QWebHitTestResultFunc_isContentEditable(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isContentEditable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->isContentEditable();
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

static PyObject* Sbk_QWebHitTestResultFunc_isContentSelected(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isContentSelected()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->isContentSelected();
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

static PyObject* Sbk_QWebHitTestResultFunc_isNull(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->isNull();
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

static PyObject* Sbk_QWebHitTestResultFunc_linkElement(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->linkElement();
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

static PyObject* Sbk_QWebHitTestResultFunc_linkTargetFrame(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkTargetFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebFrame * cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->linkTargetFrame();
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

static PyObject* Sbk_QWebHitTestResultFunc_linkText(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->linkText();
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

static PyObject* Sbk_QWebHitTestResultFunc_linkTitle(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkTitle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->linkTitle();
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

static PyObject* Sbk_QWebHitTestResultFunc_linkUrl(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkUrl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->linkUrl();
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

static PyObject* Sbk_QWebHitTestResultFunc_pixmap(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->pixmap();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebHitTestResultFunc_pos(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->pos();
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

static PyObject* Sbk_QWebHitTestResultFunc_title(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // title()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebHitTestResult*>(cppSelf)->title();
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

static PyObject* Sbk_QWebHitTestResult___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebHitTestResult& cppSelf = *(((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebHitTestResult_methods[] = {
    {"alternateText", (PyCFunction)Sbk_QWebHitTestResultFunc_alternateText, METH_NOARGS},
    {"boundingRect", (PyCFunction)Sbk_QWebHitTestResultFunc_boundingRect, METH_NOARGS},
    {"element", (PyCFunction)Sbk_QWebHitTestResultFunc_element, METH_NOARGS},
    {"enclosingBlockElement", (PyCFunction)Sbk_QWebHitTestResultFunc_enclosingBlockElement, METH_NOARGS},
    {"frame", (PyCFunction)Sbk_QWebHitTestResultFunc_frame, METH_NOARGS},
    {"imageUrl", (PyCFunction)Sbk_QWebHitTestResultFunc_imageUrl, METH_NOARGS},
    {"isContentEditable", (PyCFunction)Sbk_QWebHitTestResultFunc_isContentEditable, METH_NOARGS},
    {"isContentSelected", (PyCFunction)Sbk_QWebHitTestResultFunc_isContentSelected, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QWebHitTestResultFunc_isNull, METH_NOARGS},
    {"linkElement", (PyCFunction)Sbk_QWebHitTestResultFunc_linkElement, METH_NOARGS},
    {"linkTargetFrame", (PyCFunction)Sbk_QWebHitTestResultFunc_linkTargetFrame, METH_NOARGS},
    {"linkText", (PyCFunction)Sbk_QWebHitTestResultFunc_linkText, METH_NOARGS},
    {"linkTitle", (PyCFunction)Sbk_QWebHitTestResultFunc_linkTitle, METH_NOARGS},
    {"linkUrl", (PyCFunction)Sbk_QWebHitTestResultFunc_linkUrl, METH_NOARGS},
    {"pixmap", (PyCFunction)Sbk_QWebHitTestResultFunc_pixmap, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QWebHitTestResultFunc_pos, METH_NOARGS},
    {"title", (PyCFunction)Sbk_QWebHitTestResultFunc_title, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QWebHitTestResult___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QWebHitTestResult___nb_bool(PyObject* self)
{
    ::QWebHitTestResult* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QWebHitTestResult_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebHitTestResult_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QWebHitTestResult_TypeAsNumber;

static SbkObjectType Sbk_QWebHitTestResult_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebHitTestResult",
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
    /*tp_traverse*/         Sbk_QWebHitTestResult_traverse,
    /*tp_clear*/            Sbk_QWebHitTestResult_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebHitTestResult_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebHitTestResult_Init,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWebHitTestResult_PythonToCpp_QWebHitTestResult_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebHitTestResult_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebHitTestResult_PythonToCpp_QWebHitTestResult_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebHitTestResult_Type))
        return QWebHitTestResult_PythonToCpp_QWebHitTestResult_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebHitTestResult_PTR_CppToPython_QWebHitTestResult(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebHitTestResult*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebHitTestResult_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QWebHitTestResult_COPY_CppToPython_QWebHitTestResult(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebHitTestResult_Type, new ::QWebHitTestResult(*((::QWebHitTestResult*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QWebHitTestResult_PythonToCpp_QWebHitTestResult_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebHitTestResult*)cppOut) = *((::QWebHitTestResult*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QWebHitTestResult_PythonToCpp_QWebHitTestResult_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebHitTestResult_Type))
        return QWebHitTestResult_PythonToCpp_QWebHitTestResult_COPY;
    return 0;
}

void init_QWebHitTestResult(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QWebHitTestResult_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QWebHitTestResult_TypeAsNumber) = Sbk_QWebHitTestResult___nb_bool;
    Sbk_QWebHitTestResult_Type.super.ht_type.tp_as_number = &Sbk_QWebHitTestResult_TypeAsNumber;

    SbkPySide_QtWebKitTypes[SBK_QWEBHITTESTRESULT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebHitTestResult_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebHitTestResult", "QWebHitTestResult",
        &Sbk_QWebHitTestResult_Type, &Shiboken::callCppDestructor< ::QWebHitTestResult >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebHitTestResult_Type,
        QWebHitTestResult_PythonToCpp_QWebHitTestResult_PTR,
        is_QWebHitTestResult_PythonToCpp_QWebHitTestResult_PTR_Convertible,
        QWebHitTestResult_PTR_CppToPython_QWebHitTestResult,
        QWebHitTestResult_COPY_CppToPython_QWebHitTestResult);

    Shiboken::Conversions::registerConverterName(converter, "QWebHitTestResult");
    Shiboken::Conversions::registerConverterName(converter, "QWebHitTestResult*");
    Shiboken::Conversions::registerConverterName(converter, "QWebHitTestResult&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebHitTestResult).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QWebHitTestResult_PythonToCpp_QWebHitTestResult_COPY,
        is_QWebHitTestResult_PythonToCpp_QWebHitTestResult_COPY_Convertible);


    qRegisterMetaType< ::QWebHitTestResult >("QWebHitTestResult");
}
