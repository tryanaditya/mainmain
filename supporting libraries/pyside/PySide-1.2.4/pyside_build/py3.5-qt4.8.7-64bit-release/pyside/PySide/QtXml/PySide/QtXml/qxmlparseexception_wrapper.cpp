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
#include "pyside_qtxml_python.h"

#include "qxmlparseexception_wrapper.h"

// Extra includes
#include <qxml.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlParseException_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlParseException >()))
        return -1;

    ::QXmlParseException* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QXmlParseException", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlParseException(QString,int,int,QString,QString)
    // 1: QXmlParseException(QXmlParseException)
    if (numArgs == 0) {
        overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlParseException(QXmlParseException)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 0; // QXmlParseException(QString,int,int,QString,QString)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlParseException_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlParseException(const QString & name, int c, int l, const QString & p, const QString & s)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "name");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): got multiple values for keyword argument 'name'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QXmlParseException_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "c");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): got multiple values for keyword argument 'c'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QXmlParseException_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "l");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): got multiple values for keyword argument 'l'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QXmlParseException_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "p");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): got multiple values for keyword argument 'p'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QXmlParseException_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "s");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QXmlParseException(): got multiple values for keyword argument 's'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                        goto Sbk_QXmlParseException_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = -1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QString cppArg4 = QString();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QXmlParseException(QString,int,int,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlParseException(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlParseException(const QXmlParseException & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlParseException* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QXmlParseException(QXmlParseException)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlParseException(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlParseException >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlParseException_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlParseException_Init_TypeError:
        const char* overloads[] = {"unicode = QString(), int = -1, int = -1, unicode = QString(), unicode = QString()", "PySide.QtXml.QXmlParseException", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlParseException", overloads);
        return -1;
}

static PyObject* Sbk_QXmlParseExceptionFunc_columnNumber(PyObject* self)
{
    ::QXmlParseException* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlParseException*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlParseException*>(cppSelf)->columnNumber();
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

static PyObject* Sbk_QXmlParseExceptionFunc_lineNumber(PyObject* self)
{
    ::QXmlParseException* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlParseException*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlParseException*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QXmlParseExceptionFunc_message(PyObject* self)
{
    ::QXmlParseException* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlParseException*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // message()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlParseException*>(cppSelf)->message();
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

static PyObject* Sbk_QXmlParseExceptionFunc_publicId(PyObject* self)
{
    ::QXmlParseException* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlParseException*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // publicId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlParseException*>(cppSelf)->publicId();
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

static PyObject* Sbk_QXmlParseExceptionFunc_systemId(PyObject* self)
{
    ::QXmlParseException* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlParseException*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlParseException*>(cppSelf)->systemId();
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

static PyMethodDef Sbk_QXmlParseException_methods[] = {
    {"columnNumber", (PyCFunction)Sbk_QXmlParseExceptionFunc_columnNumber, METH_NOARGS},
    {"lineNumber", (PyCFunction)Sbk_QXmlParseExceptionFunc_lineNumber, METH_NOARGS},
    {"message", (PyCFunction)Sbk_QXmlParseExceptionFunc_message, METH_NOARGS},
    {"publicId", (PyCFunction)Sbk_QXmlParseExceptionFunc_publicId, METH_NOARGS},
    {"systemId", (PyCFunction)Sbk_QXmlParseExceptionFunc_systemId, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlParseException_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlParseException_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlParseException_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlParseException",
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
    /*tp_traverse*/         Sbk_QXmlParseException_traverse,
    /*tp_clear*/            Sbk_QXmlParseException_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlParseException_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlParseException_Init,
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
static void QXmlParseException_PythonToCpp_QXmlParseException_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlParseException_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlParseException_PythonToCpp_QXmlParseException_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlParseException_Type))
        return QXmlParseException_PythonToCpp_QXmlParseException_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlParseException_PTR_CppToPython_QXmlParseException(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlParseException*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlParseException_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlParseException(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLPARSEEXCEPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlParseException_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlParseException", "QXmlParseException*",
        &Sbk_QXmlParseException_Type, &Shiboken::callCppDestructor< ::QXmlParseException >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlParseException_Type,
        QXmlParseException_PythonToCpp_QXmlParseException_PTR,
        is_QXmlParseException_PythonToCpp_QXmlParseException_PTR_Convertible,
        QXmlParseException_PTR_CppToPython_QXmlParseException);

    Shiboken::Conversions::registerConverterName(converter, "QXmlParseException");
    Shiboken::Conversions::registerConverterName(converter, "QXmlParseException*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlParseException&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlParseException).name());



}
