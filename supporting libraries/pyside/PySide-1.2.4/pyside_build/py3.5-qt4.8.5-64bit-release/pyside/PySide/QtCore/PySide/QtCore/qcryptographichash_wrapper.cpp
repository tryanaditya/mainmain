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

#include "qcryptographichash_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qcryptographichash.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QCryptographicHash_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QCryptographicHash >()))
        return -1;

    ::QCryptographicHash* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QCryptographicHash", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QCryptographicHash(QCryptographicHash::Algorithm)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QCryptographicHash(QCryptographicHash::Algorithm)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCryptographicHash_Init_TypeError;

    // Call function/method
    {
        ::QCryptographicHash::Algorithm cppArg0 = ((::QCryptographicHash::Algorithm)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QCryptographicHash(QCryptographicHash::Algorithm)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QCryptographicHash(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QCryptographicHash >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QCryptographicHash_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QCryptographicHash_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QCryptographicHash.Algorithm", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCryptographicHash", overloads);
        return -1;
}

static PyObject* Sbk_QCryptographicHashFunc_addData(PyObject* self, PyObject* pyArg)
{
    ::QCryptographicHash* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCryptographicHash*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addData(QByteArray)
    // 1: addData(const char*,int)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 1; // addData(const char*,int)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // addData(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCryptographicHashFunc_addData_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addData(const QByteArray & data)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // addData(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addData(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // addData(const char * data, int length)
        {

            if (!PyErr_Occurred()) {
                // addData(const char*,int)
                // Begin code injection

                cppSelf->addData(Shiboken::String::toCString(pyArg), Shiboken::String::len(pyArg));

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCryptographicHashFunc_addData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCryptographicHash.addData", overloads);
        return 0;
}

static PyObject* Sbk_QCryptographicHashFunc_hash(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hash", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hash(QByteArray,QCryptographicHash::Algorithm)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX]), (pyArgs[1])))) {
        overloadId = 0; // hash(QByteArray,QCryptographicHash::Algorithm)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCryptographicHashFunc_hash_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QCryptographicHash::Algorithm cppArg1 = ((::QCryptographicHash::Algorithm)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hash(QByteArray,QCryptographicHash::Algorithm)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QCryptographicHash::hash(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCryptographicHashFunc_hash_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtCore.QCryptographicHash.Algorithm", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCryptographicHash.hash", overloads);
        return 0;
}

static PyObject* Sbk_QCryptographicHashFunc_reset(PyObject* self)
{
    ::QCryptographicHash* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCryptographicHash*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QCryptographicHashFunc_result(PyObject* self)
{
    ::QCryptographicHash* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCryptographicHash*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // result()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QCryptographicHash*>(cppSelf)->result();
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

static PyMethodDef Sbk_QCryptographicHash_methods[] = {
    {"addData", (PyCFunction)Sbk_QCryptographicHashFunc_addData, METH_O},
    {"hash", (PyCFunction)Sbk_QCryptographicHashFunc_hash, METH_VARARGS|METH_STATIC},
    {"reset", (PyCFunction)Sbk_QCryptographicHashFunc_reset, METH_NOARGS},
    {"result", (PyCFunction)Sbk_QCryptographicHashFunc_result, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QCryptographicHash_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QCryptographicHash_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QCryptographicHash_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QCryptographicHash",
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
    /*tp_traverse*/         Sbk_QCryptographicHash_traverse,
    /*tp_clear*/            Sbk_QCryptographicHash_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QCryptographicHash_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QCryptographicHash_Init,
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
static void QCryptographicHash_Algorithm_PythonToCpp_QCryptographicHash_Algorithm(PyObject* pyIn, void* cppOut) {
    *((::QCryptographicHash::Algorithm*)cppOut) = (::QCryptographicHash::Algorithm) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QCryptographicHash_Algorithm_PythonToCpp_QCryptographicHash_Algorithm_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX]))
        return QCryptographicHash_Algorithm_PythonToCpp_QCryptographicHash_Algorithm;
    return 0;
}
static PyObject* QCryptographicHash_Algorithm_CppToPython_QCryptographicHash_Algorithm(const void* cppIn) {
    int castCppIn = *((::QCryptographicHash::Algorithm*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QCryptographicHash_PythonToCpp_QCryptographicHash_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QCryptographicHash_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QCryptographicHash_PythonToCpp_QCryptographicHash_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QCryptographicHash_Type))
        return QCryptographicHash_PythonToCpp_QCryptographicHash_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QCryptographicHash_PTR_CppToPython_QCryptographicHash(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QCryptographicHash*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QCryptographicHash_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QCryptographicHash(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QCryptographicHash_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QCryptographicHash", "QCryptographicHash*",
        &Sbk_QCryptographicHash_Type, &Shiboken::callCppDestructor< ::QCryptographicHash >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QCryptographicHash_Type,
        QCryptographicHash_PythonToCpp_QCryptographicHash_PTR,
        is_QCryptographicHash_PythonToCpp_QCryptographicHash_PTR_Convertible,
        QCryptographicHash_PTR_CppToPython_QCryptographicHash);

    Shiboken::Conversions::registerConverterName(converter, "QCryptographicHash");
    Shiboken::Conversions::registerConverterName(converter, "QCryptographicHash*");
    Shiboken::Conversions::registerConverterName(converter, "QCryptographicHash&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCryptographicHash).name());


    // Initialization of enums.

    // Initialization of enum 'Algorithm'.
    SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QCryptographicHash_Type,
        "Algorithm",
        "PySide.QtCore.QCryptographicHash.Algorithm",
        "QCryptographicHash::Algorithm");
    if (!SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX],
        &Sbk_QCryptographicHash_Type, "Md4", (long) QCryptographicHash::Md4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX],
        &Sbk_QCryptographicHash_Type, "Md5", (long) QCryptographicHash::Md5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX],
        &Sbk_QCryptographicHash_Type, "Sha1", (long) QCryptographicHash::Sha1))
        return ;
    // Register converter for enum 'QCryptographicHash::Algorithm'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX],
            QCryptographicHash_Algorithm_CppToPython_QCryptographicHash_Algorithm);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QCryptographicHash_Algorithm_PythonToCpp_QCryptographicHash_Algorithm,
            is_QCryptographicHash_Algorithm_PythonToCpp_QCryptographicHash_Algorithm_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QCRYPTOGRAPHICHASH_ALGORITHM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QCryptographicHash::Algorithm");
        Shiboken::Conversions::registerConverterName(converter, "Algorithm");
    }
    // End of 'Algorithm' enum.


    qRegisterMetaType< ::QCryptographicHash::Algorithm >("QCryptographicHash::Algorithm");
}
