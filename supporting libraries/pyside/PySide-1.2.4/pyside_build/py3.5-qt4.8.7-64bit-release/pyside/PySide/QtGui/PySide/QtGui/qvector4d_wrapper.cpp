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

#include "qvector4d_wrapper.h"

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
Sbk_QVector4D_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QVector4D >()))
        return -1;

    ::QVector4D* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QVector4D", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QVector4D()
    // 1: QVector4D(QPoint)
    // 2: QVector4D(QPointF)
    // 3: QVector4D(QVector2D)
    // 4: QVector4D(QVector2D,qreal,qreal)
    // 5: QVector4D(QVector3D)
    // 6: QVector4D(QVector3D,qreal)
    // 7: QVector4D(QVector4D)
    // 8: QVector4D(qreal,qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QVector4D()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 8; // QVector4D(qreal,qreal,qreal,qreal)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QVector4D(QVector2D)
        } else if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            overloadId = 4; // QVector4D(QVector2D,qreal,qreal)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // QVector4D(QVector3D)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
            overloadId = 6; // QVector4D(QVector3D,qreal)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[0])))) {
        overloadId = 7; // QVector4D(QVector4D)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QVector4D(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QVector4D(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4D_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QVector4D()
        {

            if (!PyErr_Occurred()) {
                // QVector4D()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QVector4D(const QPoint & point)
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
                // QVector4D(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QVector4D(const QPointF & point)
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
                // QVector4D(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QVector4D(const QVector2D & vector)
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
                // QVector4D(QVector2D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QVector4D(const QVector2D & vector, qreal zpos, qreal wpos)
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
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QVector4D(QVector2D,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QVector4D(const QVector3D & vector)
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
                // QVector4D(QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QVector4D(const QVector3D & vector, qreal wpos)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QVector3D cppArg0_local = ::QVector3D();
            ::QVector3D* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QVector4D(QVector3D,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QVector4D(const QVector4D & QVector4D)
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
                // QVector4D(QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // QVector4D(qreal xpos, qreal ypos, qreal zpos, qreal wpos)
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
                // QVector4D(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QVector4D(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QVector4D >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QVector4D_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QVector4D_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "PySide.QtGui.QVector2D", "PySide.QtGui.QVector2D, float, float", "PySide.QtGui.QVector3D", "PySide.QtGui.QVector3D, float", "PySide.QtGui.QVector4D", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector4D", overloads);
        return -1;
}

static PyObject* Sbk_QVector4DFunc___reduce__(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(dddd))", PyObject_Type(self), cppSelf->x(), cppSelf->y(), cppSelf->z(), cppSelf->w());
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

static PyObject* Sbk_QVector4DFunc___repr__(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%f, %f, %f, %f)", ((PyObject*)self)->ob_type->tp_name, cppSelf->x(), cppSelf->y(), cppSelf->z(), cppSelf->w());
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

static PyObject* Sbk_QVector4DFunc_dotProduct(PyObject* self, PyObject* args)
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
    // 0: dotProduct(QVector4D,QVector4D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArgs[1])))) {
        overloadId = 0; // dotProduct(QVector4D,QVector4D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc_dotProduct_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QVector4D cppArg0_local = ::QVector4D();
        ::QVector4D* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
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
            // dotProduct(QVector4D,QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = ::QVector4D::dotProduct(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector4DFunc_dotProduct_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QVector4D.dotProduct", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc_isNull(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QVector4D*>(cppSelf)->isNull();
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

static PyObject* Sbk_QVector4DFunc_length(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->length();
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

static PyObject* Sbk_QVector4DFunc_lengthSquared(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lengthSquared()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->lengthSquared();
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

static PyObject* Sbk_QVector4DFunc_normalize(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QVector4DFunc_normalized(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalized()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector4D cppResult = const_cast<const ::QVector4D*>(cppSelf)->normalized();
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

static PyObject* Sbk_QVector4DFunc_setW(PyObject* self, PyObject* pyArg)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setW(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setW(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc_setW_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setW(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setW(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QVector4DFunc_setW_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.setW", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc_setX(PyObject* self, PyObject* pyArg)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setX(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setX(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc_setX_TypeError;

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

    Sbk_QVector4DFunc_setX_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.setX", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc_setY(PyObject* self, PyObject* pyArg)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setY(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setY(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc_setY_TypeError;

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

    Sbk_QVector4DFunc_setY_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.setY", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc_setZ(PyObject* self, PyObject* pyArg)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setZ(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setZ(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc_setZ_TypeError;

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

    Sbk_QVector4DFunc_setZ_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.setZ", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc_toPoint(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QVector4D*>(cppSelf)->toPoint();
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

static PyObject* Sbk_QVector4DFunc_toPointF(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPointF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QVector4D*>(cppSelf)->toPointF();
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

static PyObject* Sbk_QVector4DFunc_toTuple(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            // TEMPLATE - to_tuple - START
            pyResult = Py_BuildValue("dddd", cppSelf->x(), cppSelf->y(), cppSelf->z(), cppSelf->w());
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

static PyObject* Sbk_QVector4DFunc_toVector2D(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector2D()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector2D cppResult = const_cast<const ::QVector4D*>(cppSelf)->toVector2D();
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

static PyObject* Sbk_QVector4DFunc_toVector2DAffine(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector2DAffine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector2D cppResult = const_cast<const ::QVector4D*>(cppSelf)->toVector2DAffine();
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

static PyObject* Sbk_QVector4DFunc_toVector3D(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector3D()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector3D cppResult = const_cast<const ::QVector4D*>(cppSelf)->toVector3D();
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

static PyObject* Sbk_QVector4DFunc_toVector3DAffine(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector3DAffine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector3D cppResult = const_cast<const ::QVector4D*>(cppSelf)->toVector3DAffine();
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

static PyObject* Sbk_QVector4DFunc_w(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // w()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->w();
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

static PyObject* Sbk_QVector4DFunc_x(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->x();
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

static PyObject* Sbk_QVector4DFunc_y(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->y();
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

static PyObject* Sbk_QVector4DFunc_z(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // z()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QVector4D*>(cppSelf)->z();
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

static PyObject* Sbk_QVector4D___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVector4D& cppSelf = *(((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QVector4D_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QVector4DFunc___reduce__, METH_NOARGS},
    {"dotProduct", (PyCFunction)Sbk_QVector4DFunc_dotProduct, METH_VARARGS|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QVector4DFunc_isNull, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QVector4DFunc_length, METH_NOARGS},
    {"lengthSquared", (PyCFunction)Sbk_QVector4DFunc_lengthSquared, METH_NOARGS},
    {"normalize", (PyCFunction)Sbk_QVector4DFunc_normalize, METH_NOARGS},
    {"normalized", (PyCFunction)Sbk_QVector4DFunc_normalized, METH_NOARGS},
    {"setW", (PyCFunction)Sbk_QVector4DFunc_setW, METH_O},
    {"setX", (PyCFunction)Sbk_QVector4DFunc_setX, METH_O},
    {"setY", (PyCFunction)Sbk_QVector4DFunc_setY, METH_O},
    {"setZ", (PyCFunction)Sbk_QVector4DFunc_setZ, METH_O},
    {"toPoint", (PyCFunction)Sbk_QVector4DFunc_toPoint, METH_NOARGS},
    {"toPointF", (PyCFunction)Sbk_QVector4DFunc_toPointF, METH_NOARGS},
    {"toTuple", (PyCFunction)Sbk_QVector4DFunc_toTuple, METH_NOARGS},
    {"toVector2D", (PyCFunction)Sbk_QVector4DFunc_toVector2D, METH_NOARGS},
    {"toVector2DAffine", (PyCFunction)Sbk_QVector4DFunc_toVector2DAffine, METH_NOARGS},
    {"toVector3D", (PyCFunction)Sbk_QVector4DFunc_toVector3D, METH_NOARGS},
    {"toVector3DAffine", (PyCFunction)Sbk_QVector4DFunc_toVector3DAffine, METH_NOARGS},
    {"w", (PyCFunction)Sbk_QVector4DFunc_w, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QVector4DFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QVector4DFunc_y, METH_NOARGS},
    {"z", (PyCFunction)Sbk_QVector4DFunc_z, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QVector4D___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QVector4D___nb_bool(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QVector4DFunc___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator*(QMatrix4x4,QVector4D)
    // 1: operator*(QVector4D,QMatrix4x4)
    // 2: operator*(QVector4D,QVector4D)
    // 3: operator*(QVector4D,qreal)
    // 4: operator*(qreal,QVector4D)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 4; // operator*(qreal,QVector4D)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 3; // operator*(QVector4D,qreal)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 2; // operator*(QVector4D,QVector4D)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 1; // operator*(QVector4D,QMatrix4x4)
    } else if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX4X4_IDX], (pyArg)))) {
        overloadId = 0; // operator*(QMatrix4x4,QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___mul___TypeError;

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
                // operator*(QMatrix4x4,QVector4D) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector4D cppResult = (*cppArg0) * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
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
                // operator*(QVector4D,QMatrix4x4)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector4D cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
            }
            break;
        }
        case 2: // operator*(const QVector4D & v2)
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
                // operator*(QVector4D,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector4D cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
            }
            break;
        }
        case 3: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(QVector4D,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector4D cppResult = (*cppSelf) * cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator*(qreal factor)
        {
            qreal cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator*(qreal,QVector4D) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QVector4D cppResult = cppArg0 * (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
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

    Sbk_QVector4DFunc___mul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix4x4", "PySide.QtGui.QMatrix4x4", "PySide.QtGui.QVector4D", "float", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___imul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator*=(QVector4D)
    // 1: operator*=(qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 1; // operator*=(qreal)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 0; // operator*=(QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___imul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*=(const QVector4D & vector)
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
                // operator*=(QVector4D)
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

    Sbk_QVector4DFunc___imul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__imul__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator+(QVector4D,QVector4D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QVector4D,QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___add___TypeError;

    // Call function/method
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
            // operator+(QVector4D,QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector4D cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector4DFunc___add___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QVector4D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___iadd___TypeError;

    // Call function/method
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
            // operator+=(QVector4D)
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

    Sbk_QVector4DFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___neg__(PyObject* self)
{
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator-(QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector4D cppResult = - (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QVector4DFunc___sub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator-(QVector4D,QVector4D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 0; // operator-(QVector4D,QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___sub___TypeError;

    // Call function/method
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
            // operator-(QVector4D,QVector4D)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector4D cppResult = (*cppSelf) - (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector4DFunc___sub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__sub__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QVector4D)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___isub___TypeError;

    // Call function/method
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
            // operator-=(QVector4D)
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

    Sbk_QVector4DFunc___isub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___div__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator/(QVector4D,qreal)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // operator/(QVector4D,qreal)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___div___TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator/(QVector4D,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QVector4D cppResult = (*cppSelf) / cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QVector4DFunc___div___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__div__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___idiv__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QVector4DFunc___idiv___TypeError;

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

    Sbk_QVector4DFunc___idiv___TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__idiv__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QVector4D)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QVector4D)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QVector4D) [reverse operator]
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

    Sbk_QVector4DFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QVector4DFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QVector4D* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QVector4D&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QVector4D&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QVector4DFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QVector4D&) [reverse operator]
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

    Sbk_QVector4DFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QVector4D.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QVector4D_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QVector4D& cppSelf = *(((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
                // operator!=(const QVector4D & v2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVector4D cppArg0_local = ::QVector4D();
                ::QVector4D* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (pyArg)))) {
                // operator==(const QVector4D & v2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QVector4D cppArg0_local = ::QVector4D();
                ::QVector4D* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], pythonToCpp))
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
            goto Sbk_QVector4D_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QVector4D_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QVector4D_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QVector4D_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QVector4D_TypeAsNumber;

static SbkObjectType Sbk_QVector4D_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QVector4D",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QVector4DFunc___repr__,
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
    /*tp_traverse*/         Sbk_QVector4D_traverse,
    /*tp_clear*/            Sbk_QVector4D_clear,
    /*tp_richcompare*/      Sbk_QVector4D_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QVector4D_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QVector4D_Init,
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
static void QVector4D_PythonToCpp_QVector4D_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QVector4D_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QVector4D_PythonToCpp_QVector4D_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVector4D_Type))
        return QVector4D_PythonToCpp_QVector4D_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QVector4D_PTR_CppToPython_QVector4D(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QVector4D*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QVector4D_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QVector4D_COPY_CppToPython_QVector4D(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QVector4D_Type, new ::QVector4D(*((::QVector4D*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QVector4D_PythonToCpp_QVector4D_COPY(PyObject* pyIn, void* cppOut) {
    *((::QVector4D*)cppOut) = *((::QVector4D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QVector4D_PythonToCpp_QVector4D_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QVector4D_Type))
        return QVector4D_PythonToCpp_QVector4D_COPY;
    return 0;
}

// Implicit conversions.
static void constQVector2DREF_PythonToCpp_QVector4D(PyObject* pyIn, void* cppOut) {
    *((::QVector4D*)cppOut) = ::QVector4D(*((::QVector2D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQVector2DREF_PythonToCpp_QVector4D_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR2D_IDX], pyIn))
        return constQVector2DREF_PythonToCpp_QVector4D;
    return 0;
}

static void constQVector3DREF_PythonToCpp_QVector4D(PyObject* pyIn, void* cppOut) {
    *((::QVector4D*)cppOut) = ::QVector4D(*((::QVector3D*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQVector3DREF_PythonToCpp_QVector4D_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QVECTOR3D_IDX], pyIn))
        return constQVector3DREF_PythonToCpp_QVector4D;
    return 0;
}

void init_QVector4D(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QVector4D_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QVector4D_TypeAsNumber.nb_rshift = Sbk_QVector4DFunc___rshift__;
    Sbk_QVector4D_TypeAsNumber.nb_subtract = Sbk_QVector4DFunc___sub__;
#ifndef IS_PY3K
    Sbk_QVector4D_TypeAsNumber.nb_divide = Sbk_QVector4DFunc___idiv__;
#endif
    Sbk_QVector4D_TypeAsNumber.nb_negative = Sbk_QVector4DFunc___neg__;
    Sbk_QVector4D_TypeAsNumber.nb_inplace_subtract = Sbk_QVector4DFunc___isub__;
    Sbk_QVector4D_TypeAsNumber.nb_lshift = Sbk_QVector4DFunc___lshift__;
    Sbk_QVector4D_TypeAsNumber.nb_multiply = Sbk_QVector4DFunc___imul__;
#ifndef IS_PY3K
    Sbk_QVector4D_TypeAsNumber.nb_divide = Sbk_QVector4DFunc___div__;
#endif
    Sbk_QVector4D_TypeAsNumber.nb_inplace_add = Sbk_QVector4DFunc___iadd__;
    Sbk_QVector4D_TypeAsNumber.nb_add = Sbk_QVector4DFunc___add__;
    SBK_NB_BOOL(Sbk_QVector4D_TypeAsNumber) = Sbk_QVector4D___nb_bool;
    Sbk_QVector4D_TypeAsNumber.nb_multiply = Sbk_QVector4DFunc___mul__;
    Sbk_QVector4D_TypeAsNumber.nb_true_divide = Sbk_QVector4DFunc___div__;
    Sbk_QVector4D_Type.super.ht_type.tp_as_number = &Sbk_QVector4D_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QVECTOR4D_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QVector4D_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QVector4D", "QVector4D",
        &Sbk_QVector4D_Type, &Shiboken::callCppDestructor< ::QVector4D >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QVector4D_Type,
        QVector4D_PythonToCpp_QVector4D_PTR,
        is_QVector4D_PythonToCpp_QVector4D_PTR_Convertible,
        QVector4D_PTR_CppToPython_QVector4D,
        QVector4D_COPY_CppToPython_QVector4D);

    Shiboken::Conversions::registerConverterName(converter, "QVector4D");
    Shiboken::Conversions::registerConverterName(converter, "QVector4D*");
    Shiboken::Conversions::registerConverterName(converter, "QVector4D&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QVector4D).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QVector4D_PythonToCpp_QVector4D_COPY,
        is_QVector4D_PythonToCpp_QVector4D_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQVector2DREF_PythonToCpp_QVector4D,
        is_constQVector2DREF_PythonToCpp_QVector4D_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQVector3DREF_PythonToCpp_QVector4D,
        is_constQVector3DREF_PythonToCpp_QVector4D_Convertible);


    qRegisterMetaType< ::QVector4D >("QVector4D");
}
