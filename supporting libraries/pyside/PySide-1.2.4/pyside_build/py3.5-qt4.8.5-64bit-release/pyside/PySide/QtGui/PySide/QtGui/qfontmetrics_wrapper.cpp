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

#include "qfontmetrics_wrapper.h"

// Extra includes
#include <qfont.h>
#include <qfontmetrics.h>
#include <qpaintdevice.h>
#include <qrect.h>
#include <qsize.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFontMetrics_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFontMetrics >()))
        return -1;

    ::QFontMetrics* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFontMetrics", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QFontMetrics(QFont)
    // 1: QFontMetrics(QFont,QPaintDevice*)
    // 2: QFontMetrics(QFontMetrics)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QFontMetrics(QFont)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[1])))) {
            overloadId = 1; // QFontMetrics(QFont,QPaintDevice*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArgs[0])))) {
        overloadId = 2; // QFontMetrics(QFontMetrics)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetrics_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFontMetrics(const QFont & arg__1)
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
                // QFontMetrics(QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetrics(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFontMetrics(const QFont & arg__1, QPaintDevice * pd)
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
                // QFontMetrics(QFont,QPaintDevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetrics(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QFontMetrics(const QFontMetrics & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
            ::QFontMetrics* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFontMetrics(QFontMetrics)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetrics(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFontMetrics >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFontMetrics_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFontMetrics_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", "PySide.QtGui.QFont, PySide.QtGui.QPaintDevice", "PySide.QtGui.QFontMetrics", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics", overloads);
        return -1;
}

static PyObject* Sbk_QFontMetricsFunc_ascent(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ascent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->ascent();
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

static PyObject* Sbk_QFontMetricsFunc_averageCharWidth(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // averageCharWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->averageCharWidth();
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

static PyObject* Sbk_QFontMetricsFunc_boundingRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 8) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QFontMetricsFunc_boundingRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOOO:boundingRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return 0;


    // Overloaded function decisor
    // 0: boundingRect(QRect,int,QString,int,int*)const
    // 1: boundingRect(QString)const
    // 2: boundingRect(int,int,int,int,int,QString,int,int*)const
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 2; // boundingRect(int,int,int,int,int,QString,int,int*)const
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
            if (numArgs == 7) {
                overloadId = 2; // boundingRect(int,int,int,int,int,QString,int,int*)const
            } else if (true) {
                overloadId = 2; // boundingRect(int,int,int,int,int,QString,int,int*)const
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // boundingRect(QString)const
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // boundingRect(QRect,int,QString,int,int*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // boundingRect(QRect,int,QString,int,int*)const
            } else if (true) {
                overloadId = 0; // boundingRect(QRect,int,QString,int,int*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_boundingRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // boundingRect(const QRect & r, int flags, const QString & text, int tabstops, int * tabarray) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "tabstops");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): got multiple values for keyword argument 'tabstops'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QFontMetricsFunc_boundingRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "tabarray");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): got multiple values for keyword argument 'tabarray'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!PyObject_Check(pyArgs[4]))
                        goto Sbk_QFontMetricsFunc_boundingRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // boundingRect(QRect,int,QString,int,int*)const
                // Begin code injection

                int* array = NULL;
                bool errorOccurred = false;

                if (numArgs == 5) {
                    array = Shiboken::sequenceToIntArray(pyArgs[5-1], true);
                    if (PyErr_Occurred()) {
                        if (array)
                            delete []array;
                        errorOccurred = true;
                    }
                }

                if (!errorOccurred) {
                    QRect retval = cppSelf->boundingRect(*cppArg0, cppArg1, cppArg2, cppArg3, array);

                    if (array)
                        delete []array;

                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &retval);
                }

                // End of code injection


            }
            break;
        }
        case 1: // boundingRect(const QString & text) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // boundingRect(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->boundingRect(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 2: // boundingRect(int x, int y, int w, int h, int flags, const QString & text, int tabstops, int * tabarray) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "tabstops");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): got multiple values for keyword argument 'tabstops'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6]))))
                        goto Sbk_QFontMetricsFunc_boundingRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "tabarray");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.boundingRect(): got multiple values for keyword argument 'tabarray'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!PyObject_Check(pyArgs[7]))
                        goto Sbk_QFontMetricsFunc_boundingRect_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QString cppArg5 = ::QString();
            pythonToCpp[5](pyArgs[5], &cppArg5);
            int cppArg6 = 0;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // boundingRect(int,int,int,int,int,QString,int,int*)const
                // Begin code injection

                int* array = NULL;
                bool errorOccurred = false;

                if (numArgs == 8) {
                    array = Shiboken::sequenceToIntArray(pyArgs[8-1], true);
                    if (PyErr_Occurred()) {
                        if (array)
                            delete []array;
                        errorOccurred = true;
                    }
                }

                if (!errorOccurred) {
                    QRect retval = cppSelf->boundingRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, array);

                    if (array)
                        delete []array;

                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &retval);
                }

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_boundingRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, unicode, int = 0, PySide.QtCore.int = 0", "unicode", "int, int, int, int, int, unicode, int = 0, PySide.QtCore.int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics.boundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_boundingRectChar(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boundingRect(QChar)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // boundingRect(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_boundingRectChar_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect(QChar)const
            // Begin code injection

            // TEMPLATE - QFontCharFix - START
            int size = Shiboken::String::len(pyArg);
            if (size == 1) {
            const char *str = Shiboken::String::toCString(pyArg);
            QChar ch(str[0]);
            QRect cppResult = cppSelf->boundingRect(ch);
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            } else {
            PyErr_SetString(PyExc_TypeError, "String must have only one character");
            }
            // TEMPLATE - QFontCharFix - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_boundingRectChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.boundingRectChar", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_charWidth(PyObject* self, PyObject* args)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "charWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: charWidth(QString,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // charWidth(QString,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_charWidth_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // charWidth(QString,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->charWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_charWidth_TypeError:
        const char* overloads[] = {"unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics.charWidth", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_descent(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // descent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->descent();
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

static PyObject* Sbk_QFontMetricsFunc_elidedText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.elidedText(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.elidedText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:elidedText", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: elidedText(QString,Qt::TextElideMode,int,int)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // elidedText(QString,Qt::TextElideMode,int,int)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // elidedText(QString,Qt::TextElideMode,int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_elidedText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.elidedText(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QFontMetricsFunc_elidedText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TextElideMode cppArg1 = ((::Qt::TextElideMode)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // elidedText(QString,Qt::TextElideMode,int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->elidedText(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_elidedText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.TextElideMode, int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics.elidedText", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_height(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->height();
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

static PyObject* Sbk_QFontMetricsFunc_inFont(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inFont(QChar)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // inFont(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_inFont_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inFont(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->inFont(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_inFont_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.inFont", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_inFontUcs4(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inFontUcs4(uint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 0; // inFontUcs4(uint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_inFontUcs4_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inFontUcs4(uint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->inFontUcs4(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_inFontUcs4_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.inFontUcs4", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_leading(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leading()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->leading();
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

static PyObject* Sbk_QFontMetricsFunc_leftBearing(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: leftBearing(QChar)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // leftBearing(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_leftBearing_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // leftBearing(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->leftBearing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_leftBearing_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.leftBearing", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_lineSpacing(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->lineSpacing();
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

static PyObject* Sbk_QFontMetricsFunc_lineWidth(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->lineWidth();
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

static PyObject* Sbk_QFontMetricsFunc_maxWidth(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maxWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->maxWidth();
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

static PyObject* Sbk_QFontMetricsFunc_minLeftBearing(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minLeftBearing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->minLeftBearing();
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

static PyObject* Sbk_QFontMetricsFunc_minRightBearing(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minRightBearing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->minRightBearing();
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

static PyObject* Sbk_QFontMetricsFunc_overlinePos(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overlinePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->overlinePos();
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

static PyObject* Sbk_QFontMetricsFunc_rightBearing(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rightBearing(QChar)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArg)))) {
        overloadId = 0; // rightBearing(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_rightBearing_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rightBearing(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->rightBearing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_rightBearing_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.rightBearing", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_size(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.size(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.size(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:size", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: size(int,QString,int,int*)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // size(int,QString,int,int*)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // size(int,QString,int,int*)const
            } else if (true) {
                overloadId = 0; // size(int,QString,int,int*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_size_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "tabstops");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.size(): got multiple values for keyword argument 'tabstops'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QFontMetricsFunc_size_TypeError;
            }
            value = PyDict_GetItemString(kwds, "tabarray");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.size(): got multiple values for keyword argument 'tabarray'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!PyObject_Check(pyArgs[3]))
                    goto Sbk_QFontMetricsFunc_size_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // size(int,QString,int,int*)const
            // Begin code injection

            int* array = NULL;
            bool errorOccurred = false;

            if (numArgs == 4) {
                array = Shiboken::sequenceToIntArray(pyArgs[4-1], true);
                if (PyErr_Occurred()) {
                    if (array)
                        delete []array;
                    errorOccurred = true;
                }
            }

            if (!errorOccurred) {
                QSize retval = cppSelf->size(cppArg0, cppArg1, cppArg2, array);

                if (array)
                    delete []array;

                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &retval);
            }


            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_size_TypeError:
        const char* overloads[] = {"int, unicode, int = 0, PySide.QtCore.int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics.size", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_strikeOutPos(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // strikeOutPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->strikeOutPos();
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

static PyObject* Sbk_QFontMetricsFunc_tightBoundingRect(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: tightBoundingRect(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // tightBoundingRect(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_tightBoundingRect_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // tightBoundingRect(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->tightBoundingRect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_tightBoundingRect_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.tightBoundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_underlinePos(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underlinePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->underlinePos();
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

static PyObject* Sbk_QFontMetricsFunc_width(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.width(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.width(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:width", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: width(QString,int)const
    // 1: width(QString,int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // width(QString,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // width(QString,int)const
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // width(QString,int,int)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_width_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // width(const QString & arg__1, int len) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "len");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetrics.width(): got multiple values for keyword argument 'len'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QFontMetricsFunc_width_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // width(QString,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->width(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // width(const QString & arg__1, int len, int flags) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // width(QString,int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->width(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_width_TypeError:
        const char* overloads[] = {"unicode, int = -1", "unicode, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetrics.width", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_widthChar(PyObject* self, PyObject* pyArg)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: width(QChar)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // width(QChar)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFunc_widthChar_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width(QChar)const
            // Begin code injection

            // TEMPLATE - QFontCharFix - START
            int size = Shiboken::String::len(pyArg);
            if (size == 1) {
            const char *str = Shiboken::String::toCString(pyArg);
            QChar ch(str[0]);
            int cppResult = cppSelf->width(ch);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            } else {
            PyErr_SetString(PyExc_TypeError, "String must have only one character");
            }
            // TEMPLATE - QFontCharFix - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFunc_widthChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetrics.widthChar", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFunc_xHeight(PyObject* self)
{
    ::QFontMetrics* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // xHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontMetrics*>(cppSelf)->xHeight();
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

static PyObject* Sbk_QFontMetrics___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontMetrics& cppSelf = *(((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFontMetrics_methods[] = {
    {"ascent", (PyCFunction)Sbk_QFontMetricsFunc_ascent, METH_NOARGS},
    {"averageCharWidth", (PyCFunction)Sbk_QFontMetricsFunc_averageCharWidth, METH_NOARGS},
    {"boundingRect", (PyCFunction)Sbk_QFontMetricsFunc_boundingRect, METH_VARARGS|METH_KEYWORDS},
    {"boundingRectChar", (PyCFunction)Sbk_QFontMetricsFunc_boundingRectChar, METH_O},
    {"charWidth", (PyCFunction)Sbk_QFontMetricsFunc_charWidth, METH_VARARGS},
    {"descent", (PyCFunction)Sbk_QFontMetricsFunc_descent, METH_NOARGS},
    {"elidedText", (PyCFunction)Sbk_QFontMetricsFunc_elidedText, METH_VARARGS|METH_KEYWORDS},
    {"height", (PyCFunction)Sbk_QFontMetricsFunc_height, METH_NOARGS},
    {"inFont", (PyCFunction)Sbk_QFontMetricsFunc_inFont, METH_O},
    {"inFontUcs4", (PyCFunction)Sbk_QFontMetricsFunc_inFontUcs4, METH_O},
    {"leading", (PyCFunction)Sbk_QFontMetricsFunc_leading, METH_NOARGS},
    {"leftBearing", (PyCFunction)Sbk_QFontMetricsFunc_leftBearing, METH_O},
    {"lineSpacing", (PyCFunction)Sbk_QFontMetricsFunc_lineSpacing, METH_NOARGS},
    {"lineWidth", (PyCFunction)Sbk_QFontMetricsFunc_lineWidth, METH_NOARGS},
    {"maxWidth", (PyCFunction)Sbk_QFontMetricsFunc_maxWidth, METH_NOARGS},
    {"minLeftBearing", (PyCFunction)Sbk_QFontMetricsFunc_minLeftBearing, METH_NOARGS},
    {"minRightBearing", (PyCFunction)Sbk_QFontMetricsFunc_minRightBearing, METH_NOARGS},
    {"overlinePos", (PyCFunction)Sbk_QFontMetricsFunc_overlinePos, METH_NOARGS},
    {"rightBearing", (PyCFunction)Sbk_QFontMetricsFunc_rightBearing, METH_O},
    {"size", (PyCFunction)Sbk_QFontMetricsFunc_size, METH_VARARGS|METH_KEYWORDS},
    {"strikeOutPos", (PyCFunction)Sbk_QFontMetricsFunc_strikeOutPos, METH_NOARGS},
    {"tightBoundingRect", (PyCFunction)Sbk_QFontMetricsFunc_tightBoundingRect, METH_O},
    {"underlinePos", (PyCFunction)Sbk_QFontMetricsFunc_underlinePos, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QFontMetricsFunc_width, METH_VARARGS|METH_KEYWORDS},
    {"widthChar", (PyCFunction)Sbk_QFontMetricsFunc_widthChar, METH_O},
    {"xHeight", (PyCFunction)Sbk_QFontMetricsFunc_xHeight, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QFontMetrics___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QFontMetrics_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontMetrics& cppSelf = *(((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArg)))) {
                // operator!=(const QFontMetrics & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
                ::QFontMetrics* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArg)))) {
                // operator!=(const QFontMetrics & other)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
                ::QFontMetrics* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArg)))) {
                // operator==(const QFontMetrics & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
                ::QFontMetrics* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArg)))) {
                // operator==(const QFontMetrics & other)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
                ::QFontMetrics* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp))
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
            goto Sbk_QFontMetrics_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QFontMetrics_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QFontMetrics_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFontMetrics_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFontMetrics_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFontMetrics",
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
    /*tp_traverse*/         Sbk_QFontMetrics_traverse,
    /*tp_clear*/            Sbk_QFontMetrics_clear,
    /*tp_richcompare*/      Sbk_QFontMetrics_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFontMetrics_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFontMetrics_Init,
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
static void QFontMetrics_PythonToCpp_QFontMetrics_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFontMetrics_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFontMetrics_PythonToCpp_QFontMetrics_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontMetrics_Type))
        return QFontMetrics_PythonToCpp_QFontMetrics_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFontMetrics_PTR_CppToPython_QFontMetrics(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFontMetrics*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFontMetrics_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QFontMetrics_COPY_CppToPython_QFontMetrics(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QFontMetrics_Type, new ::QFontMetrics(*((::QFontMetrics*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QFontMetrics_PythonToCpp_QFontMetrics_COPY(PyObject* pyIn, void* cppOut) {
    *((::QFontMetrics*)cppOut) = *((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QFontMetrics_PythonToCpp_QFontMetrics_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontMetrics_Type))
        return QFontMetrics_PythonToCpp_QFontMetrics_COPY;
    return 0;
}

// Implicit conversions.
static void constQFontREF_PythonToCpp_QFontMetrics(PyObject* pyIn, void* cppOut) {
    *((::QFontMetrics*)cppOut) = ::QFontMetrics(*((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQFontREF_PythonToCpp_QFontMetrics_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pyIn))
        return constQFontREF_PythonToCpp_QFontMetrics;
    return 0;
}

void init_QFontMetrics(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFontMetrics_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFontMetrics", "QFontMetrics",
        &Sbk_QFontMetrics_Type, &Shiboken::callCppDestructor< ::QFontMetrics >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFontMetrics_Type,
        QFontMetrics_PythonToCpp_QFontMetrics_PTR,
        is_QFontMetrics_PythonToCpp_QFontMetrics_PTR_Convertible,
        QFontMetrics_PTR_CppToPython_QFontMetrics,
        QFontMetrics_COPY_CppToPython_QFontMetrics);

    Shiboken::Conversions::registerConverterName(converter, "QFontMetrics");
    Shiboken::Conversions::registerConverterName(converter, "QFontMetrics*");
    Shiboken::Conversions::registerConverterName(converter, "QFontMetrics&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFontMetrics).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFontMetrics_PythonToCpp_QFontMetrics_COPY,
        is_QFontMetrics_PythonToCpp_QFontMetrics_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQFontREF_PythonToCpp_QFontMetrics,
        is_constQFontREF_PythonToCpp_QFontMetrics_Convertible);


}
