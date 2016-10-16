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

#include "qsettings_wrapper.h"

// Extra includes
#include <QList>
#include <QStringList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsettings.h>
#include <qtextcodec.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSettingsWrapper::QSettingsWrapper(QObject * parent) : QSettings(parent) {
    // ... middle
}

QSettingsWrapper::QSettingsWrapper(QSettings::Format format, QSettings::Scope scope, const QString & organization, const QString & application, QObject * parent) : QSettings(format, scope, organization, application, parent) {
    // ... middle
}

QSettingsWrapper::QSettingsWrapper(QSettings::Scope scope, const QString & organization, const QString & application, QObject * parent) : QSettings(scope, organization, application, parent) {
    // ... middle
}

QSettingsWrapper::QSettingsWrapper(const QString & fileName, QSettings::Format format, QObject * parent) : QSettings(fileName, format, parent) {
    // ... middle
}

QSettingsWrapper::QSettingsWrapper(const QString & organization, const QString & application, QObject * parent) : QSettings(organization, application, parent) {
    // ... middle
}

void QSettingsWrapper::childEvent(QChildEvent * arg__1)
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

void QSettingsWrapper::connectNotify(const char * signal)
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

void QSettingsWrapper::customEvent(QEvent * arg__1)
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

void QSettingsWrapper::disconnectNotify(const char * signal)
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

bool QSettingsWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSettings::event(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSettings.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSettingsWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSettings.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QSettingsWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QSettingsWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSettings::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSettingsWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSettings::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSettingsWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSettingsWrapper* >(this));
        return QSettings::qt_metacast(_clname);
}

QSettingsWrapper::~QSettingsWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSettings_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"application", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSettings >()))
        return -1;

    ::QSettingsWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOOOO:QSettings", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QSettings(QObject*)
    // 1: QSettings(QSettings::Format,QSettings::Scope,QString,QString,QObject*)
    // 2: QSettings(QSettings::Scope,QString,QString,QObject*)
    // 3: QSettings(QString,QSettings::Format,QObject*)
    // 4: QSettings(QString,QString,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QSettings(QObject*)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QSettings(QSettings::Scope,QString,QString,QObject*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // QSettings(QSettings::Scope,QString,QString,QObject*)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3])))) {
                overloadId = 2; // QSettings(QSettings::Scope,QString,QString,QObject*)
            }
        }
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 1; // QSettings(QSettings::Format,QSettings::Scope,QString,QString,QObject*)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 1; // QSettings(QSettings::Format,QSettings::Scope,QString,QString,QObject*)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[4])))) {
                overloadId = 1; // QSettings(QSettings::Format,QSettings::Scope,QString,QString,QObject*)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSettings(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // QSettings(QString,QString,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 4; // QSettings(QString,QString,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 4; // QSettings(QString,QString,QObject*)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // QSettings(QString,QSettings::Format,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 3; // QSettings(QString,QSettings::Format,QObject*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettings_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSettings(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSettings(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSettingsWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSettingsWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QSettings(QSettings::Format format, QSettings::Scope scope, const QString & organization, const QString & application, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "application");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'application'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[4]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
            }
            ::QSettings::Format cppArg0 = ((::QSettings::Format)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSettings::Scope cppArg1 = ((::QSettings::Scope)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QObject* cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QSettings(QSettings::Format,QSettings::Scope,QString,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSettingsWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSettingsWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[4], self);
            }
            break;
        }
        case 2: // QSettings(QSettings::Scope scope, const QString & organization, const QString & application, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "application");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'application'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
            }
            ::QSettings::Scope cppArg0 = ((::QSettings::Scope)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QObject* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QSettings(QSettings::Scope,QString,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSettingsWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSettingsWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[3], self);
            }
            break;
        }
        case 3: // QSettings(const QString & fileName, QSettings::Format format, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSettings::Format cppArg1 = ((::QSettings::Format)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSettings(QString,QSettings::Format,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSettingsWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSettingsWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
        case 4: // QSettings(const QString & organization, const QString & application, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "application");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'application'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QSettings_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QSettings(QString,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSettingsWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSettingsWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSettings >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSettings_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QSettings_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "PySide.QtCore.QSettings.Format, PySide.QtCore.QSettings.Scope, unicode, unicode = QString(), PySide.QtCore.QObject = None", "PySide.QtCore.QSettings.Scope, unicode, unicode = QString(), PySide.QtCore.QObject = None", "unicode, PySide.QtCore.QSettings.Format, PySide.QtCore.QObject = None", "unicode, unicode = QString(), PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSettings", overloads);
        return -1;
}

static PyObject* Sbk_QSettingsFunc_allKeys(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // allKeys()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSettings*>(cppSelf)->allKeys();
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

static PyObject* Sbk_QSettingsFunc_applicationName(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSettings*>(cppSelf)->applicationName();
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

static PyObject* Sbk_QSettingsFunc_beginGroup(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: beginGroup(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // beginGroup(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_beginGroup_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginGroup(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->beginGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_beginGroup_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.beginGroup", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_beginReadArray(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: beginReadArray(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // beginReadArray(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_beginReadArray_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginReadArray(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->beginReadArray(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSettingsFunc_beginReadArray_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.beginReadArray", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_beginWriteArray(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.beginWriteArray(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.beginWriteArray(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:beginWriteArray", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: beginWriteArray(QString,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // beginWriteArray(QString,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // beginWriteArray(QString,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_beginWriteArray_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "size");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.beginWriteArray(): got multiple values for keyword argument 'size'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QSettingsFunc_beginWriteArray_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // beginWriteArray(QString,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->beginWriteArray(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_beginWriteArray_TypeError:
        const char* overloads[] = {"unicode, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSettings.beginWriteArray", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_childGroups(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childGroups()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSettings*>(cppSelf)->childGroups();
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

static PyObject* Sbk_QSettingsFunc_childKeys(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childKeys()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QSettings*>(cppSelf)->childKeys();
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

static PyObject* Sbk_QSettingsFunc_clear(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSettingsFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // contains(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_contains_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contains(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSettings*>(cppSelf)->contains(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSettingsFunc_contains_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.contains", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_defaultFormat(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultFormat()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSettings::Format cppResult = ::QSettings::defaultFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSettingsFunc_endArray(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endArray()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endArray();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSettingsFunc_endGroup(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endGroup()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endGroup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSettingsFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSettings::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSettingsFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.event", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_fallbacksEnabled(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fallbacksEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSettings*>(cppSelf)->fallbacksEnabled();
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

static PyObject* Sbk_QSettingsFunc_fileName(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSettings*>(cppSelf)->fileName();
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

static PyObject* Sbk_QSettingsFunc_format(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // format()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSettings::Format cppResult = const_cast<const ::QSettings*>(cppSelf)->format();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSettingsFunc_group(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // group()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSettings*>(cppSelf)->group();
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

static PyObject* Sbk_QSettingsFunc_iniCodec(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iniCodec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCodec * cppResult = const_cast<const ::QSettings*>(cppSelf)->iniCodec();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSettingsFunc_isWritable(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWritable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSettings*>(cppSelf)->isWritable();
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

static PyObject* Sbk_QSettingsFunc_organizationName(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // organizationName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSettings*>(cppSelf)->organizationName();
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

static PyObject* Sbk_QSettingsFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // remove(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_remove_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // remove(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->remove(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_remove_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.remove", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_scope(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scope()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSettings::Scope cppResult = const_cast<const ::QSettings*>(cppSelf)->scope();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSettingsFunc_setArrayIndex(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setArrayIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setArrayIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setArrayIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setArrayIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setArrayIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setArrayIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.setArrayIndex", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_setDefaultFormat(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultFormat(QSettings::Format)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), (pyArg)))) {
        overloadId = 0; // setDefaultFormat(QSettings::Format)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setDefaultFormat_TypeError;

    // Call function/method
    {
        ::QSettings::Format cppArg0 = ((::QSettings::Format)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultFormat(QSettings::Format)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSettings::setDefaultFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setDefaultFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSettings.Format", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.setDefaultFormat", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_setFallbacksEnabled(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFallbacksEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFallbacksEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setFallbacksEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFallbacksEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFallbacksEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setFallbacksEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.setFallbacksEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_setIniCodec(PyObject* self, PyObject* pyArg)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIniCodec(QTextCodec*)
    // 1: setIniCodec(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 1; // setIniCodec(const char*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTEXTCODEC_IDX], (pyArg)))) {
        overloadId = 0; // setIniCodec(QTextCodec*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setIniCodec_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setIniCodec(QTextCodec * codec)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QTextCodec* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setIniCodec(QTextCodec*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setIniCodec(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setIniCodec(const char * codecName)
        {
            const char* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setIniCodec(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setIniCodec(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setIniCodec_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTextCodec", "" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QSettings.setIniCodec", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_setPath(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPath", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setPath(QSettings::Format,QSettings::Scope,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // setPath(QSettings::Format,QSettings::Scope,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setPath_TypeError;

    // Call function/method
    {
        ::QSettings::Format cppArg0 = ((::QSettings::Format)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSettings::Scope cppArg1 = ((::QSettings::Scope)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setPath(QSettings::Format,QSettings::Scope,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QSettings::setPath(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setPath_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSettings.Format, PySide.QtCore.QSettings.Scope, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSettings.setPath", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_setValue(PyObject* self, PyObject* args)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValue", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setValue(QString,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setValue(QString,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_setValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValue(QString,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValue(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSettingsFunc_setValue_TypeError:
        const char* overloads[] = {"unicode, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSettings.setValue", overloads);
        return 0;
}

static PyObject* Sbk_QSettingsFunc_status(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // status()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSettings::Status cppResult = const_cast<const ::QSettings*>(cppSelf)->status();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSettingsFunc_sync(PyObject* self)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sync()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->sync();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSettingsFunc_value(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSettings* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSettings*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.value(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.value(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:value", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: value(QString,QVariant)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // value(QString,QVariant)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 0; // value(QString,QVariant)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSettingsFunc_value_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "defaultValue");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QSettings.value(): got multiple values for keyword argument 'defaultValue'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1]))))
                    goto Sbk_QSettingsFunc_value_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = QVariant();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // value(QString,QVariant)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QSettings*>(cppSelf)->value(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSettingsFunc_value_TypeError:
        const char* overloads[] = {"unicode, QVariant = QVariant()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QSettings.value", overloads);
        return 0;
}

static PyMethodDef Sbk_QSettings_methods[] = {
    {"allKeys", (PyCFunction)Sbk_QSettingsFunc_allKeys, METH_NOARGS},
    {"applicationName", (PyCFunction)Sbk_QSettingsFunc_applicationName, METH_NOARGS},
    {"beginGroup", (PyCFunction)Sbk_QSettingsFunc_beginGroup, METH_O},
    {"beginReadArray", (PyCFunction)Sbk_QSettingsFunc_beginReadArray, METH_O},
    {"beginWriteArray", (PyCFunction)Sbk_QSettingsFunc_beginWriteArray, METH_VARARGS|METH_KEYWORDS},
    {"childGroups", (PyCFunction)Sbk_QSettingsFunc_childGroups, METH_NOARGS},
    {"childKeys", (PyCFunction)Sbk_QSettingsFunc_childKeys, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QSettingsFunc_clear, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QSettingsFunc_contains, METH_O},
    {"defaultFormat", (PyCFunction)Sbk_QSettingsFunc_defaultFormat, METH_NOARGS|METH_STATIC},
    {"endArray", (PyCFunction)Sbk_QSettingsFunc_endArray, METH_NOARGS},
    {"endGroup", (PyCFunction)Sbk_QSettingsFunc_endGroup, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QSettingsFunc_event, METH_O},
    {"fallbacksEnabled", (PyCFunction)Sbk_QSettingsFunc_fallbacksEnabled, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QSettingsFunc_fileName, METH_NOARGS},
    {"format", (PyCFunction)Sbk_QSettingsFunc_format, METH_NOARGS},
    {"group", (PyCFunction)Sbk_QSettingsFunc_group, METH_NOARGS},
    {"iniCodec", (PyCFunction)Sbk_QSettingsFunc_iniCodec, METH_NOARGS},
    {"isWritable", (PyCFunction)Sbk_QSettingsFunc_isWritable, METH_NOARGS},
    {"organizationName", (PyCFunction)Sbk_QSettingsFunc_organizationName, METH_NOARGS},
    {"remove", (PyCFunction)Sbk_QSettingsFunc_remove, METH_O},
    {"scope", (PyCFunction)Sbk_QSettingsFunc_scope, METH_NOARGS},
    {"setArrayIndex", (PyCFunction)Sbk_QSettingsFunc_setArrayIndex, METH_O},
    {"setDefaultFormat", (PyCFunction)Sbk_QSettingsFunc_setDefaultFormat, METH_O|METH_STATIC},
    {"setFallbacksEnabled", (PyCFunction)Sbk_QSettingsFunc_setFallbacksEnabled, METH_O},
    {"setIniCodec", (PyCFunction)Sbk_QSettingsFunc_setIniCodec, METH_O},
    {"setPath", (PyCFunction)Sbk_QSettingsFunc_setPath, METH_VARARGS|METH_STATIC},
    {"setValue", (PyCFunction)Sbk_QSettingsFunc_setValue, METH_VARARGS},
    {"status", (PyCFunction)Sbk_QSettingsFunc_status, METH_NOARGS},
    {"sync", (PyCFunction)Sbk_QSettingsFunc_sync, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QSettingsFunc_value, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSettings_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSettings_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSettings_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QSettings",
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
    /*tp_traverse*/         Sbk_QSettings_traverse,
    /*tp_clear*/            Sbk_QSettings_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSettings_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSettings_Init,
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

static void* Sbk_QSettings_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSettings*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSettings_Status_PythonToCpp_QSettings_Status(PyObject* pyIn, void* cppOut) {
    *((::QSettings::Status*)cppOut) = (::QSettings::Status) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSettings_Status_PythonToCpp_QSettings_Status_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX]))
        return QSettings_Status_PythonToCpp_QSettings_Status;
    return 0;
}
static PyObject* QSettings_Status_CppToPython_QSettings_Status(const void* cppIn) {
    int castCppIn = *((::QSettings::Status*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX], castCppIn);

}

static void QSettings_Format_PythonToCpp_QSettings_Format(PyObject* pyIn, void* cppOut) {
    *((::QSettings::Format*)cppOut) = (::QSettings::Format) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSettings_Format_PythonToCpp_QSettings_Format_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX]))
        return QSettings_Format_PythonToCpp_QSettings_Format;
    return 0;
}
static PyObject* QSettings_Format_CppToPython_QSettings_Format(const void* cppIn) {
    int castCppIn = *((::QSettings::Format*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX], castCppIn);

}

static void QSettings_Scope_PythonToCpp_QSettings_Scope(PyObject* pyIn, void* cppOut) {
    *((::QSettings::Scope*)cppOut) = (::QSettings::Scope) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSettings_Scope_PythonToCpp_QSettings_Scope_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX]))
        return QSettings_Scope_PythonToCpp_QSettings_Scope;
    return 0;
}
static PyObject* QSettings_Scope_CppToPython_QSettings_Scope(const void* cppIn) {
    int castCppIn = *((::QSettings::Scope*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSettings_PythonToCpp_QSettings_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSettings_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSettings_PythonToCpp_QSettings_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSettings_Type))
        return QSettings_PythonToCpp_QSettings_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSettings_PTR_CppToPython_QSettings(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSettings*)cppIn, &Sbk_QSettings_Type);

}

void init_QSettings(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QSETTINGS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSettings_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSettings", "QSettings*",
        &Sbk_QSettings_Type, &Shiboken::callCppDestructor< ::QSettings >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSettings_Type,
        QSettings_PythonToCpp_QSettings_PTR,
        is_QSettings_PythonToCpp_QSettings_PTR_Convertible,
        QSettings_PTR_CppToPython_QSettings);

    Shiboken::Conversions::registerConverterName(converter, "QSettings");
    Shiboken::Conversions::registerConverterName(converter, "QSettings*");
    Shiboken::Conversions::registerConverterName(converter, "QSettings&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSettings).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSettingsWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSettings_Type, &Sbk_QSettings_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Status'.
    SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSettings_Type,
        "Status",
        "PySide.QtCore.QSettings.Status",
        "QSettings::Status");
    if (!SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX],
        &Sbk_QSettings_Type, "NoError", (long) QSettings::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX],
        &Sbk_QSettings_Type, "AccessError", (long) QSettings::AccessError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX],
        &Sbk_QSettings_Type, "FormatError", (long) QSettings::FormatError))
        return ;
    // Register converter for enum 'QSettings::Status'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX],
            QSettings_Status_CppToPython_QSettings_Status);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSettings_Status_PythonToCpp_QSettings_Status,
            is_QSettings_Status_PythonToCpp_QSettings_Status_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_STATUS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSettings::Status");
        Shiboken::Conversions::registerConverterName(converter, "Status");
    }
    // End of 'Status' enum.

    // Initialization of enum 'Format'.
    SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSettings_Type,
        "Format",
        "PySide.QtCore.QSettings.Format",
        "QSettings::Format");
    if (!SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "NativeFormat", (long) QSettings::NativeFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "IniFormat", (long) QSettings::IniFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "InvalidFormat", (long) QSettings::InvalidFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat1", (long) QSettings::CustomFormat1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat2", (long) QSettings::CustomFormat2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat3", (long) QSettings::CustomFormat3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat4", (long) QSettings::CustomFormat4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat5", (long) QSettings::CustomFormat5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat6", (long) QSettings::CustomFormat6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat7", (long) QSettings::CustomFormat7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat8", (long) QSettings::CustomFormat8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat9", (long) QSettings::CustomFormat9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat10", (long) QSettings::CustomFormat10))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat11", (long) QSettings::CustomFormat11))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat12", (long) QSettings::CustomFormat12))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat13", (long) QSettings::CustomFormat13))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat14", (long) QSettings::CustomFormat14))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat15", (long) QSettings::CustomFormat15))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
        &Sbk_QSettings_Type, "CustomFormat16", (long) QSettings::CustomFormat16))
        return ;
    // Register converter for enum 'QSettings::Format'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX],
            QSettings_Format_CppToPython_QSettings_Format);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSettings_Format_PythonToCpp_QSettings_Format,
            is_QSettings_Format_PythonToCpp_QSettings_Format_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_FORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSettings::Format");
        Shiboken::Conversions::registerConverterName(converter, "Format");
    }
    // End of 'Format' enum.

    // Initialization of enum 'Scope'.
    SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSettings_Type,
        "Scope",
        "PySide.QtCore.QSettings.Scope",
        "QSettings::Scope");
    if (!SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX],
        &Sbk_QSettings_Type, "UserScope", (long) QSettings::UserScope))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX],
        &Sbk_QSettings_Type, "SystemScope", (long) QSettings::SystemScope))
        return ;
    // Register converter for enum 'QSettings::Scope'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX],
            QSettings_Scope_CppToPython_QSettings_Scope);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSettings_Scope_PythonToCpp_QSettings_Scope,
            is_QSettings_Scope_PythonToCpp_QSettings_Scope_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QSETTINGS_SCOPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSettings::Scope");
        Shiboken::Conversions::registerConverterName(converter, "Scope");
    }
    // End of 'Scope' enum.

    PySide::Signal::registerSignals(&Sbk_QSettings_Type, &::QSettings::staticMetaObject);

    qRegisterMetaType< ::QSettings::Status >("QSettings::Status");
    qRegisterMetaType< ::QSettings::Format >("QSettings::Format");
    qRegisterMetaType< ::QSettings::Scope >("QSettings::Scope");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSettings_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSettings_Type, &::QSettings::staticMetaObject, sizeof(::QSettings));
}
