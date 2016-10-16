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

#include "qnetworkinterface_wrapper.h"

// Extra includes
#include <QList>
#include <qhostaddress.h>
#include <qnetworkinterface.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkInterface >()))
        return -1;

    ::QNetworkInterface* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QNetworkInterface", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkInterface()
    // 1: QNetworkInterface(QNetworkInterface)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkInterface()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkInterface(QNetworkInterface)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkInterface_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkInterface()
        {

            if (!PyErr_Occurred()) {
                // QNetworkInterface()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkInterface();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkInterface(const QNetworkInterface & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkInterface cppArg0_local = ::QNetworkInterface();
            ::QNetworkInterface* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkInterface(QNetworkInterface)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkInterface(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkInterface_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkInterface_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkInterface", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkInterface", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkInterfaceFunc_addressEntries(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // addressEntries()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QNetworkAddressEntry > cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->addressEntries();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKADDRESSENTRY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkInterfaceFunc_allAddresses(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allAddresses()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QHostAddress > cppResult = ::QNetworkInterface::allAddresses();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QHOSTADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkInterfaceFunc_allInterfaces(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allInterfaces()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QNetworkInterface > cppResult = ::QNetworkInterface::allInterfaces();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKINTERFACE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkInterfaceFunc_flags(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QNetworkInterface::InterfaceFlag> cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->flags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkInterfaceFunc_hardwareAddress(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hardwareAddress()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->hardwareAddress();
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

static PyObject* Sbk_QNetworkInterfaceFunc_humanReadableName(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // humanReadableName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->humanReadableName();
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

static PyObject* Sbk_QNetworkInterfaceFunc_index(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // index()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->index();
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

static PyObject* Sbk_QNetworkInterfaceFunc_interfaceFromIndex(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: interfaceFromIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // interfaceFromIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkInterfaceFunc_interfaceFromIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // interfaceFromIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkInterface cppResult = ::QNetworkInterface::interfaceFromIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkInterfaceFunc_interfaceFromIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkInterface.interfaceFromIndex", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkInterfaceFunc_interfaceFromName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: interfaceFromName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // interfaceFromName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkInterfaceFunc_interfaceFromName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // interfaceFromName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkInterface cppResult = ::QNetworkInterface::interfaceFromName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkInterfaceFunc_interfaceFromName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkInterface.interfaceFromName", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkInterfaceFunc_isValid(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->isValid();
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

static PyObject* Sbk_QNetworkInterfaceFunc_name(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QNetworkInterface*>(cppSelf)->name();
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

static PyObject* Sbk_QNetworkInterface___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkInterface& cppSelf = *(((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkInterface_methods[] = {
    {"addressEntries", (PyCFunction)Sbk_QNetworkInterfaceFunc_addressEntries, METH_NOARGS},
    {"allAddresses", (PyCFunction)Sbk_QNetworkInterfaceFunc_allAddresses, METH_NOARGS|METH_STATIC},
    {"allInterfaces", (PyCFunction)Sbk_QNetworkInterfaceFunc_allInterfaces, METH_NOARGS|METH_STATIC},
    {"flags", (PyCFunction)Sbk_QNetworkInterfaceFunc_flags, METH_NOARGS},
    {"hardwareAddress", (PyCFunction)Sbk_QNetworkInterfaceFunc_hardwareAddress, METH_NOARGS},
    {"humanReadableName", (PyCFunction)Sbk_QNetworkInterfaceFunc_humanReadableName, METH_NOARGS},
    {"index", (PyCFunction)Sbk_QNetworkInterfaceFunc_index, METH_NOARGS},
    {"interfaceFromIndex", (PyCFunction)Sbk_QNetworkInterfaceFunc_interfaceFromIndex, METH_O|METH_STATIC},
    {"interfaceFromName", (PyCFunction)Sbk_QNetworkInterfaceFunc_interfaceFromName, METH_O|METH_STATIC},
    {"isValid", (PyCFunction)Sbk_QNetworkInterfaceFunc_isValid, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QNetworkInterfaceFunc_name, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QNetworkInterface___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QNetworkInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QNetworkInterface__repr__(PyObject* self)
{
    ::QNetworkInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkInterface",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QNetworkInterface__repr__,
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
    /*tp_traverse*/         Sbk_QNetworkInterface_traverse,
    /*tp_clear*/            Sbk_QNetworkInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkInterface_Init,
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

PyObject* SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkInterface::InterfaceFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyLong_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyInt_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkInterface::InterfaceFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyLong_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyInt_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkInterface::InterfaceFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyLong_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkInterface::InterfaceFlags)PyInt_AsLong(self);
    cppArg = (QNetworkInterface::InterfaceFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkInterface::InterfaceFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), self, &cppSelf);
    ::QNetworkInterface::InterfaceFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag_long,
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
static void QNetworkInterface_InterfaceFlag_PythonToCpp_QNetworkInterface_InterfaceFlag(PyObject* pyIn, void* cppOut) {
    *((::QNetworkInterface::InterfaceFlag*)cppOut) = (::QNetworkInterface::InterfaceFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkInterface_InterfaceFlag_PythonToCpp_QNetworkInterface_InterfaceFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX]))
        return QNetworkInterface_InterfaceFlag_PythonToCpp_QNetworkInterface_InterfaceFlag;
    return 0;
}
static PyObject* QNetworkInterface_InterfaceFlag_CppToPython_QNetworkInterface_InterfaceFlag(const void* cppIn) {
    int castCppIn = *((::QNetworkInterface::InterfaceFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX], castCppIn);

}

static void QFlags_QNetworkInterface_InterfaceFlag__PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkInterface::InterfaceFlag>*)cppOut) = ::QFlags<QNetworkInterface::InterfaceFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QNetworkInterface_InterfaceFlag__PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]))
        return QFlags_QNetworkInterface_InterfaceFlag__PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_;
    return 0;
}
static PyObject* QFlags_QNetworkInterface_InterfaceFlag__CppToPython_QFlags_QNetworkInterface_InterfaceFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QNetworkInterface::InterfaceFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]));

}

static void QNetworkInterface_InterfaceFlag_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkInterface::InterfaceFlag>*)cppOut) = ::QFlags<QNetworkInterface::InterfaceFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QNetworkInterface_InterfaceFlag_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX]))
        return QNetworkInterface_InterfaceFlag_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QNetworkInterface::InterfaceFlag>*)cppOut) = ::QFlags<QNetworkInterface::InterfaceFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkInterface_PythonToCpp_QNetworkInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkInterface_PythonToCpp_QNetworkInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkInterface_Type))
        return QNetworkInterface_PythonToCpp_QNetworkInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkInterface_PTR_CppToPython_QNetworkInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkInterface_COPY_CppToPython_QNetworkInterface(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkInterface_Type, new ::QNetworkInterface(*((::QNetworkInterface*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkInterface_PythonToCpp_QNetworkInterface_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkInterface*)cppOut) = *((::QNetworkInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkInterface_PythonToCpp_QNetworkInterface_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkInterface_Type))
        return QNetworkInterface_PythonToCpp_QNetworkInterface_COPY;
    return 0;
}

void init_QNetworkInterface(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkInterface", "QNetworkInterface",
        &Sbk_QNetworkInterface_Type, &Shiboken::callCppDestructor< ::QNetworkInterface >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkInterface_Type,
        QNetworkInterface_PythonToCpp_QNetworkInterface_PTR,
        is_QNetworkInterface_PythonToCpp_QNetworkInterface_PTR_Convertible,
        QNetworkInterface_PTR_CppToPython_QNetworkInterface,
        QNetworkInterface_COPY_CppToPython_QNetworkInterface);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkInterface");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkInterface*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkInterface).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkInterface_PythonToCpp_QNetworkInterface_COPY,
        is_QNetworkInterface_PythonToCpp_QNetworkInterface_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'InterfaceFlag'.
    SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX] = PySide::QFlags::create("InterfaceFlags", &SbkPySide_QtNetwork_QNetworkInterface_InterfaceFlag_as_number);
    SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkInterface_Type,
        "InterfaceFlag",
        "PySide.QtNetwork.QNetworkInterface.InterfaceFlag",
        "QNetworkInterface::InterfaceFlag",
        SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX]);
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "IsUp", (long) QNetworkInterface::IsUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "IsRunning", (long) QNetworkInterface::IsRunning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "CanBroadcast", (long) QNetworkInterface::CanBroadcast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "IsLoopBack", (long) QNetworkInterface::IsLoopBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "IsPointToPoint", (long) QNetworkInterface::IsPointToPoint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
        &Sbk_QNetworkInterface_Type, "CanMulticast", (long) QNetworkInterface::CanMulticast))
        return ;
    // Register converter for enum 'QNetworkInterface::InterfaceFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX],
            QNetworkInterface_InterfaceFlag_CppToPython_QNetworkInterface_InterfaceFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkInterface_InterfaceFlag_PythonToCpp_QNetworkInterface_InterfaceFlag,
            is_QNetworkInterface_InterfaceFlag_PythonToCpp_QNetworkInterface_InterfaceFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKINTERFACE_INTERFACEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkInterface::InterfaceFlag");
        Shiboken::Conversions::registerConverterName(converter, "InterfaceFlag");
    }
    // Register converter for flag 'QFlags<QNetworkInterface::InterfaceFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX],
            QFlags_QNetworkInterface_InterfaceFlag__CppToPython_QFlags_QNetworkInterface_InterfaceFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkInterface_InterfaceFlag_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_,
            is_QNetworkInterface_InterfaceFlag_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QNetworkInterface_InterfaceFlag__PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_,
            is_QFlags_QNetworkInterface_InterfaceFlag__PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag_,
            is_number_PythonToCpp_QFlags_QNetworkInterface_InterfaceFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKINTERFACE_INTERFACEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QNetworkInterface::InterfaceFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<InterfaceFlag>");
    }
    // End of 'InterfaceFlag' enum/flags.


    qRegisterMetaType< ::QNetworkInterface >("QNetworkInterface");
    qRegisterMetaType< ::QNetworkInterface::InterfaceFlag >("QNetworkInterface::InterfaceFlag");
    qRegisterMetaType< ::QNetworkInterface::InterfaceFlags >("QNetworkInterface::InterfaceFlags");
}
