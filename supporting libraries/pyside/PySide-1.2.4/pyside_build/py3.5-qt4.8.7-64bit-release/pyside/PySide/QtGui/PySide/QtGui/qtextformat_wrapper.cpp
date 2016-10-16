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

#include "qtextformat_wrapper.h"

// Extra includes
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qdatastream.h>
#include <qpen.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextFormat >()))
        return -1;

    ::QTextFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextFormat()
    // 1: QTextFormat(QTextFormat)
    // 2: QTextFormat(int)
    if (numArgs == 0) {
        overloadId = 0; // QTextFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QTextFormat(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextFormat(const QTextFormat & rhs)
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
                // QTextFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextFormat(int type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextFormat(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextFormat(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextFormat", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextFormatFunc_background(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // background()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTextFormat*>(cppSelf)->background();
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

static PyObject* Sbk_QTextFormatFunc_boolProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boolProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // boolProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_boolProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // boolProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->boolProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_boolProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.boolProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_brushProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: brushProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // brushProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_brushProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // brushProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTextFormat*>(cppSelf)->brushProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_brushProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.brushProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_clearBackground(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearBackground()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearBackground();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextFormatFunc_clearForeground(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearForeground()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearForeground();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextFormatFunc_clearProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: clearProperty(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // clearProperty(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_clearProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // clearProperty(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_clearProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.clearProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_colorProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: colorProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // colorProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_colorProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // colorProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QTextFormat*>(cppSelf)->colorProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_colorProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.colorProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_doubleProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: doubleProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // doubleProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_doubleProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // doubleProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextFormat*>(cppSelf)->doubleProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_doubleProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.doubleProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_foreground(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // foreground()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTextFormat*>(cppSelf)->foreground();
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

static PyObject* Sbk_QTextFormatFunc_hasProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // hasProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_hasProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->hasProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_hasProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.hasProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_intProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // intProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_intProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // intProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextFormat*>(cppSelf)->intProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_intProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.intProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_isBlockFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBlockFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isBlockFormat();
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

static PyObject* Sbk_QTextFormatFunc_isCharFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCharFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isCharFormat();
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

static PyObject* Sbk_QTextFormatFunc_isFrameFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFrameFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isFrameFormat();
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

static PyObject* Sbk_QTextFormatFunc_isImageFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isImageFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isImageFormat();
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

static PyObject* Sbk_QTextFormatFunc_isListFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isListFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isListFormat();
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

static PyObject* Sbk_QTextFormatFunc_isTableCellFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isTableCellFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isTableCellFormat();
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

static PyObject* Sbk_QTextFormatFunc_isTableFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isTableFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isTableFormat();
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

static PyObject* Sbk_QTextFormatFunc_isValid(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextFormatFunc_layoutDirection(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // layoutDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QTextFormat*>(cppSelf)->layoutDirection();
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

static PyObject* Sbk_QTextFormatFunc_lengthProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: lengthProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // lengthProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_lengthProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // lengthProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextLength cppResult = const_cast<const ::QTextFormat*>(cppSelf)->lengthProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_lengthProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.lengthProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_lengthVectorProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: lengthVectorProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // lengthVectorProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_lengthVectorProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // lengthVectorProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QTextLength > cppResult = const_cast<const ::QTextFormat*>(cppSelf)->lengthVectorProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_lengthVectorProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.lengthVectorProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_merge(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: merge(QTextFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // merge(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_merge_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextFormat cppArg0_local = ::QTextFormat();
        ::QTextFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // merge(QTextFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->merge(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_merge_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.merge", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_objectIndex(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // objectIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextFormat*>(cppSelf)->objectIndex();
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

static PyObject* Sbk_QTextFormatFunc_objectType(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // objectType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextFormat*>(cppSelf)->objectType();
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

static PyObject* Sbk_QTextFormatFunc_penProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: penProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // penProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_penProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // penProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPen cppResult = const_cast<const ::QTextFormat*>(cppSelf)->penProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_penProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.penProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_properties(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // properties()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMap<int, QVariant > cppResult = const_cast<const ::QTextFormat*>(cppSelf)->properties();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QMAP_INT_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // property(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_property_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QTextFormat*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_property_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.property", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_propertyCount(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextFormat*>(cppSelf)->propertyCount();
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

static PyObject* Sbk_QTextFormatFunc_setBackground(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setBackground_TypeError;

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
            // setBackground(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackground(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.setBackground", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_setForeground(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForeground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setForeground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setForeground_TypeError;

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
            // setForeground(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForeground(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setForeground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.setForeground", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_setLayoutDirection(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLayoutDirection(Qt::LayoutDirection)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setLayoutDirection(Qt::LayoutDirection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setLayoutDirection_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLayoutDirection(Qt::LayoutDirection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLayoutDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setLayoutDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.setLayoutDirection", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_setObjectIndex(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setObjectIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setObjectIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setObjectIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setObjectIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setObjectIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setObjectIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.setObjectIndex", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_setObjectType(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setObjectType(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setObjectType(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setObjectType_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setObjectType(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setObjectType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setObjectType_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.setObjectType", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(int,QVariant)
    // 1: setProperty(int,QVector<QTextLength>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX], (pyArgs[1])))) {
            overloadId = 1; // setProperty(int,QVector<QTextLength>)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 0; // setProperty(int,QVariant)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_setProperty_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setProperty(int propertyId, const QVariant & value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setProperty(int,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setProperty(int propertyId, const QVector<QTextLength > & lengths)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVector<QTextLength > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setProperty(int,QVector<QTextLength>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setProperty(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextFormatFunc_setProperty_TypeError:
        const char* overloads[] = {"int, QVariant", "int, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextFormat.setProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_stringProperty(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stringProperty(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // stringProperty(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc_stringProperty_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // stringProperty(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextFormat*>(cppSelf)->stringProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc_stringProperty_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.stringProperty", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc_toBlockFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toBlockFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlockFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toBlockFormat();
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

static PyObject* Sbk_QTextFormatFunc_toCharFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toCharFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toCharFormat();
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

static PyObject* Sbk_QTextFormatFunc_toFrameFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toFrameFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFrameFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toFrameFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_toImageFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toImageFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextImageFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toImageFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTIMAGEFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_toListFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toListFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextListFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toListFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_toTableCellFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTableCellFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextTableCellFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toTableCellFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_toTableFormat(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTableFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextTableFormat cppResult = const_cast<const ::QTextFormat*>(cppSelf)->toTableFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextFormatFunc_type(PyObject* self)
{
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextFormat*>(cppSelf)->type();
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

static PyObject* Sbk_QTextFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextFormat& cppSelf = *(((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextFormat_methods[] = {
    {"background", (PyCFunction)Sbk_QTextFormatFunc_background, METH_NOARGS},
    {"boolProperty", (PyCFunction)Sbk_QTextFormatFunc_boolProperty, METH_O},
    {"brushProperty", (PyCFunction)Sbk_QTextFormatFunc_brushProperty, METH_O},
    {"clearBackground", (PyCFunction)Sbk_QTextFormatFunc_clearBackground, METH_NOARGS},
    {"clearForeground", (PyCFunction)Sbk_QTextFormatFunc_clearForeground, METH_NOARGS},
    {"clearProperty", (PyCFunction)Sbk_QTextFormatFunc_clearProperty, METH_O},
    {"colorProperty", (PyCFunction)Sbk_QTextFormatFunc_colorProperty, METH_O},
    {"doubleProperty", (PyCFunction)Sbk_QTextFormatFunc_doubleProperty, METH_O},
    {"foreground", (PyCFunction)Sbk_QTextFormatFunc_foreground, METH_NOARGS},
    {"hasProperty", (PyCFunction)Sbk_QTextFormatFunc_hasProperty, METH_O},
    {"intProperty", (PyCFunction)Sbk_QTextFormatFunc_intProperty, METH_O},
    {"isBlockFormat", (PyCFunction)Sbk_QTextFormatFunc_isBlockFormat, METH_NOARGS},
    {"isCharFormat", (PyCFunction)Sbk_QTextFormatFunc_isCharFormat, METH_NOARGS},
    {"isFrameFormat", (PyCFunction)Sbk_QTextFormatFunc_isFrameFormat, METH_NOARGS},
    {"isImageFormat", (PyCFunction)Sbk_QTextFormatFunc_isImageFormat, METH_NOARGS},
    {"isListFormat", (PyCFunction)Sbk_QTextFormatFunc_isListFormat, METH_NOARGS},
    {"isTableCellFormat", (PyCFunction)Sbk_QTextFormatFunc_isTableCellFormat, METH_NOARGS},
    {"isTableFormat", (PyCFunction)Sbk_QTextFormatFunc_isTableFormat, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextFormatFunc_isValid, METH_NOARGS},
    {"layoutDirection", (PyCFunction)Sbk_QTextFormatFunc_layoutDirection, METH_NOARGS},
    {"lengthProperty", (PyCFunction)Sbk_QTextFormatFunc_lengthProperty, METH_O},
    {"lengthVectorProperty", (PyCFunction)Sbk_QTextFormatFunc_lengthVectorProperty, METH_O},
    {"merge", (PyCFunction)Sbk_QTextFormatFunc_merge, METH_O},
    {"objectIndex", (PyCFunction)Sbk_QTextFormatFunc_objectIndex, METH_NOARGS},
    {"objectType", (PyCFunction)Sbk_QTextFormatFunc_objectType, METH_NOARGS},
    {"penProperty", (PyCFunction)Sbk_QTextFormatFunc_penProperty, METH_O},
    {"properties", (PyCFunction)Sbk_QTextFormatFunc_properties, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QTextFormatFunc_property, METH_O},
    {"propertyCount", (PyCFunction)Sbk_QTextFormatFunc_propertyCount, METH_NOARGS},
    {"setBackground", (PyCFunction)Sbk_QTextFormatFunc_setBackground, METH_O},
    {"setForeground", (PyCFunction)Sbk_QTextFormatFunc_setForeground, METH_O},
    {"setLayoutDirection", (PyCFunction)Sbk_QTextFormatFunc_setLayoutDirection, METH_O},
    {"setObjectIndex", (PyCFunction)Sbk_QTextFormatFunc_setObjectIndex, METH_O},
    {"setObjectType", (PyCFunction)Sbk_QTextFormatFunc_setObjectType, METH_O},
    {"setProperty", (PyCFunction)Sbk_QTextFormatFunc_setProperty, METH_VARARGS},
    {"stringProperty", (PyCFunction)Sbk_QTextFormatFunc_stringProperty, METH_O},
    {"toBlockFormat", (PyCFunction)Sbk_QTextFormatFunc_toBlockFormat, METH_NOARGS},
    {"toCharFormat", (PyCFunction)Sbk_QTextFormatFunc_toCharFormat, METH_NOARGS},
    {"toFrameFormat", (PyCFunction)Sbk_QTextFormatFunc_toFrameFormat, METH_NOARGS},
    {"toImageFormat", (PyCFunction)Sbk_QTextFormatFunc_toImageFormat, METH_NOARGS},
    {"toListFormat", (PyCFunction)Sbk_QTextFormatFunc_toListFormat, METH_NOARGS},
    {"toTableCellFormat", (PyCFunction)Sbk_QTextFormatFunc_toTableCellFormat, METH_NOARGS},
    {"toTableFormat", (PyCFunction)Sbk_QTextFormatFunc_toTableFormat, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QTextFormatFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTextFormatFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QTextFormat)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QTextFormat)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QTextFormat) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QTextFormatFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QTextFormat&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QTextFormat&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextFormatFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QTextFormat&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextFormatFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextFormat.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QTextFormat_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextFormat& cppSelf = *(((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArg)))) {
                // operator!=(const QTextFormat & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextFormat cppArg0_local = ::QTextFormat();
                ::QTextFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArg)))) {
                // operator==(const QTextFormat & rhs) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextFormat cppArg0_local = ::QTextFormat();
                ::QTextFormat* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp))
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
            goto Sbk_QTextFormat_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextFormat_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTextFormat_TypeAsNumber;

static SbkObjectType Sbk_QTextFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextFormat",
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
    /*tp_traverse*/         Sbk_QTextFormat_traverse,
    /*tp_clear*/            Sbk_QTextFormat_clear,
    /*tp_richcompare*/      Sbk_QTextFormat_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextFormat_Init,
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

PyObject* SbkPySide_QtGui_QTextFormat_PageBreakFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat::PageBreakFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextFormat::PageBreakFlags)PyLong_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextFormat::PageBreakFlags)PyInt_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextFormat_PageBreakFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat::PageBreakFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextFormat::PageBreakFlags)PyLong_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextFormat::PageBreakFlags)PyInt_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextFormat_PageBreakFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat::PageBreakFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextFormat::PageBreakFlags)PyLong_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextFormat::PageBreakFlags)PyInt_AsLong(self);
    cppArg = (QTextFormat::PageBreakFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTextFormat_PageBreakFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextFormat::PageBreakFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), self, &cppSelf);
    ::QTextFormat::PageBreakFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QTextFormat_PageBreakFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QTextFormat_PageBreakFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QTextFormat_PageBreakFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QTextFormat_PageBreakFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QTextFormat_PageBreakFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QTextFormat_PageBreakFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QTextFormat_PageBreakFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QTextFormat_PageBreakFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QTextFormat_PageBreakFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QTextFormat_PageBreakFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QTextFormat_FormatType_PythonToCpp_QTextFormat_FormatType(PyObject* pyIn, void* cppOut) {
    *((::QTextFormat::FormatType*)cppOut) = (::QTextFormat::FormatType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFormat_FormatType_PythonToCpp_QTextFormat_FormatType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX]))
        return QTextFormat_FormatType_PythonToCpp_QTextFormat_FormatType;
    return 0;
}
static PyObject* QTextFormat_FormatType_CppToPython_QTextFormat_FormatType(const void* cppIn) {
    int castCppIn = *((::QTextFormat::FormatType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX], castCppIn);

}

static void QTextFormat_Property_PythonToCpp_QTextFormat_Property(PyObject* pyIn, void* cppOut) {
    *((::QTextFormat::Property*)cppOut) = (::QTextFormat::Property) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFormat_Property_PythonToCpp_QTextFormat_Property_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX]))
        return QTextFormat_Property_PythonToCpp_QTextFormat_Property;
    return 0;
}
static PyObject* QTextFormat_Property_CppToPython_QTextFormat_Property(const void* cppIn) {
    int castCppIn = *((::QTextFormat::Property*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX], castCppIn);

}

static void QTextFormat_ObjectTypes_PythonToCpp_QTextFormat_ObjectTypes(PyObject* pyIn, void* cppOut) {
    *((::QTextFormat::ObjectTypes*)cppOut) = (::QTextFormat::ObjectTypes) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFormat_ObjectTypes_PythonToCpp_QTextFormat_ObjectTypes_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX]))
        return QTextFormat_ObjectTypes_PythonToCpp_QTextFormat_ObjectTypes;
    return 0;
}
static PyObject* QTextFormat_ObjectTypes_CppToPython_QTextFormat_ObjectTypes(const void* cppIn) {
    int castCppIn = *((::QTextFormat::ObjectTypes*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX], castCppIn);

}

static void QTextFormat_PageBreakFlag_PythonToCpp_QTextFormat_PageBreakFlag(PyObject* pyIn, void* cppOut) {
    *((::QTextFormat::PageBreakFlag*)cppOut) = (::QTextFormat::PageBreakFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextFormat_PageBreakFlag_PythonToCpp_QTextFormat_PageBreakFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX]))
        return QTextFormat_PageBreakFlag_PythonToCpp_QTextFormat_PageBreakFlag;
    return 0;
}
static PyObject* QTextFormat_PageBreakFlag_CppToPython_QTextFormat_PageBreakFlag(const void* cppIn) {
    int castCppIn = *((::QTextFormat::PageBreakFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX], castCppIn);

}

static void QFlags_QTextFormat_PageBreakFlag__PythonToCpp_QFlags_QTextFormat_PageBreakFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextFormat::PageBreakFlag>*)cppOut) = ::QFlags<QTextFormat::PageBreakFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextFormat_PageBreakFlag__PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]))
        return QFlags_QTextFormat_PageBreakFlag__PythonToCpp_QFlags_QTextFormat_PageBreakFlag_;
    return 0;
}
static PyObject* QFlags_QTextFormat_PageBreakFlag__CppToPython_QFlags_QTextFormat_PageBreakFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextFormat::PageBreakFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]));

}

static void QTextFormat_PageBreakFlag_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextFormat::PageBreakFlag>*)cppOut) = ::QFlags<QTextFormat::PageBreakFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextFormat_PageBreakFlag_PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX]))
        return QTextFormat_PageBreakFlag_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextFormat::PageBreakFlag>*)cppOut) = ::QFlags<QTextFormat::PageBreakFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextFormat_PythonToCpp_QTextFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextFormat_PythonToCpp_QTextFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextFormat_Type))
        return QTextFormat_PythonToCpp_QTextFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextFormat_PTR_CppToPython_QTextFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextFormat_COPY_CppToPython_QTextFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextFormat_Type, new ::QTextFormat(*((::QTextFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextFormat_PythonToCpp_QTextFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextFormat*)cppOut) = *((::QTextFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextFormat_PythonToCpp_QTextFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextFormat_Type))
        return QTextFormat_PythonToCpp_QTextFormat_COPY;
    return 0;
}

void init_QTextFormat(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTextFormat_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTextFormat_TypeAsNumber.nb_rshift = Sbk_QTextFormatFunc___rshift__;
    Sbk_QTextFormat_TypeAsNumber.nb_lshift = Sbk_QTextFormatFunc___lshift__;
    Sbk_QTextFormat_Type.super.ht_type.tp_as_number = &Sbk_QTextFormat_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextFormat", "QTextFormat",
        &Sbk_QTextFormat_Type, &Shiboken::callCppDestructor< ::QTextFormat >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextFormat_Type,
        QTextFormat_PythonToCpp_QTextFormat_PTR,
        is_QTextFormat_PythonToCpp_QTextFormat_PTR_Convertible,
        QTextFormat_PTR_CppToPython_QTextFormat,
        QTextFormat_COPY_CppToPython_QTextFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextFormat_PythonToCpp_QTextFormat_COPY,
        is_QTextFormat_PythonToCpp_QTextFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'FormatType'.
    SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFormat_Type,
        "FormatType",
        "PySide.QtGui.QTextFormat.FormatType",
        "QTextFormat::FormatType");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "InvalidFormat", (long) QTextFormat::InvalidFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "BlockFormat", (long) QTextFormat::BlockFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "CharFormat", (long) QTextFormat::CharFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "ListFormat", (long) QTextFormat::ListFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "TableFormat", (long) QTextFormat::TableFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "FrameFormat", (long) QTextFormat::FrameFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
        &Sbk_QTextFormat_Type, "UserFormat", (long) QTextFormat::UserFormat))
        return ;
    // Register converter for enum 'QTextFormat::FormatType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX],
            QTextFormat_FormatType_CppToPython_QTextFormat_FormatType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFormat_FormatType_PythonToCpp_QTextFormat_FormatType,
            is_QTextFormat_FormatType_PythonToCpp_QTextFormat_FormatType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFormat::FormatType");
        Shiboken::Conversions::registerConverterName(converter, "FormatType");
    }
    // End of 'FormatType' enum.

    // Initialization of enum 'Property'.
    SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFormat_Type,
        "Property",
        "PySide.QtGui.QTextFormat.Property",
        "QTextFormat::Property");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ObjectIndex", (long) QTextFormat::ObjectIndex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "CssFloat", (long) QTextFormat::CssFloat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "LayoutDirection", (long) QTextFormat::LayoutDirection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "OutlinePen", (long) QTextFormat::OutlinePen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BackgroundBrush", (long) QTextFormat::BackgroundBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ForegroundBrush", (long) QTextFormat::ForegroundBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BackgroundImageUrl", (long) QTextFormat::BackgroundImageUrl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockAlignment", (long) QTextFormat::BlockAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockTopMargin", (long) QTextFormat::BlockTopMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockBottomMargin", (long) QTextFormat::BlockBottomMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockLeftMargin", (long) QTextFormat::BlockLeftMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockRightMargin", (long) QTextFormat::BlockRightMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextIndent", (long) QTextFormat::TextIndent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TabPositions", (long) QTextFormat::TabPositions))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockIndent", (long) QTextFormat::BlockIndent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "LineHeight", (long) QTextFormat::LineHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "LineHeightType", (long) QTextFormat::LineHeightType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockNonBreakableLines", (long) QTextFormat::BlockNonBreakableLines))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "BlockTrailingHorizontalRulerWidth", (long) QTextFormat::BlockTrailingHorizontalRulerWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FirstFontProperty", (long) QTextFormat::FirstFontProperty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontCapitalization", (long) QTextFormat::FontCapitalization))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontLetterSpacing", (long) QTextFormat::FontLetterSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontWordSpacing", (long) QTextFormat::FontWordSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontStyleHint", (long) QTextFormat::FontStyleHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontStyleStrategy", (long) QTextFormat::FontStyleStrategy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontKerning", (long) QTextFormat::FontKerning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontHintingPreference", (long) QTextFormat::FontHintingPreference))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontFamily", (long) QTextFormat::FontFamily))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontPointSize", (long) QTextFormat::FontPointSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontSizeAdjustment", (long) QTextFormat::FontSizeAdjustment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontSizeIncrement", (long) QTextFormat::FontSizeIncrement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontWeight", (long) QTextFormat::FontWeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontItalic", (long) QTextFormat::FontItalic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontUnderline", (long) QTextFormat::FontUnderline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontOverline", (long) QTextFormat::FontOverline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontStrikeOut", (long) QTextFormat::FontStrikeOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontFixedPitch", (long) QTextFormat::FontFixedPitch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FontPixelSize", (long) QTextFormat::FontPixelSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "LastFontProperty", (long) QTextFormat::LastFontProperty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextUnderlineColor", (long) QTextFormat::TextUnderlineColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextVerticalAlignment", (long) QTextFormat::TextVerticalAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextOutline", (long) QTextFormat::TextOutline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextUnderlineStyle", (long) QTextFormat::TextUnderlineStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TextToolTip", (long) QTextFormat::TextToolTip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "IsAnchor", (long) QTextFormat::IsAnchor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "AnchorHref", (long) QTextFormat::AnchorHref))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "AnchorName", (long) QTextFormat::AnchorName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ObjectType", (long) QTextFormat::ObjectType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ListStyle", (long) QTextFormat::ListStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ListIndent", (long) QTextFormat::ListIndent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ListNumberPrefix", (long) QTextFormat::ListNumberPrefix))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ListNumberSuffix", (long) QTextFormat::ListNumberSuffix))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameBorder", (long) QTextFormat::FrameBorder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameMargin", (long) QTextFormat::FrameMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FramePadding", (long) QTextFormat::FramePadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameWidth", (long) QTextFormat::FrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameHeight", (long) QTextFormat::FrameHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameTopMargin", (long) QTextFormat::FrameTopMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameBottomMargin", (long) QTextFormat::FrameBottomMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameLeftMargin", (long) QTextFormat::FrameLeftMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameRightMargin", (long) QTextFormat::FrameRightMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameBorderBrush", (long) QTextFormat::FrameBorderBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FrameBorderStyle", (long) QTextFormat::FrameBorderStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableColumns", (long) QTextFormat::TableColumns))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableColumnWidthConstraints", (long) QTextFormat::TableColumnWidthConstraints))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellSpacing", (long) QTextFormat::TableCellSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellPadding", (long) QTextFormat::TableCellPadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableHeaderRowCount", (long) QTextFormat::TableHeaderRowCount))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellRowSpan", (long) QTextFormat::TableCellRowSpan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellColumnSpan", (long) QTextFormat::TableCellColumnSpan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellTopPadding", (long) QTextFormat::TableCellTopPadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellBottomPadding", (long) QTextFormat::TableCellBottomPadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellLeftPadding", (long) QTextFormat::TableCellLeftPadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "TableCellRightPadding", (long) QTextFormat::TableCellRightPadding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ImageName", (long) QTextFormat::ImageName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ImageWidth", (long) QTextFormat::ImageWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "ImageHeight", (long) QTextFormat::ImageHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "FullWidthSelection", (long) QTextFormat::FullWidthSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "PageBreakPolicy", (long) QTextFormat::PageBreakPolicy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
        &Sbk_QTextFormat_Type, "UserProperty", (long) QTextFormat::UserProperty))
        return ;
    // Register converter for enum 'QTextFormat::Property'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX],
            QTextFormat_Property_CppToPython_QTextFormat_Property);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFormat_Property_PythonToCpp_QTextFormat_Property,
            is_QTextFormat_Property_PythonToCpp_QTextFormat_Property_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFormat::Property");
        Shiboken::Conversions::registerConverterName(converter, "Property");
    }
    // End of 'Property' enum.

    // Initialization of enum 'ObjectTypes'.
    SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFormat_Type,
        "ObjectTypes",
        "PySide.QtGui.QTextFormat.ObjectTypes",
        "QTextFormat::ObjectTypes");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
        &Sbk_QTextFormat_Type, "NoObject", (long) QTextFormat::NoObject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
        &Sbk_QTextFormat_Type, "ImageObject", (long) QTextFormat::ImageObject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
        &Sbk_QTextFormat_Type, "TableObject", (long) QTextFormat::TableObject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
        &Sbk_QTextFormat_Type, "TableCellObject", (long) QTextFormat::TableCellObject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
        &Sbk_QTextFormat_Type, "UserObject", (long) QTextFormat::UserObject))
        return ;
    // Register converter for enum 'QTextFormat::ObjectTypes'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX],
            QTextFormat_ObjectTypes_CppToPython_QTextFormat_ObjectTypes);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFormat_ObjectTypes_PythonToCpp_QTextFormat_ObjectTypes,
            is_QTextFormat_ObjectTypes_PythonToCpp_QTextFormat_ObjectTypes_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFormat::ObjectTypes");
        Shiboken::Conversions::registerConverterName(converter, "ObjectTypes");
    }
    // End of 'ObjectTypes' enum.

    // Initialization of enum 'PageBreakFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX] = PySide::QFlags::create("PageBreakFlags", &SbkPySide_QtGui_QTextFormat_PageBreakFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextFormat_Type,
        "PageBreakFlag",
        "PySide.QtGui.QTextFormat.PageBreakFlag",
        "QTextFormat::PageBreakFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX],
        &Sbk_QTextFormat_Type, "PageBreak_Auto", (long) QTextFormat::PageBreak_Auto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX],
        &Sbk_QTextFormat_Type, "PageBreak_AlwaysBefore", (long) QTextFormat::PageBreak_AlwaysBefore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX],
        &Sbk_QTextFormat_Type, "PageBreak_AlwaysAfter", (long) QTextFormat::PageBreak_AlwaysAfter))
        return ;
    // Register converter for enum 'QTextFormat::PageBreakFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX],
            QTextFormat_PageBreakFlag_CppToPython_QTextFormat_PageBreakFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFormat_PageBreakFlag_PythonToCpp_QTextFormat_PageBreakFlag,
            is_QTextFormat_PageBreakFlag_PythonToCpp_QTextFormat_PageBreakFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextFormat::PageBreakFlag");
        Shiboken::Conversions::registerConverterName(converter, "PageBreakFlag");
    }
    // Register converter for flag 'QFlags<QTextFormat::PageBreakFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX],
            QFlags_QTextFormat_PageBreakFlag__CppToPython_QFlags_QTextFormat_PageBreakFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextFormat_PageBreakFlag_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_,
            is_QTextFormat_PageBreakFlag_PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextFormat_PageBreakFlag__PythonToCpp_QFlags_QTextFormat_PageBreakFlag_,
            is_QFlags_QTextFormat_PageBreakFlag__PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextFormat_PageBreakFlag_,
            is_number_PythonToCpp_QFlags_QTextFormat_PageBreakFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextFormat::PageBreakFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<PageBreakFlag>");
    }
    // End of 'PageBreakFlag' enum/flags.


    qRegisterMetaType< ::QTextFormat >("QTextFormat");
    qRegisterMetaType< ::QTextFormat::FormatType >("QTextFormat::FormatType");
    qRegisterMetaType< ::QTextFormat::Property >("QTextFormat::Property");
    qRegisterMetaType< ::QTextFormat::ObjectTypes >("QTextFormat::ObjectTypes");
    qRegisterMetaType< ::QTextFormat::PageBreakFlag >("QTextFormat::PageBreakFlag");
    qRegisterMetaType< ::QTextFormat::PageBreakFlags >("QTextFormat::PageBreakFlags");
}
