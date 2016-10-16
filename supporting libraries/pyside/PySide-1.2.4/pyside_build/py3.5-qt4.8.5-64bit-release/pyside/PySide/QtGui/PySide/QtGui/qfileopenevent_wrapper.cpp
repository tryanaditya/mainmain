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
#include "pyside_qtgui_python.h"

#include "qfileopenevent_wrapper.h"

// Extra includes
#include <qfile.h>
#include <qurl.h>


// Native ---------------------------------------------------------

QFileOpenEventWrapper::QFileOpenEventWrapper(const QString & file) : QFileOpenEvent(file) {
    // ... middle
}

QFileOpenEventWrapper::QFileOpenEventWrapper(const QUrl & url) : QFileOpenEvent(url) {
    // ... middle
}

QFileOpenEventWrapper::~QFileOpenEventWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFileOpenEvent_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFileOpenEvent >()))
        return -1;

    ::QFileOpenEventWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFileOpenEvent", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFileOpenEvent(QString)
    // 1: QFileOpenEvent(QUrl)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // QFileOpenEvent(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))) {
        overloadId = 1; // QFileOpenEvent(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileOpenEvent_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFileOpenEvent(const QString & file)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QFileOpenEvent(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFileOpenEventWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFileOpenEvent(const QUrl & url)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFileOpenEvent(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFileOpenEventWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFileOpenEvent >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFileOpenEvent_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFileOpenEvent_Init_TypeError:
        const char* overloads[] = {"unicode", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileOpenEvent", overloads);
        return -1;
}

static PyObject* Sbk_QFileOpenEventFunc_file(PyObject* self)
{
    ::QFileOpenEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileOpenEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEOPENEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // file()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileOpenEvent*>(cppSelf)->file();
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

static PyObject* Sbk_QFileOpenEventFunc_openFile(PyObject* self, PyObject* args)
{
    ::QFileOpenEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileOpenEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEOPENEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "openFile", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: openFile(QFile&,QFlags<QIODevice::OpenModeFlag>)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // openFile(QFile&,QFlags<QIODevice::OpenModeFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileOpenEventFunc_openFile_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QFile* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QIODevice::OpenModeFlag> cppArg1 = ((::QFlags<QIODevice::OpenModeFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // openFile(QFile&,QFlags<QIODevice::OpenModeFlag>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileOpenEvent*>(cppSelf)->openFile(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileOpenEventFunc_openFile_TypeError:
        const char* overloads[] = {"PySide.QtCore.QFile, PySide.QtCore.QIODevice.OpenMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileOpenEvent.openFile", overloads);
        return 0;
}

static PyObject* Sbk_QFileOpenEventFunc_url(PyObject* self)
{
    ::QFileOpenEvent* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileOpenEvent*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEOPENEVENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QFileOpenEvent*>(cppSelf)->url();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFileOpenEvent_methods[] = {
    {"file", (PyCFunction)Sbk_QFileOpenEventFunc_file, METH_NOARGS},
    {"openFile", (PyCFunction)Sbk_QFileOpenEventFunc_openFile, METH_VARARGS},
    {"url", (PyCFunction)Sbk_QFileOpenEventFunc_url, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFileOpenEvent_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFileOpenEvent_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFileOpenEvent_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFileOpenEvent",
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
    /*tp_traverse*/         Sbk_QFileOpenEvent_traverse,
    /*tp_clear*/            Sbk_QFileOpenEvent_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFileOpenEvent_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFileOpenEvent_Init,
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

static void* Sbk_QFileOpenEvent_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
     if ( reinterpret_cast< ::QFileOpenEvent*>(cptr)->type() == QEvent::FileOpen)
        return cptr;
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFileOpenEvent_PythonToCpp_QFileOpenEvent_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFileOpenEvent_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFileOpenEvent_PythonToCpp_QFileOpenEvent_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFileOpenEvent_Type))
        return QFileOpenEvent_PythonToCpp_QFileOpenEvent_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFileOpenEvent_PTR_CppToPython_QFileOpenEvent(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFileOpenEvent*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFileOpenEvent_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QFileOpenEvent(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFILEOPENEVENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFileOpenEvent_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFileOpenEvent", "QFileOpenEvent*",
        &Sbk_QFileOpenEvent_Type, &Shiboken::callCppDestructor< ::QFileOpenEvent >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFileOpenEvent_Type,
        QFileOpenEvent_PythonToCpp_QFileOpenEvent_PTR,
        is_QFileOpenEvent_PythonToCpp_QFileOpenEvent_PTR_Convertible,
        QFileOpenEvent_PTR_CppToPython_QFileOpenEvent);

    Shiboken::Conversions::registerConverterName(converter, "QFileOpenEvent");
    Shiboken::Conversions::registerConverterName(converter, "QFileOpenEvent*");
    Shiboken::Conversions::registerConverterName(converter, "QFileOpenEvent&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileOpenEvent).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileOpenEventWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFileOpenEvent_Type, &Sbk_QFileOpenEvent_typeDiscovery);


}
