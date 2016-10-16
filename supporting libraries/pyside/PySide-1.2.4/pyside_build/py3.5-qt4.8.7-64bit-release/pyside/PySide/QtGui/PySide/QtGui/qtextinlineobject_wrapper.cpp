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

#include "qtextinlineobject_wrapper.h"

// Extra includes
#include <qrect.h>
#include <qtextformat.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextInlineObject_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextInlineObject >()))
        return -1;

    ::QTextInlineObject* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextInlineObject", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QTextInlineObject()
    // 1: QTextInlineObject(QTextInlineObject)
    if (numArgs == 0) {
        overloadId = 0; // QTextInlineObject()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QTextInlineObject(QTextInlineObject)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextInlineObject_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextInlineObject()
        {

            if (!PyErr_Occurred()) {
                // QTextInlineObject()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextInlineObject();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextInlineObject(const QTextInlineObject & QTextInlineObject)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextInlineObject cppArg0_local = ::QTextInlineObject();
            ::QTextInlineObject* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextInlineObject(QTextInlineObject)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextInlineObject(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextInlineObject >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextInlineObject_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextInlineObject_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextInlineObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTextInlineObject", overloads);
        return -1;
}

static PyObject* Sbk_QTextInlineObjectFunc_ascent(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ascent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->ascent();
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

static PyObject* Sbk_QTextInlineObjectFunc_descent(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // descent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->descent();
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

static PyObject* Sbk_QTextInlineObjectFunc_format(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextFormat cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextInlineObjectFunc_formatIndex(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // formatIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->formatIndex();
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

static PyObject* Sbk_QTextInlineObjectFunc_height(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->height();
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

static PyObject* Sbk_QTextInlineObjectFunc_isValid(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextInlineObjectFunc_rect(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->rect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextInlineObjectFunc_setAscent(PyObject* self, PyObject* pyArg)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAscent(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setAscent(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextInlineObjectFunc_setAscent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAscent(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAscent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextInlineObjectFunc_setAscent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextInlineObject.setAscent", overloads);
        return 0;
}

static PyObject* Sbk_QTextInlineObjectFunc_setDescent(PyObject* self, PyObject* pyArg)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDescent(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setDescent(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextInlineObjectFunc_setDescent_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDescent(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDescent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextInlineObjectFunc_setDescent_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextInlineObject.setDescent", overloads);
        return 0;
}

static PyObject* Sbk_QTextInlineObjectFunc_setWidth(PyObject* self, PyObject* pyArg)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextInlineObjectFunc_setWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextInlineObjectFunc_setWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTextInlineObject.setWidth", overloads);
        return 0;
}

static PyObject* Sbk_QTextInlineObjectFunc_textDirection(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->textDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextInlineObjectFunc_textPosition(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->textPosition();
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

static PyObject* Sbk_QTextInlineObjectFunc_width(PyObject* self)
{
    ::QTextInlineObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTextInlineObject*>(cppSelf)->width();
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

static PyObject* Sbk_QTextInlineObject___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextInlineObject& cppSelf = *(((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextInlineObject_methods[] = {
    {"ascent", (PyCFunction)Sbk_QTextInlineObjectFunc_ascent, METH_NOARGS},
    {"descent", (PyCFunction)Sbk_QTextInlineObjectFunc_descent, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QTextInlineObjectFunc_format, METH_NOARGS},
    {"formatIndex", (PyCFunction)Sbk_QTextInlineObjectFunc_formatIndex, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QTextInlineObjectFunc_height, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextInlineObjectFunc_isValid, METH_NOARGS},
    {"rect", (PyCFunction)Sbk_QTextInlineObjectFunc_rect, METH_NOARGS},
    {"setAscent", (PyCFunction)Sbk_QTextInlineObjectFunc_setAscent, METH_O},
    {"setDescent", (PyCFunction)Sbk_QTextInlineObjectFunc_setDescent, METH_O},
    {"setWidth", (PyCFunction)Sbk_QTextInlineObjectFunc_setWidth, METH_O},
    {"textDirection", (PyCFunction)Sbk_QTextInlineObjectFunc_textDirection, METH_NOARGS},
    {"textPosition", (PyCFunction)Sbk_QTextInlineObjectFunc_textPosition, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QTextInlineObjectFunc_width, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextInlineObject___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextInlineObject_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextInlineObject_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextInlineObject_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTextInlineObject",
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
    /*tp_traverse*/         Sbk_QTextInlineObject_traverse,
    /*tp_clear*/            Sbk_QTextInlineObject_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextInlineObject_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextInlineObject_Init,
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
static void QTextInlineObject_PythonToCpp_QTextInlineObject_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextInlineObject_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextInlineObject_PythonToCpp_QTextInlineObject_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextInlineObject_Type))
        return QTextInlineObject_PythonToCpp_QTextInlineObject_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextInlineObject_PTR_CppToPython_QTextInlineObject(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextInlineObject*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextInlineObject_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextInlineObject_COPY_CppToPython_QTextInlineObject(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextInlineObject_Type, new ::QTextInlineObject(*((::QTextInlineObject*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextInlineObject_PythonToCpp_QTextInlineObject_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextInlineObject*)cppOut) = *((::QTextInlineObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextInlineObject_PythonToCpp_QTextInlineObject_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextInlineObject_Type))
        return QTextInlineObject_PythonToCpp_QTextInlineObject_COPY;
    return 0;
}

void init_QTextInlineObject(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextInlineObject_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextInlineObject", "QTextInlineObject",
        &Sbk_QTextInlineObject_Type, &Shiboken::callCppDestructor< ::QTextInlineObject >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextInlineObject_Type,
        QTextInlineObject_PythonToCpp_QTextInlineObject_PTR,
        is_QTextInlineObject_PythonToCpp_QTextInlineObject_PTR_Convertible,
        QTextInlineObject_PTR_CppToPython_QTextInlineObject,
        QTextInlineObject_COPY_CppToPython_QTextInlineObject);

    Shiboken::Conversions::registerConverterName(converter, "QTextInlineObject");
    Shiboken::Conversions::registerConverterName(converter, "QTextInlineObject*");
    Shiboken::Conversions::registerConverterName(converter, "QTextInlineObject&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextInlineObject).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextInlineObject_PythonToCpp_QTextInlineObject_COPY,
        is_QTextInlineObject_PythonToCpp_QTextInlineObject_COPY_Convertible);


    qRegisterMetaType< ::QTextInlineObject >("QTextInlineObject");
}
