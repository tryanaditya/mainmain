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

#include "qgestureevent_wrapper.h"

// Extra includes
#include <QList>
#include <qgesture.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGestureEventWrapper::QGestureEventWrapper(const QList<QGesture * > & gestures) : QGestureEvent(gestures) {
    // ... middle
}

QGestureEventWrapper::~QGestureEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGestureEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGestureEvent >()))
        return -1;

    ::QGestureEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGestureEvent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGestureEvent(QList<QGesture*>)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGestureEvent(QList<QGesture*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEvent_Init_TypeError;

    // Call function/method
    {
        ::QList<QGesture * > cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGestureEvent(QList<QGesture*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGestureEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGestureEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGestureEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGestureEvent_Init_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureEvent", overloads);
        return -1;
}

static PyObject* Sbk_QGestureEventFunc_accept(PyObject* self, PyObject* args)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "accept", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: accept()
    // 1: accept(QGesture*)
    // 2: accept(Qt::GestureType)
    if (numArgs == 0) {
        overloadId = 0; // accept()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 2; // accept(Qt::GestureType)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArgs[0])))) {
        overloadId = 1; // accept(QGesture*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_accept_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // accept()
        {

            if (!PyErr_Occurred()) {
                // accept()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->accept();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // accept(QGesture * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGesture* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // accept(QGesture*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->accept(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // accept(Qt::GestureType arg__1)
        {
            ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // accept(Qt::GestureType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->accept(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureEventFunc_accept_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QGesture", "PySide.QtCore.Qt.GestureType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureEvent.accept", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_activeGestures(PyObject* self)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activeGestures()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGesture * > cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->activeGestures();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], &cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGestureEventFunc_canceledGestures(PyObject* self)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canceledGestures()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGesture * > cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->canceledGestures();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], &cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGestureEventFunc_gesture(PyObject* self, PyObject* pyArg)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: gesture(Qt::GestureType)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArg)))) {
        overloadId = 0; // gesture(Qt::GestureType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_gesture_TypeError;

    // Call function/method
    {
        ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // gesture(Qt::GestureType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGesture * cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->gesture(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGestureEventFunc_gesture_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.GestureType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureEvent.gesture", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_gestures(PyObject* self)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // gestures()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGesture * > cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->gestures();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGESTUREPTR_IDX], &cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGestureEventFunc_ignore(PyObject* self, PyObject* args)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ignore", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: ignore()
    // 1: ignore(QGesture*)
    // 2: ignore(Qt::GestureType)
    if (numArgs == 0) {
        overloadId = 0; // ignore()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 2; // ignore(Qt::GestureType)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArgs[0])))) {
        overloadId = 1; // ignore(QGesture*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_ignore_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ignore()
        {

            if (!PyErr_Occurred()) {
                // ignore()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignore();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ignore(QGesture * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGesture* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // ignore(QGesture*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignore(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // ignore(Qt::GestureType arg__1)
        {
            ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // ignore(Qt::GestureType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignore(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureEventFunc_ignore_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QGesture", "PySide.QtCore.Qt.GestureType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureEvent.ignore", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_isAccepted(PyObject* self, PyObject* args)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isAccepted", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isAccepted()const
    // 1: isAccepted(QGesture*)const
    // 2: isAccepted(Qt::GestureType)const
    if (numArgs == 0) {
        overloadId = 0; // isAccepted()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 2; // isAccepted(Qt::GestureType)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArgs[0])))) {
        overloadId = 1; // isAccepted(QGesture*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_isAccepted_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isAccepted() const
        {

            if (!PyErr_Occurred()) {
                // isAccepted()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->isAccepted();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isAccepted(QGesture * arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGesture* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // isAccepted(QGesture*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->isAccepted(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // isAccepted(Qt::GestureType arg__1) const
        {
            ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // isAccepted(Qt::GestureType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->isAccepted(cppArg0);
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

    Sbk_QGestureEventFunc_isAccepted_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QGesture", "PySide.QtCore.Qt.GestureType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureEvent.isAccepted", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_mapToGraphicsScene(PyObject* self, PyObject* pyArg)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mapToGraphicsScene(QPointF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // mapToGraphicsScene(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_mapToGraphicsScene_TypeError;

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
            // mapToGraphicsScene(QPointF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->mapToGraphicsScene(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGestureEventFunc_mapToGraphicsScene_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureEvent.mapToGraphicsScene", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_setAccepted(PyObject* self, PyObject* args)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAccepted", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAccepted(QGesture*,bool)
    // 1: setAccepted(Qt::GestureType,bool)
    // 2: setAccepted(bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 1; // setAccepted(Qt::GestureType,bool)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 2; // setAccepted(bool)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // setAccepted(QGesture*,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_setAccepted_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAccepted(QGesture * arg__1, bool arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGesture* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAccepted(QGesture*,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAccepted(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setAccepted(Qt::GestureType arg__1, bool arg__2)
        {
            ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAccepted(Qt::GestureType,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAccepted(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setAccepted(bool accepted)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setAccepted(bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAccepted(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureEventFunc_setAccepted_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGesture, bool", "PySide.QtCore.Qt.GestureType, bool", "bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureEvent.setAccepted", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_setWidget(PyObject* self, PyObject* pyArg)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureEventFunc_setWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidget(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureEventFunc_setWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureEvent.setWidget", overloads);
        return 0;
}

static PyObject* Sbk_QGestureEventFunc_widget(PyObject* self)
{
    ::QGestureEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QGestureEvent*>(cppSelf)->widget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGestureEvent_methods[] = {
    {"accept", (PyCFunction)Sbk_QGestureEventFunc_accept, METH_VARARGS},
    {"activeGestures", (PyCFunction)Sbk_QGestureEventFunc_activeGestures, METH_NOARGS},
    {"canceledGestures", (PyCFunction)Sbk_QGestureEventFunc_canceledGestures, METH_NOARGS},
    {"gesture", (PyCFunction)Sbk_QGestureEventFunc_gesture, METH_O},
    {"gestures", (PyCFunction)Sbk_QGestureEventFunc_gestures, METH_NOARGS},
    {"ignore", (PyCFunction)Sbk_QGestureEventFunc_ignore, METH_VARARGS},
    {"isAccepted", (PyCFunction)Sbk_QGestureEventFunc_isAccepted, METH_VARARGS},
    {"mapToGraphicsScene", (PyCFunction)Sbk_QGestureEventFunc_mapToGraphicsScene, METH_O},
    {"setAccepted", (PyCFunction)Sbk_QGestureEventFunc_setAccepted, METH_VARARGS},
    {"setWidget", (PyCFunction)Sbk_QGestureEventFunc_setWidget, METH_O},
    {"widget", (PyCFunction)Sbk_QGestureEventFunc_widget, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGestureEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGestureEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGestureEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGestureEvent",
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
    /*tp_traverse*/         Sbk_QGestureEvent_traverse,
    /*tp_clear*/            Sbk_QGestureEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGestureEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGestureEvent_Init,
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

static void* Sbk_QGestureEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QGestureEvent*>(cptr)->type() == QEvent::Gesture ||  reinterpret_cast< ::QGestureEvent*>(cptr)->type() == QEvent::GestureOverride)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGestureEvent_PythonToCpp_QGestureEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGestureEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGestureEvent_PythonToCpp_QGestureEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGestureEvent_Type))
        return QGestureEvent_PythonToCpp_QGestureEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGestureEvent_PTR_CppToPython_QGestureEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGestureEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGestureEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGestureEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGESTUREEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGestureEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGestureEvent", "QGestureEvent*",
        &Sbk_QGestureEvent_Type, &Shiboken::callCppDestructor< ::QGestureEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGestureEvent_Type,
        QGestureEvent_PythonToCpp_QGestureEvent_PTR,
        is_QGestureEvent_PythonToCpp_QGestureEvent_PTR_Convertible,
        QGestureEvent_PTR_CppToPython_QGestureEvent);

    Shiboken::Conversions::registerConverterName(converter, "QGestureEvent");
    Shiboken::Conversions::registerConverterName(converter, "QGestureEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QGestureEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGestureEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGestureEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGestureEvent_Type, &Sbk_QGestureEvent_typeDiscovery);


}
