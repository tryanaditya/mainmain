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

#include "qfont_wrapper.h"

// Extra includes
#include <QStringList>
#include <qdatastream.h>
#include <qfont.h>
#include <qpaintdevice.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFont_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFont >()))
        return -1;

    ::QFont* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QFont", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QFont()
    // 1: QFont(QFont)
    // 2: QFont(QFont,QPaintDevice*)
    // 3: QFont(QString,int,int,bool)
    if (numArgs == 0) {
        overloadId = 0; // QFont()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QFont(QString,int,int,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // QFont(QString,int,int,bool)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // QFont(QString,int,int,bool)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))) {
                    overloadId = 3; // QFont(QString,int,int,bool)
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QFont(QFont)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[1])))) {
            overloadId = 2; // QFont(QFont,QPaintDevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFont_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFont()
        {

            if (!PyErr_Occurred()) {
                // QFont()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFont();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFont(const QFont & arg__1)
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
                // QFont(QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFont(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QFont(const QFont & arg__1, QPaintDevice * pd)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFont cppArg0_local = ::QFont();
            ::QFont* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QPaintDevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QFont(QFont,QPaintDevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFont(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QFont(const QString & family, int pointSize, int weight, bool italic)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pointSize");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont(): got multiple values for keyword argument 'pointSize'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QFont_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "weight");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont(): got multiple values for keyword argument 'weight'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QFont_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "italic");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont(): got multiple values for keyword argument 'italic'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3]))))
                        goto Sbk_QFont_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            bool cppArg3 = false;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QFont(QString,int,int,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFont(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFont >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFont_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFont_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QFont", "PySide.QtGui.QFont, PySide.QtGui.QPaintDevice", "unicode, int = -1, int = -1, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont", overloads);
        return -1;
}

static PyObject* Sbk_QFontFunc_bold(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bold()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->bold();
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

static PyObject* Sbk_QFontFunc_cacheStatistics(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheStatistics()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::cacheStatistics();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFontFunc_capitalization(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capitalization()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::Capitalization cppResult = const_cast<const ::QFont*>(cppSelf)->capitalization();
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

static PyObject* Sbk_QFontFunc_cleanup(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cleanup()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::cleanup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFontFunc_defaultFamily(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultFamily()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->defaultFamily();
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

static PyObject* Sbk_QFontFunc_exactMatch(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exactMatch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->exactMatch();
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

static PyObject* Sbk_QFontFunc_family(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // family()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->family();
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

static PyObject* Sbk_QFontFunc_fixedPitch(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fixedPitch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->fixedPitch();
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

static PyObject* Sbk_QFontFunc_fromString(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromString(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromString(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_fromString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromString(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->fromString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontFunc_fromString_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.fromString", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_handle(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QFont*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFontFunc_hintingPreference(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hintingPreference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::HintingPreference cppResult = const_cast<const ::QFont*>(cppSelf)->hintingPreference();
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

static PyObject* Sbk_QFontFunc_initialize(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initialize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::initialize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFontFunc_insertSubstitution(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertSubstitution", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertSubstitution(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertSubstitution(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_insertSubstitution_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertSubstitution(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::insertSubstitution(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_insertSubstitution_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont.insertSubstitution", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_insertSubstitutions(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertSubstitutions", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertSubstitutions(QString,QStringList)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertSubstitutions(QString,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_insertSubstitutions_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStringList cppArg1 = ::QStringList();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertSubstitutions(QString,QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::insertSubstitutions(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_insertSubstitutions_TypeError:
        const char* overloads[] = {"unicode, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont.insertSubstitutions", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_isCopyOf(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isCopyOf(QFont)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // isCopyOf(QFont)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_isCopyOf_TypeError;

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
            // isCopyOf(QFont)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->isCopyOf(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontFunc_isCopyOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.isCopyOf", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_italic(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // italic()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->italic();
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

static PyObject* Sbk_QFontFunc_kerning(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // kerning()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->kerning();
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

static PyObject* Sbk_QFontFunc_key(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // key()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->key();
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

static PyObject* Sbk_QFontFunc_lastResortFamily(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastResortFamily()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->lastResortFamily();
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

static PyObject* Sbk_QFontFunc_lastResortFont(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastResortFont()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->lastResortFont();
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

static PyObject* Sbk_QFontFunc_letterSpacing(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // letterSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFont*>(cppSelf)->letterSpacing();
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

static PyObject* Sbk_QFontFunc_letterSpacingType(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // letterSpacingType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::SpacingType cppResult = const_cast<const ::QFont*>(cppSelf)->letterSpacingType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFontFunc_overline(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->overline();
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

static PyObject* Sbk_QFontFunc_pixelSize(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pixelSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFont*>(cppSelf)->pixelSize();
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

static PyObject* Sbk_QFontFunc_pointSize(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pointSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFont*>(cppSelf)->pointSize();
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

static PyObject* Sbk_QFontFunc_pointSizeF(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pointSizeF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFont*>(cppSelf)->pointSizeF();
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

static PyObject* Sbk_QFontFunc_rawMode(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->rawMode();
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

static PyObject* Sbk_QFontFunc_rawName(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->rawName();
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

static PyObject* Sbk_QFontFunc_removeSubstitution(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeSubstitution(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeSubstitution(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_removeSubstitution_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeSubstitution(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QFont::removeSubstitution(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_removeSubstitution_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.removeSubstitution", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_resolve(PyObject* self, PyObject* args)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "resolve", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: resolve()const
    // 1: resolve(QFont)const
    // 2: resolve(uint)
    if (numArgs == 0) {
        overloadId = 0; // resolve()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))) {
        overloadId = 2; // resolve(uint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        overloadId = 1; // resolve(QFont)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_resolve_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // resolve() const
        {

            if (!PyErr_Occurred()) {
                // resolve()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                uint cppResult = const_cast<const ::QFont*>(cppSelf)->resolve();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
            }
            break;
        }
        case 1: // resolve(const QFont & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QFont cppArg0_local = ::QFont();
            ::QFont* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // resolve(QFont)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFont cppResult = const_cast<const ::QFont*>(cppSelf)->resolve(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
            }
            break;
        }
        case 2: // resolve(uint mask)
        {
            uint cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // resolve(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->resolve(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontFunc_resolve_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QFont", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont.resolve", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setBold(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBold(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setBold(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setBold_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBold(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBold(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setBold_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setBold", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setCapitalization(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCapitalization(QFont::Capitalization)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX]), (pyArg)))) {
        overloadId = 0; // setCapitalization(QFont::Capitalization)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setCapitalization_TypeError;

    // Call function/method
    {
        ::QFont::Capitalization cppArg0 = ((::QFont::Capitalization)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCapitalization(QFont::Capitalization)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCapitalization(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setCapitalization_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.Capitalization", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setCapitalization", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setFamily(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFamily(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFamily(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setFamily_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFamily(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFamily(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setFamily_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setFamily", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setFixedPitch(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFixedPitch(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFixedPitch(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setFixedPitch_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFixedPitch(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFixedPitch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setFixedPitch_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setFixedPitch", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setHintingPreference(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHintingPreference(QFont::HintingPreference)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX]), (pyArg)))) {
        overloadId = 0; // setHintingPreference(QFont::HintingPreference)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setHintingPreference_TypeError;

    // Call function/method
    {
        ::QFont::HintingPreference cppArg0 = ((::QFont::HintingPreference)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHintingPreference(QFont::HintingPreference)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHintingPreference(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setHintingPreference_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.HintingPreference", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setHintingPreference", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setItalic(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItalic(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setItalic(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setItalic_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setItalic(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItalic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setItalic_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setItalic", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setKerning(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setKerning(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setKerning(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setKerning_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setKerning(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setKerning(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setKerning_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setKerning", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setLetterSpacing(PyObject* self, PyObject* args)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLetterSpacing", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setLetterSpacing(QFont::SpacingType,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setLetterSpacing(QFont::SpacingType,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setLetterSpacing_TypeError;

    // Call function/method
    {
        ::QFont::SpacingType cppArg0 = ((::QFont::SpacingType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setLetterSpacing(QFont::SpacingType,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLetterSpacing(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setLetterSpacing_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.SpacingType, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont.setLetterSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setOverline(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOverline(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOverline(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setOverline_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOverline(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOverline(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setOverline_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setOverline", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setPixelSize(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPixelSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPixelSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setPixelSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPixelSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPixelSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setPixelSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setPixelSize", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setPointSize(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPointSize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPointSize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setPointSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPointSize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPointSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setPointSize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setPointSize", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setPointSizeF(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPointSizeF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPointSizeF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setPointSizeF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPointSizeF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPointSizeF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setPointSizeF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setPointSizeF", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setRawMode(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRawMode(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setRawMode(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setRawMode_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRawMode(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRawMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setRawMode_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setRawMode", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setRawName(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRawName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setRawName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setRawName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRawName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRawName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setRawName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setRawName", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStretch(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStretch(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setStretch(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStretch(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStretch_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setStretch", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStrikeOut(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStrikeOut(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setStrikeOut(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStrikeOut_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStrikeOut(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStrikeOut(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStrikeOut_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setStrikeOut", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(QFont::Style)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setStyle(QFont::Style)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStyle_TypeError;

    // Call function/method
    {
        ::QFont::Style cppArg0 = ((::QFont::Style)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyle(QFont::Style)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.Style", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStyleHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont.setStyleHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont.setStyleHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setStyleHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStyleHint(QFont::StyleHint,QFont::StyleStrategy)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setStyleHint(QFont::StyleHint,QFont::StyleStrategy)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setStyleHint(QFont::StyleHint,QFont::StyleStrategy)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStyleHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "strategy");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFont.setStyleHint(): got multiple values for keyword argument 'strategy'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArgs[1]))))
                    goto Sbk_QFontFunc_setStyleHint_TypeError;
            }
        }
        ::QFont::StyleHint cppArg0 = ((::QFont::StyleHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFont::StyleStrategy cppArg1 = QFont::PreferDefault;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStyleHint(QFont::StyleHint,QFont::StyleStrategy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyleHint(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStyleHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.StyleHint, PySide.QtGui.QFont.StyleStrategy = PreferDefault", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFont.setStyleHint", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStyleName(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyleName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStyleName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStyleName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyleName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyleName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStyleName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setStyleName", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setStyleStrategy(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyleStrategy(QFont::StyleStrategy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]), (pyArg)))) {
        overloadId = 0; // setStyleStrategy(QFont::StyleStrategy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setStyleStrategy_TypeError;

    // Call function/method
    {
        ::QFont::StyleStrategy cppArg0 = ((::QFont::StyleStrategy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyleStrategy(QFont::StyleStrategy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyleStrategy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setStyleStrategy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont.StyleStrategy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setStyleStrategy", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setUnderline(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUnderline(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUnderline(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setUnderline_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUnderline(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUnderline(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setUnderline_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setUnderline", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setWeight(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWeight(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setWeight(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setWeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWeight(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setWeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setWeight", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_setWordSpacing(PyObject* self, PyObject* pyArg)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWordSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setWordSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_setWordSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWordSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWordSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFontFunc_setWordSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.setWordSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_stretch(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stretch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFont*>(cppSelf)->stretch();
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

static PyObject* Sbk_QFontFunc_strikeOut(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // strikeOut()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->strikeOut();
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

static PyObject* Sbk_QFontFunc_style(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::Style cppResult = const_cast<const ::QFont*>(cppSelf)->style();
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

static PyObject* Sbk_QFontFunc_styleHint(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::StyleHint cppResult = const_cast<const ::QFont*>(cppSelf)->styleHint();
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

static PyObject* Sbk_QFontFunc_styleName(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->styleName();
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

static PyObject* Sbk_QFontFunc_styleStrategy(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // styleStrategy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont::StyleStrategy cppResult = const_cast<const ::QFont*>(cppSelf)->styleStrategy();
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

static PyObject* Sbk_QFontFunc_substitute(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: substitute(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // substitute(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_substitute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // substitute(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QFont::substitute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontFunc_substitute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.substitute", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_substitutes(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: substitutes(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // substitutes(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc_substitutes_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // substitutes(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QFont::substitutes(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontFunc_substitutes_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.substitutes", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc_substitutions(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // substitutions()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QFont::substitutions();
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

static PyObject* Sbk_QFontFunc_toString(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFont*>(cppSelf)->toString();
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

static PyObject* Sbk_QFontFunc_underline(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFont*>(cppSelf)->underline();
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

static PyObject* Sbk_QFontFunc_weight(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // weight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFont*>(cppSelf)->weight();
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

static PyObject* Sbk_QFontFunc_wordSpacing(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wordSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFont*>(cppSelf)->wordSpacing();
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

static PyObject* Sbk_QFont___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFont& cppSelf = *(((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFont_methods[] = {
    {"bold", (PyCFunction)Sbk_QFontFunc_bold, METH_NOARGS},
    {"cacheStatistics", (PyCFunction)Sbk_QFontFunc_cacheStatistics, METH_NOARGS|METH_STATIC},
    {"capitalization", (PyCFunction)Sbk_QFontFunc_capitalization, METH_NOARGS},
    {"cleanup", (PyCFunction)Sbk_QFontFunc_cleanup, METH_NOARGS|METH_STATIC},
    {"defaultFamily", (PyCFunction)Sbk_QFontFunc_defaultFamily, METH_NOARGS},
    {"exactMatch", (PyCFunction)Sbk_QFontFunc_exactMatch, METH_NOARGS},
    {"family", (PyCFunction)Sbk_QFontFunc_family, METH_NOARGS},
    {"fixedPitch", (PyCFunction)Sbk_QFontFunc_fixedPitch, METH_NOARGS},
    {"fromString", (PyCFunction)Sbk_QFontFunc_fromString, METH_O},
    {"handle", (PyCFunction)Sbk_QFontFunc_handle, METH_NOARGS},
    {"hintingPreference", (PyCFunction)Sbk_QFontFunc_hintingPreference, METH_NOARGS},
    {"initialize", (PyCFunction)Sbk_QFontFunc_initialize, METH_NOARGS|METH_STATIC},
    {"insertSubstitution", (PyCFunction)Sbk_QFontFunc_insertSubstitution, METH_VARARGS|METH_STATIC},
    {"insertSubstitutions", (PyCFunction)Sbk_QFontFunc_insertSubstitutions, METH_VARARGS|METH_STATIC},
    {"isCopyOf", (PyCFunction)Sbk_QFontFunc_isCopyOf, METH_O},
    {"italic", (PyCFunction)Sbk_QFontFunc_italic, METH_NOARGS},
    {"kerning", (PyCFunction)Sbk_QFontFunc_kerning, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QFontFunc_key, METH_NOARGS},
    {"lastResortFamily", (PyCFunction)Sbk_QFontFunc_lastResortFamily, METH_NOARGS},
    {"lastResortFont", (PyCFunction)Sbk_QFontFunc_lastResortFont, METH_NOARGS},
    {"letterSpacing", (PyCFunction)Sbk_QFontFunc_letterSpacing, METH_NOARGS},
    {"letterSpacingType", (PyCFunction)Sbk_QFontFunc_letterSpacingType, METH_NOARGS},
    {"overline", (PyCFunction)Sbk_QFontFunc_overline, METH_NOARGS},
    {"pixelSize", (PyCFunction)Sbk_QFontFunc_pixelSize, METH_NOARGS},
    {"pointSize", (PyCFunction)Sbk_QFontFunc_pointSize, METH_NOARGS},
    {"pointSizeF", (PyCFunction)Sbk_QFontFunc_pointSizeF, METH_NOARGS},
    {"rawMode", (PyCFunction)Sbk_QFontFunc_rawMode, METH_NOARGS},
    {"rawName", (PyCFunction)Sbk_QFontFunc_rawName, METH_NOARGS},
    {"removeSubstitution", (PyCFunction)Sbk_QFontFunc_removeSubstitution, METH_O|METH_STATIC},
    {"resolve", (PyCFunction)Sbk_QFontFunc_resolve, METH_VARARGS},
    {"setBold", (PyCFunction)Sbk_QFontFunc_setBold, METH_O},
    {"setCapitalization", (PyCFunction)Sbk_QFontFunc_setCapitalization, METH_O},
    {"setFamily", (PyCFunction)Sbk_QFontFunc_setFamily, METH_O},
    {"setFixedPitch", (PyCFunction)Sbk_QFontFunc_setFixedPitch, METH_O},
    {"setHintingPreference", (PyCFunction)Sbk_QFontFunc_setHintingPreference, METH_O},
    {"setItalic", (PyCFunction)Sbk_QFontFunc_setItalic, METH_O},
    {"setKerning", (PyCFunction)Sbk_QFontFunc_setKerning, METH_O},
    {"setLetterSpacing", (PyCFunction)Sbk_QFontFunc_setLetterSpacing, METH_VARARGS},
    {"setOverline", (PyCFunction)Sbk_QFontFunc_setOverline, METH_O},
    {"setPixelSize", (PyCFunction)Sbk_QFontFunc_setPixelSize, METH_O},
    {"setPointSize", (PyCFunction)Sbk_QFontFunc_setPointSize, METH_O},
    {"setPointSizeF", (PyCFunction)Sbk_QFontFunc_setPointSizeF, METH_O},
    {"setRawMode", (PyCFunction)Sbk_QFontFunc_setRawMode, METH_O},
    {"setRawName", (PyCFunction)Sbk_QFontFunc_setRawName, METH_O},
    {"setStretch", (PyCFunction)Sbk_QFontFunc_setStretch, METH_O},
    {"setStrikeOut", (PyCFunction)Sbk_QFontFunc_setStrikeOut, METH_O},
    {"setStyle", (PyCFunction)Sbk_QFontFunc_setStyle, METH_O},
    {"setStyleHint", (PyCFunction)Sbk_QFontFunc_setStyleHint, METH_VARARGS|METH_KEYWORDS},
    {"setStyleName", (PyCFunction)Sbk_QFontFunc_setStyleName, METH_O},
    {"setStyleStrategy", (PyCFunction)Sbk_QFontFunc_setStyleStrategy, METH_O},
    {"setUnderline", (PyCFunction)Sbk_QFontFunc_setUnderline, METH_O},
    {"setWeight", (PyCFunction)Sbk_QFontFunc_setWeight, METH_O},
    {"setWordSpacing", (PyCFunction)Sbk_QFontFunc_setWordSpacing, METH_O},
    {"stretch", (PyCFunction)Sbk_QFontFunc_stretch, METH_NOARGS},
    {"strikeOut", (PyCFunction)Sbk_QFontFunc_strikeOut, METH_NOARGS},
    {"style", (PyCFunction)Sbk_QFontFunc_style, METH_NOARGS},
    {"styleHint", (PyCFunction)Sbk_QFontFunc_styleHint, METH_NOARGS},
    {"styleName", (PyCFunction)Sbk_QFontFunc_styleName, METH_NOARGS},
    {"styleStrategy", (PyCFunction)Sbk_QFontFunc_styleStrategy, METH_NOARGS},
    {"substitute", (PyCFunction)Sbk_QFontFunc_substitute, METH_O|METH_STATIC},
    {"substitutes", (PyCFunction)Sbk_QFontFunc_substitutes, METH_O|METH_STATIC},
    {"substitutions", (PyCFunction)Sbk_QFontFunc_substitutions, METH_NOARGS|METH_STATIC},
    {"toString", (PyCFunction)Sbk_QFontFunc_toString, METH_NOARGS},
    {"underline", (PyCFunction)Sbk_QFontFunc_underline, METH_NOARGS},
    {"weight", (PyCFunction)Sbk_QFontFunc_weight, METH_NOARGS},
    {"wordSpacing", (PyCFunction)Sbk_QFontFunc_wordSpacing, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QFont___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QFontFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QFont)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QFont)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QFont) [reverse operator]
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

    Sbk_QFontFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QFontFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QFont&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QFont&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QFont&) [reverse operator]
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

    Sbk_QFontFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFont.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QFont_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFont& cppSelf = *(((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
                // operator!=(const QFont & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFont cppArg0_local = ::QFont();
                ::QFont* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
                // operator<(const QFont & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFont cppArg0_local = ::QFont();
                ::QFont* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QFont_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
                // operator==(const QFont & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFont cppArg0_local = ::QFont();
                ::QFont* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
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
            goto Sbk_QFont_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QFont_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QFont_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFont_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QFont__repr__(PyObject* self)
{
    ::QFont* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QFont_TypeAsNumber;

static SbkObjectType Sbk_QFont_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFont",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QFont__repr__,
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
    /*tp_traverse*/         Sbk_QFont_traverse,
    /*tp_clear*/            Sbk_QFont_clear,
    /*tp_richcompare*/      Sbk_QFont_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFont_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFont_Init,
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
static void QFont_StyleHint_PythonToCpp_QFont_StyleHint(PyObject* pyIn, void* cppOut) {
    *((::QFont::StyleHint*)cppOut) = (::QFont::StyleHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_StyleHint_PythonToCpp_QFont_StyleHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX]))
        return QFont_StyleHint_PythonToCpp_QFont_StyleHint;
    return 0;
}
static PyObject* QFont_StyleHint_CppToPython_QFont_StyleHint(const void* cppIn) {
    int castCppIn = *((::QFont::StyleHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX], castCppIn);

}

static void QFont_StyleStrategy_PythonToCpp_QFont_StyleStrategy(PyObject* pyIn, void* cppOut) {
    *((::QFont::StyleStrategy*)cppOut) = (::QFont::StyleStrategy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_StyleStrategy_PythonToCpp_QFont_StyleStrategy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]))
        return QFont_StyleStrategy_PythonToCpp_QFont_StyleStrategy;
    return 0;
}
static PyObject* QFont_StyleStrategy_CppToPython_QFont_StyleStrategy(const void* cppIn) {
    int castCppIn = *((::QFont::StyleStrategy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX], castCppIn);

}

static void QFont_HintingPreference_PythonToCpp_QFont_HintingPreference(PyObject* pyIn, void* cppOut) {
    *((::QFont::HintingPreference*)cppOut) = (::QFont::HintingPreference) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_HintingPreference_PythonToCpp_QFont_HintingPreference_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX]))
        return QFont_HintingPreference_PythonToCpp_QFont_HintingPreference;
    return 0;
}
static PyObject* QFont_HintingPreference_CppToPython_QFont_HintingPreference(const void* cppIn) {
    int castCppIn = *((::QFont::HintingPreference*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX], castCppIn);

}

static void QFont_Weight_PythonToCpp_QFont_Weight(PyObject* pyIn, void* cppOut) {
    *((::QFont::Weight*)cppOut) = (::QFont::Weight) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_Weight_PythonToCpp_QFont_Weight_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX]))
        return QFont_Weight_PythonToCpp_QFont_Weight;
    return 0;
}
static PyObject* QFont_Weight_CppToPython_QFont_Weight(const void* cppIn) {
    int castCppIn = *((::QFont::Weight*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX], castCppIn);

}

static void QFont_Style_PythonToCpp_QFont_Style(PyObject* pyIn, void* cppOut) {
    *((::QFont::Style*)cppOut) = (::QFont::Style) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_Style_PythonToCpp_QFont_Style_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX]))
        return QFont_Style_PythonToCpp_QFont_Style;
    return 0;
}
static PyObject* QFont_Style_CppToPython_QFont_Style(const void* cppIn) {
    int castCppIn = *((::QFont::Style*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX], castCppIn);

}

static void QFont_Stretch_PythonToCpp_QFont_Stretch(PyObject* pyIn, void* cppOut) {
    *((::QFont::Stretch*)cppOut) = (::QFont::Stretch) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_Stretch_PythonToCpp_QFont_Stretch_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX]))
        return QFont_Stretch_PythonToCpp_QFont_Stretch;
    return 0;
}
static PyObject* QFont_Stretch_CppToPython_QFont_Stretch(const void* cppIn) {
    int castCppIn = *((::QFont::Stretch*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX], castCppIn);

}

static void QFont_Capitalization_PythonToCpp_QFont_Capitalization(PyObject* pyIn, void* cppOut) {
    *((::QFont::Capitalization*)cppOut) = (::QFont::Capitalization) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_Capitalization_PythonToCpp_QFont_Capitalization_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX]))
        return QFont_Capitalization_PythonToCpp_QFont_Capitalization;
    return 0;
}
static PyObject* QFont_Capitalization_CppToPython_QFont_Capitalization(const void* cppIn) {
    int castCppIn = *((::QFont::Capitalization*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX], castCppIn);

}

static void QFont_SpacingType_PythonToCpp_QFont_SpacingType(PyObject* pyIn, void* cppOut) {
    *((::QFont::SpacingType*)cppOut) = (::QFont::SpacingType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFont_SpacingType_PythonToCpp_QFont_SpacingType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX]))
        return QFont_SpacingType_PythonToCpp_QFont_SpacingType;
    return 0;
}
static PyObject* QFont_SpacingType_CppToPython_QFont_SpacingType(const void* cppIn) {
    int castCppIn = *((::QFont::SpacingType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFont_PythonToCpp_QFont_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFont_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFont_PythonToCpp_QFont_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFont_Type))
        return QFont_PythonToCpp_QFont_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFont_PTR_CppToPython_QFont(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFont*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFont_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QFont_COPY_CppToPython_QFont(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QFont_Type, new ::QFont(*((::QFont*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QFont_PythonToCpp_QFont_COPY(PyObject* pyIn, void* cppOut) {
    *((::QFont*)cppOut) = *((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QFont_PythonToCpp_QFont_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFont_Type))
        return QFont_PythonToCpp_QFont_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQStringREF_PythonToCpp_QFont(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QFont*)cppOut) = ::QFont(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QFont_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QFont;
    return 0;
}

void init_QFont(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QFont_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QFont_TypeAsNumber.nb_rshift = Sbk_QFontFunc___rshift__;
    Sbk_QFont_TypeAsNumber.nb_lshift = Sbk_QFontFunc___lshift__;
    Sbk_QFont_Type.super.ht_type.tp_as_number = &Sbk_QFont_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QFONT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFont_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFont", "QFont",
        &Sbk_QFont_Type, &Shiboken::callCppDestructor< ::QFont >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFont_Type,
        QFont_PythonToCpp_QFont_PTR,
        is_QFont_PythonToCpp_QFont_PTR_Convertible,
        QFont_PTR_CppToPython_QFont,
        QFont_COPY_CppToPython_QFont);

    Shiboken::Conversions::registerConverterName(converter, "QFont");
    Shiboken::Conversions::registerConverterName(converter, "QFont*");
    Shiboken::Conversions::registerConverterName(converter, "QFont&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFont).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFont_PythonToCpp_QFont_COPY,
        is_QFont_PythonToCpp_QFont_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QFont,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QFont_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleHint'.
    SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "StyleHint",
        "PySide.QtGui.QFont.StyleHint",
        "QFont::StyleHint");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Helvetica", (long) QFont::Helvetica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "SansSerif", (long) QFont::SansSerif))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Times", (long) QFont::Times))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Serif", (long) QFont::Serif))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Courier", (long) QFont::Courier))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "TypeWriter", (long) QFont::TypeWriter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "OldEnglish", (long) QFont::OldEnglish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Decorative", (long) QFont::Decorative))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "System", (long) QFont::System))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "AnyStyle", (long) QFont::AnyStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Cursive", (long) QFont::Cursive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Monospace", (long) QFont::Monospace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
        &Sbk_QFont_Type, "Fantasy", (long) QFont::Fantasy))
        return ;
    // Register converter for enum 'QFont::StyleHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX],
            QFont_StyleHint_CppToPython_QFont_StyleHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_StyleHint_PythonToCpp_QFont_StyleHint,
            is_QFont_StyleHint_PythonToCpp_QFont_StyleHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::StyleHint");
        Shiboken::Conversions::registerConverterName(converter, "StyleHint");
    }
    // End of 'StyleHint' enum.

    // Initialization of enum 'StyleStrategy'.
    SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "StyleStrategy",
        "PySide.QtGui.QFont.StyleStrategy",
        "QFont::StyleStrategy");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferDefault", (long) QFont::PreferDefault))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferBitmap", (long) QFont::PreferBitmap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferDevice", (long) QFont::PreferDevice))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferOutline", (long) QFont::PreferOutline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "ForceOutline", (long) QFont::ForceOutline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferMatch", (long) QFont::PreferMatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferQuality", (long) QFont::PreferQuality))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "PreferAntialias", (long) QFont::PreferAntialias))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "NoAntialias", (long) QFont::NoAntialias))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "OpenGLCompatible", (long) QFont::OpenGLCompatible))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "ForceIntegerMetrics", (long) QFont::ForceIntegerMetrics))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
        &Sbk_QFont_Type, "NoFontMerging", (long) QFont::NoFontMerging))
        return ;
    // Register converter for enum 'QFont::StyleStrategy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX],
            QFont_StyleStrategy_CppToPython_QFont_StyleStrategy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_StyleStrategy_PythonToCpp_QFont_StyleStrategy,
            is_QFont_StyleStrategy_PythonToCpp_QFont_StyleStrategy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::StyleStrategy");
        Shiboken::Conversions::registerConverterName(converter, "StyleStrategy");
    }
    // End of 'StyleStrategy' enum.

    // Initialization of enum 'HintingPreference'.
    SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "HintingPreference",
        "PySide.QtGui.QFont.HintingPreference",
        "QFont::HintingPreference");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX],
        &Sbk_QFont_Type, "PreferDefaultHinting", (long) QFont::PreferDefaultHinting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX],
        &Sbk_QFont_Type, "PreferNoHinting", (long) QFont::PreferNoHinting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX],
        &Sbk_QFont_Type, "PreferVerticalHinting", (long) QFont::PreferVerticalHinting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX],
        &Sbk_QFont_Type, "PreferFullHinting", (long) QFont::PreferFullHinting))
        return ;
    // Register converter for enum 'QFont::HintingPreference'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX],
            QFont_HintingPreference_CppToPython_QFont_HintingPreference);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_HintingPreference_PythonToCpp_QFont_HintingPreference,
            is_QFont_HintingPreference_PythonToCpp_QFont_HintingPreference_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::HintingPreference");
        Shiboken::Conversions::registerConverterName(converter, "HintingPreference");
    }
    // End of 'HintingPreference' enum.

    // Initialization of enum 'Weight'.
    SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "Weight",
        "PySide.QtGui.QFont.Weight",
        "QFont::Weight");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
        &Sbk_QFont_Type, "Light", (long) QFont::Light))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
        &Sbk_QFont_Type, "Normal", (long) QFont::Normal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
        &Sbk_QFont_Type, "DemiBold", (long) QFont::DemiBold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
        &Sbk_QFont_Type, "Bold", (long) QFont::Bold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
        &Sbk_QFont_Type, "Black", (long) QFont::Black))
        return ;
    // Register converter for enum 'QFont::Weight'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX],
            QFont_Weight_CppToPython_QFont_Weight);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_Weight_PythonToCpp_QFont_Weight,
            is_QFont_Weight_PythonToCpp_QFont_Weight_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_WEIGHT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::Weight");
        Shiboken::Conversions::registerConverterName(converter, "Weight");
    }
    // End of 'Weight' enum.

    // Initialization of enum 'Style'.
    SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "Style",
        "PySide.QtGui.QFont.Style",
        "QFont::Style");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX],
        &Sbk_QFont_Type, "StyleNormal", (long) QFont::StyleNormal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX],
        &Sbk_QFont_Type, "StyleItalic", (long) QFont::StyleItalic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX],
        &Sbk_QFont_Type, "StyleOblique", (long) QFont::StyleOblique))
        return ;
    // Register converter for enum 'QFont::Style'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX],
            QFont_Style_CppToPython_QFont_Style);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_Style_PythonToCpp_QFont_Style,
            is_QFont_Style_PythonToCpp_QFont_Style_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::Style");
        Shiboken::Conversions::registerConverterName(converter, "Style");
    }
    // End of 'Style' enum.

    // Initialization of enum 'Stretch'.
    SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "Stretch",
        "PySide.QtGui.QFont.Stretch",
        "QFont::Stretch");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "UltraCondensed", (long) QFont::UltraCondensed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "ExtraCondensed", (long) QFont::ExtraCondensed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "Condensed", (long) QFont::Condensed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "SemiCondensed", (long) QFont::SemiCondensed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "Unstretched", (long) QFont::Unstretched))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "SemiExpanded", (long) QFont::SemiExpanded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "Expanded", (long) QFont::Expanded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "ExtraExpanded", (long) QFont::ExtraExpanded))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
        &Sbk_QFont_Type, "UltraExpanded", (long) QFont::UltraExpanded))
        return ;
    // Register converter for enum 'QFont::Stretch'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX],
            QFont_Stretch_CppToPython_QFont_Stretch);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_Stretch_PythonToCpp_QFont_Stretch,
            is_QFont_Stretch_PythonToCpp_QFont_Stretch_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_STRETCH_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::Stretch");
        Shiboken::Conversions::registerConverterName(converter, "Stretch");
    }
    // End of 'Stretch' enum.

    // Initialization of enum 'Capitalization'.
    SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "Capitalization",
        "PySide.QtGui.QFont.Capitalization",
        "QFont::Capitalization");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
        &Sbk_QFont_Type, "MixedCase", (long) QFont::MixedCase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
        &Sbk_QFont_Type, "AllUppercase", (long) QFont::AllUppercase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
        &Sbk_QFont_Type, "AllLowercase", (long) QFont::AllLowercase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
        &Sbk_QFont_Type, "SmallCaps", (long) QFont::SmallCaps))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
        &Sbk_QFont_Type, "Capitalize", (long) QFont::Capitalize))
        return ;
    // Register converter for enum 'QFont::Capitalization'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX],
            QFont_Capitalization_CppToPython_QFont_Capitalization);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_Capitalization_PythonToCpp_QFont_Capitalization,
            is_QFont_Capitalization_PythonToCpp_QFont_Capitalization_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::Capitalization");
        Shiboken::Conversions::registerConverterName(converter, "Capitalization");
    }
    // End of 'Capitalization' enum.

    // Initialization of enum 'SpacingType'.
    SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFont_Type,
        "SpacingType",
        "PySide.QtGui.QFont.SpacingType",
        "QFont::SpacingType");
    if (!SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX],
        &Sbk_QFont_Type, "PercentageSpacing", (long) QFont::PercentageSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX],
        &Sbk_QFont_Type, "AbsoluteSpacing", (long) QFont::AbsoluteSpacing))
        return ;
    // Register converter for enum 'QFont::SpacingType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX],
            QFont_SpacingType_CppToPython_QFont_SpacingType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFont_SpacingType_PythonToCpp_QFont_SpacingType,
            is_QFont_SpacingType_PythonToCpp_QFont_SpacingType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFont::SpacingType");
        Shiboken::Conversions::registerConverterName(converter, "SpacingType");
    }
    // End of 'SpacingType' enum.


    qRegisterMetaType< ::QFont >("QFont");
    qRegisterMetaType< ::QFont::StyleHint >("QFont::StyleHint");
    qRegisterMetaType< ::QFont::StyleStrategy >("QFont::StyleStrategy");
    qRegisterMetaType< ::QFont::HintingPreference >("QFont::HintingPreference");
    qRegisterMetaType< ::QFont::Weight >("QFont::Weight");
    qRegisterMetaType< ::QFont::Style >("QFont::Style");
    qRegisterMetaType< ::QFont::Stretch >("QFont::Stretch");
    qRegisterMetaType< ::QFont::Capitalization >("QFont::Capitalization");
    qRegisterMetaType< ::QFont::SpacingType >("QFont::SpacingType");
}
