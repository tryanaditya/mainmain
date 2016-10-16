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
#include "pyside_phonon_python.h"

#include "phonon_effectinterface_wrapper.h"

// Extra includes
#include <QList>
#include <effectparameter.h>

using namespace Phonon;

// Native ---------------------------------------------------------

EffectInterfaceWrapper::EffectInterfaceWrapper() : Phonon::EffectInterface() {
    // ... middle
}

QVariant EffectInterfaceWrapper::parameterValue(const Phonon::EffectParameter & arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parameterValue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.parameterValue()' not implemented.");
        return ::QVariant();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "EffectInterface.parameterValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<Phonon::EffectParameter > EffectInterfaceWrapper::parameters() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<Phonon::EffectParameter >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parameters"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.parameters()' not implemented.");
        return ::QList<Phonon::EffectParameter >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<Phonon::EffectParameter >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPARAMETER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "EffectInterface.parameters", "list", pyResult->ob_type->tp_name);
        return ::QList<Phonon::EffectParameter >();
    }
    ::QList<Phonon::EffectParameter > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void EffectInterfaceWrapper::setParameterValue(const Phonon::EffectParameter & arg__1, const QVariant & newValue)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setParameterValue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.setParameterValue()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], &arg__1),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &newValue)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

EffectInterfaceWrapper::~EffectInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_EffectInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_EFFECTINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::EffectInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::EffectInterface >()))
        return -1;

    ::EffectInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // EffectInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::EffectInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::EffectInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_EffectInterfaceFunc_parameterValue(PyObject* self, PyObject* pyArg)
{
    ::Phonon::EffectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: parameterValue(Phonon::EffectParameter)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (pyArg)))) {
        overloadId = 0; // parameterValue(Phonon::EffectParameter)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_EffectInterfaceFunc_parameterValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::EffectParameter cppArg0_local = ::Phonon::EffectParameter();
        ::Phonon::EffectParameter* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // parameterValue(Phonon::EffectParameter)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.parameterValue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::Phonon::EffectInterface*>(cppSelf)->parameterValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_EffectInterfaceFunc_parameterValue_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::EffectParameter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.EffectInterface.parameterValue", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_EffectInterfaceFunc_parameters(PyObject* self)
{
    ::Phonon::EffectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parameters()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.parameters()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::EffectParameter > cppResult = const_cast<const ::Phonon::EffectInterface*>(cppSelf)->parameters();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_EFFECTPARAMETER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_EffectInterfaceFunc_setParameterValue(PyObject* self, PyObject* args)
{
    ::Phonon::EffectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setParameterValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setParameterValue(Phonon::EffectParameter,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setParameterValue(Phonon::EffectParameter,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_EffectInterfaceFunc_setParameterValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Phonon::EffectParameter cppArg0_local = ::Phonon::EffectParameter();
        ::Phonon::EffectParameter* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setParameterValue(Phonon::EffectParameter,QVariant)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'EffectInterface.setParameterValue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setParameterValue(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_EffectInterfaceFunc_setParameterValue_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::EffectParameter, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.EffectInterface.setParameterValue", overloads);
        return 0;
}

static PyMethodDef Sbk_Phonon_EffectInterface_methods[] = {
    {"parameterValue", (PyCFunction)Sbk_Phonon_EffectInterfaceFunc_parameterValue, METH_O},
    {"parameters", (PyCFunction)Sbk_Phonon_EffectInterfaceFunc_parameters, METH_NOARGS},
    {"setParameterValue", (PyCFunction)Sbk_Phonon_EffectInterfaceFunc_setParameterValue, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_EffectInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_EffectInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_EffectInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.EffectInterface",
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
    /*tp_traverse*/         Sbk_Phonon_EffectInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_EffectInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_EffectInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_EffectInterface_Init,
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
static void EffectInterface_PythonToCpp_EffectInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_EffectInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_EffectInterface_PythonToCpp_EffectInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_EffectInterface_Type))
        return EffectInterface_PythonToCpp_EffectInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* EffectInterface_PTR_CppToPython_EffectInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::EffectInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_EffectInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_EffectInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_EFFECTINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_EffectInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "EffectInterface", "Phonon::EffectInterface*",
        &Sbk_Phonon_EffectInterface_Type, &Shiboken::callCppDestructor< ::Phonon::EffectInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_EffectInterface_Type,
        EffectInterface_PythonToCpp_EffectInterface_PTR,
        is_EffectInterface_PythonToCpp_EffectInterface_PTR_Convertible,
        EffectInterface_PTR_CppToPython_EffectInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectInterface&");
    Shiboken::Conversions::registerConverterName(converter, "EffectInterface");
    Shiboken::Conversions::registerConverterName(converter, "EffectInterface*");
    Shiboken::Conversions::registerConverterName(converter, "EffectInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::EffectInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::EffectInterfaceWrapper).name());



}
