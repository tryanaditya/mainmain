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

#include "qmatrix4x4_wrapper.h"

// Extra includes
#include <qdatastream.h>
#include <qgenericmatrix.h>
#include <qmatrix.h>
#include <qmatrix4x4.h>
#include <qpoint.h>
#include <qquaternion.h>
#include <qrect.h>
#include <qtransform.h>
#include <qvector3d.h>
#include <qvector4d.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMatrix4x4_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMatrix4x4 >()))
        return -1;

    ::QMatrix4x4* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3 || numArgs == 4 || numArgs == 5 || numArgs == 6 || numArgs == 7 || numArgs == 8 || numArgs == 9 || numArgs == 10 || numArgs == 11 || numArgs == 12 || numArgs == 13 || numArgs == 14 || numArgs == 15)
        goto Sbk_QMatrix4x4_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QMatrix4x4", 0, 16, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10]), &(pyArgs[11]), &(pyArgs[12]), &(pyArgs[13]), &(pyArgs[14]), &(pyArgs[15])))
        return -1;


    // Overloaded function decisor
    // 0: QMatrix4x4()
    // 1: QMatrix4x4(QMatrix)
    // 2: QMatrix4x4(QMatrix4x4)
    // 3: QMatrix4x4(QTransform)
    // 4: QMatrix4x4(const qreal*)
    // 5: QMatrix4x4(qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QMatrix4x4()
    } else if (numArgs == 16
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[8])))
        && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[9])))
        && (pythonToCpp[10] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[10])))
        && (pythonToCpp[11] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[11])))
        && (pythonToCpp[12] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[12])))
        && (pythonToCpp[13] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[13])))
        && (pythonToCpp[14] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[14])))
        && (pythonToCpp[15] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[15])))) {
        overloadId = 5; // QMatrix4x4(qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        overloadId = 3; // QMatrix4x4(QTransform)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMatrix4x4(QMatrix)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArgs[0])))) {
        overloadId = 2; // QMatrix4x4(QMatrix4x4)
    } else if (numArgs == 1
        && PySequence_Check(pyArgs[0])) {
        overloadId = 4; // QMatrix4x4(const qreal*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMatrix4x4()
        {

            if (!PyErr_Occurred()) {
                // QMatrix4x4()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix4x4();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QMatrix4x4(const QMatrix & matrix)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMatrix cppArg0_local = ::QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMatrix4x4(QMatrix)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix4x4(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QMatrix4x4(const QMatrix4x4 & QMatrix4x4)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
            ::QMatrix4x4* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMatrix4x4(QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix4x4(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QMatrix4x4(const QTransform & transform)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMatrix4x4(QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix4x4(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QMatrix4x4(const qreal * values)
        {

            if (!PyErr_Occurred()) {
                // QMatrix4x4(const qreal*)
                // Begin code injection

                if (PySequence_Size(pyArgs[1-1]) == 16) {
                    qreal values[16];
                    for(int i=0; i < 16; i++) {
                        PyObject *pv = PySequence_Fast_GET_ITEM(pyArgs[1-1], i);
                        values[i] = PyFloat_AsDouble(pv);
                    }

                    cptr = new QMatrix4x4(values[0], values[1], values[2], values[3],
                                   values[4], values[5], values[6], values[7],
                                   values[8], values[9], values[10], values[11],
                                   values[12], values[13], values[14], values[15]);
                }

                // End of code injection

            }
            break;
        }
        case 5: // QMatrix4x4(qreal m11, qreal m12, qreal m13, qreal m14, qreal m21, qreal m22, qreal m23, qreal m24, qreal m31, qreal m32, qreal m33, qreal m34, qreal m41, qreal m42, qreal m43, qreal m44)
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
            qreal cppArg6;
            pythonToCpp[6](pyArgs[6], &cppArg6);
            qreal cppArg7;
            pythonToCpp[7](pyArgs[7], &cppArg7);
            qreal cppArg8;
            pythonToCpp[8](pyArgs[8], &cppArg8);
            qreal cppArg9;
            pythonToCpp[9](pyArgs[9], &cppArg9);
            qreal cppArg10;
            pythonToCpp[10](pyArgs[10], &cppArg10);
            qreal cppArg11;
            pythonToCpp[11](pyArgs[11], &cppArg11);
            qreal cppArg12;
            pythonToCpp[12](pyArgs[12], &cppArg12);
            qreal cppArg13;
            pythonToCpp[13](pyArgs[13], &cppArg13);
            qreal cppArg14;
            pythonToCpp[14](pyArgs[14], &cppArg14);
            qreal cppArg15;
            pythonToCpp[15](pyArgs[15], &cppArg15);

            if (!PyErr_Occurred()) {
                // QMatrix4x4(qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMatrix4x4(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12, cppArg13, cppArg14, cppArg15);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMatrix4x4 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMatrix4x4_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMatrix4x4_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QMatrix", "PySide.QtGui.QMatrix4x4", "PySide.QtGui.QTransform", "PySide.QtCore.qreal", "float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4", overloads);
        return -1;
}

static PyObject* Sbk_QMatrix4x4Func___reduce__(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code_matrix - START
            QList< qreal > cppArgs;
            qreal data[16];
            cppSelf->copyDataTo(data);
            int matrixSize = 16;
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

static PyObject* Sbk_QMatrix4x4Func___repr__(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code_matrix - START
            QString format= QString("%1((").arg(((PyObject*)self)->ob_type->tp_name);

            QList< qreal > cppArgs;
            qreal data[16];
            cppSelf->copyDataTo(data);
            int matrixSize = 16;
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

static PyObject* Sbk_QMatrix4x4Func_column(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: column(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // column(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_column_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // column(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector4D cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->column(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_column_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.column", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_copyDataTo(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // copyDataTo(qreal*)const
            // Begin code injection

            qreal values[16];
            cppSelf->copyDataTo(values);
            pyResult = PyTuple_New(16);
            for(int i=0; i < 16; i++) {
              PyObject *v = PyFloat_FromDouble(values[i]);
              PyTuple_SET_ITEM(pyResult, i, v);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4Func_data(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()
            // Begin code injection

            // TEMPLATE - matrix_data_function - START
            const qreal* data = cppSelf->constData();
            PyObject *pyData = PyTuple_New(16);
            if (data) {
                for(int i=0; i < 16; i++)
                    PyTuple_SET_ITEM(pyData, i, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &data[i]));
            }
            return pyData;
            // TEMPLATE - matrix_data_function - END

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal * cppResult = cppSelf->data();
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

static PyObject* Sbk_QMatrix4x4Func_determinant(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // determinant()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->determinant();
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

static PyObject* Sbk_QMatrix4x4Func_fill(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fill(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // fill(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_fill_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fill(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->fill(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_fill_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.fill", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_flipCoordinates(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flipCoordinates()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->flipCoordinates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMatrix4x4Func_frustum(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "frustum", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: frustum(qreal,qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        overloadId = 0; // frustum(qreal,qreal,qreal,qreal,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_frustum_TypeError;

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
        qreal cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        qreal cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // frustum(qreal,qreal,qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->frustum(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_frustum_TypeError:
        const char* overloads[] = {"float, float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.frustum", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_inverted(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // inverted(bool*)const
            // Begin code injection

            // TEMPLATE - fix_bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 retval_ = cppSelf->inverted(&ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4Func_isIdentity(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isIdentity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->isIdentity();
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

static PyObject* Sbk_QMatrix4x4Func_lookAt(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "lookAt", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: lookAt(QVector3D,QVector3D,QVector3D)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[2])))) {
        overloadId = 0; // lookAt(QVector3D,QVector3D,QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_lookAt_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QVector3D cppArg0_local = ::QVector3D();
        ::QVector3D* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QVector3D cppArg1_local = ::QVector3D();
        ::QVector3D* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QVector3D cppArg2_local = ::QVector3D();
        ::QVector3D* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // lookAt(QVector3D,QVector3D,QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->lookAt(*cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_lookAt_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.lookAt", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_map(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: map(QPoint)const
    // 1: map(QPointF)const
    // 2: map(QVector3D)const
    // 3: map(QVector4D)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 2; // map(QVector3D)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 3; // map(QVector4D)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // map(QPoint)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 1; // map(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_map_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // map(const QPoint & point) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // map(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPoint cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->map(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
            }
            break;
        }
        case 1: // map(const QPointF & point) const
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
                // map(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->map(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // map(const QVector3D & point) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QVector3D cppArg0_local = ::QVector3D();
            ::QVector3D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // map(QVector3D)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->map(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 3: // map(const QVector4D & point) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QVector4D cppArg0_local = ::QVector4D();
            ::QVector4D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // map(QVector4D)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector4D cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->map(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_map_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "PySide.QtGui.QVector3D", "PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.map", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_mapRect(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mapRect(QRect)const
    // 1: mapRect(QRectF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // mapRect(QRect)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 1; // mapRect(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_mapRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRect(const QRect & rect) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRect(QRect)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->mapRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRect(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRect(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->mapRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_mapRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.mapRect", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_mapVector(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mapVector(QVector3D)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // mapVector(QVector3D)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_mapVector_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QVector3D cppArg0_local = ::QVector3D();
        ::QVector3D* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // mapVector(QVector3D)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector3D cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->mapVector(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_mapVector_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.mapVector", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_normalMatrix(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalMatrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix3x3 cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->normalMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX3X3_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4Func_optimize(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // optimize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->optimize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMatrix4x4Func_ortho(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3 || numArgs == 4 || numArgs == 5)
        goto Sbk_QMatrix4x4Func_ortho_TypeError;

    if (!PyArg_UnpackTuple(args, "ortho", 1, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: ortho(QRect)
    // 1: ortho(QRectF)
    // 2: ortho(qreal,qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        overloadId = 2; // ortho(qreal,qreal,qreal,qreal,qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // ortho(QRect)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // ortho(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_ortho_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ortho(const QRect & rect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ortho(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ortho(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ortho(const QRectF & rect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ortho(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ortho(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // ortho(qreal left, qreal right, qreal bottom, qreal top, qreal nearPlane, qreal farPlane)
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
                // ortho(qreal,qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ortho(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_ortho_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "PySide.QtCore.QRectF", "float, float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.ortho", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_perspective(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "perspective", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: perspective(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 0; // perspective(qreal,qreal,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_perspective_TypeError;

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
            // perspective(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->perspective(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_perspective_TypeError:
        const char* overloads[] = {"float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.perspective", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_rotate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMatrix4x4.rotate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMatrix4x4.rotate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:rotate", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: rotate(QQuaternion)
    // 1: rotate(qreal,QVector3D)
    // 2: rotate(qreal,qreal,qreal,qreal)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))) {
        if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // rotate(qreal,qreal,qreal,qreal)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
                overloadId = 2; // rotate(qreal,qreal,qreal,qreal)
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
            overloadId = 1; // rotate(qreal,QVector3D)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QQUATERNION_IDX], (pyArgs[0])))) {
        overloadId = 0; // rotate(QQuaternion)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_rotate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // rotate(const QQuaternion & quaternion)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QQuaternion cppArg0_local = ::QQuaternion();
            ::QQuaternion* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QQUATERNION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // rotate(QQuaternion)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->rotate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // rotate(qreal angle, const QVector3D & vector)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QVector3D cppArg1_local = ::QVector3D();
            ::QVector3D* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // rotate(qreal,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->rotate(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // rotate(qreal angle, qreal x, qreal y, qreal z)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "z");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMatrix4x4.rotate(): got multiple values for keyword argument 'z'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                        goto Sbk_QMatrix4x4Func_rotate_TypeError;
                }
            }
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3 = 0.0f;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // rotate(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->rotate(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_rotate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QQuaternion", "float, PySide.QtGui.QVector3D", "float, float, float, float = 0.0f", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.rotate", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_row(PyObject* self, PyObject* pyArg)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: row(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // row(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_row_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // row(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector4D cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->row(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_row_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.row", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_scale(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scale", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: scale(QVector3D)
    // 1: scale(qreal)
    // 2: scale(qreal,qreal)
    // 3: scale(qreal,qreal,qreal)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // scale(qreal)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // scale(qreal,qreal)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
                overloadId = 3; // scale(qreal,qreal,qreal)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))) {
        overloadId = 0; // scale(QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_scale_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // scale(const QVector3D & vector)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QVector3D cppArg0_local = ::QVector3D();
            ::QVector3D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // scale(QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scale(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // scale(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // scale(qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scale(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // scale(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // scale(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scale(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // scale(qreal x, qreal y, qreal z)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // scale(qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scale(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_scale_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", "float", "float, float", "float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.scale", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_setColumn(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumn", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumn(int,QVector4D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
        overloadId = 0; // setColumn(int,QVector4D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_setColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QVector4D cppArg1_local = ::QVector4D();
        ::QVector4D* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setColumn(int,QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumn(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_setColumn_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.setColumn", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_setRow(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRow", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRow(int,QVector4D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
        overloadId = 0; // setRow(int,QVector4D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_setRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QVector4D cppArg1_local = ::QVector4D();
        ::QVector4D* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setRow(int,QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRow(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_setRow_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.setRow", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_setToIdentity(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setToIdentity()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToIdentity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QMatrix4x4Func_toAffine(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toAffine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->toAffine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4Func_toTransform(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "toTransform", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toTransform()const
    // 1: toTransform(qreal)const
    if (numArgs == 0) {
        overloadId = 0; // toTransform()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))) {
        overloadId = 1; // toTransform(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_toTransform_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toTransform() const
        {

            if (!PyErr_Occurred()) {
                // toTransform()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTransform cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->toTransform();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
            }
            break;
        }
        case 1: // toTransform(qreal distanceToPlane) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toTransform(qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTransform cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->toTransform(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func_toTransform_TypeError:
        const char* overloads[] = {"", "float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.toTransform", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_translate(PyObject* self, PyObject* args)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translate", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: translate(QVector3D)
    // 1: translate(qreal,qreal)
    // 2: translate(qreal,qreal,qreal)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // translate(qreal,qreal)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            overloadId = 2; // translate(qreal,qreal,qreal)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))) {
        overloadId = 0; // translate(QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func_translate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translate(const QVector3D & vector)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QVector3D cppArg0_local = ::QVector3D();
            ::QVector3D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // translate(QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // translate(qreal x, qreal y)
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
        case 2: // translate(qreal x, qreal y, qreal z)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // translate(qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMatrix4x4Func_translate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", "float, float", "float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMatrix4x4.translate", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func_transposed(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transposed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 cppResult = const_cast<const ::QMatrix4x4*>(cppSelf)->transposed();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMatrix4x4& cppSelf = *(((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMatrix4x4_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QMatrix4x4Func___reduce__, METH_NOARGS},
    {"column", (PyCFunction)Sbk_QMatrix4x4Func_column, METH_O},
    {"copyDataTo", (PyCFunction)Sbk_QMatrix4x4Func_copyDataTo, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QMatrix4x4Func_data, METH_NOARGS},
    {"determinant", (PyCFunction)Sbk_QMatrix4x4Func_determinant, METH_NOARGS},
    {"fill", (PyCFunction)Sbk_QMatrix4x4Func_fill, METH_O},
    {"flipCoordinates", (PyCFunction)Sbk_QMatrix4x4Func_flipCoordinates, METH_NOARGS},
    {"frustum", (PyCFunction)Sbk_QMatrix4x4Func_frustum, METH_VARARGS},
    {"inverted", (PyCFunction)Sbk_QMatrix4x4Func_inverted, METH_NOARGS},
    {"isIdentity", (PyCFunction)Sbk_QMatrix4x4Func_isIdentity, METH_NOARGS},
    {"lookAt", (PyCFunction)Sbk_QMatrix4x4Func_lookAt, METH_VARARGS},
    {"map", (PyCFunction)Sbk_QMatrix4x4Func_map, METH_O},
    {"mapRect", (PyCFunction)Sbk_QMatrix4x4Func_mapRect, METH_O},
    {"mapVector", (PyCFunction)Sbk_QMatrix4x4Func_mapVector, METH_O},
    {"normalMatrix", (PyCFunction)Sbk_QMatrix4x4Func_normalMatrix, METH_NOARGS},
    {"optimize", (PyCFunction)Sbk_QMatrix4x4Func_optimize, METH_NOARGS},
    {"ortho", (PyCFunction)Sbk_QMatrix4x4Func_ortho, METH_VARARGS},
    {"perspective", (PyCFunction)Sbk_QMatrix4x4Func_perspective, METH_VARARGS},
    {"rotate", (PyCFunction)Sbk_QMatrix4x4Func_rotate, METH_VARARGS|METH_KEYWORDS},
    {"row", (PyCFunction)Sbk_QMatrix4x4Func_row, METH_O},
    {"scale", (PyCFunction)Sbk_QMatrix4x4Func_scale, METH_VARARGS},
    {"setColumn", (PyCFunction)Sbk_QMatrix4x4Func_setColumn, METH_VARARGS},
    {"setRow", (PyCFunction)Sbk_QMatrix4x4Func_setRow, METH_VARARGS},
    {"setToIdentity", (PyCFunction)Sbk_QMatrix4x4Func_setToIdentity, METH_NOARGS},
    {"toAffine", (PyCFunction)Sbk_QMatrix4x4Func_toAffine, METH_NOARGS},
    {"toTransform", (PyCFunction)Sbk_QMatrix4x4Func_toTransform, METH_VARARGS},
    {"translate", (PyCFunction)Sbk_QMatrix4x4Func_translate, METH_VARARGS},
    {"transposed", (PyCFunction)Sbk_QMatrix4x4Func_transposed, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QMatrix4x4___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QMatrix4x4Func___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
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
    // 0: operator*(QMatrix4x4,QMatrix4x4)
    // 1: operator*(QPoint,QMatrix4x4)
    // 2: operator*(QPointF,QMatrix4x4)
    // 3: operator*(qreal,QMatrix4x4)
    // 4: operator*(QMatrix4x4,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 4; // operator*(QMatrix4x4,qreal)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 3; // operator*(qreal,QMatrix4x4)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 1; // operator*(QPoint,QMatrix4x4)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 2; // operator*(QPointF,QMatrix4x4)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator*(QMatrix4x4,QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___mul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*(const QMatrix4x4 & m2)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
            ::QMatrix4x4* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator*(QMatrix4x4,QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMatrix4x4 cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator*(const QPoint & point)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator*(QPoint,QMatrix4x4) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPoint cppResult = (*cppArg0) * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator*(const QPointF & point)
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
                // operator*(QPointF,QMatrix4x4) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = (*cppArg0) * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(qreal,QMatrix4x4) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMatrix4x4 cppResult = cppArg0 * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(QMatrix4x4,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMatrix4x4 cppResult = (*cppSelf) * cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
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

    Sbk_QMatrix4x4Func___mul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "float", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___imul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator*=(QMatrix4x4)
    // 1: operator*=(qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // operator*=(qreal)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator*=(QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___imul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*=(const QMatrix4x4 & other)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
            ::QMatrix4x4* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator*=(QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) *= (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // operator*=(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*=(qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) *= cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QMatrix4x4Func___imul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__imul__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
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
    // 0: operator+(QMatrix4x4,QMatrix4x4)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QMatrix4x4,QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___add___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
        ::QMatrix4x4* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+(QMatrix4x4,QMatrix4x4)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func___add___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QMatrix4x4)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___iadd___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
        ::QMatrix4x4* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+=(QMatrix4x4)
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

    Sbk_QMatrix4x4Func___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___neg__(PyObject* self)
{
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator-(QMatrix4x4)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 cppResult = - (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMatrix4x4Func___sub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
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
    // 0: operator-(QMatrix4x4,QMatrix4x4)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator-(QMatrix4x4,QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___sub___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
        ::QMatrix4x4* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator-(QMatrix4x4,QMatrix4x4)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 cppResult = (*cppSelf) - (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func___sub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__sub__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QMatrix4x4)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___isub___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
        ::QMatrix4x4* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator-=(QMatrix4x4)
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

    Sbk_QMatrix4x4Func___isub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___div__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
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
    // 0: operator/(QMatrix4x4,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator/(QMatrix4x4,qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___div___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator/(QMatrix4x4,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix4x4 cppResult = (*cppSelf) / cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func___div___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__div__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___idiv__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___idiv___TypeError;

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

    Sbk_QMatrix4x4Func___idiv___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__idiv__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
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
    // 0: operator<<(QDataStream&,QMatrix4x4)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QMatrix4x4) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QMatrix4x4Func___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
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
    // 0: operator>>(QDataStream&,QMatrix4x4&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QMatrix4x4&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMatrix4x4Func___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QMatrix4x4&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMatrix4x4Func___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMatrix4x4.__rshift__", overloads);
        return 0;
}

PyObject* Sbk_QMatrix4x4Func___mgetitem__(PyObject* self, PyObject* _key)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMatrix4x4* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self));
    // Begin code injection

    if (PySequence_Check(_key)) {
        Shiboken::AutoDecRef key(PySequence_Fast(_key, "Invalid matrix index."));
        if (PySequence_Fast_GET_SIZE(key.object()) == 2) {
            PyObject* posx = PySequence_Fast_GET_ITEM(key.object(), 0);
            PyObject* posy = PySequence_Fast_GET_ITEM(key.object(), 1);
            Py_ssize_t x = PyInt_AsSsize_t(posx);
            Py_ssize_t y = PyInt_AsSsize_t(posy);
            qreal ret = (*cppSelf)(x,y);
            return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &ret);
        }
    }
    PyErr_SetString(PyExc_IndexError, "Invalid matrix index.");
    return 0;

    // End of code injection
}

// Rich comparison
static PyObject* Sbk_QMatrix4x4_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMatrix4x4& cppSelf = *(((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
                // operator!=(const QMatrix4x4 & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
                ::QMatrix4x4* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
                // operator==(const QMatrix4x4 & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QMatrix4x4 cppArg0_local = ::QMatrix4x4();
                ::QMatrix4x4* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], pythonToCpp))
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
            goto Sbk_QMatrix4x4_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QMatrix4x4_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QMatrix4x4_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMatrix4x4_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QMatrix4x4_TypeAsNumber;

static PyMappingMethods Sbk_QMatrix4x4_TypeAsMapping;

static SbkObjectType Sbk_QMatrix4x4_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMatrix4x4",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QMatrix4x4Func___repr__,
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
    /*tp_traverse*/         Sbk_QMatrix4x4_traverse,
    /*tp_clear*/            Sbk_QMatrix4x4_clear,
    /*tp_richcompare*/      Sbk_QMatrix4x4_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMatrix4x4_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMatrix4x4_Init,
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
static void QMatrix4x4_PythonToCpp_QMatrix4x4_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMatrix4x4_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMatrix4x4_PythonToCpp_QMatrix4x4_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMatrix4x4_Type))
        return QMatrix4x4_PythonToCpp_QMatrix4x4_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMatrix4x4_PTR_CppToPython_QMatrix4x4(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMatrix4x4*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMatrix4x4_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QMatrix4x4_COPY_CppToPython_QMatrix4x4(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QMatrix4x4_Type, new ::QMatrix4x4(*((::QMatrix4x4*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QMatrix4x4_PythonToCpp_QMatrix4x4_COPY(PyObject* pyIn, void* cppOut) {
    *((::QMatrix4x4*)cppOut) = *((::QMatrix4x4*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QMatrix4x4_PythonToCpp_QMatrix4x4_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMatrix4x4_Type))
        return QMatrix4x4_PythonToCpp_QMatrix4x4_COPY;
    return 0;
}

// Implicit conversions.
static void constQMatrixREF_PythonToCpp_QMatrix4x4(PyObject* pyIn, void* cppOut) {
    *((::QMatrix4x4*)cppOut) = ::QMatrix4x4(*((::QMatrix*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQMatrixREF_PythonToCpp_QMatrix4x4_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pyIn))
        return constQMatrixREF_PythonToCpp_QMatrix4x4;
    return 0;
}

static void constQTransformREF_PythonToCpp_QMatrix4x4(PyObject* pyIn, void* cppOut) {
    *((::QMatrix4x4*)cppOut) = ::QMatrix4x4(*((::QTransform*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQTransformREF_PythonToCpp_QMatrix4x4_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pyIn))
        return constQTransformREF_PythonToCpp_QMatrix4x4;
    return 0;
}

void init_QMatrix4x4(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QMatrix4x4_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QMatrix4x4_TypeAsNumber.nb_rshift = Sbk_QMatrix4x4Func___rshift__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_subtract = Sbk_QMatrix4x4Func___sub__;
#ifndef IS_PY3K
    Sbk_QMatrix4x4_TypeAsNumber.nb_divide = Sbk_QMatrix4x4Func___idiv__;
#endif
    Sbk_QMatrix4x4_TypeAsNumber.nb_negative = Sbk_QMatrix4x4Func___neg__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_inplace_subtract = Sbk_QMatrix4x4Func___isub__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_lshift = Sbk_QMatrix4x4Func___lshift__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_multiply = Sbk_QMatrix4x4Func___imul__;
#ifndef IS_PY3K
    Sbk_QMatrix4x4_TypeAsNumber.nb_divide = Sbk_QMatrix4x4Func___div__;
#endif
    Sbk_QMatrix4x4_TypeAsNumber.nb_inplace_add = Sbk_QMatrix4x4Func___iadd__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_add = Sbk_QMatrix4x4Func___add__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_multiply = Sbk_QMatrix4x4Func___mul__;
    Sbk_QMatrix4x4_TypeAsNumber.nb_true_divide = Sbk_QMatrix4x4Func___div__;
    Sbk_QMatrix4x4_Type.super.ht_type.tp_as_number = &Sbk_QMatrix4x4_TypeAsNumber;

    // type supports mapping protocol
    memset(&Sbk_QMatrix4x4_TypeAsMapping, 0, sizeof(PyMappingMethods));
    Sbk_QMatrix4x4_TypeAsMapping.mp_ass_subscript = 0;
    Sbk_QMatrix4x4_TypeAsMapping.mp_length = 0;
    Sbk_QMatrix4x4_TypeAsMapping.mp_subscript = &Sbk_QMatrix4x4Func___mgetitem__;
    Sbk_QMatrix4x4_Type.super.ht_type.tp_as_mapping = &Sbk_QMatrix4x4_TypeAsMapping;

    SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMatrix4x4_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMatrix4x4", "QMatrix4x4",
        &Sbk_QMatrix4x4_Type, &Shiboken::callCppDestructor< ::QMatrix4x4 >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMatrix4x4_Type,
        QMatrix4x4_PythonToCpp_QMatrix4x4_PTR,
        is_QMatrix4x4_PythonToCpp_QMatrix4x4_PTR_Convertible,
        QMatrix4x4_PTR_CppToPython_QMatrix4x4,
        QMatrix4x4_COPY_CppToPython_QMatrix4x4);

    Shiboken::Conversions::registerConverterName(converter, "QMatrix4x4");
    Shiboken::Conversions::registerConverterName(converter, "QMatrix4x4*");
    Shiboken::Conversions::registerConverterName(converter, "QMatrix4x4&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMatrix4x4).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QMatrix4x4_PythonToCpp_QMatrix4x4_COPY,
        is_QMatrix4x4_PythonToCpp_QMatrix4x4_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQMatrixREF_PythonToCpp_QMatrix4x4,
        is_constQMatrixREF_PythonToCpp_QMatrix4x4_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQTransformREF_PythonToCpp_QMatrix4x4,
        is_constQTransformREF_PythonToCpp_QMatrix4x4_Convertible);


    qRegisterMetaType< ::QMatrix4x4 >("QMatrix4x4");
}
