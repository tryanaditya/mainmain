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

#include "qpainterpathstroker_wrapper.h"

// Extra includes
#include <QVector>
#include <qpainterpath.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPainterPathStroker_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPainterPathStroker >()))
        return -1;

    ::QPainterPathStroker* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QPainterPathStroker()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPainterPathStroker();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPainterPathStroker >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QPainterPathStrokerFunc_capStyle(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::PenCapStyle cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->capStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathStrokerFunc_createStroke(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createStroke(QPainterPath)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // createStroke(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_createStroke_TypeError;

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
            // createStroke(QPainterPath)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->createStroke(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterPathStrokerFunc_createStroke_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.createStroke", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_curveThreshold(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // curveThreshold()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->curveThreshold();
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

static PyObject* Sbk_QPainterPathStrokerFunc_dashOffset(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dashOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->dashOffset();
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

static PyObject* Sbk_QPainterPathStrokerFunc_dashPattern(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dashPattern()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<qreal > cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->dashPattern();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathStrokerFunc_joinStyle(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // joinStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::PenJoinStyle cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->joinStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterPathStrokerFunc_miterLimit(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // miterLimit()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->miterLimit();
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

static PyObject* Sbk_QPainterPathStrokerFunc_setCapStyle(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCapStyle(Qt::PenCapStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setCapStyle(Qt::PenCapStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setCapStyle_TypeError;

    // Call function/method
    {
        ::Qt::PenCapStyle cppArg0 = ((::Qt::PenCapStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCapStyle(Qt::PenCapStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCapStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setCapStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenCapStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setCapStyle", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setCurveThreshold(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurveThreshold(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setCurveThreshold(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setCurveThreshold_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurveThreshold(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurveThreshold(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setCurveThreshold_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setCurveThreshold", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setDashOffset(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDashOffset(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setDashOffset(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setDashOffset_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDashOffset(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDashOffset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setDashOffset_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setDashOffset", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setDashPattern(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDashPattern(Qt::PenStyle)
    // 1: setDashPattern(QVector<qreal>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setDashPattern(Qt::PenStyle)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX], (pyArg)))) {
        overloadId = 1; // setDashPattern(QVector<qreal>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setDashPattern_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setDashPattern(Qt::PenStyle arg__1)
        {
            ::Qt::PenStyle cppArg0 = ((::Qt::PenStyle)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDashPattern(Qt::PenStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDashPattern(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setDashPattern(const QVector<qreal > & dashPattern)
        {
            ::QVector<qreal > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDashPattern(QVector<qreal>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDashPattern(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setDashPattern_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenStyle", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setDashPattern", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setJoinStyle(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setJoinStyle(Qt::PenJoinStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setJoinStyle(Qt::PenJoinStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setJoinStyle_TypeError;

    // Call function/method
    {
        ::Qt::PenJoinStyle cppArg0 = ((::Qt::PenJoinStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setJoinStyle(Qt::PenJoinStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setJoinStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setJoinStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenJoinStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setJoinStyle", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setMiterLimit(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMiterLimit(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMiterLimit(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setMiterLimit_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMiterLimit(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMiterLimit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setMiterLimit_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setMiterLimit", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_setWidth(PyObject* self, PyObject* pyArg)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPathStrokerFunc_setWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterPathStrokerFunc_setWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainterPathStroker.setWidth", overloads);
        return 0;
}

static PyObject* Sbk_QPainterPathStrokerFunc_width(PyObject* self)
{
    ::QPainterPathStroker* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPathStroker*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainterPathStroker*>(cppSelf)->width();
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

static PyMethodDef Sbk_QPainterPathStroker_methods[] = {
    {"capStyle", (PyCFunction)Sbk_QPainterPathStrokerFunc_capStyle, METH_NOARGS},
    {"createStroke", (PyCFunction)Sbk_QPainterPathStrokerFunc_createStroke, METH_O},
    {"curveThreshold", (PyCFunction)Sbk_QPainterPathStrokerFunc_curveThreshold, METH_NOARGS},
    {"dashOffset", (PyCFunction)Sbk_QPainterPathStrokerFunc_dashOffset, METH_NOARGS},
    {"dashPattern", (PyCFunction)Sbk_QPainterPathStrokerFunc_dashPattern, METH_NOARGS},
    {"joinStyle", (PyCFunction)Sbk_QPainterPathStrokerFunc_joinStyle, METH_NOARGS},
    {"miterLimit", (PyCFunction)Sbk_QPainterPathStrokerFunc_miterLimit, METH_NOARGS},
    {"setCapStyle", (PyCFunction)Sbk_QPainterPathStrokerFunc_setCapStyle, METH_O},
    {"setCurveThreshold", (PyCFunction)Sbk_QPainterPathStrokerFunc_setCurveThreshold, METH_O},
    {"setDashOffset", (PyCFunction)Sbk_QPainterPathStrokerFunc_setDashOffset, METH_O},
    {"setDashPattern", (PyCFunction)Sbk_QPainterPathStrokerFunc_setDashPattern, METH_O},
    {"setJoinStyle", (PyCFunction)Sbk_QPainterPathStrokerFunc_setJoinStyle, METH_O},
    {"setMiterLimit", (PyCFunction)Sbk_QPainterPathStrokerFunc_setMiterLimit, METH_O},
    {"setWidth", (PyCFunction)Sbk_QPainterPathStrokerFunc_setWidth, METH_O},
    {"width", (PyCFunction)Sbk_QPainterPathStrokerFunc_width, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QPainterPathStroker_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPainterPathStroker_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPainterPathStroker_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPainterPathStroker",
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
    /*tp_traverse*/         Sbk_QPainterPathStroker_traverse,
    /*tp_clear*/            Sbk_QPainterPathStroker_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPainterPathStroker_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPainterPathStroker_Init,
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
static void QPainterPathStroker_PythonToCpp_QPainterPathStroker_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPainterPathStroker_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPainterPathStroker_PythonToCpp_QPainterPathStroker_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainterPathStroker_Type))
        return QPainterPathStroker_PythonToCpp_QPainterPathStroker_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPainterPathStroker_PTR_CppToPython_QPainterPathStroker(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPainterPathStroker*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPainterPathStroker_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPainterPathStroker(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPainterPathStroker_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPainterPathStroker", "QPainterPathStroker*",
        &Sbk_QPainterPathStroker_Type, &Shiboken::callCppDestructor< ::QPainterPathStroker >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPainterPathStroker_Type,
        QPainterPathStroker_PythonToCpp_QPainterPathStroker_PTR,
        is_QPainterPathStroker_PythonToCpp_QPainterPathStroker_PTR_Convertible,
        QPainterPathStroker_PTR_CppToPython_QPainterPathStroker);

    Shiboken::Conversions::registerConverterName(converter, "QPainterPathStroker");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPathStroker*");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPathStroker&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPainterPathStroker).name());



}
