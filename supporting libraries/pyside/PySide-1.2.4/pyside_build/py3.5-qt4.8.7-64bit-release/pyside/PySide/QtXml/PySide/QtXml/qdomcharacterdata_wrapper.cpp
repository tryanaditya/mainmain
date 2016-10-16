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

#include "qdomcharacterdata_wrapper.h"

// Extra includes
#include <qdom.h>
#include <qtextstream.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDomCharacterData_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDomCharacterData >()))
        return -1;

    ::QDomCharacterData* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDomCharacterData", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDomCharacterData()
    // 1: QDomCharacterData(QDomCharacterData)
    if (numArgs == 0) {
        overloadId = 0; // QDomCharacterData()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDomCharacterData(QDomCharacterData)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterData_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDomCharacterData()
        {

            if (!PyErr_Occurred()) {
                // QDomCharacterData()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomCharacterData();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDomCharacterData(const QDomCharacterData & x)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDomCharacterData cppArg0_local = ::QDomCharacterData();
            ::QDomCharacterData* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDomCharacterData(QDomCharacterData)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDomCharacterData(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDomCharacterData >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDomCharacterData_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDomCharacterData_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtXml.QDomCharacterData", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomCharacterData", overloads);
        return -1;
}

static PyObject* Sbk_QDomCharacterDataFunc_appendData(PyObject* self, PyObject* pyArg)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendData(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendData(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_appendData_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendData(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomCharacterDataFunc_appendData_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomCharacterData.appendData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterDataFunc_data(PyObject* self)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDomCharacterData*>(cppSelf)->data();
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

static PyObject* Sbk_QDomCharacterDataFunc_deleteData(PyObject* self, PyObject* args)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "deleteData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: deleteData(ulong,ulong)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1])))) {
        overloadId = 0; // deleteData(ulong,ulong)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_deleteData_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        unsigned long cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // deleteData(ulong,ulong)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deleteData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomCharacterDataFunc_deleteData_TypeError:
        const char* overloads[] = {"unsigned long, unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomCharacterData.deleteData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterDataFunc_insertData(PyObject* self, PyObject* args)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertData(ulong,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertData(ulong,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_insertData_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertData(ulong,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomCharacterDataFunc_insertData_TypeError:
        const char* overloads[] = {"unsigned long, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomCharacterData.insertData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterDataFunc_length(PyObject* self)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QDomCharacterData*>(cppSelf)->length();
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

static PyObject* Sbk_QDomCharacterDataFunc_nodeType(PyObject* self)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nodeType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDomNode::NodeType cppResult = const_cast<const ::QDomCharacterData*>(cppSelf)->nodeType();
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

static PyObject* Sbk_QDomCharacterDataFunc_replaceData(PyObject* self, PyObject* args)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replaceData", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: replaceData(ulong,ulong,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // replaceData(ulong,ulong,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_replaceData_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        unsigned long cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // replaceData(ulong,ulong,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->replaceData(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomCharacterDataFunc_replaceData_TypeError:
        const char* overloads[] = {"unsigned long, unsigned long, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomCharacterData.replaceData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterDataFunc_setData(PyObject* self, PyObject* pyArg)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setData(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setData(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_setData_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setData(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDomCharacterDataFunc_setData_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QDomCharacterData.setData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterDataFunc_substringData(PyObject* self, PyObject* args)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "substringData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: substringData(ulong,ulong)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArgs[1])))) {
        overloadId = 0; // substringData(ulong,ulong)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDomCharacterDataFunc_substringData_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        unsigned long cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // substringData(ulong,ulong)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->substringData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDomCharacterDataFunc_substringData_TypeError:
        const char* overloads[] = {"unsigned long, unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QDomCharacterData.substringData", overloads);
        return 0;
}

static PyObject* Sbk_QDomCharacterData___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDomCharacterData& cppSelf = *(((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDomCharacterData_methods[] = {
    {"appendData", (PyCFunction)Sbk_QDomCharacterDataFunc_appendData, METH_O},
    {"data", (PyCFunction)Sbk_QDomCharacterDataFunc_data, METH_NOARGS},
    {"deleteData", (PyCFunction)Sbk_QDomCharacterDataFunc_deleteData, METH_VARARGS},
    {"insertData", (PyCFunction)Sbk_QDomCharacterDataFunc_insertData, METH_VARARGS},
    {"length", (PyCFunction)Sbk_QDomCharacterDataFunc_length, METH_NOARGS},
    {"nodeType", (PyCFunction)Sbk_QDomCharacterDataFunc_nodeType, METH_NOARGS},
    {"replaceData", (PyCFunction)Sbk_QDomCharacterDataFunc_replaceData, METH_VARARGS},
    {"setData", (PyCFunction)Sbk_QDomCharacterDataFunc_setData, METH_O},
    {"substringData", (PyCFunction)Sbk_QDomCharacterDataFunc_substringData, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QDomCharacterData___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QDomCharacterData___nb_bool(PyObject* self)
{
    ::QDomCharacterData* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

} // extern "C"

static int Sbk_QDomCharacterData_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDomCharacterData_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QDomCharacterData_TypeAsNumber;

static SbkObjectType Sbk_QDomCharacterData_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QDomCharacterData",
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
    /*tp_traverse*/         Sbk_QDomCharacterData_traverse,
    /*tp_clear*/            Sbk_QDomCharacterData_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDomCharacterData_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDomCharacterData_Init,
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
static void QDomCharacterData_PythonToCpp_QDomCharacterData_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDomCharacterData_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDomCharacterData_PythonToCpp_QDomCharacterData_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomCharacterData_Type))
        return QDomCharacterData_PythonToCpp_QDomCharacterData_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDomCharacterData_PTR_CppToPython_QDomCharacterData(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDomCharacterData*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDomCharacterData_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDomCharacterData_COPY_CppToPython_QDomCharacterData(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDomCharacterData_Type, new ::QDomCharacterData(*((::QDomCharacterData*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDomCharacterData_PythonToCpp_QDomCharacterData_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDomCharacterData*)cppOut) = *((::QDomCharacterData*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDomCharacterData_PythonToCpp_QDomCharacterData_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDomCharacterData_Type))
        return QDomCharacterData_PythonToCpp_QDomCharacterData_COPY;
    return 0;
}

void init_QDomCharacterData(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QDomCharacterData_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QDomCharacterData_TypeAsNumber) = Sbk_QDomCharacterData___nb_bool;
    Sbk_QDomCharacterData_Type.super.ht_type.tp_as_number = &Sbk_QDomCharacterData_TypeAsNumber;

    SbkPySide_QtXmlTypes[SBK_QDOMCHARACTERDATA_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDomCharacterData_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDomCharacterData", "QDomCharacterData",
        &Sbk_QDomCharacterData_Type, &Shiboken::callCppDestructor< ::QDomCharacterData >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QDOMNODE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDomCharacterData_Type,
        QDomCharacterData_PythonToCpp_QDomCharacterData_PTR,
        is_QDomCharacterData_PythonToCpp_QDomCharacterData_PTR_Convertible,
        QDomCharacterData_PTR_CppToPython_QDomCharacterData,
        QDomCharacterData_COPY_CppToPython_QDomCharacterData);

    Shiboken::Conversions::registerConverterName(converter, "QDomCharacterData");
    Shiboken::Conversions::registerConverterName(converter, "QDomCharacterData*");
    Shiboken::Conversions::registerConverterName(converter, "QDomCharacterData&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDomCharacterData).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDomCharacterData_PythonToCpp_QDomCharacterData_COPY,
        is_QDomCharacterData_PythonToCpp_QDomCharacterData_COPY_Convertible);


    qRegisterMetaType< ::QDomCharacterData >("QDomCharacterData");
}
