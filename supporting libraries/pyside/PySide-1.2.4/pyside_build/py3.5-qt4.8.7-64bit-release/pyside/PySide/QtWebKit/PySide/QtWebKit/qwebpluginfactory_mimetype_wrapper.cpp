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

#include "qwebpluginfactory_mimetype_wrapper.h"

// Extra includes
#include <qwebpluginfactory.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebPluginFactory_MimeType_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebPluginFactory::MimeType >()))
        return -1;

    ::QWebPluginFactory::MimeType* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "MimeType", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: MimeType()
    // 1: MimeType(QWebPluginFactory::MimeType)
    if (numArgs == 0) {
        overloadId = 0; // MimeType()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (pyArgs[0])))) {
        overloadId = 1; // MimeType(QWebPluginFactory::MimeType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebPluginFactory_MimeType_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // MimeType()
        {

            if (!PyErr_Occurred()) {
                // MimeType()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPluginFactory::MimeType();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // MimeType(const QWebPluginFactory::MimeType & MimeType)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebPluginFactory::MimeType cppArg0_local = ::QWebPluginFactory::MimeType();
            ::QWebPluginFactory::MimeType* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // MimeType(QWebPluginFactory::MimeType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebPluginFactory::MimeType(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebPluginFactory::MimeType >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebPluginFactory_MimeType_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebPluginFactory_MimeType_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebPluginFactory::MimeType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.MimeType", overloads);
        return -1;
}

static PyObject* Sbk_QWebPluginFactory_MimeType___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPluginFactory::MimeType& cppSelf = *(((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebPluginFactory_MimeType_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QWebPluginFactory_MimeType___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QWebPluginFactory_MimeType_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebPluginFactory::MimeType& cppSelf = *(((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (pyArg)))) {
                // operator!=(const QWebPluginFactory::MimeType & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QWebPluginFactory::MimeType cppArg0_local = ::QWebPluginFactory::MimeType();
                ::QWebPluginFactory::MimeType* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (pyArg)))) {
                // operator==(const QWebPluginFactory::MimeType & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QWebPluginFactory::MimeType cppArg0_local = ::QWebPluginFactory::MimeType();
                ::QWebPluginFactory::MimeType* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], pythonToCpp))
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
            goto Sbk_QWebPluginFactory_MimeType_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QWebPluginFactory_MimeType_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

static PyObject* Sbk_QWebPluginFactory_MimeType_get_description(PyObject* self, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->description);
    return pyOut;
}
static int Sbk_QWebPluginFactory_MimeType_set_description(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QWebPluginFactory_MimeType_get_name(PyObject* self, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->name);
    return pyOut;
}
static int Sbk_QWebPluginFactory_MimeType_set_name(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QWebPluginFactory_MimeType_get_fileExtensions(PyObject* self, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppSelf->fileExtensions);
    return pyOut;
}
static int Sbk_QWebPluginFactory_MimeType_set_fileExtensions(PyObject* self, PyObject* pyIn, void*)
{
    ::QWebPluginFactory::MimeType* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fileExtensions' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fileExtensions', 'QStringList' or convertible type expected");
        return -1;
    }

    ::QStringList& cppOut_ptr = cppSelf->fileExtensions;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for MimeType
static PyGetSetDef Sbk_QWebPluginFactory_MimeType_getsetlist[] = {
    {const_cast<char*>("description"), Sbk_QWebPluginFactory_MimeType_get_description, Sbk_QWebPluginFactory_MimeType_set_description},
    {const_cast<char*>("name"), Sbk_QWebPluginFactory_MimeType_get_name, Sbk_QWebPluginFactory_MimeType_set_name},
    {const_cast<char*>("fileExtensions"), Sbk_QWebPluginFactory_MimeType_get_fileExtensions, Sbk_QWebPluginFactory_MimeType_set_fileExtensions},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QWebPluginFactory_MimeType_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebPluginFactory_MimeType_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebPluginFactory_MimeType_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebPluginFactory.MimeType",
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
    /*tp_traverse*/         Sbk_QWebPluginFactory_MimeType_traverse,
    /*tp_clear*/            Sbk_QWebPluginFactory_MimeType_clear,
    /*tp_richcompare*/      Sbk_QWebPluginFactory_MimeType_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebPluginFactory_MimeType_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QWebPluginFactory_MimeType_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebPluginFactory_MimeType_Init,
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
static void MimeType_PythonToCpp_MimeType_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebPluginFactory_MimeType_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MimeType_PythonToCpp_MimeType_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPluginFactory_MimeType_Type))
        return MimeType_PythonToCpp_MimeType_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MimeType_PTR_CppToPython_MimeType(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebPluginFactory::MimeType*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebPluginFactory_MimeType_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* MimeType_COPY_CppToPython_MimeType(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebPluginFactory_MimeType_Type, new ::QWebPluginFactory::MimeType(*((::QWebPluginFactory::MimeType*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void MimeType_PythonToCpp_MimeType_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebPluginFactory::MimeType*)cppOut) = *((::QWebPluginFactory::MimeType*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_MimeType_PythonToCpp_MimeType_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebPluginFactory_MimeType_Type))
        return MimeType_PythonToCpp_MimeType_COPY;
    return 0;
}

void init_QWebPluginFactory_MimeType(PyObject* enclosingClass)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBPLUGINFACTORY_MIMETYPE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebPluginFactory_MimeType_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MimeType", "QWebPluginFactory::MimeType",
        &Sbk_QWebPluginFactory_MimeType_Type, &Shiboken::callCppDestructor< ::QWebPluginFactory::MimeType >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebPluginFactory_MimeType_Type,
        MimeType_PythonToCpp_MimeType_PTR,
        is_MimeType_PythonToCpp_MimeType_PTR_Convertible,
        MimeType_PTR_CppToPython_MimeType,
        MimeType_COPY_CppToPython_MimeType);

    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::MimeType");
    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::MimeType*");
    Shiboken::Conversions::registerConverterName(converter, "QWebPluginFactory::MimeType&");
    Shiboken::Conversions::registerConverterName(converter, "MimeType");
    Shiboken::Conversions::registerConverterName(converter, "MimeType*");
    Shiboken::Conversions::registerConverterName(converter, "MimeType&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebPluginFactory::MimeType).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        MimeType_PythonToCpp_MimeType_COPY,
        is_MimeType_PythonToCpp_MimeType_COPY_Convertible);


    qRegisterMetaType< ::QWebPluginFactory::MimeType >("MimeType");
    qRegisterMetaType< ::QWebPluginFactory::MimeType >("QWebPluginFactory::MimeType");
}
