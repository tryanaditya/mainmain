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

#include "qtextblock_wrapper.h"
#include "qtextblock_iterator_wrapper.h"

// Extra includes
#include <QTextBlock>
#include <qtextdocument.h>
#include <qtextformat.h>
#include <qtextlayout.h>
#include <qtextlist.h>
#include <qtextobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextBlock_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextBlock >()))
        return -1;

    ::QTextBlock* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextBlock", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextBlock()
    // 1: QTextBlock(QTextBlock)
    if (numArgs == 0) {
        overloadId = 0; // QTextBlock()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextBlock(QTextBlock)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlock_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextBlock()
        {

            if (!PyErr_Occurred()) {
                // QTextBlock()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlock();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextBlock(const QTextBlock & o)
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
                // QTextBlock(QTextBlock)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlock(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextBlock >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextBlock_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextBlock_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextBlock", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextBlock", overloads);
        return -1;
}

static PyObject* Sbk_QTextBlockFunc___iter__(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __iter__()
            // Begin code injection

            // TEMPLATE - __iter_parent__ - START
            QTextBlock::iterator _tmp = cppSelf->begin();
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &_tmp);
            // TEMPLATE - __iter_parent__ - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_begin(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // begin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock::iterator cppResult = const_cast<const ::QTextBlock*>(cppSelf)->begin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_blockFormat(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlockFormat cppResult = const_cast<const ::QTextBlock*>(cppSelf)->blockFormat();
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

static PyObject* Sbk_QTextBlockFunc_blockFormatIndex(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockFormatIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->blockFormatIndex();
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

static PyObject* Sbk_QTextBlockFunc_blockNumber(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->blockNumber();
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

static PyObject* Sbk_QTextBlockFunc_charFormat(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // charFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QTextBlock*>(cppSelf)->charFormat();
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

static PyObject* Sbk_QTextBlockFunc_charFormatIndex(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // charFormatIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->charFormatIndex();
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

static PyObject* Sbk_QTextBlockFunc_clearLayout(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearLayout()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearLayout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextBlockFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // contains(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_contains_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlock*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextBlockFunc_contains_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.contains", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_document(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // document()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QTextDocument * cppResult = const_cast<const ::QTextBlock*>(cppSelf)->document();
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

static PyObject* Sbk_QTextBlockFunc_end(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // end()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock::iterator cppResult = const_cast<const ::QTextBlock*>(cppSelf)->end();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_firstLineNumber(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstLineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->firstLineNumber();
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

static PyObject* Sbk_QTextBlockFunc_fragmentIndex(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fragmentIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->fragmentIndex();
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

static PyObject* Sbk_QTextBlockFunc_isValid(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlock*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextBlockFunc_isVisible(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlock*>(cppSelf)->isVisible();
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

static PyObject* Sbk_QTextBlockFunc_layout(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // layout()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextLayout * cppResult = const_cast<const ::QTextBlock*>(cppSelf)->layout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLAYOUT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_length(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->length();
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

static PyObject* Sbk_QTextBlockFunc_lineCount(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->lineCount();
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

static PyObject* Sbk_QTextBlockFunc_next(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // next()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextBlock*>(cppSelf)->next();
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

static PyObject* Sbk_QTextBlockFunc_position(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // position()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->position();
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

static PyObject* Sbk_QTextBlockFunc_previous(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previous()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QTextBlock*>(cppSelf)->previous();
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

static PyObject* Sbk_QTextBlockFunc_revision(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->revision();
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

static PyObject* Sbk_QTextBlockFunc_setLineCount(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLineCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLineCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_setLineCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLineCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLineCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFunc_setLineCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.setLineCount", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_setRevision(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRevision(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRevision(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_setRevision_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRevision(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRevision(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFunc_setRevision_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.setRevision", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_setUserData(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserData(QTextBlockUserData*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX], (pyArg)))) {
        overloadId = 0; // setUserData(QTextBlockUserData*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_setUserData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlockUserData* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUserData(QTextBlockUserData*)

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUserData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Begin code injection

            const QTextDocument* doc = cppSelf->document();
            if (doc) {
                Shiboken::AutoDecRef pyDocument(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], doc));
                Shiboken::Object::setParent(pyDocument, pyArg);
            }

            // End of code injection
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFunc_setUserData_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlockUserData", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.setUserData", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_setUserState(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUserState(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setUserState(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_setUserState_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUserState(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUserState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFunc_setUserState_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.setUserState", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlockFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBlockFunc_setVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextBlock.setVisible", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlockFunc_text(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextBlock*>(cppSelf)->text();
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

static PyObject* Sbk_QTextBlockFunc_textDirection(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QTextBlock*>(cppSelf)->textDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_textList(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextList * cppResult = const_cast<const ::QTextBlock*>(cppSelf)->textList();
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

static PyObject* Sbk_QTextBlockFunc_userData(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userData()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlockUserData * cppResult = const_cast<const ::QTextBlock*>(cppSelf)->userData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX], cppResult);

            // Begin code injection

            const QTextDocument* doc = cppSelf->document();
            if (doc) {
                Shiboken::AutoDecRef pyDocument(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], doc));
                Shiboken::Object::setParent(pyDocument, pyResult);
            }

            // End of code injection

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlockFunc_userState(PyObject* self)
{
    ::QTextBlock* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBlock*>(cppSelf)->userState();
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

static PyObject* Sbk_QTextBlock___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBlock& cppSelf = *(((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextBlock_methods[] = {
    {"begin", (PyCFunction)Sbk_QTextBlockFunc_begin, METH_NOARGS},
    {"blockFormat", (PyCFunction)Sbk_QTextBlockFunc_blockFormat, METH_NOARGS},
    {"blockFormatIndex", (PyCFunction)Sbk_QTextBlockFunc_blockFormatIndex, METH_NOARGS},
    {"blockNumber", (PyCFunction)Sbk_QTextBlockFunc_blockNumber, METH_NOARGS},
    {"charFormat", (PyCFunction)Sbk_QTextBlockFunc_charFormat, METH_NOARGS},
    {"charFormatIndex", (PyCFunction)Sbk_QTextBlockFunc_charFormatIndex, METH_NOARGS},
    {"clearLayout", (PyCFunction)Sbk_QTextBlockFunc_clearLayout, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QTextBlockFunc_contains, METH_O},
    {"document", (PyCFunction)Sbk_QTextBlockFunc_document, METH_NOARGS},
    {"end", (PyCFunction)Sbk_QTextBlockFunc_end, METH_NOARGS},
    {"firstLineNumber", (PyCFunction)Sbk_QTextBlockFunc_firstLineNumber, METH_NOARGS},
    {"fragmentIndex", (PyCFunction)Sbk_QTextBlockFunc_fragmentIndex, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextBlockFunc_isValid, METH_NOARGS},
    {"isVisible", (PyCFunction)Sbk_QTextBlockFunc_isVisible, METH_NOARGS},
    {"layout", (PyCFunction)Sbk_QTextBlockFunc_layout, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QTextBlockFunc_length, METH_NOARGS},
    {"lineCount", (PyCFunction)Sbk_QTextBlockFunc_lineCount, METH_NOARGS},
    {"next", (PyCFunction)Sbk_QTextBlockFunc_next, METH_NOARGS},
    {"position", (PyCFunction)Sbk_QTextBlockFunc_position, METH_NOARGS},
    {"previous", (PyCFunction)Sbk_QTextBlockFunc_previous, METH_NOARGS},
    {"revision", (PyCFunction)Sbk_QTextBlockFunc_revision, METH_NOARGS},
    {"setLineCount", (PyCFunction)Sbk_QTextBlockFunc_setLineCount, METH_O},
    {"setRevision", (PyCFunction)Sbk_QTextBlockFunc_setRevision, METH_O},
    {"setUserData", (PyCFunction)Sbk_QTextBlockFunc_setUserData, METH_O},
    {"setUserState", (PyCFunction)Sbk_QTextBlockFunc_setUserState, METH_O},
    {"setVisible", (PyCFunction)Sbk_QTextBlockFunc_setVisible, METH_O},
    {"text", (PyCFunction)Sbk_QTextBlockFunc_text, METH_NOARGS},
    {"textDirection", (PyCFunction)Sbk_QTextBlockFunc_textDirection, METH_NOARGS},
    {"textList", (PyCFunction)Sbk_QTextBlockFunc_textList, METH_NOARGS},
    {"userData", (PyCFunction)Sbk_QTextBlockFunc_userData, METH_NOARGS},
    {"userState", (PyCFunction)Sbk_QTextBlockFunc_userState, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextBlock___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QTextBlock_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBlock& cppSelf = *(((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
                // operator!=(const QTextBlock & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextBlock cppArg0_local = ::QTextBlock();
                ::QTextBlock* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
                // operator<(const QTextBlock & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextBlock cppArg0_local = ::QTextBlock();
                ::QTextBlock* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTextBlock_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
                // operator==(const QTextBlock & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextBlock cppArg0_local = ::QTextBlock();
                ::QTextBlock* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
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
            goto Sbk_QTextBlock_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextBlock_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextBlock_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextBlock_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextBlock_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextBlock",
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
    /*tp_traverse*/         Sbk_QTextBlock_traverse,
    /*tp_clear*/            Sbk_QTextBlock_clear,
    /*tp_richcompare*/      Sbk_QTextBlock_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             Sbk_QTextBlockFunc___iter__,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextBlock_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextBlock_Init,
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
static void QTextBlock_PythonToCpp_QTextBlock_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextBlock_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextBlock_PythonToCpp_QTextBlock_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlock_Type))
        return QTextBlock_PythonToCpp_QTextBlock_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextBlock_PTR_CppToPython_QTextBlock(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextBlock*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextBlock_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextBlock_COPY_CppToPython_QTextBlock(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextBlock_Type, new ::QTextBlock(*((::QTextBlock*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextBlock_PythonToCpp_QTextBlock_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextBlock*)cppOut) = *((::QTextBlock*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextBlock_PythonToCpp_QTextBlock_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlock_Type))
        return QTextBlock_PythonToCpp_QTextBlock_COPY;
    return 0;
}

void init_QTextBlock(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextBlock_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextBlock", "QTextBlock",
        &Sbk_QTextBlock_Type, &Shiboken::callCppDestructor< ::QTextBlock >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextBlock_Type,
        QTextBlock_PythonToCpp_QTextBlock_PTR,
        is_QTextBlock_PythonToCpp_QTextBlock_PTR_Convertible,
        QTextBlock_PTR_CppToPython_QTextBlock,
        QTextBlock_COPY_CppToPython_QTextBlock);

    Shiboken::Conversions::registerConverterName(converter, "QTextBlock");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlock*");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlock&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBlock).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextBlock_PythonToCpp_QTextBlock_COPY,
        is_QTextBlock_PythonToCpp_QTextBlock_COPY_Convertible);


    qRegisterMetaType< ::QTextBlock >("QTextBlock");
}
