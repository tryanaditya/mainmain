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

#include "qstyleoptionframev3_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionFrameV3_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionFrameV3 >()))
        return -1;

    ::QStyleOptionFrameV3* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionFrameV3", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionFrameV3()
    // 1: QStyleOptionFrameV3(QStyleOptionFrame)
    // 2: QStyleOptionFrameV3(QStyleOptionFrameV3)
    // 3: QStyleOptionFrameV3(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionFrameV3()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionFrameV3(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionFrameV3(QStyleOptionFrameV3)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionFrameV3(QStyleOptionFrame)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionFrameV3_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionFrameV3()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV3()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV3();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionFrameV3(const QStyleOptionFrame & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionFrame* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV3(QStyleOptionFrame)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV3(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionFrameV3(const QStyleOptionFrameV3 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionFrameV3* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV3(QStyleOptionFrameV3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV3(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionFrameV3(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionFrameV3(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionFrameV3(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionFrameV3 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionFrameV3_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionFrameV3_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionFrame", "PySide.QtGui.QStyleOptionFrameV3", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionFrameV3", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionFrameV3_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionFrameV3_get_frameShape(PyObject* self, void*)
{
    ::QStyleOptionFrameV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX], (SbkObject*)self));
    ::QFrame::Shape cppOut_local = cppSelf->frameShape;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFRAME_SHAPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionFrameV3_set_frameShape(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionFrameV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'frameShape' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFRAME_SHAPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'frameShape', 'Shape' or convertible type expected");
        return -1;
    }

    ::QFrame::Shape cppOut_local = cppSelf->frameShape;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->frameShape = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionFrameV3_get_unused(PyObject* self, void*)
{
    ::QStyleOptionFrameV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX], (SbkObject*)self));
    uint cppOut_local = cppSelf->unused;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionFrameV3_set_unused(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionFrameV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionFrameV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'unused' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'unused', 'uint' or convertible type expected");
        return -1;
    }

    uint cppOut_local = cppSelf->unused;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->unused = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionFrameV3
static PyGetSetDef Sbk_QStyleOptionFrameV3_getsetlist[] = {
    {const_cast<char*>("frameShape"), Sbk_QStyleOptionFrameV3_get_frameShape, Sbk_QStyleOptionFrameV3_set_frameShape},
    {const_cast<char*>("unused"), Sbk_QStyleOptionFrameV3_get_unused, Sbk_QStyleOptionFrameV3_set_unused},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionFrameV3_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionFrameV3_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionFrameV3_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionFrameV3",
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
    /*tp_traverse*/         Sbk_QStyleOptionFrameV3_traverse,
    /*tp_clear*/            Sbk_QStyleOptionFrameV3_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionFrameV3_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionFrameV3_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionFrameV3_Init,
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
static void QStyleOptionFrameV3_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV3_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionFrameV3::StyleOptionVersion*)cppOut) = (::QStyleOptionFrameV3::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionFrameV3_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV3_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionFrameV3_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV3_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionFrameV3_StyleOptionVersion_CppToPython_QStyleOptionFrameV3_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionFrameV3::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionFrameV3_PythonToCpp_QStyleOptionFrameV3_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionFrameV3_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionFrameV3_PythonToCpp_QStyleOptionFrameV3_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionFrameV3_Type))
        return QStyleOptionFrameV3_PythonToCpp_QStyleOptionFrameV3_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionFrameV3_PTR_CppToPython_QStyleOptionFrameV3(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionFrameV3*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionFrameV3_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionFrameV3(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionFrameV3_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionFrameV3", "QStyleOptionFrameV3*",
        &Sbk_QStyleOptionFrameV3_Type, &Shiboken::callCppDestructor< ::QStyleOptionFrameV3 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV2_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionFrameV3_Type,
        QStyleOptionFrameV3_PythonToCpp_QStyleOptionFrameV3_PTR,
        is_QStyleOptionFrameV3_PythonToCpp_QStyleOptionFrameV3_PTR_Convertible,
        QStyleOptionFrameV3_PTR_CppToPython_QStyleOptionFrameV3);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV3");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV3*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV3&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionFrameV3).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionFrameV3_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionFrameV3.StyleOptionVersion",
        "QStyleOptionFrameV3::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionFrameV3_Type, "Version", (long) QStyleOptionFrameV3::Version))
        return ;
    // Register converter for enum 'QStyleOptionFrameV3::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX],
            QStyleOptionFrameV3_StyleOptionVersion_CppToPython_QStyleOptionFrameV3_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionFrameV3_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV3_StyleOptionVersion,
            is_QStyleOptionFrameV3_StyleOptionVersion_PythonToCpp_QStyleOptionFrameV3_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAMEV3_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionFrameV3::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionFrameV3::StyleOptionVersion >("QStyleOptionFrameV3::StyleOptionVersion");
}
