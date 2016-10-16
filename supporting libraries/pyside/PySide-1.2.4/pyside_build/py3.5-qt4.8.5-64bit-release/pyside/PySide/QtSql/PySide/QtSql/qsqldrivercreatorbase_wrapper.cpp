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
#include "pyside_qtsql_python.h"

#include "qsqldrivercreatorbase_wrapper.h"

// Extra includes
#include <QSqlDriver>
#include <qsqldriver.h>


// Native ---------------------------------------------------------

QSqlDriverCreatorBaseWrapper::QSqlDriverCreatorBaseWrapper() : QSqlDriverCreatorBase() {
    // ... middle
}

QSqlDriver * QSqlDriverCreatorBaseWrapper::createObject() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QSqlDriver*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createObject"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriverCreatorBase.createObject()' not implemented.");
        return ((::QSqlDriver*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QSqlDriver*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSqlDriverCreatorBase.createObject", Shiboken::SbkType< QSqlDriver >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QSqlDriver*)0);
    }
    ::QSqlDriver* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSqlDriverCreatorBaseWrapper::~QSqlDriverCreatorBaseWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlDriverCreatorBase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtSqlTypes[SBK_QSQLDRIVERCREATORBASE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QSqlDriverCreatorBase' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlDriverCreatorBase >()))
        return -1;

    ::QSqlDriverCreatorBaseWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QSqlDriverCreatorBase()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSqlDriverCreatorBaseWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlDriverCreatorBase >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QSqlDriverCreatorBaseFunc_createObject(PyObject* self)
{
    ::QSqlDriverCreatorBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlDriverCreatorBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLDRIVERCREATORBASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createObject()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QSqlDriverCreatorBase.createObject()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlDriver * cppResult = const_cast<const ::QSqlDriverCreatorBase*>(cppSelf)->createObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLDRIVER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlDriverCreatorBase_methods[] = {
    {"createObject", (PyCFunction)Sbk_QSqlDriverCreatorBaseFunc_createObject, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlDriverCreatorBase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlDriverCreatorBase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlDriverCreatorBase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlDriverCreatorBase",
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
    /*tp_traverse*/         Sbk_QSqlDriverCreatorBase_traverse,
    /*tp_clear*/            Sbk_QSqlDriverCreatorBase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlDriverCreatorBase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlDriverCreatorBase_Init,
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
static void QSqlDriverCreatorBase_PythonToCpp_QSqlDriverCreatorBase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlDriverCreatorBase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlDriverCreatorBase_PythonToCpp_QSqlDriverCreatorBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlDriverCreatorBase_Type))
        return QSqlDriverCreatorBase_PythonToCpp_QSqlDriverCreatorBase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlDriverCreatorBase_PTR_CppToPython_QSqlDriverCreatorBase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlDriverCreatorBase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlDriverCreatorBase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSqlDriverCreatorBase(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLDRIVERCREATORBASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlDriverCreatorBase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlDriverCreatorBase", "QSqlDriverCreatorBase*",
        &Sbk_QSqlDriverCreatorBase_Type, &Shiboken::callCppDestructor< ::QSqlDriverCreatorBase >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlDriverCreatorBase_Type,
        QSqlDriverCreatorBase_PythonToCpp_QSqlDriverCreatorBase_PTR,
        is_QSqlDriverCreatorBase_PythonToCpp_QSqlDriverCreatorBase_PTR_Convertible,
        QSqlDriverCreatorBase_PTR_CppToPython_QSqlDriverCreatorBase);

    Shiboken::Conversions::registerConverterName(converter, "QSqlDriverCreatorBase");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDriverCreatorBase*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlDriverCreatorBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlDriverCreatorBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlDriverCreatorBaseWrapper).name());



}
