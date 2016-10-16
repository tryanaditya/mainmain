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

#include "qwheelevent_wrapper.h"

// Extra includes
#include <qpoint.h>


// Native ---------------------------------------------------------

QWheelEventWrapper::QWheelEventWrapper(const QPoint & pos, const QPoint & globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) : QWheelEvent(pos, globalPos, delta, buttons, modifiers, orient) {
    // ... middle
}

QWheelEventWrapper::QWheelEventWrapper(const QPoint & pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient) : QWheelEvent(pos, delta, buttons, modifiers, orient) {
    // ... middle
}

QWheelEventWrapper::~QWheelEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWheelEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWheelEvent >()))
        return -1;

    ::QWheelEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QWheelEvent(): too many arguments");
        return -1;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QWheelEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:QWheelEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QWheelEvent(QPoint,QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
    // 1: QWheelEvent(QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        if (numArgs >= 4
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 1; // QWheelEvent(QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[4])))) {
                overloadId = 1; // QWheelEvent(QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
            }
        } else if (numArgs >= 5
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 0; // QWheelEvent(QPoint,QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[5])))) {
                overloadId = 0; // QWheelEvent(QPoint,QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWheelEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QWheelEvent(const QPoint & pos, const QPoint & globalPos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "orient");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QWheelEvent(): got multiple values for keyword argument 'orient'.");
                    return -1;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[5]))))
                        goto Sbk_QWheelEvent_Init_TypeError;
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

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::MouseButton> cppArg3 = ((::QFlags<Qt::MouseButton>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QFlags<Qt::KeyboardModifier> cppArg4 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::Qt::Orientation cppArg5 = Qt::Vertical;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // QWheelEvent(QPoint,QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWheelEventWrapper(*cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QWheelEvent(const QPoint & pos, int delta, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, Qt::Orientation orient)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "orient");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QWheelEvent(): got multiple values for keyword argument 'orient'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[4]))))
                        goto Sbk_QWheelEvent_Init_TypeError;
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

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Qt::MouseButton> cppArg2 = ((::QFlags<Qt::MouseButton>)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::KeyboardModifier> cppArg3 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::Orientation cppArg4 = Qt::Vertical;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QWheelEvent(QPoint,int,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,Qt::Orientation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWheelEventWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWheelEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWheelEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWheelEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtCore.QPoint, int, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers, PySide.QtCore.Qt.Orientation = Qt.Vertical", "PySide.QtCore.QPoint, int, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers, PySide.QtCore.Qt.Orientation = Qt.Vertical", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QWheelEvent", overloads);
        return -1;
}

static PyObject* Sbk_QWheelEventFunc_buttons(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->buttons();
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

static PyObject* Sbk_QWheelEventFunc_delta(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // delta()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->delta();
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

static PyObject* Sbk_QWheelEventFunc_globalPos(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->globalPos();
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

static PyObject* Sbk_QWheelEventFunc_globalX(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->globalX();
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

static PyObject* Sbk_QWheelEventFunc_globalY(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->globalY();
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

static PyObject* Sbk_QWheelEventFunc_orientation(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // orientation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::Orientation cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->orientation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWheelEventFunc_pos(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QWheelEventFunc_x(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->x();
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

static PyObject* Sbk_QWheelEventFunc_y(PyObject* self)
{
    ::QWheelEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWheelEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWheelEvent*>(cppSelf)->y();
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

static PyMethodDef Sbk_QWheelEvent_methods[] = {
    {"buttons", (PyCFunction)Sbk_QWheelEventFunc_buttons, METH_NOARGS},
    {"delta", (PyCFunction)Sbk_QWheelEventFunc_delta, METH_NOARGS},
    {"globalPos", (PyCFunction)Sbk_QWheelEventFunc_globalPos, METH_NOARGS},
    {"globalX", (PyCFunction)Sbk_QWheelEventFunc_globalX, METH_NOARGS},
    {"globalY", (PyCFunction)Sbk_QWheelEventFunc_globalY, METH_NOARGS},
    {"orientation", (PyCFunction)Sbk_QWheelEventFunc_orientation, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QWheelEventFunc_pos, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QWheelEventFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QWheelEventFunc_y, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWheelEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWheelEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWheelEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QWheelEvent",
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
    /*tp_traverse*/         Sbk_QWheelEvent_traverse,
    /*tp_clear*/            Sbk_QWheelEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWheelEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWheelEvent_Init,
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

static void* Sbk_QWheelEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QWheelEvent*>(cptr)->type() == QEvent::Wheel)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QWheelEvent_PythonToCpp_QWheelEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWheelEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWheelEvent_PythonToCpp_QWheelEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWheelEvent_Type))
        return QWheelEvent_PythonToCpp_QWheelEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWheelEvent_PTR_CppToPython_QWheelEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWheelEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWheelEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QWheelEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWheelEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWheelEvent", "QWheelEvent*",
        &Sbk_QWheelEvent_Type, &Shiboken::callCppDestructor< ::QWheelEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWheelEvent_Type,
        QWheelEvent_PythonToCpp_QWheelEvent_PTR,
        is_QWheelEvent_PythonToCpp_QWheelEvent_PTR_Convertible,
        QWheelEvent_PTR_CppToPython_QWheelEvent);

    Shiboken::Conversions::registerConverterName(converter, "QWheelEvent");
    Shiboken::Conversions::registerConverterName(converter, "QWheelEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QWheelEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWheelEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWheelEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QWheelEvent_Type, &Sbk_QWheelEvent_typeDiscovery);


}
