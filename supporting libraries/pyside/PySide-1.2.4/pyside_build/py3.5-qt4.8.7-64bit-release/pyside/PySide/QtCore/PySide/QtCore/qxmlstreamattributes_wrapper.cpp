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

#include "qxmlstreamattributes_wrapper.h"

// Extra includes
#include <QVector>
#include <qxmlstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlStreamAttributes_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlStreamAttributes >()))
        return -1;

    ::QXmlStreamAttributes* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlStreamAttributes", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlStreamAttributes()
    // 1: QXmlStreamAttributes(QXmlStreamAttributes)
    if (numArgs == 0) {
        overloadId = 0; // QXmlStreamAttributes()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlStreamAttributes(QXmlStreamAttributes)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributes_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlStreamAttributes()
        {

            if (!PyErr_Occurred()) {
                // QXmlStreamAttributes()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamAttributes();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlStreamAttributes(const QXmlStreamAttributes & QXmlStreamAttributes)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlStreamAttributes cppArg0_local = ::QXmlStreamAttributes();
            ::QXmlStreamAttributes* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlStreamAttributes(QXmlStreamAttributes)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlStreamAttributes(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlStreamAttributes >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlStreamAttributes_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlStreamAttributes_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QXmlStreamAttributes", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes", overloads);
        return -1;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_append(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "append", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: append(QString,QString,QString)
    // 1: append(QString,QString)
    // 2: append(QXmlStreamAttribute)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))) {
        overloadId = 2; // append(QXmlStreamAttribute)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // append(QString,QString)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // append(QString,QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_append_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // append(const QString & namespaceUri, const QString & name, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // append(QString,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // append(const QString & qualifiedName, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // append(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // append(const QXmlStreamAttribute & attribute)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // append(QXmlStreamAttribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_append_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode", "unicode, unicode", "PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.append", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: at(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // at(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QXmlStreamAttribute & cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.at", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_capacity(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->capacity();
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

static PyObject* Sbk_QXmlStreamAttributesFunc_clear(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QXmlStreamAttributesFunc_constData(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // constData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QXmlStreamAttribute * cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->constData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QXmlStreamAttribute)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // contains(QXmlStreamAttribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_contains_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // contains(QXmlStreamAttribute)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->contains(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.contains", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_count(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "count", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: count()const
    // 1: count(QXmlStreamAttribute)const
    if (numArgs == 0) {
        overloadId = 0; // count()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))) {
        overloadId = 1; // count(QXmlStreamAttribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_count_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // count() const
        {

            if (!PyErr_Occurred()) {
                // count()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->count();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // count(const QXmlStreamAttribute & t) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // count(QXmlStreamAttribute)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->count(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_count_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.count", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_data(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttribute * cppResult = cppSelf->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_empty(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // empty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->empty();
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

static PyObject* Sbk_QXmlStreamAttributesFunc_endsWith(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endsWith(QXmlStreamAttribute)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // endsWith(QXmlStreamAttribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_endsWith_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // endsWith(QXmlStreamAttribute)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->endsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_endsWith_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.endsWith", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_erase(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "erase", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: erase(QXmlStreamAttribute*,QXmlStreamAttribute*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[1])))) {
        overloadId = 0; // erase(QXmlStreamAttribute*,QXmlStreamAttribute*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_erase_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlStreamAttribute* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlStreamAttribute* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // erase(QXmlStreamAttribute*,QXmlStreamAttribute*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttribute * cppResult = cppSelf->erase(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_erase_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute, PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.erase", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_fill(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.fill(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.fill(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fill", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fill(QXmlStreamAttribute,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fill(QXmlStreamAttribute,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // fill(QXmlStreamAttribute,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_fill_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "size");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.fill(): got multiple values for keyword argument 'size'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QXmlStreamAttributesFunc_fill_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fill(QXmlStreamAttribute,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamAttribute > & cppResult = cppSelf->fill(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_fill_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.fill", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_first(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // first()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttribute & cppResult = cppSelf->first();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_front(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // front()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttribute & cppResult = cppSelf->front();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_hasAttribute(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hasAttribute", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hasAttribute(QString,QString)const
    // 1: hasAttribute(QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // hasAttribute(QString)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // hasAttribute(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_hasAttribute_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // hasAttribute(const QString & namespaceUri, const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // hasAttribute(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->hasAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // hasAttribute(const QString & qualifiedName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // hasAttribute(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->hasAttribute(cppArg0);
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

    Sbk_QXmlStreamAttributesFunc_hasAttribute_TypeError:
        const char* overloads[] = {"unicode, unicode", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.hasAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_indexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.indexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.indexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:indexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: indexOf(QXmlStreamAttribute,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexOf(QXmlStreamAttribute,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // indexOf(QXmlStreamAttribute,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_indexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.indexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QXmlStreamAttributesFunc_indexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // indexOf(QXmlStreamAttribute,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->indexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_indexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.indexOf", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_insert(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insert(QXmlStreamAttribute*,int,QXmlStreamAttribute)
    // 1: insert(int,QXmlStreamAttribute)
    // 2: insert(int,int,QXmlStreamAttribute)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[2])))) {
            overloadId = 2; // insert(int,int,QXmlStreamAttribute)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[1])))) {
            overloadId = 1; // insert(int,QXmlStreamAttribute)
        }
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[2])))) {
        overloadId = 0; // insert(QXmlStreamAttribute*,int,QXmlStreamAttribute)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_insert_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insert(QXmlStreamAttribute * before, int n, const QXmlStreamAttribute & t)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlStreamAttribute* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QXmlStreamAttribute cppArg2_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // insert(QXmlStreamAttribute*,int,QXmlStreamAttribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QXmlStreamAttribute * cppResult = cppSelf->insert(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // insert(int i, const QXmlStreamAttribute & t)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlStreamAttribute cppArg1_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // insert(int,QXmlStreamAttribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 2: // insert(int i, int n, const QXmlStreamAttribute & t)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QXmlStreamAttribute cppArg2_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // insert(int,int,QXmlStreamAttribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insert(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_insert_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute, int, PySide.QtCore.QXmlStreamAttribute", "int, PySide.QtCore.QXmlStreamAttribute", "int, int, PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.insert", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_isEmpty(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QXmlStreamAttributesFunc_isSharedWith(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSharedWith(QVector<QXmlStreamAttribute>)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // isSharedWith(QVector<QXmlStreamAttribute>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_isSharedWith_TypeError;

    // Call function/method
    {
        ::QVector<QXmlStreamAttribute > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isSharedWith(QVector<QXmlStreamAttribute>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->isSharedWith(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_isSharedWith_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.isSharedWith", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_last(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // last()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlStreamAttribute & cppResult = cppSelf->last();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_lastIndexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.lastIndexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.lastIndexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:lastIndexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lastIndexOf(QXmlStreamAttribute,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // lastIndexOf(QXmlStreamAttribute,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // lastIndexOf(QXmlStreamAttribute,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_lastIndexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.lastIndexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QXmlStreamAttributesFunc_lastIndexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // lastIndexOf(QXmlStreamAttribute,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->lastIndexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_lastIndexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.lastIndexOf", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_mid(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.mid(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.mid(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:mid", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mid(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // mid(int,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // mid(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_mid_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "length");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QXmlStreamAttributes.mid(): got multiple values for keyword argument 'length'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QXmlStreamAttributesFunc_mid_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mid(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamAttribute > cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->mid(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_mid_TypeError:
        const char* overloads[] = {"int, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.mid", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_prepend(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prepend(QXmlStreamAttribute)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // prepend(QXmlStreamAttribute)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_prepend_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // prepend(QXmlStreamAttribute)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->prepend(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_prepend_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.prepend", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_remove(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "remove", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: remove(int)
    // 1: remove(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // remove(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // remove(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_remove_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // remove(int i)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // remove(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->remove(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // remove(int i, int n)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // remove(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->remove(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_remove_TypeError:
        const char* overloads[] = {"int", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.remove", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_replace(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(int,QXmlStreamAttribute)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(int,QXmlStreamAttribute)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_replace_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlStreamAttribute cppArg1_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // replace(int,QXmlStreamAttribute)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->replace(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_replace_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.replace", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_reserve(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reserve(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // reserve(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_reserve_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reserve(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reserve(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_reserve_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.reserve", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_resize(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // resize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_resize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_resize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.resize", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_setSharable(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSharable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSharable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_setSharable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSharable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSharable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_setSharable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.setSharable", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_size(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->size();
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

static PyObject* Sbk_QXmlStreamAttributesFunc_squeeze(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // squeeze()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->squeeze();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_startsWith(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startsWith(QXmlStreamAttribute)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // startsWith(QXmlStreamAttribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_startsWith_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // startsWith(QXmlStreamAttribute)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->startsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_startsWith_TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.startsWith", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QVector<QXmlStreamAttribute>&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // swap(QVector<QXmlStreamAttribute>&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_swap_TypeError;

    // Call function/method
    {
        ::QVector<QXmlStreamAttribute > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // swap(QVector<QXmlStreamAttribute>&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlStreamAttributesFunc_swap_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.swap", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc_value(PyObject* self, PyObject* args)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "value", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: value(QString,QString)const
    // 1: value(QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // value(QString)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // value(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc_value_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // value(const QString & namespaceUri, const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // value(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringRef cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->value(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
            }
            break;
        }
        case 1: // value(const QString & qualifiedName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // value(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringRef cppResult = const_cast<const ::QXmlStreamAttributes*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc_value_TypeError:
        const char* overloads[] = {"unicode, unicode", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QXmlStreamAttributes.value", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributes___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamAttributes& cppSelf = *(((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlStreamAttributes_methods[] = {
    {"append", (PyCFunction)Sbk_QXmlStreamAttributesFunc_append, METH_VARARGS},
    {"at", (PyCFunction)Sbk_QXmlStreamAttributesFunc_at, METH_O},
    {"capacity", (PyCFunction)Sbk_QXmlStreamAttributesFunc_capacity, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QXmlStreamAttributesFunc_clear, METH_NOARGS},
    {"constData", (PyCFunction)Sbk_QXmlStreamAttributesFunc_constData, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QXmlStreamAttributesFunc_contains, METH_O},
    {"count", (PyCFunction)Sbk_QXmlStreamAttributesFunc_count, METH_VARARGS},
    {"data", (PyCFunction)Sbk_QXmlStreamAttributesFunc_data, METH_NOARGS},
    {"empty", (PyCFunction)Sbk_QXmlStreamAttributesFunc_empty, METH_NOARGS},
    {"endsWith", (PyCFunction)Sbk_QXmlStreamAttributesFunc_endsWith, METH_O},
    {"erase", (PyCFunction)Sbk_QXmlStreamAttributesFunc_erase, METH_VARARGS},
    {"fill", (PyCFunction)Sbk_QXmlStreamAttributesFunc_fill, METH_VARARGS|METH_KEYWORDS},
    {"first", (PyCFunction)Sbk_QXmlStreamAttributesFunc_first, METH_NOARGS},
    {"front", (PyCFunction)Sbk_QXmlStreamAttributesFunc_front, METH_NOARGS},
    {"hasAttribute", (PyCFunction)Sbk_QXmlStreamAttributesFunc_hasAttribute, METH_VARARGS},
    {"indexOf", (PyCFunction)Sbk_QXmlStreamAttributesFunc_indexOf, METH_VARARGS|METH_KEYWORDS},
    {"insert", (PyCFunction)Sbk_QXmlStreamAttributesFunc_insert, METH_VARARGS},
    {"isEmpty", (PyCFunction)Sbk_QXmlStreamAttributesFunc_isEmpty, METH_NOARGS},
    {"isSharedWith", (PyCFunction)Sbk_QXmlStreamAttributesFunc_isSharedWith, METH_O},
    {"last", (PyCFunction)Sbk_QXmlStreamAttributesFunc_last, METH_NOARGS},
    {"lastIndexOf", (PyCFunction)Sbk_QXmlStreamAttributesFunc_lastIndexOf, METH_VARARGS|METH_KEYWORDS},
    {"mid", (PyCFunction)Sbk_QXmlStreamAttributesFunc_mid, METH_VARARGS|METH_KEYWORDS},
    {"prepend", (PyCFunction)Sbk_QXmlStreamAttributesFunc_prepend, METH_O},
    {"remove", (PyCFunction)Sbk_QXmlStreamAttributesFunc_remove, METH_VARARGS},
    {"replace", (PyCFunction)Sbk_QXmlStreamAttributesFunc_replace, METH_VARARGS},
    {"reserve", (PyCFunction)Sbk_QXmlStreamAttributesFunc_reserve, METH_O},
    {"resize", (PyCFunction)Sbk_QXmlStreamAttributesFunc_resize, METH_O},
    {"setSharable", (PyCFunction)Sbk_QXmlStreamAttributesFunc_setSharable, METH_O},
    {"size", (PyCFunction)Sbk_QXmlStreamAttributesFunc_size, METH_NOARGS},
    {"squeeze", (PyCFunction)Sbk_QXmlStreamAttributesFunc_squeeze, METH_NOARGS},
    {"startsWith", (PyCFunction)Sbk_QXmlStreamAttributesFunc_startsWith, METH_O},
    {"swap", (PyCFunction)Sbk_QXmlStreamAttributesFunc_swap, METH_O},
    {"value", (PyCFunction)Sbk_QXmlStreamAttributesFunc_value, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlStreamAttributes___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QXmlStreamAttributesFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__radd__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__radd__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator+(QVector<QXmlStreamAttribute>)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QVector<QXmlStreamAttribute>)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc___add___TypeError;

    // Call function/method
    {
        ::QVector<QXmlStreamAttribute > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator+(QVector<QXmlStreamAttribute>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlStreamAttribute > cppResult = (*cppSelf) + cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc___add___TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QXmlStreamAttribute)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QXmlStreamAttribute)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc___iadd___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
        ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+=(QXmlStreamAttribute)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) += (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QXmlStreamAttributesFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QXmlStreamAttributesFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QVector<QXmlStreamAttribute>)
    // 1: operator<<(QXmlStreamAttribute)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 1; // operator<<(QXmlStreamAttribute)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QVector<QXmlStreamAttribute>)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlStreamAttributesFunc___lshift___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator<<(const QVector<QXmlStreamAttribute > & l)
        {
            ::QVector<QXmlStreamAttribute > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(QVector<QXmlStreamAttribute>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector<QXmlStreamAttribute > & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator<<(const QXmlStreamAttribute & t)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlStreamAttribute cppArg0_local = ::QXmlStreamAttribute();
            ::QXmlStreamAttribute* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // operator<<(QXmlStreamAttribute)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector<QXmlStreamAttribute > & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], &cppResult);
            }
            break;
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlStreamAttributesFunc___lshift___TypeError:
        const char* overloads[] = {"list", "PySide.QtCore.QXmlStreamAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QXmlStreamAttributes.__lshift__", overloads);
        return 0;
}

Py_ssize_t Sbk_QXmlStreamAttributes__len__(PyObject* self)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    return cppSelf->size();
}
PyObject* Sbk_QXmlStreamAttributes__getitem__(PyObject* self, Py_ssize_t _i)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    QXmlStreamAttributes::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], &*_item);
}
int Sbk_QXmlStreamAttributes__setitem__(PyObject* self, Py_ssize_t _i, PyObject* pyArg)
{
    ::QXmlStreamAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "list assignment index out of range");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
        PyErr_SetString(PyExc_TypeError, "attributed value with wrong type, 'QXmlStreamAttribute' or other convertible type expected");
        return -1;
    }
    if (!Shiboken::Object::isValid(pyArg))
        return -1;
    ::QXmlStreamAttribute cppValue = ::QXmlStreamAttribute();
    pythonToCpp(pyArg, &cppValue);
    QXmlStreamAttributes::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    *_item = cppValue;
    return 0;
}
// Rich comparison
static PyObject* Sbk_QXmlStreamAttributes_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlStreamAttributes& cppSelf = *(((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
                // operator!=(const QVector<QXmlStreamAttribute > & v) const
                ::QVector<QXmlStreamAttribute > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf != (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QVECTOR_QXMLSTREAMATTRIBUTE_IDX], (pyArg)))) {
                // operator==(const QVector<QXmlStreamAttribute > & v) const
                ::QVector<QXmlStreamAttribute > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QXmlStreamAttributes_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QXmlStreamAttributes_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QXmlStreamAttributes_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlStreamAttributes_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QXmlStreamAttributes_TypeAsNumber;

static PySequenceMethods Sbk_QXmlStreamAttributes_TypeAsSequence;

static SbkObjectType Sbk_QXmlStreamAttributes_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QXmlStreamAttributes",
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
    /*tp_traverse*/         Sbk_QXmlStreamAttributes_traverse,
    /*tp_clear*/            Sbk_QXmlStreamAttributes_clear,
    /*tp_richcompare*/      Sbk_QXmlStreamAttributes_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlStreamAttributes_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlStreamAttributes_Init,
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
static void QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlStreamAttributes_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamAttributes_Type))
        return QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlStreamAttributes_PTR_CppToPython_QXmlStreamAttributes(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlStreamAttributes*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlStreamAttributes_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlStreamAttributes_COPY_CppToPython_QXmlStreamAttributes(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlStreamAttributes_Type, new ::QXmlStreamAttributes(*((::QXmlStreamAttributes*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlStreamAttributes*)cppOut) = *((::QXmlStreamAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlStreamAttributes_Type))
        return QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_COPY;
    return 0;
}

void init_QXmlStreamAttributes(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QXmlStreamAttributes_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QXmlStreamAttributes_TypeAsNumber.nb_lshift = Sbk_QXmlStreamAttributesFunc___lshift__;
    Sbk_QXmlStreamAttributes_TypeAsNumber.nb_inplace_add = Sbk_QXmlStreamAttributesFunc___iadd__;
    Sbk_QXmlStreamAttributes_TypeAsNumber.nb_add = Sbk_QXmlStreamAttributesFunc___add__;
    Sbk_QXmlStreamAttributes_Type.super.ht_type.tp_as_number = &Sbk_QXmlStreamAttributes_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QXmlStreamAttributes_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QXmlStreamAttributes_TypeAsSequence.sq_length = Sbk_QXmlStreamAttributes__len__;
    Sbk_QXmlStreamAttributes_TypeAsSequence.sq_item = Sbk_QXmlStreamAttributes__getitem__;
    Sbk_QXmlStreamAttributes_TypeAsSequence.sq_ass_item = Sbk_QXmlStreamAttributes__setitem__;
    Sbk_QXmlStreamAttributes_Type.super.ht_type.tp_as_sequence = &Sbk_QXmlStreamAttributes_TypeAsSequence;

    SbkPySide_QtCoreTypes[SBK_QXMLSTREAMATTRIBUTES_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlStreamAttributes_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlStreamAttributes", "QXmlStreamAttributes",
        &Sbk_QXmlStreamAttributes_Type, &Shiboken::callCppDestructor< ::QXmlStreamAttributes >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlStreamAttributes_Type,
        QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_PTR,
        is_QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_PTR_Convertible,
        QXmlStreamAttributes_PTR_CppToPython_QXmlStreamAttributes,
        QXmlStreamAttributes_COPY_CppToPython_QXmlStreamAttributes);

    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamAttributes");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamAttributes*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlStreamAttributes&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlStreamAttributes).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_COPY,
        is_QXmlStreamAttributes_PythonToCpp_QXmlStreamAttributes_COPY_Convertible);


    qRegisterMetaType< ::QXmlStreamAttributes >("QXmlStreamAttributes");
}
