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

#include "qgradient_wrapper.h"

// Extra includes
#include <QPair>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGradient_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGradient >()))
        return -1;

    ::QGradient* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGradient", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGradient()
    // 1: QGradient(QGradient)
    if (numArgs == 0) {
        overloadId = 0; // QGradient()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QGradient(QGradient)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradient_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGradient()
        {

            if (!PyErr_Occurred()) {
                // QGradient()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGradient();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGradient(const QGradient & QGradient)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGradient cppArg0_local = ::QGradient();
            ::QGradient* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QGradient(QGradient)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QGradient(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGradient >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGradient_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGradient_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QGradient", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGradient", overloads);
        return -1;
}

static PyObject* Sbk_QGradientFunc_coordinateMode(PyObject* self)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // coordinateMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGradient::CoordinateMode cppResult = const_cast<const ::QGradient*>(cppSelf)->coordinateMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGradientFunc_interpolationMode(PyObject* self)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // interpolationMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGradient::InterpolationMode cppResult = const_cast<const ::QGradient*>(cppSelf)->interpolationMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGradientFunc_setColorAt(PyObject* self, PyObject* args)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColorAt", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColorAt(qreal,QColor)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
        overloadId = 0; // setColorAt(qreal,QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradientFunc_setColorAt_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QColor cppArg1_local = ::QColor();
        ::QColor* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setColorAt(qreal,QColor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColorAt(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGradientFunc_setColorAt_TypeError:
        const char* overloads[] = {"float, PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGradient.setColorAt", overloads);
        return 0;
}

static PyObject* Sbk_QGradientFunc_setCoordinateMode(PyObject* self, PyObject* pyArg)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCoordinateMode(QGradient::CoordinateMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setCoordinateMode(QGradient::CoordinateMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradientFunc_setCoordinateMode_TypeError;

    // Call function/method
    {
        ::QGradient::CoordinateMode cppArg0 = ((::QGradient::CoordinateMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCoordinateMode(QGradient::CoordinateMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCoordinateMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGradientFunc_setCoordinateMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGradient.CoordinateMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGradient.setCoordinateMode", overloads);
        return 0;
}

static PyObject* Sbk_QGradientFunc_setInterpolationMode(PyObject* self, PyObject* pyArg)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInterpolationMode(QGradient::InterpolationMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setInterpolationMode(QGradient::InterpolationMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradientFunc_setInterpolationMode_TypeError;

    // Call function/method
    {
        ::QGradient::InterpolationMode cppArg0 = ((::QGradient::InterpolationMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInterpolationMode(QGradient::InterpolationMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInterpolationMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGradientFunc_setInterpolationMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGradient.InterpolationMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGradient.setInterpolationMode", overloads);
        return 0;
}

static PyObject* Sbk_QGradientFunc_setSpread(PyObject* self, PyObject* pyArg)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpread(QGradient::Spread)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX]), (pyArg)))) {
        overloadId = 0; // setSpread(QGradient::Spread)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradientFunc_setSpread_TypeError;

    // Call function/method
    {
        ::QGradient::Spread cppArg0 = ((::QGradient::Spread)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSpread(QGradient::Spread)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSpread(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGradientFunc_setSpread_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGradient.Spread", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGradient.setSpread", overloads);
        return 0;
}

static PyObject* Sbk_QGradientFunc_setStops(PyObject* self, PyObject* pyArg)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStops(QVector<QPair<qreal,QColor> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX], (pyArg)))) {
        overloadId = 0; // setStops(QVector<QPair<qreal,QColor> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGradientFunc_setStops_TypeError;

    // Call function/method
    {
        ::QVector<QPair<qreal, QColor > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStops(QVector<QPair<qreal,QColor> >)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStops(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGradientFunc_setStops_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGradient.setStops", overloads);
        return 0;
}

static PyObject* Sbk_QGradientFunc_spread(PyObject* self)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spread()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGradient::Spread cppResult = const_cast<const ::QGradient*>(cppSelf)->spread();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGradientFunc_stops(PyObject* self)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stops()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QPair<qreal, QColor > > cppResult = const_cast<const ::QGradient*>(cppSelf)->stops();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGradientFunc_type(PyObject* self)
{
    ::QGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGradient::Type cppResult = const_cast<const ::QGradient*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGradient___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGradient& cppSelf = *(((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGradient_methods[] = {
    {"coordinateMode", (PyCFunction)Sbk_QGradientFunc_coordinateMode, METH_NOARGS},
    {"interpolationMode", (PyCFunction)Sbk_QGradientFunc_interpolationMode, METH_NOARGS},
    {"setColorAt", (PyCFunction)Sbk_QGradientFunc_setColorAt, METH_VARARGS},
    {"setCoordinateMode", (PyCFunction)Sbk_QGradientFunc_setCoordinateMode, METH_O},
    {"setInterpolationMode", (PyCFunction)Sbk_QGradientFunc_setInterpolationMode, METH_O},
    {"setSpread", (PyCFunction)Sbk_QGradientFunc_setSpread, METH_O},
    {"setStops", (PyCFunction)Sbk_QGradientFunc_setStops, METH_O},
    {"spread", (PyCFunction)Sbk_QGradientFunc_spread, METH_NOARGS},
    {"stops", (PyCFunction)Sbk_QGradientFunc_stops, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QGradientFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QGradient___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QGradient_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QGradient& cppSelf = *(((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (pyArg)))) {
                // operator!=(const QGradient & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGradient cppArg0_local = ::QGradient();
                ::QGradient* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (pyArg)))) {
                // operator==(const QGradient & gradient) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGradient cppArg0_local = ::QGradient();
                ::QGradient* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (pyArg)))) {
                // operator==(const QGradient & gradient)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QGradient cppArg0_local = ::QGradient();
                ::QGradient* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pythonToCpp))
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
            goto Sbk_QGradient_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QGradient_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QGradient_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGradient_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGradient_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGradient",
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
    /*tp_traverse*/         Sbk_QGradient_traverse,
    /*tp_clear*/            Sbk_QGradient_clear,
    /*tp_richcompare*/      Sbk_QGradient_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGradient_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGradient_Init,
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
static void QGradient_Type_PythonToCpp_QGradient_Type(PyObject* pyIn, void* cppOut) {
    *((::QGradient::Type*)cppOut) = (::QGradient::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGradient_Type_PythonToCpp_QGradient_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX]))
        return QGradient_Type_PythonToCpp_QGradient_Type;
    return 0;
}
static PyObject* QGradient_Type_CppToPython_QGradient_Type(const void* cppIn) {
    int castCppIn = *((::QGradient::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX], castCppIn);

}

static void QGradient_Spread_PythonToCpp_QGradient_Spread(PyObject* pyIn, void* cppOut) {
    *((::QGradient::Spread*)cppOut) = (::QGradient::Spread) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGradient_Spread_PythonToCpp_QGradient_Spread_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX]))
        return QGradient_Spread_PythonToCpp_QGradient_Spread;
    return 0;
}
static PyObject* QGradient_Spread_CppToPython_QGradient_Spread(const void* cppIn) {
    int castCppIn = *((::QGradient::Spread*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX], castCppIn);

}

static void QGradient_CoordinateMode_PythonToCpp_QGradient_CoordinateMode(PyObject* pyIn, void* cppOut) {
    *((::QGradient::CoordinateMode*)cppOut) = (::QGradient::CoordinateMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGradient_CoordinateMode_PythonToCpp_QGradient_CoordinateMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX]))
        return QGradient_CoordinateMode_PythonToCpp_QGradient_CoordinateMode;
    return 0;
}
static PyObject* QGradient_CoordinateMode_CppToPython_QGradient_CoordinateMode(const void* cppIn) {
    int castCppIn = *((::QGradient::CoordinateMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX], castCppIn);

}

static void QGradient_InterpolationMode_PythonToCpp_QGradient_InterpolationMode(PyObject* pyIn, void* cppOut) {
    *((::QGradient::InterpolationMode*)cppOut) = (::QGradient::InterpolationMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGradient_InterpolationMode_PythonToCpp_QGradient_InterpolationMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX]))
        return QGradient_InterpolationMode_PythonToCpp_QGradient_InterpolationMode;
    return 0;
}
static PyObject* QGradient_InterpolationMode_CppToPython_QGradient_InterpolationMode(const void* cppIn) {
    int castCppIn = *((::QGradient::InterpolationMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGradient_PythonToCpp_QGradient_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGradient_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGradient_PythonToCpp_QGradient_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGradient_Type))
        return QGradient_PythonToCpp_QGradient_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGradient_PTR_CppToPython_QGradient(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGradient*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGradient_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QGradient_COPY_CppToPython_QGradient(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QGradient_Type, new ::QGradient(*((::QGradient*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QGradient_PythonToCpp_QGradient_COPY(PyObject* pyIn, void* cppOut) {
    *((::QGradient*)cppOut) = *((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QGradient_PythonToCpp_QGradient_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGradient_Type))
        return QGradient_PythonToCpp_QGradient_COPY;
    return 0;
}

void init_QGradient(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGradient_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGradient", "QGradient",
        &Sbk_QGradient_Type, &Shiboken::callCppDestructor< ::QGradient >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGradient_Type,
        QGradient_PythonToCpp_QGradient_PTR,
        is_QGradient_PythonToCpp_QGradient_PTR_Convertible,
        QGradient_PTR_CppToPython_QGradient,
        QGradient_COPY_CppToPython_QGradient);

    Shiboken::Conversions::registerConverterName(converter, "QGradient");
    Shiboken::Conversions::registerConverterName(converter, "QGradient*");
    Shiboken::Conversions::registerConverterName(converter, "QGradient&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGradient).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QGradient_PythonToCpp_QGradient_COPY,
        is_QGradient_PythonToCpp_QGradient_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGradient_Type,
        "Type",
        "PySide.QtGui.QGradient.Type",
        "QGradient::Type");
    if (!SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX],
        &Sbk_QGradient_Type, "LinearGradient", (long) QGradient::LinearGradient))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX],
        &Sbk_QGradient_Type, "RadialGradient", (long) QGradient::RadialGradient))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX],
        &Sbk_QGradient_Type, "ConicalGradient", (long) QGradient::ConicalGradient))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX],
        &Sbk_QGradient_Type, "NoGradient", (long) QGradient::NoGradient))
        return ;
    // Register converter for enum 'QGradient::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX],
            QGradient_Type_CppToPython_QGradient_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGradient_Type_PythonToCpp_QGradient_Type,
            is_QGradient_Type_PythonToCpp_QGradient_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGradient::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.

    // Initialization of enum 'Spread'.
    SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGradient_Type,
        "Spread",
        "PySide.QtGui.QGradient.Spread",
        "QGradient::Spread");
    if (!SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX],
        &Sbk_QGradient_Type, "PadSpread", (long) QGradient::PadSpread))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX],
        &Sbk_QGradient_Type, "ReflectSpread", (long) QGradient::ReflectSpread))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX],
        &Sbk_QGradient_Type, "RepeatSpread", (long) QGradient::RepeatSpread))
        return ;
    // Register converter for enum 'QGradient::Spread'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX],
            QGradient_Spread_CppToPython_QGradient_Spread);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGradient_Spread_PythonToCpp_QGradient_Spread,
            is_QGradient_Spread_PythonToCpp_QGradient_Spread_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGradient::Spread");
        Shiboken::Conversions::registerConverterName(converter, "Spread");
    }
    // End of 'Spread' enum.

    // Initialization of enum 'CoordinateMode'.
    SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGradient_Type,
        "CoordinateMode",
        "PySide.QtGui.QGradient.CoordinateMode",
        "QGradient::CoordinateMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX],
        &Sbk_QGradient_Type, "LogicalMode", (long) QGradient::LogicalMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX],
        &Sbk_QGradient_Type, "StretchToDeviceMode", (long) QGradient::StretchToDeviceMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX],
        &Sbk_QGradient_Type, "ObjectBoundingMode", (long) QGradient::ObjectBoundingMode))
        return ;
    // Register converter for enum 'QGradient::CoordinateMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX],
            QGradient_CoordinateMode_CppToPython_QGradient_CoordinateMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGradient_CoordinateMode_PythonToCpp_QGradient_CoordinateMode,
            is_QGradient_CoordinateMode_PythonToCpp_QGradient_CoordinateMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGradient::CoordinateMode");
        Shiboken::Conversions::registerConverterName(converter, "CoordinateMode");
    }
    // End of 'CoordinateMode' enum.

    // Initialization of enum 'InterpolationMode'.
    SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGradient_Type,
        "InterpolationMode",
        "PySide.QtGui.QGradient.InterpolationMode",
        "QGradient::InterpolationMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX],
        &Sbk_QGradient_Type, "ColorInterpolation", (long) QGradient::ColorInterpolation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX],
        &Sbk_QGradient_Type, "ComponentInterpolation", (long) QGradient::ComponentInterpolation))
        return ;
    // Register converter for enum 'QGradient::InterpolationMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX],
            QGradient_InterpolationMode_CppToPython_QGradient_InterpolationMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGradient_InterpolationMode_PythonToCpp_QGradient_InterpolationMode,
            is_QGradient_InterpolationMode_PythonToCpp_QGradient_InterpolationMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGradient::InterpolationMode");
        Shiboken::Conversions::registerConverterName(converter, "InterpolationMode");
    }
    // End of 'InterpolationMode' enum.


    qRegisterMetaType< ::QGradient >("QGradient");
    qRegisterMetaType< ::QGradient::Type >("QGradient::Type");
    qRegisterMetaType< ::QGradient::Spread >("QGradient::Spread");
    qRegisterMetaType< ::QGradient::CoordinateMode >("QGradient::CoordinateMode");
    qRegisterMetaType< ::QGradient::InterpolationMode >("QGradient::InterpolationMode");
}
