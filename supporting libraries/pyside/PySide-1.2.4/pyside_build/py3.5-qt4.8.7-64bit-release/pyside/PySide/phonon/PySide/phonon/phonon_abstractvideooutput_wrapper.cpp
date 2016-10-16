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

#include "phonon_abstractvideooutput_wrapper.h"

// Extra includes
#include <QList>
#include <path.h>

using namespace Phonon;

// Native ---------------------------------------------------------

AbstractVideoOutputWrapper::~AbstractVideoOutputWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyMethodDef Sbk_Phonon_AbstractVideoOutput_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_AbstractVideoOutput_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_AbstractVideoOutput_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_AbstractVideoOutput_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.AbstractVideoOutput",
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
    /*tp_traverse*/         Sbk_Phonon_AbstractVideoOutput_traverse,
    /*tp_clear*/            Sbk_Phonon_AbstractVideoOutput_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_AbstractVideoOutput_methods,
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

static void* Sbk_Phonon_AbstractVideoOutput_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Phonon::MediaNode >()))
        return dynamic_cast< ::Phonon::AbstractVideoOutput*>(reinterpret_cast< ::Phonon::MediaNode*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void AbstractVideoOutput_PythonToCpp_AbstractVideoOutput_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_AbstractVideoOutput_Type, pyIn, cppOut);
}
static PythonToCppFunc is_AbstractVideoOutput_PythonToCpp_AbstractVideoOutput_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_AbstractVideoOutput_Type))
        return AbstractVideoOutput_PythonToCpp_AbstractVideoOutput_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* AbstractVideoOutput_PTR_CppToPython_AbstractVideoOutput(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::AbstractVideoOutput*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_AbstractVideoOutput_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_AbstractVideoOutput(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_ABSTRACTVIDEOOUTPUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_AbstractVideoOutput_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "AbstractVideoOutput", "Phonon::AbstractVideoOutput*",
        &Sbk_Phonon_AbstractVideoOutput_Type, &Shiboken::callCppDestructor< ::Phonon::AbstractVideoOutput >, (SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_AbstractVideoOutput_Type,
        AbstractVideoOutput_PythonToCpp_AbstractVideoOutput_PTR,
        is_AbstractVideoOutput_PythonToCpp_AbstractVideoOutput_PTR_Convertible,
        AbstractVideoOutput_PTR_CppToPython_AbstractVideoOutput);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::AbstractVideoOutput");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::AbstractVideoOutput*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::AbstractVideoOutput&");
    Shiboken::Conversions::registerConverterName(converter, "AbstractVideoOutput");
    Shiboken::Conversions::registerConverterName(converter, "AbstractVideoOutput*");
    Shiboken::Conversions::registerConverterName(converter, "AbstractVideoOutput&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::AbstractVideoOutput).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::AbstractVideoOutputWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Phonon_AbstractVideoOutput_Type, &Sbk_Phonon_AbstractVideoOutput_typeDiscovery);


}
