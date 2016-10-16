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

#include "qxmlnamespacesupport_wrapper.h"

// Extra includes
#include <qxml.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QXmlNamespaceSupport_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlNamespaceSupport >()))
        return -1;

    ::QXmlNamespaceSupport* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QXmlNamespaceSupport()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QXmlNamespaceSupport();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlNamespaceSupport >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_popContext(PyObject* self)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // popContext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->popContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_prefix(PyObject* self, PyObject* pyArg)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prefix(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // prefix(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_prefix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // prefix(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->prefix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNamespaceSupportFunc_prefix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlNamespaceSupport.prefix", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_prefixes(PyObject* self, PyObject* args)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "prefixes", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: prefixes()const
    // 1: prefixes(QString)const
    if (numArgs == 0) {
        overloadId = 0; // prefixes()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // prefixes(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_prefixes_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // prefixes() const
        {

            if (!PyErr_Occurred()) {
                // prefixes()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->prefixes();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
        case 1: // prefixes(const QString & arg__1) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // prefixes(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->prefixes(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNamespaceSupportFunc_prefixes_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlNamespaceSupport.prefixes", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_processName(PyObject* self, PyObject* args)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "processName", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: processName(QString,bool,QString&,QString&)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
        overloadId = 0; // processName(QString,bool,QString&,QString&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_processName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = ::QString();
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // processName(QString,bool,QString&,QString&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->processName(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlNamespaceSupportFunc_processName_TypeError:
        const char* overloads[] = {"unicode, bool, PySide.QtCore.QString, PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlNamespaceSupport.processName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_pushContext(PyObject* self)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pushContext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pushContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_reset(PyObject* self)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_setPrefix(PyObject* self, PyObject* args)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPrefix", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPrefix(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setPrefix(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_setPrefix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setPrefix(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrefix(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlNamespaceSupportFunc_setPrefix_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlNamespaceSupport.setPrefix", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_splitName(PyObject* self, PyObject* args)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "splitName", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: splitName(QString,QString&,QString&)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // splitName(QString,QString&,QString&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_splitName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // splitName(QString,QString&,QString&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->splitName(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlNamespaceSupportFunc_splitName_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QString, PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlNamespaceSupport.splitName", overloads);
        return 0;
}

static PyObject* Sbk_QXmlNamespaceSupportFunc_uri(PyObject* self, PyObject* pyArg)
{
    ::QXmlNamespaceSupport* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlNamespaceSupport*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: uri(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // uri(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlNamespaceSupportFunc_uri_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // uri(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QXmlNamespaceSupport*>(cppSelf)->uri(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlNamespaceSupportFunc_uri_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlNamespaceSupport.uri", overloads);
        return 0;
}

static PyMethodDef Sbk_QXmlNamespaceSupport_methods[] = {
    {"popContext", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_popContext, METH_NOARGS},
    {"prefix", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_prefix, METH_O},
    {"prefixes", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_prefixes, METH_VARARGS},
    {"processName", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_processName, METH_VARARGS},
    {"pushContext", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_pushContext, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_reset, METH_NOARGS},
    {"setPrefix", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_setPrefix, METH_VARARGS},
    {"splitName", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_splitName, METH_VARARGS},
    {"uri", (PyCFunction)Sbk_QXmlNamespaceSupportFunc_uri, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlNamespaceSupport_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlNamespaceSupport_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlNamespaceSupport_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlNamespaceSupport",
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
    /*tp_traverse*/         Sbk_QXmlNamespaceSupport_traverse,
    /*tp_clear*/            Sbk_QXmlNamespaceSupport_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlNamespaceSupport_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlNamespaceSupport_Init,
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
static void QXmlNamespaceSupport_PythonToCpp_QXmlNamespaceSupport_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlNamespaceSupport_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlNamespaceSupport_PythonToCpp_QXmlNamespaceSupport_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlNamespaceSupport_Type))
        return QXmlNamespaceSupport_PythonToCpp_QXmlNamespaceSupport_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlNamespaceSupport_PTR_CppToPython_QXmlNamespaceSupport(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlNamespaceSupport*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlNamespaceSupport_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlNamespaceSupport(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLNAMESPACESUPPORT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlNamespaceSupport_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlNamespaceSupport", "QXmlNamespaceSupport*",
        &Sbk_QXmlNamespaceSupport_Type, &Shiboken::callCppDestructor< ::QXmlNamespaceSupport >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlNamespaceSupport_Type,
        QXmlNamespaceSupport_PythonToCpp_QXmlNamespaceSupport_PTR,
        is_QXmlNamespaceSupport_PythonToCpp_QXmlNamespaceSupport_PTR_Convertible,
        QXmlNamespaceSupport_PTR_CppToPython_QXmlNamespaceSupport);

    Shiboken::Conversions::registerConverterName(converter, "QXmlNamespaceSupport");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNamespaceSupport*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlNamespaceSupport&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlNamespaceSupport).name());



}
