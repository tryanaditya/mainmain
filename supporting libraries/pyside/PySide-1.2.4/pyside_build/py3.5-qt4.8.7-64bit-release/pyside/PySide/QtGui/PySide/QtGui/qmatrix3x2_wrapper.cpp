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

#include "qmatrix3x2_wrapper.h"

// Extra includes
#include <qgenericmatrix.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMatrix3x2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMatrix3x2 >()))
        return -1;

    ::QMatrix3x2* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMatrix3x2", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMatrix3x2(PySequence*)
    // 1: QMatrix3x2(QMatrix3x2)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMatrix3x2(QMatrix3x2)
    } else if (numArgs == 1
        && PySequence_Check(pyArgs[0])) {
        overloadId = 0; // QMatrix3x2(PySequence*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix3x2_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMatrix3x2(PySequence * arg__1)
        {

            if (!PyErr_Occurred()) {
                // QMatrix3x2(PySequence*)
                // Begin code injection

                // TEMPLATE - matrix_constructor - START
                if (PySequence_Size(pyArgs[1-1]) == 6) {
                    Shiboken::AutoDecRef fast(PySequence_Fast(pyArgs[1-1], "Failed to parse sequence on QMatrix3x2 constructor."));
                    qreal values[6];
                    for(int i=0; i < 6; i++) {
                        PyObject *pv = PySequence_Fast_GET_ITEM(fast.object(), i);
                        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pv, &(values[i]));
                    }
                    cptr = new QMatrix3x2(values);
                }
                // TEMPLATE - matrix_constructor - END

                // End of code injection

            }
            break;
        }
        case 1: // QMatrix3x2(const QMatrix3x2 & QMatrix3x2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMatrix3x2 cppArg0_local = ::QMatrix3x2();
            ::QMatrix3x2* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMatrix3x2(QMatrix3x2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix3x2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMatrix3x2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMatrix3x2_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMatrix3x2_Init_TypeError:
        const char* overloads[] = {"PySequence", "PySide.QtGui.QMatrix3x2", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix3x2", overloads);
        return -1;
}

static PyObject* Sbk_QMatrix3x2Func___reduce__(PyObject* self)
{
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code_matrix - START
            QList< qreal > cppArgs;
            qreal data[6];
            cppSelf->copyDataTo(data);
            int matrixSize = 6;
            for(int size=0; size < matrixSize; size++)
            cppArgs.append(data[size]);

            PyObject *type = PyObject_Type(self);
            PyObject *args = Py_BuildValue("(N)", Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QREAL_IDX], &cppArgs));
            pyResult = Py_BuildValue("(NN)", type, args);
            // TEMPLATE - reduce_code_matrix - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix3x2Func___repr__(PyObject* self)
{
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code_matrix - START
            QString format= QString("%1((").arg(((PyObject*)self)->ob_type->tp_name);

            QList< qreal > cppArgs;
            qreal data[6];
            cppSelf->copyDataTo(data);
            int matrixSize = 6;
            for(int size=0; size < matrixSize; size++) {
            if (size > 0)
                format += ", ";
            format += QString::number(data[size]);
            }
            format += "))";

            pyResult = Shiboken::String::fromCString(qPrintable(format));
            // TEMPLATE - repr_code_matrix - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix3x2Func_data(PyObject* self)
{
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()
            // Begin code injection

            // TEMPLATE - matrix_data_function - START
            const qreal* data = cppSelf->constData();
            PyObject *pyData = PyTuple_New(6);
            if (data) {
                for(int i=0; i < 6; i++)
                    PyTuple_SET_ITEM(pyData, i, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &data[i]));
            }
            return pyData;
            // TEMPLATE - matrix_data_function - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix3x2Func_fill(PyObject* self, PyObject* pyArg)
{
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fill(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // fill(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix3x2Func_fill_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fill(PyObject*)
            // Begin code injection

            // TEMPLATE - matrix_fill_function - START
            qreal value;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyArg, &(value));
            cppSelf->fill(value);
            // TEMPLATE - matrix_fill_function - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix3x2Func_fill_TypeError:
        const char* overloads[] = {"object", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix3x2.fill", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix3x2Func_transposed(PyObject* self)
{
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transposed()
            // Begin code injection

            // TEMPLATE - matrix_transposed_function - START
            QMatrix2x3 transp = cppSelf->transposed();
            return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX2X3_IDX], &transp);
            // TEMPLATE - matrix_transposed_function - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix3x2___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMatrix3x2& cppSelf = *(((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMatrix3x2_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QMatrix3x2Func___reduce__, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QMatrix3x2Func_data, METH_NOARGS},
    {"fill", (PyCFunction)Sbk_QMatrix3x2Func_fill, METH_O},
    {"transposed", (PyCFunction)Sbk_QMatrix3x2Func_transposed, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QMatrix3x2___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QMatrix3x2Func___imul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMatrix3x2Func___imul___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // operator*=(qreal)
            // Begin code injection

            // TEMPLATE - inplace_mult - START
            *cppSelf *= cppArg0;
            return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], &*cppSelf);
            // TEMPLATE - inplace_mult - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QMatrix3x2Func___imul___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix3x2.__imul__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix3x2Func___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QMatrix3x2)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QMatrix3x2)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix3x2Func___iadd___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix3x2 cppArg0 = ::QMatrix3x2();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // operator+=(QMatrix3x2)
            // Begin code injection

            // TEMPLATE - inplace_add - START
            *cppSelf += cppArg0;
            return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], &*cppSelf);
            // TEMPLATE - inplace_add - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QMatrix3x2Func___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix3x2", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix3x2.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix3x2Func___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QMatrix3x2)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QMatrix3x2)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix3x2Func___isub___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix3x2 cppArg0 = ::QMatrix3x2();
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // operator-=(QMatrix3x2)
            // Begin code injection

            // TEMPLATE - inplace_sub - START
            *cppSelf -= cppArg0;
            return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], &*cppSelf);
            // TEMPLATE - inplace_sub - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QMatrix3x2Func___isub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix3x2", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix3x2.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix3x2Func___idiv__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix3x2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMatrix3x2Func___idiv___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);
        SBK_UNUSED(cppArg0)

        if (!PyErr_Occurred()) {
            // operator/=(qreal)
            // Begin code injection

            // TEMPLATE - inplace_div - START
            *cppSelf /= cppArg0;
            return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], &*cppSelf);
            // TEMPLATE - inplace_div - END

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QMatrix3x2Func___idiv___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix3x2.__idiv__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QMatrix3x2_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMatrix3x2& cppSelf = *(((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArg)))) {
                // operator!=(QMatrix3x2 arg__1)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QMatrix3x2 cppArg0 = ::QMatrix3x2();
                pythonToCpp(pyArg, &cppArg0);
                SBK_UNUSED(cppArg0)
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (pyArg)))) {
                // operator==(QMatrix3x2 arg__1)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QMatrix3x2 cppArg0 = ::QMatrix3x2();
                pythonToCpp(pyArg, &cppArg0);
                SBK_UNUSED(cppArg0)
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QMatrix3x2_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QMatrix3x2_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QMatrix3x2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMatrix3x2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QMatrix3x2_TypeAsNumber;

static SbkObjectType Sbk_QMatrix3x2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMatrix3x2",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QMatrix3x2Func___repr__,
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
    /*tp_traverse*/         Sbk_QMatrix3x2_traverse,
    /*tp_clear*/            Sbk_QMatrix3x2_clear,
    /*tp_richcompare*/      Sbk_QMatrix3x2_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMatrix3x2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMatrix3x2_Init,
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
static void QMatrix3x2_PythonToCpp_QMatrix3x2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMatrix3x2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMatrix3x2_PythonToCpp_QMatrix3x2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMatrix3x2_Type))
        return QMatrix3x2_PythonToCpp_QMatrix3x2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMatrix3x2_PTR_CppToPython_QMatrix3x2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMatrix3x2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMatrix3x2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QMatrix3x2_COPY_CppToPython_QMatrix3x2(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QMatrix3x2_Type, new ::QMatrix3x2(*((::QMatrix3x2*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QMatrix3x2_PythonToCpp_QMatrix3x2_COPY(PyObject* pyIn, void* cppOut) {
    *((::QMatrix3x2*)cppOut) = *((::QMatrix3x2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QMatrix3x2_PythonToCpp_QMatrix3x2_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMatrix3x2_Type))
        return QMatrix3x2_PythonToCpp_QMatrix3x2_COPY;
    return 0;
}

void init_QMatrix3x2(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QMatrix3x2_TypeAsNumber, 0, sizeof(PyNumberMethods));
#ifndef IS_PY3K
    Sbk_QMatrix3x2_TypeAsNumber.nb_divide = Sbk_QMatrix3x2Func___idiv__;
#endif
    Sbk_QMatrix3x2_TypeAsNumber.nb_inplace_subtract = Sbk_QMatrix3x2Func___isub__;
    Sbk_QMatrix3x2_TypeAsNumber.nb_multiply = Sbk_QMatrix3x2Func___imul__;
    Sbk_QMatrix3x2_TypeAsNumber.nb_inplace_add = Sbk_QMatrix3x2Func___iadd__;
    Sbk_QMatrix3x2_Type.super.ht_type.tp_as_number = &Sbk_QMatrix3x2_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QMATRIX3X2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMatrix3x2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMatrix3x2", "QMatrix3x2",
        &Sbk_QMatrix3x2_Type, &Shiboken::callCppDestructor< ::QMatrix3x2 >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMatrix3x2_Type,
        QMatrix3x2_PythonToCpp_QMatrix3x2_PTR,
        is_QMatrix3x2_PythonToCpp_QMatrix3x2_PTR_Convertible,
        QMatrix3x2_PTR_CppToPython_QMatrix3x2,
        QMatrix3x2_COPY_CppToPython_QMatrix3x2);

    Shiboken::Conversions::registerConverterName(converter, "QMatrix3x2");
    Shiboken::Conversions::registerConverterName(converter, "QMatrix3x2*");
    Shiboken::Conversions::registerConverterName(converter, "QMatrix3x2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMatrix3x2).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QMatrix3x2_PythonToCpp_QMatrix3x2_COPY,
        is_QMatrix3x2_PythonToCpp_QMatrix3x2_COPY_Convertible);


}
