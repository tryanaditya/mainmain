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

#include "qmetaenum_wrapper.h"

// Extra includes
#include <qbytearray.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMetaEnum_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMetaEnum >()))
        return -1;

    ::QMetaEnum* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMetaEnum", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMetaEnum()
    // 1: QMetaEnum(QMetaEnum)
    if (numArgs == 0) {
        overloadId = 0; // QMetaEnum()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMetaEnum(QMetaEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnum_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMetaEnum()
        {

            if (!PyErr_Occurred()) {
                // QMetaEnum()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaEnum();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QMetaEnum(const QMetaEnum & QMetaEnum)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMetaEnum cppArg0_local = ::QMetaEnum();
            ::QMetaEnum* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMetaEnum(QMetaEnum)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaEnum(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMetaEnum >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMetaEnum_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMetaEnum_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QMetaEnum", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaEnum", overloads);
        return -1;
}

static PyObject* Sbk_QMetaEnumFunc_isFlag(PyObject* self)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFlag()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->isFlag();
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

static PyObject* Sbk_QMetaEnumFunc_isValid(PyObject* self)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->isValid();
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

static PyObject* Sbk_QMetaEnumFunc_key(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: key(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // key(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_key_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // key(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->key(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_key_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.key", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnumFunc_keyCount(PyObject* self)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->keyCount();
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

static PyObject* Sbk_QMetaEnumFunc_keyToValue(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyToValue(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // keyToValue(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_keyToValue_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyToValue(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->keyToValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_keyToValue_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.keyToValue", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnumFunc_keysToValue(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keysToValue(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // keysToValue(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_keysToValue_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keysToValue(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->keysToValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_keysToValue_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.keysToValue", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnumFunc_name(PyObject* self)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaEnumFunc_scope(PyObject* self)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scope()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->scope();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaEnumFunc_value(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: value(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // value(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_value_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // value(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->value(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_value_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.value", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnumFunc_valueToKey(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: valueToKey(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // valueToKey(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_valueToKey_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // valueToKey(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->valueToKey(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_valueToKey_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.valueToKey", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnumFunc_valueToKeys(PyObject* self, PyObject* pyArg)
{
    ::QMetaEnum* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: valueToKeys(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // valueToKeys(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaEnumFunc_valueToKeys_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // valueToKeys(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QMetaEnum*>(cppSelf)->valueToKeys(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaEnumFunc_valueToKeys_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaEnum.valueToKeys", overloads);
        return 0;
}

static PyObject* Sbk_QMetaEnum___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMetaEnum& cppSelf = *(((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMetaEnum_methods[] = {
    {"isFlag", (PyCFunction)Sbk_QMetaEnumFunc_isFlag, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QMetaEnumFunc_isValid, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QMetaEnumFunc_key, METH_O},
    {"keyCount", (PyCFunction)Sbk_QMetaEnumFunc_keyCount, METH_NOARGS},
    {"keyToValue", (PyCFunction)Sbk_QMetaEnumFunc_keyToValue, METH_O},
    {"keysToValue", (PyCFunction)Sbk_QMetaEnumFunc_keysToValue, METH_O},
    {"name", (PyCFunction)Sbk_QMetaEnumFunc_name, METH_NOARGS},
    {"scope", (PyCFunction)Sbk_QMetaEnumFunc_scope, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QMetaEnumFunc_value, METH_O},
    {"valueToKey", (PyCFunction)Sbk_QMetaEnumFunc_valueToKey, METH_O},
    {"valueToKeys", (PyCFunction)Sbk_QMetaEnumFunc_valueToKeys, METH_O},

    {"__copy__", (PyCFunction)Sbk_QMetaEnum___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMetaEnum_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMetaEnum_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMetaEnum_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMetaEnum",
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
    /*tp_traverse*/         Sbk_QMetaEnum_traverse,
    /*tp_clear*/            Sbk_QMetaEnum_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMetaEnum_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMetaEnum_Init,
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
static void QMetaEnum_PythonToCpp_QMetaEnum_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMetaEnum_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMetaEnum_PythonToCpp_QMetaEnum_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaEnum_Type))
        return QMetaEnum_PythonToCpp_QMetaEnum_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMetaEnum_PTR_CppToPython_QMetaEnum(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMetaEnum*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMetaEnum_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QMetaEnum_COPY_CppToPython_QMetaEnum(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QMetaEnum_Type, new ::QMetaEnum(*((::QMetaEnum*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QMetaEnum_PythonToCpp_QMetaEnum_COPY(PyObject* pyIn, void* cppOut) {
    *((::QMetaEnum*)cppOut) = *((::QMetaEnum*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QMetaEnum_PythonToCpp_QMetaEnum_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaEnum_Type))
        return QMetaEnum_PythonToCpp_QMetaEnum_COPY;
    return 0;
}

void init_QMetaEnum(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMetaEnum_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMetaEnum", "QMetaEnum",
        &Sbk_QMetaEnum_Type, &Shiboken::callCppDestructor< ::QMetaEnum >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMetaEnum_Type,
        QMetaEnum_PythonToCpp_QMetaEnum_PTR,
        is_QMetaEnum_PythonToCpp_QMetaEnum_PTR_Convertible,
        QMetaEnum_PTR_CppToPython_QMetaEnum,
        QMetaEnum_COPY_CppToPython_QMetaEnum);

    Shiboken::Conversions::registerConverterName(converter, "QMetaEnum");
    Shiboken::Conversions::registerConverterName(converter, "QMetaEnum*");
    Shiboken::Conversions::registerConverterName(converter, "QMetaEnum&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMetaEnum).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QMetaEnum_PythonToCpp_QMetaEnum_COPY,
        is_QMetaEnum_PythonToCpp_QMetaEnum_COPY_Convertible);


    qRegisterMetaType< ::QMetaEnum >("QMetaEnum");
}
