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

#include "qdomattr_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomAttr_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomAttr >()))
        return -1;

    ::QDomAttr* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomAttr", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomAttr()
    // 1: QDomAttr(QDomAttr)
    if (numArgs == 0) {
        overloadId = 0; // QDomAttr()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomAttr(QDomAttr)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomAttr_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomAttr()
        {

            if (!PyErr_Occurred()) {
                // QDomAttr()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomAttr();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomAttr(const QDomAttr & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomAttr cppArg0_local = ::QDomAttr();
            ::QDomAttr* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomAttr(QDomAttr)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomAttr(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomAttr >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomAttr_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomAttr_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomAttr", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomAttr", overloads);
        return -1;
}

static PyObject* Sbk_QDomAttrFunc_name(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomAttr*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomAttrFunc_nodeType(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomAttr*>(cppSelf)->nodeType();
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

static PyObject* Sbk_QDomAttrFunc_ownerElement(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownerElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomAttr*>(cppSelf)->ownerElement();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomAttrFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomAttrFunc_setValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomAttrFunc_setValue_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomAttr.setValue", overloads);
        return 0;
}

static PyObject* Sbk_QDomAttrFunc_specified(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // specified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomAttr*>(cppSelf)->specified();
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

static PyObject* Sbk_QDomAttrFunc_value(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomAttr*>(cppSelf)->value();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomAttr___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomAttr& cppSelf = *(((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomAttr_methods[] = {
    {"name", (PyCFunction)Sbk_QDomAttrFunc_name, METH_NOARGS},
    {"nodeType", (PyCFunction)Sbk_QDomAttrFunc_nodeType, METH_NOARGS},
    {"ownerElement", (PyCFunction)Sbk_QDomAttrFunc_ownerElement, METH_NOARGS},
    {"setValue", (PyCFunction)Sbk_QDomAttrFunc_setValue, METH_O},
    {"specified", (PyCFunction)Sbk_QDomAttrFunc_specified, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QDomAttrFunc_value, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomAttr___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomAttr___nb_bool(PyObject* self)
{
    ::QDomAttr* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomAttr_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomAttr_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomAttr_TypeAsNumber;

static SbkObjectType Sbk_QDomAttr_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomAttr",
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
    /*tp_traverse*/         Sbk_QDomAttr_traverse,
    /*tp_clear*/            Sbk_QDomAttr_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomAttr_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomAttr_Init,
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
static void QDomAttr_PythonToCpp_QDomAttr_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomAttr_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomAttr_PythonToCpp_QDomAttr_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomAttr_Type))
        return QDomAttr_PythonToCpp_QDomAttr_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomAttr_PTR_CppToPython_QDomAttr(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomAttr*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomAttr_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomAttr_COPY_CppToPython_QDomAttr(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomAttr_Type, new ::QDomAttr(*((::QDomAttr*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomAttr_PythonToCpp_QDomAttr_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomAttr*)cppOut) = *((::QDomAttr*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomAttr_PythonToCpp_QDomAttr_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomAttr_Type))
        return QDomAttr_PythonToCpp_QDomAttr_COPY;
    return 0;
}

void init_QDomAttr(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomAttr_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomAttr_TypeAsNumber) = Sbk_QDomAttr___nb_bool;
    Sbk_QDomAttr_Type.super.ht_type.tp_as_number = &Sbk_QDomAttr_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomAttr_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomAttr", "QDomAttr",
        &Sbk_QDomAttr_Type, &Shiboken::callCppDestructor< ::QDomAttr >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomAttr_Type,
        QDomAttr_PythonToCpp_QDomAttr_PTR,
        is_QDomAttr_PythonToCpp_QDomAttr_PTR_Convertible,
        QDomAttr_PTR_CppToPython_QDomAttr,
        QDomAttr_COPY_CppToPython_QDomAttr);

    Shiboken::Conversions::registerConverterName(converter, "QDomAttr");
    Shiboken::Conversions::registerConverterName(converter, "QDomAttr*");
    Shiboken::Conversions::registerConverterName(converter, "QDomAttr&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomAttr).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomAttr_PythonToCpp_QDomAttr_COPY,
        is_QDomAttr_PythonToCpp_QDomAttr_COPY_Convertible);


    qRegisterMetaType< ::QDomAttr >("QDomAttr");
}
