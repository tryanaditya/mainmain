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

#include "qdomnamednodemap_wrapper.h"

// Extra includes
#include <qdom.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomNamedNodeMap_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomNamedNodeMap >()))
        return -1;

    ::QDomNamedNodeMap* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomNamedNodeMap", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomNamedNodeMap()
    // 1: QDomNamedNodeMap(QDomNamedNodeMap)
    if (numArgs == 0) {
        overloadId = 0; // QDomNamedNodeMap()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomNamedNodeMap(QDomNamedNodeMap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMap_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomNamedNodeMap()
        {

            if (!PyErr_Occurred()) {
                // QDomNamedNodeMap()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNamedNodeMap();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomNamedNodeMap(const QDomNamedNodeMap & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomNamedNodeMap cppArg0_local = ::QDomNamedNodeMap();
            ::QDomNamedNodeMap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomNamedNodeMap(QDomNamedNodeMap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomNamedNodeMap(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomNamedNodeMap >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomNamedNodeMap_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomNamedNodeMap_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomNamedNodeMap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNamedNodeMap", overloads);
        return -1;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_contains_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_contains_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.contains", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_count(PyObject* self)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->count();
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

static PyObject* Sbk_QDomNamedNodeMapFunc_isEmpty(PyObject* self)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QDomNamedNodeMapFunc_item(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: item(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // item(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_item_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // item(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->item(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_item_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.item", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_length(PyObject* self)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->length();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_namedItem(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_namedItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // namedItem(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->namedItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_namedItem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.namedItem", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_namedItemNS(PyObject* self, PyObject* args)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "namedItemNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: namedItemNS(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // namedItemNS(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_namedItemNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // namedItemNS(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->namedItemNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_namedItemNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNamedNodeMap.namedItemNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_removeNamedItem(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeNamedItem(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeNamedItem(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_removeNamedItem_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeNamedItem(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->removeNamedItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_removeNamedItem_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.removeNamedItem", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_removeNamedItemNS(PyObject* self, PyObject* args)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removeNamedItemNS", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeNamedItemNS(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // removeNamedItemNS(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_removeNamedItemNS_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeNamedItemNS(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->removeNamedItemNS(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_removeNamedItemNS_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomNamedNodeMap.removeNamedItemNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_setNamedItem(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNamedItem(QDomNode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
        overloadId = 0; // setNamedItem(QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_setNamedItem_TypeError;

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
            // setNamedItem(QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->setNamedItem(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_setNamedItem_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.setNamedItem", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_setNamedItemNS(PyObject* self, PyObject* pyArg)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNamedItemNS(QDomNode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], (pyArg)))) {
        overloadId = 0; // setNamedItemNS(QDomNode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomNamedNodeMapFunc_setNamedItemNS_TypeError;

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
            // setNamedItemNS(QDomNode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode cppResult = cppSelf->setNamedItemNS(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomNamedNodeMapFunc_setNamedItemNS_TypeError:
        const char* overloads[] = {"PySide.QtXml.QDomNode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomNamedNodeMap.setNamedItemNS", overloads);
        return 0;
}

static PyObject* Sbk_QDomNamedNodeMapFunc_size(PyObject* self)
{
    ::QDomNamedNodeMap* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDomNamedNodeMap*>(cppSelf)->size();
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

static PyObject* Sbk_QDomNamedNodeMap___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNamedNodeMap& cppSelf = *(((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomNamedNodeMap_methods[] = {
    {"contains", (PyCFunction)Sbk_QDomNamedNodeMapFunc_contains, METH_O},
    {"count", (PyCFunction)Sbk_QDomNamedNodeMapFunc_count, METH_NOARGS},
    {"isEmpty", (PyCFunction)Sbk_QDomNamedNodeMapFunc_isEmpty, METH_NOARGS},
    {"item", (PyCFunction)Sbk_QDomNamedNodeMapFunc_item, METH_O},
    {"length", (PyCFunction)Sbk_QDomNamedNodeMapFunc_length, METH_NOARGS},
    {"namedItem", (PyCFunction)Sbk_QDomNamedNodeMapFunc_namedItem, METH_O},
    {"namedItemNS", (PyCFunction)Sbk_QDomNamedNodeMapFunc_namedItemNS, METH_VARARGS},
    {"removeNamedItem", (PyCFunction)Sbk_QDomNamedNodeMapFunc_removeNamedItem, METH_O},
    {"removeNamedItemNS", (PyCFunction)Sbk_QDomNamedNodeMapFunc_removeNamedItemNS, METH_VARARGS},
    {"setNamedItem", (PyCFunction)Sbk_QDomNamedNodeMapFunc_setNamedItem, METH_O},
    {"setNamedItemNS", (PyCFunction)Sbk_QDomNamedNodeMapFunc_setNamedItemNS, METH_O},
    {"size", (PyCFunction)Sbk_QDomNamedNodeMapFunc_size, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QDomNamedNodeMap___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QDomNamedNodeMap_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomNamedNodeMap& cppSelf = *(((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (pyArg)))) {
                // operator!=(const QDomNamedNodeMap & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNamedNodeMap cppArg0_local = ::QDomNamedNodeMap();
                ::QDomNamedNodeMap* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (pyArg)))) {
                // operator==(const QDomNamedNodeMap & arg__1) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDomNamedNodeMap cppArg0_local = ::QDomNamedNodeMap();
                ::QDomNamedNodeMap* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], pythonToCpp))
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
            goto Sbk_QDomNamedNodeMap_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDomNamedNodeMap_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDomNamedNodeMap_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomNamedNodeMap_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDomNamedNodeMap_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomNamedNodeMap",
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
    /*tp_traverse*/         Sbk_QDomNamedNodeMap_traverse,
    /*tp_clear*/            Sbk_QDomNamedNodeMap_clear,
    /*tp_richcompare*/      Sbk_QDomNamedNodeMap_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomNamedNodeMap_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomNamedNodeMap_Init,
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
static void QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomNamedNodeMap_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNamedNodeMap_Type))
        return QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomNamedNodeMap_PTR_CppToPython_QDomNamedNodeMap(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomNamedNodeMap*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomNamedNodeMap_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomNamedNodeMap_COPY_CppToPython_QDomNamedNodeMap(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomNamedNodeMap_Type, new ::QDomNamedNodeMap(*((::QDomNamedNodeMap*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomNamedNodeMap*)cppOut) = *((::QDomNamedNodeMap*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomNamedNodeMap_Type))
        return QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_COPY;
    return 0;
}

void init_QDomNamedNodeMap(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QDOMNAMEDNODEMAP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomNamedNodeMap_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomNamedNodeMap", "QDomNamedNodeMap",
        &Sbk_QDomNamedNodeMap_Type, &Shiboken::callCppDestructor< ::QDomNamedNodeMap >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomNamedNodeMap_Type,
        QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_PTR,
        is_QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_PTR_Convertible,
        QDomNamedNodeMap_PTR_CppToPython_QDomNamedNodeMap,
        QDomNamedNodeMap_COPY_CppToPython_QDomNamedNodeMap);

    Shiboken::Conversions::registerConverterName(converter, "QDomNamedNodeMap");
    Shiboken::Conversions::registerConverterName(converter, "QDomNamedNodeMap*");
    Shiboken::Conversions::registerConverterName(converter, "QDomNamedNodeMap&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomNamedNodeMap).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_COPY,
        is_QDomNamedNodeMap_PythonToCpp_QDomNamedNodeMap_COPY_Convertible);


    qRegisterMetaType< ::QDomNamedNodeMap >("QDomNamedNodeMap");
}
