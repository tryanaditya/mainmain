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

#include "qwebdatabase_wrapper.h"

// Extra includes
#include <qwebdatabase.h>
#include <qwebsecurityorigin.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebDatabase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebDatabase >()))
        return -1;

    ::QWebDatabase* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWebDatabase", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWebDatabase(QWebDatabase)
    if (numArgs == 1
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (pyArgs[0]))))) {
        overloadId = 0; // QWebDatabase(QWebDatabase)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebDatabase_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWebDatabase* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QWebDatabase(QWebDatabase)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QWebDatabase(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebDatabase >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebDatabase_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebDatabase_Init_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebDatabase", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebDatabase", overloads);
        return -1;
}

static PyObject* Sbk_QWebDatabaseFunc_displayName(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // displayName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->displayName();
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

static PyObject* Sbk_QWebDatabaseFunc_expectedSize(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expectedSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->expectedSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebDatabaseFunc_fileName(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->fileName();
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

static PyObject* Sbk_QWebDatabaseFunc_name(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->name();
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

static PyObject* Sbk_QWebDatabaseFunc_origin(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // origin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebSecurityOrigin cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->origin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebDatabaseFunc_removeAllDatabases(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllDatabases()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebDatabase::removeAllDatabases();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QWebDatabaseFunc_removeDatabase(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeDatabase(QWebDatabase)
    if ((pyArg != Py_None && (pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (pyArg))))) {
        overloadId = 0; // removeDatabase(QWebDatabase)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebDatabaseFunc_removeDatabase_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWebDatabase* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeDatabase(QWebDatabase)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebDatabase::removeDatabase(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebDatabaseFunc_removeDatabase_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebDatabase", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebDatabase.removeDatabase", overloads);
        return 0;
}

static PyObject* Sbk_QWebDatabaseFunc_size(PyObject* self)
{
    ::QWebDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QWebDatabase*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebDatabase___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebDatabase& cppSelf = *(((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebDatabase_methods[] = {
    {"displayName", (PyCFunction)Sbk_QWebDatabaseFunc_displayName, METH_NOARGS},
    {"expectedSize", (PyCFunction)Sbk_QWebDatabaseFunc_expectedSize, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QWebDatabaseFunc_fileName, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QWebDatabaseFunc_name, METH_NOARGS},
    {"origin", (PyCFunction)Sbk_QWebDatabaseFunc_origin, METH_NOARGS},
    {"removeAllDatabases", (PyCFunction)Sbk_QWebDatabaseFunc_removeAllDatabases, METH_NOARGS|METH_STATIC},
    {"removeDatabase", (PyCFunction)Sbk_QWebDatabaseFunc_removeDatabase, METH_O|METH_STATIC},
    {"size", (PyCFunction)Sbk_QWebDatabaseFunc_size, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QWebDatabase___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebDatabase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebDatabase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebDatabase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebDatabase",
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
    /*tp_traverse*/         Sbk_QWebDatabase_traverse,
    /*tp_clear*/            Sbk_QWebDatabase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebDatabase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebDatabase_Init,
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
static void QWebDatabase_PythonToCpp_QWebDatabase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebDatabase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebDatabase_PythonToCpp_QWebDatabase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebDatabase_Type))
        return QWebDatabase_PythonToCpp_QWebDatabase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebDatabase_PTR_CppToPython_QWebDatabase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebDatabase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebDatabase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QWebDatabase_COPY_CppToPython_QWebDatabase(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebDatabase_Type, new ::QWebDatabase(*((::QWebDatabase*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QWebDatabase_PythonToCpp_QWebDatabase_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebDatabase*)cppOut) = *((::QWebDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QWebDatabase_PythonToCpp_QWebDatabase_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebDatabase_Type))
        return QWebDatabase_PythonToCpp_QWebDatabase_COPY;
    return 0;
}

void init_QWebDatabase(PyObject* module)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBDATABASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebDatabase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebDatabase", "QWebDatabase",
        &Sbk_QWebDatabase_Type, &Shiboken::callCppDestructor< ::QWebDatabase >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebDatabase_Type,
        QWebDatabase_PythonToCpp_QWebDatabase_PTR,
        is_QWebDatabase_PythonToCpp_QWebDatabase_PTR_Convertible,
        QWebDatabase_PTR_CppToPython_QWebDatabase,
        QWebDatabase_COPY_CppToPython_QWebDatabase);

    Shiboken::Conversions::registerConverterName(converter, "QWebDatabase");
    Shiboken::Conversions::registerConverterName(converter, "QWebDatabase*");
    Shiboken::Conversions::registerConverterName(converter, "QWebDatabase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebDatabase).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QWebDatabase_PythonToCpp_QWebDatabase_COPY,
        is_QWebDatabase_PythonToCpp_QWebDatabase_COPY_Convertible);


}
