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
#include "pyside_qtcore_python.h"

#include "qbytearraymatcher_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qbytearraymatcher.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QByteArrayMatcher_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QByteArrayMatcher >()))
        return -1;

    ::QByteArrayMatcher* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QByteArrayMatcher", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QByteArrayMatcher()
    // 1: QByteArrayMatcher(QByteArray)
    // 2: QByteArrayMatcher(QByteArrayMatcher)
    // 3: QByteArrayMatcher(const char*,int)
    if (numArgs == 0) {
        overloadId = 0; // QByteArrayMatcher()
    } else if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 3; // QByteArrayMatcher(const char*,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (pyArgs[0])))) {
        overloadId = 2; // QByteArrayMatcher(QByteArrayMatcher)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QByteArrayMatcher(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayMatcher_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QByteArrayMatcher()
        {

            if (!PyErr_Occurred()) {
                // QByteArrayMatcher()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArrayMatcher();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QByteArrayMatcher(const QByteArray & pattern)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QByteArrayMatcher(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArrayMatcher(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QByteArrayMatcher(const QByteArrayMatcher & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArrayMatcher cppArg0_local = ::QByteArrayMatcher();
            ::QByteArrayMatcher* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QByteArrayMatcher(QByteArrayMatcher)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArrayMatcher(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QByteArrayMatcher(const char * pattern, int length)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QByteArrayMatcher(const char*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArrayMatcher(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QByteArrayMatcher >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QByteArrayMatcher_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QByteArrayMatcher_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray", "PySide.QtCore.QByteArrayMatcher", "" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArrayMatcher", overloads);
        return -1;
}

static PyObject* Sbk_QByteArrayMatcherFunc_indexIn(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArrayMatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArrayMatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArrayMatcher.indexIn(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArrayMatcher.indexIn(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:indexIn", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: indexIn(QByteArray,int)const
    // 1: indexIn(const char*,int,int)const
    if (numArgs >= 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // indexIn(const char*,int,int)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // indexIn(const char*,int,int)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexIn(QByteArray,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // indexIn(QByteArray,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayMatcherFunc_indexIn_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // indexIn(const QByteArray & ba, int from) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "from");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArrayMatcher.indexIn(): got multiple values for keyword argument 'from'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayMatcherFunc_indexIn_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // indexIn(QByteArray,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QByteArrayMatcher*>(cppSelf)->indexIn(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // indexIn(const char * str, int len, int from) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "from");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArrayMatcher.indexIn(): got multiple values for keyword argument 'from'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QByteArrayMatcherFunc_indexIn_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // indexIn(const char*,int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QByteArrayMatcher*>(cppSelf)->indexIn(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayMatcherFunc_indexIn_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, int = 0", "" SBK_STR_NAME ", int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArrayMatcher.indexIn", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayMatcherFunc_pattern(PyObject* self)
{
    ::QByteArrayMatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArrayMatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pattern()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArrayMatcher*>(cppSelf)->pattern();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayMatcherFunc_setPattern(PyObject* self, PyObject* pyArg)
{
    ::QByteArrayMatcher* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArrayMatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPattern(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setPattern(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayMatcherFunc_setPattern_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPattern(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPattern(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayMatcherFunc_setPattern_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArrayMatcher.setPattern", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayMatcher___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArrayMatcher& cppSelf = *(((::QByteArrayMatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QByteArrayMatcher_methods[] = {
    {"indexIn", (PyCFunction)Sbk_QByteArrayMatcherFunc_indexIn, METH_VARARGS|METH_KEYWORDS},
    {"pattern", (PyCFunction)Sbk_QByteArrayMatcherFunc_pattern, METH_NOARGS},
    {"setPattern", (PyCFunction)Sbk_QByteArrayMatcherFunc_setPattern, METH_O},

    {"__copy__", (PyCFunction)Sbk_QByteArrayMatcher___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QByteArrayMatcher_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QByteArrayMatcher_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QByteArrayMatcher_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QByteArrayMatcher",
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
    /*tp_traverse*/         Sbk_QByteArrayMatcher_traverse,
    /*tp_clear*/            Sbk_QByteArrayMatcher_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QByteArrayMatcher_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QByteArrayMatcher_Init,
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
static void QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QByteArrayMatcher_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QByteArrayMatcher_Type))
        return QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QByteArrayMatcher_PTR_CppToPython_QByteArrayMatcher(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QByteArrayMatcher*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QByteArrayMatcher_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QByteArrayMatcher_COPY_CppToPython_QByteArrayMatcher(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QByteArrayMatcher_Type, new ::QByteArrayMatcher(*((::QByteArrayMatcher*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_COPY(PyObject* pyIn, void* cppOut) {
    *((::QByteArrayMatcher*)cppOut) = *((::QByteArrayMatcher*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QByteArrayMatcher_Type))
        return QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_COPY;
    return 0;
}

void init_QByteArrayMatcher(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QBYTEARRAYMATCHER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QByteArrayMatcher_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QByteArrayMatcher", "QByteArrayMatcher",
        &Sbk_QByteArrayMatcher_Type, &Shiboken::callCppDestructor< ::QByteArrayMatcher >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QByteArrayMatcher_Type,
        QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_PTR,
        is_QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_PTR_Convertible,
        QByteArrayMatcher_PTR_CppToPython_QByteArrayMatcher,
        QByteArrayMatcher_COPY_CppToPython_QByteArrayMatcher);

    Shiboken::Conversions::registerConverterName(converter, "QByteArrayMatcher");
    Shiboken::Conversions::registerConverterName(converter, "QByteArrayMatcher*");
    Shiboken::Conversions::registerConverterName(converter, "QByteArrayMatcher&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QByteArrayMatcher).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_COPY,
        is_QByteArrayMatcher_PythonToCpp_QByteArrayMatcher_COPY_Convertible);


    qRegisterMetaType< ::QByteArrayMatcher >("QByteArrayMatcher");
}
