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

#include "phonon_medianode_wrapper.h"

// Extra includes
#include <QList>
#include <path.h>

using namespace Phonon;

// Native ---------------------------------------------------------

MediaNodeWrapper::~MediaNodeWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Phonon_MediaNodeFunc_inputPaths(PyObject* self)
{
    ::Phonon::MediaNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaNode*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // inputPaths()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::Path > cppResult = const_cast<const ::Phonon::MediaNode*>(cppSelf)->inputPaths();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_PATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaNodeFunc_isValid(PyObject* self)
{
    ::Phonon::MediaNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaNode*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaNode*>(cppSelf)->isValid();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaNodeFunc_outputPaths(PyObject* self)
{
    ::Phonon::MediaNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaNode*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // outputPaths()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::Path > cppResult = const_cast<const ::Phonon::MediaNode*>(cppSelf)->outputPaths();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_PATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_MediaNode_methods[] = {
    {"inputPaths", (PyCFunction)Sbk_Phonon_MediaNodeFunc_inputPaths, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_Phonon_MediaNodeFunc_isValid, METH_NOARGS},
    {"outputPaths", (PyCFunction)Sbk_Phonon_MediaNodeFunc_outputPaths, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_MediaNode_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_MediaNode_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_MediaNode_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.MediaNode",
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
    /*tp_traverse*/         Sbk_Phonon_MediaNode_traverse,
    /*tp_clear*/            Sbk_Phonon_MediaNode_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_MediaNode_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void MediaNode_PythonToCpp_MediaNode_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_MediaNode_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MediaNode_PythonToCpp_MediaNode_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaNode_Type))
        return MediaNode_PythonToCpp_MediaNode_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MediaNode_PTR_CppToPython_MediaNode(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::MediaNode*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_MediaNode_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_MediaNode(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_MediaNode_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MediaNode", "Phonon::MediaNode*",
        &Sbk_Phonon_MediaNode_Type, &Shiboken::callCppDestructor< ::Phonon::MediaNode >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_MediaNode_Type,
        MediaNode_PythonToCpp_MediaNode_PTR,
        is_MediaNode_PythonToCpp_MediaNode_PTR_Convertible,
        MediaNode_PTR_CppToPython_MediaNode);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaNode");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaNode*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaNode&");
    Shiboken::Conversions::registerConverterName(converter, "MediaNode");
    Shiboken::Conversions::registerConverterName(converter, "MediaNode*");
    Shiboken::Conversions::registerConverterName(converter, "MediaNode&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::MediaNode).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::MediaNodeWrapper).name());



}
