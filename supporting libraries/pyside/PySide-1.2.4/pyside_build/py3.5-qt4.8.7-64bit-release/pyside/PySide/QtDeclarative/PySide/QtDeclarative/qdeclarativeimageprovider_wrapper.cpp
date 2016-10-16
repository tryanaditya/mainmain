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
#include "pyside_qtdeclarative_python.h"

#include "qdeclarativeimageprovider_wrapper.h"

// Extra includes
#include <qimage.h>
#include <qpixmap.h>
#include <qsize.h>


// Native ---------------------------------------------------------

QDeclarativeImageProviderWrapper::QDeclarativeImageProviderWrapper(QDeclarativeImageProvider::ImageType type) : QDeclarativeImageProvider(type) {
    // ... middle
}

QImage QDeclarativeImageProviderWrapper::requestImage(const QString & id, QSize * size, const QSize & requestedSize)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QImage();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "requestImage"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDeclarativeImageProvider::requestImage(id, size, requestedSize);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &id),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], size),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &requestedSize)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QImage();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeImageProvider.requestImage", Shiboken::SbkType< QImage >()->tp_name, pyResult->ob_type->tp_name);
        return ::QImage();
    }
    ::QImage cppResult = ::QImage();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPixmap QDeclarativeImageProviderWrapper::requestPixmap(const QString & id, QSize * size, const QSize & requestedSize)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "requestPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDeclarativeImageProvider::requestPixmap(id, size, requestedSize);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &id),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], size),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &requestedSize)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPixmap();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDeclarativeImageProvider.requestPixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QDeclarativeImageProviderWrapper::~QDeclarativeImageProviderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDeclarativeImageProvider_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDeclarativeImageProvider >()))
        return -1;

    ::QDeclarativeImageProviderWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QDeclarativeImageProvider", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QDeclarativeImageProvider(QDeclarativeImageProvider::ImageType)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QDeclarativeImageProvider(QDeclarativeImageProvider::ImageType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeImageProvider_Init_TypeError;

    // Call function/method
    {
        ::QDeclarativeImageProvider::ImageType cppArg0 = ((::QDeclarativeImageProvider::ImageType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QDeclarativeImageProvider(QDeclarativeImageProvider::ImageType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QDeclarativeImageProviderWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDeclarativeImageProvider >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDeclarativeImageProvider_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDeclarativeImageProvider_Init_TypeError:
        const char* overloads[] = {"PySide.QtDeclarative.QDeclarativeImageProvider.ImageType", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeImageProvider", overloads);
        return -1;
}

static PyObject* Sbk_QDeclarativeImageProviderFunc_imageType(PyObject* self)
{
    ::QDeclarativeImageProvider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeImageProvider*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // imageType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDeclarativeImageProvider::ImageType cppResult = const_cast<const ::QDeclarativeImageProvider*>(cppSelf)->imageType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDeclarativeImageProviderFunc_requestImage(PyObject* self, PyObject* args)
{
    ::QDeclarativeImageProvider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeImageProvider*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "requestImage", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: requestImage(QString,QSize*,QSize)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[2])))) {
        overloadId = 0; // requestImage(QString,QSize*,QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeImageProviderFunc_requestImage_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSize* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QSize cppArg2_local = ::QSize();
        ::QSize* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // requestImage(QString,QSize*,QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDeclarativeImageProvider::requestImage(cppArg0, cppArg1, *cppArg2) : cppSelf->requestImage(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativeImageProviderFunc_requestImage_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QSize, PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeImageProvider.requestImage", overloads);
        return 0;
}

static PyObject* Sbk_QDeclarativeImageProviderFunc_requestPixmap(PyObject* self, PyObject* args)
{
    ::QDeclarativeImageProvider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDeclarativeImageProvider*)Shiboken::Conversions::cppPointer(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "requestPixmap", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: requestPixmap(QString,QSize*,QSize)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[2])))) {
        overloadId = 0; // requestPixmap(QString,QSize*,QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDeclarativeImageProviderFunc_requestPixmap_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSize* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QSize cppArg2_local = ::QSize();
        ::QSize* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // requestPixmap(QString,QSize*,QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDeclarativeImageProvider::requestPixmap(cppArg0, cppArg1, *cppArg2) : cppSelf->requestPixmap(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDeclarativeImageProviderFunc_requestPixmap_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QSize, PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtDeclarative.QDeclarativeImageProvider.requestPixmap", overloads);
        return 0;
}

static PyMethodDef Sbk_QDeclarativeImageProvider_methods[] = {
    {"imageType", (PyCFunction)Sbk_QDeclarativeImageProviderFunc_imageType, METH_NOARGS},
    {"requestImage", (PyCFunction)Sbk_QDeclarativeImageProviderFunc_requestImage, METH_VARARGS},
    {"requestPixmap", (PyCFunction)Sbk_QDeclarativeImageProviderFunc_requestPixmap, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDeclarativeImageProvider_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDeclarativeImageProvider_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDeclarativeImageProvider_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtDeclarative.QDeclarativeImageProvider",
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
    /*tp_traverse*/         Sbk_QDeclarativeImageProvider_traverse,
    /*tp_clear*/            Sbk_QDeclarativeImageProvider_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDeclarativeImageProvider_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDeclarativeImageProvider_Init,
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
static void QDeclarativeImageProvider_ImageType_PythonToCpp_QDeclarativeImageProvider_ImageType(PyObject* pyIn, void* cppOut) {
    *((::QDeclarativeImageProvider::ImageType*)cppOut) = (::QDeclarativeImageProvider::ImageType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDeclarativeImageProvider_ImageType_PythonToCpp_QDeclarativeImageProvider_ImageType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX]))
        return QDeclarativeImageProvider_ImageType_PythonToCpp_QDeclarativeImageProvider_ImageType;
    return 0;
}
static PyObject* QDeclarativeImageProvider_ImageType_CppToPython_QDeclarativeImageProvider_ImageType(const void* cppIn) {
    int castCppIn = *((::QDeclarativeImageProvider::ImageType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDeclarativeImageProvider_PythonToCpp_QDeclarativeImageProvider_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDeclarativeImageProvider_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDeclarativeImageProvider_PythonToCpp_QDeclarativeImageProvider_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDeclarativeImageProvider_Type))
        return QDeclarativeImageProvider_PythonToCpp_QDeclarativeImageProvider_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDeclarativeImageProvider_PTR_CppToPython_QDeclarativeImageProvider(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDeclarativeImageProvider*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDeclarativeImageProvider_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDeclarativeImageProvider(PyObject* module)
{
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDeclarativeImageProvider_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDeclarativeImageProvider", "QDeclarativeImageProvider*",
        &Sbk_QDeclarativeImageProvider_Type, &Shiboken::callCppDestructor< ::QDeclarativeImageProvider >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDeclarativeImageProvider_Type,
        QDeclarativeImageProvider_PythonToCpp_QDeclarativeImageProvider_PTR,
        is_QDeclarativeImageProvider_PythonToCpp_QDeclarativeImageProvider_PTR_Convertible,
        QDeclarativeImageProvider_PTR_CppToPython_QDeclarativeImageProvider);

    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeImageProvider");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeImageProvider*");
    Shiboken::Conversions::registerConverterName(converter, "QDeclarativeImageProvider&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeImageProvider).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDeclarativeImageProviderWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ImageType'.
    SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDeclarativeImageProvider_Type,
        "ImageType",
        "PySide.QtDeclarative.QDeclarativeImageProvider.ImageType",
        "QDeclarativeImageProvider::ImageType");
    if (!SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX],
        &Sbk_QDeclarativeImageProvider_Type, "Image", (long) QDeclarativeImageProvider::Image))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX],
        &Sbk_QDeclarativeImageProvider_Type, "Pixmap", (long) QDeclarativeImageProvider::Pixmap))
        return ;
    // Register converter for enum 'QDeclarativeImageProvider::ImageType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX],
            QDeclarativeImageProvider_ImageType_CppToPython_QDeclarativeImageProvider_ImageType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDeclarativeImageProvider_ImageType_PythonToCpp_QDeclarativeImageProvider_ImageType,
            is_QDeclarativeImageProvider_ImageType_PythonToCpp_QDeclarativeImageProvider_ImageType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtDeclarativeTypes[SBK_QDECLARATIVEIMAGEPROVIDER_IMAGETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDeclarativeImageProvider::ImageType");
        Shiboken::Conversions::registerConverterName(converter, "ImageType");
    }
    // End of 'ImageType' enum.


    qRegisterMetaType< ::QDeclarativeImageProvider::ImageType >("QDeclarativeImageProvider::ImageType");
}
