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
#include "pyside_qtcore_python.h"

#include "qprocess_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qprocess.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QProcessWrapper::QProcessWrapper(QObject * parent) : QProcess(parent) {
    // ... middle
}

bool QProcessWrapper::atEnd() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atEnd"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::atEnd();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.atEnd", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QProcessWrapper::bytesAvailable() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesAvailable"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::bytesAvailable();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.bytesAvailable", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QProcessWrapper::bytesToWrite() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "bytesToWrite"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::bytesToWrite();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.bytesToWrite", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QProcessWrapper::canReadLine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canReadLine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::canReadLine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.canReadLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QProcessWrapper::childEvent(QChildEvent * arg__1)
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

void QProcessWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QProcessWrapper::connectNotify(const char * signal)
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

void QProcessWrapper::customEvent(QEvent * arg__1)
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

void QProcessWrapper::disconnectNotify(const char * signal)
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

bool QProcessWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QProcessWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QProcessWrapper::isSequential() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSequential"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::isSequential();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QProcessWrapper::open(QFlags<QIODevice::OpenModeFlag> mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QProcessWrapper::pos() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QProcessWrapper::readData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QProcess::readData(data, maxlen);
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

qint64 QProcessWrapper::readLineData(char * data, qint64 maxlen)
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

bool QProcessWrapper::reset()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QProcessWrapper::seek(qint64 pos)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QProcessWrapper::setupChildProcess()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setupChildProcess"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::setupChildProcess();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

qint64 QProcessWrapper::size() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QProcessWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QProcessWrapper::waitForBytesWritten(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForBytesWritten"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::waitForBytesWritten(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.waitForBytesWritten", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QProcessWrapper::waitForReadyRead(int msecs)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "waitForReadyRead"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::waitForReadyRead(msecs);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.waitForReadyRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QProcessWrapper::writeData(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QProcess::writeData(data, len);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QProcess.writeData", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QProcessWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QProcess::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QProcessWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QProcess::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QProcessWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QProcessWrapper* >(this));
        return QProcess::qt_metacast(_clname);
}

QProcessWrapper::~QProcessWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QProcess_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QProcess >()))
        return -1;

    ::QProcessWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QProcess", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QProcess(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QProcess(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QProcess(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcess_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QProcess_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QProcess(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QProcessWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QProcessWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QProcess >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QProcess_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QProcess_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess", overloads);
        return -1;
}

static PyObject* Sbk_QProcessFunc_atEnd(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QProcess*>(cppSelf)->::QProcess::atEnd() : const_cast<const ::QProcess*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QProcessFunc_bytesAvailable(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QProcess*>(cppSelf)->::QProcess::bytesAvailable() : const_cast<const ::QProcess*>(cppSelf)->bytesAvailable();
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

static PyObject* Sbk_QProcessFunc_bytesToWrite(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesToWrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QProcess*>(cppSelf)->::QProcess::bytesToWrite() : const_cast<const ::QProcess*>(cppSelf)->bytesToWrite();
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

static PyObject* Sbk_QProcessFunc_canReadLine(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canReadLine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QProcess*>(cppSelf)->::QProcess::canReadLine() : const_cast<const ::QProcess*>(cppSelf)->canReadLine();
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

static PyObject* Sbk_QProcessFunc_close(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::close() : cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessFunc_closeReadChannel(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closeReadChannel(QProcess::ProcessChannel)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX]), (pyArg)))) {
        overloadId = 0; // closeReadChannel(QProcess::ProcessChannel)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_closeReadChannel_TypeError;

    // Call function/method
    {
        ::QProcess::ProcessChannel cppArg0 = ((::QProcess::ProcessChannel)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeReadChannel(QProcess::ProcessChannel)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->closeReadChannel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_closeReadChannel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcess.ProcessChannel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.closeReadChannel", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_closeWriteChannel(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeWriteChannel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->closeWriteChannel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessFunc_environment(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // environment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QProcess*>(cppSelf)->environment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_error(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcess::ProcessError cppResult = const_cast<const ::QProcess*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_execute(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "execute", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: execute(QString)
    // 1: execute(QString,QStringList)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // execute(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            overloadId = 1; // execute(QString,QStringList)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_execute_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // execute(const QString & program)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // execute(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = ::QProcess::execute(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // execute(const QString & program, const QStringList & arguments)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // execute(QString,QStringList)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = ::QProcess::execute(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_execute_TypeError:
        const char* overloads[] = {"unicode", "unicode, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.execute", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_exitCode(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exitCode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QProcess*>(cppSelf)->exitCode();
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

static PyObject* Sbk_QProcessFunc_exitStatus(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exitStatus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcess::ExitStatus cppResult = const_cast<const ::QProcess*>(cppSelf)->exitStatus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_isSequential(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSequential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QProcess*>(cppSelf)->::QProcess::isSequential() : const_cast<const ::QProcess*>(cppSelf)->isSequential();
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

static PyObject* Sbk_QProcessFunc_kill(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // kill()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->kill();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessFunc_pid(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pid()
            // Begin code injection

            long result;
            #ifdef WIN32
                _PROCESS_INFORMATION* procInfo = cppSelf->pid();
                result = procInfo ? procInfo->dwProcessId : 0;
            #else
                result = cppSelf->pid();
            #endif
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<long>(), &result);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_processChannelMode(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // processChannelMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcess::ProcessChannelMode cppResult = const_cast<const ::QProcess*>(cppSelf)->processChannelMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_processEnvironment(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // processEnvironment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcessEnvironment cppResult = const_cast<const ::QProcess*>(cppSelf)->processEnvironment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_readAllStandardError(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readAllStandardError()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = cppSelf->readAllStandardError();
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

static PyObject* Sbk_QProcessFunc_readAllStandardOutput(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readAllStandardOutput()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = cppSelf->readAllStandardOutput();
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

static PyObject* Sbk_QProcessFunc_readChannel(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcess::ProcessChannel cppResult = const_cast<const ::QProcess*>(cppSelf)->readChannel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_readData(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QProcessFunc_readData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::readData(ba.data(), ba.size()) : cppSelf->readData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_readData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.readData", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setEnvironment(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnvironment(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setEnvironment(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setEnvironment_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnvironment(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEnvironment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setEnvironment_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setEnvironment", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setProcessChannelMode(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProcessChannelMode(QProcess::ProcessChannelMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setProcessChannelMode(QProcess::ProcessChannelMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setProcessChannelMode_TypeError;

    // Call function/method
    {
        ::QProcess::ProcessChannelMode cppArg0 = ((::QProcess::ProcessChannelMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProcessChannelMode(QProcess::ProcessChannelMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProcessChannelMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setProcessChannelMode_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcess.ProcessChannelMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setProcessChannelMode", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setProcessEnvironment(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProcessEnvironment(QProcessEnvironment)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], (pyArg)))) {
        overloadId = 0; // setProcessEnvironment(QProcessEnvironment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setProcessEnvironment_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QProcessEnvironment cppArg0_local = ::QProcessEnvironment();
        ::QProcessEnvironment* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESSENVIRONMENT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setProcessEnvironment(QProcessEnvironment)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProcessEnvironment(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setProcessEnvironment_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcessEnvironment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setProcessEnvironment", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setProcessState(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProcessState(QProcess::ProcessState)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX]), (pyArg)))) {
        overloadId = 0; // setProcessState(QProcess::ProcessState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setProcessState_TypeError;

    // Call function/method
    {
        ::QProcess::ProcessState cppArg0 = ((::QProcess::ProcessState)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProcessState(QProcess::ProcessState)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProcessState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setProcessState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcess.ProcessState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setProcessState", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setReadChannel(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadChannel(QProcess::ProcessChannel)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX]), (pyArg)))) {
        overloadId = 0; // setReadChannel(QProcess::ProcessChannel)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setReadChannel_TypeError;

    // Call function/method
    {
        ::QProcess::ProcessChannel cppArg0 = ((::QProcess::ProcessChannel)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadChannel(QProcess::ProcessChannel)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReadChannel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setReadChannel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcess.ProcessChannel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setReadChannel", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setStandardErrorFile(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardErrorFile(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardErrorFile(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setStandardErrorFile", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStandardErrorFile(QString,QFlags<QIODevice::OpenModeFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setStandardErrorFile(QString,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // setStandardErrorFile(QString,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setStandardErrorFile_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardErrorFile(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QProcessFunc_setStandardErrorFile_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QIODevice::OpenModeFlag> cppArg1 = QIODevice::Truncate;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStandardErrorFile(QString,QFlags<QIODevice::OpenModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardErrorFile(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setStandardErrorFile_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice.OpenMode = QIODevice.Truncate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.setStandardErrorFile", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setStandardInputFile(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStandardInputFile(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStandardInputFile(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setStandardInputFile_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStandardInputFile(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardInputFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setStandardInputFile_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setStandardInputFile", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setStandardOutputFile(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardOutputFile(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardOutputFile(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setStandardOutputFile", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStandardOutputFile(QString,QFlags<QIODevice::OpenModeFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setStandardOutputFile(QString,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // setStandardOutputFile(QString,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setStandardOutputFile_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.setStandardOutputFile(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QProcessFunc_setStandardOutputFile_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QIODevice::OpenModeFlag> cppArg1 = QIODevice::Truncate;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStandardOutputFile(QString,QFlags<QIODevice::OpenModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardOutputFile(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setStandardOutputFile_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice.OpenMode = QIODevice.Truncate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.setStandardOutputFile", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setStandardOutputProcess(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStandardOutputProcess(QProcess*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (pyArg)))) {
        overloadId = 0; // setStandardOutputProcess(QProcess*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setStandardOutputProcess_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QProcess* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStandardOutputProcess(QProcess*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardOutputProcess(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setStandardOutputProcess_TypeError:
        const char* overloads[] = {"PySide.QtCore.QProcess", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setStandardOutputProcess", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setWorkingDirectory(PyObject* self, PyObject* pyArg)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWorkingDirectory(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWorkingDirectory(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_setWorkingDirectory_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWorkingDirectory(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWorkingDirectory(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_setWorkingDirectory_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QProcess.setWorkingDirectory", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_setupChildProcess(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setupChildProcess()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::setupChildProcess() : cppSelf->setupChildProcess();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessFunc_start(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.start(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.start(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:start", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: start(QString,QFlags<QIODevice::OpenModeFlag>)
    // 1: start(QString,QStringList,QFlags<QIODevice::OpenModeFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // start(QString,QFlags<QIODevice::OpenModeFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // start(QString,QStringList,QFlags<QIODevice::OpenModeFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // start(QString,QStringList,QFlags<QIODevice::OpenModeFlag>)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // start(QString,QFlags<QIODevice::OpenModeFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_start_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // start(const QString & program, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.start(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QProcessFunc_start_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QIODevice::OpenModeFlag> cppArg1 = QIODevice::ReadWrite;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // start(QString,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->start(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // start(const QString & program, const QStringList & arguments, QFlags<QIODevice::OpenModeFlag> mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.start(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QProcessFunc_start_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QIODevice::OpenModeFlag> cppArg2 = QIODevice::ReadWrite;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // start(QString,QStringList,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->start(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QProcessFunc_start_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", "unicode, QStringList, PySide.QtCore.QIODevice.OpenMode = QIODevice.ReadWrite", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.start", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_startDetached(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "startDetached", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: startDetached(QString)
    // 1: startDetached(QString,QStringList)
    // 2: startDetached(QString,QStringList,QString,qint64*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // startDetached(QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // startDetached(QString,QStringList)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 2; // startDetached(QString,QStringList,QString,qint64*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_startDetached_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // startDetached(const QString & program)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // startDetached(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QProcess::startDetached(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // startDetached(const QString & program, const QStringList & arguments)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // startDetached(QString,QStringList)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QProcess::startDetached(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // startDetached(const QString & program, const QStringList & arguments, const QString & workingDirectory, qint64 * pid)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qint64* removed_cppArg3 = 0;
            SBK_UNUSED(removed_cppArg3)

            if (!PyErr_Occurred()) {
                // startDetached(QString,QStringList,QString,qint64*)
                // Begin code injection

                qint64 pid;
                bool retval = QProcess::startDetached(cppArg0, cppArg1, cppArg2, &pid);
                pyResult = PyTuple_New(2);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &retval));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &pid));

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_startDetached_TypeError:
        const char* overloads[] = {"unicode", "unicode, QStringList", "unicode, QStringList, unicode, PySide.QtCore.qint64 = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.startDetached", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_state(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QProcess::ProcessState cppResult = const_cast<const ::QProcess*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_systemEnvironment(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemEnvironment()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QProcess::systemEnvironment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QProcessFunc_terminate(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // terminate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->terminate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QProcessFunc_waitForBytesWritten(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForBytesWritten(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QProcessFunc_waitForBytesWritten_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForBytesWritten(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QProcessFunc_waitForBytesWritten_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForBytesWritten(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::waitForBytesWritten(cppArg0) : cppSelf->waitForBytesWritten(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_waitForBytesWritten_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.waitForBytesWritten", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_waitForFinished(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForFinished(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForFinished", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForFinished(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForFinished(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForFinished(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_waitForFinished_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForFinished(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QProcessFunc_waitForFinished_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForFinished(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->waitForFinished(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_waitForFinished_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.waitForFinished", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_waitForReadyRead(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForReadyRead(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QProcessFunc_waitForReadyRead_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForReadyRead(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QProcessFunc_waitForReadyRead_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForReadyRead(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::waitForReadyRead(cppArg0) : cppSelf->waitForReadyRead(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_waitForReadyRead_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.waitForReadyRead", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_waitForStarted(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForStarted(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:waitForStarted", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: waitForStarted(int)
    if (numArgs == 0) {
        overloadId = 0; // waitForStarted(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // waitForStarted(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QProcessFunc_waitForStarted_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QProcess.waitForStarted(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QProcessFunc_waitForStarted_TypeError;
            }
        }
        int cppArg0 = 30000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // waitForStarted(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->waitForStarted(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_waitForStarted_TypeError:
        const char* overloads[] = {"int = 30000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.waitForStarted", overloads);
        return 0;
}

static PyObject* Sbk_QProcessFunc_workingDirectory(PyObject* self)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // workingDirectory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QProcess*>(cppSelf)->workingDirectory();
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

static PyObject* Sbk_QProcessFunc_writeData(PyObject* self, PyObject* args)
{
    ::QProcess* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QProcess*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QProcessFunc_writeData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeData(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QProcess::writeData(cppArg0, cppArg1) : cppSelf->writeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QProcessFunc_writeData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QProcess.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_QProcess_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QProcessFunc_atEnd, METH_NOARGS},
    {"bytesAvailable", (PyCFunction)Sbk_QProcessFunc_bytesAvailable, METH_NOARGS},
    {"bytesToWrite", (PyCFunction)Sbk_QProcessFunc_bytesToWrite, METH_NOARGS},
    {"canReadLine", (PyCFunction)Sbk_QProcessFunc_canReadLine, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QProcessFunc_close, METH_NOARGS},
    {"closeReadChannel", (PyCFunction)Sbk_QProcessFunc_closeReadChannel, METH_O},
    {"closeWriteChannel", (PyCFunction)Sbk_QProcessFunc_closeWriteChannel, METH_NOARGS},
    {"environment", (PyCFunction)Sbk_QProcessFunc_environment, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QProcessFunc_error, METH_NOARGS},
    {"execute", (PyCFunction)Sbk_QProcessFunc_execute, METH_VARARGS|METH_STATIC},
    {"exitCode", (PyCFunction)Sbk_QProcessFunc_exitCode, METH_NOARGS},
    {"exitStatus", (PyCFunction)Sbk_QProcessFunc_exitStatus, METH_NOARGS},
    {"isSequential", (PyCFunction)Sbk_QProcessFunc_isSequential, METH_NOARGS},
    {"kill", (PyCFunction)Sbk_QProcessFunc_kill, METH_NOARGS},
    {"pid", (PyCFunction)Sbk_QProcessFunc_pid, METH_NOARGS},
    {"processChannelMode", (PyCFunction)Sbk_QProcessFunc_processChannelMode, METH_NOARGS},
    {"processEnvironment", (PyCFunction)Sbk_QProcessFunc_processEnvironment, METH_NOARGS},
    {"readAllStandardError", (PyCFunction)Sbk_QProcessFunc_readAllStandardError, METH_NOARGS},
    {"readAllStandardOutput", (PyCFunction)Sbk_QProcessFunc_readAllStandardOutput, METH_NOARGS},
    {"readChannel", (PyCFunction)Sbk_QProcessFunc_readChannel, METH_NOARGS},
    {"readData", (PyCFunction)Sbk_QProcessFunc_readData, METH_O},
    {"setEnvironment", (PyCFunction)Sbk_QProcessFunc_setEnvironment, METH_O},
    {"setProcessChannelMode", (PyCFunction)Sbk_QProcessFunc_setProcessChannelMode, METH_O},
    {"setProcessEnvironment", (PyCFunction)Sbk_QProcessFunc_setProcessEnvironment, METH_O},
    {"setProcessState", (PyCFunction)Sbk_QProcessFunc_setProcessState, METH_O},
    {"setReadChannel", (PyCFunction)Sbk_QProcessFunc_setReadChannel, METH_O},
    {"setStandardErrorFile", (PyCFunction)Sbk_QProcessFunc_setStandardErrorFile, METH_VARARGS|METH_KEYWORDS},
    {"setStandardInputFile", (PyCFunction)Sbk_QProcessFunc_setStandardInputFile, METH_O},
    {"setStandardOutputFile", (PyCFunction)Sbk_QProcessFunc_setStandardOutputFile, METH_VARARGS|METH_KEYWORDS},
    {"setStandardOutputProcess", (PyCFunction)Sbk_QProcessFunc_setStandardOutputProcess, METH_O},
    {"setWorkingDirectory", (PyCFunction)Sbk_QProcessFunc_setWorkingDirectory, METH_O},
    {"setupChildProcess", (PyCFunction)Sbk_QProcessFunc_setupChildProcess, METH_NOARGS},
    {"start", (PyCFunction)Sbk_QProcessFunc_start, METH_VARARGS|METH_KEYWORDS},
    {"startDetached", (PyCFunction)Sbk_QProcessFunc_startDetached, METH_VARARGS|METH_STATIC},
    {"state", (PyCFunction)Sbk_QProcessFunc_state, METH_NOARGS},
    {"systemEnvironment", (PyCFunction)Sbk_QProcessFunc_systemEnvironment, METH_NOARGS|METH_STATIC},
    {"terminate", (PyCFunction)Sbk_QProcessFunc_terminate, METH_NOARGS},
    {"waitForBytesWritten", (PyCFunction)Sbk_QProcessFunc_waitForBytesWritten, METH_VARARGS|METH_KEYWORDS},
    {"waitForFinished", (PyCFunction)Sbk_QProcessFunc_waitForFinished, METH_VARARGS|METH_KEYWORDS},
    {"waitForReadyRead", (PyCFunction)Sbk_QProcessFunc_waitForReadyRead, METH_VARARGS|METH_KEYWORDS},
    {"waitForStarted", (PyCFunction)Sbk_QProcessFunc_waitForStarted, METH_VARARGS|METH_KEYWORDS},
    {"workingDirectory", (PyCFunction)Sbk_QProcessFunc_workingDirectory, METH_NOARGS},
    {"writeData", (PyCFunction)Sbk_QProcessFunc_writeData, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QProcess_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QProcess_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QProcess_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QProcess",
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
    /*tp_traverse*/         Sbk_QProcess_traverse,
    /*tp_clear*/            Sbk_QProcess_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QProcess_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QProcess_Init,
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

static void* Sbk_QProcess_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QProcess*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QProcess_ProcessError_PythonToCpp_QProcess_ProcessError(PyObject* pyIn, void* cppOut) {
    *((::QProcess::ProcessError*)cppOut) = (::QProcess::ProcessError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QProcess_ProcessError_PythonToCpp_QProcess_ProcessError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX]))
        return QProcess_ProcessError_PythonToCpp_QProcess_ProcessError;
    return 0;
}
static PyObject* QProcess_ProcessError_CppToPython_QProcess_ProcessError(const void* cppIn) {
    int castCppIn = *((::QProcess::ProcessError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX], castCppIn);

}

static void QProcess_ProcessState_PythonToCpp_QProcess_ProcessState(PyObject* pyIn, void* cppOut) {
    *((::QProcess::ProcessState*)cppOut) = (::QProcess::ProcessState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QProcess_ProcessState_PythonToCpp_QProcess_ProcessState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX]))
        return QProcess_ProcessState_PythonToCpp_QProcess_ProcessState;
    return 0;
}
static PyObject* QProcess_ProcessState_CppToPython_QProcess_ProcessState(const void* cppIn) {
    int castCppIn = *((::QProcess::ProcessState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX], castCppIn);

}

static void QProcess_ProcessChannel_PythonToCpp_QProcess_ProcessChannel(PyObject* pyIn, void* cppOut) {
    *((::QProcess::ProcessChannel*)cppOut) = (::QProcess::ProcessChannel) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QProcess_ProcessChannel_PythonToCpp_QProcess_ProcessChannel_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX]))
        return QProcess_ProcessChannel_PythonToCpp_QProcess_ProcessChannel;
    return 0;
}
static PyObject* QProcess_ProcessChannel_CppToPython_QProcess_ProcessChannel(const void* cppIn) {
    int castCppIn = *((::QProcess::ProcessChannel*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX], castCppIn);

}

static void QProcess_ProcessChannelMode_PythonToCpp_QProcess_ProcessChannelMode(PyObject* pyIn, void* cppOut) {
    *((::QProcess::ProcessChannelMode*)cppOut) = (::QProcess::ProcessChannelMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QProcess_ProcessChannelMode_PythonToCpp_QProcess_ProcessChannelMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX]))
        return QProcess_ProcessChannelMode_PythonToCpp_QProcess_ProcessChannelMode;
    return 0;
}
static PyObject* QProcess_ProcessChannelMode_CppToPython_QProcess_ProcessChannelMode(const void* cppIn) {
    int castCppIn = *((::QProcess::ProcessChannelMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX], castCppIn);

}

static void QProcess_ExitStatus_PythonToCpp_QProcess_ExitStatus(PyObject* pyIn, void* cppOut) {
    *((::QProcess::ExitStatus*)cppOut) = (::QProcess::ExitStatus) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QProcess_ExitStatus_PythonToCpp_QProcess_ExitStatus_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX]))
        return QProcess_ExitStatus_PythonToCpp_QProcess_ExitStatus;
    return 0;
}
static PyObject* QProcess_ExitStatus_CppToPython_QProcess_ExitStatus(const void* cppIn) {
    int castCppIn = *((::QProcess::ExitStatus*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QProcess_PythonToCpp_QProcess_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QProcess_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QProcess_PythonToCpp_QProcess_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QProcess_Type))
        return QProcess_PythonToCpp_QProcess_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QProcess_PTR_CppToPython_QProcess(const void* cppIn) {
    return PySide::getWrapperForQObject((::QProcess*)cppIn, &Sbk_QProcess_Type);

}

void init_QProcess(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QPROCESS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QProcess_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QProcess", "QProcess*",
        &Sbk_QProcess_Type, &Shiboken::callCppDestructor< ::QProcess >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QProcess_Type,
        QProcess_PythonToCpp_QProcess_PTR,
        is_QProcess_PythonToCpp_QProcess_PTR_Convertible,
        QProcess_PTR_CppToPython_QProcess);

    Shiboken::Conversions::registerConverterName(converter, "QProcess");
    Shiboken::Conversions::registerConverterName(converter, "QProcess*");
    Shiboken::Conversions::registerConverterName(converter, "QProcess&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QProcess).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QProcessWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QProcess_Type, &Sbk_QProcess_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ProcessError'.
    SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QProcess_Type,
        "ProcessError",
        "PySide.QtCore.QProcess.ProcessError",
        "QProcess::ProcessError");
    if (!SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "FailedToStart", (long) QProcess::FailedToStart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "Crashed", (long) QProcess::Crashed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "Timedout", (long) QProcess::Timedout))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "ReadError", (long) QProcess::ReadError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "WriteError", (long) QProcess::WriteError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
        &Sbk_QProcess_Type, "UnknownError", (long) QProcess::UnknownError))
        return ;
    // Register converter for enum 'QProcess::ProcessError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX],
            QProcess_ProcessError_CppToPython_QProcess_ProcessError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QProcess_ProcessError_PythonToCpp_QProcess_ProcessError,
            is_QProcess_ProcessError_PythonToCpp_QProcess_ProcessError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QProcess::ProcessError");
        Shiboken::Conversions::registerConverterName(converter, "ProcessError");
    }
    // End of 'ProcessError' enum.

    // Initialization of enum 'ProcessState'.
    SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QProcess_Type,
        "ProcessState",
        "PySide.QtCore.QProcess.ProcessState",
        "QProcess::ProcessState");
    if (!SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX],
        &Sbk_QProcess_Type, "NotRunning", (long) QProcess::NotRunning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX],
        &Sbk_QProcess_Type, "Starting", (long) QProcess::Starting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX],
        &Sbk_QProcess_Type, "Running", (long) QProcess::Running))
        return ;
    // Register converter for enum 'QProcess::ProcessState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX],
            QProcess_ProcessState_CppToPython_QProcess_ProcessState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QProcess_ProcessState_PythonToCpp_QProcess_ProcessState,
            is_QProcess_ProcessState_PythonToCpp_QProcess_ProcessState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QProcess::ProcessState");
        Shiboken::Conversions::registerConverterName(converter, "ProcessState");
    }
    // End of 'ProcessState' enum.

    // Initialization of enum 'ProcessChannel'.
    SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QProcess_Type,
        "ProcessChannel",
        "PySide.QtCore.QProcess.ProcessChannel",
        "QProcess::ProcessChannel");
    if (!SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX],
        &Sbk_QProcess_Type, "StandardOutput", (long) QProcess::StandardOutput))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX],
        &Sbk_QProcess_Type, "StandardError", (long) QProcess::StandardError))
        return ;
    // Register converter for enum 'QProcess::ProcessChannel'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX],
            QProcess_ProcessChannel_CppToPython_QProcess_ProcessChannel);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QProcess_ProcessChannel_PythonToCpp_QProcess_ProcessChannel,
            is_QProcess_ProcessChannel_PythonToCpp_QProcess_ProcessChannel_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNEL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QProcess::ProcessChannel");
        Shiboken::Conversions::registerConverterName(converter, "ProcessChannel");
    }
    // End of 'ProcessChannel' enum.

    // Initialization of enum 'ProcessChannelMode'.
    SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QProcess_Type,
        "ProcessChannelMode",
        "PySide.QtCore.QProcess.ProcessChannelMode",
        "QProcess::ProcessChannelMode");
    if (!SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX],
        &Sbk_QProcess_Type, "SeparateChannels", (long) QProcess::SeparateChannels))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX],
        &Sbk_QProcess_Type, "MergedChannels", (long) QProcess::MergedChannels))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX],
        &Sbk_QProcess_Type, "ForwardedChannels", (long) QProcess::ForwardedChannels))
        return ;
    // Register converter for enum 'QProcess::ProcessChannelMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX],
            QProcess_ProcessChannelMode_CppToPython_QProcess_ProcessChannelMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QProcess_ProcessChannelMode_PythonToCpp_QProcess_ProcessChannelMode,
            is_QProcess_ProcessChannelMode_PythonToCpp_QProcess_ProcessChannelMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_PROCESSCHANNELMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QProcess::ProcessChannelMode");
        Shiboken::Conversions::registerConverterName(converter, "ProcessChannelMode");
    }
    // End of 'ProcessChannelMode' enum.

    // Initialization of enum 'ExitStatus'.
    SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QProcess_Type,
        "ExitStatus",
        "PySide.QtCore.QProcess.ExitStatus",
        "QProcess::ExitStatus");
    if (!SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX],
        &Sbk_QProcess_Type, "NormalExit", (long) QProcess::NormalExit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX],
        &Sbk_QProcess_Type, "CrashExit", (long) QProcess::CrashExit))
        return ;
    // Register converter for enum 'QProcess::ExitStatus'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX],
            QProcess_ExitStatus_CppToPython_QProcess_ExitStatus);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QProcess_ExitStatus_PythonToCpp_QProcess_ExitStatus,
            is_QProcess_ExitStatus_PythonToCpp_QProcess_ExitStatus_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QPROCESS_EXITSTATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QProcess::ExitStatus");
        Shiboken::Conversions::registerConverterName(converter, "ExitStatus");
    }
    // End of 'ExitStatus' enum.

    PySide::Signal::registerSignals(&Sbk_QProcess_Type, &::QProcess::staticMetaObject);

    qRegisterMetaType< ::QProcess::ProcessError >("QProcess::ProcessError");
    qRegisterMetaType< ::QProcess::ProcessState >("QProcess::ProcessState");
    qRegisterMetaType< ::QProcess::ProcessChannel >("QProcess::ProcessChannel");
    qRegisterMetaType< ::QProcess::ProcessChannelMode >("QProcess::ProcessChannelMode");
    qRegisterMetaType< ::QProcess::ExitStatus >("QProcess::ExitStatus");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QProcess_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QProcess_Type, &::QProcess::staticMetaObject, sizeof(::QProcess));
}
