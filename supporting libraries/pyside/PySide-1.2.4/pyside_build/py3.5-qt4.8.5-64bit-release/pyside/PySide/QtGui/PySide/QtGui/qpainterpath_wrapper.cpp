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

#include "qpainterpath_wrapper.h"
#include "qpainterpath_element_wrapper.h"

// Extra includes
#include <QList>
#include <QPainterPath>
#include <qdatastream.h>
#include <qfont.h>
#include <qmatrix.h>
#include <qpainterpath.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>
#include <qregion.h>
#include <qtransform.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPainterPath_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPainterPath >()))
        return -1;

    ::QPainterPath* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPainterPath", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPainterPath()
    // 1: QPainterPath(QPainterPath)
    // 2: QPainterPath(QPointF)
    if (numArgs == 0) {
        overloadId = 0; // QPainterPath()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPainterPath(QPointF)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPainterPath(QPainterPath)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPath_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPainterPath()
        {

            if (!PyErr_Occurred()) {
                // QPainterPath()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainterPath();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPainterPath(const QPainterPath & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPainterPath(QPainterPath)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainterPath(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPainterPath(const QPointF & startPoint)
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
                // QPainterPath(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainterPath(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPainterPath >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPainterPath_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPainterPath_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath", overloads);
        return -1;
}

static PyObject* Sbk_QPainterPathFunc_addEllipse(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QPainterPathFunc_addEllipse_TypeError;

    if (!PyArg_UnpackTuple(args, "addEllipse", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addEllipse(QPointF,qreal,qreal)
    // 1: addEllipse(QRectF)
    // 2: addEllipse(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 2; // addEllipse(qreal,qreal,qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // addEllipse(QRectF)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 0; // addEllipse(QPointF,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addEllipse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addEllipse(const QPointF & center, qreal rx, qreal ry)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addEllipse(QPointF,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addEllipse(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addEllipse(const QRectF & rect)
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
                // addEllipse(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addEllipse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // addEllipse(qreal x, qreal y, qreal w, qreal h)
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
                // addEllipse(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addEllipse(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addEllipse_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, float, float", "PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.addEllipse", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addPath(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addPath(QPainterPath)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // addPath(QPainterPath)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addPath(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addPath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.addPath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addPolygon(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addPolygon(QPolygonF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 0; // addPolygon(QPolygonF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addPolygon_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPolygonF cppArg0_local = ::QPolygonF();
        ::QPolygonF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addPolygon(QPolygonF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addPolygon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addPolygon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.addPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addRect(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPainterPathFunc_addRect_TypeError;

    if (!PyArg_UnpackTuple(args, "addRect", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addRect(QRectF)
    // 1: addRect(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // addRect(qreal,qreal,qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // addRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addRect(const QRectF & rect)
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
                // addRect(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addRect(qreal x, qreal y, qreal w, qreal h)
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
                // addRect(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRect(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.addRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addRegion(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addRegion(QRegion)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArg)))) {
        overloadId = 0; // addRegion(QRegion)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addRegion_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRegion cppArg0_local = ::QRegion();
        ::QRegion* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addRegion(QRegion)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addRegion(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addRegion_TypeError:
        const char* overloads[] = {"PySide.QtGui.QRegion", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.addRegion", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addRoundRect(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4)
        goto Sbk_QPainterPathFunc_addRoundRect_TypeError;

    if (!PyArg_UnpackTuple(args, "addRoundRect", 2, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addRoundRect(QRectF,int)
    // 1: addRoundRect(QRectF,int,int)
    // 2: addRoundRect(qreal,qreal,qreal,qreal,int)
    // 3: addRoundRect(qreal,qreal,qreal,qreal,int,int)
    if (numArgs >= 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
        if (numArgs == 5) {
            overloadId = 2; // addRoundRect(qreal,qreal,qreal,qreal,int)
        } else if (numArgs == 6
            && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
            overloadId = 3; // addRoundRect(qreal,qreal,qreal,qreal,int,int)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addRoundRect(QRectF,int)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // addRoundRect(QRectF,int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addRoundRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addRoundRect(const QRectF & rect, int roundness)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addRoundRect(QRectF,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addRoundRect(const QRectF & rect, int xRnd, int yRnd)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addRoundRect(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundRect(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // addRoundRect(qreal x, qreal y, qreal w, qreal h, int roundness)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // addRoundRect(qreal,qreal,qreal,qreal,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // addRoundRect(qreal x, qreal y, qreal w, qreal h, int xRnd, int yRnd)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addRoundRect(qreal,qreal,qreal,qreal,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addRoundRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, int", "PySide.QtCore.QRectF, int, int", "float, float, float, float, int", "float, float, float, float, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.addRoundRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addRoundedRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.addRoundedRect(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.addRoundedRect(): not enough arguments");
        return 0;
    } else if (numArgs == 5)
        goto Sbk_QPainterPathFunc_addRoundedRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOO:addRoundedRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: addRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
    // 1: addRoundedRect(qreal,qreal,qreal,qreal,qreal,qreal,Qt::SizeMode)
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 1; // addRoundedRect(qreal,qreal,qreal,qreal,qreal,qreal,Qt::SizeMode)
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[6])))) {
            overloadId = 1; // addRoundedRect(qreal,qreal,qreal,qreal,qreal,qreal,Qt::SizeMode)
        }
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // addRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3])))) {
            overloadId = 0; // addRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addRoundedRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addRoundedRect(const QRectF & rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.addRoundedRect(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterPathFunc_addRoundedRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::SizeMode cppArg3 = Qt::AbsoluteSize;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundedRect(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addRoundedRect(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, Qt::SizeMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.addRoundedRect(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[6]))))
                        goto Sbk_QPainterPathFunc_addRoundedRect_TypeError;
                }
            }
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
            ::Qt::SizeMode cppArg6 = Qt::AbsoluteSize;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // addRoundedRect(qreal,qreal,qreal,qreal,qreal,qreal,Qt::SizeMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRoundedRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addRoundedRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, float, float, PySide.QtCore.Qt.SizeMode = Qt.AbsoluteSize", "float, float, float, float, float, float, PySide.QtCore.Qt.SizeMode = Qt.AbsoluteSize", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.addRoundedRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_addText(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addText", 3, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addText(QPointF,QFont,QString)
    // 1: addText(qreal,qreal,QFont,QString)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
        overloadId = 1; // addText(qreal,qreal,QFont,QString)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // addText(QPointF,QFont,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_addText_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addText(const QPointF & point, const QFont & f, const QString & text)
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
            ::QFont cppArg1_local = ::QFont();
            ::QFont* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addText(QPointF,QFont,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addText(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addText(qreal x, qreal y, const QFont & f, const QString & text)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QFont cppArg2_local = ::QFont();
            ::QFont* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QString cppArg3 = ::QString();
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addText(qreal,qreal,QFont,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addText(cppArg0, cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_addText_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtGui.QFont, unicode", "float, float, PySide.QtGui.QFont, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.addText", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_angleAtPercent(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: angleAtPercent(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // angleAtPercent(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_angleAtPercent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // angleAtPercent(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPath*>(cppSelf)->angleAtPercent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_angleAtPercent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.angleAtPercent", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_arcMoveTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_QPainterPathFunc_arcMoveTo_TypeError;

    if (!PyArg_UnpackTuple(args, "arcMoveTo", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: arcMoveTo(QRectF,qreal)
    // 1: arcMoveTo(qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
        overloadId = 1; // arcMoveTo(qreal,qreal,qreal,qreal,qreal)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // arcMoveTo(QRectF,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_arcMoveTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // arcMoveTo(const QRectF & rect, qreal angle)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // arcMoveTo(QRectF,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->arcMoveTo(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // arcMoveTo(qreal x, qreal y, qreal w, qreal h, qreal angle)
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
                // arcMoveTo(qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->arcMoveTo(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_arcMoveTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, float", "float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.arcMoveTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_arcTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterPathFunc_arcTo_TypeError;

    if (!PyArg_UnpackTuple(args, "arcTo", 3, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: arcTo(QRectF,qreal,qreal)
    // 1: arcTo(qreal,qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        overloadId = 1; // arcTo(qreal,qreal,qreal,qreal,qreal,qreal)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 0; // arcTo(QRectF,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_arcTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // arcTo(const QRectF & rect, qreal startAngle, qreal arcLength)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // arcTo(QRectF,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->arcTo(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // arcTo(qreal x, qreal y, qreal w, qreal h, qreal startAngle, qreal arcLength)
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
                // arcTo(qreal,qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->arcTo(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_arcTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, float, float", "float, float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.arcTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_boundingRect(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->boundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_closeSubpath(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeSubpath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->closeSubpath();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterPathFunc_connectPath(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: connectPath(QPainterPath)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // connectPath(QPainterPath)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_connectPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // connectPath(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->connectPath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_connectPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.connectPath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QPainterPath)const
    // 1: contains(QPointF)const
    // 2: contains(QRectF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 2; // contains(QRectF)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 1; // contains(QPointF)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // contains(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_contains_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // contains(const QPainterPath & p) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // contains(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->contains(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // contains(const QPointF & pt) const
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
                // contains(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->contains(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // contains(const QRectF & rect) const
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
                // contains(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->contains(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.contains", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_controlPointRect(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // controlPointRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->controlPointRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_cubicTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterPathFunc_cubicTo_TypeError;

    if (!PyArg_UnpackTuple(args, "cubicTo", 3, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: cubicTo(QPointF,QPointF,QPointF)
    // 1: cubicTo(qreal,qreal,qreal,qreal,qreal,qreal)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        overloadId = 1; // cubicTo(qreal,qreal,qreal,qreal,qreal,qreal)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
        overloadId = 0; // cubicTo(QPointF,QPointF,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_cubicTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // cubicTo(const QPointF & ctrlPt1, const QPointF & ctrlPt2, const QPointF & endPt)
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

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPointF cppArg2_local = ::QPointF();
            ::QPointF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // cubicTo(QPointF,QPointF,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->cubicTo(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // cubicTo(qreal ctrlPt1x, qreal ctrlPt1y, qreal ctrlPt2x, qreal ctrlPt2y, qreal endPtx, qreal endPty)
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
                // cubicTo(qreal,qreal,qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->cubicTo(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_cubicTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.QPointF, PySide.QtCore.QPointF", "float, float, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.cubicTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_currentPosition(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->currentPosition();
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

static PyObject* Sbk_QPainterPathFunc_elementAt(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: elementAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // elementAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_elementAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // elementAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPainterPath::Element & cppResult = const_cast<const ::QPainterPath*>(cppSelf)->elementAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_elementAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.elementAt", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_elementCount(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // elementCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPainterPath*>(cppSelf)->elementCount();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_fillRule(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fillRule()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::FillRule cppResult = const_cast<const ::QPainterPath*>(cppSelf)->fillRule();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_intersected(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersected(QPainterPath)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // intersected(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_intersected_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // intersected(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->intersected(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_intersected_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.intersected", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_intersects(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersects(QPainterPath)const
    // 1: intersects(QRectF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 1; // intersects(QRectF)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // intersects(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_intersects_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // intersects(const QPainterPath & p) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // intersects(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->intersects(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // intersects(const QRectF & rect) const
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
                // intersects(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->intersects(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_intersects_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.intersects", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_isEmpty(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainterPath*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QPainterPathFunc_length(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPath*>(cppSelf)->length();
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

static PyObject* Sbk_QPainterPathFunc_lineTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "lineTo", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lineTo(QPointF)
    // 1: lineTo(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // lineTo(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // lineTo(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_lineTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // lineTo(const QPointF & p)
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
                // lineTo(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->lineTo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // lineTo(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // lineTo(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->lineTo(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_lineTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.lineTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_moveTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveTo", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveTo(QPointF)
    // 1: moveTo(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // moveTo(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // moveTo(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_moveTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // moveTo(const QPointF & p)
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
                // moveTo(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->moveTo(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // moveTo(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // moveTo(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->moveTo(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_moveTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.moveTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_percentAtLength(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: percentAtLength(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // percentAtLength(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_percentAtLength_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // percentAtLength(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPath*>(cppSelf)->percentAtLength(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_percentAtLength_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.percentAtLength", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_pointAtPercent(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: pointAtPercent(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // pointAtPercent(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_pointAtPercent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // pointAtPercent(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->pointAtPercent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_pointAtPercent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.pointAtPercent", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_quadTo(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QPainterPathFunc_quadTo_TypeError;

    if (!PyArg_UnpackTuple(args, "quadTo", 2, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: quadTo(QPointF,QPointF)
    // 1: quadTo(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // quadTo(qreal,qreal,qreal,qreal)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // quadTo(QPointF,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_quadTo_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // quadTo(const QPointF & ctrlPt, const QPointF & endPt)
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
                // quadTo(QPointF,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->quadTo(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // quadTo(qreal ctrlPtx, qreal ctrlPty, qreal endPtx, qreal endPty)
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
                // quadTo(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->quadTo(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_quadTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.QPointF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.quadTo", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_setElementPositionAt(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setElementPositionAt", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setElementPositionAt(int,qreal,qreal)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 0; // setElementPositionAt(int,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_setElementPositionAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setElementPositionAt(int,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setElementPositionAt(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_setElementPositionAt_TypeError:
        const char* overloads[] = {"int, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.setElementPositionAt", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_setFillRule(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFillRule(Qt::FillRule)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArg)))) {
        overloadId = 0; // setFillRule(Qt::FillRule)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_setFillRule_TypeError;

    // Call function/method
    {
        ::Qt::FillRule cppArg0 = ((::Qt::FillRule)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFillRule(Qt::FillRule)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFillRule(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_setFillRule_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.FillRule", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.setFillRule", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_simplified(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // simplified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->simplified();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_slopeAtPercent(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: slopeAtPercent(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // slopeAtPercent(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_slopeAtPercent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // slopeAtPercent(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPath*>(cppSelf)->slopeAtPercent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_slopeAtPercent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.slopeAtPercent", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_subtracted(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subtracted(QPainterPath)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // subtracted(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_subtracted_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // subtracted(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->subtracted(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_subtracted_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.subtracted", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_subtractedInverted(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subtractedInverted(QPainterPath)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // subtractedInverted(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_subtractedInverted_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // subtractedInverted(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->subtractedInverted(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_subtractedInverted_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.subtractedInverted", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QPainterPath&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // swap(QPainterPath&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QPainterPath&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.swap", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_toFillPolygon(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toFillPolygon(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toFillPolygon", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toFillPolygon(QMatrix)const
    // 1: toFillPolygon(QTransform)const
    if (numArgs == 0) {
        overloadId = 0; // toFillPolygon(QMatrix)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        overloadId = 1; // toFillPolygon(QTransform)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        overloadId = 0; // toFillPolygon(QMatrix)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_toFillPolygon_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toFillPolygon(const QMatrix & matrix) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "matrix");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toFillPolygon(): got multiple values for keyword argument 'matrix'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0]))))
                        goto Sbk_QPainterPathFunc_toFillPolygon_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMatrix cppArg0_local = QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // toFillPolygon(QMatrix)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toFillPolygon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 1: // toFillPolygon(const QTransform & matrix) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // toFillPolygon(QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toFillPolygon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_toFillPolygon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix = QMatrix()", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.toFillPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_toFillPolygons(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toFillPolygons(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toFillPolygons", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toFillPolygons(QMatrix)const
    // 1: toFillPolygons(QTransform)const
    if (numArgs == 0) {
        overloadId = 0; // toFillPolygons(QMatrix)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        overloadId = 1; // toFillPolygons(QTransform)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        overloadId = 0; // toFillPolygons(QMatrix)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_toFillPolygons_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toFillPolygons(const QMatrix & matrix) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "matrix");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toFillPolygons(): got multiple values for keyword argument 'matrix'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0]))))
                        goto Sbk_QPainterPathFunc_toFillPolygons_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMatrix cppArg0_local = QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // toFillPolygons(QMatrix)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPolygonF > cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toFillPolygons(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 1: // toFillPolygons(const QTransform & matrix) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // toFillPolygons(QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPolygonF > cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toFillPolygons(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_toFillPolygons_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix = QMatrix()", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.toFillPolygons", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_toReversed(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toReversed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toReversed();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathFunc_toSubpathPolygons(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toSubpathPolygons(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toSubpathPolygons", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toSubpathPolygons(QMatrix)const
    // 1: toSubpathPolygons(QTransform)const
    if (numArgs == 0) {
        overloadId = 0; // toSubpathPolygons(QMatrix)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        overloadId = 1; // toSubpathPolygons(QTransform)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        overloadId = 0; // toSubpathPolygons(QMatrix)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_toSubpathPolygons_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toSubpathPolygons(const QMatrix & matrix) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "matrix");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainterPath.toSubpathPolygons(): got multiple values for keyword argument 'matrix'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0]))))
                        goto Sbk_QPainterPathFunc_toSubpathPolygons_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMatrix cppArg0_local = QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // toSubpathPolygons(QMatrix)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPolygonF > cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toSubpathPolygons(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 1: // toSubpathPolygons(const QTransform & matrix) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // toSubpathPolygons(QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPolygonF > cppResult = const_cast<const ::QPainterPath*>(cppSelf)->toSubpathPolygons(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_toSubpathPolygons_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix = QMatrix()", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.toSubpathPolygons", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_translate(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPainterPathFunc_translate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translate(const QPointF & offset)
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

    Sbk_QPainterPathFunc_translate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.translate", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_translated(PyObject* self, PyObject* args)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPainterPathFunc_translated_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translated(const QPointF & offset) const
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
                QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->translated(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
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
                QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->translated(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_translated_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainterPath.translated", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc_united(PyObject* self, PyObject* pyArg)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: united(QPainterPath)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // united(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc_united_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // united(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPath*>(cppSelf)->united(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc_united_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.united", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPath___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPainterPath& cppSelf = *(((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPainterPath_methods[] = {
    {"addEllipse", (PyCFunction)Sbk_QPainterPathFunc_addEllipse, METH_VARARGS},
    {"addPath", (PyCFunction)Sbk_QPainterPathFunc_addPath, METH_O},
    {"addPolygon", (PyCFunction)Sbk_QPainterPathFunc_addPolygon, METH_O},
    {"addRect", (PyCFunction)Sbk_QPainterPathFunc_addRect, METH_VARARGS},
    {"addRegion", (PyCFunction)Sbk_QPainterPathFunc_addRegion, METH_O},
    {"addRoundRect", (PyCFunction)Sbk_QPainterPathFunc_addRoundRect, METH_VARARGS},
    {"addRoundedRect", (PyCFunction)Sbk_QPainterPathFunc_addRoundedRect, METH_VARARGS|METH_KEYWORDS},
    {"addText", (PyCFunction)Sbk_QPainterPathFunc_addText, METH_VARARGS},
    {"angleAtPercent", (PyCFunction)Sbk_QPainterPathFunc_angleAtPercent, METH_O},
    {"arcMoveTo", (PyCFunction)Sbk_QPainterPathFunc_arcMoveTo, METH_VARARGS},
    {"arcTo", (PyCFunction)Sbk_QPainterPathFunc_arcTo, METH_VARARGS},
    {"boundingRect", (PyCFunction)Sbk_QPainterPathFunc_boundingRect, METH_NOARGS},
    {"closeSubpath", (PyCFunction)Sbk_QPainterPathFunc_closeSubpath, METH_NOARGS},
    {"connectPath", (PyCFunction)Sbk_QPainterPathFunc_connectPath, METH_O},
    {"contains", (PyCFunction)Sbk_QPainterPathFunc_contains, METH_O},
    {"controlPointRect", (PyCFunction)Sbk_QPainterPathFunc_controlPointRect, METH_NOARGS},
    {"cubicTo", (PyCFunction)Sbk_QPainterPathFunc_cubicTo, METH_VARARGS},
    {"currentPosition", (PyCFunction)Sbk_QPainterPathFunc_currentPosition, METH_NOARGS},
    {"elementAt", (PyCFunction)Sbk_QPainterPathFunc_elementAt, METH_O},
    {"elementCount", (PyCFunction)Sbk_QPainterPathFunc_elementCount, METH_NOARGS},
    {"fillRule", (PyCFunction)Sbk_QPainterPathFunc_fillRule, METH_NOARGS},
    {"intersected", (PyCFunction)Sbk_QPainterPathFunc_intersected, METH_O},
    {"intersects", (PyCFunction)Sbk_QPainterPathFunc_intersects, METH_O},
    {"isEmpty", (PyCFunction)Sbk_QPainterPathFunc_isEmpty, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QPainterPathFunc_length, METH_NOARGS},
    {"lineTo", (PyCFunction)Sbk_QPainterPathFunc_lineTo, METH_VARARGS},
    {"moveTo", (PyCFunction)Sbk_QPainterPathFunc_moveTo, METH_VARARGS},
    {"percentAtLength", (PyCFunction)Sbk_QPainterPathFunc_percentAtLength, METH_O},
    {"pointAtPercent", (PyCFunction)Sbk_QPainterPathFunc_pointAtPercent, METH_O},
    {"quadTo", (PyCFunction)Sbk_QPainterPathFunc_quadTo, METH_VARARGS},
    {"setElementPositionAt", (PyCFunction)Sbk_QPainterPathFunc_setElementPositionAt, METH_VARARGS},
    {"setFillRule", (PyCFunction)Sbk_QPainterPathFunc_setFillRule, METH_O},
    {"simplified", (PyCFunction)Sbk_QPainterPathFunc_simplified, METH_NOARGS},
    {"slopeAtPercent", (PyCFunction)Sbk_QPainterPathFunc_slopeAtPercent, METH_O},
    {"subtracted", (PyCFunction)Sbk_QPainterPathFunc_subtracted, METH_O},
    {"subtractedInverted", (PyCFunction)Sbk_QPainterPathFunc_subtractedInverted, METH_O},
    {"swap", (PyCFunction)Sbk_QPainterPathFunc_swap, METH_O},
    {"toFillPolygon", (PyCFunction)Sbk_QPainterPathFunc_toFillPolygon, METH_VARARGS|METH_KEYWORDS},
    {"toFillPolygons", (PyCFunction)Sbk_QPainterPathFunc_toFillPolygons, METH_VARARGS|METH_KEYWORDS},
    {"toReversed", (PyCFunction)Sbk_QPainterPathFunc_toReversed, METH_NOARGS},
    {"toSubpathPolygons", (PyCFunction)Sbk_QPainterPathFunc_toSubpathPolygons, METH_VARARGS|METH_KEYWORDS},
    {"translate", (PyCFunction)Sbk_QPainterPathFunc_translate, METH_VARARGS},
    {"translated", (PyCFunction)Sbk_QPainterPathFunc_translated, METH_VARARGS},
    {"united", (PyCFunction)Sbk_QPainterPathFunc_united, METH_O},

    {"__copy__", (PyCFunction)Sbk_QPainterPath___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QPainterPathFunc___and__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rand__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rand__"));
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
    // 0: operator&(QPainterPath)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator&(QPainterPath)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___and___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator&(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = (*cppSelf) & (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc___and___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__and__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___iand__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator&=(QPainterPath)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator&=(QPainterPath)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___iand___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator&=(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) &= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPainterPathFunc___iand___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__iand__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    // 0: operator*(QPainterPath,QMatrix)
    // 1: operator*(QPainterPath,QTransform)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 1; // operator*(QPainterPath,QTransform)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArg)))) {
        overloadId = 0; // operator*(QPainterPath,QMatrix)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___mul___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator*(const QMatrix & m)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QMatrix cppArg0_local = ::QMatrix();
            ::QMatrix* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator*(QPainterPath,QMatrix)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator*(const QTransform & m)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTransform cppArg0_local = ::QTransform();
            ::QTransform* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator*(QPainterPath,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
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

    Sbk_QPainterPathFunc___mul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    // 0: operator+(QPainterPath)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QPainterPath)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___add___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc___add___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QPainterPath)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QPainterPath)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___iadd___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+=(QPainterPath)
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

    Sbk_QPainterPathFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___sub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    // 0: operator-(QPainterPath)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator-(QPainterPath)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___sub___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator-(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = (*cppSelf) - (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc___sub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__sub__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(QPainterPath)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator-=(QPainterPath)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___isub___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator-=(QPainterPath)
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

    Sbk_QPainterPathFunc___isub___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__isub__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QPainterPath)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPainterPath)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPainterPath) [reverse operator]
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

    Sbk_QPainterPathFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QPainterPath&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPainterPath&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPainterPath&) [reverse operator]
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

    Sbk_QPainterPathFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__rshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___or__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__ror__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__ror__"));
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
    // 0: operator|(QPainterPath)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator|(QPainterPath)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___or___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator|(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = (*cppSelf) | (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathFunc___or___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__or__", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathFunc___ior__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator|=(QPainterPath)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // operator|=(QPainterPath)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathFunc___ior___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator|=(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) |= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QPainterPathFunc___ior___TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPath.__ior__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QPainterPath_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPainterPath& cppSelf = *(((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
                // operator!=(const QPainterPath & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPainterPath cppArg0_local = ::QPainterPath();
                ::QPainterPath* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
                // operator==(const QPainterPath & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPainterPath cppArg0_local = ::QPainterPath();
                ::QPainterPath* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
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
            goto Sbk_QPainterPath_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPainterPath_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QPainterPath_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPainterPath_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QPainterPath__repr__(PyObject* self)
{
    ::QPainterPath* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QPainterPath_TypeAsNumber;

static SbkObjectType Sbk_QPainterPath_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPainterPath",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QPainterPath__repr__,
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
    /*tp_traverse*/         Sbk_QPainterPath_traverse,
    /*tp_clear*/            Sbk_QPainterPath_clear,
    /*tp_richcompare*/      Sbk_QPainterPath_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPainterPath_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPainterPath_Init,
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
static void QPainterPath_ElementType_PythonToCpp_QPainterPath_ElementType(PyObject* pyIn, void* cppOut) {
    *((::QPainterPath::ElementType*)cppOut) = (::QPainterPath::ElementType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPainterPath_ElementType_PythonToCpp_QPainterPath_ElementType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX]))
        return QPainterPath_ElementType_PythonToCpp_QPainterPath_ElementType;
    return 0;
}
static PyObject* QPainterPath_ElementType_CppToPython_QPainterPath_ElementType(const void* cppIn) {
    int castCppIn = *((::QPainterPath::ElementType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPainterPath_PythonToCpp_QPainterPath_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPainterPath_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPainterPath_PythonToCpp_QPainterPath_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainterPath_Type))
        return QPainterPath_PythonToCpp_QPainterPath_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPainterPath_PTR_CppToPython_QPainterPath(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPainterPath*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPainterPath_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPainterPath_COPY_CppToPython_QPainterPath(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPainterPath_Type, new ::QPainterPath(*((::QPainterPath*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPainterPath_PythonToCpp_QPainterPath_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPainterPath*)cppOut) = *((::QPainterPath*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPainterPath_PythonToCpp_QPainterPath_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainterPath_Type))
        return QPainterPath_PythonToCpp_QPainterPath_COPY;
    return 0;
}

void init_QPainterPath(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPainterPath_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPainterPath_TypeAsNumber.nb_rshift = Sbk_QPainterPathFunc___rshift__;
    Sbk_QPainterPath_TypeAsNumber.nb_subtract = Sbk_QPainterPathFunc___sub__;
    Sbk_QPainterPath_TypeAsNumber.nb_inplace_or = Sbk_QPainterPathFunc___ior__;
    Sbk_QPainterPath_TypeAsNumber.nb_or = Sbk_QPainterPathFunc___or__;
    Sbk_QPainterPath_TypeAsNumber.nb_inplace_subtract = Sbk_QPainterPathFunc___isub__;
    Sbk_QPainterPath_TypeAsNumber.nb_lshift = Sbk_QPainterPathFunc___lshift__;
    Sbk_QPainterPath_TypeAsNumber.nb_inplace_add = Sbk_QPainterPathFunc___iadd__;
    Sbk_QPainterPath_TypeAsNumber.nb_inplace_and = Sbk_QPainterPathFunc___iand__;
    Sbk_QPainterPath_TypeAsNumber.nb_add = Sbk_QPainterPathFunc___add__;
    Sbk_QPainterPath_TypeAsNumber.nb_and = Sbk_QPainterPathFunc___and__;
    Sbk_QPainterPath_TypeAsNumber.nb_multiply = Sbk_QPainterPathFunc___mul__;
    Sbk_QPainterPath_Type.super.ht_type.tp_as_number = &Sbk_QPainterPath_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPainterPath_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPainterPath", "QPainterPath",
        &Sbk_QPainterPath_Type, &Shiboken::callCppDestructor< ::QPainterPath >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPainterPath_Type,
        QPainterPath_PythonToCpp_QPainterPath_PTR,
        is_QPainterPath_PythonToCpp_QPainterPath_PTR_Convertible,
        QPainterPath_PTR_CppToPython_QPainterPath,
        QPainterPath_COPY_CppToPython_QPainterPath);

    Shiboken::Conversions::registerConverterName(converter, "QPainterPath");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPath*");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPath&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPainterPath).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPainterPath_PythonToCpp_QPainterPath_COPY,
        is_QPainterPath_PythonToCpp_QPainterPath_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ElementType'.
    SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPainterPath_Type,
        "ElementType",
        "PySide.QtGui.QPainterPath.ElementType",
        "QPainterPath::ElementType");
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX],
        &Sbk_QPainterPath_Type, "MoveToElement", (long) QPainterPath::MoveToElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX],
        &Sbk_QPainterPath_Type, "LineToElement", (long) QPainterPath::LineToElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX],
        &Sbk_QPainterPath_Type, "CurveToElement", (long) QPainterPath::CurveToElement))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX],
        &Sbk_QPainterPath_Type, "CurveToDataElement", (long) QPainterPath::CurveToDataElement))
        return ;
    // Register converter for enum 'QPainterPath::ElementType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX],
            QPainterPath_ElementType_CppToPython_QPainterPath_ElementType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainterPath_ElementType_PythonToCpp_QPainterPath_ElementType,
            is_QPainterPath_ElementType_PythonToCpp_QPainterPath_ElementType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPainterPath::ElementType");
        Shiboken::Conversions::registerConverterName(converter, "ElementType");
    }
    // End of 'ElementType' enum.


    qRegisterMetaType< ::QPainterPath >("QPainterPath");
    qRegisterMetaType< ::QPainterPath::ElementType >("QPainterPath::ElementType");
}
