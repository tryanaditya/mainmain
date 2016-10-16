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


// default includes
#include <shiboken.h>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <typeresolver.h>
#include <typeinfo>
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qthelp_python.h"

#include "qhelpindexmodel_wrapper.h"

// Extra includes
#include <QList>
#include <QMap>
#include <pysideconversions.h>
#include <qabstractitemmodel.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdatastream.h>
#include <qmetaobject.h>
#include <qmimedata.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsize.h>
#include <qstringlistmodel.h>
#include <qthread.h>
#include <qurl.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QHelpIndexModelFunc_createIndex(PyObject* self, PyObject* pyArg)
{
    ::QHelpIndexModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpIndexModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPINDEXMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createIndex(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // createIndex(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpIndexModelFunc_createIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createIndex(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->createIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QHelpIndexModelFunc_createIndex_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtHelp.QHelpIndexModel.createIndex", overloads);
        return 0;
}

static PyObject* Sbk_QHelpIndexModelFunc_filter(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHelpIndexModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpIndexModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPINDEXMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtHelp.QHelpIndexModel.filter(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtHelp.QHelpIndexModel.filter(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:filter", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: filter(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // filter(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // filter(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpIndexModelFunc_filter_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "wildcard");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtHelp.QHelpIndexModel.filter(): got multiple values for keyword argument 'wildcard'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QHelpIndexModelFunc_filter_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // filter(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = cppSelf->filter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHelpIndexModelFunc_filter_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtHelp.QHelpIndexModel.filter", overloads);
        return 0;
}

static PyObject* Sbk_QHelpIndexModelFunc_isCreatingIndex(PyObject* self)
{
    ::QHelpIndexModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpIndexModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPINDEXMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCreatingIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QHelpIndexModel*>(cppSelf)->isCreatingIndex();
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

static PyObject* Sbk_QHelpIndexModelFunc_linksForKeyword(PyObject* self, PyObject* pyArg)
{
    ::QHelpIndexModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHelpIndexModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtHelpTypes[SBK_QHELPINDEXMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: linksForKeyword(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // linksForKeyword(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHelpIndexModelFunc_linksForKeyword_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // linksForKeyword(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMap<QString, QUrl > cppResult = const_cast<const ::QHelpIndexModel*>(cppSelf)->linksForKeyword(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtHelpTypeConverters[SBK_QTHELP_QMAP_QSTRING_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHelpIndexModelFunc_linksForKeyword_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtHelp.QHelpIndexModel.linksForKeyword", overloads);
        return 0;
}

static PyMethodDef Sbk_QHelpIndexModel_methods[] = {
    {"createIndex", (PyCFunction)Sbk_QHelpIndexModelFunc_createIndex, METH_O},
    {"filter", (PyCFunction)Sbk_QHelpIndexModelFunc_filter, METH_VARARGS|METH_KEYWORDS},
    {"isCreatingIndex", (PyCFunction)Sbk_QHelpIndexModelFunc_isCreatingIndex, METH_NOARGS},
    {"linksForKeyword", (PyCFunction)Sbk_QHelpIndexModelFunc_linksForKeyword, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QHelpIndexModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHelpIndexModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHelpIndexModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtHelp.QHelpIndexModel",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          SbkDeallocWrapperWithPrivateDtor,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QHelpIndexModel_traverse,
    /*tp_clear*/            Sbk_QHelpIndexModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHelpIndexModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

static void* Sbk_QHelpIndexModel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QHelpIndexModel*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHelpIndexModel_PythonToCpp_QHelpIndexModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHelpIndexModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHelpIndexModel_PythonToCpp_QHelpIndexModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHelpIndexModel_Type))
        return QHelpIndexModel_PythonToCpp_QHelpIndexModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHelpIndexModel_PTR_CppToPython_QHelpIndexModel(const void* cppIn) {
    return PySide::getWrapperForQObject((::QHelpIndexModel*)cppIn, &Sbk_QHelpIndexModel_Type);

}

void init_QHelpIndexModel(PyObject* module)
{
    SbkPySide_QtHelpTypes[SBK_QHELPINDEXMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHelpIndexModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHelpIndexModel", "QHelpIndexModel*",
        &Sbk_QHelpIndexModel_Type, 0, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTRINGLISTMODEL_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHelpIndexModel_Type,
        QHelpIndexModel_PythonToCpp_QHelpIndexModel_PTR,
        is_QHelpIndexModel_PythonToCpp_QHelpIndexModel_PTR_Convertible,
        QHelpIndexModel_PTR_CppToPython_QHelpIndexModel);

    Shiboken::Conversions::registerConverterName(converter, "QHelpIndexModel");
    Shiboken::Conversions::registerConverterName(converter, "QHelpIndexModel*");
    Shiboken::Conversions::registerConverterName(converter, "QHelpIndexModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHelpIndexModel).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QHelpIndexModel_Type, &Sbk_QHelpIndexModel_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QHelpIndexModel_Type, &::QHelpIndexModel::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QHelpIndexModel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QHelpIndexModel_Type, &::QHelpIndexModel::staticMetaObject, sizeof(::QHelpIndexModel));
}
