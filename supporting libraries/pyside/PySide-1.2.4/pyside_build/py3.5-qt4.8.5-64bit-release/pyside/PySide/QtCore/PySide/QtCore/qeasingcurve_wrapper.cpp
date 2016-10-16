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

#include "qeasingcurve_wrapper.h"

// Extra includes
#include "glue/qeasingcurve_glue.h"
#include <pysideweakref.h>
#include <qeasingcurve.h>




// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QEasingCurve_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QEasingCurve >()))
        return -1;

    ::QEasingCurve* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEasingCurve(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QEasingCurve", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QEasingCurve(QEasingCurve::Type)
    // 1: QEasingCurve(QEasingCurve)
    if (numArgs == 0) {
        overloadId = 0; // QEasingCurve(QEasingCurve::Type)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QEasingCurve(QEasingCurve::Type)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QEasingCurve(QEasingCurve)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurve_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QEasingCurve(QEasingCurve::Type type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QEasingCurve(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]), (pyArgs[0]))))
                        goto Sbk_QEasingCurve_Init_TypeError;
                }
            }
            ::QEasingCurve::Type cppArg0 = QEasingCurve::Linear;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QEasingCurve(QEasingCurve::Type)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QEasingCurve(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QEasingCurve(const QEasingCurve & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
            ::QEasingCurve* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QEasingCurve(QEasingCurve)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QEasingCurve(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QEasingCurve >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QEasingCurve_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QEasingCurve_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEasingCurve.Type = Linear", "PySide.QtCore.QEasingCurve", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QEasingCurve", overloads);
        return -1;
}

static PyObject* Sbk_QEasingCurveFunc_amplitude(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // amplitude()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QEasingCurve*>(cppSelf)->amplitude();
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

static PyObject* Sbk_QEasingCurveFunc_customType(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // customType()
            // Begin code injection

            //customType()
            pyResult = PySideEasingCurveFunctor::callable(self);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QEasingCurveFunc_overshoot(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overshoot()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QEasingCurve*>(cppSelf)->overshoot();
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

static PyObject* Sbk_QEasingCurveFunc_period(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // period()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QEasingCurve*>(cppSelf)->period();
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

static PyObject* Sbk_QEasingCurveFunc_setAmplitude(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAmplitude(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setAmplitude(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_setAmplitude_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAmplitude(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAmplitude(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEasingCurveFunc_setAmplitude_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.setAmplitude", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurveFunc_setCustomType(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCustomType(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // setCustomType(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_setCustomType_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setCustomType(PyObject*)
            // Begin code injection

            QEasingCurve::EasingFunction func = PySideEasingCurveFunctor::createCustomFuntion(self, pyArg);
            if (func)
                cppSelf->setCustomType(func);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEasingCurveFunc_setCustomType_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.setCustomType", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurveFunc_setOvershoot(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOvershoot(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setOvershoot(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_setOvershoot_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOvershoot(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOvershoot(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEasingCurveFunc_setOvershoot_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.setOvershoot", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurveFunc_setPeriod(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeriod(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPeriod(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_setPeriod_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeriod(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeriod(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEasingCurveFunc_setPeriod_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.setPeriod", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurveFunc_setType(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(QEasingCurve::Type)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setType(QEasingCurve::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_setType_TypeError;

    // Call function/method
    {
        ::QEasingCurve::Type cppArg0 = ((::QEasingCurve::Type)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(QEasingCurve::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QEasingCurveFunc_setType_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEasingCurve.Type", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.setType", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurveFunc_type(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QEasingCurve::Type cppResult = const_cast<const ::QEasingCurve*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QEasingCurveFunc_valueForProgress(PyObject* self, PyObject* pyArg)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: valueForProgress(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // valueForProgress(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QEasingCurveFunc_valueForProgress_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // valueForProgress(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QEasingCurve*>(cppSelf)->valueForProgress(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QEasingCurveFunc_valueForProgress_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QEasingCurve.valueForProgress", overloads);
        return 0;
}

static PyObject* Sbk_QEasingCurve___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QEasingCurve& cppSelf = *(((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QEasingCurve_methods[] = {
    {"amplitude", (PyCFunction)Sbk_QEasingCurveFunc_amplitude, METH_NOARGS},
    {"customType", (PyCFunction)Sbk_QEasingCurveFunc_customType, METH_NOARGS},
    {"overshoot", (PyCFunction)Sbk_QEasingCurveFunc_overshoot, METH_NOARGS},
    {"period", (PyCFunction)Sbk_QEasingCurveFunc_period, METH_NOARGS},
    {"setAmplitude", (PyCFunction)Sbk_QEasingCurveFunc_setAmplitude, METH_O},
    {"setCustomType", (PyCFunction)Sbk_QEasingCurveFunc_setCustomType, METH_O},
    {"setOvershoot", (PyCFunction)Sbk_QEasingCurveFunc_setOvershoot, METH_O},
    {"setPeriod", (PyCFunction)Sbk_QEasingCurveFunc_setPeriod, METH_O},
    {"setType", (PyCFunction)Sbk_QEasingCurveFunc_setType, METH_O},
    {"type", (PyCFunction)Sbk_QEasingCurveFunc_type, METH_NOARGS},
    {"valueForProgress", (PyCFunction)Sbk_QEasingCurveFunc_valueForProgress, METH_O},

    {"__copy__", (PyCFunction)Sbk_QEasingCurve___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QEasingCurve_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QEasingCurve& cppSelf = *(((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArg)))) {
                // operator!=(const QEasingCurve & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
                ::QEasingCurve* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArg)))) {
                // operator==(const QEasingCurve & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
                ::QEasingCurve* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp))
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
            goto Sbk_QEasingCurve_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QEasingCurve_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QEasingCurve_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QEasingCurve_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QEasingCurve__repr__(PyObject* self)
{
    ::QEasingCurve* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QEasingCurve_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QEasingCurve",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QEasingCurve__repr__,
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
    /*tp_traverse*/         Sbk_QEasingCurve_traverse,
    /*tp_clear*/            Sbk_QEasingCurve_clear,
    /*tp_richcompare*/      Sbk_QEasingCurve_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QEasingCurve_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QEasingCurve_Init,
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
static void QEasingCurve_Type_PythonToCpp_QEasingCurve_Type(PyObject* pyIn, void* cppOut) {
    *((::QEasingCurve::Type*)cppOut) = (::QEasingCurve::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QEasingCurve_Type_PythonToCpp_QEasingCurve_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]))
        return QEasingCurve_Type_PythonToCpp_QEasingCurve_Type;
    return 0;
}
static PyObject* QEasingCurve_Type_CppToPython_QEasingCurve_Type(const void* cppIn) {
    int castCppIn = *((::QEasingCurve::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QEasingCurve_PythonToCpp_QEasingCurve_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QEasingCurve_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QEasingCurve_PythonToCpp_QEasingCurve_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QEasingCurve_Type))
        return QEasingCurve_PythonToCpp_QEasingCurve_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QEasingCurve_PTR_CppToPython_QEasingCurve(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QEasingCurve*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QEasingCurve_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QEasingCurve_COPY_CppToPython_QEasingCurve(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QEasingCurve_Type, new ::QEasingCurve(*((::QEasingCurve*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QEasingCurve_PythonToCpp_QEasingCurve_COPY(PyObject* pyIn, void* cppOut) {
    *((::QEasingCurve*)cppOut) = *((::QEasingCurve*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QEasingCurve_PythonToCpp_QEasingCurve_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QEasingCurve_Type))
        return QEasingCurve_PythonToCpp_QEasingCurve_COPY;
    return 0;
}

// Implicit conversions.
static void QEasingCurve_Type_PythonToCpp_QEasingCurve(PyObject* pyIn, void* cppOut) {
    ::QEasingCurve::Type cppIn = ((::QEasingCurve::Type)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX]), pyIn, &cppIn);
    *((::QEasingCurve*)cppOut) = ::QEasingCurve(cppIn);
}
static PythonToCppFunc is_QEasingCurve_Type_PythonToCpp_QEasingCurve_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX], pyIn))
        return QEasingCurve_Type_PythonToCpp_QEasingCurve;
    return 0;
}

void init_QEasingCurve(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QEasingCurve_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QEasingCurve", "QEasingCurve",
        &Sbk_QEasingCurve_Type, &Shiboken::callCppDestructor< ::QEasingCurve >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QEasingCurve_Type,
        QEasingCurve_PythonToCpp_QEasingCurve_PTR,
        is_QEasingCurve_PythonToCpp_QEasingCurve_PTR_Convertible,
        QEasingCurve_PTR_CppToPython_QEasingCurve,
        QEasingCurve_COPY_CppToPython_QEasingCurve);

    Shiboken::Conversions::registerConverterName(converter, "QEasingCurve");
    Shiboken::Conversions::registerConverterName(converter, "QEasingCurve*");
    Shiboken::Conversions::registerConverterName(converter, "QEasingCurve&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QEasingCurve).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QEasingCurve_PythonToCpp_QEasingCurve_COPY,
        is_QEasingCurve_PythonToCpp_QEasingCurve_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QEasingCurve_Type_PythonToCpp_QEasingCurve,
        is_QEasingCurve_Type_PythonToCpp_QEasingCurve_Convertible);

    // Begin code injection

    PySideEasingCurveFunctor::init();

    // End of code injection

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QEasingCurve_Type,
        "Type",
        "PySide.QtCore.QEasingCurve.Type",
        "QEasingCurve::Type");
    if (!SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "Linear", (long) QEasingCurve::Linear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InQuad", (long) QEasingCurve::InQuad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutQuad", (long) QEasingCurve::OutQuad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutQuad", (long) QEasingCurve::InOutQuad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInQuad", (long) QEasingCurve::OutInQuad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InCubic", (long) QEasingCurve::InCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutCubic", (long) QEasingCurve::OutCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutCubic", (long) QEasingCurve::InOutCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInCubic", (long) QEasingCurve::OutInCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InQuart", (long) QEasingCurve::InQuart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutQuart", (long) QEasingCurve::OutQuart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutQuart", (long) QEasingCurve::InOutQuart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInQuart", (long) QEasingCurve::OutInQuart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InQuint", (long) QEasingCurve::InQuint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutQuint", (long) QEasingCurve::OutQuint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutQuint", (long) QEasingCurve::InOutQuint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInQuint", (long) QEasingCurve::OutInQuint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InSine", (long) QEasingCurve::InSine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutSine", (long) QEasingCurve::OutSine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutSine", (long) QEasingCurve::InOutSine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInSine", (long) QEasingCurve::OutInSine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InExpo", (long) QEasingCurve::InExpo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutExpo", (long) QEasingCurve::OutExpo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutExpo", (long) QEasingCurve::InOutExpo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInExpo", (long) QEasingCurve::OutInExpo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InCirc", (long) QEasingCurve::InCirc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutCirc", (long) QEasingCurve::OutCirc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutCirc", (long) QEasingCurve::InOutCirc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInCirc", (long) QEasingCurve::OutInCirc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InElastic", (long) QEasingCurve::InElastic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutElastic", (long) QEasingCurve::OutElastic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutElastic", (long) QEasingCurve::InOutElastic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInElastic", (long) QEasingCurve::OutInElastic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InBack", (long) QEasingCurve::InBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutBack", (long) QEasingCurve::OutBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutBack", (long) QEasingCurve::InOutBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInBack", (long) QEasingCurve::OutInBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InBounce", (long) QEasingCurve::InBounce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutBounce", (long) QEasingCurve::OutBounce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InOutBounce", (long) QEasingCurve::InOutBounce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutInBounce", (long) QEasingCurve::OutInBounce))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "InCurve", (long) QEasingCurve::InCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "OutCurve", (long) QEasingCurve::OutCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "SineCurve", (long) QEasingCurve::SineCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "CosineCurve", (long) QEasingCurve::CosineCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "Custom", (long) QEasingCurve::Custom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
        &Sbk_QEasingCurve_Type, "NCurveTypes", (long) QEasingCurve::NCurveTypes))
        return ;
    // Register converter for enum 'QEasingCurve::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX],
            QEasingCurve_Type_CppToPython_QEasingCurve_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QEasingCurve_Type_PythonToCpp_QEasingCurve_Type,
            is_QEasingCurve_Type_PythonToCpp_QEasingCurve_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QEasingCurve::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.



    qRegisterMetaType< ::QEasingCurve::Type >("QEasingCurve::Type");
}

