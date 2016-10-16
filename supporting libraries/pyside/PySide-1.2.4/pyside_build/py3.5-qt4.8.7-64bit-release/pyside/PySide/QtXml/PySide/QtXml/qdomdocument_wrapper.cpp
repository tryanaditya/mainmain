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

#include "qdomdocument_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qdom.h>
#include <qiodevice.h>
#include <qtextstream.h>
#include <qxml.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomDocument_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomDocument >()))
        return -1;

    ::QDomDocument* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomDocument", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomDocument()
    // 1: QDomDocument(QDomDocument)
    // 2: QDomDocument(QDomDocumentType)
    // 3: QDomDocument(QString)
    if (numArgs == 0) {
        overloadId = 0; // QDomDocument()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 3; // QDomDocument(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QDomDocument(QDomDocumentType)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomDocument(QDomDocument)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocument_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomDocument()
        {

            if (!PyErr_Occurred()) {
                // QDomDocument()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocument();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomDocument(const QDomDocument & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomDocument cppArg0_local = ::QDomDocument();
            ::QDomDocument* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomDocument(QDomDocument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocument(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDomDocument(const QDomDocumentType & doctype)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomDocumentType cppArg0_local = ::QDomDocumentType();
            ::QDomDocumentType* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomDocument(QDomDocumentType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocument(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QDomDocument(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDomDocument(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomDocument(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomDocument >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomDocument_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomDocument_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomDocument", "PySide.QtXml.QDomDocumentType", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument", overloads);
        return -1;
}

static PyObject* Sbk_QDomDocumentFunc_createAttribute(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createAttribute(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createAttribute(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createAttribute(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->createAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createAttribute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createAttributeNS(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createAttributeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createAttributeNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createAttributeNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createAttributeNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->createAttributeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.createAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createCDATASection(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createCDATASection(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createCDATASection(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createCDATASection_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createCDATASection(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomCDATASection cppResult = cppSelf->createCDATASection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCDATASECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createCDATASection_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createCDATASection", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createComment(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createComment(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createComment(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createComment_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createComment(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomComment cppResult = cppSelf->createComment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCOMMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createComment_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createComment", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createDocumentFragment(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createDocumentFragment()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocumentFragment cppResult = cppSelf->createDocumentFragment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTFRAGMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomDocumentFunc_createElement(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createElement(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createElement(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createElement_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createElement(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = cppSelf->createElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createElement_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createElement", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createElementNS(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createElementNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createElementNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createElementNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createElementNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createElementNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = cppSelf->createElementNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createElementNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.createElementNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createEntityReference(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createEntityReference(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createEntityReference(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createEntityReference_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createEntityReference(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomEntityReference cppResult = cppSelf->createEntityReference(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createEntityReference_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createEntityReference", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createProcessingInstruction(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createProcessingInstruction", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createProcessingInstruction(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createProcessingInstruction(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createProcessingInstruction_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createProcessingInstruction(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomProcessingInstruction cppResult = cppSelf->createProcessingInstruction(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMPROCESSINGINSTRUCTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createProcessingInstruction_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.createProcessingInstruction", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_createTextNode(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createTextNode(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createTextNode(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_createTextNode_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createTextNode(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomText cppResult = cppSelf->createTextNode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_createTextNode_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.createTextNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_doctype(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doctype()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocumentType cppResult = const_cast<const ::QDomDocument*>(cppSelf)->doctype();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENTTYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomDocumentFunc_documentElement(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomDocument*>(cppSelf)->documentElement();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomDocumentFunc_elementById(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: elementById(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // elementById(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_elementById_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // elementById(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = cppSelf->elementById(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_elementById_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.elementById", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_elementsByTagName(PyObject* self, PyObject* pyArg)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: elementsByTagName(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // elementsByTagName(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_elementsByTagName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // elementsByTagName(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNodeList cppResult = const_cast<const ::QDomDocument*>(cppSelf)->elementsByTagName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_elementsByTagName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomDocument.elementsByTagName", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_elementsByTagNameNS(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "elementsByTagNameNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: elementsByTagNameNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // elementsByTagNameNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_elementsByTagNameNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // elementsByTagNameNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNodeList cppResult = cppSelf->elementsByTagNameNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_elementsByTagNameNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.elementsByTagNameNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_implementation(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // implementation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomImplementation cppResult = const_cast<const ::QDomDocument*>(cppSelf)->implementation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMIMPLEMENTATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomDocumentFunc_importNode(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "importNode", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: importNode(QDomNode,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // importNode(QDomNode,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_importNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDomNode cppArg0_local = ::QDomNode();
        ::QDomNode* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // importNode(QDomNode,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->importNode(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_importNode_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.importNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_nodeType(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomDocument*>(cppSelf)->nodeType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomDocumentFunc_setContent(PyObject* self, PyObject* args)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setContent", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setContent(QIODevice*,QString*,int*,int*)
    // 1: setContent(QIODevice*,bool,QString*,int*,int*)
    // 2: setContent(QXmlInputSource*,QXmlReader*,QString*,int*,int*)
    // 3: setContent(QXmlInputSource*,bool,QString*,int*,int*)
    // 4: setContent(QByteArray,QString*,int*,int*)
    // 5: setContent(QByteArray,bool,QString*,int*,int*)
    // 6: setContent(QString,QString*,int*,int*)
    // 7: setContent(QString,bool,QString*,int*,int*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 3; // setContent(QXmlInputSource*,bool,QString*,int*,int*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (pyArgs[1])))) {
            overloadId = 2; // setContent(QXmlInputSource*,QXmlReader*,QString*,int*,int*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setContent(QIODevice*,QString*,int*,int*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 1; // setContent(QIODevice*,bool,QString*,int*,int*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // setContent(QString,QString*,int*,int*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 7; // setContent(QString,bool,QString*,int*,int*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // setContent(QByteArray,QString*,int*,int*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 5; // setContent(QByteArray,bool,QString*,int*,int*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_setContent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setContent(QIODevice * dev, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setContent(QIODevice*,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 1: // setContent(QIODevice * dev, bool namespaceProcessing, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContent(QIODevice*,bool,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, cppArg1, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 2: // setContent(QXmlInputSource * source, QXmlReader * reader, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QXmlReader* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContent(QXmlInputSource*,QXmlReader*,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, cppArg1, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 3: // setContent(QXmlInputSource * source, bool namespaceProcessing, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContent(QXmlInputSource*,bool,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, cppArg1, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 4: // setContent(const QByteArray & text, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setContent(QByteArray,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(*cppArg0, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 5: // setContent(const QByteArray & text, bool namespaceProcessing, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContent(QByteArray,bool,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(*cppArg0, cppArg1, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 6: // setContent(const QString & text, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setContent(QString,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
        case 7: // setContent(const QString & text, bool namespaceProcessing, QString * errorMsg, int * errorLine, int * errorColumn)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setContent(QString,bool,QString*,int*,int*)
                // Begin code injection

                // TEMPLATE - qdomdocument_setcontent - START
                QString _errorMsg_;
                int _errorLine_ = 0;
                int _errorColumn_ = 0;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool _ret_ = cppSelf->setContent(cppArg0, cppArg1, &_errorMsg_, &_errorLine_, &_errorColumn_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(4);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &_ret_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &_errorMsg_));
                PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorLine_));
                PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_errorColumn_));
                // TEMPLATE - qdomdocument_setcontent - END

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_setContent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "PySide.QtCore.QIODevice, bool, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "PySide.QtXml.QXmlInputSource, PySide.QtXml.QXmlReader, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "PySide.QtXml.QXmlInputSource, bool, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "PySide.QtCore.QByteArray, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "PySide.QtCore.QByteArray, bool, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "unicode, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", "unicode, bool, PySide.QtCore.QString, PySide.QtCore.int, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.setContent", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_toByteArray(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomDocument.toByteArray(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toByteArray", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toByteArray(int)const
    if (numArgs == 0) {
        overloadId = 0; // toByteArray(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toByteArray(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_toByteArray_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__1");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomDocument.toByteArray(): got multiple values for keyword argument 'arg__1'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QDomDocumentFunc_toByteArray_TypeError;
            }
        }
        int cppArg0 = 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toByteArray(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QDomDocument*>(cppSelf)->toByteArray(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_toByteArray_TypeError:
        const char* overloads[] = {"int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.toByteArray", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocumentFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomDocument.toString(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toString", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toString(int)const
    if (numArgs == 0) {
        overloadId = 0; // toString(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toString(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomDocumentFunc_toString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__1");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomDocument.toString(): got multiple values for keyword argument 'arg__1'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QDomDocumentFunc_toString_TypeError;
            }
        }
        int cppArg0 = 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toString(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomDocument*>(cppSelf)->toString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomDocumentFunc_toString_TypeError:
        const char* overloads[] = {"int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomDocument.toString", overloads);
        return 0;
}

static PyObject* Sbk_QDomDocument___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomDocument& cppSelf = *(((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomDocument_methods[] = {
    {"createAttribute", (PyCFunction)Sbk_QDomDocumentFunc_createAttribute, METH_O},
    {"createAttributeNS", (PyCFunction)Sbk_QDomDocumentFunc_createAttributeNS, METH_VARARGS},
    {"createCDATASection", (PyCFunction)Sbk_QDomDocumentFunc_createCDATASection, METH_O},
    {"createComment", (PyCFunction)Sbk_QDomDocumentFunc_createComment, METH_O},
    {"createDocumentFragment", (PyCFunction)Sbk_QDomDocumentFunc_createDocumentFragment, METH_NOARGS},
    {"createElement", (PyCFunction)Sbk_QDomDocumentFunc_createElement, METH_O},
    {"createElementNS", (PyCFunction)Sbk_QDomDocumentFunc_createElementNS, METH_VARARGS},
    {"createEntityReference", (PyCFunction)Sbk_QDomDocumentFunc_createEntityReference, METH_O},
    {"createProcessingInstruction", (PyCFunction)Sbk_QDomDocumentFunc_createProcessingInstruction, METH_VARARGS},
    {"createTextNode", (PyCFunction)Sbk_QDomDocumentFunc_createTextNode, METH_O},
    {"doctype", (PyCFunction)Sbk_QDomDocumentFunc_doctype, METH_NOARGS},
    {"documentElement", (PyCFunction)Sbk_QDomDocumentFunc_documentElement, METH_NOARGS},
    {"elementById", (PyCFunction)Sbk_QDomDocumentFunc_elementById, METH_O},
    {"elementsByTagName", (PyCFunction)Sbk_QDomDocumentFunc_elementsByTagName, METH_O},
    {"elementsByTagNameNS", (PyCFunction)Sbk_QDomDocumentFunc_elementsByTagNameNS, METH_VARARGS},
    {"implementation", (PyCFunction)Sbk_QDomDocumentFunc_implementation, METH_NOARGS},
    {"importNode", (PyCFunction)Sbk_QDomDocumentFunc_importNode, METH_VARARGS},
    {"nodeType", (PyCFunction)Sbk_QDomDocumentFunc_nodeType, METH_NOARGS},
    {"setContent", (PyCFunction)Sbk_QDomDocumentFunc_setContent, METH_VARARGS},
    {"toByteArray", (PyCFunction)Sbk_QDomDocumentFunc_toByteArray, METH_VARARGS|METH_KEYWORDS},
    {"toString", (PyCFunction)Sbk_QDomDocumentFunc_toString, METH_VARARGS|METH_KEYWORDS},

    {"__copy__", (PyCFunction)Sbk_QDomDocument___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomDocument___nb_bool(PyObject* self)
{
    ::QDomDocument* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomDocument_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomDocument_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomDocument_TypeAsNumber;

static SbkObjectType Sbk_QDomDocument_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomDocument",
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
    /*tp_traverse*/         Sbk_QDomDocument_traverse,
    /*tp_clear*/            Sbk_QDomDocument_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomDocument_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomDocument_Init,
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
static void QDomDocument_PythonToCpp_QDomDocument_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomDocument_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomDocument_PythonToCpp_QDomDocument_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomDocument_Type))
        return QDomDocument_PythonToCpp_QDomDocument_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomDocument_PTR_CppToPython_QDomDocument(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomDocument*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomDocument_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomDocument_COPY_CppToPython_QDomDocument(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomDocument_Type, new ::QDomDocument(*((::QDomDocument*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomDocument_PythonToCpp_QDomDocument_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomDocument*)cppOut) = *((::QDomDocument*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomDocument_PythonToCpp_QDomDocument_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomDocument_Type))
        return QDomDocument_PythonToCpp_QDomDocument_COPY;
    return 0;
}

void init_QDomDocument(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomDocument_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomDocument_TypeAsNumber) = Sbk_QDomDocument___nb_bool;
    Sbk_QDomDocument_Type.super.ht_type.tp_as_number = &Sbk_QDomDocument_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomDocument_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomDocument", "QDomDocument",
        &Sbk_QDomDocument_Type, &Shiboken::callCppDestructor< ::QDomDocument >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomDocument_Type,
        QDomDocument_PythonToCpp_QDomDocument_PTR,
        is_QDomDocument_PythonToCpp_QDomDocument_PTR_Convertible,
        QDomDocument_PTR_CppToPython_QDomDocument,
        QDomDocument_COPY_CppToPython_QDomDocument);

    Shiboken::Conversions::registerConverterName(converter, "QDomDocument");
    Shiboken::Conversions::registerConverterName(converter, "QDomDocument*");
    Shiboken::Conversions::registerConverterName(converter, "QDomDocument&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomDocument).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomDocument_PythonToCpp_QDomDocument_COPY,
        is_QDomDocument_PythonToCpp_QDomDocument_COPY_Convertible);


    qRegisterMetaType< ::QDomDocument >("QDomDocument");
}
