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

#include "qxmlnodemodelindex_wrapper.h"

// Extra includes
#include <qabstractxmlnodemodel.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlNodeModelIndex_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlNodeModelIndex >()))
        return -1;

    ::QXmlNodeModelIndex* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlNodeModelIndex", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlNodeModelIndex()
    // 1: QXmlNodeModelIndex(QXmlNodeModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // QXmlNodeModelIndex()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlNodeModelIndex(QXmlNodeModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNodeModelIndex_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlNodeModelIndex()
        {

            if (!PyErr_Occurred()) {
                // QXmlNodeModelIndex()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlNodeModelIndex();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlNodeModelIndex(const QXmlNodeModelIndex & other)
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
                // QXmlNodeModelIndex(QXmlNodeModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlNodeModelIndex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlNodeModelIndex >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlNodeModelIndex_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlNodeModelIndex_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QXmlNodeModelIndex", overloads);
        return -1;
}

static PyObject* Sbk_QXmlNodeModelIndexFunc_additionalData(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // additionalData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QXmlNodeModelIndex*>(cppSelf)->additionalData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlNodeModelIndexFunc_data(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QXmlNodeModelIndex*>(cppSelf)->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlNodeModelIndexFunc_internalPointer(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // internalPointer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * cppResult = const_cast<const ::QXmlNodeModelIndex*>(cppSelf)->internalPointer();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlNodeModelIndexFunc_isNull(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlNodeModelIndex*>(cppSelf)->isNull();
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

static PyObject* Sbk_QXmlNodeModelIndexFunc_model(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractXmlNodeModel * cppResult = const_cast<const ::QXmlNodeModelIndex*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlNodeModelIndex___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlNodeModelIndex& cppSelf = *(((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlNodeModelIndex_methods[] = {
    {"additionalData", (PyCFunction)Sbk_QXmlNodeModelIndexFunc_additionalData, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QXmlNodeModelIndexFunc_data, METH_NOARGS},
    {"internalPointer", (PyCFunction)Sbk_QXmlNodeModelIndexFunc_internalPointer, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QXmlNodeModelIndexFunc_isNull, METH_NOARGS},
    {"model", (PyCFunction)Sbk_QXmlNodeModelIndexFunc_model, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlNodeModelIndex___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QXmlNodeModelIndex___nb_bool(PyObject* self)
{
    ::QXmlNodeModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QXmlNodeModelIndex_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlNodeModelIndex& cppSelf = *(((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
                // operator!=(const QXmlNodeModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
                ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
                // operator==(const QXmlNodeModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
                ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QXmlNodeModelIndex_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlNodeModelIndex_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlNodeModelIndex_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlNodeModelIndex_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QXmlNodeModelIndex_TypeAsNumber;

static SbkObjectType Sbk_QXmlNodeModelIndex_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QXmlNodeModelIndex",
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
    /*tp_traverse*/         Sbk_QXmlNodeModelIndex_traverse,
    /*tp_clear*/            Sbk_QXmlNodeModelIndex_clear,
    /*tp_richcompare*/      Sbk_QXmlNodeModelIndex_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlNodeModelIndex_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlNodeModelIndex_Init,
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

// Python to C++ enum conversion.
static void QXmlNodeModelIndex_NodeKind_PythonToCpp_QXmlNodeModelIndex_NodeKind(PyObject* pyIn, void* cppOut) {
    *((::QXmlNodeModelIndex::NodeKind*)cppOut) = (::QXmlNodeModelIndex::NodeKind) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlNodeModelIndex_NodeKind_PythonToCpp_QXmlNodeModelIndex_NodeKind_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX]))
        return QXmlNodeModelIndex_NodeKind_PythonToCpp_QXmlNodeModelIndex_NodeKind;
    return 0;
}
static PyObject* QXmlNodeModelIndex_NodeKind_CppToPython_QXmlNodeModelIndex_NodeKind(const void* cppIn) {
    int castCppIn = *((::QXmlNodeModelIndex::NodeKind*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX], castCppIn);

}

static void QXmlNodeModelIndex_DocumentOrder_PythonToCpp_QXmlNodeModelIndex_DocumentOrder(PyObject* pyIn, void* cppOut) {
    *((::QXmlNodeModelIndex::DocumentOrder*)cppOut) = (::QXmlNodeModelIndex::DocumentOrder) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QXmlNodeModelIndex_DocumentOrder_PythonToCpp_QXmlNodeModelIndex_DocumentOrder_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX]))
        return QXmlNodeModelIndex_DocumentOrder_PythonToCpp_QXmlNodeModelIndex_DocumentOrder;
    return 0;
}
static PyObject* QXmlNodeModelIndex_DocumentOrder_CppToPython_QXmlNodeModelIndex_DocumentOrder(const void* cppIn) {
    int castCppIn = *((::QXmlNodeModelIndex::DocumentOrder*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlNodeModelIndex_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlNodeModelIndex_Type))
        return QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlNodeModelIndex_PTR_CppToPython_QXmlNodeModelIndex(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlNodeModelIndex*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlNodeModelIndex_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlNodeModelIndex_COPY_CppToPython_QXmlNodeModelIndex(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlNodeModelIndex_Type, new ::QXmlNodeModelIndex(*((::QXmlNodeModelIndex*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlNodeModelIndex*)cppOut) = *((::QXmlNodeModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlNodeModelIndex_Type))
        return QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_COPY;
    return 0;
}

void init_QXmlNodeModelIndex(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QXmlNodeModelIndex_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QXmlNodeModelIndex_TypeAsNumber) = Sbk_QXmlNodeModelIndex___nb_bool;
    Sbk_QXmlNodeModelIndex_Type.super.ht_type.tp_as_number = &Sbk_QXmlNodeModelIndex_TypeAsNumber;

    SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlNodeModelIndex_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlNodeModelIndex", "QXmlNodeModelIndex",
        &Sbk_QXmlNodeModelIndex_Type, &Shiboken::callCppDestructor< ::QXmlNodeModelIndex >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlNodeModelIndex_Type,
        QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_PTR,
        is_QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_PTR_Convertible,
        QXmlNodeModelIndex_PTR_CppToPython_QXmlNodeModelIndex,
        QXmlNodeModelIndex_COPY_CppToPython_QXmlNodeModelIndex);

    Shiboken::Conversions::registerConverterName(converter, "QXmlNodeModelIndex");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNodeModelIndex*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNodeModelIndex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlNodeModelIndex).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_COPY,
        is_QXmlNodeModelIndex_PythonToCpp_QXmlNodeModelIndex_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'NodeKind'.
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlNodeModelIndex_Type,
        "NodeKind",
        "PySide.QtXmlPatterns.QXmlNodeModelIndex.NodeKind",
        "QXmlNodeModelIndex::NodeKind");
    if (!SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Attribute", (long) QXmlNodeModelIndex::Attribute))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Comment", (long) QXmlNodeModelIndex::Comment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Document", (long) QXmlNodeModelIndex::Document))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Element", (long) QXmlNodeModelIndex::Element))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Namespace", (long) QXmlNodeModelIndex::Namespace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "ProcessingInstruction", (long) QXmlNodeModelIndex::ProcessingInstruction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Text", (long) QXmlNodeModelIndex::Text))
        return ;
    // Register converter for enum 'QXmlNodeModelIndex::NodeKind'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX],
            QXmlNodeModelIndex_NodeKind_CppToPython_QXmlNodeModelIndex_NodeKind);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlNodeModelIndex_NodeKind_PythonToCpp_QXmlNodeModelIndex_NodeKind,
            is_QXmlNodeModelIndex_NodeKind_PythonToCpp_QXmlNodeModelIndex_NodeKind_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlNodeModelIndex::NodeKind");
        Shiboken::Conversions::registerConverterName(converter, "NodeKind");
    }
    // End of 'NodeKind' enum.

    // Initialization of enum 'DocumentOrder'.
    SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QXmlNodeModelIndex_Type,
        "DocumentOrder",
        "PySide.QtXmlPatterns.QXmlNodeModelIndex.DocumentOrder",
        "QXmlNodeModelIndex::DocumentOrder");
    if (!SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Precedes", (long) QXmlNodeModelIndex::Precedes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Is", (long) QXmlNodeModelIndex::Is))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX],
        &Sbk_QXmlNodeModelIndex_Type, "Follows", (long) QXmlNodeModelIndex::Follows))
        return ;
    // Register converter for enum 'QXmlNodeModelIndex::DocumentOrder'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX],
            QXmlNodeModelIndex_DocumentOrder_CppToPython_QXmlNodeModelIndex_DocumentOrder);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QXmlNodeModelIndex_DocumentOrder_PythonToCpp_QXmlNodeModelIndex_DocumentOrder,
            is_QXmlNodeModelIndex_DocumentOrder_PythonToCpp_QXmlNodeModelIndex_DocumentOrder_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QXmlNodeModelIndex::DocumentOrder");
        Shiboken::Conversions::registerConverterName(converter, "DocumentOrder");
    }
    // End of 'DocumentOrder' enum.


    qRegisterMetaType< ::QXmlNodeModelIndex >("QXmlNodeModelIndex");
    qRegisterMetaType< ::QXmlNodeModelIndex::NodeKind >("QXmlNodeModelIndex::NodeKind");
    qRegisterMetaType< ::QXmlNodeModelIndex::DocumentOrder >("QXmlNodeModelIndex::DocumentOrder");
}
