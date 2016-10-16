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
#include "pyside_qthelp_python.h"

#include "qhelpcontentitem_wrapper.h"

// Extra includes
#include <qhelpcontentwidget.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QHelpContentItemFunc_child(PyObject* self, PyObject* pyArg)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: child(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // child(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpContentItemFunc_child_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // child(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHelpContentItem * cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->child(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHelpContentItemFunc_child_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtHelp.QHelpContentItem.child", overloads);
        return 0;
}

static PyObject* Sbk_QHelpContentItemFunc_childCount(PyObject* self)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->childCount();
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

static PyObject* Sbk_QHelpContentItemFunc_childPosition(PyObject* self, PyObject* pyArg)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: childPosition(QHelpContentItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (pyArg)))) {
        overloadId = 0; // childPosition(QHelpContentItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpContentItemFunc_childPosition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QHelpContentItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // childPosition(QHelpContentItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->childPosition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHelpContentItemFunc_childPosition_TypeError:
        const char* overloads[] = {"PySide.QtHelp.QHelpContentItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtHelp.QHelpContentItem.childPosition", overloads);
        return 0;
}

static PyObject* Sbk_QHelpContentItemFunc_parent(PyObject* self)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHelpContentItem * cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHelpContentItemFunc_row(PyObject* self)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // row()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->row();
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

static PyObject* Sbk_QHelpContentItemFunc_title(PyObject* self)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // title()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->title();
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

static PyObject* Sbk_QHelpContentItemFunc_url(PyObject* self)
{
    ::QHelpContentItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QHelpContentItem*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHelpContentItem___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHelpContentItem& cppSelf = *(((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHelpContentItem_methods[] = {
    {"child", (PyCFunction)Sbk_QHelpContentItemFunc_child, METH_O},
    {"childCount", (PyCFunction)Sbk_QHelpContentItemFunc_childCount, METH_NOARGS},
    {"childPosition", (PyCFunction)Sbk_QHelpContentItemFunc_childPosition, METH_O},
    {"parent", (PyCFunction)Sbk_QHelpContentItemFunc_parent, METH_NOARGS},
    {"row", (PyCFunction)Sbk_QHelpContentItemFunc_row, METH_NOARGS},
    {"title", (PyCFunction)Sbk_QHelpContentItemFunc_title, METH_NOARGS},
    {"url", (PyCFunction)Sbk_QHelpContentItemFunc_url, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QHelpContentItem___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QHelpContentItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHelpContentItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHelpContentItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtHelp.QHelpContentItem",
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
    /*tp_traverse*/         Sbk_QHelpContentItem_traverse,
    /*tp_clear*/            Sbk_QHelpContentItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHelpContentItem_methods,
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
static void QHelpContentItem_PythonToCpp_QHelpContentItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHelpContentItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHelpContentItem_PythonToCpp_QHelpContentItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHelpContentItem_Type))
        return QHelpContentItem_PythonToCpp_QHelpContentItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHelpContentItem_PTR_CppToPython_QHelpContentItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QHelpContentItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QHelpContentItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QHelpContentItem_COPY_CppToPython_QHelpContentItem(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QHelpContentItem_Type, new ::QHelpContentItem(*((::QHelpContentItem*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QHelpContentItem_PythonToCpp_QHelpContentItem_COPY(PyObject* pyIn, void* cppOut) {
    *((::QHelpContentItem*)cppOut) = *((::QHelpContentItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QHelpContentItem_PythonToCpp_QHelpContentItem_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHelpContentItem_Type))
        return QHelpContentItem_PythonToCpp_QHelpContentItem_COPY;
    return 0;
}

void init_QHelpContentItem(PyObject* module)
{
    SbkPySide_QtHelpTypes[SBK_QHELPCONTENTITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHelpContentItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHelpContentItem", "QHelpContentItem",
        &Sbk_QHelpContentItem_Type, &Shiboken::callCppDestructor< ::QHelpContentItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHelpContentItem_Type,
        QHelpContentItem_PythonToCpp_QHelpContentItem_PTR,
        is_QHelpContentItem_PythonToCpp_QHelpContentItem_PTR_Convertible,
        QHelpContentItem_PTR_CppToPython_QHelpContentItem,
        QHelpContentItem_COPY_CppToPython_QHelpContentItem);

    Shiboken::Conversions::registerConverterName(converter, "QHelpContentItem");
    Shiboken::Conversions::registerConverterName(converter, "QHelpContentItem*");
    Shiboken::Conversions::registerConverterName(converter, "QHelpContentItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHelpContentItem).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHelpContentItem_PythonToCpp_QHelpContentItem_COPY,
        is_QHelpContentItem_PythonToCpp_QHelpContentItem_COPY_Convertible);


}
