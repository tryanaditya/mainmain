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

#include "qstyleoptionframe_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionFrame_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionFrame >()))
        return -1;

    ::QStyleOptionFrame* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionFrame", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionFrame()
    // 1: QStyleOptionFrame(QStyleOptionFrame)
    // 2: QStyleOptionFrame(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionFrame()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionFrame(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionFrame(QStyleOptionFrame)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionFrame_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionFrame()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionFrame()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrame();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionFrame(const QStyleOptionFrame & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrame(QStyleOptionFrame)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrame(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionFrame(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrame(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrame(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionFrame >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionFrame_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionFrame_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionFrame", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionFrame", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionFrame_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionFrame_get_lineWidth(PyObject* self, void*)
{
    ::QStyleOptionFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->lineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionFrame_set_lineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'lineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'lineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->lineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->lineWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionFrame_get_midLineWidth(PyObject* self, void*)
{
    ::QStyleOptionFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->midLineWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionFrame_set_midLineWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionFrame* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrame*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'midLineWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'midLineWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->midLineWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->midLineWidth = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionFrame
static PyGetSetDef Sbk_QStyleOptionFrame_getsetlist[] = {
    {const_cast<char*>("lineWidth"), Sbk_QStyleOptionFrame_get_lineWidth, Sbk_QStyleOptionFrame_set_lineWidth},
    {const_cast<char*>("midLineWidth"), Sbk_QStyleOptionFrame_get_midLineWidth, Sbk_QStyleOptionFrame_set_midLineWidth},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionFrame_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionFrame_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionFrame_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionFrame",
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
    /*tp_traverse*/         Sbk_QStyleOptionFrame_traverse,
    /*tp_clear*/            Sbk_QStyleOptionFrame_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionFrame_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionFrame_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionFrame_Init,
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
static void QStyleOptionFrame_StyleOptionType_PythonToCpp_QStyleOptionFrame_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionFrame::StyleOptionType*)cppOut) = (::QStyleOptionFrame::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionFrame_StyleOptionType_PythonToCpp_QStyleOptionFrame_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionFrame_StyleOptionType_PythonToCpp_QStyleOptionFrame_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionFrame_StyleOptionType_CppToPython_QStyleOptionFrame_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionFrame::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionFrame_StyleOptionVersion_PythonToCpp_QStyleOptionFrame_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionFrame::StyleOptionVersion*)cppOut) = (::QStyleOptionFrame::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionFrame_StyleOptionVersion_PythonToCpp_QStyleOptionFrame_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionFrame_StyleOptionVersion_PythonToCpp_QStyleOptionFrame_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionFrame_StyleOptionVersion_CppToPython_QStyleOptionFrame_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionFrame::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionFrame_PythonToCpp_QStyleOptionFrame_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionFrame_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionFrame_PythonToCpp_QStyleOptionFrame_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionFrame_Type))
        return QStyleOptionFrame_PythonToCpp_QStyleOptionFrame_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionFrame_PTR_CppToPython_QStyleOptionFrame(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionFrame*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionFrame_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionFrame(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionFrame_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionFrame", "QStyleOptionFrame*",
        &Sbk_QStyleOptionFrame_Type, &Shiboken::callCppDestructor< ::QStyleOptionFrame >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionFrame_Type,
        QStyleOptionFrame_PythonToCpp_QStyleOptionFrame_PTR,
        is_QStyleOptionFrame_PythonToCpp_QStyleOptionFrame_PTR_Convertible,
        QStyleOptionFrame_PTR_CppToPython_QStyleOptionFrame);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrame");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrame*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrame&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionFrame).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionFrame_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionFrame.StyleOptionType",
        "QStyleOptionFrame::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionFrame_Type, "Type", (long) QStyleOptionFrame::Type))
        return ;
    // Register converter for enum 'QStyleOptionFrame::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX],
            QStyleOptionFrame_StyleOptionType_CppToPython_QStyleOptionFrame_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrame_StyleOptionType_PythonToCpp_QStyleOptionFrame_StyleOptionType,
            is_QStyleOptionFrame_StyleOptionType_PythonToCpp_QStyleOptionFrame_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrame::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionFrame_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionFrame.StyleOptionVersion",
        "QStyleOptionFrame::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionFrame_Type, "Version", (long) QStyleOptionFrame::Version))
        return ;
    // Register converter for enum 'QStyleOptionFrame::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX],
            QStyleOptionFrame_StyleOptionVersion_CppToPython_QStyleOptionFrame_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrame_StyleOptionVersion_PythonToCpp_QStyleOptionFrame_StyleOptionVersion,
            is_QStyleOptionFrame_StyleOptionVersion_PythonToCpp_QStyleOptionFrame_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrame::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionFrame::StyleOptionType >("QStyleOptionFrame::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionFrame::StyleOptionVersion >("QStyleOptionFrame::StyleOptionVersion");
}
