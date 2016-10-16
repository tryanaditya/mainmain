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

#include "qimageiohandler_wrapper.h"

// Extra includes
#include <QRect>
#include <qbytearray.h>
#include <qimage.h>
#include <qimageiohandler.h>
#include <qiodevice.h>
#include <qrect.h>


// Native ---------------------------------------------------------

QImageIOHandlerWrapper::QImageIOHandlerWrapper() : QImageIOHandler() {
    // ... middle
}

bool QImageIOHandlerWrapper::canRead() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canRead"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QImageIOHandler.canRead()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.canRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QImageIOHandlerWrapper::currentImageNumber() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "currentImageNumber"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::currentImageNumber();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.currentImageNumber", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QImageIOHandlerWrapper::currentImageRect() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "currentImageRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::currentImageRect();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.currentImageRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QImageIOHandlerWrapper::imageCount() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "imageCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::imageCount();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.imageCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QImageIOHandlerWrapper::jumpToImage(int imageNumber)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "jumpToImage"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::jumpToImage(imageNumber);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        imageNumber
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.jumpToImage", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QImageIOHandlerWrapper::jumpToNextImage()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "jumpToNextImage"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::jumpToNextImage();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.jumpToNextImage", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QImageIOHandlerWrapper::loopCount() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "loopCount"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::loopCount();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.loopCount", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QImageIOHandlerWrapper::nextImageDelay() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "nextImageDelay"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::nextImageDelay();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.nextImageDelay", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QImageIOHandlerWrapper::option(QImageIOHandler::ImageOption option) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "option"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::option(option);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), &option)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.option", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QImageIOHandlerWrapper::read(QImage * image)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QImageIOHandler.read()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], image)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.read", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QImageIOHandlerWrapper::setOption(QImageIOHandler::ImageOption option, const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setOption"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::setOption(option, value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), &option),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QImageIOHandlerWrapper::supportsOption(QImageIOHandler::ImageOption option) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportsOption"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::supportsOption(option);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), &option)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.supportsOption", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QImageIOHandlerWrapper::write(const QImage & image)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QImageIOHandler::write(image);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &image)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QImageIOHandler.write", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QImageIOHandlerWrapper::~QImageIOHandlerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QImageIOHandler_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QImageIOHandler' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QImageIOHandler >()))
        return -1;

    ::QImageIOHandlerWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QImageIOHandler()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QImageIOHandlerWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QImageIOHandler >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QImageIOHandlerFunc_canRead(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canRead()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QImageIOHandler.canRead()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QImageIOHandler*>(cppSelf)->canRead();
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

static PyObject* Sbk_QImageIOHandlerFunc_currentImageNumber(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentImageNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::currentImageNumber() : const_cast<const ::QImageIOHandler*>(cppSelf)->currentImageNumber();
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

static PyObject* Sbk_QImageIOHandlerFunc_currentImageRect(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentImageRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::currentImageRect() : const_cast<const ::QImageIOHandler*>(cppSelf)->currentImageRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageIOHandlerFunc_device(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QImageIOHandler*>(cppSelf)->device();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageIOHandlerFunc_format(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QImageIOHandler*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QImageIOHandlerFunc_imageCount(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // imageCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::imageCount() : const_cast<const ::QImageIOHandler*>(cppSelf)->imageCount();
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

static PyObject* Sbk_QImageIOHandlerFunc_jumpToImage(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: jumpToImage(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // jumpToImage(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_jumpToImage_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // jumpToImage(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QImageIOHandler::jumpToImage(cppArg0) : cppSelf->jumpToImage(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageIOHandlerFunc_jumpToImage_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.jumpToImage", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_jumpToNextImage(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // jumpToNextImage()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QImageIOHandler::jumpToNextImage() : cppSelf->jumpToNextImage();
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

static PyObject* Sbk_QImageIOHandlerFunc_loopCount(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // loopCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::loopCount() : const_cast<const ::QImageIOHandler*>(cppSelf)->loopCount();
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

static PyObject* Sbk_QImageIOHandlerFunc_nextImageDelay(PyObject* self)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextImageDelay()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::nextImageDelay() : const_cast<const ::QImageIOHandler*>(cppSelf)->nextImageDelay();
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

static PyObject* Sbk_QImageIOHandlerFunc_option(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: option(QImageIOHandler::ImageOption)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), (pyArg)))) {
        overloadId = 0; // option(QImageIOHandler::ImageOption)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_option_TypeError;

    // Call function/method
    {
        ::QImageIOHandler::ImageOption cppArg0 = ((::QImageIOHandler::ImageOption)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // option(QImageIOHandler::ImageOption)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::option(cppArg0) : const_cast<const ::QImageIOHandler*>(cppSelf)->option(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageIOHandlerFunc_option_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageIOHandler.ImageOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.option", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(QImage*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // read(QImage*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(QImage*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QImageIOHandler.read()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->read(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageIOHandlerFunc_read_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.read", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_setDevice(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDevice(QIODevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArg)))) {
        overloadId = 0; // setDevice(QIODevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_setDevice_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIODevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDevice(QIODevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDevice(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageIOHandlerFunc_setDevice_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.setDevice", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_setFormat(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormat(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // setFormat(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_setFormat_TypeError;

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
            // setFormat(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageIOHandlerFunc_setFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.setFormat", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_setOption(PyObject* self, PyObject* args)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setOption", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setOption(QImageIOHandler::ImageOption,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setOption(QImageIOHandler::ImageOption,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_setOption_TypeError;

    // Call function/method
    {
        ::QImageIOHandler::ImageOption cppArg0 = ((::QImageIOHandler::ImageOption)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setOption(QImageIOHandler::ImageOption,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QImageIOHandler::setOption(cppArg0, cppArg1) : cppSelf->setOption(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QImageIOHandlerFunc_setOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageIOHandler.ImageOption, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QImageIOHandler.setOption", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_supportsOption(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsOption(QImageIOHandler::ImageOption)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsOption(QImageIOHandler::ImageOption)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_supportsOption_TypeError;

    // Call function/method
    {
        ::QImageIOHandler::ImageOption cppArg0 = ((::QImageIOHandler::ImageOption)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsOption(QImageIOHandler::ImageOption)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QImageIOHandler*>(cppSelf)->::QImageIOHandler::supportsOption(cppArg0) : const_cast<const ::QImageIOHandler*>(cppSelf)->supportsOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageIOHandlerFunc_supportsOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImageIOHandler.ImageOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.supportsOption", overloads);
        return 0;
}

static PyObject* Sbk_QImageIOHandlerFunc_write(PyObject* self, PyObject* pyArg)
{
    ::QImageIOHandler* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QImageIOHandler*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QImage)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // write(QImage)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QImageIOHandlerFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // write(QImage)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QImageIOHandler::write(*cppArg0) : cppSelf->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QImageIOHandlerFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QImageIOHandler.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QImageIOHandler_methods[] = {
    {"canRead", (PyCFunction)Sbk_QImageIOHandlerFunc_canRead, METH_NOARGS},
    {"currentImageNumber", (PyCFunction)Sbk_QImageIOHandlerFunc_currentImageNumber, METH_NOARGS},
    {"currentImageRect", (PyCFunction)Sbk_QImageIOHandlerFunc_currentImageRect, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QImageIOHandlerFunc_device, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QImageIOHandlerFunc_format, METH_NOARGS},
    {"imageCount", (PyCFunction)Sbk_QImageIOHandlerFunc_imageCount, METH_NOARGS},
    {"jumpToImage", (PyCFunction)Sbk_QImageIOHandlerFunc_jumpToImage, METH_O},
    {"jumpToNextImage", (PyCFunction)Sbk_QImageIOHandlerFunc_jumpToNextImage, METH_NOARGS},
    {"loopCount", (PyCFunction)Sbk_QImageIOHandlerFunc_loopCount, METH_NOARGS},
    {"nextImageDelay", (PyCFunction)Sbk_QImageIOHandlerFunc_nextImageDelay, METH_NOARGS},
    {"option", (PyCFunction)Sbk_QImageIOHandlerFunc_option, METH_O},
    {"read", (PyCFunction)Sbk_QImageIOHandlerFunc_read, METH_O},
    {"setDevice", (PyCFunction)Sbk_QImageIOHandlerFunc_setDevice, METH_O},
    {"setFormat", (PyCFunction)Sbk_QImageIOHandlerFunc_setFormat, METH_O},
    {"setOption", (PyCFunction)Sbk_QImageIOHandlerFunc_setOption, METH_VARARGS},
    {"supportsOption", (PyCFunction)Sbk_QImageIOHandlerFunc_supportsOption, METH_O},
    {"write", (PyCFunction)Sbk_QImageIOHandlerFunc_write, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QImageIOHandler_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QImageIOHandler_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QImageIOHandler_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QImageIOHandler",
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
    /*tp_traverse*/         Sbk_QImageIOHandler_traverse,
    /*tp_clear*/            Sbk_QImageIOHandler_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QImageIOHandler_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QImageIOHandler_Init,
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
static void QImageIOHandler_ImageOption_PythonToCpp_QImageIOHandler_ImageOption(PyObject* pyIn, void* cppOut) {
    *((::QImageIOHandler::ImageOption*)cppOut) = (::QImageIOHandler::ImageOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QImageIOHandler_ImageOption_PythonToCpp_QImageIOHandler_ImageOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]))
        return QImageIOHandler_ImageOption_PythonToCpp_QImageIOHandler_ImageOption;
    return 0;
}
static PyObject* QImageIOHandler_ImageOption_CppToPython_QImageIOHandler_ImageOption(const void* cppIn) {
    int castCppIn = *((::QImageIOHandler::ImageOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QImageIOHandler_PythonToCpp_QImageIOHandler_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QImageIOHandler_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QImageIOHandler_PythonToCpp_QImageIOHandler_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QImageIOHandler_Type))
        return QImageIOHandler_PythonToCpp_QImageIOHandler_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QImageIOHandler_PTR_CppToPython_QImageIOHandler(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QImageIOHandler*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QImageIOHandler_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QImageIOHandler(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QImageIOHandler_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QImageIOHandler", "QImageIOHandler*",
        &Sbk_QImageIOHandler_Type, &Shiboken::callCppDestructor< ::QImageIOHandler >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QImageIOHandler_Type,
        QImageIOHandler_PythonToCpp_QImageIOHandler_PTR,
        is_QImageIOHandler_PythonToCpp_QImageIOHandler_PTR_Convertible,
        QImageIOHandler_PTR_CppToPython_QImageIOHandler);

    Shiboken::Conversions::registerConverterName(converter, "QImageIOHandler");
    Shiboken::Conversions::registerConverterName(converter, "QImageIOHandler*");
    Shiboken::Conversions::registerConverterName(converter, "QImageIOHandler&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImageIOHandler).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QImageIOHandlerWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ImageOption'.
    SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QImageIOHandler_Type,
        "ImageOption",
        "PySide.QtGui.QImageIOHandler.ImageOption",
        "QImageIOHandler::ImageOption");
    if (!SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Size", (long) QImageIOHandler::Size))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "ClipRect", (long) QImageIOHandler::ClipRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Description", (long) QImageIOHandler::Description))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "ScaledClipRect", (long) QImageIOHandler::ScaledClipRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "ScaledSize", (long) QImageIOHandler::ScaledSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "CompressionRatio", (long) QImageIOHandler::CompressionRatio))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Gamma", (long) QImageIOHandler::Gamma))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Quality", (long) QImageIOHandler::Quality))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Name", (long) QImageIOHandler::Name))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "SubType", (long) QImageIOHandler::SubType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "IncrementalReading", (long) QImageIOHandler::IncrementalReading))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Endianness", (long) QImageIOHandler::Endianness))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "Animation", (long) QImageIOHandler::Animation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "BackgroundColor", (long) QImageIOHandler::BackgroundColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
        &Sbk_QImageIOHandler_Type, "ImageFormat", (long) QImageIOHandler::ImageFormat))
        return ;
    // Register converter for enum 'QImageIOHandler::ImageOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX],
            QImageIOHandler_ImageOption_CppToPython_QImageIOHandler_ImageOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QImageIOHandler_ImageOption_PythonToCpp_QImageIOHandler_ImageOption,
            is_QImageIOHandler_ImageOption_PythonToCpp_QImageIOHandler_ImageOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QImageIOHandler::ImageOption");
        Shiboken::Conversions::registerConverterName(converter, "ImageOption");
    }
    // End of 'ImageOption' enum.


    qRegisterMetaType< ::QImageIOHandler::ImageOption >("QImageIOHandler::ImageOption");
}
