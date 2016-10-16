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
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtnetwork_python.h"

#include "qnetworkreply_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qiodevice.h>
#include <qmetaobject.h>
#include <qnetworkaccessmanager.h>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsslconfiguration.h>
#include <qsslerror.h>
#include <qthread.h>
#include <qurl.h>


// Native ---------------------------------------------------------

QNetworkReplyWrapper::QNetworkReplyWrapper(QObject * parent) : QNetworkReply(parent) {
    // ... middle
}

void QNetworkReplyWrapper::abort()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "abort"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QNetworkReply.abort()' not implemented.");
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

bool QNetworkReplyWrapper::atEnd() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atEnd"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::atEnd();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.atEnd", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QNetworkReplyWrapper::bytesAvailable() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesAvailable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::bytesAvailable();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.bytesAvailable", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QNetworkReplyWrapper::bytesToWrite() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesToWrite"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::bytesToWrite();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.bytesToWrite", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QNetworkReplyWrapper::canReadLine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canReadLine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::canReadLine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.canReadLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QNetworkReplyWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QNetworkReplyWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkReply::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QNetworkReplyWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QNetworkReplyWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QNetworkReplyWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QNetworkReplyWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QNetworkReplyWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QNetworkReplyWrapper::ignoreSslErrors()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "ignoreSslErrors"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkReply::ignoreSslErrors();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QNetworkReplyWrapper::isSequential() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSequential"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkReply::isSequential();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QNetworkReplyWrapper::open(QFlags<QIODevice::OpenModeFlag> mode)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "open"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::open(mode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), &mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QNetworkReplyWrapper::pos() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pos"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::pos();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QNetworkReplyWrapper::readData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readData"));
    if (pyOverride.isNull()) {

        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QNetworkReply.readData()' not implemented.");
        return ((qint64)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        maxlen
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Begin code injection

    qint64 cppResult;
    if (PyBytes_Check(pyResult)) {
        cppResult = PyBytes_GET_SIZE((PyObject*)pyResult);
        memcpy(data, PyBytes_AS_STRING((PyObject*)pyResult), cppResult);
    } else if (Shiboken::String::check(pyResult)) {
        cppResult = Shiboken::String::len((PyObject*)pyResult);
        memcpy(data, Shiboken::String::toCString((PyObject*)pyResult), cppResult);
    }

    // End of code injection

    return cppResult;
}

qint64 QNetworkReplyWrapper::readLineData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readLineData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QIODevice::readLineData(data, maxlen);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        maxlen
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Begin code injection

    qint64 cppResult;
    if (!PyBytes_Check(pyResult)) {
        cppResult = -1;
    } else {
        cppResult = PyBytes_GET_SIZE((PyObject*)pyResult);
        memcpy(data, PyBytes_AS_STRING((PyObject*)pyResult), cppResult);
    }

    // End of code injection

    return cppResult;
}

bool QNetworkReplyWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::reset();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QNetworkReplyWrapper::seek(qint64 pos)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "seek"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::seek(pos);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        pos
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QNetworkReplyWrapper::setReadBufferSize(qint64 size)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setReadBufferSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkReply::setReadBufferSize(size);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        size
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

qint64 QNetworkReplyWrapper::size() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "size"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::size();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QNetworkReplyWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QNetworkReplyWrapper::waitForBytesWritten(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForBytesWritten"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::waitForBytesWritten(msecs);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        msecs
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.waitForBytesWritten", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QNetworkReplyWrapper::waitForReadyRead(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForReadyRead"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QIODevice::waitForReadyRead(msecs);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        msecs
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.waitForReadyRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QNetworkReplyWrapper::writeData(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkReply::writeData(data, len);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NL)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), data),
        len
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qint64)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkReply.writeData", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QNetworkReplyWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QNetworkReply::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QNetworkReplyWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QNetworkReply::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QNetworkReplyWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QNetworkReplyWrapper* >(this));
        return QNetworkReply::qt_metacast(_clname);
}

QNetworkReplyWrapper::~QNetworkReplyWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkReply_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QNetworkReply' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkReply >()))
        return -1;

    ::QNetworkReplyWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QNetworkReply", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkReply(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkReply(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QNetworkReply(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReply_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkReply(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QNetworkReply_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QNetworkReply(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QNetworkReplyWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QNetworkReplyWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkReply >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkReply_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QNetworkReply_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkReplyFunc_abort(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // abort()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QNetworkReply.abort()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->abort();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QNetworkReplyFunc_attribute(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: attribute(QNetworkRequest::Attribute)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), (pyArg)))) {
        overloadId = 0; // attribute(QNetworkRequest::Attribute)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_attribute_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::Attribute cppArg0 = ((::QNetworkRequest::Attribute)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // attribute(QNetworkRequest::Attribute)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->attribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkReplyFunc_attribute_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.Attribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.attribute", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_close(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QNetworkReply::close() : cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QNetworkReplyFunc_error(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply::NetworkError cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_hasRawHeader(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasRawHeader(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // hasRawHeader(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_hasRawHeader_TypeError;

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
            // hasRawHeader(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->hasRawHeader(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkReplyFunc_hasRawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.hasRawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_header(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: header(QNetworkRequest::KnownHeaders)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX]), (pyArg)))) {
        overloadId = 0; // header(QNetworkRequest::KnownHeaders)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_header_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::KnownHeaders cppArg0 = ((::QNetworkRequest::KnownHeaders)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // header(QNetworkRequest::KnownHeaders)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->header(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkReplyFunc_header_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.KnownHeaders", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.header", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_ignoreSslErrors(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "ignoreSslErrors", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: ignoreSslErrors()
    // 1: ignoreSslErrors(QList<QSslError>)
    if (numArgs == 0) {
        overloadId = 0; // ignoreSslErrors()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX], (pyArgs[0])))) {
        overloadId = 1; // ignoreSslErrors(QList<QSslError>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_ignoreSslErrors_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ignoreSslErrors()
        {

            if (!PyErr_Occurred()) {
                // ignoreSslErrors()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QNetworkReply::ignoreSslErrors() : cppSelf->ignoreSslErrors();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ignoreSslErrors(const QList<QSslError > & errors)
        {
            ::QList<QSslError > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // ignoreSslErrors(QList<QSslError>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignoreSslErrors(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_ignoreSslErrors_TypeError:
        const char* overloads[] = {"", "list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.ignoreSslErrors", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_isFinished(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFinished()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->isFinished();
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

static PyObject* Sbk_QNetworkReplyFunc_isRunning(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRunning()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->isRunning();
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

static PyObject* Sbk_QNetworkReplyFunc_isSequential(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSequential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QNetworkReply*>(cppSelf)->::QNetworkReply::isSequential() : const_cast<const ::QNetworkReply*>(cppSelf)->isSequential();
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

static PyObject* Sbk_QNetworkReplyFunc_manager(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // manager()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkAccessManager * cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->manager();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_operation(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkAccessManager::Operation cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->operation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_rawHeader(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rawHeader(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // rawHeader(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_rawHeader_TypeError;

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
            // rawHeader(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->rawHeader(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkReplyFunc_rawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.rawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_rawHeaderList(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawHeaderList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->rawHeaderList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_rawHeaderPairs(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rawHeaderPairs()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QList<QPair<QByteArray, QByteArray > > & cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->rawHeaderPairs();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QPAIR_QBYTEARRAY_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_readBufferSize(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->readBufferSize();
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

static PyObject* Sbk_QNetworkReplyFunc_request(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // request()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkRequest cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->request();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_setAttribute(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAttribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(QNetworkRequest::Attribute,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_ATTRIBUTE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setAttribute(QNetworkRequest::Attribute,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setAttribute_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::Attribute cppArg0 = ((::QNetworkRequest::Attribute)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAttribute(QNetworkRequest::Attribute,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAttribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setAttribute_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.Attribute, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setError(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setError", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setError(QNetworkReply::NetworkError,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setError(QNetworkReply::NetworkError,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setError_TypeError;

    // Call function/method
    {
        ::QNetworkReply::NetworkError cppArg0 = ((::QNetworkReply::NetworkError)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setError(QNetworkReply::NetworkError,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setError(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setError_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkReply.NetworkError, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.setError", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setFinished(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFinished(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFinished(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setFinished_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFinished(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFinished(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setFinished_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setFinished", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setHeader(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setHeader", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setHeader(QNetworkRequest::KnownHeaders,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_KNOWNHEADERS_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setHeader(QNetworkRequest::KnownHeaders,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setHeader_TypeError;

    // Call function/method
    {
        ::QNetworkRequest::KnownHeaders cppArg0 = ((::QNetworkRequest::KnownHeaders)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setHeader(QNetworkRequest::KnownHeaders,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHeader(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setHeader_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest.KnownHeaders, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.setHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setOperation(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOperation(QNetworkAccessManager::Operation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), (pyArg)))) {
        overloadId = 0; // setOperation(QNetworkAccessManager::Operation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setOperation_TypeError;

    // Call function/method
    {
        ::QNetworkAccessManager::Operation cppArg0 = ((::QNetworkAccessManager::Operation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOperation(QNetworkAccessManager::Operation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOperation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setOperation_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkAccessManager.Operation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setOperation", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setRawHeader(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRawHeader", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRawHeader(QByteArray,QByteArray)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 0; // setRawHeader(QByteArray,QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setRawHeader_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = ::QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setRawHeader(QByteArray,QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRawHeader(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setRawHeader_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.setRawHeader", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setReadBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadBufferSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setReadBufferSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setReadBufferSize_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadBufferSize(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QNetworkReply::setReadBufferSize(cppArg0) : cppSelf->setReadBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setReadBufferSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setReadBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setRequest(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRequest(QNetworkRequest)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
        overloadId = 0; // setRequest(QNetworkRequest)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setRequest_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
        ::QNetworkRequest* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setRequest(QNetworkRequest)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRequest(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setRequest_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setRequest", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setSslConfiguration(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSslConfiguration(QSslConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setSslConfiguration(QSslConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setSslConfiguration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslConfiguration cppArg0_local = ::QSslConfiguration();
        ::QSslConfiguration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSslConfiguration(QSslConfiguration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSslConfiguration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setSslConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setSslConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_setUrl(PyObject* self, PyObject* pyArg)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_setUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setUrl(QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUrl(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkReplyFunc_setUrl_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkReply.setUrl", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkReplyFunc_sslConfiguration(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sslConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslConfiguration cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->sslConfiguration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkReplyFunc_url(PyObject* self)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // url()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QNetworkReply*>(cppSelf)->url();
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

static PyObject* Sbk_QNetworkReplyFunc_writeData(PyObject* self, PyObject* args)
{
    ::QNetworkReply* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkReply*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "writeData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: writeData(const char*,qint64)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
        overloadId = 0; // writeData(const char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkReplyFunc_writeData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeData(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QNetworkReply::writeData(cppArg0, cppArg1) : cppSelf->writeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkReplyFunc_writeData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkReply.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_QNetworkReply_methods[] = {
    {"abort", (PyCFunction)Sbk_QNetworkReplyFunc_abort, METH_NOARGS},
    {"attribute", (PyCFunction)Sbk_QNetworkReplyFunc_attribute, METH_O},
    {"close", (PyCFunction)Sbk_QNetworkReplyFunc_close, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QNetworkReplyFunc_error, METH_NOARGS},
    {"hasRawHeader", (PyCFunction)Sbk_QNetworkReplyFunc_hasRawHeader, METH_O},
    {"header", (PyCFunction)Sbk_QNetworkReplyFunc_header, METH_O},
    {"ignoreSslErrors", (PyCFunction)Sbk_QNetworkReplyFunc_ignoreSslErrors, METH_VARARGS},
    {"isFinished", (PyCFunction)Sbk_QNetworkReplyFunc_isFinished, METH_NOARGS},
    {"isRunning", (PyCFunction)Sbk_QNetworkReplyFunc_isRunning, METH_NOARGS},
    {"isSequential", (PyCFunction)Sbk_QNetworkReplyFunc_isSequential, METH_NOARGS},
    {"manager", (PyCFunction)Sbk_QNetworkReplyFunc_manager, METH_NOARGS},
    {"operation", (PyCFunction)Sbk_QNetworkReplyFunc_operation, METH_NOARGS},
    {"rawHeader", (PyCFunction)Sbk_QNetworkReplyFunc_rawHeader, METH_O},
    {"rawHeaderList", (PyCFunction)Sbk_QNetworkReplyFunc_rawHeaderList, METH_NOARGS},
    {"rawHeaderPairs", (PyCFunction)Sbk_QNetworkReplyFunc_rawHeaderPairs, METH_NOARGS},
    {"readBufferSize", (PyCFunction)Sbk_QNetworkReplyFunc_readBufferSize, METH_NOARGS},
    {"request", (PyCFunction)Sbk_QNetworkReplyFunc_request, METH_NOARGS},
    {"setAttribute", (PyCFunction)Sbk_QNetworkReplyFunc_setAttribute, METH_VARARGS},
    {"setError", (PyCFunction)Sbk_QNetworkReplyFunc_setError, METH_VARARGS},
    {"setFinished", (PyCFunction)Sbk_QNetworkReplyFunc_setFinished, METH_O},
    {"setHeader", (PyCFunction)Sbk_QNetworkReplyFunc_setHeader, METH_VARARGS},
    {"setOperation", (PyCFunction)Sbk_QNetworkReplyFunc_setOperation, METH_O},
    {"setRawHeader", (PyCFunction)Sbk_QNetworkReplyFunc_setRawHeader, METH_VARARGS},
    {"setReadBufferSize", (PyCFunction)Sbk_QNetworkReplyFunc_setReadBufferSize, METH_O},
    {"setRequest", (PyCFunction)Sbk_QNetworkReplyFunc_setRequest, METH_O},
    {"setSslConfiguration", (PyCFunction)Sbk_QNetworkReplyFunc_setSslConfiguration, METH_O},
    {"setUrl", (PyCFunction)Sbk_QNetworkReplyFunc_setUrl, METH_O},
    {"sslConfiguration", (PyCFunction)Sbk_QNetworkReplyFunc_sslConfiguration, METH_NOARGS},
    {"url", (PyCFunction)Sbk_QNetworkReplyFunc_url, METH_NOARGS},
    {"writeData", (PyCFunction)Sbk_QNetworkReplyFunc_writeData, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QNetworkReply_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkReply_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkReply_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkReply",
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
    /*tp_traverse*/         Sbk_QNetworkReply_traverse,
    /*tp_clear*/            Sbk_QNetworkReply_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkReply_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkReply_Init,
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

static void* Sbk_QNetworkReply_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QNetworkReply*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QNetworkReply_NetworkError_PythonToCpp_QNetworkReply_NetworkError(PyObject* pyIn, void* cppOut) {
    *((::QNetworkReply::NetworkError*)cppOut) = (::QNetworkReply::NetworkError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkReply_NetworkError_PythonToCpp_QNetworkReply_NetworkError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX]))
        return QNetworkReply_NetworkError_PythonToCpp_QNetworkReply_NetworkError;
    return 0;
}
static PyObject* QNetworkReply_NetworkError_CppToPython_QNetworkReply_NetworkError(const void* cppIn) {
    int castCppIn = *((::QNetworkReply::NetworkError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkReply_PythonToCpp_QNetworkReply_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkReply_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkReply_PythonToCpp_QNetworkReply_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkReply_Type))
        return QNetworkReply_PythonToCpp_QNetworkReply_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkReply_PTR_CppToPython_QNetworkReply(const void* cppIn) {
    return PySide::getWrapperForQObject((::QNetworkReply*)cppIn, &Sbk_QNetworkReply_Type);

}

void init_QNetworkReply(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkReply_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkReply", "QNetworkReply*",
        &Sbk_QNetworkReply_Type, &Shiboken::callCppDestructor< ::QNetworkReply >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkReply_Type,
        QNetworkReply_PythonToCpp_QNetworkReply_PTR,
        is_QNetworkReply_PythonToCpp_QNetworkReply_PTR_Convertible,
        QNetworkReply_PTR_CppToPython_QNetworkReply);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkReply");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkReply*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkReply&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkReply).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkReplyWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QNetworkReply_Type, &Sbk_QNetworkReply_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'NetworkError'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkReply_Type,
        "NetworkError",
        "PySide.QtNetwork.QNetworkReply.NetworkError",
        "QNetworkReply::NetworkError");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "NoError", (long) QNetworkReply::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ConnectionRefusedError", (long) QNetworkReply::ConnectionRefusedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "RemoteHostClosedError", (long) QNetworkReply::RemoteHostClosedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "HostNotFoundError", (long) QNetworkReply::HostNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "TimeoutError", (long) QNetworkReply::TimeoutError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "OperationCanceledError", (long) QNetworkReply::OperationCanceledError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "SslHandshakeFailedError", (long) QNetworkReply::SslHandshakeFailedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "TemporaryNetworkFailureError", (long) QNetworkReply::TemporaryNetworkFailureError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "UnknownNetworkError", (long) QNetworkReply::UnknownNetworkError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProxyConnectionRefusedError", (long) QNetworkReply::ProxyConnectionRefusedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProxyConnectionClosedError", (long) QNetworkReply::ProxyConnectionClosedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProxyNotFoundError", (long) QNetworkReply::ProxyNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProxyTimeoutError", (long) QNetworkReply::ProxyTimeoutError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProxyAuthenticationRequiredError", (long) QNetworkReply::ProxyAuthenticationRequiredError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "UnknownProxyError", (long) QNetworkReply::UnknownProxyError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ContentAccessDenied", (long) QNetworkReply::ContentAccessDenied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ContentOperationNotPermittedError", (long) QNetworkReply::ContentOperationNotPermittedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ContentNotFoundError", (long) QNetworkReply::ContentNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "AuthenticationRequiredError", (long) QNetworkReply::AuthenticationRequiredError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ContentReSendError", (long) QNetworkReply::ContentReSendError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "UnknownContentError", (long) QNetworkReply::UnknownContentError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProtocolUnknownError", (long) QNetworkReply::ProtocolUnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProtocolInvalidOperationError", (long) QNetworkReply::ProtocolInvalidOperationError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
        &Sbk_QNetworkReply_Type, "ProtocolFailure", (long) QNetworkReply::ProtocolFailure))
        return ;
    // Register converter for enum 'QNetworkReply::NetworkError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX],
            QNetworkReply_NetworkError_CppToPython_QNetworkReply_NetworkError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkReply_NetworkError_PythonToCpp_QNetworkReply_NetworkError,
            is_QNetworkReply_NetworkError_PythonToCpp_QNetworkReply_NetworkError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_NETWORKERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkReply::NetworkError");
        Shiboken::Conversions::registerConverterName(converter, "NetworkError");
    }
    // End of 'NetworkError' enum.

    PySide::Signal::registerSignals(&Sbk_QNetworkReply_Type, &::QNetworkReply::staticMetaObject);

    qRegisterMetaType< ::QNetworkReply::NetworkError >("QNetworkReply::NetworkError");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QNetworkReply_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QNetworkReply_Type, &::QNetworkReply::staticMetaObject, sizeof(::QNetworkReply));
}
