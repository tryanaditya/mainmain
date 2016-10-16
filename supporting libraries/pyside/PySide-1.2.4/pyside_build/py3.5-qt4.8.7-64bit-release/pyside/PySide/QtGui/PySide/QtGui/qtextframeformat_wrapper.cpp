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
#include "pyside_qtgui_python.h"

#include "qtextframeformat_wrapper.h"

// Extra includes
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qpen.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextFrameFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextFrameFormat >()))
        return -1;

    ::QTextFrameFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextFrameFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextFrameFormat()
    // 1: QTextFrameFormat(QTextFormat)
    // 2: QTextFrameFormat(QTextFrameFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextFrameFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextFrameFormat(QTextFrameFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextFrameFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextFrameFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextFrameFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFrameFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextFrameFormat(const QTextFormat & fmt)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextFormat cppArg0_local = ::QTextFormat();
            ::QTextFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextFrameFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFrameFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextFrameFormat(const QTextFrameFormat & QTextFrameFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextFrameFormat cppArg0_local = ::QTextFrameFormat();
            ::QTextFrameFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextFrameFormat(QTextFrameFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFrameFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextFrameFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextFrameFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextFrameFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextFormat", "PySide.QtGui.QTextFrameFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextFrameFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextFrameFormatFunc_border(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // border()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->border();
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

static PyObject* Sbk_QTextFrameFormatFunc_borderBrush(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // borderBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->borderBrush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormatFunc_borderStyle(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // borderStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrameFormat::BorderStyle cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->borderStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormatFunc_bottomMargin(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottomMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->bottomMargin();
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

static PyObject* Sbk_QTextFrameFormatFunc_height(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextLength cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->height();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormatFunc_isValid(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextFrameFormatFunc_leftMargin(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leftMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->leftMargin();
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

static PyObject* Sbk_QTextFrameFormatFunc_margin(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // margin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->margin();
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

static PyObject* Sbk_QTextFrameFormatFunc_padding(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // padding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->padding();
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

static PyObject* Sbk_QTextFrameFormatFunc_pageBreakPolicy(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageBreakPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextFormat::PageBreakFlag> cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->pageBreakPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormatFunc_position(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // position()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrameFormat::Position cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->position();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormatFunc_rightMargin(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rightMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->rightMargin();
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

static PyObject* Sbk_QTextFrameFormatFunc_setBorder(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBorder(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBorder(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setBorder_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBorder(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBorder(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setBorder_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setBorder", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setBorderBrush(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBorderBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBorderBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setBorderBrush_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBorderBrush(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBorderBrush(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setBorderBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setBorderBrush", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setBorderStyle(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBorderStyle(QTextFrameFormat::BorderStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setBorderStyle(QTextFrameFormat::BorderStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setBorderStyle_TypeError;

    // Call function/method
    {
        ::QTextFrameFormat::BorderStyle cppArg0 = ((::QTextFrameFormat::BorderStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBorderStyle(QTextFrameFormat::BorderStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBorderStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setBorderStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFrameFormat.BorderStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setBorderStyle", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setBottomMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBottomMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBottomMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setBottomMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBottomMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBottomMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setBottomMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setBottomMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setHeight(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHeight(QTextLength)
    // 1: setHeight(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // setHeight(qreal)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (pyArg)))) {
        overloadId = 0; // setHeight(QTextLength)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setHeight_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setHeight(const QTextLength & height)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextLength cppArg0_local = ::QTextLength();
            ::QTextLength* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setHeight(QTextLength)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setHeight(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setHeight(qreal height)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setHeight(qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setHeight(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setHeight_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextLength", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setHeight", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setLeftMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLeftMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setLeftMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setLeftMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLeftMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLeftMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setLeftMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setLeftMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setPageBreakPolicy(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPageBreakPolicy(QFlags<QTextFormat::PageBreakFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setPageBreakPolicy(QFlags<QTextFormat::PageBreakFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setPageBreakPolicy_TypeError;

    // Call function/method
    {
        ::QFlags<QTextFormat::PageBreakFlag> cppArg0 = ((::QFlags<QTextFormat::PageBreakFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPageBreakPolicy(QFlags<QTextFormat::PageBreakFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPageBreakPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setPageBreakPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFormat.PageBreakFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setPageBreakPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setPosition(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPosition(QTextFrameFormat::Position)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX]), (pyArg)))) {
        overloadId = 0; // setPosition(QTextFrameFormat::Position)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setPosition_TypeError;

    // Call function/method
    {
        ::QTextFrameFormat::Position cppArg0 = ((::QTextFrameFormat::Position)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPosition(QTextFrameFormat::Position)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPosition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setPosition_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFrameFormat.Position", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setPosition", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setRightMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRightMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRightMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setRightMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRightMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRightMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setRightMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setRightMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setTopMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTopMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTopMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setTopMargin_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTopMargin(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTopMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setTopMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setTopMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_setWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidth(QTextLength)
    // 1: setWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // setWidth(qreal)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (pyArg)))) {
        overloadId = 0; // setWidth(QTextLength)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFrameFormatFunc_setWidth_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setWidth(const QTextLength & length)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextLength cppArg0_local = ::QTextLength();
            ::QTextLength* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setWidth(QTextLength)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setWidth(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setWidth(qreal width)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setWidth(qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setWidth(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFrameFormatFunc_setWidth_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextLength", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFrameFormat.setWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextFrameFormatFunc_topMargin(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->topMargin();
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

static PyObject* Sbk_QTextFrameFormatFunc_width(PyObject* self)
{
    ::QTextFrameFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextLength cppResult = const_cast<const ::QTextFrameFormat*>(cppSelf)->width();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFrameFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextFrameFormat& cppSelf = *(((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextFrameFormat_methods[] = {
    {"border", (PyCFunction)Sbk_QTextFrameFormatFunc_border, METH_NOARGS},
    {"borderBrush", (PyCFunction)Sbk_QTextFrameFormatFunc_borderBrush, METH_NOARGS},
    {"borderStyle", (PyCFunction)Sbk_QTextFrameFormatFunc_borderStyle, METH_NOARGS},
    {"bottomMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_bottomMargin, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QTextFrameFormatFunc_height, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextFrameFormatFunc_isValid, METH_NOARGS},
    {"leftMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_leftMargin, METH_NOARGS},
    {"margin", (PyCFunction)Sbk_QTextFrameFormatFunc_margin, METH_NOARGS},
    {"padding", (PyCFunction)Sbk_QTextFrameFormatFunc_padding, METH_NOARGS},
    {"pageBreakPolicy", (PyCFunction)Sbk_QTextFrameFormatFunc_pageBreakPolicy, METH_NOARGS},
    {"position", (PyCFunction)Sbk_QTextFrameFormatFunc_position, METH_NOARGS},
    {"rightMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_rightMargin, METH_NOARGS},
    {"setBorder", (PyCFunction)Sbk_QTextFrameFormatFunc_setBorder, METH_O},
    {"setBorderBrush", (PyCFunction)Sbk_QTextFrameFormatFunc_setBorderBrush, METH_O},
    {"setBorderStyle", (PyCFunction)Sbk_QTextFrameFormatFunc_setBorderStyle, METH_O},
    {"setBottomMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_setBottomMargin, METH_O},
    {"setHeight", (PyCFunction)Sbk_QTextFrameFormatFunc_setHeight, METH_O},
    {"setLeftMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_setLeftMargin, METH_O},
    {"setMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_setMargin, METH_O},
    {"setPadding", (PyCFunction)Sbk_QTextFrameFormatFunc_setPadding, METH_O},
    {"setPageBreakPolicy", (PyCFunction)Sbk_QTextFrameFormatFunc_setPageBreakPolicy, METH_O},
    {"setPosition", (PyCFunction)Sbk_QTextFrameFormatFunc_setPosition, METH_O},
    {"setRightMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_setRightMargin, METH_O},
    {"setTopMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_setTopMargin, METH_O},
    {"setWidth", (PyCFunction)Sbk_QTextFrameFormatFunc_setWidth, METH_O},
    {"topMargin", (PyCFunction)Sbk_QTextFrameFormatFunc_topMargin, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QTextFrameFormatFunc_width, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextFrameFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextFrameFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextFrameFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextFrameFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextFrameFormat",
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
    /*tp_traverse*/         Sbk_QTextFrameFormat_traverse,
    /*tp_clear*/            Sbk_QTextFrameFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextFrameFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextFrameFormat_Init,
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

// Python to C++ enum conversion.
static void QTextFrameFormat_Position_PythonToCpp_QTextFrameFormat_Position(PyObject* pyIn, void* cppOut) {
    *((::QTextFrameFormat::Position*)cppOut) = (::QTextFrameFormat::Position) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFrameFormat_Position_PythonToCpp_QTextFrameFormat_Position_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX]))
        return QTextFrameFormat_Position_PythonToCpp_QTextFrameFormat_Position;
    return 0;
}
static PyObject* QTextFrameFormat_Position_CppToPython_QTextFrameFormat_Position(const void* cppIn) {
    int castCppIn = *((::QTextFrameFormat::Position*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX], castCppIn);

}

static void QTextFrameFormat_BorderStyle_PythonToCpp_QTextFrameFormat_BorderStyle(PyObject* pyIn, void* cppOut) {
    *((::QTextFrameFormat::BorderStyle*)cppOut) = (::QTextFrameFormat::BorderStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFrameFormat_BorderStyle_PythonToCpp_QTextFrameFormat_BorderStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX]))
        return QTextFrameFormat_BorderStyle_PythonToCpp_QTextFrameFormat_BorderStyle;
    return 0;
}
static PyObject* QTextFrameFormat_BorderStyle_CppToPython_QTextFrameFormat_BorderStyle(const void* cppIn) {
    int castCppIn = *((::QTextFrameFormat::BorderStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextFrameFormat_PythonToCpp_QTextFrameFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextFrameFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextFrameFormat_PythonToCpp_QTextFrameFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextFrameFormat_Type))
        return QTextFrameFormat_PythonToCpp_QTextFrameFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextFrameFormat_PTR_CppToPython_QTextFrameFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextFrameFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextFrameFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextFrameFormat_COPY_CppToPython_QTextFrameFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextFrameFormat_Type, new ::QTextFrameFormat(*((::QTextFrameFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextFrameFormat_PythonToCpp_QTextFrameFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextFrameFormat*)cppOut) = *((::QTextFrameFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextFrameFormat_PythonToCpp_QTextFrameFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextFrameFormat_Type))
        return QTextFrameFormat_PythonToCpp_QTextFrameFormat_COPY;
    return 0;
}

void init_QTextFrameFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextFrameFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextFrameFormat", "QTextFrameFormat",
        &Sbk_QTextFrameFormat_Type, &Shiboken::callCppDestructor< ::QTextFrameFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextFrameFormat_Type,
        QTextFrameFormat_PythonToCpp_QTextFrameFormat_PTR,
        is_QTextFrameFormat_PythonToCpp_QTextFrameFormat_PTR_Convertible,
        QTextFrameFormat_PTR_CppToPython_QTextFrameFormat,
        QTextFrameFormat_COPY_CppToPython_QTextFrameFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextFrameFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextFrameFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextFrameFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextFrameFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextFrameFormat_PythonToCpp_QTextFrameFormat_COPY,
        is_QTextFrameFormat_PythonToCpp_QTextFrameFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Position'.
    SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFrameFormat_Type,
        "Position",
        "PySide.QtGui.QTextFrameFormat.Position",
        "QTextFrameFormat::Position");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX],
        &Sbk_QTextFrameFormat_Type, "InFlow", (long) QTextFrameFormat::InFlow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX],
        &Sbk_QTextFrameFormat_Type, "FloatLeft", (long) QTextFrameFormat::FloatLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX],
        &Sbk_QTextFrameFormat_Type, "FloatRight", (long) QTextFrameFormat::FloatRight))
        return ;
    // Register converter for enum 'QTextFrameFormat::Position'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX],
            QTextFrameFormat_Position_CppToPython_QTextFrameFormat_Position);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFrameFormat_Position_PythonToCpp_QTextFrameFormat_Position,
            is_QTextFrameFormat_Position_PythonToCpp_QTextFrameFormat_Position_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFrameFormat::Position");
        Shiboken::Conversions::registerConverterName(converter, "Position");
    }
    // End of 'Position' enum.

    // Initialization of enum 'BorderStyle'.
    SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFrameFormat_Type,
        "BorderStyle",
        "PySide.QtGui.QTextFrameFormat.BorderStyle",
        "QTextFrameFormat::BorderStyle");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_None", (long) QTextFrameFormat::BorderStyle_None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Dotted", (long) QTextFrameFormat::BorderStyle_Dotted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Dashed", (long) QTextFrameFormat::BorderStyle_Dashed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Solid", (long) QTextFrameFormat::BorderStyle_Solid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Double", (long) QTextFrameFormat::BorderStyle_Double))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_DotDash", (long) QTextFrameFormat::BorderStyle_DotDash))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_DotDotDash", (long) QTextFrameFormat::BorderStyle_DotDotDash))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Groove", (long) QTextFrameFormat::BorderStyle_Groove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Ridge", (long) QTextFrameFormat::BorderStyle_Ridge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Inset", (long) QTextFrameFormat::BorderStyle_Inset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
        &Sbk_QTextFrameFormat_Type, "BorderStyle_Outset", (long) QTextFrameFormat::BorderStyle_Outset))
        return ;
    // Register converter for enum 'QTextFrameFormat::BorderStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX],
            QTextFrameFormat_BorderStyle_CppToPython_QTextFrameFormat_BorderStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFrameFormat_BorderStyle_PythonToCpp_QTextFrameFormat_BorderStyle,
            is_QTextFrameFormat_BorderStyle_PythonToCpp_QTextFrameFormat_BorderStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFrameFormat::BorderStyle");
        Shiboken::Conversions::registerConverterName(converter, "BorderStyle");
    }
    // End of 'BorderStyle' enum.


    qRegisterMetaType< ::QTextFrameFormat >("QTextFrameFormat");
    qRegisterMetaType< ::QTextFrameFormat::Position >("QTextFrameFormat::Position");
    qRegisterMetaType< ::QTextFrameFormat::BorderStyle >("QTextFrameFormat::BorderStyle");
}
