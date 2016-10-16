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

#include "qgraphicsscenecontextmenuevent_wrapper.h"

// Extra includes
#include <qgraphicssceneevent.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGraphicsSceneContextMenuEventWrapper::QGraphicsSceneContextMenuEventWrapper(QEvent::Type type) : QGraphicsSceneContextMenuEvent(type) {
    // ... middle
}

QGraphicsSceneContextMenuEventWrapper::~QGraphicsSceneContextMenuEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsSceneContextMenuEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsSceneContextMenuEvent >()))
        return -1;

    ::QGraphicsSceneContextMenuEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneContextMenuEvent(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsSceneContextMenuEvent", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsSceneContextMenuEvent(QEvent::Type)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsSceneContextMenuEvent(QEvent::Type)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QGraphicsSceneContextMenuEvent(QEvent::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsSceneContextMenuEvent(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsSceneContextMenuEvent_Init_TypeError;
            }
        }
        ::QEvent::Type cppArg0 = QEvent::None;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsSceneContextMenuEvent(QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsSceneContextMenuEventWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsSceneContextMenuEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsSceneContextMenuEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsSceneContextMenuEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent.Type = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsSceneContextMenuEvent", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_modifiers(PyObject* self)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QGraphicsSceneContextMenuEvent*>(cppSelf)->modifiers();
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

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_pos(PyObject* self)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneContextMenuEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_reason(PyObject* self)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reason()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsSceneContextMenuEvent::Reason cppResult = const_cast<const ::QGraphicsSceneContextMenuEvent*>(cppSelf)->reason();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_scenePos(PyObject* self)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsSceneContextMenuEvent*>(cppSelf)->scenePos();
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

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_screenPos(PyObject* self)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screenPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QGraphicsSceneContextMenuEvent*>(cppSelf)->screenPos();
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

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_setModifiers(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModifiers(QFlags<Qt::KeyboardModifier>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArg)))) {
        overloadId = 0; // setModifiers(QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEventFunc_setModifiers_TypeError;

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

    Sbk_QGraphicsSceneContextMenuEventFunc_setModifiers_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneContextMenuEvent.setModifiers", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_setPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEventFunc_setPos_TypeError;

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

    Sbk_QGraphicsSceneContextMenuEventFunc_setPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneContextMenuEvent.setPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_setReason(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReason(QGraphicsSceneContextMenuEvent::Reason)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX]), (pyArg)))) {
        overloadId = 0; // setReason(QGraphicsSceneContextMenuEvent::Reason)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEventFunc_setReason_TypeError;

    // Call function/method
    {
        ::QGraphicsSceneContextMenuEvent::Reason cppArg0 = ((::QGraphicsSceneContextMenuEvent::Reason)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReason(QGraphicsSceneContextMenuEvent::Reason)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReason(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneContextMenuEventFunc_setReason_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneContextMenuEvent.Reason", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneContextMenuEvent.setReason", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_setScenePos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScenePos(QPointF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // setScenePos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEventFunc_setScenePos_TypeError;

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

    Sbk_QGraphicsSceneContextMenuEventFunc_setScenePos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneContextMenuEvent.setScenePos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneContextMenuEventFunc_setScreenPos(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsSceneContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsSceneContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScreenPos(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setScreenPos(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneContextMenuEventFunc_setScreenPos_TypeError;

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

    Sbk_QGraphicsSceneContextMenuEventFunc_setScreenPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsSceneContextMenuEvent.setScreenPos", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsSceneContextMenuEvent_methods[] = {
    {"modifiers", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_modifiers, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_pos, METH_NOARGS},
    {"reason", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_reason, METH_NOARGS},
    {"scenePos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_scenePos, METH_NOARGS},
    {"screenPos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_screenPos, METH_NOARGS},
    {"setModifiers", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_setModifiers, METH_O},
    {"setPos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_setPos, METH_O},
    {"setReason", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_setReason, METH_O},
    {"setScenePos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_setScenePos, METH_O},
    {"setScreenPos", (PyCFunction)Sbk_QGraphicsSceneContextMenuEventFunc_setScreenPos, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsSceneContextMenuEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsSceneContextMenuEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsSceneContextMenuEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsSceneContextMenuEvent",
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
    /*tp_traverse*/         Sbk_QGraphicsSceneContextMenuEvent_traverse,
    /*tp_clear*/            Sbk_QGraphicsSceneContextMenuEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsSceneContextMenuEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsSceneContextMenuEvent_Init,
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

static void* Sbk_QGraphicsSceneContextMenuEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QGraphicsSceneContextMenuEvent*>(cptr)->type() == QEvent::GraphicsSceneContextMenu)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QGraphicsSceneContextMenuEvent_Reason_PythonToCpp_QGraphicsSceneContextMenuEvent_Reason(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsSceneContextMenuEvent::Reason*)cppOut) = (::QGraphicsSceneContextMenuEvent::Reason) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsSceneContextMenuEvent_Reason_PythonToCpp_QGraphicsSceneContextMenuEvent_Reason_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX]))
        return QGraphicsSceneContextMenuEvent_Reason_PythonToCpp_QGraphicsSceneContextMenuEvent_Reason;
    return 0;
}
static PyObject* QGraphicsSceneContextMenuEvent_Reason_CppToPython_QGraphicsSceneContextMenuEvent_Reason(const void* cppIn) {
    int castCppIn = *((::QGraphicsSceneContextMenuEvent::Reason*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsSceneContextMenuEvent_PythonToCpp_QGraphicsSceneContextMenuEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsSceneContextMenuEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsSceneContextMenuEvent_PythonToCpp_QGraphicsSceneContextMenuEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsSceneContextMenuEvent_Type))
        return QGraphicsSceneContextMenuEvent_PythonToCpp_QGraphicsSceneContextMenuEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsSceneContextMenuEvent_PTR_CppToPython_QGraphicsSceneContextMenuEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsSceneContextMenuEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsSceneContextMenuEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsSceneContextMenuEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsSceneContextMenuEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsSceneContextMenuEvent", "QGraphicsSceneContextMenuEvent*",
        &Sbk_QGraphicsSceneContextMenuEvent_Type, &Shiboken::callCppDestructor< ::QGraphicsSceneContextMenuEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsSceneContextMenuEvent_Type,
        QGraphicsSceneContextMenuEvent_PythonToCpp_QGraphicsSceneContextMenuEvent_PTR,
        is_QGraphicsSceneContextMenuEvent_PythonToCpp_QGraphicsSceneContextMenuEvent_PTR_Convertible,
        QGraphicsSceneContextMenuEvent_PTR_CppToPython_QGraphicsSceneContextMenuEvent);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneContextMenuEvent");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneContextMenuEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneContextMenuEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneContextMenuEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneContextMenuEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsSceneContextMenuEvent_Type, &Sbk_QGraphicsSceneContextMenuEvent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Reason'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsSceneContextMenuEvent_Type,
        "Reason",
        "PySide.QtGui.QGraphicsSceneContextMenuEvent.Reason",
        "QGraphicsSceneContextMenuEvent::Reason");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QGraphicsSceneContextMenuEvent_Type, "Mouse", (long) QGraphicsSceneContextMenuEvent::Mouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QGraphicsSceneContextMenuEvent_Type, "Keyboard", (long) QGraphicsSceneContextMenuEvent::Keyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QGraphicsSceneContextMenuEvent_Type, "Other", (long) QGraphicsSceneContextMenuEvent::Other))
        return ;
    // Register converter for enum 'QGraphicsSceneContextMenuEvent::Reason'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX],
            QGraphicsSceneContextMenuEvent_Reason_CppToPython_QGraphicsSceneContextMenuEvent_Reason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsSceneContextMenuEvent_Reason_PythonToCpp_QGraphicsSceneContextMenuEvent_Reason,
            is_QGraphicsSceneContextMenuEvent_Reason_PythonToCpp_QGraphicsSceneContextMenuEvent_Reason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_REASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsSceneContextMenuEvent::Reason");
        Shiboken::Conversions::registerConverterName(converter, "Reason");
    }
    // End of 'Reason' enum.


    qRegisterMetaType< ::QGraphicsSceneContextMenuEvent::Reason >("QGraphicsSceneContextMenuEvent::Reason");
}
