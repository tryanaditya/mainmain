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

#include "qradialgradient_wrapper.h"

// Extra includes
#include <QPair>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qpoint.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QRadialGradient_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QRadialGradient >()))
        return -1;

    ::QRadialGradient* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QRadialGradient", 0, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QRadialGradient()
    // 1: QRadialGradient(QPointF,qreal,QPointF,qreal)
    // 2: QRadialGradient(QPointF,qreal)
    // 3: QRadialGradient(QPointF,qreal,QPointF)
    // 4: QRadialGradient(QRadialGradient)
    // 5: QRadialGradient(qreal,qreal,qreal,qreal,qreal,qreal)
    // 6: QRadialGradient(qreal,qreal,qreal)
    // 7: QRadialGradient(qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QRadialGradient()
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 6; // QRadialGradient(qreal,qreal,qreal)
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 7; // QRadialGradient(qreal,qreal,qreal,qreal,qreal)
            } else if (numArgs == 6
                && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
                overloadId = 5; // QRadialGradient(qreal,qreal,qreal,qreal,qreal,qreal)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (pyArgs[0])))) {
        overloadId = 4; // QRadialGradient(QRadialGradient)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QRadialGradient(QPointF,qreal)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 3; // QRadialGradient(QPointF,qreal,QPointF)
            } else if (numArgs == 4
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
                overloadId = 1; // QRadialGradient(QPointF,qreal,QPointF,qreal)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradient_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QRadialGradient()
        {

            if (!PyErr_Occurred()) {
                // QRadialGradient()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QRadialGradient(const QPointF & center, qreal centerRadius, const QPointF & focalPoint, qreal focalRadius)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QPointF cppArg2_local = ::QPointF();
            ::QPointF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QRadialGradient(QPointF,qreal,QPointF,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(*cppArg0, cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QRadialGradient(const QPointF & center, qreal radius)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QRadialGradient(QPointF,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QRadialGradient(const QPointF & center, qreal radius, const QPointF & focalPoint)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QPointF cppArg2_local = ::QPointF();
            ::QPointF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // QRadialGradient(QPointF,qreal,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(*cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QRadialGradient(const QRadialGradient & QRadialGradient)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QRadialGradient cppArg0_local = ::QRadialGradient();
            ::QRadialGradient* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QRadialGradient(QRadialGradient)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QRadialGradient(qreal cx, qreal cy, qreal centerRadius, qreal fx, qreal fy, qreal focalRadius)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            qreal cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // QRadialGradient(qreal,qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QRadialGradient(qreal cx, qreal cy, qreal radius)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QRadialGradient(qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QRadialGradient(qreal cx, qreal cy, qreal radius, qreal fx, qreal fy)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QRadialGradient(qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRadialGradient(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QRadialGradient >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QRadialGradient_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QRadialGradient_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QPointF, float, PySide.QtCore.QPointF, float", "PySide.QtCore.QPointF, float", "PySide.QtCore.QPointF, float, PySide.QtCore.QPointF", "PySide.QtGui.QRadialGradient", "float, float, float, float, float, float", "float, float, float", "float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QRadialGradient", overloads);
        return -1;
}

static PyObject* Sbk_QRadialGradientFunc_center(PyObject* self)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // center()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QRadialGradient*>(cppSelf)->center();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QRadialGradientFunc_centerRadius(PyObject* self)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // centerRadius()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QRadialGradient*>(cppSelf)->centerRadius();
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

static PyObject* Sbk_QRadialGradientFunc_focalPoint(PyObject* self)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focalPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QRadialGradient*>(cppSelf)->focalPoint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QRadialGradientFunc_focalRadius(PyObject* self)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focalRadius()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QRadialGradient*>(cppSelf)->focalRadius();
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

static PyObject* Sbk_QRadialGradientFunc_radius(PyObject* self)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // radius()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QRadialGradient*>(cppSelf)->radius();
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

static PyObject* Sbk_QRadialGradientFunc_setCenter(PyObject* self, PyObject* args)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCenter", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCenter(QPointF)
    // 1: setCenter(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setCenter(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setCenter(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradientFunc_setCenter_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setCenter(const QPointF & center)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setCenter(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCenter(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setCenter(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setCenter(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCenter(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRadialGradientFunc_setCenter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QRadialGradient.setCenter", overloads);
        return 0;
}

static PyObject* Sbk_QRadialGradientFunc_setCenterRadius(PyObject* self, PyObject* pyArg)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCenterRadius(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setCenterRadius(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradientFunc_setCenterRadius_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCenterRadius(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCenterRadius(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRadialGradientFunc_setCenterRadius_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QRadialGradient.setCenterRadius", overloads);
        return 0;
}

static PyObject* Sbk_QRadialGradientFunc_setFocalPoint(PyObject* self, PyObject* args)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFocalPoint", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFocalPoint(QPointF)
    // 1: setFocalPoint(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setFocalPoint(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setFocalPoint(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradientFunc_setFocalPoint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setFocalPoint(const QPointF & focalPoint)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setFocalPoint(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFocalPoint(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setFocalPoint(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setFocalPoint(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFocalPoint(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRadialGradientFunc_setFocalPoint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QRadialGradient.setFocalPoint", overloads);
        return 0;
}

static PyObject* Sbk_QRadialGradientFunc_setFocalRadius(PyObject* self, PyObject* pyArg)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFocalRadius(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setFocalRadius(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradientFunc_setFocalRadius_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFocalRadius(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocalRadius(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRadialGradientFunc_setFocalRadius_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QRadialGradient.setFocalRadius", overloads);
        return 0;
}

static PyObject* Sbk_QRadialGradientFunc_setRadius(PyObject* self, PyObject* pyArg)
{
    ::QRadialGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRadius(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRadius(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRadialGradientFunc_setRadius_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRadius(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRadius(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRadialGradientFunc_setRadius_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QRadialGradient.setRadius", overloads);
        return 0;
}

static PyObject* Sbk_QRadialGradient___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QRadialGradient& cppSelf = *(((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QRadialGradient_methods[] = {
    {"center", (PyCFunction)Sbk_QRadialGradientFunc_center, METH_NOARGS},
    {"centerRadius", (PyCFunction)Sbk_QRadialGradientFunc_centerRadius, METH_NOARGS},
    {"focalPoint", (PyCFunction)Sbk_QRadialGradientFunc_focalPoint, METH_NOARGS},
    {"focalRadius", (PyCFunction)Sbk_QRadialGradientFunc_focalRadius, METH_NOARGS},
    {"radius", (PyCFunction)Sbk_QRadialGradientFunc_radius, METH_NOARGS},
    {"setCenter", (PyCFunction)Sbk_QRadialGradientFunc_setCenter, METH_VARARGS},
    {"setCenterRadius", (PyCFunction)Sbk_QRadialGradientFunc_setCenterRadius, METH_O},
    {"setFocalPoint", (PyCFunction)Sbk_QRadialGradientFunc_setFocalPoint, METH_VARARGS},
    {"setFocalRadius", (PyCFunction)Sbk_QRadialGradientFunc_setFocalRadius, METH_O},
    {"setRadius", (PyCFunction)Sbk_QRadialGradientFunc_setRadius, METH_O},

    {"__copy__", (PyCFunction)Sbk_QRadialGradient___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QRadialGradient_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QRadialGradient_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QRadialGradient_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QRadialGradient",
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
    /*tp_traverse*/         Sbk_QRadialGradient_traverse,
    /*tp_clear*/            Sbk_QRadialGradient_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QRadialGradient_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QRadialGradient_Init,
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
static void QRadialGradient_PythonToCpp_QRadialGradient_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QRadialGradient_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QRadialGradient_PythonToCpp_QRadialGradient_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QRadialGradient_Type))
        return QRadialGradient_PythonToCpp_QRadialGradient_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QRadialGradient_PTR_CppToPython_QRadialGradient(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QRadialGradient*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QRadialGradient_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QRadialGradient_COPY_CppToPython_QRadialGradient(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QRadialGradient_Type, new ::QRadialGradient(*((::QRadialGradient*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QRadialGradient_PythonToCpp_QRadialGradient_COPY(PyObject* pyIn, void* cppOut) {
    *((::QRadialGradient*)cppOut) = *((::QRadialGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QRadialGradient_PythonToCpp_QRadialGradient_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QRadialGradient_Type))
        return QRadialGradient_PythonToCpp_QRadialGradient_COPY;
    return 0;
}

void init_QRadialGradient(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QRADIALGRADIENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QRadialGradient_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QRadialGradient", "QRadialGradient",
        &Sbk_QRadialGradient_Type, &Shiboken::callCppDestructor< ::QRadialGradient >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QRadialGradient_Type,
        QRadialGradient_PythonToCpp_QRadialGradient_PTR,
        is_QRadialGradient_PythonToCpp_QRadialGradient_PTR_Convertible,
        QRadialGradient_PTR_CppToPython_QRadialGradient,
        QRadialGradient_COPY_CppToPython_QRadialGradient);

    Shiboken::Conversions::registerConverterName(converter, "QRadialGradient");
    Shiboken::Conversions::registerConverterName(converter, "QRadialGradient*");
    Shiboken::Conversions::registerConverterName(converter, "QRadialGradient&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QRadialGradient).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QRadialGradient_PythonToCpp_QRadialGradient_COPY,
        is_QRadialGradient_PythonToCpp_QRadialGradient_COPY_Convertible);


    qRegisterMetaType< ::QRadialGradient >("QRadialGradient");
}
