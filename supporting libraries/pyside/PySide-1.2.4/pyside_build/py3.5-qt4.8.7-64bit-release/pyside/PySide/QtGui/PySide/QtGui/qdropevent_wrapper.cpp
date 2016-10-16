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
#include <set>
#include "pyside_qtgui_python.h"

#include "qdropevent_wrapper.h"

// Extra includes
#include <qmimedata.h>
#include <qpoint.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QDropEventWrapper::QDropEventWrapper(const QPoint & pos, QFlags<Qt::DropAction> actions, const QMimeData * data, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, QEvent::Type type) : QDropEvent(pos, actions, data, buttons, modifiers, type) {
    // ... middle
}

QDropEventWrapper::~QDropEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDropEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX]);
    if (type != myType) {
        Shiboken::ObjectType::copyMultimpleheritance(type, myType);
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDropEvent >()))
        return -1;

    ::QDropEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDropEvent(): too many arguments");
        return -1;
    } else if (numArgs < 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDropEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:QDropEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QDropEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
    if (numArgs >= 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
        if (numArgs == 5) {
            overloadId = 0; // QDropEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[5])))) {
            overloadId = 0; // QDropEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDropEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDropEvent(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[5]))))
                    goto Sbk_QDropEvent_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QFlags<Qt::DropAction> cppArg1 = ((::QFlags<Qt::DropAction>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return -1;
        ::QMimeData* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QFlags<Qt::MouseButton> cppArg3 = ((::QFlags<Qt::MouseButton>)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QFlags<Qt::KeyboardModifier> cppArg4 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QEvent::Type cppArg5 = QEvent::Drop;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // QDropEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDropEventWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDropEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDropEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDropEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtCore.Qt.DropActions, PySide.QtCore.QMimeData, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers, PySide.QtCore.QEvent.Type = Drop", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDropEvent", overloads);
        return -1;
}

static PyObject* Sbk_QDropEventFunc_acceptProposedAction(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QDropEventFunc_dropAction(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dropAction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DropAction cppResult = const_cast<const ::QDropEvent*>(cppSelf)->dropAction();
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

static PyObject* Sbk_QDropEventFunc_keyboardModifiers(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardModifiers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::KeyboardModifier> cppResult = const_cast<const ::QDropEvent*>(cppSelf)->keyboardModifiers();
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

static PyObject* Sbk_QDropEventFunc_mimeData(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mimeData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMimeData * cppResult = const_cast<const ::QDropEvent*>(cppSelf)->mimeData();
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

static PyObject* Sbk_QDropEventFunc_mouseButtons(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mouseButtons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QDropEvent*>(cppSelf)->mouseButtons();
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

static PyObject* Sbk_QDropEventFunc_pos(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QDropEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QDropEventFunc_possibleActions(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // possibleActions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::DropAction> cppResult = const_cast<const ::QDropEvent*>(cppSelf)->possibleActions();
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

static PyObject* Sbk_QDropEventFunc_proposedAction(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proposedAction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DropAction cppResult = const_cast<const ::QDropEvent*>(cppSelf)->proposedAction();
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

static PyObject* Sbk_QDropEventFunc_setDropAction(PyObject* self, PyObject* pyArg)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDropAction(Qt::DropAction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDropAction(Qt::DropAction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDropEventFunc_setDropAction_TypeError;

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

    Sbk_QDropEventFunc_setDropAction_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDropEvent.setDropAction", overloads);
        return 0;
}

static PyObject* Sbk_QDropEventFunc_source(PyObject* self)
{
    ::QDropEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDropEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // source()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QDropEvent*>(cppSelf)->source();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDropEvent_methods[] = {
    {"acceptProposedAction", (PyCFunction)Sbk_QDropEventFunc_acceptProposedAction, METH_NOARGS},
    {"dropAction", (PyCFunction)Sbk_QDropEventFunc_dropAction, METH_NOARGS},
    {"keyboardModifiers", (PyCFunction)Sbk_QDropEventFunc_keyboardModifiers, METH_NOARGS},
    {"mimeData", (PyCFunction)Sbk_QDropEventFunc_mimeData, METH_NOARGS},
    {"mouseButtons", (PyCFunction)Sbk_QDropEventFunc_mouseButtons, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QDropEventFunc_pos, METH_NOARGS},
    {"possibleActions", (PyCFunction)Sbk_QDropEventFunc_possibleActions, METH_NOARGS},
    {"proposedAction", (PyCFunction)Sbk_QDropEventFunc_proposedAction, METH_NOARGS},
    {"setDropAction", (PyCFunction)Sbk_QDropEventFunc_setDropAction, METH_O},
    {"source", (PyCFunction)Sbk_QDropEventFunc_source, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDropEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDropEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1 };
int*
Sbk_QDropEvent_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const QDropEvent* class_ptr = reinterpret_cast<const QDropEvent*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QEvent*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QEvent*>((QDropEvent*)((void*)class_ptr))) - base);

        offsets.erase(0);

        int i = 0;
        for (it = offsets.begin(); it != offsets.end(); it++) {
            mi_offsets[i] = *it;
            i++;
        }
    }
    return mi_offsets;
}
static void* Sbk_QDropEventSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QDropEvent* me = reinterpret_cast< ::QDropEvent*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX]))
        return static_cast< ::QEvent*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDropEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDropEvent",
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
    /*tp_traverse*/         Sbk_QDropEvent_traverse,
    /*tp_clear*/            Sbk_QDropEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDropEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDropEvent_Init,
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

static void* Sbk_QDropEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QDropEvent*>(cptr)->type() == QEvent::Drop)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDropEvent_PythonToCpp_QDropEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDropEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDropEvent_PythonToCpp_QDropEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDropEvent_Type))
        return QDropEvent_PythonToCpp_QDropEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDropEvent_PTR_CppToPython_QDropEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDropEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDropEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDropEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDropEvent_Type);

    PyObject* Sbk_QDropEvent_Type_bases = PyTuple_Pack(1,
        (PyObject*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX]);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDropEvent", "QDropEvent*",
        &Sbk_QDropEvent_Type, &Shiboken::callCppDestructor< ::QDropEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], Sbk_QDropEvent_Type_bases)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDropEvent_Type,
        QDropEvent_PythonToCpp_QDropEvent_PTR,
        is_QDropEvent_PythonToCpp_QDropEvent_PTR_Convertible,
        QDropEvent_PTR_CppToPython_QDropEvent);

    Shiboken::Conversions::registerConverterName(converter, "QDropEvent");
    Shiboken::Conversions::registerConverterName(converter, "QDropEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QDropEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDropEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDropEventWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_QDropEvent_mi_init;
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QDropEvent_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QDropEvent_Type, &Sbk_QDropEventSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDropEvent_Type, &Sbk_QDropEvent_typeDiscovery);


}
