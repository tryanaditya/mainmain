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

#include "qfile_wrapper.h"

// Extra includes
#include <QAbstractFileEngine>
#include <QList>
#include <qabstractfileengine.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qfile.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QFileWrapper::QFileWrapper() : QFile() {
    // ... middle
}

QFileWrapper::QFileWrapper(QObject * parent) : QFile(parent) {
    // ... middle
}

QFileWrapper::QFileWrapper(const QString & name) : QFile(name) {
    // ... middle
}

QFileWrapper::QFileWrapper(const QString & name, QObject * parent) : QFile(name, parent) {
    // ... middle
}

bool QFileWrapper::atEnd() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atEnd"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::atEnd();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.atEnd", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::bytesAvailable() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.bytesAvailable", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::bytesToWrite() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.bytesToWrite", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileWrapper::canReadLine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.canReadLine", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileWrapper::childEvent(QChildEvent * arg__1)
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

void QFileWrapper::close()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "close"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::close();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QFileWrapper::connectNotify(const char * signal)
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

void QFileWrapper::customEvent(QEvent * arg__1)
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

void QFileWrapper::disconnectNotify(const char * signal)
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

bool QFileWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QFileWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QAbstractFileEngine * QFileWrapper::fileEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractFileEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fileEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::fileEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractFileEngine*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.fileEngine", Shiboken::SbkType< QAbstractFileEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractFileEngine*)0);
    }
    ::QAbstractFileEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileWrapper::isSequential() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isSequential"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::isSequential();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.isSequential", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileWrapper::open(QFlags<QIODevice::OpenModeFlag> flags)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "open"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::open(flags);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), &flags)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.open", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::pos() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pos"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::pos();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.pos", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::readData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QFile::readData(data, maxlen);
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

qint64 QFileWrapper::readLineData(char * data, qint64 maxlen)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "readLineData"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QFile::readLineData(data, maxlen);
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

bool QFileWrapper::reset()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.reset", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileWrapper::seek(qint64 offset)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "seek"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::seek(offset);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(L)",
        offset
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.seek", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::size() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "size"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::size();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.size", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QFileWrapper::waitForBytesWritten(int msecs)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.waitForBytesWritten", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFileWrapper::waitForReadyRead(int msecs)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.waitForReadyRead", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qint64 QFileWrapper::writeData(const char * data, qint64 len)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qint64)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "writeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFile::writeData(data, len);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFile.writeData", "qint64", pyResult->ob_type->tp_name);
        return ((qint64)0);
    }
    qint64 cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QFileWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QFile::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QFileWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QFile::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QFileWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QFileWrapper* >(this));
        return QFile::qt_metacast(_clname);
}

QFileWrapper::~QFileWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFile_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFile >()))
        return -1;

    ::QFileWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFile", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QFile()
    // 1: QFile(QObject*)
    // 2: QFile(QString)
    // 3: QFile(QString,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QFile()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QFile(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QFile(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 3; // QFile(QString,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFile_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFile()
        {

            if (!PyErr_Occurred()) {
                // QFile()
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileWrapper();
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileWrapper();
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFile(QObject * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QFile(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QFile(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QFile(QString)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QFile(const QString & name, QObject * parent)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QFile(QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFile >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFile_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QFile_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject", "unicode", "unicode, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile", overloads);
        return -1;
}

static PyObject* Sbk_QFileFunc_atEnd(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // atEnd()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFile*>(cppSelf)->::QFile::atEnd() : const_cast<const ::QFile*>(cppSelf)->atEnd();
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

static PyObject* Sbk_QFileFunc_close(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::close() : cppSelf->close();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFileFunc_copy(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "copy", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: copy(QString,QString)
    // 1: copy(QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // copy(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // copy(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_copy_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // copy(const QString & fileName, const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // copy(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::copy(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // copy(const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // copy(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->copy(cppArg0);
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

    Sbk_QFileFunc_copy_TypeError:
        const char* overloads[] = {"unicode, unicode", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.copy", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_decodeName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: decodeName(QByteArray)
    // 1: decodeName(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 1; // decodeName(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // decodeName(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_decodeName_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // decodeName(const QByteArray & localFileName)
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
                // decodeName(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QFile::decodeName(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // decodeName(const char * localFileName)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // decodeName(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QFile::decodeName(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_decodeName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.decodeName", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_encodeName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: encodeName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // encodeName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_encodeName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // encodeName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QFile::encodeName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_encodeName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.encodeName", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_error(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFile::FileError cppResult = const_cast<const ::QFile*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileFunc_exists(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "exists", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exists()const
    // 1: exists(QString)
    if (numArgs == 0) {
        overloadId = 0; // exists()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // exists(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_exists_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // exists() const
        {

            if (!PyErr_Occurred()) {
                // exists()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QFile*>(cppSelf)->exists();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // exists(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // exists(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::exists(cppArg0);
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

    Sbk_QFileFunc_exists_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.exists", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_fileEngine(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractFileEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFile*>(cppSelf)->::QFile::fileEngine() : const_cast<const ::QFile*>(cppSelf)->fileEngine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTFILEENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileFunc_fileName(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFile*>(cppSelf)->fileName();
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

static PyObject* Sbk_QFileFunc_flush(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QFileFunc_handle(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFile*>(cppSelf)->handle();
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

static PyObject* Sbk_QFileFunc_isSequential(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSequential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFile*>(cppSelf)->::QFile::isSequential() : const_cast<const ::QFile*>(cppSelf)->isSequential();
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

static PyObject* Sbk_QFileFunc_link(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "link", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: link(QString)
    // 1: link(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // link(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // link(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_link_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // link(const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // link(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->link(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // link(const QString & oldname, const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // link(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::link(cppArg0, cppArg1);
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

    Sbk_QFileFunc_link_TypeError:
        const char* overloads[] = {"unicode", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.link", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_map(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QFile.map(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QFile.map(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:map", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: map(qint64,qint64,QFile::MemoryMapFlags)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // map(qint64,qint64,QFile::MemoryMapFlags)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX]), (pyArgs[2])))) {
            overloadId = 0; // map(qint64,qint64,QFile::MemoryMapFlags)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_map_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QFile.map(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX]), (pyArgs[2]))))
                    goto Sbk_QFileFunc_map_TypeError;
            }
        }
        qint64 cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFile::MemoryMapFlags cppArg2 = QFile::NoOptions;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // map(qint64,qint64,QFile::MemoryMapFlags)
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->map(cppArg0, cppArg1, cppArg2), cppArg1, Shiboken::Buffer::ReadWrite);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_map_TypeError:
        const char* overloads[] = {"long long, long long, PySide.QtCore.QFile.MemoryMapFlags = NoOptions", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.map", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_open(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "open", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: open(QFlags<QIODevice::OpenModeFlag>)
    // 1: open(int,QFlags<QIODevice::OpenModeFlag>)
    // 2: open(int,QFlags<QIODevice::OpenModeFlag>,QFlags<QFile::FileHandleFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // open(int,QFlags<QIODevice::OpenModeFlag>)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 2; // open(int,QFlags<QIODevice::OpenModeFlag>,QFlags<QFile::FileHandleFlag>)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QIODEVICE_OPENMODEFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // open(QFlags<QIODevice::OpenModeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_open_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // open(QFlags<QIODevice::OpenModeFlag> flags)
        {
            ::QFlags<QIODevice::OpenModeFlag> cppArg0 = ((::QFlags<QIODevice::OpenModeFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // open(QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::open(cppArg0) : cppSelf->open(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // open(int fd, QFlags<QIODevice::OpenModeFlag> flags)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QIODevice::OpenModeFlag> cppArg1 = ((::QFlags<QIODevice::OpenModeFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // open(int,QFlags<QIODevice::OpenModeFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->open(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // open(int fd, QFlags<QIODevice::OpenModeFlag> ioFlags, QFlags<QFile::FileHandleFlag> handleFlags)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QIODevice::OpenModeFlag> cppArg1 = ((::QFlags<QIODevice::OpenModeFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QFile::FileHandleFlag> cppArg2 = ((::QFlags<QFile::FileHandleFlag>)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // open(int,QFlags<QIODevice::OpenModeFlag>,QFlags<QFile::FileHandleFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->open(cppArg0, cppArg1, cppArg2);
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

    Sbk_QFileFunc_open_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice.OpenMode", "int, PySide.QtCore.QIODevice.OpenMode", "int, PySide.QtCore.QIODevice.OpenMode, PySide.QtCore.QFile.FileHandleFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.open", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_permissions(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "permissions", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: permissions()const
    // 1: permissions(QString)
    if (numArgs == 0) {
        overloadId = 0; // permissions()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // permissions(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_permissions_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // permissions() const
        {

            if (!PyErr_Occurred()) {
                // permissions()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QFile::Permission> cppResult = const_cast<const ::QFile*>(cppSelf)->permissions();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
            }
            break;
        }
        case 1: // permissions(const QString & filename)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // permissions(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QFile::Permission> cppResult = ::QFile::permissions(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_permissions_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.permissions", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_pos(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFile*>(cppSelf)->::QFile::pos() : const_cast<const ::QFile*>(cppSelf)->pos();
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

static PyObject* Sbk_QFileFunc_readData(PyObject* self, PyObject* pyArg)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileFunc_readData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::readData(ba.data(), ba.size()) : cppSelf->readData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_readData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.readData", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_readLineData(PyObject* self, PyObject* pyArg)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileFunc_readLineData_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // readLineData(char*,qint64)
            // Begin code injection

            QByteArray ba;
            ba.resize(cppArg0);
            (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::readLineData(ba.data(), ba.size()) : cppSelf->readLineData(ba.data(), ba.size()));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_readLineData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.readLineData", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_readLink(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "readLink", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: readLink()const
    // 1: readLink(QString)
    if (numArgs == 0) {
        overloadId = 0; // readLink()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // readLink(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_readLink_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // readLink() const
        {

            if (!PyErr_Occurred()) {
                // readLink()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QFile*>(cppSelf)->readLink();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // readLink(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // readLink(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QFile::readLink(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_readLink_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.readLink", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_remove(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "remove", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: remove()
    // 1: remove(QString)
    if (numArgs == 0) {
        overloadId = 0; // remove()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // remove(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_remove_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // remove()
        {

            if (!PyErr_Occurred()) {
                // remove()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->remove();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // remove(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // remove(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::remove(cppArg0);
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

    Sbk_QFileFunc_remove_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.remove", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_rename(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rename", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: rename(QString)
    // 1: rename(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // rename(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // rename(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_rename_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // rename(const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // rename(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->rename(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // rename(const QString & oldName, const QString & newName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // rename(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::rename(cppArg0, cppArg1);
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

    Sbk_QFileFunc_rename_TypeError:
        const char* overloads[] = {"unicode", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.rename", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_resize(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "resize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: resize(QString,qint64)
    // 1: resize(qint64)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))) {
        overloadId = 1; // resize(qint64)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
        overloadId = 0; // resize(QString,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_resize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // resize(const QString & filename, qint64 sz)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qint64 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // resize(QString,qint64)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::resize(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // resize(qint64 sz)
        {
            qint64 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // resize(qint64)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->resize(cppArg0);
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

    Sbk_QFileFunc_resize_TypeError:
        const char* overloads[] = {"unicode, long long", "long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.resize", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_seek(PyObject* self, PyObject* pyArg)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seek(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seek(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_seek_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::seek(cppArg0) : cppSelf->seek(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_seek_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.seek", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_setFileName(PyObject* self, PyObject* pyArg)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFileName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setFileName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_setFileName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFileName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFileName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileFunc_setFileName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.setFileName", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_setPermissions(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPermissions", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPermissions(QFlags<QFile::Permission>)
    // 1: setPermissions(QString,QFlags<QFile::Permission>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), (pyArgs[1])))) {
        overloadId = 1; // setPermissions(QString,QFlags<QFile::Permission>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), (pyArgs[0])))) {
        overloadId = 0; // setPermissions(QFlags<QFile::Permission>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_setPermissions_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPermissions(QFlags<QFile::Permission> permissionSpec)
        {
            ::QFlags<QFile::Permission> cppArg0 = ((::QFlags<QFile::Permission>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setPermissions(QFlags<QFile::Permission>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setPermissions(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // setPermissions(const QString & filename, QFlags<QFile::Permission> permissionSpec)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QFile::Permission> cppArg1 = ((::QFlags<QFile::Permission>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPermissions(QString,QFlags<QFile::Permission>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QFile::setPermissions(cppArg0, cppArg1);
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

    Sbk_QFileFunc_setPermissions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QFile.Permissions", "unicode, PySide.QtCore.QFile.Permissions", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.setPermissions", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_size(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFile*>(cppSelf)->::QFile::size() : const_cast<const ::QFile*>(cppSelf)->size();
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

static PyObject* Sbk_QFileFunc_symLinkTarget(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (self) {
        if (!Shiboken::Object::isValid(self))
            return 0;
        cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    }
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "symLinkTarget", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: symLinkTarget()const
    // 1: symLinkTarget(QString)
    if (numArgs == 0) {
        overloadId = 0; // symLinkTarget()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // symLinkTarget(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_symLinkTarget_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // symLinkTarget() const
        {

            if (!PyErr_Occurred()) {
                // symLinkTarget()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QFile*>(cppSelf)->symLinkTarget();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // symLinkTarget(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // symLinkTarget(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QFile::symLinkTarget(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_symLinkTarget_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.symLinkTarget", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_unmap(PyObject* self, PyObject* pyArg)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unmap(uchar*)
    if (Shiboken::Buffer::checkType(pyArg)) {
        overloadId = 0; // unmap(uchar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileFunc_unmap_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unmap(uchar*)
            // Begin code injection

            uchar* ptr = (uchar*) Shiboken::Buffer::getPointer(pyArg);
            bool cppResult = cppSelf->unmap(ptr);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_unmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.uchar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QFile.unmap", overloads);
        return 0;
}

static PyObject* Sbk_QFileFunc_unsetError(PyObject* self)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unsetError()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unsetError();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFileFunc_writeData(PyObject* self, PyObject* args)
{
    ::QFile* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFile*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QFILE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFileFunc_writeData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qint64 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // writeData(const char*,qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFile::writeData(cppArg0, cppArg1) : cppSelf->writeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileFunc_writeData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QFile.writeData", overloads);
        return 0;
}

static PyMethodDef Sbk_QFileMethod_copy = {
    "copy", (PyCFunction)Sbk_QFileFunc_copy, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_exists = {
    "exists", (PyCFunction)Sbk_QFileFunc_exists, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_link = {
    "link", (PyCFunction)Sbk_QFileFunc_link, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_permissions = {
    "permissions", (PyCFunction)Sbk_QFileFunc_permissions, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_readLink = {
    "readLink", (PyCFunction)Sbk_QFileFunc_readLink, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_remove = {
    "remove", (PyCFunction)Sbk_QFileFunc_remove, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_rename = {
    "rename", (PyCFunction)Sbk_QFileFunc_rename, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_resize = {
    "resize", (PyCFunction)Sbk_QFileFunc_resize, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_setPermissions = {
    "setPermissions", (PyCFunction)Sbk_QFileFunc_setPermissions, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFileMethod_symLinkTarget = {
    "symLinkTarget", (PyCFunction)Sbk_QFileFunc_symLinkTarget, METH_VARARGS|METH_STATIC
};

static PyMethodDef Sbk_QFile_methods[] = {
    {"atEnd", (PyCFunction)Sbk_QFileFunc_atEnd, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QFileFunc_close, METH_NOARGS},
    Sbk_QFileMethod_copy,
    {"decodeName", (PyCFunction)Sbk_QFileFunc_decodeName, METH_O|METH_STATIC},
    {"encodeName", (PyCFunction)Sbk_QFileFunc_encodeName, METH_O|METH_STATIC},
    {"error", (PyCFunction)Sbk_QFileFunc_error, METH_NOARGS},
    Sbk_QFileMethod_exists,
    {"fileEngine", (PyCFunction)Sbk_QFileFunc_fileEngine, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QFileFunc_fileName, METH_NOARGS},
    {"flush", (PyCFunction)Sbk_QFileFunc_flush, METH_NOARGS},
    {"handle", (PyCFunction)Sbk_QFileFunc_handle, METH_NOARGS},
    {"isSequential", (PyCFunction)Sbk_QFileFunc_isSequential, METH_NOARGS},
    Sbk_QFileMethod_link,
    {"map", (PyCFunction)Sbk_QFileFunc_map, METH_VARARGS|METH_KEYWORDS},
    {"open", (PyCFunction)Sbk_QFileFunc_open, METH_VARARGS},
    Sbk_QFileMethod_permissions,
    {"pos", (PyCFunction)Sbk_QFileFunc_pos, METH_NOARGS},
    {"readData", (PyCFunction)Sbk_QFileFunc_readData, METH_O},
    {"readLineData", (PyCFunction)Sbk_QFileFunc_readLineData, METH_O},
    Sbk_QFileMethod_readLink,
    Sbk_QFileMethod_remove,
    Sbk_QFileMethod_rename,
    Sbk_QFileMethod_resize,
    {"seek", (PyCFunction)Sbk_QFileFunc_seek, METH_O},
    {"setFileName", (PyCFunction)Sbk_QFileFunc_setFileName, METH_O},
    Sbk_QFileMethod_setPermissions,
    {"size", (PyCFunction)Sbk_QFileFunc_size, METH_NOARGS},
    Sbk_QFileMethod_symLinkTarget,
    {"unmap", (PyCFunction)Sbk_QFileFunc_unmap, METH_O},
    {"unsetError", (PyCFunction)Sbk_QFileFunc_unsetError, METH_NOARGS},
    {"writeData", (PyCFunction)Sbk_QFileFunc_writeData, METH_VARARGS},

    {0} // Sentinel
};

static PyObject* Sbk_QFile_getattro(PyObject* self, PyObject* name)
{
    if (self) {
        // Search the method in the instance dict
        if (reinterpret_cast<SbkObject*>(self)->ob_dict) {
            PyObject* meth = PyDict_GetItem(reinterpret_cast<SbkObject*>(self)->ob_dict, name);
            if (meth) {
                Py_INCREF(meth);
                return meth;
            }
        }
        // Search the method in the type dict
        if (Shiboken::Object::isUserType(self)) {
            PyObject* meth = PyDict_GetItem(self->ob_type->tp_dict, name);
            if (meth)
                return PyFunction_Check(meth) ? SBK_PyMethod_New(meth, self) : PySide::getMetaDataFromQObject(((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self)), self, name);
        }
        static PyMethodDef non_static_Sbk_QFileMethod_copy = {
            Sbk_QFileMethod_copy.ml_name,
            Sbk_QFileMethod_copy.ml_meth,
            Sbk_QFileMethod_copy.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_copy.ml_doc,
        };
        if (Shiboken::String::compare(name, "copy") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_copy, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_exists = {
            Sbk_QFileMethod_exists.ml_name,
            Sbk_QFileMethod_exists.ml_meth,
            Sbk_QFileMethod_exists.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_exists.ml_doc,
        };
        if (Shiboken::String::compare(name, "exists") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_exists, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_link = {
            Sbk_QFileMethod_link.ml_name,
            Sbk_QFileMethod_link.ml_meth,
            Sbk_QFileMethod_link.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_link.ml_doc,
        };
        if (Shiboken::String::compare(name, "link") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_link, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_permissions = {
            Sbk_QFileMethod_permissions.ml_name,
            Sbk_QFileMethod_permissions.ml_meth,
            Sbk_QFileMethod_permissions.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_permissions.ml_doc,
        };
        if (Shiboken::String::compare(name, "permissions") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_permissions, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_readLink = {
            Sbk_QFileMethod_readLink.ml_name,
            Sbk_QFileMethod_readLink.ml_meth,
            Sbk_QFileMethod_readLink.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_readLink.ml_doc,
        };
        if (Shiboken::String::compare(name, "readLink") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_readLink, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_remove = {
            Sbk_QFileMethod_remove.ml_name,
            Sbk_QFileMethod_remove.ml_meth,
            Sbk_QFileMethod_remove.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_remove.ml_doc,
        };
        if (Shiboken::String::compare(name, "remove") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_remove, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_rename = {
            Sbk_QFileMethod_rename.ml_name,
            Sbk_QFileMethod_rename.ml_meth,
            Sbk_QFileMethod_rename.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_rename.ml_doc,
        };
        if (Shiboken::String::compare(name, "rename") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_rename, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_resize = {
            Sbk_QFileMethod_resize.ml_name,
            Sbk_QFileMethod_resize.ml_meth,
            Sbk_QFileMethod_resize.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_resize.ml_doc,
        };
        if (Shiboken::String::compare(name, "resize") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_resize, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_setPermissions = {
            Sbk_QFileMethod_setPermissions.ml_name,
            Sbk_QFileMethod_setPermissions.ml_meth,
            Sbk_QFileMethod_setPermissions.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_setPermissions.ml_doc,
        };
        if (Shiboken::String::compare(name, "setPermissions") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_setPermissions, self, 0);
        static PyMethodDef non_static_Sbk_QFileMethod_symLinkTarget = {
            Sbk_QFileMethod_symLinkTarget.ml_name,
            Sbk_QFileMethod_symLinkTarget.ml_meth,
            Sbk_QFileMethod_symLinkTarget.ml_flags & (~METH_STATIC),
            Sbk_QFileMethod_symLinkTarget.ml_doc,
        };
        if (Shiboken::String::compare(name, "symLinkTarget") == 0)
            return PyCFunction_NewEx(&non_static_Sbk_QFileMethod_symLinkTarget, self, 0);
    }
    return PySide::getMetaDataFromQObject(((::QObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (SbkObject*)self)), self, name);
}

} // extern "C"

static int Sbk_QFile_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFile_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFile_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QFile",
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
    /*tp_getattro*/         Sbk_QFile_getattro,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QFile_traverse,
    /*tp_clear*/            Sbk_QFile_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFile_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFile_Init,
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

static void* Sbk_QFile_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QFile*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtCore_QFile_Permission___and__(PyObject* self, PyObject* pyArg)
{
    ::QFile::Permissions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::Permissions)PyLong_AsLong(self);
    cppArg = (QFile::Permissions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::Permissions)PyInt_AsLong(self);
    cppArg = (QFile::Permissions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_Permission___or__(PyObject* self, PyObject* pyArg)
{
    ::QFile::Permissions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::Permissions)PyLong_AsLong(self);
    cppArg = (QFile::Permissions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::Permissions)PyInt_AsLong(self);
    cppArg = (QFile::Permissions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_Permission___xor__(PyObject* self, PyObject* pyArg)
{
    ::QFile::Permissions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::Permissions)PyLong_AsLong(self);
    cppArg = (QFile::Permissions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::Permissions)PyInt_AsLong(self);
    cppArg = (QFile::Permissions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_Permission___invert__(PyObject* self, PyObject* pyArg)
{
    ::QFile::Permissions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), self, &cppSelf);
    ::QFile::Permissions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QFile_Permission_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QFile_Permission__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QFile_Permission_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QFile_Permission__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QFile_Permission___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QFile_Permission___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QFile_Permission___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QFile_Permission___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QFile_Permission_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QFile_Permission_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};


PyObject* SbkPySide_QtCore_QFile_FileHandleFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QFile::FileHandleFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::FileHandleFlags)PyLong_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::FileHandleFlags)PyInt_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_FileHandleFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QFile::FileHandleFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::FileHandleFlags)PyLong_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::FileHandleFlags)PyInt_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_FileHandleFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QFile::FileHandleFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFile::FileHandleFlags)PyLong_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFile::FileHandleFlags)PyInt_AsLong(self);
    cppArg = (QFile::FileHandleFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QFile_FileHandleFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QFile::FileHandleFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), self, &cppSelf);
    ::QFile::FileHandleFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QFile_FileHandleFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QFile_FileHandleFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QFile_FileHandleFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtCore_QFile_FileHandleFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QFile_FileHandleFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QFile_FileHandleFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QFile_FileHandleFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QFile_FileHandleFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QFile_FileHandleFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QFile_FileHandleFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QFile_FileError_PythonToCpp_QFile_FileError(PyObject* pyIn, void* cppOut) {
    *((::QFile::FileError*)cppOut) = (::QFile::FileError) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFile_FileError_PythonToCpp_QFile_FileError_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX]))
        return QFile_FileError_PythonToCpp_QFile_FileError;
    return 0;
}
static PyObject* QFile_FileError_CppToPython_QFile_FileError(const void* cppIn) {
    int castCppIn = *((::QFile::FileError*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX], castCppIn);

}

static void QFile_Permission_PythonToCpp_QFile_Permission(PyObject* pyIn, void* cppOut) {
    *((::QFile::Permission*)cppOut) = (::QFile::Permission) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFile_Permission_PythonToCpp_QFile_Permission_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX]))
        return QFile_Permission_PythonToCpp_QFile_Permission;
    return 0;
}
static PyObject* QFile_Permission_CppToPython_QFile_Permission(const void* cppIn) {
    int castCppIn = *((::QFile::Permission*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX], castCppIn);

}

static void QFlags_QFile_Permission__PythonToCpp_QFlags_QFile_Permission_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFile::Permission>*)cppOut) = ::QFlags<QFile::Permission>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QFile_Permission__PythonToCpp_QFlags_QFile_Permission__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]))
        return QFlags_QFile_Permission__PythonToCpp_QFlags_QFile_Permission_;
    return 0;
}
static PyObject* QFlags_QFile_Permission__CppToPython_QFlags_QFile_Permission_(const void* cppIn) {
    int castCppIn = *((::QFlags<QFile::Permission>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]));

}

static void QFile_Permission_PythonToCpp_QFlags_QFile_Permission_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFile::Permission>*)cppOut) = ::QFlags<QFile::Permission>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QFile_Permission_PythonToCpp_QFlags_QFile_Permission__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX]))
        return QFile_Permission_PythonToCpp_QFlags_QFile_Permission_;
    return 0;
}
static void number_PythonToCpp_QFlags_QFile_Permission_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QFile::Permission>*)cppOut) = ::QFlags<QFile::Permission>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QFile_Permission__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QFile_Permission_;
    return 0;
}
static void QFile_FileHandleFlag_PythonToCpp_QFile_FileHandleFlag(PyObject* pyIn, void* cppOut) {
    *((::QFile::FileHandleFlag*)cppOut) = (::QFile::FileHandleFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFile_FileHandleFlag_PythonToCpp_QFile_FileHandleFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX]))
        return QFile_FileHandleFlag_PythonToCpp_QFile_FileHandleFlag;
    return 0;
}
static PyObject* QFile_FileHandleFlag_CppToPython_QFile_FileHandleFlag(const void* cppIn) {
    int castCppIn = *((::QFile::FileHandleFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX], castCppIn);

}

static void QFlags_QFile_FileHandleFlag__PythonToCpp_QFlags_QFile_FileHandleFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFile::FileHandleFlag>*)cppOut) = ::QFlags<QFile::FileHandleFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QFile_FileHandleFlag__PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]))
        return QFlags_QFile_FileHandleFlag__PythonToCpp_QFlags_QFile_FileHandleFlag_;
    return 0;
}
static PyObject* QFlags_QFile_FileHandleFlag__CppToPython_QFlags_QFile_FileHandleFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QFile::FileHandleFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]));

}

static void QFile_FileHandleFlag_PythonToCpp_QFlags_QFile_FileHandleFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFile::FileHandleFlag>*)cppOut) = ::QFlags<QFile::FileHandleFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QFile_FileHandleFlag_PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX]))
        return QFile_FileHandleFlag_PythonToCpp_QFlags_QFile_FileHandleFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QFile_FileHandleFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QFile::FileHandleFlag>*)cppOut) = ::QFlags<QFile::FileHandleFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QFile_FileHandleFlag_;
    return 0;
}
static void QFile_MemoryMapFlags_PythonToCpp_QFile_MemoryMapFlags(PyObject* pyIn, void* cppOut) {
    *((::QFile::MemoryMapFlags*)cppOut) = (::QFile::MemoryMapFlags) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFile_MemoryMapFlags_PythonToCpp_QFile_MemoryMapFlags_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX]))
        return QFile_MemoryMapFlags_PythonToCpp_QFile_MemoryMapFlags;
    return 0;
}
static PyObject* QFile_MemoryMapFlags_CppToPython_QFile_MemoryMapFlags(const void* cppIn) {
    int castCppIn = *((::QFile::MemoryMapFlags*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFile_PythonToCpp_QFile_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFile_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFile_PythonToCpp_QFile_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFile_Type))
        return QFile_PythonToCpp_QFile_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFile_PTR_CppToPython_QFile(const void* cppIn) {
    return PySide::getWrapperForQObject((::QFile*)cppIn, &Sbk_QFile_Type);

}

void init_QFile(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QFILE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFile_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFile", "QFile*",
        &Sbk_QFile_Type, &Shiboken::callCppDestructor< ::QFile >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFile_Type,
        QFile_PythonToCpp_QFile_PTR,
        is_QFile_PythonToCpp_QFile_PTR_Convertible,
        QFile_PTR_CppToPython_QFile);

    Shiboken::Conversions::registerConverterName(converter, "QFile");
    Shiboken::Conversions::registerConverterName(converter, "QFile*");
    Shiboken::Conversions::registerConverterName(converter, "QFile&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFile).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFile_Type, &Sbk_QFile_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'FileError'.
    SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFile_Type,
        "FileError",
        "PySide.QtCore.QFile.FileError",
        "QFile::FileError");
    if (!SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "NoError", (long) QFile::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "ReadError", (long) QFile::ReadError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "WriteError", (long) QFile::WriteError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "FatalError", (long) QFile::FatalError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "ResourceError", (long) QFile::ResourceError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "OpenError", (long) QFile::OpenError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "AbortError", (long) QFile::AbortError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "TimeOutError", (long) QFile::TimeOutError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "UnspecifiedError", (long) QFile::UnspecifiedError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "RemoveError", (long) QFile::RemoveError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "RenameError", (long) QFile::RenameError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "PositionError", (long) QFile::PositionError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "ResizeError", (long) QFile::ResizeError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "PermissionsError", (long) QFile::PermissionsError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
        &Sbk_QFile_Type, "CopyError", (long) QFile::CopyError))
        return ;
    // Register converter for enum 'QFile::FileError'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX],
            QFile_FileError_CppToPython_QFile_FileError);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_FileError_PythonToCpp_QFile_FileError,
            is_QFile_FileError_PythonToCpp_QFile_FileError_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFile::FileError");
        Shiboken::Conversions::registerConverterName(converter, "FileError");
    }
    // End of 'FileError' enum.

    // Initialization of enum 'Permission'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX] = PySide::QFlags::create("Permissions", &SbkPySide_QtCore_QFile_Permission_as_number);
    SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFile_Type,
        "Permission",
        "PySide.QtCore.QFile.Permission",
        "QFile::Permission",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ReadOwner", (long) QFile::ReadOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "WriteOwner", (long) QFile::WriteOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ExeOwner", (long) QFile::ExeOwner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ReadUser", (long) QFile::ReadUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "WriteUser", (long) QFile::WriteUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ExeUser", (long) QFile::ExeUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ReadGroup", (long) QFile::ReadGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "WriteGroup", (long) QFile::WriteGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ExeGroup", (long) QFile::ExeGroup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ReadOther", (long) QFile::ReadOther))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "WriteOther", (long) QFile::WriteOther))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
        &Sbk_QFile_Type, "ExeOther", (long) QFile::ExeOther))
        return ;
    // Register converter for enum 'QFile::Permission'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX],
            QFile_Permission_CppToPython_QFile_Permission);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_Permission_PythonToCpp_QFile_Permission,
            is_QFile_Permission_PythonToCpp_QFile_Permission_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_PERMISSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFile::Permission");
        Shiboken::Conversions::registerConverterName(converter, "Permission");
    }
    // Register converter for flag 'QFlags<QFile::Permission>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX],
            QFlags_QFile_Permission__CppToPython_QFlags_QFile_Permission_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_Permission_PythonToCpp_QFlags_QFile_Permission_,
            is_QFile_Permission_PythonToCpp_QFlags_QFile_Permission__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QFile_Permission__PythonToCpp_QFlags_QFile_Permission_,
            is_QFlags_QFile_Permission__PythonToCpp_QFlags_QFile_Permission__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QFile_Permission_,
            is_number_PythonToCpp_QFlags_QFile_Permission__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_PERMISSION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QFile::Permission>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Permission>");
    }
    // End of 'Permission' enum/flags.

    // Initialization of enum 'FileHandleFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX] = PySide::QFlags::create("FileHandleFlags", &SbkPySide_QtCore_QFile_FileHandleFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFile_Type,
        "FileHandleFlag",
        "PySide.QtCore.QFile.FileHandleFlag",
        "QFile::FileHandleFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX],
        &Sbk_QFile_Type, "AutoCloseHandle", (long) QFile::AutoCloseHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX],
        &Sbk_QFile_Type, "DontCloseHandle", (long) QFile::DontCloseHandle))
        return ;
    // Register converter for enum 'QFile::FileHandleFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX],
            QFile_FileHandleFlag_CppToPython_QFile_FileHandleFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_FileHandleFlag_PythonToCpp_QFile_FileHandleFlag,
            is_QFile_FileHandleFlag_PythonToCpp_QFile_FileHandleFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_FILEHANDLEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFile::FileHandleFlag");
        Shiboken::Conversions::registerConverterName(converter, "FileHandleFlag");
    }
    // Register converter for flag 'QFlags<QFile::FileHandleFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX],
            QFlags_QFile_FileHandleFlag__CppToPython_QFlags_QFile_FileHandleFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_FileHandleFlag_PythonToCpp_QFlags_QFile_FileHandleFlag_,
            is_QFile_FileHandleFlag_PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QFile_FileHandleFlag__PythonToCpp_QFlags_QFile_FileHandleFlag_,
            is_QFlags_QFile_FileHandleFlag__PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QFile_FileHandleFlag_,
            is_number_PythonToCpp_QFlags_QFile_FileHandleFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QFILE_FILEHANDLEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QFile::FileHandleFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<FileHandleFlag>");
    }
    // End of 'FileHandleFlag' enum/flags.

    // Initialization of enum 'MemoryMapFlags'.
    SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFile_Type,
        "MemoryMapFlags",
        "PySide.QtCore.QFile.MemoryMapFlags",
        "QFile::MemoryMapFlags");
    if (!SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX],
        &Sbk_QFile_Type, "NoOptions", (long) QFile::NoOptions))
        return ;
    // Register converter for enum 'QFile::MemoryMapFlags'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX],
            QFile_MemoryMapFlags_CppToPython_QFile_MemoryMapFlags);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFile_MemoryMapFlags_PythonToCpp_QFile_MemoryMapFlags,
            is_QFile_MemoryMapFlags_PythonToCpp_QFile_MemoryMapFlags_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFILE_MEMORYMAPFLAGS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFile::MemoryMapFlags");
        Shiboken::Conversions::registerConverterName(converter, "MemoryMapFlags");
    }
    // End of 'MemoryMapFlags' enum.

    PySide::Signal::registerSignals(&Sbk_QFile_Type, &::QFile::staticMetaObject);

    qRegisterMetaType< ::QFile::FileError >("QFile::FileError");
    qRegisterMetaType< ::QFile::Permission >("QFile::Permission");
    qRegisterMetaType< ::QFile::Permissions >("QFile::Permissions");
    qRegisterMetaType< ::QFile::FileHandleFlag >("QFile::FileHandleFlag");
    qRegisterMetaType< ::QFile::FileHandleFlags >("QFile::FileHandleFlags");
    qRegisterMetaType< ::QFile::MemoryMapFlags >("QFile::MemoryMapFlags");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QFile_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QFile_Type, &::QFile::staticMetaObject, sizeof(::QFile));
}
