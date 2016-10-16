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

#include "qtextcodec_converterstate_wrapper.h"

// Extra includes
#include <QTextCodec>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextCodec_ConverterState_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextCodec::ConverterState >()))
        return -1;

    ::QTextCodec::ConverterState* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.ConverterState(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:ConverterState", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: ConverterState(QFlags<QTextCodec::ConversionFlag>)
    if (numArgs == 0) {
        overloadId = 0; // ConverterState(QFlags<QTextCodec::ConversionFlag>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // ConverterState(QFlags<QTextCodec::ConversionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextCodec_ConverterState_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "f");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.ConverterState(): got multiple values for keyword argument 'f'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyArgs[0]))))
                    goto Sbk_QTextCodec_ConverterState_Init_TypeError;
            }
        }
        ::QFlags<QTextCodec::ConversionFlag> cppArg0 = QTextCodec::DefaultConversion;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // ConverterState(QFlags<QTextCodec::ConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QTextCodec::ConverterState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextCodec::ConverterState >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextCodec_ConverterState_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextCodec_ConverterState_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec.ConversionFlags = QTextCodec.DefaultConversion", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.ConverterState", overloads);
        return -1;
}

static PyMethodDef Sbk_QTextCodec_ConverterState_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QTextCodec_ConverterState_get_flags(PyObject* self, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), &cppSelf->flags);
    return pyOut;
}
static int Sbk_QTextCodec_ConverterState_set_flags(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'flags' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'flags', 'ConversionFlags' or convertible type expected");
        return -1;
    }

    ::QFlags<QTextCodec::ConversionFlag> cppOut_local = cppSelf->flags;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->flags = cppOut_local;

    return 0;
}

static PyObject* Sbk_QTextCodec_ConverterState_get_remainingChars(PyObject* self, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->remainingChars;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QTextCodec_ConverterState_set_remainingChars(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'remainingChars' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'remainingChars', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->remainingChars;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->remainingChars = cppOut_local;

    return 0;
}

static PyObject* Sbk_QTextCodec_ConverterState_get_invalidChars(PyObject* self, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->invalidChars;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QTextCodec_ConverterState_set_invalidChars(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextCodec::ConverterState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextCodec::ConverterState*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'invalidChars' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'invalidChars', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->invalidChars;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->invalidChars = cppOut_local;

    return 0;
}

// Getters and Setters for ConverterState
static PyGetSetDef Sbk_QTextCodec_ConverterState_getsetlist[] = {
    {const_cast<char*>("flags"), Sbk_QTextCodec_ConverterState_get_flags, Sbk_QTextCodec_ConverterState_set_flags},
    {const_cast<char*>("remainingChars"), Sbk_QTextCodec_ConverterState_get_remainingChars, Sbk_QTextCodec_ConverterState_set_remainingChars},
    {const_cast<char*>("invalidChars"), Sbk_QTextCodec_ConverterState_get_invalidChars, Sbk_QTextCodec_ConverterState_set_invalidChars},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QTextCodec_ConverterState_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextCodec_ConverterState_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextCodec_ConverterState_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextCodec.ConverterState",
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
    /*tp_traverse*/         Sbk_QTextCodec_ConverterState_traverse,
    /*tp_clear*/            Sbk_QTextCodec_ConverterState_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextCodec_ConverterState_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QTextCodec_ConverterState_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextCodec_ConverterState_Init,
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
static void ConverterState_PythonToCpp_ConverterState_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextCodec_ConverterState_Type, pyIn, cppOut);
}
static PythonToCppFunc is_ConverterState_PythonToCpp_ConverterState_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextCodec_ConverterState_Type))
        return ConverterState_PythonToCpp_ConverterState_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ConverterState_PTR_CppToPython_ConverterState(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextCodec::ConverterState*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextCodec_ConverterState_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextCodec_ConverterState(PyObject* enclosingClass)
{
    SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_CONVERTERSTATE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextCodec_ConverterState_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "ConverterState", "QTextCodec::ConverterState*",
        &Sbk_QTextCodec_ConverterState_Type, &Shiboken::callCppDestructor< ::QTextCodec::ConverterState >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextCodec_ConverterState_Type,
        ConverterState_PythonToCpp_ConverterState_PTR,
        is_ConverterState_PythonToCpp_ConverterState_PTR_Convertible,
        ConverterState_PTR_CppToPython_ConverterState);

    Shiboken::Conversions::registerConverterName(converter, "QTextCodec::ConverterState");
    Shiboken::Conversions::registerConverterName(converter, "QTextCodec::ConverterState*");
    Shiboken::Conversions::registerConverterName(converter, "QTextCodec::ConverterState&");
    Shiboken::Conversions::registerConverterName(converter, "ConverterState");
    Shiboken::Conversions::registerConverterName(converter, "ConverterState*");
    Shiboken::Conversions::registerConverterName(converter, "ConverterState&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextCodec::ConverterState).name());



}
