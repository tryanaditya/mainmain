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

#include "qelapsedtimer_wrapper.h"

// Extra includes
#include <qelapsedtimer.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QElapsedTimer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QElapsedTimer >()))
        return -1;

    ::QElapsedTimer* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QElapsedTimer", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QElapsedTimer()
    // 1: QElapsedTimer(QElapsedTimer)
    if (numArgs == 0) {
        overloadId = 0; // QElapsedTimer()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QElapsedTimer(QElapsedTimer)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QElapsedTimer_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QElapsedTimer()
        {

            if (!PyErr_Occurred()) {
                // QElapsedTimer()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QElapsedTimer();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QElapsedTimer(const QElapsedTimer & QElapsedTimer)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QElapsedTimer cppArg0_local = ::QElapsedTimer();
            ::QElapsedTimer* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QElapsedTimer(QElapsedTimer)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QElapsedTimer(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QElapsedTimer >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QElapsedTimer_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QElapsedTimer_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QElapsedTimer", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QElapsedTimer", overloads);
        return -1;
}

static PyObject* Sbk_QElapsedTimerFunc_clockType(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clockType()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QElapsedTimer::ClockType cppResult = ::QElapsedTimer::clockType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QElapsedTimerFunc_elapsed(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // elapsed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->elapsed();
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

static PyObject* Sbk_QElapsedTimerFunc_hasExpired(PyObject* self, PyObject* pyArg)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasExpired(qint64)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // hasExpired(qint64)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QElapsedTimerFunc_hasExpired_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasExpired(qint64)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->hasExpired(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QElapsedTimerFunc_hasExpired_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QElapsedTimer.hasExpired", overloads);
        return 0;
}

static PyObject* Sbk_QElapsedTimerFunc_invalidate(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QElapsedTimerFunc_isMonotonic(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMonotonic()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QElapsedTimer::isMonotonic();
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

static PyObject* Sbk_QElapsedTimerFunc_isValid(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->isValid();
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

static PyObject* Sbk_QElapsedTimerFunc_msecsSinceReference(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // msecsSinceReference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->msecsSinceReference();
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

static PyObject* Sbk_QElapsedTimerFunc_msecsTo(PyObject* self, PyObject* pyArg)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: msecsTo(QElapsedTimer)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (pyArg)))) {
        overloadId = 0; // msecsTo(QElapsedTimer)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QElapsedTimerFunc_msecsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QElapsedTimer cppArg0_local = ::QElapsedTimer();
        ::QElapsedTimer* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // msecsTo(QElapsedTimer)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->msecsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QElapsedTimerFunc_msecsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QElapsedTimer", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QElapsedTimer.msecsTo", overloads);
        return 0;
}

static PyObject* Sbk_QElapsedTimerFunc_nsecsElapsed(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nsecsElapsed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->nsecsElapsed();
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

static PyObject* Sbk_QElapsedTimerFunc_restart(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restart()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = cppSelf->restart();
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

static PyObject* Sbk_QElapsedTimerFunc_secsTo(PyObject* self, PyObject* pyArg)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: secsTo(QElapsedTimer)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (pyArg)))) {
        overloadId = 0; // secsTo(QElapsedTimer)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QElapsedTimerFunc_secsTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QElapsedTimer cppArg0_local = ::QElapsedTimer();
        ::QElapsedTimer* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // secsTo(QElapsedTimer)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QElapsedTimer*>(cppSelf)->secsTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QElapsedTimerFunc_secsTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QElapsedTimer", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QElapsedTimer.secsTo", overloads);
        return 0;
}

static PyObject* Sbk_QElapsedTimerFunc_start(PyObject* self)
{
    ::QElapsedTimer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QElapsedTimer___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QElapsedTimer& cppSelf = *(((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QElapsedTimer_methods[] = {
    {"clockType", (PyCFunction)Sbk_QElapsedTimerFunc_clockType, METH_NOARGS|METH_STATIC},
    {"elapsed", (PyCFunction)Sbk_QElapsedTimerFunc_elapsed, METH_NOARGS},
    {"hasExpired", (PyCFunction)Sbk_QElapsedTimerFunc_hasExpired, METH_O},
    {"invalidate", (PyCFunction)Sbk_QElapsedTimerFunc_invalidate, METH_NOARGS},
    {"isMonotonic", (PyCFunction)Sbk_QElapsedTimerFunc_isMonotonic, METH_NOARGS|METH_STATIC},
    {"isValid", (PyCFunction)Sbk_QElapsedTimerFunc_isValid, METH_NOARGS},
    {"msecsSinceReference", (PyCFunction)Sbk_QElapsedTimerFunc_msecsSinceReference, METH_NOARGS},
    {"msecsTo", (PyCFunction)Sbk_QElapsedTimerFunc_msecsTo, METH_O},
    {"nsecsElapsed", (PyCFunction)Sbk_QElapsedTimerFunc_nsecsElapsed, METH_NOARGS},
    {"restart", (PyCFunction)Sbk_QElapsedTimerFunc_restart, METH_NOARGS},
    {"secsTo", (PyCFunction)Sbk_QElapsedTimerFunc_secsTo, METH_O},
    {"start", (PyCFunction)Sbk_QElapsedTimerFunc_start, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QElapsedTimer___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QElapsedTimer_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QElapsedTimer& cppSelf = *(((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (pyArg)))) {
                // operator!=(const QElapsedTimer & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QElapsedTimer cppArg0_local = ::QElapsedTimer();
                ::QElapsedTimer* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (pyArg)))) {
                // operator==(const QElapsedTimer & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QElapsedTimer cppArg0_local = ::QElapsedTimer();
                ::QElapsedTimer* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], pythonToCpp))
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
            goto Sbk_QElapsedTimer_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QElapsedTimer_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QElapsedTimer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QElapsedTimer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QElapsedTimer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QElapsedTimer",
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
    /*tp_traverse*/         Sbk_QElapsedTimer_traverse,
    /*tp_clear*/            Sbk_QElapsedTimer_clear,
    /*tp_richcompare*/      Sbk_QElapsedTimer_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QElapsedTimer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QElapsedTimer_Init,
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
static void QElapsedTimer_ClockType_PythonToCpp_QElapsedTimer_ClockType(PyObject* pyIn, void* cppOut) {
    *((::QElapsedTimer::ClockType*)cppOut) = (::QElapsedTimer::ClockType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QElapsedTimer_ClockType_PythonToCpp_QElapsedTimer_ClockType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX]))
        return QElapsedTimer_ClockType_PythonToCpp_QElapsedTimer_ClockType;
    return 0;
}
static PyObject* QElapsedTimer_ClockType_CppToPython_QElapsedTimer_ClockType(const void* cppIn) {
    int castCppIn = *((::QElapsedTimer::ClockType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QElapsedTimer_PythonToCpp_QElapsedTimer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QElapsedTimer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QElapsedTimer_PythonToCpp_QElapsedTimer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QElapsedTimer_Type))
        return QElapsedTimer_PythonToCpp_QElapsedTimer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QElapsedTimer_PTR_CppToPython_QElapsedTimer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QElapsedTimer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QElapsedTimer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QElapsedTimer_COPY_CppToPython_QElapsedTimer(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QElapsedTimer_Type, new ::QElapsedTimer(*((::QElapsedTimer*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QElapsedTimer_PythonToCpp_QElapsedTimer_COPY(PyObject* pyIn, void* cppOut) {
    *((::QElapsedTimer*)cppOut) = *((::QElapsedTimer*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QElapsedTimer_PythonToCpp_QElapsedTimer_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QElapsedTimer_Type))
        return QElapsedTimer_PythonToCpp_QElapsedTimer_COPY;
    return 0;
}

void init_QElapsedTimer(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QElapsedTimer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QElapsedTimer", "QElapsedTimer",
        &Sbk_QElapsedTimer_Type, &Shiboken::callCppDestructor< ::QElapsedTimer >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QElapsedTimer_Type,
        QElapsedTimer_PythonToCpp_QElapsedTimer_PTR,
        is_QElapsedTimer_PythonToCpp_QElapsedTimer_PTR_Convertible,
        QElapsedTimer_PTR_CppToPython_QElapsedTimer,
        QElapsedTimer_COPY_CppToPython_QElapsedTimer);

    Shiboken::Conversions::registerConverterName(converter, "QElapsedTimer");
    Shiboken::Conversions::registerConverterName(converter, "QElapsedTimer*");
    Shiboken::Conversions::registerConverterName(converter, "QElapsedTimer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QElapsedTimer).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QElapsedTimer_PythonToCpp_QElapsedTimer_COPY,
        is_QElapsedTimer_PythonToCpp_QElapsedTimer_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ClockType'.
    SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QElapsedTimer_Type,
        "ClockType",
        "PySide.QtCore.QElapsedTimer.ClockType",
        "QElapsedTimer::ClockType");
    if (!SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
        &Sbk_QElapsedTimer_Type, "SystemTime", (long) QElapsedTimer::SystemTime))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
        &Sbk_QElapsedTimer_Type, "MonotonicClock", (long) QElapsedTimer::MonotonicClock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
        &Sbk_QElapsedTimer_Type, "TickCounter", (long) QElapsedTimer::TickCounter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
        &Sbk_QElapsedTimer_Type, "MachAbsoluteTime", (long) QElapsedTimer::MachAbsoluteTime))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
        &Sbk_QElapsedTimer_Type, "PerformanceCounter", (long) QElapsedTimer::PerformanceCounter))
        return ;
    // Register converter for enum 'QElapsedTimer::ClockType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX],
            QElapsedTimer_ClockType_CppToPython_QElapsedTimer_ClockType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QElapsedTimer_ClockType_PythonToCpp_QElapsedTimer_ClockType,
            is_QElapsedTimer_ClockType_PythonToCpp_QElapsedTimer_ClockType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QELAPSEDTIMER_CLOCKTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QElapsedTimer::ClockType");
        Shiboken::Conversions::registerConverterName(converter, "ClockType");
    }
    // End of 'ClockType' enum.


    qRegisterMetaType< ::QElapsedTimer >("QElapsedTimer");
    qRegisterMetaType< ::QElapsedTimer::ClockType >("QElapsedTimer::ClockType");
}
