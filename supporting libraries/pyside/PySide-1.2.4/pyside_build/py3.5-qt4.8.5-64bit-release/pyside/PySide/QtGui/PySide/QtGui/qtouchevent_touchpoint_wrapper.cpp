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

#include "qtouchevent_touchpoint_wrapper.h"

// Extra includes
#include <qevent.h>
#include <qpoint.h>
#include <qrect.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTouchEvent_TouchPoint_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTouchEvent::TouchPoint >()))
        return -1;

    ::QTouchEvent::TouchPoint* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.TouchPoint(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:TouchPoint", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: TouchPoint(QTouchEvent::TouchPoint)
    // 1: TouchPoint(int)
    if (numArgs == 0) {
        overloadId = 1; // TouchPoint(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // TouchPoint(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // TouchPoint(QTouchEvent::TouchPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPoint_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // TouchPoint(const QTouchEvent::TouchPoint & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTouchEvent::TouchPoint cppArg0_local = ::QTouchEvent::TouchPoint(((int)0));
            ::QTouchEvent::TouchPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // TouchPoint(QTouchEvent::TouchPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTouchEvent::TouchPoint(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // TouchPoint(int id)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "id");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.TouchPoint(): got multiple values for keyword argument 'id'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QTouchEvent_TouchPoint_Init_TypeError;
                }
            }
            int cppArg0 = -1;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // TouchPoint(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTouchEvent::TouchPoint(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTouchEvent::TouchPoint >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTouchEvent_TouchPoint_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTouchEvent_TouchPoint_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTouchEvent::TouchPoint", "int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.TouchPoint", overloads);
        return -1;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_id(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // id()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->id();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_isPrimary(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isPrimary()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->isPrimary();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_lastNormalizedPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastNormalizedPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->lastNormalizedPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_lastPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->lastPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_lastScenePos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastScenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->lastScenePos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_lastScreenPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastScreenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->lastScreenPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_normalizedPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalizedPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->normalizedPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_pos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->pos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_pressure(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pressure()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->pressure();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_rect(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->rect();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_scenePos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->scenePos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_sceneRect(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sceneRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->sceneRect();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_screenPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->screenPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_screenRect(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screenRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->screenRect();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setId(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setId(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setId(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setId_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setId(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setId(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setId_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setId", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setLastNormalizedPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastNormalizedPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastNormalizedPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setLastNormalizedPos_TypeError;

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
            // setLastNormalizedPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastNormalizedPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setLastNormalizedPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setLastNormalizedPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setLastPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setLastPos_TypeError;

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
            // setLastPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setLastPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setLastPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setLastScenePos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setLastScenePos_TypeError;

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
            // setLastScenePos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastScenePos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setLastScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setLastScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setLastScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastScreenPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastScreenPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setLastScreenPos_TypeError;

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
            // setLastScreenPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastScreenPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setLastScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setLastScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setNormalizedPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNormalizedPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setNormalizedPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setNormalizedPos_TypeError;

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
            // setNormalizedPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNormalizedPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setNormalizedPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setNormalizedPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setPos_TypeError;

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
            // setPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setPressure(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPressure(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPressure(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setPressure_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPressure(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPressure(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setPressure_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setPressure", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setRect(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRect(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setRect_TypeError;

    // Call function/method
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
            // setRect(QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setRect", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setScenePos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setScenePos_TypeError;

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
            // setScenePos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScenePos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setSceneRect(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSceneRect(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setSceneRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setSceneRect_TypeError;

    // Call function/method
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
            // setSceneRect(QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSceneRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setSceneRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setSceneRect", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScreenPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setScreenPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setScreenPos_TypeError;

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
            // setScreenPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScreenPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setScreenRect(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScreenRect(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setScreenRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setScreenRect_TypeError;

    // Call function/method
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
            // setScreenRect(QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScreenRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setScreenRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setScreenRect", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setStartNormalizedPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartNormalizedPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setStartNormalizedPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setStartNormalizedPos_TypeError;

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
            // setStartNormalizedPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartNormalizedPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setStartNormalizedPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setStartNormalizedPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setStartPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setStartPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setStartPos_TypeError;

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
            // setStartPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setStartPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setStartPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setStartScenePos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setStartScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setStartScenePos_TypeError;

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
            // setStartScenePos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartScenePos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setStartScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setStartScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_setStartScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartScreenPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setStartScreenPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEvent_TouchPointFunc_setStartScreenPos_TypeError;

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
            // setStartScreenPos(QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartScreenPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEvent_TouchPointFunc_setStartScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.TouchPoint.setStartScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEvent_TouchPointFunc_startNormalizedPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startNormalizedPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->startNormalizedPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_startPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->startPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_startScenePos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startScenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->startScenePos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_startScreenPos(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startScreenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->startScreenPos();
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

static PyObject* Sbk_QTouchEvent_TouchPointFunc_state(PyObject* self)
{
    ::QTouchEvent::TouchPoint* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::TouchPointState cppResult = const_cast<const ::QTouchEvent::TouchPoint*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOUCHPOINTSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTouchEvent_TouchPoint___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTouchEvent::TouchPoint& cppSelf = *(((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTouchEvent_TouchPoint_methods[] = {
    {"id", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_id, METH_NOARGS},
    {"isPrimary", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_isPrimary, METH_NOARGS},
    {"lastNormalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_lastNormalizedPos, METH_NOARGS},
    {"lastPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_lastPos, METH_NOARGS},
    {"lastScenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_lastScenePos, METH_NOARGS},
    {"lastScreenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_lastScreenPos, METH_NOARGS},
    {"normalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_normalizedPos, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_pos, METH_NOARGS},
    {"pressure", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_pressure, METH_NOARGS},
    {"rect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_rect, METH_NOARGS},
    {"scenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_scenePos, METH_NOARGS},
    {"sceneRect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_sceneRect, METH_NOARGS},
    {"screenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_screenPos, METH_NOARGS},
    {"screenRect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_screenRect, METH_NOARGS},
    {"setId", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setId, METH_O},
    {"setLastNormalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setLastNormalizedPos, METH_O},
    {"setLastPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setLastPos, METH_O},
    {"setLastScenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setLastScenePos, METH_O},
    {"setLastScreenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setLastScreenPos, METH_O},
    {"setNormalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setNormalizedPos, METH_O},
    {"setPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setPos, METH_O},
    {"setPressure", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setPressure, METH_O},
    {"setRect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setRect, METH_O},
    {"setScenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setScenePos, METH_O},
    {"setSceneRect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setSceneRect, METH_O},
    {"setScreenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setScreenPos, METH_O},
    {"setScreenRect", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setScreenRect, METH_O},
    {"setStartNormalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setStartNormalizedPos, METH_O},
    {"setStartPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setStartPos, METH_O},
    {"setStartScenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setStartScenePos, METH_O},
    {"setStartScreenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_setStartScreenPos, METH_O},
    {"startNormalizedPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_startNormalizedPos, METH_NOARGS},
    {"startPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_startPos, METH_NOARGS},
    {"startScenePos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_startScenePos, METH_NOARGS},
    {"startScreenPos", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_startScreenPos, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QTouchEvent_TouchPointFunc_state, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTouchEvent_TouchPoint___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTouchEvent_TouchPoint_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTouchEvent_TouchPoint_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTouchEvent_TouchPoint_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTouchEvent.TouchPoint",
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
    /*tp_traverse*/         Sbk_QTouchEvent_TouchPoint_traverse,
    /*tp_clear*/            Sbk_QTouchEvent_TouchPoint_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTouchEvent_TouchPoint_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTouchEvent_TouchPoint_Init,
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
static void TouchPoint_PythonToCpp_TouchPoint_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTouchEvent_TouchPoint_Type, pyIn, cppOut);
}
static PythonToCppFunc is_TouchPoint_PythonToCpp_TouchPoint_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTouchEvent_TouchPoint_Type))
        return TouchPoint_PythonToCpp_TouchPoint_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* TouchPoint_PTR_CppToPython_TouchPoint(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTouchEvent::TouchPoint*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTouchEvent_TouchPoint_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* TouchPoint_COPY_CppToPython_TouchPoint(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTouchEvent_TouchPoint_Type, new ::QTouchEvent::TouchPoint(*((::QTouchEvent::TouchPoint*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void TouchPoint_PythonToCpp_TouchPoint_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTouchEvent::TouchPoint*)cppOut) = *((::QTouchEvent::TouchPoint*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_TouchPoint_PythonToCpp_TouchPoint_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTouchEvent_TouchPoint_Type))
        return TouchPoint_PythonToCpp_TouchPoint_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_int_PythonToCpp_QTouchEvent_TouchPoint(PyObject* pyIn, void* cppOut) {
    int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &cppIn);
    *((::QTouchEvent::TouchPoint*)cppOut) = ::QTouchEvent::TouchPoint(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_int_PythonToCpp_QTouchEvent_TouchPoint_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_int_PythonToCpp_QTouchEvent_TouchPoint;
    return 0;
}

void init_QTouchEvent_TouchPoint(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTouchEvent_TouchPoint_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "TouchPoint", "QTouchEvent::TouchPoint",
        &Sbk_QTouchEvent_TouchPoint_Type, &Shiboken::callCppDestructor< ::QTouchEvent::TouchPoint >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTouchEvent_TouchPoint_Type,
        TouchPoint_PythonToCpp_TouchPoint_PTR,
        is_TouchPoint_PythonToCpp_TouchPoint_PTR_Convertible,
        TouchPoint_PTR_CppToPython_TouchPoint,
        TouchPoint_COPY_CppToPython_TouchPoint);

    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent::TouchPoint");
    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent::TouchPoint*");
    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent::TouchPoint&");
    Shiboken::Conversions::registerConverterName(converter, "TouchPoint");
    Shiboken::Conversions::registerConverterName(converter, "TouchPoint*");
    Shiboken::Conversions::registerConverterName(converter, "TouchPoint&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTouchEvent::TouchPoint).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        TouchPoint_PythonToCpp_TouchPoint_COPY,
        is_TouchPoint_PythonToCpp_TouchPoint_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_int_PythonToCpp_QTouchEvent_TouchPoint,
        is_PySide_QtCore_int_PythonToCpp_QTouchEvent_TouchPoint_Convertible);


}
