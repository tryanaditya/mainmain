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

#include "qvector3d_wrapper.h"

// Extra includes
#include <QMatrix4x4>
#include <qdatastream.h>
#include <qpoint.h>
#include <qvector2d.h>
#include <qvector3d.h>
#include <qvector4d.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QVector3D_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QVector3D >()))
        return -1;

    ::QVector3D* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QVector3D", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QVector3D()
    // 1: QVector3D(QPoint)
    // 2: QVector3D(QPointF)
    // 3: QVector3D(QVector2D)
    // 4: QVector3D(QVector2D,qreal)
    // 5: QVector3D(QVector3D)
    // 6: QVector3D(QVector4D)
    // 7: QVector3D(qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QVector3D()
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 7; // QVector3D(qreal,qreal,qreal)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QVector3D(QVector2D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
            overloadId = 4; // QVector3D(QVector2D,qreal)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))) {
        overloadId = 5; // QVector3D(QVector3D)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[0])))) {
        overloadId = 6; // QVector3D(QVector4D)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QVector3D(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QVector3D(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3D_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QVector3D()
        {

            if (!PyErr_Occurred()) {
                // QVector3D()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QVector3D(const QPoint & point)
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
                // QVector3D(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QVector3D(const QPointF & point)
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
                // QVector3D(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QVector3D(const QVector2D & vector)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVector2D cppArg0_local = ::QVector2D();
            ::QVector2D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QVector3D(QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QVector3D(const QVector2D & vector, qreal zpos)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVector2D cppArg0_local = ::QVector2D();
            ::QVector2D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QVector3D(QVector2D,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QVector3D(const QVector3D & QVector3D)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVector3D cppArg0_local = ::QVector3D();
            ::QVector3D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QVector3D(QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QVector3D(const QVector4D & vector)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVector4D cppArg0_local = ::QVector4D();
            ::QVector4D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QVector3D(QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QVector3D(qreal xpos, qreal ypos, qreal zpos)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QVector3D(qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector3D(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QVector3D >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QVector3D_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QVector3D_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "PySide.QtGui.QVector2D", "PySide.QtGui.QVector2D, float", "PySide.QtGui.QVector3D", "PySide.QtGui.QVector4D", "float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D", overloads);
        return -1;
}

static PyObject* Sbk_QVector3DFunc___reduce__(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(ddd))", PyObject_Type(self), cppSelf->x(), cppSelf->y(), cppSelf->z());
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

static PyObject* Sbk_QVector3DFunc___repr__(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%f, %f, %f)", ((PyObject*)self)->ob_type->tp_name, cppSelf->x(), cppSelf->y(), cppSelf->z());
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

static PyObject* Sbk_QVector3DFunc_crossProduct(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "crossProduct", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: crossProduct(QVector3D,QVector3D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
        overloadId = 0; // crossProduct(QVector3D,QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_crossProduct_TypeError;

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


        if (!PyErr_Occurred()) {
            // crossProduct(QVector3D,QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector3D cppResult = ::QVector3D::crossProduct(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc_crossProduct_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D.crossProduct", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_distanceToLine(PyObject* self, PyObject* args)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "distanceToLine", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: distanceToLine(QVector3D,QVector3D)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
        overloadId = 0; // distanceToLine(QVector3D,QVector3D)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_distanceToLine_TypeError;

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


        if (!PyErr_Occurred()) {
            // distanceToLine(QVector3D,QVector3D)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->distanceToLine(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc_distanceToLine_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D.distanceToLine", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_distanceToPlane(PyObject* self, PyObject* args)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "distanceToPlane", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: distanceToPlane(QVector3D,QVector3D)const
    // 1: distanceToPlane(QVector3D,QVector3D,QVector3D)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // distanceToPlane(QVector3D,QVector3D)const
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[2])))) {
            overloadId = 1; // distanceToPlane(QVector3D,QVector3D,QVector3D)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_distanceToPlane_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // distanceToPlane(const QVector3D & plane, const QVector3D & normal) const
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


            if (!PyErr_Occurred()) {
                // distanceToPlane(QVector3D,QVector3D)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->distanceToPlane(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
        case 1: // distanceToPlane(const QVector3D & plane1, const QVector3D & plane2, const QVector3D & plane3) const
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
                // distanceToPlane(QVector3D,QVector3D,QVector3D)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->distanceToPlane(*cppArg0, *cppArg1, *cppArg2);
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

    Sbk_QVector3DFunc_distanceToPlane_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", "PySide.QtGui.QVector3D, PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D.distanceToPlane", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_dotProduct(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "dotProduct", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: dotProduct(QVector3D,QVector3D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
        overloadId = 0; // dotProduct(QVector3D,QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_dotProduct_TypeError;

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


        if (!PyErr_Occurred()) {
            // dotProduct(QVector3D,QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = ::QVector3D::dotProduct(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc_dotProduct_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D.dotProduct", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_isNull(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVector3D*>(cppSelf)->isNull();
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

static PyObject* Sbk_QVector3DFunc_length(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->length();
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

static PyObject* Sbk_QVector3DFunc_lengthSquared(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lengthSquared()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->lengthSquared();
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

static PyObject* Sbk_QVector3DFunc_normal(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "normal", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: normal(QVector3D,QVector3D)
    // 1: normal(QVector3D,QVector3D,QVector3D)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // normal(QVector3D,QVector3D)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[2])))) {
            overloadId = 1; // normal(QVector3D,QVector3D,QVector3D)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_normal_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // normal(const QVector3D & v1, const QVector3D & v2)
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


            if (!PyErr_Occurred()) {
                // normal(QVector3D,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = ::QVector3D::normal(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 1: // normal(const QVector3D & v1, const QVector3D & v2, const QVector3D & v3)
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
                // normal(QVector3D,QVector3D,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = ::QVector3D::normal(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc_normal_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", "PySide.QtGui.QVector3D, PySide.QtGui.QVector3D, PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector3D.normal", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_normalize(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->normalize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QVector3DFunc_normalized(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalized()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector3D cppResult = const_cast<const ::QVector3D*>(cppSelf)->normalized();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVector3DFunc_setX(PyObject* self, PyObject* pyArg)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setX(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setX(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_setX_TypeError;

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

    Sbk_QVector3DFunc_setX_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.setX", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_setY(PyObject* self, PyObject* pyArg)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setY(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setY(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_setY_TypeError;

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

    Sbk_QVector3DFunc_setY_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.setY", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_setZ(PyObject* self, PyObject* pyArg)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setZ(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setZ(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc_setZ_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setZ(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setZ(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVector3DFunc_setZ_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.setZ", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc_toPoint(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QVector3D*>(cppSelf)->toPoint();
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

static PyObject* Sbk_QVector3DFunc_toPointF(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPointF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QVector3D*>(cppSelf)->toPointF();
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

static PyObject* Sbk_QVector3DFunc_toTuple(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            // TEMPLATE - to_tuple - START
            pyResult = Py_BuildValue("ddd", cppSelf->x(), cppSelf->y(), cppSelf->z());
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

static PyObject* Sbk_QVector3DFunc_toVector2D(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector2D()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector2D cppResult = const_cast<const ::QVector3D*>(cppSelf)->toVector2D();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVector3DFunc_toVector4D(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector4D()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector4D cppResult = const_cast<const ::QVector3D*>(cppSelf)->toVector4D();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVector3DFunc_x(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->x();
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

static PyObject* Sbk_QVector3DFunc_y(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->y();
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

static PyObject* Sbk_QVector3DFunc_z(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // z()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector3D*>(cppSelf)->z();
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

static PyObject* Sbk_QVector3D___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVector3D& cppSelf = *(((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QVector3D_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QVector3DFunc___reduce__, METH_NOARGS},
    {"crossProduct", (PyCFunction)Sbk_QVector3DFunc_crossProduct, METH_VARARGS|METH_STATIC},
    {"distanceToLine", (PyCFunction)Sbk_QVector3DFunc_distanceToLine, METH_VARARGS},
    {"distanceToPlane", (PyCFunction)Sbk_QVector3DFunc_distanceToPlane, METH_VARARGS},
    {"dotProduct", (PyCFunction)Sbk_QVector3DFunc_dotProduct, METH_VARARGS|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QVector3DFunc_isNull, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QVector3DFunc_length, METH_NOARGS},
    {"lengthSquared", (PyCFunction)Sbk_QVector3DFunc_lengthSquared, METH_NOARGS},
    {"normal", (PyCFunction)Sbk_QVector3DFunc_normal, METH_VARARGS|METH_STATIC},
    {"normalize", (PyCFunction)Sbk_QVector3DFunc_normalize, METH_NOARGS},
    {"normalized", (PyCFunction)Sbk_QVector3DFunc_normalized, METH_NOARGS},
    {"setX", (PyCFunction)Sbk_QVector3DFunc_setX, METH_O},
    {"setY", (PyCFunction)Sbk_QVector3DFunc_setY, METH_O},
    {"setZ", (PyCFunction)Sbk_QVector3DFunc_setZ, METH_O},
    {"toPoint", (PyCFunction)Sbk_QVector3DFunc_toPoint, METH_NOARGS},
    {"toPointF", (PyCFunction)Sbk_QVector3DFunc_toPointF, METH_NOARGS},
    {"toTuple", (PyCFunction)Sbk_QVector3DFunc_toTuple, METH_NOARGS},
    {"toVector2D", (PyCFunction)Sbk_QVector3DFunc_toVector2D, METH_NOARGS},
    {"toVector4D", (PyCFunction)Sbk_QVector3DFunc_toVector4D, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QVector3DFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QVector3DFunc_y, METH_NOARGS},
    {"z", (PyCFunction)Sbk_QVector3DFunc_z, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QVector3D___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QVector3D___nb_bool(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QVector3DFunc___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator*(QVector3D,QMatrix4x4)
    // 1: operator*(QMatrix4x4,QVector3D)
    // 2: operator*(QVector3D,QVector3D)
    // 3: operator*(qreal,QVector3D)
    // 4: operator*(QVector3D,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 4; // operator*(QVector3D,qreal)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 3; // operator*(qreal,QVector3D)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 2; // operator*(QVector3D,QVector3D)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 1; // operator*(QMatrix4x4,QVector3D)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator*(QVector3D,QMatrix4x4)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___mul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*(const QMatrix4x4 & matrix)
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
                // operator*(QVector3D,QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator*(const QMatrix4x4 & matrix)
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
                // operator*(QMatrix4x4,QVector3D) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = (*cppArg0) * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator*(const QVector3D & v2)
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
                // operator*(QVector3D,QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector3D cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(qreal,QVector3D) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector3D cppResult = cppArg0 * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(QVector3D,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector3D cppResult = (*cppSelf) * cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
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

    Sbk_QVector3DFunc___mul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", "PySide.QtGui.QMatrix4x4", "PySide.QtGui.QVector3D", "float", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___imul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator*=(QVector3D)
    // 1: operator*=(qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // operator*=(qreal)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // operator*=(QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___imul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*=(const QVector3D & vector)
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
                // operator*=(QVector3D)
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

    Sbk_QVector3DFunc___imul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__imul__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator+(QVector3D,QVector3D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QVector3D,QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___add___TypeError;

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
            // operator+(QVector3D,QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector3D cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc___add___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QVector3D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___iadd___TypeError;

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
            // operator+=(QVector3D)
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

    Sbk_QVector3DFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___neg__(PyObject* self)
{
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator-(QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector3D cppResult = - (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVector3DFunc___sub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator-(QVector3D,QVector3D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // operator-(QVector3D,QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___sub___TypeError;

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
            // operator-(QVector3D,QVector3D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector3D cppResult = (*cppSelf) - (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc___sub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__sub__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QVector3D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___isub___TypeError;

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
            // operator-=(QVector3D)
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

    Sbk_QVector3DFunc___isub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___div__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator/(QVector3D,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator/(QVector3D,qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___div___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator/(QVector3D,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector3D cppResult = (*cppSelf) / cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector3DFunc___div___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__div__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___idiv__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QVector3DFunc___idiv___TypeError;

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

    Sbk_QVector3DFunc___idiv___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__idiv__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QVector3D)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QVector3D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QVector3D) [reverse operator]
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

    Sbk_QVector3DFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QVector3DFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector3D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QVector3D&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QVector3D&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector3DFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QVector3D&) [reverse operator]
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

    Sbk_QVector3DFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector3D.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QVector3D_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVector3D& cppSelf = *(((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
                // operator!=(const QVector3D & v2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVector3D cppArg0_local = ::QVector3D();
                ::QVector3D* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArg)))) {
                // operator==(const QVector3D & v2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVector3D cppArg0_local = ::QVector3D();
                ::QVector3D* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp))
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
            goto Sbk_QVector3D_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QVector3D_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QVector3D_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QVector3D_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QVector3D_TypeAsNumber;

static SbkObjectType Sbk_QVector3D_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QVector3D",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QVector3DFunc___repr__,
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
    /*tp_traverse*/         Sbk_QVector3D_traverse,
    /*tp_clear*/            Sbk_QVector3D_clear,
    /*tp_richcompare*/      Sbk_QVector3D_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QVector3D_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QVector3D_Init,
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
static void QVector3D_PythonToCpp_QVector3D_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QVector3D_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QVector3D_PythonToCpp_QVector3D_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVector3D_Type))
        return QVector3D_PythonToCpp_QVector3D_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QVector3D_PTR_CppToPython_QVector3D(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QVector3D*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QVector3D_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QVector3D_COPY_CppToPython_QVector3D(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QVector3D_Type, new ::QVector3D(*((::QVector3D*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QVector3D_PythonToCpp_QVector3D_COPY(PyObject* pyIn, void* cppOut) {
    *((::QVector3D*)cppOut) = *((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QVector3D_PythonToCpp_QVector3D_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVector3D_Type))
        return QVector3D_PythonToCpp_QVector3D_COPY;
    return 0;
}

// Implicit conversions.
static void constQVector2DREF_PythonToCpp_QVector3D(PyObject* pyIn, void* cppOut) {
    *((::QVector3D*)cppOut) = ::QVector3D(*((::QVector2D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQVector2DREF_PythonToCpp_QVector3D_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pyIn))
        return constQVector2DREF_PythonToCpp_QVector3D;
    return 0;
}

void init_QVector3D(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QVector3D_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QVector3D_TypeAsNumber.nb_rshift = Sbk_QVector3DFunc___rshift__;
    Sbk_QVector3D_TypeAsNumber.nb_subtract = Sbk_QVector3DFunc___sub__;
#ifndef IS_PY3K
    Sbk_QVector3D_TypeAsNumber.nb_divide = Sbk_QVector3DFunc___idiv__;
#endif
    Sbk_QVector3D_TypeAsNumber.nb_negative = Sbk_QVector3DFunc___neg__;
    Sbk_QVector3D_TypeAsNumber.nb_inplace_subtract = Sbk_QVector3DFunc___isub__;
    Sbk_QVector3D_TypeAsNumber.nb_lshift = Sbk_QVector3DFunc___lshift__;
    Sbk_QVector3D_TypeAsNumber.nb_multiply = Sbk_QVector3DFunc___imul__;
#ifndef IS_PY3K
    Sbk_QVector3D_TypeAsNumber.nb_divide = Sbk_QVector3DFunc___div__;
#endif
    Sbk_QVector3D_TypeAsNumber.nb_inplace_add = Sbk_QVector3DFunc___iadd__;
    Sbk_QVector3D_TypeAsNumber.nb_add = Sbk_QVector3DFunc___add__;
    SBK_NB_BOOL(Sbk_QVector3D_TypeAsNumber) = Sbk_QVector3D___nb_bool;
    Sbk_QVector3D_TypeAsNumber.nb_multiply = Sbk_QVector3DFunc___mul__;
    Sbk_QVector3D_TypeAsNumber.nb_true_divide = Sbk_QVector3DFunc___div__;
    Sbk_QVector3D_Type.super.ht_type.tp_as_number = &Sbk_QVector3D_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QVector3D_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QVector3D", "QVector3D",
        &Sbk_QVector3D_Type, &Shiboken::callCppDestructor< ::QVector3D >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QVector3D_Type,
        QVector3D_PythonToCpp_QVector3D_PTR,
        is_QVector3D_PythonToCpp_QVector3D_PTR_Convertible,
        QVector3D_PTR_CppToPython_QVector3D,
        QVector3D_COPY_CppToPython_QVector3D);

    Shiboken::Conversions::registerConverterName(converter, "QVector3D");
    Shiboken::Conversions::registerConverterName(converter, "QVector3D*");
    Shiboken::Conversions::registerConverterName(converter, "QVector3D&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QVector3D).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QVector3D_PythonToCpp_QVector3D_COPY,
        is_QVector3D_PythonToCpp_QVector3D_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQVector2DREF_PythonToCpp_QVector3D,
        is_constQVector2DREF_PythonToCpp_QVector3D_Convertible);


    qRegisterMetaType< ::QVector3D >("QVector3D");
}
