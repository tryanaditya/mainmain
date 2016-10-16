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

#include "qnetworkconfiguration_wrapper.h"

// Extra includes
#include <QList>
#include <qnetworkconfiguration.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkConfiguration_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkConfiguration >()))
        return -1;

    ::QNetworkConfiguration* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QNetworkConfiguration", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkConfiguration()
    // 1: QNetworkConfiguration(QNetworkConfiguration)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkConfiguration()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkConfiguration(QNetworkConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkConfiguration_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkConfiguration()
        {

            if (!PyErr_Occurred()) {
                // QNetworkConfiguration()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkConfiguration();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkConfiguration(const QNetworkConfiguration & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
            ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkConfiguration(QNetworkConfiguration)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkConfiguration(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkConfiguration >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkConfiguration_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkConfiguration_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkConfiguration", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkConfigurationFunc_bearerName(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bearerName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->bearerName();
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

static PyObject* Sbk_QNetworkConfigurationFunc_bearerType(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bearerType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration::BearerType cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->bearerType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfigurationFunc_bearerTypeName(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bearerTypeName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->bearerTypeName();
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

static PyObject* Sbk_QNetworkConfigurationFunc_children(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // children()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QNetworkConfiguration > cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->children();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfigurationFunc_identifier(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // identifier()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->identifier();
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

static PyObject* Sbk_QNetworkConfigurationFunc_isRoamingAvailable(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRoamingAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->isRoamingAvailable();
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

static PyObject* Sbk_QNetworkConfigurationFunc_isValid(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->isValid();
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

static PyObject* Sbk_QNetworkConfigurationFunc_name(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->name();
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

static PyObject* Sbk_QNetworkConfigurationFunc_purpose(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // purpose()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration::Purpose cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->purpose();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfigurationFunc_state(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QNetworkConfiguration::StateFlag> cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfigurationFunc_type(PyObject* self)
{
    ::QNetworkConfiguration* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration::Type cppResult = const_cast<const ::QNetworkConfiguration*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfiguration___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkConfiguration& cppSelf = *(((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkConfiguration_methods[] = {
    {"bearerName", (PyCFunction)Sbk_QNetworkConfigurationFunc_bearerName, METH_NOARGS},
    {"bearerType", (PyCFunction)Sbk_QNetworkConfigurationFunc_bearerType, METH_NOARGS},
    {"bearerTypeName", (PyCFunction)Sbk_QNetworkConfigurationFunc_bearerTypeName, METH_NOARGS},
    {"children", (PyCFunction)Sbk_QNetworkConfigurationFunc_children, METH_NOARGS},
    {"identifier", (PyCFunction)Sbk_QNetworkConfigurationFunc_identifier, METH_NOARGS},
    {"isRoamingAvailable", (PyCFunction)Sbk_QNetworkConfigurationFunc_isRoamingAvailable, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QNetworkConfigurationFunc_isValid, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QNetworkConfigurationFunc_name, METH_NOARGS},
    {"purpose", (PyCFunction)Sbk_QNetworkConfigurationFunc_purpose, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QNetworkConfigurationFunc_state, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QNetworkConfigurationFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkConfiguration___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkConfiguration_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkConfiguration& cppSelf = *(((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArg)))) {
                // operator!=(const QNetworkConfiguration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
                ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArg)))) {
                // operator==(const QNetworkConfiguration & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
                ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp))
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
            goto Sbk_QNetworkConfiguration_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkConfiguration_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkConfiguration_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkConfiguration_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkConfiguration_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkConfiguration",
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
    /*tp_traverse*/         Sbk_QNetworkConfiguration_traverse,
    /*tp_clear*/            Sbk_QNetworkConfiguration_clear,
    /*tp_richcompare*/      Sbk_QNetworkConfiguration_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkConfiguration_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkConfiguration_Init,
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

PyObject* SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfiguration::StateFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfiguration::StateFlags)PyLong_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfiguration::StateFlags)PyInt_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfiguration::StateFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfiguration::StateFlags)PyLong_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfiguration::StateFlags)PyInt_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfiguration::StateFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfiguration::StateFlags)PyLong_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfiguration::StateFlags)PyInt_AsLong(self);
    cppArg = (QNetworkConfiguration::StateFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfiguration::StateFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), self, &cppSelf);
    ::QNetworkConfiguration::StateFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QNetworkConfiguration_Type_PythonToCpp_QNetworkConfiguration_Type(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfiguration::Type*)cppOut) = (::QNetworkConfiguration::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkConfiguration_Type_PythonToCpp_QNetworkConfiguration_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX]))
        return QNetworkConfiguration_Type_PythonToCpp_QNetworkConfiguration_Type;
    return 0;
}
static PyObject* QNetworkConfiguration_Type_CppToPython_QNetworkConfiguration_Type(const void* cppIn) {
    int castCppIn = *((::QNetworkConfiguration::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX], castCppIn);

}

static void QNetworkConfiguration_Purpose_PythonToCpp_QNetworkConfiguration_Purpose(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfiguration::Purpose*)cppOut) = (::QNetworkConfiguration::Purpose) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkConfiguration_Purpose_PythonToCpp_QNetworkConfiguration_Purpose_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX]))
        return QNetworkConfiguration_Purpose_PythonToCpp_QNetworkConfiguration_Purpose;
    return 0;
}
static PyObject* QNetworkConfiguration_Purpose_CppToPython_QNetworkConfiguration_Purpose(const void* cppIn) {
    int castCppIn = *((::QNetworkConfiguration::Purpose*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX], castCppIn);

}

static void QNetworkConfiguration_StateFlag_PythonToCpp_QNetworkConfiguration_StateFlag(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfiguration::StateFlag*)cppOut) = (::QNetworkConfiguration::StateFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkConfiguration_StateFlag_PythonToCpp_QNetworkConfiguration_StateFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX]))
        return QNetworkConfiguration_StateFlag_PythonToCpp_QNetworkConfiguration_StateFlag;
    return 0;
}
static PyObject* QNetworkConfiguration_StateFlag_CppToPython_QNetworkConfiguration_StateFlag(const void* cppIn) {
    int castCppIn = *((::QNetworkConfiguration::StateFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX], castCppIn);

}

static void QFlags_QNetworkConfiguration_StateFlag__PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkConfiguration::StateFlag>*)cppOut) = ::QFlags<QNetworkConfiguration::StateFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QNetworkConfiguration_StateFlag__PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]))
        return QFlags_QNetworkConfiguration_StateFlag__PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_;
    return 0;
}
static PyObject* QFlags_QNetworkConfiguration_StateFlag__CppToPython_QFlags_QNetworkConfiguration_StateFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QNetworkConfiguration::StateFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]));

}

static void QNetworkConfiguration_StateFlag_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkConfiguration::StateFlag>*)cppOut) = ::QFlags<QNetworkConfiguration::StateFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QNetworkConfiguration_StateFlag_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX]))
        return QNetworkConfiguration_StateFlag_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QNetworkConfiguration::StateFlag>*)cppOut) = ::QFlags<QNetworkConfiguration::StateFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_;
    return 0;
}
static void QNetworkConfiguration_BearerType_PythonToCpp_QNetworkConfiguration_BearerType(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfiguration::BearerType*)cppOut) = (::QNetworkConfiguration::BearerType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkConfiguration_BearerType_PythonToCpp_QNetworkConfiguration_BearerType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX]))
        return QNetworkConfiguration_BearerType_PythonToCpp_QNetworkConfiguration_BearerType;
    return 0;
}
static PyObject* QNetworkConfiguration_BearerType_CppToPython_QNetworkConfiguration_BearerType(const void* cppIn) {
    int castCppIn = *((::QNetworkConfiguration::BearerType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkConfiguration_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkConfiguration_Type))
        return QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkConfiguration_PTR_CppToPython_QNetworkConfiguration(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkConfiguration*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkConfiguration_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkConfiguration_COPY_CppToPython_QNetworkConfiguration(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkConfiguration_Type, new ::QNetworkConfiguration(*((::QNetworkConfiguration*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfiguration*)cppOut) = *((::QNetworkConfiguration*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkConfiguration_Type))
        return QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_COPY;
    return 0;
}

void init_QNetworkConfiguration(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkConfiguration_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkConfiguration", "QNetworkConfiguration",
        &Sbk_QNetworkConfiguration_Type, &Shiboken::callCppDestructor< ::QNetworkConfiguration >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkConfiguration_Type,
        QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_PTR,
        is_QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_PTR_Convertible,
        QNetworkConfiguration_PTR_CppToPython_QNetworkConfiguration,
        QNetworkConfiguration_COPY_CppToPython_QNetworkConfiguration);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkConfiguration).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_COPY,
        is_QNetworkConfiguration_PythonToCpp_QNetworkConfiguration_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Type'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkConfiguration_Type,
        "Type",
        "PySide.QtNetwork.QNetworkConfiguration.Type",
        "QNetworkConfiguration::Type");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "InternetAccessPoint", (long) QNetworkConfiguration::InternetAccessPoint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "ServiceNetwork", (long) QNetworkConfiguration::ServiceNetwork))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "UserChoice", (long) QNetworkConfiguration::UserChoice))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "Invalid", (long) QNetworkConfiguration::Invalid))
        return ;
    // Register converter for enum 'QNetworkConfiguration::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX],
            QNetworkConfiguration_Type_CppToPython_QNetworkConfiguration_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfiguration_Type_PythonToCpp_QNetworkConfiguration_Type,
            is_QNetworkConfiguration_Type_PythonToCpp_QNetworkConfiguration_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.

    // Initialization of enum 'Purpose'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkConfiguration_Type,
        "Purpose",
        "PySide.QtNetwork.QNetworkConfiguration.Purpose",
        "QNetworkConfiguration::Purpose");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX],
        &Sbk_QNetworkConfiguration_Type, "UnknownPurpose", (long) QNetworkConfiguration::UnknownPurpose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX],
        &Sbk_QNetworkConfiguration_Type, "PublicPurpose", (long) QNetworkConfiguration::PublicPurpose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX],
        &Sbk_QNetworkConfiguration_Type, "PrivatePurpose", (long) QNetworkConfiguration::PrivatePurpose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX],
        &Sbk_QNetworkConfiguration_Type, "ServiceSpecificPurpose", (long) QNetworkConfiguration::ServiceSpecificPurpose))
        return ;
    // Register converter for enum 'QNetworkConfiguration::Purpose'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX],
            QNetworkConfiguration_Purpose_CppToPython_QNetworkConfiguration_Purpose);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfiguration_Purpose_PythonToCpp_QNetworkConfiguration_Purpose,
            is_QNetworkConfiguration_Purpose_PythonToCpp_QNetworkConfiguration_Purpose_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_PURPOSE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration::Purpose");
        Shiboken::Conversions::registerConverterName(converter, "Purpose");
    }
    // End of 'Purpose' enum.

    // Initialization of enum 'StateFlag'.
    SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX] = PySide::QFlags::create("StateFlags", &SbkPySide_QtNetwork_QNetworkConfiguration_StateFlag_as_number);
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkConfiguration_Type,
        "StateFlag",
        "PySide.QtNetwork.QNetworkConfiguration.StateFlag",
        "QNetworkConfiguration::StateFlag",
        SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]);
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX],
        &Sbk_QNetworkConfiguration_Type, "Undefined", (long) QNetworkConfiguration::Undefined))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX],
        &Sbk_QNetworkConfiguration_Type, "Defined", (long) QNetworkConfiguration::Defined))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX],
        &Sbk_QNetworkConfiguration_Type, "Discovered", (long) QNetworkConfiguration::Discovered))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX],
        &Sbk_QNetworkConfiguration_Type, "Active", (long) QNetworkConfiguration::Active))
        return ;
    // Register converter for enum 'QNetworkConfiguration::StateFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX],
            QNetworkConfiguration_StateFlag_CppToPython_QNetworkConfiguration_StateFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfiguration_StateFlag_PythonToCpp_QNetworkConfiguration_StateFlag,
            is_QNetworkConfiguration_StateFlag_PythonToCpp_QNetworkConfiguration_StateFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_STATEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration::StateFlag");
        Shiboken::Conversions::registerConverterName(converter, "StateFlag");
    }
    // Register converter for flag 'QFlags<QNetworkConfiguration::StateFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX],
            QFlags_QNetworkConfiguration_StateFlag__CppToPython_QFlags_QNetworkConfiguration_StateFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfiguration_StateFlag_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_,
            is_QNetworkConfiguration_StateFlag_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QNetworkConfiguration_StateFlag__PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_,
            is_QFlags_QNetworkConfiguration_StateFlag__PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag_,
            is_number_PythonToCpp_QFlags_QNetworkConfiguration_StateFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QNetworkConfiguration::StateFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StateFlag>");
    }
    // End of 'StateFlag' enum/flags.

    // Initialization of enum 'BearerType'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkConfiguration_Type,
        "BearerType",
        "PySide.QtNetwork.QNetworkConfiguration.BearerType",
        "QNetworkConfiguration::BearerType");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerUnknown", (long) QNetworkConfiguration::BearerUnknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerEthernet", (long) QNetworkConfiguration::BearerEthernet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerWLAN", (long) QNetworkConfiguration::BearerWLAN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "Bearer2G", (long) QNetworkConfiguration::Bearer2G))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerCDMA2000", (long) QNetworkConfiguration::BearerCDMA2000))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerWCDMA", (long) QNetworkConfiguration::BearerWCDMA))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerHSPA", (long) QNetworkConfiguration::BearerHSPA))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerBluetooth", (long) QNetworkConfiguration::BearerBluetooth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
        &Sbk_QNetworkConfiguration_Type, "BearerWiMAX", (long) QNetworkConfiguration::BearerWiMAX))
        return ;
    // Register converter for enum 'QNetworkConfiguration::BearerType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX],
            QNetworkConfiguration_BearerType_CppToPython_QNetworkConfiguration_BearerType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfiguration_BearerType_PythonToCpp_QNetworkConfiguration_BearerType,
            is_QNetworkConfiguration_BearerType_PythonToCpp_QNetworkConfiguration_BearerType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_BEARERTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkConfiguration::BearerType");
        Shiboken::Conversions::registerConverterName(converter, "BearerType");
    }
    // End of 'BearerType' enum.


    qRegisterMetaType< ::QNetworkConfiguration >("QNetworkConfiguration");
    qRegisterMetaType< ::QNetworkConfiguration::Type >("QNetworkConfiguration::Type");
    qRegisterMetaType< ::QNetworkConfiguration::Purpose >("QNetworkConfiguration::Purpose");
    qRegisterMetaType< ::QNetworkConfiguration::StateFlag >("QNetworkConfiguration::StateFlag");
    qRegisterMetaType< ::QNetworkConfiguration::StateFlags >("QNetworkConfiguration::StateFlags");
    qRegisterMetaType< ::QNetworkConfiguration::BearerType >("QNetworkConfiguration::BearerType");
}
