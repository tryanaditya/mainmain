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

#include "qgraphicsscenedragdropevent_wrapper.h"

// Extra includes
#include <qgraphicssceneevent.h>
#include <qmimedata.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGraphicsSceneDragDropEventWrapper::QGraphicsSceneDragDropEventWrapper(QEvent::Type type) : QGraphicsSceneDragDropEvent(type) {
    // ... middle
}

QGraphicsSceneDragDropEventWrapper::~QGraphicsSceneDragDropEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsSceneDragDropEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsSceneDragDropEvent >()))
        return -1;

    ::QGraphicsSceneDragDropEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneDragDropEvent(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsSceneDragDropEvent", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsSceneDragDropEvent(QEvent::Type)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsSceneDragDropEvent(QEvent::Type)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QGraphicsSceneDragDropEvent(QEvent::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneDragDropEvent(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsSceneDragDropEvent_Init_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = QEvent::None;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsSceneDragDropEvent(QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsSceneDragDropEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsSceneDragDropEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsSceneDragDropEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsSceneDragDropEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneDragDropEvent", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_acceptProposedAction(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptProposedAction()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->acceptProposedAction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_buttons(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->buttons();
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

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_dropAction(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dropAction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DropAction cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->dropAction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_mimeData(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mimeData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMimeData * cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->mimeData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_modifiers(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->modifiers();
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

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_pos(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_possibleActions(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // possibleActions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::DropAction> cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->possibleActions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_proposedAction(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proposedAction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DropAction cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->proposedAction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_scenePos(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->scenePos();
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

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_screenPos(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->screenPos();
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

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setButtons(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setButtons(QFlags<Qt::MouseButton>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArg)))) {
        overloadId = 0; // setButtons(QFlags<Qt::MouseButton>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setButtons_TypeError;

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

    Sbk_QGraphicsSceneDragDropEventFunc_setButtons_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButtons", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setButtons", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setDropAction(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDropAction(Qt::DropAction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDropAction(Qt::DropAction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setDropAction_TypeError;

    // Call function/method
    {
        ::Qt::DropAction cppArg0 = ((::Qt::DropAction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDropAction(Qt::DropAction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDropAction(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneDragDropEventFunc_setDropAction_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setDropAction", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setModifiers(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModifiers(QFlags<Qt::KeyboardModifier>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArg)))) {
        overloadId = 0; // setModifiers(QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setModifiers_TypeError;

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

    Sbk_QGraphicsSceneDragDropEventFunc_setModifiers_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setModifiers", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setPos_TypeError;

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

    Sbk_QGraphicsSceneDragDropEventFunc_setPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setPossibleActions(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPossibleActions(QFlags<Qt::DropAction>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), (pyArg)))) {
        overloadId = 0; // setPossibleActions(QFlags<Qt::DropAction>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setPossibleActions_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::DropAction> cppArg0 = ((::QFlags<Qt::DropAction>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPossibleActions(QFlags<Qt::DropAction>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPossibleActions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneDragDropEventFunc_setPossibleActions_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropActions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setPossibleActions", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setProposedAction(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProposedAction(Qt::DropAction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), (pyArg)))) {
        overloadId = 0; // setProposedAction(Qt::DropAction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setProposedAction_TypeError;

    // Call function/method
    {
        ::Qt::DropAction cppArg0 = ((::Qt::DropAction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProposedAction(Qt::DropAction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProposedAction(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneDragDropEventFunc_setProposedAction_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setProposedAction", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setScenePos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setScenePos_TypeError;

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

    Sbk_QGraphicsSceneDragDropEventFunc_setScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_setScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScreenPos(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setScreenPos(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneDragDropEventFunc_setScreenPos_TypeError;

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

    Sbk_QGraphicsSceneDragDropEventFunc_setScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneDragDropEvent.setScreenPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneDragDropEventFunc_source(PyObject* self)
{
    ::QGraphicsSceneDragDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneDragDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // source()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QGraphicsSceneDragDropEvent*>(cppSelf)->source();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGraphicsSceneDragDropEvent_methods[] = {
    {"acceptProposedAction", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_acceptProposedAction, METH_NOARGS},
    {"buttons", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_buttons, METH_NOARGS},
    {"dropAction", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_dropAction, METH_NOARGS},
    {"mimeData", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_mimeData, METH_NOARGS},
    {"modifiers", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_modifiers, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_pos, METH_NOARGS},
    {"possibleActions", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_possibleActions, METH_NOARGS},
    {"proposedAction", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_proposedAction, METH_NOARGS},
    {"scenePos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_scenePos, METH_NOARGS},
    {"screenPos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_screenPos, METH_NOARGS},
    {"setButtons", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setButtons, METH_O},
    {"setDropAction", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setDropAction, METH_O},
    {"setModifiers", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setModifiers, METH_O},
    {"setPos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setPos, METH_O},
    {"setPossibleActions", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setPossibleActions, METH_O},
    {"setProposedAction", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setProposedAction, METH_O},
    {"setScenePos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setScenePos, METH_O},
    {"setScreenPos", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_setScreenPos, METH_O},
    {"source", (PyCFunction)Sbk_QGraphicsSceneDragDropEventFunc_source, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsSceneDragDropEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsSceneDragDropEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsSceneDragDropEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsSceneDragDropEvent",
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
    /*tp_traverse*/         Sbk_QGraphicsSceneDragDropEvent_traverse,
    /*tp_clear*/            Sbk_QGraphicsSceneDragDropEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsSceneDragDropEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsSceneDragDropEvent_Init,
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

static void* Sbk_QGraphicsSceneDragDropEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QGraphicsSceneDragDropEvent*>(cptr)->type() == QEvent::GraphicsSceneDragEnter ||  reinterpret_cast< ::QGraphicsSceneDragDropEvent*>(cptr)->type() == QEvent::GraphicsSceneDragLeave ||  reinterpret_cast< ::QGraphicsSceneDragDropEvent*>(cptr)->type() == QEvent::GraphicsSceneDragMove ||  reinterpret_cast< ::QGraphicsSceneDragDropEvent*>(cptr)->type() == QEvent::GraphicsSceneDrop)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsSceneDragDropEvent_PythonToCpp_QGraphicsSceneDragDropEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsSceneDragDropEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsSceneDragDropEvent_PythonToCpp_QGraphicsSceneDragDropEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsSceneDragDropEvent_Type))
        return QGraphicsSceneDragDropEvent_PythonToCpp_QGraphicsSceneDragDropEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsSceneDragDropEvent_PTR_CppToPython_QGraphicsSceneDragDropEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsSceneDragDropEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsSceneDragDropEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsSceneDragDropEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsSceneDragDropEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsSceneDragDropEvent", "QGraphicsSceneDragDropEvent*",
        &Sbk_QGraphicsSceneDragDropEvent_Type, &Shiboken::callCppDestructor< ::QGraphicsSceneDragDropEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsSceneDragDropEvent_Type,
        QGraphicsSceneDragDropEvent_PythonToCpp_QGraphicsSceneDragDropEvent_PTR,
        is_QGraphicsSceneDragDropEvent_PythonToCpp_QGraphicsSceneDragDropEvent_PTR_Convertible,
        QGraphicsSceneDragDropEvent_PTR_CppToPython_QGraphicsSceneDragDropEvent);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneDragDropEvent");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneDragDropEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneDragDropEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneDragDropEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneDragDropEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsSceneDragDropEvent_Type, &Sbk_QGraphicsSceneDragDropEvent_typeDiscovery);


}
