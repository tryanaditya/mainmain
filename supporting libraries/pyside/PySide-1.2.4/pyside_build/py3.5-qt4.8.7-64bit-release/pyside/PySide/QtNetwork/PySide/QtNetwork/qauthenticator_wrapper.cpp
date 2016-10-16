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
#include "pyside_qtnetwork_python.h"

#include "qauthenticator_wrapper.h"

// Extra includes
#include <pysideconversions.h>
#include <qauthenticator.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAuthenticator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAuthenticator >()))
        return -1;

    ::QAuthenticator* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAuthenticator", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAuthenticator()
    // 1: QAuthenticator(QAuthenticator)
    if (numArgs == 0) {
        overloadId = 0; // QAuthenticator()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // QAuthenticator(QAuthenticator)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAuthenticator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QAuthenticator()
        {

            if (!PyErr_Occurred()) {
                // QAuthenticator()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAuthenticator();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QAuthenticator(const QAuthenticator & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAuthenticator cppArg0_local = ::QAuthenticator();
            ::QAuthenticator* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QAuthenticator(QAuthenticator)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QAuthenticator(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAuthenticator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAuthenticator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QAuthenticator_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QAuthenticator", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAuthenticator", overloads);
        return -1;
}

static PyObject* Sbk_QAuthenticatorFunc_isNull(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->isNull();
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

static PyObject* Sbk_QAuthenticatorFunc_option(PyObject* self, PyObject* pyArg)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: option(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // option(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAuthenticatorFunc_option_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // option(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->option(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAuthenticatorFunc_option_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAuthenticator.option", overloads);
        return 0;
}

static PyObject* Sbk_QAuthenticatorFunc_options(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // options()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHash<QString, QVariant > cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->options();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QHASH_QSTRING_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAuthenticatorFunc_password(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // password()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->password();
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

static PyObject* Sbk_QAuthenticatorFunc_realm(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // realm()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->realm();
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

static PyObject* Sbk_QAuthenticatorFunc_setOption(PyObject* self, PyObject* args)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setOption", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setOption(QString,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setOption(QString,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAuthenticatorFunc_setOption_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setOption(QString,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOption(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAuthenticatorFunc_setOption_TypeError:
        const char* overloads[] = {"unicode, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAuthenticator.setOption", overloads);
        return 0;
}

static PyObject* Sbk_QAuthenticatorFunc_setPassword(PyObject* self, PyObject* pyArg)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPassword(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPassword(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAuthenticatorFunc_setPassword_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPassword(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPassword(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAuthenticatorFunc_setPassword_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAuthenticator.setPassword", overloads);
        return 0;
}

static PyObject* Sbk_QAuthenticatorFunc_setUser(PyObject* self, PyObject* pyArg)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUser(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setUser(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAuthenticatorFunc_setUser_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUser(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUser(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAuthenticatorFunc_setUser_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAuthenticator.setUser", overloads);
        return 0;
}

static PyObject* Sbk_QAuthenticatorFunc_user(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // user()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAuthenticator*>(cppSelf)->user();
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

static PyObject* Sbk_QAuthenticator___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAuthenticator& cppSelf = *(((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAuthenticator_methods[] = {
    {"isNull", (PyCFunction)Sbk_QAuthenticatorFunc_isNull, METH_NOARGS},
    {"option", (PyCFunction)Sbk_QAuthenticatorFunc_option, METH_O},
    {"options", (PyCFunction)Sbk_QAuthenticatorFunc_options, METH_NOARGS},
    {"password", (PyCFunction)Sbk_QAuthenticatorFunc_password, METH_NOARGS},
    {"realm", (PyCFunction)Sbk_QAuthenticatorFunc_realm, METH_NOARGS},
    {"setOption", (PyCFunction)Sbk_QAuthenticatorFunc_setOption, METH_VARARGS},
    {"setPassword", (PyCFunction)Sbk_QAuthenticatorFunc_setPassword, METH_O},
    {"setUser", (PyCFunction)Sbk_QAuthenticatorFunc_setUser, METH_O},
    {"user", (PyCFunction)Sbk_QAuthenticatorFunc_user, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QAuthenticator___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QAuthenticator___nb_bool(PyObject* self)
{
    ::QAuthenticator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QAuthenticator_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QAuthenticator& cppSelf = *(((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (pyArg)))) {
                // operator!=(const QAuthenticator & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QAuthenticator cppArg0_local = ::QAuthenticator();
                ::QAuthenticator* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (pyArg)))) {
                // operator==(const QAuthenticator & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QAuthenticator cppArg0_local = ::QAuthenticator();
                ::QAuthenticator* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], pythonToCpp))
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
            goto Sbk_QAuthenticator_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QAuthenticator_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QAuthenticator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAuthenticator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QAuthenticator_TypeAsNumber;

static SbkObjectType Sbk_QAuthenticator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QAuthenticator",
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
    /*tp_traverse*/         Sbk_QAuthenticator_traverse,
    /*tp_clear*/            Sbk_QAuthenticator_clear,
    /*tp_richcompare*/      Sbk_QAuthenticator_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAuthenticator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAuthenticator_Init,
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
static void QAuthenticator_PythonToCpp_QAuthenticator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAuthenticator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAuthenticator_PythonToCpp_QAuthenticator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAuthenticator_Type))
        return QAuthenticator_PythonToCpp_QAuthenticator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAuthenticator_PTR_CppToPython_QAuthenticator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAuthenticator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAuthenticator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QAuthenticator_COPY_CppToPython_QAuthenticator(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QAuthenticator_Type, new ::QAuthenticator(*((::QAuthenticator*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QAuthenticator_PythonToCpp_QAuthenticator_COPY(PyObject* pyIn, void* cppOut) {
    *((::QAuthenticator*)cppOut) = *((::QAuthenticator*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QAuthenticator_PythonToCpp_QAuthenticator_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAuthenticator_Type))
        return QAuthenticator_PythonToCpp_QAuthenticator_COPY;
    return 0;
}

void init_QAuthenticator(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QAuthenticator_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QAuthenticator_TypeAsNumber) = Sbk_QAuthenticator___nb_bool;
    Sbk_QAuthenticator_Type.super.ht_type.tp_as_number = &Sbk_QAuthenticator_TypeAsNumber;

    SbkPySide_QtNetworkTypes[SBK_QAUTHENTICATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAuthenticator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAuthenticator", "QAuthenticator",
        &Sbk_QAuthenticator_Type, &Shiboken::callCppDestructor< ::QAuthenticator >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAuthenticator_Type,
        QAuthenticator_PythonToCpp_QAuthenticator_PTR,
        is_QAuthenticator_PythonToCpp_QAuthenticator_PTR_Convertible,
        QAuthenticator_PTR_CppToPython_QAuthenticator,
        QAuthenticator_COPY_CppToPython_QAuthenticator);

    Shiboken::Conversions::registerConverterName(converter, "QAuthenticator");
    Shiboken::Conversions::registerConverterName(converter, "QAuthenticator*");
    Shiboken::Conversions::registerConverterName(converter, "QAuthenticator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAuthenticator).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QAuthenticator_PythonToCpp_QAuthenticator_COPY,
        is_QAuthenticator_PythonToCpp_QAuthenticator_COPY_Convertible);


    qRegisterMetaType< ::QAuthenticator >("QAuthenticator");
}
