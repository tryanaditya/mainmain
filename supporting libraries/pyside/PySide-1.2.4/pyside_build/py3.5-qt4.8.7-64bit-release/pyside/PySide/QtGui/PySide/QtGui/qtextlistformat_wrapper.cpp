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

#include "qtextlistformat_wrapper.h"

// Extra includes
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qpen.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextListFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextListFormat >()))
        return -1;

    ::QTextListFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextListFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextListFormat()
    // 1: QTextListFormat(QTextFormat)
    // 2: QTextListFormat(QTextListFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextListFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextListFormat(QTextListFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextListFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextListFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextListFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextListFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextListFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextListFormat(const QTextFormat & fmt)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextFormat cppArg0_local = ::QTextFormat();
            ::QTextFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextListFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextListFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextListFormat(const QTextListFormat & QTextListFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextListFormat cppArg0_local = ::QTextListFormat();
            ::QTextListFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextListFormat(QTextListFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextListFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextListFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextListFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextListFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextFormat", "PySide.QtGui.QTextListFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextListFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextListFormatFunc_indent(PyObject* self)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextListFormat*>(cppSelf)->indent();
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

static PyObject* Sbk_QTextListFormatFunc_isValid(PyObject* self)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextListFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextListFormatFunc_numberPrefix(PyObject* self)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numberPrefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextListFormat*>(cppSelf)->numberPrefix();
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

static PyObject* Sbk_QTextListFormatFunc_numberSuffix(PyObject* self)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numberSuffix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextListFormat*>(cppSelf)->numberSuffix();
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

static PyObject* Sbk_QTextListFormatFunc_setIndent(PyObject* self, PyObject* pyArg)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIndent(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setIndent(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextListFormatFunc_setIndent_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIndent(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIndent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextListFormatFunc_setIndent_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextListFormat.setIndent", overloads);
        return 0;
}

static PyObject* Sbk_QTextListFormatFunc_setNumberPrefix(PyObject* self, PyObject* pyArg)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumberPrefix(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNumberPrefix(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextListFormatFunc_setNumberPrefix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumberPrefix(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumberPrefix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextListFormatFunc_setNumberPrefix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextListFormat.setNumberPrefix", overloads);
        return 0;
}

static PyObject* Sbk_QTextListFormatFunc_setNumberSuffix(PyObject* self, PyObject* pyArg)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumberSuffix(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNumberSuffix(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextListFormatFunc_setNumberSuffix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumberSuffix(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumberSuffix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextListFormatFunc_setNumberSuffix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextListFormat.setNumberSuffix", overloads);
        return 0;
}

static PyObject* Sbk_QTextListFormatFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(QTextListFormat::Style)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setStyle(QTextListFormat::Style)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextListFormatFunc_setStyle_TypeError;

    // Call function/method
    {
        ::QTextListFormat::Style cppArg0 = ((::QTextListFormat::Style)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyle(QTextListFormat::Style)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextListFormatFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextListFormat.Style", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextListFormat.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QTextListFormatFunc_style(PyObject* self)
{
    ::QTextListFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextListFormat::Style cppResult = const_cast<const ::QTextListFormat*>(cppSelf)->style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextListFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextListFormat& cppSelf = *(((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextListFormat_methods[] = {
    {"indent", (PyCFunction)Sbk_QTextListFormatFunc_indent, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextListFormatFunc_isValid, METH_NOARGS},
    {"numberPrefix", (PyCFunction)Sbk_QTextListFormatFunc_numberPrefix, METH_NOARGS},
    {"numberSuffix", (PyCFunction)Sbk_QTextListFormatFunc_numberSuffix, METH_NOARGS},
    {"setIndent", (PyCFunction)Sbk_QTextListFormatFunc_setIndent, METH_O},
    {"setNumberPrefix", (PyCFunction)Sbk_QTextListFormatFunc_setNumberPrefix, METH_O},
    {"setNumberSuffix", (PyCFunction)Sbk_QTextListFormatFunc_setNumberSuffix, METH_O},
    {"setStyle", (PyCFunction)Sbk_QTextListFormatFunc_setStyle, METH_O},
    {"style", (PyCFunction)Sbk_QTextListFormatFunc_style, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextListFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextListFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextListFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextListFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextListFormat",
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
    /*tp_traverse*/         Sbk_QTextListFormat_traverse,
    /*tp_clear*/            Sbk_QTextListFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextListFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextListFormat_Init,
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
static void QTextListFormat_Style_PythonToCpp_QTextListFormat_Style(PyObject* pyIn, void* cppOut) {
    *((::QTextListFormat::Style*)cppOut) = (::QTextListFormat::Style) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextListFormat_Style_PythonToCpp_QTextListFormat_Style_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]))
        return QTextListFormat_Style_PythonToCpp_QTextListFormat_Style;
    return 0;
}
static PyObject* QTextListFormat_Style_CppToPython_QTextListFormat_Style(const void* cppIn) {
    int castCppIn = *((::QTextListFormat::Style*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextListFormat_PythonToCpp_QTextListFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextListFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextListFormat_PythonToCpp_QTextListFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextListFormat_Type))
        return QTextListFormat_PythonToCpp_QTextListFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextListFormat_PTR_CppToPython_QTextListFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextListFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextListFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextListFormat_COPY_CppToPython_QTextListFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextListFormat_Type, new ::QTextListFormat(*((::QTextListFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextListFormat_PythonToCpp_QTextListFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextListFormat*)cppOut) = *((::QTextListFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextListFormat_PythonToCpp_QTextListFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextListFormat_Type))
        return QTextListFormat_PythonToCpp_QTextListFormat_COPY;
    return 0;
}

void init_QTextListFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextListFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextListFormat", "QTextListFormat",
        &Sbk_QTextListFormat_Type, &Shiboken::callCppDestructor< ::QTextListFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextListFormat_Type,
        QTextListFormat_PythonToCpp_QTextListFormat_PTR,
        is_QTextListFormat_PythonToCpp_QTextListFormat_PTR_Convertible,
        QTextListFormat_PTR_CppToPython_QTextListFormat,
        QTextListFormat_COPY_CppToPython_QTextListFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextListFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextListFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextListFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextListFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextListFormat_PythonToCpp_QTextListFormat_COPY,
        is_QTextListFormat_PythonToCpp_QTextListFormat_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Style'.
    SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextListFormat_Type,
        "Style",
        "PySide.QtGui.QTextListFormat.Style",
        "QTextListFormat::Style");
    if (!SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListDisc", (long) QTextListFormat::ListDisc))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListCircle", (long) QTextListFormat::ListCircle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListSquare", (long) QTextListFormat::ListSquare))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListDecimal", (long) QTextListFormat::ListDecimal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListLowerAlpha", (long) QTextListFormat::ListLowerAlpha))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListUpperAlpha", (long) QTextListFormat::ListUpperAlpha))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListLowerRoman", (long) QTextListFormat::ListLowerRoman))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListUpperRoman", (long) QTextListFormat::ListUpperRoman))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
        &Sbk_QTextListFormat_Type, "ListStyleUndefined", (long) QTextListFormat::ListStyleUndefined))
        return ;
    // Register converter for enum 'QTextListFormat::Style'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX],
            QTextListFormat_Style_CppToPython_QTextListFormat_Style);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextListFormat_Style_PythonToCpp_QTextListFormat_Style,
            is_QTextListFormat_Style_PythonToCpp_QTextListFormat_Style_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextListFormat::Style");
        Shiboken::Conversions::registerConverterName(converter, "Style");
    }
    // End of 'Style' enum.


    qRegisterMetaType< ::QTextListFormat >("QTextListFormat");
    qRegisterMetaType< ::QTextListFormat::Style >("QTextListFormat::Style");
}
