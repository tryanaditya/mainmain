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

#include "qpointf_wrapper.h"

// Extra includes
#include <qpoint.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPointF_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPointF >()))
        return -1;

    ::QPointF* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPointF", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QPointF()
    // 1: QPointF(QPoint)
    // 2: QPointF(QPointF)
    // 3: QPointF(qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QPointF()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 3; // QPointF(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPointF(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPointF(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointF_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPointF()
        {

            if (!PyErr_Occurred()) {
                // QPointF()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPointF();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPointF(const QPoint & p)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPointF(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPointF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPointF(const QPointF & QPointF)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPointF(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPointF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QPointF(qreal xpos, qreal ypos)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QPointF(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPointF(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPointF >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPointF_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPointF_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QPointF", overloads);
        return -1;
}

static PyObject* Sbk_QPointFFunc___reduce__(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(dd))", PyObject_Type(self), cppSelf->x(), cppSelf->y());
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

static PyObject* Sbk_QPointFFunc___repr__(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%f, %f)", ((PyObject*)self)->ob_type->tp_name, cppSelf->x(), cppSelf->y());
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

static PyObject* Sbk_QPointFFunc_isNull(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPointF*>(cppSelf)->isNull();
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

static PyObject* Sbk_QPointFFunc_manhattanLength(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // manhattanLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPointF*>(cppSelf)->manhattanLength();
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

static PyObject* Sbk_QPointFFunc_setX(PyObject* self, PyObject* pyArg)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setX(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setX(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc_setX_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setX(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setX(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPointFFunc_setX_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.setX", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc_setY(PyObject* self, PyObject* pyArg)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setY(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setY(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc_setY_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setY(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setY(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPointFFunc_setY_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.setY", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc_toPoint(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QPointF*>(cppSelf)->toPoint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPointFFunc_toTuple(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            // TEMPLATE - to_tuple - START
            pyResult = Py_BuildValue("dd", cppSelf->x(), cppSelf->y());
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

static PyObject* Sbk_QPointFFunc_x(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPointF*>(cppSelf)->x();
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

static PyObject* Sbk_QPointFFunc_y(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPointF*>(cppSelf)->y();
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

static PyObject* Sbk_QPointF___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPointF& cppSelf = *(((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPointF_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QPointFFunc___reduce__, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QPointFFunc_isNull, METH_NOARGS},
    {"manhattanLength", (PyCFunction)Sbk_QPointFFunc_manhattanLength, METH_NOARGS},
    {"setX", (PyCFunction)Sbk_QPointFFunc_setX, METH_O},
    {"setY", (PyCFunction)Sbk_QPointFFunc_setY, METH_O},
    {"toPoint", (PyCFunction)Sbk_QPointFFunc_toPoint, METH_NOARGS},
    {"toTuple", (PyCFunction)Sbk_QPointFFunc_toTuple, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QPointFFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QPointFFunc_y, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QPointF___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QPointF___nb_bool(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QPointFFunc___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rmul__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rmul__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator*(QPointF,qreal)
    // 1: operator*(qreal,QPointF)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // operator*(qreal,QPointF)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator*(QPointF,qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___mul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*(qreal c)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(QPointF,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QPointF cppResult = (*cppSelf) * cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator*(qreal c)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(qreal,QPointF) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QPointF cppResult = cppArg0 * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPointFFunc___mul___TypeError:
        const char* overloads[] = {"float", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___imul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator*=(qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator*=(qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___imul___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator*=(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) *= cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPointFFunc___imul___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__imul__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__radd__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__radd__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator+(QPointF,QPointF)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QPointF,QPointF)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___add___TypeError;

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
            // operator+(QPointF,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPointFFunc___add___TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QPointF)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QPointF)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___iadd___TypeError;

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
            // operator+=(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) += (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPointFFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___neg__(PyObject* self)
{
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator-(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF cppResult = - (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPointFFunc___sub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rsub__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rsub__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator-(QPointF,QPointF)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // operator-(QPointF,QPointF)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___sub___TypeError;

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
            // operator-(QPointF,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF cppResult = (*cppSelf) - (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPointFFunc___sub___TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__sub__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QPointF)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QPointF)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___isub___TypeError;

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
            // operator-=(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) -= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPointFFunc___isub___TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___div__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rdiv__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rdiv__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator/(QPointF,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator/(QPointF,qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___div___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator/(QPointF,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF cppResult = (*cppSelf) / cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPointFFunc___div___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__div__", overloads);
        return 0;
}

static PyObject* Sbk_QPointFFunc___idiv__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPointF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator/=(qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator/=(qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPointFFunc___idiv___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator/=(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) /= cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPointFFunc___idiv___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QPointF.__idiv__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QPointF_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPointF& cppSelf = *(((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
                // operator!=(const QPointF & p2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPointF cppArg0_local = ::QPointF();
                ::QPointF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
                // operator==(const QPointF & p2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPointF cppArg0_local = ::QPointF();
                ::QPointF* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
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
            goto Sbk_QPointF_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPointF_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QPointF_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPointF_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPointF_TypeAsNumber;

static SbkObjectType Sbk_QPointF_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QPointF",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QPointFFunc___repr__,
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
    /*tp_traverse*/         Sbk_QPointF_traverse,
    /*tp_clear*/            Sbk_QPointF_clear,
    /*tp_richcompare*/      Sbk_QPointF_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPointF_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPointF_Init,
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
static void QPointF_PythonToCpp_QPointF_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPointF_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPointF_PythonToCpp_QPointF_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPointF_Type))
        return QPointF_PythonToCpp_QPointF_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPointF_PTR_CppToPython_QPointF(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPointF*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPointF_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPointF_COPY_CppToPython_QPointF(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPointF_Type, new ::QPointF(*((::QPointF*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPointF_PythonToCpp_QPointF_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPointF*)cppOut) = *((::QPointF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPointF_PythonToCpp_QPointF_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPointF_Type))
        return QPointF_PythonToCpp_QPointF_COPY;
    return 0;
}

// Implicit conversions.
static void constQPointREF_PythonToCpp_QPointF(PyObject* pyIn, void* cppOut) {
    *((::QPointF*)cppOut) = ::QPointF(*((::QPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPointREF_PythonToCpp_QPointF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyIn))
        return constQPointREF_PythonToCpp_QPointF;
    return 0;
}

void init_QPointF(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPointF_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPointF_TypeAsNumber.nb_subtract = Sbk_QPointFFunc___sub__;
#ifndef IS_PY3K
    Sbk_QPointF_TypeAsNumber.nb_divide = Sbk_QPointFFunc___idiv__;
#endif
    Sbk_QPointF_TypeAsNumber.nb_negative = Sbk_QPointFFunc___neg__;
    Sbk_QPointF_TypeAsNumber.nb_inplace_subtract = Sbk_QPointFFunc___isub__;
    Sbk_QPointF_TypeAsNumber.nb_multiply = Sbk_QPointFFunc___imul__;
#ifndef IS_PY3K
    Sbk_QPointF_TypeAsNumber.nb_divide = Sbk_QPointFFunc___div__;
#endif
    Sbk_QPointF_TypeAsNumber.nb_inplace_add = Sbk_QPointFFunc___iadd__;
    Sbk_QPointF_TypeAsNumber.nb_add = Sbk_QPointFFunc___add__;
    SBK_NB_BOOL(Sbk_QPointF_TypeAsNumber) = Sbk_QPointF___nb_bool;
    Sbk_QPointF_TypeAsNumber.nb_multiply = Sbk_QPointFFunc___mul__;
    Sbk_QPointF_TypeAsNumber.nb_true_divide = Sbk_QPointFFunc___div__;
    Sbk_QPointF_Type.super.ht_type.tp_as_number = &Sbk_QPointF_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPointF_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPointF", "QPointF",
        &Sbk_QPointF_Type, &Shiboken::callCppDestructor< ::QPointF >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPointF_Type,
        QPointF_PythonToCpp_QPointF_PTR,
        is_QPointF_PythonToCpp_QPointF_PTR_Convertible,
        QPointF_PTR_CppToPython_QPointF,
        QPointF_COPY_CppToPython_QPointF);

    Shiboken::Conversions::registerConverterName(converter, "QPointF");
    Shiboken::Conversions::registerConverterName(converter, "QPointF*");
    Shiboken::Conversions::registerConverterName(converter, "QPointF&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPointF).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPointF_PythonToCpp_QPointF_COPY,
        is_QPointF_PythonToCpp_QPointF_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPointREF_PythonToCpp_QPointF,
        is_constQPointREF_PythonToCpp_QPointF_Convertible);


    qRegisterMetaType< ::QPointF >("QPointF");
}
