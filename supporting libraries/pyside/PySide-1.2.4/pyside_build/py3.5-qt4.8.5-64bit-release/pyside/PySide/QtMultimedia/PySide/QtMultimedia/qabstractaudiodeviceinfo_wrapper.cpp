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
#include "pyside_qtmultimedia_python.h"

#include "qabstractaudiodeviceinfo_wrapper.h"

// Extra includes
#include <QList>
#include <qaudioformat.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QAbstractAudioDeviceInfoWrapper::QAbstractAudioDeviceInfoWrapper() : QAbstractAudioDeviceInfo() {
    // ... middle
}

QList<QAudioFormat::Endian > QAbstractAudioDeviceInfoWrapper::byteOrderList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QAudioFormat::Endian >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "byteOrderList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.byteOrderList()' not implemented.");
        return ::QList<QAudioFormat::Endian >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QAudioFormat::Endian >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.byteOrderList", "list", pyResult->ob_type->tp_name);
        return ::QList<QAudioFormat::Endian >();
    }
    ::QList<QAudioFormat::Endian > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<int > QAbstractAudioDeviceInfoWrapper::channelsList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<int >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "channelsList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.channelsList()' not implemented.");
        return ::QList<int >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<int >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.channelsList", "list", pyResult->ob_type->tp_name);
        return ::QList<int >();
    }
    ::QList<int > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractAudioDeviceInfoWrapper::childEvent(QChildEvent * arg__1)
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

QStringList QAbstractAudioDeviceInfoWrapper::codecList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "codecList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.codecList()' not implemented.");
        return ::QStringList();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QStringList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.codecList", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractAudioDeviceInfoWrapper::connectNotify(const char * signal)
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

void QAbstractAudioDeviceInfoWrapper::customEvent(QEvent * arg__1)
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

QString QAbstractAudioDeviceInfoWrapper::deviceName() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deviceName"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.deviceName()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.deviceName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractAudioDeviceInfoWrapper::disconnectNotify(const char * signal)
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

bool QAbstractAudioDeviceInfoWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractAudioDeviceInfoWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QList<int > QAbstractAudioDeviceInfoWrapper::frequencyList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<int >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "frequencyList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.frequencyList()' not implemented.");
        return ::QList<int >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<int >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.frequencyList", "list", pyResult->ob_type->tp_name);
        return ::QList<int >();
    }
    ::QList<int > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractAudioDeviceInfoWrapper::isFormatSupported(const QAudioFormat & format) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isFormatSupported"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.isFormatSupported()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &format)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.isFormatSupported", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAudioFormat QAbstractAudioDeviceInfoWrapper::nearestFormat(const QAudioFormat & format) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QAudioFormat();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "nearestFormat"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.nearestFormat()' not implemented.");
        return ::QAudioFormat();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QAudioFormat();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.nearestFormat", Shiboken::SbkType< QAudioFormat >()->tp_name, pyResult->ob_type->tp_name);
        return ::QAudioFormat();
    }
    ::QAudioFormat cppResult = ::QAudioFormat();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAudioFormat QAbstractAudioDeviceInfoWrapper::preferredFormat() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QAudioFormat();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "preferredFormat"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.preferredFormat()' not implemented.");
        return ::QAudioFormat();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QAudioFormat();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.preferredFormat", Shiboken::SbkType< QAudioFormat >()->tp_name, pyResult->ob_type->tp_name);
        return ::QAudioFormat();
    }
    ::QAudioFormat cppResult = ::QAudioFormat();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<int > QAbstractAudioDeviceInfoWrapper::sampleSizeList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<int >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sampleSizeList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.sampleSizeList()' not implemented.");
        return ::QList<int >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<int >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.sampleSizeList", "list", pyResult->ob_type->tp_name);
        return ::QList<int >();
    }
    ::QList<int > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<QAudioFormat::SampleType > QAbstractAudioDeviceInfoWrapper::sampleTypeList()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QAudioFormat::SampleType >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sampleTypeList"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.sampleTypeList()' not implemented.");
        return ::QList<QAudioFormat::SampleType >();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QAudioFormat::SampleType >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractAudioDeviceInfo.sampleTypeList", "list", pyResult->ob_type->tp_name);
        return ::QList<QAudioFormat::SampleType >();
    }
    ::QList<QAudioFormat::SampleType > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractAudioDeviceInfoWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QAbstractAudioDeviceInfoWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractAudioDeviceInfo::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractAudioDeviceInfoWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractAudioDeviceInfo::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractAudioDeviceInfoWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractAudioDeviceInfoWrapper* >(this));
        return QAbstractAudioDeviceInfo::qt_metacast(_clname);
}

QAbstractAudioDeviceInfoWrapper::~QAbstractAudioDeviceInfoWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractAudioDeviceInfo_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractAudioDeviceInfo' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractAudioDeviceInfo >()))
        return -1;

    ::QAbstractAudioDeviceInfoWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QAbstractAudioDeviceInfo()
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractAudioDeviceInfoWrapper();
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractAudioDeviceInfoWrapper();
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractAudioDeviceInfo >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_byteOrderList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // byteOrderList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.byteOrderList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAudioFormat::Endian > cppResult = cppSelf->byteOrderList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_ENDIAN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_channelsList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // channelsList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.channelsList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = cppSelf->channelsList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_codecList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // codecList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.codecList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = cppSelf->codecList();
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

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_deviceName(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceName()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.deviceName()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractAudioDeviceInfo*>(cppSelf)->deviceName();
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

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_frequencyList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // frequencyList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.frequencyList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = cppSelf->frequencyList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_isFormatSupported(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isFormatSupported(QAudioFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // isFormatSupported(QAudioFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAudioDeviceInfoFunc_isFormatSupported_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAudioFormat cppArg0_local = ::QAudioFormat();
        ::QAudioFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isFormatSupported(QAudioFormat)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.isFormatSupported()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractAudioDeviceInfo*>(cppSelf)->isFormatSupported(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractAudioDeviceInfoFunc_isFormatSupported_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractAudioDeviceInfo.isFormatSupported", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_nearestFormat(PyObject* self, PyObject* pyArg)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: nearestFormat(QAudioFormat)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // nearestFormat(QAudioFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractAudioDeviceInfoFunc_nearestFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAudioFormat cppArg0_local = ::QAudioFormat();
        ::QAudioFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // nearestFormat(QAudioFormat)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.nearestFormat()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat cppResult = const_cast<const ::QAbstractAudioDeviceInfo*>(cppSelf)->nearestFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractAudioDeviceInfoFunc_nearestFormat_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudioFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAbstractAudioDeviceInfo.nearestFormat", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_preferredFormat(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredFormat()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.preferredFormat()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAudioFormat cppResult = const_cast<const ::QAbstractAudioDeviceInfo*>(cppSelf)->preferredFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_sampleSizeList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleSizeList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.sampleSizeList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = cppSelf->sampleSizeList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractAudioDeviceInfoFunc_sampleTypeList(PyObject* self)
{
    ::QAbstractAudioDeviceInfo* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractAudioDeviceInfo*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sampleTypeList()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractAudioDeviceInfo.sampleTypeList()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAudioFormat::SampleType > cppResult = cppSelf->sampleTypeList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QAUDIOFORMAT_SAMPLETYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QAbstractAudioDeviceInfo_methods[] = {
    {"byteOrderList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_byteOrderList, METH_NOARGS},
    {"channelsList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_channelsList, METH_NOARGS},
    {"codecList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_codecList, METH_NOARGS},
    {"deviceName", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_deviceName, METH_NOARGS},
    {"frequencyList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_frequencyList, METH_NOARGS},
    {"isFormatSupported", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_isFormatSupported, METH_O},
    {"nearestFormat", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_nearestFormat, METH_O},
    {"preferredFormat", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_preferredFormat, METH_NOARGS},
    {"sampleSizeList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_sampleSizeList, METH_NOARGS},
    {"sampleTypeList", (PyCFunction)Sbk_QAbstractAudioDeviceInfoFunc_sampleTypeList, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractAudioDeviceInfo_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractAudioDeviceInfo_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractAudioDeviceInfo_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAbstractAudioDeviceInfo",
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
    /*tp_traverse*/         Sbk_QAbstractAudioDeviceInfo_traverse,
    /*tp_clear*/            Sbk_QAbstractAudioDeviceInfo_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractAudioDeviceInfo_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractAudioDeviceInfo_Init,
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

static void* Sbk_QAbstractAudioDeviceInfo_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractAudioDeviceInfo*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractAudioDeviceInfo_PythonToCpp_QAbstractAudioDeviceInfo_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractAudioDeviceInfo_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractAudioDeviceInfo_PythonToCpp_QAbstractAudioDeviceInfo_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractAudioDeviceInfo_Type))
        return QAbstractAudioDeviceInfo_PythonToCpp_QAbstractAudioDeviceInfo_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractAudioDeviceInfo_PTR_CppToPython_QAbstractAudioDeviceInfo(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractAudioDeviceInfo*)cppIn, &Sbk_QAbstractAudioDeviceInfo_Type);

}

void init_QAbstractAudioDeviceInfo(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractAudioDeviceInfo_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractAudioDeviceInfo", "QAbstractAudioDeviceInfo*",
        &Sbk_QAbstractAudioDeviceInfo_Type, &Shiboken::callCppDestructor< ::QAbstractAudioDeviceInfo >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractAudioDeviceInfo_Type,
        QAbstractAudioDeviceInfo_PythonToCpp_QAbstractAudioDeviceInfo_PTR,
        is_QAbstractAudioDeviceInfo_PythonToCpp_QAbstractAudioDeviceInfo_PTR_Convertible,
        QAbstractAudioDeviceInfo_PTR_CppToPython_QAbstractAudioDeviceInfo);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractAudioDeviceInfo");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractAudioDeviceInfo*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractAudioDeviceInfo&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractAudioDeviceInfo).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractAudioDeviceInfoWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractAudioDeviceInfo_Type, &Sbk_QAbstractAudioDeviceInfo_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QAbstractAudioDeviceInfo_Type, &::QAbstractAudioDeviceInfo::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractAudioDeviceInfo_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractAudioDeviceInfo_Type, &::QAbstractAudioDeviceInfo::staticMetaObject, sizeof(::QAbstractAudioDeviceInfo));
}
