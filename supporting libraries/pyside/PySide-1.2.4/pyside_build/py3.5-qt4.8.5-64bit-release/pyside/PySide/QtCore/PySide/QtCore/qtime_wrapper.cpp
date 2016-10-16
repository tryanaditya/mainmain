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
#include "pyside_qtcore_python.h"

#include "qtime_wrapper.h"

// Extra includes
#include <datetime.h>
#include <qdatetime.h>


// Begin code injection

// TEMPLATE - pydatetime_importandcheck_function - START
#ifdef IS_PY3K
#define PySideDateTime_IMPORT PyDateTime_IMPORT
#else
#define PySideDateTime_IMPORT \
        (PyDateTimeAPI = (PyDateTime_CAPI*) PyCObject_Import((char*)"datetime", \
                                                         (char*)"datetime_CAPI"))
#endif
static bool PyDateTime_ImportAndCheck(PyObject* pyIn) {
if (!PyDateTimeAPI) PySideDateTime_IMPORT;
return PyTime_Check(pyIn);
}
// TEMPLATE - pydatetime_importandcheck_function - END

// End of code injection


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTime_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTime >()))
        return -1;

    ::QTime* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QTime()
    // 1: QTime(QTime)
    // 2: QTime(int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QTime()
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QTime(int,int,int,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // QTime(int,int,int,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                overloadId = 2; // QTime(int,int,int,int)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTime(QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTime_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTime()
        {

            if (!PyErr_Occurred()) {
                // QTime()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTime();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTime(const QTime & QTime)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTime(QTime)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTime(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTime(int h, int m, int s, int ms)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "s");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime(): got multiple values for keyword argument 's'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTime_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ms");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime(): got multiple values for keyword argument 'ms'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTime_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QTime(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTime(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTime >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTime_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTime_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QTime", "int, int, int = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTime", overloads);
        return -1;
}

static PyObject* Sbk_QTimeFunc___reduce__(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(iiii))", PyObject_Type(self), cppSelf->hour(), cppSelf->minute(), cppSelf->second(), cppSelf->msec());
            // TEMPLATE - reduce_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeFunc___repr__(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%i, %i, %i, %i)", ((PyObject*)self)->ob_type->tp_name, cppSelf->hour(), cppSelf->minute(), cppSelf->second(), cppSelf->msec());
            pyResult = Shiboken::String::fromCString(qPrintable(format));
            // TEMPLATE - repr_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeFunc_addMSecs(PyObject* self, PyObject* pyArg)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addMSecs(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addMSecs(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_addMSecs_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addMSecs(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QTime*>(cppSelf)->addMSecs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_addMSecs_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTime.addMSecs", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_addSecs(PyObject* self, PyObject* pyArg)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addSecs(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addSecs(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_addSecs_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addSecs(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QTime*>(cppSelf)->addSecs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_addSecs_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTime.addSecs", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_currentTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = ::QTime::currentTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeFunc_elapsed(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // elapsed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->elapsed();
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

static PyObject* Sbk_QTimeFunc_fromString(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.fromString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.fromString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromString", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromString(QString,Qt::DateFormat)
    // 1: fromString(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromString(QString,Qt::DateFormat)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // fromString(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromString(QString,Qt::DateFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_fromString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromString(const QString & s, Qt::DateFormat f)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.fromString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QTimeFunc_fromString_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::DateFormat cppArg1 = Qt::TextDate;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromString(QString,Qt::DateFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTime cppResult = ::QTime::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
            }
            break;
        }
        case 1: // fromString(const QString & s, const QString & format)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromString(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTime cppResult = ::QTime::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_fromString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTime.fromString", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_hour(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hour()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->hour();
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

static PyObject* Sbk_QTimeFunc_isNull(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTime*>(cppSelf)->isNull();
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

static PyObject* Sbk_QTimeFunc_isValid(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.isValid(): too many arguments");
        return 0;
    } else if (numArgs == 1 || numArgs == 2)
        goto Sbk_QTimeFunc_isValid_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:isValid", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: isValid()const
    // 1: isValid(int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // isValid()const
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 1; // isValid(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 1; // isValid(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_isValid_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isValid() const
        {

            if (!PyErr_Occurred()) {
                // isValid()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QTime*>(cppSelf)->isValid();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isValid(int h, int m, int s, int ms)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "ms");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.isValid(): got multiple values for keyword argument 'ms'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QTimeFunc_isValid_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // isValid(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QTime::isValid(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_isValid_TypeError:
        const char* overloads[] = {"", "int, int, int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTime.isValid", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_minute(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minute()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->minute();
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

static PyObject* Sbk_QTimeFunc_msec(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // msec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->msec();
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

static PyObject* Sbk_QTimeFunc_msecsTo(PyObject* self, PyObject* pyArg)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: msecsTo(QTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // msecsTo(QTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_msecsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // msecsTo(QTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->msecsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_msecsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTime.msecsTo", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_restart(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restart()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->restart();
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

static PyObject* Sbk_QTimeFunc_second(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // second()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->second();
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

static PyObject* Sbk_QTimeFunc_secsTo(PyObject* self, PyObject* pyArg)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: secsTo(QTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // secsTo(QTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_secsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // secsTo(QTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTime*>(cppSelf)->secsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_secsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTime.secsTo", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_setHMS(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.setHMS(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.setHMS(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setHMS", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setHMS(int,int,int,int)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // setHMS(int,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // setHMS(int,int,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_setHMS_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "ms");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.setHMS(): got multiple values for keyword argument 'ms'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QTimeFunc_setHMS_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setHMS(int,int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setHMS(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_setHMS_TypeError:
        const char* overloads[] = {"int, int, int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTime.setHMS", overloads);
        return 0;
}

static PyObject* Sbk_QTimeFunc_start(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // start()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTimeFunc_toPython(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPython()
            // Begin code injection

            if (!PyDateTimeAPI) PySideDateTime_IMPORT;
            pyResult = PyTime_FromTime(cppSelf->hour(), cppSelf->minute(), cppSelf->second(), cppSelf->msec()*1000);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.toString(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toString", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toString(Qt::DateFormat)const
    // 1: toString(QString)const
    if (numArgs == 0) {
        overloadId = 0; // toString(Qt::DateFormat)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // toString(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[0])))) {
        overloadId = 0; // toString(Qt::DateFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeFunc_toString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toString(Qt::DateFormat f) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTime.toString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[0]))))
                        goto Sbk_QTimeFunc_toString_TypeError;
                }
            }
            ::Qt::DateFormat cppArg0 = Qt::TextDate;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(Qt::DateFormat)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTime*>(cppSelf)->toString(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // toString(const QString & format) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTime*>(cppSelf)->toString(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTime.toString", overloads);
        return 0;
}

static PyObject* Sbk_QTime___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTime& cppSelf = *(((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTimeMethod_isValid = {
    "isValid", (PyCFunction)Sbk_QTimeFunc_isValid, METH_VARARGS|METH_KEYWORDS|METH_STATIC
};

static PyMethodDef Sbk_QTime_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QTimeFunc___reduce__, METH_NOARGS},
    {"addMSecs", (PyCFunction)Sbk_QTimeFunc_addMSecs, METH_O},
    {"addSecs", (PyCFunction)Sbk_QTimeFunc_addSecs, METH_O},
    {"currentTime", (PyCFunction)Sbk_QTimeFunc_currentTime, METH_NOARGS|METH_STATIC},
    {"elapsed", (PyCFunction)Sbk_QTimeFunc_elapsed, METH_NOARGS},
    {"fromString", (PyCFunction)Sbk_QTimeFunc_fromString, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"hour", (PyCFunction)Sbk_QTimeFunc_hour, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QTimeFunc_isNull, METH_NOARGS},
    Sbk_QTimeMethod_isValid,
    {"minute", (PyCFunction)Sbk_QTimeFunc_minute, METH_NOARGS},
    {"msec", (PyCFunction)Sbk_QTimeFunc_msec, METH_NOARGS},
    {"msecsTo", (PyCFunction)Sbk_QTimeFunc_msecsTo, METH_O},
    {"restart", (PyCFunction)Sbk_QTimeFunc_restart, METH_NOARGS},
    {"second", (PyCFunction)Sbk_QTimeFunc_second, METH_NOARGS},
    {"secsTo", (PyCFunction)Sbk_QTimeFunc_secsTo, METH_O},
    {"setHMS", (PyCFunction)Sbk_QTimeFunc_setHMS, METH_VARARGS|METH_KEYWORDS},
    {"start", (PyCFunction)Sbk_QTimeFunc_start, METH_NOARGS},
    {"toPython", (PyCFunction)Sbk_QTimeFunc_toPython, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QTimeFunc_toString, METH_VARARGS|METH_KEYWORDS},

    {"__copy__", (PyCFunction)Sbk_QTime___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTime_getattro(PyObject* self, PyObject* name)
{
    if (self) {
        // Search the method in the instance dict
        if (reinterpret_cast<SbkObject*>(self)->ob_dict) {
            PyObject* meth = PyDict_GetItem(reinterpret_cast<SbkObject*>(self)->ob_dict, name);
            if (meth) {
                Py_INCREF(meth);
                return meth;
            }
        }
        // Search the method in the type dict
        if (Shiboken::Object::isUserType(self)) {
            PyObject* meth = PyDict_GetItem(self->ob_type->tp_dict, name);
            if (meth)
                return PyFunction_Check(meth) ? SBK_PyMethod_New(meth, self) : PyObject_GenericGetAttr(self, name);
        }
        static PyMethodDef non_static_Sbk_QTimeMethod_isValid = {
            Sbk_QTimeMethod_isValid.ml_name,
            Sbk_QTimeMethod_isValid.ml_meth,
            Sbk_QTimeMethod_isValid.ml_flags & (~METH_STATIC),
            Sbk_QTimeMethod_isValid.ml_doc,
        };
        if (Shiboken::String::compare(name, "isValid") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QTimeMethod_isValid, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

static int Sbk_QTime___nb_bool(PyObject* self)
{
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QTime_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTime& cppSelf = *(((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator!=(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator<(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTime_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator<=(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTime_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator==(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator>(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTime_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
                // operator>=(const QTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTime cppArg0_local = ::QTime();
                ::QTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTime_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QTime_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTime_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QTime_HashFunc(PyObject* self) {
    ::QTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)self));
    return PySide::hash(*cppSelf);
}

static int Sbk_QTime_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTime_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTime_TypeAsNumber;

static SbkObjectType Sbk_QTime_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTime",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QTimeFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QTime_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         Sbk_QTime_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QTime_traverse,
    /*tp_clear*/            Sbk_QTime_clear,
    /*tp_richcompare*/      Sbk_QTime_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTime_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTime_Init,
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
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTime_PythonToCpp_QTime_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTime_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTime_PythonToCpp_QTime_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTime_Type))
        return QTime_PythonToCpp_QTime_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTime_PTR_CppToPython_QTime(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTime*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTime_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTime_COPY_CppToPython_QTime(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTime_Type, new ::QTime(*((::QTime*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTime_PythonToCpp_QTime_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTime*)cppOut) = *((::QTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTime_PythonToCpp_QTime_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTime_Type))
        return QTime_PythonToCpp_QTime_COPY;
    return 0;
}

// Python to C++ conversions for type 'QTime'.
static void Py_None_PythonToCpp_QTime(PyObject* pyIn, void* cppOut) {

    *((::QTime*)cppOut) = QTime();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QTime_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QTime;
    return 0;
}
static void PyTime_PythonToCpp_QTime(PyObject* pyIn, void* cppOut) {

    int hour = PyDateTime_TIME_GET_HOUR(pyIn);
    int min = PyDateTime_TIME_GET_MINUTE(pyIn);
    int sec = PyDateTime_TIME_GET_SECOND(pyIn);
    int usec = PyDateTime_TIME_GET_MICROSECOND(pyIn);
    *((::QTime*)cppOut) = QTime(hour, min, sec, usec/1000);

}
static PythonToCppFunc is_PyTime_PythonToCpp_QTime_Convertible(PyObject* pyIn) {
    if (PyDateTime_ImportAndCheck(pyIn))
        return PyTime_PythonToCpp_QTime;
    return 0;
}

void init_QTime(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTime_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QTime_TypeAsNumber) = Sbk_QTime___nb_bool;
    Sbk_QTime_Type.super.ht_type.tp_as_number = &Sbk_QTime_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QTIME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTime_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTime", "QTime",
        &Sbk_QTime_Type, &Shiboken::callCppDestructor< ::QTime >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTime_Type,
        QTime_PythonToCpp_QTime_PTR,
        is_QTime_PythonToCpp_QTime_PTR_Convertible,
        QTime_PTR_CppToPython_QTime,
        QTime_COPY_CppToPython_QTime);

    Shiboken::Conversions::registerConverterName(converter, "QTime");
    Shiboken::Conversions::registerConverterName(converter, "QTime*");
    Shiboken::Conversions::registerConverterName(converter, "QTime&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTime).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTime_PythonToCpp_QTime_COPY,
        is_QTime_PythonToCpp_QTime_COPY_Convertible);
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Py_None_PythonToCpp_QTime,
        is_Py_None_PythonToCpp_QTime_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PyTime_PythonToCpp_QTime,
        is_PyTime_PythonToCpp_QTime_Convertible);


    // Initialization of enums.



    qRegisterMetaType< ::QTime >("QTime");
}

