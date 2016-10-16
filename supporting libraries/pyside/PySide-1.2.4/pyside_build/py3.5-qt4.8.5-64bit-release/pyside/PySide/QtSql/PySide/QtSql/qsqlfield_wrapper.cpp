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

#include "qsqlfield_wrapper.h"

// Extra includes
#include <qsqlfield.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSqlField_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSqlField >()))
        return -1;

    ::QSqlField* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlField(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QSqlField", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSqlField(QSqlField)
    // 1: QSqlField(QString,QVariant::Type)
    if (numArgs == 0) {
        overloadId = 1; // QSqlField(QString,QVariant::Type)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSqlField(QString,QVariant::Type)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArgs[1])))) {
            overloadId = 1; // QSqlField(QString,QVariant::Type)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSqlField(QSqlField)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlField_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSqlField(const QSqlField & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
            ::QSqlField* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QSqlField(QSqlField)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlField(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QSqlField(const QString & fieldName, QVariant::Type type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fieldName");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlField(): got multiple values for keyword argument 'fieldName'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QSqlField_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtSql.QSqlField(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArgs[1]))))
                        goto Sbk_QSqlField_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant::Type cppArg1 = QVariant::Invalid;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSqlField(QString,QVariant::Type)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QSqlField(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSqlField >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSqlField_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSqlField_Init_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlField", "unicode = QString(), QVariant::Type = QVariant.Invalid", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtSql.QSqlField", overloads);
        return -1;
}

static PyObject* Sbk_QSqlFieldFunc_clear(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QSqlFieldFunc_defaultValue(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QSqlField*>(cppSelf)->defaultValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlFieldFunc_isAutoValue(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAutoValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlField*>(cppSelf)->isAutoValue();
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

static PyObject* Sbk_QSqlFieldFunc_isGenerated(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isGenerated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlField*>(cppSelf)->isGenerated();
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

static PyObject* Sbk_QSqlFieldFunc_isNull(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlField*>(cppSelf)->isNull();
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

static PyObject* Sbk_QSqlFieldFunc_isReadOnly(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlField*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QSqlFieldFunc_isValid(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSqlField*>(cppSelf)->isValid();
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

static PyObject* Sbk_QSqlFieldFunc_length(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlField*>(cppSelf)->length();
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

static PyObject* Sbk_QSqlFieldFunc_name(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSqlField*>(cppSelf)->name();
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

static PyObject* Sbk_QSqlFieldFunc_precision(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // precision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlField*>(cppSelf)->precision();
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

static PyObject* Sbk_QSqlFieldFunc_requiredStatus(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // requiredStatus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSqlField::RequiredStatus cppResult = const_cast<const ::QSqlField*>(cppSelf)->requiredStatus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlFieldFunc_setAutoValue(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoValue(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoValue(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setAutoValue_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoValue(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setAutoValue_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setAutoValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultValue(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultValue(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultValue(QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setDefaultValue_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setDefaultValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setGenerated(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGenerated(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setGenerated(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setGenerated_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGenerated(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGenerated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setGenerated_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setGenerated", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setLength(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLength(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLength(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setLength_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLength(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLength(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setLength_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setLength", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setName(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setName_TypeError;

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

    Sbk_QSqlFieldFunc_setName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setName", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setPrecision(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrecision(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPrecision(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setPrecision_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrecision(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrecision(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setPrecision_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setPrecision", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setReadOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReadOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setRequired(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRequired(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setRequired(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setRequired_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRequired(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRequired(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setRequired_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setRequired", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setRequiredStatus(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRequiredStatus(QSqlField::RequiredStatus)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX]), (pyArg)))) {
        overloadId = 0; // setRequiredStatus(QSqlField::RequiredStatus)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setRequiredStatus_TypeError;

    // Call function/method
    {
        ::QSqlField::RequiredStatus cppArg0 = ((::QSqlField::RequiredStatus)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRequiredStatus(QSqlField::RequiredStatus)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRequiredStatus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setRequiredStatus_TypeError:
        const char* overloads[] = {"PySide.QtSql.QSqlField.RequiredStatus", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setRequiredStatus", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setSqlType(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSqlType(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSqlType(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setSqlType_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSqlType(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSqlType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setSqlType_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setSqlType", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setType(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setType(QVariant::Type)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArg)))) {
        overloadId = 0; // setType(QVariant::Type)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setType_TypeError;

    // Call function/method
    {
        ::QVariant::Type cppArg0 = QVariant::Invalid;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(QVariant::Type)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setType_TypeError:
        const char* overloads[] = {"QVariant::Type", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setType", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_setValue(PyObject* self, PyObject* pyArg)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValue(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSqlFieldFunc_setValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSqlFieldFunc_setValue_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtSql.QSqlField.setValue", overloads);
        return 0;
}

static PyObject* Sbk_QSqlFieldFunc_type(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant::Type cppResult = const_cast<const ::QSqlField*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlFieldFunc_typeID(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // typeID()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSqlField*>(cppSelf)->typeID();
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

static PyObject* Sbk_QSqlFieldFunc_value(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QSqlField*>(cppSelf)->value();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSqlField___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlField& cppSelf = *(((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QSqlField_methods[] = {
    {"clear", (PyCFunction)Sbk_QSqlFieldFunc_clear, METH_NOARGS},
    {"defaultValue", (PyCFunction)Sbk_QSqlFieldFunc_defaultValue, METH_NOARGS},
    {"isAutoValue", (PyCFunction)Sbk_QSqlFieldFunc_isAutoValue, METH_NOARGS},
    {"isGenerated", (PyCFunction)Sbk_QSqlFieldFunc_isGenerated, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QSqlFieldFunc_isNull, METH_NOARGS},
    {"isReadOnly", (PyCFunction)Sbk_QSqlFieldFunc_isReadOnly, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QSqlFieldFunc_isValid, METH_NOARGS},
    {"length", (PyCFunction)Sbk_QSqlFieldFunc_length, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QSqlFieldFunc_name, METH_NOARGS},
    {"precision", (PyCFunction)Sbk_QSqlFieldFunc_precision, METH_NOARGS},
    {"requiredStatus", (PyCFunction)Sbk_QSqlFieldFunc_requiredStatus, METH_NOARGS},
    {"setAutoValue", (PyCFunction)Sbk_QSqlFieldFunc_setAutoValue, METH_O},
    {"setDefaultValue", (PyCFunction)Sbk_QSqlFieldFunc_setDefaultValue, METH_O},
    {"setGenerated", (PyCFunction)Sbk_QSqlFieldFunc_setGenerated, METH_O},
    {"setLength", (PyCFunction)Sbk_QSqlFieldFunc_setLength, METH_O},
    {"setName", (PyCFunction)Sbk_QSqlFieldFunc_setName, METH_O},
    {"setPrecision", (PyCFunction)Sbk_QSqlFieldFunc_setPrecision, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QSqlFieldFunc_setReadOnly, METH_O},
    {"setRequired", (PyCFunction)Sbk_QSqlFieldFunc_setRequired, METH_O},
    {"setRequiredStatus", (PyCFunction)Sbk_QSqlFieldFunc_setRequiredStatus, METH_O},
    {"setSqlType", (PyCFunction)Sbk_QSqlFieldFunc_setSqlType, METH_O},
    {"setType", (PyCFunction)Sbk_QSqlFieldFunc_setType, METH_O},
    {"setValue", (PyCFunction)Sbk_QSqlFieldFunc_setValue, METH_O},
    {"type", (PyCFunction)Sbk_QSqlFieldFunc_type, METH_NOARGS},
    {"typeID", (PyCFunction)Sbk_QSqlFieldFunc_typeID, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QSqlFieldFunc_value, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QSqlField___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QSqlField___nb_bool(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QSqlField_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QSqlField& cppSelf = *(((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArg)))) {
                // operator!=(const QSqlField & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
                ::QSqlField* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (pyArg)))) {
                // operator==(const QSqlField & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QSqlField cppArg0_local = ::QSqlField(::QString(), QVariant::Invalid);
                ::QSqlField* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], pythonToCpp))
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
            goto Sbk_QSqlField_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QSqlField_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QSqlField_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSqlField_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QSqlField__repr__(PyObject* self)
{
    ::QSqlField* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QSqlField_TypeAsNumber;

static SbkObjectType Sbk_QSqlField_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtSql.QSqlField",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QSqlField__repr__,
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
    /*tp_traverse*/         Sbk_QSqlField_traverse,
    /*tp_clear*/            Sbk_QSqlField_clear,
    /*tp_richcompare*/      Sbk_QSqlField_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSqlField_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSqlField_Init,
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
static void QSqlField_RequiredStatus_PythonToCpp_QSqlField_RequiredStatus(PyObject* pyIn, void* cppOut) {
    *((::QSqlField::RequiredStatus*)cppOut) = (::QSqlField::RequiredStatus) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSqlField_RequiredStatus_PythonToCpp_QSqlField_RequiredStatus_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX]))
        return QSqlField_RequiredStatus_PythonToCpp_QSqlField_RequiredStatus;
    return 0;
}
static PyObject* QSqlField_RequiredStatus_CppToPython_QSqlField_RequiredStatus(const void* cppIn) {
    int castCppIn = *((::QSqlField::RequiredStatus*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSqlField_PythonToCpp_QSqlField_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSqlField_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSqlField_PythonToCpp_QSqlField_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlField_Type))
        return QSqlField_PythonToCpp_QSqlField_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSqlField_PTR_CppToPython_QSqlField(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QSqlField*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QSqlField_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QSqlField_COPY_CppToPython_QSqlField(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QSqlField_Type, new ::QSqlField(*((::QSqlField*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QSqlField_PythonToCpp_QSqlField_COPY(PyObject* pyIn, void* cppOut) {
    *((::QSqlField*)cppOut) = *((::QSqlField*)Shiboken::Conversions::cppPointer(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QSqlField_PythonToCpp_QSqlField_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSqlField_Type))
        return QSqlField_PythonToCpp_QSqlField_COPY;
    return 0;
}

void init_QSqlField(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QSqlField_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QSqlField_TypeAsNumber) = Sbk_QSqlField___nb_bool;
    Sbk_QSqlField_Type.super.ht_type.tp_as_number = &Sbk_QSqlField_TypeAsNumber;

    SbkPySide_QtSqlTypes[SBK_QSQLFIELD_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSqlField_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSqlField", "QSqlField",
        &Sbk_QSqlField_Type, &Shiboken::callCppDestructor< ::QSqlField >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSqlField_Type,
        QSqlField_PythonToCpp_QSqlField_PTR,
        is_QSqlField_PythonToCpp_QSqlField_PTR_Convertible,
        QSqlField_PTR_CppToPython_QSqlField,
        QSqlField_COPY_CppToPython_QSqlField);

    Shiboken::Conversions::registerConverterName(converter, "QSqlField");
    Shiboken::Conversions::registerConverterName(converter, "QSqlField*");
    Shiboken::Conversions::registerConverterName(converter, "QSqlField&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSqlField).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QSqlField_PythonToCpp_QSqlField_COPY,
        is_QSqlField_PythonToCpp_QSqlField_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'RequiredStatus'.
    SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSqlField_Type,
        "RequiredStatus",
        "PySide.QtSql.QSqlField.RequiredStatus",
        "QSqlField::RequiredStatus");
    if (!SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX],
        &Sbk_QSqlField_Type, "Unknown", (long) QSqlField::Unknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX],
        &Sbk_QSqlField_Type, "Optional", (long) QSqlField::Optional))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX],
        &Sbk_QSqlField_Type, "Required", (long) QSqlField::Required))
        return ;
    // Register converter for enum 'QSqlField::RequiredStatus'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX],
            QSqlField_RequiredStatus_CppToPython_QSqlField_RequiredStatus);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSqlField_RequiredStatus_PythonToCpp_QSqlField_RequiredStatus,
            is_QSqlField_RequiredStatus_PythonToCpp_QSqlField_RequiredStatus_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtSqlTypes[SBK_QSQLFIELD_REQUIREDSTATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSqlField::RequiredStatus");
        Shiboken::Conversions::registerConverterName(converter, "RequiredStatus");
    }
    // End of 'RequiredStatus' enum.


    qRegisterMetaType< ::QSqlField::RequiredStatus >("QSqlField::RequiredStatus");
}
