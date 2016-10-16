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
#include "pyside_qtwebkit_python.h"

#include "qwebpluginfactory_plugin_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPluginFactory_Plugin_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPluginFactory::Plugin >()))
        return -1;

    ::QWebPluginFactory::Plugin* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Plugin", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: Plugin()
    // 1: Plugin(QWebPluginFactory::Plugin)
    if (numArgs == 0) {
        overloadId = 0; // Plugin()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (pyArgs[0])))) {
        overloadId = 1; // Plugin(QWebPluginFactory::Plugin)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPluginFactory_Plugin_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Plugin()
        {

            if (!PyErr_Occurred()) {
                // Plugin()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPluginFactory::Plugin();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Plugin(const QWebPluginFactory::Plugin & Plugin)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPluginFactory::Plugin cppArg0_local = ::QWebPluginFactory::Plugin();
            ::QWebPluginFactory::Plugin* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // Plugin(QWebPluginFactory::Plugin)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPluginFactory::Plugin(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPluginFactory::Plugin >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPluginFactory_Plugin_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPluginFactory_Plugin_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPluginFactory::Plugin", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.Plugin", overloads);
        return -1;
}

static PyObject* Sbk_QWebPluginFactory_Plugin___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPluginFactory::Plugin& cppSelf = *(((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPluginFactory_Plugin_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPluginFactory_Plugin___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QWebPluginFactory_Plugin_get_description(PyObject* self, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->description);
    return pyOut;
}
static int Sbk_QWebPluginFactory_Plugin_set_description(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'description' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'description', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->description;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPluginFactory_Plugin_get_name(PyObject* self, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->name);
    return pyOut;
}
static int Sbk_QWebPluginFactory_Plugin_set_name(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'name' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'name', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->name;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QWebPluginFactory_Plugin_get_mimeTypes(PyObject* self, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_MIMETYPE_IDX], &cppSelf->mimeTypes);
    return pyOut;
}
static int Sbk_QWebPluginFactory_Plugin_set_mimeTypes(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::Plugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'mimeTypes' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBPLUGINFACTORY_MIMETYPE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'mimeTypes', 'QList' or convertible type expected");
        return -1;
    }

    ::QList<QWebPluginFactory::MimeType >& cppOut_ptr = cppSelf->mimeTypes;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for Plugin
static PyGetSetDef Sbk_QWebPluginFactory_Plugin_getsetlist[] = {
    {const_cast<char*>("description"), Sbk_QWebPluginFactory_Plugin_get_description, Sbk_QWebPluginFactory_Plugin_set_description},
    {const_cast<char*>("name"), Sbk_QWebPluginFactory_Plugin_get_name, Sbk_QWebPluginFactory_Plugin_set_name},
    {const_cast<char*>("mimeTypes"), Sbk_QWebPluginFactory_Plugin_get_mimeTypes, Sbk_QWebPluginFactory_Plugin_set_mimeTypes},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QWebPluginFactory_Plugin_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPluginFactory_Plugin_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPluginFactory_Plugin_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPluginFactory.Plugin",
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
    /*tp_traverse*/         Sbk_QWebPluginFactory_Plugin_traverse,
    /*tp_clear*/            Sbk_QWebPluginFactory_Plugin_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPluginFactory_Plugin_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QWebPluginFactory_Plugin_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPluginFactory_Plugin_Init,
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
static void Plugin_PythonToCpp_Plugin_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPluginFactory_Plugin_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Plugin_PythonToCpp_Plugin_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPluginFactory_Plugin_Type))
        return Plugin_PythonToCpp_Plugin_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Plugin_PTR_CppToPython_Plugin(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPluginFactory::Plugin*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPluginFactory_Plugin_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* Plugin_COPY_CppToPython_Plugin(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPluginFactory_Plugin_Type, new ::QWebPluginFactory::Plugin(*((::QWebPluginFactory::Plugin*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void Plugin_PythonToCpp_Plugin_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPluginFactory::Plugin*)cppOut) = *((::QWebPluginFactory::Plugin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_Plugin_PythonToCpp_Plugin_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPluginFactory_Plugin_Type))
        return Plugin_PythonToCpp_Plugin_COPY;
    return 0;
}

void init_QWebPluginFactory_Plugin(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_PLUGIN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPluginFactory_Plugin_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Plugin", "QWebPluginFactory::Plugin",
        &Sbk_QWebPluginFactory_Plugin_Type, &Shiboken::callCppDestructor< ::QWebPluginFactory::Plugin >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPluginFactory_Plugin_Type,
        Plugin_PythonToCpp_Plugin_PTR,
        is_Plugin_PythonToCpp_Plugin_PTR_Convertible,
        Plugin_PTR_CppToPython_Plugin,
        Plugin_COPY_CppToPython_Plugin);

    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::Plugin");
    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::Plugin*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::Plugin&");
    Shiboken::Conversions::registerConverterName(converter, "Plugin");
    Shiboken::Conversions::registerConverterName(converter, "Plugin*");
    Shiboken::Conversions::registerConverterName(converter, "Plugin&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPluginFactory::Plugin).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Plugin_PythonToCpp_Plugin_COPY,
        is_Plugin_PythonToCpp_Plugin_COPY_Convertible);


    qRegisterMetaType< ::QWebPluginFactory::Plugin >("Plugin");
    qRegisterMetaType< ::QWebPluginFactory::Plugin >("QWebPluginFactory::Plugin");
}
