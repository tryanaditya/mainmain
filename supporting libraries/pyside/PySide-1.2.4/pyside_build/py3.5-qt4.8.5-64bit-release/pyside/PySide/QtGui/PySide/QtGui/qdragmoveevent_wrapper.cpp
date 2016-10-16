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

#include "qdragmoveevent_wrapper.h"

// Extra includes
#include <qmimedata.h>
#include <qpoint.h>
#include <qrect.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QDragMoveEventWrapper::QDragMoveEventWrapper(const QPoint & pos, QFlags<Qt::DropAction> actions, const QMimeData * data, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers, QEvent::Type type) : QDragMoveEvent(pos, actions, data, buttons, modifiers, type) {
    // ... middle
}

QDragMoveEventWrapper::~QDragMoveEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDragMoveEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDragMoveEvent >()))
        return -1;

    ::QDragMoveEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDragMoveEvent(): too many arguments");
        return -1;
    } else if (numArgs < 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDragMoveEvent(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:QDragMoveEvent", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QDragMoveEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
    if (numArgs >= 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
        if (numArgs == 5) {
            overloadId = 0; // QDragMoveEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[5])))) {
            overloadId = 0; // QDragMoveEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDragMoveEvent_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDragMoveEvent(): got multiple values for keyword argument 'type'.");
                return -1;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QEVENT_TYPE_IDX]), (pyArgs[5]))))
                    goto Sbk_QDragMoveEvent_Init_TypeError;
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
        ::QEvent::Type cppArg5 = QEvent::DragMove;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // QDragMoveEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>,QEvent::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDragMoveEventWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDragMoveEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDragMoveEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDragMoveEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtCore.Qt.DropActions, PySide.QtCore.QMimeData, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers, PySide.QtCore.QEvent.Type = DragMove", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDragMoveEvent", overloads);
        return -1;
}

static PyObject* Sbk_QDragMoveEventFunc_accept(PyObject* self, PyObject* args)
{
    ::QDragMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDragMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (SbkObject*)self));
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
    // 1: accept(QRect)
    if (numArgs == 0) {
        overloadId = 0; // accept()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // accept(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDragMoveEventFunc_accept_TypeError;

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
        case 1: // accept(const QRect & r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // accept(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->accept(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDragMoveEventFunc_accept_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDragMoveEvent.accept", overloads);
        return 0;
}

static PyObject* Sbk_QDragMoveEventFunc_answerRect(PyObject* self)
{
    ::QDragMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDragMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // answerRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QDragMoveEvent*>(cppSelf)->answerRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDragMoveEventFunc_ignore(PyObject* self, PyObject* args)
{
    ::QDragMoveEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDragMoveEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (SbkObject*)self));
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
    // 1: ignore(QRect)
    if (numArgs == 0) {
        overloadId = 0; // ignore()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // ignore(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDragMoveEventFunc_ignore_TypeError;

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
        case 1: // ignore(const QRect & r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // ignore(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignore(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDragMoveEventFunc_ignore_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDragMoveEvent.ignore", overloads);
        return 0;
}

static PyMethodDef Sbk_QDragMoveEvent_methods[] = {
    {"accept", (PyCFunction)Sbk_QDragMoveEventFunc_accept, METH_VARARGS},
    {"answerRect", (PyCFunction)Sbk_QDragMoveEventFunc_answerRect, METH_NOARGS},
    {"ignore", (PyCFunction)Sbk_QDragMoveEventFunc_ignore, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDragMoveEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDragMoveEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QDragMoveEventSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QDragMoveEvent* me = reinterpret_cast< ::QDragMoveEvent*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX]))
        return static_cast< ::QDropEvent*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX]))
        return static_cast< ::QEvent*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDragMoveEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDragMoveEvent",
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
    /*tp_traverse*/         Sbk_QDragMoveEvent_traverse,
    /*tp_clear*/            Sbk_QDragMoveEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDragMoveEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDragMoveEvent_Init,
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

static void* Sbk_QDragMoveEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QDragMoveEvent*>(cptr)->type() == QEvent::DragMove)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDragMoveEvent_PythonToCpp_QDragMoveEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDragMoveEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDragMoveEvent_PythonToCpp_QDragMoveEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDragMoveEvent_Type))
        return QDragMoveEvent_PythonToCpp_QDragMoveEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDragMoveEvent_PTR_CppToPython_QDragMoveEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDragMoveEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDragMoveEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDragMoveEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDragMoveEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDragMoveEvent", "QDragMoveEvent*",
        &Sbk_QDragMoveEvent_Type, &Shiboken::callCppDestructor< ::QDragMoveEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDragMoveEvent_Type,
        QDragMoveEvent_PythonToCpp_QDragMoveEvent_PTR,
        is_QDragMoveEvent_PythonToCpp_QDragMoveEvent_PTR_Convertible,
        QDragMoveEvent_PTR_CppToPython_QDragMoveEvent);

    Shiboken::Conversions::registerConverterName(converter, "QDragMoveEvent");
    Shiboken::Conversions::registerConverterName(converter, "QDragMoveEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QDragMoveEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDragMoveEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDragMoveEventWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QDragMoveEvent_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QDragMoveEvent_Type, &Sbk_QDragMoveEventSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDragMoveEvent_Type, &Sbk_QDragMoveEvent_typeDiscovery);


}
