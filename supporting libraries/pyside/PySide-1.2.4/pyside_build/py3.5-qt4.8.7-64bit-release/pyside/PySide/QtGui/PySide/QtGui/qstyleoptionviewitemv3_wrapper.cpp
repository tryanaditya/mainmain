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

#include "qstyleoptionviewitemv3_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionViewItemV3_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionViewItemV3 >()))
        return -1;

    ::QStyleOptionViewItemV3* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionViewItemV3", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionViewItemV3()
    // 1: QStyleOptionViewItemV3(QStyleOptionViewItem)
    // 2: QStyleOptionViewItemV3(QStyleOptionViewItemV3)
    // 3: QStyleOptionViewItemV3(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionViewItemV3()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QStyleOptionViewItemV3(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionViewItemV3(QStyleOptionViewItemV3)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionViewItemV3(QStyleOptionViewItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionViewItemV3_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionViewItemV3()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV3()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV3();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionViewItemV3(const QStyleOptionViewItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionViewItem cppArg0_local = ::QStyleOptionViewItem();
            ::QStyleOptionViewItem* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV3(QStyleOptionViewItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV3(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionViewItemV3(const QStyleOptionViewItemV3 & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionViewItemV3 cppArg0_local = ::QStyleOptionViewItemV3();
            ::QStyleOptionViewItemV3* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV3(QStyleOptionViewItemV3)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV3(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStyleOptionViewItemV3(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionViewItemV3(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionViewItemV3(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionViewItemV3 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionViewItemV3_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionViewItemV3_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionViewItem", "PySide.QtGui.QStyleOptionViewItemV3", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionViewItemV3", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionViewItemV3___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStyleOptionViewItemV3& cppSelf = *(((::QStyleOptionViewItemV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QStyleOptionViewItemV3_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QStyleOptionViewItemV3___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionViewItemV3_get_widget(PyObject* self, void*)
{
    ::QStyleOptionViewItemV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppSelf->widget);
    return pyOut;
}

static PyObject* Sbk_QStyleOptionViewItemV3_get_locale(PyObject* self, void*)
{
    ::QStyleOptionViewItemV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &(cppSelf->locale), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionViewItemV3_set_locale(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionViewItemV3* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionViewItemV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'locale' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'locale', 'QLocale' or convertible type expected");
        return -1;
    }

    ::QLocale& cppOut_ptr = cppSelf->locale;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionViewItemV3
static PyGetSetDef Sbk_QStyleOptionViewItemV3_getsetlist[] = {
    {const_cast<char*>("widget"), Sbk_QStyleOptionViewItemV3_get_widget, 0},
    {const_cast<char*>("locale"), Sbk_QStyleOptionViewItemV3_get_locale, Sbk_QStyleOptionViewItemV3_set_locale},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionViewItemV3_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionViewItemV3_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionViewItemV3_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionViewItemV3",
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
    /*tp_traverse*/         Sbk_QStyleOptionViewItemV3_traverse,
    /*tp_clear*/            Sbk_QStyleOptionViewItemV3_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionViewItemV3_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionViewItemV3_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionViewItemV3_Init,
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
static void QStyleOptionViewItemV3_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV3_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV3::StyleOptionVersion*)cppOut) = (::QStyleOptionViewItemV3::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionViewItemV3_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV3_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionViewItemV3_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV3_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionViewItemV3_StyleOptionVersion_CppToPython_QStyleOptionViewItemV3_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionViewItemV3::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionViewItemV3_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV3_Type))
        return QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionViewItemV3_PTR_CppToPython_QStyleOptionViewItemV3(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionViewItemV3*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV3_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QStyleOptionViewItemV3_COPY_CppToPython_QStyleOptionViewItemV3(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QStyleOptionViewItemV3_Type, new ::QStyleOptionViewItemV3(*((::QStyleOptionViewItemV3*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_COPY(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV3*)cppOut) = *((::QStyleOptionViewItemV3*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionViewItemV3_Type))
        return QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_COPY;
    return 0;
}

// Implicit conversions.
static void constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV3(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionViewItemV3*)cppOut) = ::QStyleOptionViewItemV3(*((::QStyleOptionViewItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV3_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pyIn))
        return constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV3;
    return 0;
}

void init_QStyleOptionViewItemV3(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionViewItemV3_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionViewItemV3", "QStyleOptionViewItemV3",
        &Sbk_QStyleOptionViewItemV3_Type, &Shiboken::callCppDestructor< ::QStyleOptionViewItemV3 >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV2_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionViewItemV3_Type,
        QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_PTR,
        is_QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_PTR_Convertible,
        QStyleOptionViewItemV3_PTR_CppToPython_QStyleOptionViewItemV3,
        QStyleOptionViewItemV3_COPY_CppToPython_QStyleOptionViewItemV3);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV3");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV3*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV3&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionViewItemV3).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_COPY,
        is_QStyleOptionViewItemV3_PythonToCpp_QStyleOptionViewItemV3_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV3,
        is_constQStyleOptionViewItemREF_PythonToCpp_QStyleOptionViewItemV3_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionViewItemV3_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionViewItemV3.StyleOptionVersion",
        "QStyleOptionViewItemV3::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionViewItemV3_Type, "Version", (long) QStyleOptionViewItemV3::Version))
        return ;
    // Register converter for enum 'QStyleOptionViewItemV3::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX],
            QStyleOptionViewItemV3_StyleOptionVersion_CppToPython_QStyleOptionViewItemV3_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionViewItemV3_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV3_StyleOptionVersion,
            is_QStyleOptionViewItemV3_StyleOptionVersion_PythonToCpp_QStyleOptionViewItemV3_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEMV3_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionViewItemV3::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionViewItemV3 >("QStyleOptionViewItemV3");
    qRegisterMetaType< ::QStyleOptionViewItemV3::StyleOptionVersion >("QStyleOptionViewItemV3::StyleOptionVersion");
}
