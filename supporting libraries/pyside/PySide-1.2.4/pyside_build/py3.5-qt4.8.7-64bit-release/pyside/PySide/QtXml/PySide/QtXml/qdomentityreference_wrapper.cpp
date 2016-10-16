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
#include "pyside_qtxml_python.h"

#include "qdomentityreference_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomEntityReference_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomEntityReference >()))
        return -1;

    ::QDomEntityReference* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomEntityReference", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomEntityReference()
    // 1: QDomEntityReference(QDomEntityReference)
    if (numArgs == 0) {
        overloadId = 0; // QDomEntityReference()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomEntityReference(QDomEntityReference)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomEntityReference_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomEntityReference()
        {

            if (!PyErr_Occurred()) {
                // QDomEntityReference()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomEntityReference();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomEntityReference(const QDomEntityReference & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomEntityReference cppArg0_local = ::QDomEntityReference();
            ::QDomEntityReference* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomEntityReference(QDomEntityReference)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomEntityReference(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomEntityReference >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomEntityReference_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomEntityReference_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomEntityReference", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomEntityReference", overloads);
        return -1;
}

static PyObject* Sbk_QDomEntityReferenceFunc_nodeType(PyObject* self)
{
    ::QDomEntityReference* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomEntityReference*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomEntityReference*>(cppSelf)->nodeType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomEntityReference___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomEntityReference& cppSelf = *(((::QDomEntityReference*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomEntityReference_methods[] = {
    {"nodeType", (PyCFunction)Sbk_QDomEntityReferenceFunc_nodeType, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomEntityReference___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomEntityReference___nb_bool(PyObject* self)
{
    ::QDomEntityReference* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomEntityReference*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomEntityReference_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomEntityReference_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomEntityReference_TypeAsNumber;

static SbkObjectType Sbk_QDomEntityReference_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomEntityReference",
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
    /*tp_traverse*/         Sbk_QDomEntityReference_traverse,
    /*tp_clear*/            Sbk_QDomEntityReference_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomEntityReference_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomEntityReference_Init,
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
static void QDomEntityReference_PythonToCpp_QDomEntityReference_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomEntityReference_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomEntityReference_PythonToCpp_QDomEntityReference_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomEntityReference_Type))
        return QDomEntityReference_PythonToCpp_QDomEntityReference_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomEntityReference_PTR_CppToPython_QDomEntityReference(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomEntityReference*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomEntityReference_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomEntityReference_COPY_CppToPython_QDomEntityReference(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomEntityReference_Type, new ::QDomEntityReference(*((::QDomEntityReference*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomEntityReference_PythonToCpp_QDomEntityReference_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomEntityReference*)cppOut) = *((::QDomEntityReference*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomEntityReference_PythonToCpp_QDomEntityReference_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomEntityReference_Type))
        return QDomEntityReference_PythonToCpp_QDomEntityReference_COPY;
    return 0;
}

void init_QDomEntityReference(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomEntityReference_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomEntityReference_TypeAsNumber) = Sbk_QDomEntityReference___nb_bool;
    Sbk_QDomEntityReference_Type.super.ht_type.tp_as_number = &Sbk_QDomEntityReference_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomEntityReference_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomEntityReference", "QDomEntityReference",
        &Sbk_QDomEntityReference_Type, &Shiboken::callCppDestructor< ::QDomEntityReference >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomEntityReference_Type,
        QDomEntityReference_PythonToCpp_QDomEntityReference_PTR,
        is_QDomEntityReference_PythonToCpp_QDomEntityReference_PTR_Convertible,
        QDomEntityReference_PTR_CppToPython_QDomEntityReference,
        QDomEntityReference_COPY_CppToPython_QDomEntityReference);

    Shiboken::Conversions::registerConverterName(converter, "QDomEntityReference");
    Shiboken::Conversions::registerConverterName(converter, "QDomEntityReference*");
    Shiboken::Conversions::registerConverterName(converter, "QDomEntityReference&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomEntityReference).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomEntityReference_PythonToCpp_QDomEntityReference_COPY,
        is_QDomEntityReference_PythonToCpp_QDomEntityReference_COPY_Convertible);


    qRegisterMetaType< ::QDomEntityReference >("QDomEntityReference");
}
