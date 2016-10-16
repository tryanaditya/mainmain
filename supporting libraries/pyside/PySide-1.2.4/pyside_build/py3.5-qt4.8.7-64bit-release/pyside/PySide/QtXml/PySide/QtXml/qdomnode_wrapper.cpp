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

#include "qdomnode_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomNode_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomNode >()))
        return -1;

    ::QDomNode* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomNode", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomNode()
    // 1: QDomNode(QDomNode)
    if (numArgs == 0) {
        overloadId = 0; // QDomNode()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomNode(QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNode_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomNode()
        {

            if (!PyErr_Occurred()) {
                // QDomNode()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNode();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomNode(const QDomNode & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomNode cppArg0_local = ::QDomNode();
            ::QDomNode* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomNode(QDomNode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNode(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomNode >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomNode_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomNode_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode", overloads);
        return -1;
}

static PyObject* Sbk_QDomNodeFunc_appendChild(PyObject* self, PyObject* pyArg)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendChild(QDomNode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
        overloadId = 0; // appendChild(QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_appendChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDomNode cppArg0_local = ::QDomNode();
        ::QDomNode* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // appendChild(QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->appendChild(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_appendChild_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.appendChild", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_attributes(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // attributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNamedNodeMap cppResult = const_cast<const ::QDomNode*>(cppSelf)->attributes();
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

static PyObject* Sbk_QDomNodeFunc_childNodes(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childNodes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNodeList cppResult = const_cast<const ::QDomNode*>(cppSelf)->childNodes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODELIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_clear(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QDomNodeFunc_cloneNode(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.cloneNode(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:cloneNode", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: cloneNode(bool)const
    if (numArgs == 0) {
        overloadId = 0; // cloneNode(bool)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // cloneNode(bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_cloneNode_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "deep");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.cloneNode(): got multiple values for keyword argument 'deep'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_QDomNodeFunc_cloneNode_TypeError;
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // cloneNode(bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->cloneNode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_cloneNode_TypeError:
        const char* overloads[] = {"bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.cloneNode", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_columnNumber(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNode*>(cppSelf)->columnNumber();
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

static PyObject* Sbk_QDomNodeFunc_firstChild(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstChild()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->firstChild();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_firstChildElement(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.firstChildElement(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:firstChildElement", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: firstChildElement(QString)const
    if (numArgs == 0) {
        overloadId = 0; // firstChildElement(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // firstChildElement(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_firstChildElement_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "tagName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.firstChildElement(): got multiple values for keyword argument 'tagName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QDomNodeFunc_firstChildElement_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // firstChildElement(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomNode*>(cppSelf)->firstChildElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_firstChildElement_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.firstChildElement", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_hasAttributes(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAttributes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->hasAttributes();
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

static PyObject* Sbk_QDomNodeFunc_hasChildNodes(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasChildNodes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->hasChildNodes();
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

static PyObject* Sbk_QDomNodeFunc_insertAfter(PyObject* self, PyObject* args)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertAfter", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertAfter(QDomNode,QDomNode)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertAfter(QDomNode,QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_insertAfter_TypeError;

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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDomNode cppArg1_local = ::QDomNode();
        ::QDomNode* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insertAfter(QDomNode,QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->insertAfter(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_insertAfter_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode, PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.insertAfter", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_insertBefore(PyObject* self, PyObject* args)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertBefore", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertBefore(QDomNode,QDomNode)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertBefore(QDomNode,QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_insertBefore_TypeError;

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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDomNode cppArg1_local = ::QDomNode();
        ::QDomNode* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insertBefore(QDomNode,QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->insertBefore(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_insertBefore_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode, PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.insertBefore", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_isAttr(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAttr()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isAttr();
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

static PyObject* Sbk_QDomNodeFunc_isCDATASection(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCDATASection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isCDATASection();
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

static PyObject* Sbk_QDomNodeFunc_isCharacterData(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCharacterData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isCharacterData();
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

static PyObject* Sbk_QDomNodeFunc_isComment(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isComment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isComment();
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

static PyObject* Sbk_QDomNodeFunc_isDocument(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isDocument();
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

static PyObject* Sbk_QDomNodeFunc_isDocumentFragment(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDocumentFragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isDocumentFragment();
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

static PyObject* Sbk_QDomNodeFunc_isDocumentType(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDocumentType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isDocumentType();
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

static PyObject* Sbk_QDomNodeFunc_isElement(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isElement();
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

static PyObject* Sbk_QDomNodeFunc_isEntity(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEntity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isEntity();
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

static PyObject* Sbk_QDomNodeFunc_isEntityReference(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEntityReference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isEntityReference();
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

static PyObject* Sbk_QDomNodeFunc_isNotation(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNotation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isNotation();
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

static PyObject* Sbk_QDomNodeFunc_isNull(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isNull();
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

static PyObject* Sbk_QDomNodeFunc_isProcessingInstruction(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isProcessingInstruction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isProcessingInstruction();
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

static PyObject* Sbk_QDomNodeFunc_isSupported(PyObject* self, PyObject* args)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isSupported", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isSupported(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // isSupported(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_isSupported_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isSupported(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isSupported(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_isSupported_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.isSupported", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_isText(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNode*>(cppSelf)->isText();
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

static PyObject* Sbk_QDomNodeFunc_lastChild(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastChild()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->lastChild();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_lastChildElement(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.lastChildElement(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:lastChildElement", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: lastChildElement(QString)const
    if (numArgs == 0) {
        overloadId = 0; // lastChildElement(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // lastChildElement(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_lastChildElement_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "tagName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.lastChildElement(): got multiple values for keyword argument 'tagName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QDomNodeFunc_lastChildElement_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // lastChildElement(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomNode*>(cppSelf)->lastChildElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_lastChildElement_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.lastChildElement", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_lineNumber(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNode*>(cppSelf)->lineNumber();
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

static PyObject* Sbk_QDomNodeFunc_localName(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomNode*>(cppSelf)->localName();
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

static PyObject* Sbk_QDomNodeFunc_namedItem(PyObject* self, PyObject* pyArg)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: namedItem(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // namedItem(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_namedItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // namedItem(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->namedItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_namedItem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.namedItem", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_namespaceURI(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // namespaceURI()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomNode*>(cppSelf)->namespaceURI();
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

static PyObject* Sbk_QDomNodeFunc_nextSibling(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextSibling()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->nextSibling();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_nextSiblingElement(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.nextSiblingElement(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:nextSiblingElement", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: nextSiblingElement(QString)const
    if (numArgs == 0) {
        overloadId = 0; // nextSiblingElement(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // nextSiblingElement(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_nextSiblingElement_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "taName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.nextSiblingElement(): got multiple values for keyword argument 'taName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QDomNodeFunc_nextSiblingElement_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // nextSiblingElement(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomNode*>(cppSelf)->nextSiblingElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_nextSiblingElement_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.nextSiblingElement", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_nodeName(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomNode*>(cppSelf)->nodeName();
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

static PyObject* Sbk_QDomNodeFunc_nodeType(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomNode*>(cppSelf)->nodeType();
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

static PyObject* Sbk_QDomNodeFunc_nodeValue(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomNode*>(cppSelf)->nodeValue();
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

static PyObject* Sbk_QDomNodeFunc_normalize(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalize()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->normalize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDomNodeFunc_ownerDocument(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownerDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocument cppResult = const_cast<const ::QDomNode*>(cppSelf)->ownerDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_parentNode(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentNode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->parentNode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_prefix(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomNode*>(cppSelf)->prefix();
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

static PyObject* Sbk_QDomNodeFunc_previousSibling(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previousSibling()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNode*>(cppSelf)->previousSibling();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_previousSiblingElement(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.previousSiblingElement(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:previousSiblingElement", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: previousSiblingElement(QString)const
    if (numArgs == 0) {
        overloadId = 0; // previousSiblingElement(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // previousSiblingElement(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_previousSiblingElement_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "tagName");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtXml.QDomNode.previousSiblingElement(): got multiple values for keyword argument 'tagName'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QDomNodeFunc_previousSiblingElement_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // previousSiblingElement(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomNode*>(cppSelf)->previousSiblingElement(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_previousSiblingElement_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.previousSiblingElement", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_removeChild(PyObject* self, PyObject* pyArg)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeChild(QDomNode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
        overloadId = 0; // removeChild(QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_removeChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDomNode cppArg0_local = ::QDomNode();
        ::QDomNode* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // removeChild(QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->removeChild(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_removeChild_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.removeChild", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_replaceChild(PyObject* self, PyObject* args)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replaceChild", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replaceChild(QDomNode,QDomNode)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArgs[1])))) {
        overloadId = 0; // replaceChild(QDomNode,QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_replaceChild_TypeError;

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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDomNode cppArg1_local = ::QDomNode();
        ::QDomNode* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // replaceChild(QDomNode,QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->replaceChild(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc_replaceChild_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode, PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.replaceChild", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_save(PyObject* self, PyObject* args)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "save", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: save(QTextStream&,int)const
    // 1: save(QTextStream&,int,QDomNode::EncodingPolicy)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // save(QTextStream&,int)const
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX]), (pyArgs[2])))) {
            overloadId = 1; // save(QTextStream&,int,QDomNode::EncodingPolicy)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_save_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // save(QTextStream & arg__1, int arg__2) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextStream* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // save(QTextStream&,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const_cast<const ::QDomNode*>(cppSelf)->save(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // save(QTextStream & arg__1, int arg__2, QDomNode::EncodingPolicy arg__3) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextStream* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QDomNode::EncodingPolicy cppArg2 = ((::QDomNode::EncodingPolicy)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // save(QTextStream&,int,QDomNode::EncodingPolicy)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const_cast<const ::QDomNode*>(cppSelf)->save(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomNodeFunc_save_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream, int", "PySide.QtCore.QTextStream, int, PySide.QtXml.QDomNode.EncodingPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNode.save", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_setNodeValue(PyObject* self, PyObject* pyArg)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNodeValue(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNodeValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_setNodeValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNodeValue(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNodeValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomNodeFunc_setNodeValue_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.setNodeValue", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_setPrefix(PyObject* self, PyObject* pyArg)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrefix(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPrefix(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc_setPrefix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrefix(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrefix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomNodeFunc_setPrefix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.setPrefix", overloads);
        return 0;
}

static PyObject* Sbk_QDomNodeFunc_toAttr(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toAttr()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomAttr cppResult = const_cast<const ::QDomNode*>(cppSelf)->toAttr();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMATTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toCDATASection(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toCDATASection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomCDATASection cppResult = const_cast<const ::QDomNode*>(cppSelf)->toCDATASection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCDATASECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toCharacterData(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toCharacterData()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomCharacterData cppResult = const_cast<const ::QDomNode*>(cppSelf)->toCharacterData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toComment(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toComment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomComment cppResult = const_cast<const ::QDomNode*>(cppSelf)->toComment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCOMMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toDocument(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toDocument()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocument cppResult = const_cast<const ::QDomNode*>(cppSelf)->toDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMDOCUMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toDocumentFragment(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toDocumentFragment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocumentFragment cppResult = const_cast<const ::QDomNode*>(cppSelf)->toDocumentFragment();
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

static PyObject* Sbk_QDomNodeFunc_toDocumentType(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toDocumentType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomDocumentType cppResult = const_cast<const ::QDomNode*>(cppSelf)->toDocumentType();
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

static PyObject* Sbk_QDomNodeFunc_toElement(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toElement()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomElement cppResult = const_cast<const ::QDomNode*>(cppSelf)->toElement();
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

static PyObject* Sbk_QDomNodeFunc_toEntity(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toEntity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomEntity cppResult = const_cast<const ::QDomNode*>(cppSelf)->toEntity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toEntityReference(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toEntityReference()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomEntityReference cppResult = const_cast<const ::QDomNode*>(cppSelf)->toEntityReference();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMENTITYREFERENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toNotation(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toNotation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNotation cppResult = const_cast<const ::QDomNode*>(cppSelf)->toNotation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNOTATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toProcessingInstruction(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toProcessingInstruction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomProcessingInstruction cppResult = const_cast<const ::QDomNode*>(cppSelf)->toProcessingInstruction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMPROCESSINGINSTRUCTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNodeFunc_toText(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomText cppResult = const_cast<const ::QDomNode*>(cppSelf)->toText();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMTEXT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNode___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNode& cppSelf = *(((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomNode_methods[] = {
    {"appendChild", (PyCFunction)Sbk_QDomNodeFunc_appendChild, METH_O},
    {"attributes", (PyCFunction)Sbk_QDomNodeFunc_attributes, METH_NOARGS},
    {"childNodes", (PyCFunction)Sbk_QDomNodeFunc_childNodes, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QDomNodeFunc_clear, METH_NOARGS},
    {"cloneNode", (PyCFunction)Sbk_QDomNodeFunc_cloneNode, METH_VARARGS|METH_KEYWORDS},
    {"columnNumber", (PyCFunction)Sbk_QDomNodeFunc_columnNumber, METH_NOARGS},
    {"firstChild", (PyCFunction)Sbk_QDomNodeFunc_firstChild, METH_NOARGS},
    {"firstChildElement", (PyCFunction)Sbk_QDomNodeFunc_firstChildElement, METH_VARARGS|METH_KEYWORDS},
    {"hasAttributes", (PyCFunction)Sbk_QDomNodeFunc_hasAttributes, METH_NOARGS},
    {"hasChildNodes", (PyCFunction)Sbk_QDomNodeFunc_hasChildNodes, METH_NOARGS},
    {"insertAfter", (PyCFunction)Sbk_QDomNodeFunc_insertAfter, METH_VARARGS},
    {"insertBefore", (PyCFunction)Sbk_QDomNodeFunc_insertBefore, METH_VARARGS},
    {"isAttr", (PyCFunction)Sbk_QDomNodeFunc_isAttr, METH_NOARGS},
    {"isCDATASection", (PyCFunction)Sbk_QDomNodeFunc_isCDATASection, METH_NOARGS},
    {"isCharacterData", (PyCFunction)Sbk_QDomNodeFunc_isCharacterData, METH_NOARGS},
    {"isComment", (PyCFunction)Sbk_QDomNodeFunc_isComment, METH_NOARGS},
    {"isDocument", (PyCFunction)Sbk_QDomNodeFunc_isDocument, METH_NOARGS},
    {"isDocumentFragment", (PyCFunction)Sbk_QDomNodeFunc_isDocumentFragment, METH_NOARGS},
    {"isDocumentType", (PyCFunction)Sbk_QDomNodeFunc_isDocumentType, METH_NOARGS},
    {"isElement", (PyCFunction)Sbk_QDomNodeFunc_isElement, METH_NOARGS},
    {"isEntity", (PyCFunction)Sbk_QDomNodeFunc_isEntity, METH_NOARGS},
    {"isEntityReference", (PyCFunction)Sbk_QDomNodeFunc_isEntityReference, METH_NOARGS},
    {"isNotation", (PyCFunction)Sbk_QDomNodeFunc_isNotation, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QDomNodeFunc_isNull, METH_NOARGS},
    {"isProcessingInstruction", (PyCFunction)Sbk_QDomNodeFunc_isProcessingInstruction, METH_NOARGS},
    {"isSupported", (PyCFunction)Sbk_QDomNodeFunc_isSupported, METH_VARARGS},
    {"isText", (PyCFunction)Sbk_QDomNodeFunc_isText, METH_NOARGS},
    {"lastChild", (PyCFunction)Sbk_QDomNodeFunc_lastChild, METH_NOARGS},
    {"lastChildElement", (PyCFunction)Sbk_QDomNodeFunc_lastChildElement, METH_VARARGS|METH_KEYWORDS},
    {"lineNumber", (PyCFunction)Sbk_QDomNodeFunc_lineNumber, METH_NOARGS},
    {"localName", (PyCFunction)Sbk_QDomNodeFunc_localName, METH_NOARGS},
    {"namedItem", (PyCFunction)Sbk_QDomNodeFunc_namedItem, METH_O},
    {"namespaceURI", (PyCFunction)Sbk_QDomNodeFunc_namespaceURI, METH_NOARGS},
    {"nextSibling", (PyCFunction)Sbk_QDomNodeFunc_nextSibling, METH_NOARGS},
    {"nextSiblingElement", (PyCFunction)Sbk_QDomNodeFunc_nextSiblingElement, METH_VARARGS|METH_KEYWORDS},
    {"nodeName", (PyCFunction)Sbk_QDomNodeFunc_nodeName, METH_NOARGS},
    {"nodeType", (PyCFunction)Sbk_QDomNodeFunc_nodeType, METH_NOARGS},
    {"nodeValue", (PyCFunction)Sbk_QDomNodeFunc_nodeValue, METH_NOARGS},
    {"normalize", (PyCFunction)Sbk_QDomNodeFunc_normalize, METH_NOARGS},
    {"ownerDocument", (PyCFunction)Sbk_QDomNodeFunc_ownerDocument, METH_NOARGS},
    {"parentNode", (PyCFunction)Sbk_QDomNodeFunc_parentNode, METH_NOARGS},
    {"prefix", (PyCFunction)Sbk_QDomNodeFunc_prefix, METH_NOARGS},
    {"previousSibling", (PyCFunction)Sbk_QDomNodeFunc_previousSibling, METH_NOARGS},
    {"previousSiblingElement", (PyCFunction)Sbk_QDomNodeFunc_previousSiblingElement, METH_VARARGS|METH_KEYWORDS},
    {"removeChild", (PyCFunction)Sbk_QDomNodeFunc_removeChild, METH_O},
    {"replaceChild", (PyCFunction)Sbk_QDomNodeFunc_replaceChild, METH_VARARGS},
    {"save", (PyCFunction)Sbk_QDomNodeFunc_save, METH_VARARGS},
    {"setNodeValue", (PyCFunction)Sbk_QDomNodeFunc_setNodeValue, METH_O},
    {"setPrefix", (PyCFunction)Sbk_QDomNodeFunc_setPrefix, METH_O},
    {"toAttr", (PyCFunction)Sbk_QDomNodeFunc_toAttr, METH_NOARGS},
    {"toCDATASection", (PyCFunction)Sbk_QDomNodeFunc_toCDATASection, METH_NOARGS},
    {"toCharacterData", (PyCFunction)Sbk_QDomNodeFunc_toCharacterData, METH_NOARGS},
    {"toComment", (PyCFunction)Sbk_QDomNodeFunc_toComment, METH_NOARGS},
    {"toDocument", (PyCFunction)Sbk_QDomNodeFunc_toDocument, METH_NOARGS},
    {"toDocumentFragment", (PyCFunction)Sbk_QDomNodeFunc_toDocumentFragment, METH_NOARGS},
    {"toDocumentType", (PyCFunction)Sbk_QDomNodeFunc_toDocumentType, METH_NOARGS},
    {"toElement", (PyCFunction)Sbk_QDomNodeFunc_toElement, METH_NOARGS},
    {"toEntity", (PyCFunction)Sbk_QDomNodeFunc_toEntity, METH_NOARGS},
    {"toEntityReference", (PyCFunction)Sbk_QDomNodeFunc_toEntityReference, METH_NOARGS},
    {"toNotation", (PyCFunction)Sbk_QDomNodeFunc_toNotation, METH_NOARGS},
    {"toProcessingInstruction", (PyCFunction)Sbk_QDomNodeFunc_toProcessingInstruction, METH_NOARGS},
    {"toText", (PyCFunction)Sbk_QDomNodeFunc_toText, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomNode___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomNode___nb_bool(PyObject* self)
{
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QDomNodeFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QDomNode* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self));
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
    // 0: operator<<(QTextStream&,QDomNode)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QTextStream&,QDomNode)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNodeFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QTextStream&,QDomNode) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTSTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNodeFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNode.__lshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QDomNode_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNode& cppSelf = *(((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
                // operator!=(const QDomNode & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNode cppArg0_local = ::QDomNode();
                ::QDomNode* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
                // operator==(const QDomNode & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNode cppArg0_local = ::QDomNode();
                ::QDomNode* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], pythonToCpp))
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
            goto Sbk_QDomNode_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDomNode_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDomNode_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomNode_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomNode_TypeAsNumber;

static SbkObjectType Sbk_QDomNode_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomNode",
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
    /*tp_traverse*/         Sbk_QDomNode_traverse,
    /*tp_clear*/            Sbk_QDomNode_clear,
    /*tp_richcompare*/      Sbk_QDomNode_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomNode_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomNode_Init,
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
static void QDomNode_NodeType_PythonToCpp_QDomNode_NodeType(PyObject* pyIn, void* cppOut) {
    *((::QDomNode::NodeType*)cppOut) = (::QDomNode::NodeType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDomNode_NodeType_PythonToCpp_QDomNode_NodeType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX]))
        return QDomNode_NodeType_PythonToCpp_QDomNode_NodeType;
    return 0;
}
static PyObject* QDomNode_NodeType_CppToPython_QDomNode_NodeType(const void* cppIn) {
    int castCppIn = *((::QDomNode::NodeType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX], castCppIn);

}

static void QDomNode_EncodingPolicy_PythonToCpp_QDomNode_EncodingPolicy(PyObject* pyIn, void* cppOut) {
    *((::QDomNode::EncodingPolicy*)cppOut) = (::QDomNode::EncodingPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDomNode_EncodingPolicy_PythonToCpp_QDomNode_EncodingPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX]))
        return QDomNode_EncodingPolicy_PythonToCpp_QDomNode_EncodingPolicy;
    return 0;
}
static PyObject* QDomNode_EncodingPolicy_CppToPython_QDomNode_EncodingPolicy(const void* cppIn) {
    int castCppIn = *((::QDomNode::EncodingPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDomNode_PythonToCpp_QDomNode_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomNode_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomNode_PythonToCpp_QDomNode_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNode_Type))
        return QDomNode_PythonToCpp_QDomNode_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomNode_PTR_CppToPython_QDomNode(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomNode*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomNode_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomNode_COPY_CppToPython_QDomNode(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomNode_Type, new ::QDomNode(*((::QDomNode*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomNode_PythonToCpp_QDomNode_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomNode*)cppOut) = *((::QDomNode*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomNode_PythonToCpp_QDomNode_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNode_Type))
        return QDomNode_PythonToCpp_QDomNode_COPY;
    return 0;
}

void init_QDomNode(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomNode_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QDomNode_TypeAsNumber.nb_lshift = Sbk_QDomNodeFunc___lshift__;
    SBK_NB_BOOL(Sbk_QDomNode_TypeAsNumber) = Sbk_QDomNode___nb_bool;
    Sbk_QDomNode_Type.super.ht_type.tp_as_number = &Sbk_QDomNode_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomNode_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomNode", "QDomNode",
        &Sbk_QDomNode_Type, &Shiboken::callCppDestructor< ::QDomNode >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomNode_Type,
        QDomNode_PythonToCpp_QDomNode_PTR,
        is_QDomNode_PythonToCpp_QDomNode_PTR_Convertible,
        QDomNode_PTR_CppToPython_QDomNode,
        QDomNode_COPY_CppToPython_QDomNode);

    Shiboken::Conversions::registerConverterName(converter, "QDomNode");
    Shiboken::Conversions::registerConverterName(converter, "QDomNode*");
    Shiboken::Conversions::registerConverterName(converter, "QDomNode&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomNode).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomNode_PythonToCpp_QDomNode_COPY,
        is_QDomNode_PythonToCpp_QDomNode_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'NodeType'.
    SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDomNode_Type,
        "NodeType",
        "PySide.QtXml.QDomNode.NodeType",
        "QDomNode::NodeType");
    if (!SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "ElementNode", (long) QDomNode::ElementNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "AttributeNode", (long) QDomNode::AttributeNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "TextNode", (long) QDomNode::TextNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "CDATASectionNode", (long) QDomNode::CDATASectionNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "EntityReferenceNode", (long) QDomNode::EntityReferenceNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "EntityNode", (long) QDomNode::EntityNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "ProcessingInstructionNode", (long) QDomNode::ProcessingInstructionNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "CommentNode", (long) QDomNode::CommentNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "DocumentNode", (long) QDomNode::DocumentNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "DocumentTypeNode", (long) QDomNode::DocumentTypeNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "DocumentFragmentNode", (long) QDomNode::DocumentFragmentNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "NotationNode", (long) QDomNode::NotationNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "BaseNode", (long) QDomNode::BaseNode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
        &Sbk_QDomNode_Type, "CharacterDataNode", (long) QDomNode::CharacterDataNode))
        return ;
    // Register converter for enum 'QDomNode::NodeType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX],
            QDomNode_NodeType_CppToPython_QDomNode_NodeType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDomNode_NodeType_PythonToCpp_QDomNode_NodeType,
            is_QDomNode_NodeType_PythonToCpp_QDomNode_NodeType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_NODETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDomNode::NodeType");
        Shiboken::Conversions::registerConverterName(converter, "NodeType");
    }
    // End of 'NodeType' enum.

    // Initialization of enum 'EncodingPolicy'.
    SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDomNode_Type,
        "EncodingPolicy",
        "PySide.QtXml.QDomNode.EncodingPolicy",
        "QDomNode::EncodingPolicy");
    if (!SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX],
        &Sbk_QDomNode_Type, "EncodingFromDocument", (long) QDomNode::EncodingFromDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX],
        &Sbk_QDomNode_Type, "EncodingFromTextStream", (long) QDomNode::EncodingFromTextStream))
        return ;
    // Register converter for enum 'QDomNode::EncodingPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX],
            QDomNode_EncodingPolicy_CppToPython_QDomNode_EncodingPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDomNode_EncodingPolicy_PythonToCpp_QDomNode_EncodingPolicy,
            is_QDomNode_EncodingPolicy_PythonToCpp_QDomNode_EncodingPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlTypes[SBK_QDOMNODE_ENCODINGPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDomNode::EncodingPolicy");
        Shiboken::Conversions::registerConverterName(converter, "EncodingPolicy");
    }
    // End of 'EncodingPolicy' enum.


    qRegisterMetaType< ::QDomNode >("QDomNode");
    qRegisterMetaType< ::QDomNode::NodeType >("QDomNode::NodeType");
    qRegisterMetaType< ::QDomNode::EncodingPolicy >("QDomNode::EncodingPolicy");
}
