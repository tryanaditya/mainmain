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
#include "pyside_qthelp_python.h"

#include "qhelpsearchquery_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QHelpSearchQuery_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QHelpSearchQuery >()))
        return -1;

    ::QHelpSearchQuery* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QHelpSearchQuery", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QHelpSearchQuery()
    // 1: QHelpSearchQuery(QHelpSearchQuery::FieldName,QStringList)
    // 2: QHelpSearchQuery(QHelpSearchQuery)
    if (numArgs == 0) {
        overloadId = 0; // QHelpSearchQuery()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (pyArgs[0])))) {
        overloadId = 2; // QHelpSearchQuery(QHelpSearchQuery)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 1; // QHelpSearchQuery(QHelpSearchQuery::FieldName,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpSearchQuery_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QHelpSearchQuery()
        {

            if (!PyErr_Occurred()) {
                // QHelpSearchQuery()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHelpSearchQuery();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QHelpSearchQuery(QHelpSearchQuery::FieldName field, const QStringList & wordList)
        {
            ::QHelpSearchQuery::FieldName cppArg0 = ((::QHelpSearchQuery::FieldName)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QHelpSearchQuery(QHelpSearchQuery::FieldName,QStringList)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHelpSearchQuery(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QHelpSearchQuery(const QHelpSearchQuery & QHelpSearchQuery)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QHelpSearchQuery cppArg0_local = ::QHelpSearchQuery();
            ::QHelpSearchQuery* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QHelpSearchQuery(QHelpSearchQuery)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QHelpSearchQuery(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QHelpSearchQuery >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QHelpSearchQuery_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QHelpSearchQuery_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtHelp.QHelpSearchQuery.FieldName, QStringList", "PySide.QtHelp.QHelpSearchQuery", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtHelp.QHelpSearchQuery", overloads);
        return -1;
}

static PyObject* Sbk_QHelpSearchQuery___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QHelpSearchQuery& cppSelf = *(((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHelpSearchQuery_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QHelpSearchQuery___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QHelpSearchQuery_get_wordList(PyObject* self, void*)
{
    ::QHelpSearchQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppSelf->wordList);
    return pyOut;
}
static int Sbk_QHelpSearchQuery_set_wordList(PyObject* self, PyObject* pyIn, void*)
{
    ::QHelpSearchQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'wordList' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'wordList', 'QStringList' or convertible type expected");
        return -1;
    }

    ::QStringList& cppOut_ptr = cppSelf->wordList;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QHelpSearchQuery_get_fieldName(PyObject* self, void*)
{
    ::QHelpSearchQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)self));
    ::QHelpSearchQuery::FieldName cppOut_local = cppSelf->fieldName;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QHelpSearchQuery_set_fieldName(PyObject* self, PyObject* pyIn, void*)
{
    ::QHelpSearchQuery* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fieldName' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fieldName', 'FieldName' or convertible type expected");
        return -1;
    }

    ::QHelpSearchQuery::FieldName cppOut_local = cppSelf->fieldName;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->fieldName = cppOut_local;

    return 0;
}

// Getters and Setters for QHelpSearchQuery
static PyGetSetDef Sbk_QHelpSearchQuery_getsetlist[] = {
    {const_cast<char*>("wordList"), Sbk_QHelpSearchQuery_get_wordList, Sbk_QHelpSearchQuery_set_wordList},
    {const_cast<char*>("fieldName"), Sbk_QHelpSearchQuery_get_fieldName, Sbk_QHelpSearchQuery_set_fieldName},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QHelpSearchQuery_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHelpSearchQuery_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHelpSearchQuery_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtHelp.QHelpSearchQuery",
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
    /*tp_traverse*/         Sbk_QHelpSearchQuery_traverse,
    /*tp_clear*/            Sbk_QHelpSearchQuery_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHelpSearchQuery_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QHelpSearchQuery_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QHelpSearchQuery_Init,
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
static void QHelpSearchQuery_FieldName_PythonToCpp_QHelpSearchQuery_FieldName(PyObject* pyIn, void* cppOut) {
    *((::QHelpSearchQuery::FieldName*)cppOut) = (::QHelpSearchQuery::FieldName) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHelpSearchQuery_FieldName_PythonToCpp_QHelpSearchQuery_FieldName_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX]))
        return QHelpSearchQuery_FieldName_PythonToCpp_QHelpSearchQuery_FieldName;
    return 0;
}
static PyObject* QHelpSearchQuery_FieldName_CppToPython_QHelpSearchQuery_FieldName(const void* cppIn) {
    int castCppIn = *((::QHelpSearchQuery::FieldName*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHelpSearchQuery_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHelpSearchQuery_Type))
        return QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHelpSearchQuery_PTR_CppToPython_QHelpSearchQuery(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QHelpSearchQuery*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QHelpSearchQuery_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QHelpSearchQuery_COPY_CppToPython_QHelpSearchQuery(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QHelpSearchQuery_Type, new ::QHelpSearchQuery(*((::QHelpSearchQuery*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_COPY(PyObject* pyIn, void* cppOut) {
    *((::QHelpSearchQuery*)cppOut) = *((::QHelpSearchQuery*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHelpSearchQuery_Type))
        return QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_COPY;
    return 0;
}

void init_QHelpSearchQuery(PyObject* module)
{
    SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHelpSearchQuery_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHelpSearchQuery", "QHelpSearchQuery",
        &Sbk_QHelpSearchQuery_Type, &Shiboken::callCppDestructor< ::QHelpSearchQuery >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHelpSearchQuery_Type,
        QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_PTR,
        is_QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_PTR_Convertible,
        QHelpSearchQuery_PTR_CppToPython_QHelpSearchQuery,
        QHelpSearchQuery_COPY_CppToPython_QHelpSearchQuery);

    Shiboken::Conversions::registerConverterName(converter, "QHelpSearchQuery");
    Shiboken::Conversions::registerConverterName(converter, "QHelpSearchQuery*");
    Shiboken::Conversions::registerConverterName(converter, "QHelpSearchQuery&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHelpSearchQuery).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_COPY,
        is_QHelpSearchQuery_PythonToCpp_QHelpSearchQuery_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'FieldName'.
    SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHelpSearchQuery_Type,
        "FieldName",
        "PySide.QtHelp.QHelpSearchQuery.FieldName",
        "QHelpSearchQuery::FieldName");
    if (!SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "DEFAULT", (long) QHelpSearchQuery::DEFAULT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "FUZZY", (long) QHelpSearchQuery::FUZZY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "WITHOUT", (long) QHelpSearchQuery::WITHOUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "PHRASE", (long) QHelpSearchQuery::PHRASE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "ALL", (long) QHelpSearchQuery::ALL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
        &Sbk_QHelpSearchQuery_Type, "ATLEAST", (long) QHelpSearchQuery::ATLEAST))
        return ;
    // Register converter for enum 'QHelpSearchQuery::FieldName'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX],
            QHelpSearchQuery_FieldName_CppToPython_QHelpSearchQuery_FieldName);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHelpSearchQuery_FieldName_PythonToCpp_QHelpSearchQuery_FieldName,
            is_QHelpSearchQuery_FieldName_PythonToCpp_QHelpSearchQuery_FieldName_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtHelpTypes[SBK_QHELPSEARCHQUERY_FIELDNAME_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHelpSearchQuery::FieldName");
        Shiboken::Conversions::registerConverterName(converter, "FieldName");
    }
    // End of 'FieldName' enum.


    qRegisterMetaType< ::QHelpSearchQuery >("QHelpSearchQuery");
    qRegisterMetaType< ::QHelpSearchQuery::FieldName >("QHelpSearchQuery::FieldName");
}
