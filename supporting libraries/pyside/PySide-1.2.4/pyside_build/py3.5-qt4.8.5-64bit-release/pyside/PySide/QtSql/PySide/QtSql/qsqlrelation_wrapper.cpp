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
#include "pyside_qtsql_python.h"

#include "qsqlrelation_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlRelation_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlRelation >()))
        return -1;

    ::QSqlRelation* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QSqlRelation_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QSqlRelation", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlRelation()
    // 1: QSqlRelation(QSqlRelation)
    // 2: QSqlRelation(QString,QString,QString)
    if (numArgs == 0) {
        overloadId = 0; // QSqlRelation()
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 2; // QSqlRelation(QString,QString,QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSqlRelation(QSqlRelation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRelation_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlRelation()
        {

            if (!PyErr_Occurred()) {
                // QSqlRelation()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlRelation();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlRelation(const QSqlRelation & QSqlRelation)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlRelation cppArg0_local = ::QSqlRelation();
            ::QSqlRelation* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlRelation(QSqlRelation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlRelation(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QSqlRelation(const QString & aTableName, const QString & indexCol, const QString & displayCol)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSqlRelation(QString,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlRelation(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlRelation >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlRelation_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlRelation_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtSql.QSqlRelation", "unicode, unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRelation", overloads);
        return -1;
}

static PyObject* Sbk_QSqlRelationFunc_displayColumn(PyObject* self)
{
    ::QSqlRelation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // displayColumn()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlRelation*>(cppSelf)->displayColumn();
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

static PyObject* Sbk_QSqlRelationFunc_indexColumn(PyObject* self)
{
    ::QSqlRelation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indexColumn()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlRelation*>(cppSelf)->indexColumn();
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

static PyObject* Sbk_QSqlRelationFunc_isValid(PyObject* self)
{
    ::QSqlRelation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlRelation*>(cppSelf)->isValid();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlRelationFunc_tableName(PyObject* self)
{
    ::QSqlRelation* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlRelation*>(cppSelf)->tableName();
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

static PyObject* Sbk_QSqlRelation___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlRelation& cppSelf = *(((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlRelation_methods[] = {
    {"displayColumn", (PyCFunction)Sbk_QSqlRelationFunc_displayColumn, METH_NOARGS},
    {"indexColumn", (PyCFunction)Sbk_QSqlRelationFunc_indexColumn, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlRelationFunc_isValid, METH_NOARGS},
    {"tableName", (PyCFunction)Sbk_QSqlRelationFunc_tableName, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSqlRelation___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlRelation_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlRelation_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlRelation_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlRelation",
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
    /*tp_traverse*/         Sbk_QSqlRelation_traverse,
    /*tp_clear*/            Sbk_QSqlRelation_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlRelation_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlRelation_Init,
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
static void QSqlRelation_PythonToCpp_QSqlRelation_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlRelation_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlRelation_PythonToCpp_QSqlRelation_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlRelation_Type))
        return QSqlRelation_PythonToCpp_QSqlRelation_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlRelation_PTR_CppToPython_QSqlRelation(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlRelation*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlRelation_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlRelation_COPY_CppToPython_QSqlRelation(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlRelation_Type, new ::QSqlRelation(*((::QSqlRelation*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlRelation_PythonToCpp_QSqlRelation_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlRelation*)cppOut) = *((::QSqlRelation*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlRelation_PythonToCpp_QSqlRelation_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlRelation_Type))
        return QSqlRelation_PythonToCpp_QSqlRelation_COPY;
    return 0;
}

void init_QSqlRelation(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLRELATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlRelation_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlRelation", "QSqlRelation",
        &Sbk_QSqlRelation_Type, &Shiboken::callCppDestructor< ::QSqlRelation >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlRelation_Type,
        QSqlRelation_PythonToCpp_QSqlRelation_PTR,
        is_QSqlRelation_PythonToCpp_QSqlRelation_PTR_Convertible,
        QSqlRelation_PTR_CppToPython_QSqlRelation,
        QSqlRelation_COPY_CppToPython_QSqlRelation);

    Shiboken::Conversions::registerConverterName(converter, "QSqlRelation");
    Shiboken::Conversions::registerConverterName(converter, "QSqlRelation*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlRelation&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlRelation).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlRelation_PythonToCpp_QSqlRelation_COPY,
        is_QSqlRelation_PythonToCpp_QSqlRelation_COPY_Convertible);


    qRegisterMetaType< ::QSqlRelation >("QSqlRelation");
}
