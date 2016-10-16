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

#include "qtextencoder_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qtextcodec.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextEncoder_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextEncoder >()))
        return -1;

    ::QTextEncoder* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextEncoder", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTextEncoder(const QTextCodec*)
    // 1: QTextEncoder(const QTextCodec*,QFlags<QTextCodec::ConversionFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QTextEncoder(const QTextCodec*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTCODEC_CONVERSIONFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // QTextEncoder(const QTextCodec*,QFlags<QTextCodec::ConversionFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextEncoder_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextEncoder(const QTextCodec * codec)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextCodec* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextEncoder(const QTextCodec*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextEncoder(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextEncoder(const QTextCodec * codec, QFlags<QTextCodec::ConversionFlag> flags)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextCodec* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QTextCodec::ConversionFlag> cppArg1 = ((::QFlags<QTextCodec::ConversionFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTextEncoder(const QTextCodec*,QFlags<QTextCodec::ConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextEncoder(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextEncoder >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextEncoder_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextEncoder_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", "PySide.QtCore.QTextCodec, PySide.QtCore.QTextCodec.ConversionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextEncoder", overloads);
        return -1;
}

static PyObject* Sbk_QTextEncoderFunc_fromUnicode(PyObject* self, PyObject* pyArg)
{
    ::QTextEncoder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEncoder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTENCODER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromUnicode(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromUnicode(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextEncoderFunc_fromUnicode_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromUnicode(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = cppSelf->fromUnicode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextEncoderFunc_fromUnicode_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextEncoder.fromUnicode", overloads);
        return 0;
}

static PyObject* Sbk_QTextEncoderFunc_hasFailure(PyObject* self)
{
    ::QTextEncoder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextEncoder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTENCODER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFailure()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextEncoder*>(cppSelf)->hasFailure();
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

static PyMethodDef Sbk_QTextEncoder_methods[] = {
    {"fromUnicode", (PyCFunction)Sbk_QTextEncoderFunc_fromUnicode, METH_O},
    {"hasFailure", (PyCFunction)Sbk_QTextEncoderFunc_hasFailure, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextEncoder_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextEncoder_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextEncoder_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextEncoder",
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
    /*tp_traverse*/         Sbk_QTextEncoder_traverse,
    /*tp_clear*/            Sbk_QTextEncoder_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextEncoder_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextEncoder_Init,
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
static void QTextEncoder_PythonToCpp_QTextEncoder_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextEncoder_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextEncoder_PythonToCpp_QTextEncoder_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextEncoder_Type))
        return QTextEncoder_PythonToCpp_QTextEncoder_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextEncoder_PTR_CppToPython_QTextEncoder(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextEncoder*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextEncoder_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTextEncoder(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTEXTENCODER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextEncoder_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextEncoder", "QTextEncoder*",
        &Sbk_QTextEncoder_Type, &Shiboken::callCppDestructor< ::QTextEncoder >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextEncoder_Type,
        QTextEncoder_PythonToCpp_QTextEncoder_PTR,
        is_QTextEncoder_PythonToCpp_QTextEncoder_PTR_Convertible,
        QTextEncoder_PTR_CppToPython_QTextEncoder);

    Shiboken::Conversions::registerConverterName(converter, "QTextEncoder");
    Shiboken::Conversions::registerConverterName(converter, "QTextEncoder*");
    Shiboken::Conversions::registerConverterName(converter, "QTextEncoder&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextEncoder).name());



}
