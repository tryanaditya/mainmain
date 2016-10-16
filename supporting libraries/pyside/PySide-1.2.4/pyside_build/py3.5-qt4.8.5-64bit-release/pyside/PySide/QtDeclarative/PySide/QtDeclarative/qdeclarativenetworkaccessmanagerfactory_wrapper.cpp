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
#include "pyside_qtdeclarative_python.h"

#include "qdeclarativenetworkaccessmanagerfactory_wrapper.h"

// Extra includes
#include <qnetworkaccessmanager.h>
#include <qobject.h>


// Native ---------------------------------------------------------

QDeclarativeNetworkAccessManagerFactoryWrapper::QDeclarativeNetworkAccessManagerFactoryWrapper() : QDeclarativeNetworkAccessManagerFactory() {
    // ... middle
}

QNetworkAccessManager * QDeclarativeNetworkAccessManagerFactoryWrapper::create(QObject * parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QNetworkAccessManager*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "create"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QDeclarativeNetworkAccessManagerFactory.create()' not implemented.");
        return ((::QNetworkAccessManager*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QNetworkAccessManager*)0);
    }
    bool invalidateArg0 = pyResult->ob_refcnt == 1;
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeNetworkAccessManagerFactory.create", Shiboken::SbkType< QNetworkAccessManager >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QNetworkAccessManager*)0);
    }
    ::QNetworkAccessManager* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg0)
        Shiboken::Object::releaseOwnership(pyResult.object());
    return cppResult;
}

QDeclarativeNetworkAccessManagerFactoryWrapper::~QDeclarativeNetworkAccessManagerFactoryWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeNetworkAccessManagerFactory_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVENETWORKACCESSMANAGERFACTORY_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QDeclarativeNetworkAccessManagerFactory' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeNetworkAccessManagerFactory >()))
        return -1;

    ::QDeclarativeNetworkAccessManagerFactoryWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QDeclarativeNetworkAccessManagerFactory()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDeclarativeNetworkAccessManagerFactoryWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeNetworkAccessManagerFactory >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QDeclarativeNetworkAccessManagerFactoryFunc_create(PyObject* self, PyObject* pyArg)
{
    ::QDeclarativeNetworkAccessManagerFactory* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeNetworkAccessManagerFactory*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVENETWORKACCESSMANAGERFACTORY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: create(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // create(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeNetworkAccessManagerFactoryFunc_create_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // create(QObject*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QDeclarativeNetworkAccessManagerFactory.create()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkAccessManager * cppResult = cppSelf->create(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::invalidate(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativeNetworkAccessManagerFactoryFunc_create_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtDeclarative.QDeclarativeNetworkAccessManagerFactory.create", overloads);
        return 0;
}

static PyMethodDef Sbk_QDeclarativeNetworkAccessManagerFactory_methods[] = {
    {"create", (PyCFunction)Sbk_QDeclarativeNetworkAccessManagerFactoryFunc_create, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDeclarativeNetworkAccessManagerFactory_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeNetworkAccessManagerFactory_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeNetworkAccessManagerFactory_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeNetworkAccessManagerFactory",
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
    /*tp_traverse*/         Sbk_QDeclarativeNetworkAccessManagerFactory_traverse,
    /*tp_clear*/            Sbk_QDeclarativeNetworkAccessManagerFactory_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeNetworkAccessManagerFactory_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeNetworkAccessManagerFactory_Init,
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
static void QDeclarativeNetworkAccessManagerFactory_PythonToCpp_QDeclarativeNetworkAccessManagerFactory_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeNetworkAccessManagerFactory_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeNetworkAccessManagerFactory_PythonToCpp_QDeclarativeNetworkAccessManagerFactory_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeNetworkAccessManagerFactory_Type))
        return QDeclarativeNetworkAccessManagerFactory_PythonToCpp_QDeclarativeNetworkAccessManagerFactory_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeNetworkAccessManagerFactory_PTR_CppToPython_QDeclarativeNetworkAccessManagerFactory(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDeclarativeNetworkAccessManagerFactory*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDeclarativeNetworkAccessManagerFactory_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDeclarativeNetworkAccessManagerFactory(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVENETWORKACCESSMANAGERFACTORY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeNetworkAccessManagerFactory_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeNetworkAccessManagerFactory", "QDeclarativeNetworkAccessManagerFactory*",
        &Sbk_QDeclarativeNetworkAccessManagerFactory_Type, &Shiboken::callCppDestructor< ::QDeclarativeNetworkAccessManagerFactory >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeNetworkAccessManagerFactory_Type,
        QDeclarativeNetworkAccessManagerFactory_PythonToCpp_QDeclarativeNetworkAccessManagerFactory_PTR,
        is_QDeclarativeNetworkAccessManagerFactory_PythonToCpp_QDeclarativeNetworkAccessManagerFactory_PTR_Convertible,
        QDeclarativeNetworkAccessManagerFactory_PTR_CppToPython_QDeclarativeNetworkAccessManagerFactory);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeNetworkAccessManagerFactory");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeNetworkAccessManagerFactory*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeNetworkAccessManagerFactory&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeNetworkAccessManagerFactory).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeNetworkAccessManagerFactoryWrapper).name());



}
