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

#include "qxmlstreamentitydeclaration_wrapper.h"

// Extra includes
#include <qxmlstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlStreamEntityDeclaration_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlStreamEntityDeclaration >()))
        return -1;

    ::QXmlStreamEntityDeclaration* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlStreamEntityDeclaration", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlStreamEntityDeclaration()
    // 1: QXmlStreamEntityDeclaration(QXmlStreamEntityDeclaration)
    if (numArgs == 0) {
        overloadId = 0; // QXmlStreamEntityDeclaration()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlStreamEntityDeclaration(QXmlStreamEntityDeclaration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamEntityDeclaration_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlStreamEntityDeclaration()
        {

            if (!PyErr_Occurred()) {
                // QXmlStreamEntityDeclaration()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamEntityDeclaration();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlStreamEntityDeclaration(const QXmlStreamEntityDeclaration & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlStreamEntityDeclaration cppArg0_local = ::QXmlStreamEntityDeclaration();
            ::QXmlStreamEntityDeclaration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlStreamEntityDeclaration(QXmlStreamEntityDeclaration)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamEntityDeclaration(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlStreamEntityDeclaration >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlStreamEntityDeclaration_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlStreamEntityDeclaration_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QXmlStreamEntityDeclaration", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamEntityDeclaration", overloads);
        return -1;
}

static PyObject* Sbk_QXmlStreamEntityDeclarationFunc_name(PyObject* self)
{
    ::QXmlStreamEntityDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamEntityDeclaration*>(cppSelf)->name();
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

static PyObject* Sbk_QXmlStreamEntityDeclarationFunc_notationName(PyObject* self)
{
    ::QXmlStreamEntityDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notationName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamEntityDeclaration*>(cppSelf)->notationName();
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

static PyObject* Sbk_QXmlStreamEntityDeclarationFunc_publicId(PyObject* self)
{
    ::QXmlStreamEntityDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // publicId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamEntityDeclaration*>(cppSelf)->publicId();
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

static PyObject* Sbk_QXmlStreamEntityDeclarationFunc_systemId(PyObject* self)
{
    ::QXmlStreamEntityDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamEntityDeclaration*>(cppSelf)->systemId();
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

static PyObject* Sbk_QXmlStreamEntityDeclarationFunc_value(PyObject* self)
{
    ::QXmlStreamEntityDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamEntityDeclaration*>(cppSelf)->value();
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

static PyObject* Sbk_QXmlStreamEntityDeclaration___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamEntityDeclaration& cppSelf = *(((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlStreamEntityDeclaration_methods[] = {
    {"name", (PyCFunction)Sbk_QXmlStreamEntityDeclarationFunc_name, METH_NOARGS},
    {"notationName", (PyCFunction)Sbk_QXmlStreamEntityDeclarationFunc_notationName, METH_NOARGS},
    {"publicId", (PyCFunction)Sbk_QXmlStreamEntityDeclarationFunc_publicId, METH_NOARGS},
    {"systemId", (PyCFunction)Sbk_QXmlStreamEntityDeclarationFunc_systemId, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QXmlStreamEntityDeclarationFunc_value, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlStreamEntityDeclaration___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QXmlStreamEntityDeclaration_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamEntityDeclaration& cppSelf = *(((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (pyArg)))) {
                // operator!=(const QXmlStreamEntityDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamEntityDeclaration cppArg0_local = ::QXmlStreamEntityDeclaration();
                ::QXmlStreamEntityDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (pyArg)))) {
                // operator==(const QXmlStreamEntityDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamEntityDeclaration cppArg0_local = ::QXmlStreamEntityDeclaration();
                ::QXmlStreamEntityDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], pythonToCpp))
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
            goto Sbk_QXmlStreamEntityDeclaration_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlStreamEntityDeclaration_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlStreamEntityDeclaration_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlStreamEntityDeclaration_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlStreamEntityDeclaration_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QXmlStreamEntityDeclaration",
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
    /*tp_traverse*/         Sbk_QXmlStreamEntityDeclaration_traverse,
    /*tp_clear*/            Sbk_QXmlStreamEntityDeclaration_clear,
    /*tp_richcompare*/      Sbk_QXmlStreamEntityDeclaration_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlStreamEntityDeclaration_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlStreamEntityDeclaration_Init,
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
static void QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlStreamEntityDeclaration_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamEntityDeclaration_Type))
        return QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlStreamEntityDeclaration_PTR_CppToPython_QXmlStreamEntityDeclaration(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlStreamEntityDeclaration*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlStreamEntityDeclaration_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlStreamEntityDeclaration_COPY_CppToPython_QXmlStreamEntityDeclaration(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlStreamEntityDeclaration_Type, new ::QXmlStreamEntityDeclaration(*((::QXmlStreamEntityDeclaration*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamEntityDeclaration*)cppOut) = *((::QXmlStreamEntityDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamEntityDeclaration_Type))
        return QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_COPY;
    return 0;
}

void init_QXmlStreamEntityDeclaration(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMENTITYDECLARATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlStreamEntityDeclaration_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlStreamEntityDeclaration", "QXmlStreamEntityDeclaration",
        &Sbk_QXmlStreamEntityDeclaration_Type, &Shiboken::callCppDestructor< ::QXmlStreamEntityDeclaration >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlStreamEntityDeclaration_Type,
        QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_PTR,
        is_QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_PTR_Convertible,
        QXmlStreamEntityDeclaration_PTR_CppToPython_QXmlStreamEntityDeclaration,
        QXmlStreamEntityDeclaration_COPY_CppToPython_QXmlStreamEntityDeclaration);

    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamEntityDeclaration");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamEntityDeclaration*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamEntityDeclaration&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlStreamEntityDeclaration).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_COPY,
        is_QXmlStreamEntityDeclaration_PythonToCpp_QXmlStreamEntityDeclaration_COPY_Convertible);


    qRegisterMetaType< ::QXmlStreamEntityDeclaration >("QXmlStreamEntityDeclaration");
}
