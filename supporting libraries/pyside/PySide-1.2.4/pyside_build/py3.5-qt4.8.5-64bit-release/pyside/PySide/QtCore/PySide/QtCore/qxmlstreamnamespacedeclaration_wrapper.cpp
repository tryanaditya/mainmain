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

#include "qxmlstreamnamespacedeclaration_wrapper.h"

// Extra includes
#include <qxmlstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlStreamNamespaceDeclaration_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlStreamNamespaceDeclaration >()))
        return -1;

    ::QXmlStreamNamespaceDeclaration* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlStreamNamespaceDeclaration", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlStreamNamespaceDeclaration()
    // 1: QXmlStreamNamespaceDeclaration(QString,QString)
    // 2: QXmlStreamNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
    if (numArgs == 0) {
        overloadId = 0; // QXmlStreamNamespaceDeclaration()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (pyArgs[0])))) {
        overloadId = 2; // QXmlStreamNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // QXmlStreamNamespaceDeclaration(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamNamespaceDeclaration_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlStreamNamespaceDeclaration()
        {

            if (!PyErr_Occurred()) {
                // QXmlStreamNamespaceDeclaration()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamNamespaceDeclaration();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlStreamNamespaceDeclaration(const QString & prefix, const QString & namespaceUri)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QXmlStreamNamespaceDeclaration(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamNamespaceDeclaration(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QXmlStreamNamespaceDeclaration(const QXmlStreamNamespaceDeclaration & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlStreamNamespaceDeclaration cppArg0_local = ::QXmlStreamNamespaceDeclaration();
            ::QXmlStreamNamespaceDeclaration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlStreamNamespaceDeclaration(QXmlStreamNamespaceDeclaration)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamNamespaceDeclaration(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlStreamNamespaceDeclaration >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlStreamNamespaceDeclaration_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlStreamNamespaceDeclaration_Init_TypeError:
        const char* overloads[] = {"", "unicode, unicode", "PySide.QtCore.QXmlStreamNamespaceDeclaration", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamNamespaceDeclaration", overloads);
        return -1;
}

static PyObject* Sbk_QXmlStreamNamespaceDeclarationFunc_namespaceUri(PyObject* self)
{
    ::QXmlStreamNamespaceDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamNamespaceDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceUri()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamNamespaceDeclaration*>(cppSelf)->namespaceUri();
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

static PyObject* Sbk_QXmlStreamNamespaceDeclarationFunc_prefix(PyObject* self)
{
    ::QXmlStreamNamespaceDeclaration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamNamespaceDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringRef cppResult = const_cast<const ::QXmlStreamNamespaceDeclaration*>(cppSelf)->prefix();
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

static PyObject* Sbk_QXmlStreamNamespaceDeclaration___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamNamespaceDeclaration& cppSelf = *(((::QXmlStreamNamespaceDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlStreamNamespaceDeclaration_methods[] = {
    {"namespaceUri", (PyCFunction)Sbk_QXmlStreamNamespaceDeclarationFunc_namespaceUri, METH_NOARGS},
    {"prefix", (PyCFunction)Sbk_QXmlStreamNamespaceDeclarationFunc_prefix, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlStreamNamespaceDeclaration___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QXmlStreamNamespaceDeclaration_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamNamespaceDeclaration& cppSelf = *(((::QXmlStreamNamespaceDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (pyArg)))) {
                // operator!=(const QXmlStreamNamespaceDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamNamespaceDeclaration cppArg0_local = ::QXmlStreamNamespaceDeclaration();
                ::QXmlStreamNamespaceDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (pyArg)))) {
                // operator==(const QXmlStreamNamespaceDeclaration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QXmlStreamNamespaceDeclaration cppArg0_local = ::QXmlStreamNamespaceDeclaration();
                ::QXmlStreamNamespaceDeclaration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], pythonToCpp))
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
            goto Sbk_QXmlStreamNamespaceDeclaration_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlStreamNamespaceDeclaration_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlStreamNamespaceDeclaration_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlStreamNamespaceDeclaration_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlStreamNamespaceDeclaration_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QXmlStreamNamespaceDeclaration",
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
    /*tp_traverse*/         Sbk_QXmlStreamNamespaceDeclaration_traverse,
    /*tp_clear*/            Sbk_QXmlStreamNamespaceDeclaration_clear,
    /*tp_richcompare*/      Sbk_QXmlStreamNamespaceDeclaration_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlStreamNamespaceDeclaration_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlStreamNamespaceDeclaration_Init,
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
static void QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlStreamNamespaceDeclaration_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamNamespaceDeclaration_Type))
        return QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlStreamNamespaceDeclaration_PTR_CppToPython_QXmlStreamNamespaceDeclaration(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlStreamNamespaceDeclaration*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlStreamNamespaceDeclaration_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlStreamNamespaceDeclaration_COPY_CppToPython_QXmlStreamNamespaceDeclaration(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlStreamNamespaceDeclaration_Type, new ::QXmlStreamNamespaceDeclaration(*((::QXmlStreamNamespaceDeclaration*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamNamespaceDeclaration*)cppOut) = *((::QXmlStreamNamespaceDeclaration*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamNamespaceDeclaration_Type))
        return QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_COPY;
    return 0;
}

void init_QXmlStreamNamespaceDeclaration(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMNAMESPACEDECLARATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlStreamNamespaceDeclaration_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlStreamNamespaceDeclaration", "QXmlStreamNamespaceDeclaration",
        &Sbk_QXmlStreamNamespaceDeclaration_Type, &Shiboken::callCppDestructor< ::QXmlStreamNamespaceDeclaration >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlStreamNamespaceDeclaration_Type,
        QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_PTR,
        is_QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_PTR_Convertible,
        QXmlStreamNamespaceDeclaration_PTR_CppToPython_QXmlStreamNamespaceDeclaration,
        QXmlStreamNamespaceDeclaration_COPY_CppToPython_QXmlStreamNamespaceDeclaration);

    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNamespaceDeclaration");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNamespaceDeclaration*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamNamespaceDeclaration&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlStreamNamespaceDeclaration).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_COPY,
        is_QXmlStreamNamespaceDeclaration_PythonToCpp_QXmlStreamNamespaceDeclaration_COPY_Convertible);


    qRegisterMetaType< ::QXmlStreamNamespaceDeclaration >("QXmlStreamNamespaceDeclaration");
}
