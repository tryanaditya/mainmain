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

#include "phonon_volumefaderinterface_wrapper.h"

// Extra includes

using namespace Phonon;

// Native ---------------------------------------------------------

VolumeFaderInterfaceWrapper::VolumeFaderInterfaceWrapper() : Phonon::VolumeFaderInterface() {
    // ... middle
}

Phonon::VolumeFaderEffect::FadeCurve VolumeFaderInterfaceWrapper::fadeCurve() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::VolumeFaderEffect::FadeCurve)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fadeCurve"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::VolumeFaderInterface::fadeCurve();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::VolumeFaderEffect::FadeCurve)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VolumeFaderInterface.fadeCurve", Shiboken::SbkType< Phonon::VolumeFaderEffect::FadeCurve >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::VolumeFaderEffect::FadeCurve)0);
    }
    ::Phonon::VolumeFaderEffect::FadeCurve cppResult = ((::Phonon::VolumeFaderEffect::FadeCurve)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VolumeFaderInterfaceWrapper::fadeTo(float arg__1, int arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fadeTo"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::VolumeFaderInterface::fadeTo(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(fi)",
        arg__1,
        arg__2
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VolumeFaderInterfaceWrapper::setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFadeCurve"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::VolumeFaderInterface::setFadeCurve(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VolumeFaderInterfaceWrapper::setVolume(float arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVolume"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::VolumeFaderInterface::setVolume(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(f)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

float VolumeFaderInterfaceWrapper::volume() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((float)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "volume"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::VolumeFaderInterface::volume();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((float)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VolumeFaderInterface.volume", "float", pyResult->ob_type->tp_name);
        return ((float)0);
    }
    float cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

VolumeFaderInterfaceWrapper::~VolumeFaderInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_VolumeFaderInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::VolumeFaderInterface >()))
        return -1;

    ::VolumeFaderInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // VolumeFaderInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::VolumeFaderInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::VolumeFaderInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_VolumeFaderInterfaceFunc_fadeCurve(PyObject* self)
{
    ::Phonon::VolumeFaderInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fadeCurve()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::VolumeFaderEffect::FadeCurve cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::VolumeFaderInterface*>(cppSelf)->::Phonon::VolumeFaderInterface::fadeCurve() : const_cast<const ::Phonon::VolumeFaderInterface*>(cppSelf)->fadeCurve();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_VolumeFaderInterfaceFunc_fadeTo(PyObject* self, PyObject* args)
{
    ::Phonon::VolumeFaderInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fadeTo", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fadeTo(float,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // fadeTo(float,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderInterfaceFunc_fadeTo_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fadeTo(float,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Phonon::VolumeFaderInterface::fadeTo(cppArg0, cppArg1) : cppSelf->fadeTo(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderInterfaceFunc_fadeTo_TypeError:
        const char* overloads[] = {"float, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.VolumeFaderInterface.fadeTo", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderInterfaceFunc_setFadeCurve(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), (pyArg)))) {
        overloadId = 0; // setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderInterfaceFunc_setFadeCurve_TypeError;

    // Call function/method
    {
        ::Phonon::VolumeFaderEffect::FadeCurve cppArg0 = ((::Phonon::VolumeFaderEffect::FadeCurve)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Phonon::VolumeFaderInterface::setFadeCurve(cppArg0) : cppSelf->setFadeCurve(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderInterfaceFunc_setFadeCurve_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::VolumeFaderEffect.FadeCurve", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderInterface.setFadeCurve", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderInterfaceFunc_setVolume(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVolume(float)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArg)))) {
        overloadId = 0; // setVolume(float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderInterfaceFunc_setVolume_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVolume(float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Phonon::VolumeFaderInterface::setVolume(cppArg0) : cppSelf->setVolume(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderInterfaceFunc_setVolume_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderInterface.setVolume", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderInterfaceFunc_volume(PyObject* self)
{
    ::Phonon::VolumeFaderInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // volume()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            float cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::VolumeFaderInterface*>(cppSelf)->::Phonon::VolumeFaderInterface::volume() : const_cast<const ::Phonon::VolumeFaderInterface*>(cppSelf)->volume();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_VolumeFaderInterface_methods[] = {
    {"fadeCurve", (PyCFunction)Sbk_Phonon_VolumeFaderInterfaceFunc_fadeCurve, METH_NOARGS},
    {"fadeTo", (PyCFunction)Sbk_Phonon_VolumeFaderInterfaceFunc_fadeTo, METH_VARARGS},
    {"setFadeCurve", (PyCFunction)Sbk_Phonon_VolumeFaderInterfaceFunc_setFadeCurve, METH_O},
    {"setVolume", (PyCFunction)Sbk_Phonon_VolumeFaderInterfaceFunc_setVolume, METH_O},
    {"volume", (PyCFunction)Sbk_Phonon_VolumeFaderInterfaceFunc_volume, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_VolumeFaderInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_VolumeFaderInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_VolumeFaderInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.VolumeFaderInterface",
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
    /*tp_traverse*/         Sbk_Phonon_VolumeFaderInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_VolumeFaderInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_VolumeFaderInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_VolumeFaderInterface_Init,
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
static void VolumeFaderInterface_PythonToCpp_VolumeFaderInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_VolumeFaderInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_VolumeFaderInterface_PythonToCpp_VolumeFaderInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_VolumeFaderInterface_Type))
        return VolumeFaderInterface_PythonToCpp_VolumeFaderInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* VolumeFaderInterface_PTR_CppToPython_VolumeFaderInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::VolumeFaderInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_VolumeFaderInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_VolumeFaderInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADERINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_VolumeFaderInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "VolumeFaderInterface", "Phonon::VolumeFaderInterface*",
        &Sbk_Phonon_VolumeFaderInterface_Type, &Shiboken::callCppDestructor< ::Phonon::VolumeFaderInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_VolumeFaderInterface_Type,
        VolumeFaderInterface_PythonToCpp_VolumeFaderInterface_PTR,
        is_VolumeFaderInterface_PythonToCpp_VolumeFaderInterface_PTR_Convertible,
        VolumeFaderInterface_PTR_CppToPython_VolumeFaderInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderInterface&");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderInterface");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderInterface*");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::VolumeFaderInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::VolumeFaderInterfaceWrapper).name());



}
