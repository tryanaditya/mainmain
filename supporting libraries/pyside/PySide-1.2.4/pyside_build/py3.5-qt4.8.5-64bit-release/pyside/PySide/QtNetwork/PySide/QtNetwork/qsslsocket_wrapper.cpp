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

#include "qsslsocket_wrapper.h"

// Extra includes
#include <QList>
#include <qauthenticator.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qhostaddress.h>
#include <qmetaobject.h>
#include <qnetworkproxy.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsslcertificate.h>
#include <qsslcipher.h>
#include <qsslconfiguration.h>
#include <qsslerror.h>
#include <qsslkey.h>
#include <qsslsocket.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSslSocketWrapper::QSslSocketWrapper(QObject * parent) : QSslSocket(parent) {
    // ... middle
}

bool QSslSocketWrapper::atEnd() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atEnd"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::atEnd();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.atEnd", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::bytesAvailable() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesAvailable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::bytesAvailable();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.bytesAvailable", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::bytesToWrite() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesToWrite"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::bytesToWrite();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.bytesToWrite", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSslSocketWrapper::canReadLine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canReadLine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::canReadLine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.canReadLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSslSocketWrapper::childEvent(QChildEvent * arg__1)
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

void QSslSocketWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSslSocketWrapper::connectNotify(const char * signal)
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

void QSslSocketWrapper::customEvent(QEvent * arg__1)
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

void QSslSocketWrapper::disconnectNotify(const char * signal)
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

bool QSslSocketWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSslSocketWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QSslSocketWrapper::isSequential() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSequential"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::isSequential();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSslSocketWrapper::open(QFlags<QIODevice::OpenModeFlag> mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::pos() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::readData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QSslSocket::readData(data, maxlen);
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

qint64 QSslSocketWrapper::readLineData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readLineData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractSocket::readLineData(data, maxlen);
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

bool QSslSocketWrapper::reset()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSslSocketWrapper::seek(qint64 pos)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::size() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QSslSocketWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QSslSocketWrapper::waitForBytesWritten(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForBytesWritten"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::waitForBytesWritten(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.waitForBytesWritten", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QSslSocketWrapper::waitForReadyRead(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForReadyRead"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::waitForReadyRead(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.waitForReadyRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QSslSocketWrapper::writeData(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSslSocket::writeData(data, len);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSslSocket.writeData", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QSslSocketWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSslSocket::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSslSocketWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSslSocket::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSslSocketWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSslSocketWrapper* >(this));
        return QSslSocket::qt_metacast(_clname);
}

QSslSocketWrapper::~QSslSocketWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSslSocket_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSslSocket >()))
        return -1;

    ::QSslSocketWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QSslSocket", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QSslSocket(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QSslSocket(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSslSocket(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocket_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QSslSocket_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QSslSocket(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QSslSocketWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QSslSocketWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSslSocket >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSslSocket_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QSslSocket_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket", overloads);
        return -1;
}

static PyObject* Sbk_QSslSocketFunc_abort(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // abort()
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

static PyObject* Sbk_QSslSocketFunc_addCaCertificate(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addCaCertificate(QSslCertificate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // addCaCertificate(QSslCertificate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_addCaCertificate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
        ::QSslCertificate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addCaCertificate(QSslCertificate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addCaCertificate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_addCaCertificate_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.addCaCertificate", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_addCaCertificates(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addCaCertificates(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addCaCertificates(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addCaCertificates", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addCaCertificates(QList<QSslCertificate>)
    // 1: addCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // addCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // addCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2])))) {
                overloadId = 1; // addCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], (pyArgs[0])))) {
        overloadId = 0; // addCaCertificates(QList<QSslCertificate>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_addCaCertificates_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addCaCertificates(const QList<QSslCertificate > & certificates)
        {
            ::QList<QSslCertificate > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addCaCertificates(QList<QSslCertificate>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addCaCertificates(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // addCaCertificates(const QString & path, QSsl::EncodingFormat format, QRegExp::PatternSyntax syntax)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addCaCertificates(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslSocketFunc_addCaCertificates_TypeError;
                }
                value = PyDict_GetItemString(kwds, "syntax");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addCaCertificates(): got multiple values for keyword argument 'syntax'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2]))))
                        goto Sbk_QSslSocketFunc_addCaCertificates_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QRegExp::PatternSyntax cppArg2 = QRegExp::FixedString;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->addCaCertificates(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_addCaCertificates_TypeError:
        const char* overloads[] = {"list", "unicode, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtCore.QRegExp.PatternSyntax = QRegExp.FixedString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.addCaCertificates", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_addDefaultCaCertificate(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addDefaultCaCertificate(QSslCertificate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // addDefaultCaCertificate(QSslCertificate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_addDefaultCaCertificate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
        ::QSslCertificate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addDefaultCaCertificate(QSslCertificate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSslSocket::addDefaultCaCertificate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_addDefaultCaCertificate_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificate", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_addDefaultCaCertificates(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificates(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificates(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addDefaultCaCertificates", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addDefaultCaCertificates(QList<QSslCertificate>)
    // 1: addDefaultCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // addDefaultCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // addDefaultCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2])))) {
                overloadId = 1; // addDefaultCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], (pyArgs[0])))) {
        overloadId = 0; // addDefaultCaCertificates(QList<QSslCertificate>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_addDefaultCaCertificates_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addDefaultCaCertificates(const QList<QSslCertificate > & certificates)
        {
            ::QList<QSslCertificate > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addDefaultCaCertificates(QList<QSslCertificate>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QSslSocket::addDefaultCaCertificates(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // addDefaultCaCertificates(const QString & path, QSsl::EncodingFormat format, QRegExp::PatternSyntax syntax)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificates(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslSocketFunc_addDefaultCaCertificates_TypeError;
                }
                value = PyDict_GetItemString(kwds, "syntax");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificates(): got multiple values for keyword argument 'syntax'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2]))))
                        goto Sbk_QSslSocketFunc_addDefaultCaCertificates_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QRegExp::PatternSyntax cppArg2 = QRegExp::FixedString;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addDefaultCaCertificates(QString,QSsl::EncodingFormat,QRegExp::PatternSyntax)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QSslSocket::addDefaultCaCertificates(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_addDefaultCaCertificates_TypeError:
        const char* overloads[] = {"list", "unicode, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtCore.QRegExp.PatternSyntax = QRegExp.FixedString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.addDefaultCaCertificates", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_atEnd(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSslSocket*>(cppSelf)->::QSslSocket::atEnd() : const_cast<const ::QSslSocket*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QSslSocketFunc_bytesAvailable(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSslSocket*>(cppSelf)->::QSslSocket::bytesAvailable() : const_cast<const ::QSslSocket*>(cppSelf)->bytesAvailable();
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

static PyObject* Sbk_QSslSocketFunc_bytesToWrite(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesToWrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSslSocket*>(cppSelf)->::QSslSocket::bytesToWrite() : const_cast<const ::QSslSocket*>(cppSelf)->bytesToWrite();
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

static PyObject* Sbk_QSslSocketFunc_caCertificates(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // caCertificates()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = const_cast<const ::QSslSocket*>(cppSelf)->caCertificates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_canReadLine(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canReadLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QSslSocket*>(cppSelf)->::QSslSocket::canReadLine() : const_cast<const ::QSslSocket*>(cppSelf)->canReadLine();
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

static PyObject* Sbk_QSslSocketFunc_ciphers(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ciphers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCipher > cppResult = const_cast<const ::QSslSocket*>(cppSelf)->ciphers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_close(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSslSocket::close() : cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSslSocketFunc_connectToHostEncrypted(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.connectToHostEncrypted(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.connectToHostEncrypted(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:connectToHostEncrypted", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: connectToHostEncrypted(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
    // 1: connectToHostEncrypted(QString,quint16,QString,QFlags<QIODevice::OpenModeFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // connectToHostEncrypted(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // connectToHostEncrypted(QString,quint16,QString,QFlags<QIODevice::OpenModeFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 1; // connectToHostEncrypted(QString,quint16,QString,QFlags<QIODevice::OpenModeFlag>)
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 0; // connectToHostEncrypted(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_connectToHostEncrypted_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // connectToHostEncrypted(const QString & hostName, quint16 port, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.connectToHostEncrypted(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QSslSocketFunc_connectToHostEncrypted_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            quint16 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // connectToHostEncrypted(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->connectToHostEncrypted(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // connectToHostEncrypted(const QString & hostName, quint16 port, const QString & sslPeerName, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.connectToHostEncrypted(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QSslSocketFunc_connectToHostEncrypted_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            quint16 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QIODevice::OpenModeFlag> cppArg3 = QIODevice::ReadWrite;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // connectToHostEncrypted(QString,quint16,QString,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->connectToHostEncrypted(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_connectToHostEncrypted_TypeError:
        const char* overloads[] = {"unicode, unsigned short, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", "unicode, unsigned short, unicode, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.connectToHostEncrypted", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_connectToHostImplementation(PyObject* self, PyObject* args)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "connectToHostImplementation", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
        overloadId = 0; // connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_connectToHostImplementation_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        quint16 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<QIODevice::OpenModeFlag> cppArg2 = ((::QFlags<QIODevice::OpenModeFlag>)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->connectToHostImplementation(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_connectToHostImplementation_TypeError:
        const char* overloads[] = {"unicode, unsigned short, PySide.QtCore.QIODevice.OpenMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.connectToHostImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_defaultCaCertificates(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultCaCertificates()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = ::QSslSocket::defaultCaCertificates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_defaultCiphers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultCiphers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCipher > cppResult = ::QSslSocket::defaultCiphers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_disconnectFromHostImplementation(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // disconnectFromHostImplementation()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->disconnectFromHostImplementation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSslSocketFunc_encryptedBytesAvailable(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encryptedBytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QSslSocket*>(cppSelf)->encryptedBytesAvailable();
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

static PyObject* Sbk_QSslSocketFunc_encryptedBytesToWrite(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // encryptedBytesToWrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QSslSocket*>(cppSelf)->encryptedBytesToWrite();
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

static PyObject* Sbk_QSslSocketFunc_flush(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flush()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->flush();
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

static PyObject* Sbk_QSslSocketFunc_ignoreSslErrors(PyObject* self, PyObject* args)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSslSocketFunc_ignoreSslErrors_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ignoreSslErrors()
        {

            if (!PyErr_Occurred()) {
                // ignoreSslErrors()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ignoreSslErrors();
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

    Sbk_QSslSocketFunc_ignoreSslErrors_TypeError:
        const char* overloads[] = {"", "list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.ignoreSslErrors", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_isEncrypted(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEncrypted()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSslSocket*>(cppSelf)->isEncrypted();
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

static PyObject* Sbk_QSslSocketFunc_localCertificate(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localCertificate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCertificate cppResult = const_cast<const ::QSslSocket*>(cppSelf)->localCertificate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_mode(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslSocket::SslMode cppResult = const_cast<const ::QSslSocket*>(cppSelf)->mode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_peerCertificate(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerCertificate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCertificate cppResult = const_cast<const ::QSslSocket*>(cppSelf)->peerCertificate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_peerCertificateChain(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerCertificateChain()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = const_cast<const ::QSslSocket*>(cppSelf)->peerCertificateChain();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_peerVerifyDepth(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerVerifyDepth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QSslSocket*>(cppSelf)->peerVerifyDepth();
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

static PyObject* Sbk_QSslSocketFunc_peerVerifyMode(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerVerifyMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslSocket::PeerVerifyMode cppResult = const_cast<const ::QSslSocket*>(cppSelf)->peerVerifyMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_peerVerifyName(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerVerifyName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSslSocket*>(cppSelf)->peerVerifyName();
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

static PyObject* Sbk_QSslSocketFunc_privateKey(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // privateKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslKey cppResult = const_cast<const ::QSslSocket*>(cppSelf)->privateKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_protocol(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // protocol()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSsl::SslProtocol cppResult = const_cast<const ::QSslSocket*>(cppSelf)->protocol();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_readData(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: readData(char*,qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // readData(char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_readData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSslSocket::readData(ba.data(), ba.size()) : cppSelf->readData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_readData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.readData", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_sessionCipher(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sessionCipher()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslCipher cppResult = const_cast<const ::QSslSocket*>(cppSelf)->sessionCipher();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_setCaCertificates(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCaCertificates(QList<QSslCertificate>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // setCaCertificates(QList<QSslCertificate>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setCaCertificates_TypeError;

    // Call function/method
    {
        ::QList<QSslCertificate > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCaCertificates(QList<QSslCertificate>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCaCertificates(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setCaCertificates_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setCaCertificates", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setCiphers(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCiphers(QList<QSslCipher>)
    // 1: setCiphers(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setCiphers(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], (pyArg)))) {
        overloadId = 0; // setCiphers(QList<QSslCipher>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setCiphers_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setCiphers(const QList<QSslCipher > & ciphers)
        {
            ::QList<QSslCipher > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setCiphers(QList<QSslCipher>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCiphers(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setCiphers(const QString & ciphers)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setCiphers(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCiphers(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setCiphers_TypeError:
        const char* overloads[] = {"list", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setCiphers", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setDefaultCaCertificates(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultCaCertificates(QList<QSslCertificate>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultCaCertificates(QList<QSslCertificate>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setDefaultCaCertificates_TypeError;

    // Call function/method
    {
        ::QList<QSslCertificate > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultCaCertificates(QList<QSslCertificate>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSslSocket::setDefaultCaCertificates(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setDefaultCaCertificates_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setDefaultCaCertificates", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setDefaultCiphers(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultCiphers(QList<QSslCipher>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultCiphers(QList<QSslCipher>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setDefaultCiphers_TypeError;

    // Call function/method
    {
        ::QList<QSslCipher > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultCiphers(QList<QSslCipher>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSslSocket::setDefaultCiphers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setDefaultCiphers_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setDefaultCiphers", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setLocalCertificate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setLocalCertificate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setLocalCertificate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setLocalCertificate", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setLocalCertificate(QSslCertificate)
    // 1: setLocalCertificate(QString,QSsl::EncodingFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setLocalCertificate(QString,QSsl::EncodingFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 1; // setLocalCertificate(QString,QSsl::EncodingFormat)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], (pyArgs[0])))) {
        overloadId = 0; // setLocalCertificate(QSslCertificate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setLocalCertificate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setLocalCertificate(const QSslCertificate & certificate)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSslCertificate cppArg0_local = ::QSslCertificate(((::QIODevice*)0));
            ::QSslCertificate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCERTIFICATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setLocalCertificate(QSslCertificate)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setLocalCertificate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setLocalCertificate(const QString & fileName, QSsl::EncodingFormat format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setLocalCertificate(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslSocketFunc_setLocalCertificate_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::EncodingFormat cppArg1 = QSsl::Pem;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setLocalCertificate(QString,QSsl::EncodingFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setLocalCertificate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setLocalCertificate_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslCertificate", "unicode, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.setLocalCertificate", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setPeerVerifyDepth(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerVerifyDepth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setPeerVerifyDepth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setPeerVerifyDepth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerVerifyDepth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerVerifyDepth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setPeerVerifyDepth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setPeerVerifyDepth", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setPeerVerifyMode(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerVerifyMode(QSslSocket::PeerVerifyMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setPeerVerifyMode(QSslSocket::PeerVerifyMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setPeerVerifyMode_TypeError;

    // Call function/method
    {
        ::QSslSocket::PeerVerifyMode cppArg0 = ((::QSslSocket::PeerVerifyMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerVerifyMode(QSslSocket::PeerVerifyMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerVerifyMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setPeerVerifyMode_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslSocket.PeerVerifyMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setPeerVerifyMode", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setPeerVerifyName(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerVerifyName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPeerVerifyName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setPeerVerifyName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerVerifyName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerVerifyName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setPeerVerifyName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setPeerVerifyName", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setPrivateKey(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setPrivateKey(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setPrivateKey(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setPrivateKey", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setPrivateKey(QSslKey)
    // 1: setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[3])))) {
                    overloadId = 1; // setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], (pyArgs[0])))) {
        overloadId = 0; // setPrivateKey(QSslKey)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setPrivateKey_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPrivateKey(const QSslKey & key)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSslKey cppArg0_local = ::QSslKey();
            ::QSslKey* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLKEY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setPrivateKey(QSslKey)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPrivateKey(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPrivateKey(const QString & fileName, QSsl::KeyAlgorithm algorithm, QSsl::EncodingFormat format, const QByteArray & passPhrase)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "algorithm");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setPrivateKey(): got multiple values for keyword argument 'algorithm'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_KEYALGORITHM_IDX]), (pyArgs[1]))))
                        goto Sbk_QSslSocketFunc_setPrivateKey_TypeError;
                }
                value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setPrivateKey(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_ENCODINGFORMAT_IDX]), (pyArgs[2]))))
                        goto Sbk_QSslSocketFunc_setPrivateKey_TypeError;
                }
                value = PyDict_GetItemString(kwds, "passPhrase");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setPrivateKey(): got multiple values for keyword argument 'passPhrase'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[3]))))
                        goto Sbk_QSslSocketFunc_setPrivateKey_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSsl::KeyAlgorithm cppArg1 = QSsl::Rsa;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSsl::EncodingFormat cppArg2 = QSsl::Pem;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QByteArray cppArg3_local = QByteArray();
            ::QByteArray* cppArg3 = &cppArg3_local;
            if (pythonToCpp[3]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);
            }

            if (!PyErr_Occurred()) {
                // setPrivateKey(QString,QSsl::KeyAlgorithm,QSsl::EncodingFormat,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPrivateKey(cppArg0, cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setPrivateKey_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslKey", "unicode, PySide.QtNetwork.QSsl.KeyAlgorithm = QSsl.Rsa, PySide.QtNetwork.QSsl.EncodingFormat = QSsl.Pem, PySide.QtCore.QByteArray = QByteArray()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.setPrivateKey", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setProtocol(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProtocol(QSsl::SslProtocol)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QSSL_SSLPROTOCOL_IDX]), (pyArg)))) {
        overloadId = 0; // setProtocol(QSsl::SslProtocol)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setProtocol_TypeError;

    // Call function/method
    {
        ::QSsl::SslProtocol cppArg0 = ((::QSsl::SslProtocol)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProtocol(QSsl::SslProtocol)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProtocol(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setProtocol_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSsl.SslProtocol", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setProtocol", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setReadBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadBufferSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setReadBufferSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setReadBufferSize_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadBufferSize(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReadBufferSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setReadBufferSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setReadBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setSocketDescriptor(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setSocketDescriptor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setSocketDescriptor(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setSocketDescriptor", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setSocketDescriptor(int,QAbstractSocket::SocketState,QFlags<QIODevice::OpenModeFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setSocketDescriptor(int,QAbstractSocket::SocketState,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setSocketDescriptor(int,QAbstractSocket::SocketState,QFlags<QIODevice::OpenModeFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 0; // setSocketDescriptor(int,QAbstractSocket::SocketState,QFlags<QIODevice::OpenModeFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setSocketDescriptor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setSocketDescriptor(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]), (pyArgs[1]))))
                    goto Sbk_QSslSocketFunc_setSocketDescriptor_TypeError;
            }
            value = PyDict_GetItemString(kwds, "openMode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.setSocketDescriptor(): got multiple values for keyword argument 'openMode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                    goto Sbk_QSslSocketFunc_setSocketDescriptor_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QAbstractSocket::SocketState cppArg1 = QAbstractSocket::ConnectedState;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setSocketDescriptor(int,QAbstractSocket::SocketState,QFlags<QIODevice::OpenModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setSocketDescriptor(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_setSocketDescriptor_TypeError:
        const char* overloads[] = {"int, PySide.QtNetwork.QAbstractSocket.SocketState = ConnectedState, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.setSocketDescriptor", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setSocketOption(PyObject* self, PyObject* args)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSocketOption", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSocketOption(QAbstractSocket::SocketOption,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setSocketOption(QAbstractSocket::SocketOption,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setSocketOption_TypeError;

    // Call function/method
    {
        ::QAbstractSocket::SocketOption cppArg0 = ((::QAbstractSocket::SocketOption)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSocketOption(QAbstractSocket::SocketOption,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSocketOption(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSslSocketFunc_setSocketOption_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketOption, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.setSocketOption", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_setSslConfiguration(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSslConfiguration(QSslConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QSSLCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setSslConfiguration(QSslConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_setSslConfiguration_TypeError;

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

    Sbk_QSslSocketFunc_setSslConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QSslConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.setSslConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_socketOption(PyObject* self, PyObject* pyArg)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: socketOption(QAbstractSocket::SocketOption)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX]), (pyArg)))) {
        overloadId = 0; // socketOption(QAbstractSocket::SocketOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_socketOption_TypeError;

    // Call function/method
    {
        ::QAbstractSocket::SocketOption cppArg0 = ((::QAbstractSocket::SocketOption)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // socketOption(QAbstractSocket::SocketOption)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = cppSelf->socketOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_socketOption_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QSslSocket.socketOption", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_sslConfiguration(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sslConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSslConfiguration cppResult = const_cast<const ::QSslSocket*>(cppSelf)->sslConfiguration();
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

static PyObject* Sbk_QSslSocketFunc_sslErrors(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sslErrors()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslError > cppResult = const_cast<const ::QSslSocket*>(cppSelf)->sslErrors();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLERROR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_startClientEncryption(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startClientEncryption()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startClientEncryption();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSslSocketFunc_startServerEncryption(PyObject* self)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startServerEncryption()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startServerEncryption();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSslSocketFunc_supportedCiphers(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedCiphers()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCipher > cppResult = ::QSslSocket::supportedCiphers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCIPHER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_supportsSsl(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsSsl()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QSslSocket::supportsSsl();
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

static PyObject* Sbk_QSslSocketFunc_systemCaCertificates(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemCaCertificates()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSslCertificate > cppResult = ::QSslSocket::systemCaCertificates();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QSSLCERTIFICATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSslSocketFunc_waitForBytesWritten(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForBytesWritten(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForBytesWritten", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForBytesWritten(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForBytesWritten(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForBytesWritten(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_waitForBytesWritten_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForBytesWritten(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSslSocketFunc_waitForBytesWritten_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForBytesWritten(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSslSocket::waitForBytesWritten(cppArg0) : cppSelf->waitForBytesWritten(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_waitForBytesWritten_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.waitForBytesWritten", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_waitForConnected(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForConnected(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForConnected", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForConnected(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForConnected(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForConnected(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_waitForConnected_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForConnected(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSslSocketFunc_waitForConnected_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForConnected(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->waitForConnected(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_waitForConnected_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.waitForConnected", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_waitForDisconnected(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForDisconnected(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForDisconnected", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForDisconnected(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForDisconnected(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForDisconnected(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_waitForDisconnected_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForDisconnected(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSslSocketFunc_waitForDisconnected_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForDisconnected(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->waitForDisconnected(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_waitForDisconnected_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.waitForDisconnected", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_waitForEncrypted(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForEncrypted(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForEncrypted", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForEncrypted(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForEncrypted(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForEncrypted(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_waitForEncrypted_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForEncrypted(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSslSocketFunc_waitForEncrypted_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForEncrypted(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->waitForEncrypted(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_waitForEncrypted_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.waitForEncrypted", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_waitForReadyRead(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForReadyRead(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForReadyRead", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForReadyRead(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForReadyRead(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForReadyRead(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSslSocketFunc_waitForReadyRead_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QSslSocket.waitForReadyRead(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QSslSocketFunc_waitForReadyRead_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForReadyRead(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSslSocket::waitForReadyRead(cppArg0) : cppSelf->waitForReadyRead(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_waitForReadyRead_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.waitForReadyRead", overloads);
        return 0;
}

static PyObject* Sbk_QSslSocketFunc_writeData(PyObject* self, PyObject* args)
{
    ::QSslSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSslSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSslSocketFunc_writeData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeData(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSslSocket::writeData(cppArg0, cppArg1) : cppSelf->writeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSslSocketFunc_writeData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QSslSocket.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_QSslSocket_methods[] = {
    {"abort", (PyCFunction)Sbk_QSslSocketFunc_abort, METH_NOARGS},
    {"addCaCertificate", (PyCFunction)Sbk_QSslSocketFunc_addCaCertificate, METH_O},
    {"addCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_addCaCertificates, METH_VARARGS|METH_KEYWORDS},
    {"addDefaultCaCertificate", (PyCFunction)Sbk_QSslSocketFunc_addDefaultCaCertificate, METH_O|METH_STATIC},
    {"addDefaultCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_addDefaultCaCertificates, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"atEnd", (PyCFunction)Sbk_QSslSocketFunc_atEnd, METH_NOARGS},
    {"bytesAvailable", (PyCFunction)Sbk_QSslSocketFunc_bytesAvailable, METH_NOARGS},
    {"bytesToWrite", (PyCFunction)Sbk_QSslSocketFunc_bytesToWrite, METH_NOARGS},
    {"caCertificates", (PyCFunction)Sbk_QSslSocketFunc_caCertificates, METH_NOARGS},
    {"canReadLine", (PyCFunction)Sbk_QSslSocketFunc_canReadLine, METH_NOARGS},
    {"ciphers", (PyCFunction)Sbk_QSslSocketFunc_ciphers, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QSslSocketFunc_close, METH_NOARGS},
    {"connectToHostEncrypted", (PyCFunction)Sbk_QSslSocketFunc_connectToHostEncrypted, METH_VARARGS|METH_KEYWORDS},
    {"connectToHostImplementation", (PyCFunction)Sbk_QSslSocketFunc_connectToHostImplementation, METH_VARARGS},
    {"defaultCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_defaultCaCertificates, METH_NOARGS|METH_STATIC},
    {"defaultCiphers", (PyCFunction)Sbk_QSslSocketFunc_defaultCiphers, METH_NOARGS|METH_STATIC},
    {"disconnectFromHostImplementation", (PyCFunction)Sbk_QSslSocketFunc_disconnectFromHostImplementation, METH_NOARGS},
    {"encryptedBytesAvailable", (PyCFunction)Sbk_QSslSocketFunc_encryptedBytesAvailable, METH_NOARGS},
    {"encryptedBytesToWrite", (PyCFunction)Sbk_QSslSocketFunc_encryptedBytesToWrite, METH_NOARGS},
    {"flush", (PyCFunction)Sbk_QSslSocketFunc_flush, METH_NOARGS},
    {"ignoreSslErrors", (PyCFunction)Sbk_QSslSocketFunc_ignoreSslErrors, METH_VARARGS},
    {"isEncrypted", (PyCFunction)Sbk_QSslSocketFunc_isEncrypted, METH_NOARGS},
    {"localCertificate", (PyCFunction)Sbk_QSslSocketFunc_localCertificate, METH_NOARGS},
    {"mode", (PyCFunction)Sbk_QSslSocketFunc_mode, METH_NOARGS},
    {"peerCertificate", (PyCFunction)Sbk_QSslSocketFunc_peerCertificate, METH_NOARGS},
    {"peerCertificateChain", (PyCFunction)Sbk_QSslSocketFunc_peerCertificateChain, METH_NOARGS},
    {"peerVerifyDepth", (PyCFunction)Sbk_QSslSocketFunc_peerVerifyDepth, METH_NOARGS},
    {"peerVerifyMode", (PyCFunction)Sbk_QSslSocketFunc_peerVerifyMode, METH_NOARGS},
    {"peerVerifyName", (PyCFunction)Sbk_QSslSocketFunc_peerVerifyName, METH_NOARGS},
    {"privateKey", (PyCFunction)Sbk_QSslSocketFunc_privateKey, METH_NOARGS},
    {"protocol", (PyCFunction)Sbk_QSslSocketFunc_protocol, METH_NOARGS},
    {"readData", (PyCFunction)Sbk_QSslSocketFunc_readData, METH_O},
    {"sessionCipher", (PyCFunction)Sbk_QSslSocketFunc_sessionCipher, METH_NOARGS},
    {"setCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_setCaCertificates, METH_O},
    {"setCiphers", (PyCFunction)Sbk_QSslSocketFunc_setCiphers, METH_O},
    {"setDefaultCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_setDefaultCaCertificates, METH_O|METH_STATIC},
    {"setDefaultCiphers", (PyCFunction)Sbk_QSslSocketFunc_setDefaultCiphers, METH_O|METH_STATIC},
    {"setLocalCertificate", (PyCFunction)Sbk_QSslSocketFunc_setLocalCertificate, METH_VARARGS|METH_KEYWORDS},
    {"setPeerVerifyDepth", (PyCFunction)Sbk_QSslSocketFunc_setPeerVerifyDepth, METH_O},
    {"setPeerVerifyMode", (PyCFunction)Sbk_QSslSocketFunc_setPeerVerifyMode, METH_O},
    {"setPeerVerifyName", (PyCFunction)Sbk_QSslSocketFunc_setPeerVerifyName, METH_O},
    {"setPrivateKey", (PyCFunction)Sbk_QSslSocketFunc_setPrivateKey, METH_VARARGS|METH_KEYWORDS},
    {"setProtocol", (PyCFunction)Sbk_QSslSocketFunc_setProtocol, METH_O},
    {"setReadBufferSize", (PyCFunction)Sbk_QSslSocketFunc_setReadBufferSize, METH_O},
    {"setSocketDescriptor", (PyCFunction)Sbk_QSslSocketFunc_setSocketDescriptor, METH_VARARGS|METH_KEYWORDS},
    {"setSocketOption", (PyCFunction)Sbk_QSslSocketFunc_setSocketOption, METH_VARARGS},
    {"setSslConfiguration", (PyCFunction)Sbk_QSslSocketFunc_setSslConfiguration, METH_O},
    {"socketOption", (PyCFunction)Sbk_QSslSocketFunc_socketOption, METH_O},
    {"sslConfiguration", (PyCFunction)Sbk_QSslSocketFunc_sslConfiguration, METH_NOARGS},
    {"sslErrors", (PyCFunction)Sbk_QSslSocketFunc_sslErrors, METH_NOARGS},
    {"startClientEncryption", (PyCFunction)Sbk_QSslSocketFunc_startClientEncryption, METH_NOARGS},
    {"startServerEncryption", (PyCFunction)Sbk_QSslSocketFunc_startServerEncryption, METH_NOARGS},
    {"supportedCiphers", (PyCFunction)Sbk_QSslSocketFunc_supportedCiphers, METH_NOARGS|METH_STATIC},
    {"supportsSsl", (PyCFunction)Sbk_QSslSocketFunc_supportsSsl, METH_NOARGS|METH_STATIC},
    {"systemCaCertificates", (PyCFunction)Sbk_QSslSocketFunc_systemCaCertificates, METH_NOARGS|METH_STATIC},
    {"waitForBytesWritten", (PyCFunction)Sbk_QSslSocketFunc_waitForBytesWritten, METH_VARARGS|METH_KEYWORDS},
    {"waitForConnected", (PyCFunction)Sbk_QSslSocketFunc_waitForConnected, METH_VARARGS|METH_KEYWORDS},
    {"waitForDisconnected", (PyCFunction)Sbk_QSslSocketFunc_waitForDisconnected, METH_VARARGS|METH_KEYWORDS},
    {"waitForEncrypted", (PyCFunction)Sbk_QSslSocketFunc_waitForEncrypted, METH_VARARGS|METH_KEYWORDS},
    {"waitForReadyRead", (PyCFunction)Sbk_QSslSocketFunc_waitForReadyRead, METH_VARARGS|METH_KEYWORDS},
    {"writeData", (PyCFunction)Sbk_QSslSocketFunc_writeData, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSslSocket_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSslSocket_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSslSocket_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QSslSocket",
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
    /*tp_traverse*/         Sbk_QSslSocket_traverse,
    /*tp_clear*/            Sbk_QSslSocket_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSslSocket_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSslSocket_Init,
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

static void* Sbk_QSslSocket_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSslSocket*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSslSocket_SslMode_PythonToCpp_QSslSocket_SslMode(PyObject* pyIn, void* cppOut) {
    *((::QSslSocket::SslMode*)cppOut) = (::QSslSocket::SslMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSslSocket_SslMode_PythonToCpp_QSslSocket_SslMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX]))
        return QSslSocket_SslMode_PythonToCpp_QSslSocket_SslMode;
    return 0;
}
static PyObject* QSslSocket_SslMode_CppToPython_QSslSocket_SslMode(const void* cppIn) {
    int castCppIn = *((::QSslSocket::SslMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX], castCppIn);

}

static void QSslSocket_PeerVerifyMode_PythonToCpp_QSslSocket_PeerVerifyMode(PyObject* pyIn, void* cppOut) {
    *((::QSslSocket::PeerVerifyMode*)cppOut) = (::QSslSocket::PeerVerifyMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSslSocket_PeerVerifyMode_PythonToCpp_QSslSocket_PeerVerifyMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX]))
        return QSslSocket_PeerVerifyMode_PythonToCpp_QSslSocket_PeerVerifyMode;
    return 0;
}
static PyObject* QSslSocket_PeerVerifyMode_CppToPython_QSslSocket_PeerVerifyMode(const void* cppIn) {
    int castCppIn = *((::QSslSocket::PeerVerifyMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSslSocket_PythonToCpp_QSslSocket_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSslSocket_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSslSocket_PythonToCpp_QSslSocket_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSslSocket_Type))
        return QSslSocket_PythonToCpp_QSslSocket_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSslSocket_PTR_CppToPython_QSslSocket(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSslSocket*)cppIn, &Sbk_QSslSocket_Type);

}

void init_QSslSocket(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSslSocket_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSslSocket", "QSslSocket*",
        &Sbk_QSslSocket_Type, &Shiboken::callCppDestructor< ::QSslSocket >, (SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QTCPSOCKET_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSslSocket_Type,
        QSslSocket_PythonToCpp_QSslSocket_PTR,
        is_QSslSocket_PythonToCpp_QSslSocket_PTR_Convertible,
        QSslSocket_PTR_CppToPython_QSslSocket);

    Shiboken::Conversions::registerConverterName(converter, "QSslSocket");
    Shiboken::Conversions::registerConverterName(converter, "QSslSocket*");
    Shiboken::Conversions::registerConverterName(converter, "QSslSocket&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslSocket).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSslSocketWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSslSocket_Type, &Sbk_QSslSocket_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'SslMode'.
    SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSslSocket_Type,
        "SslMode",
        "PySide.QtNetwork.QSslSocket.SslMode",
        "QSslSocket::SslMode");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX],
        &Sbk_QSslSocket_Type, "UnencryptedMode", (long) QSslSocket::UnencryptedMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX],
        &Sbk_QSslSocket_Type, "SslClientMode", (long) QSslSocket::SslClientMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX],
        &Sbk_QSslSocket_Type, "SslServerMode", (long) QSslSocket::SslServerMode))
        return ;
    // Register converter for enum 'QSslSocket::SslMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX],
            QSslSocket_SslMode_CppToPython_QSslSocket_SslMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSslSocket_SslMode_PythonToCpp_QSslSocket_SslMode,
            is_QSslSocket_SslMode_PythonToCpp_QSslSocket_SslMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_SSLMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSslSocket::SslMode");
        Shiboken::Conversions::registerConverterName(converter, "SslMode");
    }
    // End of 'SslMode' enum.

    // Initialization of enum 'PeerVerifyMode'.
    SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSslSocket_Type,
        "PeerVerifyMode",
        "PySide.QtNetwork.QSslSocket.PeerVerifyMode",
        "QSslSocket::PeerVerifyMode");
    if (!SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX],
        &Sbk_QSslSocket_Type, "VerifyNone", (long) QSslSocket::VerifyNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX],
        &Sbk_QSslSocket_Type, "QueryPeer", (long) QSslSocket::QueryPeer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX],
        &Sbk_QSslSocket_Type, "VerifyPeer", (long) QSslSocket::VerifyPeer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX],
        &Sbk_QSslSocket_Type, "AutoVerifyPeer", (long) QSslSocket::AutoVerifyPeer))
        return ;
    // Register converter for enum 'QSslSocket::PeerVerifyMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX],
            QSslSocket_PeerVerifyMode_CppToPython_QSslSocket_PeerVerifyMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSslSocket_PeerVerifyMode_PythonToCpp_QSslSocket_PeerVerifyMode,
            is_QSslSocket_PeerVerifyMode_PythonToCpp_QSslSocket_PeerVerifyMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QSSLSOCKET_PEERVERIFYMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSslSocket::PeerVerifyMode");
        Shiboken::Conversions::registerConverterName(converter, "PeerVerifyMode");
    }
    // End of 'PeerVerifyMode' enum.

    PySide::Signal::registerSignals(&Sbk_QSslSocket_Type, &::QSslSocket::staticMetaObject);

    qRegisterMetaType< ::QSslSocket::SslMode >("QSslSocket::SslMode");
    qRegisterMetaType< ::QSslSocket::PeerVerifyMode >("QSslSocket::PeerVerifyMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSslSocket_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSslSocket_Type, &::QSslSocket::staticMetaObject, sizeof(::QSslSocket));
}
