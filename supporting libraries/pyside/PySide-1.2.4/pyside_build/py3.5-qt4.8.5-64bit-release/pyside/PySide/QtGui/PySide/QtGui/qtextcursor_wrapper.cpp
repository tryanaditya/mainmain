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

#include "qtextcursor_wrapper.h"

// Extra includes
#include <QTextBlock>
#include <QTextDocumentFragment>
#include <qimage.h>
#include <qtextcursor.h>
#include <qtextdocument.h>
#include <qtextdocumentfragment.h>
#include <qtextformat.h>
#include <qtextlist.h>
#include <qtextobject.h>
#include <qtexttable.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextCursor_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextCursor >()))
        return -1;

    ::QTextCursor* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextCursor", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextCursor()
    // 1: QTextCursor(QTextDocument*)
    // 2: QTextCursor(QTextFrame*)
    // 3: QTextCursor(QTextBlock)
    // 4: QTextCursor(QTextCursor)
    if (numArgs == 0) {
        overloadId = 0; // QTextCursor()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[0])))) {
        overloadId = 4; // QTextCursor(QTextCursor)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArgs[0])))) {
        overloadId = 3; // QTextCursor(QTextBlock)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextCursor(QTextFrame*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextCursor(QTextDocument*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursor_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextCursor()
        {

            if (!PyErr_Occurred()) {
                // QTextCursor()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCursor();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextCursor(QTextDocument * document)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextDocument* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextCursor(QTextDocument*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCursor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextCursor(QTextFrame * frame)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextCursor(QTextFrame*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCursor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QTextCursor(const QTextBlock & block)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextBlock cppArg0_local = ::QTextBlock();
            ::QTextBlock* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextCursor(QTextBlock)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCursor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QTextCursor(const QTextCursor & cursor)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextCursor cppArg0_local = ::QTextCursor();
            ::QTextCursor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextCursor(QTextCursor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCursor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextCursor >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextCursor_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextCursor_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextDocument", "PySide.QtGui.QTextFrame", "PySide.QtGui.QTextBlock", "PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor", overloads);
        return -1;
}

static PyObject* Sbk_QTextCursorFunc_anchor(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // anchor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->anchor();
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

static PyObject* Sbk_QTextCursorFunc_atBlockEnd(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atBlockEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->atBlockEnd();
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

static PyObject* Sbk_QTextCursorFunc_atBlockStart(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atBlockStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->atBlockStart();
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

static PyObject* Sbk_QTextCursorFunc_atEnd(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QTextCursorFunc_atStart(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->atStart();
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

static PyObject* Sbk_QTextCursorFunc_beginEditBlock(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beginEditBlock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->beginEditBlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_block(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // block()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextCursor*>(cppSelf)->block();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_blockCharFormat(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockCharFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QTextCursor*>(cppSelf)->blockCharFormat();
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

static PyObject* Sbk_QTextCursorFunc_blockFormat(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlockFormat cppResult = const_cast<const ::QTextCursor*>(cppSelf)->blockFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_blockNumber(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->blockNumber();
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

static PyObject* Sbk_QTextCursorFunc_charFormat(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // charFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QTextCursor*>(cppSelf)->charFormat();
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

static PyObject* Sbk_QTextCursorFunc_clearSelection(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearSelection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearSelection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_columnNumber(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->columnNumber();
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

static PyObject* Sbk_QTextCursorFunc_createList(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createList(QTextListFormat::Style)
    // 1: createList(QTextListFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (pyArg)))) {
        overloadId = 1; // createList(QTextListFormat)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]), (pyArg)))) {
        overloadId = 0; // createList(QTextListFormat::Style)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_createList_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // createList(QTextListFormat::Style style)
        {
            ::QTextListFormat::Style cppArg0 = ((::QTextListFormat::Style)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // createList(QTextListFormat::Style)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextList * cppResult = cppSelf->createList(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLIST_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // createList(const QTextListFormat & format)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextListFormat cppArg0_local = ::QTextListFormat();
            ::QTextListFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // createList(QTextListFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextList * cppResult = cppSelf->createList(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLIST_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_createList_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextListFormat.Style", "PySide.QtGui.QTextListFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.createList", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_currentFrame(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame * cppResult = const_cast<const ::QTextCursor*>(cppSelf)->currentFrame();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_currentList(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextList * cppResult = const_cast<const ::QTextCursor*>(cppSelf)->currentList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLIST_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_currentTable(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextTable * cppResult = const_cast<const ::QTextCursor*>(cppSelf)->currentTable();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_deleteChar(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deleteChar()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deleteChar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_deletePreviousChar(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deletePreviousChar()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deletePreviousChar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_document(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // document()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocument * cppResult = const_cast<const ::QTextCursor*>(cppSelf)->document();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_endEditBlock(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endEditBlock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endEditBlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_hasComplexSelection(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasComplexSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->hasComplexSelection();
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

static PyObject* Sbk_QTextCursorFunc_hasSelection(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->hasSelection();
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

static PyObject* Sbk_QTextCursorFunc_insertBlock(PyObject* self, PyObject* args)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertBlock", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertBlock()
    // 1: insertBlock(QTextBlockFormat)
    // 2: insertBlock(QTextBlockFormat,QTextCharFormat)
    if (numArgs == 0) {
        overloadId = 0; // insertBlock()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // insertBlock(QTextBlockFormat)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArgs[1])))) {
            overloadId = 2; // insertBlock(QTextBlockFormat,QTextCharFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertBlock_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertBlock()
        {

            if (!PyErr_Occurred()) {
                // insertBlock()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertBlock();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // insertBlock(const QTextBlockFormat & format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextBlockFormat cppArg0_local = ::QTextBlockFormat();
            ::QTextBlockFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // insertBlock(QTextBlockFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertBlock(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // insertBlock(const QTextBlockFormat & format, const QTextCharFormat & charFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextBlockFormat cppArg0_local = ::QTextBlockFormat();
            ::QTextBlockFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCharFormat cppArg1_local = ::QTextCharFormat();
            ::QTextCharFormat* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // insertBlock(QTextBlockFormat,QTextCharFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertBlock(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_insertBlock_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextBlockFormat", "PySide.QtGui.QTextBlockFormat, PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.insertBlock", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertFragment(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertFragment(QTextDocumentFragment)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (pyArg)))) {
        overloadId = 0; // insertFragment(QTextDocumentFragment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertFragment_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextDocumentFragment cppArg0_local = ::QTextDocumentFragment();
        ::QTextDocumentFragment* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // insertFragment(QTextDocumentFragment)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertFragment(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_insertFragment_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocumentFragment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.insertFragment", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertFrame(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertFrame(QTextFrameFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // insertFrame(QTextFrameFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertFrame_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextFrameFormat cppArg0_local = ::QTextFrameFormat();
        ::QTextFrameFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // insertFrame(QTextFrameFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrame * cppResult = cppSelf->insertFrame(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAME_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_insertFrame_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFrameFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.insertFrame", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertHtml(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertHtml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // insertHtml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertHtml_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // insertHtml(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertHtml(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_insertHtml_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.insertHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertImage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.insertImage(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.insertImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:insertImage", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertImage(QImage,QString)
    // 1: insertImage(QString)
    // 2: insertImage(QTextImageFormat)
    // 3: insertImage(QTextImageFormat,QTextFrameFormat::Position)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTIMAGEFORMAT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // insertImage(QTextImageFormat)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX]), (pyArgs[1])))) {
            overloadId = 3; // insertImage(QTextImageFormat,QTextFrameFormat::Position)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // insertImage(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // insertImage(QImage,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertImage(QImage,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertImage_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertImage(const QImage & image, const QString & name)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "name");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.insertImage(): got multiple values for keyword argument 'name'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QTextCursorFunc_insertImage_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertImage(QImage,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertImage(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // insertImage(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // insertImage(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertImage(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // insertImage(const QTextImageFormat & format)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextImageFormat cppArg0_local = ::QTextImageFormat();
            ::QTextImageFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTIMAGEFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // insertImage(QTextImageFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertImage(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // insertImage(const QTextImageFormat & format, QTextFrameFormat::Position alignment)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextImageFormat cppArg0_local = ::QTextImageFormat();
            ::QTextImageFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTIMAGEFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QTextFrameFormat::Position cppArg1 = ((::QTextFrameFormat::Position)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertImage(QTextImageFormat,QTextFrameFormat::Position)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertImage(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_insertImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, unicode = QString()", "unicode", "PySide.QtGui.QTextImageFormat", "PySide.QtGui.QTextImageFormat, PySide.QtGui.QTextFrameFormat.Position", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.insertImage", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertList(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertList(QTextListFormat::Style)
    // 1: insertList(QTextListFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (pyArg)))) {
        overloadId = 1; // insertList(QTextListFormat)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]), (pyArg)))) {
        overloadId = 0; // insertList(QTextListFormat::Style)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertList_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertList(QTextListFormat::Style style)
        {
            ::QTextListFormat::Style cppArg0 = ((::QTextListFormat::Style)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // insertList(QTextListFormat::Style)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextList * cppResult = cppSelf->insertList(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLIST_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // insertList(const QTextListFormat & format)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextListFormat cppArg0_local = ::QTextListFormat();
            ::QTextListFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // insertList(QTextListFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextList * cppResult = cppSelf->insertList(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLIST_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_insertList_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextListFormat.Style", "PySide.QtGui.QTextListFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.insertList", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertTable(PyObject* self, PyObject* args)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertTable", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insertTable(int,int)
    // 1: insertTable(int,int,QTextTableFormat)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // insertTable(int,int)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], (pyArgs[2])))) {
            overloadId = 1; // insertTable(int,int,QTextTableFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertTable_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertTable(int rows, int cols)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertTable(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextTable * cppResult = cppSelf->insertTable(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLE_IDX], cppResult);

                // Ownership transferences.
            }
            break;
        }
        case 1: // insertTable(int rows, int cols, const QTextTableFormat & format)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextTableFormat cppArg2_local = ::QTextTableFormat();
            ::QTextTableFormat* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // insertTable(int,int,QTextTableFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextTable * cppResult = cppSelf->insertTable(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLE_IDX], cppResult);

                // Ownership transferences.
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_insertTable_TypeError:
        const char* overloads[] = {"int, int", "int, int, PySide.QtGui.QTextTableFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.insertTable", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_insertText(PyObject* self, PyObject* args)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertText", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertText(QString)
    // 1: insertText(QString,QTextCharFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // insertText(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArgs[1])))) {
            overloadId = 1; // insertText(QString,QTextCharFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_insertText_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertText(const QString & text)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // insertText(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertText(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // insertText(const QString & text, const QTextCharFormat & format)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextCharFormat cppArg1_local = ::QTextCharFormat();
            ::QTextCharFormat* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // insertText(QString,QTextCharFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertText(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_insertText_TypeError:
        const char* overloads[] = {"unicode", "unicode, PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.insertText", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_isCopyOf(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isCopyOf(QTextCursor)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // isCopyOf(QTextCursor)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_isCopyOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCursor cppArg0_local = ::QTextCursor();
        ::QTextCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isCopyOf(QTextCursor)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->isCopyOf(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_isCopyOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.isCopyOf", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_isNull(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->isNull();
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

static PyObject* Sbk_QTextCursorFunc_joinPreviousEditBlock(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // joinPreviousEditBlock()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->joinPreviousEditBlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_keepPositionOnInsert(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keepPositionOnInsert()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->keepPositionOnInsert();
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

static PyObject* Sbk_QTextCursorFunc_mergeBlockCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mergeBlockCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // mergeBlockCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_mergeBlockCharFormat_TypeError;

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
            // mergeBlockCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->mergeBlockCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_mergeBlockCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.mergeBlockCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_mergeBlockFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mergeBlockFormat(QTextBlockFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // mergeBlockFormat(QTextBlockFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_mergeBlockFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlockFormat cppArg0_local = ::QTextBlockFormat();
        ::QTextBlockFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // mergeBlockFormat(QTextBlockFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->mergeBlockFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_mergeBlockFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlockFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.mergeBlockFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_mergeCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mergeCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // mergeCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_mergeCharFormat_TypeError;

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
            // mergeCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->mergeCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_mergeCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.mergeCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_movePosition(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.movePosition(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.movePosition(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:movePosition", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: movePosition(QTextCursor::MoveOperation,QTextCursor::MoveMode,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // movePosition(QTextCursor::MoveOperation,QTextCursor::MoveMode,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // movePosition(QTextCursor::MoveOperation,QTextCursor::MoveMode,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // movePosition(QTextCursor::MoveOperation,QTextCursor::MoveMode,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_movePosition_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__2");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.movePosition(): got multiple values for keyword argument 'arg__2'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QTextCursorFunc_movePosition_TypeError;
            }
            value = PyDict_GetItemString(kwds, "n");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.movePosition(): got multiple values for keyword argument 'n'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QTextCursorFunc_movePosition_TypeError;
            }
        }
        ::QTextCursor::MoveOperation cppArg0 = ((::QTextCursor::MoveOperation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTextCursor::MoveMode cppArg1 = QTextCursor::MoveAnchor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // movePosition(QTextCursor::MoveOperation,QTextCursor::MoveMode,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->movePosition(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextCursorFunc_movePosition_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCursor.MoveOperation, PySide.QtGui.QTextCursor.MoveMode = MoveAnchor, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.movePosition", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_position(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // position()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->position();
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

static PyObject* Sbk_QTextCursorFunc_positionInBlock(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // positionInBlock()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->positionInBlock();
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

static PyObject* Sbk_QTextCursorFunc_removeSelectedText(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeSelectedText()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeSelectedText();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextCursorFunc_select(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: select(QTextCursor::SelectionType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // select(QTextCursor::SelectionType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_select_TypeError;

    // Call function/method
    {
        ::QTextCursor::SelectionType cppArg0 = ((::QTextCursor::SelectionType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // select(QTextCursor::SelectionType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->select(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_select_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCursor.SelectionType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.select", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_selectedTableCells(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedTableCells(int*,int*,int*,int*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            int a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QTextCursor::selectedTableCells(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_selectedText(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextCursor*>(cppSelf)->selectedText();
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

static PyObject* Sbk_QTextCursorFunc_selection(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocumentFragment cppResult = const_cast<const ::QTextCursor*>(cppSelf)->selection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCursorFunc_selectionEnd(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->selectionEnd();
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

static PyObject* Sbk_QTextCursorFunc_selectionStart(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->selectionStart();
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

static PyObject* Sbk_QTextCursorFunc_setBlockCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlockCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setBlockCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setBlockCharFormat_TypeError;

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
            // setBlockCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlockCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setBlockCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setBlockCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setBlockFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBlockFormat(QTextBlockFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setBlockFormat(QTextBlockFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setBlockFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlockFormat cppArg0_local = ::QTextBlockFormat();
        ::QTextBlockFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBlockFormat(QTextBlockFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBlockFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setBlockFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlockFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setBlockFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setCharFormat_TypeError;

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
            // setCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setKeepPositionOnInsert(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setKeepPositionOnInsert(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setKeepPositionOnInsert(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setKeepPositionOnInsert_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setKeepPositionOnInsert(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setKeepPositionOnInsert(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setKeepPositionOnInsert_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setKeepPositionOnInsert", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setPosition(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.setPosition(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.setPosition(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setPosition", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPosition(int,QTextCursor::MoveMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setPosition(int,QTextCursor::MoveMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setPosition(int,QTextCursor::MoveMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setPosition_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCursor.setPosition(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QTextCursorFunc_setPosition_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTextCursor::MoveMode cppArg1 = QTextCursor::MoveAnchor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setPosition(int,QTextCursor::MoveMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPosition(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setPosition_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QTextCursor.MoveMode = MoveAnchor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCursor.setPosition", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setVerticalMovementX(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalMovementX(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setVerticalMovementX(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setVerticalMovementX_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalMovementX(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalMovementX(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setVerticalMovementX_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setVerticalMovementX", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_setVisualNavigation(PyObject* self, PyObject* pyArg)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisualNavigation(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisualNavigation(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCursorFunc_setVisualNavigation_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisualNavigation(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVisualNavigation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCursorFunc_setVisualNavigation_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCursor.setVisualNavigation", overloads);
        return 0;
}

static PyObject* Sbk_QTextCursorFunc_verticalMovementX(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalMovementX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCursor*>(cppSelf)->verticalMovementX();
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

static PyObject* Sbk_QTextCursorFunc_visualNavigation(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // visualNavigation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCursor*>(cppSelf)->visualNavigation();
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

static PyObject* Sbk_QTextCursor___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextCursor& cppSelf = *(((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextCursor_methods[] = {
    {"anchor", (PyCFunction)Sbk_QTextCursorFunc_anchor, METH_NOARGS},
    {"atBlockEnd", (PyCFunction)Sbk_QTextCursorFunc_atBlockEnd, METH_NOARGS},
    {"atBlockStart", (PyCFunction)Sbk_QTextCursorFunc_atBlockStart, METH_NOARGS},
    {"atEnd", (PyCFunction)Sbk_QTextCursorFunc_atEnd, METH_NOARGS},
    {"atStart", (PyCFunction)Sbk_QTextCursorFunc_atStart, METH_NOARGS},
    {"beginEditBlock", (PyCFunction)Sbk_QTextCursorFunc_beginEditBlock, METH_NOARGS},
    {"block", (PyCFunction)Sbk_QTextCursorFunc_block, METH_NOARGS},
    {"blockCharFormat", (PyCFunction)Sbk_QTextCursorFunc_blockCharFormat, METH_NOARGS},
    {"blockFormat", (PyCFunction)Sbk_QTextCursorFunc_blockFormat, METH_NOARGS},
    {"blockNumber", (PyCFunction)Sbk_QTextCursorFunc_blockNumber, METH_NOARGS},
    {"charFormat", (PyCFunction)Sbk_QTextCursorFunc_charFormat, METH_NOARGS},
    {"clearSelection", (PyCFunction)Sbk_QTextCursorFunc_clearSelection, METH_NOARGS},
    {"columnNumber", (PyCFunction)Sbk_QTextCursorFunc_columnNumber, METH_NOARGS},
    {"createList", (PyCFunction)Sbk_QTextCursorFunc_createList, METH_O},
    {"currentFrame", (PyCFunction)Sbk_QTextCursorFunc_currentFrame, METH_NOARGS},
    {"currentList", (PyCFunction)Sbk_QTextCursorFunc_currentList, METH_NOARGS},
    {"currentTable", (PyCFunction)Sbk_QTextCursorFunc_currentTable, METH_NOARGS},
    {"deleteChar", (PyCFunction)Sbk_QTextCursorFunc_deleteChar, METH_NOARGS},
    {"deletePreviousChar", (PyCFunction)Sbk_QTextCursorFunc_deletePreviousChar, METH_NOARGS},
    {"document", (PyCFunction)Sbk_QTextCursorFunc_document, METH_NOARGS},
    {"endEditBlock", (PyCFunction)Sbk_QTextCursorFunc_endEditBlock, METH_NOARGS},
    {"hasComplexSelection", (PyCFunction)Sbk_QTextCursorFunc_hasComplexSelection, METH_NOARGS},
    {"hasSelection", (PyCFunction)Sbk_QTextCursorFunc_hasSelection, METH_NOARGS},
    {"insertBlock", (PyCFunction)Sbk_QTextCursorFunc_insertBlock, METH_VARARGS},
    {"insertFragment", (PyCFunction)Sbk_QTextCursorFunc_insertFragment, METH_O},
    {"insertFrame", (PyCFunction)Sbk_QTextCursorFunc_insertFrame, METH_O},
    {"insertHtml", (PyCFunction)Sbk_QTextCursorFunc_insertHtml, METH_O},
    {"insertImage", (PyCFunction)Sbk_QTextCursorFunc_insertImage, METH_VARARGS|METH_KEYWORDS},
    {"insertList", (PyCFunction)Sbk_QTextCursorFunc_insertList, METH_O},
    {"insertTable", (PyCFunction)Sbk_QTextCursorFunc_insertTable, METH_VARARGS},
    {"insertText", (PyCFunction)Sbk_QTextCursorFunc_insertText, METH_VARARGS},
    {"isCopyOf", (PyCFunction)Sbk_QTextCursorFunc_isCopyOf, METH_O},
    {"isNull", (PyCFunction)Sbk_QTextCursorFunc_isNull, METH_NOARGS},
    {"joinPreviousEditBlock", (PyCFunction)Sbk_QTextCursorFunc_joinPreviousEditBlock, METH_NOARGS},
    {"keepPositionOnInsert", (PyCFunction)Sbk_QTextCursorFunc_keepPositionOnInsert, METH_NOARGS},
    {"mergeBlockCharFormat", (PyCFunction)Sbk_QTextCursorFunc_mergeBlockCharFormat, METH_O},
    {"mergeBlockFormat", (PyCFunction)Sbk_QTextCursorFunc_mergeBlockFormat, METH_O},
    {"mergeCharFormat", (PyCFunction)Sbk_QTextCursorFunc_mergeCharFormat, METH_O},
    {"movePosition", (PyCFunction)Sbk_QTextCursorFunc_movePosition, METH_VARARGS|METH_KEYWORDS},
    {"position", (PyCFunction)Sbk_QTextCursorFunc_position, METH_NOARGS},
    {"positionInBlock", (PyCFunction)Sbk_QTextCursorFunc_positionInBlock, METH_NOARGS},
    {"removeSelectedText", (PyCFunction)Sbk_QTextCursorFunc_removeSelectedText, METH_NOARGS},
    {"select", (PyCFunction)Sbk_QTextCursorFunc_select, METH_O},
    {"selectedTableCells", (PyCFunction)Sbk_QTextCursorFunc_selectedTableCells, METH_NOARGS},
    {"selectedText", (PyCFunction)Sbk_QTextCursorFunc_selectedText, METH_NOARGS},
    {"selection", (PyCFunction)Sbk_QTextCursorFunc_selection, METH_NOARGS},
    {"selectionEnd", (PyCFunction)Sbk_QTextCursorFunc_selectionEnd, METH_NOARGS},
    {"selectionStart", (PyCFunction)Sbk_QTextCursorFunc_selectionStart, METH_NOARGS},
    {"setBlockCharFormat", (PyCFunction)Sbk_QTextCursorFunc_setBlockCharFormat, METH_O},
    {"setBlockFormat", (PyCFunction)Sbk_QTextCursorFunc_setBlockFormat, METH_O},
    {"setCharFormat", (PyCFunction)Sbk_QTextCursorFunc_setCharFormat, METH_O},
    {"setKeepPositionOnInsert", (PyCFunction)Sbk_QTextCursorFunc_setKeepPositionOnInsert, METH_O},
    {"setPosition", (PyCFunction)Sbk_QTextCursorFunc_setPosition, METH_VARARGS|METH_KEYWORDS},
    {"setVerticalMovementX", (PyCFunction)Sbk_QTextCursorFunc_setVerticalMovementX, METH_O},
    {"setVisualNavigation", (PyCFunction)Sbk_QTextCursorFunc_setVisualNavigation, METH_O},
    {"verticalMovementX", (PyCFunction)Sbk_QTextCursorFunc_verticalMovementX, METH_NOARGS},
    {"visualNavigation", (PyCFunction)Sbk_QTextCursorFunc_visualNavigation, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextCursor___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QTextCursor___nb_bool(PyObject* self)
{
    ::QTextCursor* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QTextCursor_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextCursor& cppSelf = *(((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator!=(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
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
        case Py_LT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator<(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTextCursor_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator<=(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTextCursor_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator==(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
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
        case Py_GT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator>(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTextCursor_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
                // operator>=(const QTextCursor & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextCursor cppArg0_local = ::QTextCursor();
                ::QTextCursor* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTextCursor_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QTextCursor_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextCursor_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextCursor_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextCursor_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTextCursor_TypeAsNumber;

static SbkObjectType Sbk_QTextCursor_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextCursor",
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
    /*tp_traverse*/         Sbk_QTextCursor_traverse,
    /*tp_clear*/            Sbk_QTextCursor_clear,
    /*tp_richcompare*/      Sbk_QTextCursor_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextCursor_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextCursor_Init,
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
static void QTextCursor_MoveMode_PythonToCpp_QTextCursor_MoveMode(PyObject* pyIn, void* cppOut) {
    *((::QTextCursor::MoveMode*)cppOut) = (::QTextCursor::MoveMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCursor_MoveMode_PythonToCpp_QTextCursor_MoveMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]))
        return QTextCursor_MoveMode_PythonToCpp_QTextCursor_MoveMode;
    return 0;
}
static PyObject* QTextCursor_MoveMode_CppToPython_QTextCursor_MoveMode(const void* cppIn) {
    int castCppIn = *((::QTextCursor::MoveMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX], castCppIn);

}

static void QTextCursor_MoveOperation_PythonToCpp_QTextCursor_MoveOperation(PyObject* pyIn, void* cppOut) {
    *((::QTextCursor::MoveOperation*)cppOut) = (::QTextCursor::MoveOperation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCursor_MoveOperation_PythonToCpp_QTextCursor_MoveOperation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX]))
        return QTextCursor_MoveOperation_PythonToCpp_QTextCursor_MoveOperation;
    return 0;
}
static PyObject* QTextCursor_MoveOperation_CppToPython_QTextCursor_MoveOperation(const void* cppIn) {
    int castCppIn = *((::QTextCursor::MoveOperation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX], castCppIn);

}

static void QTextCursor_SelectionType_PythonToCpp_QTextCursor_SelectionType(PyObject* pyIn, void* cppOut) {
    *((::QTextCursor::SelectionType*)cppOut) = (::QTextCursor::SelectionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCursor_SelectionType_PythonToCpp_QTextCursor_SelectionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX]))
        return QTextCursor_SelectionType_PythonToCpp_QTextCursor_SelectionType;
    return 0;
}
static PyObject* QTextCursor_SelectionType_CppToPython_QTextCursor_SelectionType(const void* cppIn) {
    int castCppIn = *((::QTextCursor::SelectionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextCursor_PythonToCpp_QTextCursor_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextCursor_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextCursor_PythonToCpp_QTextCursor_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCursor_Type))
        return QTextCursor_PythonToCpp_QTextCursor_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextCursor_PTR_CppToPython_QTextCursor(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextCursor*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextCursor_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextCursor_COPY_CppToPython_QTextCursor(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextCursor_Type, new ::QTextCursor(*((::QTextCursor*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextCursor_PythonToCpp_QTextCursor_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextCursor*)cppOut) = *((::QTextCursor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextCursor_PythonToCpp_QTextCursor_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCursor_Type))
        return QTextCursor_PythonToCpp_QTextCursor_COPY;
    return 0;
}

void init_QTextCursor(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTextCursor_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QTextCursor_TypeAsNumber) = Sbk_QTextCursor___nb_bool;
    Sbk_QTextCursor_Type.super.ht_type.tp_as_number = &Sbk_QTextCursor_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextCursor_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextCursor", "QTextCursor",
        &Sbk_QTextCursor_Type, &Shiboken::callCppDestructor< ::QTextCursor >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextCursor_Type,
        QTextCursor_PythonToCpp_QTextCursor_PTR,
        is_QTextCursor_PythonToCpp_QTextCursor_PTR_Convertible,
        QTextCursor_PTR_CppToPython_QTextCursor,
        QTextCursor_COPY_CppToPython_QTextCursor);

    Shiboken::Conversions::registerConverterName(converter, "QTextCursor");
    Shiboken::Conversions::registerConverterName(converter, "QTextCursor*");
    Shiboken::Conversions::registerConverterName(converter, "QTextCursor&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextCursor).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextCursor_PythonToCpp_QTextCursor_COPY,
        is_QTextCursor_PythonToCpp_QTextCursor_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'MoveMode'.
    SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCursor_Type,
        "MoveMode",
        "PySide.QtGui.QTextCursor.MoveMode",
        "QTextCursor::MoveMode");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX],
        &Sbk_QTextCursor_Type, "MoveAnchor", (long) QTextCursor::MoveAnchor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX],
        &Sbk_QTextCursor_Type, "KeepAnchor", (long) QTextCursor::KeepAnchor))
        return ;
    // Register converter for enum 'QTextCursor::MoveMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX],
            QTextCursor_MoveMode_CppToPython_QTextCursor_MoveMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCursor_MoveMode_PythonToCpp_QTextCursor_MoveMode,
            is_QTextCursor_MoveMode_PythonToCpp_QTextCursor_MoveMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCursor::MoveMode");
        Shiboken::Conversions::registerConverterName(converter, "MoveMode");
    }
    // End of 'MoveMode' enum.

    // Initialization of enum 'MoveOperation'.
    SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCursor_Type,
        "MoveOperation",
        "PySide.QtGui.QTextCursor.MoveOperation",
        "QTextCursor::MoveOperation");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NoMove", (long) QTextCursor::NoMove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "Start", (long) QTextCursor::Start))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "Up", (long) QTextCursor::Up))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "StartOfLine", (long) QTextCursor::StartOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "StartOfBlock", (long) QTextCursor::StartOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "StartOfWord", (long) QTextCursor::StartOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "PreviousBlock", (long) QTextCursor::PreviousBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "PreviousCharacter", (long) QTextCursor::PreviousCharacter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "PreviousWord", (long) QTextCursor::PreviousWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "Left", (long) QTextCursor::Left))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "WordLeft", (long) QTextCursor::WordLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "End", (long) QTextCursor::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "Down", (long) QTextCursor::Down))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "EndOfLine", (long) QTextCursor::EndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "EndOfWord", (long) QTextCursor::EndOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "EndOfBlock", (long) QTextCursor::EndOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NextBlock", (long) QTextCursor::NextBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NextCharacter", (long) QTextCursor::NextCharacter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NextWord", (long) QTextCursor::NextWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "Right", (long) QTextCursor::Right))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "WordRight", (long) QTextCursor::WordRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NextCell", (long) QTextCursor::NextCell))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "PreviousCell", (long) QTextCursor::PreviousCell))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "NextRow", (long) QTextCursor::NextRow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
        &Sbk_QTextCursor_Type, "PreviousRow", (long) QTextCursor::PreviousRow))
        return ;
    // Register converter for enum 'QTextCursor::MoveOperation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX],
            QTextCursor_MoveOperation_CppToPython_QTextCursor_MoveOperation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCursor_MoveOperation_PythonToCpp_QTextCursor_MoveOperation,
            is_QTextCursor_MoveOperation_PythonToCpp_QTextCursor_MoveOperation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCursor::MoveOperation");
        Shiboken::Conversions::registerConverterName(converter, "MoveOperation");
    }
    // End of 'MoveOperation' enum.

    // Initialization of enum 'SelectionType'.
    SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCursor_Type,
        "SelectionType",
        "PySide.QtGui.QTextCursor.SelectionType",
        "QTextCursor::SelectionType");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX],
        &Sbk_QTextCursor_Type, "WordUnderCursor", (long) QTextCursor::WordUnderCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX],
        &Sbk_QTextCursor_Type, "LineUnderCursor", (long) QTextCursor::LineUnderCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX],
        &Sbk_QTextCursor_Type, "BlockUnderCursor", (long) QTextCursor::BlockUnderCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX],
        &Sbk_QTextCursor_Type, "Document", (long) QTextCursor::Document))
        return ;
    // Register converter for enum 'QTextCursor::SelectionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX],
            QTextCursor_SelectionType_CppToPython_QTextCursor_SelectionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCursor_SelectionType_PythonToCpp_QTextCursor_SelectionType,
            is_QTextCursor_SelectionType_PythonToCpp_QTextCursor_SelectionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCursor::SelectionType");
        Shiboken::Conversions::registerConverterName(converter, "SelectionType");
    }
    // End of 'SelectionType' enum.


    qRegisterMetaType< ::QTextCursor >("QTextCursor");
    qRegisterMetaType< ::QTextCursor::MoveMode >("QTextCursor::MoveMode");
    qRegisterMetaType< ::QTextCursor::MoveOperation >("QTextCursor::MoveOperation");
    qRegisterMetaType< ::QTextCursor::SelectionType >("QTextCursor::SelectionType");
}
