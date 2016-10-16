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

#include "qdate_wrapper.h"

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
return PyDate_Check(pyIn);
}
// TEMPLATE - pydatetime_importandcheck_function - END

// End of code injection


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDate_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDate >()))
        return -1;

    ::QDate* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QDate_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QDate", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QDate()
    // 1: QDate(QDate)
    // 2: QDate(int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QDate()
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 2; // QDate(int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDate(QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDate_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDate()
        {

            if (!PyErr_Occurred()) {
                // QDate()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDate();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDate(const QDate & QDate)
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
                // QDate(QDate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDate(int y, int m, int d)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDate(int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDate(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDate >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDate_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDate_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QDate", "int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate", overloads);
        return -1;
}

static PyObject* Sbk_QDateFunc___reduce__(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(iii))", PyObject_Type(self), cppSelf->year(), cppSelf->month(), cppSelf->day());
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

static PyObject* Sbk_QDateFunc___repr__(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%i, %i, %i)", ((PyObject*)self)->ob_type->tp_name, cppSelf->year(), cppSelf->month(), cppSelf->day());
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

static PyObject* Sbk_QDateFunc_addDays(PyObject* self, PyObject* pyArg)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateFunc_addDays_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addDays(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDate*>(cppSelf)->addDays(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_addDays_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.addDays", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_addMonths(PyObject* self, PyObject* pyArg)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateFunc_addMonths_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addMonths(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDate*>(cppSelf)->addMonths(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_addMonths_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.addMonths", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_addYears(PyObject* self, PyObject* pyArg)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateFunc_addYears_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addYears(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDate*>(cppSelf)->addYears(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_addYears_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.addYears", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_currentDate(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = ::QDate::currentDate();
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

static PyObject* Sbk_QDateFunc_day(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // day()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->day();
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

static PyObject* Sbk_QDateFunc_dayOfWeek(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dayOfWeek()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->dayOfWeek();
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

static PyObject* Sbk_QDateFunc_dayOfYear(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dayOfYear()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->dayOfYear();
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

static PyObject* Sbk_QDateFunc_daysInMonth(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // daysInMonth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->daysInMonth();
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

static PyObject* Sbk_QDateFunc_daysInYear(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // daysInYear()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->daysInYear();
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

static PyObject* Sbk_QDateFunc_daysTo(PyObject* self, PyObject* pyArg)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: daysTo(QDate)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 0; // daysTo(QDate)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_daysTo_TypeError;

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
            // daysTo(QDate)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->daysTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_daysTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.daysTo", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_fromJulianDay(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromJulianDay(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fromJulianDay(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_fromJulianDay_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromJulianDay(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = ::QDate::fromJulianDay(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_fromJulianDay_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.fromJulianDay", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_fromString(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDate.fromString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDate.fromString(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QDateFunc_fromString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromString(const QString & s, Qt::DateFormat f)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDate.fromString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QDateFunc_fromString_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::DateFormat cppArg1 = Qt::TextDate;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromString(QString,Qt::DateFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDate cppResult = ::QDate::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
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
                QDate cppResult = ::QDate::fromString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_fromString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.fromString", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_getDate(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDate(int*,int*,int*)
            // Begin code injection

            int year, month, day;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getDate(&year, &month, &day);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &year));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &month));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &day));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateFunc_gregorianToJulian(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "gregorianToJulian", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: gregorianToJulian(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // gregorianToJulian(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_gregorianToJulian_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // gregorianToJulian(int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = ::QDate::gregorianToJulian(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_gregorianToJulian_TypeError:
        const char* overloads[] = {"int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.gregorianToJulian", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_isLeapYear(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isLeapYear(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // isLeapYear(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_isLeapYear_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isLeapYear(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QDate::isLeapYear(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_isLeapYear_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDate.isLeapYear", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_isNull(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDate*>(cppSelf)->isNull();
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

static PyObject* Sbk_QDateFunc_isValid(PyObject* self, PyObject* args)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 1 || numArgs == 2)
        goto Sbk_QDateFunc_isValid_TypeError;

    if (!PyArg_UnpackTuple(args, "isValid", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: isValid()const
    // 1: isValid(int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // isValid()const
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // isValid(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_isValid_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isValid() const
        {

            if (!PyErr_Occurred()) {
                // isValid()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDate*>(cppSelf)->isValid();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isValid(int y, int m, int d)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // isValid(int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDate::isValid(cppArg0, cppArg1, cppArg2);
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

    Sbk_QDateFunc_isValid_TypeError:
        const char* overloads[] = {"", "int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.isValid", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_longDayName(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "longDayName", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: longDayName(int)
    // 1: longDayName(int,QDate::MonthNameType)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // longDayName(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // longDayName(int,QDate::MonthNameType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_longDayName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // longDayName(int weekday)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // longDayName(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::longDayName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // longDayName(int weekday, QDate::MonthNameType type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDate::MonthNameType cppArg1 = ((::QDate::MonthNameType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // longDayName(int,QDate::MonthNameType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::longDayName(cppArg0, cppArg1);
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

    Sbk_QDateFunc_longDayName_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtCore.QDate.MonthNameType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.longDayName", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_longMonthName(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "longMonthName", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: longMonthName(int)
    // 1: longMonthName(int,QDate::MonthNameType)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // longMonthName(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // longMonthName(int,QDate::MonthNameType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_longMonthName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // longMonthName(int month)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // longMonthName(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::longMonthName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // longMonthName(int month, QDate::MonthNameType type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDate::MonthNameType cppArg1 = ((::QDate::MonthNameType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // longMonthName(int,QDate::MonthNameType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::longMonthName(cppArg0, cppArg1);
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

    Sbk_QDateFunc_longMonthName_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtCore.QDate.MonthNameType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.longMonthName", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_month(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // month()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->month();
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

static PyObject* Sbk_QDateFunc_setDate(PyObject* self, PyObject* args)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDate", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setDate(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // setDate(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_setDate_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setDate(int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setDate(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_setDate_TypeError:
        const char* overloads[] = {"int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.setDate", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_setYMD(PyObject* self, PyObject* args)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setYMD", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setYMD(int,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // setYMD(int,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_setYMD_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setYMD(int,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setYMD(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateFunc_setYMD_TypeError:
        const char* overloads[] = {"int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.setYMD", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_shortDayName(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "shortDayName", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: shortDayName(int)
    // 1: shortDayName(int,QDate::MonthNameType)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // shortDayName(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // shortDayName(int,QDate::MonthNameType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_shortDayName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // shortDayName(int weekday)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // shortDayName(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::shortDayName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // shortDayName(int weekday, QDate::MonthNameType type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDate::MonthNameType cppArg1 = ((::QDate::MonthNameType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // shortDayName(int,QDate::MonthNameType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::shortDayName(cppArg0, cppArg1);
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

    Sbk_QDateFunc_shortDayName_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtCore.QDate.MonthNameType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.shortDayName", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_shortMonthName(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "shortMonthName", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: shortMonthName(int)
    // 1: shortMonthName(int,QDate::MonthNameType)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // shortMonthName(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // shortMonthName(int,QDate::MonthNameType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateFunc_shortMonthName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // shortMonthName(int month)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // shortMonthName(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::shortMonthName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // shortMonthName(int month, QDate::MonthNameType type)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDate::MonthNameType cppArg1 = ((::QDate::MonthNameType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // shortMonthName(int,QDate::MonthNameType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QDate::shortMonthName(cppArg0, cppArg1);
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

    Sbk_QDateFunc_shortMonthName_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtCore.QDate.MonthNameType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.shortMonthName", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_toJulianDay(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toJulianDay()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->toJulianDay();
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

static PyObject* Sbk_QDateFunc_toPython(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPython()
            // Begin code injection

            if (!PyDateTimeAPI) PySideDateTime_IMPORT;
            pyResult = PyDate_FromDate(cppSelf->year(), cppSelf->month(), cppSelf->day());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDate.toString(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QDateFunc_toString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toString(Qt::DateFormat f) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDate.toString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DATEFORMAT_IDX]), (pyArgs[0]))))
                        goto Sbk_QDateFunc_toString_TypeError;
                }
            }
            ::Qt::DateFormat cppArg0 = Qt::TextDate;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(Qt::DateFormat)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QDate*>(cppSelf)->toString(cppArg0);
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
                QString cppResult = const_cast<const ::QDate*>(cppSelf)->toString(cppArg0);
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

    Sbk_QDateFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DateFormat = Qt.TextDate", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDate.toString", overloads);
        return 0;
}

static PyObject* Sbk_QDateFunc_weekNumber(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        int* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // weekNumber(int*)const
            // Begin code injection

            int yearNumber;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int week = cppSelf->weekNumber(&yearNumber);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &week));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &yearNumber));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateFunc_year(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // year()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDate*>(cppSelf)->year();
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

static PyObject* Sbk_QDate___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDate& cppSelf = *(((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDateMethod_isValid = {
    "isValid", (PyCFunction)Sbk_QDateFunc_isValid, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QDate_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QDateFunc___reduce__, METH_NOARGS},
    {"addDays", (PyCFunction)Sbk_QDateFunc_addDays, METH_O},
    {"addMonths", (PyCFunction)Sbk_QDateFunc_addMonths, METH_O},
    {"addYears", (PyCFunction)Sbk_QDateFunc_addYears, METH_O},
    {"currentDate", (PyCFunction)Sbk_QDateFunc_currentDate, METH_NOARGS|METH_STATIC},
    {"day", (PyCFunction)Sbk_QDateFunc_day, METH_NOARGS},
    {"dayOfWeek", (PyCFunction)Sbk_QDateFunc_dayOfWeek, METH_NOARGS},
    {"dayOfYear", (PyCFunction)Sbk_QDateFunc_dayOfYear, METH_NOARGS},
    {"daysInMonth", (PyCFunction)Sbk_QDateFunc_daysInMonth, METH_NOARGS},
    {"daysInYear", (PyCFunction)Sbk_QDateFunc_daysInYear, METH_NOARGS},
    {"daysTo", (PyCFunction)Sbk_QDateFunc_daysTo, METH_O},
    {"fromJulianDay", (PyCFunction)Sbk_QDateFunc_fromJulianDay, METH_O|METH_STATIC},
    {"fromString", (PyCFunction)Sbk_QDateFunc_fromString, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"getDate", (PyCFunction)Sbk_QDateFunc_getDate, METH_NOARGS},
    {"gregorianToJulian", (PyCFunction)Sbk_QDateFunc_gregorianToJulian, METH_VARARGS|METH_STATIC},
    {"isLeapYear", (PyCFunction)Sbk_QDateFunc_isLeapYear, METH_O|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QDateFunc_isNull, METH_NOARGS},
    Sbk_QDateMethod_isValid,
    {"longDayName", (PyCFunction)Sbk_QDateFunc_longDayName, METH_VARARGS|METH_STATIC},
    {"longMonthName", (PyCFunction)Sbk_QDateFunc_longMonthName, METH_VARARGS|METH_STATIC},
    {"month", (PyCFunction)Sbk_QDateFunc_month, METH_NOARGS},
    {"setDate", (PyCFunction)Sbk_QDateFunc_setDate, METH_VARARGS},
    {"setYMD", (PyCFunction)Sbk_QDateFunc_setYMD, METH_VARARGS},
    {"shortDayName", (PyCFunction)Sbk_QDateFunc_shortDayName, METH_VARARGS|METH_STATIC},
    {"shortMonthName", (PyCFunction)Sbk_QDateFunc_shortMonthName, METH_VARARGS|METH_STATIC},
    {"toJulianDay", (PyCFunction)Sbk_QDateFunc_toJulianDay, METH_NOARGS},
    {"toPython", (PyCFunction)Sbk_QDateFunc_toPython, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QDateFunc_toString, METH_VARARGS|METH_KEYWORDS},
    {"weekNumber", (PyCFunction)Sbk_QDateFunc_weekNumber, METH_NOARGS},
    {"year", (PyCFunction)Sbk_QDateFunc_year, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDate___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QDate_getattro(PyObject* self, PyObject* name)
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
        static PyMethodDef non_static_Sbk_QDateMethod_isValid = {
            Sbk_QDateMethod_isValid.ml_name,
            Sbk_QDateMethod_isValid.ml_meth,
            Sbk_QDateMethod_isValid.ml_flags & (~METH_STATIC),
            Sbk_QDateMethod_isValid.ml_doc,
        };
        if (Shiboken::String::compare(name, "isValid") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QDateMethod_isValid, self, 0);
    }
    return PyObject_GenericGetAttr(self, name);
}

static int Sbk_QDate___nb_bool(PyObject* self)
{
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QDate_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDate& cppSelf = *(((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator!=(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator<(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDate_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator<=(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDate_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator==(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator>(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDate_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
                // operator>=(const QDate & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDate cppArg0_local = ::QDate();
                ::QDate* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QDate_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QDate_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDate_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QDate_HashFunc(PyObject* self) {
    ::QDate* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)self));
    return PySide::hash(*cppSelf);
}

static int Sbk_QDate_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDate_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDate_TypeAsNumber;

static SbkObjectType Sbk_QDate_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QDate",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QDateFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QDate_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         Sbk_QDate_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QDate_traverse,
    /*tp_clear*/            Sbk_QDate_clear,
    /*tp_richcompare*/      Sbk_QDate_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDate_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDate_Init,
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
static void QDate_MonthNameType_PythonToCpp_QDate_MonthNameType(PyObject* pyIn, void* cppOut) {
    *((::QDate::MonthNameType*)cppOut) = (::QDate::MonthNameType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDate_MonthNameType_PythonToCpp_QDate_MonthNameType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX]))
        return QDate_MonthNameType_PythonToCpp_QDate_MonthNameType;
    return 0;
}
static PyObject* QDate_MonthNameType_CppToPython_QDate_MonthNameType(const void* cppIn) {
    int castCppIn = *((::QDate::MonthNameType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDate_PythonToCpp_QDate_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDate_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDate_PythonToCpp_QDate_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDate_Type))
        return QDate_PythonToCpp_QDate_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDate_PTR_CppToPython_QDate(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDate*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDate_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDate_COPY_CppToPython_QDate(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDate_Type, new ::QDate(*((::QDate*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDate_PythonToCpp_QDate_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDate*)cppOut) = *((::QDate*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDate_PythonToCpp_QDate_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDate_Type))
        return QDate_PythonToCpp_QDate_COPY;
    return 0;
}

// Python to C++ conversions for type 'QDate'.
static void Py_None_PythonToCpp_QDate(PyObject* pyIn, void* cppOut) {

    *((::QDate*)cppOut) = QDate();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QDate_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QDate;
    return 0;
}
static void PyDate_PythonToCpp_QDate(PyObject* pyIn, void* cppOut) {

    int day = PyDateTime_GET_DAY(pyIn);
    int month = PyDateTime_GET_MONTH(pyIn);
    int year = PyDateTime_GET_YEAR(pyIn);
    *((::QDate*)cppOut) = QDate(year, month, day);

}
static PythonToCppFunc is_PyDate_PythonToCpp_QDate_Convertible(PyObject* pyIn) {
    if (PyDateTime_ImportAndCheck(pyIn))
        return PyDate_PythonToCpp_QDate;
    return 0;
}

void init_QDate(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDate_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDate_TypeAsNumber) = Sbk_QDate___nb_bool;
    Sbk_QDate_Type.super.ht_type.tp_as_number = &Sbk_QDate_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QDATE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDate_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDate", "QDate",
        &Sbk_QDate_Type, &Shiboken::callCppDestructor< ::QDate >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDate_Type,
        QDate_PythonToCpp_QDate_PTR,
        is_QDate_PythonToCpp_QDate_PTR_Convertible,
        QDate_PTR_CppToPython_QDate,
        QDate_COPY_CppToPython_QDate);

    Shiboken::Conversions::registerConverterName(converter, "QDate");
    Shiboken::Conversions::registerConverterName(converter, "QDate*");
    Shiboken::Conversions::registerConverterName(converter, "QDate&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDate).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDate_PythonToCpp_QDate_COPY,
        is_QDate_PythonToCpp_QDate_COPY_Convertible);
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Py_None_PythonToCpp_QDate,
        is_Py_None_PythonToCpp_QDate_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PyDate_PythonToCpp_QDate,
        is_PyDate_PythonToCpp_QDate_Convertible);


    // Initialization of enums.

    // Initialization of enum 'MonthNameType'.
    SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDate_Type,
        "MonthNameType",
        "PySide.QtCore.QDate.MonthNameType",
        "QDate::MonthNameType");
    if (!SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX],
        &Sbk_QDate_Type, "DateFormat", (long) QDate::DateFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX],
        &Sbk_QDate_Type, "StandaloneFormat", (long) QDate::StandaloneFormat))
        return ;
    // Register converter for enum 'QDate::MonthNameType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX],
            QDate_MonthNameType_CppToPython_QDate_MonthNameType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDate_MonthNameType_PythonToCpp_QDate_MonthNameType,
            is_QDate_MonthNameType_PythonToCpp_QDate_MonthNameType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDATE_MONTHNAMETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDate::MonthNameType");
        Shiboken::Conversions::registerConverterName(converter, "MonthNameType");
    }
    // End of 'MonthNameType' enum.



    qRegisterMetaType< ::QDate >("QDate");
    qRegisterMetaType< ::QDate::MonthNameType >("QDate::MonthNameType");
}

