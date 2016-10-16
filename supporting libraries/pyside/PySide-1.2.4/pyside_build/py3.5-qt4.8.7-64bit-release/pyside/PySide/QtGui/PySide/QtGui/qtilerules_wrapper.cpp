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

#include "qtilerules_wrapper.h"

// Extra includes



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTileRules_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTileRules >()))
        return -1;

    ::QTileRules* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTileRules(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QTileRules", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTileRules(Qt::TileRule,Qt::TileRule)
    // 1: QTileRules(Qt::TileRule)
    // 2: QTileRules(QTileRules)
    if (numArgs == 0) {
        overloadId = 1; // QTileRules(Qt::TileRule)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QTileRules(Qt::TileRule)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // QTileRules(Qt::TileRule,Qt::TileRule)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTileRules(QTileRules)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTileRules_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTileRules(Qt::TileRule horizontalRule, Qt::TileRule verticalRule)
        {
            ::Qt::TileRule cppArg0 = ((::Qt::TileRule)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::TileRule cppArg1 = ((::Qt::TileRule)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTileRules(Qt::TileRule,Qt::TileRule)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTileRules(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTileRules(Qt::TileRule rule)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rule");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTileRules(): got multiple values for keyword argument 'rule'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), (pyArgs[0]))))
                        goto Sbk_QTileRules_Init_TypeError;
                }
            }
            ::Qt::TileRule cppArg0 = Qt::StretchTile;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTileRules(Qt::TileRule)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTileRules(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTileRules(const QTileRules & QTileRules)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTileRules cppArg0_local = ::QTileRules(((::Qt::TileRule)0), ((::Qt::TileRule)0));
            ::QTileRules* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTileRules(QTileRules)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTileRules(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTileRules >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTileRules_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTileRules_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TileRule, PySide.QtCore.Qt.TileRule", "PySide.QtCore.Qt.TileRule = Qt.StretchTile", "PySide.QtGui.QTileRules", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTileRules", overloads);
        return -1;
}

static PyObject* Sbk_QTileRules___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTileRules& cppSelf = *(((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTileRules_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QTileRules___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTileRules_get_vertical(PyObject* self, void*)
{
    ::QTileRules* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)self));
    ::Qt::TileRule cppOut_local = cppSelf->vertical;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QTileRules_set_vertical(PyObject* self, PyObject* pyIn, void*)
{
    ::QTileRules* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'vertical' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'vertical', 'TileRule' or convertible type expected");
        return -1;
    }

    ::Qt::TileRule cppOut_local = cppSelf->vertical;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->vertical = cppOut_local;

    return 0;
}

static PyObject* Sbk_QTileRules_get_horizontal(PyObject* self, void*)
{
    ::QTileRules* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)self));
    ::Qt::TileRule cppOut_local = cppSelf->horizontal;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QTileRules_set_horizontal(PyObject* self, PyObject* pyIn, void*)
{
    ::QTileRules* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'horizontal' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'horizontal', 'TileRule' or convertible type expected");
        return -1;
    }

    ::Qt::TileRule cppOut_local = cppSelf->horizontal;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->horizontal = cppOut_local;

    return 0;
}

// Getters and Setters for QTileRules
static PyGetSetDef Sbk_QTileRules_getsetlist[] = {
    {const_cast<char*>("vertical"), Sbk_QTileRules_get_vertical, Sbk_QTileRules_set_vertical},
    {const_cast<char*>("horizontal"), Sbk_QTileRules_get_horizontal, Sbk_QTileRules_set_horizontal},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QTileRules_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTileRules_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTileRules_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTileRules",
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
    /*tp_traverse*/         Sbk_QTileRules_traverse,
    /*tp_clear*/            Sbk_QTileRules_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTileRules_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QTileRules_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTileRules_Init,
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
static void QTileRules_PythonToCpp_QTileRules_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTileRules_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTileRules_PythonToCpp_QTileRules_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTileRules_Type))
        return QTileRules_PythonToCpp_QTileRules_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTileRules_PTR_CppToPython_QTileRules(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTileRules*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTileRules_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTileRules_COPY_CppToPython_QTileRules(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTileRules_Type, new ::QTileRules(*((::QTileRules*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTileRules_PythonToCpp_QTileRules_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTileRules*)cppOut) = *((::QTileRules*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTileRules_PythonToCpp_QTileRules_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTileRules_Type))
        return QTileRules_PythonToCpp_QTileRules_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_Qt_TileRule_PythonToCpp_QTileRules(PyObject* pyIn, void* cppOut) {
    ::Qt::TileRule cppIn = ((::Qt::TileRule)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX]), pyIn, &cppIn);
    *((::QTileRules*)cppOut) = ::QTileRules(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_TileRule_PythonToCpp_QTileRules_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_TILERULE_IDX], pyIn))
        return PySide_QtCore_Qt_TileRule_PythonToCpp_QTileRules;
    return 0;
}

void init_QTileRules(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTILERULES_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTileRules_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTileRules", "QTileRules",
        &Sbk_QTileRules_Type, &Shiboken::callCppDestructor< ::QTileRules >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTileRules_Type,
        QTileRules_PythonToCpp_QTileRules_PTR,
        is_QTileRules_PythonToCpp_QTileRules_PTR_Convertible,
        QTileRules_PTR_CppToPython_QTileRules,
        QTileRules_COPY_CppToPython_QTileRules);

    Shiboken::Conversions::registerConverterName(converter, "QTileRules");
    Shiboken::Conversions::registerConverterName(converter, "QTileRules*");
    Shiboken::Conversions::registerConverterName(converter, "QTileRules&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTileRules).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTileRules_PythonToCpp_QTileRules_COPY,
        is_QTileRules_PythonToCpp_QTileRules_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_TileRule_PythonToCpp_QTileRules,
        is_PySide_QtCore_Qt_TileRule_PythonToCpp_QTileRules_Convertible);


}
