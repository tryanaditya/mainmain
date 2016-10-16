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

#include "qtextdocumentfragment_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qtextcursor.h>
#include <qtextdocument.h>
#include <qtextdocumentfragment.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextDocumentFragment_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextDocumentFragment >()))
        return -1;

    ::QTextDocumentFragment* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextDocumentFragment", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextDocumentFragment()
    // 1: QTextDocumentFragment(QTextCursor)
    // 2: QTextDocumentFragment(const QTextDocument*)
    // 3: QTextDocumentFragment(QTextDocumentFragment)
    if (numArgs == 0) {
        overloadId = 0; // QTextDocumentFragment()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (pyArgs[0])))) {
        overloadId = 3; // QTextDocumentFragment(QTextDocumentFragment)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextDocumentFragment(const QTextDocument*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextDocumentFragment(QTextCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFragment_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextDocumentFragment()
        {

            if (!PyErr_Occurred()) {
                // QTextDocumentFragment()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextDocumentFragment();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextDocumentFragment(const QTextCursor & range)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextCursor cppArg0_local = ::QTextCursor();
            ::QTextCursor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextDocumentFragment(QTextCursor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextDocumentFragment(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextDocumentFragment(const QTextDocument * document)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextDocument* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTextDocumentFragment(const QTextDocument*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextDocumentFragment(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QTextDocumentFragment(const QTextDocumentFragment & rhs)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextDocumentFragment cppArg0_local = ::QTextDocumentFragment();
            ::QTextDocumentFragment* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextDocumentFragment(QTextDocumentFragment)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextDocumentFragment(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextDocumentFragment >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextDocumentFragment_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextDocumentFragment_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextCursor", "PySide.QtGui.QTextDocument", "PySide.QtGui.QTextDocumentFragment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocumentFragment", overloads);
        return -1;
}

static PyObject* Sbk_QTextDocumentFragmentFunc_fromHtml(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fromHtml", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromHtml(QString)
    // 1: fromHtml(QString,const QTextDocument*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromHtml(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArgs[1])))) {
            overloadId = 1; // fromHtml(QString,const QTextDocument*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFragmentFunc_fromHtml_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fromHtml(const QString & html)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // fromHtml(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextDocumentFragment cppResult = ::QTextDocumentFragment::fromHtml(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], &cppResult);
            }
            break;
        }
        case 1: // fromHtml(const QString & html, const QTextDocument * resourceProvider)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextDocument* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fromHtml(QString,const QTextDocument*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTextDocumentFragment cppResult = ::QTextDocumentFragment::fromHtml(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFragmentFunc_fromHtml_TypeError:
        const char* overloads[] = {"unicode", "unicode, PySide.QtGui.QTextDocument", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocumentFragment.fromHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFragmentFunc_fromPlainText(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFragmentFunc_fromPlainText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromPlainText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocumentFragment cppResult = ::QTextDocumentFragment::fromPlainText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFragmentFunc_fromPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextDocumentFragment.fromPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFragmentFunc_isEmpty(PyObject* self)
{
    ::QTextDocumentFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextDocumentFragment*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QTextDocumentFragmentFunc_toHtml(PyObject* self, PyObject* args)
{
    ::QTextDocumentFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "toHtml", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toHtml()const
    // 1: toHtml(QByteArray)const
    if (numArgs == 0) {
        overloadId = 0; // toHtml()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 1; // toHtml(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextDocumentFragmentFunc_toHtml_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toHtml() const
        {

            if (!PyErr_Occurred()) {
                // toHtml()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTextDocumentFragment*>(cppSelf)->toHtml();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // toHtml(const QByteArray & encoding) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // toHtml(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QTextDocumentFragment*>(cppSelf)->toHtml(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTextDocumentFragmentFunc_toHtml_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextDocumentFragment.toHtml", overloads);
        return 0;
}

static PyObject* Sbk_QTextDocumentFragmentFunc_toPlainText(PyObject* self)
{
    ::QTextDocumentFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPlainText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextDocumentFragment*>(cppSelf)->toPlainText();
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

static PyObject* Sbk_QTextDocumentFragment___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextDocumentFragment& cppSelf = *(((::QTextDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextDocumentFragment_methods[] = {
    {"fromHtml", (PyCFunction)Sbk_QTextDocumentFragmentFunc_fromHtml, METH_VARARGS|METH_STATIC},
    {"fromPlainText", (PyCFunction)Sbk_QTextDocumentFragmentFunc_fromPlainText, METH_O|METH_STATIC},
    {"isEmpty", (PyCFunction)Sbk_QTextDocumentFragmentFunc_isEmpty, METH_NOARGS},
    {"toHtml", (PyCFunction)Sbk_QTextDocumentFragmentFunc_toHtml, METH_VARARGS},
    {"toPlainText", (PyCFunction)Sbk_QTextDocumentFragmentFunc_toPlainText, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextDocumentFragment___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextDocumentFragment_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextDocumentFragment_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextDocumentFragment_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextDocumentFragment",
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
    /*tp_traverse*/         Sbk_QTextDocumentFragment_traverse,
    /*tp_clear*/            Sbk_QTextDocumentFragment_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextDocumentFragment_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextDocumentFragment_Init,
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
static void QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextDocumentFragment_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextDocumentFragment_Type))
        return QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextDocumentFragment_PTR_CppToPython_QTextDocumentFragment(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextDocumentFragment*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextDocumentFragment_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextDocumentFragment_COPY_CppToPython_QTextDocumentFragment(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextDocumentFragment_Type, new ::QTextDocumentFragment(*((::QTextDocumentFragment*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextDocumentFragment*)cppOut) = *((::QTextDocumentFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextDocumentFragment_Type))
        return QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_COPY;
    return 0;
}

void init_QTextDocumentFragment(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextDocumentFragment_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextDocumentFragment", "QTextDocumentFragment",
        &Sbk_QTextDocumentFragment_Type, &Shiboken::callCppDestructor< ::QTextDocumentFragment >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextDocumentFragment_Type,
        QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_PTR,
        is_QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_PTR_Convertible,
        QTextDocumentFragment_PTR_CppToPython_QTextDocumentFragment,
        QTextDocumentFragment_COPY_CppToPython_QTextDocumentFragment);

    Shiboken::Conversions::registerConverterName(converter, "QTextDocumentFragment");
    Shiboken::Conversions::registerConverterName(converter, "QTextDocumentFragment*");
    Shiboken::Conversions::registerConverterName(converter, "QTextDocumentFragment&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextDocumentFragment).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_COPY,
        is_QTextDocumentFragment_PythonToCpp_QTextDocumentFragment_COPY_Convertible);


    qRegisterMetaType< ::QTextDocumentFragment >("QTextDocumentFragment");
}
