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

#include "qtextcharformat_wrapper.h"

// Extra includes
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qfont.h>
#include <qpen.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextCharFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextCharFormat >()))
        return -1;

    ::QTextCharFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextCharFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextCharFormat()
    // 1: QTextCharFormat(QTextCharFormat)
    // 2: QTextCharFormat(QTextFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextCharFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextCharFormat(QTextCharFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextCharFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextCharFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextCharFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCharFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextCharFormat(const QTextCharFormat & QTextCharFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextCharFormat cppArg0_local = ::QTextCharFormat();
            ::QTextCharFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextCharFormat(QTextCharFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCharFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextCharFormat(const QTextFormat & fmt)
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
                // QTextCharFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextCharFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextCharFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextCharFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextCharFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextCharFormat", "PySide.QtGui.QTextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCharFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextCharFormatFunc_anchorHref(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // anchorHref()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->anchorHref();
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

static PyObject* Sbk_QTextCharFormatFunc_anchorNames(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // anchorNames()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->anchorNames();
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

static PyObject* Sbk_QTextCharFormatFunc_font(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_fontCapitalization(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontCapitalization()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::Capitalization cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontCapitalization();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_fontFamily(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontFamily()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontFamily();
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

static PyObject* Sbk_QTextCharFormatFunc_fontFixedPitch(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontFixedPitch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontFixedPitch();
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

static PyObject* Sbk_QTextCharFormatFunc_fontHintingPreference(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontHintingPreference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::HintingPreference cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontHintingPreference();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_fontItalic(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontItalic()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontItalic();
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

static PyObject* Sbk_QTextCharFormatFunc_fontKerning(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontKerning()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontKerning();
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

static PyObject* Sbk_QTextCharFormatFunc_fontLetterSpacing(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontLetterSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontLetterSpacing();
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

static PyObject* Sbk_QTextCharFormatFunc_fontOverline(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontOverline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontOverline();
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

static PyObject* Sbk_QTextCharFormatFunc_fontPointSize(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontPointSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontPointSize();
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

static PyObject* Sbk_QTextCharFormatFunc_fontStrikeOut(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontStrikeOut()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontStrikeOut();
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

static PyObject* Sbk_QTextCharFormatFunc_fontStyleHint(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontStyleHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::StyleHint cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontStyleHint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_fontStyleStrategy(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontStyleStrategy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::StyleStrategy cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontStyleStrategy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_fontUnderline(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontUnderline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontUnderline();
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

static PyObject* Sbk_QTextCharFormatFunc_fontWeight(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontWeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontWeight();
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

static PyObject* Sbk_QTextCharFormatFunc_fontWordSpacing(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontWordSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->fontWordSpacing();
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

static PyObject* Sbk_QTextCharFormatFunc_isAnchor(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAnchor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->isAnchor();
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

static PyObject* Sbk_QTextCharFormatFunc_isValid(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextCharFormatFunc_setAnchor(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnchor(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAnchor(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setAnchor_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnchor(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAnchor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setAnchor_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setAnchor", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setAnchorHref(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnchorHref(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setAnchorHref(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setAnchorHref_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnchorHref(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAnchorHref(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setAnchorHref_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setAnchorHref", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setAnchorNames(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnchorNames(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setAnchorNames(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setAnchorNames_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnchorNames(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAnchorNames(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setAnchorNames_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setAnchorNames", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontCapitalization(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontCapitalization(QFont::Capitalization)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX]), (pyArg)))) {
        overloadId = 0; // setFontCapitalization(QFont::Capitalization)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontCapitalization_TypeError;

    // Call function/method
    {
        ::QFont::Capitalization cppArg0 = ((::QFont::Capitalization)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontCapitalization(QFont::Capitalization)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontCapitalization(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontCapitalization_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.Capitalization", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontCapitalization", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontFamily(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontFamily(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFontFamily(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontFamily_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontFamily(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontFamily(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontFamily_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontFamily", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontFixedPitch(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontFixedPitch(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontFixedPitch(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontFixedPitch_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontFixedPitch(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontFixedPitch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontFixedPitch_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontFixedPitch", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontHintingPreference(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontHintingPreference(QFont::HintingPreference)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX]), (pyArg)))) {
        overloadId = 0; // setFontHintingPreference(QFont::HintingPreference)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontHintingPreference_TypeError;

    // Call function/method
    {
        ::QFont::HintingPreference cppArg0 = ((::QFont::HintingPreference)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontHintingPreference(QFont::HintingPreference)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontHintingPreference(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontHintingPreference_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.HintingPreference", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontHintingPreference", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontItalic(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontItalic(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontItalic(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontItalic_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontItalic(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontItalic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontItalic_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontItalic", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontKerning(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontKerning(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontKerning(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontKerning_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontKerning(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontKerning(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontKerning_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontKerning", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontLetterSpacing(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontLetterSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setFontLetterSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontLetterSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontLetterSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontLetterSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontLetterSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontLetterSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontOverline(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontOverline(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontOverline(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontOverline_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontOverline(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontOverline(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontOverline_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontOverline", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontPointSize(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontPointSize(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setFontPointSize(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontPointSize_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontPointSize(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontPointSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontPointSize_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontPointSize", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontStrikeOut(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontStrikeOut(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontStrikeOut(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontStrikeOut_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontStrikeOut(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontStrikeOut(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontStrikeOut_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontStrikeOut", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontStyleHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCharFormat.setFontStyleHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCharFormat.setFontStyleHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setFontStyleHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFontStyleHint(QFont::StyleHint,QFont::StyleStrategy)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setFontStyleHint(QFont::StyleHint,QFont::StyleStrategy)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setFontStyleHint(QFont::StyleHint,QFont::StyleStrategy)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontStyleHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "strategy");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTextCharFormat.setFontStyleHint(): got multiple values for keyword argument 'strategy'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArgs[1]))))
                    goto Sbk_QTextCharFormatFunc_setFontStyleHint_TypeError;
            }
        }
        ::QFont::StyleHint cppArg0 = ((::QFont::StyleHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFont::StyleStrategy cppArg1 = QFont::PreferDefault;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFontStyleHint(QFont::StyleHint,QFont::StyleStrategy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontStyleHint(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontStyleHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.StyleHint, PySide.QtGui.QFont.StyleStrategy = QFont.PreferDefault", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextCharFormat.setFontStyleHint", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontStyleStrategy(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontStyleStrategy(QFont::StyleStrategy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArg)))) {
        overloadId = 0; // setFontStyleStrategy(QFont::StyleStrategy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontStyleStrategy_TypeError;

    // Call function/method
    {
        ::QFont::StyleStrategy cppArg0 = ((::QFont::StyleStrategy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontStyleStrategy(QFont::StyleStrategy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontStyleStrategy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontStyleStrategy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.StyleStrategy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontStyleStrategy", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontUnderline(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontUnderline(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontUnderline(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontUnderline_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontUnderline(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontUnderline(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontUnderline_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontUnderline", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontWeight(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontWeight(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setFontWeight(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontWeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontWeight(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontWeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontWeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontWeight", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setFontWordSpacing(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontWordSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setFontWordSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setFontWordSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontWordSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontWordSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setFontWordSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setFontWordSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setTableCellColumnSpan(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTableCellColumnSpan(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setTableCellColumnSpan(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setTableCellColumnSpan_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTableCellColumnSpan(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTableCellColumnSpan(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setTableCellColumnSpan_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setTableCellColumnSpan", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setTableCellRowSpan(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTableCellRowSpan(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setTableCellRowSpan(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setTableCellRowSpan_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTableCellRowSpan(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTableCellRowSpan(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setTableCellRowSpan_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setTableCellRowSpan", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setTextOutline(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextOutline(QPen)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArg)))) {
        overloadId = 0; // setTextOutline(QPen)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setTextOutline_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPen cppArg0_local = ::QPen();
        ::QPen* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTextOutline(QPen)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextOutline(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setTextOutline_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPen", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setTextOutline", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setToolTip_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setToolTip(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToolTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setUnderlineColor(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUnderlineColor(QColor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 0; // setUnderlineColor(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setUnderlineColor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QColor cppArg0_local = ::QColor();
        ::QColor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setUnderlineColor(QColor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUnderlineColor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setUnderlineColor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setUnderlineColor", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setUnderlineStyle(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUnderlineStyle(QTextCharFormat::UnderlineStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setUnderlineStyle(QTextCharFormat::UnderlineStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setUnderlineStyle_TypeError;

    // Call function/method
    {
        ::QTextCharFormat::UnderlineStyle cppArg0 = ((::QTextCharFormat::UnderlineStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUnderlineStyle(QTextCharFormat::UnderlineStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUnderlineStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setUnderlineStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat.UnderlineStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setUnderlineStyle", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_setVerticalAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalAlignment(QTextCharFormat::VerticalAlignment)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX]), (pyArg)))) {
        overloadId = 0; // setVerticalAlignment(QTextCharFormat::VerticalAlignment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCharFormatFunc_setVerticalAlignment_TypeError;

    // Call function/method
    {
        ::QTextCharFormat::VerticalAlignment cppArg0 = ((::QTextCharFormat::VerticalAlignment)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalAlignment(QTextCharFormat::VerticalAlignment)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextCharFormatFunc_setVerticalAlignment_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat.VerticalAlignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextCharFormat.setVerticalAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTextCharFormatFunc_tableCellColumnSpan(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableCellColumnSpan()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->tableCellColumnSpan();
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

static PyObject* Sbk_QTextCharFormatFunc_tableCellRowSpan(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableCellRowSpan()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->tableCellRowSpan();
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

static PyObject* Sbk_QTextCharFormatFunc_textOutline(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textOutline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPen cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->textOutline();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_toolTip(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->toolTip();
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

static PyObject* Sbk_QTextCharFormatFunc_underlineColor(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underlineColor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->underlineColor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_underlineStyle(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underlineStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat::UnderlineStyle cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->underlineStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormatFunc_verticalAlignment(PyObject* self)
{
    ::QTextCharFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat::VerticalAlignment cppResult = const_cast<const ::QTextCharFormat*>(cppSelf)->verticalAlignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextCharFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextCharFormat& cppSelf = *(((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextCharFormat_methods[] = {
    {"anchorHref", (PyCFunction)Sbk_QTextCharFormatFunc_anchorHref, METH_NOARGS},
    {"anchorNames", (PyCFunction)Sbk_QTextCharFormatFunc_anchorNames, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QTextCharFormatFunc_font, METH_NOARGS},
    {"fontCapitalization", (PyCFunction)Sbk_QTextCharFormatFunc_fontCapitalization, METH_NOARGS},
    {"fontFamily", (PyCFunction)Sbk_QTextCharFormatFunc_fontFamily, METH_NOARGS},
    {"fontFixedPitch", (PyCFunction)Sbk_QTextCharFormatFunc_fontFixedPitch, METH_NOARGS},
    {"fontHintingPreference", (PyCFunction)Sbk_QTextCharFormatFunc_fontHintingPreference, METH_NOARGS},
    {"fontItalic", (PyCFunction)Sbk_QTextCharFormatFunc_fontItalic, METH_NOARGS},
    {"fontKerning", (PyCFunction)Sbk_QTextCharFormatFunc_fontKerning, METH_NOARGS},
    {"fontLetterSpacing", (PyCFunction)Sbk_QTextCharFormatFunc_fontLetterSpacing, METH_NOARGS},
    {"fontOverline", (PyCFunction)Sbk_QTextCharFormatFunc_fontOverline, METH_NOARGS},
    {"fontPointSize", (PyCFunction)Sbk_QTextCharFormatFunc_fontPointSize, METH_NOARGS},
    {"fontStrikeOut", (PyCFunction)Sbk_QTextCharFormatFunc_fontStrikeOut, METH_NOARGS},
    {"fontStyleHint", (PyCFunction)Sbk_QTextCharFormatFunc_fontStyleHint, METH_NOARGS},
    {"fontStyleStrategy", (PyCFunction)Sbk_QTextCharFormatFunc_fontStyleStrategy, METH_NOARGS},
    {"fontUnderline", (PyCFunction)Sbk_QTextCharFormatFunc_fontUnderline, METH_NOARGS},
    {"fontWeight", (PyCFunction)Sbk_QTextCharFormatFunc_fontWeight, METH_NOARGS},
    {"fontWordSpacing", (PyCFunction)Sbk_QTextCharFormatFunc_fontWordSpacing, METH_NOARGS},
    {"isAnchor", (PyCFunction)Sbk_QTextCharFormatFunc_isAnchor, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextCharFormatFunc_isValid, METH_NOARGS},
    {"setAnchor", (PyCFunction)Sbk_QTextCharFormatFunc_setAnchor, METH_O},
    {"setAnchorHref", (PyCFunction)Sbk_QTextCharFormatFunc_setAnchorHref, METH_O},
    {"setAnchorNames", (PyCFunction)Sbk_QTextCharFormatFunc_setAnchorNames, METH_O},
    {"setFont", (PyCFunction)Sbk_QTextCharFormatFunc_setFont, METH_O},
    {"setFontCapitalization", (PyCFunction)Sbk_QTextCharFormatFunc_setFontCapitalization, METH_O},
    {"setFontFamily", (PyCFunction)Sbk_QTextCharFormatFunc_setFontFamily, METH_O},
    {"setFontFixedPitch", (PyCFunction)Sbk_QTextCharFormatFunc_setFontFixedPitch, METH_O},
    {"setFontHintingPreference", (PyCFunction)Sbk_QTextCharFormatFunc_setFontHintingPreference, METH_O},
    {"setFontItalic", (PyCFunction)Sbk_QTextCharFormatFunc_setFontItalic, METH_O},
    {"setFontKerning", (PyCFunction)Sbk_QTextCharFormatFunc_setFontKerning, METH_O},
    {"setFontLetterSpacing", (PyCFunction)Sbk_QTextCharFormatFunc_setFontLetterSpacing, METH_O},
    {"setFontOverline", (PyCFunction)Sbk_QTextCharFormatFunc_setFontOverline, METH_O},
    {"setFontPointSize", (PyCFunction)Sbk_QTextCharFormatFunc_setFontPointSize, METH_O},
    {"setFontStrikeOut", (PyCFunction)Sbk_QTextCharFormatFunc_setFontStrikeOut, METH_O},
    {"setFontStyleHint", (PyCFunction)Sbk_QTextCharFormatFunc_setFontStyleHint, METH_VARARGS|METH_KEYWORDS},
    {"setFontStyleStrategy", (PyCFunction)Sbk_QTextCharFormatFunc_setFontStyleStrategy, METH_O},
    {"setFontUnderline", (PyCFunction)Sbk_QTextCharFormatFunc_setFontUnderline, METH_O},
    {"setFontWeight", (PyCFunction)Sbk_QTextCharFormatFunc_setFontWeight, METH_O},
    {"setFontWordSpacing", (PyCFunction)Sbk_QTextCharFormatFunc_setFontWordSpacing, METH_O},
    {"setTableCellColumnSpan", (PyCFunction)Sbk_QTextCharFormatFunc_setTableCellColumnSpan, METH_O},
    {"setTableCellRowSpan", (PyCFunction)Sbk_QTextCharFormatFunc_setTableCellRowSpan, METH_O},
    {"setTextOutline", (PyCFunction)Sbk_QTextCharFormatFunc_setTextOutline, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QTextCharFormatFunc_setToolTip, METH_O},
    {"setUnderlineColor", (PyCFunction)Sbk_QTextCharFormatFunc_setUnderlineColor, METH_O},
    {"setUnderlineStyle", (PyCFunction)Sbk_QTextCharFormatFunc_setUnderlineStyle, METH_O},
    {"setVerticalAlignment", (PyCFunction)Sbk_QTextCharFormatFunc_setVerticalAlignment, METH_O},
    {"tableCellColumnSpan", (PyCFunction)Sbk_QTextCharFormatFunc_tableCellColumnSpan, METH_NOARGS},
    {"tableCellRowSpan", (PyCFunction)Sbk_QTextCharFormatFunc_tableCellRowSpan, METH_NOARGS},
    {"textOutline", (PyCFunction)Sbk_QTextCharFormatFunc_textOutline, METH_NOARGS},
    {"toolTip", (PyCFunction)Sbk_QTextCharFormatFunc_toolTip, METH_NOARGS},
    {"underlineColor", (PyCFunction)Sbk_QTextCharFormatFunc_underlineColor, METH_NOARGS},
    {"underlineStyle", (PyCFunction)Sbk_QTextCharFormatFunc_underlineStyle, METH_NOARGS},
    {"verticalAlignment", (PyCFunction)Sbk_QTextCharFormatFunc_verticalAlignment, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextCharFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextCharFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextCharFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextCharFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextCharFormat",
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
    /*tp_traverse*/         Sbk_QTextCharFormat_traverse,
    /*tp_clear*/            Sbk_QTextCharFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextCharFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextCharFormat_Init,
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
static void QTextCharFormat_VerticalAlignment_PythonToCpp_QTextCharFormat_VerticalAlignment(PyObject* pyIn, void* cppOut) {
    *((::QTextCharFormat::VerticalAlignment*)cppOut) = (::QTextCharFormat::VerticalAlignment) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCharFormat_VerticalAlignment_PythonToCpp_QTextCharFormat_VerticalAlignment_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX]))
        return QTextCharFormat_VerticalAlignment_PythonToCpp_QTextCharFormat_VerticalAlignment;
    return 0;
}
static PyObject* QTextCharFormat_VerticalAlignment_CppToPython_QTextCharFormat_VerticalAlignment(const void* cppIn) {
    int castCppIn = *((::QTextCharFormat::VerticalAlignment*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX], castCppIn);

}

static void QTextCharFormat_UnderlineStyle_PythonToCpp_QTextCharFormat_UnderlineStyle(PyObject* pyIn, void* cppOut) {
    *((::QTextCharFormat::UnderlineStyle*)cppOut) = (::QTextCharFormat::UnderlineStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextCharFormat_UnderlineStyle_PythonToCpp_QTextCharFormat_UnderlineStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX]))
        return QTextCharFormat_UnderlineStyle_PythonToCpp_QTextCharFormat_UnderlineStyle;
    return 0;
}
static PyObject* QTextCharFormat_UnderlineStyle_CppToPython_QTextCharFormat_UnderlineStyle(const void* cppIn) {
    int castCppIn = *((::QTextCharFormat::UnderlineStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextCharFormat_PythonToCpp_QTextCharFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextCharFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextCharFormat_PythonToCpp_QTextCharFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCharFormat_Type))
        return QTextCharFormat_PythonToCpp_QTextCharFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextCharFormat_PTR_CppToPython_QTextCharFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextCharFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextCharFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextCharFormat_COPY_CppToPython_QTextCharFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextCharFormat_Type, new ::QTextCharFormat(*((::QTextCharFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextCharFormat_PythonToCpp_QTextCharFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextCharFormat*)cppOut) = *((::QTextCharFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextCharFormat_PythonToCpp_QTextCharFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCharFormat_Type))
        return QTextCharFormat_PythonToCpp_QTextCharFormat_COPY;
    return 0;
}

void init_QTextCharFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextCharFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextCharFormat", "QTextCharFormat",
        &Sbk_QTextCharFormat_Type, &Shiboken::callCppDestructor< ::QTextCharFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextCharFormat_Type,
        QTextCharFormat_PythonToCpp_QTextCharFormat_PTR,
        is_QTextCharFormat_PythonToCpp_QTextCharFormat_PTR_Convertible,
        QTextCharFormat_PTR_CppToPython_QTextCharFormat,
        QTextCharFormat_COPY_CppToPython_QTextCharFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextCharFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextCharFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextCharFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextCharFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextCharFormat_PythonToCpp_QTextCharFormat_COPY,
        is_QTextCharFormat_PythonToCpp_QTextCharFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'VerticalAlignment'.
    SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCharFormat_Type,
        "VerticalAlignment",
        "PySide.QtGui.QTextCharFormat.VerticalAlignment",
        "QTextCharFormat::VerticalAlignment");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignNormal", (long) QTextCharFormat::AlignNormal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignSuperScript", (long) QTextCharFormat::AlignSuperScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignSubScript", (long) QTextCharFormat::AlignSubScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignMiddle", (long) QTextCharFormat::AlignMiddle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignTop", (long) QTextCharFormat::AlignTop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignBottom", (long) QTextCharFormat::AlignBottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
        &Sbk_QTextCharFormat_Type, "AlignBaseline", (long) QTextCharFormat::AlignBaseline))
        return ;
    // Register converter for enum 'QTextCharFormat::VerticalAlignment'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX],
            QTextCharFormat_VerticalAlignment_CppToPython_QTextCharFormat_VerticalAlignment);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCharFormat_VerticalAlignment_PythonToCpp_QTextCharFormat_VerticalAlignment,
            is_QTextCharFormat_VerticalAlignment_PythonToCpp_QTextCharFormat_VerticalAlignment_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCharFormat::VerticalAlignment");
        Shiboken::Conversions::registerConverterName(converter, "VerticalAlignment");
    }
    // End of 'VerticalAlignment' enum.

    // Initialization of enum 'UnderlineStyle'.
    SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextCharFormat_Type,
        "UnderlineStyle",
        "PySide.QtGui.QTextCharFormat.UnderlineStyle",
        "QTextCharFormat::UnderlineStyle");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "NoUnderline", (long) QTextCharFormat::NoUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "SingleUnderline", (long) QTextCharFormat::SingleUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "DashUnderline", (long) QTextCharFormat::DashUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "DotLine", (long) QTextCharFormat::DotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "DashDotLine", (long) QTextCharFormat::DashDotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "DashDotDotLine", (long) QTextCharFormat::DashDotDotLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "WaveUnderline", (long) QTextCharFormat::WaveUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
        &Sbk_QTextCharFormat_Type, "SpellCheckUnderline", (long) QTextCharFormat::SpellCheckUnderline))
        return ;
    // Register converter for enum 'QTextCharFormat::UnderlineStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX],
            QTextCharFormat_UnderlineStyle_CppToPython_QTextCharFormat_UnderlineStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextCharFormat_UnderlineStyle_PythonToCpp_QTextCharFormat_UnderlineStyle,
            is_QTextCharFormat_UnderlineStyle_PythonToCpp_QTextCharFormat_UnderlineStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextCharFormat::UnderlineStyle");
        Shiboken::Conversions::registerConverterName(converter, "UnderlineStyle");
    }
    // End of 'UnderlineStyle' enum.


    qRegisterMetaType< ::QTextCharFormat >("QTextCharFormat");
    qRegisterMetaType< ::QTextCharFormat::VerticalAlignment >("QTextCharFormat::VerticalAlignment");
    qRegisterMetaType< ::QTextCharFormat::UnderlineStyle >("QTextCharFormat::UnderlineStyle");
}
