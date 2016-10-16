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

#include "qtexttableformat_wrapper.h"

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
Sbk_QTextTableFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextTableFormat >()))
        return -1;

    ::QTextTableFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextTableFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextTableFormat()
    // 1: QTextTableFormat(QTextFormat)
    // 2: QTextTableFormat(QTextTableFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextTableFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextTableFormat(QTextTableFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextTableFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextTableFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextTableFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextTableFormat(const QTextFormat & fmt)
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
                // QTextTableFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextTableFormat(const QTextTableFormat & QTextTableFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextTableFormat cppArg0_local = ::QTextTableFormat();
            ::QTextTableFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextTableFormat(QTextTableFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextTableFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextTableFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextTableFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextFormat", "PySide.QtGui.QTextTableFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextTableFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextTableFormatFunc_alignment(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->alignment();
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

static PyObject* Sbk_QTextTableFormatFunc_cellPadding(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cellPadding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->cellPadding();
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

static PyObject* Sbk_QTextTableFormatFunc_cellSpacing(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cellSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->cellSpacing();
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

static PyObject* Sbk_QTextTableFormatFunc_clearColumnWidthConstraints(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearColumnWidthConstraints()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearColumnWidthConstraints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextTableFormatFunc_columnWidthConstraints(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnWidthConstraints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QTextLength > cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->columnWidthConstraints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableFormatFunc_columns(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columns()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->columns();
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

static PyObject* Sbk_QTextTableFormatFunc_headerRowCount(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // headerRowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->headerRowCount();
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

static PyObject* Sbk_QTextTableFormatFunc_isValid(PyObject* self)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextTableFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextTableFormatFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setAlignment_TypeError;

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

    Sbk_QTextTableFormatFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormatFunc_setCellPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCellPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setCellPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setCellPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCellPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCellPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableFormatFunc_setCellPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setCellPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormatFunc_setCellSpacing(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCellSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setCellSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setCellSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCellSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCellSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableFormatFunc_setCellSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setCellSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormatFunc_setColumnWidthConstraints(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColumnWidthConstraints(QVector<QTextLength>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX], (pyArg)))) {
        overloadId = 0; // setColumnWidthConstraints(QVector<QTextLength>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setColumnWidthConstraints_TypeError;

    // Call function/method
    {
        ::QVector<QTextLength > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColumnWidthConstraints(QVector<QTextLength>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnWidthConstraints(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableFormatFunc_setColumnWidthConstraints_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setColumnWidthConstraints", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormatFunc_setColumns(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColumns(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setColumns(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setColumns_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColumns(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumns(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableFormatFunc_setColumns_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setColumns", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormatFunc_setHeaderRowCount(PyObject* self, PyObject* pyArg)
{
    ::QTextTableFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHeaderRowCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setHeaderRowCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableFormatFunc_setHeaderRowCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHeaderRowCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHeaderRowCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableFormatFunc_setHeaderRowCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableFormat.setHeaderRowCount", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextTableFormat& cppSelf = *(((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextTableFormat_methods[] = {
    {"alignment", (PyCFunction)Sbk_QTextTableFormatFunc_alignment, METH_NOARGS},
    {"cellPadding", (PyCFunction)Sbk_QTextTableFormatFunc_cellPadding, METH_NOARGS},
    {"cellSpacing", (PyCFunction)Sbk_QTextTableFormatFunc_cellSpacing, METH_NOARGS},
    {"clearColumnWidthConstraints", (PyCFunction)Sbk_QTextTableFormatFunc_clearColumnWidthConstraints, METH_NOARGS},
    {"columnWidthConstraints", (PyCFunction)Sbk_QTextTableFormatFunc_columnWidthConstraints, METH_NOARGS},
    {"columns", (PyCFunction)Sbk_QTextTableFormatFunc_columns, METH_NOARGS},
    {"headerRowCount", (PyCFunction)Sbk_QTextTableFormatFunc_headerRowCount, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextTableFormatFunc_isValid, METH_NOARGS},
    {"setAlignment", (PyCFunction)Sbk_QTextTableFormatFunc_setAlignment, METH_O},
    {"setCellPadding", (PyCFunction)Sbk_QTextTableFormatFunc_setCellPadding, METH_O},
    {"setCellSpacing", (PyCFunction)Sbk_QTextTableFormatFunc_setCellSpacing, METH_O},
    {"setColumnWidthConstraints", (PyCFunction)Sbk_QTextTableFormatFunc_setColumnWidthConstraints, METH_O},
    {"setColumns", (PyCFunction)Sbk_QTextTableFormatFunc_setColumns, METH_O},
    {"setHeaderRowCount", (PyCFunction)Sbk_QTextTableFormatFunc_setHeaderRowCount, METH_O},

    {"__copy__", (PyCFunction)Sbk_QTextTableFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextTableFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextTableFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextTableFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextTableFormat",
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
    /*tp_traverse*/         Sbk_QTextTableFormat_traverse,
    /*tp_clear*/            Sbk_QTextTableFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextTableFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextTableFormat_Init,
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
static void QTextTableFormat_PythonToCpp_QTextTableFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextTableFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextTableFormat_PythonToCpp_QTextTableFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableFormat_Type))
        return QTextTableFormat_PythonToCpp_QTextTableFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextTableFormat_PTR_CppToPython_QTextTableFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextTableFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextTableFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextTableFormat_COPY_CppToPython_QTextTableFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextTableFormat_Type, new ::QTextTableFormat(*((::QTextTableFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextTableFormat_PythonToCpp_QTextTableFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextTableFormat*)cppOut) = *((::QTextTableFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextTableFormat_PythonToCpp_QTextTableFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableFormat_Type))
        return QTextTableFormat_PythonToCpp_QTextTableFormat_COPY;
    return 0;
}

void init_QTextTableFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextTableFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextTableFormat", "QTextTableFormat",
        &Sbk_QTextTableFormat_Type, &Shiboken::callCppDestructor< ::QTextTableFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextTableFormat_Type,
        QTextTableFormat_PythonToCpp_QTextTableFormat_PTR,
        is_QTextTableFormat_PythonToCpp_QTextTableFormat_PTR_Convertible,
        QTextTableFormat_PTR_CppToPython_QTextTableFormat,
        QTextTableFormat_COPY_CppToPython_QTextTableFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextTableFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextTableFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextTableFormat_PythonToCpp_QTextTableFormat_COPY,
        is_QTextTableFormat_PythonToCpp_QTextTableFormat_COPY_Convertible);


    qRegisterMetaType< ::QTextTableFormat >("QTextTableFormat");
}
