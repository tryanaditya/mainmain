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

#include "qpolygonf_wrapper.h"

// Extra includes
#include <QList>
#include <QMatrix>
#include <QTransform>
#include <QVector>
#include <qdatastream.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPolygonF_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPolygonF >()))
        return -1;

    ::QPolygonF* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPolygonF", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPolygonF()
    // 1: QPolygonF(QPolygon)
    // 2: QPolygonF(QPolygonF)
    // 3: QPolygonF(QRectF)
    // 4: QPolygonF(QVector<QPointF>)
    // 5: QPolygonF(int)
    if (numArgs == 0) {
        overloadId = 0; // QPolygonF()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 5; // QPolygonF(int)
    } else if (numArgs == 1
        && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArgs[0])
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 4; // QPolygonF(QVector<QPointF>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // QPolygonF(QRectF)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPolygonF(QPolygon)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPolygonF(QPolygonF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonF_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPolygonF()
        {

            if (!PyErr_Occurred()) {
                // QPolygonF()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPolygonF(const QPolygon & a)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPolygonF(QPolygon)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPolygonF(const QPolygonF & a)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPolygonF(QPolygonF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QPolygonF(const QRectF & r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPolygonF(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QPolygonF(const QVector<QPointF > & v)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPolygonF(QVector<QPointF>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QPolygonF(int size)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPolygonF(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPolygonF(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPolygonF >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPolygonF_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPolygonF_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPolygon", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "list", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF", overloads);
        return -1;
}

static PyObject* Sbk_QPolygonFFunc_append(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: append(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // append(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_append_TypeError;

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
            // append(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->append(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_append_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.append", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: at(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // at(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF & cppResult = const_cast<const ::QPolygonF*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.at", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_boundingRect(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->boundingRect();
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

static PyObject* Sbk_QPolygonFFunc_capacity(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->capacity();
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

static PyObject* Sbk_QPolygonFFunc_clear(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPolygonFFunc_constData(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // constData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF * cppResult = const_cast<const ::QPolygonF*>(cppSelf)->constData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QPointF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // contains(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_contains_TypeError;

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
            // contains(QPointF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->contains(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.contains", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_containsPoint(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "containsPoint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: containsPoint(QPointF,Qt::FillRule)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // containsPoint(QPointF,Qt::FillRule)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_containsPoint_TypeError;

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

        ::Qt::FillRule cppArg1 = ((::Qt::FillRule)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // containsPoint(QPointF,Qt::FillRule)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->containsPoint(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_containsPoint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.Qt.FillRule", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.containsPoint", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_count(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "count", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: count()const
    // 1: count(QPointF)const
    if (numArgs == 0) {
        overloadId = 0; // count()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // count(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_count_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // count() const
        {

            if (!PyErr_Occurred()) {
                // count()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->count();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // count(const QPointF & t) const
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
                // count(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->count(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_count_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.count", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_data(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF * cppResult = cppSelf->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_empty(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // empty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->empty();
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

static PyObject* Sbk_QPolygonFFunc_endsWith(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endsWith(QPointF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // endsWith(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_endsWith_TypeError;

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
            // endsWith(QPointF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->endsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_endsWith_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.endsWith", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_erase(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "erase", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: erase(QPointF*,QPointF*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // erase(QPointF*,QPointF*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_erase_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPointF* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // erase(QPointF*,QPointF*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF * cppResult = cppSelf->erase(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_erase_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.erase", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_fill(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.fill(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.fill(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fill", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fill(QPointF,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fill(QPointF,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // fill(QPointF,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_fill_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "size");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.fill(): got multiple values for keyword argument 'size'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QPolygonFFunc_fill_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fill(QPointF,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QPointF > & cppResult = cppSelf->fill(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_fill_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.fill", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_first(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // first()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF & cppResult = cppSelf->first();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_fromList(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromList(QList<QPointF>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // fromList(QList<QPointF>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_fromList_TypeError;

    // Call function/method
    {
        ::QList<QPointF > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromList(QList<QPointF>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QPointF > cppResult = ::QPolygonF::fromList(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_fromList_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.fromList", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_front(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // front()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF & cppResult = cppSelf->front();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_indexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.indexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.indexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:indexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: indexOf(QPointF,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexOf(QPointF,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // indexOf(QPointF,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_indexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.indexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QPolygonFFunc_indexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // indexOf(QPointF,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->indexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_indexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.indexOf", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_insert(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insert(QPointF*,int,QPointF)
    // 1: insert(int,QPointF)
    // 2: insert(int,int,QPointF)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
            overloadId = 2; // insert(int,int,QPointF)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 1; // insert(int,QPointF)
        }
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
        overloadId = 0; // insert(QPointF*,int,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_insert_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insert(QPointF * before, int n, const QPointF & t)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
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
                // insert(QPointF*,int,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF * cppResult = cppSelf->insert(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // insert(int i, const QPointF & t)
        {
            int cppArg0;
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
                // insert(int,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 2: // insert(int i, int n, const QPointF & t)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
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
                // insert(int,int,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_insert_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, int, PySide.QtCore.QPointF", "int, PySide.QtCore.QPointF", "int, int, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.insert", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_intersected(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersected(QPolygonF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 0; // intersected(QPolygonF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_intersected_TypeError;

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
            // intersected(QPolygonF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPolygonF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->intersected(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_intersected_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.intersected", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_isClosed(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isClosed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->isClosed();
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

static PyObject* Sbk_QPolygonFFunc_isEmpty(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QPolygonFFunc_isSharedWith(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSharedWith(QVector<QPointF>)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // isSharedWith(QVector<QPointF>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_isSharedWith_TypeError;

    // Call function/method
    {
        ::QVector<QPointF > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isSharedWith(QVector<QPointF>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->isSharedWith(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_isSharedWith_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.isSharedWith", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_last(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // last()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF & cppResult = cppSelf->last();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_lastIndexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.lastIndexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.lastIndexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:lastIndexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lastIndexOf(QPointF,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // lastIndexOf(QPointF,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // lastIndexOf(QPointF,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_lastIndexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.lastIndexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QPolygonFFunc_lastIndexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // lastIndexOf(QPointF,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->lastIndexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_lastIndexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.lastIndexOf", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_mid(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.mid(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.mid(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:mid", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mid(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // mid(int,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // mid(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_mid_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "length");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPolygonF.mid(): got multiple values for keyword argument 'length'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QPolygonFFunc_mid_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mid(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QPointF > cppResult = const_cast<const ::QPolygonF*>(cppSelf)->mid(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_mid_TypeError:
        const char* overloads[] = {"int, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.mid", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_pop_back(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pop_back()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pop_back();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPolygonFFunc_pop_front(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pop_front()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pop_front();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPolygonFFunc_prepend(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prepend(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // prepend(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_prepend_TypeError;

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
            // prepend(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->prepend(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_prepend_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.prepend", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_push_back(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: push_back(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // push_back(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_push_back_TypeError;

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
            // push_back(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->push_back(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_push_back_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.push_back", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_push_front(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: push_front(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // push_front(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_push_front_TypeError;

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
            // push_front(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->push_front(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_push_front_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.push_front", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_remove(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "remove", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: remove(int)
    // 1: remove(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // remove(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // remove(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_remove_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // remove(int i)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // remove(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->remove(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // remove(int i, int n)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // remove(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->remove(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_remove_TypeError:
        const char* overloads[] = {"int", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.remove", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_replace(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(int,QPointF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(int,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_replace_TypeError;

    // Call function/method
    {
        int cppArg0;
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
            // replace(int,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->replace(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_replace_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.replace", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_reserve(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reserve(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // reserve(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_reserve_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reserve(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reserve(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_reserve_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.reserve", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_resize(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // resize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_resize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_resize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.resize", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_setSharable(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSharable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSharable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_setSharable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSharable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSharable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_setSharable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.setSharable", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_size(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPolygonF*>(cppSelf)->size();
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

static PyObject* Sbk_QPolygonFFunc_squeeze(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // squeeze()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->squeeze();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPolygonFFunc_startsWith(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startsWith(QPointF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // startsWith(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_startsWith_TypeError;

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
            // startsWith(QPointF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPolygonF*>(cppSelf)->startsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_startsWith_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.startsWith", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_subtracted(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: subtracted(QPolygonF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 0; // subtracted(QPolygonF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_subtracted_TypeError;

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
            // subtracted(QPolygonF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPolygonF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->subtracted(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_subtracted_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.subtracted", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QPolygonF&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 0; // swap(QPolygonF&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_swap_TypeError;

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
            // swap(QPolygonF&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPolygonFFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.swap", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_toList(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QPointF > cppResult = const_cast<const ::QPolygonF*>(cppSelf)->toList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_toPolygon(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPolygon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPolygon cppResult = const_cast<const ::QPolygonF*>(cppSelf)->toPolygon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPolygonFFunc_translate(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPolygonFFunc_translate_TypeError;

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

    Sbk_QPolygonFFunc_translate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.translate", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_translated(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPolygonFFunc_translated_TypeError;

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
                QPolygonF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->translated(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
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
                QPolygonF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->translated(cppArg0, cppArg1);
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

    Sbk_QPolygonFFunc_translated_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.translated", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_united(PyObject* self, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: united(QPolygonF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 0; // united(QPolygonF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_united_TypeError;

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
            // united(QPolygonF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPolygonF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->united(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_united_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.united", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc_value(PyObject* self, PyObject* args)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "value", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: value(int)const
    // 1: value(int,QPointF)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // value(int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 1; // value(int,QPointF)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc_value_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // value(int i) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // value(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // value(int i, const QPointF & defaultValue) const
        {
            int cppArg0;
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
                // value(int,QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QPolygonF*>(cppSelf)->value(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc_value_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPolygonF.value", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonF___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPolygonF& cppSelf = *(((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPolygonF_methods[] = {
    {"append", (PyCFunction)Sbk_QPolygonFFunc_append, METH_O},
    {"at", (PyCFunction)Sbk_QPolygonFFunc_at, METH_O},
    {"boundingRect", (PyCFunction)Sbk_QPolygonFFunc_boundingRect, METH_NOARGS},
    {"capacity", (PyCFunction)Sbk_QPolygonFFunc_capacity, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QPolygonFFunc_clear, METH_NOARGS},
    {"constData", (PyCFunction)Sbk_QPolygonFFunc_constData, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QPolygonFFunc_contains, METH_O},
    {"containsPoint", (PyCFunction)Sbk_QPolygonFFunc_containsPoint, METH_VARARGS},
    {"count", (PyCFunction)Sbk_QPolygonFFunc_count, METH_VARARGS},
    {"data", (PyCFunction)Sbk_QPolygonFFunc_data, METH_NOARGS},
    {"empty", (PyCFunction)Sbk_QPolygonFFunc_empty, METH_NOARGS},
    {"endsWith", (PyCFunction)Sbk_QPolygonFFunc_endsWith, METH_O},
    {"erase", (PyCFunction)Sbk_QPolygonFFunc_erase, METH_VARARGS},
    {"fill", (PyCFunction)Sbk_QPolygonFFunc_fill, METH_VARARGS|METH_KEYWORDS},
    {"first", (PyCFunction)Sbk_QPolygonFFunc_first, METH_NOARGS},
    {"fromList", (PyCFunction)Sbk_QPolygonFFunc_fromList, METH_O|METH_STATIC},
    {"front", (PyCFunction)Sbk_QPolygonFFunc_front, METH_NOARGS},
    {"indexOf", (PyCFunction)Sbk_QPolygonFFunc_indexOf, METH_VARARGS|METH_KEYWORDS},
    {"insert", (PyCFunction)Sbk_QPolygonFFunc_insert, METH_VARARGS},
    {"intersected", (PyCFunction)Sbk_QPolygonFFunc_intersected, METH_O},
    {"isClosed", (PyCFunction)Sbk_QPolygonFFunc_isClosed, METH_NOARGS},
    {"isEmpty", (PyCFunction)Sbk_QPolygonFFunc_isEmpty, METH_NOARGS},
    {"isSharedWith", (PyCFunction)Sbk_QPolygonFFunc_isSharedWith, METH_O},
    {"last", (PyCFunction)Sbk_QPolygonFFunc_last, METH_NOARGS},
    {"lastIndexOf", (PyCFunction)Sbk_QPolygonFFunc_lastIndexOf, METH_VARARGS|METH_KEYWORDS},
    {"mid", (PyCFunction)Sbk_QPolygonFFunc_mid, METH_VARARGS|METH_KEYWORDS},
    {"pop_back", (PyCFunction)Sbk_QPolygonFFunc_pop_back, METH_NOARGS},
    {"pop_front", (PyCFunction)Sbk_QPolygonFFunc_pop_front, METH_NOARGS},
    {"prepend", (PyCFunction)Sbk_QPolygonFFunc_prepend, METH_O},
    {"push_back", (PyCFunction)Sbk_QPolygonFFunc_push_back, METH_O},
    {"push_front", (PyCFunction)Sbk_QPolygonFFunc_push_front, METH_O},
    {"remove", (PyCFunction)Sbk_QPolygonFFunc_remove, METH_VARARGS},
    {"replace", (PyCFunction)Sbk_QPolygonFFunc_replace, METH_VARARGS},
    {"reserve", (PyCFunction)Sbk_QPolygonFFunc_reserve, METH_O},
    {"resize", (PyCFunction)Sbk_QPolygonFFunc_resize, METH_O},
    {"setSharable", (PyCFunction)Sbk_QPolygonFFunc_setSharable, METH_O},
    {"size", (PyCFunction)Sbk_QPolygonFFunc_size, METH_NOARGS},
    {"squeeze", (PyCFunction)Sbk_QPolygonFFunc_squeeze, METH_NOARGS},
    {"startsWith", (PyCFunction)Sbk_QPolygonFFunc_startsWith, METH_O},
    {"subtracted", (PyCFunction)Sbk_QPolygonFFunc_subtracted, METH_O},
    {"swap", (PyCFunction)Sbk_QPolygonFFunc_swap, METH_O},
    {"toList", (PyCFunction)Sbk_QPolygonFFunc_toList, METH_NOARGS},
    {"toPolygon", (PyCFunction)Sbk_QPolygonFFunc_toPolygon, METH_NOARGS},
    {"translate", (PyCFunction)Sbk_QPolygonFFunc_translate, METH_VARARGS},
    {"translated", (PyCFunction)Sbk_QPolygonFFunc_translated, METH_VARARGS},
    {"united", (PyCFunction)Sbk_QPolygonFFunc_united, METH_O},
    {"value", (PyCFunction)Sbk_QPolygonFFunc_value, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QPolygonF___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QPolygonFFunc___mul__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    // 0: operator*(QPolygonF,QMatrix)
    // 1: operator*(QPolygonF,QTransform)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 1; // operator*(QPolygonF,QTransform)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArg)))) {
        overloadId = 0; // operator*(QPolygonF,QMatrix)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc___mul___TypeError;

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
                // operator*(QPolygonF,QMatrix)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
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
                // operator*(QPolygonF,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = (*cppSelf) * (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
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

    Sbk_QPolygonFFunc___mul___TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix", "PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.__mul__", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    // 0: operator+(QVector<QPointF>)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QVector<QPointF>)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc___add___TypeError;

    // Call function/method
    {
        ::QVector<QPointF > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator+(QVector<QPointF>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QPointF > cppResult = (*cppSelf) + cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPolygonFFunc___add___TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPolygonFFunc___iadd___TypeError;

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

    Sbk_QPolygonFFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QPolygonF)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPolygonF)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPolygonF) [reverse operator]
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

    Sbk_QPolygonFFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPolygonFFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QPolygonF&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPolygonF&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPolygonFFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPolygonF&) [reverse operator]
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

    Sbk_QPolygonFFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPolygonF.__rshift__", overloads);
        return 0;
}

Py_ssize_t Sbk_QPolygonF__len__(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    return cppSelf->size();
}
PyObject* Sbk_QPolygonF__getitem__(PyObject* self, Py_ssize_t _i)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    QPolygonF::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &*_item);
}
int Sbk_QPolygonF__setitem__(PyObject* self, Py_ssize_t _i, PyObject* pyArg)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "list assignment index out of range");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        PyErr_SetString(PyExc_TypeError, "attributed value with wrong type, 'QPointF' or other convertible type expected");
        return -1;
    }
    if (!Shiboken::Object::isValid(pyArg))
        return -1;
    ::QPointF cppValue = ::QPointF();
    pythonToCpp(pyArg, &cppValue);
    QPolygonF::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    *_item = cppValue;
    return 0;
}
// Rich comparison
static PyObject* Sbk_QPolygonF_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPolygonF& cppSelf = *(((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
                // operator!=(const QVector<QPointF > & v) const
                ::QVector<QPointF > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf != (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
                // operator==(const QVector<QPointF > & v) const
                ::QVector<QPointF > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QPolygonF_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPolygonF_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QPolygonF_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPolygonF_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QPolygonF__repr__(PyObject* self)
{
    ::QPolygonF* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QPolygonF_TypeAsNumber;

static PySequenceMethods Sbk_QPolygonF_TypeAsSequence;

static SbkObjectType Sbk_QPolygonF_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPolygonF",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QPolygonF__repr__,
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
    /*tp_traverse*/         Sbk_QPolygonF_traverse,
    /*tp_clear*/            Sbk_QPolygonF_clear,
    /*tp_richcompare*/      Sbk_QPolygonF_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPolygonF_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPolygonF_Init,
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
static void QPolygonF_PythonToCpp_QPolygonF_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPolygonF_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPolygonF_PythonToCpp_QPolygonF_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPolygonF_Type))
        return QPolygonF_PythonToCpp_QPolygonF_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPolygonF_PTR_CppToPython_QPolygonF(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPolygonF*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPolygonF_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPolygonF_COPY_CppToPython_QPolygonF(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPolygonF_Type, new ::QPolygonF(*((::QPolygonF*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPolygonF_PythonToCpp_QPolygonF_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPolygonF*)cppOut) = *((::QPolygonF*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPolygonF_PythonToCpp_QPolygonF_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPolygonF_Type))
        return QPolygonF_PythonToCpp_QPolygonF_COPY;
    return 0;
}

// Implicit conversions.
static void constQPolygonREF_PythonToCpp_QPolygonF(PyObject* pyIn, void* cppOut) {
    *((::QPolygonF*)cppOut) = ::QPolygonF(*((::QPolygon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPolygonREF_PythonToCpp_QPolygonF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pyIn))
        return constQPolygonREF_PythonToCpp_QPolygonF;
    return 0;
}

static void PySide_QtCore_constQRectFREF_PythonToCpp_QPolygonF(PyObject* pyIn, void* cppOut) {
    *((::QPolygonF*)cppOut) = ::QPolygonF(*((::QRectF*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_PySide_QtCore_constQRectFREF_PythonToCpp_QPolygonF_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyIn))
        return PySide_QtCore_constQRectFREF_PythonToCpp_QPolygonF;
    return 0;
}

static void _constQVector_QPointF_REF_PythonToCpp_QPolygonF(PyObject* pyIn, void* cppOut) {
    ::QVector<QPointF > cppIn = ::QVector<QPointF >();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], pyIn, &cppIn);
    *((::QPolygonF*)cppOut) = ::QPolygonF(cppIn);
}
static PythonToCppFunc is__constQVector_QPointF_REF_PythonToCpp_QPolygonF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pyIn))
        return _constQVector_QPointF_REF_PythonToCpp_QPolygonF;
    return 0;
}

static void PySide_QtCore_int_PythonToCpp_QPolygonF(PyObject* pyIn, void* cppOut) {
    int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &cppIn);
    *((::QPolygonF*)cppOut) = ::QPolygonF(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_int_PythonToCpp_QPolygonF_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_int_PythonToCpp_QPolygonF;
    return 0;
}

void init_QPolygonF(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPolygonF_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPolygonF_TypeAsNumber.nb_rshift = Sbk_QPolygonFFunc___rshift__;
    Sbk_QPolygonF_TypeAsNumber.nb_lshift = Sbk_QPolygonFFunc___lshift__;
    Sbk_QPolygonF_TypeAsNumber.nb_inplace_add = Sbk_QPolygonFFunc___iadd__;
    Sbk_QPolygonF_TypeAsNumber.nb_add = Sbk_QPolygonFFunc___add__;
    Sbk_QPolygonF_TypeAsNumber.nb_multiply = Sbk_QPolygonFFunc___mul__;
    Sbk_QPolygonF_Type.super.ht_type.tp_as_number = &Sbk_QPolygonF_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QPolygonF_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QPolygonF_TypeAsSequence.sq_length = Sbk_QPolygonF__len__;
    Sbk_QPolygonF_TypeAsSequence.sq_item = Sbk_QPolygonF__getitem__;
    Sbk_QPolygonF_TypeAsSequence.sq_ass_item = Sbk_QPolygonF__setitem__;
    Sbk_QPolygonF_Type.super.ht_type.tp_as_sequence = &Sbk_QPolygonF_TypeAsSequence;

    SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPolygonF_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPolygonF", "QPolygonF",
        &Sbk_QPolygonF_Type, &Shiboken::callCppDestructor< ::QPolygonF >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPolygonF_Type,
        QPolygonF_PythonToCpp_QPolygonF_PTR,
        is_QPolygonF_PythonToCpp_QPolygonF_PTR_Convertible,
        QPolygonF_PTR_CppToPython_QPolygonF,
        QPolygonF_COPY_CppToPython_QPolygonF);

    Shiboken::Conversions::registerConverterName(converter, "QPolygonF");
    Shiboken::Conversions::registerConverterName(converter, "QPolygonF*");
    Shiboken::Conversions::registerConverterName(converter, "QPolygonF&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPolygonF).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPolygonF_PythonToCpp_QPolygonF_COPY,
        is_QPolygonF_PythonToCpp_QPolygonF_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPolygonREF_PythonToCpp_QPolygonF,
        is_constQPolygonREF_PythonToCpp_QPolygonF_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQRectFREF_PythonToCpp_QPolygonF,
        is_PySide_QtCore_constQRectFREF_PythonToCpp_QPolygonF_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        _constQVector_QPointF_REF_PythonToCpp_QPolygonF,
        is__constQVector_QPointF_REF_PythonToCpp_QPolygonF_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_int_PythonToCpp_QPolygonF,
        is_PySide_QtCore_int_PythonToCpp_QPolygonF_Convertible);


    qRegisterMetaType< ::QPolygonF >("QPolygonF");
}
