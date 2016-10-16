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
#include "pyside_qtxml_python.h"

#include "qxmlattributes_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QXmlAttributesWrapper::QXmlAttributesWrapper() : QXmlAttributes() {
    // ... middle
}

QXmlAttributesWrapper::~QXmlAttributesWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlAttributes_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlAttributes >()))
        return -1;

    ::QXmlAttributesWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QXmlAttributes", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QXmlAttributes()
    // 1: QXmlAttributes(QXmlAttributes)
    if (numArgs == 0) {
        overloadId = 0; // QXmlAttributes()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (pyArgs[0])))) {
        overloadId = 1; // QXmlAttributes(QXmlAttributes)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributes_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QXmlAttributes()
        {

            if (!PyErr_Occurred()) {
                // QXmlAttributes()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlAttributesWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QXmlAttributes(const QXmlAttributes & QXmlAttributes)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QXmlAttributes cppArg0_local = ::QXmlAttributes();
            ::QXmlAttributes* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QXmlAttributes(QXmlAttributes)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QXmlAttributesWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlAttributes >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QXmlAttributes_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QXmlAttributes_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QXmlAttributes", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlAttributes", overloads);
        return -1;
}

static PyObject* Sbk_QXmlAttributesFunc_append(PyObject* self, PyObject* args)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "append", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: append(QString,QString,QString,QString)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
        overloadId = 0; // append(QString,QString,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_append_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = ::QString();
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // append(QString,QString,QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->append(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlAttributesFunc_append_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlAttributes.append", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_clear(PyObject* self)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QXmlAttributesFunc_count(PyObject* self)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->count();
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

static PyObject* Sbk_QXmlAttributesFunc_index(PyObject* self, PyObject* args)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "index", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: index(QString)const
    // 1: index(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // index(QString)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // index(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_index_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // index(const QString & qName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // index(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->index(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // index(const QString & uri, const QString & localPart) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // index(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->index(cppArg0, cppArg1);
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

    Sbk_QXmlAttributesFunc_index_TypeError:
        const char* overloads[] = {"unicode", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlAttributes.index", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_length(PyObject* self)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->length();
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

static PyObject* Sbk_QXmlAttributesFunc_localName(PyObject* self, PyObject* pyArg)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: localName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // localName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_localName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // localName(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->localName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlAttributesFunc_localName_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlAttributes.localName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_qName(PyObject* self, PyObject* pyArg)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: qName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // qName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_qName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // qName(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->qName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlAttributesFunc_qName_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlAttributes.qName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_type(PyObject* self, PyObject* args)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "type", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: type(QString)const
    // 1: type(QString,QString)const
    // 2: type(int)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // type(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // type(QString)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // type(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_type_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // type(const QString & qName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // type(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->type(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // type(const QString & uri, const QString & localName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // type(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->type(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // type(int index) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // type(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->type(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlAttributesFunc_type_TypeError:
        const char* overloads[] = {"unicode", "unicode, unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlAttributes.type", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_uri(PyObject* self, PyObject* pyArg)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: uri(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // uri(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_uri_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // uri(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->uri(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlAttributesFunc_uri_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlAttributes.uri", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributesFunc_value(PyObject* self, PyObject* args)
{
    ::QXmlAttributes* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self));
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
    // 0: value(QString)const
    // 1: value(QString,QString)const
    // 2: value(int)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // value(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // value(QString)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // value(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlAttributesFunc_value_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // value(const QString & qName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // value(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // value(const QString & uri, const QString & localName) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // value(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->value(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // value(int index) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // value(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QXmlAttributes*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlAttributesFunc_value_TypeError:
        const char* overloads[] = {"unicode", "unicode, unicode", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlAttributes.value", overloads);
        return 0;
}

static PyObject* Sbk_QXmlAttributes___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QXmlAttributes& cppSelf = *(((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QXmlAttributes_methods[] = {
    {"append", (PyCFunction)Sbk_QXmlAttributesFunc_append, METH_VARARGS},
    {"clear", (PyCFunction)Sbk_QXmlAttributesFunc_clear, METH_NOARGS},
    {"count", (PyCFunction)Sbk_QXmlAttributesFunc_count, METH_NOARGS},
    {"index", (PyCFunction)Sbk_QXmlAttributesFunc_index, METH_VARARGS},
    {"length", (PyCFunction)Sbk_QXmlAttributesFunc_length, METH_NOARGS},
    {"localName", (PyCFunction)Sbk_QXmlAttributesFunc_localName, METH_O},
    {"qName", (PyCFunction)Sbk_QXmlAttributesFunc_qName, METH_O},
    {"type", (PyCFunction)Sbk_QXmlAttributesFunc_type, METH_VARARGS},
    {"uri", (PyCFunction)Sbk_QXmlAttributesFunc_uri, METH_O},
    {"value", (PyCFunction)Sbk_QXmlAttributesFunc_value, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QXmlAttributes___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlAttributes_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlAttributes_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlAttributes_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlAttributes",
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
    /*tp_traverse*/         Sbk_QXmlAttributes_traverse,
    /*tp_clear*/            Sbk_QXmlAttributes_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlAttributes_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlAttributes_Init,
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
static void QXmlAttributes_PythonToCpp_QXmlAttributes_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlAttributes_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlAttributes_PythonToCpp_QXmlAttributes_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlAttributes_Type))
        return QXmlAttributes_PythonToCpp_QXmlAttributes_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlAttributes_PTR_CppToPython_QXmlAttributes(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlAttributes*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlAttributes_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QXmlAttributes_COPY_CppToPython_QXmlAttributes(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QXmlAttributes_Type, new ::QXmlAttributesWrapper(*((::QXmlAttributes*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QXmlAttributes_PythonToCpp_QXmlAttributes_COPY(PyObject* pyIn, void* cppOut) {
    *((::QXmlAttributes*)cppOut) = *((::QXmlAttributes*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QXmlAttributes_PythonToCpp_QXmlAttributes_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlAttributes_Type))
        return QXmlAttributes_PythonToCpp_QXmlAttributes_COPY;
    return 0;
}

void init_QXmlAttributes(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLATTRIBUTES_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlAttributes_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlAttributes", "QXmlAttributes",
        &Sbk_QXmlAttributes_Type, &Shiboken::callCppDestructor< ::QXmlAttributesWrapper >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlAttributes_Type,
        QXmlAttributes_PythonToCpp_QXmlAttributes_PTR,
        is_QXmlAttributes_PythonToCpp_QXmlAttributes_PTR_Convertible,
        QXmlAttributes_PTR_CppToPython_QXmlAttributes,
        QXmlAttributes_COPY_CppToPython_QXmlAttributes);

    Shiboken::Conversions::registerConverterName(converter, "QXmlAttributes");
    Shiboken::Conversions::registerConverterName(converter, "QXmlAttributes*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlAttributes&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlAttributes).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlAttributesWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QXmlAttributes_PythonToCpp_QXmlAttributes_COPY,
        is_QXmlAttributes_PythonToCpp_QXmlAttributes_COPY_Convertible);


    qRegisterMetaType< ::QXmlAttributes >("QXmlAttributes");
}
