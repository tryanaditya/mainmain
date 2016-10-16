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

#include "qcontextmenuevent_wrapper.h"

// Extra includes
#include <qpoint.h>


// Native ---------------------------------------------------------

QContextMenuEventWrapper::QContextMenuEventWrapper(QContextMenuEvent::Reason reason, const QPoint & pos) : QContextMenuEvent(reason, pos) {
    // ... middle
}

QContextMenuEventWrapper::QContextMenuEventWrapper(QContextMenuEvent::Reason reason, const QPoint & pos, const QPoint & globalPos) : QContextMenuEvent(reason, pos, globalPos) {
    // ... middle
}

QContextMenuEventWrapper::QContextMenuEventWrapper(QContextMenuEvent::Reason reason, const QPoint & pos, const QPoint & globalPos, QFlags<Qt::KeyboardModifier> modifiers) : QContextMenuEvent(reason, pos, globalPos, modifiers) {
    // ... middle
}

QContextMenuEventWrapper::~QContextMenuEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QContextMenuEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QContextMenuEvent >()))
        return -1;

    ::QContextMenuEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QContextMenuEvent", 2, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QContextMenuEvent(QContextMenuEvent::Reason,QPoint)
    // 1: QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint)
    // 2: QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint,QFlags<Qt::KeyboardModifier>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // QContextMenuEvent(QContextMenuEvent::Reason,QPoint)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint)
            } else if (numArgs == 4
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[3])))) {
                overloadId = 2; // QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint,QFlags<Qt::KeyboardModifier>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QContextMenuEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint & pos)
        {
            ::QContextMenuEvent::Reason cppArg0 = ((::QContextMenuEvent::Reason)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QContextMenuEvent(QContextMenuEvent::Reason,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QContextMenuEventWrapper(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint & pos, const QPoint & globalPos)
        {
            ::QContextMenuEvent::Reason cppArg0 = ((::QContextMenuEvent::Reason)0);
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


            if (!PyErr_Occurred()) {
                // QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QContextMenuEventWrapper(cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint & pos, const QPoint & globalPos, QFlags<Qt::KeyboardModifier> modifiers)
        {
            ::QContextMenuEvent::Reason cppArg0 = ((::QContextMenuEvent::Reason)0);
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

            ::QFlags<Qt::KeyboardModifier> cppArg3 = ((::QFlags<Qt::KeyboardModifier>)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QContextMenuEvent(QContextMenuEvent::Reason,QPoint,QPoint,QFlags<Qt::KeyboardModifier>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QContextMenuEventWrapper(cppArg0, *cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QContextMenuEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QContextMenuEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QContextMenuEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent.Reason, PySide.QtCore.QPoint", "PySide.QtGui.QContextMenuEvent.Reason, PySide.QtCore.QPoint, PySide.QtCore.QPoint", "PySide.QtGui.QContextMenuEvent.Reason, PySide.QtCore.QPoint, PySide.QtCore.QPoint, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QContextMenuEvent", overloads);
        return -1;
}

static PyObject* Sbk_QContextMenuEventFunc_globalPos(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalPos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->globalPos();
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

static PyObject* Sbk_QContextMenuEventFunc_globalX(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->globalX();
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

static PyObject* Sbk_QContextMenuEventFunc_globalY(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->globalY();
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

static PyObject* Sbk_QContextMenuEventFunc_pos(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPoint & cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->pos();
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

static PyObject* Sbk_QContextMenuEventFunc_reason(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reason()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QContextMenuEvent::Reason cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->reason();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QContextMenuEventFunc_x(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->x();
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

static PyObject* Sbk_QContextMenuEventFunc_y(PyObject* self)
{
    ::QContextMenuEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QContextMenuEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QContextMenuEvent*>(cppSelf)->y();
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

static PyMethodDef Sbk_QContextMenuEvent_methods[] = {
    {"globalPos", (PyCFunction)Sbk_QContextMenuEventFunc_globalPos, METH_NOARGS},
    {"globalX", (PyCFunction)Sbk_QContextMenuEventFunc_globalX, METH_NOARGS},
    {"globalY", (PyCFunction)Sbk_QContextMenuEventFunc_globalY, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QContextMenuEventFunc_pos, METH_NOARGS},
    {"reason", (PyCFunction)Sbk_QContextMenuEventFunc_reason, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QContextMenuEventFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QContextMenuEventFunc_y, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QContextMenuEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QContextMenuEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QContextMenuEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QContextMenuEvent",
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
    /*tp_traverse*/         Sbk_QContextMenuEvent_traverse,
    /*tp_clear*/            Sbk_QContextMenuEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QContextMenuEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QContextMenuEvent_Init,
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

static void* Sbk_QContextMenuEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QContextMenuEvent*>(cptr)->type() == QEvent::ContextMenu)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QContextMenuEvent_Reason_PythonToCpp_QContextMenuEvent_Reason(PyObject* pyIn, void* cppOut) {
    *((::QContextMenuEvent::Reason*)cppOut) = (::QContextMenuEvent::Reason) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QContextMenuEvent_Reason_PythonToCpp_QContextMenuEvent_Reason_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX]))
        return QContextMenuEvent_Reason_PythonToCpp_QContextMenuEvent_Reason;
    return 0;
}
static PyObject* QContextMenuEvent_Reason_CppToPython_QContextMenuEvent_Reason(const void* cppIn) {
    int castCppIn = *((::QContextMenuEvent::Reason*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QContextMenuEvent_PythonToCpp_QContextMenuEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QContextMenuEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QContextMenuEvent_PythonToCpp_QContextMenuEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QContextMenuEvent_Type))
        return QContextMenuEvent_PythonToCpp_QContextMenuEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QContextMenuEvent_PTR_CppToPython_QContextMenuEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QContextMenuEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QContextMenuEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QContextMenuEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QContextMenuEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QContextMenuEvent", "QContextMenuEvent*",
        &Sbk_QContextMenuEvent_Type, &Shiboken::callCppDestructor< ::QContextMenuEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QContextMenuEvent_Type,
        QContextMenuEvent_PythonToCpp_QContextMenuEvent_PTR,
        is_QContextMenuEvent_PythonToCpp_QContextMenuEvent_PTR_Convertible,
        QContextMenuEvent_PTR_CppToPython_QContextMenuEvent);

    Shiboken::Conversions::registerConverterName(converter, "QContextMenuEvent");
    Shiboken::Conversions::registerConverterName(converter, "QContextMenuEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QContextMenuEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QContextMenuEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QContextMenuEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QContextMenuEvent_Type, &Sbk_QContextMenuEvent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Reason'.
    SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QContextMenuEvent_Type,
        "Reason",
        "PySide.QtGui.QContextMenuEvent.Reason",
        "QContextMenuEvent::Reason");
    if (!SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QContextMenuEvent_Type, "Mouse", (long) QContextMenuEvent::Mouse))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QContextMenuEvent_Type, "Keyboard", (long) QContextMenuEvent::Keyboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX],
        &Sbk_QContextMenuEvent_Type, "Other", (long) QContextMenuEvent::Other))
        return ;
    // Register converter for enum 'QContextMenuEvent::Reason'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX],
            QContextMenuEvent_Reason_CppToPython_QContextMenuEvent_Reason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QContextMenuEvent_Reason_PythonToCpp_QContextMenuEvent_Reason,
            is_QContextMenuEvent_Reason_PythonToCpp_QContextMenuEvent_Reason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QContextMenuEvent::Reason");
        Shiboken::Conversions::registerConverterName(converter, "Reason");
    }
    // End of 'Reason' enum.


    qRegisterMetaType< ::QContextMenuEvent::Reason >("QContextMenuEvent::Reason");
}
