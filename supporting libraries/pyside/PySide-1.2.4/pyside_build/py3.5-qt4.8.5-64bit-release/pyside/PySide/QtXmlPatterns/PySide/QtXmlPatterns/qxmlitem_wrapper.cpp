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

#include "qxmlitem_wrapper.h"

// Extra includes
#include <qabstractxmlnodemodel.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlItem >()))
        return -1;

    ::QXmlItem* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlItem", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlItem()
    // 1: QXmlItem(QVariant)
    // 2: QXmlItem(QXmlItem)
    // 3: QXmlItem(QXmlNodeModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // QXmlItem()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 3; // QXmlItem(QXmlNodeModelIndex)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlItem(QVariant)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (pyArgs[0])))) {
        overloadId = 2; // QXmlItem(QXmlItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlItem()
        {

            if (!PyErr_Occurred()) {
                // QXmlItem()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlItem();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlItem(const QVariant & atomicValue)
        {
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlItem(QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlItem(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QXmlItem(const QXmlItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlItem cppArg0_local = ::QXmlItem();
            ::QXmlItem* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlItem(QXmlItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlItem(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QXmlItem(const QXmlNodeModelIndex & node)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
            ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlItem(QXmlNodeModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlItem(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlItem_Init_TypeError:
        const char* overloads[] = {"", "QVariant", "PySide.QtXmlPatterns.QXmlItem", "PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlItem", overloads);
        return -1;
}

static PyObject* Sbk_QXmlItemFunc_isAtomicValue(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAtomicValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlItem*>(cppSelf)->isAtomicValue();
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

static PyObject* Sbk_QXmlItemFunc_isNode(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlItem*>(cppSelf)->isNode();
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

static PyObject* Sbk_QXmlItemFunc_isNull(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlItem*>(cppSelf)->isNull();
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

static PyObject* Sbk_QXmlItemFunc_toAtomicValue(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toAtomicValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QXmlItem*>(cppSelf)->toAtomicValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlItemFunc_toNodeModelIndex(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toNodeModelIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex cppResult = const_cast<const ::QXmlItem*>(cppSelf)->toNodeModelIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlItem___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlItem& cppSelf = *(((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlItem_methods[] = {
    {"isAtomicValue", (PyCFunction)Sbk_QXmlItemFunc_isAtomicValue, METH_NOARGS},
    {"isNode", (PyCFunction)Sbk_QXmlItemFunc_isNode, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QXmlItemFunc_isNull, METH_NOARGS},
    {"toAtomicValue", (PyCFunction)Sbk_QXmlItemFunc_toAtomicValue, METH_NOARGS},
    {"toNodeModelIndex", (PyCFunction)Sbk_QXmlItemFunc_toNodeModelIndex, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlItem___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QXmlItem___nb_bool(PyObject* self)
{
    ::QXmlItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QXmlItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QXmlItem_TypeAsNumber;

static SbkObjectType Sbk_QXmlItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlItem",
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
    /*tp_traverse*/         Sbk_QXmlItem_traverse,
    /*tp_clear*/            Sbk_QXmlItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlItem_Init,
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
static void QXmlItem_PythonToCpp_QXmlItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlItem_PythonToCpp_QXmlItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlItem_Type))
        return QXmlItem_PythonToCpp_QXmlItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlItem_PTR_CppToPython_QXmlItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlItem_COPY_CppToPython_QXmlItem(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlItem_Type, new ::QXmlItem(*((::QXmlItem*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlItem_PythonToCpp_QXmlItem_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlItem*)cppOut) = *((::QXmlItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlItem_PythonToCpp_QXmlItem_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlItem_Type))
        return QXmlItem_PythonToCpp_QXmlItem_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQVariantREF_PythonToCpp_QXmlItem(PyObject* pyIn, void* cppOut) {
    ::QVariant cppIn = ::QVariant();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn, &cppIn);
    *((::QXmlItem*)cppOut) = ::QXmlItem(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQVariantREF_PythonToCpp_QXmlItem_Convertible(PyObject* pyIn) {
    if (PyObject_Check(pyIn))
        return PySide_QtCore_constQVariantREF_PythonToCpp_QXmlItem;
    return 0;
}

static void constQXmlNodeModelIndexREF_PythonToCpp_QXmlItem(PyObject* pyIn, void* cppOut) {
    *((::QXmlItem*)cppOut) = ::QXmlItem(*((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQXmlNodeModelIndexREF_PythonToCpp_QXmlItem_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyIn))
        return constQXmlNodeModelIndexREF_PythonToCpp_QXmlItem;
    return 0;
}

void init_QXmlItem(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QXmlItem_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QXmlItem_TypeAsNumber) = Sbk_QXmlItem___nb_bool;
    Sbk_QXmlItem_Type.super.ht_type.tp_as_number = &Sbk_QXmlItem_TypeAsNumber;

    SbkPySide_QtXmlPatternsTypes[SBK_QXMLITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlItem", "QXmlItem",
        &Sbk_QXmlItem_Type, &Shiboken::callCppDestructor< ::QXmlItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlItem_Type,
        QXmlItem_PythonToCpp_QXmlItem_PTR,
        is_QXmlItem_PythonToCpp_QXmlItem_PTR_Convertible,
        QXmlItem_PTR_CppToPython_QXmlItem,
        QXmlItem_COPY_CppToPython_QXmlItem);

    Shiboken::Conversions::registerConverterName(converter, "QXmlItem");
    Shiboken::Conversions::registerConverterName(converter, "QXmlItem*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlItem).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlItem_PythonToCpp_QXmlItem_COPY,
        is_QXmlItem_PythonToCpp_QXmlItem_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQVariantREF_PythonToCpp_QXmlItem,
        is_PySide_QtCore_constQVariantREF_PythonToCpp_QXmlItem_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQXmlNodeModelIndexREF_PythonToCpp_QXmlItem,
        is_constQXmlNodeModelIndexREF_PythonToCpp_QXmlItem_Convertible);


    qRegisterMetaType< ::QXmlItem >("QXmlItem");
}
