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

#include "qmouseevent_wrapper.h"

// Extra includes
#include <qevent.h>
#include <qpoint.h>


// Native ---------------------------------------------------------

QMouseEventWrapper::QMouseEventWrapper(QEvent::Type type, const QPoint & pos, Qt::MouseButton button, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers) : QMouseEvent(type, pos, button, buttons, modifiers) {
    // ... middle
}

QMouseEventWrapper::QMouseEventWrapper(QEvent::Type type, const QPoint & pos, const QPoint & globalPos, Qt::MouseButton button, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers) : QMouseEvent(type, pos, globalPos, button, buttons, modifiers) {
    // ... middle
}

QMouseEventWrapper::~QMouseEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMouseEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMouseEvent >()))
        return -1;

    ::QMouseEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMouseEvent", 5, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QMouseEvent(QEvent::Type,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    // 1: QMouseEvent(QEvent::Type,QPoint,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
        if (numArgs == 6
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[4])))
            && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[5])))) {
            overloadId = 1; // QMouseEvent(QEvent::Type,QPoint,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
        } else if (numArgs == 5
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
            overloadId = 0; // QMouseEvent(QEvent::Type,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMouseEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMouseEvent(QEvent::Type type, const QPoint & pos, Qt::MouseButton button, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers)
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

            ::Qt::MouseButton cppArg2 = ((::Qt::MouseButton)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::MouseButton> cppArg3 = ((::QFlags<Qt::MouseButton>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QFlags<Qt::KeyboardModifier> cppArg4 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QMouseEvent(QEvent::Type,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMouseEventWrapper(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QMouseEvent(QEvent::Type type, const QPoint & pos, const QPoint & globalPos, Qt::MouseButton button, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers)
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

            ::Qt::MouseButton cppArg3 = ((::Qt::MouseButton)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QFlags<Qt::MouseButton> cppArg4 = ((::QFlags<Qt::MouseButton>)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::KeyboardModifier> cppArg5 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // QMouseEvent(QEvent::Type,QPoint,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMouseEventWrapper(cppArg0, *cppArg1, *cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMouseEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMouseEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMouseEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, PySide.QtCore.QPoint, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers", "PySide.QtCore.QEvent.Type, PySide.QtCore.QPoint, PySide.QtCore.QPoint, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMouseEvent", overloads);
        return -1;
}

static PyObject* Sbk_QMouseEventFunc_button(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // button()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::MouseButton cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->button();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMouseEventFunc_buttons(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->buttons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMouseEventFunc_createExtendedMouseEvent(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createExtendedMouseEvent", 6, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: createExtendedMouseEvent(QEvent::Type,QPointF,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[5])))) {
        overloadId = 0; // createExtendedMouseEvent(QEvent::Type,QPointF,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMouseEventFunc_createExtendedMouseEvent_TypeError;

    // Call function/method
    {
        ::QEvent::Type cppArg0 = ((::QEvent::Type)0);
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
        ::QPoint cppArg2_local = ::QPoint();
        ::QPoint* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        ::Qt::MouseButton cppArg3 = ((::Qt::MouseButton)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QFlags<Qt::MouseButton> cppArg4 = ((::QFlags<Qt::MouseButton>)0);
        pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QFlags<Qt::KeyboardModifier> cppArg5 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // createExtendedMouseEvent(QEvent::Type,QPointF,QPoint,Qt::MouseButton,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMouseEvent * cppResult = ::QMouseEvent::createExtendedMouseEvent(cppArg0, *cppArg1, *cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMouseEventFunc_createExtendedMouseEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type, PySide.QtCore.QPointF, PySide.QtCore.QPoint, PySide.QtCore.Qt.MouseButton, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMouseEvent.createExtendedMouseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMouseEventFunc_globalPos(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->globalPos();
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

static PyObject* Sbk_QMouseEventFunc_globalX(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->globalX();
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

static PyObject* Sbk_QMouseEventFunc_globalY(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->globalY();
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

static PyObject* Sbk_QMouseEventFunc_hasExtendedInfo(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasExtendedInfo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->hasExtendedInfo();
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

static PyObject* Sbk_QMouseEventFunc_pos(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QMouseEventFunc_posF(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // posF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->posF();
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

static PyObject* Sbk_QMouseEventFunc_x(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->x();
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

static PyObject* Sbk_QMouseEventFunc_y(PyObject* self)
{
    ::QMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMouseEvent*>(cppSelf)->y();
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

static PyMethodDef Sbk_QMouseEvent_methods[] = {
    {"button", (PyCFunction)Sbk_QMouseEventFunc_button, METH_NOARGS},
    {"buttons", (PyCFunction)Sbk_QMouseEventFunc_buttons, METH_NOARGS},
    {"createExtendedMouseEvent", (PyCFunction)Sbk_QMouseEventFunc_createExtendedMouseEvent, METH_VARARGS|METH_STATIC},
    {"globalPos", (PyCFunction)Sbk_QMouseEventFunc_globalPos, METH_NOARGS},
    {"globalX", (PyCFunction)Sbk_QMouseEventFunc_globalX, METH_NOARGS},
    {"globalY", (PyCFunction)Sbk_QMouseEventFunc_globalY, METH_NOARGS},
    {"hasExtendedInfo", (PyCFunction)Sbk_QMouseEventFunc_hasExtendedInfo, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QMouseEventFunc_pos, METH_NOARGS},
    {"posF", (PyCFunction)Sbk_QMouseEventFunc_posF, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QMouseEventFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QMouseEventFunc_y, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMouseEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMouseEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMouseEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMouseEvent",
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
    /*tp_traverse*/         Sbk_QMouseEvent_traverse,
    /*tp_clear*/            Sbk_QMouseEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMouseEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMouseEvent_Init,
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

static void* Sbk_QMouseEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QMouseEvent*>(cptr)->type() == QEvent::MouseButtonDblClick ||  reinterpret_cast< ::QMouseEvent*>(cptr)->type() == QEvent::MouseButtonPress ||  reinterpret_cast< ::QMouseEvent*>(cptr)->type() == QEvent::MouseButtonRelease ||  reinterpret_cast< ::QMouseEvent*>(cptr)->type() == QEvent::MouseMove)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMouseEvent_PythonToCpp_QMouseEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMouseEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMouseEvent_PythonToCpp_QMouseEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMouseEvent_Type))
        return QMouseEvent_PythonToCpp_QMouseEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMouseEvent_PTR_CppToPython_QMouseEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMouseEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMouseEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QMouseEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMouseEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMouseEvent", "QMouseEvent*",
        &Sbk_QMouseEvent_Type, &Shiboken::callCppDestructor< ::QMouseEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMouseEvent_Type,
        QMouseEvent_PythonToCpp_QMouseEvent_PTR,
        is_QMouseEvent_PythonToCpp_QMouseEvent_PTR_Convertible,
        QMouseEvent_PTR_CppToPython_QMouseEvent);

    Shiboken::Conversions::registerConverterName(converter, "QMouseEvent");
    Shiboken::Conversions::registerConverterName(converter, "QMouseEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QMouseEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMouseEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMouseEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QMouseEvent_Type, &Sbk_QMouseEvent_typeDiscovery);


}
