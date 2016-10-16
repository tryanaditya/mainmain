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

#include "qtabletevent_wrapper.h"

// Extra includes
#include <qpoint.h>


// Native ---------------------------------------------------------

QTabletEventWrapper::QTabletEventWrapper(QEvent::Type t, const QPoint & pos, const QPoint & globalPos, const QPointF & hiResGlobalPos, int device, int pointerType, qreal pressure, int xTilt, int yTilt, qreal tangentialPressure, qreal rotation, int z, QFlags<Qt::KeyboardModifier> keyState, qint64 uniqueID) : QTabletEvent(t, pos, globalPos, hiResGlobalPos, device, pointerType, pressure, xTilt, yTilt, tangentialPressure, rotation, z, keyState, uniqueID) {
    // ... middle
}

QTabletEventWrapper::~QTabletEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTabletEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTabletEvent >()))
        return -1;

    ::QTabletEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTabletEvent", 14, 14, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10]), &(pyArgs[11]), &(pyArgs[12]), &(pyArgs[13])))
        return -1;


    // Overloaded function decisor
    // 0: QTabletEvent(QEvent::Type,QPoint,QPoint,QPointF,int,int,qreal,int,int,qreal,qreal,int,QFlags<Qt::KeyboardModifier>,qint64)
    if (numArgs == 14
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[8])))
        && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[9])))
        && (pythonToCpp[10] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[10])))
        && (pythonToCpp[11] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[11])))
        && (pythonToCpp[12] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[12])))
        && (pythonToCpp[13] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[13])))) {
        overloadId = 0; // QTabletEvent(QEvent::Type,QPoint,QPoint,QPointF,int,int,qreal,int,int,qreal,qreal,int,QFlags<Qt::KeyboardModifier>,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTabletEvent_Init_TypeError;

    // Call function/method
    {
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QPoint cppArg1_local = ::QPoint();
        ::QPoint* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return -1;
        ::QPoint cppArg2_local = ::QPoint();
        ::QPoint* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!Shiboken::Object::isValid(pyArgs[3]))
            return -1;
        ::QPointF cppArg3_local = ::QPointF();
        ::QPointF* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);

        int cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        int cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        qreal cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        int cppArg7;
        pythonToCpp[7](pyArgs[7], &cppArg7);
        int cppArg8;
        pythonToCpp[8](pyArgs[8], &cppArg8);
        qreal cppArg9;
        pythonToCpp[9](pyArgs[9], &cppArg9);
        qreal cppArg10;
        pythonToCpp[10](pyArgs[10], &cppArg10);
        int cppArg11;
        pythonToCpp[11](pyArgs[11], &cppArg11);
        ::QFlags<Qt::KeyboardModifier> cppArg12 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[12](pyArgs[12], &cppArg12);
        qint64 cppArg13;
        pythonToCpp[13](pyArgs[13], &cppArg13);

        if (!PyErr_Occurred()) {
            // QTabletEvent(QEvent::Type,QPoint,QPoint,QPointF,int,int,qreal,int,int,qreal,qreal,int,QFlags<Qt::KeyboardModifier>,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QTabletEventWrapper(cppArg0, *cppArg1, *cppArg2, *cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12, cppArg13);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTabletEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTabletEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTabletEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, PySide.QtCore.QPoint, PySide.QtCore.QPoint, PySide.QtCore.QPointF, int, int, float, int, int, float, float, int, PySide.QtCore.Qt.KeyboardModifiers, long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTabletEvent", overloads);
        return -1;
}

static PyObject* Sbk_QTabletEventFunc_device(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTabletEvent::TabletDevice cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->device();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTabletEventFunc_globalPos(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->globalPos();
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

static PyObject* Sbk_QTabletEventFunc_globalX(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->globalX();
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

static PyObject* Sbk_QTabletEventFunc_globalY(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->globalY();
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

static PyObject* Sbk_QTabletEventFunc_hiResGlobalPos(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hiResGlobalPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPointF & cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->hiResGlobalPos();
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

static PyObject* Sbk_QTabletEventFunc_hiResGlobalX(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hiResGlobalX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->hiResGlobalX();
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

static PyObject* Sbk_QTabletEventFunc_hiResGlobalY(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hiResGlobalY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->hiResGlobalY();
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

static PyObject* Sbk_QTabletEventFunc_pointerType(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pointerType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTabletEvent::PointerType cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->pointerType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTabletEventFunc_pos(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QTabletEventFunc_pressure(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pressure()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->pressure();
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

static PyObject* Sbk_QTabletEventFunc_rotation(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rotation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->rotation();
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

static PyObject* Sbk_QTabletEventFunc_tangentialPressure(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tangentialPressure()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->tangentialPressure();
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

static PyObject* Sbk_QTabletEventFunc_uniqueId(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uniqueId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->uniqueId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTabletEventFunc_x(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->x();
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

static PyObject* Sbk_QTabletEventFunc_xTilt(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // xTilt()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->xTilt();
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

static PyObject* Sbk_QTabletEventFunc_y(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->y();
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

static PyObject* Sbk_QTabletEventFunc_yTilt(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // yTilt()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->yTilt();
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

static PyObject* Sbk_QTabletEventFunc_z(PyObject* self)
{
    ::QTabletEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTabletEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // z()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTabletEvent*>(cppSelf)->z();
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

static PyMethodDef Sbk_QTabletEvent_methods[] = {
    {"device", (PyCFunction)Sbk_QTabletEventFunc_device, METH_NOARGS},
    {"globalPos", (PyCFunction)Sbk_QTabletEventFunc_globalPos, METH_NOARGS},
    {"globalX", (PyCFunction)Sbk_QTabletEventFunc_globalX, METH_NOARGS},
    {"globalY", (PyCFunction)Sbk_QTabletEventFunc_globalY, METH_NOARGS},
    {"hiResGlobalPos", (PyCFunction)Sbk_QTabletEventFunc_hiResGlobalPos, METH_NOARGS},
    {"hiResGlobalX", (PyCFunction)Sbk_QTabletEventFunc_hiResGlobalX, METH_NOARGS},
    {"hiResGlobalY", (PyCFunction)Sbk_QTabletEventFunc_hiResGlobalY, METH_NOARGS},
    {"pointerType", (PyCFunction)Sbk_QTabletEventFunc_pointerType, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QTabletEventFunc_pos, METH_NOARGS},
    {"pressure", (PyCFunction)Sbk_QTabletEventFunc_pressure, METH_NOARGS},
    {"rotation", (PyCFunction)Sbk_QTabletEventFunc_rotation, METH_NOARGS},
    {"tangentialPressure", (PyCFunction)Sbk_QTabletEventFunc_tangentialPressure, METH_NOARGS},
    {"uniqueId", (PyCFunction)Sbk_QTabletEventFunc_uniqueId, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QTabletEventFunc_x, METH_NOARGS},
    {"xTilt", (PyCFunction)Sbk_QTabletEventFunc_xTilt, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QTabletEventFunc_y, METH_NOARGS},
    {"yTilt", (PyCFunction)Sbk_QTabletEventFunc_yTilt, METH_NOARGS},
    {"z", (PyCFunction)Sbk_QTabletEventFunc_z, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTabletEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTabletEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTabletEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTabletEvent",
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
    /*tp_traverse*/         Sbk_QTabletEvent_traverse,
    /*tp_clear*/            Sbk_QTabletEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTabletEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTabletEvent_Init,
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

static void* Sbk_QTabletEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QTabletEvent*>(cptr)->type() == QEvent::TabletMove ||  reinterpret_cast< ::QTabletEvent*>(cptr)->type() == QEvent::TabletPress ||  reinterpret_cast< ::QTabletEvent*>(cptr)->type() == QEvent::TabletRelease)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QTabletEvent_TabletDevice_PythonToCpp_QTabletEvent_TabletDevice(PyObject* pyIn, void* cppOut) {
    *((::QTabletEvent::TabletDevice*)cppOut) = (::QTabletEvent::TabletDevice) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTabletEvent_TabletDevice_PythonToCpp_QTabletEvent_TabletDevice_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX]))
        return QTabletEvent_TabletDevice_PythonToCpp_QTabletEvent_TabletDevice;
    return 0;
}
static PyObject* QTabletEvent_TabletDevice_CppToPython_QTabletEvent_TabletDevice(const void* cppIn) {
    int castCppIn = *((::QTabletEvent::TabletDevice*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX], castCppIn);

}

static void QTabletEvent_PointerType_PythonToCpp_QTabletEvent_PointerType(PyObject* pyIn, void* cppOut) {
    *((::QTabletEvent::PointerType*)cppOut) = (::QTabletEvent::PointerType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTabletEvent_PointerType_PythonToCpp_QTabletEvent_PointerType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX]))
        return QTabletEvent_PointerType_PythonToCpp_QTabletEvent_PointerType;
    return 0;
}
static PyObject* QTabletEvent_PointerType_CppToPython_QTabletEvent_PointerType(const void* cppIn) {
    int castCppIn = *((::QTabletEvent::PointerType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTabletEvent_PythonToCpp_QTabletEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTabletEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTabletEvent_PythonToCpp_QTabletEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTabletEvent_Type))
        return QTabletEvent_PythonToCpp_QTabletEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTabletEvent_PTR_CppToPython_QTabletEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTabletEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTabletEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTabletEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTabletEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTabletEvent", "QTabletEvent*",
        &Sbk_QTabletEvent_Type, &Shiboken::callCppDestructor< ::QTabletEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTabletEvent_Type,
        QTabletEvent_PythonToCpp_QTabletEvent_PTR,
        is_QTabletEvent_PythonToCpp_QTabletEvent_PTR_Convertible,
        QTabletEvent_PTR_CppToPython_QTabletEvent);

    Shiboken::Conversions::registerConverterName(converter, "QTabletEvent");
    Shiboken::Conversions::registerConverterName(converter, "QTabletEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QTabletEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTabletEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTabletEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QTabletEvent_Type, &Sbk_QTabletEvent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'TabletDevice'.
    SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTabletEvent_Type,
        "TabletDevice",
        "PySide.QtGui.QTabletEvent.TabletDevice",
        "QTabletEvent::TabletDevice");
    if (!SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "NoDevice", (long) QTabletEvent::NoDevice))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "Puck", (long) QTabletEvent::Puck))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "Stylus", (long) QTabletEvent::Stylus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "Airbrush", (long) QTabletEvent::Airbrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "FourDMouse", (long) QTabletEvent::FourDMouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "XFreeEraser", (long) QTabletEvent::XFreeEraser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
        &Sbk_QTabletEvent_Type, "RotationStylus", (long) QTabletEvent::RotationStylus))
        return ;
    // Register converter for enum 'QTabletEvent::TabletDevice'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX],
            QTabletEvent_TabletDevice_CppToPython_QTabletEvent_TabletDevice);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTabletEvent_TabletDevice_PythonToCpp_QTabletEvent_TabletDevice,
            is_QTabletEvent_TabletDevice_PythonToCpp_QTabletEvent_TabletDevice_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTabletEvent::TabletDevice");
        Shiboken::Conversions::registerConverterName(converter, "TabletDevice");
    }
    // End of 'TabletDevice' enum.

    // Initialization of enum 'PointerType'.
    SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTabletEvent_Type,
        "PointerType",
        "PySide.QtGui.QTabletEvent.PointerType",
        "QTabletEvent::PointerType");
    if (!SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX],
        &Sbk_QTabletEvent_Type, "UnknownPointer", (long) QTabletEvent::UnknownPointer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX],
        &Sbk_QTabletEvent_Type, "Pen", (long) QTabletEvent::Pen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX],
        &Sbk_QTabletEvent_Type, "Cursor", (long) QTabletEvent::Cursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX],
        &Sbk_QTabletEvent_Type, "Eraser", (long) QTabletEvent::Eraser))
        return ;
    // Register converter for enum 'QTabletEvent::PointerType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX],
            QTabletEvent_PointerType_CppToPython_QTabletEvent_PointerType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTabletEvent_PointerType_PythonToCpp_QTabletEvent_PointerType,
            is_QTabletEvent_PointerType_PythonToCpp_QTabletEvent_PointerType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTabletEvent::PointerType");
        Shiboken::Conversions::registerConverterName(converter, "PointerType");
    }
    // End of 'PointerType' enum.


    qRegisterMetaType< ::QTabletEvent::TabletDevice >("QTabletEvent::TabletDevice");
    qRegisterMetaType< ::QTabletEvent::PointerType >("QTabletEvent::PointerType");
}
