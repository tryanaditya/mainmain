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
#include "pyside_qtwebkit_python.h"

#include "qwebsecurityorigin_wrapper.h"

// Extra includes
#include <QList>
#include <qwebdatabase.h>
#include <qwebsecurityorigin.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebSecurityOrigin_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebSecurityOrigin >()))
        return -1;

    ::QWebSecurityOrigin* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWebSecurityOrigin", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QWebSecurityOrigin(QWebSecurityOrigin)
    if (numArgs == 1
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (pyArgs[0]))))) {
        overloadId = 0; // QWebSecurityOrigin(QWebSecurityOrigin)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSecurityOrigin_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWebSecurityOrigin* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QWebSecurityOrigin(QWebSecurityOrigin)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QWebSecurityOrigin(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebSecurityOrigin >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebSecurityOrigin_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebSecurityOrigin_Init_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebSecurityOrigin", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebSecurityOrigin", overloads);
        return -1;
}

static PyObject* Sbk_QWebSecurityOriginFunc_addLocalScheme(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addLocalScheme(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addLocalScheme(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSecurityOriginFunc_addLocalScheme_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addLocalScheme(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSecurityOrigin::addLocalScheme(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSecurityOriginFunc_addLocalScheme_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSecurityOrigin.addLocalScheme", overloads);
        return 0;
}

static PyObject* Sbk_QWebSecurityOriginFunc_allOrigins(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allOrigins()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWebSecurityOrigin > cppResult = ::QWebSecurityOrigin::allOrigins();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBSECURITYORIGIN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSecurityOriginFunc_databaseQuota(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // databaseQuota()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->databaseQuota();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSecurityOriginFunc_databaseUsage(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // databaseUsage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->databaseUsage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSecurityOriginFunc_databases(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // databases()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWebDatabase > cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->databases();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBDATABASE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSecurityOriginFunc_host(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // host()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->host();
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

static PyObject* Sbk_QWebSecurityOriginFunc_localSchemes(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localSchemes()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QWebSecurityOrigin::localSchemes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebSecurityOriginFunc_port(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // port()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->port();
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

static PyObject* Sbk_QWebSecurityOriginFunc_removeLocalScheme(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeLocalScheme(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeLocalScheme(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSecurityOriginFunc_removeLocalScheme_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeLocalScheme(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QWebSecurityOrigin::removeLocalScheme(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSecurityOriginFunc_removeLocalScheme_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSecurityOrigin.removeLocalScheme", overloads);
        return 0;
}

static PyObject* Sbk_QWebSecurityOriginFunc_scheme(PyObject* self)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scheme()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QWebSecurityOrigin*>(cppSelf)->scheme();
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

static PyObject* Sbk_QWebSecurityOriginFunc_setApplicationCacheQuota(PyObject* self, PyObject* pyArg)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setApplicationCacheQuota(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setApplicationCacheQuota(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSecurityOriginFunc_setApplicationCacheQuota_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setApplicationCacheQuota(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setApplicationCacheQuota(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSecurityOriginFunc_setApplicationCacheQuota_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSecurityOrigin.setApplicationCacheQuota", overloads);
        return 0;
}

static PyObject* Sbk_QWebSecurityOriginFunc_setDatabaseQuota(PyObject* self, PyObject* pyArg)
{
    ::QWebSecurityOrigin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDatabaseQuota(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setDatabaseQuota(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebSecurityOriginFunc_setDatabaseQuota_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDatabaseQuota(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDatabaseQuota(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebSecurityOriginFunc_setDatabaseQuota_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebSecurityOrigin.setDatabaseQuota", overloads);
        return 0;
}

static PyObject* Sbk_QWebSecurityOrigin___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebSecurityOrigin& cppSelf = *(((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebSecurityOrigin_methods[] = {
    {"addLocalScheme", (PyCFunction)Sbk_QWebSecurityOriginFunc_addLocalScheme, METH_O|METH_STATIC},
    {"allOrigins", (PyCFunction)Sbk_QWebSecurityOriginFunc_allOrigins, METH_NOARGS|METH_STATIC},
    {"databaseQuota", (PyCFunction)Sbk_QWebSecurityOriginFunc_databaseQuota, METH_NOARGS},
    {"databaseUsage", (PyCFunction)Sbk_QWebSecurityOriginFunc_databaseUsage, METH_NOARGS},
    {"databases", (PyCFunction)Sbk_QWebSecurityOriginFunc_databases, METH_NOARGS},
    {"host", (PyCFunction)Sbk_QWebSecurityOriginFunc_host, METH_NOARGS},
    {"localSchemes", (PyCFunction)Sbk_QWebSecurityOriginFunc_localSchemes, METH_NOARGS|METH_STATIC},
    {"port", (PyCFunction)Sbk_QWebSecurityOriginFunc_port, METH_NOARGS},
    {"removeLocalScheme", (PyCFunction)Sbk_QWebSecurityOriginFunc_removeLocalScheme, METH_O|METH_STATIC},
    {"scheme", (PyCFunction)Sbk_QWebSecurityOriginFunc_scheme, METH_NOARGS},
    {"setApplicationCacheQuota", (PyCFunction)Sbk_QWebSecurityOriginFunc_setApplicationCacheQuota, METH_O},
    {"setDatabaseQuota", (PyCFunction)Sbk_QWebSecurityOriginFunc_setDatabaseQuota, METH_O},

    {"__copy__", (PyCFunction)Sbk_QWebSecurityOrigin___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QWebSecurityOrigin_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebSecurityOrigin_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QWebSecurityOrigin_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebSecurityOrigin",
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
    /*tp_traverse*/         Sbk_QWebSecurityOrigin_traverse,
    /*tp_clear*/            Sbk_QWebSecurityOrigin_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebSecurityOrigin_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebSecurityOrigin_Init,
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
static void QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebSecurityOrigin_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebSecurityOrigin_Type))
        return QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebSecurityOrigin_PTR_CppToPython_QWebSecurityOrigin(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebSecurityOrigin*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebSecurityOrigin_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QWebSecurityOrigin_COPY_CppToPython_QWebSecurityOrigin(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebSecurityOrigin_Type, new ::QWebSecurityOrigin(*((::QWebSecurityOrigin*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebSecurityOrigin*)cppOut) = *((::QWebSecurityOrigin*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebSecurityOrigin_Type))
        return QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_COPY;
    return 0;
}

void init_QWebSecurityOrigin(PyObject* module)
{
    SbkPySide_QtWebKitTypes[SBK_QWEBSECURITYORIGIN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebSecurityOrigin_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebSecurityOrigin", "QWebSecurityOrigin",
        &Sbk_QWebSecurityOrigin_Type, &Shiboken::callCppDestructor< ::QWebSecurityOrigin >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebSecurityOrigin_Type,
        QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_PTR,
        is_QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_PTR_Convertible,
        QWebSecurityOrigin_PTR_CppToPython_QWebSecurityOrigin,
        QWebSecurityOrigin_COPY_CppToPython_QWebSecurityOrigin);

    Shiboken::Conversions::registerConverterName(converter, "QWebSecurityOrigin");
    Shiboken::Conversions::registerConverterName(converter, "QWebSecurityOrigin*");
    Shiboken::Conversions::registerConverterName(converter, "QWebSecurityOrigin&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebSecurityOrigin).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_COPY,
        is_QWebSecurityOrigin_PythonToCpp_QWebSecurityOrigin_COPY_Convertible);


}
