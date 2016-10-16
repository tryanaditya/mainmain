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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include "pyside_qttest_python.h"

#include "qtest_wrapper.h"
#include "qtest_pysideqtoucheventsequence_wrapper.h"

// Extra includes
#include <QtTest>
#include <pysideqtesttouch.h>
#include <qobject.h>
#include <qpoint.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QTestFunc_addColumnInternal(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addColumnInternal", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addColumnInternal(int,const char*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        overloadId = 0; // addColumnInternal(int,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_addColumnInternal_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addColumnInternal(int,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::addColumnInternal(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_addColumnInternal_TypeError:
        const char* overloads[] = {"int, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.addColumnInternal", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_asciiToKey(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: asciiToKey(char)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // asciiToKey(char)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_asciiToKey_TypeError;

    // Call function/method
    {
        char cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // asciiToKey(char)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::Key cppResult = ::QTest::asciiToKey(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_asciiToKey_TypeError:
        const char* overloads[] = {"char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtTest.QTest.asciiToKey", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_compare_ptr_helper(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "compare_ptr_helper", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: compare_ptr_helper(const void*,const void*,const char*,const char*,const char*,int)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1])))
        && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))
        && Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))
        && Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        overloadId = 0; // compare_ptr_helper(const void*,const void*,const char*,const char*,const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_compare_ptr_helper_TypeError;

    // Call function/method
    {
        void* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        void* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        const char* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        const char* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        const char* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        int cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // compare_ptr_helper(const void*,const void*,const char*,const char*,const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QTest::compare_ptr_helper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_compare_ptr_helper_TypeError:
        const char* overloads[] = {"void, void, " SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.compare_ptr_helper", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_compare_string_helper(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "compare_string_helper", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: compare_string_helper(const char*,const char*,const char*,const char*,const char*,int)
    if (numArgs == 6
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))
        && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))
        && Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))
        && Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        overloadId = 0; // compare_string_helper(const char*,const char*,const char*,const char*,const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_compare_string_helper_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        const char* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        const char* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        const char* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        int cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // compare_string_helper(const char*,const char*,const char*,const char*,const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QTest::compare_string_helper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_compare_string_helper_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.compare_string_helper", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_currentAppName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentAppName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = ::QTest::currentAppName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTestFunc_currentDataTag(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDataTag()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = ::QTest::currentDataTag();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTestFunc_currentTestFailed(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTestFailed()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QTest::currentTestFailed();
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

static PyObject* Sbk_QTestFunc_currentTestFunction(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTestFunction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = ::QTest::currentTestFunction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTestFunc_ignoreMessage(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ignoreMessage", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: ignoreMessage(QtMsgType,const char*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTMSGTYPE_IDX]), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        overloadId = 0; // ignoreMessage(QtMsgType,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_ignoreMessage_TypeError;

    // Call function/method
    {
        ::QtMsgType cppArg0 = ((::QtMsgType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // ignoreMessage(QtMsgType,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::ignoreMessage(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_ignoreMessage_TypeError:
        const char* overloads[] = {"PySide.QtCore.QtMsgType, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.ignoreMessage", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyClick(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:keyClick", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: keyClick(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
    // 1: keyClick(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // keyClick(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // keyClick(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 0; // keyClick(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // keyClick(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // keyClick(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 1; // keyClick(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyClick_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // keyClick(QWidget * widget, Qt::Key key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyClick_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyClick_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::Key cppArg1 = ((::Qt::Key)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyClick(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyClick(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // keyClick(QWidget * widget, char key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyClick_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClick(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyClick_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyClick(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyClick(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_keyClick_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", "PySide.QtGui.QWidget, char, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.keyClick", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyClicks(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClicks(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClicks(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:keyClicks", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: keyClicks(QWidget*,QString,QFlags<Qt::KeyboardModifier>,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // keyClicks(QWidget*,QString,QFlags<Qt::KeyboardModifier>,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // keyClicks(QWidget*,QString,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                overloadId = 0; // keyClicks(QWidget*,QString,QFlags<Qt::KeyboardModifier>,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyClicks_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "modifier");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClicks(): got multiple values for keyword argument 'modifier'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                    goto Sbk_QTestFunc_keyClicks_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyClicks(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QTestFunc_keyClicks_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = -1;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // keyClicks(QWidget*,QString,QFlags<Qt::KeyboardModifier>,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::keyClicks(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_keyClicks_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.keyClicks", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:keyEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: keyEvent(QTest::KeyAction,QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
    // 1: keyEvent(QTest::KeyAction,QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // keyEvent(QTest::KeyAction,QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // keyEvent(QTest::KeyAction,QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 0; // keyEvent(QTest::KeyAction,QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        } else if (SbkChar_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // keyEvent(QTest::KeyAction,QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 1; // keyEvent(QTest::KeyAction,QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 1; // keyEvent(QTest::KeyAction,QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyEvent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // keyEvent(QTest::KeyAction action, QWidget * widget, Qt::Key key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyEvent_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QTestFunc_keyEvent_TypeError;
                }
            }
            ::QTest::KeyAction cppArg0 = ((::QTest::KeyAction)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::Key cppArg2 = ((::Qt::Key)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::KeyboardModifier> cppArg3 = Qt::NoModifier;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = -1;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // keyEvent(QTest::KeyAction,QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // keyEvent(QTest::KeyAction action, QWidget * widget, char ascii, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyEvent_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyEvent(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QTestFunc_keyEvent_TypeError;
                }
            }
            ::QTest::KeyAction cppArg0 = ((::QTest::KeyAction)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            char cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::KeyboardModifier> cppArg3 = Qt::NoModifier;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = -1;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // keyEvent(QTest::KeyAction,QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_keyEvent_TypeError:
        const char* overloads[] = {"PySide.QtTest.QTest.KeyAction, PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", "PySide.QtTest.QTest.KeyAction, PySide.QtGui.QWidget, char, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.keyEvent", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyPress(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:keyPress", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: keyPress(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
    // 1: keyPress(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // keyPress(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // keyPress(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 0; // keyPress(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // keyPress(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // keyPress(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 1; // keyPress(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyPress_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // keyPress(QWidget * widget, Qt::Key key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyPress_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyPress_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::Key cppArg1 = ((::Qt::Key)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyPress(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyPress(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // keyPress(QWidget * widget, char key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyPress_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyPress(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyPress_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyPress(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyPress(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_keyPress_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", "PySide.QtGui.QWidget, char, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.keyPress", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyRelease(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:keyRelease", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: keyRelease(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
    // 1: keyRelease(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // keyRelease(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // keyRelease(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 0; // keyRelease(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // keyRelease(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // keyRelease(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 1; // keyRelease(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyRelease_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // keyRelease(QWidget * widget, Qt::Key key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyRelease_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyRelease_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::Key cppArg1 = ((::Qt::Key)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyRelease(QWidget*,Qt::Key,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyRelease(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // keyRelease(QWidget * widget, char key, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "modifier");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): got multiple values for keyword argument 'modifier'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                        goto Sbk_QTestFunc_keyRelease_TypeError;
                }
                value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.keyRelease(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTestFunc_keyRelease_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::KeyboardModifier> cppArg2 = Qt::NoModifier;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = -1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // keyRelease(QWidget*,char,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::keyRelease(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_keyRelease_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", "PySide.QtGui.QWidget, char, PySide.QtCore.Qt.KeyboardModifiers = Qt.NoModifier, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.keyRelease", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_keyToAscii(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyToAscii(Qt::Key)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArg)))) {
        overloadId = 0; // keyToAscii(Qt::Key)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_keyToAscii_TypeError;

    // Call function/method
    {
        ::Qt::Key cppArg0 = ((::Qt::Key)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyToAscii(Qt::Key)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            char cppResult = ::QTest::keyToAscii(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_keyToAscii_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Key", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtTest.QTest.keyToAscii", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mouseClick(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseClick(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseClick(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:mouseClick", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 0; // mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mouseClick_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stateKey");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseClick(): got multiple values for keyword argument 'stateKey'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                    goto Sbk_QTestFunc_mouseClick_TypeError;
            }
            value = PyDict_GetItemString(kwds, "pos");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseClick(): got multiple values for keyword argument 'pos'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3]))))
                    goto Sbk_QTestFunc_mouseClick_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseClick(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QTestFunc_mouseClick_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::MouseButton cppArg1 = ((::Qt::MouseButton)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = QFlags<Qt::KeyboardModifier>(0);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPoint cppArg3 = QPoint();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // mouseClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mouseClick(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mouseClick_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.KeyboardModifiers = 0, PySide.QtCore.QPoint = QPoint(), int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mouseClick", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mouseDClick(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseDClick(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseDClick(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:mouseDClick", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 0; // mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mouseDClick_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stateKey");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseDClick(): got multiple values for keyword argument 'stateKey'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                    goto Sbk_QTestFunc_mouseDClick_TypeError;
            }
            value = PyDict_GetItemString(kwds, "pos");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseDClick(): got multiple values for keyword argument 'pos'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3]))))
                    goto Sbk_QTestFunc_mouseDClick_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseDClick(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QTestFunc_mouseDClick_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::MouseButton cppArg1 = ((::Qt::MouseButton)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = QFlags<Qt::KeyboardModifier>(0);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPoint cppArg3 = QPoint();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // mouseDClick(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mouseDClick(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mouseDClick_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.KeyboardModifiers = 0, PySide.QtCore.QPoint = QPoint(), int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mouseDClick", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mouseEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseEvent(): too many arguments");
        return 0;
    } else if (numArgs < 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:mouseEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: mouseEvent(QTest::MouseAction,QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
    if (numArgs >= 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[4])))) {
        if (numArgs == 5) {
            overloadId = 0; // mouseEvent(QTest::MouseAction,QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
            overloadId = 0; // mouseEvent(QTest::MouseAction,QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mouseEvent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseEvent(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                    goto Sbk_QTestFunc_mouseEvent_TypeError;
            }
        }
        ::QTest::MouseAction cppArg0 = ((::QTest::MouseAction)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::MouseButton cppArg2 = ((::Qt::MouseButton)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QFlags<Qt::KeyboardModifier> cppArg3 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QPoint cppArg4 = ::QPoint();
        pythonToCpp[4](pyArgs[4], &cppArg4);
        int cppArg5 = -1;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // mouseEvent(QTest::MouseAction,QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mouseEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mouseEvent_TypeError:
        const char* overloads[] = {"PySide.QtTest.QTest.MouseAction, PySide.QtGui.QWidget, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.KeyboardModifiers, PySide.QtCore.QPoint, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mouseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mouseMove(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseMove(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseMove(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:mouseMove", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: mouseMove(QWidget*,QPoint,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // mouseMove(QWidget*,QPoint,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // mouseMove(QWidget*,QPoint,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // mouseMove(QWidget*,QPoint,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mouseMove_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "pos");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseMove(): got multiple values for keyword argument 'pos'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1]))))
                    goto Sbk_QTestFunc_mouseMove_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseMove(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QTestFunc_mouseMove_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPoint cppArg1 = QPoint();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = -1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // mouseMove(QWidget*,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mouseMove(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mouseMove_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.QPoint = QPoint(), int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mouseMove", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mousePress(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mousePress(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mousePress(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:mousePress", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 0; // mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mousePress_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stateKey");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mousePress(): got multiple values for keyword argument 'stateKey'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                    goto Sbk_QTestFunc_mousePress_TypeError;
            }
            value = PyDict_GetItemString(kwds, "pos");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mousePress(): got multiple values for keyword argument 'pos'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3]))))
                    goto Sbk_QTestFunc_mousePress_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mousePress(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QTestFunc_mousePress_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::MouseButton cppArg1 = ((::Qt::MouseButton)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = QFlags<Qt::KeyboardModifier>(0);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPoint cppArg3 = QPoint();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // mousePress(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mousePress(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mousePress_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.KeyboardModifiers = 0, PySide.QtCore.QPoint = QPoint(), int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mousePress", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_mouseRelease(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseRelease(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseRelease(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:mouseRelease", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 0; // mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_mouseRelease_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stateKey");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseRelease(): got multiple values for keyword argument 'stateKey'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[2]))))
                    goto Sbk_QTestFunc_mouseRelease_TypeError;
            }
            value = PyDict_GetItemString(kwds, "pos");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseRelease(): got multiple values for keyword argument 'pos'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[3]))))
                    goto Sbk_QTestFunc_mouseRelease_TypeError;
            }
            value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.mouseRelease(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                    goto Sbk_QTestFunc_mouseRelease_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::MouseButton cppArg1 = ((::Qt::MouseButton)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::KeyboardModifier> cppArg2 = QFlags<Qt::KeyboardModifier>(0);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPoint cppArg3 = QPoint();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4 = -1;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // mouseRelease(QWidget*,Qt::MouseButton,QFlags<Qt::KeyboardModifier>,QPoint,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::mouseRelease(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_mouseRelease_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.KeyboardModifiers = 0, PySide.QtCore.QPoint = QPoint(), int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.mouseRelease", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_qElementData(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qElementData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qElementData(const char*,int)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // qElementData(const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_qElementData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qElementData(const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = ::QTest::qElementData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_qElementData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.qElementData", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_qExpectFail(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qExpectFail", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: qExpectFail(const char*,const char*,QTest::TestFailMode,const char*,int)
    if (numArgs == 5
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX]), (pyArgs[2])))
        && Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
        overloadId = 0; // qExpectFail(const char*,const char*,QTest::TestFailMode,const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_qExpectFail_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QTest::TestFailMode cppArg2 = ((::QTest::TestFailMode)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        const char* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        int cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // qExpectFail(const char*,const char*,QTest::TestFailMode,const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QTest::qExpectFail(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_qExpectFail_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", " SBK_STR_NAME ", PySide.QtTest.QTest.TestFailMode, " SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.qExpectFail", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_qGlobalData(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qGlobalData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: qGlobalData(const char*,int)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // qGlobalData(const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_qGlobalData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // qGlobalData(const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = ::QTest::qGlobalData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_qGlobalData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.qGlobalData", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_qSkip(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "qSkip", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: qSkip(const char*,QTest::SkipMode,const char*,int)
    if (numArgs == 4
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX]), (pyArgs[1])))
        && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 0; // qSkip(const char*,QTest::SkipMode,const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_qSkip_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTest::SkipMode cppArg1 = ((::QTest::SkipMode)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        const char* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // qSkip(const char*,QTest::SkipMode,const char*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::qSkip(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_qSkip_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", PySide.QtTest.QTest.SkipMode, " SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.qSkip", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_qWaitForWindowShown(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qWaitForWindowShown(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // qWaitForWindowShown(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_qWaitForWindowShown_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qWaitForWindowShown(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QTest::qWaitForWindowShown(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_qWaitForWindowShown_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtTest.QTest.qWaitForWindowShown", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_sendKeyEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.sendKeyEvent(): too many arguments");
        return 0;
    } else if (numArgs < 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.sendKeyEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:sendKeyEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,QString,QFlags<Qt::KeyboardModifier>,int)
    // 1: sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,char,QFlags<Qt::KeyboardModifier>,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_KEY_IDX]), (pyArgs[2])))) {
        if (numArgs >= 5
            && SbkChar_Check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,char,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                overloadId = 1; // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,char,QFlags<Qt::KeyboardModifier>,int)
            }
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 0; // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,QString,QFlags<Qt::KeyboardModifier>,int)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                overloadId = 0; // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,QString,QFlags<Qt::KeyboardModifier>,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_sendKeyEvent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // sendKeyEvent(QTest::KeyAction action, QWidget * widget, Qt::Key code, QString text, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.sendKeyEvent(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QTestFunc_sendKeyEvent_TypeError;
                }
            }
            ::QTest::KeyAction cppArg0 = ((::QTest::KeyAction)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::Key cppArg2 = ((::Qt::Key)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = ::QString();
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QFlags<Qt::KeyboardModifier> cppArg4 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5 = -1;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,QString,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::sendKeyEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // sendKeyEvent(QTest::KeyAction action, QWidget * widget, Qt::Key code, char ascii, QFlags<Qt::KeyboardModifier> modifier, int delay)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "delay");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.sendKeyEvent(): got multiple values for keyword argument 'delay'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QTestFunc_sendKeyEvent_TypeError;
                }
            }
            ::QTest::KeyAction cppArg0 = ((::QTest::KeyAction)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::Key cppArg2 = ((::Qt::Key)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            char cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QFlags<Qt::KeyboardModifier> cppArg4 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5 = -1;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // sendKeyEvent(QTest::KeyAction,QWidget*,Qt::Key,char,QFlags<Qt::KeyboardModifier>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QTest::sendKeyEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_sendKeyEvent_TypeError:
        const char* overloads[] = {"PySide.QtTest.QTest.KeyAction, PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, unicode, PySide.QtCore.Qt.KeyboardModifiers, int = -1", "PySide.QtTest.QTest.KeyAction, PySide.QtGui.QWidget, PySide.QtCore.Qt.Key, char, PySide.QtCore.Qt.KeyboardModifiers, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.sendKeyEvent", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_setBenchmarkResult(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setBenchmarkResult", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setBenchmarkResult(qreal,QTest::QBenchmarkMetric)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setBenchmarkResult(qreal,QTest::QBenchmarkMetric)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_setBenchmarkResult_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTest::QBenchmarkMetric cppArg1 = ((::QTest::QBenchmarkMetric)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setBenchmarkResult(qreal,QTest::QBenchmarkMetric)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::setBenchmarkResult(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_setBenchmarkResult_TypeError:
        const char* overloads[] = {"float, PySide.QtTest.QTest.QBenchmarkMetric", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.setBenchmarkResult", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_simulateEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.simulateEvent(): too many arguments");
        return 0;
    } else if (numArgs < 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.simulateEvent(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOO:simulateEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: simulateEvent(QWidget*,bool,int,QFlags<Qt::KeyboardModifier>,QString,bool,int)
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 0; // simulateEvent(QWidget*,bool,int,QFlags<Qt::KeyboardModifier>,QString,bool,int)
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
            overloadId = 0; // simulateEvent(QWidget*,bool,int,QFlags<Qt::KeyboardModifier>,QString,bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_simulateEvent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "delay");
            if (value && pyArgs[6]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.simulateEvent(): got multiple values for keyword argument 'delay'.");
                return 0;
            } else if (value) {
                pyArgs[6] = value;
                if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6]))))
                    goto Sbk_QTestFunc_simulateEvent_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QFlags<Qt::KeyboardModifier> cppArg3 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = ::QString();
        pythonToCpp[4](pyArgs[4], &cppArg4);
        bool cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        int cppArg6 = -1;
        if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!PyErr_Occurred()) {
            // simulateEvent(QWidget*,bool,int,QFlags<Qt::KeyboardModifier>,QString,bool,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QTest::simulateEvent(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTestFunc_simulateEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, bool, int, PySide.QtCore.Qt.KeyboardModifiers, unicode, bool, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.simulateEvent", overloads);
        return 0;
}

static PyObject* Sbk_QTestFunc_testObject(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // testObject()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = ::QTest::testObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTestFunc_touchEvent(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.touchEvent(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:touchEvent", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: generateTouchEvent(QWidget*,QTouchEvent::DeviceType)
    if (numArgs == 0) {
        overloadId = 0; // generateTouchEvent(QWidget*,QTouchEvent::DeviceType)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // generateTouchEvent(QWidget*,QTouchEvent::DeviceType)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // generateTouchEvent(QWidget*,QTouchEvent::DeviceType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTestFunc_touchEvent_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.touchEvent(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QTestFunc_touchEvent_TypeError;
            }
            value = PyDict_GetItemString(kwds, "deviceType");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtTest.QTest.touchEvent(): got multiple values for keyword argument 'deviceType'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX]), (pyArgs[1]))))
                    goto Sbk_QTestFunc_touchEvent_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTouchEvent::DeviceType cppArg1 = QTouchEvent::TouchScreen;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // generateTouchEvent(QWidget*,QTouchEvent::DeviceType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTest::PySideQTouchEventSequence * cppResult = ::QTest::generateTouchEvent(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtTestTypes[SBK_QTEST_PYSIDEQTOUCHEVENTSEQUENCE_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTestFunc_touchEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, PySide.QtGui.QTouchEvent.DeviceType = QTouchEvent.TouchScreen", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtTest.QTest.touchEvent", overloads);
        return 0;
}

static PyMethodDef Sbk_QTest_methods[] = {
    {"addColumnInternal", (PyCFunction)Sbk_QTestFunc_addColumnInternal, METH_VARARGS|METH_STATIC},
    {"asciiToKey", (PyCFunction)Sbk_QTestFunc_asciiToKey, METH_O|METH_STATIC},
    {"compare_ptr_helper", (PyCFunction)Sbk_QTestFunc_compare_ptr_helper, METH_VARARGS|METH_STATIC},
    {"compare_string_helper", (PyCFunction)Sbk_QTestFunc_compare_string_helper, METH_VARARGS|METH_STATIC},
    {"currentAppName", (PyCFunction)Sbk_QTestFunc_currentAppName, METH_NOARGS|METH_STATIC},
    {"currentDataTag", (PyCFunction)Sbk_QTestFunc_currentDataTag, METH_NOARGS|METH_STATIC},
    {"currentTestFailed", (PyCFunction)Sbk_QTestFunc_currentTestFailed, METH_NOARGS|METH_STATIC},
    {"currentTestFunction", (PyCFunction)Sbk_QTestFunc_currentTestFunction, METH_NOARGS|METH_STATIC},
    {"ignoreMessage", (PyCFunction)Sbk_QTestFunc_ignoreMessage, METH_VARARGS|METH_STATIC},
    {"keyClick", (PyCFunction)Sbk_QTestFunc_keyClick, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"keyClicks", (PyCFunction)Sbk_QTestFunc_keyClicks, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"keyEvent", (PyCFunction)Sbk_QTestFunc_keyEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"keyPress", (PyCFunction)Sbk_QTestFunc_keyPress, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"keyRelease", (PyCFunction)Sbk_QTestFunc_keyRelease, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"keyToAscii", (PyCFunction)Sbk_QTestFunc_keyToAscii, METH_O|METH_STATIC},
    {"mouseClick", (PyCFunction)Sbk_QTestFunc_mouseClick, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"mouseDClick", (PyCFunction)Sbk_QTestFunc_mouseDClick, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"mouseEvent", (PyCFunction)Sbk_QTestFunc_mouseEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"mouseMove", (PyCFunction)Sbk_QTestFunc_mouseMove, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"mousePress", (PyCFunction)Sbk_QTestFunc_mousePress, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"mouseRelease", (PyCFunction)Sbk_QTestFunc_mouseRelease, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"qElementData", (PyCFunction)Sbk_QTestFunc_qElementData, METH_VARARGS|METH_STATIC},
    {"qExpectFail", (PyCFunction)Sbk_QTestFunc_qExpectFail, METH_VARARGS|METH_STATIC},
    {"qGlobalData", (PyCFunction)Sbk_QTestFunc_qGlobalData, METH_VARARGS|METH_STATIC},
    {"qSkip", (PyCFunction)Sbk_QTestFunc_qSkip, METH_VARARGS|METH_STATIC},
    {"qWaitForWindowShown", (PyCFunction)Sbk_QTestFunc_qWaitForWindowShown, METH_O|METH_STATIC},
    {"sendKeyEvent", (PyCFunction)Sbk_QTestFunc_sendKeyEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setBenchmarkResult", (PyCFunction)Sbk_QTestFunc_setBenchmarkResult, METH_VARARGS|METH_STATIC},
    {"simulateEvent", (PyCFunction)Sbk_QTestFunc_simulateEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"testObject", (PyCFunction)Sbk_QTestFunc_testObject, METH_NOARGS|METH_STATIC},
    {"touchEvent", (PyCFunction)Sbk_QTestFunc_touchEvent, METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTest_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTest_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTest_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtTest.QTest",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QTest_traverse,
    /*tp_clear*/            Sbk_QTest_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTest_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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
static void QTest_SkipMode_PythonToCpp_QTest_SkipMode(PyObject* pyIn, void* cppOut) {
    *((::QTest::SkipMode*)cppOut) = (::QTest::SkipMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_SkipMode_PythonToCpp_QTest_SkipMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX]))
        return QTest_SkipMode_PythonToCpp_QTest_SkipMode;
    return 0;
}
static PyObject* QTest_SkipMode_CppToPython_QTest_SkipMode(const void* cppIn) {
    int castCppIn = *((::QTest::SkipMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX], castCppIn);

}

static void QTest_TestFailMode_PythonToCpp_QTest_TestFailMode(PyObject* pyIn, void* cppOut) {
    *((::QTest::TestFailMode*)cppOut) = (::QTest::TestFailMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_TestFailMode_PythonToCpp_QTest_TestFailMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX]))
        return QTest_TestFailMode_PythonToCpp_QTest_TestFailMode;
    return 0;
}
static PyObject* QTest_TestFailMode_CppToPython_QTest_TestFailMode(const void* cppIn) {
    int castCppIn = *((::QTest::TestFailMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX], castCppIn);

}

static void QTest_QBenchmarkMetric_PythonToCpp_QTest_QBenchmarkMetric(PyObject* pyIn, void* cppOut) {
    *((::QTest::QBenchmarkMetric*)cppOut) = (::QTest::QBenchmarkMetric) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_QBenchmarkMetric_PythonToCpp_QTest_QBenchmarkMetric_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX]))
        return QTest_QBenchmarkMetric_PythonToCpp_QTest_QBenchmarkMetric;
    return 0;
}
static PyObject* QTest_QBenchmarkMetric_CppToPython_QTest_QBenchmarkMetric(const void* cppIn) {
    int castCppIn = *((::QTest::QBenchmarkMetric*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX], castCppIn);

}

static void QTest_KeyAction_PythonToCpp_QTest_KeyAction(PyObject* pyIn, void* cppOut) {
    *((::QTest::KeyAction*)cppOut) = (::QTest::KeyAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_KeyAction_PythonToCpp_QTest_KeyAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX]))
        return QTest_KeyAction_PythonToCpp_QTest_KeyAction;
    return 0;
}
static PyObject* QTest_KeyAction_CppToPython_QTest_KeyAction(const void* cppIn) {
    int castCppIn = *((::QTest::KeyAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX], castCppIn);

}

static void QTest_MouseAction_PythonToCpp_QTest_MouseAction(PyObject* pyIn, void* cppOut) {
    *((::QTest::MouseAction*)cppOut) = (::QTest::MouseAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_MouseAction_PythonToCpp_QTest_MouseAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX]))
        return QTest_MouseAction_PythonToCpp_QTest_MouseAction;
    return 0;
}
static PyObject* QTest_MouseAction_CppToPython_QTest_MouseAction(const void* cppIn) {
    int castCppIn = *((::QTest::MouseAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX], castCppIn);

}

static void QTest_AttributeIndex_PythonToCpp_QTest_AttributeIndex(PyObject* pyIn, void* cppOut) {
    *((::QTest::AttributeIndex*)cppOut) = (::QTest::AttributeIndex) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_AttributeIndex_PythonToCpp_QTest_AttributeIndex_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX]))
        return QTest_AttributeIndex_PythonToCpp_QTest_AttributeIndex;
    return 0;
}
static PyObject* QTest_AttributeIndex_CppToPython_QTest_AttributeIndex(const void* cppIn) {
    int castCppIn = *((::QTest::AttributeIndex*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX], castCppIn);

}

static void QTest_LogElementType_PythonToCpp_QTest_LogElementType(PyObject* pyIn, void* cppOut) {
    *((::QTest::LogElementType*)cppOut) = (::QTest::LogElementType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTest_LogElementType_PythonToCpp_QTest_LogElementType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX]))
        return QTest_LogElementType_PythonToCpp_QTest_LogElementType;
    return 0;
}
static PyObject* QTest_LogElementType_CppToPython_QTest_LogElementType(const void* cppIn) {
    int castCppIn = *((::QTest::LogElementType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX], castCppIn);

}

void init_QTest(PyObject* module)
{
    SbkPySide_QtTestTypes[SBK_QTEST_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTest_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTest", "QTest",
        &Sbk_QTest_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'SkipMode'.
    SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "SkipMode",
        "PySide.QtTest.QTest.SkipMode",
        "QTest::SkipMode");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX],
        &Sbk_QTest_Type, "SkipSingle", (long) QTest::SkipSingle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX],
        &Sbk_QTest_Type, "SkipAll", (long) QTest::SkipAll))
        return ;
    // Register converter for enum 'QTest::SkipMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX],
            QTest_SkipMode_CppToPython_QTest_SkipMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_SkipMode_PythonToCpp_QTest_SkipMode,
            is_QTest_SkipMode_PythonToCpp_QTest_SkipMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_SKIPMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::SkipMode");
        Shiboken::Conversions::registerConverterName(converter, "SkipMode");
    }
    // End of 'SkipMode' enum.

    // Initialization of enum 'TestFailMode'.
    SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "TestFailMode",
        "PySide.QtTest.QTest.TestFailMode",
        "QTest::TestFailMode");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX],
        &Sbk_QTest_Type, "Abort", (long) QTest::Abort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX],
        &Sbk_QTest_Type, "Continue", (long) QTest::Continue))
        return ;
    // Register converter for enum 'QTest::TestFailMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX],
            QTest_TestFailMode_CppToPython_QTest_TestFailMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_TestFailMode_PythonToCpp_QTest_TestFailMode,
            is_QTest_TestFailMode_PythonToCpp_QTest_TestFailMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_TESTFAILMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::TestFailMode");
        Shiboken::Conversions::registerConverterName(converter, "TestFailMode");
    }
    // End of 'TestFailMode' enum.

    // Initialization of enum 'QBenchmarkMetric'.
    SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "QBenchmarkMetric",
        "PySide.QtTest.QTest.QBenchmarkMetric",
        "QTest::QBenchmarkMetric");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "FramesPerSecond", (long) QTest::FramesPerSecond))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "BitsPerSecond", (long) QTest::BitsPerSecond))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "BytesPerSecond", (long) QTest::BytesPerSecond))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "WalltimeMilliseconds", (long) QTest::WalltimeMilliseconds))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "CPUTicks", (long) QTest::CPUTicks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "InstructionReads", (long) QTest::InstructionReads))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
        &Sbk_QTest_Type, "Events", (long) QTest::Events))
        return ;
    // Register converter for enum 'QTest::QBenchmarkMetric'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX],
            QTest_QBenchmarkMetric_CppToPython_QTest_QBenchmarkMetric);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_QBenchmarkMetric_PythonToCpp_QTest_QBenchmarkMetric,
            is_QTest_QBenchmarkMetric_PythonToCpp_QTest_QBenchmarkMetric_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_QBENCHMARKMETRIC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::QBenchmarkMetric");
        Shiboken::Conversions::registerConverterName(converter, "QBenchmarkMetric");
    }
    // End of 'QBenchmarkMetric' enum.

    // Initialization of enum 'KeyAction'.
    SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "KeyAction",
        "PySide.QtTest.QTest.KeyAction",
        "QTest::KeyAction");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX],
        &Sbk_QTest_Type, "Press", (long) QTest::Press))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX],
        &Sbk_QTest_Type, "Release", (long) QTest::Release))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX],
        &Sbk_QTest_Type, "Click", (long) QTest::Click))
        return ;
    // Register converter for enum 'QTest::KeyAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX],
            QTest_KeyAction_CppToPython_QTest_KeyAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_KeyAction_PythonToCpp_QTest_KeyAction,
            is_QTest_KeyAction_PythonToCpp_QTest_KeyAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_KEYACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::KeyAction");
        Shiboken::Conversions::registerConverterName(converter, "KeyAction");
    }
    // End of 'KeyAction' enum.

    // Initialization of enum 'MouseAction'.
    SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "MouseAction",
        "PySide.QtTest.QTest.MouseAction",
        "QTest::MouseAction");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
        &Sbk_QTest_Type, "MousePress", (long) QTest::MousePress))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
        &Sbk_QTest_Type, "MouseRelease", (long) QTest::MouseRelease))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
        &Sbk_QTest_Type, "MouseClick", (long) QTest::MouseClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
        &Sbk_QTest_Type, "MouseDClick", (long) QTest::MouseDClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
        &Sbk_QTest_Type, "MouseMove", (long) QTest::MouseMove))
        return ;
    // Register converter for enum 'QTest::MouseAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX],
            QTest_MouseAction_CppToPython_QTest_MouseAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_MouseAction_PythonToCpp_QTest_MouseAction,
            is_QTest_MouseAction_PythonToCpp_QTest_MouseAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_MOUSEACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::MouseAction");
        Shiboken::Conversions::registerConverterName(converter, "MouseAction");
    }
    // End of 'MouseAction' enum.

    // Initialization of enum 'AttributeIndex'.
    SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "AttributeIndex",
        "PySide.QtTest.QTest.AttributeIndex",
        "QTest::AttributeIndex");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Undefined", (long) QTest::AI_Undefined))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Name", (long) QTest::AI_Name))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Result", (long) QTest::AI_Result))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Tests", (long) QTest::AI_Tests))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Failures", (long) QTest::AI_Failures))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Errors", (long) QTest::AI_Errors))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Type", (long) QTest::AI_Type))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Description", (long) QTest::AI_Description))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_PropertyValue", (long) QTest::AI_PropertyValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_QTestVersion", (long) QTest::AI_QTestVersion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_QtVersion", (long) QTest::AI_QtVersion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_File", (long) QTest::AI_File))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Line", (long) QTest::AI_Line))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Metric", (long) QTest::AI_Metric))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Tag", (long) QTest::AI_Tag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Value", (long) QTest::AI_Value))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
        &Sbk_QTest_Type, "AI_Iterations", (long) QTest::AI_Iterations))
        return ;
    // Register converter for enum 'QTest::AttributeIndex'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX],
            QTest_AttributeIndex_CppToPython_QTest_AttributeIndex);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_AttributeIndex_PythonToCpp_QTest_AttributeIndex,
            is_QTest_AttributeIndex_PythonToCpp_QTest_AttributeIndex_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_ATTRIBUTEINDEX_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::AttributeIndex");
        Shiboken::Conversions::registerConverterName(converter, "AttributeIndex");
    }
    // End of 'AttributeIndex' enum.

    // Initialization of enum 'LogElementType'.
    SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTest_Type,
        "LogElementType",
        "PySide.QtTest.QTest.LogElementType",
        "QTest::LogElementType");
    if (!SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Undefined", (long) QTest::LET_Undefined))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Property", (long) QTest::LET_Property))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Properties", (long) QTest::LET_Properties))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Failure", (long) QTest::LET_Failure))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Error", (long) QTest::LET_Error))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_TestCase", (long) QTest::LET_TestCase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_TestSuite", (long) QTest::LET_TestSuite))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_Benchmark", (long) QTest::LET_Benchmark))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
        &Sbk_QTest_Type, "LET_SystemError", (long) QTest::LET_SystemError))
        return ;
    // Register converter for enum 'QTest::LogElementType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX],
            QTest_LogElementType_CppToPython_QTest_LogElementType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTest_LogElementType_PythonToCpp_QTest_LogElementType,
            is_QTest_LogElementType_PythonToCpp_QTest_LogElementType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtTestTypes[SBK_QTEST_LOGELEMENTTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTest::LogElementType");
        Shiboken::Conversions::registerConverterName(converter, "LogElementType");
    }
    // End of 'LogElementType' enum.


    qRegisterMetaType< ::QTest::SkipMode >("QTest::SkipMode");
    qRegisterMetaType< ::QTest::TestFailMode >("QTest::TestFailMode");
    qRegisterMetaType< ::QTest::QBenchmarkMetric >("QTest::QBenchmarkMetric");
    qRegisterMetaType< ::QTest::KeyAction >("QTest::KeyAction");
    qRegisterMetaType< ::QTest::MouseAction >("QTest::MouseAction");
    qRegisterMetaType< ::QTest::AttributeIndex >("QTest::AttributeIndex");
    qRegisterMetaType< ::QTest::LogElementType >("QTest::LogElementType");
}
