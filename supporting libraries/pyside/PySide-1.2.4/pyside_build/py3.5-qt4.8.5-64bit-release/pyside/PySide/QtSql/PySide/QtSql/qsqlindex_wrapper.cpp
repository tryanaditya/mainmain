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
#include "pyside_qtsql_python.h"

#include "qsqlindex_wrapper.h"

// Extra includes
#include <qsqlfield.h>
#include <qsqlindex.h>
#include <qsqlrecord.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlIndex_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlIndex >()))
        return -1;

    ::QSqlIndex* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlIndex(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QSqlIndex", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlIndex(QSqlIndex)
    // 1: QSqlIndex(QString,QString)
    if (numArgs == 0) {
        overloadId = 1; // QSqlIndex(QString,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSqlIndex(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // QSqlIndex(QString,QString)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlIndex(QSqlIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndex_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlIndex(const QSqlIndex & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlIndex cppArg0_local = ::QSqlIndex(::QString(), ::QString());
            ::QSqlIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlIndex(QSqlIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlIndex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlIndex(const QString & cursorName, const QString & name)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "cursorName");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlIndex(): got multiple values for keyword argument 'cursorName'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QSqlIndex_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "name");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlIndex(): got multiple values for keyword argument 'name'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlIndex_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSqlIndex(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlIndex(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlIndex >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlIndex_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlIndex_Init_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlIndex", "unicode = QString(), unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlIndex", overloads);
        return -1;
}

static PyObject* Sbk_QSqlIndexFunc_append(PyObject* self, PyObject* args)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "append", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: append(QSqlField)
    // 1: append(QSqlField,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // append(QSqlField)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 1; // append(QSqlField,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndexFunc_append_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // append(const QSqlField & field)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
            ::QSqlField* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // append(QSqlField)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // append(const QSqlField & field, bool desc)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
            ::QSqlField* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // append(QSqlField,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlIndexFunc_append_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlField", "PySide.QtSql.QSqlField, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlIndex.append", overloads);
        return 0;
}

static PyObject* Sbk_QSqlIndexFunc_cursorName(PyObject* self)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlIndex*>(cppSelf)->cursorName();
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

static PyObject* Sbk_QSqlIndexFunc_isDescending(PyObject* self, PyObject* pyArg)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isDescending(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // isDescending(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndexFunc_isDescending_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isDescending(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlIndex*>(cppSelf)->isDescending(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlIndexFunc_isDescending_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlIndex.isDescending", overloads);
        return 0;
}

static PyObject* Sbk_QSqlIndexFunc_name(PyObject* self)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlIndex*>(cppSelf)->name();
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

static PyObject* Sbk_QSqlIndexFunc_setCursorName(PyObject* self, PyObject* pyArg)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursorName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setCursorName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndexFunc_setCursorName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursorName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursorName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlIndexFunc_setCursorName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlIndex.setCursorName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlIndexFunc_setDescending(PyObject* self, PyObject* args)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDescending", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDescending(int,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // setDescending(int,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndexFunc_setDescending_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDescending(int,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDescending(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlIndexFunc_setDescending_TypeError:
        const char* overloads[] = {"int, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlIndex.setDescending", overloads);
        return 0;
}

static PyObject* Sbk_QSqlIndexFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::QSqlIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlIndexFunc_setName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlIndexFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlIndex.setName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlIndex___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlIndex& cppSelf = *(((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlIndex_methods[] = {
    {"append", (PyCFunction)Sbk_QSqlIndexFunc_append, METH_VARARGS},
    {"cursorName", (PyCFunction)Sbk_QSqlIndexFunc_cursorName, METH_NOARGS},
    {"isDescending", (PyCFunction)Sbk_QSqlIndexFunc_isDescending, METH_O},
    {"name", (PyCFunction)Sbk_QSqlIndexFunc_name, METH_NOARGS},
    {"setCursorName", (PyCFunction)Sbk_QSqlIndexFunc_setCursorName, METH_O},
    {"setDescending", (PyCFunction)Sbk_QSqlIndexFunc_setDescending, METH_VARARGS},
    {"setName", (PyCFunction)Sbk_QSqlIndexFunc_setName, METH_O},

    {"__copy__", (PyCFunction)Sbk_QSqlIndex___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSqlIndex_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlIndex_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlIndex_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlIndex",
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
    /*tp_traverse*/         Sbk_QSqlIndex_traverse,
    /*tp_clear*/            Sbk_QSqlIndex_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlIndex_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlIndex_Init,
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
static void QSqlIndex_PythonToCpp_QSqlIndex_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlIndex_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlIndex_PythonToCpp_QSqlIndex_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlIndex_Type))
        return QSqlIndex_PythonToCpp_QSqlIndex_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlIndex_PTR_CppToPython_QSqlIndex(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlIndex*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlIndex_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlIndex_COPY_CppToPython_QSqlIndex(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlIndex_Type, new ::QSqlIndex(*((::QSqlIndex*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlIndex_PythonToCpp_QSqlIndex_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlIndex*)cppOut) = *((::QSqlIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlIndex_PythonToCpp_QSqlIndex_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlIndex_Type))
        return QSqlIndex_PythonToCpp_QSqlIndex_COPY;
    return 0;
}

void init_QSqlIndex(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLINDEX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlIndex_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlIndex", "QSqlIndex",
        &Sbk_QSqlIndex_Type, &Shiboken::callCppDestructor< ::QSqlIndex >, (SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlIndex_Type,
        QSqlIndex_PythonToCpp_QSqlIndex_PTR,
        is_QSqlIndex_PythonToCpp_QSqlIndex_PTR_Convertible,
        QSqlIndex_PTR_CppToPython_QSqlIndex,
        QSqlIndex_COPY_CppToPython_QSqlIndex);

    Shiboken::Conversions::registerConverterName(converter, "QSqlIndex");
    Shiboken::Conversions::registerConverterName(converter, "QSqlIndex*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlIndex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlIndex).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlIndex_PythonToCpp_QSqlIndex_COPY,
        is_QSqlIndex_PythonToCpp_QSqlIndex_COPY_Convertible);


}
