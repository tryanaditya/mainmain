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
#include "pyside_qtgui_python.h"

#include "qstyleoptioncomplex_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionComplex_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionComplex >()))
        return -1;

    ::QStyleOptionComplex* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOptionComplex(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QStyleOptionComplex", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionComplex(QStyleOptionComplex)
    // 1: QStyleOptionComplex(int,int)
    if (numArgs == 0) {
        overloadId = 1; // QStyleOptionComplex(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QStyleOptionComplex(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // QStyleOptionComplex(int,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // QStyleOptionComplex(QStyleOptionComplex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionComplex_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionComplex(const QStyleOptionComplex & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionComplex* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionComplex(QStyleOptionComplex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionComplex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionComplex(int version, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "version");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOptionComplex(): got multiple values for keyword argument 'version'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QStyleOptionComplex_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOptionComplex(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QStyleOptionComplex_Init_TypeError;
                }
            }
            int cppArg0 = QStyleOptionComplex::Version;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QStyleOptionComplex::SO_Complex;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QStyleOptionComplex(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionComplex(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionComplex >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionComplex_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionComplex_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyleOptionComplex", "int = QStyleOptionComplex.Version, int = SO_Complex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionComplex", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionComplex_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionComplex_get_subControls(PyObject* self, void*)
{
    ::QStyleOptionComplex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComplex*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppSelf->subControls);
    return pyOut;
}
static int Sbk_QStyleOptionComplex_set_subControls(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComplex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComplex*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'subControls' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'subControls', 'SubControls' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyle::SubControl> cppOut_local = cppSelf->subControls;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->subControls = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionComplex_get_activeSubControls(PyObject* self, void*)
{
    ::QStyleOptionComplex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComplex*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppSelf->activeSubControls);
    return pyOut;
}
static int Sbk_QStyleOptionComplex_set_activeSubControls(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionComplex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionComplex*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'activeSubControls' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'activeSubControls', 'SubControls' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyle::SubControl> cppOut_local = cppSelf->activeSubControls;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->activeSubControls = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionComplex
static PyGetSetDef Sbk_QStyleOptionComplex_getsetlist[] = {
    {const_cast<char*>("subControls"), Sbk_QStyleOptionComplex_get_subControls, Sbk_QStyleOptionComplex_set_subControls},
    {const_cast<char*>("activeSubControls"), Sbk_QStyleOptionComplex_get_activeSubControls, Sbk_QStyleOptionComplex_set_activeSubControls},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionComplex_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionComplex_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionComplex_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionComplex",
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
    /*tp_traverse*/         Sbk_QStyleOptionComplex_traverse,
    /*tp_clear*/            Sbk_QStyleOptionComplex_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionComplex_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionComplex_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionComplex_Init,
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
static void QStyleOptionComplex_StyleOptionType_PythonToCpp_QStyleOptionComplex_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionComplex::StyleOptionType*)cppOut) = (::QStyleOptionComplex::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionComplex_StyleOptionType_PythonToCpp_QStyleOptionComplex_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionComplex_StyleOptionType_PythonToCpp_QStyleOptionComplex_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionComplex_StyleOptionType_CppToPython_QStyleOptionComplex_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionComplex::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionComplex_StyleOptionVersion_PythonToCpp_QStyleOptionComplex_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionComplex::StyleOptionVersion*)cppOut) = (::QStyleOptionComplex::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionComplex_StyleOptionVersion_PythonToCpp_QStyleOptionComplex_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionComplex_StyleOptionVersion_PythonToCpp_QStyleOptionComplex_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionComplex_StyleOptionVersion_CppToPython_QStyleOptionComplex_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionComplex::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionComplex_PythonToCpp_QStyleOptionComplex_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionComplex_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionComplex_PythonToCpp_QStyleOptionComplex_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionComplex_Type))
        return QStyleOptionComplex_PythonToCpp_QStyleOptionComplex_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionComplex_PTR_CppToPython_QStyleOptionComplex(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionComplex*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionComplex_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionComplex(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionComplex_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionComplex", "QStyleOptionComplex*",
        &Sbk_QStyleOptionComplex_Type, &Shiboken::callCppDestructor< ::QStyleOptionComplex >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionComplex_Type,
        QStyleOptionComplex_PythonToCpp_QStyleOptionComplex_PTR,
        is_QStyleOptionComplex_PythonToCpp_QStyleOptionComplex_PTR_Convertible,
        QStyleOptionComplex_PTR_CppToPython_QStyleOptionComplex);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComplex");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComplex*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComplex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionComplex).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionComplex_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionComplex.StyleOptionType",
        "QStyleOptionComplex::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionComplex_Type, "Type", (long) QStyleOptionComplex::Type))
        return ;
    // Register converter for enum 'QStyleOptionComplex::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX],
            QStyleOptionComplex_StyleOptionType_CppToPython_QStyleOptionComplex_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionComplex_StyleOptionType_PythonToCpp_QStyleOptionComplex_StyleOptionType,
            is_QStyleOptionComplex_StyleOptionType_PythonToCpp_QStyleOptionComplex_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComplex::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionComplex_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionComplex.StyleOptionVersion",
        "QStyleOptionComplex::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionComplex_Type, "Version", (long) QStyleOptionComplex::Version))
        return ;
    // Register converter for enum 'QStyleOptionComplex::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX],
            QStyleOptionComplex_StyleOptionVersion_CppToPython_QStyleOptionComplex_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionComplex_StyleOptionVersion_PythonToCpp_QStyleOptionComplex_StyleOptionVersion,
            is_QStyleOptionComplex_StyleOptionVersion_PythonToCpp_QStyleOptionComplex_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionComplex::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionComplex::StyleOptionType >("QStyleOptionComplex::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionComplex::StyleOptionVersion >("QStyleOptionComplex::StyleOptionVersion");
}
