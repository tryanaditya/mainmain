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

#include "qfontmetricsf_wrapper.h"

// Extra includes
#include <qfont.h>
#include <qfontmetrics.h>
#include <qpaintdevice.h>
#include <qrect.h>
#include <qsize.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFontMetricsF_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFontMetricsF >()))
        return -1;

    ::QFontMetricsF* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFontMetricsF", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QFontMetricsF(QFont)
    // 1: QFontMetricsF(QFont,QPaintDevice*)
    // 2: QFontMetricsF(QFontMetrics)
    // 3: QFontMetricsF(QFontMetricsF)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QFontMetricsF(QFont)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[1])))) {
            overloadId = 1; // QFontMetricsF(QFont,QPaintDevice*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArgs[0])))) {
        overloadId = 2; // QFontMetricsF(QFontMetrics)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (pyArgs[0])))) {
        overloadId = 3; // QFontMetricsF(QFontMetricsF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsF_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFontMetricsF(const QFont & arg__1)
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
                // QFontMetricsF(QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetricsF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFontMetricsF(const QFont & arg__1, QPaintDevice * pd)
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
                // QFontMetricsF(QFont,QPaintDevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetricsF(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QFontMetricsF(const QFontMetrics & arg__1)
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
                // QFontMetricsF(QFontMetrics)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetricsF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QFontMetricsF(const QFontMetricsF & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFontMetricsF cppArg0_local = ::QFontMetricsF(::QFont());
            ::QFontMetricsF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFontMetricsF(QFontMetricsF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontMetricsF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFontMetricsF >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFontMetricsF_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFontMetricsF_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", "PySide.QtGui.QFont, PySide.QtGui.QPaintDevice", "PySide.QtGui.QFontMetrics", "PySide.QtGui.QFontMetricsF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetricsF", overloads);
        return -1;
}

static PyObject* Sbk_QFontMetricsFFunc_ascent(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ascent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->ascent();
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

static PyObject* Sbk_QFontMetricsFFunc_averageCharWidth(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // averageCharWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->averageCharWidth();
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

static PyObject* Sbk_QFontMetricsFFunc_boundingRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.boundingRect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.boundingRect(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QFontMetricsFFunc_boundingRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:boundingRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: boundingRect(QRectF,int,QString,int,int*)const
    // 1: boundingRect(QString)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // boundingRect(QString)const
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // boundingRect(QRectF,int,QString,int,int*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // boundingRect(QRectF,int,QString,int,int*)const
            } else if (true) {
                overloadId = 0; // boundingRect(QRectF,int,QString,int,int*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_boundingRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // boundingRect(const QRectF & r, int flags, const QString & string, int tabstops, int * tabarray) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "tabstops");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.boundingRect(): got multiple values for keyword argument 'tabstops'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QFontMetricsFFunc_boundingRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "tabarray");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.boundingRect(): got multiple values for keyword argument 'tabarray'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!PyObject_Check(pyArgs[4]))
                        goto Sbk_QFontMetricsFFunc_boundingRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
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
                // boundingRect(QRectF,int,QString,int,int*)const
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
                    QRectF retval = cppSelf->boundingRect(*cppArg0, cppArg1, cppArg2, cppArg3, array);

                    if (array)
                        delete []array;

                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &retval);
                }

                // End of code injection


            }
            break;
        }
        case 1: // boundingRect(const QString & string) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // boundingRect(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->boundingRect(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_boundingRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, int, unicode, int = 0, PySide.QtCore.int = 0", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetricsF.boundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_boundingRectChar(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_boundingRectChar_TypeError;

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
            QRectF cppResult = cppSelf->boundingRect(ch);
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
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

    Sbk_QFontMetricsFFunc_boundingRectChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.boundingRectChar", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_descent(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // descent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->descent();
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

static PyObject* Sbk_QFontMetricsFFunc_elidedText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.elidedText(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.elidedText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:elidedText", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: elidedText(QString,Qt::TextElideMode,qreal,int)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // elidedText(QString,Qt::TextElideMode,qreal,int)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // elidedText(QString,Qt::TextElideMode,qreal,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_elidedText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.elidedText(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QFontMetricsFFunc_elidedText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::TextElideMode cppArg1 = ((::Qt::TextElideMode)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // elidedText(QString,Qt::TextElideMode,qreal,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->elidedText(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_elidedText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.TextElideMode, float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetricsF.elidedText", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_height(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->height();
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

static PyObject* Sbk_QFontMetricsFFunc_inFont(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_inFont_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inFont(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->inFont(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_inFont_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.inFont", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_inFontUcs4(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_inFontUcs4_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inFontUcs4(uint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->inFontUcs4(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_inFontUcs4_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.inFontUcs4", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_leading(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leading()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->leading();
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

static PyObject* Sbk_QFontMetricsFFunc_leftBearing(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_leftBearing_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // leftBearing(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->leftBearing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_leftBearing_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.leftBearing", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_lineSpacing(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->lineSpacing();
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

static PyObject* Sbk_QFontMetricsFFunc_lineWidth(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->lineWidth();
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

static PyObject* Sbk_QFontMetricsFFunc_maxWidth(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maxWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->maxWidth();
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

static PyObject* Sbk_QFontMetricsFFunc_minLeftBearing(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minLeftBearing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->minLeftBearing();
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

static PyObject* Sbk_QFontMetricsFFunc_minRightBearing(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minRightBearing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->minRightBearing();
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

static PyObject* Sbk_QFontMetricsFFunc_overlinePos(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overlinePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->overlinePos();
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

static PyObject* Sbk_QFontMetricsFFunc_rightBearing(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_rightBearing_TypeError;

    // Call function/method
    {
        ::QChar cppArg0 = ::QChar();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rightBearing(QChar)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->rightBearing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_rightBearing_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.rightBearing", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_size(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.size(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.size(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_size_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "tabstops");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.size(): got multiple values for keyword argument 'tabstops'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QFontMetricsFFunc_size_TypeError;
            }
            value = PyDict_GetItemString(kwds, "tabarray");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontMetricsF.size(): got multiple values for keyword argument 'tabarray'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!PyObject_Check(pyArgs[3]))
                    goto Sbk_QFontMetricsFFunc_size_TypeError;
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
                QSizeF retval = cppSelf->size(cppArg0, cppArg1, cppArg2, array);

                if (array)
                    delete []array;

                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &retval);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_size_TypeError:
        const char* overloads[] = {"int, unicode, int = 0, PySide.QtCore.int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontMetricsF.size", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_strikeOutPos(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // strikeOutPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->strikeOutPos();
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

static PyObject* Sbk_QFontMetricsFFunc_tightBoundingRect(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_tightBoundingRect_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // tightBoundingRect(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->tightBoundingRect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_tightBoundingRect_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.tightBoundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_underlinePos(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // underlinePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->underlinePos();
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

static PyObject* Sbk_QFontMetricsFFunc_width(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: width(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // width(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_width_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // width(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->width(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontMetricsFFunc_width_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.width", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_widthChar(PyObject* self, PyObject* pyArg)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFontMetricsFFunc_widthChar_TypeError;

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
            qreal cppResult = cppSelf->width(ch);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
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

    Sbk_QFontMetricsFFunc_widthChar_TypeError:
        const char* overloads[] = {"1-unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontMetricsF.widthChar", overloads);
        return 0;
}

static PyObject* Sbk_QFontMetricsFFunc_xHeight(PyObject* self)
{
    ::QFontMetricsF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // xHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QFontMetricsF*>(cppSelf)->xHeight();
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

static PyObject* Sbk_QFontMetricsF___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontMetricsF& cppSelf = *(((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFontMetricsF_methods[] = {
    {"ascent", (PyCFunction)Sbk_QFontMetricsFFunc_ascent, METH_NOARGS},
    {"averageCharWidth", (PyCFunction)Sbk_QFontMetricsFFunc_averageCharWidth, METH_NOARGS},
    {"boundingRect", (PyCFunction)Sbk_QFontMetricsFFunc_boundingRect, METH_VARARGS|METH_KEYWORDS},
    {"boundingRectChar", (PyCFunction)Sbk_QFontMetricsFFunc_boundingRectChar, METH_O},
    {"descent", (PyCFunction)Sbk_QFontMetricsFFunc_descent, METH_NOARGS},
    {"elidedText", (PyCFunction)Sbk_QFontMetricsFFunc_elidedText, METH_VARARGS|METH_KEYWORDS},
    {"height", (PyCFunction)Sbk_QFontMetricsFFunc_height, METH_NOARGS},
    {"inFont", (PyCFunction)Sbk_QFontMetricsFFunc_inFont, METH_O},
    {"inFontUcs4", (PyCFunction)Sbk_QFontMetricsFFunc_inFontUcs4, METH_O},
    {"leading", (PyCFunction)Sbk_QFontMetricsFFunc_leading, METH_NOARGS},
    {"leftBearing", (PyCFunction)Sbk_QFontMetricsFFunc_leftBearing, METH_O},
    {"lineSpacing", (PyCFunction)Sbk_QFontMetricsFFunc_lineSpacing, METH_NOARGS},
    {"lineWidth", (PyCFunction)Sbk_QFontMetricsFFunc_lineWidth, METH_NOARGS},
    {"maxWidth", (PyCFunction)Sbk_QFontMetricsFFunc_maxWidth, METH_NOARGS},
    {"minLeftBearing", (PyCFunction)Sbk_QFontMetricsFFunc_minLeftBearing, METH_NOARGS},
    {"minRightBearing", (PyCFunction)Sbk_QFontMetricsFFunc_minRightBearing, METH_NOARGS},
    {"overlinePos", (PyCFunction)Sbk_QFontMetricsFFunc_overlinePos, METH_NOARGS},
    {"rightBearing", (PyCFunction)Sbk_QFontMetricsFFunc_rightBearing, METH_O},
    {"size", (PyCFunction)Sbk_QFontMetricsFFunc_size, METH_VARARGS|METH_KEYWORDS},
    {"strikeOutPos", (PyCFunction)Sbk_QFontMetricsFFunc_strikeOutPos, METH_NOARGS},
    {"tightBoundingRect", (PyCFunction)Sbk_QFontMetricsFFunc_tightBoundingRect, METH_O},
    {"underlinePos", (PyCFunction)Sbk_QFontMetricsFFunc_underlinePos, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QFontMetricsFFunc_width, METH_O},
    {"widthChar", (PyCFunction)Sbk_QFontMetricsFFunc_widthChar, METH_O},
    {"xHeight", (PyCFunction)Sbk_QFontMetricsFFunc_xHeight, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QFontMetricsF___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QFontMetricsF_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontMetricsF& cppSelf = *(((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (pyArg)))) {
                // operator!=(const QFontMetricsF & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetricsF cppArg0_local = ::QFontMetricsF(::QFont());
                ::QFontMetricsF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (pyArg)))) {
                // operator!=(const QFontMetricsF & other)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetricsF cppArg0_local = ::QFontMetricsF(::QFont());
                ::QFontMetricsF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (pyArg)))) {
                // operator==(const QFontMetricsF & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetricsF cppArg0_local = ::QFontMetricsF(::QFont());
                ::QFontMetricsF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (pyArg)))) {
                // operator==(const QFontMetricsF & other)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QFontMetricsF cppArg0_local = ::QFontMetricsF(::QFont());
                ::QFontMetricsF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], pythonToCpp))
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
            goto Sbk_QFontMetricsF_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QFontMetricsF_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QFontMetricsF_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFontMetricsF_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFontMetricsF_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFontMetricsF",
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
    /*tp_traverse*/         Sbk_QFontMetricsF_traverse,
    /*tp_clear*/            Sbk_QFontMetricsF_clear,
    /*tp_richcompare*/      Sbk_QFontMetricsF_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFontMetricsF_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFontMetricsF_Init,
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
static void QFontMetricsF_PythonToCpp_QFontMetricsF_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFontMetricsF_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFontMetricsF_PythonToCpp_QFontMetricsF_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontMetricsF_Type))
        return QFontMetricsF_PythonToCpp_QFontMetricsF_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFontMetricsF_PTR_CppToPython_QFontMetricsF(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFontMetricsF*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFontMetricsF_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QFontMetricsF_COPY_CppToPython_QFontMetricsF(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QFontMetricsF_Type, new ::QFontMetricsF(*((::QFontMetricsF*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QFontMetricsF_PythonToCpp_QFontMetricsF_COPY(PyObject* pyIn, void* cppOut) {
    *((::QFontMetricsF*)cppOut) = *((::QFontMetricsF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QFontMetricsF_PythonToCpp_QFontMetricsF_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontMetricsF_Type))
        return QFontMetricsF_PythonToCpp_QFontMetricsF_COPY;
    return 0;
}

// Implicit conversions.
static void constQFontREF_PythonToCpp_QFontMetricsF(PyObject* pyIn, void* cppOut) {
    *((::QFontMetricsF*)cppOut) = ::QFontMetricsF(*((::QFont*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQFontREF_PythonToCpp_QFontMetricsF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pyIn))
        return constQFontREF_PythonToCpp_QFontMetricsF;
    return 0;
}

static void constQFontMetricsREF_PythonToCpp_QFontMetricsF(PyObject* pyIn, void* cppOut) {
    *((::QFontMetricsF*)cppOut) = ::QFontMetricsF(*((::QFontMetrics*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQFontMetricsREF_PythonToCpp_QFontMetricsF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pyIn))
        return constQFontMetricsREF_PythonToCpp_QFontMetricsF;
    return 0;
}

void init_QFontMetricsF(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFONTMETRICSF_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFontMetricsF_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFontMetricsF", "QFontMetricsF",
        &Sbk_QFontMetricsF_Type, &Shiboken::callCppDestructor< ::QFontMetricsF >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFontMetricsF_Type,
        QFontMetricsF_PythonToCpp_QFontMetricsF_PTR,
        is_QFontMetricsF_PythonToCpp_QFontMetricsF_PTR_Convertible,
        QFontMetricsF_PTR_CppToPython_QFontMetricsF,
        QFontMetricsF_COPY_CppToPython_QFontMetricsF);

    Shiboken::Conversions::registerConverterName(converter, "QFontMetricsF");
    Shiboken::Conversions::registerConverterName(converter, "QFontMetricsF*");
    Shiboken::Conversions::registerConverterName(converter, "QFontMetricsF&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFontMetricsF).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFontMetricsF_PythonToCpp_QFontMetricsF_COPY,
        is_QFontMetricsF_PythonToCpp_QFontMetricsF_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQFontREF_PythonToCpp_QFontMetricsF,
        is_constQFontREF_PythonToCpp_QFontMetricsF_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQFontMetricsREF_PythonToCpp_QFontMetricsF,
        is_constQFontMetricsREF_PythonToCpp_QFontMetricsF_Convertible);


}
