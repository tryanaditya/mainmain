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
#include "pyside_qtscript_python.h"

#include "qscriptprogram_wrapper.h"

// Extra includes
#include <qscriptprogram.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptProgram_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptProgram >()))
        return -1;

    ::QScriptProgram* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptProgram(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QScriptProgram", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptProgram()
    // 1: QScriptProgram(QScriptProgram)
    // 2: QScriptProgram(QString,QString,int)
    if (numArgs == 0) {
        overloadId = 0; // QScriptProgram()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QScriptProgram(QString,QString,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QScriptProgram(QString,QString,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 2; // QScriptProgram(QString,QString,int)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QScriptProgram(QScriptProgram)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptProgram_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QScriptProgram()
        {

            if (!PyErr_Occurred()) {
                // QScriptProgram()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptProgram();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QScriptProgram(const QScriptProgram & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptProgram cppArg0_local = ::QScriptProgram();
            ::QScriptProgram* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QScriptProgram(QScriptProgram)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptProgram(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QScriptProgram(const QString & sourceCode, const QString fileName, int firstLineNumber)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fileName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptProgram(): got multiple values for keyword argument 'fileName'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QScriptProgram_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "firstLineNumber");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptProgram(): got multiple values for keyword argument 'firstLineNumber'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QScriptProgram_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QScriptProgram(QString,QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptProgram(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptProgram >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptProgram_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QScriptProgram_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtScript.QScriptProgram", "unicode, unicode = QString(), int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptProgram", overloads);
        return -1;
}

static PyObject* Sbk_QScriptProgramFunc_fileName(PyObject* self)
{
    ::QScriptProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptProgram*>(cppSelf)->fileName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptProgramFunc_firstLineNumber(PyObject* self)
{
    ::QScriptProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstLineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptProgram*>(cppSelf)->firstLineNumber();
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

static PyObject* Sbk_QScriptProgramFunc_isNull(PyObject* self)
{
    ::QScriptProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptProgram*>(cppSelf)->isNull();
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

static PyObject* Sbk_QScriptProgramFunc_sourceCode(PyObject* self)
{
    ::QScriptProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sourceCode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptProgram*>(cppSelf)->sourceCode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptProgram___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptProgram& cppSelf = *(((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QScriptProgram_methods[] = {
    {"fileName", (PyCFunction)Sbk_QScriptProgramFunc_fileName, METH_NOARGS},
    {"firstLineNumber", (PyCFunction)Sbk_QScriptProgramFunc_firstLineNumber, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QScriptProgramFunc_isNull, METH_NOARGS},
    {"sourceCode", (PyCFunction)Sbk_QScriptProgramFunc_sourceCode, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QScriptProgram___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QScriptProgram___nb_bool(PyObject* self)
{
    ::QScriptProgram* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QScriptProgram_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptProgram& cppSelf = *(((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (pyArg)))) {
                // operator!=(const QScriptProgram & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QScriptProgram cppArg0_local = ::QScriptProgram();
                ::QScriptProgram* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (pyArg)))) {
                // operator==(const QScriptProgram & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QScriptProgram cppArg0_local = ::QScriptProgram();
                ::QScriptProgram* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], pythonToCpp))
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
            goto Sbk_QScriptProgram_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QScriptProgram_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QScriptProgram_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptProgram_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QScriptProgram_TypeAsNumber;

static SbkObjectType Sbk_QScriptProgram_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptProgram",
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
    /*tp_traverse*/         Sbk_QScriptProgram_traverse,
    /*tp_clear*/            Sbk_QScriptProgram_clear,
    /*tp_richcompare*/      Sbk_QScriptProgram_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptProgram_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptProgram_Init,
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
static void QScriptProgram_PythonToCpp_QScriptProgram_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptProgram_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptProgram_PythonToCpp_QScriptProgram_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptProgram_Type))
        return QScriptProgram_PythonToCpp_QScriptProgram_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptProgram_PTR_CppToPython_QScriptProgram(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptProgram*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptProgram_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QScriptProgram_COPY_CppToPython_QScriptProgram(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QScriptProgram_Type, new ::QScriptProgram(*((::QScriptProgram*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QScriptProgram_PythonToCpp_QScriptProgram_COPY(PyObject* pyIn, void* cppOut) {
    *((::QScriptProgram*)cppOut) = *((::QScriptProgram*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QScriptProgram_PythonToCpp_QScriptProgram_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptProgram_Type))
        return QScriptProgram_PythonToCpp_QScriptProgram_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_constQStringREF_PythonToCpp_QScriptProgram(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QScriptProgram*)cppOut) = ::QScriptProgram(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QScriptProgram_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QScriptProgram;
    return 0;
}

void init_QScriptProgram(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QScriptProgram_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QScriptProgram_TypeAsNumber) = Sbk_QScriptProgram___nb_bool;
    Sbk_QScriptProgram_Type.super.ht_type.tp_as_number = &Sbk_QScriptProgram_TypeAsNumber;

    SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptProgram_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptProgram", "QScriptProgram",
        &Sbk_QScriptProgram_Type, &Shiboken::callCppDestructor< ::QScriptProgram >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptProgram_Type,
        QScriptProgram_PythonToCpp_QScriptProgram_PTR,
        is_QScriptProgram_PythonToCpp_QScriptProgram_PTR_Convertible,
        QScriptProgram_PTR_CppToPython_QScriptProgram,
        QScriptProgram_COPY_CppToPython_QScriptProgram);

    Shiboken::Conversions::registerConverterName(converter, "QScriptProgram");
    Shiboken::Conversions::registerConverterName(converter, "QScriptProgram*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptProgram&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptProgram).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QScriptProgram_PythonToCpp_QScriptProgram_COPY,
        is_QScriptProgram_PythonToCpp_QScriptProgram_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QScriptProgram,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QScriptProgram_Convertible);


    qRegisterMetaType< ::QScriptProgram >("QScriptProgram");
}
