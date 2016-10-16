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

#include "qsystemlocale_wrapper.h"

// Extra includes
#include <qlocale.h>


// Native ---------------------------------------------------------

QSystemLocaleWrapper::QSystemLocaleWrapper() : QSystemLocale() {
    // ... middle
}

QLocale QSystemLocaleWrapper::fallbackLocale() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QLocale();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fallbackLocale"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSystemLocale::fallbackLocale();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QLocale();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSystemLocale.fallbackLocale", Shiboken::SbkType< QLocale >()->tp_name, pyResult->ob_type->tp_name);
        return ::QLocale();
    }
    ::QLocale cppResult = ::QLocale();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QSystemLocaleWrapper::query(QSystemLocale::QueryType type, QVariant in) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "query"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSystemLocale::query(type, in);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX]), &type),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &in)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSystemLocale.query", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSystemLocaleWrapper::~QSystemLocaleWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSystemLocale_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSystemLocale >()))
        return -1;

    ::QSystemLocaleWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QSystemLocale()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QSystemLocaleWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSystemLocale >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QSystemLocaleFunc_fallbackLocale(PyObject* self)
{
    ::QSystemLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fallbackLocale()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSystemLocale*>(cppSelf)->::QSystemLocale::fallbackLocale() : const_cast<const ::QSystemLocale*>(cppSelf)->fallbackLocale();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSystemLocaleFunc_query(PyObject* self, PyObject* args)
{
    ::QSystemLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "query", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: query(QSystemLocale::QueryType,QVariant)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // query(QSystemLocale::QueryType,QVariant)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemLocaleFunc_query_TypeError;

    // Call function/method
    {
        ::QSystemLocale::QueryType cppArg0 = ((::QSystemLocale::QueryType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // query(QSystemLocale::QueryType,QVariant)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSystemLocale*>(cppSelf)->::QSystemLocale::query(cppArg0, cppArg1) : const_cast<const ::QSystemLocale*>(cppSelf)->query(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSystemLocaleFunc_query_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSystemLocale.QueryType, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSystemLocale.query", overloads);
        return 0;
}

static PyMethodDef Sbk_QSystemLocale_methods[] = {
    {"fallbackLocale", (PyCFunction)Sbk_QSystemLocaleFunc_fallbackLocale, METH_NOARGS},
    {"query", (PyCFunction)Sbk_QSystemLocaleFunc_query, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSystemLocale_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSystemLocale_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSystemLocale_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSystemLocale",
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
    /*tp_traverse*/         Sbk_QSystemLocale_traverse,
    /*tp_clear*/            Sbk_QSystemLocale_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSystemLocale_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSystemLocale_Init,
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
static void QSystemLocale_QueryType_PythonToCpp_QSystemLocale_QueryType(PyObject* pyIn, void* cppOut) {
    *((::QSystemLocale::QueryType*)cppOut) = (::QSystemLocale::QueryType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSystemLocale_QueryType_PythonToCpp_QSystemLocale_QueryType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX]))
        return QSystemLocale_QueryType_PythonToCpp_QSystemLocale_QueryType;
    return 0;
}
static PyObject* QSystemLocale_QueryType_CppToPython_QSystemLocale_QueryType(const void* cppIn) {
    int castCppIn = *((::QSystemLocale::QueryType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSystemLocale_PythonToCpp_QSystemLocale_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSystemLocale_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSystemLocale_PythonToCpp_QSystemLocale_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSystemLocale_Type))
        return QSystemLocale_PythonToCpp_QSystemLocale_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSystemLocale_PTR_CppToPython_QSystemLocale(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSystemLocale*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSystemLocale_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QSystemLocale(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSystemLocale_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSystemLocale", "QSystemLocale*",
        &Sbk_QSystemLocale_Type, &Shiboken::callCppDestructor< ::QSystemLocale >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSystemLocale_Type,
        QSystemLocale_PythonToCpp_QSystemLocale_PTR,
        is_QSystemLocale_PythonToCpp_QSystemLocale_PTR_Convertible,
        QSystemLocale_PTR_CppToPython_QSystemLocale);

    Shiboken::Conversions::registerConverterName(converter, "QSystemLocale");
    Shiboken::Conversions::registerConverterName(converter, "QSystemLocale*");
    Shiboken::Conversions::registerConverterName(converter, "QSystemLocale&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSystemLocale).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSystemLocaleWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'QueryType'.
    SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSystemLocale_Type,
        "QueryType",
        "PySide.QtCore.QSystemLocale.QueryType",
        "QSystemLocale::QueryType");
    if (!SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "LanguageId", (long) QSystemLocale::LanguageId))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "CountryId", (long) QSystemLocale::CountryId))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DecimalPoint", (long) QSystemLocale::DecimalPoint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "GroupSeparator", (long) QSystemLocale::GroupSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "ZeroDigit", (long) QSystemLocale::ZeroDigit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "NegativeSign", (long) QSystemLocale::NegativeSign))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateFormatLong", (long) QSystemLocale::DateFormatLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateFormatShort", (long) QSystemLocale::DateFormatShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "TimeFormatLong", (long) QSystemLocale::TimeFormatLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "TimeFormatShort", (long) QSystemLocale::TimeFormatShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DayNameLong", (long) QSystemLocale::DayNameLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DayNameShort", (long) QSystemLocale::DayNameShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "MonthNameLong", (long) QSystemLocale::MonthNameLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "MonthNameShort", (long) QSystemLocale::MonthNameShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateToStringLong", (long) QSystemLocale::DateToStringLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateToStringShort", (long) QSystemLocale::DateToStringShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "TimeToStringLong", (long) QSystemLocale::TimeToStringLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "TimeToStringShort", (long) QSystemLocale::TimeToStringShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateTimeFormatLong", (long) QSystemLocale::DateTimeFormatLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateTimeFormatShort", (long) QSystemLocale::DateTimeFormatShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateTimeToStringLong", (long) QSystemLocale::DateTimeToStringLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "DateTimeToStringShort", (long) QSystemLocale::DateTimeToStringShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "MeasurementSystem", (long) QSystemLocale::MeasurementSystem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "PositiveSign", (long) QSystemLocale::PositiveSign))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "AMText", (long) QSystemLocale::AMText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "PMText", (long) QSystemLocale::PMText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "FirstDayOfWeek", (long) QSystemLocale::FirstDayOfWeek))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "Weekdays", (long) QSystemLocale::Weekdays))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "CurrencySymbol", (long) QSystemLocale::CurrencySymbol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "CurrencyToString", (long) QSystemLocale::CurrencyToString))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "UILanguages", (long) QSystemLocale::UILanguages))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "StringToStandardQuotation", (long) QSystemLocale::StringToStandardQuotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "StringToAlternateQuotation", (long) QSystemLocale::StringToAlternateQuotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "ScriptId", (long) QSystemLocale::ScriptId))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "ListToSeparatedString", (long) QSystemLocale::ListToSeparatedString))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "LocaleChanged", (long) QSystemLocale::LocaleChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "NativeLanguageName", (long) QSystemLocale::NativeLanguageName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "NativeCountryName", (long) QSystemLocale::NativeCountryName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "StandaloneMonthNameLong", (long) QSystemLocale::StandaloneMonthNameLong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
        &Sbk_QSystemLocale_Type, "StandaloneMonthNameShort", (long) QSystemLocale::StandaloneMonthNameShort))
        return ;
    // Register converter for enum 'QSystemLocale::QueryType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX],
            QSystemLocale_QueryType_CppToPython_QSystemLocale_QueryType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSystemLocale_QueryType_PythonToCpp_QSystemLocale_QueryType,
            is_QSystemLocale_QueryType_PythonToCpp_QSystemLocale_QueryType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSYSTEMLOCALE_QUERYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSystemLocale::QueryType");
        Shiboken::Conversions::registerConverterName(converter, "QueryType");
    }
    // End of 'QueryType' enum.


    qRegisterMetaType< ::QSystemLocale::QueryType >("QSystemLocale::QueryType");
}
