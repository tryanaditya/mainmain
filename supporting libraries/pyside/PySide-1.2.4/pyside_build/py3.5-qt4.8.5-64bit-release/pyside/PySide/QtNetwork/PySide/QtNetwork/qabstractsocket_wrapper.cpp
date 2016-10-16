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

#include "qabstractsocket_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractsocket.h>
#include <qauthenticator.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qhostaddress.h>
#include <qmetaobject.h>
#include <qnetworkproxy.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QAbstractSocketWrapper::QAbstractSocketWrapper(QAbstractSocket::SocketType socketType, QObject * parent) : QAbstractSocket(socketType, parent) {
    // ... middle
}

bool QAbstractSocketWrapper::atEnd() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atEnd"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::atEnd();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.atEnd", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::bytesAvailable() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesAvailable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::bytesAvailable();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.bytesAvailable", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::bytesToWrite() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesToWrite"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::bytesToWrite();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.bytesToWrite", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractSocketWrapper::canReadLine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canReadLine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::canReadLine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.canReadLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSocketWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractSocketWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractSocketWrapper::connectNotify(const char * signal)
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

void QAbstractSocketWrapper::customEvent(QEvent * arg__1)
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

void QAbstractSocketWrapper::disconnectNotify(const char * signal)
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

bool QAbstractSocketWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractSocketWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QAbstractSocketWrapper::isSequential() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractSocketWrapper::open(QFlags<QIODevice::OpenModeFlag> mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::pos() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::readData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractSocket::readData(data, maxlen);
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

qint64 QAbstractSocketWrapper::readLineData(char * data, qint64 maxlen)
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

bool QAbstractSocketWrapper::reset()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractSocketWrapper::seek(qint64 pos)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::size() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSocketWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QAbstractSocketWrapper::waitForBytesWritten(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForBytesWritten"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::waitForBytesWritten(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.waitForBytesWritten", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractSocketWrapper::waitForReadyRead(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForReadyRead"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::waitForReadyRead(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.waitForReadyRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QAbstractSocketWrapper::writeData(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSocket::writeData(data, len);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSocket.writeData", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QAbstractSocketWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractSocket::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractSocketWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractSocket::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractSocketWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractSocketWrapper* >(this));
        return QAbstractSocket::qt_metacast(_clname);
}

QAbstractSocketWrapper::~QAbstractSocketWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractSocket_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractSocket >()))
        return -1;

    ::QAbstractSocketWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAbstractSocket", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractSocket(QAbstractSocket::SocketType,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // QAbstractSocket(QAbstractSocket::SocketType,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocket_Init_TypeError;

    // Call function/method
    {
        ::QAbstractSocket::SocketType cppArg0 = ((::QAbstractSocket::SocketType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QAbstractSocket(QAbstractSocket::SocketType,QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractSocketWrapper(cppArg0, cppArg1);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractSocketWrapper(cppArg0, cppArg1);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[1], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractSocket >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractSocket_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QAbstractSocket_Init_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketType, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractSocketFunc_abort(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QAbstractSocketFunc_atEnd(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSocket*>(cppSelf)->::QAbstractSocket::atEnd() : const_cast<const ::QAbstractSocket*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QAbstractSocketFunc_bytesAvailable(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSocket*>(cppSelf)->::QAbstractSocket::bytesAvailable() : const_cast<const ::QAbstractSocket*>(cppSelf)->bytesAvailable();
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

static PyObject* Sbk_QAbstractSocketFunc_bytesToWrite(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesToWrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSocket*>(cppSelf)->::QAbstractSocket::bytesToWrite() : const_cast<const ::QAbstractSocket*>(cppSelf)->bytesToWrite();
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

static PyObject* Sbk_QAbstractSocketFunc_canReadLine(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canReadLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSocket*>(cppSelf)->::QAbstractSocket::canReadLine() : const_cast<const ::QAbstractSocket*>(cppSelf)->canReadLine();
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

static PyObject* Sbk_QAbstractSocketFunc_close(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::close() : cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSocketFunc_connectToHost(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHost(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHost(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:connectToHost", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: connectToHost(QHostAddress,quint16,QFlags<QIODevice::OpenModeFlag>)
    // 1: connectToHost(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // connectToHost(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 1; // connectToHost(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // connectToHost(QHostAddress,quint16,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 0; // connectToHost(QHostAddress,quint16,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_connectToHost_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // connectToHost(const QHostAddress & address, quint16 port, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHost(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QAbstractSocketFunc_connectToHost_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QHostAddress cppArg0_local = ::QHostAddress();
            ::QHostAddress* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            quint16 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // connectToHost(QHostAddress,quint16,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->connectToHost(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // connectToHost(const QString & hostName, quint16 port, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHost(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QAbstractSocketFunc_connectToHost_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            quint16 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // connectToHost(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->connectToHost(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_connectToHost_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress, unsigned short, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", "unicode, unsigned short, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.connectToHost", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_connectToHostImplementation(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHostImplementation(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHostImplementation(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:connectToHostImplementation", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 0; // connectToHostImplementation(QString,quint16,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_connectToHostImplementation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.connectToHostImplementation(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                    goto Sbk_QAbstractSocketFunc_connectToHostImplementation_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        quint16 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

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

    Sbk_QAbstractSocketFunc_connectToHostImplementation_TypeError:
        const char* overloads[] = {"unicode, unsigned short, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.connectToHostImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_disconnectFromHost(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // disconnectFromHost()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->disconnectFromHost();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSocketFunc_disconnectFromHostImplementation(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QAbstractSocketFunc_error(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSocket::SocketError cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_flush(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QAbstractSocketFunc_isSequential(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSequential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSocket*>(cppSelf)->::QAbstractSocket::isSequential() : const_cast<const ::QAbstractSocket*>(cppSelf)->isSequential();
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

static PyObject* Sbk_QAbstractSocketFunc_isValid(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->isValid();
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

static PyObject* Sbk_QAbstractSocketFunc_localAddress(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localAddress()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostAddress cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->localAddress();
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

static PyObject* Sbk_QAbstractSocketFunc_localPort(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // localPort()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint16 cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->localPort();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_peerAddress(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerAddress()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHostAddress cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->peerAddress();
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

static PyObject* Sbk_QAbstractSocketFunc_peerName(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->peerName();
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

static PyObject* Sbk_QAbstractSocketFunc_peerPort(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // peerPort()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint16 cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->peerPort();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_proxy(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxy cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->proxy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_readBufferSize(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readBufferSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->readBufferSize();
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

static PyObject* Sbk_QAbstractSocketFunc_readData(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_readData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::readData(ba.data(), ba.size()) : cppSelf->readData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSocketFunc_readData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.readData", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_readLineData(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: readLineData(char*,qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // readLineData(char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_readLineData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readLineData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::readLineData(ba.data(), ba.size()) : cppSelf->readLineData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSocketFunc_readLineData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.readLineData", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setLocalAddress(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocalAddress(QHostAddress)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setLocalAddress(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setLocalAddress_TypeError;

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
            // setLocalAddress(QHostAddress)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocalAddress(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setLocalAddress_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setLocalAddress", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setLocalPort(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLocalPort(quint16)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArg)))) {
        overloadId = 0; // setLocalPort(quint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setLocalPort_TypeError;

    // Call function/method
    {
        quint16 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLocalPort(quint16)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLocalPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setLocalPort_TypeError:
        const char* overloads[] = {"unsigned short", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setLocalPort", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setPeerAddress(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerAddress(QHostAddress)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHOSTADDRESS_IDX], (pyArg)))) {
        overloadId = 0; // setPeerAddress(QHostAddress)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setPeerAddress_TypeError;

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
            // setPeerAddress(QHostAddress)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerAddress(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setPeerAddress_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHostAddress", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setPeerAddress", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setPeerName(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPeerName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setPeerName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setPeerName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setPeerName", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setPeerPort(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPeerPort(quint16)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArg)))) {
        overloadId = 0; // setPeerPort(quint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setPeerPort_TypeError;

    // Call function/method
    {
        quint16 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPeerPort(quint16)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPeerPort(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setPeerPort_TypeError:
        const char* overloads[] = {"unsigned short", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setPeerPort", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setProxy(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProxy(QNetworkProxy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArg)))) {
        overloadId = 0; // setProxy(QNetworkProxy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setProxy_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
        ::QNetworkProxy* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setProxy(QNetworkProxy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProxy(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setProxy_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setProxy", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setReadBufferSize(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadBufferSize(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // setReadBufferSize(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setReadBufferSize_TypeError;

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

    Sbk_QAbstractSocketFunc_setReadBufferSize_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setReadBufferSize", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setSocketDescriptor(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.setSocketDescriptor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.setSocketDescriptor(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setSocketDescriptor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.setSocketDescriptor(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]), (pyArgs[1]))))
                    goto Sbk_QAbstractSocketFunc_setSocketDescriptor_TypeError;
            }
            value = PyDict_GetItemString(kwds, "openMode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.setSocketDescriptor(): got multiple values for keyword argument 'openMode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                    goto Sbk_QAbstractSocketFunc_setSocketDescriptor_TypeError;
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

    Sbk_QAbstractSocketFunc_setSocketDescriptor_TypeError:
        const char* overloads[] = {"int, PySide.QtNetwork.QAbstractSocket.SocketState = ConnectedState, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.setSocketDescriptor", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setSocketError(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSocketError(QAbstractSocket::SocketError)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX]), (pyArg)))) {
        overloadId = 0; // setSocketError(QAbstractSocket::SocketError)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setSocketError_TypeError;

    // Call function/method
    {
        ::QAbstractSocket::SocketError cppArg0 = ((::QAbstractSocket::SocketError)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSocketError(QAbstractSocket::SocketError)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSocketError(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setSocketError_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketError", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setSocketError", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setSocketOption(PyObject* self, PyObject* args)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setSocketOption_TypeError;

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

    Sbk_QAbstractSocketFunc_setSocketOption_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketOption, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.setSocketOption", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_setSocketState(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSocketState(QAbstractSocket::SocketState)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]), (pyArg)))) {
        overloadId = 0; // setSocketState(QAbstractSocket::SocketState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_setSocketState_TypeError;

    // Call function/method
    {
        ::QAbstractSocket::SocketState cppArg0 = ((::QAbstractSocket::SocketState)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSocketState(QAbstractSocket::SocketState)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSocketState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSocketFunc_setSocketState_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.setSocketState", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_socketDescriptor(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // socketDescriptor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->socketDescriptor();
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

static PyObject* Sbk_QAbstractSocketFunc_socketOption(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_socketOption_TypeError;

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

    Sbk_QAbstractSocketFunc_socketOption_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractSocket.SocketOption", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QAbstractSocket.socketOption", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_socketType(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // socketType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSocket::SocketType cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->socketType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_state(PyObject* self)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSocket::SocketState cppResult = const_cast<const ::QAbstractSocket*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSocketFunc_waitForBytesWritten(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForBytesWritten(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_waitForBytesWritten_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForBytesWritten(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QAbstractSocketFunc_waitForBytesWritten_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForBytesWritten(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::waitForBytesWritten(cppArg0) : cppSelf->waitForBytesWritten(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSocketFunc_waitForBytesWritten_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.waitForBytesWritten", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_waitForConnected(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForConnected(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_waitForConnected_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForConnected(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QAbstractSocketFunc_waitForConnected_TypeError;
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

    Sbk_QAbstractSocketFunc_waitForConnected_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.waitForConnected", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_waitForDisconnected(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForDisconnected(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_waitForDisconnected_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForDisconnected(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QAbstractSocketFunc_waitForDisconnected_TypeError;
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

    Sbk_QAbstractSocketFunc_waitForDisconnected_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.waitForDisconnected", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_waitForReadyRead(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForReadyRead(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_waitForReadyRead_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QAbstractSocket.waitForReadyRead(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QAbstractSocketFunc_waitForReadyRead_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForReadyRead(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::waitForReadyRead(cppArg0) : cppSelf->waitForReadyRead(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSocketFunc_waitForReadyRead_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.waitForReadyRead", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSocketFunc_writeData(PyObject* self, PyObject* args)
{
    ::QAbstractSocket* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSocket*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSocketFunc_writeData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeData(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSocket::writeData(cppArg0, cppArg1) : cppSelf->writeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSocketFunc_writeData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QAbstractSocket.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractSocket_methods[] = {
    {"abort", (PyCFunction)Sbk_QAbstractSocketFunc_abort, METH_NOARGS},
    {"atEnd", (PyCFunction)Sbk_QAbstractSocketFunc_atEnd, METH_NOARGS},
    {"bytesAvailable", (PyCFunction)Sbk_QAbstractSocketFunc_bytesAvailable, METH_NOARGS},
    {"bytesToWrite", (PyCFunction)Sbk_QAbstractSocketFunc_bytesToWrite, METH_NOARGS},
    {"canReadLine", (PyCFunction)Sbk_QAbstractSocketFunc_canReadLine, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QAbstractSocketFunc_close, METH_NOARGS},
    {"connectToHost", (PyCFunction)Sbk_QAbstractSocketFunc_connectToHost, METH_VARARGS|METH_KEYWORDS},
    {"connectToHostImplementation", (PyCFunction)Sbk_QAbstractSocketFunc_connectToHostImplementation, METH_VARARGS|METH_KEYWORDS},
    {"disconnectFromHost", (PyCFunction)Sbk_QAbstractSocketFunc_disconnectFromHost, METH_NOARGS},
    {"disconnectFromHostImplementation", (PyCFunction)Sbk_QAbstractSocketFunc_disconnectFromHostImplementation, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QAbstractSocketFunc_error, METH_NOARGS},
    {"flush", (PyCFunction)Sbk_QAbstractSocketFunc_flush, METH_NOARGS},
    {"isSequential", (PyCFunction)Sbk_QAbstractSocketFunc_isSequential, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QAbstractSocketFunc_isValid, METH_NOARGS},
    {"localAddress", (PyCFunction)Sbk_QAbstractSocketFunc_localAddress, METH_NOARGS},
    {"localPort", (PyCFunction)Sbk_QAbstractSocketFunc_localPort, METH_NOARGS},
    {"peerAddress", (PyCFunction)Sbk_QAbstractSocketFunc_peerAddress, METH_NOARGS},
    {"peerName", (PyCFunction)Sbk_QAbstractSocketFunc_peerName, METH_NOARGS},
    {"peerPort", (PyCFunction)Sbk_QAbstractSocketFunc_peerPort, METH_NOARGS},
    {"proxy", (PyCFunction)Sbk_QAbstractSocketFunc_proxy, METH_NOARGS},
    {"readBufferSize", (PyCFunction)Sbk_QAbstractSocketFunc_readBufferSize, METH_NOARGS},
    {"readData", (PyCFunction)Sbk_QAbstractSocketFunc_readData, METH_O},
    {"readLineData", (PyCFunction)Sbk_QAbstractSocketFunc_readLineData, METH_O},
    {"setLocalAddress", (PyCFunction)Sbk_QAbstractSocketFunc_setLocalAddress, METH_O},
    {"setLocalPort", (PyCFunction)Sbk_QAbstractSocketFunc_setLocalPort, METH_O},
    {"setPeerAddress", (PyCFunction)Sbk_QAbstractSocketFunc_setPeerAddress, METH_O},
    {"setPeerName", (PyCFunction)Sbk_QAbstractSocketFunc_setPeerName, METH_O},
    {"setPeerPort", (PyCFunction)Sbk_QAbstractSocketFunc_setPeerPort, METH_O},
    {"setProxy", (PyCFunction)Sbk_QAbstractSocketFunc_setProxy, METH_O},
    {"setReadBufferSize", (PyCFunction)Sbk_QAbstractSocketFunc_setReadBufferSize, METH_O},
    {"setSocketDescriptor", (PyCFunction)Sbk_QAbstractSocketFunc_setSocketDescriptor, METH_VARARGS|METH_KEYWORDS},
    {"setSocketError", (PyCFunction)Sbk_QAbstractSocketFunc_setSocketError, METH_O},
    {"setSocketOption", (PyCFunction)Sbk_QAbstractSocketFunc_setSocketOption, METH_VARARGS},
    {"setSocketState", (PyCFunction)Sbk_QAbstractSocketFunc_setSocketState, METH_O},
    {"socketDescriptor", (PyCFunction)Sbk_QAbstractSocketFunc_socketDescriptor, METH_NOARGS},
    {"socketOption", (PyCFunction)Sbk_QAbstractSocketFunc_socketOption, METH_O},
    {"socketType", (PyCFunction)Sbk_QAbstractSocketFunc_socketType, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QAbstractSocketFunc_state, METH_NOARGS},
    {"waitForBytesWritten", (PyCFunction)Sbk_QAbstractSocketFunc_waitForBytesWritten, METH_VARARGS|METH_KEYWORDS},
    {"waitForConnected", (PyCFunction)Sbk_QAbstractSocketFunc_waitForConnected, METH_VARARGS|METH_KEYWORDS},
    {"waitForDisconnected", (PyCFunction)Sbk_QAbstractSocketFunc_waitForDisconnected, METH_VARARGS|METH_KEYWORDS},
    {"waitForReadyRead", (PyCFunction)Sbk_QAbstractSocketFunc_waitForReadyRead, METH_VARARGS|METH_KEYWORDS},
    {"writeData", (PyCFunction)Sbk_QAbstractSocketFunc_writeData, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractSocket_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractSocket_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractSocket_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QAbstractSocket",
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
    /*tp_traverse*/         Sbk_QAbstractSocket_traverse,
    /*tp_clear*/            Sbk_QAbstractSocket_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractSocket_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractSocket_Init,
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

static void* Sbk_QAbstractSocket_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractSocket*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QAbstractSocket_SocketType_PythonToCpp_QAbstractSocket_SocketType(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSocket::SocketType*)cppOut) = (::QAbstractSocket::SocketType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSocket_SocketType_PythonToCpp_QAbstractSocket_SocketType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX]))
        return QAbstractSocket_SocketType_PythonToCpp_QAbstractSocket_SocketType;
    return 0;
}
static PyObject* QAbstractSocket_SocketType_CppToPython_QAbstractSocket_SocketType(const void* cppIn) {
    int castCppIn = *((::QAbstractSocket::SocketType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX], castCppIn);

}

static void QAbstractSocket_NetworkLayerProtocol_PythonToCpp_QAbstractSocket_NetworkLayerProtocol(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSocket::NetworkLayerProtocol*)cppOut) = (::QAbstractSocket::NetworkLayerProtocol) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSocket_NetworkLayerProtocol_PythonToCpp_QAbstractSocket_NetworkLayerProtocol_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX]))
        return QAbstractSocket_NetworkLayerProtocol_PythonToCpp_QAbstractSocket_NetworkLayerProtocol;
    return 0;
}
static PyObject* QAbstractSocket_NetworkLayerProtocol_CppToPython_QAbstractSocket_NetworkLayerProtocol(const void* cppIn) {
    int castCppIn = *((::QAbstractSocket::NetworkLayerProtocol*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX], castCppIn);

}

static void QAbstractSocket_SocketError_PythonToCpp_QAbstractSocket_SocketError(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSocket::SocketError*)cppOut) = (::QAbstractSocket::SocketError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSocket_SocketError_PythonToCpp_QAbstractSocket_SocketError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX]))
        return QAbstractSocket_SocketError_PythonToCpp_QAbstractSocket_SocketError;
    return 0;
}
static PyObject* QAbstractSocket_SocketError_CppToPython_QAbstractSocket_SocketError(const void* cppIn) {
    int castCppIn = *((::QAbstractSocket::SocketError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX], castCppIn);

}

static void QAbstractSocket_SocketState_PythonToCpp_QAbstractSocket_SocketState(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSocket::SocketState*)cppOut) = (::QAbstractSocket::SocketState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSocket_SocketState_PythonToCpp_QAbstractSocket_SocketState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX]))
        return QAbstractSocket_SocketState_PythonToCpp_QAbstractSocket_SocketState;
    return 0;
}
static PyObject* QAbstractSocket_SocketState_CppToPython_QAbstractSocket_SocketState(const void* cppIn) {
    int castCppIn = *((::QAbstractSocket::SocketState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX], castCppIn);

}

static void QAbstractSocket_SocketOption_PythonToCpp_QAbstractSocket_SocketOption(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSocket::SocketOption*)cppOut) = (::QAbstractSocket::SocketOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSocket_SocketOption_PythonToCpp_QAbstractSocket_SocketOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX]))
        return QAbstractSocket_SocketOption_PythonToCpp_QAbstractSocket_SocketOption;
    return 0;
}
static PyObject* QAbstractSocket_SocketOption_CppToPython_QAbstractSocket_SocketOption(const void* cppIn) {
    int castCppIn = *((::QAbstractSocket::SocketOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractSocket_PythonToCpp_QAbstractSocket_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractSocket_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractSocket_PythonToCpp_QAbstractSocket_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractSocket_Type))
        return QAbstractSocket_PythonToCpp_QAbstractSocket_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractSocket_PTR_CppToPython_QAbstractSocket(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractSocket*)cppIn, &Sbk_QAbstractSocket_Type);

}

void init_QAbstractSocket(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractSocket_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractSocket", "QAbstractSocket*",
        &Sbk_QAbstractSocket_Type, &Shiboken::callCppDestructor< ::QAbstractSocket >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractSocket_Type,
        QAbstractSocket_PythonToCpp_QAbstractSocket_PTR,
        is_QAbstractSocket_PythonToCpp_QAbstractSocket_PTR_Convertible,
        QAbstractSocket_PTR_CppToPython_QAbstractSocket);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractSocket).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractSocketWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractSocket_Type, &Sbk_QAbstractSocket_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'SocketType'.
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSocket_Type,
        "SocketType",
        "PySide.QtNetwork.QAbstractSocket.SocketType",
        "QAbstractSocket::SocketType");
    if (!SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX],
        &Sbk_QAbstractSocket_Type, "TcpSocket", (long) QAbstractSocket::TcpSocket))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX],
        &Sbk_QAbstractSocket_Type, "UdpSocket", (long) QAbstractSocket::UdpSocket))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX],
        &Sbk_QAbstractSocket_Type, "UnknownSocketType", (long) QAbstractSocket::UnknownSocketType))
        return ;
    // Register converter for enum 'QAbstractSocket::SocketType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX],
            QAbstractSocket_SocketType_CppToPython_QAbstractSocket_SocketType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSocket_SocketType_PythonToCpp_QAbstractSocket_SocketType,
            is_QAbstractSocket_SocketType_PythonToCpp_QAbstractSocket_SocketType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket::SocketType");
        Shiboken::Conversions::registerConverterName(converter, "SocketType");
    }
    // End of 'SocketType' enum.

    // Initialization of enum 'NetworkLayerProtocol'.
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSocket_Type,
        "NetworkLayerProtocol",
        "PySide.QtNetwork.QAbstractSocket.NetworkLayerProtocol",
        "QAbstractSocket::NetworkLayerProtocol");
    if (!SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX],
        &Sbk_QAbstractSocket_Type, "IPv4Protocol", (long) QAbstractSocket::IPv4Protocol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX],
        &Sbk_QAbstractSocket_Type, "IPv6Protocol", (long) QAbstractSocket::IPv6Protocol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX],
        &Sbk_QAbstractSocket_Type, "UnknownNetworkLayerProtocol", (long) QAbstractSocket::UnknownNetworkLayerProtocol))
        return ;
    // Register converter for enum 'QAbstractSocket::NetworkLayerProtocol'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX],
            QAbstractSocket_NetworkLayerProtocol_CppToPython_QAbstractSocket_NetworkLayerProtocol);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSocket_NetworkLayerProtocol_PythonToCpp_QAbstractSocket_NetworkLayerProtocol,
            is_QAbstractSocket_NetworkLayerProtocol_PythonToCpp_QAbstractSocket_NetworkLayerProtocol_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_NETWORKLAYERPROTOCOL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket::NetworkLayerProtocol");
        Shiboken::Conversions::registerConverterName(converter, "NetworkLayerProtocol");
    }
    // End of 'NetworkLayerProtocol' enum.

    // Initialization of enum 'SocketError'.
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSocket_Type,
        "SocketError",
        "PySide.QtNetwork.QAbstractSocket.SocketError",
        "QAbstractSocket::SocketError");
    if (!SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ConnectionRefusedError", (long) QAbstractSocket::ConnectionRefusedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "RemoteHostClosedError", (long) QAbstractSocket::RemoteHostClosedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "HostNotFoundError", (long) QAbstractSocket::HostNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "SocketAccessError", (long) QAbstractSocket::SocketAccessError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "SocketResourceError", (long) QAbstractSocket::SocketResourceError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "SocketTimeoutError", (long) QAbstractSocket::SocketTimeoutError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "DatagramTooLargeError", (long) QAbstractSocket::DatagramTooLargeError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "NetworkError", (long) QAbstractSocket::NetworkError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "AddressInUseError", (long) QAbstractSocket::AddressInUseError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "SocketAddressNotAvailableError", (long) QAbstractSocket::SocketAddressNotAvailableError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "UnsupportedSocketOperationError", (long) QAbstractSocket::UnsupportedSocketOperationError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "UnfinishedSocketOperationError", (long) QAbstractSocket::UnfinishedSocketOperationError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyAuthenticationRequiredError", (long) QAbstractSocket::ProxyAuthenticationRequiredError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "SslHandshakeFailedError", (long) QAbstractSocket::SslHandshakeFailedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyConnectionRefusedError", (long) QAbstractSocket::ProxyConnectionRefusedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyConnectionClosedError", (long) QAbstractSocket::ProxyConnectionClosedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyConnectionTimeoutError", (long) QAbstractSocket::ProxyConnectionTimeoutError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyNotFoundError", (long) QAbstractSocket::ProxyNotFoundError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "ProxyProtocolError", (long) QAbstractSocket::ProxyProtocolError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
        &Sbk_QAbstractSocket_Type, "UnknownSocketError", (long) QAbstractSocket::UnknownSocketError))
        return ;
    // Register converter for enum 'QAbstractSocket::SocketError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX],
            QAbstractSocket_SocketError_CppToPython_QAbstractSocket_SocketError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSocket_SocketError_PythonToCpp_QAbstractSocket_SocketError,
            is_QAbstractSocket_SocketError_PythonToCpp_QAbstractSocket_SocketError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket::SocketError");
        Shiboken::Conversions::registerConverterName(converter, "SocketError");
    }
    // End of 'SocketError' enum.

    // Initialization of enum 'SocketState'.
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSocket_Type,
        "SocketState",
        "PySide.QtNetwork.QAbstractSocket.SocketState",
        "QAbstractSocket::SocketState");
    if (!SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "UnconnectedState", (long) QAbstractSocket::UnconnectedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "HostLookupState", (long) QAbstractSocket::HostLookupState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "ConnectingState", (long) QAbstractSocket::ConnectingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "ConnectedState", (long) QAbstractSocket::ConnectedState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "BoundState", (long) QAbstractSocket::BoundState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "ListeningState", (long) QAbstractSocket::ListeningState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
        &Sbk_QAbstractSocket_Type, "ClosingState", (long) QAbstractSocket::ClosingState))
        return ;
    // Register converter for enum 'QAbstractSocket::SocketState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX],
            QAbstractSocket_SocketState_CppToPython_QAbstractSocket_SocketState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSocket_SocketState_PythonToCpp_QAbstractSocket_SocketState,
            is_QAbstractSocket_SocketState_PythonToCpp_QAbstractSocket_SocketState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket::SocketState");
        Shiboken::Conversions::registerConverterName(converter, "SocketState");
    }
    // End of 'SocketState' enum.

    // Initialization of enum 'SocketOption'.
    SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSocket_Type,
        "SocketOption",
        "PySide.QtNetwork.QAbstractSocket.SocketOption",
        "QAbstractSocket::SocketOption");
    if (!SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX],
        &Sbk_QAbstractSocket_Type, "LowDelayOption", (long) QAbstractSocket::LowDelayOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX],
        &Sbk_QAbstractSocket_Type, "KeepAliveOption", (long) QAbstractSocket::KeepAliveOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX],
        &Sbk_QAbstractSocket_Type, "MulticastTtlOption", (long) QAbstractSocket::MulticastTtlOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX],
        &Sbk_QAbstractSocket_Type, "MulticastLoopbackOption", (long) QAbstractSocket::MulticastLoopbackOption))
        return ;
    // Register converter for enum 'QAbstractSocket::SocketOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX],
            QAbstractSocket_SocketOption_CppToPython_QAbstractSocket_SocketOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSocket_SocketOption_PythonToCpp_QAbstractSocket_SocketOption,
            is_QAbstractSocket_SocketOption_PythonToCpp_QAbstractSocket_SocketOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QABSTRACTSOCKET_SOCKETOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSocket::SocketOption");
        Shiboken::Conversions::registerConverterName(converter, "SocketOption");
    }
    // End of 'SocketOption' enum.

    PySide::Signal::registerSignals(&Sbk_QAbstractSocket_Type, &::QAbstractSocket::staticMetaObject);

    qRegisterMetaType< ::QAbstractSocket::SocketType >("QAbstractSocket::SocketType");
    qRegisterMetaType< ::QAbstractSocket::NetworkLayerProtocol >("QAbstractSocket::NetworkLayerProtocol");
    qRegisterMetaType< ::QAbstractSocket::SocketError >("QAbstractSocket::SocketError");
    qRegisterMetaType< ::QAbstractSocket::SocketState >("QAbstractSocket::SocketState");
    qRegisterMetaType< ::QAbstractSocket::SocketOption >("QAbstractSocket::SocketOption");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractSocket_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractSocket_Type, &::QAbstractSocket::staticMetaObject, sizeof(::QAbstractSocket));
}
