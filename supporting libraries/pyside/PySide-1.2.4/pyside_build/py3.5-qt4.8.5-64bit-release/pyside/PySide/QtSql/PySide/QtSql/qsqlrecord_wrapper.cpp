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

#include "qsqlrecord_wrapper.h"

// Extra includes
#include <QSqlField>
#include <qsqlfield.h>
#include <qsqlrecord.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlRecord_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlRecord >()))
        return -1;

    ::QSqlRecord* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QSqlRecord", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlRecord()
    // 1: QSqlRecord(QSqlRecord)
    if (numArgs == 0) {
        overloadId = 0; // QSqlRecord()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArgs[0])))) {
        overloadId = 1; // QSqlRecord(QSqlRecord)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecord_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlRecord()
        {

            if (!PyErr_Occurred()) {
                // QSqlRecord()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlRecord();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlRecord(const QSqlRecord & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlRecord cppArg0_local = ::QSqlRecord();
            ::QSqlRecord* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlRecord(QSqlRecord)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlRecord(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlRecord >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlRecord_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlRecord_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtSql.QSqlRecord", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRecord", overloads);
        return -1;
}

static PyObject* Sbk_QSqlRecordFunc_append(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: append(QSqlField)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArg)))) {
        overloadId = 0; // append(QSqlField)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_append_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
        ::QSqlField* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // append(QSqlField)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->append(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_append_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlField", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.append", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_clear(PyObject* self)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QSqlRecordFunc_clearValues(PyObject* self)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearValues()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearValues();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSqlRecordFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_contains_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_contains_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.contains", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_count(PyObject* self)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->count();
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

static PyObject* Sbk_QSqlRecordFunc_field(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: field(QString)const
    // 1: field(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // field(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // field(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_field_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // field(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // field(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QSqlField cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->field(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], &cppResult);
            }
            break;
        }
        case 1: // field(int i) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // field(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QSqlField cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->field(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_field_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.field", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_fieldName(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fieldName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fieldName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_fieldName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fieldName(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->fieldName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_fieldName_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.fieldName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_indexOf(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOf(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // indexOf(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_indexOf_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOf(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->indexOf(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_indexOf_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.indexOf", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_insert(PyObject* self, PyObject* args)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insert(int,QSqlField)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArgs[1])))) {
        overloadId = 0; // insert(int,QSqlField)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_insert_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlField cppArg1_local = ::QSqlField(::QString(), QVariant::Invalid);
        ::QSqlField* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insert(int,QSqlField)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insert(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_insert_TypeError:
        const char* overloads[] = {"int, PySide.QtSql.QSqlField", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRecord.insert", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_isEmpty(PyObject* self)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QSqlRecordFunc_isGenerated(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isGenerated(QString)const
    // 1: isGenerated(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // isGenerated(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isGenerated(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_isGenerated_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isGenerated(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // isGenerated(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->isGenerated(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isGenerated(int i) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // isGenerated(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->isGenerated(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_isGenerated_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.isGenerated", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_isNull(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isNull(QString)const
    // 1: isNull(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // isNull(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isNull(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_isNull_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isNull(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // isNull(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->isNull(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isNull(int i) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // isNull(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->isNull(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_isNull_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.isNull", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // remove(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_remove_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // remove(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->remove(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_remove_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.remove", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_replace(PyObject* self, PyObject* args)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(int,QSqlField)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(int,QSqlField)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_replace_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSqlField cppArg1_local = ::QSqlField(::QString(), QVariant::Invalid);
        ::QSqlField* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // replace(int,QSqlField)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->replace(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_replace_TypeError:
        const char* overloads[] = {"int, PySide.QtSql.QSqlField", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRecord.replace", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_setGenerated(PyObject* self, PyObject* args)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setGenerated", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setGenerated(QString,bool)
    // 1: setGenerated(int,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 1; // setGenerated(int,bool)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // setGenerated(QString,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_setGenerated_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setGenerated(const QString & name, bool generated)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setGenerated(QString,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setGenerated(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setGenerated(int i, bool generated)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setGenerated(int,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setGenerated(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_setGenerated_TypeError:
        const char* overloads[] = {"unicode, bool", "int, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRecord.setGenerated", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_setNull(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNull(QString)
    // 1: setNull(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // setNull(int)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNull(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_setNull_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setNull(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setNull(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setNull(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setNull(int i)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setNull(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setNull(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_setNull_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.setNull", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_setValue(PyObject* self, PyObject* args)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValue(QString,QVariant)
    // 1: setValue(int,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 1; // setValue(int,QVariant)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setValue(QString,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_setValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setValue(const QString & name, const QVariant & val)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setValue(QString,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setValue(int i, const QVariant & val)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setValue(int,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlRecordFunc_setValue_TypeError:
        const char* overloads[] = {"unicode, QVariant", "int, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlRecord.setValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecordFunc_value(PyObject* self, PyObject* pyArg)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: value(QString)const
    // 1: value(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // value(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // value(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlRecordFunc_value_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // value(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // value(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
        case 1: // value(int i) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // value(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVariant cppResult = const_cast<const ::QSqlRecord*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSqlRecordFunc_value_TypeError:
        const char* overloads[] = {"unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlRecord.value", overloads);
        return 0;
}

static PyObject* Sbk_QSqlRecord___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlRecord& cppSelf = *(((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlRecord_methods[] = {
    {"append", (PyCFunction)Sbk_QSqlRecordFunc_append, METH_O},
    {"clear", (PyCFunction)Sbk_QSqlRecordFunc_clear, METH_NOARGS},
    {"clearValues", (PyCFunction)Sbk_QSqlRecordFunc_clearValues, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QSqlRecordFunc_contains, METH_O},
    {"count", (PyCFunction)Sbk_QSqlRecordFunc_count, METH_NOARGS},
    {"field", (PyCFunction)Sbk_QSqlRecordFunc_field, METH_O},
    {"fieldName", (PyCFunction)Sbk_QSqlRecordFunc_fieldName, METH_O},
    {"indexOf", (PyCFunction)Sbk_QSqlRecordFunc_indexOf, METH_O},
    {"insert", (PyCFunction)Sbk_QSqlRecordFunc_insert, METH_VARARGS},
    {"isEmpty", (PyCFunction)Sbk_QSqlRecordFunc_isEmpty, METH_NOARGS},
    {"isGenerated", (PyCFunction)Sbk_QSqlRecordFunc_isGenerated, METH_O},
    {"isNull", (PyCFunction)Sbk_QSqlRecordFunc_isNull, METH_O},
    {"remove", (PyCFunction)Sbk_QSqlRecordFunc_remove, METH_O},
    {"replace", (PyCFunction)Sbk_QSqlRecordFunc_replace, METH_VARARGS},
    {"setGenerated", (PyCFunction)Sbk_QSqlRecordFunc_setGenerated, METH_VARARGS},
    {"setNull", (PyCFunction)Sbk_QSqlRecordFunc_setNull, METH_O},
    {"setValue", (PyCFunction)Sbk_QSqlRecordFunc_setValue, METH_VARARGS},
    {"value", (PyCFunction)Sbk_QSqlRecordFunc_value, METH_O},

    {"__copy__", (PyCFunction)Sbk_QSqlRecord___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QSqlRecord_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlRecord& cppSelf = *(((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArg)))) {
                // operator!=(const QSqlRecord & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSqlRecord cppArg0_local = ::QSqlRecord();
                ::QSqlRecord* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (pyArg)))) {
                // operator==(const QSqlRecord & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSqlRecord cppArg0_local = ::QSqlRecord();
                ::QSqlRecord* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], pythonToCpp))
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
            goto Sbk_QSqlRecord_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSqlRecord_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSqlRecord_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlRecord_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSqlRecord__repr__(PyObject* self)
{
    ::QSqlRecord* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSqlRecord_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlRecord",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSqlRecord__repr__,
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
    /*tp_traverse*/         Sbk_QSqlRecord_traverse,
    /*tp_clear*/            Sbk_QSqlRecord_clear,
    /*tp_richcompare*/      Sbk_QSqlRecord_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlRecord_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlRecord_Init,
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
static void QSqlRecord_PythonToCpp_QSqlRecord_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlRecord_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlRecord_PythonToCpp_QSqlRecord_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlRecord_Type))
        return QSqlRecord_PythonToCpp_QSqlRecord_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlRecord_PTR_CppToPython_QSqlRecord(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlRecord*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlRecord_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlRecord_COPY_CppToPython_QSqlRecord(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlRecord_Type, new ::QSqlRecord(*((::QSqlRecord*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlRecord_PythonToCpp_QSqlRecord_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlRecord*)cppOut) = *((::QSqlRecord*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlRecord_PythonToCpp_QSqlRecord_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlRecord_Type))
        return QSqlRecord_PythonToCpp_QSqlRecord_COPY;
    return 0;
}

void init_QSqlRecord(PyObject* module)
{
    SbkPySide_QtSqlTypes[SBK_QSQLRECORD_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlRecord_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlRecord", "QSqlRecord",
        &Sbk_QSqlRecord_Type, &Shiboken::callCppDestructor< ::QSqlRecord >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlRecord_Type,
        QSqlRecord_PythonToCpp_QSqlRecord_PTR,
        is_QSqlRecord_PythonToCpp_QSqlRecord_PTR_Convertible,
        QSqlRecord_PTR_CppToPython_QSqlRecord,
        QSqlRecord_COPY_CppToPython_QSqlRecord);

    Shiboken::Conversions::registerConverterName(converter, "QSqlRecord");
    Shiboken::Conversions::registerConverterName(converter, "QSqlRecord*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlRecord&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlRecord).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlRecord_PythonToCpp_QSqlRecord_COPY,
        is_QSqlRecord_PythonToCpp_QSqlRecord_COPY_Convertible);


    qRegisterMetaType< ::QSqlRecord >("QSqlRecord");
}
