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

#include "qdomdocumentfragment_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomDocumentFragment_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomDocumentFragment >()))
        return -1;

    ::QDomDocumentFragment* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomDocumentFragment", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomDocumentFragment()
    // 1: QDomDocumentFragment(QDomDocumentFragment)
    if (numArgs == 0) {
        overloadId = 0; // QDomDocumentFragment()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomDocumentFragment(QDomDocumentFragment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFragment_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomDocumentFragment()
        {

            if (!PyErr_Occurred()) {
                // QDomDocumentFragment()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocumentFragment();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomDocumentFragment(const QDomDocumentFragment & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomDocumentFragment cppArg0_local = ::QDomDocumentFragment();
            ::QDomDocumentFragment* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomDocumentFragment(QDomDocumentFragment)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocumentFragment(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomDocumentFragment >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomDocumentFragment_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomDocumentFragment_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomDocumentFragment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocumentFragment", overloads);
        return -1;
}

static PyObject* Sbk_QDomDocumentFragmentFunc_nodeType(PyObject* self)
{
    ::QDomDocumentFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomDocumentFragment*>(cppSelf)->nodeType();
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

static PyObject* Sbk_QDomDocumentFragment___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomDocumentFragment& cppSelf = *(((::QDomDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomDocumentFragment_methods[] = {
    {"nodeType", (PyCFunction)Sbk_QDomDocumentFragmentFunc_nodeType, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomDocumentFragment___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomDocumentFragment___nb_bool(PyObject* self)
{
    ::QDomDocumentFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomDocumentFragment_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomDocumentFragment_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomDocumentFragment_TypeAsNumber;

static SbkObjectType Sbk_QDomDocumentFragment_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomDocumentFragment",
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
    /*tp_traverse*/         Sbk_QDomDocumentFragment_traverse,
    /*tp_clear*/            Sbk_QDomDocumentFragment_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomDocumentFragment_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomDocumentFragment_Init,
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
static void QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomDocumentFragment_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomDocumentFragment_Type))
        return QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomDocumentFragment_PTR_CppToPython_QDomDocumentFragment(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomDocumentFragment*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomDocumentFragment_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomDocumentFragment_COPY_CppToPython_QDomDocumentFragment(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomDocumentFragment_Type, new ::QDomDocumentFragment(*((::QDomDocumentFragment*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomDocumentFragment*)cppOut) = *((::QDomDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomDocumentFragment_Type))
        return QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_COPY;
    return 0;
}

void init_QDomDocumentFragment(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomDocumentFragment_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomDocumentFragment_TypeAsNumber) = Sbk_QDomDocumentFragment___nb_bool;
    Sbk_QDomDocumentFragment_Type.super.ht_type.tp_as_number = &Sbk_QDomDocumentFragment_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomDocumentFragment_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomDocumentFragment", "QDomDocumentFragment",
        &Sbk_QDomDocumentFragment_Type, &Shiboken::callCppDestructor< ::QDomDocumentFragment >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomDocumentFragment_Type,
        QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_PTR,
        is_QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_PTR_Convertible,
        QDomDocumentFragment_PTR_CppToPython_QDomDocumentFragment,
        QDomDocumentFragment_COPY_CppToPython_QDomDocumentFragment);

    Shiboken::Conversions::registerConverterName(converter, "QDomDocumentFragment");
    Shiboken::Conversions::registerConverterName(converter, "QDomDocumentFragment*");
    Shiboken::Conversions::registerConverterName(converter, "QDomDocumentFragment&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomDocumentFragment).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_COPY,
        is_QDomDocumentFragment_PythonToCpp_QDomDocumentFragment_COPY_Convertible);


    qRegisterMetaType< ::QDomDocumentFragment >("QDomDocumentFragment");
}
