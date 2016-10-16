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

#include "qgraphicsscenemouseevent_wrapper.h"

// Extra includes
#include <qgraphicssceneevent.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGraphicsSceneMouseEventWrapper::QGraphicsSceneMouseEventWrapper(QEvent::Type type) : QGraphicsSceneMouseEvent(type) {
    // ... middle
}

QGraphicsSceneMouseEventWrapper::~QGraphicsSceneMouseEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsSceneMouseEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsSceneMouseEvent >()))
        return -1;

    ::QGraphicsSceneMouseEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneMouseEvent(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsSceneMouseEvent", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsSceneMouseEvent(QEvent::Type)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsSceneMouseEvent(QEvent::Type)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QGraphicsSceneMouseEvent(QEvent::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneMouseEvent(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsSceneMouseEvent_Init_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = QEvent::None;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsSceneMouseEvent(QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsSceneMouseEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsSceneMouseEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsSceneMouseEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsSceneMouseEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneMouseEvent", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_button(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // button()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::MouseButton cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->button();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_buttonDownPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: buttonDownPos(Qt::MouseButton)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // buttonDownPos(Qt::MouseButton)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_buttonDownPos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // buttonDownPos(Qt::MouseButton)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->buttonDownPos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneMouseEventFunc_buttonDownPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.buttonDownPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_buttonDownScenePos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: buttonDownScenePos(Qt::MouseButton)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // buttonDownScenePos(Qt::MouseButton)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_buttonDownScenePos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // buttonDownScenePos(Qt::MouseButton)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->buttonDownScenePos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneMouseEventFunc_buttonDownScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.buttonDownScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_buttonDownScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: buttonDownScreenPos(Qt::MouseButton)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // buttonDownScreenPos(Qt::MouseButton)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_buttonDownScreenPos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // buttonDownScreenPos(Qt::MouseButton)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->buttonDownScreenPos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneMouseEventFunc_buttonDownScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.buttonDownScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_buttons(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->buttons();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_lastPos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->lastPos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_lastScenePos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastScenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->lastScenePos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_lastScreenPos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastScreenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->lastScreenPos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_modifiers(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->modifiers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_pos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_scenePos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->scenePos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_screenPos(PyObject* self)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QGraphicsSceneMouseEvent*>(cppSelf)->screenPos();
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

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setButton(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setButton(Qt::MouseButton)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // setButton(Qt::MouseButton)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setButton_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setButton(Qt::MouseButton)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButton(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setButton_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setButton", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setButtonDownPos(PyObject* self, PyObject* args)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setButtonDownPos", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setButtonDownPos(Qt::MouseButton,QPointF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // setButtonDownPos(Qt::MouseButton,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setButtonDownPos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
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
            // setButtonDownPos(Qt::MouseButton,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButtonDownPos(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setButtonDownPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneMouseEvent.setButtonDownPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScenePos(PyObject* self, PyObject* args)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setButtonDownScenePos", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setButtonDownScenePos(Qt::MouseButton,QPointF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // setButtonDownScenePos(Qt::MouseButton,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScenePos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
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
            // setButtonDownScenePos(Qt::MouseButton,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButtonDownScenePos(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneMouseEvent.setButtonDownScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScreenPos(PyObject* self, PyObject* args)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setButtonDownScreenPos", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setButtonDownScreenPos(Qt::MouseButton,QPoint)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_MOUSEBUTTON_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setButtonDownScreenPos(Qt::MouseButton,QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScreenPos_TypeError;

    // Call function/method
    {
        ::Qt::MouseButton cppArg0 = ((::Qt::MouseButton)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPoint cppArg1_local = ::QPoint();
        ::QPoint* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setButtonDownScreenPos(Qt::MouseButton,QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButtonDownScreenPos(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButton, PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneMouseEvent.setButtonDownScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setButtons(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setButtons(QFlags<Qt::MouseButton>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArg)))) {
        overloadId = 0; // setButtons(QFlags<Qt::MouseButton>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setButtons_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::MouseButton> cppArg0 = ((::QFlags<Qt::MouseButton>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setButtons(QFlags<Qt::MouseButton>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButtons(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setButtons_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButtons", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setButtons", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setLastPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setLastPos_TypeError;

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

    Sbk_QGraphicsSceneMouseEventFunc_setLastPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setLastPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setLastScenePos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setLastScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setLastScenePos_TypeError;

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

    Sbk_QGraphicsSceneMouseEventFunc_setLastScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setLastScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setLastScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLastScreenPos(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setLastScreenPos(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setLastScreenPos_TypeError;

    // Call function/method
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
            // setLastScreenPos(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLastScreenPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setLastScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setLastScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setModifiers(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModifiers(QFlags<Qt::KeyboardModifier>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArg)))) {
        overloadId = 0; // setModifiers(QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setModifiers_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::KeyboardModifier> cppArg0 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModifiers(QFlags<Qt::KeyboardModifier>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModifiers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setModifiers_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setModifiers", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setPos_TypeError;

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

    Sbk_QGraphicsSceneMouseEventFunc_setPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setScenePos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setScenePos_TypeError;

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

    Sbk_QGraphicsSceneMouseEventFunc_setScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneMouseEventFunc_setScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneMouseEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneMouseEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScreenPos(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setScreenPos(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneMouseEventFunc_setScreenPos_TypeError;

    // Call function/method
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
            // setScreenPos(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScreenPos(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneMouseEventFunc_setScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneMouseEvent.setScreenPos", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsSceneMouseEvent_methods[] = {
    {"button", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_button, METH_NOARGS},
    {"buttonDownPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_buttonDownPos, METH_O},
    {"buttonDownScenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_buttonDownScenePos, METH_O},
    {"buttonDownScreenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_buttonDownScreenPos, METH_O},
    {"buttons", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_buttons, METH_NOARGS},
    {"lastPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_lastPos, METH_NOARGS},
    {"lastScenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_lastScenePos, METH_NOARGS},
    {"lastScreenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_lastScreenPos, METH_NOARGS},
    {"modifiers", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_modifiers, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_pos, METH_NOARGS},
    {"scenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_scenePos, METH_NOARGS},
    {"screenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_screenPos, METH_NOARGS},
    {"setButton", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setButton, METH_O},
    {"setButtonDownPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setButtonDownPos, METH_VARARGS},
    {"setButtonDownScenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScenePos, METH_VARARGS},
    {"setButtonDownScreenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setButtonDownScreenPos, METH_VARARGS},
    {"setButtons", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setButtons, METH_O},
    {"setLastPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setLastPos, METH_O},
    {"setLastScenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setLastScenePos, METH_O},
    {"setLastScreenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setLastScreenPos, METH_O},
    {"setModifiers", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setModifiers, METH_O},
    {"setPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setPos, METH_O},
    {"setScenePos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setScenePos, METH_O},
    {"setScreenPos", (PyCFunction)Sbk_QGraphicsSceneMouseEventFunc_setScreenPos, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsSceneMouseEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsSceneMouseEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsSceneMouseEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsSceneMouseEvent",
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
    /*tp_traverse*/         Sbk_QGraphicsSceneMouseEvent_traverse,
    /*tp_clear*/            Sbk_QGraphicsSceneMouseEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsSceneMouseEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsSceneMouseEvent_Init,
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

static void* Sbk_QGraphicsSceneMouseEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QGraphicsSceneMouseEvent*>(cptr)->type() == QEvent::GraphicsSceneMouseDoubleClick ||  reinterpret_cast< ::QGraphicsSceneMouseEvent*>(cptr)->type() == QEvent::GraphicsSceneMouseMove ||  reinterpret_cast< ::QGraphicsSceneMouseEvent*>(cptr)->type() == QEvent::GraphicsSceneMousePress ||  reinterpret_cast< ::QGraphicsSceneMouseEvent*>(cptr)->type() == QEvent::GraphicsSceneMouseRelease)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsSceneMouseEvent_PythonToCpp_QGraphicsSceneMouseEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsSceneMouseEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsSceneMouseEvent_PythonToCpp_QGraphicsSceneMouseEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsSceneMouseEvent_Type))
        return QGraphicsSceneMouseEvent_PythonToCpp_QGraphicsSceneMouseEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsSceneMouseEvent_PTR_CppToPython_QGraphicsSceneMouseEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsSceneMouseEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsSceneMouseEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsSceneMouseEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsSceneMouseEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsSceneMouseEvent", "QGraphicsSceneMouseEvent*",
        &Sbk_QGraphicsSceneMouseEvent_Type, &Shiboken::callCppDestructor< ::QGraphicsSceneMouseEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsSceneMouseEvent_Type,
        QGraphicsSceneMouseEvent_PythonToCpp_QGraphicsSceneMouseEvent_PTR,
        is_QGraphicsSceneMouseEvent_PythonToCpp_QGraphicsSceneMouseEvent_PTR_Convertible,
        QGraphicsSceneMouseEvent_PTR_CppToPython_QGraphicsSceneMouseEvent);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMouseEvent");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMouseEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneMouseEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneMouseEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneMouseEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsSceneMouseEvent_Type, &Sbk_QGraphicsSceneMouseEvent_typeDiscovery);


}
