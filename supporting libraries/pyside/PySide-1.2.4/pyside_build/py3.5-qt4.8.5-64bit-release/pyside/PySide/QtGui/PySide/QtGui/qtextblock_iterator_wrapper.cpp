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

#include "qtextblock_iterator_wrapper.h"

// Extra includes
#include <QTextBlock>
#include <qtextobject.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QTextBlock_iteratorFunc___iter__(PyObject* self)
{
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __iter__()
            // Begin code injection

            // TEMPLATE - __iter__ - START
            Py_INCREF(self);
            pyResult = self;
            // TEMPLATE - __iter__ - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlock_iteratorFunc___next__(PyObject* self)
{
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __next__()
            // Begin code injection

            // TEMPLATE - __next__ - START
            if (!cppSelf->atEnd()) {
              pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &*cppSelf);
              ++(*cppSelf);
            }
            // TEMPLATE - __next__ - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlock_iteratorFunc_atEnd(PyObject* self)
{
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBlock::iterator*>(cppSelf)->atEnd();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBlock_iteratorFunc_fragment(PyObject* self)
{
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFragment cppResult = const_cast<const ::QTextBlock::iterator*>(cppSelf)->fragment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFRAGMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static int
Sbk_QTextBlock_iterator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextBlock::iterator >()))
        return -1;

    ::QTextBlock::iterator* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "iterator", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: iterator()
    // 1: iterator(QTextBlock::iterator)
    if (numArgs == 0) {
        overloadId = 0; // iterator()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // iterator(QTextBlock::iterator)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlock_iterator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // iterator()
        {

            if (!PyErr_Occurred()) {
                // iterator()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlock::iterator();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // iterator(const QTextBlock::iterator & o)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextBlock::iterator cppArg0_local = ::QTextBlock::iterator();
            ::QTextBlock::iterator* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // iterator(QTextBlock::iterator)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBlock::iterator(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextBlock::iterator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextBlock_iterator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextBlock_iterator_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextBlock::iterator", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.iterator", overloads);
        return -1;
}

static PyObject* Sbk_QTextBlock_iterator___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBlock::iterator& cppSelf = *(((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextBlock_iterator_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QTextBlock_iteratorFunc_atEnd, METH_NOARGS},
    {"fragment", (PyCFunction)Sbk_QTextBlock_iteratorFunc_fragment, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextBlock_iterator___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTextBlock_iteratorFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__riadd__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__riadd__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator++(int)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // operator++(int)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlock_iteratorFunc___iadd___TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator++(int)

            for(int i=0; i < cppArg0; i++, (*cppSelf)++);
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock::iterator cppResult = (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextBlock_iteratorFunc___iadd___TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.iterator.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QTextBlock_iteratorFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextBlock::iterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__risub__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__risub__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator--(int)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // operator--(int)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBlock_iteratorFunc___isub___TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator--(int)

            for(int i=0; i < cppArg0; i++, (*cppSelf)--);
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock::iterator cppResult = (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextBlock_iteratorFunc___isub___TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.iterator.__isub__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QTextBlock_iterator_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBlock::iterator& cppSelf = *(((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (pyArg)))) {
                // operator!=(const QTextBlock::iterator & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextBlock::iterator cppArg0_local = ::QTextBlock::iterator();
                ::QTextBlock::iterator* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (pyArg)))) {
                // operator==(const QTextBlock::iterator & o) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextBlock::iterator cppArg0_local = ::QTextBlock::iterator();
                ::QTextBlock::iterator* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], pythonToCpp))
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
            goto Sbk_QTextBlock_iterator_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextBlock_iterator_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextBlock_iterator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextBlock_iterator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTextBlock_iterator_TypeAsNumber;

static SbkObjectType Sbk_QTextBlock_iterator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextBlock.iterator",
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
    /*tp_traverse*/         Sbk_QTextBlock_iterator_traverse,
    /*tp_clear*/            Sbk_QTextBlock_iterator_clear,
    /*tp_richcompare*/      Sbk_QTextBlock_iterator_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             Sbk_QTextBlock_iteratorFunc___iter__,
    /*tp_iternext*/         Sbk_QTextBlock_iteratorFunc___next__,
    /*tp_methods*/          Sbk_QTextBlock_iterator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextBlock_iterator_Init,
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
static void iterator_PythonToCpp_iterator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextBlock_iterator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_iterator_PythonToCpp_iterator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlock_iterator_Type))
        return iterator_PythonToCpp_iterator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* iterator_PTR_CppToPython_iterator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextBlock::iterator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextBlock_iterator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* iterator_COPY_CppToPython_iterator(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextBlock_iterator_Type, new ::QTextBlock::iterator(*((::QTextBlock::iterator*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void iterator_PythonToCpp_iterator_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextBlock::iterator*)cppOut) = *((::QTextBlock::iterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_iterator_PythonToCpp_iterator_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBlock_iterator_Type))
        return iterator_PythonToCpp_iterator_COPY;
    return 0;
}

void init_QTextBlock_iterator(PyObject* enclosingClass)
{
    // type has number operators
    memset(&Sbk_QTextBlock_iterator_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTextBlock_iterator_TypeAsNumber.nb_inplace_subtract = Sbk_QTextBlock_iteratorFunc___isub__;
    Sbk_QTextBlock_iterator_TypeAsNumber.nb_inplace_add = Sbk_QTextBlock_iteratorFunc___iadd__;
    Sbk_QTextBlock_iterator_Type.super.ht_type.tp_as_number = &Sbk_QTextBlock_iterator_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextBlock_iterator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "iterator", "QTextBlock::iterator",
        &Sbk_QTextBlock_iterator_Type, &Shiboken::callCppDestructor< ::QTextBlock::iterator >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextBlock_iterator_Type,
        iterator_PythonToCpp_iterator_PTR,
        is_iterator_PythonToCpp_iterator_PTR_Convertible,
        iterator_PTR_CppToPython_iterator,
        iterator_COPY_CppToPython_iterator);

    Shiboken::Conversions::registerConverterName(converter, "QTextBlock::iterator");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlock::iterator*");
    Shiboken::Conversions::registerConverterName(converter, "QTextBlock::iterator&");
    Shiboken::Conversions::registerConverterName(converter, "iterator");
    Shiboken::Conversions::registerConverterName(converter, "iterator*");
    Shiboken::Conversions::registerConverterName(converter, "iterator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBlock::iterator).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        iterator_PythonToCpp_iterator_COPY,
        is_iterator_PythonToCpp_iterator_COPY_Convertible);


    qRegisterMetaType< ::QTextBlock::iterator >("iterator");
    qRegisterMetaType< ::QTextBlock::iterator >("QTextBlock::iterator");
}
