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

#include "qdatetime_wrapper.h"

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
return PyDateTime_Check(pyIn);
}
// TEMPLATE - pydatetime_importandcheck_function - END

// End of code injection


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDateTime_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDateTime >()))
        return -1;

    ::QDateTime* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 8) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime(): too many arguments");
        return -1;
    } else if (numArgs == 4 || numArgs == 5)
        goto Sbk_QDateTime_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOOO:QDateTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return -1;


    // Overloaded function decisor
    // 0: QDateTime()
    // 1: QDateTime(QDate)
    // 2: QDateTime(QDate,QTime,Qt::TimeSpec)
    // 3: QDateTime(QDateTime)
    // 4: QDateTime(int,int,int,int,int,int)
    // 5: QDateTime(int,int,int,int,int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QDateTime()
    } else if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 4; // QDateTime(int,int,int,int,int,int)
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
            if (numArgs == 7) {
                overloadId = 5; // QDateTime(int,int,int,int,int,int,int,int)
            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[7])))) {
                overloadId = 5; // QDateTime(int,int,int,int,int,int,int,int)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[0])))) {
        overloadId = 3; // QDateTime(QDateTime)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QDateTime(QDate)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QDateTime(QDate,QTime,Qt::TimeSpec)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), (pyArgs[2])))) {
                overloadId = 2; // QDateTime(QDate,QTime,Qt::TimeSpec)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTime_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDateTime()
        {

            if (!PyErr_Occurred()) {
                // QDateTime()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDateTime();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDateTime(const QDate & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDateTime(QDate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDateTime(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDateTime(const QDate & arg__1, const QTime & arg__2, Qt::TimeSpec spec)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "spec");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime(): got multiple values for keyword argument 'spec'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), (pyArgs[2]))))
                        goto Sbk_QDateTime_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QTime cppArg1_local = ::QTime();
            ::QTime* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::Qt::TimeSpec cppArg2 = Qt::LocalTime;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDateTime(QDate,QTime,Qt::TimeSpec)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDateTime(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QDateTime(const QDateTime & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDateTime(QDateTime)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDateTime(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QDateTime(int arg__1, int arg__2, int arg__3, int arg__4, int arg__5, int arg__6)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            SBK_UNUSED(cppArg4)
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            SBK_UNUSED(cppArg5)

            if (!PyErr_Occurred()) {
                // QDateTime(int,int,int,int,int,int)
                // Begin code injection

                QDate date(cppArg0, cppArg1, cppArg2);
                QTime time(cppArg3, cppArg4, cppArg5);
                cptr = new QDateTime(date, time);

                // End of code injection

            }
            break;
        }
        case 5: // QDateTime(int arg__1, int arg__2, int arg__3, int arg__4, int arg__5, int arg__6, int arg__7, int arg__8)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__8");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime(): got multiple values for keyword argument 'arg__8'.");
                    return -1;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[7]))))
                        goto Sbk_QDateTime_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            SBK_UNUSED(cppArg2)
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            SBK_UNUSED(cppArg4)
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            SBK_UNUSED(cppArg5)
            int cppArg6;
            pythonToCpp[6](pyArgs[6], &cppArg6);
            SBK_UNUSED(cppArg6)
            int cppArg7 = Qt::LocalTime;
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            SBK_UNUSED(cppArg7)

            if (!PyErr_Occurred()) {
                // QDateTime(int,int,int,int,int,int,int,int)
                // Begin code injection

                QDate date(cppArg0, cppArg1, cppArg2);
                QTime time(cppArg3, cppArg4, cppArg5, cppArg6);
                cptr = new QDateTime(date, time, Qt::TimeSpec(cppArg7));

                // End of code injection

            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDateTime >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDateTime_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDateTime_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QDate", "PySide.QtCore.QDate, PySide.QtCore.QTime, PySide.QtCore.Qt.TimeSpec = Qt.LocalTime", "PySide.QtCore.QDateTime", "int, int, int, int, int, int", "int, int, int, int, int, int, int, int = Qt.LocalTime", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDateTime", overloads);
        return -1;
}

static PyObject* Sbk_QDateTimeFunc___reduce__(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(iiiiiiii))", PyObject_Type(self), cppSelf->date().year(), cppSelf->date().month(), cppSelf->date().day(), cppSelf->time().hour(), cppSelf->time().minute(), cppSelf->time().second(), cppSelf->time().msec(), (int)cppSelf->timeSpec());
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

static PyObject* Sbk_QDateTimeFunc___repr__(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%i, %i, %i, %i, %i, %i, %i, %i)", ((PyObject*)self)->ob_type->tp_name, cppSelf->date().year(), cppSelf->date().month(), cppSelf->date().day(), cppSelf->time().hour(), cppSelf->time().minute(), cppSelf->time().second(), cppSelf->time().msec(), (int)cppSelf->timeSpec());
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

static PyObject* Sbk_QDateTimeFunc_addDays(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addDays(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addDays(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_addDays_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addDays(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->addDays(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_addDays_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.addDays", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_addMSecs(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addMSecs(qint64)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // addMSecs(qint64)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_addMSecs_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addMSecs(qint64)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->addMSecs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_addMSecs_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.addMSecs", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_addMonths(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addMonths(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addMonths(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_addMonths_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addMonths(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->addMonths(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_addMonths_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.addMonths", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_addSecs(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateTimeFunc_addSecs_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addSecs(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->addSecs(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_addSecs_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.addSecs", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_addYears(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addYears(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addYears(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_addYears_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addYears(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->addYears(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_addYears_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.addYears", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_currentDateTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDateTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = ::QDateTime::currentDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_currentDateTimeUtc(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDateTimeUtc()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = ::QDateTime::currentDateTimeUtc();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_currentMSecsSinceEpoch(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentMSecsSinceEpoch()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = ::QDateTime::currentMSecsSinceEpoch();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_date(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // date()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDateTime*>(cppSelf)->date();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_daysTo(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: daysTo(QDateTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // daysTo(QDateTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_daysTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // daysTo(QDateTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDateTime*>(cppSelf)->daysTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_daysTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.daysTo", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_fromMSecsSinceEpoch(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromMSecsSinceEpoch(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // fromMSecsSinceEpoch(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_fromMSecsSinceEpoch_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromMSecsSinceEpoch(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = ::QDateTime::fromMSecsSinceEpoch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_fromMSecsSinceEpoch_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.fromMSecsSinceEpoch", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_fromString(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime.fromString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime.fromString(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QDateTimeFunc_fromString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromString(const QString & s, Qt::DateFormat f)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime.fromString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QDateTimeFunc_fromString_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::DateFormat cppArg1 = Qt::TextDate;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromString(QString,Qt::DateFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDateTime cppResult = ::QDateTime::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
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
                QDateTime cppResult = ::QDateTime::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_fromString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDateTime.fromString", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_fromTime_t(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromTime_t(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 0; // fromTime_t(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_fromTime_t_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromTime_t(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = ::QDateTime::fromTime_t(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_fromTime_t_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.fromTime_t", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_isNull(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDateTime*>(cppSelf)->isNull();
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

static PyObject* Sbk_QDateTimeFunc_isValid(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDateTime*>(cppSelf)->isValid();
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

static PyObject* Sbk_QDateTimeFunc_msecsTo(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: msecsTo(QDateTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // msecsTo(QDateTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_msecsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // msecsTo(QDateTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QDateTime*>(cppSelf)->msecsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_msecsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.msecsTo", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_secsTo(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: secsTo(QDateTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // secsTo(QDateTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_secsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // secsTo(QDateTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDateTime*>(cppSelf)->secsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_secsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.secsTo", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setDate(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDate(QDate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 0; // setDate(QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setDate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDate cppArg0_local = ::QDate();
        ::QDate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDate(QDate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setDate", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setMSecsSinceEpoch(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMSecsSinceEpoch(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setMSecsSinceEpoch(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setMSecsSinceEpoch_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMSecsSinceEpoch(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMSecsSinceEpoch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setMSecsSinceEpoch_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setMSecsSinceEpoch", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTime(QTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // setTime(QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setTime_TypeError;

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
            // setTime(QTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setTimeSpec(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTimeSpec(Qt::TimeSpec)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), (pyArg)))) {
        overloadId = 0; // setTimeSpec(Qt::TimeSpec)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setTimeSpec_TypeError;

    // Call function/method
    {
        ::Qt::TimeSpec cppArg0 = ((::Qt::TimeSpec)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTimeSpec(Qt::TimeSpec)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTimeSpec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setTimeSpec_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TimeSpec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setTimeSpec", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setTime_t(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTime_t(uint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArg)))) {
        overloadId = 0; // setTime_t(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setTime_t_TypeError;

    // Call function/method
    {
        uint cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTime_t(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTime_t(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setTime_t_TypeError:
        const char* overloads[] = {"unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setTime_t", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_setUtcOffset(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUtcOffset(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setUtcOffset(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_setUtcOffset_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUtcOffset(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUtcOffset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeFunc_setUtcOffset_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.setUtcOffset", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_time(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // time()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->time();
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

static PyObject* Sbk_QDateTimeFunc_timeSpec(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timeSpec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::TimeSpec cppResult = const_cast<const ::QDateTime*>(cppSelf)->timeSpec();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_toLocalTime(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toLocalTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->toLocalTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_toMSecsSinceEpoch(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toMSecsSinceEpoch()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QDateTime*>(cppSelf)->toMSecsSinceEpoch();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_toPython(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPython()
            // Begin code injection

            QDate date = cppSelf->date();
            QTime time = cppSelf->time();
            if (!PyDateTimeAPI) PySideDateTime_IMPORT;
            pyResult = PyDateTime_FromDateAndTime(date.year(), date.month(), date.day(), time.hour(), time.minute(), time.second(), time.msec()*1000);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime.toString(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QDateTimeFunc_toString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toString(Qt::DateFormat f) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDateTime.toString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[0]))))
                        goto Sbk_QDateTimeFunc_toString_TypeError;
                }
            }
            ::Qt::DateFormat cppArg0 = Qt::TextDate;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(Qt::DateFormat)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QDateTime*>(cppSelf)->toString(cppArg0);
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
                QString cppResult = const_cast<const ::QDateTime*>(cppSelf)->toString(cppArg0);
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

    Sbk_QDateTimeFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDateTime.toString", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_toTimeSpec(PyObject* self, PyObject* pyArg)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toTimeSpec(Qt::TimeSpec)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), (pyArg)))) {
        overloadId = 0; // toTimeSpec(Qt::TimeSpec)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeFunc_toTimeSpec_TypeError;

    // Call function/method
    {
        ::Qt::TimeSpec cppArg0 = ((::Qt::TimeSpec)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toTimeSpec(Qt::TimeSpec)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->toTimeSpec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeFunc_toTimeSpec_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TimeSpec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDateTime.toTimeSpec", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeFunc_toTime_t(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTime_t()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QDateTime*>(cppSelf)->toTime_t();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_toUTC(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toUTC()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTime*>(cppSelf)->toUTC();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeFunc_utcOffset(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // utcOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDateTime*>(cppSelf)->utcOffset();
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

static PyObject* Sbk_QDateTime___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDateTime& cppSelf = *(((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDateTime_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QDateTimeFunc___reduce__, METH_NOARGS},
    {"addDays", (PyCFunction)Sbk_QDateTimeFunc_addDays, METH_O},
    {"addMSecs", (PyCFunction)Sbk_QDateTimeFunc_addMSecs, METH_O},
    {"addMonths", (PyCFunction)Sbk_QDateTimeFunc_addMonths, METH_O},
    {"addSecs", (PyCFunction)Sbk_QDateTimeFunc_addSecs, METH_O},
    {"addYears", (PyCFunction)Sbk_QDateTimeFunc_addYears, METH_O},
    {"currentDateTime", (PyCFunction)Sbk_QDateTimeFunc_currentDateTime, METH_NOARGS|METH_STATIC},
    {"currentDateTimeUtc", (PyCFunction)Sbk_QDateTimeFunc_currentDateTimeUtc, METH_NOARGS|METH_STATIC},
    {"currentMSecsSinceEpoch", (PyCFunction)Sbk_QDateTimeFunc_currentMSecsSinceEpoch, METH_NOARGS|METH_STATIC},
    {"date", (PyCFunction)Sbk_QDateTimeFunc_date, METH_NOARGS},
    {"daysTo", (PyCFunction)Sbk_QDateTimeFunc_daysTo, METH_O},
    {"fromMSecsSinceEpoch", (PyCFunction)Sbk_QDateTimeFunc_fromMSecsSinceEpoch, METH_O|METH_STATIC},
    {"fromString", (PyCFunction)Sbk_QDateTimeFunc_fromString, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromTime_t", (PyCFunction)Sbk_QDateTimeFunc_fromTime_t, METH_O|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QDateTimeFunc_isNull, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QDateTimeFunc_isValid, METH_NOARGS},
    {"msecsTo", (PyCFunction)Sbk_QDateTimeFunc_msecsTo, METH_O},
    {"secsTo", (PyCFunction)Sbk_QDateTimeFunc_secsTo, METH_O},
    {"setDate", (PyCFunction)Sbk_QDateTimeFunc_setDate, METH_O},
    {"setMSecsSinceEpoch", (PyCFunction)Sbk_QDateTimeFunc_setMSecsSinceEpoch, METH_O},
    {"setTime", (PyCFunction)Sbk_QDateTimeFunc_setTime, METH_O},
    {"setTimeSpec", (PyCFunction)Sbk_QDateTimeFunc_setTimeSpec, METH_O},
    {"setTime_t", (PyCFunction)Sbk_QDateTimeFunc_setTime_t, METH_O},
    {"setUtcOffset", (PyCFunction)Sbk_QDateTimeFunc_setUtcOffset, METH_O},
    {"time", (PyCFunction)Sbk_QDateTimeFunc_time, METH_NOARGS},
    {"timeSpec", (PyCFunction)Sbk_QDateTimeFunc_timeSpec, METH_NOARGS},
    {"toLocalTime", (PyCFunction)Sbk_QDateTimeFunc_toLocalTime, METH_NOARGS},
    {"toMSecsSinceEpoch", (PyCFunction)Sbk_QDateTimeFunc_toMSecsSinceEpoch, METH_NOARGS},
    {"toPython", (PyCFunction)Sbk_QDateTimeFunc_toPython, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QDateTimeFunc_toString, METH_VARARGS|METH_KEYWORDS},
    {"toTimeSpec", (PyCFunction)Sbk_QDateTimeFunc_toTimeSpec, METH_O},
    {"toTime_t", (PyCFunction)Sbk_QDateTimeFunc_toTime_t, METH_NOARGS},
    {"toUTC", (PyCFunction)Sbk_QDateTimeFunc_toUTC, METH_NOARGS},
    {"utcOffset", (PyCFunction)Sbk_QDateTimeFunc_utcOffset, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDateTime___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDateTime___nb_bool(PyObject* self)
{
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QDateTime_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDateTime& cppSelf = *(((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator!=(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator<(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDateTime_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator<=(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDateTime_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator==(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator>(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDateTime_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
                // operator>=(const QDateTime & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDateTime cppArg0_local = ::QDateTime();
                ::QDateTime* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDateTime_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QDateTime_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDateTime_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QDateTime_HashFunc(PyObject* self) {
    ::QDateTime* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)self));
    return PySide::hash(*cppSelf);
}

static int Sbk_QDateTime_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDateTime_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDateTime_TypeAsNumber;

static SbkObjectType Sbk_QDateTime_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QDateTime",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QDateTimeFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QDateTime_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QDateTime_traverse,
    /*tp_clear*/            Sbk_QDateTime_clear,
    /*tp_richcompare*/      Sbk_QDateTime_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDateTime_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDateTime_Init,
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
static void QDateTime_PythonToCpp_QDateTime_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDateTime_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDateTime_PythonToCpp_QDateTime_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDateTime_Type))
        return QDateTime_PythonToCpp_QDateTime_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDateTime_PTR_CppToPython_QDateTime(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDateTime*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDateTime_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDateTime_COPY_CppToPython_QDateTime(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDateTime_Type, new ::QDateTime(*((::QDateTime*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDateTime_PythonToCpp_QDateTime_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDateTime*)cppOut) = *((::QDateTime*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDateTime_PythonToCpp_QDateTime_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDateTime_Type))
        return QDateTime_PythonToCpp_QDateTime_COPY;
    return 0;
}

// Python to C++ conversions for type 'QDateTime'.
static void Py_None_PythonToCpp_QDateTime(PyObject* pyIn, void* cppOut) {

    *((::QDateTime*)cppOut) = QDateTime();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QDateTime_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QDateTime;
    return 0;
}
static void PyDateTime_PythonToCpp_QDateTime(PyObject* pyIn, void* cppOut) {

    int day = PyDateTime_GET_DAY(pyIn);
    int month = PyDateTime_GET_MONTH(pyIn);
    int year = PyDateTime_GET_YEAR(pyIn);
    int hour = PyDateTime_DATE_GET_HOUR(pyIn);
    int min = PyDateTime_DATE_GET_MINUTE(pyIn);
    int sec = PyDateTime_DATE_GET_SECOND(pyIn);
    int usec = PyDateTime_DATE_GET_MICROSECOND(pyIn);
    *((::QDateTime*)cppOut) = QDateTime(QDate(year, month, day), QTime(hour, min, sec, usec/1000));

}
static PythonToCppFunc is_PyDateTime_PythonToCpp_QDateTime_Convertible(PyObject* pyIn) {
    if (PyDateTime_ImportAndCheck(pyIn))
        return PyDateTime_PythonToCpp_QDateTime;
    return 0;
}

void init_QDateTime(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDateTime_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDateTime_TypeAsNumber) = Sbk_QDateTime___nb_bool;
    Sbk_QDateTime_Type.super.ht_type.tp_as_number = &Sbk_QDateTime_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDateTime_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDateTime", "QDateTime",
        &Sbk_QDateTime_Type, &Shiboken::callCppDestructor< ::QDateTime >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDateTime_Type,
        QDateTime_PythonToCpp_QDateTime_PTR,
        is_QDateTime_PythonToCpp_QDateTime_PTR_Convertible,
        QDateTime_PTR_CppToPython_QDateTime,
        QDateTime_COPY_CppToPython_QDateTime);

    Shiboken::Conversions::registerConverterName(converter, "QDateTime");
    Shiboken::Conversions::registerConverterName(converter, "QDateTime*");
    Shiboken::Conversions::registerConverterName(converter, "QDateTime&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDateTime).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDateTime_PythonToCpp_QDateTime_COPY,
        is_QDateTime_PythonToCpp_QDateTime_COPY_Convertible);
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Py_None_PythonToCpp_QDateTime,
        is_Py_None_PythonToCpp_QDateTime_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PyDateTime_PythonToCpp_QDateTime,
        is_PyDateTime_PythonToCpp_QDateTime_Convertible);




    qRegisterMetaType< ::QDateTime >("QDateTime");
}

