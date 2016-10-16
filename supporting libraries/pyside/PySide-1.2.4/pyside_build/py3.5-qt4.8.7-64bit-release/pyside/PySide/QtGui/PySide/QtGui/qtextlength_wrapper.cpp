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

#include "qtextlength_wrapper.h"

// Extra includes
#include <qdatastream.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextLength_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextLength >()))
        return -1;

    ::QTextLength* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextLength", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTextLength()
    // 1: QTextLength(QTextLength::Type,qreal)
    // 2: QTextLength(QTextLength)
    if (numArgs == 0) {
        overloadId = 0; // QTextLength()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextLength(QTextLength)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // QTextLength(QTextLength::Type,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLength_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextLength()
        {

            if (!PyErr_Occurred()) {
                // QTextLength()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLength();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextLength(QTextLength::Type type, qreal value)
        {
            ::QTextLength::Type cppArg0 = ((::QTextLength::Type)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTextLength(QTextLength::Type,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLength(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextLength(const QTextLength & QTextLength)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextLength cppArg0_local = ::QTextLength();
            ::QTextLength* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextLength(QTextLength)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextLength(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextLength >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextLength_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextLength_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextLength.Type, float", "PySide.QtGui.QTextLength", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextLength", overloads);
        return -1;
}

static PyObject* Sbk_QTextLengthFunc_rawValue(PyObject* self)
{
    ::QTextLength* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLength*>(cppSelf)->rawValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextLengthFunc_type(PyObject* self)
{
    ::QTextLength* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextLength::Type cppResult = const_cast<const ::QTextLength*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextLengthFunc_value(PyObject* self, PyObject* pyArg)
{
    ::QTextLength* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: value(qreal)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // value(qreal)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLengthFunc_value_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // value(qreal)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextLength*>(cppSelf)->value(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextLengthFunc_value_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLength.value", overloads);
        return 0;
}

static PyObject* Sbk_QTextLength___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextLength& cppSelf = *(((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextLength_methods[] = {
    {"rawValue", (PyCFunction)Sbk_QTextLengthFunc_rawValue, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QTextLengthFunc_type, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QTextLengthFunc_value, METH_O},

    {"__copy__", (PyCFunction)Sbk_QTextLength___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTextLengthFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextLength* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
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
    // 0: operator<<(QDataStream&,QTextLength)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QTextLength)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLengthFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QTextLength) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextLengthFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLength.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QTextLengthFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTextLength* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
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
    // 0: operator>>(QDataStream&,QTextLength&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QTextLength&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextLengthFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QTextLength&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextLengthFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextLength.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QTextLength_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextLength& cppSelf = *(((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (pyArg)))) {
                // operator!=(const QTextLength & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextLength cppArg0_local = ::QTextLength();
                ::QTextLength* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (pyArg)))) {
                // operator==(const QTextLength & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTextLength cppArg0_local = ::QTextLength();
                ::QTextLength* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], pythonToCpp))
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
            goto Sbk_QTextLength_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTextLength_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTextLength_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextLength_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTextLength_TypeAsNumber;

static SbkObjectType Sbk_QTextLength_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextLength",
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
    /*tp_traverse*/         Sbk_QTextLength_traverse,
    /*tp_clear*/            Sbk_QTextLength_clear,
    /*tp_richcompare*/      Sbk_QTextLength_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextLength_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextLength_Init,
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
static void QTextLength_Type_PythonToCpp_QTextLength_Type(PyObject* pyIn, void* cppOut) {
    *((::QTextLength::Type*)cppOut) = (::QTextLength::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextLength_Type_PythonToCpp_QTextLength_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX]))
        return QTextLength_Type_PythonToCpp_QTextLength_Type;
    return 0;
}
static PyObject* QTextLength_Type_CppToPython_QTextLength_Type(const void* cppIn) {
    int castCppIn = *((::QTextLength::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextLength_PythonToCpp_QTextLength_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextLength_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextLength_PythonToCpp_QTextLength_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLength_Type))
        return QTextLength_PythonToCpp_QTextLength_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextLength_PTR_CppToPython_QTextLength(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextLength*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextLength_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextLength_COPY_CppToPython_QTextLength(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextLength_Type, new ::QTextLength(*((::QTextLength*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextLength_PythonToCpp_QTextLength_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextLength*)cppOut) = *((::QTextLength*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextLength_PythonToCpp_QTextLength_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextLength_Type))
        return QTextLength_PythonToCpp_QTextLength_COPY;
    return 0;
}

void init_QTextLength(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTextLength_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTextLength_TypeAsNumber.nb_rshift = Sbk_QTextLengthFunc___rshift__;
    Sbk_QTextLength_TypeAsNumber.nb_lshift = Sbk_QTextLengthFunc___lshift__;
    Sbk_QTextLength_Type.super.ht_type.tp_as_number = &Sbk_QTextLength_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextLength_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextLength", "QTextLength",
        &Sbk_QTextLength_Type, &Shiboken::callCppDestructor< ::QTextLength >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextLength_Type,
        QTextLength_PythonToCpp_QTextLength_PTR,
        is_QTextLength_PythonToCpp_QTextLength_PTR_Convertible,
        QTextLength_PTR_CppToPython_QTextLength,
        QTextLength_COPY_CppToPython_QTextLength);

    Shiboken::Conversions::registerConverterName(converter, "QTextLength");
    Shiboken::Conversions::registerConverterName(converter, "QTextLength*");
    Shiboken::Conversions::registerConverterName(converter, "QTextLength&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextLength).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextLength_PythonToCpp_QTextLength_COPY,
        is_QTextLength_PythonToCpp_QTextLength_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextLength_Type,
        "Type",
        "PySide.QtGui.QTextLength.Type",
        "QTextLength::Type");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX],
        &Sbk_QTextLength_Type, "VariableLength", (long) QTextLength::VariableLength))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX],
        &Sbk_QTextLength_Type, "FixedLength", (long) QTextLength::FixedLength))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX],
        &Sbk_QTextLength_Type, "PercentageLength", (long) QTextLength::PercentageLength))
        return ;
    // Register converter for enum 'QTextLength::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX],
            QTextLength_Type_CppToPython_QTextLength_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextLength_Type_PythonToCpp_QTextLength_Type,
            is_QTextLength_Type_PythonToCpp_QTextLength_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextLength::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


    qRegisterMetaType< ::QTextLength >("QTextLength");
    qRegisterMetaType< ::QTextLength::Type >("QTextLength::Type");
}
