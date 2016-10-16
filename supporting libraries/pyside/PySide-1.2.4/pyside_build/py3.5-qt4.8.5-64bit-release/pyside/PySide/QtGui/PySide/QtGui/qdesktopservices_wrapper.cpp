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

#include "qdesktopservices_wrapper.h"

// Extra includes
#include <qobject.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDesktopServices_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDesktopServices >()))
        return -1;

    ::QDesktopServices* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QDesktopServices()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDesktopServices();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDesktopServices >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QDesktopServicesFunc_displayName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: displayName(QDesktopServices::StandardLocation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX]), (pyArg)))) {
        overloadId = 0; // displayName(QDesktopServices::StandardLocation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDesktopServicesFunc_displayName_TypeError;

    // Call function/method
    {
        ::QDesktopServices::StandardLocation cppArg0 = ((::QDesktopServices::StandardLocation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // displayName(QDesktopServices::StandardLocation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDesktopServices::displayName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDesktopServicesFunc_displayName_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDesktopServices.StandardLocation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDesktopServices.displayName", overloads);
        return 0;
}

static PyObject* Sbk_QDesktopServicesFunc_openUrl(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: openUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // openUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDesktopServicesFunc_openUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // openUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QDesktopServices::openUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDesktopServicesFunc_openUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDesktopServices.openUrl", overloads);
        return 0;
}

static PyObject* Sbk_QDesktopServicesFunc_setUrlHandler(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setUrlHandler", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setUrlHandler(QString,QObject*,const char*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))
        && Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
        overloadId = 0; // setUrlHandler(QString,QObject*,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDesktopServicesFunc_setUrlHandler_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        const char* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setUrlHandler(QString,QObject*,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDesktopServices::setUrlHandler(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDesktopServicesFunc_setUrlHandler_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QObject, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDesktopServices.setUrlHandler", overloads);
        return 0;
}

static PyObject* Sbk_QDesktopServicesFunc_storageLocation(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: storageLocation(QDesktopServices::StandardLocation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX]), (pyArg)))) {
        overloadId = 0; // storageLocation(QDesktopServices::StandardLocation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDesktopServicesFunc_storageLocation_TypeError;

    // Call function/method
    {
        ::QDesktopServices::StandardLocation cppArg0 = ((::QDesktopServices::StandardLocation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // storageLocation(QDesktopServices::StandardLocation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDesktopServices::storageLocation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDesktopServicesFunc_storageLocation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDesktopServices.StandardLocation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDesktopServices.storageLocation", overloads);
        return 0;
}

static PyObject* Sbk_QDesktopServicesFunc_unsetUrlHandler(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unsetUrlHandler(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // unsetUrlHandler(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDesktopServicesFunc_unsetUrlHandler_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unsetUrlHandler(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDesktopServices::unsetUrlHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDesktopServicesFunc_unsetUrlHandler_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDesktopServices.unsetUrlHandler", overloads);
        return 0;
}

static PyMethodDef Sbk_QDesktopServices_methods[] = {
    {"displayName", (PyCFunction)Sbk_QDesktopServicesFunc_displayName, METH_O|METH_STATIC},
    {"openUrl", (PyCFunction)Sbk_QDesktopServicesFunc_openUrl, METH_O|METH_STATIC},
    {"setUrlHandler", (PyCFunction)Sbk_QDesktopServicesFunc_setUrlHandler, METH_VARARGS|METH_STATIC},
    {"storageLocation", (PyCFunction)Sbk_QDesktopServicesFunc_storageLocation, METH_O|METH_STATIC},
    {"unsetUrlHandler", (PyCFunction)Sbk_QDesktopServicesFunc_unsetUrlHandler, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDesktopServices_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDesktopServices_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDesktopServices_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDesktopServices",
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
    /*tp_traverse*/         Sbk_QDesktopServices_traverse,
    /*tp_clear*/            Sbk_QDesktopServices_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDesktopServices_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDesktopServices_Init,
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
static void QDesktopServices_StandardLocation_PythonToCpp_QDesktopServices_StandardLocation(PyObject* pyIn, void* cppOut) {
    *((::QDesktopServices::StandardLocation*)cppOut) = (::QDesktopServices::StandardLocation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDesktopServices_StandardLocation_PythonToCpp_QDesktopServices_StandardLocation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX]))
        return QDesktopServices_StandardLocation_PythonToCpp_QDesktopServices_StandardLocation;
    return 0;
}
static PyObject* QDesktopServices_StandardLocation_CppToPython_QDesktopServices_StandardLocation(const void* cppIn) {
    int castCppIn = *((::QDesktopServices::StandardLocation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDesktopServices_PythonToCpp_QDesktopServices_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDesktopServices_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDesktopServices_PythonToCpp_QDesktopServices_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDesktopServices_Type))
        return QDesktopServices_PythonToCpp_QDesktopServices_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDesktopServices_PTR_CppToPython_QDesktopServices(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDesktopServices*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDesktopServices_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDesktopServices(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDesktopServices_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDesktopServices", "QDesktopServices*",
        &Sbk_QDesktopServices_Type, &Shiboken::callCppDestructor< ::QDesktopServices >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDesktopServices_Type,
        QDesktopServices_PythonToCpp_QDesktopServices_PTR,
        is_QDesktopServices_PythonToCpp_QDesktopServices_PTR_Convertible,
        QDesktopServices_PTR_CppToPython_QDesktopServices);

    Shiboken::Conversions::registerConverterName(converter, "QDesktopServices");
    Shiboken::Conversions::registerConverterName(converter, "QDesktopServices*");
    Shiboken::Conversions::registerConverterName(converter, "QDesktopServices&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDesktopServices).name());


    // Initialization of enums.

    // Initialization of enum 'StandardLocation'.
    SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDesktopServices_Type,
        "StandardLocation",
        "PySide.QtGui.QDesktopServices.StandardLocation",
        "QDesktopServices::StandardLocation");
    if (!SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "DesktopLocation", (long) QDesktopServices::DesktopLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "DocumentsLocation", (long) QDesktopServices::DocumentsLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "FontsLocation", (long) QDesktopServices::FontsLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "ApplicationsLocation", (long) QDesktopServices::ApplicationsLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "MusicLocation", (long) QDesktopServices::MusicLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "MoviesLocation", (long) QDesktopServices::MoviesLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "PicturesLocation", (long) QDesktopServices::PicturesLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "TempLocation", (long) QDesktopServices::TempLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "HomeLocation", (long) QDesktopServices::HomeLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "DataLocation", (long) QDesktopServices::DataLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
        &Sbk_QDesktopServices_Type, "CacheLocation", (long) QDesktopServices::CacheLocation))
        return ;
    // Register converter for enum 'QDesktopServices::StandardLocation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX],
            QDesktopServices_StandardLocation_CppToPython_QDesktopServices_StandardLocation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDesktopServices_StandardLocation_PythonToCpp_QDesktopServices_StandardLocation,
            is_QDesktopServices_StandardLocation_PythonToCpp_QDesktopServices_StandardLocation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDESKTOPSERVICES_STANDARDLOCATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDesktopServices::StandardLocation");
        Shiboken::Conversions::registerConverterName(converter, "StandardLocation");
    }
    // End of 'StandardLocation' enum.


    qRegisterMetaType< ::QDesktopServices::StandardLocation >("QDesktopServices::StandardLocation");
}
