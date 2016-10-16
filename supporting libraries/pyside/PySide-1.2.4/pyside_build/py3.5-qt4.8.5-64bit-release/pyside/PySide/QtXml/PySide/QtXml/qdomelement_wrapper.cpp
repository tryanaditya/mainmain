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

#include "qdomelement_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomElement_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomElement >()))
        return -1;

    ::QDomElement* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomElement", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomElement()
    // 1: QDomElement(QDomElement)
    if (numArgs == 0) {
        overloadId = 0; // QDomElement()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomElement(QDomElement)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElement_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomElement()
        {

            if (!PyErr_Occurred()) {
                // QDomElement()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomElement();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomElement(const QDomElement & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomElement cppArg0_local = ::QDomElement();
            ::QDomElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomElement(QDomElement)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomElement(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomElement >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomElement_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomElement_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomElement", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement", overloads);
        return -1;
}

static PyObject* Sbk_QDomElementFunc_attribute(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attribute(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attribute(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:attribute", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: attribute(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // attribute(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // attribute(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_attribute_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attribute(): got multiple values for keyword argument 'defValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QDomElementFunc_attribute_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // attribute(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomElement*>(cppSelf)->attribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_attribute_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.attribute", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_attributeNS(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attributeNS(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attributeNS(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:attributeNS", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: attributeNS(QString,QString,QString)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // attributeNS(QString,QString,QString)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // attributeNS(QString,QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_attributeNS_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defValue");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomElement.attributeNS(): got multiple values for keyword argument 'defValue'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QDomElementFunc_attributeNS_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // attributeNS(QString,QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomElement*>(cppSelf)->attributeNS(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_attributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.attributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_attributeNode(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: attributeNode(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // attributeNode(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_attributeNode_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // attributeNode(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->attributeNode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_attributeNode_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.attributeNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_attributeNodeNS(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "attributeNodeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: attributeNodeNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // attributeNodeNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_attributeNodeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // attributeNodeNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->attributeNodeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_attributeNodeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.attributeNodeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_attributes(PyObject* self)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNamedNodeMap cppResult = const_cast<const ::QDomElement*>(cppSelf)->attributes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomElementFunc_elementsByTagName(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDomElementFunc_elementsByTagName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // elementsByTagName(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNodeList cppResult = const_cast<const ::QDomElement*>(cppSelf)->elementsByTagName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_elementsByTagName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.elementsByTagName", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_elementsByTagNameNS(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
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
    // 0: elementsByTagNameNS(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // elementsByTagNameNS(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_elementsByTagNameNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // elementsByTagNameNS(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNodeList cppResult = const_cast<const ::QDomElement*>(cppSelf)->elementsByTagNameNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_elementsByTagNameNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.elementsByTagNameNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_hasAttribute(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasAttribute(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasAttribute(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_hasAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasAttribute(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomElement*>(cppSelf)->hasAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_hasAttribute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.hasAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_hasAttributeNS(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "hasAttributeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: hasAttributeNS(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // hasAttributeNS(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_hasAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // hasAttributeNS(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomElement*>(cppSelf)->hasAttributeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_hasAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.hasAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_nodeType(PyObject* self)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomElement*>(cppSelf)->nodeType();
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

static PyObject* Sbk_QDomElementFunc_removeAttribute(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAttribute(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeAttribute(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_removeAttribute_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAttribute(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomElementFunc_removeAttribute_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.removeAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_removeAttributeNS(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removeAttributeNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeAttributeNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // removeAttributeNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_removeAttributeNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeAttributeNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAttributeNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomElementFunc_removeAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.removeAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_removeAttributeNode(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAttributeNode(QDomAttr)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (pyArg)))) {
        overloadId = 0; // removeAttributeNode(QDomAttr)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_removeAttributeNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDomAttr cppArg0_local = ::QDomAttr();
        ::QDomAttr* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // removeAttributeNode(QDomAttr)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->removeAttributeNode(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_removeAttributeNode_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomAttr", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.removeAttributeNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_setAttribute(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(QString,QString)
    // 1: setAttribute(QString,double)
    // 2: setAttribute(QString,float)
    // 3: setAttribute(QString,int)
    // 4: setAttribute(QString,qlonglong)
    // 5: setAttribute(QString,qulonglong)
    // 6: setAttribute(QString,uint)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[1])))) {
            overloadId = 6; // setAttribute(QString,uint)
        } else if (numArgs == 2
            && PyLong_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qulonglong>(), (pyArgs[1])))) {
            overloadId = 5; // setAttribute(QString,qulonglong)
        } else if (numArgs == 2
            && PyLong_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[1])))) {
            overloadId = 4; // setAttribute(QString,qlonglong)
        } else if (numArgs == 2
            && PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[1])))) {
            overloadId = 2; // setAttribute(QString,float)
        } else if (numArgs == 2
            && PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // setAttribute(QString,double)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 3; // setAttribute(QString,int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setAttribute(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_setAttribute_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttribute(const QString & name, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setAttribute(const QString & name, double value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setAttribute(const QString & name, float value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            float cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,float)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // setAttribute(const QString & name, int value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // setAttribute(const QString & name, qlonglong value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qlonglong cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,qlonglong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // setAttribute(const QString & name, qulonglong value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qulonglong cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,qulonglong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // setAttribute(const QString & name, uint value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            uint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setAttribute(QString,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttribute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomElementFunc_setAttribute_TypeError:
        const char* overloads[] = {"unicode, unicode", "unicode, float", "unicode, float", "unicode, int", "unicode, long long", "unicode, unsigned long long", "unicode, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_setAttributeNS(PyObject* self, PyObject* args)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttributeNS", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setAttributeNS(QString,QString,QString)
    // 1: setAttributeNS(QString,QString,double)
    // 2: setAttributeNS(QString,QString,int)
    // 3: setAttributeNS(QString,QString,qlonglong)
    // 4: setAttributeNS(QString,QString,qulonglong)
    // 5: setAttributeNS(QString,QString,uint)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[2])))) {
            overloadId = 5; // setAttributeNS(QString,QString,uint)
        } else if (numArgs == 3
            && PyLong_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qulonglong>(), (pyArgs[2])))) {
            overloadId = 4; // setAttributeNS(QString,QString,qulonglong)
        } else if (numArgs == 3
            && PyLong_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[2])))) {
            overloadId = 3; // setAttributeNS(QString,QString,qlonglong)
        } else if (numArgs == 3
            && PyFloat_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
            overloadId = 1; // setAttributeNS(QString,QString,double)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 2; // setAttributeNS(QString,QString,int)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // setAttributeNS(QString,QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_setAttributeNS_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setAttributeNS(const QString nsURI, const QString & qName, const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setAttributeNS(const QString nsURI, const QString & qName, double value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setAttributeNS(const QString nsURI, const QString & qName, int value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // setAttributeNS(const QString nsURI, const QString & qName, qlonglong value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qlonglong cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,qlonglong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // setAttributeNS(const QString nsURI, const QString & qName, qulonglong value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qulonglong cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,qulonglong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // setAttributeNS(const QString nsURI, const QString & qName, uint value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            uint cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setAttributeNS(QString,QString,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setAttributeNS(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomElementFunc_setAttributeNS_TypeError:
        const char* overloads[] = {"unicode, unicode, unicode", "unicode, unicode, float", "unicode, unicode, int", "unicode, unicode, long long", "unicode, unicode, unsigned long long", "unicode, unicode, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomElement.setAttributeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_setAttributeNode(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAttributeNode(QDomAttr)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (pyArg)))) {
        overloadId = 0; // setAttributeNode(QDomAttr)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_setAttributeNode_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDomAttr cppArg0_local = ::QDomAttr();
        ::QDomAttr* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setAttributeNode(QDomAttr)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->setAttributeNode(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_setAttributeNode_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomAttr", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.setAttributeNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_setAttributeNodeNS(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAttributeNodeNS(QDomAttr)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], (pyArg)))) {
        overloadId = 0; // setAttributeNodeNS(QDomAttr)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_setAttributeNodeNS_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDomAttr cppArg0_local = ::QDomAttr();
        ::QDomAttr* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setAttributeNodeNS(QDomAttr)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = cppSelf->setAttributeNodeNS(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomElementFunc_setAttributeNodeNS_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomAttr", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.setAttributeNodeNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_setTagName(PyObject* self, PyObject* pyArg)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTagName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setTagName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomElementFunc_setTagName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTagName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTagName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomElementFunc_setTagName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomElement.setTagName", overloads);
        return 0;
}

static PyObject* Sbk_QDomElementFunc_tagName(PyObject* self)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tagName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomElement*>(cppSelf)->tagName();
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

static PyObject* Sbk_QDomElementFunc_text(PyObject* self)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomElement*>(cppSelf)->text();
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

static PyObject* Sbk_QDomElement___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomElement& cppSelf = *(((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomElement_methods[] = {
    {"attribute", (PyCFunction)Sbk_QDomElementFunc_attribute, METH_VARARGS|METH_KEYWORDS},
    {"attributeNS", (PyCFunction)Sbk_QDomElementFunc_attributeNS, METH_VARARGS|METH_KEYWORDS},
    {"attributeNode", (PyCFunction)Sbk_QDomElementFunc_attributeNode, METH_O},
    {"attributeNodeNS", (PyCFunction)Sbk_QDomElementFunc_attributeNodeNS, METH_VARARGS},
    {"attributes", (PyCFunction)Sbk_QDomElementFunc_attributes, METH_NOARGS},
    {"elementsByTagName", (PyCFunction)Sbk_QDomElementFunc_elementsByTagName, METH_O},
    {"elementsByTagNameNS", (PyCFunction)Sbk_QDomElementFunc_elementsByTagNameNS, METH_VARARGS},
    {"hasAttribute", (PyCFunction)Sbk_QDomElementFunc_hasAttribute, METH_O},
    {"hasAttributeNS", (PyCFunction)Sbk_QDomElementFunc_hasAttributeNS, METH_VARARGS},
    {"nodeType", (PyCFunction)Sbk_QDomElementFunc_nodeType, METH_NOARGS},
    {"removeAttribute", (PyCFunction)Sbk_QDomElementFunc_removeAttribute, METH_O},
    {"removeAttributeNS", (PyCFunction)Sbk_QDomElementFunc_removeAttributeNS, METH_VARARGS},
    {"removeAttributeNode", (PyCFunction)Sbk_QDomElementFunc_removeAttributeNode, METH_O},
    {"setAttribute", (PyCFunction)Sbk_QDomElementFunc_setAttribute, METH_VARARGS},
    {"setAttributeNS", (PyCFunction)Sbk_QDomElementFunc_setAttributeNS, METH_VARARGS},
    {"setAttributeNode", (PyCFunction)Sbk_QDomElementFunc_setAttributeNode, METH_O},
    {"setAttributeNodeNS", (PyCFunction)Sbk_QDomElementFunc_setAttributeNodeNS, METH_O},
    {"setTagName", (PyCFunction)Sbk_QDomElementFunc_setTagName, METH_O},
    {"tagName", (PyCFunction)Sbk_QDomElementFunc_tagName, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QDomElementFunc_text, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomElement___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomElement___nb_bool(PyObject* self)
{
    ::QDomElement* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomElement_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomElement_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomElement_TypeAsNumber;

static SbkObjectType Sbk_QDomElement_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomElement",
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
    /*tp_traverse*/         Sbk_QDomElement_traverse,
    /*tp_clear*/            Sbk_QDomElement_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomElement_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomElement_Init,
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
static void QDomElement_PythonToCpp_QDomElement_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomElement_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomElement_PythonToCpp_QDomElement_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomElement_Type))
        return QDomElement_PythonToCpp_QDomElement_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomElement_PTR_CppToPython_QDomElement(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomElement*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomElement_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomElement_COPY_CppToPython_QDomElement(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomElement_Type, new ::QDomElement(*((::QDomElement*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomElement_PythonToCpp_QDomElement_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomElement*)cppOut) = *((::QDomElement*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomElement_PythonToCpp_QDomElement_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomElement_Type))
        return QDomElement_PythonToCpp_QDomElement_COPY;
    return 0;
}

void init_QDomElement(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomElement_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomElement_TypeAsNumber) = Sbk_QDomElement___nb_bool;
    Sbk_QDomElement_Type.super.ht_type.tp_as_number = &Sbk_QDomElement_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomElement_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomElement", "QDomElement",
        &Sbk_QDomElement_Type, &Shiboken::callCppDestructor< ::QDomElement >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomElement_Type,
        QDomElement_PythonToCpp_QDomElement_PTR,
        is_QDomElement_PythonToCpp_QDomElement_PTR_Convertible,
        QDomElement_PTR_CppToPython_QDomElement,
        QDomElement_COPY_CppToPython_QDomElement);

    Shiboken::Conversions::registerConverterName(converter, "QDomElement");
    Shiboken::Conversions::registerConverterName(converter, "QDomElement*");
    Shiboken::Conversions::registerConverterName(converter, "QDomElement&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomElement).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomElement_PythonToCpp_QDomElement_COPY,
        is_QDomElement_PythonToCpp_QDomElement_COPY_Convertible);


    qRegisterMetaType< ::QDomElement >("QDomElement");
}
