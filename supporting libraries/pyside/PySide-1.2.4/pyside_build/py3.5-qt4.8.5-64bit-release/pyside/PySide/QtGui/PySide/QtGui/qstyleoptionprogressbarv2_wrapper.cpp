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

#include "qstyleoptionprogressbarv2_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionProgressBarV2_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionProgressBarV2 >()))
        return -1;

    ::QStyleOptionProgressBarV2* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionProgressBarV2", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionProgressBarV2()
    // 1: QStyleOptionProgressBarV2(QStyleOptionProgressBar)
    // 2: QStyleOptionProgressBarV2(QStyleOptionProgressBarV2)
    // 3: QStyleOptionProgressBarV2(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionProgressBarV2()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionProgressBarV2(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionProgressBarV2(QStyleOptionProgressBarV2)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionProgressBarV2(QStyleOptionProgressBar)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionProgressBarV2_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionProgressBarV2()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBarV2()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBarV2();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionProgressBarV2(const QStyleOptionProgressBar & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionProgressBar* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBarV2(QStyleOptionProgressBar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBarV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionProgressBarV2(const QStyleOptionProgressBarV2 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionProgressBarV2* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBarV2(QStyleOptionProgressBarV2)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBarV2(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionProgressBarV2(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionProgressBarV2(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionProgressBarV2(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionProgressBarV2 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionProgressBarV2_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionProgressBarV2_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionProgressBar", "PySide.QtGui.QStyleOptionProgressBarV2", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionProgressBarV2", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionProgressBarV2_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionProgressBarV2_get_bottomToTop(PyObject* self, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->bottomToTop;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBarV2_set_bottomToTop(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'bottomToTop' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'bottomToTop', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->bottomToTop;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->bottomToTop = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBarV2_get_invertedAppearance(PyObject* self, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->invertedAppearance;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBarV2_set_invertedAppearance(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'invertedAppearance' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'invertedAppearance', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->invertedAppearance;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->invertedAppearance = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionProgressBarV2_get_orientation(PyObject* self, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    ::Qt::Orientation cppOut_local = cppSelf->orientation;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionProgressBarV2_set_orientation(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionProgressBarV2* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionProgressBarV2*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'orientation' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'orientation', 'Orientation' or convertible type expected");
        return -1;
    }

    ::Qt::Orientation cppOut_local = cppSelf->orientation;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->orientation = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionProgressBarV2
static PyGetSetDef Sbk_QStyleOptionProgressBarV2_getsetlist[] = {
    {const_cast<char*>("bottomToTop"), Sbk_QStyleOptionProgressBarV2_get_bottomToTop, Sbk_QStyleOptionProgressBarV2_set_bottomToTop},
    {const_cast<char*>("invertedAppearance"), Sbk_QStyleOptionProgressBarV2_get_invertedAppearance, Sbk_QStyleOptionProgressBarV2_set_invertedAppearance},
    {const_cast<char*>("orientation"), Sbk_QStyleOptionProgressBarV2_get_orientation, Sbk_QStyleOptionProgressBarV2_set_orientation},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionProgressBarV2_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionProgressBarV2_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionProgressBarV2_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionProgressBarV2",
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
    /*tp_traverse*/         Sbk_QStyleOptionProgressBarV2_traverse,
    /*tp_clear*/            Sbk_QStyleOptionProgressBarV2_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionProgressBarV2_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionProgressBarV2_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionProgressBarV2_Init,
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
static void QStyleOptionProgressBarV2_StyleOptionType_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionProgressBarV2::StyleOptionType*)cppOut) = (::QStyleOptionProgressBarV2::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionProgressBarV2_StyleOptionType_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionProgressBarV2_StyleOptionType_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionProgressBarV2_StyleOptionType_CppToPython_QStyleOptionProgressBarV2_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionProgressBarV2::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionProgressBarV2_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionProgressBarV2::StyleOptionVersion*)cppOut) = (::QStyleOptionProgressBarV2::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionProgressBarV2_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionProgressBarV2_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionProgressBarV2_StyleOptionVersion_CppToPython_QStyleOptionProgressBarV2_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionProgressBarV2::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionProgressBarV2_PythonToCpp_QStyleOptionProgressBarV2_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionProgressBarV2_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionProgressBarV2_PythonToCpp_QStyleOptionProgressBarV2_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionProgressBarV2_Type))
        return QStyleOptionProgressBarV2_PythonToCpp_QStyleOptionProgressBarV2_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionProgressBarV2_PTR_CppToPython_QStyleOptionProgressBarV2(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionProgressBarV2*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionProgressBarV2_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionProgressBarV2(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionProgressBarV2_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionProgressBarV2", "QStyleOptionProgressBarV2*",
        &Sbk_QStyleOptionProgressBarV2_Type, &Shiboken::callCppDestructor< ::QStyleOptionProgressBarV2 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBAR_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionProgressBarV2_Type,
        QStyleOptionProgressBarV2_PythonToCpp_QStyleOptionProgressBarV2_PTR,
        is_QStyleOptionProgressBarV2_PythonToCpp_QStyleOptionProgressBarV2_PTR_Convertible,
        QStyleOptionProgressBarV2_PTR_CppToPython_QStyleOptionProgressBarV2);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBarV2");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBarV2*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBarV2&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionProgressBarV2).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionProgressBarV2_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionProgressBarV2.StyleOptionType",
        "QStyleOptionProgressBarV2::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionProgressBarV2_Type, "Type", (long) QStyleOptionProgressBarV2::Type))
        return ;
    // Register converter for enum 'QStyleOptionProgressBarV2::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX],
            QStyleOptionProgressBarV2_StyleOptionType_CppToPython_QStyleOptionProgressBarV2_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionProgressBarV2_StyleOptionType_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionType,
            is_QStyleOptionProgressBarV2_StyleOptionType_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBarV2::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionProgressBarV2_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionProgressBarV2.StyleOptionVersion",
        "QStyleOptionProgressBarV2::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionProgressBarV2_Type, "Version", (long) QStyleOptionProgressBarV2::Version))
        return ;
    // Register converter for enum 'QStyleOptionProgressBarV2::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX],
            QStyleOptionProgressBarV2_StyleOptionVersion_CppToPython_QStyleOptionProgressBarV2_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionProgressBarV2_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionVersion,
            is_QStyleOptionProgressBarV2_StyleOptionVersion_PythonToCpp_QStyleOptionProgressBarV2_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONPROGRESSBARV2_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionProgressBarV2::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionProgressBarV2::StyleOptionType >("QStyleOptionProgressBarV2::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionProgressBarV2::StyleOptionVersion >("QStyleOptionProgressBarV2::StyleOptionVersion");
}
