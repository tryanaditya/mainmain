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

#include "qtouchevent_wrapper.h"
#include "qtouchevent_touchpoint_wrapper.h"

// Extra includes
#include <QList>
#include <qevent.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QTouchEventWrapper::~QTouchEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QTouchEventFunc_deviceType(PyObject* self)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTouchEvent::DeviceType cppResult = const_cast<const ::QTouchEvent*>(cppSelf)->deviceType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTouchEventFunc_setDeviceType(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDeviceType(QTouchEvent::DeviceType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX]), (pyArg)))) {
        overloadId = 0; // setDeviceType(QTouchEvent::DeviceType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEventFunc_setDeviceType_TypeError;

    // Call function/method
    {
        ::QTouchEvent::DeviceType cppArg0 = ((::QTouchEvent::DeviceType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDeviceType(QTouchEvent::DeviceType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDeviceType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEventFunc_setDeviceType_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTouchEvent.DeviceType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTouchEvent.setDeviceType", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEventFunc_setTouchPoints(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTouchPoints(QList<QTouchEvent::TouchPoint>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setTouchPoints(QList<QTouchEvent::TouchPoint>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEventFunc_setTouchPoints_TypeError;

    // Call function/method
    {
        ::QList<QTouchEvent::TouchPoint > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTouchPoints(QList<QTouchEvent::TouchPoint>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTouchPoints(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTouchEventFunc_setTouchPoints_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTouchEvent.setTouchPoints", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEventFunc_setWidget(PyObject* self, PyObject* pyArg)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTouchEventFunc_setWidget_TypeError;

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

    Sbk_QTouchEventFunc_setWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTouchEvent.setWidget", overloads);
        return 0;
}

static PyObject* Sbk_QTouchEventFunc_touchPoints(PyObject* self)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // touchPoints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QTouchEvent::TouchPoint > & cppResult = const_cast<const ::QTouchEvent*>(cppSelf)->touchPoints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTouchEventFunc_widget(PyObject* self)
{
    ::QTouchEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTouchEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QTouchEvent*>(cppSelf)->widget();
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

static PyMethodDef Sbk_QTouchEvent_methods[] = {
    {"deviceType", (PyCFunction)Sbk_QTouchEventFunc_deviceType, METH_NOARGS},
    {"setDeviceType", (PyCFunction)Sbk_QTouchEventFunc_setDeviceType, METH_O},
    {"setTouchPoints", (PyCFunction)Sbk_QTouchEventFunc_setTouchPoints, METH_O},
    {"setWidget", (PyCFunction)Sbk_QTouchEventFunc_setWidget, METH_O},
    {"touchPoints", (PyCFunction)Sbk_QTouchEventFunc_touchPoints, METH_NOARGS},
    {"widget", (PyCFunction)Sbk_QTouchEventFunc_widget, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTouchEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTouchEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTouchEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTouchEvent",
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QTouchEvent_traverse,
    /*tp_clear*/            Sbk_QTouchEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTouchEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

static void* Sbk_QTouchEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QEvent >()))
        return dynamic_cast< ::QTouchEvent*>(reinterpret_cast< ::QEvent*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QTouchEvent_DeviceType_PythonToCpp_QTouchEvent_DeviceType(PyObject* pyIn, void* cppOut) {
    *((::QTouchEvent::DeviceType*)cppOut) = (::QTouchEvent::DeviceType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTouchEvent_DeviceType_PythonToCpp_QTouchEvent_DeviceType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX]))
        return QTouchEvent_DeviceType_PythonToCpp_QTouchEvent_DeviceType;
    return 0;
}
static PyObject* QTouchEvent_DeviceType_CppToPython_QTouchEvent_DeviceType(const void* cppIn) {
    int castCppIn = *((::QTouchEvent::DeviceType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTouchEvent_PythonToCpp_QTouchEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTouchEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTouchEvent_PythonToCpp_QTouchEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTouchEvent_Type))
        return QTouchEvent_PythonToCpp_QTouchEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTouchEvent_PTR_CppToPython_QTouchEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTouchEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTouchEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTouchEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTouchEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTouchEvent", "QTouchEvent*",
        &Sbk_QTouchEvent_Type, &Shiboken::callCppDestructor< ::QTouchEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTouchEvent_Type,
        QTouchEvent_PythonToCpp_QTouchEvent_PTR,
        is_QTouchEvent_PythonToCpp_QTouchEvent_PTR_Convertible,
        QTouchEvent_PTR_CppToPython_QTouchEvent);

    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent");
    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QTouchEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTouchEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTouchEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QTouchEvent_Type, &Sbk_QTouchEvent_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'DeviceType'.
    SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTouchEvent_Type,
        "DeviceType",
        "PySide.QtGui.QTouchEvent.DeviceType",
        "QTouchEvent::DeviceType");
    if (!SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX],
        &Sbk_QTouchEvent_Type, "TouchScreen", (long) QTouchEvent::TouchScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX],
        &Sbk_QTouchEvent_Type, "TouchPad", (long) QTouchEvent::TouchPad))
        return ;
    // Register converter for enum 'QTouchEvent::DeviceType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX],
            QTouchEvent_DeviceType_CppToPython_QTouchEvent_DeviceType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTouchEvent_DeviceType_PythonToCpp_QTouchEvent_DeviceType,
            is_QTouchEvent_DeviceType_PythonToCpp_QTouchEvent_DeviceType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTOUCHEVENT_DEVICETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTouchEvent::DeviceType");
        Shiboken::Conversions::registerConverterName(converter, "DeviceType");
    }
    // End of 'DeviceType' enum.


    qRegisterMetaType< ::QTouchEvent::DeviceType >("QTouchEvent::DeviceType");
}
