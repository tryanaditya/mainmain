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

#include "qtextoption_tab_wrapper.h"

// Extra includes
#include <qtextoption.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextOption_Tab_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextOption::Tab >()))
        return -1;

    ::QTextOption::Tab* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.Tab(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:Tab", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: Tab()
    // 1: Tab(QTextOption::Tab)
    // 2: Tab(qreal,QTextOption::TabType,QChar)
    if (numArgs == 0) {
        overloadId = 0; // Tab()
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // Tab(qreal,QTextOption::TabType,QChar)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArgs[2])))) {
            overloadId = 2; // Tab(qreal,QTextOption::TabType,QChar)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (pyArgs[0])))) {
        overloadId = 1; // Tab(QTextOption::Tab)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextOption_Tab_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Tab()
        {

            if (!PyErr_Occurred()) {
                // Tab()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption::Tab();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Tab(const QTextOption::Tab & Tab)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextOption::Tab cppArg0_local = ::QTextOption::Tab();
            ::QTextOption::Tab* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // Tab(QTextOption::Tab)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption::Tab(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // Tab(qreal pos, QTextOption::TabType tabType, QChar delim)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "delim");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.Tab(): got multiple values for keyword argument 'delim'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyArgs[2]))))
                        goto Sbk_QTextOption_Tab_Init_TypeError;
                }
            }
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QTextOption::TabType cppArg1 = ((::QTextOption::TabType)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QChar cppArg2 = QChar();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // Tab(qreal,QTextOption::TabType,QChar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextOption::Tab(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextOption::Tab >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextOption_Tab_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextOption_Tab_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextOption::Tab", "float, PySide.QtGui.QTextOption.TabType, 1-unicode = QChar()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.Tab", overloads);
        return -1;
}

static PyObject* Sbk_QTextOption_Tab___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextOption::Tab& cppSelf = *(((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextOption_Tab_methods[] = {

    {"__copy__", (PyCFunction)Sbk_QTextOption_Tab___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QTextOption_Tab_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextOption::Tab& cppSelf = *(((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (pyArg)))) {
                // operator!=(const QTextOption::Tab & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextOption::Tab cppArg0_local = ::QTextOption::Tab();
                ::QTextOption::Tab* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (pyArg)))) {
                // operator==(const QTextOption::Tab & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextOption::Tab cppArg0_local = ::QTextOption::Tab();
                ::QTextOption::Tab* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QTextOption_Tab_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextOption_Tab_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

static PyObject* Sbk_QTextOption_Tab_get_delimiter(PyObject* self, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], &cppSelf->delimiter);
    return pyOut;
}
static int Sbk_QTextOption_Tab_set_delimiter(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'delimiter' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'delimiter', 'QChar' or convertible type expected");
        return -1;
    }

    ::QChar& cppOut_ptr = cppSelf->delimiter;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QTextOption_Tab_get_position(PyObject* self, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->position);
    return pyOut;
}
static int Sbk_QTextOption_Tab_set_position(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'position' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'position', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->position;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QTextOption_Tab_get_type(PyObject* self, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    ::QTextOption::TabType cppOut_local = cppSelf->type;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QTextOption_Tab_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::QTextOption::Tab* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'TabType' or convertible type expected");
        return -1;
    }

    ::QTextOption::TabType cppOut_local = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->type = cppOut_local;

    return 0;
}

// Getters and Setters for Tab
static PyGetSetDef Sbk_QTextOption_Tab_getsetlist[] = {
    {const_cast<char*>("delimiter"), Sbk_QTextOption_Tab_get_delimiter, Sbk_QTextOption_Tab_set_delimiter},
    {const_cast<char*>("position"), Sbk_QTextOption_Tab_get_position, Sbk_QTextOption_Tab_set_position},
    {const_cast<char*>("type"), Sbk_QTextOption_Tab_get_type, Sbk_QTextOption_Tab_set_type},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QTextOption_Tab_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextOption_Tab_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextOption_Tab_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextOption.Tab",
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
    /*tp_traverse*/         Sbk_QTextOption_Tab_traverse,
    /*tp_clear*/            Sbk_QTextOption_Tab_clear,
    /*tp_richcompare*/      Sbk_QTextOption_Tab_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextOption_Tab_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QTextOption_Tab_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextOption_Tab_Init,
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
static void Tab_PythonToCpp_Tab_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextOption_Tab_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Tab_PythonToCpp_Tab_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextOption_Tab_Type))
        return Tab_PythonToCpp_Tab_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Tab_PTR_CppToPython_Tab(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextOption::Tab*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextOption_Tab_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* Tab_COPY_CppToPython_Tab(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextOption_Tab_Type, new ::QTextOption::Tab(*((::QTextOption::Tab*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void Tab_PythonToCpp_Tab_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextOption::Tab*)cppOut) = *((::QTextOption::Tab*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_Tab_PythonToCpp_Tab_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextOption_Tab_Type))
        return Tab_PythonToCpp_Tab_COPY;
    return 0;
}

void init_QTextOption_Tab(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextOption_Tab_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Tab", "QTextOption::Tab",
        &Sbk_QTextOption_Tab_Type, &Shiboken::callCppDestructor< ::QTextOption::Tab >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextOption_Tab_Type,
        Tab_PythonToCpp_Tab_PTR,
        is_Tab_PythonToCpp_Tab_PTR_Convertible,
        Tab_PTR_CppToPython_Tab,
        Tab_COPY_CppToPython_Tab);

    Shiboken::Conversions::registerConverterName(converter, "QTextOption::Tab");
    Shiboken::Conversions::registerConverterName(converter, "QTextOption::Tab*");
    Shiboken::Conversions::registerConverterName(converter, "QTextOption::Tab&");
    Shiboken::Conversions::registerConverterName(converter, "Tab");
    Shiboken::Conversions::registerConverterName(converter, "Tab*");
    Shiboken::Conversions::registerConverterName(converter, "Tab&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextOption::Tab).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Tab_PythonToCpp_Tab_COPY,
        is_Tab_PythonToCpp_Tab_COPY_Convertible);


    qRegisterMetaType< ::QTextOption::Tab >("Tab");
    qRegisterMetaType< ::QTextOption::Tab >("QTextOption::Tab");
}
