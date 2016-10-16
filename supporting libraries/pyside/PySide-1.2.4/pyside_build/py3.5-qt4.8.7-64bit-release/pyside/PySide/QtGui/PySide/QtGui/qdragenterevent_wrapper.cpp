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

#include "qdragenterevent_wrapper.h"

// Extra includes
#include <qmimedata.h>
#include <qpoint.h>
#include <qrect.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QDragEnterEventWrapper::QDragEnterEventWrapper(const QPoint & pos, QFlags<Qt::DropAction> actions, const QMimeData * data, QFlags<Qt::MouseButton> buttons, QFlags<Qt::KeyboardModifier> modifiers) : QDragEnterEvent(pos, actions, data, buttons, modifiers) {
    // ... middle
}

QDragEnterEventWrapper::~QDragEnterEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDragEnterEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDragEnterEvent >()))
        return -1;

    ::QDragEnterEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDragEnterEvent", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QDragEnterEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[4])))) {
        overloadId = 0; // QDragEnterEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDragEnterEvent_Init_TypeError;

    // Call function/method
    {
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

        if (!PyErr_Occurred()) {
            // QDragEnterEvent(QPoint,QFlags<Qt::DropAction>,const QMimeData*,QFlags<Qt::MouseButton>,QFlags<Qt::KeyboardModifier>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDragEnterEventWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDragEnterEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDragEnterEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDragEnterEvent_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtCore.Qt.DropActions, PySide.QtCore.QMimeData, PySide.QtCore.Qt.MouseButtons, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDragEnterEvent", overloads);
        return -1;
}

static PyMethodDef Sbk_QDragEnterEvent_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDragEnterEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDragEnterEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QDragEnterEventSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QDragEnterEvent* me = reinterpret_cast< ::QDragEnterEvent*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX]))
        return static_cast< ::QDragMoveEvent*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX]))
        return static_cast< ::QDropEvent*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QEVENT_IDX]))
        return static_cast< ::QEvent*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDragEnterEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDragEnterEvent",
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
    /*tp_traverse*/         Sbk_QDragEnterEvent_traverse,
    /*tp_clear*/            Sbk_QDragEnterEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDragEnterEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDragEnterEvent_Init,
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

static void* Sbk_QDragEnterEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QDragEnterEvent*>(cptr)->type() == QEvent::DragEnter)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDragEnterEvent_PythonToCpp_QDragEnterEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDragEnterEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDragEnterEvent_PythonToCpp_QDragEnterEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDragEnterEvent_Type))
        return QDragEnterEvent_PythonToCpp_QDragEnterEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDragEnterEvent_PTR_CppToPython_QDragEnterEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDragEnterEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDragEnterEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDragEnterEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDragEnterEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDragEnterEvent", "QDragEnterEvent*",
        &Sbk_QDragEnterEvent_Type, &Shiboken::callCppDestructor< ::QDragEnterEvent >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDragEnterEvent_Type,
        QDragEnterEvent_PythonToCpp_QDragEnterEvent_PTR,
        is_QDragEnterEvent_PythonToCpp_QDragEnterEvent_PTR_Convertible,
        QDragEnterEvent_PTR_CppToPython_QDragEnterEvent);

    Shiboken::Conversions::registerConverterName(converter, "QDragEnterEvent");
    Shiboken::Conversions::registerConverterName(converter, "QDragEnterEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QDragEnterEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDragEnterEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDragEnterEventWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QDragEnterEvent_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QDragEnterEvent_Type, &Sbk_QDragEnterEventSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDragEnterEvent_Type, &Sbk_QDragEnterEvent_typeDiscovery);


}
