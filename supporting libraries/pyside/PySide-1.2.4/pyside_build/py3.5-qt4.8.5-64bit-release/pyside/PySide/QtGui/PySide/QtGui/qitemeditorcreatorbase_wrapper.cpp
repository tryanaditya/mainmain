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

#include "qitemeditorcreatorbase_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QItemEditorCreatorBaseWrapper::QItemEditorCreatorBaseWrapper() : QItemEditorCreatorBase() {
    // ... middle
}

QWidget * QItemEditorCreatorBaseWrapper::createWidget(QWidget * parent) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createWidget"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QItemEditorCreatorBase.createWidget()' not implemented.");
        return ((::QWidget*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], parent)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemEditorCreatorBase.createWidget", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QByteArray QItemEditorCreatorBaseWrapper::valuePropertyName() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QByteArray();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "valuePropertyName"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QItemEditorCreatorBase.valuePropertyName()' not implemented.");
        return ::QByteArray();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QByteArray();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemEditorCreatorBase.valuePropertyName", Shiboken::SbkType< QByteArray >()->tp_name, pyResult->ob_type->tp_name);
        return ::QByteArray();
    }
    ::QByteArray cppResult = ::QByteArray();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QItemEditorCreatorBaseWrapper::~QItemEditorCreatorBaseWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QItemEditorCreatorBase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QITEMEDITORCREATORBASE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QItemEditorCreatorBase' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QItemEditorCreatorBase >()))
        return -1;

    ::QItemEditorCreatorBaseWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QItemEditorCreatorBase()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QItemEditorCreatorBaseWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QItemEditorCreatorBase >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QItemEditorCreatorBaseFunc_createWidget(PyObject* self, PyObject* pyArg)
{
    ::QItemEditorCreatorBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemEditorCreatorBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMEDITORCREATORBASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createWidget(QWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // createWidget(QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemEditorCreatorBaseFunc_createWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createWidget(QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QItemEditorCreatorBase.createWidget()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QItemEditorCreatorBase*>(cppSelf)->createWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemEditorCreatorBaseFunc_createWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemEditorCreatorBase.createWidget", overloads);
        return 0;
}

static PyObject* Sbk_QItemEditorCreatorBaseFunc_valuePropertyName(PyObject* self)
{
    ::QItemEditorCreatorBase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemEditorCreatorBase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMEDITORCREATORBASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // valuePropertyName()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QItemEditorCreatorBase.valuePropertyName()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QItemEditorCreatorBase*>(cppSelf)->valuePropertyName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QItemEditorCreatorBase_methods[] = {
    {"createWidget", (PyCFunction)Sbk_QItemEditorCreatorBaseFunc_createWidget, METH_O},
    {"valuePropertyName", (PyCFunction)Sbk_QItemEditorCreatorBaseFunc_valuePropertyName, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QItemEditorCreatorBase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QItemEditorCreatorBase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QItemEditorCreatorBase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QItemEditorCreatorBase",
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
    /*tp_traverse*/         Sbk_QItemEditorCreatorBase_traverse,
    /*tp_clear*/            Sbk_QItemEditorCreatorBase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QItemEditorCreatorBase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QItemEditorCreatorBase_Init,
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
static void QItemEditorCreatorBase_PythonToCpp_QItemEditorCreatorBase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QItemEditorCreatorBase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QItemEditorCreatorBase_PythonToCpp_QItemEditorCreatorBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemEditorCreatorBase_Type))
        return QItemEditorCreatorBase_PythonToCpp_QItemEditorCreatorBase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QItemEditorCreatorBase_PTR_CppToPython_QItemEditorCreatorBase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QItemEditorCreatorBase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QItemEditorCreatorBase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QItemEditorCreatorBase(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QITEMEDITORCREATORBASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QItemEditorCreatorBase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QItemEditorCreatorBase", "QItemEditorCreatorBase*",
        &Sbk_QItemEditorCreatorBase_Type, &Shiboken::callCppDestructor< ::QItemEditorCreatorBase >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QItemEditorCreatorBase_Type,
        QItemEditorCreatorBase_PythonToCpp_QItemEditorCreatorBase_PTR,
        is_QItemEditorCreatorBase_PythonToCpp_QItemEditorCreatorBase_PTR_Convertible,
        QItemEditorCreatorBase_PTR_CppToPython_QItemEditorCreatorBase);

    Shiboken::Conversions::registerConverterName(converter, "QItemEditorCreatorBase");
    Shiboken::Conversions::registerConverterName(converter, "QItemEditorCreatorBase*");
    Shiboken::Conversions::registerConverterName(converter, "QItemEditorCreatorBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemEditorCreatorBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemEditorCreatorBaseWrapper).name());



}
