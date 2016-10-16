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
#include "pyside_qtmultimedia_python.h"

#include "qabstractvideobuffer_wrapper.h"

// Extra includes
#include <qabstractvideobuffer.h>


// Native ---------------------------------------------------------

QAbstractVideoBufferWrapper::QAbstractVideoBufferWrapper(QAbstractVideoBuffer::HandleType type) : QAbstractVideoBuffer(type) {
    // ... middle
}

QVariant QAbstractVideoBufferWrapper::handle() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "handle"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractVideoBuffer::handle();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoBuffer.handle", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

uchar * QAbstractVideoBufferWrapper::map(QAbstractVideoBuffer::MapMode mode, int * numBytes, int * bytesPerLine)
{
    return ((uchar*)0);
}

QAbstractVideoBuffer::MapMode QAbstractVideoBufferWrapper::mapMode() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractVideoBuffer::MapMode)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mapMode"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoBuffer.mapMode()' not implemented.");
        return ((::QAbstractVideoBuffer::MapMode)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractVideoBuffer::MapMode)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractVideoBuffer.mapMode", Shiboken::SbkType< QAbstractVideoBuffer::MapMode >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractVideoBuffer::MapMode)0);
    }
    ::QAbstractVideoBuffer::MapMode cppResult = ((::QAbstractVideoBuffer::MapMode)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractVideoBufferWrapper::unmap()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unmap"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoBuffer.unmap()' not implemented.");
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

QAbstractVideoBufferWrapper::~QAbstractVideoBufferWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractVideoBuffer_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractVideoBuffer' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractVideoBuffer >()))
        return -1;

    ::QAbstractVideoBufferWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAbstractVideoBuffer", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractVideoBuffer(QAbstractVideoBuffer::HandleType)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QAbstractVideoBuffer(QAbstractVideoBuffer::HandleType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractVideoBuffer_Init_TypeError;

    // Call function/method
    {
        ::QAbstractVideoBuffer::HandleType cppArg0 = ((::QAbstractVideoBuffer::HandleType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractVideoBuffer(QAbstractVideoBuffer::HandleType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QAbstractVideoBufferWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractVideoBuffer >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractVideoBuffer_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QAbstractVideoBuffer_Init_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAbstractVideoBuffer.HandleType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAbstractVideoBuffer", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractVideoBufferFunc_handle(PyObject* self)
{
    ::QAbstractVideoBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractVideoBuffer*>(cppSelf)->::QAbstractVideoBuffer::handle() : const_cast<const ::QAbstractVideoBuffer*>(cppSelf)->handle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractVideoBufferFunc_handleType(PyObject* self)
{
    ::QAbstractVideoBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handleType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoBuffer::HandleType cppResult = const_cast<const ::QAbstractVideoBuffer*>(cppSelf)->handleType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractVideoBufferFunc_mapMode(PyObject* self)
{
    ::QAbstractVideoBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mapMode()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoBuffer.mapMode()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractVideoBuffer::MapMode cppResult = const_cast<const ::QAbstractVideoBuffer*>(cppSelf)->mapMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractVideoBufferFunc_unmap(PyObject* self)
{
    ::QAbstractVideoBuffer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractVideoBuffer*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unmap()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractVideoBuffer.unmap()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unmap();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QAbstractVideoBuffer_methods[] = {
    {"handle", (PyCFunction)Sbk_QAbstractVideoBufferFunc_handle, METH_NOARGS},
    {"handleType", (PyCFunction)Sbk_QAbstractVideoBufferFunc_handleType, METH_NOARGS},
    {"mapMode", (PyCFunction)Sbk_QAbstractVideoBufferFunc_mapMode, METH_NOARGS},
    {"unmap", (PyCFunction)Sbk_QAbstractVideoBufferFunc_unmap, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractVideoBuffer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractVideoBuffer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractVideoBuffer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAbstractVideoBuffer",
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
    /*tp_traverse*/         Sbk_QAbstractVideoBuffer_traverse,
    /*tp_clear*/            Sbk_QAbstractVideoBuffer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractVideoBuffer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractVideoBuffer_Init,
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

// Python to C++ enum conversion.
static void QAbstractVideoBuffer_HandleType_PythonToCpp_QAbstractVideoBuffer_HandleType(PyObject* pyIn, void* cppOut) {
    *((::QAbstractVideoBuffer::HandleType*)cppOut) = (::QAbstractVideoBuffer::HandleType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractVideoBuffer_HandleType_PythonToCpp_QAbstractVideoBuffer_HandleType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX]))
        return QAbstractVideoBuffer_HandleType_PythonToCpp_QAbstractVideoBuffer_HandleType;
    return 0;
}
static PyObject* QAbstractVideoBuffer_HandleType_CppToPython_QAbstractVideoBuffer_HandleType(const void* cppIn) {
    int castCppIn = *((::QAbstractVideoBuffer::HandleType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX], castCppIn);

}

static void QAbstractVideoBuffer_MapMode_PythonToCpp_QAbstractVideoBuffer_MapMode(PyObject* pyIn, void* cppOut) {
    *((::QAbstractVideoBuffer::MapMode*)cppOut) = (::QAbstractVideoBuffer::MapMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractVideoBuffer_MapMode_PythonToCpp_QAbstractVideoBuffer_MapMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX]))
        return QAbstractVideoBuffer_MapMode_PythonToCpp_QAbstractVideoBuffer_MapMode;
    return 0;
}
static PyObject* QAbstractVideoBuffer_MapMode_CppToPython_QAbstractVideoBuffer_MapMode(const void* cppIn) {
    int castCppIn = *((::QAbstractVideoBuffer::MapMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractVideoBuffer_PythonToCpp_QAbstractVideoBuffer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractVideoBuffer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractVideoBuffer_PythonToCpp_QAbstractVideoBuffer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractVideoBuffer_Type))
        return QAbstractVideoBuffer_PythonToCpp_QAbstractVideoBuffer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractVideoBuffer_PTR_CppToPython_QAbstractVideoBuffer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAbstractVideoBuffer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAbstractVideoBuffer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QAbstractVideoBuffer(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractVideoBuffer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractVideoBuffer", "QAbstractVideoBuffer*",
        &Sbk_QAbstractVideoBuffer_Type, &Shiboken::callCppDestructor< ::QAbstractVideoBuffer >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractVideoBuffer_Type,
        QAbstractVideoBuffer_PythonToCpp_QAbstractVideoBuffer_PTR,
        is_QAbstractVideoBuffer_PythonToCpp_QAbstractVideoBuffer_PTR_Convertible,
        QAbstractVideoBuffer_PTR_CppToPython_QAbstractVideoBuffer);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoBuffer");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoBuffer*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoBuffer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractVideoBuffer).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractVideoBufferWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'HandleType'.
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractVideoBuffer_Type,
        "HandleType",
        "PySide.QtMultimedia.QAbstractVideoBuffer.HandleType",
        "QAbstractVideoBuffer::HandleType");
    if (!SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "NoHandle", (long) QAbstractVideoBuffer::NoHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "GLTextureHandle", (long) QAbstractVideoBuffer::GLTextureHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "XvShmImageHandle", (long) QAbstractVideoBuffer::XvShmImageHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "CoreImageHandle", (long) QAbstractVideoBuffer::CoreImageHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "QPixmapHandle", (long) QAbstractVideoBuffer::QPixmapHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "UserHandle", (long) QAbstractVideoBuffer::UserHandle))
        return ;
    // Register converter for enum 'QAbstractVideoBuffer::HandleType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX],
            QAbstractVideoBuffer_HandleType_CppToPython_QAbstractVideoBuffer_HandleType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractVideoBuffer_HandleType_PythonToCpp_QAbstractVideoBuffer_HandleType,
            is_QAbstractVideoBuffer_HandleType_PythonToCpp_QAbstractVideoBuffer_HandleType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_HANDLETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoBuffer::HandleType");
        Shiboken::Conversions::registerConverterName(converter, "HandleType");
    }
    // End of 'HandleType' enum.

    // Initialization of enum 'MapMode'.
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractVideoBuffer_Type,
        "MapMode",
        "PySide.QtMultimedia.QAbstractVideoBuffer.MapMode",
        "QAbstractVideoBuffer::MapMode");
    if (!SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "NotMapped", (long) QAbstractVideoBuffer::NotMapped))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "ReadOnly", (long) QAbstractVideoBuffer::ReadOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "WriteOnly", (long) QAbstractVideoBuffer::WriteOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX],
        &Sbk_QAbstractVideoBuffer_Type, "ReadWrite", (long) QAbstractVideoBuffer::ReadWrite))
        return ;
    // Register converter for enum 'QAbstractVideoBuffer::MapMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX],
            QAbstractVideoBuffer_MapMode_CppToPython_QAbstractVideoBuffer_MapMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractVideoBuffer_MapMode_PythonToCpp_QAbstractVideoBuffer_MapMode,
            is_QAbstractVideoBuffer_MapMode_PythonToCpp_QAbstractVideoBuffer_MapMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTVIDEOBUFFER_MAPMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractVideoBuffer::MapMode");
        Shiboken::Conversions::registerConverterName(converter, "MapMode");
    }
    // End of 'MapMode' enum.


    qRegisterMetaType< ::QAbstractVideoBuffer::HandleType >("QAbstractVideoBuffer::HandleType");
    qRegisterMetaType< ::QAbstractVideoBuffer::MapMode >("QAbstractVideoBuffer::MapMode");
}
