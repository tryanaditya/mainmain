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

#include "qfileiconprovider_wrapper.h"

// Extra includes
#include <qfileiconprovider.h>
#include <qfileinfo.h>
#include <qicon.h>


// Native ---------------------------------------------------------

QFileIconProviderWrapper::QFileIconProviderWrapper() : QFileIconProvider() {
    // ... middle
}

QIcon QFileIconProviderWrapper::icon(QFileIconProvider::IconType type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QIcon();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "icon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileIconProvider::icon(type);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QIcon();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileIconProvider.icon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon QFileIconProviderWrapper::icon(const QFileInfo & info) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QIcon();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "icon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileIconProvider::icon(info);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], &info)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QIcon();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileIconProvider.icon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QFileIconProviderWrapper::type(const QFileInfo & info) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "type"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileIconProvider::type(info);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], &info)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileIconProvider.type", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFileIconProviderWrapper::~QFileIconProviderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFileIconProvider_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFileIconProvider >()))
        return -1;

    ::QFileIconProviderWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QFileIconProvider()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QFileIconProviderWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFileIconProvider >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QFileIconProviderFunc_icon(PyObject* self, PyObject* pyArg)
{
    ::QFileIconProvider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileIconProvider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: icon(QFileIconProvider::IconType)const
    // 1: icon(QFileInfo)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], (pyArg)))) {
        overloadId = 1; // icon(QFileInfo)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // icon(QFileIconProvider::IconType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileIconProviderFunc_icon_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // icon(QFileIconProvider::IconType type) const
        {
            ::QFileIconProvider::IconType cppArg0 = ((::QFileIconProvider::IconType)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // icon(QFileIconProvider::IconType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QIcon cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileIconProvider*>(cppSelf)->::QFileIconProvider::icon(cppArg0) : const_cast<const ::QFileIconProvider*>(cppSelf)->icon(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
            }
            break;
        }
        case 1: // icon(const QFileInfo & info) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QFileInfo cppArg0_local = ::QFileInfo();
            ::QFileInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // icon(QFileInfo)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QIcon cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileIconProvider*>(cppSelf)->::QFileIconProvider::icon(*cppArg0) : const_cast<const ::QFileIconProvider*>(cppSelf)->icon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileIconProviderFunc_icon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileIconProvider.IconType", "PySide.QtCore.QFileInfo", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileIconProvider.icon", overloads);
        return 0;
}

static PyObject* Sbk_QFileIconProviderFunc_type(PyObject* self, PyObject* pyArg)
{
    ::QFileIconProvider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileIconProvider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: type(QFileInfo)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], (pyArg)))) {
        overloadId = 0; // type(QFileInfo)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileIconProviderFunc_type_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFileInfo cppArg0_local = ::QFileInfo();
        ::QFileInfo* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // type(QFileInfo)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFileIconProvider*>(cppSelf)->::QFileIconProvider::type(*cppArg0) : const_cast<const ::QFileIconProvider*>(cppSelf)->type(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileIconProviderFunc_type_TypeError:
        const char* overloads[] = {"PySide.QtCore.QFileInfo", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileIconProvider.type", overloads);
        return 0;
}

static PyMethodDef Sbk_QFileIconProvider_methods[] = {
    {"icon", (PyCFunction)Sbk_QFileIconProviderFunc_icon, METH_O},
    {"type", (PyCFunction)Sbk_QFileIconProviderFunc_type, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFileIconProvider_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFileIconProvider_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFileIconProvider_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFileIconProvider",
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
    /*tp_traverse*/         Sbk_QFileIconProvider_traverse,
    /*tp_clear*/            Sbk_QFileIconProvider_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFileIconProvider_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFileIconProvider_Init,
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
static void QFileIconProvider_IconType_PythonToCpp_QFileIconProvider_IconType(PyObject* pyIn, void* cppOut) {
    *((::QFileIconProvider::IconType*)cppOut) = (::QFileIconProvider::IconType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileIconProvider_IconType_PythonToCpp_QFileIconProvider_IconType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX]))
        return QFileIconProvider_IconType_PythonToCpp_QFileIconProvider_IconType;
    return 0;
}
static PyObject* QFileIconProvider_IconType_CppToPython_QFileIconProvider_IconType(const void* cppIn) {
    int castCppIn = *((::QFileIconProvider::IconType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFileIconProvider_PythonToCpp_QFileIconProvider_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFileIconProvider_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFileIconProvider_PythonToCpp_QFileIconProvider_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFileIconProvider_Type))
        return QFileIconProvider_PythonToCpp_QFileIconProvider_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFileIconProvider_PTR_CppToPython_QFileIconProvider(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFileIconProvider*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFileIconProvider_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QFileIconProvider(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFileIconProvider_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFileIconProvider", "QFileIconProvider*",
        &Sbk_QFileIconProvider_Type, &Shiboken::callCppDestructor< ::QFileIconProvider >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFileIconProvider_Type,
        QFileIconProvider_PythonToCpp_QFileIconProvider_PTR,
        is_QFileIconProvider_PythonToCpp_QFileIconProvider_PTR_Convertible,
        QFileIconProvider_PTR_CppToPython_QFileIconProvider);

    Shiboken::Conversions::registerConverterName(converter, "QFileIconProvider");
    Shiboken::Conversions::registerConverterName(converter, "QFileIconProvider*");
    Shiboken::Conversions::registerConverterName(converter, "QFileIconProvider&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileIconProvider).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileIconProviderWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'IconType'.
    SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileIconProvider_Type,
        "IconType",
        "PySide.QtGui.QFileIconProvider.IconType",
        "QFileIconProvider::IconType");
    if (!SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Computer", (long) QFileIconProvider::Computer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Desktop", (long) QFileIconProvider::Desktop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Trashcan", (long) QFileIconProvider::Trashcan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Network", (long) QFileIconProvider::Network))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Drive", (long) QFileIconProvider::Drive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "Folder", (long) QFileIconProvider::Folder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
        &Sbk_QFileIconProvider_Type, "File", (long) QFileIconProvider::File))
        return ;
    // Register converter for enum 'QFileIconProvider::IconType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX],
            QFileIconProvider_IconType_CppToPython_QFileIconProvider_IconType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileIconProvider_IconType_PythonToCpp_QFileIconProvider_IconType,
            is_QFileIconProvider_IconType_PythonToCpp_QFileIconProvider_IconType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_ICONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileIconProvider::IconType");
        Shiboken::Conversions::registerConverterName(converter, "IconType");
    }
    // End of 'IconType' enum.


    qRegisterMetaType< ::QFileIconProvider::IconType >("QFileIconProvider::IconType");
}
