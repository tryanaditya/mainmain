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

#include "qdomtext_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomText_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomText >()))
        return -1;

    ::QDomText* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomText", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomText()
    // 1: QDomText(QDomText)
    if (numArgs == 0) {
        overloadId = 0; // QDomText()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomText(QDomText)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomText_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomText()
        {

            if (!PyErr_Occurred()) {
                // QDomText()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomText();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomText(const QDomText & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomText cppArg0_local = ::QDomText();
            ::QDomText* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomText(QDomText)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomText(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomText >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomText_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomText_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomText", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomText", overloads);
        return -1;
}

static PyObject* Sbk_QDomTextFunc_nodeType(PyObject* self)
{
    ::QDomText* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomText*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomText*>(cppSelf)->nodeType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomTextFunc_splitText(PyObject* self, PyObject* pyArg)
{
    ::QDomText* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomText*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: splitText(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // splitText(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomTextFunc_splitText_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // splitText(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomText cppResult = cppSelf->splitText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomTextFunc_splitText_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomText.splitText", overloads);
        return 0;
}

static PyObject* Sbk_QDomText___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomText& cppSelf = *(((::QDomText*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomText_methods[] = {
    {"nodeType", (PyCFunction)Sbk_QDomTextFunc_nodeType, METH_NOARGS},
    {"splitText", (PyCFunction)Sbk_QDomTextFunc_splitText, METH_O},

    {"__copy__", (PyCFunction)Sbk_QDomText___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomText___nb_bool(PyObject* self)
{
    ::QDomText* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomText*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomText_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomText_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomText_TypeAsNumber;

static SbkObjectType Sbk_QDomText_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomText",
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
    /*tp_traverse*/         Sbk_QDomText_traverse,
    /*tp_clear*/            Sbk_QDomText_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomText_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomText_Init,
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
static void QDomText_PythonToCpp_QDomText_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomText_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomText_PythonToCpp_QDomText_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomText_Type))
        return QDomText_PythonToCpp_QDomText_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomText_PTR_CppToPython_QDomText(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomText*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomText_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomText_COPY_CppToPython_QDomText(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomText_Type, new ::QDomText(*((::QDomText*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomText_PythonToCpp_QDomText_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomText*)cppOut) = *((::QDomText*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomText_PythonToCpp_QDomText_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomText_Type))
        return QDomText_PythonToCpp_QDomText_COPY;
    return 0;
}

void init_QDomText(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomText_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomText_TypeAsNumber) = Sbk_QDomText___nb_bool;
    Sbk_QDomText_Type.super.ht_type.tp_as_number = &Sbk_QDomText_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomText_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomText", "QDomText",
        &Sbk_QDomText_Type, &Shiboken::callCppDestructor< ::QDomText >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomText_Type,
        QDomText_PythonToCpp_QDomText_PTR,
        is_QDomText_PythonToCpp_QDomText_PTR_Convertible,
        QDomText_PTR_CppToPython_QDomText,
        QDomText_COPY_CppToPython_QDomText);

    Shiboken::Conversions::registerConverterName(converter, "QDomText");
    Shiboken::Conversions::registerConverterName(converter, "QDomText*");
    Shiboken::Conversions::registerConverterName(converter, "QDomText&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomText).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomText_PythonToCpp_QDomText_COPY,
        is_QDomText_PythonToCpp_QDomText_COPY_Convertible);


    qRegisterMetaType< ::QDomText >("QDomText");
}
