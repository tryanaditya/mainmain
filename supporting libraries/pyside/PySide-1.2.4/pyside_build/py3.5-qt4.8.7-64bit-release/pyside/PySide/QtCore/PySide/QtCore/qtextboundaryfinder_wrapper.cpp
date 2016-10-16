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

#include "qtextboundaryfinder_wrapper.h"

// Extra includes
#include <qtextboundaryfinder.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTextBoundaryFinder_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTextBoundaryFinder >()))
        return -1;

    ::QTextBoundaryFinder* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QTextBoundaryFinder", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTextBoundaryFinder()
    // 1: QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType,QString)
    // 2: QTextBoundaryFinder(QTextBoundaryFinder)
    if (numArgs == 0) {
        overloadId = 0; // QTextBoundaryFinder()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTextBoundaryFinder(QTextBoundaryFinder)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBoundaryFinder_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTextBoundaryFinder()
        {

            if (!PyErr_Occurred()) {
                // QTextBoundaryFinder()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBoundaryFinder();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType type, const QString & string)
        {
            ::QTextBoundaryFinder::BoundaryType cppArg0 = ((::QTextBoundaryFinder::BoundaryType)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBoundaryFinder(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTextBoundaryFinder(const QTextBoundaryFinder & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTextBoundaryFinder cppArg0_local = ::QTextBoundaryFinder();
            ::QTextBoundaryFinder* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTextBoundaryFinder(QTextBoundaryFinder)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTextBoundaryFinder(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTextBoundaryFinder >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTextBoundaryFinder_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTextBoundaryFinder_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QTextBoundaryFinder.BoundaryType, unicode", "PySide.QtCore.QTextBoundaryFinder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTextBoundaryFinder", overloads);
        return -1;
}

static PyObject* Sbk_QTextBoundaryFinderFunc_boundaryReasons(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundaryReasons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QTextBoundaryFinder::BoundaryReason> cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->boundaryReasons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBoundaryFinderFunc_isAtBoundary(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAtBoundary()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->isAtBoundary();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_isValid(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->isValid();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_position(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // position()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->position();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_setPosition(PyObject* self, PyObject* pyArg)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPosition(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPosition(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTextBoundaryFinderFunc_setPosition_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPosition(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPosition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTextBoundaryFinderFunc_setPosition_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTextBoundaryFinder.setPosition", overloads);
        return 0;
}

static PyObject* Sbk_QTextBoundaryFinderFunc_string(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // string()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->string();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_toEnd(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toEnd()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toEnd();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextBoundaryFinderFunc_toNextBoundary(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toNextBoundary()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->toNextBoundary();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_toPreviousBoundary(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPreviousBoundary()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->toPreviousBoundary();
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

static PyObject* Sbk_QTextBoundaryFinderFunc_toStart(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toStart()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toStart();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTextBoundaryFinderFunc_type(PyObject* self)
{
    ::QTextBoundaryFinder* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBoundaryFinder::BoundaryType cppResult = const_cast<const ::QTextBoundaryFinder*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTextBoundaryFinder___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTextBoundaryFinder& cppSelf = *(((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTextBoundaryFinder_methods[] = {
    {"boundaryReasons", (PyCFunction)Sbk_QTextBoundaryFinderFunc_boundaryReasons, METH_NOARGS},
    {"isAtBoundary", (PyCFunction)Sbk_QTextBoundaryFinderFunc_isAtBoundary, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QTextBoundaryFinderFunc_isValid, METH_NOARGS},
    {"position", (PyCFunction)Sbk_QTextBoundaryFinderFunc_position, METH_NOARGS},
    {"setPosition", (PyCFunction)Sbk_QTextBoundaryFinderFunc_setPosition, METH_O},
    {"string", (PyCFunction)Sbk_QTextBoundaryFinderFunc_string, METH_NOARGS},
    {"toEnd", (PyCFunction)Sbk_QTextBoundaryFinderFunc_toEnd, METH_NOARGS},
    {"toNextBoundary", (PyCFunction)Sbk_QTextBoundaryFinderFunc_toNextBoundary, METH_NOARGS},
    {"toPreviousBoundary", (PyCFunction)Sbk_QTextBoundaryFinderFunc_toPreviousBoundary, METH_NOARGS},
    {"toStart", (PyCFunction)Sbk_QTextBoundaryFinderFunc_toStart, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QTextBoundaryFinderFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTextBoundaryFinder___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTextBoundaryFinder_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTextBoundaryFinder_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTextBoundaryFinder_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTextBoundaryFinder",
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
    /*tp_traverse*/         Sbk_QTextBoundaryFinder_traverse,
    /*tp_clear*/            Sbk_QTextBoundaryFinder_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTextBoundaryFinder_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTextBoundaryFinder_Init,
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

PyObject* SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___and__(PyObject* self, PyObject* pyArg)
{
    ::QTextBoundaryFinder::BoundaryReasons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___or__(PyObject* self, PyObject* pyArg)
{
    ::QTextBoundaryFinder::BoundaryReasons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTextBoundaryFinder::BoundaryReasons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(self);
    cppArg = (QTextBoundaryFinder::BoundaryReasons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTextBoundaryFinder::BoundaryReasons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), self, &cppSelf);
    ::QTextBoundaryFinder::BoundaryReasons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QTextBoundaryFinder_BoundaryType_PythonToCpp_QTextBoundaryFinder_BoundaryType(PyObject* pyIn, void* cppOut) {
    *((::QTextBoundaryFinder::BoundaryType*)cppOut) = (::QTextBoundaryFinder::BoundaryType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextBoundaryFinder_BoundaryType_PythonToCpp_QTextBoundaryFinder_BoundaryType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX]))
        return QTextBoundaryFinder_BoundaryType_PythonToCpp_QTextBoundaryFinder_BoundaryType;
    return 0;
}
static PyObject* QTextBoundaryFinder_BoundaryType_CppToPython_QTextBoundaryFinder_BoundaryType(const void* cppIn) {
    int castCppIn = *((::QTextBoundaryFinder::BoundaryType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX], castCppIn);

}

static void QTextBoundaryFinder_BoundaryReason_PythonToCpp_QTextBoundaryFinder_BoundaryReason(PyObject* pyIn, void* cppOut) {
    *((::QTextBoundaryFinder::BoundaryReason*)cppOut) = (::QTextBoundaryFinder::BoundaryReason) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTextBoundaryFinder_BoundaryReason_PythonToCpp_QTextBoundaryFinder_BoundaryReason_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX]))
        return QTextBoundaryFinder_BoundaryReason_PythonToCpp_QTextBoundaryFinder_BoundaryReason;
    return 0;
}
static PyObject* QTextBoundaryFinder_BoundaryReason_CppToPython_QTextBoundaryFinder_BoundaryReason(const void* cppIn) {
    int castCppIn = *((::QTextBoundaryFinder::BoundaryReason*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX], castCppIn);

}

static void QFlags_QTextBoundaryFinder_BoundaryReason__PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextBoundaryFinder::BoundaryReason>*)cppOut) = ::QFlags<QTextBoundaryFinder::BoundaryReason>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTextBoundaryFinder_BoundaryReason__PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]))
        return QFlags_QTextBoundaryFinder_BoundaryReason__PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_;
    return 0;
}
static PyObject* QFlags_QTextBoundaryFinder_BoundaryReason__CppToPython_QFlags_QTextBoundaryFinder_BoundaryReason_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTextBoundaryFinder::BoundaryReason>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]));

}

static void QTextBoundaryFinder_BoundaryReason_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTextBoundaryFinder::BoundaryReason>*)cppOut) = ::QFlags<QTextBoundaryFinder::BoundaryReason>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTextBoundaryFinder_BoundaryReason_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX]))
        return QTextBoundaryFinder_BoundaryReason_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTextBoundaryFinder::BoundaryReason>*)cppOut) = ::QFlags<QTextBoundaryFinder::BoundaryReason>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTextBoundaryFinder_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBoundaryFinder_Type))
        return QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTextBoundaryFinder_PTR_CppToPython_QTextBoundaryFinder(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTextBoundaryFinder*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTextBoundaryFinder_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTextBoundaryFinder_COPY_CppToPython_QTextBoundaryFinder(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTextBoundaryFinder_Type, new ::QTextBoundaryFinder(*((::QTextBoundaryFinder*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTextBoundaryFinder*)cppOut) = *((::QTextBoundaryFinder*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTextBoundaryFinder_Type))
        return QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_COPY;
    return 0;
}

void init_QTextBoundaryFinder(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTextBoundaryFinder_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTextBoundaryFinder", "QTextBoundaryFinder",
        &Sbk_QTextBoundaryFinder_Type, &Shiboken::callCppDestructor< ::QTextBoundaryFinder >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTextBoundaryFinder_Type,
        QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_PTR,
        is_QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_PTR_Convertible,
        QTextBoundaryFinder_PTR_CppToPython_QTextBoundaryFinder,
        QTextBoundaryFinder_COPY_CppToPython_QTextBoundaryFinder);

    Shiboken::Conversions::registerConverterName(converter, "QTextBoundaryFinder");
    Shiboken::Conversions::registerConverterName(converter, "QTextBoundaryFinder*");
    Shiboken::Conversions::registerConverterName(converter, "QTextBoundaryFinder&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTextBoundaryFinder).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_COPY,
        is_QTextBoundaryFinder_PythonToCpp_QTextBoundaryFinder_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'BoundaryType'.
    SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextBoundaryFinder_Type,
        "BoundaryType",
        "PySide.QtCore.QTextBoundaryFinder.BoundaryType",
        "QTextBoundaryFinder::BoundaryType");
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX],
        &Sbk_QTextBoundaryFinder_Type, "Grapheme", (long) QTextBoundaryFinder::Grapheme))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX],
        &Sbk_QTextBoundaryFinder_Type, "Word", (long) QTextBoundaryFinder::Word))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX],
        &Sbk_QTextBoundaryFinder_Type, "Line", (long) QTextBoundaryFinder::Line))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX],
        &Sbk_QTextBoundaryFinder_Type, "Sentence", (long) QTextBoundaryFinder::Sentence))
        return ;
    // Register converter for enum 'QTextBoundaryFinder::BoundaryType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX],
            QTextBoundaryFinder_BoundaryType_CppToPython_QTextBoundaryFinder_BoundaryType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextBoundaryFinder_BoundaryType_PythonToCpp_QTextBoundaryFinder_BoundaryType,
            is_QTextBoundaryFinder_BoundaryType_PythonToCpp_QTextBoundaryFinder_BoundaryType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextBoundaryFinder::BoundaryType");
        Shiboken::Conversions::registerConverterName(converter, "BoundaryType");
    }
    // End of 'BoundaryType' enum.

    // Initialization of enum 'BoundaryReason'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX] = PySide::QFlags::create("BoundaryReasons", &SbkPySide_QtCore_QTextBoundaryFinder_BoundaryReason_as_number);
    SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTextBoundaryFinder_Type,
        "BoundaryReason",
        "PySide.QtCore.QTextBoundaryFinder.BoundaryReason",
        "QTextBoundaryFinder::BoundaryReason",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX],
        &Sbk_QTextBoundaryFinder_Type, "NotAtBoundary", (long) QTextBoundaryFinder::NotAtBoundary))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX],
        &Sbk_QTextBoundaryFinder_Type, "StartWord", (long) QTextBoundaryFinder::StartWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX],
        &Sbk_QTextBoundaryFinder_Type, "EndWord", (long) QTextBoundaryFinder::EndWord))
        return ;
    // Register converter for enum 'QTextBoundaryFinder::BoundaryReason'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX],
            QTextBoundaryFinder_BoundaryReason_CppToPython_QTextBoundaryFinder_BoundaryReason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextBoundaryFinder_BoundaryReason_PythonToCpp_QTextBoundaryFinder_BoundaryReason,
            is_QTextBoundaryFinder_BoundaryReason_PythonToCpp_QTextBoundaryFinder_BoundaryReason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTEXTBOUNDARYFINDER_BOUNDARYREASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTextBoundaryFinder::BoundaryReason");
        Shiboken::Conversions::registerConverterName(converter, "BoundaryReason");
    }
    // Register converter for flag 'QFlags<QTextBoundaryFinder::BoundaryReason>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX],
            QFlags_QTextBoundaryFinder_BoundaryReason__CppToPython_QFlags_QTextBoundaryFinder_BoundaryReason_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTextBoundaryFinder_BoundaryReason_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_,
            is_QTextBoundaryFinder_BoundaryReason_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTextBoundaryFinder_BoundaryReason__PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_,
            is_QFlags_QTextBoundaryFinder_BoundaryReason__PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason_,
            is_number_PythonToCpp_QFlags_QTextBoundaryFinder_BoundaryReason__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QTEXTBOUNDARYFINDER_BOUNDARYREASON__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTextBoundaryFinder::BoundaryReason>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<BoundaryReason>");
    }
    // End of 'BoundaryReason' enum/flags.


    qRegisterMetaType< ::QTextBoundaryFinder >("QTextBoundaryFinder");
    qRegisterMetaType< ::QTextBoundaryFinder::BoundaryType >("QTextBoundaryFinder::BoundaryType");
    qRegisterMetaType< ::QTextBoundaryFinder::BoundaryReason >("QTextBoundaryFinder::BoundaryReason");
    qRegisterMetaType< ::QTextBoundaryFinder::BoundaryReasons >("QTextBoundaryFinder::BoundaryReasons");
}
