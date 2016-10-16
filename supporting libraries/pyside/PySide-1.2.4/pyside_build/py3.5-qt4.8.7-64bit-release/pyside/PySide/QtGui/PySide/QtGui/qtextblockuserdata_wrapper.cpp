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

#include "qtextblockuserdata_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QTextBlockUserDataWrapper::QTextBlockUserDataWrapper() : QTextBlockUserData() {
    // ... middle
}

QTextBlockUserDataWrapper::~QTextBlockUserDataWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextBlockUserData_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextBlockUserData >()))
        return -1;

    ::QTextBlockUserDataWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QTextBlockUserData()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QTextBlockUserDataWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextBlockUserData >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_QTextBlockUserData_methods[] = {

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextBlockUserData_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextBlockUserData_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextBlockUserData_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextBlockUserData",
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
    /*tp_traverse*/         Sbk_QTextBlockUserData_traverse,
    /*tp_clear*/            Sbk_QTextBlockUserData_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextBlockUserData_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextBlockUserData_Init,
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
static void QTextBlockUserData_PythonToCpp_QTextBlockUserData_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextBlockUserData_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextBlockUserData_PythonToCpp_QTextBlockUserData_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlockUserData_Type))
        return QTextBlockUserData_PythonToCpp_QTextBlockUserData_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextBlockUserData_PTR_CppToPython_QTextBlockUserData(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextBlockUserData*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextBlockUserData_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextBlockUserData(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextBlockUserData_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextBlockUserData", "QTextBlockUserData*",
        &Sbk_QTextBlockUserData_Type, &Shiboken::callCppDestructor< ::QTextBlockUserData >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextBlockUserData_Type,
        QTextBlockUserData_PythonToCpp_QTextBlockUserData_PTR,
        is_QTextBlockUserData_PythonToCpp_QTextBlockUserData_PTR_Convertible,
        QTextBlockUserData_PTR_CppToPython_QTextBlockUserData);

    Shiboken::Conversions::registerConverterName(converter, "QTextBlockUserData");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlockUserData*");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlockUserData&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBlockUserData).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBlockUserDataWrapper).name());



}
