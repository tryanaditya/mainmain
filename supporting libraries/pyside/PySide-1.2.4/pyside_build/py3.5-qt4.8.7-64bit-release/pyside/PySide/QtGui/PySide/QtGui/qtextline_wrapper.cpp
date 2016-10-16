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

#include "qtextline_wrapper.h"

// Extra includes
#include <QTextLayout>
#include <qpainter.h>
#include <qpoint.h>
#include <qrect.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextLine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextLine >()))
        return -1;

    ::QTextLine* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextLine", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextLine()
    // 1: QTextLine(QTextLine)
    if (numArgs == 0) {
        overloadId = 0; // QTextLine()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextLine(QTextLine)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLine_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextLine()
        {

            if (!PyErr_Occurred()) {
                // QTextLine()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLine();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextLine(const QTextLine & QTextLine)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextLine cppArg0_local = ::QTextLine();
            ::QTextLine* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextLine(QTextLine)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLine(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextLine >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextLine_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextLine_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextLine", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLine", overloads);
        return -1;
}

static PyObject* Sbk_QTextLineFunc_ascent(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ascent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->ascent();
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

static PyObject* Sbk_QTextLineFunc_cursorToX(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.cursorToX(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.cursorToX(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:cursorToX", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: cursorToX(int,QTextLine::Edge)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // cursorToX(int,QTextLine::Edge)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // cursorToX(int,QTextLine::Edge)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_cursorToX_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "edge");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.cursorToX(): got multiple values for keyword argument 'edge'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX]), (pyArgs[1]))))
                    goto Sbk_QTextLineFunc_cursorToX_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTextLine::Edge cppArg1 = QTextLine::Leading;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // cursorToX(int,QTextLine::Edge)const
            // Begin code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = cppSelf->::QTextLine::cursorToX(&cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppArg0));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextLineFunc_cursorToX_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QTextLine.Edge = Leading", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLine.cursorToX", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_descent(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // descent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->descent();
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

static PyObject* Sbk_QTextLineFunc_draw(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.draw(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.draw(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:draw", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: draw(QPainter*,QPointF,const QTextLayout::FormatRange*)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // draw(QPainter*,QPointF,const QTextLayout::FormatRange*)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (pyArgs[2])))) {
            overloadId = 0; // draw(QPainter*,QPointF,const QTextLayout::FormatRange*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_draw_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "selection");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.draw(): got multiple values for keyword argument 'selection'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX], (pyArgs[2]))))
                    goto Sbk_QTextLineFunc_draw_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPointF cppArg1_local = ::QPointF();
        ::QPointF* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QTextLayout::FormatRange* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // draw(QPainter*,QPointF,const QTextLayout::FormatRange*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QTextLine*>(cppSelf)->draw(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextLineFunc_draw_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QPointF, PySide.QtGui.QTextLayout::FormatRange = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLine.draw", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_height(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->height();
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

static PyObject* Sbk_QTextLineFunc_horizontalAdvance(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalAdvance()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->horizontalAdvance();
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

static PyObject* Sbk_QTextLineFunc_isValid(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextLine*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextLineFunc_leading(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leading()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->leading();
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

static PyObject* Sbk_QTextLineFunc_leadingIncluded(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leadingIncluded()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextLine*>(cppSelf)->leadingIncluded();
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

static PyObject* Sbk_QTextLineFunc_lineNumber(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextLine*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QTextLineFunc_naturalTextRect(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // naturalTextRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTextLine*>(cppSelf)->naturalTextRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextLineFunc_naturalTextWidth(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // naturalTextWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->naturalTextWidth();
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

static PyObject* Sbk_QTextLineFunc_position(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // position()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTextLine*>(cppSelf)->position();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextLineFunc_rect(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTextLine*>(cppSelf)->rect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextLineFunc_setLeadingIncluded(PyObject* self, PyObject* pyArg)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLeadingIncluded(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setLeadingIncluded(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_setLeadingIncluded_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLeadingIncluded(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLeadingIncluded(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextLineFunc_setLeadingIncluded_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLine.setLeadingIncluded", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_setLineWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLineWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setLineWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_setLineWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLineWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLineWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextLineFunc_setLineWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLine.setLineWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_setNumColumns(PyObject* self, PyObject* args)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setNumColumns", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setNumColumns(int)
    // 1: setNumColumns(int,qreal)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setNumColumns(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
            overloadId = 1; // setNumColumns(int,qreal)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_setNumColumns_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setNumColumns(int columns)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setNumColumns(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setNumColumns(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setNumColumns(int columns, qreal alignmentWidth)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setNumColumns(int,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setNumColumns(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextLineFunc_setNumColumns_TypeError:
        const char* overloads[] = {"int", "int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLine.setNumColumns", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_setPosition(PyObject* self, PyObject* pyArg)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPosition(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setPosition(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_setPosition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPosition(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPosition(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextLineFunc_setPosition_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLine.setPosition", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_textLength(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextLine*>(cppSelf)->textLength();
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

static PyObject* Sbk_QTextLineFunc_textStart(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextLine*>(cppSelf)->textStart();
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

static PyObject* Sbk_QTextLineFunc_width(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->width();
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

static PyObject* Sbk_QTextLineFunc_x(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->x();
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

static PyObject* Sbk_QTextLineFunc_xToCursor(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.xToCursor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.xToCursor(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:xToCursor", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: xToCursor(qreal,QTextLine::CursorPosition)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // xToCursor(qreal,QTextLine::CursorPosition)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX]), (pyArgs[1])))) {
            overloadId = 0; // xToCursor(qreal,QTextLine::CursorPosition)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLineFunc_xToCursor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "edge");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextLine.xToCursor(): got multiple values for keyword argument 'edge'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX]), (pyArgs[1]))))
                    goto Sbk_QTextLineFunc_xToCursor_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTextLine::CursorPosition cppArg1 = QTextLine::CursorBetweenCharacters;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // xToCursor(qreal,QTextLine::CursorPosition)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextLine*>(cppSelf)->xToCursor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextLineFunc_xToCursor_TypeError:
        const char* overloads[] = {"float, PySide.QtGui.QTextLine.CursorPosition = CursorBetweenCharacters", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLine.xToCursor", overloads);
        return 0;
}

static PyObject* Sbk_QTextLineFunc_y(PyObject* self)
{
    ::QTextLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLine*>(cppSelf)->y();
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

static PyObject* Sbk_QTextLine___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextLine& cppSelf = *(((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextLine_methods[] = {
    {"ascent", (PyCFunction)Sbk_QTextLineFunc_ascent, METH_NOARGS},
    {"cursorToX", (PyCFunction)Sbk_QTextLineFunc_cursorToX, METH_VARARGS|METH_KEYWORDS},
    {"descent", (PyCFunction)Sbk_QTextLineFunc_descent, METH_NOARGS},
    {"draw", (PyCFunction)Sbk_QTextLineFunc_draw, METH_VARARGS|METH_KEYWORDS},
    {"height", (PyCFunction)Sbk_QTextLineFunc_height, METH_NOARGS},
    {"horizontalAdvance", (PyCFunction)Sbk_QTextLineFunc_horizontalAdvance, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextLineFunc_isValid, METH_NOARGS},
    {"leading", (PyCFunction)Sbk_QTextLineFunc_leading, METH_NOARGS},
    {"leadingIncluded", (PyCFunction)Sbk_QTextLineFunc_leadingIncluded, METH_NOARGS},
    {"lineNumber", (PyCFunction)Sbk_QTextLineFunc_lineNumber, METH_NOARGS},
    {"naturalTextRect", (PyCFunction)Sbk_QTextLineFunc_naturalTextRect, METH_NOARGS},
    {"naturalTextWidth", (PyCFunction)Sbk_QTextLineFunc_naturalTextWidth, METH_NOARGS},
    {"position", (PyCFunction)Sbk_QTextLineFunc_position, METH_NOARGS},
    {"rect", (PyCFunction)Sbk_QTextLineFunc_rect, METH_NOARGS},
    {"setLeadingIncluded", (PyCFunction)Sbk_QTextLineFunc_setLeadingIncluded, METH_O},
    {"setLineWidth", (PyCFunction)Sbk_QTextLineFunc_setLineWidth, METH_O},
    {"setNumColumns", (PyCFunction)Sbk_QTextLineFunc_setNumColumns, METH_VARARGS},
    {"setPosition", (PyCFunction)Sbk_QTextLineFunc_setPosition, METH_O},
    {"textLength", (PyCFunction)Sbk_QTextLineFunc_textLength, METH_NOARGS},
    {"textStart", (PyCFunction)Sbk_QTextLineFunc_textStart, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QTextLineFunc_width, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QTextLineFunc_x, METH_NOARGS},
    {"xToCursor", (PyCFunction)Sbk_QTextLineFunc_xToCursor, METH_VARARGS|METH_KEYWORDS},
    {"y", (PyCFunction)Sbk_QTextLineFunc_y, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextLine___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextLine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextLine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextLine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextLine",
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
    /*tp_traverse*/         Sbk_QTextLine_traverse,
    /*tp_clear*/            Sbk_QTextLine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextLine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextLine_Init,
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
static void QTextLine_Edge_PythonToCpp_QTextLine_Edge(PyObject* pyIn, void* cppOut) {
    *((::QTextLine::Edge*)cppOut) = (::QTextLine::Edge) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextLine_Edge_PythonToCpp_QTextLine_Edge_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX]))
        return QTextLine_Edge_PythonToCpp_QTextLine_Edge;
    return 0;
}
static PyObject* QTextLine_Edge_CppToPython_QTextLine_Edge(const void* cppIn) {
    int castCppIn = *((::QTextLine::Edge*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX], castCppIn);

}

static void QTextLine_CursorPosition_PythonToCpp_QTextLine_CursorPosition(PyObject* pyIn, void* cppOut) {
    *((::QTextLine::CursorPosition*)cppOut) = (::QTextLine::CursorPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextLine_CursorPosition_PythonToCpp_QTextLine_CursorPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX]))
        return QTextLine_CursorPosition_PythonToCpp_QTextLine_CursorPosition;
    return 0;
}
static PyObject* QTextLine_CursorPosition_CppToPython_QTextLine_CursorPosition(const void* cppIn) {
    int castCppIn = *((::QTextLine::CursorPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextLine_PythonToCpp_QTextLine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextLine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextLine_PythonToCpp_QTextLine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLine_Type))
        return QTextLine_PythonToCpp_QTextLine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextLine_PTR_CppToPython_QTextLine(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextLine*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextLine_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextLine_COPY_CppToPython_QTextLine(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextLine_Type, new ::QTextLine(*((::QTextLine*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextLine_PythonToCpp_QTextLine_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextLine*)cppOut) = *((::QTextLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextLine_PythonToCpp_QTextLine_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLine_Type))
        return QTextLine_PythonToCpp_QTextLine_COPY;
    return 0;
}

void init_QTextLine(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTLINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextLine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextLine", "QTextLine",
        &Sbk_QTextLine_Type, &Shiboken::callCppDestructor< ::QTextLine >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextLine_Type,
        QTextLine_PythonToCpp_QTextLine_PTR,
        is_QTextLine_PythonToCpp_QTextLine_PTR_Convertible,
        QTextLine_PTR_CppToPython_QTextLine,
        QTextLine_COPY_CppToPython_QTextLine);

    Shiboken::Conversions::registerConverterName(converter, "QTextLine");
    Shiboken::Conversions::registerConverterName(converter, "QTextLine*");
    Shiboken::Conversions::registerConverterName(converter, "QTextLine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextLine).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextLine_PythonToCpp_QTextLine_COPY,
        is_QTextLine_PythonToCpp_QTextLine_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Edge'.
    SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextLine_Type,
        "Edge",
        "PySide.QtGui.QTextLine.Edge",
        "QTextLine::Edge");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX],
        &Sbk_QTextLine_Type, "Leading", (long) QTextLine::Leading))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX],
        &Sbk_QTextLine_Type, "Trailing", (long) QTextLine::Trailing))
        return ;
    // Register converter for enum 'QTextLine::Edge'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX],
            QTextLine_Edge_CppToPython_QTextLine_Edge);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextLine_Edge_PythonToCpp_QTextLine_Edge,
            is_QTextLine_Edge_PythonToCpp_QTextLine_Edge_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextLine::Edge");
        Shiboken::Conversions::registerConverterName(converter, "Edge");
    }
    // End of 'Edge' enum.

    // Initialization of enum 'CursorPosition'.
    SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextLine_Type,
        "CursorPosition",
        "PySide.QtGui.QTextLine.CursorPosition",
        "QTextLine::CursorPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX],
        &Sbk_QTextLine_Type, "CursorBetweenCharacters", (long) QTextLine::CursorBetweenCharacters))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX],
        &Sbk_QTextLine_Type, "CursorOnCharacter", (long) QTextLine::CursorOnCharacter))
        return ;
    // Register converter for enum 'QTextLine::CursorPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX],
            QTextLine_CursorPosition_CppToPython_QTextLine_CursorPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextLine_CursorPosition_PythonToCpp_QTextLine_CursorPosition,
            is_QTextLine_CursorPosition_PythonToCpp_QTextLine_CursorPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextLine::CursorPosition");
        Shiboken::Conversions::registerConverterName(converter, "CursorPosition");
    }
    // End of 'CursorPosition' enum.


    qRegisterMetaType< ::QTextLine >("QTextLine");
    qRegisterMetaType< ::QTextLine::Edge >("QTextLine::Edge");
    qRegisterMetaType< ::QTextLine::CursorPosition >("QTextLine::CursorPosition");
}
