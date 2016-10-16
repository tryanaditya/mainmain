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

#include "phonon_mediaobjectinterface_wrapper.h"

// Extra includes
#include <mediasource.h>

using namespace Phonon;

// Native ---------------------------------------------------------

MediaObjectInterfaceWrapper::MediaObjectInterfaceWrapper() : Phonon::MediaObjectInterface() {
    // ... middle
}

qint64 MediaObjectInterfaceWrapper::currentTime() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "currentTime"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.currentTime()' not implemented.");
        return ((qint64)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.currentTime", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString MediaObjectInterfaceWrapper::errorString() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "errorString"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.errorString()' not implemented.");
        return ::QString();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.errorString", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

Phonon::ErrorType MediaObjectInterfaceWrapper::errorType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::ErrorType)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "errorType"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.errorType()' not implemented.");
        return ((::Phonon::ErrorType)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::ErrorType)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.errorType", Shiboken::SbkType< Phonon::ErrorType >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::ErrorType)0);
    }
    ::Phonon::ErrorType cppResult = ((::Phonon::ErrorType)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool MediaObjectInterfaceWrapper::hasVideo() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasVideo"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.hasVideo()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.hasVideo", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool MediaObjectInterfaceWrapper::isSeekable() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSeekable"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.isSeekable()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.isSeekable", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void MediaObjectInterfaceWrapper::pause()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pause"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.pause()' not implemented.");
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

void MediaObjectInterfaceWrapper::play()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "play"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.play()' not implemented.");
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

qint32 MediaObjectInterfaceWrapper::prefinishMark() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint32)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "prefinishMark"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.prefinishMark()' not implemented.");
        return ((qint32)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint32)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.prefinishMark", "qint32", pyResult->ob_type->tp_name);
        return ((qint32)0);
    }
    qint32 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 MediaObjectInterfaceWrapper::remainingTime() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "remainingTime"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::MediaObjectInterface::remainingTime();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.remainingTime", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void MediaObjectInterfaceWrapper::seek(qint64 milliseconds)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "seek"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.seek()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        milliseconds
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void MediaObjectInterfaceWrapper::setNextSource(const Phonon::MediaSource & source)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setNextSource"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setNextSource()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &source)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void MediaObjectInterfaceWrapper::setPrefinishMark(qint32 arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setPrefinishMark"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setPrefinishMark()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void MediaObjectInterfaceWrapper::setSource(const Phonon::MediaSource & arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSource"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setSource()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void MediaObjectInterfaceWrapper::setTickInterval(qint32 interval)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setTickInterval"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setTickInterval()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        interval
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void MediaObjectInterfaceWrapper::setTransitionTime(qint32 arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setTransitionTime"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setTransitionTime()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

Phonon::MediaSource MediaObjectInterfaceWrapper::source() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::Phonon::MediaSource();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "source"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.source()' not implemented.");
        return ::Phonon::MediaSource();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::Phonon::MediaSource();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.source", Shiboken::SbkType< Phonon::MediaSource >()->tp_name, pyResult->ob_type->tp_name);
        return ::Phonon::MediaSource();
    }
    ::Phonon::MediaSource cppResult = ::Phonon::MediaSource();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

Phonon::State MediaObjectInterfaceWrapper::state() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::State)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "state"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.state()' not implemented.");
        return ((::Phonon::State)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::State)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.state", Shiboken::SbkType< Phonon::State >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::State)0);
    }
    ::Phonon::State cppResult = ((::Phonon::State)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void MediaObjectInterfaceWrapper::stop()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stop"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.stop()' not implemented.");
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

qint32 MediaObjectInterfaceWrapper::tickInterval() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint32)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tickInterval"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.tickInterval()' not implemented.");
        return ((qint32)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint32)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.tickInterval", "qint32", pyResult->ob_type->tp_name);
        return ((qint32)0);
    }
    qint32 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 MediaObjectInterfaceWrapper::totalTime() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "totalTime"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.totalTime()' not implemented.");
        return ((qint64)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.totalTime", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint32 MediaObjectInterfaceWrapper::transitionTime() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint32)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "transitionTime"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.transitionTime()' not implemented.");
        return ((qint32)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint32)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObjectInterface.transitionTime", "qint32", pyResult->ob_type->tp_name);
        return ((qint32)0);
    }
    qint32 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

MediaObjectInterfaceWrapper::~MediaObjectInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_MediaObjectInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::MediaObjectInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::MediaObjectInterface >()))
        return -1;

    ::MediaObjectInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // MediaObjectInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::MediaObjectInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::MediaObjectInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_currentTime(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTime()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.currentTime()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->currentTime();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_errorString(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.errorString()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->errorString();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_errorType(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorType()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.errorType()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::ErrorType cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->errorType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_hasVideo(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasVideo()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.hasVideo()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->hasVideo();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_isSeekable(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSeekable()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.isSeekable()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->isSeekable();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_pause(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pause()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.pause()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pause();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_play(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // play()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.play()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->play();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_prefinishMark(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefinishMark()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.prefinishMark()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->prefinishMark();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_remainingTime(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // remainingTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->::Phonon::MediaObjectInterface::remainingTime() : const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->remainingTime();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_seek(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seek(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seek(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_seek_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(qint64)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.seek()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->seek(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_seek_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.seek", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_setNextSource(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNextSource(Phonon::MediaSource)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // setNextSource(Phonon::MediaSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_setNextSource_TypeError;

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
            // setNextSource(Phonon::MediaSource)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setNextSource()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNextSource(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_setNextSource_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.setNextSource", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_setPrefinishMark(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrefinishMark(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setPrefinishMark(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_setPrefinishMark_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrefinishMark(qint32)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setPrefinishMark()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrefinishMark(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_setPrefinishMark_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.setPrefinishMark", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_setSource(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSource(Phonon::MediaSource)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // setSource(Phonon::MediaSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_setSource_TypeError;

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
            // setSource(Phonon::MediaSource)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setSource()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSource(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_setSource_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.setSource", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_setTickInterval(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTickInterval(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setTickInterval(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_setTickInterval_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTickInterval(qint32)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setTickInterval()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTickInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_setTickInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.setTickInterval", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_setTransitionTime(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransitionTime(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setTransitionTime(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectInterfaceFunc_setTransitionTime_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTransitionTime(qint32)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.setTransitionTime()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransitionTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectInterfaceFunc_setTransitionTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObjectInterface.setTransitionTime", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_source(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // source()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.source()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaSource cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->source();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_state(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.state()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::State cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_stop(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.stop()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_tickInterval(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tickInterval()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.tickInterval()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->tickInterval();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_totalTime(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // totalTime()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.totalTime()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->totalTime();
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

static PyObject* Sbk_Phonon_MediaObjectInterfaceFunc_transitionTime(PyObject* self)
{
    ::Phonon::MediaObjectInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObjectInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transitionTime()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'MediaObjectInterface.transitionTime()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObjectInterface*>(cppSelf)->transitionTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_MediaObjectInterface_methods[] = {
    {"currentTime", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_currentTime, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_errorString, METH_NOARGS},
    {"errorType", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_errorType, METH_NOARGS},
    {"hasVideo", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_hasVideo, METH_NOARGS},
    {"isSeekable", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_isSeekable, METH_NOARGS},
    {"pause", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_pause, METH_NOARGS},
    {"play", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_play, METH_NOARGS},
    {"prefinishMark", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_prefinishMark, METH_NOARGS},
    {"remainingTime", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_remainingTime, METH_NOARGS},
    {"seek", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_seek, METH_O},
    {"setNextSource", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_setNextSource, METH_O},
    {"setPrefinishMark", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_setPrefinishMark, METH_O},
    {"setSource", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_setSource, METH_O},
    {"setTickInterval", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_setTickInterval, METH_O},
    {"setTransitionTime", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_setTransitionTime, METH_O},
    {"source", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_source, METH_NOARGS},
    {"state", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_state, METH_NOARGS},
    {"stop", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_stop, METH_NOARGS},
    {"tickInterval", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_tickInterval, METH_NOARGS},
    {"totalTime", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_totalTime, METH_NOARGS},
    {"transitionTime", (PyCFunction)Sbk_Phonon_MediaObjectInterfaceFunc_transitionTime, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_MediaObjectInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_MediaObjectInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_MediaObjectInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.MediaObjectInterface",
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
    /*tp_traverse*/         Sbk_Phonon_MediaObjectInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_MediaObjectInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_MediaObjectInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_MediaObjectInterface_Init,
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
static void MediaObjectInterface_PythonToCpp_MediaObjectInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_MediaObjectInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MediaObjectInterface_PythonToCpp_MediaObjectInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaObjectInterface_Type))
        return MediaObjectInterface_PythonToCpp_MediaObjectInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MediaObjectInterface_PTR_CppToPython_MediaObjectInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::MediaObjectInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_MediaObjectInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_MediaObjectInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECTINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_MediaObjectInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MediaObjectInterface", "Phonon::MediaObjectInterface*",
        &Sbk_Phonon_MediaObjectInterface_Type, &Shiboken::callCppDestructor< ::Phonon::MediaObjectInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_MediaObjectInterface_Type,
        MediaObjectInterface_PythonToCpp_MediaObjectInterface_PTR,
        is_MediaObjectInterface_PythonToCpp_MediaObjectInterface_PTR_Convertible,
        MediaObjectInterface_PTR_CppToPython_MediaObjectInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObjectInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObjectInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObjectInterface&");
    Shiboken::Conversions::registerConverterName(converter, "MediaObjectInterface");
    Shiboken::Conversions::registerConverterName(converter, "MediaObjectInterface*");
    Shiboken::Conversions::registerConverterName(converter, "MediaObjectInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::MediaObjectInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::MediaObjectInterfaceWrapper).name());



}
