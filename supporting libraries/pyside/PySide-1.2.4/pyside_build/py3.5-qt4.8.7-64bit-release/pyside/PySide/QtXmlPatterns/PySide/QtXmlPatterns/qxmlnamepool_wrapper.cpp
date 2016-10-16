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
#include "pyside_qtxmlpatterns_python.h"

#include "qxmlnamepool_wrapper.h"

// Extra includes
#include <qxmlnamepool.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlNamePool_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlNamePool >()))
        return -1;

    ::QXmlNamePool* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlNamePool", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlNamePool()
    // 1: QXmlNamePool(QXmlNamePool)
    if (numArgs == 0) {
        overloadId = 0; // QXmlNamePool()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlNamePool(QXmlNamePool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamePool_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlNamePool()
        {

            if (!PyErr_Occurred()) {
                // QXmlNamePool()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlNamePool();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlNamePool(const QXmlNamePool & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlNamePool cppArg0_local = ::QXmlNamePool();
            ::QXmlNamePool* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlNamePool(QXmlNamePool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlNamePool(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlNamePool >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlNamePool_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlNamePool_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QXmlNamePool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlNamePool", overloads);
        return -1;
}

static PyObject* Sbk_QXmlNamePool___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlNamePool& cppSelf = *(((::QXmlNamePool*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlNamePool_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QXmlNamePool___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlNamePool_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlNamePool_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlNamePool_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlNamePool",
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
    /*tp_traverse*/         Sbk_QXmlNamePool_traverse,
    /*tp_clear*/            Sbk_QXmlNamePool_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlNamePool_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlNamePool_Init,
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
static void QXmlNamePool_PythonToCpp_QXmlNamePool_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlNamePool_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlNamePool_PythonToCpp_QXmlNamePool_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlNamePool_Type))
        return QXmlNamePool_PythonToCpp_QXmlNamePool_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlNamePool_PTR_CppToPython_QXmlNamePool(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlNamePool*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlNamePool_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlNamePool_COPY_CppToPython_QXmlNamePool(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlNamePool_Type, new ::QXmlNamePool(*((::QXmlNamePool*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlNamePool_PythonToCpp_QXmlNamePool_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlNamePool*)cppOut) = *((::QXmlNamePool*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlNamePool_PythonToCpp_QXmlNamePool_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlNamePool_Type))
        return QXmlNamePool_PythonToCpp_QXmlNamePool_COPY;
    return 0;
}

void init_QXmlNamePool(PyObject* module)
{
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAMEPOOL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlNamePool_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlNamePool", "QXmlNamePool",
        &Sbk_QXmlNamePool_Type, &Shiboken::callCppDestructor< ::QXmlNamePool >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlNamePool_Type,
        QXmlNamePool_PythonToCpp_QXmlNamePool_PTR,
        is_QXmlNamePool_PythonToCpp_QXmlNamePool_PTR_Convertible,
        QXmlNamePool_PTR_CppToPython_QXmlNamePool,
        QXmlNamePool_COPY_CppToPython_QXmlNamePool);

    Shiboken::Conversions::registerConverterName(converter, "QXmlNamePool");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNamePool*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNamePool&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlNamePool).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlNamePool_PythonToCpp_QXmlNamePool_COPY,
        is_QXmlNamePool_PythonToCpp_QXmlNamePool_COPY_Convertible);


    qRegisterMetaType< ::QXmlNamePool >("QXmlNamePool");
}
