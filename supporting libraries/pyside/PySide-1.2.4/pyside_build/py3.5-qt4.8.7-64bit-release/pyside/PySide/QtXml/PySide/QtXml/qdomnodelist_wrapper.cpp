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

#include "qdomnodelist_wrapper.h"

// Extra includes
#include <qdom.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomNodeList_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomNodeList >()))
        return -1;

    ::QDomNodeList* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomNodeList", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomNodeList()
    // 1: QDomNodeList(QDomNodeList)
    if (numArgs == 0) {
        overloadId = 0; // QDomNodeList()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomNodeList(QDomNodeList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeList_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomNodeList()
        {

            if (!PyErr_Occurred()) {
                // QDomNodeList()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNodeList();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomNodeList(const QDomNodeList & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomNodeList cppArg0_local = ::QDomNodeList();
            ::QDomNodeList* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomNodeList(QDomNodeList)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNodeList(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomNodeList >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomNodeList_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomNodeList_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomNodeList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNodeList", overloads);
        return -1;
}

static PyObject* Sbk_QDomNodeListFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: at(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // at(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeListFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeListFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNodeList.at", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeListFunc_count(PyObject* self)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->count();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeListFunc_isEmpty(PyObject* self)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QDomNodeListFunc_item(PyObject* self, PyObject* pyArg)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: item(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // item(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeListFunc_item_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // item(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->item(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeListFunc_item_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNodeList.item", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeListFunc_length(PyObject* self)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->length();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeListFunc_size(PyObject* self)
{
    ::QDomNodeList* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNodeList*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeList___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNodeList& cppSelf = *(((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomNodeList_methods[] = {
    {"at", (PyCFunction)Sbk_QDomNodeListFunc_at, METH_O},
    {"count", (PyCFunction)Sbk_QDomNodeListFunc_count, METH_NOARGS},
    {"isEmpty", (PyCFunction)Sbk_QDomNodeListFunc_isEmpty, METH_NOARGS},
    {"item", (PyCFunction)Sbk_QDomNodeListFunc_item, METH_O},
    {"length", (PyCFunction)Sbk_QDomNodeListFunc_length, METH_NOARGS},
    {"size", (PyCFunction)Sbk_QDomNodeListFunc_size, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomNodeList___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QDomNodeList_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNodeList& cppSelf = *(((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (pyArg)))) {
                // operator!=(const QDomNodeList & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNodeList cppArg0_local = ::QDomNodeList();
                ::QDomNodeList* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (pyArg)))) {
                // operator==(const QDomNodeList & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNodeList cppArg0_local = ::QDomNodeList();
                ::QDomNodeList* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], pythonToCpp))
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
            goto Sbk_QDomNodeList_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDomNodeList_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDomNodeList_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomNodeList_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDomNodeList_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomNodeList",
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
    /*tp_traverse*/         Sbk_QDomNodeList_traverse,
    /*tp_clear*/            Sbk_QDomNodeList_clear,
    /*tp_richcompare*/      Sbk_QDomNodeList_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomNodeList_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomNodeList_Init,
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
static void QDomNodeList_PythonToCpp_QDomNodeList_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomNodeList_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomNodeList_PythonToCpp_QDomNodeList_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNodeList_Type))
        return QDomNodeList_PythonToCpp_QDomNodeList_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomNodeList_PTR_CppToPython_QDomNodeList(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomNodeList*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomNodeList_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomNodeList_COPY_CppToPython_QDomNodeList(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomNodeList_Type, new ::QDomNodeList(*((::QDomNodeList*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomNodeList_PythonToCpp_QDomNodeList_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomNodeList*)cppOut) = *((::QDomNodeList*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomNodeList_PythonToCpp_QDomNodeList_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNodeList_Type))
        return QDomNodeList_PythonToCpp_QDomNodeList_COPY;
    return 0;
}

void init_QDomNodeList(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomNodeList_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomNodeList", "QDomNodeList",
        &Sbk_QDomNodeList_Type, &Shiboken::callCppDestructor< ::QDomNodeList >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomNodeList_Type,
        QDomNodeList_PythonToCpp_QDomNodeList_PTR,
        is_QDomNodeList_PythonToCpp_QDomNodeList_PTR_Convertible,
        QDomNodeList_PTR_CppToPython_QDomNodeList,
        QDomNodeList_COPY_CppToPython_QDomNodeList);

    Shiboken::Conversions::registerConverterName(converter, "QDomNodeList");
    Shiboken::Conversions::registerConverterName(converter, "QDomNodeList*");
    Shiboken::Conversions::registerConverterName(converter, "QDomNodeList&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomNodeList).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomNodeList_PythonToCpp_QDomNodeList_COPY,
        is_QDomNodeList_PythonToCpp_QDomNodeList_COPY_Convertible);


    qRegisterMetaType< ::QDomNodeList >("QDomNodeList");
}
