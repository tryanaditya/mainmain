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

#include "qnetworkaddressentry_wrapper.h"

// Extra includes
#include <qhostaddress.h>
#include <qnetworkinterface.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkAddressEntry_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkAddressEntry >()))
        return -1;

    ::QNetworkAddressEntry* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QNetworkAddressEntry", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkAddressEntry()
    // 1: QNetworkAddressEntry(QNetworkAddressEntry)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkAddressEntry()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QNetworkAddressEntry(QNetworkAddressEntry)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAddressEntry_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QNetworkAddressEntry()
        {

            if (!PyErr_Occurred()) {
                // QNetworkAddressEntry()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkAddressEntry();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QNetworkAddressEntry(const QNetworkAddressEntry & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QNetworkAddressEntry cppArg0_local = ::QNetworkAddressEntry();
            ::QNetworkAddressEntry* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QNetworkAddressEntry(QNetworkAddressEntry)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QNetworkAddressEntry(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkAddressEntry >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkAddressEntry_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QNetworkAddressEntry_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtNetwork.QNetworkAddressEntry", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAddressEntry", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_broadcast(PyObject* self)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // broadcast()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostAddress cppResult = const_cast<const ::QNetworkAddressEntry*>(cppSelf)->broadcast();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_ip(PyObject* self)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostAddress cppResult = const_cast<const ::QNetworkAddressEntry*>(cppSelf)->ip();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_netmask(PyObject* self)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // netmask()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostAddress cppResult = const_cast<const ::QNetworkAddressEntry*>(cppSelf)->netmask();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_prefixLength(PyObject* self)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefixLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QNetworkAddressEntry*>(cppSelf)->prefixLength();
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

static PyObject* Sbk_QNetworkAddressEntryFunc_setBroadcast(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBroadcast(QHostAddress)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setBroadcast(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAddressEntryFunc_setBroadcast_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QHostAddress cppArg0_local = ::QHostAddress();
        ::QHostAddress* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBroadcast(QHostAddress)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBroadcast(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAddressEntryFunc_setBroadcast_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAddressEntry.setBroadcast", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_setIp(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIp(QHostAddress)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setIp(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAddressEntryFunc_setIp_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QHostAddress cppArg0_local = ::QHostAddress();
        ::QHostAddress* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setIp(QHostAddress)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIp(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAddressEntryFunc_setIp_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAddressEntry.setIp", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_setNetmask(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNetmask(QHostAddress)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setNetmask(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAddressEntryFunc_setNetmask_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QHostAddress cppArg0_local = ::QHostAddress();
        ::QHostAddress* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setNetmask(QHostAddress)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNetmask(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAddressEntryFunc_setNetmask_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAddressEntry.setNetmask", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAddressEntryFunc_setPrefixLength(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAddressEntry* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrefixLength(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPrefixLength(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAddressEntryFunc_setPrefixLength_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrefixLength(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrefixLength(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAddressEntryFunc_setPrefixLength_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAddressEntry.setPrefixLength", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAddressEntry___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkAddressEntry& cppSelf = *(((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QNetworkAddressEntry_methods[] = {
    {"broadcast", (PyCFunction)Sbk_QNetworkAddressEntryFunc_broadcast, METH_NOARGS},
    {"ip", (PyCFunction)Sbk_QNetworkAddressEntryFunc_ip, METH_NOARGS},
    {"netmask", (PyCFunction)Sbk_QNetworkAddressEntryFunc_netmask, METH_NOARGS},
    {"prefixLength", (PyCFunction)Sbk_QNetworkAddressEntryFunc_prefixLength, METH_NOARGS},
    {"setBroadcast", (PyCFunction)Sbk_QNetworkAddressEntryFunc_setBroadcast, METH_O},
    {"setIp", (PyCFunction)Sbk_QNetworkAddressEntryFunc_setIp, METH_O},
    {"setNetmask", (PyCFunction)Sbk_QNetworkAddressEntryFunc_setNetmask, METH_O},
    {"setPrefixLength", (PyCFunction)Sbk_QNetworkAddressEntryFunc_setPrefixLength, METH_O},

    {"__copy__", (PyCFunction)Sbk_QNetworkAddressEntry___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QNetworkAddressEntry_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QNetworkAddressEntry& cppSelf = *(((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (pyArg)))) {
                // operator!=(const QNetworkAddressEntry & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkAddressEntry cppArg0_local = ::QNetworkAddressEntry();
                ::QNetworkAddressEntry* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (pyArg)))) {
                // operator==(const QNetworkAddressEntry & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QNetworkAddressEntry cppArg0_local = ::QNetworkAddressEntry();
                ::QNetworkAddressEntry* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], pythonToCpp))
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
            goto Sbk_QNetworkAddressEntry_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QNetworkAddressEntry_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QNetworkAddressEntry_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkAddressEntry_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkAddressEntry_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkAddressEntry",
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
    /*tp_traverse*/         Sbk_QNetworkAddressEntry_traverse,
    /*tp_clear*/            Sbk_QNetworkAddressEntry_clear,
    /*tp_richcompare*/      Sbk_QNetworkAddressEntry_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkAddressEntry_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkAddressEntry_Init,
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
static void QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkAddressEntry_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkAddressEntry_Type))
        return QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkAddressEntry_PTR_CppToPython_QNetworkAddressEntry(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QNetworkAddressEntry*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QNetworkAddressEntry_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QNetworkAddressEntry_COPY_CppToPython_QNetworkAddressEntry(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QNetworkAddressEntry_Type, new ::QNetworkAddressEntry(*((::QNetworkAddressEntry*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_COPY(PyObject* pyIn, void* cppOut) {
    *((::QNetworkAddressEntry*)cppOut) = *((::QNetworkAddressEntry*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkAddressEntry_Type))
        return QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_COPY;
    return 0;
}

void init_QNetworkAddressEntry(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKADDRESSENTRY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkAddressEntry_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkAddressEntry", "QNetworkAddressEntry",
        &Sbk_QNetworkAddressEntry_Type, &Shiboken::callCppDestructor< ::QNetworkAddressEntry >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkAddressEntry_Type,
        QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_PTR,
        is_QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_PTR_Convertible,
        QNetworkAddressEntry_PTR_CppToPython_QNetworkAddressEntry,
        QNetworkAddressEntry_COPY_CppToPython_QNetworkAddressEntry);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkAddressEntry");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkAddressEntry*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkAddressEntry&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkAddressEntry).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_COPY,
        is_QNetworkAddressEntry_PythonToCpp_QNetworkAddressEntry_COPY_Convertible);


    qRegisterMetaType< ::QNetworkAddressEntry >("QNetworkAddressEntry");
}
