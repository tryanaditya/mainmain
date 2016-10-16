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
#include "pyside_qtcore_python.h"

#include "qxmlstreamnotationdeclaration_wrapper.h"

// Extra includes
#include <qxmlstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlStreamNotationDeclaration_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlStreamNotationDeclaration >()))
        return -1;

    ::QXmlStreamNotationDeclaration* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlStreamNotationDeclaration", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlStreamNotationDeclaration()
    // 1: QXmlStreamNotationDeclaration(QXmlStreamNotationDeclaration)
    if (numArgs == 0) {
        overloadId = 0; // QXmlStreamNotationDeclaration()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlStreamNotationDeclaration(QXmlStreamNotationDeclaration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamNotationDeclaration_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlStreamNotationDeclaration()
        {

            if (!PyErr_Occurred()) {
                // QXmlStreamNotationDeclaration()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamNotationDeclaration();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlStreamNotationDeclaration(const QXmlStreamNotationDeclaration & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlStreamNotationDeclaration cppArg0_local = ::QXmlStreamNotationDeclaration();
            ::QXmlStreamNotationDeclaration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlStreamNotationDeclaration(QXmlStreamNotationDeclaration)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamNotationDeclaration(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlStreamNotationDeclaration >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlStreamNotationDeclaration_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlStreamNotationDeclaration_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QXmlStreamNotationDeclaration", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamNotationDeclaration", overloads);
        return -1;
}

static PyObject* Sbk_QXmlStreamNotationDeclarationFunc_name(PyObject* self)
{
    ::QXmlStreamNotationDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamNotationDeclaration*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamNotationDeclarationFunc_publicId(PyObject* self)
{
    ::QXmlStreamNotationDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // publicId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamNotationDeclaration*>(cppSelf)->publicId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamNotationDeclarationFunc_systemId(PyObject* self)
{
    ::QXmlStreamNotationDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamNotationDeclaration*>(cppSelf)->systemId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamNotationDeclaration___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamNotationDeclaration& cppSelf = *(((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlStreamNotationDeclaration_methods[] = {
    {"name", (PyCFunction)Sbk_QXmlStreamNotationDeclarationFunc_name, METH_NOARGS},
    {"publicId", (PyCFunction)Sbk_QXmlStreamNotationDeclarationFunc_publicId, METH_NOARGS},
    {"systemId", (PyCFunction)Sbk_QXmlStreamNotationDeclarationFunc_systemId, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlStreamNotationDeclaration___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QXmlStreamNotationDeclaration_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamNotationDeclaration& cppSelf = *(((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (pyArg)))) {
                // operator!=(const QXmlStreamNotationDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamNotationDeclaration cppArg0_local = ::QXmlStreamNotationDeclaration();
                ::QXmlStreamNotationDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (pyArg)))) {
                // operator==(const QXmlStreamNotationDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamNotationDeclaration cppArg0_local = ::QXmlStreamNotationDeclaration();
                ::QXmlStreamNotationDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], pythonToCpp))
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
            goto Sbk_QXmlStreamNotationDeclaration_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlStreamNotationDeclaration_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlStreamNotationDeclaration_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlStreamNotationDeclaration_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlStreamNotationDeclaration_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QXmlStreamNotationDeclaration",
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
    /*tp_traverse*/         Sbk_QXmlStreamNotationDeclaration_traverse,
    /*tp_clear*/            Sbk_QXmlStreamNotationDeclaration_clear,
    /*tp_richcompare*/      Sbk_QXmlStreamNotationDeclaration_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlStreamNotationDeclaration_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlStreamNotationDeclaration_Init,
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
static void QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlStreamNotationDeclaration_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamNotationDeclaration_Type))
        return QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlStreamNotationDeclaration_PTR_CppToPython_QXmlStreamNotationDeclaration(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlStreamNotationDeclaration*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlStreamNotationDeclaration_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlStreamNotationDeclaration_COPY_CppToPython_QXmlStreamNotationDeclaration(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlStreamNotationDeclaration_Type, new ::QXmlStreamNotationDeclaration(*((::QXmlStreamNotationDeclaration*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamNotationDeclaration*)cppOut) = *((::QXmlStreamNotationDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamNotationDeclaration_Type))
        return QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_COPY;
    return 0;
}

void init_QXmlStreamNotationDeclaration(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNOTATIONDECLARATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlStreamNotationDeclaration_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlStreamNotationDeclaration", "QXmlStreamNotationDeclaration",
        &Sbk_QXmlStreamNotationDeclaration_Type, &Shiboken::callCppDestructor< ::QXmlStreamNotationDeclaration >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlStreamNotationDeclaration_Type,
        QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_PTR,
        is_QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_PTR_Convertible,
        QXmlStreamNotationDeclaration_PTR_CppToPython_QXmlStreamNotationDeclaration,
        QXmlStreamNotationDeclaration_COPY_CppToPython_QXmlStreamNotationDeclaration);

    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNotationDeclaration");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNotationDeclaration*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNotationDeclaration&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlStreamNotationDeclaration).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_COPY,
        is_QXmlStreamNotationDeclaration_PythonToCpp_QXmlStreamNotationDeclaration_COPY_Convertible);


    qRegisterMetaType< ::QXmlStreamNotationDeclaration >("QXmlStreamNotationDeclaration");
}
