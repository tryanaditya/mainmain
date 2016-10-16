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

#include "qtextblockformat_wrapper.h"

// Extra includes
#include <QList>
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qpen.h>
#include <qtextformat.h>
#include <qtextoption.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextBlockFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextBlockFormat >()))
        return -1;

    ::QTextBlockFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextBlockFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextBlockFormat()
    // 1: QTextBlockFormat(QTextBlockFormat)
    // 2: QTextBlockFormat(QTextFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextBlockFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextBlockFormat(QTextBlockFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextBlockFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextBlockFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextBlockFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlockFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextBlockFormat(const QTextBlockFormat & QTextBlockFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextBlockFormat cppArg0_local = ::QTextBlockFormat();
            ::QTextBlockFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextBlockFormat(QTextBlockFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlockFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextBlockFormat(const QTextFormat & fmt)
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
                // QTextBlockFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlockFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextBlockFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextBlockFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextBlockFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextBlockFormat", "PySide.QtGui.QTextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextBlockFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextBlockFormatFunc_alignment(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->alignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFormatFunc_bottomMargin(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottomMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->bottomMargin();
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

static PyObject* Sbk_QTextBlockFormatFunc_indent(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->indent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFormatFunc_isValid(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextBlockFormatFunc_leftMargin(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leftMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->leftMargin();
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

static PyObject* Sbk_QTextBlockFormatFunc_lineHeight(PyObject* self, PyObject* args)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QTextBlockFormatFunc_lineHeight_TypeError;

    if (!PyArg_UnpackTuple(args, "lineHeight", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lineHeight()const
    // 1: lineHeight(qreal,qreal)const
    if (numArgs == 0) {
        overloadId = 0; // lineHeight()const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // lineHeight(qreal,qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_lineHeight_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // lineHeight() const
        {

            if (!PyErr_Occurred()) {
                // lineHeight()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->lineHeight();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
        case 1: // lineHeight(qreal scriptLineHeight, qreal scaling) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // lineHeight(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->lineHeight(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextBlockFormatFunc_lineHeight_TypeError:
        const char* overloads[] = {"", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextBlockFormat.lineHeight", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_lineHeightType(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineHeightType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->lineHeightType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFormatFunc_nonBreakableLines(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nonBreakableLines()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->nonBreakableLines();
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

static PyObject* Sbk_QTextBlockFormatFunc_pageBreakPolicy(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageBreakPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextFormat::PageBreakFlag> cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->pageBreakPolicy();
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

static PyObject* Sbk_QTextBlockFormatFunc_rightMargin(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rightMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->rightMargin();
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

static PyObject* Sbk_QTextBlockFormatFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setBottomMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBottomMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBottomMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setBottomMargin_TypeError;

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

    Sbk_QTextBlockFormatFunc_setBottomMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setBottomMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setIndent(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIndent(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setIndent(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setIndent_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIndent(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIndent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setIndent_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setIndent", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setLeftMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLeftMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setLeftMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setLeftMargin_TypeError;

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

    Sbk_QTextBlockFormatFunc_setLeftMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setLeftMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setLineHeight(PyObject* self, PyObject* args)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLineHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setLineHeight(qreal,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setLineHeight(qreal,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setLineHeight_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setLineHeight(qreal,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLineHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setLineHeight_TypeError:
        const char* overloads[] = {"float, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextBlockFormat.setLineHeight", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setNonBreakableLines(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNonBreakableLines(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setNonBreakableLines(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setNonBreakableLines_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNonBreakableLines(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNonBreakableLines(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setNonBreakableLines_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setNonBreakableLines", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setPageBreakPolicy(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPageBreakPolicy(QFlags<QTextFormat::PageBreakFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setPageBreakPolicy(QFlags<QTextFormat::PageBreakFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setPageBreakPolicy_TypeError;

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

    Sbk_QTextBlockFormatFunc_setPageBreakPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFormat.PageBreakFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setPageBreakPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setRightMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRightMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRightMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setRightMargin_TypeError;

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

    Sbk_QTextBlockFormatFunc_setRightMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setRightMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setTabPositions(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabPositions(QList<QTextOption::Tab>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], (pyArg)))) {
        overloadId = 0; // setTabPositions(QList<QTextOption::Tab>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setTabPositions_TypeError;

    // Call function/method
    {
        ::QList<QTextOption::Tab > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabPositions(QList<QTextOption::Tab>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabPositions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setTabPositions_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setTabPositions", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setTextIndent(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextIndent(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTextIndent(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setTextIndent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextIndent(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextIndent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFormatFunc_setTextIndent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setTextIndent", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_setTopMargin(PyObject* self, PyObject* pyArg)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTopMargin(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTopMargin(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFormatFunc_setTopMargin_TypeError;

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

    Sbk_QTextBlockFormatFunc_setTopMargin_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlockFormat.setTopMargin", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFormatFunc_tabPositions(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabPositions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QTextOption::Tab > cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->tabPositions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFormatFunc_textIndent(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textIndent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->textIndent();
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

static PyObject* Sbk_QTextBlockFormatFunc_topMargin(PyObject* self)
{
    ::QTextBlockFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextBlockFormat*>(cppSelf)->topMargin();
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

static PyObject* Sbk_QTextBlockFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBlockFormat& cppSelf = *(((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextBlockFormat_methods[] = {
    {"alignment", (PyCFunction)Sbk_QTextBlockFormatFunc_alignment, METH_NOARGS},
    {"bottomMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_bottomMargin, METH_NOARGS},
    {"indent", (PyCFunction)Sbk_QTextBlockFormatFunc_indent, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextBlockFormatFunc_isValid, METH_NOARGS},
    {"leftMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_leftMargin, METH_NOARGS},
    {"lineHeight", (PyCFunction)Sbk_QTextBlockFormatFunc_lineHeight, METH_VARARGS},
    {"lineHeightType", (PyCFunction)Sbk_QTextBlockFormatFunc_lineHeightType, METH_NOARGS},
    {"nonBreakableLines", (PyCFunction)Sbk_QTextBlockFormatFunc_nonBreakableLines, METH_NOARGS},
    {"pageBreakPolicy", (PyCFunction)Sbk_QTextBlockFormatFunc_pageBreakPolicy, METH_NOARGS},
    {"rightMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_rightMargin, METH_NOARGS},
    {"setAlignment", (PyCFunction)Sbk_QTextBlockFormatFunc_setAlignment, METH_O},
    {"setBottomMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_setBottomMargin, METH_O},
    {"setIndent", (PyCFunction)Sbk_QTextBlockFormatFunc_setIndent, METH_O},
    {"setLeftMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_setLeftMargin, METH_O},
    {"setLineHeight", (PyCFunction)Sbk_QTextBlockFormatFunc_setLineHeight, METH_VARARGS},
    {"setNonBreakableLines", (PyCFunction)Sbk_QTextBlockFormatFunc_setNonBreakableLines, METH_O},
    {"setPageBreakPolicy", (PyCFunction)Sbk_QTextBlockFormatFunc_setPageBreakPolicy, METH_O},
    {"setRightMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_setRightMargin, METH_O},
    {"setTabPositions", (PyCFunction)Sbk_QTextBlockFormatFunc_setTabPositions, METH_O},
    {"setTextIndent", (PyCFunction)Sbk_QTextBlockFormatFunc_setTextIndent, METH_O},
    {"setTopMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_setTopMargin, METH_O},
    {"tabPositions", (PyCFunction)Sbk_QTextBlockFormatFunc_tabPositions, METH_NOARGS},
    {"textIndent", (PyCFunction)Sbk_QTextBlockFormatFunc_textIndent, METH_NOARGS},
    {"topMargin", (PyCFunction)Sbk_QTextBlockFormatFunc_topMargin, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextBlockFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextBlockFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextBlockFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextBlockFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextBlockFormat",
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
    /*tp_traverse*/         Sbk_QTextBlockFormat_traverse,
    /*tp_clear*/            Sbk_QTextBlockFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextBlockFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextBlockFormat_Init,
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
static void QTextBlockFormat_LineHeightTypes_PythonToCpp_QTextBlockFormat_LineHeightTypes(PyObject* pyIn, void* cppOut) {
    *((::QTextBlockFormat::LineHeightTypes*)cppOut) = (::QTextBlockFormat::LineHeightTypes) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextBlockFormat_LineHeightTypes_PythonToCpp_QTextBlockFormat_LineHeightTypes_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX]))
        return QTextBlockFormat_LineHeightTypes_PythonToCpp_QTextBlockFormat_LineHeightTypes;
    return 0;
}
static PyObject* QTextBlockFormat_LineHeightTypes_CppToPython_QTextBlockFormat_LineHeightTypes(const void* cppIn) {
    int castCppIn = *((::QTextBlockFormat::LineHeightTypes*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextBlockFormat_PythonToCpp_QTextBlockFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextBlockFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextBlockFormat_PythonToCpp_QTextBlockFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlockFormat_Type))
        return QTextBlockFormat_PythonToCpp_QTextBlockFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextBlockFormat_PTR_CppToPython_QTextBlockFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextBlockFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextBlockFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextBlockFormat_COPY_CppToPython_QTextBlockFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextBlockFormat_Type, new ::QTextBlockFormat(*((::QTextBlockFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextBlockFormat_PythonToCpp_QTextBlockFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextBlockFormat*)cppOut) = *((::QTextBlockFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextBlockFormat_PythonToCpp_QTextBlockFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlockFormat_Type))
        return QTextBlockFormat_PythonToCpp_QTextBlockFormat_COPY;
    return 0;
}

void init_QTextBlockFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextBlockFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextBlockFormat", "QTextBlockFormat",
        &Sbk_QTextBlockFormat_Type, &Shiboken::callCppDestructor< ::QTextBlockFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextBlockFormat_Type,
        QTextBlockFormat_PythonToCpp_QTextBlockFormat_PTR,
        is_QTextBlockFormat_PythonToCpp_QTextBlockFormat_PTR_Convertible,
        QTextBlockFormat_PTR_CppToPython_QTextBlockFormat,
        QTextBlockFormat_COPY_CppToPython_QTextBlockFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextBlockFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlockFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlockFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBlockFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextBlockFormat_PythonToCpp_QTextBlockFormat_COPY,
        is_QTextBlockFormat_PythonToCpp_QTextBlockFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'LineHeightTypes'.
    SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextBlockFormat_Type,
        "LineHeightTypes",
        "PySide.QtGui.QTextBlockFormat.LineHeightTypes",
        "QTextBlockFormat::LineHeightTypes");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
        &Sbk_QTextBlockFormat_Type, "SingleHeight", (long) QTextBlockFormat::SingleHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
        &Sbk_QTextBlockFormat_Type, "ProportionalHeight", (long) QTextBlockFormat::ProportionalHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
        &Sbk_QTextBlockFormat_Type, "FixedHeight", (long) QTextBlockFormat::FixedHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
        &Sbk_QTextBlockFormat_Type, "MinimumHeight", (long) QTextBlockFormat::MinimumHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
        &Sbk_QTextBlockFormat_Type, "LineDistanceHeight", (long) QTextBlockFormat::LineDistanceHeight))
        return ;
    // Register converter for enum 'QTextBlockFormat::LineHeightTypes'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX],
            QTextBlockFormat_LineHeightTypes_CppToPython_QTextBlockFormat_LineHeightTypes);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextBlockFormat_LineHeightTypes_PythonToCpp_QTextBlockFormat_LineHeightTypes,
            is_QTextBlockFormat_LineHeightTypes_PythonToCpp_QTextBlockFormat_LineHeightTypes_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextBlockFormat::LineHeightTypes");
        Shiboken::Conversions::registerConverterName(converter, "LineHeightTypes");
    }
    // End of 'LineHeightTypes' enum.


    qRegisterMetaType< ::QTextBlockFormat >("QTextBlockFormat");
    qRegisterMetaType< ::QTextBlockFormat::LineHeightTypes >("QTextBlockFormat::LineHeightTypes");
}
