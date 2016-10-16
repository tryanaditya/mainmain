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

#include "qprocessenvironment_wrapper.h"

// Extra includes
#include <qprocess.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QProcessEnvironment_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QProcessEnvironment >()))
        return -1;

    ::QProcessEnvironment* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QProcessEnvironment", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QProcessEnvironment()
    // 1: QProcessEnvironment(QProcessEnvironment)
    if (numArgs == 0) {
        overloadId = 0; // QProcessEnvironment()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QProcessEnvironment(QProcessEnvironment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessEnvironment_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QProcessEnvironment()
        {

            if (!PyErr_Occurred()) {
                // QProcessEnvironment()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QProcessEnvironment();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QProcessEnvironment(const QProcessEnvironment & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QProcessEnvironment cppArg0_local = ::QProcessEnvironment();
            ::QProcessEnvironment* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QProcessEnvironment(QProcessEnvironment)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QProcessEnvironment(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QProcessEnvironment >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QProcessEnvironment_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QProcessEnvironment_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QProcessEnvironment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcessEnvironment", overloads);
        return -1;
}

static PyObject* Sbk_QProcessEnvironmentFunc_clear(PyObject* self)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessEnvironmentFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // contains(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessEnvironmentFunc_contains_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QProcessEnvironment*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessEnvironmentFunc_contains_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcessEnvironment.contains", overloads);
        return 0;
}

static PyObject* Sbk_QProcessEnvironmentFunc_insert(PyObject* self, PyObject* args)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insert(QProcessEnvironment)
    // 1: insert(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // insert(QString,QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (pyArgs[0])))) {
        overloadId = 0; // insert(QProcessEnvironment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessEnvironmentFunc_insert_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insert(const QProcessEnvironment & e)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QProcessEnvironment cppArg0_local = ::QProcessEnvironment();
            ::QProcessEnvironment* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // insert(QProcessEnvironment)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // insert(const QString & name, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insert(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessEnvironmentFunc_insert_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcessEnvironment", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcessEnvironment.insert", overloads);
        return 0;
}

static PyObject* Sbk_QProcessEnvironmentFunc_isEmpty(PyObject* self)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QProcessEnvironment*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QProcessEnvironmentFunc_keys(PyObject* self)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keys()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QProcessEnvironment*>(cppSelf)->keys();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessEnvironmentFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // remove(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessEnvironmentFunc_remove_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // remove(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->remove(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessEnvironmentFunc_remove_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcessEnvironment.remove", overloads);
        return 0;
}

static PyObject* Sbk_QProcessEnvironmentFunc_systemEnvironment(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemEnvironment()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcessEnvironment cppResult = ::QProcessEnvironment::systemEnvironment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessEnvironmentFunc_toStringList(PyObject* self)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toStringList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QProcessEnvironment*>(cppSelf)->toStringList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessEnvironmentFunc_value(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcessEnvironment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcessEnvironment.value(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcessEnvironment.value(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:value", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: value(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // value(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // value(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessEnvironmentFunc_value_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defaultValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcessEnvironment.value(): got multiple values for keyword argument 'defaultValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QProcessEnvironmentFunc_value_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // value(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QProcessEnvironment*>(cppSelf)->value(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessEnvironmentFunc_value_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcessEnvironment.value", overloads);
        return 0;
}

static PyObject* Sbk_QProcessEnvironment___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QProcessEnvironment& cppSelf = *(((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QProcessEnvironment_methods[] = {
    {"clear", (PyCFunction)Sbk_QProcessEnvironmentFunc_clear, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QProcessEnvironmentFunc_contains, METH_O},
    {"insert", (PyCFunction)Sbk_QProcessEnvironmentFunc_insert, METH_VARARGS},
    {"isEmpty", (PyCFunction)Sbk_QProcessEnvironmentFunc_isEmpty, METH_NOARGS},
    {"keys", (PyCFunction)Sbk_QProcessEnvironmentFunc_keys, METH_NOARGS},
    {"remove", (PyCFunction)Sbk_QProcessEnvironmentFunc_remove, METH_O},
    {"systemEnvironment", (PyCFunction)Sbk_QProcessEnvironmentFunc_systemEnvironment, METH_NOARGS|METH_STATIC},
    {"toStringList", (PyCFunction)Sbk_QProcessEnvironmentFunc_toStringList, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QProcessEnvironmentFunc_value, METH_VARARGS|METH_KEYWORDS},

    {"__copy__", (PyCFunction)Sbk_QProcessEnvironment___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QProcessEnvironment_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QProcessEnvironment& cppSelf = *(((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (pyArg)))) {
                // operator!=(const QProcessEnvironment & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QProcessEnvironment cppArg0_local = ::QProcessEnvironment();
                ::QProcessEnvironment* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (pyArg)))) {
                // operator==(const QProcessEnvironment & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QProcessEnvironment cppArg0_local = ::QProcessEnvironment();
                ::QProcessEnvironment* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QProcessEnvironment_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QProcessEnvironment_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QProcessEnvironment_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QProcessEnvironment_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QProcessEnvironment_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QProcessEnvironment",
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
    /*tp_traverse*/         Sbk_QProcessEnvironment_traverse,
    /*tp_clear*/            Sbk_QProcessEnvironment_clear,
    /*tp_richcompare*/      Sbk_QProcessEnvironment_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QProcessEnvironment_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QProcessEnvironment_Init,
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
static void QProcessEnvironment_PythonToCpp_QProcessEnvironment_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QProcessEnvironment_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QProcessEnvironment_PythonToCpp_QProcessEnvironment_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QProcessEnvironment_Type))
        return QProcessEnvironment_PythonToCpp_QProcessEnvironment_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QProcessEnvironment_PTR_CppToPython_QProcessEnvironment(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QProcessEnvironment*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QProcessEnvironment_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QProcessEnvironment_COPY_CppToPython_QProcessEnvironment(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QProcessEnvironment_Type, new ::QProcessEnvironment(*((::QProcessEnvironment*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QProcessEnvironment_PythonToCpp_QProcessEnvironment_COPY(PyObject* pyIn, void* cppOut) {
    *((::QProcessEnvironment*)cppOut) = *((::QProcessEnvironment*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QProcessEnvironment_PythonToCpp_QProcessEnvironment_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QProcessEnvironment_Type))
        return QProcessEnvironment_PythonToCpp_QProcessEnvironment_COPY;
    return 0;
}

void init_QProcessEnvironment(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QProcessEnvironment_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QProcessEnvironment", "QProcessEnvironment",
        &Sbk_QProcessEnvironment_Type, &Shiboken::callCppDestructor< ::QProcessEnvironment >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QProcessEnvironment_Type,
        QProcessEnvironment_PythonToCpp_QProcessEnvironment_PTR,
        is_QProcessEnvironment_PythonToCpp_QProcessEnvironment_PTR_Convertible,
        QProcessEnvironment_PTR_CppToPython_QProcessEnvironment,
        QProcessEnvironment_COPY_CppToPython_QProcessEnvironment);

    Shiboken::Conversions::registerConverterName(converter, "QProcessEnvironment");
    Shiboken::Conversions::registerConverterName(converter, "QProcessEnvironment*");
    Shiboken::Conversions::registerConverterName(converter, "QProcessEnvironment&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QProcessEnvironment).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QProcessEnvironment_PythonToCpp_QProcessEnvironment_COPY,
        is_QProcessEnvironment_PythonToCpp_QProcessEnvironment_COPY_Convertible);


    qRegisterMetaType< ::QProcessEnvironment >("QProcessEnvironment");
}
