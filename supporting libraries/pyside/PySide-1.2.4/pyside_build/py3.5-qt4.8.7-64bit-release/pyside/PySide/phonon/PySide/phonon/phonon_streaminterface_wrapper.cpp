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
#include "pyside_phonon_python.h"

#include "phonon_streaminterface_wrapper.h"

// Extra includes
#include <mediasource.h>
#include <qbytearray.h>

using namespace Phonon;

// Native ---------------------------------------------------------

StreamInterfaceWrapper::StreamInterfaceWrapper() : Phonon::StreamInterface() {
    // ... middle
}

void StreamInterfaceWrapper::endOfData()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endOfData"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.endOfData()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void StreamInterfaceWrapper::setStreamSeekable(bool s)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setStreamSeekable"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.setStreamSeekable()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &s)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void StreamInterfaceWrapper::setStreamSize(qint64 newSize)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setStreamSize"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.setStreamSize()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        newSize
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void StreamInterfaceWrapper::writeData(const QByteArray & data)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.writeData()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &data)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

StreamInterfaceWrapper::~StreamInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_StreamInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::StreamInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::StreamInterface >()))
        return -1;

    ::StreamInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // StreamInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::StreamInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::StreamInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_connectToSource(PyObject* self, PyObject* pyArg)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: connectToSource(Phonon::MediaSource)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // connectToSource(Phonon::MediaSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_StreamInterfaceFunc_connectToSource_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::MediaSource cppArg0_local = ::Phonon::MediaSource();
        ::Phonon::MediaSource* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // connectToSource(Phonon::MediaSource)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->connectToSource(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_StreamInterfaceFunc_connectToSource_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.StreamInterface.connectToSource", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_endOfData(PyObject* self)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endOfData()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.endOfData()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endOfData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_enoughData(PyObject* self)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enoughData()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->enoughData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_needData(PyObject* self)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // needData()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->needData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_reset(PyObject* self)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));

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

static PyObject* Sbk_Phonon_StreamInterfaceFunc_seekStream(PyObject* self, PyObject* pyArg)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seekStream(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seekStream(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_StreamInterfaceFunc_seekStream_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seekStream(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->seekStream(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_StreamInterfaceFunc_seekStream_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.StreamInterface.seekStream", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_setStreamSeekable(PyObject* self, PyObject* pyArg)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStreamSeekable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setStreamSeekable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_StreamInterfaceFunc_setStreamSeekable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStreamSeekable(bool)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.setStreamSeekable()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStreamSeekable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_StreamInterfaceFunc_setStreamSeekable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.StreamInterface.setStreamSeekable", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_setStreamSize(PyObject* self, PyObject* pyArg)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStreamSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setStreamSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_StreamInterfaceFunc_setStreamSize_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStreamSize(qint64)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.setStreamSize()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStreamSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_StreamInterfaceFunc_setStreamSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.StreamInterface.setStreamSize", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_StreamInterfaceFunc_writeData(PyObject* self, PyObject* pyArg)
{
    ::Phonon::StreamInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::StreamInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeData(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // writeData(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_StreamInterfaceFunc_writeData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // writeData(QByteArray)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'StreamInterface.writeData()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->writeData(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_StreamInterfaceFunc_writeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.StreamInterface.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_Phonon_StreamInterface_methods[] = {
    {"connectToSource", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_connectToSource, METH_O},
    {"endOfData", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_endOfData, METH_NOARGS},
    {"enoughData", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_enoughData, METH_NOARGS},
    {"needData", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_needData, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_reset, METH_NOARGS},
    {"seekStream", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_seekStream, METH_O},
    {"setStreamSeekable", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_setStreamSeekable, METH_O},
    {"setStreamSize", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_setStreamSize, METH_O},
    {"writeData", (PyCFunction)Sbk_Phonon_StreamInterfaceFunc_writeData, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_StreamInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_StreamInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_StreamInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.StreamInterface",
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
    /*tp_traverse*/         Sbk_Phonon_StreamInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_StreamInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_StreamInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_StreamInterface_Init,
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
static void StreamInterface_PythonToCpp_StreamInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_StreamInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_StreamInterface_PythonToCpp_StreamInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_StreamInterface_Type))
        return StreamInterface_PythonToCpp_StreamInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StreamInterface_PTR_CppToPython_StreamInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::StreamInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_StreamInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_StreamInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_STREAMINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_StreamInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "StreamInterface", "Phonon::StreamInterface*",
        &Sbk_Phonon_StreamInterface_Type, &Shiboken::callCppDestructor< ::Phonon::StreamInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_StreamInterface_Type,
        StreamInterface_PythonToCpp_StreamInterface_PTR,
        is_StreamInterface_PythonToCpp_StreamInterface_PTR_Convertible,
        StreamInterface_PTR_CppToPython_StreamInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::StreamInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::StreamInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::StreamInterface&");
    Shiboken::Conversions::registerConverterName(converter, "StreamInterface");
    Shiboken::Conversions::registerConverterName(converter, "StreamInterface*");
    Shiboken::Conversions::registerConverterName(converter, "StreamInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::StreamInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StreamInterfaceWrapper).name());



}
