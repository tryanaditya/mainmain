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

#include "qgesturerecognizer_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qgesture.h>
#include <qgesturerecognizer.h>
#include <qobject.h>


// Native ---------------------------------------------------------

QGestureRecognizerWrapper::QGestureRecognizerWrapper() : QGestureRecognizer() {
    // ... middle
}

QGesture * QGestureRecognizerWrapper::create(QObject * target)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QGesture*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "create"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGestureRecognizer::create(target);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], target)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QGesture*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGestureRecognizer.create", Shiboken::SbkType< QGesture >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QGesture*)0);
    }
    ::QGesture* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<QGestureRecognizer::ResultFlag> QGestureRecognizerWrapper::recognize(QGesture * state, QObject * watched, QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QGestureRecognizer::ResultFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "recognize"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGestureRecognizer.recognize()' not implemented.");
        return ((::QFlags<QGestureRecognizer::ResultFlag>)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], state),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], watched),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<QGestureRecognizer::ResultFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGestureRecognizer.recognize", Shiboken::SbkType< QFlags<QGestureRecognizer::ResultFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QGestureRecognizer::ResultFlag>)0);
    }
    ::QFlags<QGestureRecognizer::ResultFlag> cppResult = ((::QFlags<QGestureRecognizer::ResultFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGestureRecognizerWrapper::reset(QGesture * state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGestureRecognizer::reset(state);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], state)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QGestureRecognizerWrapper::~QGestureRecognizerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGestureRecognizer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QGestureRecognizer' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGestureRecognizer >()))
        return -1;

    ::QGestureRecognizerWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QGestureRecognizer()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGestureRecognizerWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGestureRecognizer >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QGestureRecognizerFunc_create(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureRecognizer*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: create(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // create(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureRecognizerFunc_create_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // create(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGesture * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGestureRecognizer::create(cppArg0) : cppSelf->create(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGestureRecognizerFunc_create_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureRecognizer.create", overloads);
        return 0;
}

static PyObject* Sbk_QGestureRecognizerFunc_recognize(PyObject* self, PyObject* args)
{
    ::QGestureRecognizer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureRecognizer*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "recognize", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: recognize(QGesture*,QObject*,QEvent*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[2])))) {
        overloadId = 0; // recognize(QGesture*,QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureRecognizerFunc_recognize_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGesture* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QEvent* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // recognize(QGesture*,QObject*,QEvent*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGestureRecognizer.recognize()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGestureRecognizer::ResultFlag> cppResult = cppSelf->recognize(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGestureRecognizerFunc_recognize_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGesture, PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGestureRecognizer.recognize", overloads);
        return 0;
}

static PyObject* Sbk_QGestureRecognizerFunc_registerRecognizer(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: registerRecognizer(QGestureRecognizer*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX], (pyArg)))) {
        overloadId = 0; // registerRecognizer(QGestureRecognizer*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureRecognizerFunc_registerRecognizer_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGestureRecognizer* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // registerRecognizer(QGestureRecognizer*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::GestureType cppResult = ::QGestureRecognizer::registerRecognizer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGestureRecognizerFunc_registerRecognizer_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGestureRecognizer", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureRecognizer.registerRecognizer", overloads);
        return 0;
}

static PyObject* Sbk_QGestureRecognizerFunc_reset(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGestureRecognizer*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reset(QGesture*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGESTURE_IDX], (pyArg)))) {
        overloadId = 0; // reset(QGesture*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureRecognizerFunc_reset_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGesture* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reset(QGesture*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGestureRecognizer::reset(cppArg0) : cppSelf->reset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureRecognizerFunc_reset_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGesture", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureRecognizer.reset", overloads);
        return 0;
}

static PyObject* Sbk_QGestureRecognizerFunc_unregisterRecognizer(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unregisterRecognizer(Qt::GestureType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GESTURETYPE_IDX]), (pyArg)))) {
        overloadId = 0; // unregisterRecognizer(Qt::GestureType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGestureRecognizerFunc_unregisterRecognizer_TypeError;

    // Call function/method
    {
        ::Qt::GestureType cppArg0 = ((::Qt::GestureType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unregisterRecognizer(Qt::GestureType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGestureRecognizer::unregisterRecognizer(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGestureRecognizerFunc_unregisterRecognizer_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.GestureType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGestureRecognizer.unregisterRecognizer", overloads);
        return 0;
}

static PyMethodDef Sbk_QGestureRecognizer_methods[] = {
    {"create", (PyCFunction)Sbk_QGestureRecognizerFunc_create, METH_O},
    {"recognize", (PyCFunction)Sbk_QGestureRecognizerFunc_recognize, METH_VARARGS},
    {"registerRecognizer", (PyCFunction)Sbk_QGestureRecognizerFunc_registerRecognizer, METH_O|METH_STATIC},
    {"reset", (PyCFunction)Sbk_QGestureRecognizerFunc_reset, METH_O},
    {"unregisterRecognizer", (PyCFunction)Sbk_QGestureRecognizerFunc_unregisterRecognizer, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGestureRecognizer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGestureRecognizer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGestureRecognizer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGestureRecognizer",
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
    /*tp_traverse*/         Sbk_QGestureRecognizer_traverse,
    /*tp_clear*/            Sbk_QGestureRecognizer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGestureRecognizer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGestureRecognizer_Init,
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

PyObject* SbkPySide_QtGui_QGestureRecognizer_ResultFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer::Result cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGestureRecognizer::Result)PyLong_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGestureRecognizer::Result)PyInt_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGestureRecognizer_ResultFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer::Result cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGestureRecognizer::Result)PyLong_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGestureRecognizer::Result)PyInt_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGestureRecognizer_ResultFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer::Result cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGestureRecognizer::Result)PyLong_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGestureRecognizer::Result)PyInt_AsLong(self);
    cppArg = (QGestureRecognizer::Result)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGestureRecognizer_ResultFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGestureRecognizer::Result cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), self, &cppSelf);
    ::QGestureRecognizer::Result cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGestureRecognizer_ResultFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGestureRecognizer_ResultFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGestureRecognizer_ResultFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGestureRecognizer_ResultFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGestureRecognizer_ResultFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGestureRecognizer_ResultFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGestureRecognizer_ResultFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGestureRecognizer_ResultFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGestureRecognizer_ResultFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGestureRecognizer_ResultFlag_long,
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
static void QGestureRecognizer_ResultFlag_PythonToCpp_QGestureRecognizer_ResultFlag(PyObject* pyIn, void* cppOut) {
    *((::QGestureRecognizer::ResultFlag*)cppOut) = (::QGestureRecognizer::ResultFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGestureRecognizer_ResultFlag_PythonToCpp_QGestureRecognizer_ResultFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX]))
        return QGestureRecognizer_ResultFlag_PythonToCpp_QGestureRecognizer_ResultFlag;
    return 0;
}
static PyObject* QGestureRecognizer_ResultFlag_CppToPython_QGestureRecognizer_ResultFlag(const void* cppIn) {
    int castCppIn = *((::QGestureRecognizer::ResultFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX], castCppIn);

}

static void QFlags_QGestureRecognizer_ResultFlag__PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGestureRecognizer::ResultFlag>*)cppOut) = ::QFlags<QGestureRecognizer::ResultFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGestureRecognizer_ResultFlag__PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]))
        return QFlags_QGestureRecognizer_ResultFlag__PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_;
    return 0;
}
static PyObject* QFlags_QGestureRecognizer_ResultFlag__CppToPython_QFlags_QGestureRecognizer_ResultFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGestureRecognizer::ResultFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]));

}

static void QGestureRecognizer_ResultFlag_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGestureRecognizer::ResultFlag>*)cppOut) = ::QFlags<QGestureRecognizer::ResultFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGestureRecognizer_ResultFlag_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX]))
        return QGestureRecognizer_ResultFlag_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGestureRecognizer::ResultFlag>*)cppOut) = ::QFlags<QGestureRecognizer::ResultFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGestureRecognizer_PythonToCpp_QGestureRecognizer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGestureRecognizer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGestureRecognizer_PythonToCpp_QGestureRecognizer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGestureRecognizer_Type))
        return QGestureRecognizer_PythonToCpp_QGestureRecognizer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGestureRecognizer_PTR_CppToPython_QGestureRecognizer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGestureRecognizer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGestureRecognizer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGestureRecognizer(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGestureRecognizer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGestureRecognizer", "QGestureRecognizer*",
        &Sbk_QGestureRecognizer_Type, &Shiboken::callCppDestructor< ::QGestureRecognizer >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGestureRecognizer_Type,
        QGestureRecognizer_PythonToCpp_QGestureRecognizer_PTR,
        is_QGestureRecognizer_PythonToCpp_QGestureRecognizer_PTR_Convertible,
        QGestureRecognizer_PTR_CppToPython_QGestureRecognizer);

    Shiboken::Conversions::registerConverterName(converter, "QGestureRecognizer");
    Shiboken::Conversions::registerConverterName(converter, "QGestureRecognizer*");
    Shiboken::Conversions::registerConverterName(converter, "QGestureRecognizer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGestureRecognizer).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGestureRecognizerWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ResultFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX] = PySide::QFlags::create("Result", &SbkPySide_QtGui_QGestureRecognizer_ResultFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGestureRecognizer_Type,
        "ResultFlag",
        "PySide.QtGui.QGestureRecognizer.ResultFlag",
        "QGestureRecognizer::ResultFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "Ignore", (long) QGestureRecognizer::Ignore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "MayBeGesture", (long) QGestureRecognizer::MayBeGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "TriggerGesture", (long) QGestureRecognizer::TriggerGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "FinishGesture", (long) QGestureRecognizer::FinishGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "CancelGesture", (long) QGestureRecognizer::CancelGesture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "ResultState_Mask", (long) QGestureRecognizer::ResultState_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "ConsumeEventHint", (long) QGestureRecognizer::ConsumeEventHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
        &Sbk_QGestureRecognizer_Type, "ResultHint_Mask", (long) QGestureRecognizer::ResultHint_Mask))
        return ;
    // Register converter for enum 'QGestureRecognizer::ResultFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX],
            QGestureRecognizer_ResultFlag_CppToPython_QGestureRecognizer_ResultFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGestureRecognizer_ResultFlag_PythonToCpp_QGestureRecognizer_ResultFlag,
            is_QGestureRecognizer_ResultFlag_PythonToCpp_QGestureRecognizer_ResultFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGESTURERECOGNIZER_RESULTFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGestureRecognizer::ResultFlag");
        Shiboken::Conversions::registerConverterName(converter, "ResultFlag");
    }
    // Register converter for flag 'QFlags<QGestureRecognizer::ResultFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX],
            QFlags_QGestureRecognizer_ResultFlag__CppToPython_QFlags_QGestureRecognizer_ResultFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGestureRecognizer_ResultFlag_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_,
            is_QGestureRecognizer_ResultFlag_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGestureRecognizer_ResultFlag__PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_,
            is_QFlags_QGestureRecognizer_ResultFlag__PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag_,
            is_number_PythonToCpp_QFlags_QGestureRecognizer_ResultFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGESTURERECOGNIZER_RESULTFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGestureRecognizer::ResultFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ResultFlag>");
    }
    // End of 'ResultFlag' enum/flags.


    qRegisterMetaType< ::QGestureRecognizer::ResultFlag >("QGestureRecognizer::ResultFlag");
    qRegisterMetaType< ::QGestureRecognizer::Result >("QGestureRecognizer::Result");
}
