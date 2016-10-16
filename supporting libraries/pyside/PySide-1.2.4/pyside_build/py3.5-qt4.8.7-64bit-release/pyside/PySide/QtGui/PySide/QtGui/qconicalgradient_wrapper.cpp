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

#include "qconicalgradient_wrapper.h"

// Extra includes
#include <QPair>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qpoint.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QConicalGradient_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QConicalGradient >()))
        return -1;

    ::QConicalGradient* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QConicalGradient", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QConicalGradient()
    // 1: QConicalGradient(QConicalGradient)
    // 2: QConicalGradient(QPointF,qreal)
    // 3: QConicalGradient(qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // QConicalGradient()
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 3; // QConicalGradient(qreal,qreal,qreal)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 2; // QConicalGradient(QPointF,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QConicalGradient(QConicalGradient)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QConicalGradient_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QConicalGradient()
        {

            if (!PyErr_Occurred()) {
                // QConicalGradient()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QConicalGradient();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QConicalGradient(const QConicalGradient & QConicalGradient)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QConicalGradient cppArg0_local = ::QConicalGradient();
            ::QConicalGradient* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QConicalGradient(QConicalGradient)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QConicalGradient(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QConicalGradient(const QPointF & center, qreal startAngle)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QConicalGradient(QPointF,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QConicalGradient(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QConicalGradient(qreal cx, qreal cy, qreal startAngle)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QConicalGradient(qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QConicalGradient(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QConicalGradient >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QConicalGradient_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QConicalGradient_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QConicalGradient", "PySide.QtCore.QPointF, float", "float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QConicalGradient", overloads);
        return -1;
}

static PyObject* Sbk_QConicalGradientFunc_angle(PyObject* self)
{
    ::QConicalGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // angle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QConicalGradient*>(cppSelf)->angle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QConicalGradientFunc_center(PyObject* self)
{
    ::QConicalGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // center()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QConicalGradient*>(cppSelf)->center();
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

static PyObject* Sbk_QConicalGradientFunc_setAngle(PyObject* self, PyObject* pyArg)
{
    ::QConicalGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAngle(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setAngle(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QConicalGradientFunc_setAngle_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAngle(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAngle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QConicalGradientFunc_setAngle_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QConicalGradient.setAngle", overloads);
        return 0;
}

static PyObject* Sbk_QConicalGradientFunc_setCenter(PyObject* self, PyObject* args)
{
    ::QConicalGradient* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCenter", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCenter(QPointF)
    // 1: setCenter(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setCenter(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setCenter(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QConicalGradientFunc_setCenter_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setCenter(const QPointF & center)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setCenter(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCenter(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setCenter(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setCenter(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCenter(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QConicalGradientFunc_setCenter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QConicalGradient.setCenter", overloads);
        return 0;
}

static PyObject* Sbk_QConicalGradient___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QConicalGradient& cppSelf = *(((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QConicalGradient_methods[] = {
    {"angle", (PyCFunction)Sbk_QConicalGradientFunc_angle, METH_NOARGS},
    {"center", (PyCFunction)Sbk_QConicalGradientFunc_center, METH_NOARGS},
    {"setAngle", (PyCFunction)Sbk_QConicalGradientFunc_setAngle, METH_O},
    {"setCenter", (PyCFunction)Sbk_QConicalGradientFunc_setCenter, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QConicalGradient___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QConicalGradient_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QConicalGradient_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QConicalGradient_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QConicalGradient",
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
    /*tp_traverse*/         Sbk_QConicalGradient_traverse,
    /*tp_clear*/            Sbk_QConicalGradient_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QConicalGradient_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QConicalGradient_Init,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QConicalGradient_PythonToCpp_QConicalGradient_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QConicalGradient_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QConicalGradient_PythonToCpp_QConicalGradient_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QConicalGradient_Type))
        return QConicalGradient_PythonToCpp_QConicalGradient_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QConicalGradient_PTR_CppToPython_QConicalGradient(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QConicalGradient*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QConicalGradient_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QConicalGradient_COPY_CppToPython_QConicalGradient(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QConicalGradient_Type, new ::QConicalGradient(*((::QConicalGradient*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QConicalGradient_PythonToCpp_QConicalGradient_COPY(PyObject* pyIn, void* cppOut) {
    *((::QConicalGradient*)cppOut) = *((::QConicalGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QConicalGradient_PythonToCpp_QConicalGradient_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QConicalGradient_Type))
        return QConicalGradient_PythonToCpp_QConicalGradient_COPY;
    return 0;
}

void init_QConicalGradient(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QCONICALGRADIENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QConicalGradient_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QConicalGradient", "QConicalGradient",
        &Sbk_QConicalGradient_Type, &Shiboken::callCppDestructor< ::QConicalGradient >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QConicalGradient_Type,
        QConicalGradient_PythonToCpp_QConicalGradient_PTR,
        is_QConicalGradient_PythonToCpp_QConicalGradient_PTR_Convertible,
        QConicalGradient_PTR_CppToPython_QConicalGradient,
        QConicalGradient_COPY_CppToPython_QConicalGradient);

    Shiboken::Conversions::registerConverterName(converter, "QConicalGradient");
    Shiboken::Conversions::registerConverterName(converter, "QConicalGradient*");
    Shiboken::Conversions::registerConverterName(converter, "QConicalGradient&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QConicalGradient).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QConicalGradient_PythonToCpp_QConicalGradient_COPY,
        is_QConicalGradient_PythonToCpp_QConicalGradient_COPY_Convertible);


    qRegisterMetaType< ::QConicalGradient >("QConicalGradient");
}
