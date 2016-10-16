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

#include "qtablewidgetselectionrange_wrapper.h"

// Extra includes
#include <qtablewidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTableWidgetSelectionRange_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTableWidgetSelectionRange >()))
        return -1;

    ::QTableWidgetSelectionRange* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QTableWidgetSelectionRange_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QTableWidgetSelectionRange", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QTableWidgetSelectionRange()
    // 1: QTableWidgetSelectionRange(QTableWidgetSelectionRange)
    // 2: QTableWidgetSelectionRange(int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QTableWidgetSelectionRange()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 2; // QTableWidgetSelectionRange(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTableWidgetSelectionRange(QTableWidgetSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetSelectionRange_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTableWidgetSelectionRange()
        {

            if (!PyErr_Occurred()) {
                // QTableWidgetSelectionRange()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetSelectionRange();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTableWidgetSelectionRange(const QTableWidgetSelectionRange & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTableWidgetSelectionRange cppArg0_local = ::QTableWidgetSelectionRange();
            ::QTableWidgetSelectionRange* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTableWidgetSelectionRange(QTableWidgetSelectionRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetSelectionRange(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTableWidgetSelectionRange(int top, int left, int bottom, int right)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QTableWidgetSelectionRange(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetSelectionRange(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTableWidgetSelectionRange >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTableWidgetSelectionRange_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTableWidgetSelectionRange_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTableWidgetSelectionRange", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTableWidgetSelectionRange", overloads);
        return -1;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_bottomRow(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottomRow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->bottomRow();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_columnCount(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->columnCount();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_leftColumn(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leftColumn()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->leftColumn();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_rightColumn(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rightColumn()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->rightColumn();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_rowCount(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->rowCount();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRangeFunc_topRow(PyObject* self)
{
    ::QTableWidgetSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topRow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetSelectionRange*>(cppSelf)->topRow();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetSelectionRange___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTableWidgetSelectionRange& cppSelf = *(((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTableWidgetSelectionRange_methods[] = {
    {"bottomRow", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_bottomRow, METH_NOARGS},
    {"columnCount", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_columnCount, METH_NOARGS},
    {"leftColumn", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_leftColumn, METH_NOARGS},
    {"rightColumn", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_rightColumn, METH_NOARGS},
    {"rowCount", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_rowCount, METH_NOARGS},
    {"topRow", (PyCFunction)Sbk_QTableWidgetSelectionRangeFunc_topRow, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTableWidgetSelectionRange___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTableWidgetSelectionRange_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTableWidgetSelectionRange_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTableWidgetSelectionRange_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTableWidgetSelectionRange",
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
    /*tp_traverse*/         Sbk_QTableWidgetSelectionRange_traverse,
    /*tp_clear*/            Sbk_QTableWidgetSelectionRange_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTableWidgetSelectionRange_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTableWidgetSelectionRange_Init,
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
static void QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTableWidgetSelectionRange_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTableWidgetSelectionRange_Type))
        return QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTableWidgetSelectionRange_PTR_CppToPython_QTableWidgetSelectionRange(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTableWidgetSelectionRange*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTableWidgetSelectionRange_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTableWidgetSelectionRange_COPY_CppToPython_QTableWidgetSelectionRange(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTableWidgetSelectionRange_Type, new ::QTableWidgetSelectionRange(*((::QTableWidgetSelectionRange*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTableWidgetSelectionRange*)cppOut) = *((::QTableWidgetSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTableWidgetSelectionRange_Type))
        return QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_COPY;
    return 0;
}

void init_QTableWidgetSelectionRange(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETSELECTIONRANGE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTableWidgetSelectionRange_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTableWidgetSelectionRange", "QTableWidgetSelectionRange",
        &Sbk_QTableWidgetSelectionRange_Type, &Shiboken::callCppDestructor< ::QTableWidgetSelectionRange >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTableWidgetSelectionRange_Type,
        QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_PTR,
        is_QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_PTR_Convertible,
        QTableWidgetSelectionRange_PTR_CppToPython_QTableWidgetSelectionRange,
        QTableWidgetSelectionRange_COPY_CppToPython_QTableWidgetSelectionRange);

    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetSelectionRange");
    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetSelectionRange*");
    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetSelectionRange&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTableWidgetSelectionRange).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_COPY,
        is_QTableWidgetSelectionRange_PythonToCpp_QTableWidgetSelectionRange_COPY_Convertible);


    qRegisterMetaType< ::QTableWidgetSelectionRange >("QTableWidgetSelectionRange");
}
