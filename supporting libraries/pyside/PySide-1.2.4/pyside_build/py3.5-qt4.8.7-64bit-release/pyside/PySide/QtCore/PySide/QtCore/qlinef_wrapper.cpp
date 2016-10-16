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

#include "qlinef_wrapper.h"

// Extra includes
#include <qline.h>
#include <qpoint.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QLineF_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QLineF >()))
        return -1;

    ::QLineF* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QLineF_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QLineF", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QLineF()
    // 1: QLineF(QLine)
    // 2: QLineF(QLineF)
    // 3: QLineF(QPointF,QPointF)
    // 4: QLineF(qreal,qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QLineF()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 4; // QLineF(qreal,qreal,qreal,qreal)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 3; // QLineF(QPointF,QPointF)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QLineF(QLine)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QLineF(QLineF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineF_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QLineF()
        {

            if (!PyErr_Occurred()) {
                // QLineF()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLineF();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QLineF(const QLine & line)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QLine cppArg0_local = ::QLine();
            ::QLine* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QLineF(QLine)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLineF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QLineF(const QLineF & QLineF)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QLineF(QLineF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLineF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QLineF(const QPointF & pt1, const QPointF & pt2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QLineF(QPointF,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLineF(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QLineF(qreal x1, qreal y1, qreal x2, qreal y2)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QLineF(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLineF(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QLineF >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QLineF_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QLineF_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QLine", "PySide.QtCore.QLineF", "PySide.QtCore.QPointF, PySide.QtCore.QPointF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF", overloads);
        return -1;
}

static PyObject* Sbk_QLineFFunc___reduce__(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(dddd))", PyObject_Type(self), cppSelf->x1(), cppSelf->y1(), cppSelf->x2(), cppSelf->y2());
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

static PyObject* Sbk_QLineFFunc___repr__(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%f, %f, %f, %f)", ((PyObject*)self)->ob_type->tp_name, cppSelf->x1(), cppSelf->y1(), cppSelf->x2(), cppSelf->y2());
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

static PyObject* Sbk_QLineFFunc_angle(PyObject* self, PyObject* args)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "angle", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: angle()const
    // 1: angle(QLineF)const
    if (numArgs == 0) {
        overloadId = 0; // angle()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArgs[0])))) {
        overloadId = 1; // angle(QLineF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_angle_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // angle() const
        {

            if (!PyErr_Occurred()) {
                // angle()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->angle();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
        case 1: // angle(const QLineF & l) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // angle(QLineF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->angle(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_angle_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QLineF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.angle", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_angleTo(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: angleTo(QLineF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
        overloadId = 0; // angleTo(QLineF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_angleTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLineF cppArg0_local = ::QLineF();
        ::QLineF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // angleTo(QLineF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->angleTo(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_angleTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLineF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.angleTo", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_dx(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dx()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->dx();
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

static PyObject* Sbk_QLineFFunc_dy(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->dy();
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

static PyObject* Sbk_QLineFFunc_fromPolar(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fromPolar", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromPolar(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // fromPolar(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_fromPolar_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromPolar(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLineF cppResult = ::QLineF::fromPolar(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_fromPolar_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.fromPolar", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_intersect(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersect(QLineF,QPointF*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
        overloadId = 0; // intersect(QLineF,QPointF*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_intersect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLineF cppArg0_local = ::QLineF();
        ::QLineF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // intersect(QLineF,QPointF*)const
            // Begin code injection

            QPointF p;
            QLineF::IntersectType retval = cppSelf->intersect(*cppArg0, &p);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX]), &retval));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &p));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_intersect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLineF, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.intersect", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_isNull(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineF*>(cppSelf)->isNull();
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

static PyObject* Sbk_QLineFFunc_length(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->length();
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

static PyObject* Sbk_QLineFFunc_normalVector(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalVector()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLineF cppResult = const_cast<const ::QLineF*>(cppSelf)->normalVector();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineFFunc_p1(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // p1()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QLineF*>(cppSelf)->p1();
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

static PyObject* Sbk_QLineFFunc_p2(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // p2()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QLineF*>(cppSelf)->p2();
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

static PyObject* Sbk_QLineFFunc_pointAt(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: pointAt(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // pointAt(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_pointAt_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // pointAt(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QLineF*>(cppSelf)->pointAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_pointAt_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.pointAt", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setAngle(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAngle(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setAngle(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setAngle_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAngle(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAngle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setAngle_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.setAngle", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setLength(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLength(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setLength(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setLength_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLength(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLength(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setLength_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.setLength", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setLine(PyObject* self, PyObject* args)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLine", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setLine(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 0; // setLine(qreal,qreal,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setLine_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setLine(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLine(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setLine_TypeError:
        const char* overloads[] = {"float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.setLine", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setP1(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setP1(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setP1(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setP1_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setP1(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setP1(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setP1_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.setP1", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setP2(PyObject* self, PyObject* pyArg)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setP2(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setP2(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setP2_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setP2(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setP2(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setP2_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLineF.setP2", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_setPoints(PyObject* self, PyObject* args)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPoints", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPoints(QPointF,QPointF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // setPoints(QPointF,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_setPoints_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPointF cppArg1_local = ::QPointF();
        ::QPointF* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setPoints(QPointF,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPoints(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_setPoints_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.setPoints", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_toLine(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLine cppResult = const_cast<const ::QLineF*>(cppSelf)->toLine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineFFunc_toTuple(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            // TEMPLATE - to_tuple - START
            pyResult = Py_BuildValue("dddd", cppSelf->x1(), cppSelf->y1(), cppSelf->x2(), cppSelf->y2());
            // TEMPLATE - to_tuple - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineFFunc_translate(PyObject* self, PyObject* args)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translate", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: translate(QPointF)
    // 1: translate(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // translate(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // translate(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_translate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translate(const QPointF & p)
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
                // translate(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // translate(qreal dx, qreal dy)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // translate(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineFFunc_translate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.translate", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_translated(PyObject* self, PyObject* args)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translated", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: translated(QPointF)const
    // 1: translated(qreal,qreal)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // translated(qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // translated(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineFFunc_translated_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translated(const QPointF & p) const
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
                // translated(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QLineF cppResult = const_cast<const ::QLineF*>(cppSelf)->translated(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppResult);
            }
            break;
        }
        case 1: // translated(qreal dx, qreal dy) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // translated(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QLineF cppResult = const_cast<const ::QLineF*>(cppSelf)->translated(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineFFunc_translated_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLineF.translated", overloads);
        return 0;
}

static PyObject* Sbk_QLineFFunc_unitVector(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unitVector()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLineF cppResult = const_cast<const ::QLineF*>(cppSelf)->unitVector();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineFFunc_x1(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x1()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->x1();
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

static PyObject* Sbk_QLineFFunc_x2(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x2()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->x2();
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

static PyObject* Sbk_QLineFFunc_y1(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y1()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->y1();
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

static PyObject* Sbk_QLineFFunc_y2(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y2()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QLineF*>(cppSelf)->y2();
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

static PyObject* Sbk_QLineF___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QLineF& cppSelf = *(((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QLineF_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QLineFFunc___reduce__, METH_NOARGS},
    {"angle", (PyCFunction)Sbk_QLineFFunc_angle, METH_VARARGS},
    {"angleTo", (PyCFunction)Sbk_QLineFFunc_angleTo, METH_O},
    {"dx", (PyCFunction)Sbk_QLineFFunc_dx, METH_NOARGS},
    {"dy", (PyCFunction)Sbk_QLineFFunc_dy, METH_NOARGS},
    {"fromPolar", (PyCFunction)Sbk_QLineFFunc_fromPolar, METH_VARARGS|METH_STATIC},
    {"intersect", (PyCFunction)Sbk_QLineFFunc_intersect, METH_O},
    {"isNull", (PyCFunction)Sbk_QLineFFunc_isNull, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QLineFFunc_length, METH_NOARGS},
    {"normalVector", (PyCFunction)Sbk_QLineFFunc_normalVector, METH_NOARGS},
    {"p1", (PyCFunction)Sbk_QLineFFunc_p1, METH_NOARGS},
    {"p2", (PyCFunction)Sbk_QLineFFunc_p2, METH_NOARGS},
    {"pointAt", (PyCFunction)Sbk_QLineFFunc_pointAt, METH_O},
    {"setAngle", (PyCFunction)Sbk_QLineFFunc_setAngle, METH_O},
    {"setLength", (PyCFunction)Sbk_QLineFFunc_setLength, METH_O},
    {"setLine", (PyCFunction)Sbk_QLineFFunc_setLine, METH_VARARGS},
    {"setP1", (PyCFunction)Sbk_QLineFFunc_setP1, METH_O},
    {"setP2", (PyCFunction)Sbk_QLineFFunc_setP2, METH_O},
    {"setPoints", (PyCFunction)Sbk_QLineFFunc_setPoints, METH_VARARGS},
    {"toLine", (PyCFunction)Sbk_QLineFFunc_toLine, METH_NOARGS},
    {"toTuple", (PyCFunction)Sbk_QLineFFunc_toTuple, METH_NOARGS},
    {"translate", (PyCFunction)Sbk_QLineFFunc_translate, METH_VARARGS},
    {"translated", (PyCFunction)Sbk_QLineFFunc_translated, METH_VARARGS},
    {"unitVector", (PyCFunction)Sbk_QLineFFunc_unitVector, METH_NOARGS},
    {"x1", (PyCFunction)Sbk_QLineFFunc_x1, METH_NOARGS},
    {"x2", (PyCFunction)Sbk_QLineFFunc_x2, METH_NOARGS},
    {"y1", (PyCFunction)Sbk_QLineFFunc_y1, METH_NOARGS},
    {"y2", (PyCFunction)Sbk_QLineFFunc_y2, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QLineF___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QLineF___nb_bool(PyObject* self)
{
    ::QLineF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QLineF_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QLineF& cppSelf = *(((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
                // operator!=(const QLineF & d) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QLineF cppArg0_local = ::QLineF();
                ::QLineF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArg)))) {
                // operator==(const QLineF & d) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QLineF cppArg0_local = ::QLineF();
                ::QLineF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp))
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
            goto Sbk_QLineF_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QLineF_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QLineF_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QLineF_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QLineF_TypeAsNumber;

static SbkObjectType Sbk_QLineF_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QLineF",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QLineFFunc___repr__,
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
    /*tp_traverse*/         Sbk_QLineF_traverse,
    /*tp_clear*/            Sbk_QLineF_clear,
    /*tp_richcompare*/      Sbk_QLineF_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QLineF_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QLineF_Init,
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
static void QLineF_IntersectType_PythonToCpp_QLineF_IntersectType(PyObject* pyIn, void* cppOut) {
    *((::QLineF::IntersectType*)cppOut) = (::QLineF::IntersectType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLineF_IntersectType_PythonToCpp_QLineF_IntersectType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX]))
        return QLineF_IntersectType_PythonToCpp_QLineF_IntersectType;
    return 0;
}
static PyObject* QLineF_IntersectType_CppToPython_QLineF_IntersectType(const void* cppIn) {
    int castCppIn = *((::QLineF::IntersectType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QLineF_PythonToCpp_QLineF_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QLineF_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QLineF_PythonToCpp_QLineF_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLineF_Type))
        return QLineF_PythonToCpp_QLineF_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QLineF_PTR_CppToPython_QLineF(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QLineF*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QLineF_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QLineF_COPY_CppToPython_QLineF(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QLineF_Type, new ::QLineF(*((::QLineF*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QLineF_PythonToCpp_QLineF_COPY(PyObject* pyIn, void* cppOut) {
    *((::QLineF*)cppOut) = *((::QLineF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QLineF_PythonToCpp_QLineF_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLineF_Type))
        return QLineF_PythonToCpp_QLineF_COPY;
    return 0;
}

// Implicit conversions.
static void constQLineREF_PythonToCpp_QLineF(PyObject* pyIn, void* cppOut) {
    *((::QLineF*)cppOut) = ::QLineF(*((::QLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQLineREF_PythonToCpp_QLineF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pyIn))
        return constQLineREF_PythonToCpp_QLineF;
    return 0;
}

void init_QLineF(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QLineF_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QLineF_TypeAsNumber) = Sbk_QLineF___nb_bool;
    Sbk_QLineF_Type.super.ht_type.tp_as_number = &Sbk_QLineF_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QLINEF_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QLineF_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QLineF", "QLineF",
        &Sbk_QLineF_Type, &Shiboken::callCppDestructor< ::QLineF >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QLineF_Type,
        QLineF_PythonToCpp_QLineF_PTR,
        is_QLineF_PythonToCpp_QLineF_PTR_Convertible,
        QLineF_PTR_CppToPython_QLineF,
        QLineF_COPY_CppToPython_QLineF);

    Shiboken::Conversions::registerConverterName(converter, "QLineF");
    Shiboken::Conversions::registerConverterName(converter, "QLineF*");
    Shiboken::Conversions::registerConverterName(converter, "QLineF&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLineF).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QLineF_PythonToCpp_QLineF_COPY,
        is_QLineF_PythonToCpp_QLineF_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQLineREF_PythonToCpp_QLineF,
        is_constQLineREF_PythonToCpp_QLineF_Convertible);

    // Initialization of enums.

    // Initialization of enum 'IntersectType'.
    SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLineF_Type,
        "IntersectType",
        "PySide.QtCore.QLineF.IntersectType",
        "QLineF::IntersectType");
    if (!SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX],
        &Sbk_QLineF_Type, "NoIntersection", (long) QLineF::NoIntersection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX],
        &Sbk_QLineF_Type, "BoundedIntersection", (long) QLineF::BoundedIntersection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX],
        &Sbk_QLineF_Type, "UnboundedIntersection", (long) QLineF::UnboundedIntersection))
        return ;
    // Register converter for enum 'QLineF::IntersectType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX],
            QLineF_IntersectType_CppToPython_QLineF_IntersectType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLineF_IntersectType_PythonToCpp_QLineF_IntersectType,
            is_QLineF_IntersectType_PythonToCpp_QLineF_IntersectType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLINEF_INTERSECTTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLineF::IntersectType");
        Shiboken::Conversions::registerConverterName(converter, "IntersectType");
    }
    // End of 'IntersectType' enum.


    qRegisterMetaType< ::QLineF >("QLineF");
    qRegisterMetaType< ::QLineF::IntersectType >("QLineF::IntersectType");
}
