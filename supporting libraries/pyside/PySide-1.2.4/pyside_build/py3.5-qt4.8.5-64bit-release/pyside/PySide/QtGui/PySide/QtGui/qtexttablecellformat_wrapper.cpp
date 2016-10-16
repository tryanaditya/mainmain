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

#include "qtexttablecellformat_wrapper.h"

// Extra includes
#include <QMap>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qfont.h>
#include <qpen.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextTableCellFormat_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextTableCellFormat >()))
        return -1;

    ::QTextTableCellFormat* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextTableCellFormat", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextTableCellFormat()
    // 1: QTextTableCellFormat(QTextFormat)
    // 2: QTextTableCellFormat(QTextTableCellFormat)
    if (numArgs == 0) {
        overloadId = 0; // QTextTableCellFormat()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextTableCellFormat(QTextTableCellFormat)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextTableCellFormat(QTextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormat_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextTableCellFormat()
        {

            if (!PyErr_Occurred()) {
                // QTextTableCellFormat()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableCellFormat();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextTableCellFormat(const QTextFormat & fmt)
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
                // QTextTableCellFormat(QTextFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableCellFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextTableCellFormat(const QTextTableCellFormat & QTextTableCellFormat)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextTableCellFormat cppArg0_local = ::QTextTableCellFormat();
            ::QTextTableCellFormat* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextTableCellFormat(QTextTableCellFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextTableCellFormat(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextTableCellFormat >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextTableCellFormat_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextTableCellFormat_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextFormat", "PySide.QtGui.QTextTableCellFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextTableCellFormat", overloads);
        return -1;
}

static PyObject* Sbk_QTextTableCellFormatFunc_bottomPadding(PyObject* self)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottomPadding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableCellFormat*>(cppSelf)->bottomPadding();
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

static PyObject* Sbk_QTextTableCellFormatFunc_isValid(PyObject* self)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextTableCellFormat*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextTableCellFormatFunc_leftPadding(PyObject* self)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // leftPadding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableCellFormat*>(cppSelf)->leftPadding();
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

static PyObject* Sbk_QTextTableCellFormatFunc_rightPadding(PyObject* self)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rightPadding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableCellFormat*>(cppSelf)->rightPadding();
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

static PyObject* Sbk_QTextTableCellFormatFunc_setBottomPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBottomPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBottomPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormatFunc_setBottomPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBottomPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBottomPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFormatFunc_setBottomPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCellFormat.setBottomPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFormatFunc_setLeftPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLeftPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setLeftPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormatFunc_setLeftPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLeftPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLeftPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFormatFunc_setLeftPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCellFormat.setLeftPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFormatFunc_setPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormatFunc_setPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFormatFunc_setPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCellFormat.setPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFormatFunc_setRightPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRightPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRightPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormatFunc_setRightPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRightPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRightPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFormatFunc_setRightPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCellFormat.setRightPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFormatFunc_setTopPadding(PyObject* self, PyObject* pyArg)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTopPadding(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setTopPadding(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextTableCellFormatFunc_setTopPadding_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTopPadding(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTopPadding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextTableCellFormatFunc_setTopPadding_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextTableCellFormat.setTopPadding", overloads);
        return 0;
}

static PyObject* Sbk_QTextTableCellFormatFunc_topPadding(PyObject* self)
{
    ::QTextTableCellFormat* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topPadding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextTableCellFormat*>(cppSelf)->topPadding();
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

static PyObject* Sbk_QTextTableCellFormat___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextTableCellFormat& cppSelf = *(((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextTableCellFormat_methods[] = {
    {"bottomPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_bottomPadding, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextTableCellFormatFunc_isValid, METH_NOARGS},
    {"leftPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_leftPadding, METH_NOARGS},
    {"rightPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_rightPadding, METH_NOARGS},
    {"setBottomPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_setBottomPadding, METH_O},
    {"setLeftPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_setLeftPadding, METH_O},
    {"setPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_setPadding, METH_O},
    {"setRightPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_setRightPadding, METH_O},
    {"setTopPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_setTopPadding, METH_O},
    {"topPadding", (PyCFunction)Sbk_QTextTableCellFormatFunc_topPadding, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextTableCellFormat___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextTableCellFormat_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextTableCellFormat_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextTableCellFormat_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextTableCellFormat",
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
    /*tp_traverse*/         Sbk_QTextTableCellFormat_traverse,
    /*tp_clear*/            Sbk_QTextTableCellFormat_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextTableCellFormat_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextTableCellFormat_Init,
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
static void QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextTableCellFormat_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableCellFormat_Type))
        return QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextTableCellFormat_PTR_CppToPython_QTextTableCellFormat(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextTableCellFormat*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextTableCellFormat_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextTableCellFormat_COPY_CppToPython_QTextTableCellFormat(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextTableCellFormat_Type, new ::QTextTableCellFormat(*((::QTextTableCellFormat*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextTableCellFormat*)cppOut) = *((::QTextTableCellFormat*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextTableCellFormat_Type))
        return QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_COPY;
    return 0;
}

void init_QTextTableCellFormat(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextTableCellFormat_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextTableCellFormat", "QTextTableCellFormat",
        &Sbk_QTextTableCellFormat_Type, &Shiboken::callCppDestructor< ::QTextTableCellFormat >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextTableCellFormat_Type,
        QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_PTR,
        is_QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_PTR_Convertible,
        QTextTableCellFormat_PTR_CppToPython_QTextTableCellFormat,
        QTextTableCellFormat_COPY_CppToPython_QTextTableCellFormat);

    Shiboken::Conversions::registerConverterName(converter, "QTextTableCellFormat");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableCellFormat*");
    Shiboken::Conversions::registerConverterName(converter, "QTextTableCellFormat&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextTableCellFormat).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_COPY,
        is_QTextTableCellFormat_PythonToCpp_QTextTableCellFormat_COPY_Convertible);


    qRegisterMetaType< ::QTextTableCellFormat >("QTextTableCellFormat");
}
