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

#include "qtexttablecell_wrapper.h"

// Extra includes
#include <QTextCursor>
#include <QTextFrame>
#include <qtextcursor.h>
#include <qtextformat.h>
#include <qtexttable.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextTableCell_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextTableCell >()))
        return -1;

    ::QTextTableCell* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextTableCell", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextTableCell()
    // 1: QTextTableCell(QTextTableCell)
    if (numArgs == 0) {
        overloadId = 0; // QTextTableCell()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextTableCell(QTextTableCell)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCell_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextTableCell()
        {

            if (!PyErr_Occurred()) {
                // QTextTableCell()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableCell();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextTableCell(const QTextTableCell & o)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextTableCell cppArg0_local = ::QTextTableCell();
            ::QTextTableCell* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextTableCell(QTextTableCell)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableCell(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextTableCell >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextTableCell_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextTableCell_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextTableCell", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextTableCell", overloads);
        return -1;
}

static PyObject* Sbk_QTextTableCellFunc_begin(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // begin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame::iterator cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->begin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_ITERATOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableCellFunc_column(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // column()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->column();
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

static PyObject* Sbk_QTextTableCellFunc_columnSpan(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnSpan()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->columnSpan();
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

static PyObject* Sbk_QTextTableCellFunc_end(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // end()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame::iterator cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->end();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_ITERATOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableCellFunc_firstCursorPosition(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstCursorPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCursor cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->firstCursorPosition();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableCellFunc_firstPosition(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->firstPosition();
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

static PyObject* Sbk_QTextTableCellFunc_format(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableCellFunc_isValid(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextTableCellFunc_lastCursorPosition(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastCursorPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCursor cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->lastCursorPosition();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextTableCellFunc_lastPosition(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->lastPosition();
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

static PyObject* Sbk_QTextTableCellFunc_row(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // row()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->row();
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

static PyObject* Sbk_QTextTableCellFunc_rowSpan(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowSpan()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->rowSpan();
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

static PyObject* Sbk_QTextTableCellFunc_setFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFunc_setFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCharFormat cppArg0_local = ::QTextCharFormat();
        ::QTextCharFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFunc_setFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCell.setFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFunc_tableCellFormatIndex(PyObject* self)
{
    ::QTextTableCell* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableCellFormatIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextTableCell*>(cppSelf)->tableCellFormatIndex();
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

static PyObject* Sbk_QTextTableCell___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextTableCell& cppSelf = *(((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextTableCell_methods[] = {
    {"begin", (PyCFunction)Sbk_QTextTableCellFunc_begin, METH_NOARGS},
    {"column", (PyCFunction)Sbk_QTextTableCellFunc_column, METH_NOARGS},
    {"columnSpan", (PyCFunction)Sbk_QTextTableCellFunc_columnSpan, METH_NOARGS},
    {"end", (PyCFunction)Sbk_QTextTableCellFunc_end, METH_NOARGS},
    {"firstCursorPosition", (PyCFunction)Sbk_QTextTableCellFunc_firstCursorPosition, METH_NOARGS},
    {"firstPosition", (PyCFunction)Sbk_QTextTableCellFunc_firstPosition, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QTextTableCellFunc_format, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextTableCellFunc_isValid, METH_NOARGS},
    {"lastCursorPosition", (PyCFunction)Sbk_QTextTableCellFunc_lastCursorPosition, METH_NOARGS},
    {"lastPosition", (PyCFunction)Sbk_QTextTableCellFunc_lastPosition, METH_NOARGS},
    {"row", (PyCFunction)Sbk_QTextTableCellFunc_row, METH_NOARGS},
    {"rowSpan", (PyCFunction)Sbk_QTextTableCellFunc_rowSpan, METH_NOARGS},
    {"setFormat", (PyCFunction)Sbk_QTextTableCellFunc_setFormat, METH_O},
    {"tableCellFormatIndex", (PyCFunction)Sbk_QTextTableCellFunc_tableCellFormatIndex, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextTableCell___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QTextTableCell_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextTableCell& cppSelf = *(((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (pyArg)))) {
                // operator!=(const QTextTableCell & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextTableCell cppArg0_local = ::QTextTableCell();
                ::QTextTableCell* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (pyArg)))) {
                // operator==(const QTextTableCell & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextTableCell cppArg0_local = ::QTextTableCell();
                ::QTextTableCell* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QTextTableCell_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextTableCell_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextTableCell_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextTableCell_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextTableCell_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextTableCell",
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
    /*tp_traverse*/         Sbk_QTextTableCell_traverse,
    /*tp_clear*/            Sbk_QTextTableCell_clear,
    /*tp_richcompare*/      Sbk_QTextTableCell_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextTableCell_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextTableCell_Init,
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
static void QTextTableCell_PythonToCpp_QTextTableCell_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextTableCell_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextTableCell_PythonToCpp_QTextTableCell_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableCell_Type))
        return QTextTableCell_PythonToCpp_QTextTableCell_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextTableCell_PTR_CppToPython_QTextTableCell(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextTableCell*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextTableCell_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextTableCell_COPY_CppToPython_QTextTableCell(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextTableCell_Type, new ::QTextTableCell(*((::QTextTableCell*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextTableCell_PythonToCpp_QTextTableCell_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextTableCell*)cppOut) = *((::QTextTableCell*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextTableCell_PythonToCpp_QTextTableCell_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableCell_Type))
        return QTextTableCell_PythonToCpp_QTextTableCell_COPY;
    return 0;
}

void init_QTextTableCell(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextTableCell_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextTableCell", "QTextTableCell",
        &Sbk_QTextTableCell_Type, &Shiboken::callCppDestructor< ::QTextTableCell >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextTableCell_Type,
        QTextTableCell_PythonToCpp_QTextTableCell_PTR,
        is_QTextTableCell_PythonToCpp_QTextTableCell_PTR_Convertible,
        QTextTableCell_PTR_CppToPython_QTextTableCell,
        QTextTableCell_COPY_CppToPython_QTextTableCell);

    Shiboken::Conversions::registerConverterName(converter, "QTextTableCell");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableCell*");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableCell&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextTableCell).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextTableCell_PythonToCpp_QTextTableCell_COPY,
        is_QTextTableCell_PythonToCpp_QTextTableCell_COPY_Convertible);


    qRegisterMetaType< ::QTextTableCell >("QTextTableCell");
}
