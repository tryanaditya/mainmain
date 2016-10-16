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

#include "qhttp_wrapper.h"

// Extra includes
#include <QList>
#include <qauthenticator.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qhttp.h>
#include <qiodevice.h>
#include <qmetaobject.h>
#include <qnetworkproxy.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsslerror.h>
#include <qtcpsocket.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QHttpWrapper::QHttpWrapper(QObject * parent) : QHttp(parent) {
    // ... middle
}

QHttpWrapper::QHttpWrapper(const QString & hostname, QHttp::ConnectionMode mode, quint16 port, QObject * parent) : QHttp(hostname, mode, port, parent) {
    // ... middle
}

QHttpWrapper::QHttpWrapper(const QString & hostname, quint16 port, QObject * parent) : QHttp(hostname, port, parent) {
    // ... middle
}

void QHttpWrapper::childEvent(QChildEvent * arg__1)
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

void QHttpWrapper::connectNotify(const char * signal)
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

void QHttpWrapper::customEvent(QEvent * arg__1)
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

void QHttpWrapper::disconnectNotify(const char * signal)
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

bool QHttpWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttp.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QHttpWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QHttp.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QHttpWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QHttpWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QHttp::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QHttpWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QHttp::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QHttpWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QHttpWrapper* >(this));
        return QHttp::qt_metacast(_clname);
}

QHttpWrapper::~QHttpWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QHttp_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent", "port"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QHttp >()))
        return -1;

    ::QHttpWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOOO:QHttp", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QHttp(QObject*)
    // 1: QHttp(QString,QHttp::ConnectionMode,quint16,QObject*)
    // 2: QHttp(QString,quint16,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QHttp(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QHttp(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QHttp(QString,quint16,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QHttp(QString,QHttp::ConnectionMode,quint16,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // QHttp(QString,QHttp::ConnectionMode,quint16,QObject*)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3])))) {
                    overloadId = 1; // QHttp(QString,QHttp::ConnectionMode,quint16,QObject*)
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QHttp(QString,quint16,QObject*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
                overloadId = 2; // QHttp(QString,quint16,QObject*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttp_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QHttp(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QHttp_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QHttp(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QHttpWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QHttpWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QHttp(const QString & hostname, QHttp::ConnectionMode mode, quint16 port, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "port");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp(): got multiple values for keyword argument 'port'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2]))))
                        goto Sbk_QHttp_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3]))))
                        goto Sbk_QHttp_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QHttp::ConnectionMode cppArg1 = ((::QHttp::ConnectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            quint16 cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QObject* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QHttp(QString,QHttp::ConnectionMode,quint16,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QHttpWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QHttpWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[3], self);
            }
            break;
        }
        case 2: // QHttp(const QString & hostname, quint16 port, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "port");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp(): got multiple values for keyword argument 'port'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1]))))
                        goto Sbk_QHttp_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2]))))
                        goto Sbk_QHttp_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            quint16 cppArg1 = 80;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QHttp(QString,quint16,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QHttpWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QHttpWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QHttp >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QHttp_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QHttp_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "unicode, PySide.QtNetwork.QHttp.ConnectionMode, unsigned short = 0, PySide.QtCore.QObject = None", "unicode, unsigned short = 80, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp", overloads);
        return -1;
}

static PyObject* Sbk_QHttpFunc_abort(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QHttpFunc_bytesAvailable(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QHttp*>(cppSelf)->bytesAvailable();
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

static PyObject* Sbk_QHttpFunc_clearPendingRequests(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearPendingRequests()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearPendingRequests();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QHttpFunc_close(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // close()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->close();
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

static PyObject* Sbk_QHttpFunc_currentDestinationDevice(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDestinationDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QHttp*>(cppSelf)->currentDestinationDevice();
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

static PyObject* Sbk_QHttpFunc_currentId(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QHttp*>(cppSelf)->currentId();
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

static PyObject* Sbk_QHttpFunc_currentRequest(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentRequest()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHttpRequestHeader cppResult = const_cast<const ::QHttp*>(cppSelf)->currentRequest();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHttpFunc_currentSourceDevice(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentSourceDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QHttp*>(cppSelf)->currentSourceDevice();
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

static PyObject* Sbk_QHttpFunc_error(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHttp::Error cppResult = const_cast<const ::QHttp*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHttpFunc_errorString(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QHttp*>(cppSelf)->errorString();
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

static PyObject* Sbk_QHttpFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.get(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.get(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: get(QString,QIODevice*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // get(QString,QIODevice*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            overloadId = 0; // get(QString,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_get_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "to");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.get(): got multiple values for keyword argument 'to'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1]))))
                    goto Sbk_QHttpFunc_get_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QIODevice* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // get(QString,QIODevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->get(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpFunc_get_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.get", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_hasPendingRequests(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasPendingRequests()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QHttp*>(cppSelf)->hasPendingRequests();
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

static PyObject* Sbk_QHttpFunc_head(PyObject* self, PyObject* pyArg)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: head(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // head(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_head_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // head(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->head(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpFunc_head_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHttp.head", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_ignoreSslErrors(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ignoreSslErrors()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->ignoreSslErrors();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QHttpFunc_lastResponse(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lastResponse()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHttpResponseHeader cppResult = const_cast<const ::QHttp*>(cppSelf)->lastResponse();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPRESPONSEHEADER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QHttpFunc_post(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.post(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.post(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:post", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: post(QString,QIODevice*,QIODevice*)
    // 1: post(QString,QByteArray,QIODevice*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // post(QString,QByteArray,QIODevice*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
                overloadId = 1; // post(QString,QByteArray,QIODevice*)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // post(QString,QIODevice*,QIODevice*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
                overloadId = 0; // post(QString,QIODevice*,QIODevice*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_post_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // post(const QString & path, QIODevice * data, QIODevice * to)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "to");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.post(): got multiple values for keyword argument 'to'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                        goto Sbk_QHttpFunc_post_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QIODevice* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // post(QString,QIODevice*,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->post(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // post(const QString & path, const QByteArray & data, QIODevice * to)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "to");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.post(): got multiple values for keyword argument 'to'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                        goto Sbk_QHttpFunc_post_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QIODevice* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // post(QString,QByteArray,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->post(cppArg0, *cppArg1, cppArg2);
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

    Sbk_QHttpFunc_post_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice, PySide.QtCore.QIODevice = None", "unicode, PySide.QtCore.QByteArray, PySide.QtCore.QIODevice = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.post", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(char*,qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // read(char*,qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_read_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(char*,qint64)
            // Begin code injection

            // TEMPLATE - read_wrapper - START
            Shiboken::AutoArrayPointer<char> _data(cppArg0);
            qint64 _size = cppSelf->read(_data, cppArg0);
            QByteArray ba;
            if (_size > 0)
            ba = QByteArray(_data, _size);
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);
            // TEMPLATE - read_wrapper - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpFunc_read_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHttp.read", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_readAll(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // readAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = cppSelf->readAll();
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

static PyObject* Sbk_QHttpFunc_request(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.request(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.request(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:request", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: request(QHttpRequestHeader,QIODevice*,QIODevice*)
    // 1: request(QHttpRequestHeader,QByteArray,QIODevice*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // request(QHttpRequestHeader,QIODevice*,QIODevice*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // request(QHttpRequestHeader,QByteArray,QIODevice*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
                overloadId = 1; // request(QHttpRequestHeader,QByteArray,QIODevice*)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // request(QHttpRequestHeader,QIODevice*,QIODevice*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
                overloadId = 0; // request(QHttpRequestHeader,QIODevice*,QIODevice*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_request_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // request(const QHttpRequestHeader & header, QIODevice * device, QIODevice * to)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "device");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.request(): got multiple values for keyword argument 'device'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1]))))
                        goto Sbk_QHttpFunc_request_TypeError;
                }
                value = PyDict_GetItemString(kwds, "to");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.request(): got multiple values for keyword argument 'to'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                        goto Sbk_QHttpFunc_request_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QHttpRequestHeader cppArg0_local = ::QHttpRequestHeader();
            ::QHttpRequestHeader* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QIODevice* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // request(QHttpRequestHeader,QIODevice*,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->request(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // request(const QHttpRequestHeader & header, const QByteArray & data, QIODevice * to)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "to");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.request(): got multiple values for keyword argument 'to'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                        goto Sbk_QHttpFunc_request_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QHttpRequestHeader cppArg0_local = ::QHttpRequestHeader();
            ::QHttpRequestHeader* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QHTTPREQUESTHEADER_IDX], pythonToCpp[0]))
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

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QIODevice* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // request(QHttpRequestHeader,QByteArray,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->request(*cppArg0, *cppArg1, cppArg2);
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

    Sbk_QHttpFunc_request_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QHttpRequestHeader, PySide.QtCore.QIODevice = None, PySide.QtCore.QIODevice = None", "PySide.QtNetwork.QHttpRequestHeader, PySide.QtCore.QByteArray, PySide.QtCore.QIODevice = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.request", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_setHost(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setHost(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setHost(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setHost", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setHost(QString,QHttp::ConnectionMode,quint16)
    // 1: setHost(QString,quint16)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setHost(QString,quint16)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setHost(QString,QHttp::ConnectionMode,quint16)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2])))) {
                overloadId = 0; // setHost(QString,QHttp::ConnectionMode,quint16)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
            overloadId = 1; // setHost(QString,quint16)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_setHost_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setHost(const QString & hostname, QHttp::ConnectionMode mode, quint16 port)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "port");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setHost(): got multiple values for keyword argument 'port'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[2]))))
                        goto Sbk_QHttpFunc_setHost_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QHttp::ConnectionMode cppArg1 = ((::QHttp::ConnectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            quint16 cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setHost(QString,QHttp::ConnectionMode,quint16)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->setHost(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // setHost(const QString & hostname, quint16 port)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "port");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setHost(): got multiple values for keyword argument 'port'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1]))))
                        goto Sbk_QHttpFunc_setHost_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            quint16 cppArg1 = 80;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setHost(QString,quint16)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->setHost(cppArg0, cppArg1);
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

    Sbk_QHttpFunc_setHost_TypeError:
        const char* overloads[] = {"unicode, PySide.QtNetwork.QHttp.ConnectionMode, unsigned short = 0", "unicode, unsigned short = 80", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.setHost", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_setProxy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setProxy(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setProxy(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setProxy", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setProxy(QNetworkProxy)
    // 1: setProxy(QString,int,QString,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // setProxy(QString,int,QString,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // setProxy(QString,int,QString,QString)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                overloadId = 1; // setProxy(QString,int,QString,QString)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArgs[0])))) {
        overloadId = 0; // setProxy(QNetworkProxy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_setProxy_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setProxy(const QNetworkProxy & proxy)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkProxy cppArg0_local = ::QNetworkProxy();
            ::QNetworkProxy* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setProxy(QNetworkProxy)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->setProxy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // setProxy(const QString & host, int port, const QString & username, const QString & password)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "username");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setProxy(): got multiple values for keyword argument 'username'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QHttpFunc_setProxy_TypeError;
                }
                value = PyDict_GetItemString(kwds, "password");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setProxy(): got multiple values for keyword argument 'password'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QHttpFunc_setProxy_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setProxy(QString,int,QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->setProxy(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_QHttpFunc_setProxy_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy", "unicode, int, unicode = QString(), unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.setProxy", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_setSocket(PyObject* self, PyObject* pyArg)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSocket(QTcpSocket*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QTCPSOCKET_IDX], (pyArg)))) {
        overloadId = 0; // setSocket(QTcpSocket*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_setSocket_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTcpSocket* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSocket(QTcpSocket*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->setSocket(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpFunc_setSocket_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QTcpSocket", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QHttp.setSocket", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_setUser(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setUser(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setUser(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setUser", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setUser(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setUser(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setUser(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QHttpFunc_setUser_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "password");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QHttp.setUser(): got multiple values for keyword argument 'password'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QHttpFunc_setUser_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setUser(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->setUser(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QHttpFunc_setUser_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QHttp.setUser", overloads);
        return 0;
}

static PyObject* Sbk_QHttpFunc_state(PyObject* self)
{
    ::QHttp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QHttp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHttp::State cppResult = const_cast<const ::QHttp*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QHttp_methods[] = {
    {"abort", (PyCFunction)Sbk_QHttpFunc_abort, METH_NOARGS},
    {"bytesAvailable", (PyCFunction)Sbk_QHttpFunc_bytesAvailable, METH_NOARGS},
    {"clearPendingRequests", (PyCFunction)Sbk_QHttpFunc_clearPendingRequests, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QHttpFunc_close, METH_NOARGS},
    {"currentDestinationDevice", (PyCFunction)Sbk_QHttpFunc_currentDestinationDevice, METH_NOARGS},
    {"currentId", (PyCFunction)Sbk_QHttpFunc_currentId, METH_NOARGS},
    {"currentRequest", (PyCFunction)Sbk_QHttpFunc_currentRequest, METH_NOARGS},
    {"currentSourceDevice", (PyCFunction)Sbk_QHttpFunc_currentSourceDevice, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QHttpFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QHttpFunc_errorString, METH_NOARGS},
    {"get", (PyCFunction)Sbk_QHttpFunc_get, METH_VARARGS|METH_KEYWORDS},
    {"hasPendingRequests", (PyCFunction)Sbk_QHttpFunc_hasPendingRequests, METH_NOARGS},
    {"head", (PyCFunction)Sbk_QHttpFunc_head, METH_O},
    {"ignoreSslErrors", (PyCFunction)Sbk_QHttpFunc_ignoreSslErrors, METH_NOARGS},
    {"lastResponse", (PyCFunction)Sbk_QHttpFunc_lastResponse, METH_NOARGS},
    {"post", (PyCFunction)Sbk_QHttpFunc_post, METH_VARARGS|METH_KEYWORDS},
    {"read", (PyCFunction)Sbk_QHttpFunc_read, METH_O},
    {"readAll", (PyCFunction)Sbk_QHttpFunc_readAll, METH_NOARGS},
    {"request", (PyCFunction)Sbk_QHttpFunc_request, METH_VARARGS|METH_KEYWORDS},
    {"setHost", (PyCFunction)Sbk_QHttpFunc_setHost, METH_VARARGS|METH_KEYWORDS},
    {"setProxy", (PyCFunction)Sbk_QHttpFunc_setProxy, METH_VARARGS|METH_KEYWORDS},
    {"setSocket", (PyCFunction)Sbk_QHttpFunc_setSocket, METH_O},
    {"setUser", (PyCFunction)Sbk_QHttpFunc_setUser, METH_VARARGS|METH_KEYWORDS},
    {"state", (PyCFunction)Sbk_QHttpFunc_state, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QHttp_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QHttp_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QHttp_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QHttp",
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
    /*tp_traverse*/         Sbk_QHttp_traverse,
    /*tp_clear*/            Sbk_QHttp_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QHttp_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QHttp_Init,
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

static void* Sbk_QHttp_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QHttp*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QHttp_ConnectionMode_PythonToCpp_QHttp_ConnectionMode(PyObject* pyIn, void* cppOut) {
    *((::QHttp::ConnectionMode*)cppOut) = (::QHttp::ConnectionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHttp_ConnectionMode_PythonToCpp_QHttp_ConnectionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX]))
        return QHttp_ConnectionMode_PythonToCpp_QHttp_ConnectionMode;
    return 0;
}
static PyObject* QHttp_ConnectionMode_CppToPython_QHttp_ConnectionMode(const void* cppIn) {
    int castCppIn = *((::QHttp::ConnectionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX], castCppIn);

}

static void QHttp_State_PythonToCpp_QHttp_State(PyObject* pyIn, void* cppOut) {
    *((::QHttp::State*)cppOut) = (::QHttp::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHttp_State_PythonToCpp_QHttp_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX]))
        return QHttp_State_PythonToCpp_QHttp_State;
    return 0;
}
static PyObject* QHttp_State_CppToPython_QHttp_State(const void* cppIn) {
    int castCppIn = *((::QHttp::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX], castCppIn);

}

static void QHttp_Error_PythonToCpp_QHttp_Error(PyObject* pyIn, void* cppOut) {
    *((::QHttp::Error*)cppOut) = (::QHttp::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QHttp_Error_PythonToCpp_QHttp_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX]))
        return QHttp_Error_PythonToCpp_QHttp_Error;
    return 0;
}
static PyObject* QHttp_Error_CppToPython_QHttp_Error(const void* cppIn) {
    int castCppIn = *((::QHttp::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QHttp_PythonToCpp_QHttp_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QHttp_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QHttp_PythonToCpp_QHttp_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QHttp_Type))
        return QHttp_PythonToCpp_QHttp_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QHttp_PTR_CppToPython_QHttp(const void* cppIn) {
    return PySide::getWrapperForQObject((::QHttp*)cppIn, &Sbk_QHttp_Type);

}

void init_QHttp(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QHTTP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QHttp_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QHttp", "QHttp*",
        &Sbk_QHttp_Type, &Shiboken::callCppDestructor< ::QHttp >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QHttp_Type,
        QHttp_PythonToCpp_QHttp_PTR,
        is_QHttp_PythonToCpp_QHttp_PTR_Convertible,
        QHttp_PTR_CppToPython_QHttp);

    Shiboken::Conversions::registerConverterName(converter, "QHttp");
    Shiboken::Conversions::registerConverterName(converter, "QHttp*");
    Shiboken::Conversions::registerConverterName(converter, "QHttp&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHttp).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QHttpWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QHttp_Type, &Sbk_QHttp_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ConnectionMode'.
    SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHttp_Type,
        "ConnectionMode",
        "PySide.QtNetwork.QHttp.ConnectionMode",
        "QHttp::ConnectionMode");
    if (!SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX],
        &Sbk_QHttp_Type, "ConnectionModeHttp", (long) QHttp::ConnectionModeHttp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX],
        &Sbk_QHttp_Type, "ConnectionModeHttps", (long) QHttp::ConnectionModeHttps))
        return ;
    // Register converter for enum 'QHttp::ConnectionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX],
            QHttp_ConnectionMode_CppToPython_QHttp_ConnectionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHttp_ConnectionMode_PythonToCpp_QHttp_ConnectionMode,
            is_QHttp_ConnectionMode_PythonToCpp_QHttp_ConnectionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_CONNECTIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHttp::ConnectionMode");
        Shiboken::Conversions::registerConverterName(converter, "ConnectionMode");
    }
    // End of 'ConnectionMode' enum.

    // Initialization of enum 'State'.
    SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHttp_Type,
        "State",
        "PySide.QtNetwork.QHttp.State",
        "QHttp::State");
    if (!SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Unconnected", (long) QHttp::Unconnected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "HostLookup", (long) QHttp::HostLookup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Connecting", (long) QHttp::Connecting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Sending", (long) QHttp::Sending))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Reading", (long) QHttp::Reading))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Connected", (long) QHttp::Connected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
        &Sbk_QHttp_Type, "Closing", (long) QHttp::Closing))
        return ;
    // Register converter for enum 'QHttp::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX],
            QHttp_State_CppToPython_QHttp_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHttp_State_PythonToCpp_QHttp_State,
            is_QHttp_State_PythonToCpp_QHttp_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHttp::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'Error'.
    SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QHttp_Type,
        "Error",
        "PySide.QtNetwork.QHttp.Error",
        "QHttp::Error");
    if (!SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "NoError", (long) QHttp::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "UnknownError", (long) QHttp::UnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "HostNotFound", (long) QHttp::HostNotFound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "ConnectionRefused", (long) QHttp::ConnectionRefused))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "UnexpectedClose", (long) QHttp::UnexpectedClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "InvalidResponseHeader", (long) QHttp::InvalidResponseHeader))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "WrongContentLength", (long) QHttp::WrongContentLength))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "Aborted", (long) QHttp::Aborted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "AuthenticationRequiredError", (long) QHttp::AuthenticationRequiredError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
        &Sbk_QHttp_Type, "ProxyAuthenticationRequiredError", (long) QHttp::ProxyAuthenticationRequiredError))
        return ;
    // Register converter for enum 'QHttp::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX],
            QHttp_Error_CppToPython_QHttp_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QHttp_Error_PythonToCpp_QHttp_Error,
            is_QHttp_Error_PythonToCpp_QHttp_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QHTTP_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QHttp::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.

    PySide::Signal::registerSignals(&Sbk_QHttp_Type, &::QHttp::staticMetaObject);

    qRegisterMetaType< ::QHttp::ConnectionMode >("QHttp::ConnectionMode");
    qRegisterMetaType< ::QHttp::State >("QHttp::State");
    qRegisterMetaType< ::QHttp::Error >("QHttp::Error");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QHttp_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QHttp_Type, &::QHttp::staticMetaObject, sizeof(::QHttp));
}
