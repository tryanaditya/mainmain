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

#include "qfontinfo_wrapper.h"

// Extra includes
#include <qfont.h>
#include <qfontinfo.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFontInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFontInfo >()))
        return -1;

    ::QFontInfo* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFontInfo", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFontInfo(QFont)
    // 1: QFontInfo(QFontInfo)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QFontInfo(QFont)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (pyArgs[0])))) {
        overloadId = 1; // QFontInfo(QFontInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontInfo_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFontInfo(const QFont & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFont cppArg0_local = ::QFont();
            ::QFont* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFontInfo(QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFontInfo(const QFontInfo & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFontInfo cppArg0_local = ::QFontInfo(::QFont());
            ::QFontInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFontInfo(QFontInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontInfo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFontInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFontInfo_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFontInfo_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", "PySide.QtGui.QFontInfo", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontInfo", overloads);
        return -1;
}

static PyObject* Sbk_QFontInfoFunc_bold(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bold()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->bold();
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

static PyObject* Sbk_QFontInfoFunc_exactMatch(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exactMatch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->exactMatch();
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

static PyObject* Sbk_QFontInfoFunc_family(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // family()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFontInfo*>(cppSelf)->family();
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

static PyObject* Sbk_QFontInfoFunc_fixedPitch(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fixedPitch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->fixedPitch();
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

static PyObject* Sbk_QFontInfoFunc_italic(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // italic()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->italic();
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

static PyObject* Sbk_QFontInfoFunc_overline(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->overline();
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

static PyObject* Sbk_QFontInfoFunc_pixelSize(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixelSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontInfo*>(cppSelf)->pixelSize();
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

static PyObject* Sbk_QFontInfoFunc_pointSize(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pointSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontInfo*>(cppSelf)->pointSize();
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

static PyObject* Sbk_QFontInfoFunc_pointSizeF(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pointSizeF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontInfo*>(cppSelf)->pointSizeF();
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

static PyObject* Sbk_QFontInfoFunc_rawMode(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->rawMode();
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

static PyObject* Sbk_QFontInfoFunc_strikeOut(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // strikeOut()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->strikeOut();
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

static PyObject* Sbk_QFontInfoFunc_style(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::Style cppResult = const_cast<const ::QFontInfo*>(cppSelf)->style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFontInfoFunc_styleHint(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::StyleHint cppResult = const_cast<const ::QFontInfo*>(cppSelf)->styleHint();
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

static PyObject* Sbk_QFontInfoFunc_styleName(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFontInfo*>(cppSelf)->styleName();
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

static PyObject* Sbk_QFontInfoFunc_underline(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontInfo*>(cppSelf)->underline();
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

static PyObject* Sbk_QFontInfoFunc_weight(PyObject* self)
{
    ::QFontInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // weight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontInfo*>(cppSelf)->weight();
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

static PyObject* Sbk_QFontInfo___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontInfo& cppSelf = *(((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFontInfo_methods[] = {
    {"bold", (PyCFunction)Sbk_QFontInfoFunc_bold, METH_NOARGS},
    {"exactMatch", (PyCFunction)Sbk_QFontInfoFunc_exactMatch, METH_NOARGS},
    {"family", (PyCFunction)Sbk_QFontInfoFunc_family, METH_NOARGS},
    {"fixedPitch", (PyCFunction)Sbk_QFontInfoFunc_fixedPitch, METH_NOARGS},
    {"italic", (PyCFunction)Sbk_QFontInfoFunc_italic, METH_NOARGS},
    {"overline", (PyCFunction)Sbk_QFontInfoFunc_overline, METH_NOARGS},
    {"pixelSize", (PyCFunction)Sbk_QFontInfoFunc_pixelSize, METH_NOARGS},
    {"pointSize", (PyCFunction)Sbk_QFontInfoFunc_pointSize, METH_NOARGS},
    {"pointSizeF", (PyCFunction)Sbk_QFontInfoFunc_pointSizeF, METH_NOARGS},
    {"rawMode", (PyCFunction)Sbk_QFontInfoFunc_rawMode, METH_NOARGS},
    {"strikeOut", (PyCFunction)Sbk_QFontInfoFunc_strikeOut, METH_NOARGS},
    {"style", (PyCFunction)Sbk_QFontInfoFunc_style, METH_NOARGS},
    {"styleHint", (PyCFunction)Sbk_QFontInfoFunc_styleHint, METH_NOARGS},
    {"styleName", (PyCFunction)Sbk_QFontInfoFunc_styleName, METH_NOARGS},
    {"underline", (PyCFunction)Sbk_QFontInfoFunc_underline, METH_NOARGS},
    {"weight", (PyCFunction)Sbk_QFontInfoFunc_weight, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QFontInfo___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFontInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFontInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFontInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFontInfo",
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
    /*tp_traverse*/         Sbk_QFontInfo_traverse,
    /*tp_clear*/            Sbk_QFontInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFontInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFontInfo_Init,
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
static void QFontInfo_PythonToCpp_QFontInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFontInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFontInfo_PythonToCpp_QFontInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontInfo_Type))
        return QFontInfo_PythonToCpp_QFontInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFontInfo_PTR_CppToPython_QFontInfo(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFontInfo*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFontInfo_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QFontInfo_COPY_CppToPython_QFontInfo(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QFontInfo_Type, new ::QFontInfo(*((::QFontInfo*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QFontInfo_PythonToCpp_QFontInfo_COPY(PyObject* pyIn, void* cppOut) {
    *((::QFontInfo*)cppOut) = *((::QFontInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QFontInfo_PythonToCpp_QFontInfo_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontInfo_Type))
        return QFontInfo_PythonToCpp_QFontInfo_COPY;
    return 0;
}

// Implicit conversions.
static void constQFontREF_PythonToCpp_QFontInfo(PyObject* pyIn, void* cppOut) {
    *((::QFontInfo*)cppOut) = ::QFontInfo(*((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQFontREF_PythonToCpp_QFontInfo_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pyIn))
        return constQFontREF_PythonToCpp_QFontInfo;
    return 0;
}

void init_QFontInfo(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFontInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFontInfo", "QFontInfo",
        &Sbk_QFontInfo_Type, &Shiboken::callCppDestructor< ::QFontInfo >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFontInfo_Type,
        QFontInfo_PythonToCpp_QFontInfo_PTR,
        is_QFontInfo_PythonToCpp_QFontInfo_PTR_Convertible,
        QFontInfo_PTR_CppToPython_QFontInfo,
        QFontInfo_COPY_CppToPython_QFontInfo);

    Shiboken::Conversions::registerConverterName(converter, "QFontInfo");
    Shiboken::Conversions::registerConverterName(converter, "QFontInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QFontInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFontInfo).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFontInfo_PythonToCpp_QFontInfo_COPY,
        is_QFontInfo_PythonToCpp_QFontInfo_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQFontREF_PythonToCpp_QFontInfo,
        is_constQFontREF_PythonToCpp_QFontInfo_Convertible);


}
